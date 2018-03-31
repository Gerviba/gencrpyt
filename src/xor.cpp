/*
 * xor.cpp
 *
 *  Created on: Mar 31, 2018
 *      Author: Gerviba
 */

#include "xor.h"

gencrypt::Xor::Xor(Key key) : SymmetricEncription(key) {}

inline std::string gencrypt::Xor::code(std::string input) {
	for (int i = 0, len = input.length(); i < len; ++i)
		input[i] ^= this->key[i % this->key.getLength()];
	return input;
}

std::string gencrypt::Xor::getName() const {
	return "Xor";
}

std::string gencrypt::Xor::encode(std::string en) {
	return code(en);
}

std::istream& gencrypt::Xor::operator>>(std::istream& in) {
	return in;
}

std::string gencrypt::Xor::decode(std::string de) {
	return code(de);
}

std::ostream& gencrypt::Xor::operator<<(std::ostream& out) {
	return out;
}

std::ostream& gencrypt::operator<<(std::ostream& os, const Xor& obj) {
	return os;
}
