#include "stdafx.h"
#include "DuzaLiczba.h"
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cassert>
#include <sstream>
#include <stdexcept>

using namespace std;


DuzaLiczba::DuzaLiczba() : Liczba(), wartosc(new char[2]{ '0', '\0' })
{

}

DuzaLiczba::DuzaLiczba(int a) : Liczba()
{
	int n = 1;
	if (a > 0)
		n = log10(a) + 1;
	else if (a < 0)
		n = log10(abs(a)) + 2;

	wartosc = new char[n + 1];
	wartosc[n] = '\0';
	sprintf(wartosc, "%i", a);
}

DuzaLiczba::DuzaLiczba(const char* a) : Liczba()
{
	int n = strlen(a);
	wartosc = new char[n + 1];
	wartosc[n] = '\0';
	strcpy(wartosc, a);
}

DuzaLiczba::DuzaLiczba(const DuzaLiczba& liczba) // konstr. kopiujacy
{
	int n = strlen(liczba.wartosc);
	wartosc = new char[n + 1];
	wartosc[n] = '\0';
	strcpy(wartosc, liczba.wartosc);
}

DuzaLiczba::~DuzaLiczba()
{
	delete[] wartosc;
}

DuzaLiczba& DuzaLiczba::operator=(const DuzaLiczba& liczba)
{
	if (this != &liczba) // sprawdzeni czy jest taka sytuacja: p0 = p0;
	{
		int n = strlen(liczba.wartosc);
		char* tmp = new char[n + 1];
		strcpy(tmp, liczba.wartosc);
		tmp[n] = '\0';
		delete[] wartosc;
		wartosc = tmp;
	}

	return *this;
}

// a = a + b;
DuzaLiczba DuzaLiczba::operator+(const DuzaLiczba& liczba) const
{
	if (*this < "0" && liczba >= "0")
		return liczba - -(*this);

	if (*this >= "0" && liczba < "0")
		return *this - -liczba;

	if (*this < "0" && liczba < "0")
		return *this - liczba;

	int s1 = strlen(wartosc);
	int s2 = strlen(liczba.wartosc);
	int s3 = s1 > s2 ? s1 + 1 : s2 + 1;

	const char* tmp1 = wartosc;
	const char* tmp2 = liczba.wartosc;
	char* tmp3 = new char[s3 + 1];
	for (int i = 0; i < s3; ++i)
		tmp3[i] = '0';
	tmp3[s3] = '\0';

	for (int i3 = s3 - 1, i2 = s2 - 1, i1 = s1 - 1; i3 >= 0; --i3, --i2, --i1)
	{
		if (i1 >= 0)
		{
			char p = '0';
			tmp3[i3] = add(tmp3[i3], tmp1[i1], &p);
			if (i3 > 0)
				tmp3[i3 - 1] = add(tmp3[i3 - 1], p, &p);
		}

		if (i2 >= 0)
		{
			char p = '0';
			tmp3[i3] = add(tmp3[i3], tmp2[i2], &p); // 9 + 9 -> 8, p = 1
			if (i3 > 0)
				tmp3[i3 - 1] = add(tmp3[i3 - 1], p, &p);
		}
	}

	// 999 + 999 = 1998
	// 111 + 11 = 0122

	while (tmp3[0] == '0' && s3 > 1)
	{
		for (int i = 0; i < s3; ++i)
			tmp3[i] = tmp3[i + 1];
		--s3;
	}

	DuzaLiczba wynik = tmp3; // konstruktor przenoszacy
	delete[] tmp3; // unique_ptr?
	return wynik;
}

DuzaLiczba DuzaLiczba::operator-(const DuzaLiczba& liczba) const
{
	// (-2) - 3 = (-2) + (-1)*3 = -5
	// 2 - (-3) = 2 + (-1)*(-3) = 5
	// (-3) - 2 = (-3)+ (-1)*2 = -5
	// 3 - (-2) = 3 + (-1)*(-2) = 5
	if ((*this < "0" && liczba >= "0") || (*this >= "0" && liczba < "0"))
		return *this + (-liczba);

	if ((*this >= "0" && liczba >= "0") && ((*this) < liczba))
		return -(liczba - *this);

	if ((*this < "0" && liczba < "0") && ((*this) <= liczba))
	{
		DuzaLiczba tmp = (-(*this)) - (-liczba);
		return -tmp;
	}

	if ((*this < "0" && liczba < "0") && ((*this) >= liczba)) //-2 - (-3) = 1 -> 3 - 2
	{
		return (-liczba) - (-(*this));
	}

	int s1 = strlen(wartosc);
	int s2 = strlen(liczba.wartosc);

	char* tmp1 = new char[s1 + 1];
	strcpy(tmp1, wartosc);
	char* tmp2 = liczba.wartosc;

	int s3 = s1;
	if (s2 > s1)
	{
		s3 = s2;
	}
	char* tmp3 = new char[s3 + 1];
	for (int i = 0; i < s3; ++i)
	{
		tmp3[i] = '0';
	}
	tmp3[s3] = NULL;

	for (int i3 = s3 - 1, i2 = s2 - 1, i1 = s1 - 1; i3 >= 0; --i3, --i2, --i1)
	{
		if (i1 >= 0 && i2 >= 0)
		{
			char p = '0';
			tmp3[i3] = sub(tmp1[i1], tmp2[i2], &p);
			//tmp1[i1-1] = sub(tmp1[i1-1], p, &p);
			for (int i = 0; p != '0'; ++i)
			{
				tmp1[i1 - 1 - i] = sub(tmp1[i1 - 1 - i], p, &p);
			}
		}
		else if (i1 >= 0)
		{
			tmp3[i3] = tmp1[i1];
		}
	}

	// 1234 - 1233 = 0001

	while (tmp3[0] == '0'  && strlen(tmp3) > 1)
	{
		for (int i = 0; i < s3; ++i)
		{
			tmp3[i] = tmp3[i + 1];
		}
	}

	DuzaLiczba wynik(tmp3);
	delete[] tmp3;
	return wynik;
}

