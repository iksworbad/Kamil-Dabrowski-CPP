#include "stdafx.h"
#include "ListaDuzychLiczb.h"
#include "DuzaLiczba.h"

ListaDuzychLiczb::ListaDuzychLiczb()
{
	pierwszy = NULL;
	ostatni = NULL;
}

ListaDuzychLiczb::~ListaDuzychLiczb()
{
	usunWszystkieElementy();
}

void ListaDuzychLiczb::wstawNaPoczatek(Liczba* liczba)
{
	ElementyListy* element = new ElementyListy(liczba);

	if (ostatni == NULL)
	{
		ostatni = element;
	}

	element->nastepny = pierwszy;
	if (pierwszy != NULL)
	{
		pierwszy->poprzedni = element;
	}

	pierwszy = element;
}

void ListaDuzychLiczb::wstawNaKoniec(Liczba* liczba)
{
	ElementyListy* element = new ElementyListy(liczba);

	if (pierwszy == NULL)
	{
		pierwszy = element;
	}

	element->poprzedni = ostatni;
	if (ostatni != NULL)
	{
		ostatni->nastepny = element;
	}

	ostatni = element;
}

void ListaDuzychLiczb::wstawNaPozycje(Liczba* liczba, int p)
{
	if (p == 1)
	{
		wstawNaPoczatek(liczba);
	}
	else
	{
		ElementyListy* tmp = znajdz(p);
		if (!tmp)
		{
			wstawNaKoniec(liczba);
		}
		else
		{
			ElementyListy* element = new ElementyListy(liczba);
			element->nastepny = tmp;
			element->poprzedni = tmp->poprzedni;//strazlak -> oznacza, ze zamiast dostac sie do obiektu na ktory wskazuje wskaznik(w tym wypadku TMP) dostajemy sie do pola tego obiektu
			tmp->poprzedni->nastepny = element;
			tmp->poprzedni = element;
		}
	}
}

void ListaDuzychLiczb::usunPierwszyElement()
{
	ElementyListy* tmp = pierwszy;
	pierwszy = pierwszy->nastepny;
	pierwszy->poprzedni = NULL;
	delete tmp;
}

void ListaDuzychLiczb::usunOstatniElement()
{
	ElementyListy* tmp = ostatni;
	ostatni = ostatni->poprzedni;
	ostatni->nastepny = NULL;
	delete tmp;
}

void ListaDuzychLiczb::usunPozycje(int p)
{
	if (p == 1)
	{
		usunPierwszyElement();
	}
	else
	{
		ElementyListy* tmp = znajdz(p);
		if (tmp != NULL)
		{
			if (tmp == ostatni)
			{
				usunOstatniElement();
			}
			else
			{
				tmp->poprzedni->nastepny = tmp->nastepny;
				tmp->nastepny->poprzedni = tmp->poprzedni;
				delete tmp;
			}
		}
	}
}

void ListaDuzychLiczb::usunWszystkieElementy()
{
	ElementyListy* tmp = pierwszy;
	while (tmp != NULL)
	{
		ElementyListy* tmp2 = tmp;
		tmp = tmp->nastepny;
		delete tmp2;
	}

	pierwszy = NULL;
	ostatni = NULL;
}

void ListaDuzychLiczb::sortuj()
{
	int s = ileElementow();
	for (int i = 1; i <= s; i++)
	{
		for (int j = 1; j <= s - 1; j++)
		{
			ElementyListy* a = znajdz(j);
			ElementyListy* b = znajdz(j + 1);

			DuzaLiczba d1 = a->liczba->Wartosc();
			DuzaLiczba d2 = b->liczba->Wartosc();

			if (d1 > d2)
			{
				Liczba* tmp = a->liczba;
				a->liczba = b->liczba;
				b->liczba = tmp;
			}
		}
	}
}

int ListaDuzychLiczb::ileElementow() const
{
	int i = 0;
	for (ElementyListy* tmp = pierwszy; tmp != NULL; tmp = tmp->nastepny)
	{
		i++;
	}

	return i;
}

ElementyListy* ListaDuzychLiczb::znajdz(int p) const
{
	ElementyListy* tmp = pierwszy;
	for (int i = 1; i != p && tmp != NULL; ++i)
		tmp = tmp->nastepny;

	return tmp;
}

std::ostream& operator<<(std::ostream& out, const ListaDuzychLiczb& lista)
{
	if (!lista.pierwszy)
	{
		out << "NULL" << std::endl;
		return out;
	}

	for (ElementyListy* tmp = lista.pierwszy; tmp != NULL; tmp = tmp->nastepny)
	{
		out << *(tmp->liczba) << std::endl;
	}

	return out;
}