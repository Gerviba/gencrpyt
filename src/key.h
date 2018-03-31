/*
 * key.h
 *
 *  Created on: Mar 31, 2018
 *      Author: Gerviba
 */

#ifndef SRC_KEY_H_
#define SRC_KEY_H_

namespace gencrypt {

class Key {
private:
	char *key;
	unsigned int length;
public:
	Key();
	Key(const char* key);
	Key(const Key& key);
	char *getRawKey() const;
	unsigned int getLength() const;
	char operator[](unsigned int index) const;
	char getByteAt(unsigned int index) const;
	virtual ~Key();
};

} /* namespace gencrypt */

#endif /* SRC_KEY_H_ */
