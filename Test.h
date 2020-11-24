#pragma once
class Test
{
public:
	//Конструктор класса Test по умолчанию
	Test();

	//bool Test :: test_polymorph_toString()
	//Тест полиморфизма на переопределённом методе toString()
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_polymorph_toString();

	//bool Test :: test_toString()
	//Тест представления дека в строковом типе
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_toString();

	//bool Test :: test_toStringReverse()
	//Тест представления дека в строковом типе (обр. направление)
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_toStringReverse();

	//bool Test :: test_push_front_empty_deque()
	//Тест добавления элемента в дек при изначально пустом деке
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_push_front_empty_deque();

	//bool Test :: test_push_front()
	//Тест добавления элементов в дек
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_push_front();

	//bool Test :: test_pop_front_empty()
	//Тест удаления элемента с начала дека при пустом деке
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_pop_front_empty();

	//bool Test :: test_pop_front_alone()
	//Тест удаления элемента с начала дека (в деке присутсвует один элемент)
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_pop_front_alone();

	//bool Test :: test_pop_front_one()
	//Тест удаления одного элемента с начала дека при заполненом деке (n>1)
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_pop_front_one();

	//bool Test :: test_pop_front_few()
	//Тест удаления нескольких элементов с начала дека при заполненом деке (n>2)
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_pop_front_few();

	//bool Test :: test_pop_back_empty()
	//Тест удаления элемента с конца дека при пустом деке
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_pop_back_empty();

	//bool Test :: test_pop_back_alone()
	//Тест удаления элемента с конца дека (в деке присутсвует один элемент)
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_pop_back_alone();

	//bool Test :: test_pop_back_one()
	//Тест удаления одного элемента с конца дека при заполненом деке (n>1)
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_pop_back_one();

	//bool Test :: test_pop_back_few()
	//Тест удаления нескольких элементов с конца дека при заполненом деке (n>2)
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_pop_back_few();

	//bool Test :: test_find_without_NULL()
	//Тест поиска (все элементы в деке не NULL)
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_find_without_NULL();

	//bool Test :: test_pop_back_few()
	//Тест поиска (среди элементов есть NULL)
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_find_with_NULL();

	//bool Test :: test_pop_front_return()
	//Тест удаления элемента с начала дека (возвращаемое значение)
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_pop_front_return();

	//bool Test :: test_pop_back_return()
	//Тест удаления элемента с конца дека (возвращаемое значение)
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_pop_back_return();

	//bool Test :: test_pop_front_return_NULL()
	//Тест удаления элемента с начала дека (дек пустой)
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_pop_front_return_NULL();

	//bool Test :: test_pop_back_return_NULL()
	//Тест удаления элемента с конца дека (дек пустой)
	//args:
	//- нет входных параметров -
	//return - true или false
	bool test_pop_back_return_NULL();

	//количество удачных тестов
	int suc;

	//количество неудачных тестов
	int fail;
};