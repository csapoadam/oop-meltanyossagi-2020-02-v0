#include "stdafx.h"
#include "helpers.h"

std::string regularityToString(Regularity r) {
	if (r == Regularity::MONTHLY) { return "monthly"; }
	if (r == Regularity::DAILY) { return "daily"; }
}
