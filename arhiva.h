#ifndef _arhiva_h_
#define _arhiva_h_
#include <iostream>
#include "let.h"
using namespace std;

class Arhiva {

	struct ElemArh {

		Let* L;
		ElemArh* sled;
		ElemArh(Let* l, ElemArh* s = nullptr) :L(l), sled(s) {};
	};
	ElemArh* prvi = nullptr;

public:

	Arhiva(ElemArh* prvi = nullptr) {};
	Arhiva(const Arhiva& ar);
	Arhiva(Arhiva&& ar);
	~Arhiva();

	void dodaj(Let* l) {
		prvi = new ElemArh(l, prvi);
	}

	void pisiA() const {
		cout << "ARHIVA" << endl;
		for (ElemArh* tek = prvi; tek; tek = tek->sled) {
			tek->L->pisiL();
			cout << endl;
		}
	}

	Arhiva* dohvLetovePOL(string pol) {
		Arhiva* A = new Arhiva;
		for (ElemArh* tek = prvi; tek; tek = tek->sled) {
			if (tek->L->dohvPolaz() == pol) {
				A->dodaj(tek->L);
			}
		}
		return A;
	}
	Arhiva* dohvLetoveDOL(string dol) {
		Arhiva* A = new Arhiva;
		for (ElemArh* tek = prvi; tek; tek = tek->sled) {
			if (tek->L->dohvDolaz() == dol) {
				A->dodaj(tek->L);
			}
		}
		return A;
	}
	Arhiva* dohvLetovePOLDOL(string pol, string dol) {
		Arhiva* A = new Arhiva;
		for (ElemArh* tek = prvi; tek; tek = tek->sled) {
			if (tek->L->dohvPolaz() == pol && tek->L->dohvDolaz() == dol) {
				A->dodaj(tek->L);
			}
		}
		return A;
	}
	void brisi_arhiv() {
		while (prvi) {
			ElemArh* stari = prvi;
			prvi = prvi->sled;
			delete stari;
		}
	}

};

#endif