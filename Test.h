#pragma once
class Test
{
public:

	Test();

	//bool Test :: test_sum()
	//Тест перегрузки оператора суммы объектов класса
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_sum();

	//bool Test :: test_deduct()
	//Тест перегрузки оператора вычитания объектов класса
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_deduct();

	//bool Test :: test_addTen_int()
	//Тест перегрузки умножения на 10^n (int)
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_addTen_int();

	//bool Test :: test_addTen_long_long()
	//Тест перегрузки умножения на 10^n (long long)
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_addTen_long_long();

	//bool Test :: test_addTen_unsigned_long_long()
	//Тест перегрузки умножения на 10^n (unsigned long long)
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_addTen_unsigned_long_long();

	//bool Test :: test_addTen_null()
	//Тест перегрузки умножения на 0 
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_addTen_null();

	//bool Test :: test_addTen_one()
	//Тест перегрузки умножения на 10 (10^0) 
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_addTen_one();

	//bool Test :: test_divTen_int()
	//Тест перегрузки деления на 10^n (int)
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_divTen_int();
	
	//bool Test :: test_divTen_long_long()
	//Тест перегрузки деления на 10^n (long long)
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_divTen_long_long();

	//bool Test :: test_divTen_unsigned_long_long()
	//Тест перегрузки деления на 10^n (unsigned long long)
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_divTen_unsigned_long_long();

	//bool Test :: test_divTen_null()
	//Тест перегрузки деления на 0 
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_divTen_null();
	
	//bool Test :: test_divTen_one()
	//Тест перегрузки деления на 10^n (10^0) 
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_divTen_one();

	//bool Test :: test_divTen_first_smaller_then_number()
	//Тест перегрузки деления на 10^n (число в объекте меньше делителя) 
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_divTen_first_smaller_then_number();

	//bool Test :: test_divTen_equal()
	//Тест перегрузки деления на 10^n (число в объекте по длине равно делителю) 
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_divTen_equal();

	//bool Test :: test_assigning_once()
	//Тест перегрузки одинарного присваивания
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_assigning_once();

	//bool Test :: test_assigning_twice()
	//Тест перегрузки двойного присваивания
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_assigning_twice();

	//bool Test :: test_assigning_himself()
	//Тест перегрузки присваивания самого себя
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_assigning_himself();

	//bool Test::test1_unsigned_long_test1()
	//Тест перегрузки приведения к типу unsigned long
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test1_unsigned_long();

	//bool Test::test2_unsigned_long()
	//Тест перегрузки приведения к типу unsigned long, если пременная была уже инициализирована
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test2_unsigned_long();
	
	//количество удачных тестов
	int suc;

	//количество неудачных тестов
	int fail;
};


