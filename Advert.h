#pragma once
#include <iostream>
#include <fstream>
class Advert
{
public:
	static const char rubrics[6][30];
	Advert();
	Advert(char _category, int _rubric, int _dd, int _mm, int _yy, char* _text, char *telephone);
	Advert(Advert &other);
	~Advert();
	
	friend std::ostream& operator<< (std::ostream &, Advert &);//���������� ������������� �������� ��������� ���������� ������
	friend std::istream& operator>> (std::istream &, Advert &); //���������� ������������� �������� ��������� ���������� �����
	friend std::fstream& operator<< (std::fstream&, Advert&); //���������� ������������� �������� ��������� ��������� ������
	friend std::fstream& operator>> (std::fstream&, Advert&); //���������� ������������� �������� ��������� ��������� �����
	Advert& operator =(Advert const&); //���������� ������������
	bool operator == (Advert const&); //���������� ��������� ���������
	bool operator > (Advert&); //���������� ��������� "������"
	bool operator < (Advert&); //���������� ��������� "������"
	void SetRub(int r); //������ - �������
	void SetText(char* text);
	void print();
private:
	char category; //��������� (�����-������)
	int rubric; //�������
	int dd, mm, yy; //���� ������
	char* text; //����� ����������
	char* telephone; //�������
};

