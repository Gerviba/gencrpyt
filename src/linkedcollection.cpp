/*
 * linkedcollection.cpp
 *
 *  Created on: May 9, 2018
 *      Author: root
 */

#include "linkedcollection.hpp"

namespace gencrypt {

// Element<T>

//template <class T>
//T* Element<T>::operator*() {
//	return data;
//}
//
//template <class T>
//T* Element<T>::get() const {
//	return data;
//}
//
//template <class T>
//Element<T>* Element<T>::getNext() const {
//	return next;
//}
//
//template <class T>
//void Element<T>::setNext(Element<T>* next) {
//	this->next = next;
//}

// LinkedCollection<T>

//template <class T>
//void LinkedCollection<T>::append(T* data) {
//	if (last == NULL) {
//		first = new Element<T>(data);
//		last = first;
//		return;
//	}
//
//	Element<T>* next = new Element<T>(data);
//	last->setNext(next);
//	last = next;
//}
//
//template <class T>
//typename LinkedCollection<T>::Iterator& LinkedCollection<T>::Iterator::operator++() {
//	data = data->getNext();
//	return *this;
//}
//
//template <class T>
//T* LinkedCollection<T>::Iterator::operator*() {
//	return *(*data);
//}
//
//template <class T>
//bool LinkedCollection<T>::Iterator::hasNext() const {
//	return data->getNext() != NULL;
//}
//
//template <class T>
//bool LinkedCollection<T>::Iterator::notNull() const {
//	return data != NULL;
//}
//
//template <class T>
//class LinkedCollection<T>::Iterator LinkedCollection<T>::iterator() {
//	return Iterator(first);
//}
//
//template <class T>
//LinkedCollection<T>::~LinkedCollection() {
//	Element<T>* current = first;
//	while (current->getNext() != NULL) {
//		Element<T>* temp = current->getNext();
//		delete current;
//		current = temp;
//	}
//}

} /* namespace gencrypt */
