#pragma once


#include"btree.h"


class playlist
{
	std::string name;
    SinglyLinkedList songs;

public:
	playlist();
	playlist(std::string name);
	std::string get_name();
	void setsong(song s);
	void setName(std::string playlist_name);
	void add_song_to_playlist(song s);
	void delete_song_from_playlist(int position);
	int get_position_of_song(std::string name);
	int number_of_songs_in_playlist();
	void display_playlist();
	SinglyLinkedList* Shuffle_playist(int type);
	void reverse_sort_number_of_plays();
	void sort_number_of_plays();
	SinglyLinkedList get_songs();
	void set_occ_of_song(std::string song_name);

};

