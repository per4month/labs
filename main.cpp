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
	cout << "---------Выберите интересующий вас пункт меню--------" << endl;
	cout << "1. Создать бинарный файл" << endl;
	cout << "2. Загрузить бинарный файл" << endl;
	cout << "3. Вывести список в прямом направлении" << endl;
	cout << "4. Вывести список в обратном направлении" << endl;
	cout << "5. Вставить элемент в конец списка" << endl;
	cout << "6. Вставить элемент в начало списка" << endl;
	cout << "7. Вставить элемент в список по логическому номеру" << endl;
	cout << "8. Вставить элемент в список с сохранением порядка" << endl;
	cout << "9. Редактировать (обновить) данные элемента списка" << endl;
	cout << "10. Извлечь элемент из списка" << endl;
	cout << "11. Поиск элемента в списке" << endl;
	cout << "12. Сортировка" << endl;
	cout << "13. Удалить элемент с конца списка" << endl;
	cout << "14. Удалить элемент с начала списка" << endl;
	cout << "15. Удалить элемент списка по логическому номеру" << endl;
	cout << "16. Сжатие файла" << endl;
	cout << "17. Выйти из данного меню" << endl;
	cout << "Команда: ";
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
		cout << "         Работа с простым типом данных (int)" << endl;
		menu();
		cin >> cmd;
		switch (cmd){
			case 1: //Создание списка в двоичном файле
				{
					cout << endl << "Введите имя файла (с расширением .txt или .dat): " << endl;
					cin >> fname;
					f_list->close();
					ofstream of(fname);
					if (!of) {
						cout << "Ошибка! Невозможно прочитать файл." << endl;
						of.close();
						break;
					}
					of.close();
					f_list = new FList<int>(fname);
					cout << "Список успешно создан в бинарном файле." << endl;
					break;
				}
			case 2: //Загрузка списка из двоичного файла
				{
					cout << endl << "Введите имя файла (с расширением .txt или .dat): " << endl;
					cin >> fname;
					f_list->close();
					f_list = new FList<int>(fname);
					if (f_list->fail())
					{
						cout << "Ошибка! Невозможно прочитать бинарный файл." << endl;
						break;
					}
					else
						cout << "Бинарный файл со списком успешно загружен." << endl;
					break;
				}
			case 3: //Вывод списка в прямом направлении
				{
					if (!f_list->fail())
					{
						cout << "Список: " <<endl;
						cout << endl;
						f_list->printList();
						break;
					}
					else 
					{
						cout <<"Ошибка! Невозможно прочитать бинарный файл."<<endl;
						break;
					}
				}
			case 4: //Вывод cписка в обратном направлении
				{
					if (!f_list->fail())
					{
						cout << endl << "Список: " <<endl;
						cout << endl;
						f_list->printListReverse();
						break;
					}
					else 
					{
						cout <<"Ошибка! Невозможно прочитать бинарный файл."<<endl;
						break;
					}
				}
			case 5: //Вставка в конец списка
				{
					if (!f_list->fail())
					{
						cout << endl << "Введите значение для вставки в конец списка: ";
						cin >> value;
						f_list->push_back(value);
						cout << endl << "Узел успешно добавлен!" << endl;
						break;
					}
					else 
					{
						cout <<"Ошибка! Невозможно прочитать бинарный файл."<<endl;
						break;
					}
				}
			case 6: //Вставка в начало списка
				{
					if (!f_list->fail())
					{
						cout << endl << "Введите значение для вставки в начало списка: ";
						cin >> value;
						f_list->push_front(value);
						cout << endl << "Узел успешно добавлен!" << endl;
						break;
					}
					else 
					{
						cout <<"Ошибка! Невозможно прочитать бинарный файл."<<endl;
						break;
					}
				}
			case 7: //Вставка элемента по логическому номеру
				{
					if (!f_list->fail())
					{
						cout << endl << "Введите значение узла: ";
						cin >> value;
						cout << endl <<"Замечание: индексация списка начинается с 1(одного)!" << endl;
						cout << "Введите логический номер для вставки: ";
						cin >> pos;
						bool flag = f_list->insert(pos,value);
						if (flag)
						{
							cout << endl << "Узел успешно добавлен!" << endl;
						}
						else {
							cout << endl << "Узел не добавлен!" << endl;
						}
						break;
						}
					else 
					{
						cout <<"Ошибка! Невозможно прочитать бинарный файл."<<endl;
						break;
					}
				}
			case 8: //вставка с сохранением порядка
				{
					if (!f_list->fail())
					{
						cout << endl << "Введите значение узла: ";
						cin >> value;
						pos = f_list->insertSort(value);
						cout << endl << "Узел успешно добавлен и расположен по логическому номеру: " << pos << endl;
						break;
					}
					else 
					{
						cout <<"Ошибка! Невозможно прочитать бинарный файл."<<endl;
						break;
					}
				}
			case 9: //Редактирование узла
				{
					if (!f_list->fail())
					{
						cout << endl << "Замечание: индексация списка начинается с 1(одного)!" << endl;
						cout << "Введите логический номер редактируемого узла: ";
						cin >> pos;
						bool flag = f_list->update(pos);
						if (flag)
						{
							cout << endl << "Значение в узле успешно отредактировано!" << endl;
						}	
					else 
					{
						cout << endl << "Значение в узле не отредактировано!" << endl;
					}
						break;
					}
					else 
					{
						cout <<"Ошибка! Невозможно прочитать бинарный файл."<<endl;
						break;
					}
				}
			case 10: //Извлечение
				{
					if (!f_list->fail())
					{
						cout << endl <<"Замечание: индексация списка начинается с 1(одного)!" << endl;
						cout << "Введите логический номер узла, значение которого вы хотите извлечь: ";
						cin >> pos;
						try{ 
							if(pos < 1 || pos > f_list->getCount())
							{
								//Неверная позиция
								throw exception("Ошибка! Неверное значение логического номера!");
							}	
						}
						catch (exception &ex){
							cout << ex.what() << endl;
							break;
						}
						value = f_list->getFromPos(pos);
						cout << endl << "Извлечённое значение узла № " << pos <<": " << value << endl;
						break;
					}
					else 
					{
						cout <<"Ошибка! Невозможно прочитать бинарный файл."<<endl;
						break;
					}	
				}
			case 11: //Поиск элемента в списке
				{
					if (!f_list->fail())
					{
						cout << endl << "Введите значение элемента, который вы хотите найти в списке: ";
						cin >> value;
						pos = f_list->find(value);
						if (pos == 0) 
							{
								cout << endl << "Подходящих значений не найдено!" << endl;
							}
						else if (pos >0) {
								cout << "----------------------------------------------------------------------" << endl; 
								cout << "Найдено элементов: " << pos << " шт., удовлетворяющих вашему запросу." << endl;
								cout << "----------------------------------------------------------------------" << endl;
						}	
						break;
					}
					else 
					{
						cout <<"Ошибка! Невозможно прочитать бинарный файл."<<endl;
						break;
					}
				}
			case 12: //Сортировка
				{
					if (!f_list->fail())
					{
						f_list->sort();
						break;
					}
					else
					{
						cout <<"Ошибка! Невозможно прочитать бинарный файл."<<endl;
						break;
					}
				}
			case 13: //Удаление элемента  с конца списка
				{
					if (!f_list->fail())
					{
						try {
							if (f_list->getCount() == 0) {
								throw exception("Ошибка! Удаление невозможно, в списке отсутсвуют элементы");
							}
						}
						catch(exception &ex){
							cout << ex.what() << endl;
							break;
						}
						value = f_list->pop_back();
						cout << "Значение удалённого узла списка: " << value << endl;
						break;
					}
					else 
					{
						cout <<"Ошибка! Невозможно прочитать бинарный файл."<<endl;
						break;
					}
				}
			case 14: //Удаление элемента  с начала списка
				{
					if (!f_list->fail())
					{
						try {
							if (f_list->getCount() == 0) {
								throw exception("Ошибка! Удаление невозможно, в списке отсутсвуют элементы");
							}
						}
						catch(exception &ex){
							cout << ex.what() << endl;
							break;
						}
						value = f_list->pop_front();
						cout << "Значение удалённого узла списка: " << value << endl;
						break;
					}
					else 
					{
						cout <<"Ошибка! Невозможно прочитать бинарный файл."<<endl;
						break;
					}
				}
			case 15: //Удаление элемента  по логическому номеру
				{
					if (!f_list->fail())
					{
						cout << endl <<"Замечание: индексация списка начинается с 1(одного)!" << endl;
						cout << "Введите логический номер узла, который хотите удалить: ";
						cin >> pos;
						try{
							if(pos < 1 || pos > f_list->getCount())
								{
								//Неверная позиция
								throw exception("Ошибка! Неверное значение логического номера!");
								}	
							}
						catch (exception &ex){
						cout << ex.what() << endl;
						break;
						}
						value = f_list->pop(pos);
						cout << "Значение удалённого узла списка: " << value << endl;
						break;
					}
					else 
					{
						cout <<"Ошибка! Невозможно прочитать бинарный файл."<<endl;
						break;
					}
				}
			case 16: //Сжатие
				{
					if (!f_list->fail())
					{
						int oldsize, newsize = 0;
						f_list->seekg(0, ios::end);//перемещаемся на последнюю свободную позицию для записи
						oldsize = f_list->tellp();
						f_list->compress(fname);
						f_list->seekg(0, ios::end);
						newsize = f_list->tellp();
						if (oldsize == newsize){
							cout << endl << "Файл не содержит лишней информации." << endl;
							cout << "Размер файла: " << oldsize << " байт." << endl;
						}
						else {
							cout << endl << "Сжатие файла проведено успешно." << endl;
							cout << "Старый размер файла: " << oldsize << " байт."<< endl;
							cout << "Новый размер файла: " << newsize << " байт."<< endl;
						}
						break;
					}
					else 
					{
						cout <<"Ошибка! Невозможно прочитать бинарный файл."<<endl;
						break;
					}
				}
			case 17: //Выход из меню
				{
				f_list->close();
				return;
				}
			default:
				{
				cout << "Повторите ввод!" << endl;
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
		cout << "                    Доска объявлений" << endl;
		menu();
		cin >> cmd;
		switch (cmd){
			case 1: //Создание списка в двоичном файле
				{
					cout << endl << "Введите имя файла (с расширением .txt или .dat): " << endl;
					cin >> fname;
					f_list->close();
					ofstream of(fname);
					if (!of) {
						cout << "Ошибка! Невозможно прочитать файл." << endl;
						of.close();
						break;
					}
					of.close();
					f_list = new FList<Advert>(fname);
					cout << "Список успешно создан в бинарном файле." << endl;
					break;
				}
			case 2: //Загрузка списка из двоичного файла
				{
					cout << endl << "Введите имя файла (с расширением .txt или .dat): " << endl;
					cin >> fname;
					f_list->close();
					f_list = new FList<Advert>(fname);
					if (f_list->fail())
					{
						cout << "Ошибка! Невозможно прочитать бинарный файл." << endl;
						break;
					}
					else
						cout << "Бинарный файл со списком успешно загружен." << endl;
					break;
				}
			case 3: //Вывод списка в прямом направлении
				{
					if (!f_list->fail())
					{
						cout << "Список: " <<endl;
						cout << endl;
						f_list->printList();
						break;
					}
					else 
					{
						cout <<"Ошибка! Невозможно прочитать бинарный файл."<<endl;
						break;
					}
				}
			case 4: //Вывод cписка в обратном направлении
				{
					if (!f_list->fail())
					{
						cout << endl << "Список: " <<endl;
						cout << endl;
						f_list->printListReverse();
						break;
					}
					else 
					{
						cout <<"Ошибка! Невозможно прочитать бинарный файл."<<endl;
						break;
					}
				}
			case 5: //Вставка в конец списка
				{
					if (!f_list->fail())
					{
					cout << endl << "Введите значение для вставки в конец списка: " << endl;
					cin >> value;
					f_list->push_back(value);
					cout << endl << "Узел успешно добавлен!" << endl;
					break;
					}
					else 
					{
						cout <<"Ошибка! Невозможно прочитать бинарный файл."<<endl;
						break;
					}
				}
			case 6: //Вставка в начало списка
				{
					if (!f_list->fail())
					{
					cout << endl << "Введите значение для вставки в начало списка: " << endl;
					cin >> value;
					f_list->push_front(value);
					cout << endl << "Узел успешно добавлен!" << endl;
					break;
					}
					else 
					{
						cout <<"Ошибка! Невозможно прочитать бинарный файл."<<endl;
						break;
					}
				}
			case 7: //Вставка элемента по логическому номеру
				{
					if (!f_list->fail())
					{
						cout << endl <<"Замечание: индексация списка начинается с 1(одного)!" << endl;
						cout << "Введите логический номер для вставки: ";
						cin >> pos;
						try{
							if(pos < 1 || pos > f_list->getCount() + 1)
							{
							//Неверная позиция
							throw exception("Ошибка! Неверное значение логического номера!");
							}	
						}
						catch (exception &ex){
							cout << ex.what() << endl;
							break;
						}
						cout << endl << "Введите значение узла: " << endl;
						cin >> value;
						bool flag = f_list->insert(pos,value);
						if (flag)
						{
							cout << endl << "Узел успешно добавлен!" << endl;
						}
						else {
							cout << endl << "Узел не добавлен!" << endl;
						}
						break;
					}
					else 
					{
						cout <<"Ошибка! Невозможно прочитать бинарный файл."<<endl;
						break;
					}
				}
			case 8: //вставка с сохранением порядка
				{
					if (!f_list->fail())
					{
						cout << endl << "Введите значение узла: " << endl;;
						cin >> value;
						pos = f_list->insertSort(value);
						cout << endl << "Узел успешно добавлен и расположен по логическому номеру: " << pos << endl;
						break;
					}
					else 
					{
						cout <<"Ошибка! Невозможно прочитать бинарный файл."<<endl;
						break;
					}
				}
			case 9: //Редактирование узла
				{
					if (!f_list->fail())
					{
					cout << endl << "Замечание: индексация списка начинается с 1(одного)!" << endl;
					cout << "Введите логический номер редактируемого узла: ";
					cin >> pos;
					cout << endl;
					bool flag = f_list->update(pos);
					if (flag)
					{
						cout << endl << "Значение в узле успешно отредактировано!" << endl;
					}
					else {
						cout << endl << "Значение в узле не отредактировано!" << endl;
					}
					break;
					}
					else 
					{
						cout <<"Ошибка! Невозможно прочитать бинарный файл."<<endl;
						break;
					}
				}
			case 10: //Извлечение
				{
					if (!f_list->fail())
					{
						cout << endl <<"Замечание: индексация списка начинается с 1(одного)!" << endl;
						cout << "Введите логический номер узла, значение которого вы хотите извлечь: ";
						cin >> pos;
						try{ 
							if(pos < 1 || pos > f_list->getCount())
							{
								//Неверная позиция
								throw exception("Ошибка! Неверное значение логического номера!");
							}	
						}
						catch (exception &ex){
							cout << ex.what() << endl;
							break;
						}
						value = f_list->getFromPos(pos);
						cout << endl << "Извлечённое значение узла № " << pos << endl;
						cout << value << endl;
						break;
					}
					else 
					{
						cout <<"Ошибка! Невозможно прочитать бинарный файл."<<endl;
						break;
					}	
				}
			case 11: //Поиск элемента в списке
				{
					if (!f_list->fail())
					{
						cout << endl << "Введите значение для поиска: ";
						cout << "Рубрика\n1 - транспорт\n2 - недвижимость\n3 - материалы\n4 - одежда\n5 - бытовая техника\n0 - прочее" << endl;
						cout << "Введите 1(одно) число: ";
						int rub = 0;
						cin >> rub;
						if (rub > 5 || rub < 0)
							rub = 0;
						cout << endl << "Введите фрагмент текста объявления: ";
						cin.getline(buf, 1);
						cin.getline(buf, 255);
						value.SetRub(rub);
						value.SetText(_strdup(buf));
						pos = f_list->find(value);
						if (pos == 0) 
							{
								cout << endl << "Подходящих значений не найдено!" << endl;
							}
						else if (pos > 0) {
								cout << "----------------------------------------------------------------------" << endl; 
								cout << "Найдено элементов: " << pos << " шт., удовлетворяющих вашему запросу." << endl;
								cout << "----------------------------------------------------------------------" << endl;
						}	
						break;
					}
					else 
					{
						cout <<"Ошибка! Невозможно прочитать бинарный файл."<<endl;
						break;
					}
				}
			case 12: //Сортировка
				{
					if (!f_list->fail())
					{
						f_list->sort();
						break;
					}
					else
					{
						cout <<"Ошибка! Невозможно прочитать бинарный файл."<<endl;
						break;
					}
				}
			case 13: //Удаление элемента  с конца списка
				{
					if (!f_list->fail())
					{
						try {
							if (f_list->getCount() == 0) {
								throw exception("Ошибка! Удаление невозможно, в списке отсутсвуют элементы");
							}
						}
						catch(exception &ex){
							cout << ex.what() << endl;
							break;
						}
						value = f_list->pop_back();
						cout << "Значение удалённого узла списка: " << endl << value << endl;
						break;
					}
					else 
					{
						cout <<"Ошибка! Невозможно прочитать бинарный файл."<<endl;
						break;
					}
				}
			case 14: //Удаление элемента  с начала списка
				{
					if (!f_list->fail())
					{
						try {
							if (f_list->getCount() == 0) {
								throw exception("Ошибка! Удаление невозможно, в списке отсутсвуют элементы");
							}
						}
						catch(exception &ex){
							cout << ex.what() << endl;
							break;
						}
						value = f_list->pop_front();
						cout << "Значение удалённого узла списка: " << endl << value << endl;
						break;
					}
					else 
					{
						cout <<"Ошибка! Невозможно прочитать бинарный файл."<<endl;
						break;
					}
				}
			case 15: //Удаление элемента  по логическому номеру
				{
					if (!f_list->fail())
					{
						cout << endl <<"Замечание: индексация списка начинается с 1(одного)!" << endl;
						cout << "Введите логический номер узла, который хотите удалить: ";
						cin >> pos;
						try{
							if (f_list->getCount() == 0) {
								throw exception("Ошибка! Удаление невозможно, в списке отсутсвуют элементы");
							}
							if(pos < 1 || pos > f_list->getCount())
								{
								//Неверная позиция
								throw exception("Ошибка! Неверное значение логического номера!");
								}	
							}
						catch (exception &ex){
						cout << ex.what() << endl;
						break;
						}
						value = f_list->pop(pos);
						cout << "Значение удалённого узла списка: " << endl << value << endl;
						break;
					}
					else 
					{
						cout <<"Ошибка! Невозможно прочитать бинарный файл."<<endl;
						break;
					}
				}
			case 16: //Сжатие
				{
					if (!f_list->fail())
					{
						int oldsize, newsize = 0;
						f_list->seekg(0, ios::end);//перемещаемся на последнюю свободную позицию для записи
						oldsize = f_list->tellp();
						f_list->compress(fname);
						f_list->seekg(0, ios::end);
						newsize = f_list->tellp();
						if (oldsize == newsize){
							cout << endl << "Файл не содержит лишней информации." << endl;
							cout << "Размер файла: " << oldsize << " байт." << endl;
						}
						else {
							cout << endl << "Сжатие файл проведено успешно." << endl;
							cout << "Старый размер файла: " << oldsize << " байт."<< endl;
							cout << "Новый размер файла: " << newsize << " байт."<< endl;
						}
						break;
					}
					else 
					{
						cout <<"Ошибка! Невозможно прочитать бинарный файл."<<endl;
						break;
					}
				}
			case 17: //Выход из меню
				{
				f_list->close();
				return;
				}
			default:
				cout << "Повторите ввод!" << endl;
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
		cout << "Количество добавленных элементов: " << i*10000 <<endl;
		cout << "Время вставки: " << (double)(after - before) / 1000 << " сек." << endl;
		cout << "Исходный объём: " << oldsize << " байт." << endl;
		cout << "Итоговый объем: " << newsize << " байт." <<endl;
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
		cout << "                  Курсовая работа" << endl;
		cout << "           по дисциплине Программирование" << endl;
		cout << "       Тема: Последовательный двоичный файл" << endl;
		cout << "Группа: АВТ-943" << endl;
		cout << "Студент: Васильченко М.А." << endl;
		cout << "Вариант: 2.9.4" << endl;
		cout << "Преподаватель: Романенко Т.А." << endl;
		cout << endl;
		cout << "Выберите интересующий вас пункт меню:" << endl;
		cout << "1. Проверка списка на простом типе данных (int)" << endl;
		cout << "2. Работа с доской объявлений" << endl;
		cout << "3. Нагрузочное тестирование" << endl;
		cout << "4. Выход из программы" << endl;
		cout << "Команда: ";
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
			cout << "Повторите ввод" << endl;
		}
		system("pause");
	}
	return 0;
}