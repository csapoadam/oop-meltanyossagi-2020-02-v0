// Meltanyossagi-2020-feb.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

#include "MediaOutlets.h"

// Feladat: a MediaOutlets.cpp fajlban valositson meg minden metodust es fuggvenyt, ami kell a main fv fordulasahoz es helyes futasashoz.

// csak deklaraciok - definialni is kell oket a MediaOutlets.cpp file-ban
bool isMediaOutletANewspaper(MediaOutlet* mo);
Newspaper* convertMediaOutletToNewspaper(MediaOutlet* mo);

// Elvart kimenet:
// Newspaper called Erdekfeszito Napilap (editor in chief: Ujsagiro Ubul) appears on a daily basis and has been published 2 times
// 2 people subscribed to newspaper called Erdekfeszito Napilap :
//   --> Pirinyo Panni
//   --> Nagy Nandor
// Newspaper called Ritka Havilap(editor in chief : Riporter Reka) appears on a monthly basis and has been published 1 times
// 1 people subscribed to newspaper called Ritka Havilap :
//   --> Orosz Olga
// TV show called Daily news is hosted by Hajdu Hedvig and has aired 1 times
// TV show called Daily comedy is hosted by Vak Vendel and has aired 2 times

int main()
{
	Person host1("Hajdu Hedvig"); // Person osztaly mar definialva van a helpers.h file-ban
	Person host2("Vak Vendel"); // ezert itt nincs teendo
	Person editor1("Ujsagiro Ubul");
	Person editor2("Riporter Reka");
	Person akarki1("Pirinyo Panni");
	Person akarki2("Nagy Nandor");
	Person akarki3("Orosz Olga");

	std::vector<MediaOutlet*> mediaOutlets;

	Newspaper newspaper1("Erdekfeszito Napilap", &editor1, Regularity::DAILY); // Newspaper konstruktorat definialni kell a MediaOutlets.cpp file-ban
	Newspaper newspaper2("Ritka Havilap", &editor2, Regularity::MONTHLY);
	TVShow show1("Daily news", &host1); // TVShow konstruktorat definialni kell a MediaOutlets.cpp file-ban
	TVShow show2("Daily comedy", &host2);

	newspaper1.publish(); // Newspaper publish() metodusat definialni kell a MediaOutlets.cpp file-ban - ez novel egy szamlalot az osztalyban
	newspaper1.publish();
	newspaper2.publish();
	show1.air(); // TVShow air() metodusat definialni kell a MediaOutlets.cpp file-ban - ez novel egy szamlalot az osztalyban
	show2.air();
	show2.air();

	newspaper1.subscribe(&akarki1); // subscribe() metodust definialni kell a MediaOutlets.cpp file-ban
	newspaper1.subscribe(&akarki2);
	newspaper2.subscribe(&akarki3);

	mediaOutlets.push_back(&newspaper1);
	mediaOutlets.push_back(&newspaper2);
	mediaOutlets.push_back(&show1);
	mediaOutlets.push_back(&show2);

	for (MediaOutlet* mo : mediaOutlets) {
		mo->introduce(); // introduce() metodust definialni kell a MediaOutlets.cpp file-ban
		if (isMediaOutletANewspaper(mo)) { // errol meg a kovetkezo sorrol is gondoskodni kell
			convertMediaOutletToNewspaper(mo)->printSubscribers();
		}
	}

	std::cin.get();
    return 0;
}

