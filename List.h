#pragma once
#include <iostream>
#include <fstream>
#include "Advert.h"
using namespace std;
 
template <class DataT> class FList : public fstream
{
public:
	
	FList(); //конструктор без параметров
	FList(char*); //конструктор с параметром
	int getHead(); //вернуть позицию начала списка в файле
	int getTail(); //вернуть позицию конца списка в файле
	int getCount(); //вернуть значение количества элементов списка
	int getLastPos(); //вернуть значение последней свободной позиции для записи
	void setHead(int); //установить значение начала списка
	void setTail(int); //установить значение конца списка
	void setCount(int); //установить значение количества элемнтов списка
	void setLastPos(int); //установить значение последней свободной позиции для записи

	void printList(); //печать списка на консоль (постраничный просмотр)
	void printListReverse(); //печать списка на консоль в обратном направлении
	void push_back(DataT); //вставка узла в конец списка
	void push_front(DataT); //вставка узла в начало списка
	bool insert(int, DataT); //вставка узла по логическому номеру
	int insertSort(DataT); //вставка узла с сохранением порядка
	bool update(int); //обновление строки
	DataT getFromPos(int); //извлечение по логическому номеру
	int find(DataT); //поиск элементов по ключу
	DataT pop_back(); //удаление с конца списка
	DataT pop_front(); //удаление с начала списка
	DataT pop(int pos); //удаление с позиции по лог. номеру
	void sort(); //сортировка выбором
	void compress(char*); //сжатие файла

private:
	class FElem { //Узел двухсвязного списка в файле
	public: 
		FElem():next(-1),prev(-1){};
		DataT data; //шаблонное значение
		int next; //указатель на следующий узел в файле
		int prev; //указатель на предыдущий узел в файле
	};
	int head; //указатель на "голову" в файле
	int tail; //указатель на "хвост" в файле
	int count; //длина списка
	int lastStreamPos; //последняя позиция записи в файле
};

template <class DataT> FList<DataT> ::FList():fstream() {
	char* fname = "test.dat";
	ofstream f(fname); //создаем выводной поток, что бы создать файл
	if (!f) {
		cout << "Ошибка! Невозможно прочитать файл!" << endl;
		f.close();
		return;
	}
	f.close(); //закрываем файл
	open(fname, ios::in | ios::out | ios::ate | ios::binary);	//открываем файл в текущем потоке
	if(!fail()){
	count = 0;
	head = -1;
	tail = -1;
	lastStreamPos = 16;
	seekg(0,ios::beg);
	write((char*)&count,sizeof(int));
	write((char*)&head,sizeof(int));
	write((char*)&tail,sizeof(int));
	write((char*)&lastStreamPos,sizeof(int));
	}
}

template <class DataT> FList<DataT>::FList(char *_fname) : fstream(_fname, ios::in | ios::out | ios::ate | ios::binary )
{
	char* fname = _strdup(_fname);	
	if (fail())
	{
		ofstream f(_fname);	
		if (!f) {
		cout << "Ошибка! Невозможно прочитать файл!" << endl;
		f.close();
		return;
		}
		f.close();	
		fstream::open(_fname, ios::in | ios::out | ios::ate | ios::binary);	//открываем файл в текущем потоке
	}
	if ((int)tellp() == 0)	//если позиция последнего элемента в файле равна нулю, значит файл пуст
	{
		count = 0;
		head = -1;
		tail = -1;
		lastStreamPos = 16;
		seekg(0,ios::beg);
		write((char*)&count,sizeof(int)); //записываем количество элементов списка
		write((char*)&head,sizeof(int)); //записываем "голову" списка
		write((char*)&tail,sizeof(int)); //записываем "хвост" списка
		write((char*)&lastStreamPos,sizeof(int)); //записываем последнюю позицию в файле
	}
	else
	{
		seekg(0,ios::beg);
		read((char*)&count,sizeof(int)); //считываем количество элементов списка
		read((char*)&head,sizeof(int)); //считываем "голову" списка
		read((char*)&tail,sizeof(int)); //считываем "хвост" списка
		read((char*)&lastStreamPos,sizeof(int)); //считываем последнюю позицию в файле
	}
}

template <class DataT> int FList<DataT>::getHead(){
	return head;
}

template <class DataT> int FList<DataT>::getTail(){
	return tail;
}

template <class DataT> int FList<DataT>::getCount(){
	return count;
}

template <class DataT> int FList<DataT>::getLastPos(){
	return lastStreamPos;
}

template <class DataT> void FList<DataT>::setHead(int start){
	int i = tellp();
	head = start;
	seekg(4,ios::beg);
	write((char*)&head, sizeof(int));
	seekg(i,ios::beg);
}

template <class DataT> void FList<DataT>::setTail(int end){
	int i = tellp();
	tail = end;
	seekg(8,ios::beg);
	write((char*)&tail, sizeof(int));
	seekg(i,ios::beg);
}

template <class DataT> void FList<DataT>::setCount(int cnt){
	int i = tellp();
	count = cnt;
	seekg(0,ios::beg);
	write((char*)&count, sizeof(int));
	seekg(i,ios::beg);
}

template <class DataT> void FList<DataT>::setLastPos(int pos){
	int i = tellp();
	lastStreamPos = pos;
	seekg(12,ios::beg);
	write((char*)&lastStreamPos, sizeof(int));
	seekg(i,ios::beg);
}

