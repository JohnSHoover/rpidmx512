/**
 * @file propertiesbuilder.h
 *
 */
/* Copyright (C) 2019-2020 by Arjan van Vught mailto:info@orangepi-dmx.nl
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

#ifndef PROPERTIESBUILDER_H_
#define PROPERTIESBUILDER_H_

#include <stdint.h>
#include <stdbool.h>
#include <time.h>

class PropertiesBuilder {
public:
	PropertiesBuilder(const char *pFileName, uint8_t *pBuffer, uint32_t nLength);
	~PropertiesBuilder(void);

	bool Add(const char *pProperty, uint32_t nValue, bool bIsSet = true);

	bool Add(const char *pProperty, uint16_t nValue, bool bIsSet = true) {
		return Add(pProperty, static_cast<uint32_t>(nValue), bIsSet);
	}

	bool Add(const char *pProperty, uint8_t nValue, bool bIsSet = true) {
		return Add(pProperty, static_cast<uint32_t>(nValue), bIsSet);
	}

	bool Add(const char *pProperty, time_t nValue, bool bIsSet = true) {
		return Add(pProperty, static_cast<uint32_t>(nValue), bIsSet);
	}

	bool Add(const char *pProperty, bool bValue, bool bIsSet = true) {
		return Add(pProperty, static_cast<uint32_t>(bValue), bIsSet);
	}

	bool Add(const char *pProperty, float fValue, bool bIsSet = true, uint32_t nPrecision = 1);

	bool Add(const char *pProperty, const char *pValue, bool bIsSet = true);

	bool AddIpAddress(const char *pProperty, uint32_t nValue, bool bIsSet = true);

	bool AddHex16(const char *pProperty, const uint8_t nValue[2], bool bIsSet = true);

	bool AddHex16(const char *pProperty, const uint16_t nValue16, bool bIsSet = true) {
		const uint8_t nValue[2] = { static_cast<uint8_t>((nValue16 & 0xFF00) >> 8), static_cast<uint8_t>(nValue16 & 0xFF) };
		return AddHex16(pProperty, nValue, bIsSet);
	}

	bool AddHex24(const char *pProperty, const uint32_t nValue32, bool bIsSet = true);

	bool AddComment(const char *pComment);

	uint32_t GetSize(void) {
		return m_nSize;
	}

private:
	uint8_t *m_pBuffer;
	uint32_t m_nLength;
	uint32_t m_nSize;
};

#endif /* PROPERTIESBUILDER_H_ */
