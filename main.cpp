#include "List.h"
#include <iostream>
#include "Advert.h"
#include "locale.h"
#include <iomanip>
#include <windows.h>
#include <fstream>
#include <ctime>

using namespace std;

void menu(){
	cout << "---------�������� ������������ ��� ����� ����--------" << endl;
	cout << "1. ������� �������� ����" << endl;
	cout << "2. ��������� �������� ����" << endl;
	cout << "3. ������� ������ � ������ �����������" << endl;
	cout << "4. ������� ������ � �������� �����������" << endl;
	cout << "5. �������� ������� � ����� ������" << endl;
	cout << "6. �������� ������� � ������ ������" << endl;
	cout << "7. �������� ������� � ������ �� ����������� ������" << endl;
	cout << "8. �������� ������� � ������ � ����������� �������" << endl;
	cout << "9. ������������� (��������) ������ �������� ������" << endl;
	cout << "10. ������� ������� �� ������" << endl;
	cout << "11. ����� �������� � ������" << endl;
	cout << "12. ����������" << endl;
	cout << "13. ������� ������� � ����� ������" << endl;
	cout << "14. ������� ������� � ������ ������" << endl;
	cout << "15. ������� ������� ������ �� ����������� ������" << endl;
	cout << "16. ������ �����" << endl;
	cout << "17. ����� �� ������� ����" << endl;
	cout << "�������: ";
}

