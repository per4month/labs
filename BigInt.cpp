#include "BigInt.h"
#include <iostream>
#include <cmath>

int BigInt::counter = 0;

void BigInt::addNull(int maxLength, int tempArray[], BigInt& object) {
	for (int i = 0, j = 0; i < maxLength; i++) {
		if (maxLength - i > object.getLength()) {
			tempArray[i] = 0;
			continue;
		}
		tempArray[i] = object.getLongNumberValue(j++);
	}
}

void BigInt::sum(int maxLength, int resultArray[], int tempArray[], int &carry, BigInt& object ) {
	for (int i = maxLength - 1; i >= 0; i--) {
		resultArray[i] = carry + tempArray[i] + object.getLongNumberValue(i);
		carry = resultArray[i] / 10;
		resultArray[i] = resultArray[i] % 10;
	}
}

int* BigInt::addMemory(int &maxLength, int tempArray[], int resultArray[], int &carry) {
	for (int i = 0; i < maxLength; i++) {
		tempArray[i] = resultArray[i];
	}
	delete[]resultArray;
	maxLength++;

	//выделение памяти с учётом +1 разряда
	resultArray = new int[maxLength];
	resultArray[0] = carry;

	for (int i = 1; i < maxLength; i++) {
		resultArray[i] = tempArray[i - 1];
	}

	return resultArray;
}

int* BigInt::reverseArray(BigInt& object) {
	int tempLength = object.getLength();
	int* tempArray = new int[tempLength];
	for (int i = 0, j = tempLength - 1; i < tempLength; i++) {
		tempArray[i] = object.getLongNumberValue(j);
		j--;
	}

	return tempArray;
}

int* BigInt::makeArrayForSub(BigInt& object, int currentLength) { //функция добавляет нули и переворачивает массив меньшего элемента
	//int tempLength = object.getLength();
	int* tempArray = new int[currentLength];
	for (int i = 0, j = object.getLength()-1; i < currentLength ; i++) {
		if (j < 0) {
			tempArray[i] = 0;
		}
		else {
			tempArray[i] = object.getLongNumberValue(j--);
		}
	}
	return tempArray;
}

int BigInt::digitToInt(char num)
{
	switch (num)
	{
	case '0': return 0;
	case '1': return 1;
	case '2': return 2;
	case '3': return 3;
	case '4': return 4;
	case '5': return 5;
	case '6': return 6;
	case '7': return 7;
	case '8': return 8;
	case '9': return 9;
	}
}

char BigInt::digitToChar(int num)
{
	switch (num)
	{
	case 0: return '0';
	case 1: return '1';
	case 2: return '2';
	case 3: return '3';
	case 4: return '4';
	case 5: return '5';
	case 6: return '6';
	case 7: return '7';
	case 8: return '8';
	case 9: return '9';
	case 10: return 'A';
	case 11: return 'B';
	case 12: return 'C';
	case 13: return 'D';
	case 14: return 'E';
	case 15: return 'F';
	}
}

int BigInt::helpConvert(char* a, int base, char* c)
{
	int rest = 0; // остаток от деления
	char* s; // символьное десятичное представление частного a/p
	int lena = strlen(a);
	s = new char[lena];
	int flag = 0; // проверка на нулевой результат в частном
	for (int i = 0; i < lena; i++)
	{
		int dig = a[i] > 0 ? digitToInt(a[i]) : 0;
		int num = rest * 10 + dig; // делимое на текущем шаге
		s[i] = digitToChar(num / base); // следующий разряд частного
		rest = num % base; // остаток от деления
		if (s[i] != '0') flag = 1; // в случае ненулевого результата установить флаг
	}
	if (flag == 0)  // частное равно 0, базовый случай рекурсии
	{
		c[0] = digitToChar(rest); return 1; // запись старшего разряда результата
	}
	s[lena] = '\0'; // заканчиваем полученную строку результата
	int sub = helpConvert(s, base, c); // рекурсивный вызов для следующего разряда
	c[sub++] = digitToChar(rest); // заполнение текущего разряда результата
	return sub;
}

