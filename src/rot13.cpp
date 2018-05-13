/*
 * rot13.cpp
 *
 *  Created on: Mar 31, 2018
 *      Author: Gerviba
 */

#include "rot13.h"

#include <string>

std::string gencrypt::Rot13::UPPERCASE = "NOPQRSTUVWXYZABCDEFGHIJKLM";
std::string gencrypt::Rot13::LOWERCASE = "nopqrstuvwxyzabcdefghijklm";

inline std::string gencrypt::Rot13::code(std::string input) {
	for (int i = 0, len = input.length(); i < len; ++i) {
		if (input[i] >= 'A' && input[i] <= 'Z')
			input[i] = UPPERCASE[input[i] - 'A'];
		else if (input[i] >= 'a' && input[i] <= 'z')
			input[i] = LOWERCASE[input[i] - 'a'];
	}
	return input;
}

std::string gencrypt::Rot13::getName() const {
	return "Rot13";
}

std::string gencrypt::Rot13::encode(std::string en) {
	return code(en);
}

std::string gencrypt::Rot13::decode(std::string de) {
	return code(de);
}

void gencrypt::Rot13::encode(std::istream& is, std::ostream& os, bool endl) {
	std::string input;
	std::getline(is, input);
	os << encode(input);
	if (endl)
		os << std::endl;
}

void gencrypt::Rot13::decode(std::istream& is, std::ostream& os, bool endl) {
	std::string input;
	std::getline(is, input);
	os << decode(input);
	if (endl)
		os << std::endl;
}

