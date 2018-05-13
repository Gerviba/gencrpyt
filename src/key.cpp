/*
 * key.cpp
 *
 *  Created on: Mar 31, 2018
 *      Author: Gerviba
 */

#include "key.h"

#include <iostream>
#include <cstdlib>
#include <string.h>
#include <algorithm>
#include <iomanip>
#include <stdexcept>

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
	this->length = temp.length();
	this->key = new char[this->length + 1];
	strcpy(this->key, temp.c_str());
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
	if (index < 0 || index >= length)
		throw std::out_of_range("Out of range");
	return this->key[index];
}

gencrypt::Key::~Key() {
	delete[] this->key;
}

gencrypt::PrimeKey::PrimeKey(long int prime) {
	this->key = NULL;
	this->length = 0;
	this->prime = prime;
}

gencrypt::PrimeKey::PrimeKey(std::istream& is) {
	this->prime = 0;
	is >> this->prime;
	is.ignore(1);

	this->key = NULL;
	this->length = 0;
}

gencrypt::PrimeKey* gencrypt::PrimeKey::BLANK() {
	return new PrimeKey();
}

long int gencrypt::PrimeKey::getPrime() const {
	return prime;
}
