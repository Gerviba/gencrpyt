/*
 * rsa.h
 *
 *  Created on: Apr 26, 2018
 *      Author: root
 */

#ifndef SRC_RSA_H_
#define SRC_RSA_H_

#include "gencrypt.h"

namespace gencrypt {

class RSA: public AsymmetricEncription {
public:
	RSA(Key const& privateKey, Key const& publicKey);
	std::string getName() const;
	std::string encode(std::string en);
	std::string decode(std::string de);
};

} /* namespace gencrypt */

#endif /* SRC_RSA_H_ */
