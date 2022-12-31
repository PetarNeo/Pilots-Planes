#ifndef _avion_h_
#define _avion_h_
#include <iostream>
#include "pilot.h"
#include <string>
using namespace std;

class Avion {

	string naziv;
	Pilot k, ko;
	int max;
	

public:
	Avion() = default;
	Avion(const Avion&) = delete;
	Avion(string naz, int m) : naziv(naz), max(m) {};

	string dohvNaziv() const { return naziv; }
	string dohvKap() const { return k.dohvIme(); }
	string dohvKop() const { return ko.dohvIme(); }
	int dohvMax() const { return max; }

	bool postaviKap(Pilot& p) {
		if (p.dohvSate() < 100) return false;
		else k = p;
		p.let();
		return true;
	}
	void postaviKop(Pilot& p) { ko = p; }

	void pisiA() const {
		cout << "AVION:" << naziv << " - " << max;
	}

};

#endif