/*
 * rot13.h
 *
 *  Created on: Mar 31, 2018
 *      Author: root
 */

#ifndef SRC_ROT13_H_
#define SRC_ROT13_H_

#include "gencrypt.h"

namespace gencrypt {

class Rot13: KeylessEncription {
public:
	Rot13() {}
	std::string getName() const;
	virtual std::string getType() const;
	std::string encode(std::string& in);
	std::istream& operator>>(std::istream& in);
	std::string decode(std::string out);
	std::ostream& operator<<(std::ostream& out);

};

std::ostream& operator<<(std::ostream& os, const Rot13& obj);

}


#endif /* SRC_ROT13_H_ */
