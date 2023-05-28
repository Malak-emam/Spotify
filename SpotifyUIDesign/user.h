#pragma once
#include <iostream>
#include <queue>
#include <list>
#include <stack>
#include<fstream>
#include "playlist.h"
//using namespace std;


class user
{
	std::string uniqueId;
	std::string password;
	std::string first_name;
	std::string last_name;
	std::string phone_number;
	std::queue<playlist> my_playlists;
	playlist fav_playlist;
	std::stack<song> played_songs;
	std::stack<std::string> searched_history;
	playlist app_songs;

public:
	user();
	user(std::string first_name, std::string last_name, std::string phone_number);
	std::string getName();
	std::queue<playlist> get_playlists();
	std::string get_user_id();
	void create_fav_playlist(std::string fav_artists[10], int size);
	void create_playlist(std::string name);
	void play_song(std::string song_name);
	std::string recently_played_song();
	std::stack<song> recently_played_songs();
	std::stack<std::string> get_search_history();
	song search_song(std::string NAME, std::fstream& allsongs_file);
	SinglyLinkedList* search(std::string search_text);
	playlist get_fav_playlist();
	void add_to_fav_playlist(song s);
	void load();
	void store();
	playlist* get_playlist_by_name(std::string playlist_name);
	playlist get_app_songs();
	//void delete_playlist(playlist l);
	// 
	// 
	// // to be implemented
	// user load_user(ffstream file);
	// void store_user();
};