void testInt(){
	system("cls");
	char fname[20] = "testInt.dat";
	ofstream of(fname);
	of.close();
	FList<int> *f_list= new FList<int>(fname);
	while (true)
	{
		system("cls");
		int cmd = 0;
		int value = 0;
		int pos = 0;
		cout << "         ������ � ������� ����� ������ (int)" << endl;
		menu();
		cin >> cmd;
		switch (cmd){
			case 1: //�������� ������ � �������� �����
				{
					cout << endl << "������� ��� ����� (� ����������� .txt ��� .dat): " << endl;
					cin >> fname;
					f_list->close();
					ofstream of(fname);
					if (!of) {
						cout << "������! ���������� ��������� ����." << endl;
						of.close();
						break;
					}
					of.close();
					f_list = new FList<int>(fname);
					cout << "������ ������� ������ � �������� �����." << endl;
					break;
				}
			case 2: //�������� ������ �� ��������� �����
				{
					cout << endl << "������� ��� ����� (� ����������� .txt ��� .dat): " << endl;
					cin >> fname;
					f_list->close();
					f_list = new FList<int>(fname);
					if (f_list->fail())
					{
						cout << "������! ���������� ��������� �������� ����." << endl;
						break;
					}
					else
						cout << "�������� ���� �� ������� ������� ��������." << endl;
					break;
				}
			case 3: //����� ������ � ������ �����������
				{
					if (!f_list->fail())
					{
						cout << "������: " <<endl;
						cout << endl;
						f_list->printList();
						break;
					}
					else 
					{
						cout <<"������! ���������� ��������� �������� ����."<<endl;
						break;
					}
				}
			case 4: //����� c����� � �������� �����������
				{
					if (!f_list->fail())
					{
						cout << endl << "������: " <<endl;
						cout << endl;
						f_list->printListReverse();
						break;
					}
					else 
					{
						cout <<"������! ���������� ��������� �������� ����."<<endl;
						break;
					}
				}
			case 5: //������� � ����� ������
				{
					if (!f_list->fail())
					{
						cout << endl << "������� �������� ��� ������� � ����� ������: ";
						cin >> value;
						f_list->push_back(value);
						cout << endl << "���� ������� ��������!" << endl;
						break;
					}
					else 
					{
						cout <<"������! ���������� ��������� �������� ����."<<endl;
						break;
					}
				}
			case 6: //������� � ������ ������
				{
					if (!f_list->fail())
					{
						cout << endl << "������� �������� ��� ������� � ������ ������: ";
						cin >> value;
						f_list->push_front(value);
						cout << endl << "���� ������� ��������!" << endl;
						break;
					}
					else 
					{
						cout <<"������! ���������� ��������� �������� ����."<<endl;
						break;
					}
				}
			case 7: //������� �������� �� ����������� ������
				{
					if (!f_list->fail())
					{
						cout << endl << "������� �������� ����: ";
						cin >> value;
						cout << endl <<"���������: ���������� ������ ���������� � 1(������)!" << endl;
						cout << "������� ���������� ����� ��� �������: ";
						cin >> pos;
						bool flag = f_list->insert(pos,value);
						if (flag)
						{
							cout << endl << "���� ������� ��������!" << endl;
						}
						else {
							cout << endl << "���� �� ��������!" << endl;
						}
						break;
						}
					else 
					{
						cout <<"������! ���������� ��������� �������� ����."<<endl;
						break;
					}
				}
			case 8: //������� � ����������� �������
				{
					if (!f_list->fail())
					{
						cout << endl << "������� �������� ����: ";
						cin >> value;
						pos = f_list->insertSort(value);
						cout << endl << "���� ������� �������� � ���������� �� ����������� ������: " << pos << endl;
						break;
					}
					else 
					{
						cout <<"������! ���������� ��������� �������� ����."<<endl;
						break;
					}
				}
			case 9: //�������������� ����
				{
					if (!f_list->fail())
					{
						cout << endl << "���������: ���������� ������ ���������� � 1(������)!" << endl;
						cout << "������� ���������� ����� �������������� ����: ";
						cin >> pos;
						bool flag = f_list->update(pos);
						if (flag)
						{
							cout << endl << "�������� � ���� ������� ���������������!" << endl;
						}	
					else 
					{
						cout << endl << "�������� � ���� �� ���������������!" << endl;
					}
						break;
					}
					else 
					{
						cout <<"������! ���������� ��������� �������� ����."<<endl;
						break;
					}
				}
			case 10: //����������
				{
					if (!f_list->fail())
					{
						cout << endl <<"���������: ���������� ������ ���������� � 1(������)!" << endl;
						cout << "������� ���������� ����� ����, �������� �������� �� ������ �������: ";
						cin >> pos;
						try{ 
							if(pos < 1 || pos > f_list->getCount())
							{
								//�������� �������
								throw exception("������! �������� �������� ����������� ������!");
							}	
						}
						catch (exception &ex){
							cout << ex.what() << endl;
							break;
						}
						value = f_list->getFromPos(pos);
						cout << endl << "����������� �������� ���� � " << pos <<": " << value << endl;
						break;
					}
					else 
					{
						cout <<"������! ���������� ��������� �������� ����."<<endl;
						break;
					}	
				}
			case 11: //����� �������� � ������
				{
					if (!f_list->fail())
					{
						cout << endl << "������� �������� ��������, ������� �� ������ ����� � ������: ";
						cin >> value;
						pos = f_list->find(value);
						if (pos == 0) 
							{
								cout << endl << "���������� �������� �� �������!" << endl;
							}
						else if (pos >0) {
								cout << "----------------------------------------------------------------------" << endl; 
								cout << "������� ���������: " << pos << " ��., ��������������� ������ �������." << endl;
								cout << "----------------------------------------------------------------------" << endl;
						}	
						break;
					}
					else 
					{
						cout <<"������! ���������� ��������� �������� ����."<<endl;
						break;
					}
				}
			case 12: //����������
				{
					if (!f_list->fail())
					{
						f_list->sort();
						break;
					}
					else
					{
						cout <<"������! ���������� ��������� �������� ����."<<endl;
						break;
					}
				}
			case 13: //�������� ��������  � ����� ������
				{
					if (!f_list->fail())
					{
						try {
							if (f_list->getCount() == 0) {
								throw exception("������! �������� ����������, � ������ ���������� ��������");
							}
						}
						catch(exception &ex){
							cout << ex.what() << endl;
							break;
						}
						value = f_list->pop_back();
						cout << "�������� ��������� ���� ������: " << value << endl;
						break;
					}
					else 
					{
						cout <<"������! ���������� ��������� �������� ����."<<endl;
						break;
					}
				}
			case 14: //�������� ��������  � ������ ������
				{
					if (!f_list->fail())
					{
						try {
							if (f_list->getCount() == 0) {
								throw exception("������! �������� ����������, � ������ ���������� ��������");
							}
						}
						catch(exception &ex){
							cout << ex.what() << endl;
							break;
						}
						value = f_list->pop_front();
						cout << "�������� ��������� ���� ������: " << value << endl;
						break;
					}
					else 
					{
						cout <<"������! ���������� ��������� �������� ����."<<endl;
						break;
					}
				}
			case 15: //�������� ��������  �� ����������� ������
				{
					if (!f_list->fail())
					{
						cout << endl <<"���������: ���������� ������ ���������� � 1(������)!" << endl;
						cout << "������� ���������� ����� ����, ������� ������ �������: ";
						cin >> pos;
						try{
							if(pos < 1 || pos > f_list->getCount())
								{
								//�������� �������
								throw exception("������! �������� �������� ����������� ������!");
								}	
							}
						catch (exception &ex){
						cout << ex.what() << endl;
						break;
						}
						value = f_list->pop(pos);
						cout << "�������� ��������� ���� ������: " << value << endl;
						break;
					}
					else 
					{
						cout <<"������! ���������� ��������� �������� ����."<<endl;
						break;
					}
				}
			case 16: //������
				{
					if (!f_list->fail())
					{
						int oldsize, newsize = 0;
						f_list->seekg(0, ios::end);//������������ �� ��������� ��������� ������� ��� ������
						oldsize = f_list->tellp();
						f_list->compress(fname);
						f_list->seekg(0, ios::end);
						newsize = f_list->tellp();
						if (oldsize == newsize){
							cout << endl << "���� �� �������� ������ ����������." << endl;
							cout << "������ �����: " << oldsize << " ����." << endl;
						}
						else {
							cout << endl << "������ ����� ��������� �������." << endl;
							cout << "������ ������ �����: " << oldsize << " ����."<< endl;
							cout << "����� ������ �����: " << newsize << " ����."<< endl;
						}
						break;
					}
					else 
					{
						cout <<"������! ���������� ��������� �������� ����."<<endl;
						break;
					}
				}
			case 17: //����� �� ����
				{
				f_list->close();
				return;
				}
			default:
				{
				cout << "��������� ����!" << endl;
				break;
				}

		}
		system("pause");
	}
}

