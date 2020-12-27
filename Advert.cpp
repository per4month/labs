#include "Advert.h"
#include <string.h> //для функции _strdup
using namespace std;

bool isDigit(char* str) {
	try {
		if (strlen(str) != 11) {
			throw exception("Телефонный номер должен состоять из 11 знаков!");
		}
		for (int i = 0; str[i]!= '\0'; i++){
			if (!(str[i] <= '9' && str[i] >= '0')) 
			{
				throw exception("Телефонный номер может состоять только из цифр и без <+> в начале!");
				return false;
			}
		}
	}
	catch (exception &ex){
		cout << ex.what() << endl;
		return false;
	}
	return true;
}

const char Advert::rubrics[6][30] = { "прочее","транспорт", "недвижимость" ,"материалы" ,"одежда", "бытовая техника" };

const int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; // вспомогательный массив для перевода даты в дни

Advert::Advert()
{
	category = 'x';
	rubric = 0;
	dd = 0; 
	mm = 0;
	yy = 0;
	text = new char;
	telephone = new char;
}

Advert::Advert(char _category, int _rubric, int _dd, int _mm, int _yy, char* _text, char* _telephone)
{
	category = _category;
	rubric = _rubric;
	dd = _dd;
	mm = _mm;
	yy = _yy;
	text = _strdup(_text);
	telephone = _strdup(_telephone);
}

Advert::Advert(Advert &other)
{
	category = other.category;
	rubric = other.rubric;
	dd = other.dd;
	mm = other.mm;
	yy = other.yy;
	text = _strdup(other.text);
	telephone = _strdup(other.telephone);
}

Advert::~Advert(void)
{
	if (text)
	{
		delete[] text;
		text = NULL;
	}
	if (telephone)
	{
		delete[] telephone;
		telephone = NULL;
	}
}

void Advert::SetRub(int r)
{
	rubric = r;
}

void Advert::SetText(char* _text)
{
	text = _strdup(_text);
}

bool Advert::operator < (Advert& a)
{
	if (this->yy < a.yy)
		return true;
	if ((this->yy == a.yy) && (this->mm < a.mm))
		return true;
	if ((this->yy == a.yy) && (this->mm = a.mm) && (this->dd < a.dd))
		return true;
	return false;
}

bool Advert::operator > (Advert& a)
{
	return a < *this;
}

bool Advert::operator ==(Advert const& other)
{
	
	return (rubric==other.rubric && strstr(text,other.text)!=NULL);
}

Advert& Advert::operator =(Advert const& other)
{
	category = other.category;
	rubric = other.rubric;
	dd = other.dd;
	mm = other.mm;
	yy = other.yy;
	text = _strdup(other.text);
	telephone = _strdup(other.telephone);
	return *this;
}

void Advert::print()
{
	cout << "Категория: " << (category == 's' ? "продажа" : (category == 'b' ? "покупка" : "прочее")) << std::endl;
	cout << "Рубрика:" << Advert::rubrics[rubric] << std::endl;
	cout << "Дата: " << dd / 10 << dd % 10 << '.' << mm / 10 << mm % 10 << '.' << yy << std::endl;
	cout << "Текст: " << text << std::endl;
	cout << "Тел.: " << telephone << std::endl << std::endl;
}

std::ostream& operator << (std::ostream &out, Advert &an)
{
	out << "Категория: " << (an.category =='s'? "продажа" : (an.category == 'b'? "покупка": "прочее"))<<std::endl; 
	out << "Рубрика:" << Advert::rubrics[an.rubric] << std::endl;
	out << "Дата: " << an.dd/10<< an.dd%10<<'.' <<an.mm / 10 << an.mm % 10  <<'.' << an.yy << std::endl;
	out << "Текст: " << an.text << std::endl;
	out << "Телефон: " << an.telephone << std::endl<<endl;
	return out;
}

std::istream& operator >> (std::istream& in, Advert& an)
{
	cout << "Введите(один символ) категорию s - продажа , b - покупка, x - прочее: ";
	cin >> an.category;
	if (an.category != 's' && an.category != 'b')
		an.category = 'x';
	cout << "Рубрика\n1 - транспорт\n2 - недвижимость\n3 - материалы\n4 - одежда\n5 - бытовая техника\n0 - прочее\n";
	cout << "Введите 1(одно) число: ";
	cin >> an.rubric;
	if (an.rubric > 5 || an.rubric < 1)
		an.rubric = 0;
	cout << "Введите(три числа через пробел) дату подачи объявления в формате yyyy mm dd:";
	bool flag = true;
	while (flag){
	cin >> an.yy >> an.mm >> an.dd;
		if (an.yy <= 0) {
			cout << "Неверно введён год! Повторите попытку ввода в формате yyyy mm dd: ";
			continue;
		}
		if (an.mm > 12 || an.mm <= 0) {
			cout << "Неверно введён месяц! Повторите попытку ввода в формате yyyy mm dd: ";
			continue;
		}
		if (an.dd > month[an.mm-1] || an.dd <=0) {
			cout << "Неверно введён день! Повторите попытку ввода в формате yyyy mm dd: ";
			continue;
		}
		flag = false;
	}
	cout << "Введите текст объявления, не более 255 символов: ";
	char* buf = new char[255];
	cin.getline(buf, 1);
	cin.getline(buf, 255);
	an.text = _strdup(buf);
	flag = false;
	while (!flag){
		cout << "Введите 11-значный номер телефона (без + в начале): ";
		cin.getline(buf, 255);
		if (isDigit(buf)){
			an.telephone = _strdup(buf);
			cout << "Номер телефона успешно введён!" << endl;
			flag = true;
		}
		else
		{
			cout << "Повторите попытку ввода!" << endl;
			cout << endl;
		}
	}
	delete[] buf;
	return in;
}

