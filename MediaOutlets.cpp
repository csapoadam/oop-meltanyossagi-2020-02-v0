////////////////////////
// CSAK EZ A FAJL TITKOS - EZT KELL MEGIRNI!! (50 kodsorbol megvan)

#include "stdafx.h"

#include "MediaOutlets.h"
#include <string>
#include <iostream>

MediaOutlet::MediaOutlet(std::string name) : name(name) {
}

Newspaper::Newspaper(std::string name, Person* editor, Regularity r) :
	MediaOutlet(name),
	editorInChief(editor),
	howRegular(r),
	numIssuesPublished(0) {}

void Newspaper::introduce() const {
	std::cout << "Newspaper called " << name << " (editor in chief: " << editorInChief->name;
	std::cout << ") appears on a " << regularityToString(howRegular) << " basis";
	std::cout << " and has been published " << numIssuesPublished << " times" << std::endl;
}

void Newspaper::publish() { ++numIssuesPublished; }

void Newspaper::subscribe(Person* p) { subscribers.push_back(p); }

void Newspaper::printSubscribers() const {
	std::cout << subscribers.size() << " people subscribed to newspaper called " << name << ":" << std::endl;
	for (Person* p : subscribers) {
		std::cout << "  --> " << p->name << std::endl;
	}
}

TVShow::TVShow(std::string name, Person* host) : MediaOutlet(name), host(host), numTimesAired(0) {}

void TVShow::air() { ++numTimesAired; }

void TVShow::introduce() const {
	std::cout << "TV show called " << name << " is hosted by " << host->name;
	std::cout << " and has aired " << numTimesAired << " times" << std::endl;
}

bool isMediaOutletANewspaper(MediaOutlet* mo) {
	return dynamic_cast<Newspaper*>(mo) != nullptr;
}

Newspaper* convertMediaOutletToNewspaper(MediaOutlet* mo) {
	return dynamic_cast<Newspaper*>(mo);
}

