#include <iostream>
#include "flota.h"
#include "let.h"
#include "arhiva.h"
#include <string>
using namespace std;

int main() {
	
	Pilot p1("Petar",120);
	Pilot p2("Pavle",50);
	Pilot p3("Luka", 150);
	Pilot p4("Stefan", 200);

	Avion a1("Avion1", 500);
	Avion a2("Avion2", 1000);
	Avion a3("Avion3", 700);
	Avion a4("Avion4", 2000);
	Avion a5("Avion5", 1500);

	a1.postaviKap(p2);
	a1.postaviKop(p1);
	a2.postaviKap(p3);
	a3.postaviKap(p4);

	Flota F("Flota");
	Flota *F2;

	F.dodaj(&a1);
	F.dodaj(&a2);
	F.dodaj(&a3);
	F.dodaj(&a4);
	F.dodaj(&a5);

	Let l1("Beograd","Barselona", &a1);
	Let l3("Novi Sad", "Madrid", &a3);
	Let l2("Beograd", "Pariz", &a2);
	Let l4("Brcko", "Barselona", &a4);
	Let l5("Beograd", "Barselona", &a5);

	Arhiva* A = new Arhiva;
	Arhiva* BG;
	Arhiva* BAR;
	Arhiva* BGBAR;

	A->dodaj(&l1);
	A->dodaj(&l3);
	A->dodaj(&l2);
	A->dodaj(&l4);
	A->dodaj(&l5);

	//A->pisiA();
	
	BG = A->dohvLetovePOL("Beograd");
	BAR = A->dohvLetoveDOL("Barselona");
	BGBAR = A->dohvLetovePOLDOL("Beograd", "Barselona");
	BG->pisiA();
	BAR->pisiA();
	BGBAR->pisiA();

	BG->brisi_arhiv();
	BAR->brisi_arhiv();
	BGBAR->brisi_arhiv();

	

	
	

}