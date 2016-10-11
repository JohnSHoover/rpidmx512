/**
 * @file e131bridge.cpp
 *
 */
/* Copyright (C) 2016 by Arjan van Vught mailto:info@raspberrypi-dmx.nl
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

#include "e131.h"
#include "e131bridge.h"
#include "lightset.h"
#include "udp.h"

#include "util.h"

static const uint8_t DEVICE_SOFTWARE_VERSION[] = {0x00, 0x03 };	///<
static const uint8_t ACN_PACKET_IDENTIFIER[12] = { 0x41, 0x53, 0x43, 0x2d, 0x45, 0x31, 0x2e, 0x31, 0x37, 0x00, 0x00, 0x00 }; ///< 5.3 ACN Packet Identifier

#define SWAP_UINT16(x) (((x) >> 8) | ((x) << 8))

/**
 *
 */
E131Bridge::E131Bridge(void) :
		m_pLightSet(0), m_nUniverse(E131_DEFAULT_UNIVERSE), m_nLastSequenceNumber(0) {
}

/**
 *
 */
E131Bridge::~E131Bridge(void) {
	if (m_pLightSet != 0) {
		m_pLightSet->Stop();
		m_pLightSet = 0;
	}
}


/**
 *
 */
void E131Bridge::Start(void) {
	assert(m_pLightSet != 0);

	m_pLightSet->Start();
}

/**
 *
 */
void E131Bridge::Stop(void) {
	m_pLightSet->Stop();
}

/**
 *
 * @return
 */
const uint8_t *E131Bridge::GetSoftwareVersion(void) {
	return DEVICE_SOFTWARE_VERSION;
}

/**
 *
 */
void E131Bridge::SetOutput(LightSet *pLightSet) {
	assert(pLightSet != 0);
	m_pLightSet = pLightSet;
}

/**
 *
 * @return
 */
const uint16_t E131Bridge::getUniverse() {
	return m_nUniverse;
}

/**
 *
 * @param nUniverse
 */
void E131Bridge::setUniverse(const uint16_t nUniverse) {
	m_nUniverse = nUniverse;
}

/**
 *
 */
void E131Bridge::HandleDmx(void) {
	uint8_t *p = m_E131Packet.E131.DMPLayer.PropertyValues;
	uint16_t slots = SWAP_UINT16(m_E131Packet.E131.DMPLayer.PropertyValueCount);

	if (slots > (uint16_t)513) {
		return;
	}

	// Skip DMX Start Code
	p++;
	slots--;

	m_pLightSet->SetData(0, p, slots);

}

/**
 *
 * @return
 */
bool E131Bridge::IsValid(void) {
	// Root layer

	// 5 E1.31 use of the ACN Root Layer Protocol
	// Receivers shall discard the packet if the ACN Packet Identifier is not valid.
	if (memcmp(m_E131Packet.E131.RootLayer.ACNPacketIdentifier, ACN_PACKET_IDENTIFIER, 12) != 0) {
		return false;
	}

	// Frame layer

	// 6.9.2 Sequence Numbering
	// Having first received a packet with sequence number A, a second packet with sequence number B
	// arrives. If, using signed 8-bit binary arithmetic, B – A is less than or equal to 0, but greater than -20 then
	// the packet containing sequence number B shall be deemed out of sequence and discarded
	const int8_t diff = (int8_t)(m_E131Packet.E131.FrameLayer.SequenceNumber - m_nLastSequenceNumber);

	m_nLastSequenceNumber = m_E131Packet.E131.FrameLayer.SequenceNumber;

	if ((diff <= (int8_t)0) && (diff > (int8_t)-20)) {
		return false;
	}

	// 8.2 Association of Multicast Addresses and Universe
	// Note: The identity of the universe shall be determined by the universe number in the
	// packet and not assumed from the multicast address.
	if (m_E131Packet.E131.FrameLayer.Universe != SWAP_UINT16(m_nUniverse)) {
		return false;
	}

	// DMP layer

	// The DMP Layer's Vector shall be set to 0x02, which indicates a DMP Set Property message by
	// transmitters. Receivers shall discard the packet if the received value is not 0x02.
	if (m_E131Packet.E131.DMPLayer.Vector != (uint8_t)0x02) {
		return false;
	}

	// Transmitters shall set the DMP Layer's Address Type and Data Type to 0xa1. Receivers shall discard the
	// packet if the received value is not 0xa1.
	if (m_E131Packet.E131.DMPLayer.Type != (uint8_t)0xa1) {
		return false;
	}

	// Transmitters shall set the DMP Layer's First Property Address to 0x0000. Receivers shall discard the
	// packet if the received value is not 0x0000.
	if (m_E131Packet.E131.DMPLayer.FirstAddressProperty != SWAP_UINT16((uint16_t)0x0000)) {
		return false;
	}

	// Transmitters shall set the DMP Layer's Address Increment to 0x0001. Receivers shall discard the packet if
	// the received value is not 0x0001.
	if (m_E131Packet.E131.DMPLayer.AddressIncrement != SWAP_UINT16((uint16_t)0x0001)) {
		return false;
	}

	return true;
}

/**
 *
 */
int E131Bridge::HandlePacket(void) {
	const char *packet = (char *) &(m_E131Packet.E131);
	uint16_t nForeignPort;
	uint32_t IPAddressFrom;

	const int nBytesReceived = udp_recvfrom((const uint8_t *)packet, (const uint16_t)sizeof(m_E131Packet.E131), &IPAddressFrom, &nForeignPort) ;


	if (nBytesReceived == 0) {
		return 0;
	}

	if (!IsValid()) {
		return 0;
	}

	HandleDmx();

	return nBytesReceived;
}