int BigInt::compare(BigInt& numOne, BigInt& numTwo, int& currentLength)
{
	//Функция сравнения
	//Если 1ое > 2ого, то возвращает 1
	//Если 1ое < 2ого, то возвращает 2
	//Если 1ое == 2ое, то возвращает 3
	if (numOne.getLength() > numTwo.getLength())
	{
		currentLength = numOne.getLength();
		return 1; 
	}
	else if (numTwo.getLength() > numOne.getLength())
	{
		currentLength = numTwo.getLength();
		return 2; 
	}
	else // если числа одинаковой длины, то необходимо сравнить их значения
		for (int i = 0; i < currentLength; i++) // поразрядное сравнение значения чисел
		{
			if (numOne.getLongNumberValue(i) > numTwo.getLongNumberValue(i)) 
			{
				return 1; 
				break; 
			}

			if (numOne.getLongNumberValue(i) < numTwo.getLongNumberValue(i)) 
			{
				return 2; 
				break; 
			}
		} 
	return 3;
}

int* BigInt::sub(BigInt& obj1, BigInt& obj2, int currentLength) //obj1 > obj2
{
	int* tempArrayOne = reverseArray(obj1); //переворачиваем массив первого числа (большего)
	int* tempArrayTwo = makeArrayForSub(obj2, currentLength); //меньшее число также переворачиваем и добавляем значащие нули
	for (int i = 0; i < obj2.getLength(); i++) {
		if (tempArrayOne[i] >= tempArrayTwo[i]) {  //если значение 1ого > 2ого
			tempArrayOne[i] -= tempArrayTwo[i];
		}
		else { //иначе 1ого < 2ого
			if (tempArrayOne[i + 1] != 0) { //если следующее число !=0
				tempArrayOne[i] = tempArrayOne[i] + 10 - tempArrayTwo[i]; //отдаём десяток
				tempArrayOne[i + 1]--; //занимаем у следующего числа
			}
			else { //если следующее число == 0
				tempArrayOne[i] = tempArrayOne[i] + 10 - tempArrayTwo[i]; //отдаём десяток
				i++; //сдвигаемся к следующей цифре
				while (tempArrayOne[i] == 0) { //пока встречаются нули

					tempArrayOne[i] = tempArrayOne[i] + 9 - tempArrayTwo[i];
					i++;
				}
				tempArrayOne[i]--; //занимаем десяток у первого попавшегося !=0
				i--; //на шаг назад
			}
		}
	}
	return tempArrayOne;
}

int* BigInt::mult(int tempA[], int tempB[], int lenA, int lenB, int &maxLength ) { //используется в умножении и делении
	
	maxLength = lenA + lenB + 1;
	int* resultArray = new int[maxLength];
	int carry = 0;

	for (int i = 0; i < maxLength; i++) {
		resultArray[i] = 0;
	}

	for (int i = 0; i < lenA; i++) {
		for (int j = 0; j < lenB; j++) {
			resultArray[i + j] += tempA[i] * tempB[j]; //оформить по кодстайлу
		}
	}

	for (int i = 0; i < maxLength; i++) {
		resultArray[i] = carry + resultArray[i];
		carry = resultArray[i] / 10;
		resultArray[i] = resultArray[i] % 10;
	}

	while ((resultArray[maxLength - 1] == 0) && (maxLength != 1)) { //второе условие нужно, чтобы если произ = 0, то 0 не терялся
		maxLength--;
	}

	return resultArray;
}

void BigInt::reverseArrayForDiv(int tempArray[], int len) {
	for (int i = 0, j = len - 1; i < j; i++, j--)
	{
		int k = tempArray[i]; 
		tempArray[i] = tempArray[j];
		tempArray[j] = k;
	}
}

bool BigInt::cmp(int arrayOne[], int arrayTwo[], int lengthOne, int lengthTwo) { //на вход перевёрнутые числа
	if (lengthOne > lengthTwo)
	{
		return false;
	}
	else if (lengthTwo > lengthOne)
	{
		return true;
	}
	else // если числа одинаковой длины, то необходимо сравнить их значения
		for (int i = lengthOne - 1; i >=0; i--) // поразрядное сравнение значения чисел
		{
			if (arrayOne[i] > arrayTwo[i])
			{
				return false;
				break;
			}

			if (arrayOne[i] < arrayTwo[i])
			{
				return true;
				break;
			}
		}
}

