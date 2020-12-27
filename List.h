#pragma once
#include <iostream>
#include <fstream>
#include "Advert.h"
using namespace std;
 
template <class DataT> class FList : public fstream
{
public:
	
	FList(); //����������� ��� ����������
	FList(char*); //����������� � ����������
	int getHead(); //������� ������� ������ ������ � �����
	int getTail(); //������� ������� ����� ������ � �����
	int getCount(); //������� �������� ���������� ��������� ������
	int getLastPos(); //������� �������� ��������� ��������� ������� ��� ������
	void setHead(int); //���������� �������� ������ ������
	void setTail(int); //���������� �������� ����� ������
	void setCount(int); //���������� �������� ���������� �������� ������
	void setLastPos(int); //���������� �������� ��������� ��������� ������� ��� ������

	void printList(); //������ ������ �� ������� (������������ ��������)
	void printListReverse(); //������ ������ �� ������� � �������� �����������
	void push_back(DataT); //������� ���� � ����� ������
	void push_front(DataT); //������� ���� � ������ ������
	bool insert(int, DataT); //������� ���� �� ����������� ������
	int insertSort(DataT); //������� ���� � ����������� �������
	bool update(int); //���������� ������
	DataT getFromPos(int); //���������� �� ����������� ������
	int find(DataT); //����� ��������� �� �����
	DataT pop_back(); //�������� � ����� ������
	DataT pop_front(); //�������� � ������ ������
	DataT pop(int pos); //�������� � ������� �� ���. ������
	void sort(); //���������� �������
	void compress(char*); //������ �����

private:
	class FElem { //���� ������������ ������ � �����
	public: 
		FElem():next(-1),prev(-1){};
		DataT data; //��������� ��������
		int next; //��������� �� ��������� ���� � �����
		int prev; //��������� �� ���������� ���� � �����
	};
	int head; //��������� �� "������" � �����
	int tail; //��������� �� "�����" � �����
	int count; //����� ������
	int lastStreamPos; //��������� ������� ������ � �����
};

template <class DataT> FList<DataT> ::FList():fstream() {
	char* fname = "test.dat";
	ofstream f(fname); //������� �������� �����, ��� �� ������� ����
	if (!f) {
		cout << "������! ���������� ��������� ����!" << endl;
		f.close();
		return;
	}
	f.close(); //��������� ����
	open(fname, ios::in | ios::out | ios::ate | ios::binary);	//��������� ���� � ������� ������
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
		cout << "������! ���������� ��������� ����!" << endl;
		f.close();
		return;
		}
		f.close();	
		fstream::open(_fname, ios::in | ios::out | ios::ate | ios::binary);	//��������� ���� � ������� ������
	}
	if ((int)tellp() == 0)	//���� ������� ���������� �������� � ����� ����� ����, ������ ���� ����
	{
		count = 0;
		head = -1;
		tail = -1;
		lastStreamPos = 16;
		seekg(0,ios::beg);
		write((char*)&count,sizeof(int)); //���������� ���������� ��������� ������
		write((char*)&head,sizeof(int)); //���������� "������" ������
		write((char*)&tail,sizeof(int)); //���������� "�����" ������
		write((char*)&lastStreamPos,sizeof(int)); //���������� ��������� ������� � �����
	}
	else
	{
		seekg(0,ios::beg);
		read((char*)&count,sizeof(int)); //��������� ���������� ��������� ������
		read((char*)&head,sizeof(int)); //��������� "������" ������
		read((char*)&tail,sizeof(int)); //��������� "�����" ������
		read((char*)&lastStreamPos,sizeof(int)); //��������� ��������� ������� � �����
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
if (count == 0) { //���� ��������� � ������ ���, �� ��������� ������
	FElem temp;
	temp.data = value; //�������� ���� ������
	setHead(16); //������������� ������ � � ��������� ������
	setTail(16); //������������� ����� � � ��������� ������
	seekg(tail,ios::beg);
	write((char*)&temp.prev, sizeof(int)); //���������� �������� ��������� �� ���������� �������
	write((char*)&temp.next, sizeof(int)); //���������� �������� ��������� �� ��������� �������
	write((char*)&temp.data, sizeof(DataT));  //���������� �������� ����
	setCount(count+1); //��������� ������� �����
	setLastPos(tellp()); //��������� ��������� ������� ��� ������
    }
   else { //���� �������� � ������ ����
	FElem temp;
	temp.next = -1; //�������� ��������� �� ��������� ������� "��������"
	temp.prev = tail; //�������� ��������� �� ���������� ������� ��������� �� "���������� �����" ������
	temp.data = value; //�������� ����
	seekg(lastStreamPos,ios::beg); //��������� �� ��������� ��������� ������� ��� ������
	write((char*)&temp.prev, sizeof(int)); //���������� �������� ��������� �� ���������� �������
	write((char*)&temp.next, sizeof(int)); //���������� �������� ��������� �� ��������� �������
	write((char*)&temp.data, sizeof(DataT));  //���������� �������� ����
	int pos = tellp(); //���������� ��������� ��������� ������� ��� ������
	setCount(count+1); //��������� ������� �����
	setTail(lastStreamPos); //������ �������� "������ ������ ������"
	seekg(temp.prev+sizeof(int), ios::beg); //������������ � ������ ��������� ���������-next ����������� ��������
	write((char*)&tail, sizeof(int)); //�������� ���������-next ����������� �������� ��������� �� ����� ��������� 
	seekg(pos, ios::beg); //������������ �� ��������� ��������� ������� ��� ������
	setLastPos(pos); //��������� ��������� ������� ��� ������
   }
}

