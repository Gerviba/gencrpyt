/*
 * genericcrypto.cpp
 *
 *  Created on: Mar 30, 2018
 *      Author: Gerviba
 */

#include <iostream>
#include <stdexcept>
#include <sstream>

#include "../_src/memtrace.h"
#include "../src/base64.h"
#include "../src/gtest_lite.h"
#include "../src/linkedcollection.hpp"
#include "../src/md5.h"
#include "../src/rot13.h"
#include "../src/rsa.h"
#include "../src/xor.h"

using namespace gencrypt;

int main(int argc, char **argv) {

	TEST(Key, value) {
		Key key("private key");
		EXPECT_STREQ("private key", key.getRawKey())
				<< "Invalid key value" << std::endl;

		std::ifstream ifs("xor_key");
		Key key2(ifs);
		ifs.close();
		EXPECT_STREQ("Deal_with_IIT_secret_xor_key", key2.getRawKey())
				<< "Invalid key value from stream" << std::endl;
	} ENDM

	TEST(PrimeKey, prime) {
		PrimeKey pkey1(2147483647);
		EXPECT_EQ(2147483647L, pkey1.getPrime()) << "Invalid key number" << std::endl;

		PrimeKey pkey2(0L);
		EXPECT_EQ(0L, pkey2.getPrime()) << "Invalid key number" << std::endl;

		PrimeKey pkey3(999999999999999L);
		EXPECT_EQ(0L, pkey2.getPrime()) << "Invalid key number" << std::endl;

		std::ifstream ifs("prime_key");
		PrimeKey ifpkey1(ifs);
		EXPECT_EQ(59l, ifpkey1.getPrime())
				<< "Invalid key value from stream" << std::endl;
		PrimeKey ifpkey2(ifs);
		EXPECT_EQ(131l, ifpkey2.getPrime())
				<< "Invalid key value from stream" << std::endl;
		PrimeKey ifpkey3(ifs);
		EXPECT_EQ(31l, ifpkey3.getPrime())
				<< "Invalid key value from stream" << std::endl;
		ifs.close();

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
		Xor x1(new Key("1234567"));

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

		Xor x2(new Key("ABCDEFGHIJKLMNO"));
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

	TEST(EncodeDecode, rsaExceptions) {

		EXPECT_THROW({RSA rsa(new PrimeKey(10), new PrimeKey(97));}, std::invalid_argument&)
				<< "Prime check failed (private key)" << std::endl;
		EXPECT_THROW({RSA rsa(new PrimeKey(97), new PrimeKey(42));}, std::invalid_argument&)
				<< "Prime check failed (public key)" << std::endl;
		EXPECT_THROW({RSA rsa(new PrimeKey(13), new PrimeKey(13));}, std::invalid_argument&)
				<< "Prime check failed (equals check)" << std::endl;

	} ENDM

	TEST(EncodeDecode, rsaSingle) {

		RSA rsa(new PrimeKey(11), new PrimeKey(97), 30);

		EXPECT_STREQ("RandomTestString123", rsa.decode(rsa.encode("RandomTestString123")).c_str())
				<< "Invalid RSA encoded and re-decoded value" << std::endl;

		RSA in(new PrimeKey(47), new PrimeKey(67), 30);
		RSA out(new PrimeKey(47), new PrimeKey(67), 30);

		EXPECT_STREQ("foobar", out.decode(in.encode("foobar")).c_str())
				<< "Failed to code and decode RSA message" << std::endl;

	} ENDM

	TEST(EncodeDecode, rsaSwitch) {

		RSA in(new PrimeKey(47), new PrimeKey(67), 30);
		RSA out(new PrimeKey(67), new PrimeKey(47), 30);

		EXPECT_STREQ("foobar", out.decode(in.encode("foobar")).c_str())
				<< "Failed to code and decode RSA message" << std::endl;

	} ENDM

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

	TEST(Collection, storeAndRead) {
		LinkedCollection<CryptoAlgorithm> collection;
		collection.append(new Rot13());
		collection.append(new Xor(new Key("1234567")));
		collection.append(new MD5Hasher());
		collection.append(new Base64());
		collection.append(new RSA(new PrimeKey(11), new PrimeKey(97)));

		LinkedCollection<CryptoAlgorithm>::Iterator it = collection.iterator();
		EXPECT_STREQ("Rot13", (*it)->getName().c_str())
				<< "Invalid name or the collection my be broken" << std::endl;
		EXPECT_STREQ("Symmetric", (*it)->getType().c_str())
				<< "Invalid type or the collection my be broken" << std::endl;
		++it;
		EXPECT_STREQ("Xor", (*it)->getName().c_str())
				<< "Invalid name or the collection my be broken" << std::endl;
		EXPECT_STREQ("Symmetric", (*it)->getType().c_str())
				<< "Invalid type or the collection my be broken" << std::endl;
		++it;
		EXPECT_STREQ("MD5", (*it)->getName().c_str())
				<< "Invalid name or the collection my be broken" << std::endl;
		EXPECT_STREQ("Hash", (*it)->getType().c_str())
				<< "Invalid type or the collection my be broken" << std::endl;
		++it;
		EXPECT_STREQ("Base64", (*it)->getName().c_str())
				<< "Invalid name or the collection my be broken" << std::endl;
		EXPECT_STREQ("Symmetric", (*it)->getType().c_str())
				<< "Invalid type or the collection my be broken" << std::endl;
		++it;
		EXPECT_STREQ("RSA", (*it)->getName().c_str())
				<< "Invalid name or the collection my be broken" << std::endl;
		EXPECT_STREQ("Asymmetric", (*it)->getType().c_str())
				<< "Invalid type or the collection my be broken" << std::endl;
		++it;
		EXPECT_FALSE(it.notNull())
				<< "The collection is longer than expected" << std::endl;
	} ENDM

	TEST(Collection, storeAndRead) {
		LinkedCollection<CryptoAlgorithm> collection;
		collection.append(new Rot13());
		collection.append(new Xor(new Key("1234567")));
		collection.append(new MD5Hasher());
		collection.append(new Base64());
		collection.append(new RSA(new PrimeKey(47), new PrimeKey(101)));

		for (LinkedCollection<CryptoAlgorithm>::Iterator it = collection.iterator(); it.notNull(); ++it)
			if ((*it)->isTwoWay())
				EXPECT_STREQ("Test", ((TwoWayEncription*)*it)
						->decode(((TwoWayEncription*)*it)->encode("Test")).c_str())
					<< "Failed to use: " << (*it)->getName() << std::endl;

		for (LinkedCollection<CryptoAlgorithm>::Iterator it = collection.iterator(); it.notNull(); ++it)
			if (!(*it)->isTwoWay())
					EXPECT_STRNE("Test", ((TwoWayEncription*)*it)->encode("Test").c_str())
						<< "Failed to use: " << (*it)->getName() << std::endl;
	} ENDM

	TEST(Collection, streams) {
		LinkedCollection<CryptoAlgorithm> collection;
		collection.append(new Rot13());
		std::ifstream ifsXor("xor_key");
		collection.append(new Xor(new Key(ifsXor)));
		ifsXor.close();
		collection.append(new MD5Hasher());
		collection.append(new Base64());
		std::ifstream ifsRsa("rsa_keys");
		collection.append(new RSA(new PrimeKey(ifsRsa), new PrimeKey(ifsRsa)));
		ifsRsa.close();

		for (LinkedCollection<CryptoAlgorithm>::Iterator it = collection.iterator(); it.notNull(); ++it) {
			if (!(*it)->isTwoWay())
				continue;

			std::ifstream ifsRef("encode_list");
			std::string actual;
			std::getline(ifsRef, actual);
			ifsRef.close();

			std::ifstream ifs("encode_list");
			std::stringstream ss;
			((TwoWayEncription*)*it)->encode(ifs, ss);
			std::stringstream oss;
			((TwoWayEncription*)*it)->decode(ss, oss);

			std::string converted;
			std::getline(oss, converted);

			EXPECT_STREQ(actual.c_str(), converted.c_str())
				<< "Failed to use: " << (*it)->getName() << std::endl;
		}

	} ENDM

	TEST(Collection, md5_streams) {
		std::istringstream ins("test this stream");
		std::stringstream ss;

		MD5Hasher md5;
		md5.encode(ins, ss);

		std::string converted;
		std::getline(ss, converted);
		EXPECT_STREQ("9fea2a9def1152ccf215a267b1ae5b78", converted.c_str())
			<< "Failed to use: MD5" << std::endl;
	} ENDM

	TEST(Collection, stdInEncode) {
		LinkedCollection<CryptoAlgorithm> collection;
		collection.append(new Rot13());
		collection.append(new Xor(new Key("randomPasswordForThisTest")));
		collection.append(new MD5Hasher());
		collection.append(new Base64());
		collection.append(new RSA(new PrimeKey(47), new PrimeKey(101)));

		std::string read;
		std::getline(std::cin, read);
		for (LinkedCollection<CryptoAlgorithm>::Iterator it = collection.iterator(); it.notNull(); ++it)
			std::cout << (*it)->getName() << "\t" << ((TwoWayEncription*)*it)->encode(read) << std::endl;

	} ENDM

	TEST(Collection, stdEncodeDecodeRsa) {
		RSA rsa(new PrimeKey(61), new PrimeKey(67));
		std::stringstream ss;
		rsa.encode(std::cin, ss);
		rsa.decode(ss, std::cout);
	} ENDM

	return 0;
}
