/*
 * md5.cpp
 *
 *  Created on: Apr 26, 2018
 *      Author: root
 */

#include "md5.h"

namespace gencrypt {

MD5::MD5() {}

std::string MD5::getName() const {
	return "MD5";
}

std::string MD5::encode(std::string en) {
	return en;
}

} /* namespace gencrypt */
