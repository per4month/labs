#pragma once
#include <iostream>
#include "SignedBigFloat.h"
#include "BigFloat.h"
#include "BigInt.h"

class MyDeque
{
public:

	//MyDeque::MyDeque()
	//Конструктор дека по умолчанию
	//args:
	//- нет входных параметров -
	// - создаёт дек по умолчанию -
	MyDeque();

	//void MyDeque::push_front(BigInt* obj)
	//Функция добавления элемента в начало дека
	//args:
	//BigInt* obj - ссылка на объект
	//- добавляет элемент в начало дека -
	void push_front(BigInt* obj);

	//void MyDeque::pop_front()
	//Функция удаления элемента с начала дека
	//args:
	//- нет входных параметров - 
	//- удаляет элемент с начала дека -
	void pop_front();

	//void MyDeque::pop_back()
	//Функция удаления элемента с конца дека
	//args:
	//- нет входных параметров - 
	//- удаляет элемент с конца дека -
	void pop_back();

	//bool MyDeque::find()
	//Функция поиска не NULL элементов
	//args:
	//- нет входных параметров - 
	//- true - все элементы не NULL - 
	//- false - был найден NULL элемент -
	bool find();

	//void MyDeque::print()
	//Функция вывода дека на консоль
	//args:
	//- нет входных параметров - 
	//- выводит дек на консоль -
	void print();

	//void MyDeque::print()
	//Функция вывода дека на консоль в обратном направлении
	//args:
	//- нет входных параметров - 
	//- выводит дек на консоль в обратном направлении -
	void reversePrint();

	//const char* MyDeque::toString()
	//Функция внесения всех элементов дека в строку
	//args:
	//- нет входных параметров - 
	//- вносит дек в строковое представление -
	const char* toString();

	//const char* MyDeque::toStringReverse()
	//Функция внесения всех элементов дека в строку (обр. направление)
	//args:
	//- нет входных параметров - 
	//- вносит дек в строковое представление (обр. направление) -
	const char* toStringReverse();

	//MyDeque::~MyDeque()
	//Деструктор
	//args:
	//- нет входных параметров - 
	// - удаляет динамическую память дека -
	~MyDeque();

private:
	class Elem {
	public:
		//Указатель на объект
		BigInt* data = NULL;

		//Указатель на следующий элемент списка
		Elem* next = NULL;

		//Указатель на предыдущий элемент списка
		Elem* prev = NULL;
	};
	//Указатель на начало дека
	Elem* head;

	//Указатель на конец дека
	Elem* tail;
};