template <class DataT> void FList<DataT>::push_back(DataT value) { 
if (count == 0) { //если элементов в списке нет, то добавляем первый
	FElem temp;
	temp.data = value; //значение узла списка
	setHead(16); //устанавливаем голову с в свободную ячейку
	setTail(16); //устанавливаем хвост с в свободную ячейку
	seekg(tail,ios::beg);
	write((char*)&temp.prev, sizeof(int)); //записываем файловый указатель на предыдущий элемент
	write((char*)&temp.next, sizeof(int)); //записываем файловый указатель на следующий элемент
	write((char*)&temp.data, sizeof(DataT));  //записываем значение узла
	setCount(count+1); //обновляем счётчик узлов
	setLastPos(tellp()); //обновляем последнюю позицию для записи
    }
   else { //если элементы в списке есть
	FElem temp;
	temp.next = -1; //файловый указатель на следующий элемент "зануляем"
	temp.prev = tail; //файловый указатель на предыдущий элемент указываем на "предыдущий хвост" списка
	temp.data = value; //значение узла
	seekg(lastStreamPos,ios::beg); //переходим на последнюю свободную позицию для записи
	write((char*)&temp.prev, sizeof(int)); //записываем файловый указатель на предыдущий элемент
	write((char*)&temp.next, sizeof(int)); //записываем файловый указатель на следующий элемент
	write((char*)&temp.data, sizeof(DataT));  //записываем значение узла
	int pos = tellp(); //запоминаем последнюю свободную позицию для записи
	setCount(count+1); //обновляем счётчик узлов
	setTail(lastStreamPos); //ставим значение "нового хвоста списка"
	seekg(temp.prev+sizeof(int), ios::beg); //возвращаемся к записи файлового указателя-next предыдущего элемента
	write((char*)&tail, sizeof(int)); //файловый указатель-next предыдущего элемента указываем на новый созданный 
	seekg(pos, ios::beg); //возвращаемся на последнюю свободную позицию для записи
	setLastPos(pos); //оюновляем последнюю позицию для записи
   }
}

template <> void FList<Advert>::push_back(Advert value) { 
if (count == 0) { //если элементов в списке нет, то добавляем первый
	FElem temp;
	temp.data = value; //значение узла списка
	setHead(16); //устанавливаем голову с в свободную ячейку
	setTail(16); //устанавливаем хвост с в свободную ячейку
	seekg(tail,ios::beg);
	write((char*)&temp.prev, sizeof(int)); //записываем файловый указатель на предыдущий элемент
	write((char*)&temp.next, sizeof(int)); //записываем файловый указатель на следующий элемент
	*this << temp.data; //записываем значение узла
	setCount(count+1); //обновляем счётчик узлов
	setLastPos(tellp()); //обновляем последнюю позицию для записи
    }
   else { //если элементы в списке есть
	FElem temp;
	temp.next = -1; //файловый указатель на следующий элемент "зануляем"
	temp.prev = tail; //файловый указатель на предыдущий элемент указываем на "предыдущий хвост" списка
	temp.data = value; //значение узла
	seekg(lastStreamPos,ios::beg); //переходим на последнюю свободную позицию для записи
	write((char*)&temp.prev, sizeof(int)); //записываем файловый указатель на предыдущий элемент
	write((char*)&temp.next, sizeof(int)); //записываем файловый указатель на следующий элемент
	*this << temp.data;  //записываем значение узла
	int pos = tellp(); //запоминаем последнюю свободную позицию для записи
	setCount(count+1); //обновляем счётчик узлов
	setTail(lastStreamPos); //ставим значение "нового хвоста списка"
	seekg(temp.prev+sizeof(int), ios::beg); //возвращаемся к записи файлового указателя-next предыдущего элемента
	write((char*)&tail, sizeof(int)); //файловый указатель-next предыдущего элемента указываем на новый созданный 
	seekg(pos, ios::beg); //возвращаемся на последнюю свободную позицию для записи
	setLastPos(pos); //оюновляем последнюю позицию для записи
   }
}

template <class DataT> void FList<DataT>::push_front(DataT value) { 
if (count == 0) { //если элементов в списке нет, то добавляем первый
	FElem temp;
	temp.data = value; //значение узла списка
	setHead(16); //устанавливаем голову с в свободную ячейку
	setTail(16); //устанавливаем хвост с в свободную ячейку
	seekg(tail,ios::beg);
	write((char*)&temp.prev, sizeof(int)); //записываем файловый указатель на предыдущий элемент
	write((char*)&temp.next, sizeof(int)); //записываем файловый указатель на следующий элемент
	write((char*)&temp.data,sizeof(DataT)); //записываем значение узла
	setCount(count+1); //обновляем счётчик узлов
	setLastPos(tellp()); //обновляем последнюю позицию для записи
    }
   else { //если элементы в списке есть
	FElem temp;
	temp.prev = -1; //файловый указатель на предыдущий элемент "зануляем"
	temp.next = head; //файловый указатель на следующий элемент указываем на "предыдущую голову" списка
	temp.data = value; //значение узла
	seekg(lastStreamPos,ios::beg); //переходим на последнюю свободную позицию для записи
	write((char*)&temp.prev, sizeof(int)); //записываем файловый указатель на предыдущий элемент
	write((char*)&temp.next, sizeof(int)); //записываем файловый указатель на следующий элемент
	write((char*)&temp.data, sizeof(DataT)); //записываем значение узла
	int pos = tellp(); //запоминаем последнюю свободную позицию для записи
	setCount(count+1); //обновляем счётчик узлов
	setHead(lastStreamPos); //ставим значение "новой головы списка"
	seekg(temp.next, ios::beg); //возвращаемся к записи файлового указателя-prev следующего элемента
	write((char*)&head, sizeof(int)); //файловый указатель-prev следующего элемента указываем на новый созданный 
	seekg(pos, ios::beg); //возвращаемся на последнюю свободную позицию для записи
	setLastPos(pos); //обновляем последнюю позицию для записи
   }
}

