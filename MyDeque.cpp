#include "MyDeque.h"
#include <iostream>

MyDeque::MyDeque() {
	head = NULL;
	tail = NULL;
}

void MyDeque::push_front(BigInt* obj) {
	Elem* elem = new Elem();
	elem->data = obj;

	if (head == NULL) {
		tail = elem;
		head = elem;
		return;
	}
	elem->prev = NULL;
	elem->next = head;
	head->prev = elem;
	head = elem;
}

void MyDeque::pop_front() {
	try {
		if (head == NULL) {
			throw exception("Error! No elements in deque");
		}
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
		return;
	}
	if (head->next == NULL) {
		delete head->data;
		delete head;
		head = NULL;
		tail = NULL;
		return;
	}
	Elem* cur = head;
	head = head->next;
	head->prev = NULL;
	delete cur->data;
	delete cur;
}

void MyDeque::pop_back() {
	try {
		if (tail == NULL) {
			throw exception("Error! No elements in deque");
		}
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
		return;
	}
	if (tail->prev == NULL) {
		delete tail->data;
		delete tail;
		head = NULL;
		tail = NULL;
		return;
	}
	Elem* cur = tail;
	tail = tail->prev;
	tail->next = NULL;
	delete cur->data;
	delete cur;
}

bool MyDeque::find() {
	for (Elem* temp = head; temp != NULL; temp = temp->next) {
		if (temp->data == NULL) {
			return false;
		}
	}
	return true;
}

void MyDeque::print() {
	for (Elem* temp = head; temp!= NULL; temp = temp->next) {
		cout << temp->data->toString() << endl;
	}
}

void MyDeque::reversePrint() {
	for (Elem* temp = tail; temp != NULL; temp = temp->prev) {
		cout << temp->data->toString() << endl;
	}
}

const char* MyDeque::toString() {
	int length = 0;
	int count = 0;
	for (Elem* temp = head; temp != NULL; temp = temp->next) {
		if (temp->data == NULL) {
			length += 4;
			count++;
			continue;
		}
		length += strlen(temp->data->toString());
		count++;
	}
	try {
		length = length + count - 1;
		if (length == -1) {
			throw exception("Error! No elements in deque");
		}
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
		return "Empty";
	}
	char* str = new char[length+1];
	int j = 0;
	for (Elem* temp = head; temp != NULL; temp = temp->next) {
		const char* strPut;
		if (temp->data == NULL) {
			strPut = "NULL";
		}
		else {
			strPut = temp->data->toString();
		}
		int tempLength = strlen(strPut);
		for (int i = 0; i < tempLength; i++) {
			str[j++] = strPut[i];
		}
		if (j < length) {
			str[j++] = ' ';
		}
	}
	str[length] = '\0';
	return str;
}

const char* MyDeque::toStringReverse() {
	int length = 0;
	int count = 0;
	for (Elem* temp = tail; temp != NULL; temp = temp->prev) {
		if (temp->data == NULL) {
			length += 4;
			count++;
			continue;
		}
		length += strlen(temp->data->toString());
		count++;
	}
	try {
		length = length + count - 1;
		if (length == -1) {
			throw exception("Error! No elements in deque");
		}
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
		return "Empty";
	}
	char* str = new char[length + 1];
	int j = 0;
	for (Elem* temp = tail; temp != NULL; temp = temp->prev) {
		const char* strPut;
		if (temp->data == NULL) {
			strPut = "NULL";
		}
		else {
			strPut = temp->data->toString();
		}
		int tempLength = strlen(strPut);
		for (int i = 0; i < tempLength; i++) {
			str[j++] = strPut[i];
		}
		if (j < length) {
			str[j++] = ' ';
		}
	}
	str[length] = '\0';
	return str;
}

MyDeque::~MyDeque() {
	for (Elem* current = head; current != NULL;) {
		Elem* tmp = current;
		current = current->next;
		delete tmp->data;
		delete tmp;
	}
	head = NULL;
	tail = NULL;
}