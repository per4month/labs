#pragma once
class BigInt
{
public:
	//---------------Конструкторы:----------------

	//BigInt::BigInt()
	//Конструктор по умолчанию (длина массива = 1, элемент массива = 0)
	//args:
	//- нет входных параметров -
	// - создаёт объект по умолчанию -
	BigInt();

	//BigInt::BigInt(long num)
	//Конструктор, принимающий тип long
	//args:
	//- long num - длинное целочисленное число
	// - создаёт объект по входному параметру long-
	BigInt(long num); 

	//BigInt::BigInt(const char* s)
	//Конструктор, принимающий тип const char* s
	//args:
	//- const char* s - строка символов 
	// - создаёт объект по входному параметру const char* s -
	BigInt(const char* s);

	//BigInt::BigInt(BigInt &other)
	//Конструктор, делающий копию другого объекта
	//args:
	//- BigInt &other - объект для копирования
	// - создаёт копию входного объекта -
	BigInt(const BigInt &other);

	//---------------Деструктор:----------------

	//BigInt::~BigInt()
	//Деструктор
	//args:
	//- нет входных параметров - 
	// - удаляет динамическую память объекта -
	~BigInt();

	//---------------Геттеры:-------------------

	//int BigInt::getLength()
	//Функция возврата длины числа в объекте
	//args:
	//- нет входных параметров - 
	//return - длина числа в объекте
	int getLength(); 

	//int BigInt::getLongNumberValue(int i)
	//Функция возврата элемента массива длинного числа в разряде i
	//args:
	//int i - порядковый номер разряда числа
	//return - элемент массива длинного числа в разряде i
	int getLongNumberValue(int i);

	//int BigInt::getNumber()
	//Функция возврата статической переменной кол-ва созданных объектов
	//args:
	//- нет входных параметров -
	//return - кол-во созданных объектов
	static int getNumber();

	//---------------Сеттеры:-------------------

	//void BigInt::setLength(int currentLength)
	//Функция устанавливает новую заданную длину currentLength
	//args:
	//int currentLength - текущая длина для замены
	//- устанавливает в объект новую заданную длину currentLength -
	void setLength(int currentLength); 

	//void BigInt::setLongNumberValue(int i, int value)
	//Функция устанавливает новое значение числа value в разряд i
	//args:
	//int i - порядковый номер разряда числа 
	//int value - новое устанавливаемое значение разряда
	//- устанавливает новое значение числа value в разряд i -
	void setLongNumberValue(int i, int value);
	
	//void BigInt::setArray()
	//Функция создаёт новый массив длинного числа размерности length
	//args:
	//- нет входных параметров -
	//- создаётся новый массив числа -
	void setArray();

	//------Функции для работы с объектами класса:------

	//void BigInt::add(BigInt& numOne, BigInt& numTwo)
	//Функция сложения
	//args:
	//BigInt& numOne - первый объект
	//BigInt& numTwo - второй объект
	//- складываются два числа двух объектов -
	void add(BigInt& numOne, BigInt& numTwo);

	//void BigInt::multiply(BigInt& numOne, BigInt& numTwo)
	//Функция умножения
	//args:
	//BigInt& numOne - первый объект
	//BigInt& numTwo - второй объект
	//- умнажаются два числа двух объектов -
	void multiply(BigInt& numOne, BigInt& numTwo);

	//void BigInt::deduct(BigInt& numOne, BigInt& numTwo)
	//Функция вычитания
	//args:
	//BigInt& numOne - первый объект
	//BigInt& numTwo - второй объект
	//- вычитаются из первого числа первого объекта второе число второго объекта -
	void deduct(BigInt& numOne, BigInt& numTwo);

	//const char* BigInt::divide(BigInt& numOne, BigInt& numTwo)
	//Функция деления
	//args:
	//BigInt& numOne - первый объект
	//BigInt& numTwo - второй объект
	//return - остаток числа
	const char* divide(BigInt& numOne, BigInt& numTwo);

	//const char* BigInt::convertTo(int base)
	//Функция перевода числа в другие системы счисления
	//args:
	//int base - число, в систему которой нужно перевести
	//return - переведённое число в base-системе счислления
	const char* convertTo(int base);

	//char* BigInt::toString()
	//Функция перевода числа из массива int в массив char
	//args:
	//- нет входных параметров -
	//return - массив символов char (число объекта)
	char* toString();

	//-----------------Перегрузка операторов--------------

	//BigInt operator+(BigInt& obj1, BigInt& obj2)
	//Перегрузка оператора сложения (реализовано через дружественную функцию)
	//args:
	//BigInt& obj1 и BigInt& obj2 - слагаемые
	//return - result - объект суммы
	friend BigInt operator+(BigInt& obj1, BigInt& obj2);

