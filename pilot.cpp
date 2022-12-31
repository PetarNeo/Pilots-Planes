#include "pilot.h"

//bool Pilot::letenje[] = { "N","L" };

void Pilot::pisiP()const {
	cout << "(" << sati << ")-";
	if (leti == false) cout << "N";
	else cout << "L";
}