void testAdvert(){
	system("cls");
	char fname[20] = "testAdvert.dat";
	ofstream of(fname);
	of.close();
	int cmd = 0;
	Advert value;
	int pos = 0;
	char buf[300];
	FList<Advert> *f_list= new FList<Advert>(fname);
	while (true)
	{
		system("cls");
		cout << "                    ����� ����������" << endl;
		menu();
		cin >> cmd;
		switch (cmd){
			case 1: //�������� ������ � �������� �����
				{
					cout << endl << "������� ��� ����� (� ����������� .txt ��� .dat): " << endl;
					cin >> fname;
					f_list->close();
					ofstream of(fname);
					if (!of) {
						cout << "������! ���������� ��������� ����." << endl;
						of.close();
						break;
					}
					of.close();
					f_list = new FList<Advert>(fname);
					cout << "������ ������� ������ � �������� �����." << endl;
					break;
				}
			case 2: //�������� ������ �� ��������� �����
				{
					cout << endl << "������� ��� ����� (� ����������� .txt ��� .dat): " << endl;
					cin >> fname;
					f_list->close();
					f_list = new FList<Advert>(fname);
					if (f_list->fail())
					{
						cout << "������! ���������� ��������� �������� ����." << endl;
						break;
					}
					else
						cout << "�������� ���� �� ������� ������� ��������." << endl;
					break;
				}
			case 3: //����� ������ � ������ �����������
				{
					if (!f_list->fail())
					{
						cout << "������: " <<endl;
						cout << endl;
						f_list->printList();
						break;
					}
					else 
					{
						cout <<"������! ���������� ��������� �������� ����."<<endl;
						break;
					}
				}
			case 4: //����� c����� � �������� �����������
				{
					if (!f_list->fail())
					{
						cout << endl << "������: " <<endl;
						cout << endl;
						f_list->printListReverse();
						break;
					}
					else 
					{
						cout <<"������! ���������� ��������� �������� ����."<<endl;
						break;
					}
				}
			case 5: //������� � ����� ������
				{
					if (!f_list->fail())
					{
					cout << endl << "������� �������� ��� ������� � ����� ������: " << endl;
					cin >> value;
					f_list->push_back(value);
					cout << endl << "���� ������� ��������!" << endl;
					break;
					}
					else 
					{
						cout <<"������! ���������� ��������� �������� ����."<<endl;
						break;
					}
				}
			case 6: //������� � ������ ������
				{
					if (!f_list->fail())
					{
					cout << endl << "������� �������� ��� ������� � ������ ������: " << endl;
					cin >> value;
					f_list->push_front(value);
					cout << endl << "���� ������� ��������!" << endl;
					break;
					}
					else 
					{
						cout <<"������! ���������� ��������� �������� ����."<<endl;
						break;
					}
				}
			case 7: //������� �������� �� ����������� ������
				{
					if (!f_list->fail())
					{
						cout << endl <<"���������: ���������� ������ ���������� � 1(������)!" << endl;
						cout << "������� ���������� ����� ��� �������: ";
						cin >> pos;
						try{
							if(pos < 1 || pos > f_list->getCount() + 1)
							{
							//�������� �������
							throw exception("������! �������� �������� ����������� ������!");
							}	
						}
						catch (exception &ex){
							cout << ex.what() << endl;
							break;
						}
						cout << endl << "������� �������� ����: " << endl;
						cin >> value;
						bool flag = f_list->insert(pos,value);
						if (flag)
						{
							cout << endl << "���� ������� ��������!" << endl;
						}
						else {
							cout << endl << "���� �� ��������!" << endl;
						}
						break;
					}
					else 
					{
						cout <<"������! ���������� ��������� �������� ����."<<endl;
						break;
					}
				}
			case 8: //������� � ����������� �������
				{
					if (!f_list->fail())
					{
						cout << endl << "������� �������� ����: " << endl;;
						cin >> value;
						pos = f_list->insertSort(value);
						cout << endl << "���� ������� �������� � ���������� �� ����������� ������: " << pos << endl;
						break;
					}
					else 
					{
						cout <<"������! ���������� ��������� �������� ����."<<endl;
						break;
					}
				}
			case 9: //�������������� ����
				{
					if (!f_list->fail())
					{
					cout << endl << "���������: ���������� ������ ���������� � 1(������)!" << endl;
					cout << "������� ���������� ����� �������������� ����: ";
					cin >> pos;
					cout << endl;
					bool flag = f_list->update(pos);
					if (flag)
					{
						cout << endl << "�������� � ���� ������� ���������������!" << endl;
					}
					else {
						cout << endl << "�������� � ���� �� ���������������!" << endl;
					}
					break;
					}
					else 
					{
						cout <<"������! ���������� ��������� �������� ����."<<endl;
						break;
					}
				}
			case 10: //����������
				{
					if (!f_list->fail())
					{
						cout << endl <<"���������: ���������� ������ ���������� � 1(������)!" << endl;
						cout << "������� ���������� ����� ����, �������� �������� �� ������ �������: ";
						cin >> pos;
						try{ 
							if(pos < 1 || pos > f_list->getCount())
							{
								//�������� �������
								throw exception("������! �������� �������� ����������� ������!");
							}	
						}
						catch (exception &ex){
							cout << ex.what() << endl;
							break;
						}
						value = f_list->getFromPos(pos);
						cout << endl << "����������� �������� ���� � " << pos << endl;
						cout << value << endl;
						break;
					}
					else 
					{
						cout <<"������! ���������� ��������� �������� ����."<<endl;
						break;
					}	
				}
			case 11: //����� �������� � ������
				{
					if (!f_list->fail())
					{
						cout << endl << "������� �������� ��� ������: ";
						cout << "�������\n1 - ���������\n2 - ������������\n3 - ���������\n4 - ������\n5 - ������� �������\n0 - ������" << endl;
						cout << "������� 1(����) �����: ";
						int rub = 0;
						cin >> rub;
						if (rub > 5 || rub < 0)
							rub = 0;
						cout << endl << "������� �������� ������ ����������: ";
						cin.getline(buf, 1);
						cin.getline(buf, 255);
						value.SetRub(rub);
						value.SetText(_strdup(buf));
						pos = f_list->find(value);
						if (pos == 0) 
							{
								cout << endl << "���������� �������� �� �������!" << endl;
							}
						else if (pos > 0) {
								cout << "----------------------------------------------------------------------" << endl; 
								cout << "������� ���������: " << pos << " ��., ��������������� ������ �������." << endl;
								cout << "----------------------------------------------------------------------" << endl;
						}	
						break;
					}
					else 
					{
						cout <<"������! ���������� ��������� �������� ����."<<endl;
						break;
					}
				}
			case 12: //����������
				{
					if (!f_list->fail())
					{
						f_list->sort();
						break;
					}
					else
					{
						cout <<"������! ���������� ��������� �������� ����."<<endl;
						break;
					}
				}
			case 13: //�������� ��������  � ����� ������
				{
					if (!f_list->fail())
					{
						try {
							if (f_list->getCount() == 0) {
								throw exception("������! �������� ����������, � ������ ���������� ��������");
							}
						}
						catch(exception &ex){
							cout << ex.what() << endl;
							break;
						}
						value = f_list->pop_back();
						cout << "�������� ��������� ���� ������: " << endl << value << endl;
						break;
					}
					else 
					{
						cout <<"������! ���������� ��������� �������� ����."<<endl;
						break;
					}
				}
			case 14: //�������� ��������  � ������ ������
				{
					if (!f_list->fail())
					{
						try {
							if (f_list->getCount() == 0) {
								throw exception("������! �������� ����������, � ������ ���������� ��������");
							}
						}
						catch(exception &ex){
							cout << ex.what() << endl;
							break;
						}
						value = f_list->pop_front();
						cout << "�������� ��������� ���� ������: " << endl << value << endl;
						break;
					}
					else 
					{
						cout <<"������! ���������� ��������� �������� ����."<<endl;
						break;
					}
				}
			case 15: //�������� ��������  �� ����������� ������
				{
					if (!f_list->fail())
					{
						cout << endl <<"���������: ���������� ������ ���������� � 1(������)!" << endl;
						cout << "������� ���������� ����� ����, ������� ������ �������: ";
						cin >> pos;
						try{
							if (f_list->getCount() == 0) {
								throw exception("������! �������� ����������, � ������ ���������� ��������");
							}
							if(pos < 1 || pos > f_list->getCount())
								{
								//�������� �������
								throw exception("������! �������� �������� ����������� ������!");
								}	
							}
						catch (exception &ex){
						cout << ex.what() << endl;
						break;
						}
						value = f_list->pop(pos);
						cout << "�������� ��������� ���� ������: " << endl << value << endl;
						break;
					}
					else 
					{
						cout <<"������! ���������� ��������� �������� ����."<<endl;
						break;
					}
				}
			case 16: //������
				{
					if (!f_list->fail())
					{
						int oldsize, newsize = 0;
						f_list->seekg(0, ios::end);//������������ �� ��������� ��������� ������� ��� ������
						oldsize = f_list->tellp();
						f_list->compress(fname);
						f_list->seekg(0, ios::end);
						newsize = f_list->tellp();
						if (oldsize == newsize){
							cout << endl << "���� �� �������� ������ ����������." << endl;
							cout << "������ �����: " << oldsize << " ����." << endl;
						}
						else {
							cout << endl << "������ ���� ��������� �������." << endl;
							cout << "������ ������ �����: " << oldsize << " ����."<< endl;
							cout << "����� ������ �����: " << newsize << " ����."<< endl;
						}
						break;
					}
					else 
					{
						cout <<"������! ���������� ��������� �������� ����."<<endl;
						break;
					}
				}
			case 17: //����� �� ����
				{
				f_list->close();
				return;
				}
			default:
				cout << "��������� ����!" << endl;
		}
		system("pause");
	}
}

