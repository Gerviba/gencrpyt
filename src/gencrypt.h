/*
 * gencrpyt.h
 *
 *  Created on: Mar 30, 2018
 *      Author: Gerviba
 */

#ifndef SRC_GENCRYPT_H_
#define SRC_GENCRYPT_H_

#include <iostream>
#include <string>

#include "key.h"

namespace gencrypt {

class CryptoAlgorithm {
private:
	CryptoAlgorithm& operator=(const CryptoAlgorithm& rhs);
public:
	CryptoAlgorithm() {};
	CryptoAlgorithm(const CryptoAlgorithm& obj) {};
	virtual std::string getName() const = 0;
	virtual std::string getType() const = 0;
	virtual std::string encode(std::string in) = 0;
	virtual void encode(std::istream& is, std::ostream& os, bool endl = true) = 0;
	virtual bool isTwoWay() const = 0;
	virtual ~CryptoAlgorithm() {};
};

class TwoWayEncription: public CryptoAlgorithm {
public:
	virtual std::string decode(std::string out) = 0;
	virtual void decode(std::istream& is, std::ostream& os, bool endl = true) = 0;
	virtual bool isSymmetric() const = 0;
	virtual bool isTwoWay() const;
};

class SymmetricEncription: public TwoWayEncription {
protected:
	const Key* key;
public:
	SymmetricEncription() : key(new Key()) {}
	SymmetricEncription(const Key* key) : key(key) {}
	const Key* getKey() const;
	bool isSymmetric() const;
	virtual std::string getType() const;
	virtual ~SymmetricEncription() {
		delete key;
	}
};

class AsymmetricEncription: public TwoWayEncription {
protected:
	const Key* privateKey;
	const Key* publicKey;
public:
	AsymmetricEncription(const Key* privateKey, const Key* publicKey)
		: privateKey(privateKey), publicKey(publicKey) {}
	const Key* getPrivateKey() const;
	const Key* getPublicKey() const;
	bool isSymmetric() const;
	virtual std::string getType() const;
	virtual ~AsymmetricEncription() {
		delete privateKey;
		delete publicKey;
	}
};

class HashAlgorithm: public CryptoAlgorithm {
public:
	std::string getType() const;
	virtual bool isTwoWay() const;
};

} /* namespace gencrypt */

#endif /* SRC_GENCRYPT_H_ */
