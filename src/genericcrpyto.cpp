/*
 * genericencode.cpp
 *
 *  Created on: Mar 30, 2018
 *      Author: Gerviba
 */

#include <iostream>
#include "genericcrpyto.h"
#include "rot13.h"
#include "xor.h"

using namespace gencrypt;

int main(int argc, char **argv) {

	Rot13 r13;
	std::cout << r13.getType() << "\t"
			<< r13.getName() << "\t"
			<< r13.decode("Gerviba") << "\t"
			<< r13.encode(r13.decode("Gerviba")) << "\t"
			<< std::endl;

	Xor x(Key("1234567"));
	std::cout << x.getType() << "\t"
			<< x.getName() << "\t"
			<< x.decode("Gerviba") << "\t"
			<< x.encode(x.decode("Gerviba")) << "\t"
			<< std::endl;

	std::cout << std::endl;

	return 0;
}