void BigInt::subForDiv(int tempArrayOne[], int tempArrayTwo[], int currentLength) //obj1 > obj2 кюрЛен - длина меньшего числа
{
	for (int i = 0; i < currentLength; i++) {
		if (tempArrayOne[i] >= tempArrayTwo[i]) {  //если значение 1ого > 2ого
			tempArrayOne[i] -= tempArrayTwo[i];
		}
		else { //иначе 1ого < 2ого
			if (tempArrayOne[i + 1] != 0) { //если следующее число !=0
				tempArrayOne[i] = tempArrayOne[i] + 10 - tempArrayTwo[i]; //отдаём десяток
				tempArrayOne[i + 1]--; //занимаем у следующего числа
			}
			else { //если следующее число == 0
				tempArrayOne[i] = tempArrayOne[i] + 10 - tempArrayTwo[i]; //отдаём десяток
				i++; //сдвигаемся к следующей цифре
				while (tempArrayOne[i] == 0) { //пока встречаются нули

					tempArrayOne[i] = tempArrayOne[i] + 9 - tempArrayTwo[i];
					i++;
				}
				tempArrayOne[i]--; //занимаем десяток у первого попавшегося !=0
				i--; //на шаг назад
			}
		}
	}
}

void BigInt::searchLenght(int &lenght, int tempArray[]) {
	for (int i = lenght - 1, key = 1; i >= 0; i--) {
		if (tempArray[i] == 0 && key) {
			lenght--;
			continue;
		}
		else {
			key = 0;
		}
	}
}

void BigInt::putValue (BigInt& object, int currentLength, int tempArray[]) {
	for (int i = currentLength - 1, key = 1, j = 0; i >= 0; i--) {
		if (tempArray[i] == 0 && key) {
			continue;
		}
		else {
			key = 0;
		}
		object.setLongNumberValue(j++, tempArray[i]);
	}
}

BigInt::BigInt()
{
	counter++;
	length = 1;
	longNumber = new int[length];
	longNumber[0] = 0;
}

BigInt::BigInt(long num)
{
	counter++;
	long buffer = num;
	length = 1;
	while ((buffer /= 10) > 0)
	{
		length++;
	}
	longNumber = new int[length];
	for (int i = length-1; i >= 0; i--)
	{
		longNumber[i] = num % 10;
		num /= 10;
	}
}

BigInt::BigInt(const char *str) 
{
	counter++;
	length = 0;
	int count = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		length++;
		if (str[i] >= '0' && str[i] <= '9') {
			count++;
		}
	}
	if (length == count) {
		longNumber = new int[length];
		for (int i = 0; str[i] != '\0'; i++)
			longNumber[i] = str[i] - '0';
	}
	else {
		length = 1;
		longNumber = new int[length];
		longNumber[0] = 0;
	}
}

BigInt::BigInt(const BigInt& other)
{
	counter++;
	length = other.length;
	longNumber = new int [length];
	for (int i = 0; i < length; i++)
	{
		longNumber[i] = other.longNumber[i];
	}
}

BigInt::~BigInt() {
	counter--;
	delete[] longNumber;
}

int BigInt::getLength()
{
	return length;
}

int BigInt::getLongNumberValue(int i)
{
	return longNumber[i];
}

int BigInt::getNumber() {
	return counter;
}

void BigInt::setLength(int currentLength)
{
	length = currentLength;
}

void BigInt::setLongNumberValue(int i, int value)
{
	longNumber[i] = value;
}

void BigInt::setArray() {
	delete[] longNumber;
	longNumber = NULL;
	longNumber = new int[length];
}

char* BigInt::toString()
{
	char *str = new char [length+1];     
	for (int i = 0; i < length; i++)
	{
		str[i] = longNumber[i] + '0';
	}
	str[length] = '\0';
	return str;
}
	
void BigInt::add(BigInt& numOne, BigInt& numTwo) {
	int maxLength = 0;
	int carry = 0;
	int* tempArray = nullptr;
	int* resultArray = nullptr;

	//Если длина первого числа больше, чем второго числа
	if (numOne.getLength() > numTwo.getLength()) {
		maxLength = numOne.getLength();
		tempArray = new int[maxLength];
		resultArray = new int[maxLength];

		//Добавляем значащие нули для суммирования
		addNull(maxLength, tempArray, numTwo);

		//Суммирование
		sum(maxLength, resultArray, tempArray, carry, numOne);

		//Если был сохранен разряд, то очищаем массив и создаем заново
		if (carry) {

			//Добавление памяти под один дополнительный разряд
			resultArray = addMemory(maxLength, tempArray, resultArray, carry);

		}
	}
	//Если длины одинаковы
	else if (numOne.getLength() == numTwo.getLength()) {
		maxLength = numOne.getLength();
		tempArray = new int[maxLength];
		resultArray = new int[maxLength];

		for (int i = maxLength-1; i >= 0; i--) {
			tempArray[i] = numTwo.getLongNumberValue(i);
		}

		sum(maxLength, resultArray, tempArray, carry, numOne);
		if (carry) {

			//Добавление памяти под один дополнительный разряд
			resultArray = addMemory(maxLength, tempArray, resultArray, carry);
		}
	}
	//Если длина второго числа больше, чем первого числа
	else {
		maxLength = numTwo.getLength();
		tempArray = new int[maxLength];
		resultArray = new int[maxLength];

		//Добавляем значащие нули для суммирования
		addNull(maxLength, tempArray, numOne);

		//Суммирование
		sum(maxLength, resultArray, tempArray, carry, numTwo);

		//Если был сохранен разряд, то очищаем массив и создаем заново
		if (carry) {

			//Добавление памяти под один дополнительный разряд
			resultArray = addMemory(maxLength, tempArray, resultArray, carry);

		}
	}
	
	
	this->setLength(maxLength);

	this->setArray();

	for (int i = 0; i < maxLength; i++) {
		this->setLongNumberValue(i,resultArray[i]);
	}

	delete[] resultArray;
	delete[] tempArray;
}

