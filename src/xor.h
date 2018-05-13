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
	Xor(const Key* key);
	std::string getName() const;
	std::string encode(std::string en);
	void encode(std::istream& is, std::ostream& os, bool endl = true);
	std::string decode(std::string de);
	void decode(std::istream& is, std::ostream& os, bool endl = true);
};

} /* namespace gencrypt */

#endif /* SRC_XOR_H_ */
