#pragma once
#include "BigFloat.h"
class SignedBigFloat :public BigFloat
{
public:

	//---------------Конструкторы:----------------

	//SignedBigFloat::SignedBigFloat()
	//Конструктор знакового дробного числа по умолчанию 
	//args:
	//- нет входных параметров -
	// - создаёт объект по умолчанию -
	SignedBigFloat();

	//SignedBigFloat::SignedBigFloat(const char sign, const char* numInt, const char* numFloat);
	//Конструктор знаковой дробной части, принимающий типы const char*
	//args:
	// - const char sign - знак числа ('-' - минус, ' ' -положительное)
	//- const char* numInt - строка символов целой части
	//- const char* numFloat - строка символов дробной части
	// - создаёт объект по входным параметрам const char*  -
	SignedBigFloat(const char sign, 
		const char* numInt, const char* numFloat);

	//SignedBigFloat::SignedBigFloat(const char sign, long numInt, long numFloat);
	//Конструктор знаковой дробной части, принимающий типы long
	//args:
	//- const char sign - знак числа
	//- long numInt - длинное целочисленное число
	//- long numFloat - длинная дробная часть
	//- создаёт объект по входным параметрам long -
	SignedBigFloat(const char sign, long numInt, 
		long numFloat);

	//SignedBigFloat::SignedBigFloat(SignedBigFloat &other)
	//Конструктор знаковой дробной части, делающий копию другого объекта этого класса
	//args:
	//- SignedBigFloat &other - объект для копирования
	// - создаёт копию входного объекта -
	SignedBigFloat(SignedBigFloat& other);

	//---------------Деструктор:----------------

	//SignedBigFloat::~SignedBigFloat()
	//Деструктор
	//args:
	//- нет входных параметров - 
	// - удаление объекта -
	~SignedBigFloat();

	//---------------Геттеры:-------------------

	//bool SignedBigFloat::getSign()
	//Функция возврата знака числа
	//args:
	//- нет входных параметров - 
	//return - true - плюс, false - минус
	bool getSign();

	//---------------Сеттеры:-------------------

	//void SignedBigFloat::setSign(bool pos)
	//Функция устанавливает знак числа bool pos
	//args:
	//int currentLength - текущая длина для замены
	//- устанавливает в объект знак числа bool pos -
	void setSign(bool pos);

	//------Функции для работы с объектами класса:------

	//void SignedBigFloat::add(SignedBigFloat& numOne, SignedBigFloat& numTwo)
	//Функция сложения чисел знакового дробного типа
	//args:
	//SignedBigFloat& numOne - первый объект
	//SignedBigFloat& numTwo - второй объект
	//- складываются два числа двух объектов данного класса -
	void add(SignedBigFloat& numOne, 
		SignedBigFloat& numTwo);

	//void SignedBigFloat::multiply(SignedBigFloat& numOne, SignedBigFloat& numTwo)
	//Функция умножения чисел знакового дробного типа
	//args:
	//SignedBigFloat& numOne - первый объект
	//SignedBigFloat& numTwo - второй объект
	//- умножаются два числа двух объектов данного класса-
	void multiply(SignedBigFloat& numOne,
		SignedBigFloat& numTwo);

	//void SignedBigFloat::deduct(SignedBigFloat& numOne, SignedBigFloat& numTwo)
	//Функция вычитания чисел знакового дробного типа
	//args:
	//SignedBigFloat& numOne - первый объект
	//SignedBigFloat& numTwo - второй объект
	//- вычитаются из первого числа первого объекта второе число 
	//второго объекта знакового дробного типа -
	void deduct(SignedBigFloat& numOne,
		SignedBigFloat& numTwo);

	//char* SignedBigFloat::toString()
	//Функция перевода всего знакового дробного числа в массив char
	//args:
	//- нет входных параметров -
	//return - массив символов char (число объекта)
	char* toString();

private:

	//знак числа
	bool positive;

	//void SignedBigFloat::writeMemory(BigFloat& obj)
	//Функция записи данных объекта BigFloat в объект SignedBigFloat
	//args:
	//- нет входных параметров -
	//записывает данные объекта BigFloat в объект SignedBigFloat
	void writeMemory(BigFloat& obj);
};

