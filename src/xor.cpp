/*
 * xor.cpp
 *
 *  Created on: Mar 31, 2018
 *      Author: Gerviba
 */

#include "xor.h"

#include <iostream>

gencrypt::Xor::Xor(const Key* key) : SymmetricEncription(key) {}

inline std::string gencrypt::Xor::code(std::string input) {
	for (int i = 0, len = input.length(); i < len; ++i)
		input[i] ^= (*this->key)[i % this->key->getLength()];
	return input;
}

std::string gencrypt::Xor::getName() const {
	return "Xor";
}

std::string gencrypt::Xor::encode(std::string en) {
	return code(en);
}

std::string gencrypt::Xor::decode(std::string de) {
	return code(de);
}

void gencrypt::Xor::encode(std::istream& is, std::ostream& os, bool endl) {
	std::string input;
	std::getline(is, input);
	os << encode(input);
	if (endl)
		os << std::endl;
}

void gencrypt::Xor::decode(std::istream& is, std::ostream& os, bool endl) {
	std::string input;
	std::getline(is, input);
	os << decode(input);
	if (endl)
		os << std::endl;
}
