/*
 * rot13.cpp
 *
 *  Created on: Mar 31, 2018
 *      Author: root
 */

#include <sstream>
#include "rot13.h"

std::string gencrypt::Rot13::getName() const {
	return "Rot13";
}

std::string gencrypt::Rot13::getType() const {
	return KeylessEncription::getType();
}

std::string gencrypt::Rot13::encode(std::string& in) {
//	std::string line;
//	in >> line;
//	std::cout << line;
	return in;
}

std::istream& gencrypt::Rot13::operator>>(std::istream& in) {
//	std::string line;
//	in >> line;
//	std::cout << line;
	return in;
}

std::string gencrypt::Rot13::decode(std::string out) {
//	std::cout << "--asd2--";
	return "TESTED";
}

//std::string gencrypt::Rot13::operator<<(const char* out) {
//	std::cout << "gencrypt::Rot13::operator<<(const char* out)" << std::endl;
////	std::stringstream ss;
////	ss << "r1";
//	return out;
//}

std::ostream& gencrypt::Rot13::operator<<(std::ostream& out) {
	std::cout << "gencrypt::Rot13::operator<<(std::ostream& out)" << std::endl;
//	std::stringstream ss;
//	ss << "r2";
	return out;
}


std::ostream& gencrypt::operator<<(std::ostream& os, const Rot13& obj) {
//	std::ostream stream;
//	stream << "####";
	return os;
}

//std::string gencrypt::operator<<(std::ostream& os, const Rot13& obj) {
////	std::ostream stream;
////	stream << "####";
//	return "asd";
//}