template <> void FList<Advert>::push_front(Advert value) { 
if (count == 0) { //если элементов в списке нет, то добавляем первый
	FElem temp;
	temp.data = value; //значение узла списка
	setHead(16); //устанавливаем голову с в свободную ячейку
	setTail(16); //устанавливаем хвост с в свободную ячейку
	seekg(tail,ios::beg);
	write((char*)&temp.prev, sizeof(int)); //записываем файловый указатель на предыдущий элемент
	write((char*)&temp.next, sizeof(int)); //записываем файловый указатель на следующий элемент
	*this << temp.data; //записываем значение узла
	setCount(count+1); //обновляем счётчик узлов
	setLastPos(tellp()); //обновляем последнюю позицию для записи
    }
   else { //если элементы в списке есть
	FElem temp;
	temp.prev = -1; //файловый указатель на предыдущий элемент "зануляем"
	temp.next = head; //файловый указатель на следующий элемент указываем на "предыдущую голову" списка
	temp.data = value; //значение узла
	seekg(lastStreamPos,ios::beg); //переходим на последнюю свободную позицию для записи
	write((char*)&temp.prev, sizeof(int)); //записываем файловый указатель на предыдущий элемент
	write((char*)&temp.next, sizeof(int)); //записываем файловый указатель на следующий элемент
	*this << temp.data;  //записываем значение узла
	int pos = tellp(); //запоминаем последнюю свободную позицию для записи
	setCount(count+1); //обновляем счётчик узлов
	setHead(lastStreamPos); //ставим значение "новой головы списка"
	seekg(temp.next, ios::beg); //возвращаемся к записи файлового указателя-prev следующего элемента
	write((char*)&head, sizeof(int)); //файловый указатель-prev следующего элемента указываем на новый созданный 
	seekg(pos, ios::beg); //возвращаемся на последнюю свободную позицию для записи
	setLastPos(pos); //обновляем последнюю позицию для записи
   }
}

template <class DataT> bool FList<DataT>::insert(int pos, DataT value) { 
	try{
	if(pos < 1 || pos > count + 1)
    {
      //Неверная позиция
      throw exception("Ошибка! Неверное значение логического номера!");
    }	
	}
	catch (exception &ex){
		cout << ex.what() << endl;
		return false;
	}
  if(pos == count + 1) //если крайний элемент
  {
      push_back(value); //вставляем в конец списка
      return true;
  }
  else if (pos == 1) //если крайний элемент
  {
	  push_front(value); //вставляем в начало списка
	  return true;
  }
  int i = 1;
  seekg(head,ios::beg);
  FElem nextIns; //следующий узел после вставляемого
  read((char*)&nextIns.prev,sizeof(int));
  read((char*)&nextIns.next,sizeof(int));
  seekg(nextIns.next,ios::beg);
  while(i < pos) //поиск позиции вставки
  {
	  read((char*)&nextIns.prev,sizeof(int));
	  read((char*)&nextIns.next,sizeof(int));
	  i++;
	  if (nextIns.next == -1)
	  {
		  break;
	  }
	  seekg(nextIns.next,ios::beg);
  }
  seekg(nextIns.prev, ios::beg);
  FElem prevIns; //предыдущий узел перед вставляемым
  read((char*)&prevIns.prev,sizeof(int));
  read((char*)&prevIns.next,sizeof(int));
  FElem ins; //вставляемый узел
  ins.prev = nextIns.prev; // записываем файловый указатель на предыдущий
  ins.next = prevIns.next; // записываем файловый указатель на следующий
  ins.data = value; //записываем значение узла
  seekg(ins.prev+sizeof(int), ios::beg); 
  write((char*)&lastStreamPos,sizeof(int)); //переписываем файловый указатель-next предыдущего узла на вставляемый
  seekg(ins.next, ios::beg);
  write((char*)&lastStreamPos,sizeof(int)); //переписываем файловый указатель-prev следующего узла на вставляемый
  seekg(lastStreamPos, ios::beg);
  write((char*)&ins.prev,sizeof(int)); //записываем файловый указатель prev нового узла в бинарный файл
  write((char*)&ins.next,sizeof(int)); //записываем файловый указатель next нового узла в бинарный файл
  write((char*)&ins.data,sizeof(DataT)); //записываем значение узла
  setCount(count+1); //обновляем счётчик
  setLastPos(tellp()); //обновляем последнюю позицию для записи
  return true;
}

