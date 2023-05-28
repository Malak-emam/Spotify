
#include<iostream>
#include "playlist.h"
//using namespace std;

playlist::playlist()
{
	this->name = " ";
	songs = SinglyLinkedList();
}
playlist::playlist(std::string name)
{
	this->name = name;
}
std::string playlist::get_name() {
	return name;
}
void playlist::setsong(song s) {
	songs.insert_node(s);
}
void playlist::setName(std::string playlist_name)
{
	name = playlist_name;
}
void playlist::add_song_to_playlist(song s)
{
	songs.insert_node(s);
}

void playlist::delete_song_from_playlist(int position)
{
	songs.deleteN(position);
}

int playlist::get_position_of_song(std::string name)
{
	SinglyLinkedListNode* temp = songs.getHead();
	int pos = 0;
	while (temp) {
		pos += 1;
		if (temp->getData().getName() == name) {
			return pos;
		}
		temp = temp->getNext();
	}
	return -1;
}

int playlist::number_of_songs_in_playlist()
{
	return songs.getCount();
}

void playlist::display_playlist() {
	songs.displayAll();
}


SinglyLinkedList* playlist::Shuffle_playist(int type) {
	SinglyLinkedListNode* temp=songs.getHead();
	std::string songName="";
	int value = 0;
	song l;
	btree b;
	while (temp != NULL) {
		l = temp->getData(); 
		songName = l.getName();
		for (int i = 0; i < songName.length(); i++) 
		{
			if (songName[i] == ' ' ) {
				continue;
			}
		    value += songName[i];
		} 
		b.insert(value,l);
		temp = temp->getNext();
		songName = "";
		value = 0;
	}
	if (type == 1) {
		return b.inorder_print();
	}
	else if (type == 2) {
		return b.preorder_print();
	}
	else if (type == 3) {
		return b.postorder_print();
	}
}

void playlist::sort_number_of_plays() {
	songs.sortLinkedList();
}

void playlist::reverse_sort_number_of_plays() {
	songs.reverseSort();
}

SinglyLinkedList playlist::get_songs()
{
	return songs;
}

void playlist::set_occ_of_song(std::string song_name)
{
	SinglyLinkedListNode* temp = this->get_songs().getHead();
	
	while (temp) {
		if (temp->getData().getName() == song_name) {
			song s(song_name);
			s.setOccurrence(temp->getData().get_occurrence() + 1);
			temp->setData(s);
			return;
		}
		temp = temp->getNext();
	}
}








