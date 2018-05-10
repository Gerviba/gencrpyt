/*
 * key.h
 *
 *  Created on: Mar 31, 2018
 *      Author: Gerviba
 */

#ifndef SRC_KEY_H_
#define SRC_KEY_H_

#include <iostream>

namespace gencrypt {

class Key {
protected:
	char *key;
	size_t length;
public:
	Key();
	Key(const char* key);
	Key(std::istream& is);
	Key(const Key& key);
	char *getRawKey() const;
	size_t getLength() const;
	char operator[](unsigned int index) const;
	char getByteAt(unsigned int index) const;
	virtual ~Key();
};

class PrimeKey: public Key {
private:
	long int prime;
public:
	PrimeKey() : Key() {};
	PrimeKey(const char* key) : Key(key) {};
	PrimeKey(std::istream& is) : Key(is) {};
	PrimeKey(const PrimeKey& key) : Key(key) {};
	PrimeKey(long int prime);
	long int getPrime() const;
	virtual ~PrimeKey() {};
};

} /* namespace gencrypt */

#endif /* SRC_KEY_H_ */
