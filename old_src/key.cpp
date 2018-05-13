/*
 * key.cpp
 *
 *  Created on: Mar 31, 2018
 *      Author: Gerviba
 */

#include <iostream>
#include <cstdlib>
#include <string.h>
#include <algorithm>
#include "key.h"
#include <iomanip>

gencrypt::Key::Key() {
	this->key = NULL;
	this->length = 0;
}

gencrypt::Key::Key(const char* key) {
	this->length = strlen(key);
	this->key = new char[this->length + 1];
	strcpy(this->key, key);
}

gencrypt::Key::Key(std::istream& is) {
	std::string temp;
	getline(is, temp);
	this->key = NULL;
	this->length = 0;
}

gencrypt::Key::Key(const Key& key) {
	this->length = key.length;
	this->key = new char[this->length + 1];
	strcpy(this->key, key.key);
}

char *gencrypt::Key::getRawKey() const {
	return this->key;
}

size_t gencrypt::Key::getLength() const {
	return this->length;
}

char gencrypt::Key::operator[](unsigned int index) const {
	return this->key[index];
}

char gencrypt::Key::getByteAt(unsigned int index) const {
	return this->key[index];
}

gencrypt::Key::~Key() {
	delete[] this->key;
}

gencrypt::PrimeKey::PrimeKey(long int prime) {
	this->key = NULL;
	this->length = 0;
	this->prime = prime;
//	this->key = new char[9];
//	this->length = 8;
//	for (size_t i = 0; i < 8; ++i) {
//		std::cout << std::hex << ((prime & (255l << ((7 - i) * 8))) >> ((7 - i) * 8)) << std::endl;
//		this->key[i] = ((prime & (255l << ((7 - i) * 8))) >> ((7 - i) * 8));
//	}
//	this->key[8] = '\0';
//	std::cout << (int) this->key[7] << " " << (int) this->key[6]
//			<< " " << (int) this->key[5] << " " << (int) this->key[4]
//			<< " " << (int) this->key[3] << " " << (int) this->key[2]
//			<< " " << (int) this->key[1] << " " << (int) this->key[0] << std::endl;
}

long int gencrypt::PrimeKey::getPrime() const {
//	long int result = 0;
//	for (size_t i = 0; i < 8; ++i)
//		result |= this->key[i] << (i * 8);
//	return result;
	return prime;
}
