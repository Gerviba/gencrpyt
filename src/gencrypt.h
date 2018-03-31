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
	virtual std::istream& operator>>(std::istream& in) = 0;
	virtual ~CryptoAlgorithm() {};
};

class TwoWayEncription: public CryptoAlgorithm {
public:
	virtual std::string decode(std::string out) = 0;
	virtual std::ostream& operator<<(std::ostream& out) = 0;
	virtual bool isSymmetric() const = 0;
};

class SymmetricEncription: public TwoWayEncription {
protected:
	Key const& key;
public:
	SymmetricEncription() : key(Key()) {}
	SymmetricEncription(Key key) : key(key) {}
	Key const& getKey() const;
	bool isSymmetric() const;
	virtual std::string getType() const;
};

class AsymmetricEncription: public TwoWayEncription {
protected:
	Key const& privateKey;
	Key const& publicKey;
public:
	AsymmetricEncription(Key privateKey, Key publicKey)
		: privateKey(privateKey), publicKey(publicKey) {}
	Key const& getPrivateKey() const;
	Key const& getPublicKey() const;
	bool isSymmetric() const;
	std::string getType() const;
};

class HashAlgorithm: public CryptoAlgorithm {
public:
	std::string getType() const;
};

} /* namespace gencrypt */

#endif /* SRC_GENCRYPT_H_ */
