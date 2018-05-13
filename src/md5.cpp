/*
 * md5.cpp
 *
 *  Created on: Apr 26, 2018
 *      Author: Gerviba
 */

#include "md5.h"

#include <iostream>

#include "md5impl.h"

namespace gencrypt {

MD5Hasher::MD5Hasher() {}

std::string MD5Hasher::getName() const {
	return "MD5";
}

std::string MD5Hasher::encode(std::string en) {
	return md5(en);
}

void MD5Hasher::encode(std::istream& is, std::ostream& os, bool endl) {
	std::string input;
	std::getline(is, input);
	os << md5(input);
	if (endl)
		os << std::endl;
}

} /* namespace gencrypt */
