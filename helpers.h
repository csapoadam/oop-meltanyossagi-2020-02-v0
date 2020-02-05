#pragma once

#include <string>

enum class Regularity {
	MONTHLY,
	DAILY
};

std::string regularityToString(Regularity r);

struct Person {
	std::string name;
	Person(std::string n) : name(n) {}
};