template <> bool FList<Advert>::insert(int pos, Advert value) { 
	try{
	if(pos < 1 || pos > count + 1)
    {
      //Неверная позиция
      throw exception("Ошибка! Неверное значение логического номера!");
    }	
	}
	catch (exception &ex){
		cout << ex.what() << endl;
		return false;
	}
  if(pos == count + 1) //если крайний элемент
  {
      push_back(value); //вставляем в конец списка
      return true;
  }
  else if (pos == 1) //если крайний элемент
  {
	  push_front(value); //вставляем в начало списка
	  return true;
  }
  int i = 1;
  seekg(head,ios::beg);
  FElem nextIns; //следующий узел после вставляемого
  read((char*)&nextIns.prev,sizeof(int));
  read((char*)&nextIns.next,sizeof(int));
  seekg(nextIns.next,ios::beg);
  while(i < pos)
  {
	  read((char*)&nextIns.prev,sizeof(int));
	  read((char*)&nextIns.next,sizeof(int));
	  i++;
	  if (nextIns.next == -1)
	  {
		  break;
	  }
	  seekg(nextIns.next,ios::beg);
  }
  seekg(nextIns.prev, ios::beg);
  FElem prevIns; //предыдущий узел перед вставляемым
  read((char*)&prevIns.prev,sizeof(int));
  read((char*)&prevIns.next,sizeof(int));
  FElem ins; //вставляемый узел
  ins.prev = nextIns.prev; // записываем файловый указатель на предыдущий
  ins.next = prevIns.next; // записываем файловый указатель на следующий
  ins.data = value; //записываем значение узла
  seekg(ins.prev+sizeof(int), ios::beg);
  write((char*)&lastStreamPos,sizeof(int)); //переписываем файловый указатель-next предыдущего узла на вставляемый
  seekg(ins.next, ios::beg);
  write((char*)&lastStreamPos,sizeof(int)); //переписываем файловый указатель-prev следующего узла на вставляемый
  seekg(lastStreamPos, ios::beg);
  write((char*)&ins.prev,sizeof(int)); //записываем файловый указатель prev нового узла в бинарный файл
  write((char*)&ins.next,sizeof(int)); //записываем файловый указатель next нового узла в бинарный файл
  *this << ins.data; //записываем значение узла
  setCount(count+1); //обновляем счётчик
  setLastPos(tellp()); //обновляем последнюю позицию для записи
  return true;
}

template <class DataT> int FList<DataT>::insertSort(DataT value){
	FElem nextIns; //следующий элемент после вставляемого
	int i = 1;
	if (head == -1){
		push_back(value);
		return i;
	}
	seekg(head,ios::beg);
	while (i < count+1){ //проходим по списку
		read((char*)&nextIns.prev,sizeof(int));
		read((char*)&nextIns.next,sizeof(int));
		read((char*)&nextIns.data, sizeof(DataT));
		if (value < nextIns.data){ //ищем место для вставки
			break;
		}
		i++;
		if (nextIns.next==-1){ //проверка чтобы не ушло в -1
			break;
		}
		seekg(nextIns.next, ios::beg);
		
	}
	insert(i,value);//вставляем по найденному логическому номеру
	return i;
}

template <> int FList<Advert>::insertSort(Advert value){
	FElem nextIns; //следующий узел после вставляемого
	int i = 1;
	if (head == -1){
		push_back(value);
		return i;
	}
	seekg(head,ios::beg);
	while (i < count+1){ //проходим по списку
		read((char*)&nextIns.prev,sizeof(int));
		read((char*)&nextIns.next,sizeof(int));
		*this >> nextIns.data;
		if (value < nextIns.data){ //поиск позиции вставки
			break;
		}
		i++;
		if (nextIns.next==-1){
			break;
		}
		seekg(nextIns.next, ios::beg);
		
	}
	insert(i,value);
	return i;
}

template <class DataT> bool FList<DataT>::update(int pos){
	try{
	if(pos < 1 || pos > count)
    {
      //Неверная позиция
      throw exception("Ошибка! Неверное значение логического номера!");
    }	
	}
	catch (exception &ex){
		cout << ex.what() << endl;
		return false;
	}
	FElem temp; //редактируемый узел
	if (pos == 1){ //если это голова списка
		seekg(head, ios::beg);
	}
	else if (pos == count){ //если это хвост списка
		seekg(tail, ios::beg);
	}
	else { //если другой элемент
		seekg(head, ios::beg);
		int i = 1;
		while (i!=pos){ //ищем позицию редактируемого элемента
			read((char*)&temp.prev,	sizeof(int));
			read((char*)&temp.next, sizeof(int));
			i++;
			if (temp.next==-1){
				break;
		}
		seekg(temp.next, ios::beg);
		}
	}
	read((char*)&temp.prev,	sizeof(int));
	read((char*)&temp.next, sizeof(int));
	int currPos = tellp();
	read((char*)&temp.data, sizeof(DataT));
	cout << "Узел с логическим номером: " << pos << endl;
	cout << "Next: " << temp.next << endl;
	cout << "Prev: " << temp.prev << endl;
	cout << "Значение в узле: " << endl;
	cout << temp.data << endl;
	cout << "Введите новое значение для редактирования: " << endl;
	cin >> temp.data; //вводим новые данные
	seekg(currPos,ios::beg);
	write((char*)&temp.data, sizeof(DataT));
	cout << "------------------------------------------ " << endl;
	cout << "Редактированный узел с логическим номером: " << pos << endl;
	cout << "Next: " << temp.next << endl;
	cout << "Prev: " << temp.prev << endl;
	cout << "Значение в узле: " << endl;
	cout << temp.data << endl;
	seekg(lastStreamPos,ios::beg);
	return true;
}

