/*
 * base64.h
 *
 *  Created on: May 10, 2018
 *      Author: root
 */

#ifndef SRC_BASE64_H_
#define SRC_BASE64_H_

#include <iostream>
#include "gencrypt.h"

namespace gencrypt {

class Base64: public SymmetricEncription {
private:
	static std::string BASE64_CHARS;

	int calcIds(const std::string& de, size_t i);

public:
	Base64();
	std::string getName() const;
	std::string encode(std::string en);
	std::string decode(std::string de);
};

} /* namespace gencrypt */

#endif /* SRC_BASE64_H_ */
