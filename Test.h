#pragma once
class Test
{
public:
	//����������� ������ Test �� ���������
	Test();

	//---------�������� ������-���������� BigFloat--------

	//bool Test :: test_constructror_bigfloat_default()
	//���� ������������ ������ BigFloat �� ���������
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_constructror_bigfloat_default();

	//bool Test :: test_constructror_bigfloat_long()
	//���� ������������ ������ BigFloat, ������������ ��� long
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_constructror_bigfloat_long();

	//bool Test :: test_constructror_bigfloat_char()
	//���� ������������ ������ BigFloat, ������������ ��� char
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_constructror_bigfloat_char();

	//bool Test :: test_constructror_bigfloat_copy()
	//���� ������������ ����������� ������ BigFloat
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_constructror_bigfloat_copy();

	//bool Test :: test_bigfloat_add_null()
	//���� �������� ������� � ��������, ���������� ����
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_bigfloat_add_null();

	//bool Test :: test_bigfloat_add_number1()
	//���� �������� ������� � �������� (������� >= 1.0)
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_bigfloat_add_number1();

	//bool Test :: test_bigfloat_add_number2()
	//���� �������� ������� � �������� (0.0 < ������� < 1.0)
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_bigfloat_add_number2();

	//bool Test :: test_bigfloat_deduct_number_equal()
	//���� ��������� ���� ���������� ��������
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_bigfloat_deduct_number_equal();

	//bool Test :: test_bigfloat_deduct_number1()
	//���� ��������� ���� �������� (������� >= 1.0)
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_bigfloat_deduct_number1();

	//bool Test :: test_bigfloat_deduct_number2()
	//���� ��������� ���� �������� (0.0 < ������� < 1.0)
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_bigfloat_deduct_number2();

	//bool Test :: test_bigfloat_mult_null()
	//���� ��������� ���� �������� (���� �� �������� ����� ����)
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_bigfloat_mult_null();

	//bool Test :: test_bigfloat_mult_number1()
	//���� ��������� ���� �������� (������� >= 1.0)
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_bigfloat_mult_number1();

	//bool Test :: test_bigfloat_mult_number2()
	//���� ��������� ���� �������� (0.0 < ������� < 1.0)
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_bigfloat_mult_number2();

	//-----------�������� ������-���������� SignedBigFloat------------

	//bool Test :: test_constructror_signedbigfloat_default()
	//���� ������������ ������ SignedBigFloat �� ���������
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_constructror_signedbigfloat_default();

	//bool Test :: test_constructror_signedbigfloat_positive_long()
	//���� ������������ ������ SignedBigFloat, ������������ ��� long (������������� �����)
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_constructror_signedbigfloat_positive_long();

	//bool Test :: test_constructror_signedbigfloat_negative_long()
	//���� ������������ ������ SignedBigFloat, ������������ ��� long (������������� ����� �����)
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_constructror_signedbigfloat_negative_long();

	//bool Test :: test_constructror_signedbigfloat_positive_char()
	//���� ������������ ������ SignedBigFloat, ������������ ��� char (������������� �����)
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_constructror_signedbigfloat_positive_char();

	//bool Test :: test_constructror_signedbigfloat_negative_char()
	//���� ������������ ������ SignedBigFloat, ������������ ��� char (������������� ����� �����)
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_constructror_signedbigfloat_negative_char();

	//bool Test :: test_constructror_signedbigfloat_copy()
	//���� ������������ ����������� ������ SignedBigFloat
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_constructror_signedbigfloat_copy();
	
	//bool Test :: test_signedbigfloat_pos_add_pos()
	//���� �������� ���� ������������� �����
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_signedbigfloat_pos_add_pos();

	//bool Test :: test_signedbigfloat_neg_add_pos1()
	//���� �������� ��������������(obj1) � �������������� �����(obj2)
	//��� ����: |obj1| > |obj2|
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_signedbigfloat_neg_add_pos1();

	//bool Test :: test_signedbigfloat_neg_add_pos2()
	//���� �������� ��������������(obj1) � �������������� �����(obj2)
	//��� ����: |obj1| < |obj2|
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_signedbigfloat_neg_add_pos2();

	//bool Test :: test_signedbigfloat_pos_add_neg1()
	//���� �������� ��������������(obj1) � �������������� �����(obj2)
	//��� ����: |obj1| > |obj2|
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_signedbigfloat_pos_add_neg1();

	//bool Test :: test_signedbigfloat_pos_add_neg2()
	//���� �������� ��������������(obj1) � �������������� �����(obj2)
	//��� ����: |obj1| < |obj2|
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_signedbigfloat_pos_add_neg2();

	//test_signedbigfloat_neg_add_neg()
	//���� �������� ���� ������������� �����
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_signedbigfloat_neg_add_neg();
	
	//bool Test :: test_signedbigfloat_pos_ded_pos1()
	//���� �������� ��������������(obj1) � �������������� �����(obj2)
	//��� ����: |obj1| > |obj2|
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_signedbigfloat_pos_ded_pos1();

	//bool Test :: test_signedbigfloat_pos_ded_pos2()
	//���� �������� ��������������(obj1) � �������������� �����(obj2)
	//��� ����: |obj1| < |obj2|
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_signedbigfloat_pos_ded_pos2();

	//bool Test :: test_signedbigfloat_neg_ded_pos1()
	//���� �������� ��������������(obj1) � �������������� �����(obj2)
	//��� ����: |obj1| > |obj2|
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_signedbigfloat_neg_ded_pos1();

	//bool Test :: test_signedbigfloat_neg_ded_pos2()
	//���� �������� ��������������(obj1) � �������������� �����(obj2)
	//��� ����: |obj1| < |obj2|
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_signedbigfloat_neg_ded_pos2();

	//bool Test :: test_signedbigfloat_pos_ded_neg()
	//���� �������� ��������������(obj1) � �������������� �����(obj2)
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_signedbigfloat_pos_ded_neg();

	//bool Test :: test_signedbigfloat_neg_ded_neg1()
	//���� �������� ��������������(obj1) � �������������� �����(obj2)
	//��� ����: |obj1| > |obj2|
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_signedbigfloat_neg_ded_neg1();

	//bool Test :: test_signedbigfloat_neg_ded_neg2()
	//���� �������� ��������������(obj1) � �������������� �����(obj2)
	//��� ����: |obj1| < |obj2|
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_signedbigfloat_neg_ded_neg2();
	
	//bool Test :: test_signedbigfloat_pos_mult_pos1()
	//���� ��������� ���� ������������� �������� (0.0 < ������� < 1.0)
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_signedbigfloat_pos_mult_pos1();

	//bool Test :: test_signedbigfloat_pos_mult_pos2()
	//���� ��������� ���� ������������� �������� (������� >= 1.0)
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_signedbigfloat_pos_mult_pos2();

	//bool Test :: test_signedbigfloat_neg_mult_pos()
	//���� ��������� �������������� � �������������� �����
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_signedbigfloat_neg_mult_pos();

	//bool Test :: test_signedbigfloat_pos_mult_neg()
	//���� ��������� �������������� � �������������� �����
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_signedbigfloat_pos_mult_neg();

	//bool Test :: test_signedbigfloat_neg_mult_neg()
	//���� ��������� ���� ������������� �����
	//args:
	//- ��� ������� ���������� -
	//return - true ��� false
	bool test_signedbigfloat_neg_mult_neg();
	
	//���������� ������� ������
	int suc;

	//���������� ��������� ������
	int fail;
};