void BigInt::multiply(BigInt& numOne, BigInt& numTwo) {
	int* tempArrayOne = reverseArray(numOne);
	int* tempArrayTwo = reverseArray(numTwo);
	int maxLength = 0;
	
	int* resultArray = mult(tempArrayOne, tempArrayTwo, 
		numOne.getLength(), numTwo.getLength(), maxLength);

	numOne.setLength(maxLength);

	numOne.setArray();

	for (int i = 0, j = maxLength -1; i < maxLength; i++, j--) {
		numOne.setLongNumberValue(i, resultArray[j]);
	}

	delete[] resultArray;
	delete[] tempArrayOne;
	delete[] tempArrayTwo;
}

void BigInt::deduct(BigInt& numOne, BigInt& numTwo) {
	
	int currentLength = numOne.getLength(); //текущая длина (максимальная)
	int* resultArray = NULL; //результирующий массив
		
	int subtract = compare(numOne, numTwo, currentLength); //сравнение

	if (subtract == 1) {
		resultArray = sub(numOne, numTwo, currentLength);
	}
	if (subtract == 2) {
		resultArray = sub(numTwo, numOne, currentLength); 
	}
	if (subtract == 3) {
		currentLength = 1;
		resultArray = new int[1];
		resultArray[0] = 0;
	}
	int  len = currentLength;

	for (int i = currentLength - 1, key = 1; i >= 0; i--) {
		if (resultArray[i] == 0 && key && subtract!=3) {
			len--;
			continue;
		}
		else {
			key = 0;
		}
	}

	this->setLength(len);
	this->setArray();

	for (int i = currentLength - 1, key = 1, j = 0; i >= 0; i--) {
		if (resultArray[i] == 0 && key && subtract!=3) {
			continue;
		}
		else {
			key = 0;
		}
		setLongNumberValue(j++, resultArray[i]);
	}
	
	delete[] resultArray;
}
	
