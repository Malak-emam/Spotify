
#include <filesystem>
#include <string>
#include "user.h"
namespace fs = std::filesystem;
//need to be changed

void user::create_fav_playlist(std::string fav_artists[10], int size) {

	std::string path = "D:\\SpotifyUIDesign_copy\\songs";
	std::fstream f;
	f.open(uniqueId+".txt", std::ios::app);
	for (int i = 0; i < size; i++)
	{		
		for (const auto& entry : fs::directory_iterator(path)) {
			std::string str{ entry.path().u8string()};

			int pos = str.find("songs");
			std::string song_file = str.substr(pos + 6);
			//std::cout << song_file << endl;

			pos = song_file.find(".");
			std::string no_ext = song_file.substr(0, pos);
			//std::cout << no_ext << endl;

			pos = no_ext.find("-");
			std::string artist_name = no_ext.substr(pos+1);
			std::string song_name = no_ext.substr(0, pos);

			if (fav_artists[i] == artist_name)
			{
				song s(no_ext);
				fav_playlist.setsong(s);
				f << s.getName() << "\n";
			}
		}
	}
}

user::user()
{
}

user::user(std::string fn, std::string ln, std::string pn)
{
	this->first_name = fn;
	this->last_name = ln;
	this->phone_number = pn;
	this->uniqueId = first_name + last_name + "000";
	this->password = this->uniqueId;
	song s("Before I Let Go-Beyonce");
	app_songs.add_song_to_playlist(s);
	song s2("Do I Wanna Know-Arctic Monkeys");
	app_songs.add_song_to_playlist(s2);
	song s3("Everything I Wanted-Billie Eilish");
	app_songs.add_song_to_playlist(s3);
	song s4("Ft Jay Z Jail-Kanye West");
	app_songs.add_song_to_playlist(s4);
	song s5("Hold On-Justin Bieber");
	app_songs.add_song_to_playlist(s5);
	song s6("King Of The Fall-The Weeknd");
	app_songs.add_song_to_playlist(s6);
	song s7("Lift Me Up-Rihanna");
	app_songs.add_song_to_playlist(s7);
	song s8("Medicine Olagist co-Harry Styles");
	app_songs.add_song_to_playlist(s8);
}

std::string user::getName()
{
	return this->first_name;
}

std::string user::get_user_id()
{
	return this->uniqueId;
}

std::queue<playlist> user::get_playlists() {
	return my_playlists;
}

playlist* user::get_playlist_by_name(std::string playlist_name)
{
	std::queue<playlist> p1;
	playlist* target = NULL;
	while (! my_playlists.empty()) {
		playlist temp = my_playlists.front();
		if (temp.get_name() == playlist_name) {
			target = &my_playlists.front();
		}
		p1.push(temp);
		my_playlists.pop();
	}
	my_playlists = p1;
	return target;
}
playlist user::get_app_songs()
{
	return app_songs;
}
void user::create_playlist(std::string name)
{
	playlist my_new_playlist(name);
	my_playlists.push(my_new_playlist);
}
void user::play_song(std::string song_name)
{
	song s(song_name);
	played_songs.push(s);
	app_songs.set_occ_of_song(song_name);

}
std::string user::recently_played_song() {
	if(!played_songs.empty())
		return played_songs.top().getName();
	return "No recently played songs";
}

std::stack<song> user::recently_played_songs()
{
	return played_songs;
}

std::stack<std::string> user::get_search_history()
{
	return searched_history;
}

song user::search_song(std::string NAME,std::fstream &allsongs_file) {
	allsongs_file.open("songs.txt", std::ios::in);
	std::string Line, Line_copy;
		while (1)
		{
			getline(allsongs_file, Line);
			Line_copy = Line;
			if (Line == "")
				break;
			Line.erase(Line.find("- "), strlen("- "));
			if (Line == NAME)
			{
				 song searched_song(NAME);
				 return searched_song;
			}
		}
}

SinglyLinkedList* user::search(std::string search_text)
{
	searched_history.push(search_text);
	SinglyLinkedList* songs = new SinglyLinkedList();
	for (const auto& i : std::filesystem::directory_iterator("D:\\SpotifyUIDesign_copy\\songs"))
	{

		std::string fileName = i.path().filename().string();
		if (fileName.find(search_text) != std::string::npos)
		{
			int pos = fileName.find(".");
			std::string no_ext = fileName.substr(0, pos);
			songs->insert_node(song(no_ext));
		}
	}
	return songs;
}

playlist user::get_fav_playlist()
{
	return this->fav_playlist;
}

void user::add_to_fav_playlist(song s)
{
	this->fav_playlist.add_song_to_playlist(s);
}

void user::load() {
	std::fstream f;
	f.open("playlists" + uniqueId + ".txt", std::ios::in);
	std::string Line;
	bool flag;
	while (1) {
		getline(f, Line);
		if (Line == "")
			break;
		playlist p(Line);
		flag = true;
		while (1) {
			getline(f, Line);
			if (Line == "-------------------------------------------")
				break;
			song s(Line);
			p.add_song_to_playlist(s);
		}
		my_playlists.push(p);
	}
	f.close();
}

void user::store() {
	std::fstream f;
	std::string filename = "playlists" + uniqueId + ".txt";
	remove(filename.c_str());
	f.open("playlists" + uniqueId + ".txt", std::ios::app);
	std::queue<playlist> Q = get_playlists();
	playlist p;
	while (!Q.empty()) {
		p = Q.front();
		f << p.get_name() << "\n";
		SinglyLinkedList p_songs = p.get_songs();
		SinglyLinkedListNode* temp_song = p_songs.getHead();
		while (temp_song) {
			f << temp_song->getData().getName() << "\n";
			temp_song = temp_song->getNext();
		}
		f << "-------------------------------------------" << "\n";
		Q.pop();
	}
}