template <> bool FList<Advert>::update(int pos){
	try{
	if(pos < 1 || pos > count)
    {
      //Неверная позиция
      throw exception("Ошибка! Неверное значение логического номера!");
    }	
	}
	catch (exception &ex){
		cout << ex.what() << endl;
		return false;
	}
	FElem temp;
	if (pos == 1){ //если это голова списка
		seekg(head, ios::beg);
	}
	else if (pos == count){ //если это хвост списка
		seekg(tail, ios::beg);
	}
	else { //если другой элемент
		seekg(head, ios::beg);
		int i = 1;
		while (i!=pos){ //ищем позицию редактируемого элемента
			read((char*)&temp.prev,	sizeof(int));
			read((char*)&temp.next, sizeof(int));
			i++;
			if (temp.next==-1){
				break;
		}
		seekg(temp.next, ios::beg);
		}
	}
	read((char*)&temp.prev, sizeof(int));
	read((char*)&temp.next, sizeof(int));
	*this >> temp.data;
	cout << "Редактируемый узел списка с логическим номером: " << pos << endl;
	cout << "Prev: " << temp.prev << endl;
	cout << "Next: " << temp.next << endl;
	cout << "Значение в узле: " << endl;
	cout << temp.data << endl;
	(temp.data).redact(temp.data); //редактируем объект
	seekg(lastStreamPos, ios::beg); //идём на последнюю позицию для записи
	//записываем предыдущий значения next,prev и data редактируемого узла в последнюю свободную позицию для записи в бинарном файле
	write((char*)&temp.prev, sizeof(int)); 
	write((char*)&temp.next, sizeof(int)); 
	*this << temp.data; 
	int currPos = tellp();
	if (pos == 1){
		if (count !=1){
			seekg(temp.next, ios::beg);
			write((char*)&lastStreamPos,sizeof(int));
			//"зануляем" файловые указатели в прошлой позиции узла
			temp.prev = -1; 
			temp.next = -1;
			seekg(head,ios::beg);
			write((char*)&temp.prev,sizeof(int));
			write((char*)&temp.next,sizeof(int));
			//устанавливаем "голову" списка на отредактированный узел
			setHead(lastStreamPos);
			//обновляем последнюю свободную позцию для записи
			setLastPos(currPos);
			return true;
		}
		else { //если редактируемый элемент единственный в списке
			setHead(lastStreamPos);
			setTail(lastStreamPos);
			//обновляем последнюю свободную позцию для записи
			setLastPos(currPos);
			return true;
		}
	}
	if (pos == count){  //если редактируем хвост списка 
		seekg(temp.prev+sizeof(int), ios::beg);
		write((char*)&lastStreamPos,sizeof(int));
		//"зануляем" файловые указатели в прошлой позиции узла
		temp.prev = -1; 
		temp.next = -1;
		seekg(tail,ios::beg);
		write((char*)&temp.prev,sizeof(int));
		write((char*)&temp.next,sizeof(int));
		//устанавливаем "хвост" списка на отредактированный узел
		setTail(lastStreamPos);
		//обновляем последнюю свободную позицию для записи
		setLastPos(currPos);
		return true;
	}
	//если не хвост и не голова списка
	//восстанавливаем все связи редактируемого узла, в связи с его новой позицией в файле
	seekg(temp.prev+sizeof(int), ios::beg);
	write((char*)&lastStreamPos, sizeof(int));
	seekg(temp.next, ios::beg);
	write((char*)&lastStreamPos, sizeof(int));
	seekg(currPos,ios::beg);
	//"зануляем" файловые указатели в прошлой позиции узла
	temp.prev = -1;
	temp.next = -1;
	write((char*)&temp.prev, sizeof(int));
	write((char*)&temp.next, sizeof(int));
	//обновляем значение последней свободной позиции для записи
	setLastPos(currPos);
	return true;
}

template <class DataT> DataT FList<DataT>::getFromPos(int pos){
	FElem temp;
	seekg(head, ios::beg);
	int i = 1;
	while (i!=pos){ //ищем позицию извлекаемого узла
		read((char*)&temp.prev,	sizeof(int));
		read((char*)&temp.next, sizeof(int));
		i++;
		if (temp.next==-1){
			break;
		}
		seekg(temp.next, ios::beg);
	}
	read((char*)&temp.prev, sizeof(int));
	read((char*)&temp.next, sizeof(int));
	read((char*)&temp.data, sizeof(DataT));
	return temp.data; //возвращаем значение
}

template <> Advert FList<Advert>::getFromPos(int pos){
	FElem temp;
	seekg(head, ios::beg);
	int i = 1;
	while (i!=pos){ //ищем позицию
		read((char*)&temp.prev,	sizeof(int));
		read((char*)&temp.next, sizeof(int));
		i++;
		if (temp.next==-1){
			break;
		}
		seekg(temp.next, ios::beg);
	}
	read((char*)&temp.prev, sizeof(int));
	read((char*)&temp.next, sizeof(int));
	*this >> temp.data;
	return temp.data; //извлёченное значение узла
}

template <class DataT> int FList<DataT>::find(DataT key){
	FElem temp;
	try{
		if (head == -1) 
			throw exception("Ошибка! В списке нет элементов!");
	}
	catch (exception &ex){
		cout << ex.what() << endl;
		return -1;
	}
	int cnt = 0;
	seekg(head, ios::beg);
	for (int i = 1; i < count+1; i++){
		read((char*)&temp.prev, sizeof(int));
		read((char*)&temp.next, sizeof(int));
		read((char*)&temp.data, sizeof(int));
		if (temp.data == key) { //если значение ключа совпало со значением узла из списка, то выводим данный узел
			cout << "Найденный узел списка с логическим номером: " << i << endl;
			cout << "Prev: " << temp.prev << endl;
			cout << "Next: " << temp.next << endl;
			cout << "Значение в узле: " << endl;
			cout << temp.data << endl;
			cnt++;
		}
		if (temp.next == -1)
			break;
		seekg(temp.next,ios::beg);
	}
	return cnt;
}