std::fstream& operator << (std::fstream& outf, Advert&  a)
{
	outf.write((char*)&a.category, sizeof(a.category));
	outf.write((char*)&a.rubric, sizeof(a.rubric));
	outf.write((char*)&a.dd, sizeof(a.dd));
	outf.write((char*)&a.mm, sizeof(a.mm));
	outf.write((char*)&a.yy, sizeof(a.yy));
	int len = strlen(a.text);
	outf.write((char*)&len, sizeof(len));
	outf.write((char*)a.text, sizeof(char)*len);
	len = strlen(a.telephone);
	outf.write((char*)&len, sizeof(len));
	outf.write((char*)a.telephone, sizeof(char)*len);
	return outf;
}

std::fstream& operator >>(std::fstream& inf, Advert& a)
{
	delete[] a.text;
	delete[] a.telephone;

	inf.read((char*)&a.category, sizeof(a.category));
	inf.read((char*)&a.rubric, sizeof(a.rubric));
	inf.read((char*)&a.dd, sizeof(a.dd));
	inf.read((char*)&a.mm, sizeof(a.mm));
	inf.read((char*)&a.yy, sizeof(a.yy));
	int len = 0;
	inf.read((char*)&len, sizeof(len));
	a.text = new char[len + 1];
	a.text[len]='\0';
	inf.read((char*)a.text, sizeof(char)*len);
	inf.read((char*)&len, sizeof(len));
	a.telephone = new char[len + 1];
	a.telephone[len]='\0';
 	inf.read((char*)a.telephone, sizeof(char)*len);

	return inf;
}

void Advert :: redact(Advert &obj){
while(true){
	cout <<"Введите номер редактируемого параметра из доски объявлений"<< endl;
	cout <<"1. Категория объявления" << endl;
	cout <<"2. Рубрика" << endl;
	cout <<"3. Дата подачи" << endl;
	cout <<"4. Текст объявления" << endl;
	cout <<"5. Контактный телефон" << endl;
	int x = 0;
	while(true){
		cout <<"Команда: ";
		cin >> x;
		if (x < 1 || x > 5) {
			cout << "Осуществлён неверный ввод! Повторите попытку снова." << endl;
		}
		else {
			break;
		}
	}
	switch(x) {
		case 1:
		{
			cout << "Введите(один символ) категорию s - продажа , b - покупка, x - прочее: ";
			cin >> (obj.category);
			if (obj.category != 's' && obj.category != 'b')
			obj.category = 'x';
			break;
		}
		case 2:
		{
			cout << "Рубрика\n1 - транспорт\n2 - недвижимость\n3 - материалы\n4 - одежда\n5 - бытовая техника\n0 - прочее\n";
			cout << "Введите 1(одно) число: ";
			cin >> obj.rubric;
			if (obj.rubric > 5 || obj.rubric < 1)
				obj.rubric = 0;
			break;
		}
		case 3:
		{
			cout << "Введите(три числа через пробел) дату подачи объявления в формате yyyy mm dd:";
			bool flag = true;
			while (flag){
				cin >> obj.yy >> obj.mm >> obj.dd;
				if (obj.yy <= 0) {
					cout << "Неверно введён год! Повторите попытку ввода в формате yyyy mm dd: ";
					continue;
				}
				if (obj.mm > 12 || obj.mm <= 0) {
					cout << "Неверно введён месяц! Повторите попытку ввода в формате yyyy mm dd: ";
					continue;
				}
				if (obj.dd > month[obj.mm-1] || obj.dd <=0) {
					cout << "Неверно введён день! Повторите попытку ввода в формате yyyy mm dd: ";
					continue;
				}
				flag = false;
			}
			break;
		}
		case 4:
		{
			cout << "Введите текст объявления, не более 255 символов: ";
			char* buf = new char[255];
			cin.getline(buf, 1);
			cin.getline(buf, 255);
			obj.text = _strdup(buf);
			delete[] buf;
			break;
		}	
		case 5:
		{
			bool flag = false;
			char* buf = new char[255];
			while (!flag){
			cout << "Введите 11-значный номер телефона (без +): ";
			cin.getline(buf, 1);
			cin.getline(buf, 255);
			if (isDigit(buf)){
				obj.telephone = _strdup(buf);
				cout << "Номер телефона успешно введён!" << endl;
				flag = true;
			}
			else
			{
				cout << "Повторите попытку ввода!" << endl;
				cout << endl;
			}
	}
	delete[] buf;
		}
	}
	cout << "Вы хотите продолжить редактирование?" << endl;
	cout << "1. Да" << endl;
	cout << "2. Нет" << endl;
	while(true){
		cout <<"Команда: ";
		cin >> x;
		if (x < 1 || x > 2) {
			cout << "Осуществлён неверный ввод! Повторите попытку снова." << endl;
		}
		else {
			break;
		}
	}
	if (x == 2) break;
}
}