const char* BigInt::divide(BigInt& numOne, BigInt& numTwo) {
	if (numTwo.getLongNumberValue(0) == 0)
		return "Error";
	
	int divLength = numOne.getLength(); //текущая длина (максимальная)
	int* resultArray = NULL; //результирующий массив
	int *rest; //остаток
	int division = compare(numOne, numTwo, divLength); //сравнение

	if (division == 1) { //получится неполное частное и остаток
		int maxLength = 0;
		bool zero = false;
		int* dividend = reverseArray(numOne); //делимое
		int* divider = reverseArray(numTwo); //делитель
		int* cmpArray = new int[divLength]; //частное
		int* resultArray = new int[divLength]; //для перебора цифр
		
		//Запоминание предыдущих
		int* resultArrayPrev = new int[divLength];
		int* cmpArrayPrev = new int[divLength];
		int* dividendPrev = new int[divLength];

		for (int i = 0; i < divLength; i++) {
			resultArray[i] = 0;
		}
		int k = 0;
		int carry = 0;
		while (k != -1) { //перебор частного
			k = divLength - 1;
			while (resultArray[k] < 10) {
				reverseArrayForDiv(resultArray, divLength); //переворачиваем для умножения
				cmpArray = mult(divider, resultArray, numTwo.getLength(), divLength, maxLength); //умножаем неполное частное на делитель
				if (cmp(dividend, cmpArray, divLength, maxLength)) { //сравниваем данные числа
					k = -1; //для выхода из вешнего цикла
					subForDiv(dividend, cmpArray, divLength); //в dividend записывается остаток числа
					int count = 0;
					for (int i = 0; i < divLength; i++)
						if (dividend[i] == 0)   //если остаток == 0, то применяем частный случай
							count++;
					if (count == divLength)
						zero = true;

					break;
				}
				
				//копирование предыдущих показаний
				for (int i = 0; i < divLength; i++)
					resultArrayPrev[i] = resultArray[i];
				for (int i = 0; i < maxLength; i++)
					cmpArrayPrev[i] = cmpArray[i];
				for (int i = 0; i < divLength; i++)
					dividendPrev[i] = dividend[i];

				reverseArrayForDiv(resultArray, divLength); //возвращаем обратно в правильном порядке
				resultArray[k]++;
			}
			while (resultArray[k] == 10) { 
				carry = resultArray[k] / 10;
				resultArray[k] %= 10;
				k--;
				if (k == -1) {
					for (int j = 0; j < divLength; j++) {
						resultArray[j] = 9;
					}
					break;
				}
				resultArray[k] += carry;
			}
		}
		if (!zero) {
			subForDiv(dividendPrev, cmpArrayPrev, maxLength);
			maxLength = divLength;
			searchLenght(maxLength, resultArrayPrev);
			numOne.setLength(maxLength);
			numOne.setArray();
			putValue(numOne, maxLength, resultArrayPrev);
			maxLength = divLength;
			searchLenght(maxLength, dividendPrev);
			char* str = new char[maxLength + 1];
			for (int i = divLength - 1, key = 1, j = 0; i >= 0; i--) {
				if (dividendPrev[i] == 0 && key) {
					continue;
				}
				else {
					key = 0;
				}
				str[j++] = dividendPrev[i] + '0';
			}
			str[maxLength] = '\0';
			return str;
		}
		else {
			maxLength = divLength;
			searchLenght(maxLength, resultArray);
			numOne.setLength(maxLength);
			numOne.setArray();
			putValue(numOne, maxLength, resultArray);
			maxLength = divLength;
			char* str = new char[2];
			str[0] = '0';
			str[1] = '\0';
			return str;
		}
	}

	if (division == 2) { //получится 0
		divLength = 1;
		resultArray = new int[1];
		resultArray[0] = 0;
		numOne.setLength(divLength);
		numOne.setArray();
		numOne.setLongNumberValue(0, resultArray[0]);
		return "0";
	}

	if (division == 3) { //получится 1
		divLength = 1;
		resultArray = new int[1];
		resultArray[0] = 1;
		numOne.setLength(divLength);
		numOne.setArray();
		numOne.setLongNumberValue(0, resultArray[0]);
		return "0";
	}
}

const char* BigInt::convertTo(int base)
{
	
	if (!(2 <= base && base <= 16))
		return "Error";

	char* inStr = this->toString();
	char* outStr = new char[pow(2,this->getLength())];

	int sub = helpConvert(inStr, base, outStr);
	outStr[sub] = '\0';

	delete[] inStr;

	return outStr;

}

BigInt operator+(BigInt& obj1, BigInt& obj2) { 
	BigInt result;
	result.add(obj1, obj2);
	return result;
}

BigInt operator-(BigInt& obj1, BigInt& obj2) {
	BigInt result;
	result.deduct(obj1, obj2);
	return result;
}

BigInt BigInt::operator*(int number) {
	BigInt result;
	int count = 0;
	if (number == 0) {
		return result;
	}
	while (number != 1) { //подсчитываем кол-во добавленных нулей
		number /= 10;
		count++;
	}
	int tempLength = this->length;
	int* tempArray = new int[tempLength];
	for (int i = 0; i < this->length; i++) {
		tempArray[i] = this->longNumber[i];
	}
	result.setLength(tempLength + count);
	result.setArray();
	for (int i = 0; i < result.length; i++) {
		if (i < tempLength) {
			result.longNumber[i] = tempArray[i];
		}
		else {
			result.longNumber[i] = 0;
		}
	}
	delete[] tempArray;
	return result;
}

