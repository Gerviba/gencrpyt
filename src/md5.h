/*
 * md5.h
 *
 *  Created on: Apr 26, 2018
 *      Author: root
 */

#ifndef SRC_MD5_H_
#define SRC_MD5_H_

#include "gencrypt.h"

namespace gencrypt {

class MD5: public HashAlgorithm {
public:
	MD5();
	std::string getName() const;
	std::string encode(std::string en);
};

} /* namespace gencrypt */

#endif /* SRC_MD5_H_ */
