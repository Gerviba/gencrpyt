/*
 * rsa.cpp
 *
 * Converted to C++ and clean-ups by Szabó Gergely (Gerviba)
 * Based on: https://www.sanfoundry.com/cpp-program-implement-rsa-algorithm/
 */

#include "rsa.h"

#include <string.h>
#include <stdexcept>

#include <iostream>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

namespace gencrypt {

RSA::RSA(const PrimeKey* privateKey, const PrimeKey* publicKey, size_t size)
		: AsymmetricEncription(privateKey, publicKey) {

	p = privateKey->getPrime();
	if (!isPrime(p) && p != 0)
		throw std::invalid_argument("The private key is not a prime number");

	q = publicKey->getPrime();
	if (!isPrime(q) && q != 0)
		throw std::invalid_argument("The public key is not a prime number");

	if (p == q)
		throw std::invalid_argument("The private and the public keys are the same");

	e = new long int[100];
	d = new long int[100];
	temp = new long int[size];
	msg = new long int[size];
	en = new long int[size];
	this->size = size;

	n = p * q;
	t = (p - 1) * (q - 1);
	calcE();
}

std::string RSA::getName() const {
	return "RSA";
}

std::string RSA::encode(std::string en) {
	for (size_t i = 0; i < en.length(); i++)
		this->msg[i] = en[i];
	this->msg[en.length()] = '\0';
	return encrypt(en.length());
}

std::string RSA::decode(std::string de) {
	for (size_t index = 0; index < de.length(); index += 8) {
		converter conv;
		for (int bit = 0; bit < 8; ++bit)
			conv.c[bit] = de[index + bit];
		en[index / 8] = conv.l;
	}
	en[de.length() / 8] = -1;
	return decrypt();
}

void RSA::encode(std::istream& is, std::ostream& os, bool endl) {
	std::string input;
	std::getline(is, input);
	os << encode(input);
	if (endl)
		os << std::endl;
}

void RSA::decode(std::istream& is, std::ostream& os, bool endl) {
	std::string input;
	std::getline(is, input);
	os << decode(input);
	if (endl)
		os << std::endl;
}

bool RSA::isPrime(long int pr) { //TODO: Bool
	int j = sqrt(pr);
	for (int i = 2; i <= j; i++)
		if (pr % i == 0)
			return false;
	return true;
}

inline std::string RSA::encrypt(long int length) {
	long int pt, ct, key = e[0], k;
	int i = 0;
	while (i != length) {
		pt = msg[i];
		pt -= 96;
		k = 1;
		for (int j = 0; j < key; j++) {
			k *= pt;
			k %= n;
		}
		temp[i] = k;
		ct = k + 96;
		en[i] = ct;
		i++;
	}
	en[i] = -1;

	std::string result;
	for (size_t index = 0; en[index] != -1; ++index) {
		converter conv;
		conv.l = temp[index];
		for (int byte = 0; byte < 8; ++byte)
			result += conv.c[byte];
	}

	return result;
}

inline std::string RSA::decrypt() {
	long int pt, ct, key = d[0], k;
	int i = 0;
	while (en[i] != -1) {
		ct = en[i];
		k = 1;
		for (int j = 0; j < key; j++) {
			k *= ct;
			k %= n;
		}
		pt = k + 96;
		msg[i] = pt;
		i++;
	}
	msg[i] = -1;
	std::string result = "";
	for (i = 0; msg[i] != -1; i++)
		result += (char) msg[i];
	return result;
}

long int RSA::calcD(long int x) {
	long int k = 1;
	while (true) {
		k += t;
		if (k % x == 0)
			return (k / x);
	}
}

void RSA::calcE() {
	int k = 0;
	for (int i = 2; i < t; i++) {
		if (t % i == 0)
			continue;
		long int flag = isPrime(i);
		if (flag == 1 && i != p && i != q) {
			e[k] = i;
			flag = calcD(e[k]);
			if (flag > 0) {
				d[k] = flag;
				k++;
			}
			if (k == 99)
				break;
		}
	}
}

RSA::~RSA() {
	delete[] e;
	delete[] d;
	delete[] temp;
	delete[] msg;
	delete[] en;
}

} /* namespace gencrypt */
