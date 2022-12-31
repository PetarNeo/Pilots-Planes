#include <iostream>
#include "flota.h"

Flota::Flota(const Flota& f) {

	naziv = f.naziv;
	Elem* tek = f.prvi;
	Elem* novi, * posl = nullptr;
	while (tek) {
		novi = new Elem(tek->avion);
		if (!prvi) prvi = novi;
		else posl->sled = novi;
		posl = novi;
		tek = tek->sled;
	}
}

Flota::Flota(Flota&& f) {
	prvi = f.prvi;
	f.prvi = nullptr;
}

Flota::~Flota() {
	Elem* tek = prvi,*stari;
	while (tek) {
		stari = tek;
		tek = tek->sled;
		delete stari;
	}
}

int Flota::ukupanBrAv() {
	Elem* tek = prvi;
	int brA = 0;
	while (tek) {
		brA += 1;
		tek = tek->sled;
	}
	return brA;
}

int Flota::ukupanBrPutnika() {
	Elem* tek = prvi;
	int br = 0;
	while (tek)
	{
		br += tek->avion->dohvMax();
		tek = tek->sled;
	}
	return br;
}

void Flota::dodaj(Avion* a) {
	prvi = new Elem(a, prvi);
}

Avion* Flota::dohvAvMax()const {
	for (Elem* tek = prvi; tek ; tek = tek->sled) {
		for (Elem* sled = tek->sled; sled; sled = sled->sled) {
			if (tek->avion->dohvMax() < sled->avion->dohvMax()) {
				Avion* pom = tek->avion;
				tek->avion = sled->avion;
				sled->avion = pom;
			}
		}
	}
	return prvi->avion;
}

void Flota::pisiF()const {
	cout << naziv << endl;
	Elem* tek = prvi;
	while (tek) {
		cout << tek->avion->dohvNaziv(); cout << endl;
		tek = tek->sled;
	}
}