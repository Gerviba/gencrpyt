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
#include "rsa.h"
#include "md5.h"

using namespace gencrypt;

int main(int argc, char **argv) {

	//TODO: Add GTEST_LITE tests

	std::cout << ">> Test #1: Encode Decode" << std::endl;

	Rot13 r13;
	std::cout << r13.getType() << "\t"
			<< r13.getName() << "\t"
			<< r13.encode("Gerviba") << "\t"
			<< r13.decode(r13.encode("Gerviba")) << "\t"
			<< std::endl;

	Xor x(Key("1234567"));
	std::cout << x.getType() << "\t"
			<< x.getName() << "\t"
			<< x.encode("Gerviba") << "\t"
			<< x.decode(x.encode("Gerviba")) << "\t"
			<< std::endl;

	RSA rsa(Key("private"), Key("public"));
	std::cout << rsa.getType() << "\t"
			<< rsa.getName() << "\t"
			<< rsa.encode("Gerviba") << "\t"
			<< rsa.decode(rsa.encode("Gerviba")) << "\t"
			<< std::endl;

	MD5 md5;
	std::cout << md5.getType() << "\t\t"
			<< md5.getName() << "\t"
			<< md5.encode("Gerviba") << "\t"
			<< std::endl;

	std::cout << ">> Test #2: Collection" << std::endl;

	CryptoAlgorithm *algorithms[4];
	algorithms[0] = &r13;
	algorithms[1] = &x;
	algorithms[2] = &rsa;
	algorithms[3] = &md5;

	std::cout << ">> Test #2.1: Encode and Decode" << std::endl;

	for (int i = 0; i < 4; ++i)
		if (algorithms[i]->isTwoWay())
			std::cout << algorithms[i]->getName() << "\t"
					<< ((TwoWayEncription*)algorithms[i])->decode(
							((TwoWayEncription*)algorithms[i])->encode("Test"))
					<< std::endl;

	std::cout << ">> Test #2.2: Encode only hashes" << std::endl;

	for (int i = 0; i < 4; ++i)
		if (!algorithms[i]->isTwoWay())
			std::cout << algorithms[i]->getName() << "\t"
					<< ((HashAlgorithm*)algorithms[i])->encode("Test")
					<< std::endl;

	std::cout << ">> Test #3: Encode from stdin" << std::endl;

	std::string input;
	std::cin >> input;

	for (int i = 0; i < 4; ++i)
		std::cout << algorithms[i]->getName() << "\t"
				<< algorithms[i]->encode(input) << std::endl;

	std::cout << std::endl;

	return 0;
}
