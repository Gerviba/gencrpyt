/*
 * gencrpyt.cpp
 *
 *  Created on: Mar 30, 2018
 *      Author: Gerviba
 */

#include "gencrypt.h"
#include <string>
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

const gencrypt::Key* gencrypt::SymmetricEncription::getKey() const {
	return this->key;
}

// AsymmetricEncription

bool gencrypt::AsymmetricEncription::isSymmetric() const {
	return false;
}

std::string gencrypt::AsymmetricEncription::getType() const {
	return "Asymmetric";
}

const gencrypt::Key* gencrypt::AsymmetricEncription::getPrivateKey() const {
	return this->privateKey;
}

const gencrypt::Key* gencrypt::AsymmetricEncription::getPublicKey() const {
	return this->publicKey;
}

// HashAlgorithm

std::string gencrypt::HashAlgorithm::getType() const {
	return "Hash";
}

bool gencrypt::HashAlgorithm::isTwoWay() const {
	return false;
}
