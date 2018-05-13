/*
 * rot13.h
 *
 *  Created on: Mar 31, 2018
 *      Author: Gerviba
 */

#ifndef SRC_ROT13_H_
#define SRC_ROT13_H_

#include "gencrypt.h"

namespace gencrypt {

class Rot13: public SymmetricEncription {
private:
	inline std::string code(std::string input);
	static std::string UPPERCASE;
	static std::string LOWERCASE;
public:
	Rot13() {}
	std::string getName() const;
	std::string encode(std::string en);
	std::string decode(std::string de);

};

} /* namespace gencrypt */

#endif /* SRC_ROT13_H_ */
