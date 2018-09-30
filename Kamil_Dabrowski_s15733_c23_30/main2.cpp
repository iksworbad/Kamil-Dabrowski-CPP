#include "stdafx.h"
#include "DuzaLiczba.h" 
#include "DuzaLiczbaZespolona.h" 
/*
using namespace std;
int main() {
	// konstruktor bezargumentowy inicjalizuje obiekt wartoœci¹ (0,0)
	DuzaLiczbaZespolona l1;
	// konstruktor z argumentem typu int inicjalizuje obiekt 
	// wartoœci¹ sta³o-liczbow¹ (172834,0)
	DuzaLiczbaZespolona l2(172834);
	// konstruktor z dwoma argumentami typu int inicjalizuje  
	// inicjalizuje obiekt wartoœci¹ (134,394)
	DuzaLiczbaZespolona l2a(134, 394);

	// konstruktor z argumentem typu char* inicjalizuje obiekt podan¹ 
	// wartoœci¹ (“1728390”)
	DuzaLiczbaZespolona l3("17290");

	// konstruktor z argumentem typu char* inicjalizuje obiekt 
	// podan¹ wartoœci¹ (17283,-420)
	DuzaLiczbaZespolona l3a("17283", "-420");

	// konstruktor kopiuj¹cy g³êboko
	DuzaLiczbaZespolona l4(l3);
	// konstruktor z argumentem typu char* inicjalizuje 
	DuzaLiczbaZespolona l5 = l4;
	DuzaLiczbaZespolona l6(-172834);

	DuzaLiczbaZespolona *l7 = new DuzaLiczbaZespolona("-172834555665554324678875494");

	// Wszystkie obiekty od l1 do l6 s¹ obiektami statycznymi, 
	// tzn. istniej¹ od pocz¹tku do koñca dzia³ania funkcji main 
	// natomiast obiekt wskazywany przez wskaŸnik l7 jest obiektem
	// dynamicznym, tzn. mo¿e byæ usuniêty przez wywo³anie operatora delete.
	// przedefiniowany operator >>
	cin >> l1;
	// przedefiniowany operator <<              
	cout << l1 <<endl << l2 << endl << l3 << endl << l4 << endl << l5 << endl << l6 << endl << *l7 << endl;
	cout << l2a << endl << l3a << endl;
	// usuniêcie obiektu wskazywanego przez l7
	delete l7;

	// przedefiniowany operator =
	l1 = l2;
	// przedefiniowane operatory +-* /  dzielenie ca³kowite            
	l1 = l1 + l2 - l3 * l4 / l5;
	// przedefiniowany operator += - zwiêkszenie sk³adowej rzeczywistej liczby l1 o 23
	l1 += 23;
	// przedefiniowany operator +=
	l1 += l4;
	// przedefiniowany operator -=
	l2 -= l3;
	// przedefiniowany operator *=
	l3 *= l4;

	// przedefiniowany operator ==
	if (l4 == "23424")
		// przedefiniowany operator /=  dzielenie ca³kowite        
		l4 /= l5;

	// przedefiniowany operator ==
	if (l4 == l5)
		// przedefiniowany operator /=  dzielenie ca³kowite          
		l4 /= l5;

	// przedefiniowany operator !=
	if (l5 != l4) {
		// przedefiniowany operator – zmiana wartoœci sk³adowych na przeciwne          
		l5 = -l5;
		cout << l5 << endl;
	}

	// przedefiniowany operator =
	l2 = "1221";
	// przedefiniowane operatory >=  <
	if (l2 >= 0 && l2 < "1223") {
		cout << "ok";
	}
	system("pause");
	return 0;
}
*/