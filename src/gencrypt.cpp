/*
 * gencrpyt.cpp
 *
 *  Created on: Mar 30, 2018
 *      Author: Gerviba
 */

#include <string>

#include "gencrypt.h"

// SymmetricEncription

bool gencrypt::SymmetricEncription::isSymmetric() const {
	return true;
}

std::string gencrypt::SymmetricEncription::getType() const {
	return "Symmetric";
}

Key const& gencrypt::SymmetricEncription::getKey() const {
	return this->key;
}

std::string gencrypt::KeylessEncription::getType() const {
	return "Keyless";
}

// AsymmetricEncription

bool gencrypt::AsymmetricEncription::isSymmetric() const {
	return false;
}

std::string gencrypt::AsymmetricEncription::getType() const {
	return "Asymmetric";
}

Key const& gencrypt::AsymmetricEncription::getPrivateKey() const {
	return this->privateKey;
}

Key const& gencrypt::AsymmetricEncription::getPublicKey() const {
	return this->publicKey;
}

// HashAlgorithm

std::string gencrypt::HashAlgorithm::getType() const {
	return "Hash";
}