template <> int FList<Advert>::find(Advert key){
	FElem temp;
	try{
		if (head == -1) 
			throw exception("Ошибка! В списке нет элементов!");
	}
	catch (exception &ex){
		cout << ex.what() << endl;
		return -1;
	}
	int cnt = 0;
	seekg(head, ios::beg);
	for (int i = 1; i < count+1; i++){
		read((char*)&temp.prev, sizeof(int));
		read((char*)&temp.next, sizeof(int));
		*this >> temp.data;
		if (temp.data == key) {
			cout << "Найденный узел списка с логическим номером: " << i << endl;
			cout << "Prev: " << temp.prev << endl;
			cout << "Next: " << temp.next << endl;
			cout << "Значение в узле: " << endl;
			cout << temp.data << endl;
			cnt++;
		}
		if (temp.next == -1)
			break;
		seekg(temp.next,ios::beg);
		}
	return cnt;
}

template <class DataT> DataT FList<DataT>::pop_back(){
	seekg(tail,ios::beg); //перемещаемся на хвост списка
	FElem temp;
	read((char*)&temp.prev, sizeof(int));
	read((char*)&temp.next, sizeof(int));
	read((char*)&temp.data, sizeof(int));
	if (temp.prev == -1){ //если последний элемент списка
		temp.prev = -1;
		temp.next = -1;
		seekg(tail, ios::beg);
		write((char*)&temp.prev, sizeof(int));
		write((char*)&temp.next, sizeof(int));
		setHead(-1);
		setTail(-1);
		setCount(0);
		return temp.data;
	}
	seekg(temp.prev+sizeof(int),ios::beg);
	int pos = temp.prev;
	temp.next = -1;
	write((char*)&temp.next, sizeof(int));
	seekg(tail,ios::beg);
	temp.prev = -1;
	temp.next = -1;
	write((char*)&temp.prev, sizeof(int));
	write((char*)&temp.next, sizeof(int));
	setTail(pos);
	setCount(count-1);
	return temp.data;
}


template <> Advert FList<Advert>::pop_back(){
	seekg(tail,ios::beg);
	FElem temp;
	read((char*)&temp.prev, sizeof(int));
	read((char*)&temp.next, sizeof(int));
	*this >> temp.data;
	if (temp.prev == -1){
		temp.prev = -1;
		temp.next = -1;
		seekg(tail, ios::beg);
		write((char*)&temp.prev, sizeof(int));
		write((char*)&temp.next, sizeof(int));
		setHead(-1);
		setTail(-1);
		setCount(0);
		return temp.data;
	}
	seekg(temp.prev+sizeof(int),ios::beg);
	int pos = temp.prev;
	temp.next = -1;
	write((char*)&temp.next, sizeof(int));
	seekg(tail,ios::beg);
	temp.prev = -1;
	temp.next = -1;
	write((char*)&temp.prev, sizeof(int));
	write((char*)&temp.next, sizeof(int));
	setTail(pos);
	setCount(count-1);
	return temp.data;
}

template <class DataT> DataT FList<DataT>::pop_front(){
	seekg(head,ios::beg);
	FElem temp;
	read((char*)&temp.prev, sizeof(int));
	read((char*)&temp.next, sizeof(int));
	read((char*)&temp.data, sizeof(int));
	if (temp.next == -1){
		temp.prev = -1;
		temp.next = -1;
		seekg(head, ios::beg);
		write((char*)&temp.prev, sizeof(int));
		write((char*)&temp.next, sizeof(int));
		setHead(-1);
		setTail(-1);
		setCount(0);
		return temp.data;
	}
	seekg(temp.next,ios::beg);
	int pos = temp.next;
	temp.prev = -1;
	write((char*)&temp.prev, sizeof(int));
	seekg(head,ios::beg);
	temp.prev = -1;
	temp.next = -1;
	write((char*)&temp.prev, sizeof(int));
	write((char*)&temp.next, sizeof(int));
	setHead(pos);
	setCount(count-1);
	return temp.data;
}

template <> Advert FList<Advert>::pop_front(){
	seekg(head,ios::beg);
	FElem temp;
	read((char*)&temp.prev, sizeof(int));
	read((char*)&temp.next, sizeof(int));
	*this >> temp.data;
	if (temp.next == -1){
		temp.prev = -1;
		temp.next = -1;
		seekg(head, ios::beg);
		write((char*)&temp.prev, sizeof(int));
		write((char*)&temp.next, sizeof(int));
		setHead(-1);
		setTail(-1);
		setCount(0);
		return temp.data;
	}
	seekg(temp.next,ios::beg);
	int pos = temp.next;
	temp.prev = -1;
	write((char*)&temp.prev, sizeof(int));
	seekg(head,ios::beg);
	temp.prev = -1;
	temp.next = -1;
	write((char*)&temp.prev, sizeof(int));
	write((char*)&temp.next, sizeof(int));
	setHead(pos);
	setCount(count-1);
	return temp.data;
}

