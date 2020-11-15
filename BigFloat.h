#pragma once
#include "BigInt.h"
class BigFloat : public BigInt
{
public:
	//---------------Конструкторы:----------------

	//BigFloat::BigFloat()
	//Конструктор дробной части по умолчанию 
	//args:
	//- нет входных параметров -
	// - создаёт объект по умолчанию -
	BigFloat();

	//BigFloat::BigFloat(long numInt, long numFloat)
	//Конструктор дробной части, принимающий типы long
	//args:
	//- long numInt - длинное целочисленное число
	//- long numFloat - длинная дробная часть
	//- создаёт объект по входным параметрам long -
	BigFloat(long numInt, long numFloat);

	//BigFloat::BigFloat(const char* numInt, const char* numFloat)
	//Конструктор дробной части, принимающий типы const char*
	//args:
	//- const char* numInt - строка символов целой части
	//- const char* numFloat - строка символов дробной части
	// - создаёт объект по входным параметрам const char*  -
	BigFloat(const char* numInt, const char* numFloat);

	//BigFloat::BigFloat(BigFloat &other)
	//Конструктор дробнойчасти, делающий копию другого объекта этого класса
	//args:
	//- BigFloat &other - объект для копирования
	// - создаёт копию входного объекта -
	BigFloat(const BigFloat& other);

	//---------------Деструктор:----------------

	//BigFloat::~BigFloat()
	//Деструктор
	//args:
	//- нет входных параметров - 
	// - удаление объекта -
	~BigFloat();

	//---------------Геттеры:-------------------

	//int BigFloat::getLengthFloat()
	//Функция возврата длины числа после запятой в объекте
	//args:
	//- нет входных параметров - 
	//return - длина числа после запятой в объекте
	int getLengthFloat();

	//int BigFloat::getFloatNumberValue(int i)
	//Функция возврата элемента массива дробного длинного числа в разряде i
	//args:
	//int i - порядковый номер разряда дробного числа (после запятой)
	//return - элемент массива длинного дробного числа в разряде i
	int getFloatNumberValue(int i);

	//---------------Сеттеры:-------------------

	//void BigFloat::setLength(int currentLength)
	//Функция устанавливает новую заданную длину дробного числа currentLength
	//args:
	//int currentLength - текущая длина для замены
	//- устанавливает в объект новую заданную длину currentLength -
	void setLengthFloat(int currentLength);

	//void BigFloat::setLongNumberValue(int i, int value)
	//Функция устанавливает новое значение числа value в разряд i дробного числа
	//args:
	//int i - порядковый номер разряда числа 
	//int value - новое устанавливаемое значение разряда
	//- устанавливает новое значение числа value в разряд i -
	void setFloatNumberValue(int i, int value);

	//void BigFloat::setArray()
	//Функция создаёт новый массив длинного дробного числа размерности lengthFloat
	//args:
	//- нет входных параметров -
	//- создаётся новый массив числа -
	void setFloatArray();

	//------Функции для работы с объектами класса:------

	//void BigFloat::add(BigFloat& numOne, BigFloat& numTwo)
	//Функция сложения чисел дробного типа
	//args:
	//BigFloat& numOne - первый объект
	//BigFloat& numTwo - второй объект
	//- складываются два числа двух объектов данного класса -
	void add(BigFloat& numOne, BigFloat& numTwo);

	//void BigFloat::multiply(BigFloat& numOne, BigFloat& numTwo)
	//Функция умножения чисел дробного типа
	//args:
	//BigFloat& numOne - первый объект
	//BigFloat& numTwo - второй объект
	//- умнажаются два числа двух объектов данного класса-
	void multiply(BigFloat& numOne, BigFloat& numTwo);

	//void BigFloat::deduct(BigFloat& numOne, BigFloat& numTwo)
	//Функция вычитания чисел дробного типа
	//args:
	//BigFloat& numOne - первый объект
	//BigFloat& numTwo - второй объект
	//- вычитаются из первого числа первого объекта второе число второго объекта дробного типа -
	bool deduct(BigFloat& numOne, BigFloat& numTwo);
	
	//const char* divide(BigFloat& numOne, BigFloat& numTwo);

	//char* BigFloat::toString()
	//Функция перевода всего дробного числа в массив char
	//args:
	//- нет входных параметров -
	//return - массив символов char (число объекта)
	char* toString();

	//char* BigFloat::toStringInt()
	//Функция перевода целой части числа в массив char
	//args:
	//- нет входных параметров -
	//return - массив символов char 
	char* toStringInt();

	//char* BigFloat::toStringFloat()
	//Функция перевода дробной части числа в массив char
	//args:
	//- нет входных параметров -
	//return - массив символов char 
	char* toStringFloat();

private:

	//Длина дробной части числа
	int lengthFloat;

	//Дробная часть числа
	int* floatNumber;

	//char* BigFloat::toStringConcat()
	//Функция перевода целой и дробной части числа в массив char
	//args:
	//- нет входных параметров -
	//return - массив символов char 
	char* toStringConcat();

	//char* BigFloat::addNulls(BigFloat& obj, int length)
	//Функция добавления нулей (чтобы точка была под точкой)
	//args:
	//BigFloat& obj - объект класса (число)
	//length - длина, к которой нужно приести число
	//return - массив символов char 
	char* addNulls(BigFloat& obj, int length);
};