/*
 * xor.h
 *
 *  Created on: Mar 31, 2018
 *      Author: Gerviba
 */

#ifndef SRC_XOR_H_
#define SRC_XOR_H_

#include "gencrypt.h"

namespace gencrypt {

class Xor: public SymmetricEncription {
private:
	inline std::string code(std::string input);
	Xor();
public:
	Xor(Key const& key);
	std::string getName() const;
	std::string encode(std::string en);
	std::string decode(std::string de);
};

} /* namespace gencrypt */

#endif /* SRC_XOR_H_ */
