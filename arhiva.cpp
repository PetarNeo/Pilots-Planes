#include "arhiva.h"

Arhiva::Arhiva(const Arhiva& ar) {
	ElemArh* tek = ar.prvi;
	ElemArh* novi = nullptr, * posl = nullptr;
	while (tek) {
		novi = new ElemArh(tek->L);
		if (!prvi) prvi = novi;
		else posl->sled = novi;
		posl = novi;
		tek = tek->sled;
	}
}
Arhiva::Arhiva(Arhiva&& ar) {
	prvi = ar.prvi;
	ar.prvi = nullptr;
}
Arhiva::~Arhiva() {
	while (prvi) {
		ElemArh* stari = prvi;
		prvi = prvi->sled;
		delete stari;
	}
}