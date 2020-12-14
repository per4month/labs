#include "Advert.h"
#include <string.h> //��� ������� _strdup
using namespace std;

const char Advert::rubrics[6][30] = { "������","���������", "������������" ,"���������" ,"������", "������� �������" };

const int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; // ��������������� ������ ��� �������� ���� � ���

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

void Advert::print()
{
	cout << "���������: " << (category == 's' ? "�������" : (category == 'b' ? "�������" : "������")) << std::endl;
	cout << "�������:" << Advert::rubrics[rubric] << std::endl;
	cout << "����: " << dd / 10 << dd % 10 << '.' << mm / 10 << mm % 10 << '.' << yy << std::endl;
	cout << "�����: " << text << std::endl;
	cout << "���.: " << telephone << std::endl << std::endl;
}

std::ostream& operator << (std::ostream &out, Advert &an)
{
	out << "���������: " << (an.category =='s'? "�������" : (an.category == 'b'? "�������": "������"))<<std::endl; 
	out << "�������:" << Advert::rubrics[an.rubric] << std::endl;
	out << "����: " << an.dd/10<< an.dd%10<<'.' <<an.mm / 10 << an.mm % 10  <<'.' << an.yy << std::endl;
	out << "�����: " << an.text << std::endl;
	out << "�������: " << an.telephone << std::endl<<endl;
	return out;
}

std::istream& operator >> (std::istream& in, Advert& an)
{
	cout << "�������(���� ������) ��������� s - ������� , b - �������, x - ������: ";
	cin >> an.category;
	if (an.category != 's' && an.category != 'b')
		an.category = 'x';
	cout << "�������\n1 - ���������\n2 - ������������\n3 - ���������\n4 - ������\n5 - ������� �������\n0 - ������\n";
	cout << "������� 1(����) �����: ";
	cin >> an.rubric;
	if (an.rubric > 5)
		an.rubric = 0;
	cout << "�������(��� ����� ����� ������) ���� ������ ���������� � ������� yyyy mm dd:";
	bool flag = true;
	while (flag){
	cin >> an.yy >> an.mm >> an.dd;
		if (an.yy <= 0) {
			cout << "������� ����� ���! ��������� ������� ����� � ������� yyyy mm dd: ";
			continue;
		}
		if (an.mm > 12 || an.mm <= 0) {
			cout << "������� ����� �����! ��������� ������� ����� � ������� yyyy mm dd: ";
			continue;
		}
		if (an.dd >= month[an.mm-1]) {
			cout << "������� ����� ����! ��������� ������� ����� � ������� yyyy mm dd: ";
			continue;
		}
		flag = false;
	}
	cout << "������� ����� ����������, �� ����� 255 ��������: ";
	char* buf = new char[255];
	cin.getline(buf, 1);
	cin.getline(buf, 255);
	an.text = _strdup(buf);
	cout << "������� ����� ��������, � ������������ ������: ";
	cin.getline(buf, 255);
	an.telephone = _strdup(buf);
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