/*
 * md5.cpp
 *
 *  Created on: Apr 26, 2018
 *      Author: root
 */

#include "md5.h"
#include "md5impl.h"

namespace gencrypt {

MD5Hasher::MD5Hasher() {}

std::string MD5Hasher::getName() const {
	return "MD5";
}

std::string MD5Hasher::encode(std::string en) {
	return md5(en);
}

} /* namespace gencrypt */
