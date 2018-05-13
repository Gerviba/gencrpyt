/*
 * base64.h
 *
 *  Created on: May 10, 2018
 *      Author: Gerviba
 */

#ifndef SRC_BASE64_H_
#define SRC_BASE64_H_

#include <iostream>

#include "gencrypt.h"

namespace gencrypt {

class Base64: public SymmetricEncription {
private:
	int calcIds(const std::string& de, size_t i);

public:
	Base64();
	std::string getName() const;
	std::string encode(std::string en);
	void encode(std::istream& is, std::ostream& os, bool endl = true);
	std::string decode(std::string de);
	void decode(std::istream& is, std::ostream& os, bool endl = true);
};

} /* namespace gencrypt */

#endif /* SRC_BASE64_H_ */
