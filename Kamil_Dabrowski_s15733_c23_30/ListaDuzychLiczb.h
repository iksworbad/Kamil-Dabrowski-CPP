#pragma once
#ifndef LISTADUZYCHLICZB_H
#define LISTADUZYCHLICZB_H

#include "Liczba.h"
#include <cstdlib>
#include <iostream>

class ListaDuzychLiczb;

class ElementyListy
{
	friend class ListaDuzychLiczb;
	friend std::ostream& operator<<(std::ostream& out, const ListaDuzychLiczb& lista);
private:
	ElementyListy(Liczba* zm) { liczba = zm; nastepny = NULL; poprzedni = NULL; }

	Liczba* liczba;
	ElementyListy* nastepny;
	ElementyListy* poprzedni;
};

class ListaDuzychLiczb
{
	friend std::ostream& operator<<(std::ostream& out, const ListaDuzychLiczb& lista);
public:
	ListaDuzychLiczb();
	~ListaDuzychLiczb();

	void wstawNaPoczatek(Liczba* liczba);
	void wstawNaKoniec(Liczba* liczba);
	void wstawNaPozycje(Liczba* liczba, int p);
	void usunPierwszyElement();
	void usunOstatniElement();
	void usunPozycje(int p);
	void usunWszystkieElementy();

	void sortuj();
	int ileElementow() const;
	ElementyListy* znajdz(int p) const;

private:
	ElementyListy * pierwszy;
	ElementyListy* ostatni;
};

std::ostream& operator<<(std::ostream& out, const ListaDuzychLiczb& lista);

#endif // LISTADUZYCHLICZB_H
