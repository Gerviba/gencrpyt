/*
 * linkedcollection.h
 *
 *  Created on: May 9, 2018
 *      Author: root
 */

#ifndef SRC_LINKEDCOLLECTION_HPP_
#define SRC_LINKEDCOLLECTION_HPP_

#include <cstdlib>
#include <iostream>

namespace gencrypt {

template <class T>
class Element {
private:
	T* data;
	Element* next;
public:
	Element(T* data) : data(data), next(NULL) {}
	T* operator*() {
		return data;
	}
	T* get() const {
		return data;
	}
	Element* getNext() const {
		return next;
	}
	void setNext(Element* next) {
		this->next = next;
	}
};

template <class T>
class LinkedCollection {
private:
	Element<T>* first;
	Element<T>* last;
public:
	LinkedCollection() : first(NULL), last(NULL) {}
	LinkedCollection(T* data) : first(new Element<T>(data)) {
		last = first;
	}
	void append(T* data){
		if (last == NULL) {
			first = new Element<T>(data);
			last = first;
			return;
		}

		Element<T>* next = new Element<T>(data);
		last->setNext(next);
		last = next;
	}

	class Iterator {
	private:
		Element<T>* data;
	public:
		Iterator(Element<T>* current) : data(current) {}
		Iterator(const Iterator& it) : data(it.data) {}
		Iterator& operator++() {
			data = data->getNext();
			return *this;
		}
		T* operator*() {
			return *(*data);
		}
		bool operator!=(Iterator& iter) {
			return data != iter.data;
		}
		bool hasNext() const {
			return data->getNext() != NULL;
		}
		bool notNull() const {
			return data != NULL;
		}
	};

	Iterator iterator() {
		return Iterator(first);
	}

	virtual ~LinkedCollection(){
		Element<T>* current = first;
		while (current != NULL) {
			Element<T>* temp = current->getNext();
			delete current->get();
			delete current;
			current = temp;
		}
	}

};

} /* namespace gencrypt */

#endif /* SRC_LINKEDCOLLECTION_HPP_ */
