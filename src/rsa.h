/*
 * rsa.h
 *
 *  Created on: Apr 26, 2018
 *      Author: root
 *
 *
 * https://www.sanfoundry.com/cpp-program-implement-rsa-algorithm/
 */

#ifndef SRC_RSA_H_
#define SRC_RSA_H_

#include "gencrypt.h"

namespace gencrypt {

class RSA: public AsymmetricEncription {
private:
	long int p, q, n, t, flag, e[100], d[100], temp[100], j, m[100], en[100], i;
	char msg[100];
public:
	RSA(Key const& privateKey, Key const& publicKey);
	std::string getName() const;
	std::string encode(std::string en);
	std::string decode(std::string de);
	int prime(long int);
	void ce();
	long int cd(long int);
	void encrypt();
	void decrypt();
	int rsa();
};

} /* namespace gencrypt */

#endif /* SRC_RSA_H_ */
