/*
 * gencrpyt.cpp
 *
 *  Created on: Mar 30, 2018
 *      Author: Gerviba
 */

#include <string>

#include "gencrypt.h"
#include "key.h"

// TwoWay

bool gencrypt::TwoWayEncription::isTwoWay() const {
	return true;
}

// SymmetricEncription

bool gencrypt::SymmetricEncription::isSymmetric() const {
	return true;
}

std::string gencrypt::SymmetricEncription::getType() const {
	return "Symmetric";
}

gencrypt::Key const& gencrypt::SymmetricEncription::getKey() const {
	return this->key;
}

// AsymmetricEncription

bool gencrypt::AsymmetricEncription::isSymmetric() const {
	return false;
}

std::string gencrypt::AsymmetricEncription::getType() const {
	return "Asymmetric";
}

gencrypt::Key const& gencrypt::AsymmetricEncription::getPrivateKey() const {
	return this->privateKey;
}

gencrypt::Key const& gencrypt::AsymmetricEncription::getPublicKey() const {
	return this->publicKey;
}

// HashAlgorithm

std::string gencrypt::HashAlgorithm::getType() const {
	return "Hash";
}

bool gencrypt::HashAlgorithm::isTwoWay() const {
	return false;
}