template <> void FList<Advert>::push_back(Advert value) { 
if (count == 0) { //���� ��������� � ������ ���, �� ��������� ������
	FElem temp;
	temp.data = value; //�������� ���� ������
	setHead(16); //������������� ������ � � ��������� ������
	setTail(16); //������������� ����� � � ��������� ������
	seekg(tail,ios::beg);
	write((char*)&temp.prev, sizeof(int)); //���������� �������� ��������� �� ���������� �������
	write((char*)&temp.next, sizeof(int)); //���������� �������� ��������� �� ��������� �������
	*this << temp.data; //���������� �������� ����
	setCount(count+1); //��������� ������� �����
	setLastPos(tellp()); //��������� ��������� ������� ��� ������
    }
   else { //���� �������� � ������ ����
	FElem temp;
	temp.next = -1; //�������� ��������� �� ��������� ������� "��������"
	temp.prev = tail; //�������� ��������� �� ���������� ������� ��������� �� "���������� �����" ������
	temp.data = value; //�������� ����
	seekg(lastStreamPos,ios::beg); //��������� �� ��������� ��������� ������� ��� ������
	write((char*)&temp.prev, sizeof(int)); //���������� �������� ��������� �� ���������� �������
	write((char*)&temp.next, sizeof(int)); //���������� �������� ��������� �� ��������� �������
	*this << temp.data;  //���������� �������� ����
	int pos = tellp(); //���������� ��������� ��������� ������� ��� ������
	setCount(count+1); //��������� ������� �����
	setTail(lastStreamPos); //������ �������� "������ ������ ������"
	seekg(temp.prev+sizeof(int), ios::beg); //������������ � ������ ��������� ���������-next ����������� ��������
	write((char*)&tail, sizeof(int)); //�������� ���������-next ����������� �������� ��������� �� ����� ��������� 
	seekg(pos, ios::beg); //������������ �� ��������� ��������� ������� ��� ������
	setLastPos(pos); //��������� ��������� ������� ��� ������
   }
}

