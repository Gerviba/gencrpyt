/*
 * rsa.cpp
 *
 *  Created on: Apr 26, 2018
 *      Author: root
 */

#include "rsa.h"

namespace gencrypt {

RSA::RSA(Key const& privateKey, Key const& publicKey)
		: AsymmetricEncription(privateKey, publicKey) {}

std::string RSA::getName() const {
	return "RSA";
}

std::string RSA::encode(std::string en) {
	return en;
}

std::string RSA::decode(std::string de) {
	return de;
}

} /* namespace gencrypt */
