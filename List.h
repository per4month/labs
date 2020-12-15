#pragma once
#include <iostream>
#include <fstream>
#include "Advert.h"
using namespace std;
 
template <class DataT> class FList : public fstream
{
public:
	FList();
	FList(const FList&);
	FList(char*);
	long getHead();
	long getTail();
	/*
	//*Вставка в конец*
	void push_back(long pos, DataT &_value);
	//*Вставка по логическому номеру*
	void insert(long pos, DataT &_value);
	//*Извлечение*
	long или DataT getElem(long pos);
	//*Удаление из любой позиции?*
	Data T pop(long pos, DataT &_value);
	//*Обновление строки*
	void update(long pos, DataT &_value);
	//*Поиск*
	long find(long pos, DataT &key); 
	//*Вставка с сохранением порядка*
	//надо осуществить после сортировки (иначе нет смысла)
	void insertSort(long pos, DataT &_value);
	//*Сортировка(лучше, если вставками)*
	void sort();
	//*Постраничный просмотр?*
	//*Сжатие*
	void compress();
	//*Печать списка на консоль*
	void printList(long pos);
	//~TDeque();  //нужен ли деструктор?*/

private:
	class Elem { //Узел двухсвязного списка в памяти
	public:
		Elem():next(NULL),prev(NULL){};
		DataT data; //шаблонное значение 
		Elem* next; 
		Elem* prev; 
	};

	class FElem { //Узел двухсвязного списка в файле
	public: 
		FElem():next(-1),prev(-1){};
		DataT data; //шаблонное значение
		long next; //Указатель на следующий узел в файле
		long prev; //Указатель на предыдущий узел в файле
	};
	
	long head; //указатель на "голову" в файле
	long tail; //указатель на "хвост" в файле
	int size; //длина списка
	char *fname; //название файла
};

template <class DataT> FList<DataT> ::FList():fstream() {
	fname = new char[10]{"test.dat"};
	ofstream f(fname); //создаем выводной поток, что бы создать файл
	f.close(); //закрываем файл
	open(fname, ios::in | ios::out | ios::ate | ios::binary);	//открываем файл в текущем потоке
	head = -1;
	tail = -1;
	size = 0;
}

template <class DataT> FList<DataT>::FList( const FList& other) : fstream(other)
{
	head = 0; //??????
	fname = _strdup(other.fname);
}

template <class DataT> FList<DataT>::FList(char *_fname) : fstream(_fname, ios::in | ios::out | ios::ate | ios::binary )
{
	fname = _strdup(_fname);	
	if (fail())
	{
		ofstream f(_fname);	
		f.close();	
		fstream::open(_fname, ios::in | ios::out | ios::ate | ios::binary);	//открываем файл в текущем потоке
	}
	if ((int)tellp() == 0)	//если позиция последнего элемента в файле равна нулю, значит файл пуст
	{
		head = -1;	//зануляем указатель на голову
		tail = -1;  //зануляем указатель на хвост
	}
	else
	{
		seekp(ios::beg);	//переходим в начало файла
		read((char*)&head, sizeof(long)); //считываем указатель на головной элемент
		//как тут считывать?
		//seekp(n); //переходим в конец файла
		//read((char*)&tail, sizeof(long)); //считываем указатель на хвостовой элемент
	}
}

template <class DataT> long FList<DataT>::getHead(){
	return head;
}

template <class DataT> long FList<DataT>::getTail(){
	return tail;
}

template <class DataT> 
void pushBack(long pos, DataT &value) { //не готово
   
	if (tmp == NULL) {
        exit(3);
    }
    tmp->value = value;
    tmp->next = NULL;
    tmp->prev = list->tail;
    if (list->tail) {
        list->tail->next = tmp;
    }
    list->tail = tmp;
 
    if (list->head == NULL) {
        list->head = tmp;
    }
    list->size++;
}

/*template <class DataT> FList<DataT>::~FList():
{
	
	delete[] fname;
	fname = NULL;
}*/