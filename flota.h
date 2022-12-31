#ifndef _flota_h_
#define _flota_h_
#include <iostream>
#include "avion.h"
#include <string>
using namespace std;

class Flota {

	string naziv;

	struct Elem {
		Avion* avion;
		Elem* sled;
		Elem(Avion* a, Elem* s = nullptr) :avion(a), sled(s) {};
	};
	Elem* prvi = nullptr;

public:
	Flota() = default;
	Flota(const Flota& f);
	Flota(Flota&& f);
	Flota(string naz) : naziv(naz) {};
	~Flota();

	void dodaj(Avion* a);

	int ukupanBrAv();
	int ukupanBrPutnika();
	Avion *dohvAvMax() const;

	void ukloni(string naz) {
		for (Elem* tek = prvi; tek; tek = tek->sled) {
			Elem* sled = tek->sled;
			if (tek->avion->dohvNaziv() == naz) {
				tek->avion = sled->avion;
				tek->sled = sled->sled;
				sled = nullptr;
				delete sled;
			}
		}
	}

	void pisiF() const;

};
#endif