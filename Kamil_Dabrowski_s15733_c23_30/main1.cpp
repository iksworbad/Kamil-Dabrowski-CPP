// Kamil_Dabrowski_s15733_c23_30.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "DuzaLiczba.h" 

using namespace std;
/*
int main() {
	// konstruktor bezargumentowy inicjalizuje obiekt wartością 0
	DuzaLiczba l1;
	// konstruktor z argumentem typu int inicjalizuje obiekt wartością stało-liczbową
	DuzaLiczba l2(99999999999);
	// konstruktor z argumentem typu char* inicjalizuje obiekt podaną wartością
	DuzaLiczba l3("99999999999");
	// konstruktor kopiujący głęboko
	DuzaLiczba l4(l3);
	// też konstruktor kopiujący głęboko
	DuzaLiczba l5 = l4;
	DuzaLiczba l6(-987654);

	DuzaLiczba *l7 = new DuzaLiczba(" - 99999999999");

	// Wszystkie obiekty od l1 do l6 są obiektami statycznymi, 
	// tzn. istnieją od początku do końca działania funkcji main 
	// natomiast obiekt wskazywany przez wskaźnik l7 jest 
	// obiektem dynamicznym, tzn. może być usunięty przez wywołanie 
	// operatora delete.


	// przedefiniowany operator >> 
	cin >> l1;
	// przedefiniowany operator <<
	cout << l1 <<endl << l2 << endl << l3 << endl << l4 << endl << l5 << endl << l6 << endl << *l7 << endl;

	// usunięcie obiektu wskazywanego przez l7
	delete l7;
	
	// przedefiniowany operator =
	l1 = l2;
	l5 = "9344455544555554345";
	// przedefiniowane operatory +-* / dzielenie całkowite
	l1 = l1 + l2 - l3 * l4 / l5; 
	// przedefiniowany operator +=
	l1 += 23;
	// przedefiniowany operator += 
	l1 += l4;
	// przedefiniowany operator -=
	l2 -= l3;
	// przedefiniowany operator *=
	l3 *= l4;

	// przedefiniowany operator ==
	if (l4 == "23424")
		// przedefiniowany operator /= dzielenie całkowite
		l4 /= l5;

	// przedefiniowany operator !=
	if (l5 != l4) {
		// przedefiniowany jednoargumentowy operator -
		l5 = -l5;
		cout << l5 << endl;
	}

	// przedefiniowany operator =
	l2 = "456";

	DuzaLiczba silnia = 0;
	// przedefiniowane operatory >= <
	if (l2 >= 0 && l2 < "1223111111111111111111111111111111111111")
	{

		// przedefiniowany operator !
		silnia = !l2;
		cout <<"Wynik silni: "<< silnia << endl;
	}
	system("pause");
	return 0;
}
*/