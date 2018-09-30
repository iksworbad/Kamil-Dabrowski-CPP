#include "stdafx.h"
#include "Liczba.h"

Liczba::Liczba()
{

}

Liczba::~Liczba()
{

}

std::ostream& operator<<(std::ostream& out, const Liczba& liczba)
{
	return liczba.print(out);
}