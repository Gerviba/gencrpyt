/*
 * genericcrypto.cpp
 *
 *  Created on: Mar 30, 2018
 *      Author: Gerviba
 */

#include "memtrace.h"
#include "gtest_lite.h"

#include <iostream>
#include "genericcrpyto.h"

#include "linkedcollection.hpp"
#include "md5.h"
#include "rot13.h"
#include "xor.h"
#include "base64.h"
#include "rsa.h"

using namespace gencrypt;

int main(int argc, char **argv) {

	//TODO: Add GTEST_LITE tests
#ifdef MEMTRACE
	std::cout << "MEMTRACE" << std::endl;
#endif

	TEST(Key, value) {
		Key key("private key");
		EXPECT_STREQ("private key", key.getRawKey()) << "Invalid key value" << std::endl;
	} ENDM

	TEST(PrimeKey, prime) {
		PrimeKey pkey1(2147483647);
		EXPECT_EQ(2147483647L, pkey1.getPrime()) << "Invalid key number" << std::endl;

		PrimeKey pkey2(0L);
		EXPECT_EQ(0L, pkey2.getPrime()) << "Invalid key number" << std::endl;

		PrimeKey pkey3(999999999999999L);
		EXPECT_EQ(0L, pkey2.getPrime()) << "Invalid key number" << std::endl;
	} ENDM

	TEST(EncodeDecode, rot13) {
		Rot13 r13;

		EXPECT_STREQ("Rot13", r13.getName().c_str())
				<< "Invalid name for Base64" << std::endl;
		EXPECT_STREQ("Symmetric", r13.getType().c_str())
				<< "Invalid type for Base64" << std::endl;

		EXPECT_STREQ("Treivon", r13.encode("Gerviba").c_str())
				<< "Invalid Rot13 encoded value" << std::endl;

		EXPECT_STREQ("TestMePls", r13.decode("GrfgZrCyf").c_str())
				<< "Invalid Rot13 encoded value" << std::endl;

		EXPECT_STREQ("RandomTestString123", r13.decode(r13.encode("RandomTestString123")).c_str())
				<< "Invalid Rot13 encoded and re-decoded value" << std::endl;
	} ENDM

	TEST(EncodeDecode, xor) {
		Key k1("1234567");
		Xor x1(k1);

		EXPECT_STREQ("Xor", x1.getName().c_str())
				<< "Invalid name for Xor" << std::endl;
		EXPECT_STREQ("Symmetric", x1.getType().c_str())
				<< "Invalid type for Xor" << std::endl;

		EXPECT_STREQ("vWAB\\TV", x1.encode("Gerviba").c_str())
				<< "Invalid Xor encoded value" << std::endl;

		EXPECT_STREQ("TestMePls", x1.decode("eW@@xSg]A").c_str())
				<< "Invalid Xor encoded value" << std::endl;

		EXPECT_STREQ("RandomTestString123", x1.decode(x1.encode("RandomTestString123")).c_str())
				<< "Invalid Xor encoded and re-decoded value" << std::endl;

		Key k2("ABCDEFGHIJKLMNO"); //TODO: Allocate space for k2
		Xor x2(k2);
		EXPECT_STRNE(x1.encode("foobar").c_str(), x2.encode("foobar").c_str())
				<< "Both keys are the same or too much similar" << std::endl;
	} ENDM

	TEST(EncodeDecode, base64) {
		Base64 b64;

		EXPECT_STREQ("Base64", b64.getName().c_str())
				<< "Invalid name for Base64" << std::endl;
		EXPECT_STREQ("Symmetric", b64.getType().c_str())
				<< "Invalid type for Base64" << std::endl;

		EXPECT_STREQ("R2VydmliYQ==", b64.encode("Gerviba").c_str())
				<< "Invalid Xor encoded value" << std::endl;

		EXPECT_STREQ("TestMePls", b64.decode("VGVzdE1lUGxz").c_str())
				<< "Invalid Xor encoded value" << std::endl;

		EXPECT_STREQ("RandomTestString123", b64.decode(b64.encode("RandomTestString123")).c_str())
				<< "Invalid Xor encoded and re-decoded value" << std::endl;
	} ENDM

	RSA rsa(PrimeKey(11), PrimeKey(97));
	std::cout << rsa.getType() << "\t"
			<< rsa.getName() << "\t"
			<< rsa.encode("Gerviba") << "\t"
			<< rsa.decode(rsa.encode("Gerviba")) << "\t"
			<< std::endl;

	TEST(EncodeDecode, md5) {
		MD5Hasher md5;

		EXPECT_STREQ("MD5", md5.getName().c_str())
				<< "Invalid name for MD5" << std::endl;
		EXPECT_STREQ("Hash", md5.getType().c_str())
				<< "Invalid type for MD5" << std::endl;

		EXPECT_STREQ("d41d8cd98f00b204e9800998ecf8427e", md5.encode("").c_str())
				<< "Invalid value for empty input" << std::endl;

		EXPECT_STREQ("5fdadcb312051c615e90bde1e5bce70c", md5.encode("Gerviba").c_str())
				<< "Invalid Xor encoded value" << std::endl;

		EXPECT_STREQ("201730d4278e576b25515bd90c6072d3", md5.encode("lorem ipsum dolor sit amet").c_str())
				<< "Invalid Xor encoded and re-decoded value" << std::endl;
	} ENDM

	std::cout << ">> Test #2: Collection" << std::endl;


	TEST(Collection, storeAndRead) {
		LinkedCollection<CryptoAlgorithm> collection;
		collection.append(new Rot13());
		collection.append(new Xor(Key("1234567")));
		collection.append(new MD5Hasher());

		for (LinkedCollection<CryptoAlgorithm>::Iterator it = collection.iterator(); it.notNull(); ++it)
			std::cout << (*it)->getName() << std::endl;

		LinkedCollection<CryptoAlgorithm>::Iterator it = collection.iterator();
		EXPECT_STREQ("Rot13", (*it)->getName().c_str())
				<< "Invalid name or the collection my be broken" << std::endl;
		++it;
		EXPECT_STREQ("Xor", (*it)->getName().c_str())
				<< "Invalid name or the collection my be broken" << std::endl;
		++it;
		EXPECT_STREQ("MD5", (*it)->getName().c_str())
				<< "Invalid name or the collection my be broken" << std::endl;
//		++it;
//		EXPECT_TRUE((*it) == NULL)
//				<< "The collection is longer than expected" << std::endl;
	} ENDM

//	CryptoAlgorithm *algorithms[4];
//	algorithms[0] = &r13;
//	algorithms[1] = &x;
//	algorithms[2] = &rsa;
//	algorithms[3] = &md5;

	std::cout << ">> Test #2.1: Encode and Decode" << std::endl;

//
//	for (LinkedCollection<CryptoAlgorithm>::Iterator it = collection.iterator(); it.notNull(); ++it)
//		if ((*it)->isTwoWay())
//			std::cout << (*it)->getName() << "\t"
//					<< ((TwoWayEncription*)*it)->decode(
//							((TwoWayEncription*)*it)->encode("Test"))
//					<< std::endl;
//
////	for (int i = 0; i < 4; ++i)
////		if (algorithms[i]->isTwoWay())
////			std::cout << algorithms[i]->getName() << "\t"
////					<< ((TwoWayEncription*)algorithms[i])->decode(
////							((TwoWayEncription*)algorithms[i])->encode("Test"))
////					<< std::endl;
//
//	std::cout << ">> Test #2.2: Encode only hashes" << std::endl;
//
//	for (LinkedCollection<CryptoAlgorithm>::Iterator it = collection.iterator(); it.notNull(); ++it)
//		if (!(*it)->isTwoWay())
//			std::cout << (*it)->getName() << "\t"
//					<< ((HashAlgorithm*)(*it))->encode("Test")
//					<< std::endl;
//
////	for (int i = 0; i < 4; ++i)
////		if (!algorithms[i]->isTwoWay())
////			std::cout << algorithms[i]->getName() << "\t"
////					<< ((HashAlgorithm*)algorithms[i])->encode("Test")
////					<< std::endl;
//
//	std::cout << ">> Test #3: Encode from stdin" << std::endl;
//
//	std::string input;
//	std::cin >> input;
//
////	for (int i = 0; i < 4; ++i)
////		std::cout << algorithms[i]->getName() << "\t"
////				<< algorithms[i]->encode(input) << std::endl;
//
//	for (LinkedCollection<CryptoAlgorithm>::Iterator it = collection.iterator(); it.notNull(); ++it)
//		std::cout << (*it)->getName() << "\t"
//				<< (*it)->encode(input) << std::endl;
//
//
//	std::cout << std::endl;

//	rsa.rsa();

	return 0;
}