	//BigInt operator+(BigInt& obj1, BigInt& obj2)
	//Перегрузка оператора вычитания (реализовано через дружественную функцию)
	//args:
	//BigInt& obj1 - уменьшаемое и BigInt& obj2 - вычитаемое
	//return - result - объект разности
	friend BigInt operator-(BigInt& obj1, BigInt& obj2);

	//BigInt BigInt::operator*(int number)
	//Перегрузка оператора умножения на 10^n (int) (реализовано через метод класса)
	//args:
	//int number - число 10^n
	//return - result - объект произведения
	BigInt operator*(int number);
	
	//BigInt BigInt::operator*(long long number)
	//Перегрузка оператора умножения на 10^n (long long) (реализовано через метод класса)
	//args:
	//long long number - число 10^n
	//return - result - объект произведения
	BigInt operator*(long long number);

	//BigInt BigInt::operator*(unsigned long long number)
	//Перегрузка оператора умножения на 10^n (unsigned long long) (реализовано через метод класса)
	//args:
	//unsigned long long number - число 10^n
	//return - result - объект произведения
	BigInt operator*(unsigned long long number);

	//BigInt BigInt::operator/(int number)
	//Перегрузка оператора деления на 10^n (int) (реализовано через метод класса)
	//args:
	//int number - число 10^n
	//return - result - объект произведения
	BigInt operator/(int number);

	//BigInt BigInt::operator/(long long number)
	//Перегрузка оператора деления на 10^n (long long) (реализовано через метод класса)
	//args:
	//long long number - число 10^n
	//return - result - объект произведения
	BigInt operator/(long long number);

	//BigInt BigInt::operator/(unsigned long long number)
	//Перегрузка оператора деления на 10^n (unsigned long long) (реализовано через метод класса)
	//args:
	//unsigned long long number - число 10^n
	//return - result - объект произведения
	BigInt operator/(unsigned long long number);

	//BigInt& BigInt::operator= (const BigInt& obj)
	//Перегрузка оператора присваивания (только через метод класса)
	//args:
	//const BigInt& obj - присваиваемый объект
	//return - *this - объект присваивания
	BigInt& operator=(const BigInt& obj);

	//BigInt& BigInt::operator unsigned long()
	//Перегрузка функции приведения к типу unsigned long
	//args:
	//- нет входных параметров -
	//return - число типа unsigned long
	operator unsigned long();

	

private:
	//------------Переменные:-------------

	//Длина числа
	int length; 

	//Число
	int *longNumber;

	//Кол-во объектов
	static int counter;

	//--------Доп.функции для работы с public методами-------------------

	//void BigInt::addNull(int maxLength, int tempArray[], BigInt& object)
	//Функция добавления значащих нулей перед числом (исп. в сложении)
	//args:
	//int maxLength - наибольшая длина среди двух объектов
	//int tempArray[] - массив меньшего из двух чисел, в котором нужны нули
	//BigInt& object - объект с меньшей длиной
	//-добавляет значащие нули перед наименьшим числом-
	void addNull(int maxLength, int tempArray[], BigInt& object);

	//void BigInt::sum(int maxLength, int resultArray[], int tempArray[], int &carry, BigInt& object)
	//Функция суммирования (исп. в сложении)
	//args:
	//int maxLength - наибольшая длина среди двух объектов
	//int resultArray[] - массив результата сложения
	//int tempArray[] - массив меньшего из двух чисел, со значащими нулями,
	//int& carry - доп. десяток
	//BigInt& object - объект с большей длиной числа
	//- суммирует два числа -
	void sum(int maxLength, int resultArray[], int tempArray[], int& carry, BigInt& object);

	//int* BigInt::addMemory(int &maxLength, int tempArray[], int resultArray[], int &carry)
	//Функция добавления одной ячейки массива (увеличения памяти) (исп. в сложении)
	//args:
	//int maxLength - наибольшая длина среди двух объектов
	//int resultArray[] - массив результата сложения
	//int tempArray[] - массив меньшего из двух чисел, со значащими нулями,
	//int& carry - доп. десяток
	//return - resultArray[] - массив с доп элементом
	int* addMemory(int& maxLength, int tempArray[], int resultArray[], int& carry);

	//int* BigInt::reverseArray(BigInt& object)
	//Функция переворачивания массива числа (исп. в вычитании, умножении, делении)
	//args:
	//BigInt& object - необходимый объект, число которого нужно перевернуть
	//return - перевернутый массив числа объекта
	int* reverseArray(BigInt& object);

