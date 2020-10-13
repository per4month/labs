#pragma once
class Test
{
public:

	Test();

	//bool Test :: test_sum()
	//���� ���������� ��������� ����� �������� ������
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_sum();

	//bool Test :: test_deduct()
	//���� ���������� ��������� ��������� �������� ������
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_deduct();

	//bool Test :: test_addTen_int()
	//���� ���������� ��������� �� 10^n (int)
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_addTen_int();

	//bool Test :: test_addTen_long_long()
	//���� ���������� ��������� �� 10^n (long long)
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_addTen_long_long();

	//bool Test :: test_addTen_unsigned_long_long()
	//���� ���������� ��������� �� 10^n (unsigned long long)
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_addTen_unsigned_long_long();

	//bool Test :: test_addTen_null()
	//���� ���������� ��������� �� 0 
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_addTen_null();

	//bool Test :: test_addTen_one()
	//���� ���������� ��������� �� 10 (10^0) 
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_addTen_one();

	//bool Test :: test_divTen_int()
	//���� ���������� ������� �� 10^n (int)
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_divTen_int();
	
	//bool Test :: test_divTen_long_long()
	//���� ���������� ������� �� 10^n (long long)
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_divTen_long_long();

	//bool Test :: test_divTen_unsigned_long_long()
	//���� ���������� ������� �� 10^n (unsigned long long)
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_divTen_unsigned_long_long();

	//bool Test :: test_divTen_null()
	//���� ���������� ������� �� 0 
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_divTen_null();
	
	//bool Test :: test_divTen_one()
	//���� ���������� ������� �� 10^n (10^0) 
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_divTen_one();

	//bool Test :: test_divTen_first_smaller_then_number()
	//���� ���������� ������� �� 10^n (����� � ������� ������ ��������) 
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_divTen_first_smaller_then_number();

	//bool Test :: test_divTen_equal()
	//���� ���������� ������� �� 10^n (����� � ������� �� ����� ����� ��������) 
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_divTen_equal();

	//bool Test :: test_assigning_once()
	//���� ���������� ���������� ������������
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_assigning_once();

	//bool Test :: test_assigning_twice()
	//���� ���������� �������� ������������
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_assigning_twice();

	//bool Test :: test_assigning_himself()
	//���� ���������� ������������ ������ ����
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_assigning_himself();

	//bool Test::test1_unsigned_long_test1()
	//���� ���������� ���������� � ���� unsigned long
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test1_unsigned_long();

	//bool Test::test2_unsigned_long()
	//���� ���������� ���������� � ���� unsigned long, ���� ��������� ���� ��� ����������������
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test2_unsigned_long();
	
	//���������� ������� ������
	int suc;

	//���������� ��������� ������
	int fail;
};


