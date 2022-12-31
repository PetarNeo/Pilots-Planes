#ifndef _let_h_
#define _let_h_
#include <iostream>
#include <string>
#include "avion.h"
using namespace std;

class Let {

	string polaziste, dolaziste;
	int identifikator = 0;
	Avion* avion;

public:
	static int br;
	
	Let(string p, string d, Avion* a) :polaziste(p), dolaziste(d), avion(a) { identifikator = ++br; };
	
	string dohvPolaz() const { return polaziste; }
	string dohvDolaz() const { return dolaziste; }
	int dohvIden() { return identifikator; }
	Avion* dohvAvion() const { return avion; }

	void pisiL() const {cout << "LET-" << polaziste << ":" << dolaziste;}

};


#endif