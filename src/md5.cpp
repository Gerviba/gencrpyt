/*
 * md5.cpp
 *
 *  Created on: Apr 26, 2018
 *      Author: Gerviba
 */

#include "../src/md5.h"

#include <iostream>

#include "../src/md5impl.h"

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
	if (endl)
		os << md5(input) << std::endl;
	else
		os << md5(input);
}

} /* namespace gencrypt */
