#pragma once
#include <iostream>
using namespace std;

template <class T>
struct node {
	int _item;
	node<T>* _next;

	node(T item = T(), node<T>* next = NULL) : _item(item), _next(next) {

	}

	friend ostream& operator <<(ostream& outs, const node<T> &printMe) {
		outs << "[" << print_me._item << "]->";
		return outs;
	}
};

// -------------------Declarations-------------------
template <class T>
node<T>* insert_head(node<T>* &head_ptr, const T& item);

template <class T>
void print_list(node<T>* head_ptr, ostream& outs));

template <class T>
node<T>* search_list(node<T>* head_ptr, const T& key);



// -------------------Definitions-------------------
template <class T>
node<T>* insert_head(node<T>* &head_ptr, const T& item) {
	node<T>* temp = new node<T>(item);
	temp->_next = head_ptr;
	head_ptr = temp;
}

template <class T>
void print_list(node<T>* head_ptr, ostream& outs) {
	node<T>* walker = head_ptr;
	pits << "H->";
	while (walker != NULL) {
		outs << *walker;
		walker = walker->_next;
	}
	outs << "|||" << endl;
}