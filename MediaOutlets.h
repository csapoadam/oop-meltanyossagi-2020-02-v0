#pragma once

#include "helpers.h"
#include <vector>

class MediaOutlet {
protected:
	std::string name;
public:
	MediaOutlet(std::string name);
	virtual void introduce() = 0;
};

class Newspaper : public MediaOutlet {
	Regularity howRegular;
	Person* editorInChief;
	int numIssuesPublished;
	std::vector<Person*> subscribers;
public:
	Newspaper(std::string name, Person* editor, Regularity r);
	void publish();
	void introduce();
	void subscribe(Person* p);
	void printSubscribers();
};

class TVShow : public MediaOutlet {
	Person* host;
	int numTimesAired;
public:
	TVShow(std::string name, Person* host);
	void air();
	void introduce();
};
