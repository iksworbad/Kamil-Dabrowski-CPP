#pragma once
#ifndef LICZBA_H
#define LICZBA_H

#include <iostream>

class Liczba
{
	friend std::ostream& operator<<(std::ostream& out, const Liczba& liczba);
public:
	Liczba();
	virtual ~Liczba();
	virtual const char* Wartosc() const = 0;

protected:
	virtual std::ostream& print(std::ostream& out) const = 0;
};

std::ostream& operator<<(std::ostream& out, const Liczba& liczba);

#endif // LICZBA_H