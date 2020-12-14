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
	
	friend std::ostream& operator<< (std::ostream &, Advert &);//перегрузка дружественной функцией оператора потокового вывода
	friend std::istream& operator>> (std::istream &, Advert &); //перегрузка дружественной функцией оператора потокового ввода
	friend std::fstream& operator<< (std::fstream&, Advert&); //перегрузка дружественной функцией оператора файлового вывода
	friend std::fstream& operator>> (std::fstream&, Advert&); //перегрузка дружественной функцией оператора файлового ввода
	Advert& operator =(Advert const&); //перегрузка присваивания
	bool operator == (Advert const&); //перегрузка сравнения равенства
	bool operator > (Advert&); //перегрузка сравнения "больше"
	bool operator < (Advert&); //перегрузка сравнения "меньше"
	void SetRub(int r); //сеттер - рубрики
	void SetText(char* text);
	void print();
private:
	char category; //категория (куплю-продам)
	int rubric; //рубрика
	int dd, mm, yy; //дата подачи
	char* text; //текст объявления
	char* telephone; //телефон
};

