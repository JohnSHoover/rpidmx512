/**
 * @file ws28xxdisplay7segment_font.h
 */
/*
 * Copyright (C) 2019 by hippy mailto:dmxout@gmail.com
 * Based on: displaymax7219.h
 * Copyright (C) 2019-2020 by Arjan van Vught mailto:info@orangepi-dmx.nl
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

#ifndef WS28XXDISPLAY7SEGMENT_FONT_H_
#define WS28XXDISPLAY7SEGMENT_FONT_H_

#include <stdint.h>

// Compliments Dean Reading (deanreading@hotmail.com: http://arduino.cc/playground/Main/SevenSegmentLibrary), 2012
// This is the combined array that contains all the segment configurations for many different characters and symbols

static const uint8_t Seg7Array[] __attribute__ ((aligned (4))) = {
			//dec     ABCDEFG  Segments   7-segment map:
		126,//0b1111110, // 0   "0"         AAA
		48, //0b0110000, // 1   "1"         F   B
		109, //0b1101101, // 2   "2"        F   B
		121, //0b1111001, // 3   "3"         GGG
		51, //0b0110011, // 4   "4"         E   C
		91, //0b1011011, // 5   "5"         E   C
		95, //0b1011111, // 6   "6"          DDD
		112, //0b1110000, // 7   "7"
		127, //0b1111111, // 8   "8"
		123, //0b1111011, // 9   "9"
		119, //0b1110111, // 10  "A"
		31, //0b0011111, // 11  "b"
		78, //0b1001110, // 12  "C"
		61, //0b0111101, // 13  "d"
		79, //0b1001111, // 14  "E"
		71, //0b1000111, // 15  "F"
		0, //0b0000000, // 16  NO DISPLAY
		0, //0b0000000, // 17  NO DISPLAY
		0, //0b0000000, // 18  NO DISPLAY
		0, //0b0000000, // 19  NO DISPLAY
		0, //0b0000000, // 20  NO DISPLAY
		0, //0b0000000, // 21  NO DISPLAY
		0, //0b0000000, // 22  NO DISPLAY
		0, //0b0000000, // 23  NO DISPLAY
		0, //0b0000000, // 24  NO DISPLAY
		0, //0b0000000, // 25  NO DISPLAY
		0, //0b0000000, // 26  NO DISPLAY
		0, //0b0000000, // 27  NO DISPLAY
		0, //0b0000000, // 28  NO DISPLAY
		0, //0b0000000, // 29  NO DISPLAY
		0, //0b0000000, // 30  NO DISPLAY
		0, //0b0000000, // 31  NO DISPLAY
		0, //0b0000000, // 32  ' '
		0, //0b0000000, // 33  '!'  NO DISPLAY
		34, //0b0100010, // 34  '"'
		0, //0b0000000, // 35  '#'  NO DISPLAY
		0, //0b0000000, // 36  '$'  NO DISPLAY
		0, //0b0000000, // 37  '%'  NO DISPLAY
		0, //0b0000000, // 38  '&'  NO DISPLAY
		32, //0b0100000, // 39  '''
		78, //0b1001110, // 40  '('
		120, //0b1111000, // 41  ')'
		0, //0b0000000, // 42  '*'  NO DISPLAY
		0, //0b0000000, // 43  '+'  NO DISPLAY
		4, //0b0000100, // 44  ','
		1, //0b0000001, // 45  '-'
		0, //0b0000000, // 46  '.'  NO DISPLAY
		0, //0b0000000, // 47  '/'  NO DISPLAY
		126, //0b1111110, // 48  '0'
		48, //0b0110000, // 49  '1'
		109, //0b1101101, // 50  '2'
		121, //0b1111001, // 51  '3'
		51, //0b0110011, // 52  '4'
		91, //0b1011011, // 53  '5'
		95, //0b1011111, // 54  '6'
		112, //0b1110000, // 55  '7'
		127, //0b1111111, // 56  '8'
		123, //0b1111011, // 57  '9'
		0, //0b0000000, // 58  ':'  NO DISPLAY
		0, //0b0000000, // 59  ';'  NO DISPLAY
		0, //0b0000000, // 60  '<'  NO DISPLAY
		0, //0b0000000, // 61  '='  NO DISPLAY
		0, //0b0000000, // 62  '>'  NO DISPLAY
		0, //0b0000000, // 63  '?'  NO DISPLAY
		0, //0b0000000, // 64  '@'  NO DISPLAY
		119, //0b1110111, // 65  'A'
		31, //0b0011111, // 66  'b'
		78, //0b1001110, // 67  'C'
		61, //0b0111101, // 68  'd'
		79, //0b1001111, // 69  'E'
		71, //0b1000111, // 70  'F'
		94, //0b1011110, // 71  'G'
		55, //0b0110111, // 72  'H'
		48, //0b0110000, // 73  'I'
		56, //0b0111000, // 74  'J'
		0, //0b0000000, // 75  'K'  NO DISPLAY
		14, //0b0001110, // 76  'L'
		0, //0b0000000, // 77  'M'  NO DISPLAY
		21, //0b0010101, // 78  'n'
		126, //0b1111110, // 79  'O'
		103, //0b1100111, // 80  'P'
		115, //0b1110011, // 81  'q'
		5, //0b0000101, // 82  'r'
		91, //0b1011011, // 83  'S'
		15, //0b0001111, // 84  't'
		62, //0b0111110, // 85  'U'
		0, //0b0000000, // 86  'V'  NO DISPLAY
		0, //0b0000000, // 87  'W'  NO DISPLAY
		0, //0b0000000, // 88  'X'  NO DISPLAY
		59, //0b0111011, // 89  'y'
		0, //0b0000000, // 90  'Z'  NO DISPLAY
		78, //0b1001110, // 91  '['
		0, //0b0000000, // 92  '\'  NO DISPLAY
		120, //0b1111000, // 93  ']'
		0, //0b0000000, // 94  '^'  NO DISPLAY
		8, //0b0001000, // 95  '_'
		2, //0b0000010, // 96  '`'
		119, //0b1110111, // 97  'a' SAME AS CAP
		31, //0b0011111, // 98  'b' SAME AS CAP
		13, //0b0001101, // 99  'c'
		61, //0b0111101, // 100 'd' SAME AS CAP
		111, //0b1101111, // 101 'e'
		71, //0b1000111, // 102 'F' SAME AS CAP
		94, //0b1011110, // 103 'G' SAME AS CAP
		23, //0b0010111, // 104 'h'
		16, //0b0010000, // 105 'i'
		56, //0b0111000, // 106 'j' SAME AS CAP
		0, //0b0000000, // 107 'k'  NO DISPLAY
		48, //0b0110000, // 108 'l'
		0, //0b0000000, // 109 'm'  NO DISPLAY
		21, //0b0010101, // 110 'n' SAME AS CAP
		29, //0b0011101, // 111 'o'
		103, //0b1100111, // 112 'p' SAME AS CAP
		115, //0b1110011, // 113 'q' SAME AS CAP
		5, //0b0000101, // 114 'r' SAME AS CAP
		91, //0b1011011, // 115 'S' SAME AS CAP
		15, //0b0001111, // 116 't' SAME AS CAP
		28, //0b0011100, // 117 'u'
		0, //0b0000000, // 118 'b'  NO DISPLAY
		0, //0b0000000, // 119 'w'  NO DISPLAY
		0, //0b0000000, // 120 'x'  NO DISPLAY
		0, //0b0000000, // 121 'y'  NO DISPLAY
		0, //0b0000000, // 122 'z'  NO DISPLAY
		0, //0b0000000, // 123 '0b'  NO DISPLAY
		0, //0b0000000, // 124 '|'  NO DISPLAY
		0, //0b0000000, // 125 ','  NO DISPLAY
		0, //0b0000000, // 126 '~'  NO DISPLAY
		0 //0b0000000, // 127 'DEL'  NO DISPLAY
};

#endif /* WS28XXDISPLAY7SEGMENT_FONT_H_ */