DuzaLiczba DuzaLiczba::operator*(const DuzaLiczba& liczba) const
{
	if (*this < "0" && liczba < "0")
	{
		return (-(*this) * (-liczba)); // rekurencyjne wywołanie funkcji
	}

	if ((*this < "0" && liczba >= "0") || (*this >= "0" && liczba < "0"))
	{
		//1 * (-1) = -( 1 * (-(-1)))
		return -((*this) * (-liczba));
	}

	int s1 = strlen(wartosc);
	int s2 = strlen(liczba.wartosc);

	int s3 = 2 * s1;
	if (s2 > s1)
	{
		s3 = 2 * s2;
	}

	char* tmp1 = wartosc;
	char* tmp2 = liczba.wartosc;

	char* tmp3 = new char[s3 + 1];
	for (int i = 0; i<s3; ++i)
	{
		tmp3[i] = '0';
	}
	tmp3[s3] = NULL;

	//9999999
	//*    37
	//-------
	//3

	for (int i2 = s2 - 1; i2 >= 0; --i2)
	{
		for (int i1 = s1 - 1; i1 >= 0; --i1)
		{
			int i3 = s1 - 1 - i1 + s2 - 1 - i2; // indeks liczony 'po ludzku' od prawej strony

			char p = '0';
			char m = mult(tmp1[i1], tmp2[i2], &p);
			for (int i = 1; p != '0'; ++i)
			{
				tmp3[s3 - 1 - i3 - i] = add(tmp3[s3 - 1 - i3 - i], p, &p);
			}

			tmp3[s3 - 1 - i3] = add(tmp3[s3 - 1 - i3], m, &p);
			for (int i = 1; p != '0'; ++i)
			{
				tmp3[s3 - 1 - i3 - i] = add(tmp3[s3 - 1 - i3 - i], p, &p);
			}
		}

	}

	while (tmp3[0] == '0' && strlen(tmp3) > 1)
	{
		for (int i = 0; i < s3; ++i)
		{
			tmp3[i] = tmp3[i + 1];
		}
	}

	DuzaLiczba wynik = tmp3;
	delete[] tmp3;
	return wynik;
}

DuzaLiczba DuzaLiczba::operator/(const DuzaLiczba& liczba) const
{
	if (liczba == "0")
	{
		throw - 1;
	}

	if (*this < "0" && liczba < "0")
	{
		return (-(*this) / (-liczba)); // rekurencyjne wywołanie funkcji
	}

	if ((*this < "0" && liczba >= "0") || (*this >= "0" && liczba < "0"))
	{
		return -((*this) / (-liczba));
	}

	DuzaLiczba wynik = "0";
	for (DuzaLiczba tmp = *this; tmp >= liczba; wynik += 1)
	{
		tmp -= liczba;
	}

	return wynik;
}

DuzaLiczba& DuzaLiczba::operator+=(const DuzaLiczba& liczba)
{
	// i = i + 2
	// i += 2
	(*this) = (*this) + liczba;
	return *this;
}

DuzaLiczba&DuzaLiczba::operator-=(const DuzaLiczba& liczba)
{
	*this = *this - liczba;
	return *this;
}

DuzaLiczba&DuzaLiczba::operator*=(const DuzaLiczba& liczba)
{
	*this = (*this) * liczba;
	return *this;
}

DuzaLiczba&DuzaLiczba::operator/=(const DuzaLiczba& liczba)
{
	if (liczba == "0")
	{
		throw 0;
	}

	*this = (*this) / liczba;
	return *this;
}

DuzaLiczba DuzaLiczba::operator!() const
{
	if (*this < "0")
	{
		return "-1";
	}

	if (*this == "0")
	{
		return "1";
	}

	DuzaLiczba tmp = "1";
	for (DuzaLiczba i = "1"; i <= (*this); i += "1")
	{
		tmp *= i;
	}

	return tmp;
}

