/*
 * genericencode.cpp
 *
 *  Created on: Mar 30, 2018
 *      Author: root
 */

#include <iostream>
#include "genericcrpyto.h"
#include "rot13.h"
using namespace gencrypt;



int main(int argc, char **argv) {
	Rot13 r13;
//	r13 << "Gerviba";
//	r13.ss(). << "Treivon";
//	std::cout << "";
	std::cout << r13.getType() << "\t" << r13.getName() << "\t" << r13.decode("Gerviba") << std::endl;
	std::cout << std::endl;

	return 0;
}