template <class DataT> void FList<DataT>::push_front(DataT value) { 
if (count == 0) { //���� ��������� � ������ ���, �� ��������� ������
	FElem temp;
	temp.data = value; //�������� ���� ������
	setHead(16); //������������� ������ � � ��������� ������
	setTail(16); //������������� ����� � � ��������� ������
	seekg(tail,ios::beg);
	write((char*)&temp.prev, sizeof(int)); //���������� �������� ��������� �� ���������� �������
	write((char*)&temp.next, sizeof(int)); //���������� �������� ��������� �� ��������� �������
	write((char*)&temp.data,sizeof(DataT)); //���������� �������� ����
	setCount(count+1); //��������� ������� �����
	setLastPos(tellp()); //��������� ��������� ������� ��� ������
    }
   else { //���� �������� � ������ ����
	FElem temp;
	temp.prev = -1; //�������� ��������� �� ���������� ������� "��������"
	temp.next = head; //�������� ��������� �� ��������� ������� ��������� �� "���������� ������" ������
	temp.data = value; //�������� ����
	seekg(lastStreamPos,ios::beg); //��������� �� ��������� ��������� ������� ��� ������
	write((char*)&temp.prev, sizeof(int)); //���������� �������� ��������� �� ���������� �������
	write((char*)&temp.next, sizeof(int)); //���������� �������� ��������� �� ��������� �������
	write((char*)&temp.data, sizeof(DataT)); //���������� �������� ����
	int pos = tellp(); //���������� ��������� ��������� ������� ��� ������
	setCount(count+1); //��������� ������� �����
	setHead(lastStreamPos); //������ �������� "����� ������ ������"
	seekg(temp.next, ios::beg); //������������ � ������ ��������� ���������-prev ���������� ��������
	write((char*)&head, sizeof(int)); //�������� ���������-prev ���������� �������� ��������� �� ����� ��������� 
	seekg(pos, ios::beg); //������������ �� ��������� ��������� ������� ��� ������
	setLastPos(pos); //��������� ��������� ������� ��� ������
   }
}

template <> void FList<Advert>::push_front(Advert value) { 
if (count == 0) { //���� ��������� � ������ ���, �� ��������� ������
	FElem temp;
	temp.data = value; //�������� ���� ������
	setHead(16); //������������� ������ � � ��������� ������
	setTail(16); //������������� ����� � � ��������� ������
	seekg(tail,ios::beg);
	write((char*)&temp.prev, sizeof(int)); //���������� �������� ��������� �� ���������� �������
	write((char*)&temp.next, sizeof(int)); //���������� �������� ��������� �� ��������� �������
	*this << temp.data; //���������� �������� ����
	setCount(count+1); //��������� ������� �����
	setLastPos(tellp()); //��������� ��������� ������� ��� ������
    }
   else { //���� �������� � ������ ����
	FElem temp;
	temp.prev = -1; //�������� ��������� �� ���������� ������� "��������"
	temp.next = head; //�������� ��������� �� ��������� ������� ��������� �� "���������� ������" ������
	temp.data = value; //�������� ����
	seekg(lastStreamPos,ios::beg); //��������� �� ��������� ��������� ������� ��� ������
	write((char*)&temp.prev, sizeof(int)); //���������� �������� ��������� �� ���������� �������
	write((char*)&temp.next, sizeof(int)); //���������� �������� ��������� �� ��������� �������
	*this << temp.data;  //���������� �������� ����
	int pos = tellp(); //���������� ��������� ��������� ������� ��� ������
	setCount(count+1); //��������� ������� �����
	setHead(lastStreamPos); //������ �������� "����� ������ ������"
	seekg(temp.next, ios::beg); //������������ � ������ ��������� ���������-prev ���������� ��������
	write((char*)&head, sizeof(int)); //�������� ���������-prev ���������� �������� ��������� �� ����� ��������� 
	seekg(pos, ios::beg); //������������ �� ��������� ��������� ������� ��� ������
	setLastPos(pos); //��������� ��������� ������� ��� ������
   }
}

