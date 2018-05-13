/*
 * base64.cpp
 *
 *  Created on: May 10, 2018
 *      Author: Gerviba
 */

#include "base64.h"

#include <math.h>

namespace gencrypt {

Base64::Base64() {}

std::string Base64::getName() const {
	return "Base64";
}

std::string Base64::encode(std::string en) {
	std::string BASE64_CHARS =
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz"
			"0123456789+/";

	bool bits[en.length() * 8];
	for (size_t index = 0; index < en.length(); ++index)
		for (int bit = 7; bit >= 0; --bit)
			bits[index * 8 + (7 - bit)] = en[index] & (1 << bit);

	size_t length = ceil(en.length() * 8 / 6.0);
	unsigned char ids[length] = {0};
	std::string result;

	for (size_t i = 0; i < ceil(length / 4.0) * 4; ++i)
		result += "=";

	for (size_t i = 0; i < en.length() * 8; ++i)
		ids[i / 6] |= bits[i] << (5 - (i % 6));

	for (size_t i = 0; i < length; ++i)
		result[i] = BASE64_CHARS[ids[i]];
	return result;
}

int Base64::calcIds(const std::string& de, size_t i) {
	return de[i] >= 'A' && de[i] <= 'Z' ?
				de[i] - 'A' :
			de[i] >= 'a' && de[i] <= 'z' ?
				de[i] - 'a' + 26 :
			de[i] >= '0' && de[i] <= '9' ?
				de[i] - '0' + 52 :
			de[i] == '+' ?
				62 :
			de[i] == '/' ?
				63 : 0;
}

std::string Base64::decode(std::string de) {
	unsigned char ids[de.length()] = {0};
	for (size_t i = 0; i < de.length(); ++i)
		ids[i] = calcIds(de, i);

	bool bits[de.length() * 6];
	for (size_t index = 0; index < de.length(); ++index)
		for (int bit = 5; bit >= 0; --bit)
			bits[index * 6 + (5 - bit)] = ids[index] & (1 << bit);

	std::string result;
	for (size_t i = 0; i < ceil(de.length() * 6 / 8); ++i) {
		unsigned char pre = 0;
		for (int bit = 7; bit >= 0; --bit)
			pre |= bits[i * 8 + (7 - bit)] << bit;
		result += (char) pre;
	}

	return result;
}

void Base64::encode(std::istream& is, std::ostream& os, bool endl) {
	std::string input;
	std::getline(is, input);
	os << encode(input);
	if (endl)
		os << std::endl;
}

void Base64::decode(std::istream& is, std::ostream& os, bool endl) {
	std::string input;
	std::getline(is, input);
	os << decode(input);
	if (endl)
		os << std::endl;
}

} /* namespace gencrypt */
