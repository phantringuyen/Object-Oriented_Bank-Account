#include "Card.h"

Card::Card()
{
	number = 0;
	day = "\0";
}

Card::~Card()
{
	number = 0;
	day = "\0";
}
Card::Card(long _number, string _day)
{
	number = _number;
	day = _day;
}