template <class DataT> DataT FList<DataT>::pop(int pos){
  if(pos == count) //если крайний элемент
  {
      return pop_back(); //удаляем с конца
  }
  else if (pos == 1) //если крайний элемент
  {  
	  return pop_front(); //удаляем с начала
  }
  int i = 1;
  seekg(head,ios::beg);
  FElem del;
  while(i < pos) //ищем позицию удаляемого элемента
  {
	  read((char*)&del.prev,sizeof(int));
	  read((char*)&del.next,sizeof(int));
	  seekg(del.next,ios::beg);
	  i++;
  }
  int currPos = tellp();
  read((char*)&del.prev,sizeof(int));
  read((char*)&del.next,sizeof(int));
  read((char*)&del.data,sizeof(DataT));
  seekg(del.prev+sizeof(int), ios::beg);
  write((char*)&del.next, sizeof(int));
  seekg(del.next, ios::beg);
  write((char*)&del.prev, sizeof(int));
  seekg(currPos, ios::beg);
  del.next = -1;
  del.prev = -1;
  write((char*)&del.prev, sizeof(int));
  write((char*)&del.next, sizeof(int));
  setCount(count-1);
  return del.data;
}

template <> Advert FList<Advert>::pop(int pos){
  if(pos == count) //если крайний элемент
  {
      return pop_back();
  }
  else if (pos == 1) //если крайний элемент
  {
	  
	  return pop_front();
  }
  int i = 1;
  seekg(head,ios::beg);
  FElem del;
  while(i < pos)
  {
	  read((char*)&del.prev,sizeof(int));
	  read((char*)&del.next,sizeof(int));
	  seekg(del.next,ios::beg);
	  i++;
  }
  int currPos = tellp();
  read((char*)&del.prev,sizeof(int));
  read((char*)&del.next,sizeof(int));
  *this >> del.data;
  seekg(del.prev+sizeof(int), ios::beg);
  write((char*)&del.next, sizeof(int));
  seekg(del.next, ios::beg);
  write((char*)&del.prev, sizeof(int));
  seekg(currPos, ios::beg);
  del.next = -1;
  del.prev = -1;
  write((char*)&del.prev, sizeof(int));
  write((char*)&del.next, sizeof(int));
  setCount(count-1);
  return del.data;
}

template <class DataT> void FList<DataT>::compress(char* fname){
	char buffer[15] = "buffer.dat";
	ofstream of(buffer);
	of.close();
	FList <DataT> f_buf(buffer);
	if (count == 0) { //если элементов нет
		close();
		f_buf.close();
		remove(fname);
		rename(buffer,fname);
		open(fname, ios::in | ios::out | ios::ate | ios::binary);
		return;
	}
	FElem temp;
	seekg(head,ios::beg);
	bool flag = true;
	while (flag){
		read((char*)&temp.prev, sizeof(int));
		read((char*)&temp.next, sizeof(int));
		read((char*)&temp.data, sizeof(DataT));
		f_buf.push_back(temp.data);
		if (temp.next == -1) 
			break;
		seekg(temp.next, ios::beg);
	}
	close();
	f_buf.close();
	remove(fname);
	rename(buffer,fname);
	open(fname, ios::in | ios::out | ios::ate | ios::binary);
}

template <> void FList<Advert>::compress(char* fname){
	char buffer[15] = "buffer.dat";
	ofstream of(buffer);
	of.close();
	FList <Advert> f_buf(buffer);
	if (count == 0) { //если элементов нет
		close();
		f_buf.close();
		remove(fname);
		rename(buffer,fname);
		open(fname, ios::in | ios::out | ios::ate | ios::binary);
		return;
	}
	FElem temp;
	seekg(head,ios::beg);
	bool flag = true;
	while (flag){
		read((char*)&temp.prev, sizeof(int));
		read((char*)&temp.next, sizeof(int));
		*this >> temp.data;
		f_buf.push_back(temp.data);
		if (temp.next == -1) 
			break;
		seekg(temp.next, ios::beg);
	}
	close();
	f_buf.close();
	remove(fname);
	rename(buffer,fname);
	open(fname, ios::in | ios::out | ios::ate | ios::binary);
}

template <class DataT> void FList<DataT>:: sort(){ //сортировка выбором
	try{
		if (count == 0) {
			throw exception("Отсутствуют элементы в списке!");
		}
		if (count == 1) {
			throw exception("В списке всего один элемент!");
		}
	}
	catch (exception &ex) {
		cout << endl << ex.what() << endl;
		return;
	}
	for (int i = 1; i < count; i++)
	{
		int min = i;
		for (int j = i + 1; j <= count; j++)
		{
			if (getFromPos(j) < getFromPos(min))
			{
				min = j;
			}
		}
		if (min != i)
		{
			DataT temp = pop(i);
			DataT minElem = pop(min-1);
			insert(i, minElem);
			insert(min, temp);
		}
	}
	cout << endl << "Сортировка прошла успешно!" << endl;
		
}

