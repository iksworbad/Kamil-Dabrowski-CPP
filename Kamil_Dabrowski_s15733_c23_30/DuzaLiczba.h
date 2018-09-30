#pragma once
#ifndef DUZALICZBA_H
#define DUZALICZBA_H

#include "Liczba.h"
#include <iostream>
#include <string>

char add(char a, char b, char* r);
char sub(char a, char b, char* r);
char mult(char a, char b, char* r);
char div(std::string a, std::string b, std::string* r);
char digitToChar(int a);
int charToDigit(char a);

class DuzaLiczba : public Liczba
{
	friend std::istream& operator>>(std::istream& in, DuzaLiczba& liczba);
	friend std::ostream& operator<<(std::ostream& out, const DuzaLiczba& liczba);

public:
	DuzaLiczba();
	DuzaLiczba(int a);
	DuzaLiczba(const char* a);
	DuzaLiczba(const DuzaLiczba& liczba);

	~DuzaLiczba();

	DuzaLiczba& operator=(const DuzaLiczba& liczba);
	DuzaLiczba operator+(const DuzaLiczba& liczba) const;
	DuzaLiczba operator-(const DuzaLiczba& liczba) const;
	DuzaLiczba operator*(const DuzaLiczba& liczba) const;
	DuzaLiczba operator/(const DuzaLiczba& liczba) const;

	DuzaLiczba& operator+=(const DuzaLiczba& liczba);
	DuzaLiczba& operator-=(const DuzaLiczba& liczba);
	DuzaLiczba& operator*=(const DuzaLiczba& liczba);
	DuzaLiczba& operator/=(const DuzaLiczba& liczba);

	DuzaLiczba operator!() const;
	DuzaLiczba operator-() const;

	bool operator==(const DuzaLiczba& liczba) const;
	bool operator!=(const DuzaLiczba& liczba) const;
	bool operator<(const DuzaLiczba& liczba) const;
	bool operator<=(const DuzaLiczba& liczba) const;
	bool operator>(const DuzaLiczba& liczba) const;
	bool operator>=(const DuzaLiczba& liczba) const;

	const char* c_str() const { return wartosc; }

	const char* Wartosc() const;

protected:
	std::ostream& print(std::ostream& out) const;

private:
	char* wartosc;
};

std::istream& operator>>(std::istream& in, DuzaLiczba& liczba);
std::ostream& operator<<(std::ostream& out, const DuzaLiczba& liczba);

#endif // DUZALICZBA_H