template <class DataT> bool FList<DataT>::insert(int pos, DataT value) { 
	try{
	if(pos < 1 || pos > count + 1)
    {
      //�������� �������
      throw exception("������! �������� �������� ����������� ������!");
    }	
	}
	catch (exception &ex){
		cout << ex.what() << endl;
		return false;
	}
  if(pos == count + 1) //���� ������� �������
  {
      push_back(value); //��������� � ����� ������
      return true;
  }
  else if (pos == 1) //���� ������� �������
  {
	  push_front(value); //��������� � ������ ������
	  return true;
  }
  int i = 1;
  seekg(head,ios::beg);
  FElem nextIns; //��������� ���� ����� ������������
  read((char*)&nextIns.prev,sizeof(int));
  read((char*)&nextIns.next,sizeof(int));
  seekg(nextIns.next,ios::beg);
  while(i < pos) //����� ������� �������
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
  FElem prevIns; //���������� ���� ����� �����������
  read((char*)&prevIns.prev,sizeof(int));
  read((char*)&prevIns.next,sizeof(int));
  FElem ins; //����������� ����
  ins.prev = nextIns.prev; // ���������� �������� ��������� �� ����������
  ins.next = prevIns.next; // ���������� �������� ��������� �� ���������
  ins.data = value; //���������� �������� ����
  seekg(ins.prev+sizeof(int), ios::beg); 
  write((char*)&lastStreamPos,sizeof(int)); //������������ �������� ���������-next ����������� ���� �� �����������
  seekg(ins.next, ios::beg);
  write((char*)&lastStreamPos,sizeof(int)); //������������ �������� ���������-prev ���������� ���� �� �����������
  seekg(lastStreamPos, ios::beg);
  write((char*)&ins.prev,sizeof(int)); //���������� �������� ��������� prev ������ ���� � �������� ����
  write((char*)&ins.next,sizeof(int)); //���������� �������� ��������� next ������ ���� � �������� ����
  write((char*)&ins.data,sizeof(DataT)); //���������� �������� ����
  setCount(count+1); //��������� �������
  setLastPos(tellp()); //��������� ��������� ������� ��� ������
  return true;
}

template <> bool FList<Advert>::insert(int pos, Advert value) { 
	try{
	if(pos < 1 || pos > count + 1)
    {
      //�������� �������
      throw exception("������! �������� �������� ����������� ������!");
    }	
	}
	catch (exception &ex){
		cout << ex.what() << endl;
		return false;
	}
  if(pos == count + 1) //���� ������� �������
  {
      push_back(value); //��������� � ����� ������
      return true;
  }
  else if (pos == 1) //���� ������� �������
  {
	  push_front(value); //��������� � ������ ������
	  return true;
  }
  int i = 1;
  seekg(head,ios::beg);
  FElem nextIns; //��������� ���� ����� ������������
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
  FElem prevIns; //���������� ���� ����� �����������
  read((char*)&prevIns.prev,sizeof(int));
  read((char*)&prevIns.next,sizeof(int));
  FElem ins; //����������� ����
  ins.prev = nextIns.prev; // ���������� �������� ��������� �� ����������
  ins.next = prevIns.next; // ���������� �������� ��������� �� ���������
  ins.data = value; //���������� �������� ����
  seekg(ins.prev+sizeof(int), ios::beg);
  write((char*)&lastStreamPos,sizeof(int)); //������������ �������� ���������-next ����������� ���� �� �����������
  seekg(ins.next, ios::beg);
  write((char*)&lastStreamPos,sizeof(int)); //������������ �������� ���������-prev ���������� ���� �� �����������
  seekg(lastStreamPos, ios::beg);
  write((char*)&ins.prev,sizeof(int)); //���������� �������� ��������� prev ������ ���� � �������� ����
  write((char*)&ins.next,sizeof(int)); //���������� �������� ��������� next ������ ���� � �������� ����
  *this << ins.data; //���������� �������� ����
  setCount(count+1); //��������� �������
  setLastPos(tellp()); //��������� ��������� ������� ��� ������
  return true;
}

template <class DataT> int FList<DataT>::insertSort(DataT value){
	FElem nextIns; //��������� ������� ����� ������������
	int i = 1;
	if (head == -1){
		push_back(value);
		return i;
	}
	seekg(head,ios::beg);
	while (i < count+1){ //�������� �� ������
		read((char*)&nextIns.prev,sizeof(int));
		read((char*)&nextIns.next,sizeof(int));
		read((char*)&nextIns.data, sizeof(DataT));
		if (value < nextIns.data){ //���� ����� ��� �������
			break;
		}
		i++;
		if (nextIns.next==-1){ //�������� ����� �� ���� � -1
			break;
		}
		seekg(nextIns.next, ios::beg);
		
	}
	insert(i,value);//��������� �� ���������� ����������� ������
	return i;
}