void testStress(){
	system("cls");
	srand(time(NULL));
	char fname[25] = "test_stress.dat";

	for (int i = 1; i < 11; i++){
		int before = clock();
		ofstream of(fname);
		of.close();
		FList<int>f_list(fname);
		f_list.seekg(0, ios::end);
		int oldsize = f_list.tellp();
		for (int j = 10000 * i; j > 0; j--)
		{
			f_list.push_back(rand()%1000);
		}
		int after = clock();
		f_list.seekp(0, ios::end);
		int newsize = f_list.tellp();
		f_list.close();
		cout << "���������� ����������� ���������: " << i*10000 <<endl;
		cout << "����� �������: " << (double)(after - before) / 1000 << " ���." << endl;
		cout << "�������� �����: " << oldsize << " ����." << endl;
		cout << "�������� �����: " << newsize << " ����." <<endl;
		cout << "-------------------------------------------------" << endl;
	}
	system("pause");
}


int main(){
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Russian");
	int cmnd;
	while (true){
		system("cls");
		cout << "                  �������� ������" << endl;
		cout << "           �� ���������� ����������������" << endl;
		cout << "       ����: ���������������� �������� ����" << endl;
		cout << "������: ���-943" << endl;
		cout << "�������: ����������� �.�." << endl;
		cout << "�������: 2.9.4" << endl;
		cout << "�������������: ��������� �.�." << endl;
		cout << endl;
		cout << "�������� ������������ ��� ����� ����:" << endl;
		cout << "1. �������� ������ �� ������� ���� ������ (int)" << endl;
		cout << "2. ������ � ������ ����������" << endl;
		cout << "3. ����������� ������������" << endl;
		cout << "4. ����� �� ���������" << endl;
		cout << "�������: ";
		cin >> cmnd;
		switch (cmnd)
		{
		case 1:
			{
			testInt();
			break;
			}
		case 2:
			{
			testAdvert();
			break;
			}
		case 3:
			{
			testStress();
			break;
			}
		case 4:
			{
			return 0;
			}
		default:
			cout << "��������� ����" << endl;
		}
		system("pause");
	}
	return 0;
}