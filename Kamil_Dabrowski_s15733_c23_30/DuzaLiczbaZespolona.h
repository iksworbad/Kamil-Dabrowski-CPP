#pragma once
#ifndef DUZALICZBAZESPOLONA_H
#define DUZALICZBAZESPOLONA_H

#include "Liczba.h"
#include "DuzaLiczba.h"
#include <iostream>
#include <string>

class DuzaLiczbaZespolona : public Liczba
{
	friend std::istream& operator>>(std::istream& in, DuzaLiczbaZespolona& zespolona);
	friend std::ostream& operator<<(std::ostream& out, const DuzaLiczbaZespolona& zespolona);

public:
	DuzaLiczbaZespolona();
	DuzaLiczbaZespolona(int r, int im = 0);
	DuzaLiczbaZespolona(const char* r, const char* im = "0");
	DuzaLiczbaZespolona(const DuzaLiczbaZespolona& zespolona);
	~DuzaLiczbaZespolona();

	DuzaLiczbaZespolona& operator=(const DuzaLiczbaZespolona& zespolona);

	DuzaLiczbaZespolona operator+(const DuzaLiczbaZespolona& zespolona) const;
	DuzaLiczbaZespolona operator-(const DuzaLiczbaZespolona& zespolona) const;
	DuzaLiczbaZespolona operator*(const DuzaLiczbaZespolona& zespolona) const;
	DuzaLiczbaZespolona operator/(const DuzaLiczbaZespolona& zespolona) const;

	DuzaLiczbaZespolona& operator+=(const DuzaLiczbaZespolona& zespolona);
	DuzaLiczbaZespolona& operator-=(const DuzaLiczbaZespolona& zespolona);
	DuzaLiczbaZespolona& operator*=(const DuzaLiczbaZespolona& zespolona);
	DuzaLiczbaZespolona& operator/=(const DuzaLiczbaZespolona& zespolona);

	bool operator==(const DuzaLiczbaZespolona& zespolona) const;
	bool operator!=(const DuzaLiczbaZespolona& zespolona) const;
	bool operator<(const DuzaLiczbaZespolona& zespolona) const;
	bool operator<=(const DuzaLiczbaZespolona& zespolona) const;
	bool operator>(const DuzaLiczbaZespolona& zespolona) const;
	bool operator>=(const DuzaLiczbaZespolona& zespolona) const;

	DuzaLiczbaZespolona operator-() const;

	DuzaLiczba modulusToPower2() const;

	const char* Wartosc() const;

protected:
	std::ostream& print(std::ostream& out) const;

private:
	DuzaLiczba * real;
	DuzaLiczba* imagine;
};

std::istream& operator>>(std::istream& in, DuzaLiczbaZespolona& zespolona);
std::ostream& operator<<(std::ostream& out, const DuzaLiczbaZespolona& zespolona);

#endif // DUZALICZBAZESPOLONA_H
