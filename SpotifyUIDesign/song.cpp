#include "song.h"

song::song()
{
	this->name = " ";
	played_occurence = 0;
}


song::song(std::string name)
{
	this->name = name;
	played_occurence = 0;
}

void song::IncrementOccurrence()
{
	played_occurence++;
}

void song::setOccurrence(int num)
{
	played_occurence = num;
}

int song::get_occurrence()
{
	return played_occurence;
}

void song::setName(std::string Name)
{
	name = Name;
}

std::string song::getName()
{
	return name;
}
