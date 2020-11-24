#pragma once
class Test
{
public:
	//����������� ������ Test �� ���������
	Test();

	//bool Test :: test_polymorph_toString()
	//���� ������������ �� ��������������� ������ toString()
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_polymorph_toString();

	//bool Test :: test_toString()
	//���� ������������� ���� � ��������� ����
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_toString();

	//bool Test :: test_toStringReverse()
	//���� ������������� ���� � ��������� ���� (���. �����������)
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_toStringReverse();

	//bool Test :: test_push_front_empty_deque()
	//���� ���������� �������� � ��� ��� ���������� ������ ����
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_push_front_empty_deque();

	//bool Test :: test_push_front()
	//���� ���������� ��������� � ���
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_push_front();

	//bool Test :: test_pop_front_empty()
	//���� �������� �������� � ������ ���� ��� ������ ����
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_pop_front_empty();

	//bool Test :: test_pop_front_alone()
	//���� �������� �������� � ������ ���� (� ���� ����������� ���� �������)
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_pop_front_alone();

	//bool Test :: test_pop_front_one()
	//���� �������� ������ �������� � ������ ���� ��� ���������� ���� (n>1)
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_pop_front_one();

	//bool Test :: test_pop_front_few()
	//���� �������� ���������� ��������� � ������ ���� ��� ���������� ���� (n>2)
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_pop_front_few();

	//bool Test :: test_pop_back_empty()
	//���� �������� �������� � ����� ���� ��� ������ ����
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_pop_back_empty();

	//bool Test :: test_pop_back_alone()
	//���� �������� �������� � ����� ���� (� ���� ����������� ���� �������)
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_pop_back_alone();

	//bool Test :: test_pop_back_one()
	//���� �������� ������ �������� � ����� ���� ��� ���������� ���� (n>1)
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_pop_back_one();

	//bool Test :: test_pop_back_few()
	//���� �������� ���������� ��������� � ����� ���� ��� ���������� ���� (n>2)
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_pop_back_few();

	//bool Test :: test_find_without_NULL()
	//���� ������ (��� �������� � ���� �� NULL)
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_find_without_NULL();

	//bool Test :: test_pop_back_few()
	//���� ������ (����� ��������� ���� NULL)
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_find_with_NULL();

	//bool Test :: test_pop_front_return()
	//���� �������� �������� � ������ ���� (������������ ��������)
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_pop_front_return();

	//bool Test :: test_pop_back_return()
	//���� �������� �������� � ����� ���� (������������ ��������)
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_pop_back_return();

	//bool Test :: test_pop_front_return_NULL()
	//���� �������� �������� � ������ ���� (��� ������)
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_pop_front_return_NULL();

	//bool Test :: test_pop_back_return_NULL()
	//���� �������� �������� � ����� ���� (��� ������)
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_pop_back_return_NULL();

	//���������� ������� ������
	int suc;

	//���������� ��������� ������
	int fail;
};