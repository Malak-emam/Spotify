#ifndef song_H
#define song_H

#include<iostream>
#include <string>
#include <list>

//using namespace std;

class song
{
	std::string name;
	int played_occurence;

public:
	song();
	song(std::string name);
	void IncrementOccurrence();
	void setOccurrence(int num);
	int get_occurrence();
	void setName(std::string Name);
	std::string getName();
	bool operator == (const song& s) const { return name == s.name && played_occurence == s.played_occurence; }
	bool operator != (const song& s) const { return !operator==(s); }
};

#endif


