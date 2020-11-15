#pragma once
class Test
{
public:
	//Конструктор класса Test по умолчанию
	Test();

	//---------Проверка класса-наследника BigFloat--------

	//bool Test :: test_constructror_bigfloat_default()
	//Тест конструктора класса BigFloat по умолчанию
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_constructror_bigfloat_default();

	//bool Test :: test_constructror_bigfloat_long()
	//Тест конструктора класса BigFloat, принимающего тип long
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_constructror_bigfloat_long();

	//bool Test :: test_constructror_bigfloat_char()
	//Тест конструктора класса BigFloat, принимающего тип char
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_constructror_bigfloat_char();

	//bool Test :: test_constructror_bigfloat_copy()
	//Тест конструктора копирования класса BigFloat
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_constructror_bigfloat_copy();

	//bool Test :: test_bigfloat_add_null()
	//Тест сложения объекта с объектом, содержащим ноль
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_bigfloat_add_null();

	//bool Test :: test_bigfloat_add_number1()
	//Тест сложения объекта с объектом (объекты >= 1.0)
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_bigfloat_add_number1();

	//bool Test :: test_bigfloat_add_number2()
	//Тест сложения объекта с объектом (0.0 < объекты < 1.0)
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_bigfloat_add_number2();

	//bool Test :: test_bigfloat_deduct_number_equal()
	//Тест вычитания двух идентичных объектов
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_bigfloat_deduct_number_equal();

	//bool Test :: test_bigfloat_deduct_number1()
	//Тест вычитания двух объектов (объекты >= 1.0)
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_bigfloat_deduct_number1();

	//bool Test :: test_bigfloat_deduct_number2()
	//Тест вычитания двух объектов (0.0 < объекты < 1.0)
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_bigfloat_deduct_number2();

	//bool Test :: test_bigfloat_mult_null()
	//Тест умножения двух объектов (один из объектов равен нулю)
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_bigfloat_mult_null();

	//bool Test :: test_bigfloat_mult_number1()
	//Тест умножения двух объектов (объекты >= 1.0)
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_bigfloat_mult_number1();

	//bool Test :: test_bigfloat_mult_number2()
	//Тест умножения двух объектов (0.0 < объекты < 1.0)
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_bigfloat_mult_number2();

	//-----------Проверка класса-наследника SignedBigFloat------------

	//bool Test :: test_constructror_signedbigfloat_default()
	//Тест конструктора класса SignedBigFloat по умолчанию
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_constructror_signedbigfloat_default();

	//bool Test :: test_constructror_signedbigfloat_positive_long()
	//Тест конструктора класса SignedBigFloat, принимающего тип long (положительное число)
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_constructror_signedbigfloat_positive_long();

	//bool Test :: test_constructror_signedbigfloat_negative_long()
	//Тест конструктора класса SignedBigFloat, принимающего тип long (отрицательное число число)
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_constructror_signedbigfloat_negative_long();

	//bool Test :: test_constructror_signedbigfloat_positive_char()
	//Тест конструктора класса SignedBigFloat, принимающего тип char (положительное число)
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_constructror_signedbigfloat_positive_char();

	//bool Test :: test_constructror_signedbigfloat_negative_char()
	//Тест конструктора класса SignedBigFloat, принимающего тип char (отрицательное число число)
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_constructror_signedbigfloat_negative_char();

	//bool Test :: test_constructror_signedbigfloat_copy()
	//Тест конструктора копирования класса SignedBigFloat
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_constructror_signedbigfloat_copy();
	
	//bool Test :: test_signedbigfloat_pos_add_pos()
	//Тест сложения двух положительных чисел
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_signedbigfloat_pos_add_pos();

	//bool Test :: test_signedbigfloat_neg_add_pos1()
	//Тест сложения отрицательного(obj1) и положительного чисел(obj2)
	//при этом: |obj1| > |obj2|
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_signedbigfloat_neg_add_pos1();

	//bool Test :: test_signedbigfloat_neg_add_pos2()
	//Тест сложения отрицательного(obj1) и положительного чисел(obj2)
	//при этом: |obj1| < |obj2|
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_signedbigfloat_neg_add_pos2();

	//bool Test :: test_signedbigfloat_pos_add_neg1()
	//Тест сложения положительного(obj1) и отрицательного чисел(obj2)
	//при этом: |obj1| > |obj2|
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_signedbigfloat_pos_add_neg1();

	//bool Test :: test_signedbigfloat_pos_add_neg2()
	//Тест сложения положительного(obj1) и отрицательного чисел(obj2)
	//при этом: |obj1| < |obj2|
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_signedbigfloat_pos_add_neg2();

	//test_signedbigfloat_neg_add_neg()
	//Тест сложения двух отрицательных чисел
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_signedbigfloat_neg_add_neg();
	
	//bool Test :: test_signedbigfloat_pos_ded_pos1()
	//Тест разности положительного(obj1) и положительного чисел(obj2)
	//при этом: |obj1| > |obj2|
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_signedbigfloat_pos_ded_pos1();

	//bool Test :: test_signedbigfloat_pos_ded_pos2()
	//Тест разности положительного(obj1) и положительного чисел(obj2)
	//при этом: |obj1| < |obj2|
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_signedbigfloat_pos_ded_pos2();

	//bool Test :: test_signedbigfloat_neg_ded_pos1()
	//Тест разности отрицательного(obj1) и положительного чисел(obj2)
	//при этом: |obj1| > |obj2|
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_signedbigfloat_neg_ded_pos1();

	//bool Test :: test_signedbigfloat_neg_ded_pos2()
	//Тест разности отрицательного(obj1) и положительного чисел(obj2)
	//при этом: |obj1| < |obj2|
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_signedbigfloat_neg_ded_pos2();

	//bool Test :: test_signedbigfloat_pos_ded_neg()
	//Тест разности положительного(obj1) и отрицательного чисел(obj2)
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_signedbigfloat_pos_ded_neg();

	//bool Test :: test_signedbigfloat_neg_ded_neg1()
	//Тест разности отрицательного(obj1) и отрицательного чисел(obj2)
	//при этом: |obj1| > |obj2|
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_signedbigfloat_neg_ded_neg1();

	//bool Test :: test_signedbigfloat_neg_ded_neg2()
	//Тест разности отрицательного(obj1) и отрицательного чисел(obj2)
	//при этом: |obj1| < |obj2|
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_signedbigfloat_neg_ded_neg2();
	
	//bool Test :: test_signedbigfloat_pos_mult_pos1()
	//Тест умножения двух положительных объектов (0.0 < объекты < 1.0)
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_signedbigfloat_pos_mult_pos1();

	//bool Test :: test_signedbigfloat_pos_mult_pos2()
	//Тест умножения двух положительных объектов (объекты >= 1.0)
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_signedbigfloat_pos_mult_pos2();

	//bool Test :: test_signedbigfloat_neg_mult_pos()
	//Тест умножения отрицательного и положительного числа
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_signedbigfloat_neg_mult_pos();

	//bool Test :: test_signedbigfloat_pos_mult_neg()
	//Тест умножения положительного и отрицательного числа
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_signedbigfloat_pos_mult_neg();

	//bool Test :: test_signedbigfloat_neg_mult_neg()
	//Тест умножения двух отрицательных чисел
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_signedbigfloat_neg_mult_neg();
	
	//количество удачных тестов
	int suc;

	//количество неудачных тестов
	int fail;
};