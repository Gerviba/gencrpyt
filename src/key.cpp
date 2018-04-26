/*
 * key.cpp
 *
 *  Created on: Mar 31, 2018
 *      Author: Gerviba
 */

#include <iostream>
#include <cstdlib>
#include <string.h>
#include "key.h"

gencrypt::Key::Key() {
	this->key = NULL;
	this->length = 0;
}

gencrypt::Key::Key(const char* key) {
	this->length = strlen(key);
	this->key = new char[this->length + 1];
	strcpy(this->key, key);
}

gencrypt::Key::Key(const std::istream& file) {
	std::cout << "Key ios ctor " << this->length << std::endl;
	//TODO: Load from file
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

unsigned int gencrypt::Key::getLength() const {
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