BigInt BigInt::operator*(long long number) {
	BigInt result;
	int count = 0;
	if (number == 0) {
		return result;
	}
	while (number != 1) { //подсчитываем кол-во добавленных нулей
		number /= 10;
		count++;
	}
	int tempLength = this->length;
	int* tempArray = new int[tempLength];
	for (int i = 0; i < this->length; i++) {
		tempArray[i] = this->longNumber[i];
	}
	result.setLength(tempLength + count);
	result.setArray();
	for (int i = 0; i < result.length; i++) {
		if (i < tempLength) {
			result.longNumber[i] = tempArray[i];
		}
		else {
			result.longNumber[i] = 0;
		}
	}
	delete[] tempArray;
	return result;
}

BigInt BigInt::operator*(unsigned long long number) {
	BigInt result;
	int count = 0;
	if (number == 0) {
		return result;
	}
	while (number != 1) { //подсчитываем кол-во добавленных нулей
		number /= 10;
		count++;
	}
	int tempLength = this->length;
	int* tempArray = new int[tempLength];
	for (int i = 0; i < this->length; i++) {
		tempArray[i] = this->longNumber[i];
	}
	result.setLength(tempLength + count);
	result.setArray();
	for (int i = 0; i < result.length; i++) {
		if (i < tempLength) {
			result.longNumber[i] = tempArray[i];
		}
		else {
			result.longNumber[i] = 0;
		}
	}
	delete[] tempArray;
	return result;
}

BigInt BigInt::operator/(int number) {
	BigInt result;
	int count = 0;
	if (number == 0) {
		std::cerr << "Error! Division by zero is not possible." << std::endl;
		result.longNumber[0] = 21;
		return result;
	}
	while (number != 1) { //подсчитываем кол-во убираемых разрядов
		number /= 10;
		count++;
	}
	if (count >= this->length) {
		return result;
	}
	int tempLength = this->length;
	int* tempArray = new int[tempLength];
	for (int i = 0; i < this->length; i++) {
		tempArray[i] = this->longNumber[i];
	}
	result.setLength(tempLength - count);
	result.setArray();
	for (int i = 0; i < result.length; i++) {
		result.longNumber[i] = tempArray[i];
	}
	delete[] tempArray;
	return result;
}

BigInt BigInt::operator/(long long number) {
	BigInt result;
	int count = 0;
	if (number == 0) {
		std::cerr << "Error! Division by zero is not possible." << std::endl;
		result.longNumber[0] = 21;
		return result;
	}
	while (number != 1) { //подсчитываем кол-во убираемых разрядов
		number /= 10;
		count++;
	}
	if (count >= this->length) {
		return result;
	}
	int tempLength = this->length;
	int* tempArray = new int[tempLength];
	for (int i = 0; i < this->length; i++) {
		tempArray[i] = this->longNumber[i];
	}
	result.setLength(tempLength - count);
	result.setArray();
	for (int i = 0; i < result.length; i++) {
		result.longNumber[i] = tempArray[i];
	}
	delete[] tempArray;
	return result;
}

BigInt BigInt::operator/(unsigned long long number) {
	BigInt result;
	int count = 0;
	if (number == 0) {
		std::cerr << "Error! Division by zero is not possible." << std::endl;
		result.longNumber[0] = 21;
		return result;
	}
	while (number != 1) { //подсчитываем кол-во убираемых разрядов
		number /= 10;
		count++;
	}
	if (count >= this->length) {
		return result;
	}
	int tempLength = this->length;
	int* tempArray = new int[tempLength];
	for (int i = 0; i < this->length; i++) {
		tempArray[i] = this->longNumber[i];
	}
	result.setLength(tempLength - count);
	result.setArray();
	for (int i = 0; i < result.length; i++) {
		result.longNumber[i] = tempArray[i];
	}
	delete[] tempArray;
	return result;
}

BigInt& BigInt::operator= (const BigInt& obj) {
	int count = 0;
	if (this->length == obj.length) {
		for (int i = 0; i < obj.length; i++) {
			if (this->longNumber[i] != obj.longNumber[i])
				break;
			else
				count++;
		}
	}	
	if (count == obj.length) {
		return *this;
	}
	else {
		this->length = obj.length;
		delete[] this->longNumber;
		this->longNumber = new int[this->length];
		for (int i = 0; i < length; i++)
		{
			this->longNumber[i] = obj.longNumber[i];
		}
		return *this;
	}
	
}

BigInt::operator unsigned long() {
	int currentLength = this->length;
	unsigned long number = 0;
	for (int i = 0; i < currentLength; i++) {
		if ((ULONG_MAX - this->longNumber[i])/10 < number) {
			std::cerr << "Overload unsigned int!" << std::endl; 
			return 0;
		}
		number = number * 10 + this->longNumber[i];
	}
	return number;
}