template <> int FList<Advert>::insertSort(Advert value){
	FElem nextIns; //��������� ���� ����� ������������
	int i = 1;
	if (head == -1){
		push_back(value);
		return i;
	}
	seekg(head,ios::beg);
	while (i < count+1){ //�������� �� ������
		read((char*)&nextIns.prev,sizeof(int));
		read((char*)&nextIns.next,sizeof(int));
		*this >> nextIns.data;
		if (value < nextIns.data){ //����� ������� �������
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
      //�������� �������
      throw exception("������! �������� �������� ����������� ������!");
    }	
	}
	catch (exception &ex){
		cout << ex.what() << endl;
		return false;
	}
	FElem temp; //������������� ����
	if (pos == 1){ //���� ��� ������ ������
		seekg(head, ios::beg);
	}
	else if (pos == count){ //���� ��� ����� ������
		seekg(tail, ios::beg);
	}
	else { //���� ������ �������
		seekg(head, ios::beg);
		int i = 1;
		while (i!=pos){ //���� ������� �������������� ��������
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
	cout << "���� � ���������� �������: " << pos << endl;
	cout << "Next: " << temp.next << endl;
	cout << "Prev: " << temp.prev << endl;
	cout << "�������� � ����: " << endl;
	cout << temp.data << endl;
	cout << "������� ����� �������� ��� ��������������: " << endl;
	cin >> temp.data; //������ ����� ������
	seekg(currPos,ios::beg);
	write((char*)&temp.data, sizeof(DataT));
	cout << "------------------------------------------ " << endl;
	cout << "��������������� ���� � ���������� �������: " << pos << endl;
	cout << "Next: " << temp.next << endl;
	cout << "Prev: " << temp.prev << endl;
	cout << "�������� � ����: " << endl;
	cout << temp.data << endl;
	seekg(lastStreamPos,ios::beg);
	return true;
}

template <> bool FList<Advert>::update(int pos){
	try{
	if(pos < 1 || pos > count)
    {
      //�������� �������
      throw exception("������! �������� �������� ����������� ������!");
    }	
	}
	catch (exception &ex){
		cout << ex.what() << endl;
		return false;
	}
	FElem temp;
	if (pos == 1){ //���� ��� ������ ������
		seekg(head, ios::beg);
	}
	else if (pos == count){ //���� ��� ����� ������
		seekg(tail, ios::beg);
	}
	else { //���� ������ �������
		seekg(head, ios::beg);
		int i = 1;
		while (i!=pos){ //���� ������� �������������� ��������
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
	cout << "������������� ���� ������ � ���������� �������: " << pos << endl;
	cout << "Prev: " << temp.prev << endl;
	cout << "Next: " << temp.next << endl;
	cout << "�������� � ����: " << endl;
	cout << temp.data << endl;
	(temp.data).redact(temp.data); //����������� ������
	seekg(lastStreamPos, ios::beg); //��� �� ��������� ������� ��� ������
	//���������� ���������� �������� next,prev � data �������������� ���� � ��������� ��������� ������� ��� ������ � �������� �����
	write((char*)&temp.prev, sizeof(int)); 
	write((char*)&temp.next, sizeof(int)); 
	*this << temp.data; 
	int currPos = tellp();
	if (pos == 1){
		if (count !=1){
			seekg(temp.next, ios::beg);
			write((char*)&lastStreamPos,sizeof(int));
			//"��������" �������� ��������� � ������� ������� ����
			temp.prev = -1; 
			temp.next = -1;
			seekg(head,ios::beg);
			write((char*)&temp.prev,sizeof(int));
			write((char*)&temp.next,sizeof(int));
			//������������� "������" ������ �� ����������������� ����
			setHead(lastStreamPos);
			//��������� ��������� ��������� ������ ��� ������
			setLastPos(currPos);
			return true;
		}
		else { //���� ������������� ������� ������������ � ������
			setHead(lastStreamPos);
			setTail(lastStreamPos);
			//��������� ��������� ��������� ������ ��� ������
			setLastPos(currPos);
			return true;
		}
	}
	if (pos == count){  //���� ����������� ����� ������ 
		seekg(temp.prev+sizeof(int), ios::beg);
		write((char*)&lastStreamPos,sizeof(int));
		//"��������" �������� ��������� � ������� ������� ����
		temp.prev = -1; 
		temp.next = -1;
		seekg(tail,ios::beg);
		write((char*)&temp.prev,sizeof(int));
		write((char*)&temp.next,sizeof(int));
		//������������� "�����" ������ �� ����������������� ����
		setTail(lastStreamPos);
		//��������� ��������� ��������� ������� ��� ������
		setLastPos(currPos);
		return true;
	}
	//���� �� ����� � �� ������ ������
	//��������������� ��� ����� �������������� ����, � ����� � ��� ����� �������� � �����
	seekg(temp.prev+sizeof(int), ios::beg);
	write((char*)&lastStreamPos, sizeof(int));
	seekg(temp.next, ios::beg);
	write((char*)&lastStreamPos, sizeof(int));
	seekg(currPos,ios::beg);
	//"��������" �������� ��������� � ������� ������� ����
	temp.prev = -1;
	temp.next = -1;
	write((char*)&temp.prev, sizeof(int));
	write((char*)&temp.next, sizeof(int));
	//��������� �������� ��������� ��������� ������� ��� ������
	setLastPos(currPos);
	return true;
}

template <class DataT> DataT FList<DataT>::getFromPos(int pos){
	FElem temp;
	seekg(head, ios::beg);
	int i = 1;
	while (i!=pos){ //���� ������� ������������ ����
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
	return temp.data; //���������� ��������
}

template <> Advert FList<Advert>::getFromPos(int pos){
	FElem temp;
	seekg(head, ios::beg);
	int i = 1;
	while (i!=pos){ //���� �������
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
	return temp.data; //���������� �������� ����
}

template <class DataT> int FList<DataT>::find(DataT key){
	FElem temp;
	try{
		if (head == -1) 
			throw exception("������! � ������ ��� ���������!");
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
		if (temp.data == key) { //���� �������� ����� ������� �� ��������� ���� �� ������, �� ������� ������ ����
			cout << "��������� ���� ������ � ���������� �������: " << i << endl;
			cout << "Prev: " << temp.prev << endl;
			cout << "Next: " << temp.next << endl;
			cout << "�������� � ����: " << endl;
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
			throw exception("������! � ������ ��� ���������!");
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
			cout << "��������� ���� ������ � ���������� �������: " << i << endl;
			cout << "Prev: " << temp.prev << endl;
			cout << "Next: " << temp.next << endl;
			cout << "�������� � ����: " << endl;
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
	seekg(tail,ios::beg); //������������ �� ����� ������
	FElem temp;
	read((char*)&temp.prev, sizeof(int));
	read((char*)&temp.next, sizeof(int));
	read((char*)&temp.data, sizeof(int));
	if (temp.prev == -1){ //���� ��������� ������� ������
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
  if(pos == count) //���� ������� �������
  {
      return pop_back(); //������� � �����
  }
  else if (pos == 1) //���� ������� �������
  {  
	  return pop_front(); //������� � ������
  }
  int i = 1;
  seekg(head,ios::beg);
  FElem del;
  while(i < pos) //���� ������� ���������� ��������
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
  if(pos == count) //���� ������� �������
  {
      return pop_back();
  }
  else if (pos == 1) //���� ������� �������
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
	if (count == 0) { //���� ��������� ���
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
	if (count == 0) { //���� ��������� ���
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

template <class DataT> void FList<DataT>:: sort(){ //���������� �������
	try{
		if (count == 0) {
			throw exception("����������� �������� � ������!");
		}
		if (count == 1) {
			throw exception("� ������ ����� ���� �������!");
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
	cout << endl << "���������� ������ �������!" << endl;
		
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
			throw exception("��� ��������� � ������!");
		}
	}
	catch (exception &ex){
		cout << ex.what() << endl;
		return;
	}
	cout << "���������� ��������� � ������: " << count <<endl;
	cout << "������ ������: " << head << endl;
	cout << "����� ������: " << tail << endl;
	cout << "��������� ������� ��� ������: " << lastStreamPos << endl;
	cout << "-----------------------------------------------" << endl;
	seekg(head,ios::beg);
	bool flag = true;
	int i = 1;
	while(flag){
	cout << "���������� �����: " << i << endl;
	i++;
	cout << "������� �� �������: " << tellp() << endl;
	cout << endl;
	read((char*)&temp.prev,sizeof(int));
	cout << "Prev: " << temp.prev << endl;
	read((char*)&temp.next,sizeof(int));
	cout << "Next: " << temp.next << endl;
	cout << "�������� � ����:" << endl;
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
			throw exception("��� ��������� � ������!");
		}
	}
	catch (exception &ex){
		cout << ex.what() << endl;
		return;
	}
	cout << "���������� ��������� � ������: " << count <<endl;
	cout << "������ ������: " << head << endl;
	cout << "����� ������: " << tail << endl;
	cout << "��������� ������� ��� ������: " << lastStreamPos << endl;
	cout << "-----------------------------------------------" << endl;
	seekg(head,ios::beg);
	bool flag = true;
	int i = 1;
	while(flag){
	cout << "���������� �����: " << i << endl;
	i++;
	cout << "������� �� �������: " << tellp() << endl;
	cout << endl;
	read((char*)&temp.prev,sizeof(int));
	cout << "Prev: " << temp.prev << endl;
	read((char*)&temp.next,sizeof(int));
	cout << "Next: " << temp.next << endl;
	cout << "�������� � ����:" << endl;
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
			throw exception("��� ��������� � ������!");
		}
	}
	catch (exception &ex){
		cout << ex.what() << endl;
		return;
	}
	cout << "���������� ��������� � ������: " << count <<endl;
	cout << "������ ������: " << head << endl;
	cout << "����� ������: " << tail << endl;
	cout << "��������� ������� ��� ������: " << lastStreamPos << endl;
	cout << "-----------------------------------------------" << endl;
	seekg(tail,ios::beg);
	bool flag = true;
	int i = count;
	while(flag){
	cout << "���������� �����: " << i << endl;
	i--;
	cout << "������� �� �������: " << tellp() << endl;
	cout << endl;
	read((char*)&temp.prev,sizeof(int));
	cout << "Prev: " << temp.prev << endl;
	read((char*)&temp.next,sizeof(int));
	cout << "Next: " << temp.next << endl;
	cout << "�������� � ����:" << endl;
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
			throw exception("��� ��������� � ������!");
		}
	}
	catch (exception &ex){
		cout << ex.what() << endl;
		return;
	}
	cout << "���������� ��������� � ������: " << count <<endl;
	cout << "������ ������: " << head << endl;
	cout << "����� ������: " << tail << endl;
	cout << "��������� ������� ��� ������: " << lastStreamPos << endl;
	cout << "-----------------------------------------------" << endl;
	seekg(tail,ios::beg);
	bool flag = true;
	int i = count;
	while(flag){
	cout << "���������� �����: " << i << endl;
	i--;
	cout << "������� �� �������: " << tellp() << endl;
	cout << endl;
	read((char*)&temp.prev,sizeof(int));
	cout << "Prev: " << temp.prev << endl;
	read((char*)&temp.next,sizeof(int));
	cout << "Next: " << temp.next << endl;
	cout << "�������� � ����:" << endl;
	*this >> temp.data;
	cout << temp.data << endl;
	cout << "-----------------------------------------------" << endl;
	if (temp.prev == -1) break;
	seekg(temp.prev, ios::beg);
	}	
}