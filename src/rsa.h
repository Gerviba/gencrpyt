/*
 * rsa.h
 *
 *  Created on: Apr 26, 2018
 *
 * Converted to C++ and clean-ups by Szabó Gergely (Gerviba)
 * Based on: https://www.sanfoundry.com/cpp-program-implement-rsa-algorithm/
 */

#ifndef SRC_RSA_H_
#define SRC_RSA_H_

#include "gencrypt.h"

namespace gencrypt {

class RSA: public AsymmetricEncription {
private:
	long int p, q, n, t;
	long int* e;
	long int* d;
	long int* temp;
	long int* msg;
	long int* en;
	size_t size;
	bool isPrime(long int);
	void calcE();
	long int calcD(long int);
	inline std::string encrypt(long int length);
	inline std::string decrypt();
public:
	RSA(const PrimeKey* privateKey, const PrimeKey* publicKey, size_t size = 100);
	std::string getName() const;
	std::string encode(std::string en);
	void encode(std::istream& is, std::ostream& os, bool endl = true);
	std::string decode(std::string de);
	void decode(std::istream& is, std::ostream& os, bool endl = true);
	virtual ~RSA();
};

union converter {
	long int l;
	struct {
		char c[8];
	};
};

} /* namespace gencrypt */

#endif /* SRC_RSA_H_ */
