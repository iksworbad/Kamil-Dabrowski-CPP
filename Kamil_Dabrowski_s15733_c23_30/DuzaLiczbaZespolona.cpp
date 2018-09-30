#include "stdafx.h"
#include "DuzaLiczbaZespolona.h"

DuzaLiczbaZespolona::DuzaLiczbaZespolona() : Liczba()
{
	real = new DuzaLiczba;
	imagine = new DuzaLiczba;
}

DuzaLiczbaZespolona::DuzaLiczbaZespolona(int r, int im) : Liczba()
{
	real = new DuzaLiczba(r);
	imagine = new DuzaLiczba(im);
}

DuzaLiczbaZespolona::DuzaLiczbaZespolona(const char* r, const char* im) : Liczba()
{
	real = new DuzaLiczba(r);
	imagine = new DuzaLiczba(im);
}

DuzaLiczbaZespolona::DuzaLiczbaZespolona(const DuzaLiczbaZespolona& zespolona)
{
	real = new DuzaLiczba(*zespolona.real);
	imagine = new DuzaLiczba(*zespolona.imagine);
}

DuzaLiczbaZespolona::~DuzaLiczbaZespolona()
{
	delete real;
	delete imagine;
}

DuzaLiczbaZespolona& DuzaLiczbaZespolona::operator=(const DuzaLiczbaZespolona& zespolona)
{
	*real = *(zespolona.real);
	*imagine = *(zespolona.imagine);

	return *this;
}

DuzaLiczbaZespolona DuzaLiczbaZespolona::operator+(const DuzaLiczbaZespolona& zespolona) const
{
	DuzaLiczba re = *(this->real) + *(zespolona.real);
	DuzaLiczba im = *(this->imagine) + *(zespolona.imagine);

	return DuzaLiczbaZespolona(re.c_str(), im.c_str());
}

DuzaLiczbaZespolona DuzaLiczbaZespolona::operator-(const DuzaLiczbaZespolona& zespolona) const
{
	DuzaLiczba re = *(this->real) - *(zespolona.real);
	DuzaLiczba im = *(this->imagine) - *(zespolona.imagine);

	return DuzaLiczbaZespolona(re.c_str(), im.c_str());
}

DuzaLiczbaZespolona DuzaLiczbaZespolona::operator*(const DuzaLiczbaZespolona& zespolona) const
{
	DuzaLiczba re = *(this->real) * *(zespolona.real) - *(this->imagine) * *(zespolona.imagine);
	DuzaLiczba im = *(this->imagine) * *(zespolona.real) + *(this->real) * *(zespolona.imagine);

	return DuzaLiczbaZespolona(re.c_str(), im.c_str());
}

DuzaLiczbaZespolona DuzaLiczbaZespolona::operator/(const DuzaLiczbaZespolona& zespolona) const
{
	DuzaLiczba re = *(this->real) * *(zespolona.real) + *(this->imagine) * *(zespolona.imagine);
	DuzaLiczba im = *(this->imagine) * *(zespolona.real) - *(this->real) * *(zespolona.imagine);
	DuzaLiczba denominator = *(zespolona.real) * *(zespolona.real) + *(zespolona.imagine) * *(zespolona.imagine);

	re = re / denominator;
	im = im / denominator;

	return DuzaLiczbaZespolona(re.c_str(), im.c_str());
}

DuzaLiczbaZespolona&DuzaLiczbaZespolona::operator+=(const DuzaLiczbaZespolona& zespolona)
{
	*this = *this + zespolona;
	return *this;
}

DuzaLiczbaZespolona&DuzaLiczbaZespolona::operator-=(const DuzaLiczbaZespolona& zespolona)
{
	*this = *this - zespolona;
	return *this;
}

DuzaLiczbaZespolona&DuzaLiczbaZespolona::operator*=(const DuzaLiczbaZespolona& zespolona)
{
	*this = *this * zespolona;
	return *this;
}

DuzaLiczbaZespolona&DuzaLiczbaZespolona::operator/=(const DuzaLiczbaZespolona& zespolona)
{
	*this = *this / zespolona;
	return *this;
}

bool DuzaLiczbaZespolona::operator==(const DuzaLiczbaZespolona& zespolona) const
{
	return (*(this->real) == *(zespolona.real)) && (*(this->imagine) == *(zespolona.imagine));
}

bool DuzaLiczbaZespolona::operator!=(const DuzaLiczbaZespolona& zespolona) const
{
	return !(*this == zespolona);
}

bool DuzaLiczbaZespolona::operator<(const DuzaLiczbaZespolona& zespolona) const
{
	return this->modulusToPower2() < zespolona.modulusToPower2();
}

bool DuzaLiczbaZespolona::operator<=(const DuzaLiczbaZespolona& zespolona) const
{
	return this->modulusToPower2() <= zespolona.modulusToPower2();
}

bool DuzaLiczbaZespolona::operator>(const DuzaLiczbaZespolona& zespolona) const
{
	return this->modulusToPower2() > zespolona.modulusToPower2();
}

bool DuzaLiczbaZespolona::operator>=(const DuzaLiczbaZespolona& zespolona) const
{
	return this->modulusToPower2() >= zespolona.modulusToPower2();
}

DuzaLiczbaZespolona DuzaLiczbaZespolona::operator-() const
{
	DuzaLiczba re = *this->real;
	DuzaLiczba im = *this->imagine;
	if (*this->real != "0")
		re = -re;
	if (*this->imagine != "0")
		im = -im;

	return DuzaLiczbaZespolona(re.c_str(), im.c_str());
}

DuzaLiczba DuzaLiczbaZespolona::modulusToPower2() const
{
	return (*this->real)*(*this->real) + (*this->imagine)*(*this->imagine);
}

const char* DuzaLiczbaZespolona::Wartosc() const
{
	DuzaLiczbaZespolona tmp = *this;
	if (*(tmp.real) < "0")
	{
		(*tmp.real) = -(*tmp.real);
	}

	return tmp.real->Wartosc();
}

std::ostream& DuzaLiczbaZespolona::print(std::ostream& out) const
{
	out << *this;
	return out;
}

std::istream& operator>>(std::istream& in, DuzaLiczbaZespolona& zespolona)
{
	in >> *(zespolona.real) >> *(zespolona.imagine);
	return in;
}

std::ostream&operator<<(std::ostream& out, const DuzaLiczbaZespolona& zespolona)
{
	out << *(zespolona.real);
	if (*(zespolona.imagine) >= 0)
	{
		out << "+";
	}
	out << *(zespolona.imagine) << "i";
	return out;
}