template <class DataT> void FList<DataT>::printList() {
	FElem temp;
	seekg(0,ios::beg);
	read((char*)&count,sizeof(int));
	read((char*)&head,sizeof(int));
	read((char*)&tail,sizeof(int));
	read((char*)&lastStreamPos,sizeof(int));
	try{
		if (count == 0) {
			throw exception("Нет элементов в списке!");
		}
	}
	catch (exception &ex){
		cout << ex.what() << endl;
		return;
	}
	cout << "Количество элементов в списке: " << count <<endl;
	cout << "Голова списка: " << head << endl;
	cout << "Хвост списка: " << tail << endl;
	cout << "Последняя позиция для записи: " << lastStreamPos << endl;
	cout << "-----------------------------------------------" << endl;
	seekg(head,ios::beg);
	bool flag = true;
	int i = 1;
	while(flag){
	cout << "Логический номер: " << i << endl;
	i++;
	cout << "Элемент на позиции: " << tellp() << endl;
	cout << endl;
	read((char*)&temp.prev,sizeof(int));
	cout << "Prev: " << temp.prev << endl;
	read((char*)&temp.next,sizeof(int));
	cout << "Next: " << temp.next << endl;
	cout << "Значение в узле:" << endl;
	read((char*)&temp.data, sizeof(DataT));
	cout << temp.data << endl;
	cout << "-----------------------------------------------" << endl;
	if (temp.next == -1) break;
	seekg(temp.next, ios::beg);
	}	
}

template <> void FList<Advert>::printList() {
	FElem temp;
	seekg(0,ios::beg);
	read((char*)&count,sizeof(int));
	read((char*)&head,sizeof(int));
	read((char*)&tail,sizeof(int));
	read((char*)&lastStreamPos,sizeof(int));
	try{
		if (count == 0) {
			throw exception("Нет элементов в списке!");
		}
	}
	catch (exception &ex){
		cout << ex.what() << endl;
		return;
	}
	cout << "Количество элементов в списке: " << count <<endl;
	cout << "Голова списка: " << head << endl;
	cout << "Хвост списка: " << tail << endl;
	cout << "Последняя позиция для записи: " << lastStreamPos << endl;
	cout << "-----------------------------------------------" << endl;
	seekg(head,ios::beg);
	bool flag = true;
	int i = 1;
	while(flag){
	cout << "Логический номер: " << i << endl;
	i++;
	cout << "Элемент на позиции: " << tellp() << endl;
	cout << endl;
	read((char*)&temp.prev,sizeof(int));
	cout << "Prev: " << temp.prev << endl;
	read((char*)&temp.next,sizeof(int));
	cout << "Next: " << temp.next << endl;
	cout << "Значение в узле:" << endl;
	*this >> temp.data;
	cout << temp.data;
	cout << "-----------------------------------------------" << endl;
	if (temp.next == -1) break;
	seekg(temp.next, ios::beg);
	}	
}

template <class DataT> void FList<DataT>::printListReverse() {
	FElem temp;
	seekg(0,ios::beg);
	read((char*)&count,sizeof(int));
	read((char*)&head,sizeof(int));
	read((char*)&tail,sizeof(int));
	read((char*)&lastStreamPos,sizeof(int));
	try{
		if (count == 0) {
			throw exception("Нет элементов в списке!");
		}
	}
	catch (exception &ex){
		cout << ex.what() << endl;
		return;
	}
	cout << "Количество элементов в списке: " << count <<endl;
	cout << "Голова списка: " << head << endl;
	cout << "Хвост списка: " << tail << endl;
	cout << "Последняя позиция для записи: " << lastStreamPos << endl;
	cout << "-----------------------------------------------" << endl;
	seekg(tail,ios::beg);
	bool flag = true;
	int i = count;
	while(flag){
	cout << "Логический номер: " << i << endl;
	i--;
	cout << "Элемент на позиции: " << tellp() << endl;
	cout << endl;
	read((char*)&temp.prev,sizeof(int));
	cout << "Prev: " << temp.prev << endl;
	read((char*)&temp.next,sizeof(int));
	cout << "Next: " << temp.next << endl;
	cout << "Значение в узле:" << endl;
	read((char*)&temp.data, sizeof(DataT));
	cout << temp.data << endl;
	cout << "-----------------------------------------------" << endl;
	if (temp.prev == -1) break;
	seekg(temp.prev, ios::beg);
	}	
}

template <> void FList<Advert>::printListReverse() {
	FElem temp;
	seekg(0,ios::beg);
	read((char*)&count,sizeof(int));
	read((char*)&head,sizeof(int));
	read((char*)&tail,sizeof(int));
	read((char*)&lastStreamPos,sizeof(int));
	try{
		if (count == 0) {
			throw exception("Нет элементов в списке!");
		}
	}
	catch (exception &ex){
		cout << ex.what() << endl;
		return;
	}
	cout << "Количество элементов в списке: " << count <<endl;
	cout << "Голова списка: " << head << endl;
	cout << "Хвост списка: " << tail << endl;
	cout << "Последняя позиция для записи: " << lastStreamPos << endl;
	cout << "-----------------------------------------------" << endl;
	seekg(tail,ios::beg);
	bool flag = true;
	int i = count;
	while(flag){
	cout << "Логический номер: " << i << endl;
	i--;
	cout << "Элемент на позиции: " << tellp() << endl;
	cout << endl;
	read((char*)&temp.prev,sizeof(int));
	cout << "Prev: " << temp.prev << endl;
	read((char*)&temp.next,sizeof(int));
	cout << "Next: " << temp.next << endl;
	cout << "Значение в узле:" << endl;
	*this >> temp.data;
	cout << temp.data << endl;
	cout << "-----------------------------------------------" << endl;
	if (temp.prev == -1) break;
	seekg(temp.prev, ios::beg);
	}	
}