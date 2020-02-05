#pragma once

#include "helpers.h"
#include <vector>

class MediaOutlet {
protected:
	std::string name;
public:
	MediaOutlet(std::string name);
	virtual void introduce() const = 0;
};

class Newspaper : public MediaOutlet {
	Regularity howRegular;
	Person* editorInChief;
	int numIssuesPublished;
	std::vector<Person*> subscribers;
public:
	Newspaper(std::string name, Person* editor, Regularity r);
	void publish();
	void introduce() const override;
	void subscribe(Person* p);
	void printSubscribers() const;
};

class TVShow : public MediaOutlet {
	Person* host;
	int numTimesAired;
public:
	TVShow(std::string name, Person* host);
	void air();
	void introduce() const override;
};
