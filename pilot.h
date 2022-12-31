#ifndef _pilot_h_
#define _pilot_h_
#include <iostream>
#include <string>
using namespace std;


class Pilot {

	string ime;
	int sati;
	bool leti;

public:

	Pilot() = default;
	Pilot(const Pilot& p) = delete;
	Pilot(string i, int s, bool l = false) : ime(i), sati(s), leti(l) {};

	string dohvIme() const { return ime; }
	int dohvSate() const { return sati; }
	bool dohvLet() const { return leti; }

	void povecajSate(int sat) {sati += sat; }
	bool let() {
		if (leti == true) return leti = false;
		else return leti = true;
	}

	void pisiP()const;

};
#endif