DuzaLiczba DuzaLiczba::operator-() const
{
	if (this->wartosc[0] == '-')
	{
		DuzaLiczba wynik = *this; //obiekt na którym wywołujemy funkce
								  //strcpy(wynik.wartosc, &wynik.wartosc[1]);
		int s = strlen(wynik.wartosc);
		for (int i = 0; i < s; ++i)
		{
			wynik.wartosc[i] = wynik.wartosc[i + 1];
		}
		return wynik;
	}

	int s = 1 + strlen(this->wartosc);
	char* tmp = new char[s + 1];
	tmp[s] = NULL;
	//strcpy(&wynik.wartosc[1], this->wartosc);
	for (int i = 0; i < s - 1; ++i)
	{
		tmp[i + 1] = wartosc[i];
	}
	tmp[0] = '-';

	DuzaLiczba wynik = tmp;
	delete[] tmp;
	return wynik;
}

bool DuzaLiczba::operator==(const DuzaLiczba& liczba) const
{
	int s1 = strlen(wartosc);
	int s2 = strlen(liczba.wartosc);

	if (s1 != s2)
	{
		return false;
	}

	for (int i = 0; i < s1; ++i)
	{
		if (wartosc[i] != liczba.wartosc[i])
		{
			return false;
		}
	}

	return true;
}

bool DuzaLiczba::operator!=(const DuzaLiczba& liczba) const
{
	return !(*this == liczba);
}

//liczba < 0
bool DuzaLiczba::operator<(const DuzaLiczba& liczba) const
{
	if ((*this) == liczba)
	{
		return false;
	}

	int s1 = strlen(wartosc);
	int s2 = strlen(liczba.wartosc);

	char z1 = '-';
	if (wartosc[0] != '-')
	{
		z1 = '+';
	}
	char z2 = '-';
	if (liczba.wartosc[0] != '-')
	{
		z2 = '+';
	}

	if (z1 == '-' && z2 != '-') // znaki są różne
	{
		return true;
	}

	if (z1 != '-' && z2 == '-') // znaki są różne
	{
		return false;
	}

	if (z1 != '-' && z2 != '-' && s1 < s2) // znaki są te same i s1 jest krótsze niż s2
	{
		return true;
	}
	else if ((z1 != '-' && z2 != '-' && s1 > s2))
	{
		return false;
	}
	else if (z1 == '-' && z2 == '-' && s1 < s2)
	{
		return false;
	}
	else if (z1 == '-' && z2 == '-' && s1 > s2)
	{
		return true;
	}

	// "1" < "0"
	for (int i = 0; i < s1; ++i)
	{
		if (wartosc[i] > liczba.wartosc[i])
		{
			return false;
		}

		if (wartosc[i] < liczba.wartosc[i])
		{
			return true;
		}

		if (i == s1 - 1)
		{
			return false;
		}
	}

	return true;
}

bool DuzaLiczba::operator<=(const DuzaLiczba& liczba) const
{
	return (*this < liczba || *this == liczba);
}

bool DuzaLiczba::operator>(const DuzaLiczba& liczba) const
{
	return !(*this <= liczba);
}

bool DuzaLiczba::operator>=(const DuzaLiczba& liczba) const
{
	return (*this > liczba || *this == liczba);
}

const char* DuzaLiczba::Wartosc() const
{
	return wartosc;
}

std::ostream& DuzaLiczba::print(std::ostream& out) const
{
	out << *this;
	return out;
}

char add(char a, char b, char* r)
{
	int x = charToDigit(a);
	int y = charToDigit(b);

	int z = (x + y) % 10; //9 + 9 = 18, 18 % 10 = 8
	int p = (x + y) / 10; // liczba w pamięci

	(*r) = digitToChar(p);
	return digitToChar(z);
}

char sub(char a, char b, char* r)
{
	int x = charToDigit(a);
	int y = charToDigit(b);

	int z = x - y;
	int p = 0;
	if (z < 0)
	{
		p = 1;
		z += 10;
	}

	(*r) = digitToChar(p);
	return digitToChar(z);
}

char mult(char a, char b, char* r)
{
	int x = charToDigit(a);
	int y = charToDigit(b);

	int z = (x * y) % 10;
	int p = (x * y) / 10; // liczba w pamięci

	(*r) = digitToChar(p);
	return digitToChar(z);
}

/*char div(std::string a, std::string b, std::string* r)
{
long long int x = std::strtoll(a.c_str(), NULL, 10); // string to int
long long int y = std::strtoll(b.c_str(), NULL, 10);

int z = x / y;
int p = x % y;

std::ostringstream ss;
ss << p;
*r = ss.str();
return digitToChar(z);//ss2.str();
}*/

char digitToChar(int a)
{
	return '0' + a;
}

int charToDigit(char a)
{
	return a - '0';
}

istream& operator>>(istream& in, DuzaLiczba& liczba)
{
	std::string napis;
	in >> napis;

	int n = napis.length();
	delete[] liczba.wartosc;
	liczba.wartosc = new char[n + 1];
	strcpy(liczba.wartosc, napis.c_str());

	return in;
}

ostream& operator<<(ostream& out, const DuzaLiczba& liczba)
{
	return out << liczba.wartosc;
} 