	//int* BigInt::makeArrayForSub(BigInt& object, int currentLength)
	//Функция переворачивает массив и добавляет значащие нули в конце (исп.в вычитании)
	//args:
	//BigInt& object - необходимый объект, число которого нужно перевернуть и добавить знач. нули
	//int currentLength - наибольшая длина из двух чисел
	//return - перевернутый массив числа объекта со значащими нулями
	int* makeArrayForSub(BigInt& object, int currentLength);

	//int BigInt::digitToInt(char num)
	//Функция принимает символ и возвращает его значение в int (исп. в переводе СС)
	//args:
	//char num - символ, который нужно перевести в int
	//return - значение символа в int
	int digitToInt(char num);

	//int BigInt::digitToChar(int num)
	//Функция принимает значение в int и переводит его в соответсвующий символ (исп. в переводе СС)
	//args:
	//int num - значение int, которое нужно перевести в символ
	//return - символ значения int
	char digitToChar(int num);

	//int BigInt::helpConvert(char* a, int base, char* c)
	//Конвертация из 10-CC в base-СС
	//args:
	//char* a - входной массив символов
	//int base - СС для перевода в неё
	//char* c - конвертированный массив символов
	//return - кол-во символов в выходном массиве
	int helpConvert(char* a, int base, char* c);

	//int BigInt::compare(BigInt& numOne, BigInt& numTwo, int& currentLength)
	//Функция сравнения чисел двух объектов
	//args:
	//int& currentLength - максимальная длина из двух чисел
	//return - значение сравнения
	int compare(BigInt& numOne, BigInt& numTwo, int& currentLength);

	//int* BigInt::sub(BigInt& obj1, BigInt& obj2, int currentLength)
	//Функция вычитания числа объекта 2 из числа объекта 1 (исп. в вычитании)
	//args:
	//BigInt& obj1 - уменьшаемое
	//BigInt& obj2 - вычитаемое
	//int currentLength - длина вычитаемого
	//return - массив разности двух чисел
	int* sub(BigInt& obj1, BigInt& obj2, int currentLength);

	//int* BigInt::mult(int tempA[], int tempB[], int lenA, int lenB, int &maxLength )
	//Функция умножения двух чисел в массивах (исп. в умножении, делении)
	//args:
	//int tempA[] - множитель 1
	//int tempB[] - множитель 2
	//int lenA - длина числа множителя 1
	//int lenB - длина числа множителя 2
	//int &maxLength - длина результирующего массива
	//return - массив произведения
	int* mult(int tempA[], int tempB[], int lenA, int lenB, int& maxLength);

	//void BigInt::reverseArrayForDiv(int tempArray[], int len)
	//Функция переворачивает массив задом наперед (исп. в делении)
	//args:
	//int tempArray[] - массив, который нужно перевернуть
	//int len - длина исходного массива
	//- переворачивает исходный массив - 
	void reverseArrayForDiv(int tempArray[], int len);

	//bool BigInt::cmp(int arrayOne[], int arrayTwo[], int lengthOne, int lengthTwo)
	//Функция сравнивает числа в массивах
	//args:
	//int arrayOne[] - первое число
	//int arrayTwo[] - второе число
	//int lengthOne - длина первого числа
	//int lengthTwo - длина второго числа
	//return - значение сравнения
	bool cmp(int arrayOne[], int arrayTwo[], int lengthOne, int lengthTwo);
	
	//void BigInt::subForDiv(int tempArrayOne[], int tempArrayTwo[], int currentLength)
	//Функция вычитания чисел в массивах (исп. в делении)
	//args:
	//int tempArrayOne[] - уменьшаемое
	//int tempArrayTwo[] - вычитаемое
	//int currentLength - длина вычитаемого
	//- разность сохраняется в tempArrayOne[] -
	void subForDiv(int tempArrayOne[], int tempArrayTwo[], int currentLength);

	//void BigInt::searchLenght(int &lenght, int tempArray[])
	//Функция поиска длины массива числа без значащих нулей (исп. в делении)
	//args:
	//int tempArray[] - исходный массив со значащими нулями
	//int &lenght - изменяемая длина
	//- ищется длина -
	void searchLenght(int& lenght, int tempArray[]);

	//void BigInt::putValue (BigInt& object, int currentLength, int tempArray[])
	//Функция помещения значения массива числа в объект (исп. в делении)
	//args:
	//BigInt& object - необходимый объект
	//int currentLength - длина массива числа
	//int tempArray[] - массив числа
	//- в объект записывается массив числа -
	void putValue(BigInt& object, int currentLength, int tempArray[]);

};