#include "stdafx.h"
#include "DuzaLiczbaZespolona.h"
#include "DuzaLiczba.h" 
#include "ListaDuzychLiczb.h"

using namespace std;


int main() {

	ListaDuzychLiczb *lista = new ListaDuzychLiczb();

	lista->wstawNaPoczatek(new DuzaLiczba("9129081391"));
	lista->wstawNaPoczatek(new DuzaLiczbaZespolona(12908, 1391));
	lista->wstawNaKoniec(new DuzaLiczba("81391"));
	lista->wstawNaKoniec(new DuzaLiczbaZespolona(12908, 1391));
	for (int i = 0; i < 15; i++) {
		lista->wstawNaPozycje(new DuzaLiczba(rand() * 9283), 1);
		lista->wstawNaPozycje(new DuzaLiczbaZespolona(rand() * 9293, rand() * 92983), 1);
	}

	cout << *lista << endl<<endl;

	lista->sortuj();

	cout << *lista << endl << endl;

	lista->usunPierwszyElement();
	cout << *lista << endl << endl;
	lista->usunOstatniElement();
	cout << *lista << endl << endl;
	lista->usunPozycje(3);
	cout << *lista << endl << endl;
	lista->usunWszystkieElementy();
	cout << *lista << endl << endl;

	delete lista;
	
	system("pause");
	return 0;
}