#pragma once
//#include "user.h"
#include <list>
#include "Global.h"
#include <msclr\marshal_cppstd.h>
#include<stdio.h>



namespace SpotifyUIDesign {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Summary for Home2
	/// </summary>
	public ref class Home2 : public System::Windows::Forms::Form
	{
	public:
		Home2()
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		
		void UncheckAll() {
			song1_chbx->Checked = false;
			song2_chbx->Checked = false;
			song3_chbx->Checked = false;
			song4_chbx->Checked = false;
			song5_chbx->Checked = false;
		}
		
		void hide_songs_buttons()
		{
			song_btn_1->Visible = false;
			song_btn_2->Visible = false;
			song_btn_3->Visible = false;
			song_btn_4->Visible = false;
			song_btn_5->Visible = false;
		}
		void hide_delete_songs_buttons()
		{
			delete_song1_btn->Visible = false;
			delete_song2_btn->Visible = false;
			delete_song3_btn->Visible = false;
			delete_song4_btn->Visible = false;
			delete_song5_btn->Visible = false;
		}
		void hide_playlists_buttons()
		{
			playlist_btn1->Visible = false;
			playlist_btn2->Visible = false;
			playlist_btn3->Visible = false;
			playlist_btn4->Visible = false;
			playlist_btn5->Visible = false;
		}
		void play_song(std::string song_name)
		{
			SoundPlayer^ sound = gcnew SoundPlayer;
			std::string song_directory = "D:\\SpotifyUIDesign_copy\\songs\\" + song_name + ".wav";
			String^ str = gcnew String{ song_directory.c_str() };
			sound->SoundLocation = str;
			sound->Load();
			sound->Play();
			current_user.play_song(song_name);
			str = gcnew String{ song_name.c_str() };
			LastPlayed_lbl->Text = str;
		}
		void display_songs_in_playlist(std::string playlist_name) {
			hide_songs_buttons();
			hide_delete_songs_buttons();
			playlist* user_playlist = current_user.get_playlist_by_name(playlist_name);

			SinglyLinkedListNode* temp = user_playlist->get_songs().getHead();
			int count = user_playlist->get_songs().getCount();
			std::string songs_number = "NO. Songs : " + std::to_string(count);
			songs_count->Text = gcnew String{ songs_number.c_str() };
			String^ str2 = gcnew String{ playlist_name.c_str() };
			Playlist_name->Text = str2;
			String^ str;
			if (count > 0) {
				str = gcnew String{ temp->getData().getName().c_str() };
				song_btn_1->Text = str;
				song_btn_1->Visible = true;
				delete_song1_btn->Visible = true;
			}
			if (count > 1) {
				temp = temp->getNext();
				str = gcnew String{ temp->getData().getName().c_str() };
				song_btn_2->Text = str;
				song_btn_2->Visible = true;
				delete_song2_btn->Visible = true;
			}
			if (count > 2) {
				temp = temp->getNext();
				str = gcnew String{ temp->getData().getName().c_str() };
				song_btn_3->Text = str;
				song_btn_3->Visible = true;
				delete_song3_btn->Visible = true;
			}
			if (count > 3) {
				temp = temp->getNext();
				str = gcnew String{ temp->getData().getName().c_str() };
				song_btn_4->Text = str;
				song_btn_4->Visible = true;
				delete_song4_btn->Visible = true;
			}
			if (count > 4) {
				temp = temp->getNext();
				str = gcnew String{ temp->getData().getName().c_str() };
				song_btn_5->Text = str;
				song_btn_5->Visible = true;
				delete_song5_btn->Visible = true;
			}

		}
		void display_songs(playlist p) {
			SinglyLinkedListNode* temp = p.get_songs().getHead();
			String^ str = gcnew String{ temp->getData().getName().c_str() };
			app_song1_btn->Text = str;
			temp = temp->getNext();
			str = gcnew String{ temp->getData().getName().c_str() };
			app_song2_btn->Text = str;
			temp = temp->getNext();
			str = gcnew String{ temp->getData().getName().c_str() };
			app_song3_btn->Text = str;
			temp = temp->getNext();
			str = gcnew String{ temp->getData().getName().c_str() };
			app_song4_btn->Text = str;
			temp = temp->getNext();
			str = gcnew String{ temp->getData().getName().c_str() };
			app_song5_btn->Text = str;
			temp = temp->getNext();
			str = gcnew String{ temp->getData().getName().c_str() };
			app_song6_btn->Text = str;
			temp = temp->getNext();
			str = gcnew String{ temp->getData().getName().c_str() };
			app_song7_btn->Text = str;
			temp = temp->getNext();
			str = gcnew String{ temp->getData().getName().c_str() };
			app_song8_btn->Text = str;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Home2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ Side_panel;
	protected:

	private: System::Windows::Forms::Panel^ Bottom_panel;

	private: System::Windows::Forms::Panel^ Home_panel;
	private: System::Windows::Forms::Panel^ Playlist_panel;
	private: System::Windows::Forms::Panel^ Add_new_pl_panel;
	private: System::Windows::Forms::Panel^ Fav_playlist_panel;
	private: System::Windows::Forms::Panel^ Activity_panel;
	private: System::Windows::Forms::Panel^ Browse_panel;

	private: System::Windows::Forms::Panel^ search_panel;
	private: System::Windows::Forms::TextBox^ search_TB;
	private: System::Windows::Forms::Panel^ listen_on_spot_panel;

	private: System::Windows::Forms::Label^ ur_music_lbl;
	private: System::Windows::Forms::Button^ playlists_btn;
	private: System::Windows::Forms::Button^ albums_btn;
	private: System::Windows::Forms::Button^ song_btn;
	private: System::Windows::Forms::Button^ radio_btn;
	private: System::Windows::Forms::Button^ activity_btn;
	private: System::Windows::Forms::Button^ browse_btn;
	private: System::Windows::Forms::Label^ main_lbl;
	private: System::Windows::Forms::PictureBox^ pictureBox10;
	private: System::Windows::Forms::PictureBox^ pictureBox9;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::PictureBox^ pictureBox8;
	private: System::Windows::Forms::PictureBox^ pictureBox7;
	private: System::Windows::Forms::PictureBox^ pictureBox6;
	private: System::Windows::Forms::PictureBox^ pictureBox5;




	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ back_frm_brwsr_to_home_btn;

	private: System::Windows::Forms::Button^ back_frm_pl_to_home_btn;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ add_playlist_btn;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ back_to_pl_panel;
	private: System::Windows::Forms::Button^ back_to_pl_frm_fav_btn;

	private: System::Windows::Forms::Panel^ search_history_panel;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Panel^ recently_played_panel;

	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Panel^ last_played_song_panel;
	private: System::Windows::Forms::Button^ vol_btn;
	private: System::Windows::Forms::Button^ last_song_btn;
	private: System::Windows::Forms::Button^ next_song_btn;
	private: System::Windows::Forms::Button^ pause_play_btn;
	private: System::Windows::Forms::Label^ LastPlayed_lbl;

	private: System::Windows::Forms::Label^ Playlist_name;

	private: System::Windows::Forms::Panel^ search_browser;
	private: System::Windows::Forms::Panel^ searchbar_panel;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ searchbar_TB;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Button^ song_btn_5;
	private: System::Windows::Forms::Button^ song_btn_2;
	private: System::Windows::Forms::Button^ song_btn_3;
	private: System::Windows::Forms::Button^ song_btn_4;
	private: System::Windows::Forms::Button^ song_btn_1;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Panel^ playlists_panel;
	private: System::Windows::Forms::Button^ my_playlists_btn;

	private: System::Windows::Forms::TextBox^ TB_playlist_name;
	private: System::Windows::Forms::Panel^ panel_playlist_collection;
private: System::Windows::Forms::Button^ playlist_btn5;

	private: System::Windows::Forms::Button^ playlist_btn2;
private: System::Windows::Forms::Button^ playlist_btn3;
private: System::Windows::Forms::Button^ playlist_btn4;


	private: System::Windows::Forms::Button^ playlist_btn1;
	private: System::Windows::Forms::Label^ label15;
private: System::Windows::Forms::Button^ bck_home_from_playlists_collection;
private: System::Windows::Forms::Button^ add_song_to_playlist_btn;
private: System::Windows::Forms::Panel^ songs_to_be_selected_panel;
private: System::Windows::Forms::CheckBox^ song5_chbx;
private: System::Windows::Forms::CheckBox^ song4_chbx;
private: System::Windows::Forms::CheckBox^ song3_chbx;
private: System::Windows::Forms::CheckBox^ song2_chbx;
private: System::Windows::Forms::CheckBox^ song1_chbx;
private: System::Windows::Forms::Label^ label12;
private: System::Windows::Forms::Button^ button8;
private: System::Windows::Forms::Button^ add_song_implemented_btn;
private: System::Windows::Forms::Label^ songs_count;
private: System::Windows::Forms::Button^ button3;
private: System::Windows::Forms::Label^ label16;


private: System::Windows::Forms::Button^ shuffle_btn;







	protected:

	protected:



	protected:

	private:
		//user* current_user;
		/// <summary>
		/// Required designer variable.
		/// </summary>
		int type_no=0;
		bool sort_flag = true;
private: System::Windows::Forms::Button^ searched_song_btn3;
private: System::Windows::Forms::Button^ searched_song_btn2;
private: System::Windows::Forms::Button^ searched_song_btn1;
private: System::Windows::Forms::Label^ searched_lbl2;
private: System::Windows::Forms::Label^ searched_lbl1;
private: System::Windows::Forms::Label^ searched_lbl3;
private: System::Windows::Forms::Panel^ songs_panel;
private: System::Windows::Forms::Button^ app_song8_btn;
private: System::Windows::Forms::Button^ app_song7_btn;
private: System::Windows::Forms::Button^ app_song6_btn;
private: System::Windows::Forms::Button^ app_song5_btn;
private: System::Windows::Forms::Button^ app_song2_btn;
private: System::Windows::Forms::Button^ app_song3_btn;
private: System::Windows::Forms::Button^ app_song4_btn;
private: System::Windows::Forms::Button^ app_song1_btn;
private: System::Windows::Forms::Label^ label_songs;
private: System::Windows::Forms::Button^ bck_frm_songs_panel_btn;

private: System::Windows::Forms::Button^ sort_btn;










private: System::Windows::Forms::Button^ delete_song5_btn;
private: System::Windows::Forms::Button^ delete_song4_btn;
private: System::Windows::Forms::Button^ delete_song3_btn;
private: System::Windows::Forms::Button^ delete_song2_btn;
private: System::Windows::Forms::Button^ delete_song1_btn;
private: System::Windows::Forms::Button^ recent_song4_btn;

private: System::Windows::Forms::Button^ recent_song3_btn;
private: System::Windows::Forms::Button^ recent_song2_btn;
private: System::Windows::Forms::Button^ recent_song1_btn;
private: System::Windows::Forms::Button^ recent_song7_btn;

private: System::Windows::Forms::Button^ recent_song6_btn;

private: System::Windows::Forms::Button^ recent_song5_btn;
private: System::Windows::Forms::Button^ logout_btn;



	   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Home2::typeid));
			this->Side_panel = (gcnew System::Windows::Forms::Panel());
			this->logout_btn = (gcnew System::Windows::Forms::Button());
			this->search_panel = (gcnew System::Windows::Forms::Panel());
			this->search_TB = (gcnew System::Windows::Forms::TextBox());
			this->listen_on_spot_panel = (gcnew System::Windows::Forms::Panel());
			this->ur_music_lbl = (gcnew System::Windows::Forms::Label());
			this->playlists_btn = (gcnew System::Windows::Forms::Button());
			this->albums_btn = (gcnew System::Windows::Forms::Button());
			this->song_btn = (gcnew System::Windows::Forms::Button());
			this->radio_btn = (gcnew System::Windows::Forms::Button());
			this->activity_btn = (gcnew System::Windows::Forms::Button());
			this->browse_btn = (gcnew System::Windows::Forms::Button());
			this->main_lbl = (gcnew System::Windows::Forms::Label());
			this->searched_lbl2 = (gcnew System::Windows::Forms::Label());
			this->searched_lbl1 = (gcnew System::Windows::Forms::Label());
			this->searched_lbl3 = (gcnew System::Windows::Forms::Label());
			this->Bottom_panel = (gcnew System::Windows::Forms::Panel());
			this->last_played_song_panel = (gcnew System::Windows::Forms::Panel());
			this->vol_btn = (gcnew System::Windows::Forms::Button());
			this->last_song_btn = (gcnew System::Windows::Forms::Button());
			this->next_song_btn = (gcnew System::Windows::Forms::Button());
			this->pause_play_btn = (gcnew System::Windows::Forms::Button());
			this->LastPlayed_lbl = (gcnew System::Windows::Forms::Label());
			this->Home_panel = (gcnew System::Windows::Forms::Panel());
			this->pictureBox10 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox9 = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->Playlist_panel = (gcnew System::Windows::Forms::Panel());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->playlists_panel = (gcnew System::Windows::Forms::Panel());
			this->my_playlists_btn = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->add_playlist_btn = (gcnew System::Windows::Forms::Button());
			this->back_frm_pl_to_home_btn = (gcnew System::Windows::Forms::Button());
			this->Add_new_pl_panel = (gcnew System::Windows::Forms::Panel());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->TB_playlist_name = (gcnew System::Windows::Forms::TextBox());
			this->back_to_pl_panel = (gcnew System::Windows::Forms::Button());
			this->Fav_playlist_panel = (gcnew System::Windows::Forms::Panel());
			this->delete_song5_btn = (gcnew System::Windows::Forms::Button());
			this->delete_song4_btn = (gcnew System::Windows::Forms::Button());
			this->delete_song3_btn = (gcnew System::Windows::Forms::Button());
			this->delete_song2_btn = (gcnew System::Windows::Forms::Button());
			this->delete_song1_btn = (gcnew System::Windows::Forms::Button());
			this->shuffle_btn = (gcnew System::Windows::Forms::Button());
			this->songs_count = (gcnew System::Windows::Forms::Label());
			this->add_song_to_playlist_btn = (gcnew System::Windows::Forms::Button());
			this->song_btn_5 = (gcnew System::Windows::Forms::Button());
			this->song_btn_2 = (gcnew System::Windows::Forms::Button());
			this->song_btn_3 = (gcnew System::Windows::Forms::Button());
			this->song_btn_4 = (gcnew System::Windows::Forms::Button());
			this->song_btn_1 = (gcnew System::Windows::Forms::Button());
			this->Playlist_name = (gcnew System::Windows::Forms::Label());
			this->back_to_pl_frm_fav_btn = (gcnew System::Windows::Forms::Button());
			this->Activity_panel = (gcnew System::Windows::Forms::Panel());
			this->search_history_panel = (gcnew System::Windows::Forms::Panel());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->recently_played_panel = (gcnew System::Windows::Forms::Panel());
			this->recent_song7_btn = (gcnew System::Windows::Forms::Button());
			this->recent_song6_btn = (gcnew System::Windows::Forms::Button());
			this->recent_song5_btn = (gcnew System::Windows::Forms::Button());
			this->recent_song4_btn = (gcnew System::Windows::Forms::Button());
			this->recent_song3_btn = (gcnew System::Windows::Forms::Button());
			this->recent_song2_btn = (gcnew System::Windows::Forms::Button());
			this->recent_song1_btn = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->Browse_panel = (gcnew System::Windows::Forms::Panel());
			this->search_browser = (gcnew System::Windows::Forms::Panel());
			this->searched_song_btn3 = (gcnew System::Windows::Forms::Button());
			this->searched_song_btn2 = (gcnew System::Windows::Forms::Button());
			this->searched_song_btn1 = (gcnew System::Windows::Forms::Button());
			this->searchbar_panel = (gcnew System::Windows::Forms::Panel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->searchbar_TB = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->back_frm_brwsr_to_home_btn = (gcnew System::Windows::Forms::Button());
			this->panel_playlist_collection = (gcnew System::Windows::Forms::Panel());
			this->playlist_btn5 = (gcnew System::Windows::Forms::Button());
			this->playlist_btn2 = (gcnew System::Windows::Forms::Button());
			this->playlist_btn3 = (gcnew System::Windows::Forms::Button());
			this->playlist_btn4 = (gcnew System::Windows::Forms::Button());
			this->playlist_btn1 = (gcnew System::Windows::Forms::Button());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->bck_home_from_playlists_collection = (gcnew System::Windows::Forms::Button());
			this->songs_to_be_selected_panel = (gcnew System::Windows::Forms::Panel());
			this->add_song_implemented_btn = (gcnew System::Windows::Forms::Button());
			this->song5_chbx = (gcnew System::Windows::Forms::CheckBox());
			this->song4_chbx = (gcnew System::Windows::Forms::CheckBox());
			this->song3_chbx = (gcnew System::Windows::Forms::CheckBox());
			this->song2_chbx = (gcnew System::Windows::Forms::CheckBox());
			this->song1_chbx = (gcnew System::Windows::Forms::CheckBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->songs_panel = (gcnew System::Windows::Forms::Panel());
			this->sort_btn = (gcnew System::Windows::Forms::Button());
			this->app_song8_btn = (gcnew System::Windows::Forms::Button());
			this->app_song7_btn = (gcnew System::Windows::Forms::Button());
			this->app_song6_btn = (gcnew System::Windows::Forms::Button());
			this->app_song5_btn = (gcnew System::Windows::Forms::Button());
			this->app_song2_btn = (gcnew System::Windows::Forms::Button());
			this->app_song3_btn = (gcnew System::Windows::Forms::Button());
			this->app_song4_btn = (gcnew System::Windows::Forms::Button());
			this->app_song1_btn = (gcnew System::Windows::Forms::Button());
			this->label_songs = (gcnew System::Windows::Forms::Label());
			this->bck_frm_songs_panel_btn = (gcnew System::Windows::Forms::Button());
			this->Side_panel->SuspendLayout();
			this->search_panel->SuspendLayout();
			this->Bottom_panel->SuspendLayout();
			this->last_played_song_panel->SuspendLayout();
			this->Home_panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->Playlist_panel->SuspendLayout();
			this->playlists_panel->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->Add_new_pl_panel->SuspendLayout();
			this->Fav_playlist_panel->SuspendLayout();
			this->Activity_panel->SuspendLayout();
			this->search_history_panel->SuspendLayout();
			this->recently_played_panel->SuspendLayout();
			this->Browse_panel->SuspendLayout();
			this->search_browser->SuspendLayout();
			this->searchbar_panel->SuspendLayout();
			this->panel_playlist_collection->SuspendLayout();
			this->songs_to_be_selected_panel->SuspendLayout();
			this->songs_panel->SuspendLayout();
			this->SuspendLayout();
			// 
			// Side_panel
			// 
			this->Side_panel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(17)), static_cast<System::Int32>(static_cast<System::Byte>(17)),
				static_cast<System::Int32>(static_cast<System::Byte>(17)));
			this->Side_panel->Controls->Add(this->logout_btn);
			this->Side_panel->Controls->Add(this->search_panel);
			this->Side_panel->Controls->Add(this->listen_on_spot_panel);
			this->Side_panel->Controls->Add(this->ur_music_lbl);
			this->Side_panel->Controls->Add(this->playlists_btn);
			this->Side_panel->Controls->Add(this->albums_btn);
			this->Side_panel->Controls->Add(this->song_btn);
			this->Side_panel->Controls->Add(this->radio_btn);
			this->Side_panel->Controls->Add(this->activity_btn);
			this->Side_panel->Controls->Add(this->browse_btn);
			this->Side_panel->Controls->Add(this->main_lbl);
			this->Side_panel->Dock = System::Windows::Forms::DockStyle::Left;
			this->Side_panel->Location = System::Drawing::Point(0, 0);
			this->Side_panel->Margin = System::Windows::Forms::Padding(4);
			this->Side_panel->Name = L"Side_panel";
			this->Side_panel->Size = System::Drawing::Size(224, 639);
			this->Side_panel->TabIndex = 0;
			// 
			// logout_btn
			// 
			this->logout_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->logout_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->logout_btn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->logout_btn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->logout_btn->ForeColor = System::Drawing::Color::White;
			this->logout_btn->Location = System::Drawing::Point(51, 597);
			this->logout_btn->Name = L"logout_btn";
			this->logout_btn->Size = System::Drawing::Size(125, 36);
			this->logout_btn->TabIndex = 37;
			this->logout_btn->Text = L" Logout";
			this->logout_btn->UseVisualStyleBackColor = false;
			this->logout_btn->Click += gcnew System::EventHandler(this, &Home2::logout_btn_Click);
			// 
			// search_panel
			// 
			this->search_panel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"search_panel.BackgroundImage")));
			this->search_panel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->search_panel->Controls->Add(this->search_TB);
			this->search_panel->Location = System::Drawing::Point(-3, 101);
			this->search_panel->Margin = System::Windows::Forms::Padding(4);
			this->search_panel->Name = L"search_panel";
			this->search_panel->Size = System::Drawing::Size(231, 59);
			this->search_panel->TabIndex = 12;
			// 
			// search_TB
			// 
			this->search_TB->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(52)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)));
			this->search_TB->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->search_TB->Location = System::Drawing::Point(16, 21);
			this->search_TB->Margin = System::Windows::Forms::Padding(4);
			this->search_TB->Name = L"search_TB";
			this->search_TB->Size = System::Drawing::Size(188, 15);
			this->search_TB->TabIndex = 0;
			// 
			// listen_on_spot_panel
			// 
			this->listen_on_spot_panel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"listen_on_spot_panel.BackgroundImage")));
			this->listen_on_spot_panel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->listen_on_spot_panel->Location = System::Drawing::Point(1, 12);
			this->listen_on_spot_panel->Margin = System::Windows::Forms::Padding(4);
			this->listen_on_spot_panel->Name = L"listen_on_spot_panel";
			this->listen_on_spot_panel->Size = System::Drawing::Size(217, 80);
			this->listen_on_spot_panel->TabIndex = 11;
			// 
			// ur_music_lbl
			// 
			this->ur_music_lbl->AutoSize = true;
			this->ur_music_lbl->BackColor = System::Drawing::Color::Transparent;
			this->ur_music_lbl->Font = (gcnew System::Drawing::Font(L"Century Gothic", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ur_music_lbl->ForeColor = System::Drawing::Color::Gainsboro;
			this->ur_music_lbl->Location = System::Drawing::Point(5, 362);
			this->ur_music_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->ur_music_lbl->Name = L"ur_music_lbl";
			this->ur_music_lbl->Size = System::Drawing::Size(93, 17);
			this->ur_music_lbl->TabIndex = 20;
			this->ur_music_lbl->Text = L"YOUR MUSIC";
			// 
			// playlists_btn
			// 
			this->playlists_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->playlists_btn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->playlists_btn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.25F, System::Drawing::FontStyle::Bold));
			this->playlists_btn->ForeColor = System::Drawing::Color::White;
			this->playlists_btn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"playlists_btn.Image")));
			this->playlists_btn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->playlists_btn->Location = System::Drawing::Point(19, 508);
			this->playlists_btn->Margin = System::Windows::Forms::Padding(4);
			this->playlists_btn->Name = L"playlists_btn";
			this->playlists_btn->Size = System::Drawing::Size(187, 48);
			this->playlists_btn->TabIndex = 19;
			this->playlists_btn->Text = L"    Playlists";
			this->playlists_btn->UseVisualStyleBackColor = true;
			this->playlists_btn->Click += gcnew System::EventHandler(this, &Home2::playlists_btn_Click);
			// 
			// albums_btn
			// 
			this->albums_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->albums_btn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->albums_btn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.25F, System::Drawing::FontStyle::Bold));
			this->albums_btn->ForeColor = System::Drawing::Color::White;
			this->albums_btn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"albums_btn.Image")));
			this->albums_btn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->albums_btn->Location = System::Drawing::Point(19, 447);
			this->albums_btn->Margin = System::Windows::Forms::Padding(4);
			this->albums_btn->Name = L"albums_btn";
			this->albums_btn->Size = System::Drawing::Size(187, 48);
			this->albums_btn->TabIndex = 18;
			this->albums_btn->Text = L"    Album";
			this->albums_btn->UseVisualStyleBackColor = true;
			// 
			// song_btn
			// 
			this->song_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->song_btn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->song_btn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.25F, System::Drawing::FontStyle::Bold));
			this->song_btn->ForeColor = System::Drawing::Color::White;
			this->song_btn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"song_btn.Image")));
			this->song_btn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->song_btn->Location = System::Drawing::Point(19, 388);
			this->song_btn->Margin = System::Windows::Forms::Padding(4);
			this->song_btn->Name = L"song_btn";
			this->song_btn->Size = System::Drawing::Size(187, 48);
			this->song_btn->TabIndex = 17;
			this->song_btn->Text = L"    Songs";
			this->song_btn->UseVisualStyleBackColor = true;
			this->song_btn->Click += gcnew System::EventHandler(this, &Home2::song_btn_Click);
			// 
			// radio_btn
			// 
			this->radio_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->radio_btn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->radio_btn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.25F, System::Drawing::FontStyle::Bold));
			this->radio_btn->ForeColor = System::Drawing::Color::White;
			this->radio_btn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"radio_btn.Image")));
			this->radio_btn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->radio_btn->Location = System::Drawing::Point(19, 304);
			this->radio_btn->Margin = System::Windows::Forms::Padding(4);
			this->radio_btn->Name = L"radio_btn";
			this->radio_btn->Size = System::Drawing::Size(187, 48);
			this->radio_btn->TabIndex = 16;
			this->radio_btn->Text = L"    Radio";
			this->radio_btn->UseVisualStyleBackColor = true;
			// 
			// activity_btn
			// 
			this->activity_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->activity_btn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->activity_btn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.25F, System::Drawing::FontStyle::Bold));
			this->activity_btn->ForeColor = System::Drawing::Color::White;
			this->activity_btn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"activity_btn.Image")));
			this->activity_btn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->activity_btn->Location = System::Drawing::Point(19, 249);
			this->activity_btn->Margin = System::Windows::Forms::Padding(4);
			this->activity_btn->Name = L"activity_btn";
			this->activity_btn->Size = System::Drawing::Size(187, 48);
			this->activity_btn->TabIndex = 15;
			this->activity_btn->Text = L"    Activity";
			this->activity_btn->UseVisualStyleBackColor = true;
			this->activity_btn->Click += gcnew System::EventHandler(this, &Home2::activity_btn_Click);
			// 
			// browse_btn
			// 
			this->browse_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->browse_btn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->browse_btn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.25F, System::Drawing::FontStyle::Bold));
			this->browse_btn->ForeColor = System::Drawing::Color::White;
			this->browse_btn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"browse_btn.Image")));
			this->browse_btn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->browse_btn->Location = System::Drawing::Point(17, 192);
			this->browse_btn->Margin = System::Windows::Forms::Padding(4);
			this->browse_btn->Name = L"browse_btn";
			this->browse_btn->Size = System::Drawing::Size(187, 48);
			this->browse_btn->TabIndex = 14;
			this->browse_btn->Text = L"    Browse";
			this->browse_btn->UseVisualStyleBackColor = true;
			this->browse_btn->Click += gcnew System::EventHandler(this, &Home2::browse_btn_Click);
			// 
			// main_lbl
			// 
			this->main_lbl->AutoSize = true;
			this->main_lbl->BackColor = System::Drawing::Color::Transparent;
			this->main_lbl->Font = (gcnew System::Drawing::Font(L"Century Gothic", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->main_lbl->ForeColor = System::Drawing::Color::Gainsboro;
			this->main_lbl->Location = System::Drawing::Point(5, 169);
			this->main_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->main_lbl->Name = L"main_lbl";
			this->main_lbl->Size = System::Drawing::Size(45, 17);
			this->main_lbl->TabIndex = 13;
			this->main_lbl->Text = L"MAIN";
			// 
			// searched_lbl2
			// 
			this->searched_lbl2->AutoSize = true;
			this->searched_lbl2->BackColor = System::Drawing::Color::Transparent;
			this->searched_lbl2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.25F));
			this->searched_lbl2->ForeColor = System::Drawing::Color::Gainsboro;
			this->searched_lbl2->Location = System::Drawing::Point(137, 112);
			this->searched_lbl2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->searched_lbl2->Name = L"searched_lbl2";
			this->searched_lbl2->Size = System::Drawing::Size(299, 27);
			this->searched_lbl2->TabIndex = 32;
			this->searched_lbl2->Text = L"No recently played songs";
			this->searched_lbl2->Visible = false;
			// 
			// searched_lbl1
			// 
			this->searched_lbl1->AutoSize = true;
			this->searched_lbl1->BackColor = System::Drawing::Color::Transparent;
			this->searched_lbl1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.25F));
			this->searched_lbl1->ForeColor = System::Drawing::Color::Gainsboro;
			this->searched_lbl1->Location = System::Drawing::Point(137, 76);
			this->searched_lbl1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->searched_lbl1->Name = L"searched_lbl1";
			this->searched_lbl1->Size = System::Drawing::Size(299, 27);
			this->searched_lbl1->TabIndex = 31;
			this->searched_lbl1->Text = L"No recently played songs";
			this->searched_lbl1->Visible = false;
			// 
			// searched_lbl3
			// 
			this->searched_lbl3->AutoSize = true;
			this->searched_lbl3->BackColor = System::Drawing::Color::Transparent;
			this->searched_lbl3->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.25F));
			this->searched_lbl3->ForeColor = System::Drawing::Color::Gainsboro;
			this->searched_lbl3->Location = System::Drawing::Point(137, 143);
			this->searched_lbl3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->searched_lbl3->Name = L"searched_lbl3";
			this->searched_lbl3->Size = System::Drawing::Size(299, 27);
			this->searched_lbl3->TabIndex = 32;
			this->searched_lbl3->Text = L"No recently played songs";
			this->searched_lbl3->Visible = false;
			// 
			// Bottom_panel
			// 
			this->Bottom_panel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(17)), static_cast<System::Int32>(static_cast<System::Byte>(17)),
				static_cast<System::Int32>(static_cast<System::Byte>(17)));
			this->Bottom_panel->Controls->Add(this->last_played_song_panel);
			this->Bottom_panel->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->Bottom_panel->Location = System::Drawing::Point(224, 589);
			this->Bottom_panel->Margin = System::Windows::Forms::Padding(4);
			this->Bottom_panel->Name = L"Bottom_panel";
			this->Bottom_panel->Size = System::Drawing::Size(955, 50);
			this->Bottom_panel->TabIndex = 1;
			// 
			// last_played_song_panel
			// 
			this->last_played_song_panel->Controls->Add(this->vol_btn);
			this->last_played_song_panel->Controls->Add(this->last_song_btn);
			this->last_played_song_panel->Controls->Add(this->next_song_btn);
			this->last_played_song_panel->Controls->Add(this->pause_play_btn);
			this->last_played_song_panel->Controls->Add(this->LastPlayed_lbl);
			this->last_played_song_panel->Location = System::Drawing::Point(0, 4);
			this->last_played_song_panel->Margin = System::Windows::Forms::Padding(4);
			this->last_played_song_panel->Name = L"last_played_song_panel";
			this->last_played_song_panel->Size = System::Drawing::Size(911, 43);
			this->last_played_song_panel->TabIndex = 15;
			// 
			// vol_btn
			// 
			this->vol_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->vol_btn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->vol_btn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.25F, System::Drawing::FontStyle::Bold));
			this->vol_btn->ForeColor = System::Drawing::Color::White;
			this->vol_btn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"vol_btn.Image")));
			this->vol_btn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->vol_btn->Location = System::Drawing::Point(876, 12);
			this->vol_btn->Margin = System::Windows::Forms::Padding(4);
			this->vol_btn->Name = L"vol_btn";
			this->vol_btn->Size = System::Drawing::Size(31, 32);
			this->vol_btn->TabIndex = 19;
			this->vol_btn->UseVisualStyleBackColor = true;
			// 
			// last_song_btn
			// 
			this->last_song_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->last_song_btn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->last_song_btn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.25F, System::Drawing::FontStyle::Bold));
			this->last_song_btn->ForeColor = System::Drawing::Color::White;
			this->last_song_btn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"last_song_btn.Image")));
			this->last_song_btn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->last_song_btn->Location = System::Drawing::Point(734, 4);
			this->last_song_btn->Margin = System::Windows::Forms::Padding(4);
			this->last_song_btn->Name = L"last_song_btn";
			this->last_song_btn->Size = System::Drawing::Size(36, 32);
			this->last_song_btn->TabIndex = 18;
			this->last_song_btn->UseVisualStyleBackColor = true;
			// 
			// next_song_btn
			// 
			this->next_song_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->next_song_btn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->next_song_btn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.25F, System::Drawing::FontStyle::Bold));
			this->next_song_btn->ForeColor = System::Drawing::Color::White;
			this->next_song_btn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"next_song_btn.Image")));
			this->next_song_btn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->next_song_btn->Location = System::Drawing::Point(808, 4);
			this->next_song_btn->Margin = System::Windows::Forms::Padding(4);
			this->next_song_btn->Name = L"next_song_btn";
			this->next_song_btn->Size = System::Drawing::Size(31, 32);
			this->next_song_btn->TabIndex = 17;
			this->next_song_btn->UseVisualStyleBackColor = true;
			// 
			// pause_play_btn
			// 
			this->pause_play_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pause_play_btn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->pause_play_btn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.25F, System::Drawing::FontStyle::Bold));
			this->pause_play_btn->ForeColor = System::Drawing::Color::White;
			this->pause_play_btn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pause_play_btn.Image")));
			this->pause_play_btn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->pause_play_btn->Location = System::Drawing::Point(769, 4);
			this->pause_play_btn->Margin = System::Windows::Forms::Padding(4);
			this->pause_play_btn->Name = L"pause_play_btn";
			this->pause_play_btn->Size = System::Drawing::Size(45, 32);
			this->pause_play_btn->TabIndex = 16;
			this->pause_play_btn->UseVisualStyleBackColor = true;
			this->pause_play_btn->Click += gcnew System::EventHandler(this, &Home2::pause_play_btn_Click);
			// 
			// LastPlayed_lbl
			// 
			this->LastPlayed_lbl->AutoSize = true;
			this->LastPlayed_lbl->BackColor = System::Drawing::Color::Transparent;
			this->LastPlayed_lbl->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LastPlayed_lbl->ForeColor = System::Drawing::Color::Gainsboro;
			this->LastPlayed_lbl->Location = System::Drawing::Point(28, 19);
			this->LastPlayed_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->LastPlayed_lbl->Name = L"LastPlayed_lbl";
			this->LastPlayed_lbl->Size = System::Drawing::Size(90, 18);
			this->LastPlayed_lbl->TabIndex = 15;
			this->LastPlayed_lbl->Text = L"Last Played";
			// 
			// Home_panel
			// 
			this->Home_panel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Home_panel.BackgroundImage")));
			this->Home_panel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Home_panel->Controls->Add(this->pictureBox10);
			this->Home_panel->Controls->Add(this->pictureBox9);
			this->Home_panel->Controls->Add(this->label2);
			this->Home_panel->Controls->Add(this->label8);
			this->Home_panel->Controls->Add(this->pictureBox8);
			this->Home_panel->Controls->Add(this->pictureBox7);
			this->Home_panel->Controls->Add(this->pictureBox6);
			this->Home_panel->Controls->Add(this->pictureBox5);
			this->Home_panel->Controls->Add(this->pictureBox4);
			this->Home_panel->Controls->Add(this->pictureBox3);
			this->Home_panel->Controls->Add(this->pictureBox2);
			this->Home_panel->Controls->Add(this->pictureBox1);
			this->Home_panel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Home_panel->Location = System::Drawing::Point(0, 0);
			this->Home_panel->Margin = System::Windows::Forms::Padding(4);
			this->Home_panel->Name = L"Home_panel";
			this->Home_panel->Size = System::Drawing::Size(1179, 639);
			this->Home_panel->TabIndex = 2;
			// 
			// pictureBox10
			// 
			this->pictureBox10->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox10->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox10.BackgroundImage")));
			this->pictureBox10->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox10->Location = System::Drawing::Point(936, 202);
			this->pictureBox10->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox10->Name = L"pictureBox10";
			this->pictureBox10->Size = System::Drawing::Size(237, 153);
			this->pictureBox10->TabIndex = 36;
			this->pictureBox10->TabStop = false;
			// 
			// pictureBox9
			// 
			this->pictureBox9->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox9->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox9.BackgroundImage")));
			this->pictureBox9->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox9->Location = System::Drawing::Point(936, 49);
			this->pictureBox9->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox9->Name = L"pictureBox9";
			this->pictureBox9->Size = System::Drawing::Size(237, 153);
			this->pictureBox9->TabIndex = 35;
			this->pictureBox9->TabStop = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(230, 4);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(342, 44);
			this->label2->TabIndex = 34;
			this->label2->Text = L"YOUR TOP GENRES";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->Font = (gcnew System::Drawing::Font(L"Century Gothic", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::White;
			this->label8->Location = System::Drawing::Point(225, 359);
			this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(292, 44);
			this->label8->TabIndex = 33;
			this->label8->Text = L"MADE FOR YOU";
			// 
			// pictureBox8
			// 
			this->pictureBox8->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox8.BackgroundImage")));
			this->pictureBox8->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox8->Location = System::Drawing::Point(276, 49);
			this->pictureBox8->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox8->Name = L"pictureBox8";
			this->pictureBox8->Size = System::Drawing::Size(241, 153);
			this->pictureBox8->TabIndex = 32;
			this->pictureBox8->TabStop = false;
			// 
			// pictureBox7
			// 
			this->pictureBox7->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.BackgroundImage")));
			this->pictureBox7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox7->Location = System::Drawing::Point(276, 202);
			this->pictureBox7->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(241, 153);
			this->pictureBox7->TabIndex = 31;
			this->pictureBox7->TabStop = false;
			// 
			// pictureBox6
			// 
			this->pictureBox6->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.BackgroundImage")));
			this->pictureBox6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox6->Location = System::Drawing::Point(605, 202);
			this->pictureBox6->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(237, 153);
			this->pictureBox6->TabIndex = 30;
			this->pictureBox6->TabStop = false;
			// 
			// pictureBox5
			// 
			this->pictureBox5->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.BackgroundImage")));
			this->pictureBox5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox5->Location = System::Drawing::Point(605, 49);
			this->pictureBox5->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(237, 153);
			this->pictureBox5->TabIndex = 29;
			this->pictureBox5->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.BackgroundImage")));
			this->pictureBox4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox4->Location = System::Drawing::Point(936, 403);
			this->pictureBox4->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(243, 165);
			this->pictureBox4->TabIndex = 24;
			this->pictureBox4->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.BackgroundImage")));
			this->pictureBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox3->Location = System::Drawing::Point(696, 403);
			this->pictureBox3->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(243, 165);
			this->pictureBox3->TabIndex = 23;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox2->Location = System::Drawing::Point(456, 403);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(243, 165);
			this->pictureBox2->TabIndex = 22;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox1->Location = System::Drawing::Point(224, 403);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(243, 165);
			this->pictureBox1->TabIndex = 21;
			this->pictureBox1->TabStop = false;
			// 
			// Playlist_panel
			// 
			this->Playlist_panel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Playlist_panel.BackgroundImage")));
			this->Playlist_panel->Controls->Add(this->label14);
			this->Playlist_panel->Controls->Add(this->playlists_panel);
			this->Playlist_panel->Controls->Add(this->label7);
			this->Playlist_panel->Controls->Add(this->panel2);
			this->Playlist_panel->Controls->Add(this->label1);
			this->Playlist_panel->Controls->Add(this->panel1);
			this->Playlist_panel->Controls->Add(this->back_frm_pl_to_home_btn);
			this->Playlist_panel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Playlist_panel->Location = System::Drawing::Point(0, 0);
			this->Playlist_panel->Margin = System::Windows::Forms::Padding(4);
			this->Playlist_panel->Name = L"Playlist_panel";
			this->Playlist_panel->Size = System::Drawing::Size(1179, 639);
			this->Playlist_panel->TabIndex = 0;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->BackColor = System::Drawing::Color::Transparent;
			this->label14->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.25F, System::Drawing::FontStyle::Bold));
			this->label14->ForeColor = System::Drawing::Color::Gainsboro;
			this->label14->Location = System::Drawing::Point(705, 264);
			this->label14->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(120, 22);
			this->label14->TabIndex = 23;
			this->label14->Text = L"Your Playlists";
			// 
			// playlists_panel
			// 
			this->playlists_panel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->playlists_panel->Controls->Add(this->my_playlists_btn);
			this->playlists_panel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->playlists_panel->Location = System::Drawing::Point(677, 122);
			this->playlists_panel->Margin = System::Windows::Forms::Padding(4);
			this->playlists_panel->Name = L"playlists_panel";
			this->playlists_panel->Size = System::Drawing::Size(173, 123);
			this->playlists_panel->TabIndex = 22;
			// 
			// my_playlists_btn
			// 
			this->my_playlists_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->my_playlists_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->my_playlists_btn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->my_playlists_btn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.25F, System::Drawing::FontStyle::Bold));
			this->my_playlists_btn->ForeColor = System::Drawing::Color::White;
			this->my_playlists_btn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"my_playlists_btn.Image")));
			this->my_playlists_btn->Location = System::Drawing::Point(16, 9);
			this->my_playlists_btn->Margin = System::Windows::Forms::Padding(4);
			this->my_playlists_btn->Name = L"my_playlists_btn";
			this->my_playlists_btn->Size = System::Drawing::Size(143, 103);
			this->my_playlists_btn->TabIndex = 18;
			this->my_playlists_btn->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->my_playlists_btn->UseVisualStyleBackColor = false;
			this->my_playlists_btn->Click += gcnew System::EventHandler(this, &Home2::my_playlists_btn_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.25F, System::Drawing::FontStyle::Bold));
			this->label7->ForeColor = System::Drawing::Color::Gainsboro;
			this->label7->Location = System::Drawing::Point(415, 262);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(140, 22);
			this->label7->TabIndex = 21;
			this->label7->Text = L"Your favourites\r\n";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->panel2->Controls->Add(this->button1);
			this->panel2->Location = System::Drawing::Point(399, 122);
			this->panel2->Margin = System::Windows::Forms::Padding(4);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(173, 123);
			this->panel2->TabIndex = 20;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Cyan;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.25F, System::Drawing::FontStyle::Bold));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->Location = System::Drawing::Point(16, 9);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(143, 103);
			this->button1->TabIndex = 18;
			this->button1->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Home2::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.25F, System::Drawing::FontStyle::Bold));
			this->label1->ForeColor = System::Drawing::Color::Gainsboro;
			this->label1->Location = System::Drawing::Point(99, 262);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(194, 22);
			this->label1->TabIndex = 19;
			this->label1->Text = L"Create a new playlist";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->panel1->Controls->Add(this->add_playlist_btn);
			this->panel1->Location = System::Drawing::Point(112, 122);
			this->panel1->Margin = System::Windows::Forms::Padding(4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(173, 123);
			this->panel1->TabIndex = 18;
			// 
			// add_playlist_btn
			// 
			this->add_playlist_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->add_playlist_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->add_playlist_btn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->add_playlist_btn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.25F, System::Drawing::FontStyle::Bold));
			this->add_playlist_btn->ForeColor = System::Drawing::Color::White;
			this->add_playlist_btn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"add_playlist_btn.Image")));
			this->add_playlist_btn->Location = System::Drawing::Point(13, 11);
			this->add_playlist_btn->Margin = System::Windows::Forms::Padding(4);
			this->add_playlist_btn->Name = L"add_playlist_btn";
			this->add_playlist_btn->Size = System::Drawing::Size(143, 103);
			this->add_playlist_btn->TabIndex = 18;
			this->add_playlist_btn->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->add_playlist_btn->UseVisualStyleBackColor = false;
			this->add_playlist_btn->Click += gcnew System::EventHandler(this, &Home2::add_playlist_btn_Click);
			// 
			// back_frm_pl_to_home_btn
			// 
			this->back_frm_pl_to_home_btn->BackColor = System::Drawing::Color::Transparent;
			this->back_frm_pl_to_home_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->back_frm_pl_to_home_btn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->back_frm_pl_to_home_btn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.25F, System::Drawing::FontStyle::Bold));
			this->back_frm_pl_to_home_btn->ForeColor = System::Drawing::Color::White;
			this->back_frm_pl_to_home_btn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"back_frm_pl_to_home_btn.Image")));
			this->back_frm_pl_to_home_btn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->back_frm_pl_to_home_btn->Location = System::Drawing::Point(0, 0);
			this->back_frm_pl_to_home_btn->Margin = System::Windows::Forms::Padding(4);
			this->back_frm_pl_to_home_btn->Name = L"back_frm_pl_to_home_btn";
			this->back_frm_pl_to_home_btn->Size = System::Drawing::Size(101, 48);
			this->back_frm_pl_to_home_btn->TabIndex = 17;
			this->back_frm_pl_to_home_btn->Text = L"Back";
			this->back_frm_pl_to_home_btn->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->back_frm_pl_to_home_btn->UseVisualStyleBackColor = false;
			this->back_frm_pl_to_home_btn->Click += gcnew System::EventHandler(this, &Home2::back_frm_pl_to_home_btn_Click);
			// 
			// Add_new_pl_panel
			// 
			this->Add_new_pl_panel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Add_new_pl_panel.BackgroundImage")));
			this->Add_new_pl_panel->Controls->Add(this->label16);
			this->Add_new_pl_panel->Controls->Add(this->button3);
			this->Add_new_pl_panel->Controls->Add(this->TB_playlist_name);
			this->Add_new_pl_panel->Controls->Add(this->back_to_pl_panel);
			this->Add_new_pl_panel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Add_new_pl_panel->Location = System::Drawing::Point(0, 0);
			this->Add_new_pl_panel->Margin = System::Windows::Forms::Padding(4);
			this->Add_new_pl_panel->Name = L"Add_new_pl_panel";
			this->Add_new_pl_panel->Size = System::Drawing::Size(1179, 639);
			this->Add_new_pl_panel->TabIndex = 0;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->BackColor = System::Drawing::Color::Transparent;
			this->label16->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.25F, System::Drawing::FontStyle::Bold));
			this->label16->ForeColor = System::Drawing::Color::Gainsboro;
			this->label16->Location = System::Drawing::Point(250, 92);
			this->label16->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(336, 27);
			this->label16->TabIndex = 25;
			this->label16->Text = L"Enter you new playlist name :";
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button3->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.25F, System::Drawing::FontStyle::Bold));
			this->button3->ForeColor = System::Drawing::Color::White;
			this->button3->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button3->Location = System::Drawing::Point(377, 221);
			this->button3->Margin = System::Windows::Forms::Padding(4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(140, 37);
			this->button3->TabIndex = 21;
			this->button3->Text = L"Create";
			this->button3->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Home2::create_playlist_btn_Click);
			// 
			// TB_playlist_name
			// 
			this->TB_playlist_name->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->TB_playlist_name->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->TB_playlist_name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TB_playlist_name->ForeColor = System::Drawing::Color::White;
			this->TB_playlist_name->Location = System::Drawing::Point(318, 161);
			this->TB_playlist_name->Name = L"TB_playlist_name";
			this->TB_playlist_name->Size = System::Drawing::Size(251, 41);
			this->TB_playlist_name->TabIndex = 19;
			// 
			// back_to_pl_panel
			// 
			this->back_to_pl_panel->BackColor = System::Drawing::Color::Transparent;
			this->back_to_pl_panel->Cursor = System::Windows::Forms::Cursors::Hand;
			this->back_to_pl_panel->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->back_to_pl_panel->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.25F, System::Drawing::FontStyle::Bold));
			this->back_to_pl_panel->ForeColor = System::Drawing::Color::White;
			this->back_to_pl_panel->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"back_to_pl_panel.Image")));
			this->back_to_pl_panel->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->back_to_pl_panel->Location = System::Drawing::Point(0, 0);
			this->back_to_pl_panel->Margin = System::Windows::Forms::Padding(4);
			this->back_to_pl_panel->Name = L"back_to_pl_panel";
			this->back_to_pl_panel->Size = System::Drawing::Size(101, 48);
			this->back_to_pl_panel->TabIndex = 18;
			this->back_to_pl_panel->Text = L"Back";
			this->back_to_pl_panel->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->back_to_pl_panel->UseVisualStyleBackColor = false;
			this->back_to_pl_panel->Click += gcnew System::EventHandler(this, &Home2::back_to_pl_panel_Click);
			// 
			// Fav_playlist_panel
			// 
			this->Fav_playlist_panel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Fav_playlist_panel.BackgroundImage")));
			this->Fav_playlist_panel->Controls->Add(this->delete_song5_btn);
			this->Fav_playlist_panel->Controls->Add(this->delete_song4_btn);
			this->Fav_playlist_panel->Controls->Add(this->delete_song3_btn);
			this->Fav_playlist_panel->Controls->Add(this->delete_song2_btn);
			this->Fav_playlist_panel->Controls->Add(this->delete_song1_btn);
			this->Fav_playlist_panel->Controls->Add(this->shuffle_btn);
			this->Fav_playlist_panel->Controls->Add(this->songs_count);
			this->Fav_playlist_panel->Controls->Add(this->add_song_to_playlist_btn);
			this->Fav_playlist_panel->Controls->Add(this->song_btn_5);
			this->Fav_playlist_panel->Controls->Add(this->song_btn_2);
			this->Fav_playlist_panel->Controls->Add(this->song_btn_3);
			this->Fav_playlist_panel->Controls->Add(this->song_btn_4);
			this->Fav_playlist_panel->Controls->Add(this->song_btn_1);
			this->Fav_playlist_panel->Controls->Add(this->Playlist_name);
			this->Fav_playlist_panel->Controls->Add(this->back_to_pl_frm_fav_btn);
			this->Fav_playlist_panel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Fav_playlist_panel->Location = System::Drawing::Point(0, 0);
			this->Fav_playlist_panel->Margin = System::Windows::Forms::Padding(4);
			this->Fav_playlist_panel->Name = L"Fav_playlist_panel";
			this->Fav_playlist_panel->Size = System::Drawing::Size(1179, 639);
			this->Fav_playlist_panel->TabIndex = 0;
			// 
			// delete_song5_btn
			// 
			this->delete_song5_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(17)), static_cast<System::Int32>(static_cast<System::Byte>(17)),
				static_cast<System::Int32>(static_cast<System::Byte>(17)));
			this->delete_song5_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->delete_song5_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->delete_song5_btn->ForeColor = System::Drawing::Color::Gray;
			this->delete_song5_btn->Location = System::Drawing::Point(769, 347);
			this->delete_song5_btn->Name = L"delete_song5_btn";
			this->delete_song5_btn->Size = System::Drawing::Size(40, 41);
			this->delete_song5_btn->TabIndex = 39;
			this->delete_song5_btn->Text = L"-";
			this->delete_song5_btn->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->delete_song5_btn->UseVisualStyleBackColor = false;
			this->delete_song5_btn->Visible = false;
			this->delete_song5_btn->Click += gcnew System::EventHandler(this, &Home2::delete_song5_btn_Click);
			// 
			// delete_song4_btn
			// 
			this->delete_song4_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(17)), static_cast<System::Int32>(static_cast<System::Byte>(17)),
				static_cast<System::Int32>(static_cast<System::Byte>(17)));
			this->delete_song4_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->delete_song4_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->delete_song4_btn->ForeColor = System::Drawing::Color::Gray;
			this->delete_song4_btn->Location = System::Drawing::Point(769, 288);
			this->delete_song4_btn->Name = L"delete_song4_btn";
			this->delete_song4_btn->Size = System::Drawing::Size(40, 41);
			this->delete_song4_btn->TabIndex = 38;
			this->delete_song4_btn->Text = L"-";
			this->delete_song4_btn->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->delete_song4_btn->UseVisualStyleBackColor = false;
			this->delete_song4_btn->Visible = false;
			this->delete_song4_btn->Click += gcnew System::EventHandler(this, &Home2::delete_song4_btn_Click);
			// 
			// delete_song3_btn
			// 
			this->delete_song3_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(17)), static_cast<System::Int32>(static_cast<System::Byte>(17)),
				static_cast<System::Int32>(static_cast<System::Byte>(17)));
			this->delete_song3_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->delete_song3_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->delete_song3_btn->ForeColor = System::Drawing::Color::Gray;
			this->delete_song3_btn->Location = System::Drawing::Point(769, 229);
			this->delete_song3_btn->Name = L"delete_song3_btn";
			this->delete_song3_btn->Size = System::Drawing::Size(40, 41);
			this->delete_song3_btn->TabIndex = 37;
			this->delete_song3_btn->Text = L"-";
			this->delete_song3_btn->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->delete_song3_btn->UseVisualStyleBackColor = false;
			this->delete_song3_btn->Visible = false;
			this->delete_song3_btn->Click += gcnew System::EventHandler(this, &Home2::delete_song3_btn_Click);
			// 
			// delete_song2_btn
			// 
			this->delete_song2_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(17)), static_cast<System::Int32>(static_cast<System::Byte>(17)),
				static_cast<System::Int32>(static_cast<System::Byte>(17)));
			this->delete_song2_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->delete_song2_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->delete_song2_btn->ForeColor = System::Drawing::Color::Gray;
			this->delete_song2_btn->Location = System::Drawing::Point(769, 169);
			this->delete_song2_btn->Name = L"delete_song2_btn";
			this->delete_song2_btn->Size = System::Drawing::Size(40, 41);
			this->delete_song2_btn->TabIndex = 36;
			this->delete_song2_btn->Text = L"-";
			this->delete_song2_btn->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->delete_song2_btn->UseVisualStyleBackColor = false;
			this->delete_song2_btn->Visible = false;
			this->delete_song2_btn->Click += gcnew System::EventHandler(this, &Home2::delete_song2_btn_Click);
			// 
			// delete_song1_btn
			// 
			this->delete_song1_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(17)), static_cast<System::Int32>(static_cast<System::Byte>(17)),
				static_cast<System::Int32>(static_cast<System::Byte>(17)));
			this->delete_song1_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->delete_song1_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->delete_song1_btn->ForeColor = System::Drawing::Color::Gray;
			this->delete_song1_btn->Location = System::Drawing::Point(769, 113);
			this->delete_song1_btn->Name = L"delete_song1_btn";
			this->delete_song1_btn->Size = System::Drawing::Size(40, 41);
			this->delete_song1_btn->TabIndex = 35;
			this->delete_song1_btn->Text = L"-";
			this->delete_song1_btn->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->delete_song1_btn->UseVisualStyleBackColor = false;
			this->delete_song1_btn->Visible = false;
			this->delete_song1_btn->Click += gcnew System::EventHandler(this, &Home2::delete_song1_btn_Click);
			// 
			// shuffle_btn
			// 
			this->shuffle_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->shuffle_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->shuffle_btn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->shuffle_btn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.25F, System::Drawing::FontStyle::Bold));
			this->shuffle_btn->ForeColor = System::Drawing::Color::White;
			this->shuffle_btn->Location = System::Drawing::Point(670, 414);
			this->shuffle_btn->Margin = System::Windows::Forms::Padding(4);
			this->shuffle_btn->Name = L"shuffle_btn";
			this->shuffle_btn->Size = System::Drawing::Size(142, 56);
			this->shuffle_btn->TabIndex = 32;
			this->shuffle_btn->Text = L"Shuffle";
			this->shuffle_btn->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->shuffle_btn->UseVisualStyleBackColor = false;
			this->shuffle_btn->Click += gcnew System::EventHandler(this, &Home2::shuffle_btn_Click);
			// 
			// songs_count
			// 
			this->songs_count->AutoSize = true;
			this->songs_count->BackColor = System::Drawing::Color::Transparent;
			this->songs_count->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.25F));
			this->songs_count->ForeColor = System::Drawing::Color::Gainsboro;
			this->songs_count->Location = System::Drawing::Point(288, 65);
			this->songs_count->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->songs_count->Name = L"songs_count";
			this->songs_count->Size = System::Drawing::Size(241, 27);
			this->songs_count->TabIndex = 31;
			this->songs_count->Text = L"Your favorite Playlist";
			// 
			// add_song_to_playlist_btn
			// 
			this->add_song_to_playlist_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->add_song_to_playlist_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->add_song_to_playlist_btn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->add_song_to_playlist_btn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.25F, System::Drawing::FontStyle::Bold));
			this->add_song_to_playlist_btn->ForeColor = System::Drawing::Color::White;
			this->add_song_to_playlist_btn->Location = System::Drawing::Point(668, 54);
			this->add_song_to_playlist_btn->Margin = System::Windows::Forms::Padding(4);
			this->add_song_to_playlist_btn->Name = L"add_song_to_playlist_btn";
			this->add_song_to_playlist_btn->Size = System::Drawing::Size(142, 56);
			this->add_song_to_playlist_btn->TabIndex = 30;
			this->add_song_to_playlist_btn->Text = L"+ Add Song";
			this->add_song_to_playlist_btn->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->add_song_to_playlist_btn->UseVisualStyleBackColor = false;
			this->add_song_to_playlist_btn->Click += gcnew System::EventHandler(this, &Home2::add_song_to_playlist_btn_Click);
			// 
			// song_btn_5
			// 
			this->song_btn_5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(17)), static_cast<System::Int32>(static_cast<System::Byte>(17)),
				static_cast<System::Int32>(static_cast<System::Byte>(17)));
			this->song_btn_5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->song_btn_5->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->song_btn_5->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->song_btn_5->ForeColor = System::Drawing::Color::White;
			this->song_btn_5->Location = System::Drawing::Point(41, 347);
			this->song_btn_5->Margin = System::Windows::Forms::Padding(4);
			this->song_btn_5->Name = L"song_btn_5";
			this->song_btn_5->Size = System::Drawing::Size(771, 44);
			this->song_btn_5->TabIndex = 29;
			this->song_btn_5->UseVisualStyleBackColor = false;
			this->song_btn_5->Visible = false;
			this->song_btn_5->Click += gcnew System::EventHandler(this, &Home2::song_btn_5_Click);
			// 
			// song_btn_2
			// 
			this->song_btn_2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(17)), static_cast<System::Int32>(static_cast<System::Byte>(17)),
				static_cast<System::Int32>(static_cast<System::Byte>(17)));
			this->song_btn_2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->song_btn_2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->song_btn_2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->song_btn_2->ForeColor = System::Drawing::Color::White;
			this->song_btn_2->Location = System::Drawing::Point(41, 169);
			this->song_btn_2->Margin = System::Windows::Forms::Padding(4);
			this->song_btn_2->Name = L"song_btn_2";
			this->song_btn_2->Size = System::Drawing::Size(771, 44);
			this->song_btn_2->TabIndex = 28;
			this->song_btn_2->UseVisualStyleBackColor = false;
			this->song_btn_2->Visible = false;
			this->song_btn_2->Click += gcnew System::EventHandler(this, &Home2::song_btn_2_Click);
			// 
			// song_btn_3
			// 
			this->song_btn_3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(17)), static_cast<System::Int32>(static_cast<System::Byte>(17)),
				static_cast<System::Int32>(static_cast<System::Byte>(17)));
			this->song_btn_3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->song_btn_3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->song_btn_3->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->song_btn_3->ForeColor = System::Drawing::Color::White;
			this->song_btn_3->Location = System::Drawing::Point(41, 229);
			this->song_btn_3->Margin = System::Windows::Forms::Padding(4);
			this->song_btn_3->Name = L"song_btn_3";
			this->song_btn_3->Size = System::Drawing::Size(771, 44);
			this->song_btn_3->TabIndex = 27;
			this->song_btn_3->UseVisualStyleBackColor = false;
			this->song_btn_3->Visible = false;
			this->song_btn_3->Click += gcnew System::EventHandler(this, &Home2::song_btn_3_Click);
			// 
			// song_btn_4
			// 
			this->song_btn_4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(17)), static_cast<System::Int32>(static_cast<System::Byte>(17)),
				static_cast<System::Int32>(static_cast<System::Byte>(17)));
			this->song_btn_4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->song_btn_4->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->song_btn_4->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->song_btn_4->ForeColor = System::Drawing::Color::White;
			this->song_btn_4->Location = System::Drawing::Point(41, 288);
			this->song_btn_4->Margin = System::Windows::Forms::Padding(4);
			this->song_btn_4->Name = L"song_btn_4";
			this->song_btn_4->Size = System::Drawing::Size(771, 44);
			this->song_btn_4->TabIndex = 26;
			this->song_btn_4->UseVisualStyleBackColor = false;
			this->song_btn_4->Visible = false;
			this->song_btn_4->Click += gcnew System::EventHandler(this, &Home2::song_btn_4_Click);
			// 
			// song_btn_1
			// 
			this->song_btn_1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(17)), static_cast<System::Int32>(static_cast<System::Byte>(17)),
				static_cast<System::Int32>(static_cast<System::Byte>(17)));
			this->song_btn_1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->song_btn_1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->song_btn_1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->song_btn_1->ForeColor = System::Drawing::Color::White;
			this->song_btn_1->Location = System::Drawing::Point(41, 112);
			this->song_btn_1->Margin = System::Windows::Forms::Padding(4);
			this->song_btn_1->Name = L"song_btn_1";
			this->song_btn_1->Size = System::Drawing::Size(771, 44);
			this->song_btn_1->TabIndex = 25;
			this->song_btn_1->UseVisualStyleBackColor = false;
			this->song_btn_1->Visible = false;
			this->song_btn_1->Click += gcnew System::EventHandler(this, &Home2::song_btn_1_Click);
			// 
			// Playlist_name
			// 
			this->Playlist_name->AutoSize = true;
			this->Playlist_name->BackColor = System::Drawing::Color::Transparent;
			this->Playlist_name->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.25F, System::Drawing::FontStyle::Bold));
			this->Playlist_name->ForeColor = System::Drawing::Color::Gainsboro;
			this->Playlist_name->Location = System::Drawing::Point(36, 65);
			this->Playlist_name->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Playlist_name->Name = L"Playlist_name";
			this->Playlist_name->Size = System::Drawing::Size(234, 27);
			this->Playlist_name->TabIndex = 24;
			this->Playlist_name->Text = L"Your favorite Playlist";
			// 
			// back_to_pl_frm_fav_btn
			// 
			this->back_to_pl_frm_fav_btn->BackColor = System::Drawing::Color::Transparent;
			this->back_to_pl_frm_fav_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->back_to_pl_frm_fav_btn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->back_to_pl_frm_fav_btn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.25F, System::Drawing::FontStyle::Bold));
			this->back_to_pl_frm_fav_btn->ForeColor = System::Drawing::Color::White;
			this->back_to_pl_frm_fav_btn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"back_to_pl_frm_fav_btn.Image")));
			this->back_to_pl_frm_fav_btn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->back_to_pl_frm_fav_btn->Location = System::Drawing::Point(0, 0);
			this->back_to_pl_frm_fav_btn->Margin = System::Windows::Forms::Padding(4);
			this->back_to_pl_frm_fav_btn->Name = L"back_to_pl_frm_fav_btn";
			this->back_to_pl_frm_fav_btn->Size = System::Drawing::Size(101, 48);
			this->back_to_pl_frm_fav_btn->TabIndex = 19;
			this->back_to_pl_frm_fav_btn->Text = L"Back";
			this->back_to_pl_frm_fav_btn->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->back_to_pl_frm_fav_btn->UseVisualStyleBackColor = false;
			this->back_to_pl_frm_fav_btn->Click += gcnew System::EventHandler(this, &Home2::back_to_pl_frm_fav_btn_Click);
			// 
			// Activity_panel
			// 
			this->Activity_panel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Activity_panel.BackgroundImage")));
			this->Activity_panel->Controls->Add(this->search_history_panel);
			this->Activity_panel->Controls->Add(this->recently_played_panel);
			this->Activity_panel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Activity_panel->Location = System::Drawing::Point(0, 0);
			this->Activity_panel->Margin = System::Windows::Forms::Padding(4);
			this->Activity_panel->Name = L"Activity_panel";
			this->Activity_panel->Size = System::Drawing::Size(1179, 639);
			this->Activity_panel->TabIndex = 0;
			// 
			// search_history_panel
			// 
			this->search_history_panel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->search_history_panel->Controls->Add(this->searched_lbl3);
			this->search_history_panel->Controls->Add(this->label10);
			this->search_history_panel->Controls->Add(this->searched_lbl1);
			this->search_history_panel->Controls->Add(this->searched_lbl2);
			this->search_history_panel->Location = System::Drawing::Point(12, 407);
			this->search_history_panel->Margin = System::Windows::Forms::Padding(4);
			this->search_history_panel->Name = L"search_history_panel";
			this->search_history_panel->Size = System::Drawing::Size(887, 178);
			this->search_history_panel->TabIndex = 24;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::Transparent;
			this->label10->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.25F, System::Drawing::FontStyle::Bold));
			this->label10->ForeColor = System::Drawing::Color::Gainsboro;
			this->label10->Location = System::Drawing::Point(15, 20);
			this->label10->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(226, 27);
			this->label10->TabIndex = 23;
			this->label10->Text = L"Your Search History";
			// 
			// recently_played_panel
			// 
			this->recently_played_panel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->recently_played_panel->Controls->Add(this->recent_song7_btn);
			this->recently_played_panel->Controls->Add(this->recent_song6_btn);
			this->recently_played_panel->Controls->Add(this->recent_song5_btn);
			this->recently_played_panel->Controls->Add(this->recent_song4_btn);
			this->recently_played_panel->Controls->Add(this->recent_song3_btn);
			this->recently_played_panel->Controls->Add(this->recent_song2_btn);
			this->recently_played_panel->Controls->Add(this->recent_song1_btn);
			this->recently_played_panel->Controls->Add(this->label9);
			this->recently_played_panel->Location = System::Drawing::Point(13, 4);
			this->recently_played_panel->Margin = System::Windows::Forms::Padding(4);
			this->recently_played_panel->Name = L"recently_played_panel";
			this->recently_played_panel->Size = System::Drawing::Size(887, 391);
			this->recently_played_panel->TabIndex = 23;
			// 
			// recent_song7_btn
			// 
			this->recent_song7_btn->BackColor = System::Drawing::Color::Black;
			this->recent_song7_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->recent_song7_btn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->recent_song7_btn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->recent_song7_btn->ForeColor = System::Drawing::Color::White;
			this->recent_song7_btn->Location = System::Drawing::Point(72, 342);
			this->recent_song7_btn->Margin = System::Windows::Forms::Padding(4);
			this->recent_song7_btn->Name = L"recent_song7_btn";
			this->recent_song7_btn->Size = System::Drawing::Size(771, 44);
			this->recent_song7_btn->TabIndex = 32;
			this->recent_song7_btn->UseVisualStyleBackColor = false;
			this->recent_song7_btn->Visible = false;
			// 
			// recent_song6_btn
			// 
			this->recent_song6_btn->BackColor = System::Drawing::Color::Black;
			this->recent_song6_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->recent_song6_btn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->recent_song6_btn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->recent_song6_btn->ForeColor = System::Drawing::Color::White;
			this->recent_song6_btn->Location = System::Drawing::Point(72, 292);
			this->recent_song6_btn->Margin = System::Windows::Forms::Padding(4);
			this->recent_song6_btn->Name = L"recent_song6_btn";
			this->recent_song6_btn->Size = System::Drawing::Size(771, 44);
			this->recent_song6_btn->TabIndex = 31;
			this->recent_song6_btn->UseVisualStyleBackColor = false;
			this->recent_song6_btn->Visible = false;
			// 
			// recent_song5_btn
			// 
			this->recent_song5_btn->BackColor = System::Drawing::Color::Black;
			this->recent_song5_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->recent_song5_btn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->recent_song5_btn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->recent_song5_btn->ForeColor = System::Drawing::Color::White;
			this->recent_song5_btn->Location = System::Drawing::Point(72, 237);
			this->recent_song5_btn->Margin = System::Windows::Forms::Padding(4);
			this->recent_song5_btn->Name = L"recent_song5_btn";
			this->recent_song5_btn->Size = System::Drawing::Size(771, 44);
			this->recent_song5_btn->TabIndex = 30;
			this->recent_song5_btn->UseVisualStyleBackColor = false;
			this->recent_song5_btn->Visible = false;
			// 
			// recent_song4_btn
			// 
			this->recent_song4_btn->BackColor = System::Drawing::Color::Black;
			this->recent_song4_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->recent_song4_btn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->recent_song4_btn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->recent_song4_btn->ForeColor = System::Drawing::Color::White;
			this->recent_song4_btn->Location = System::Drawing::Point(72, 185);
			this->recent_song4_btn->Margin = System::Windows::Forms::Padding(4);
			this->recent_song4_btn->Name = L"recent_song4_btn";
			this->recent_song4_btn->Size = System::Drawing::Size(771, 44);
			this->recent_song4_btn->TabIndex = 29;
			this->recent_song4_btn->UseVisualStyleBackColor = false;
			this->recent_song4_btn->Visible = false;
			// 
			// recent_song3_btn
			// 
			this->recent_song3_btn->BackColor = System::Drawing::Color::Black;
			this->recent_song3_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->recent_song3_btn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->recent_song3_btn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->recent_song3_btn->ForeColor = System::Drawing::Color::White;
			this->recent_song3_btn->Location = System::Drawing::Point(72, 133);
			this->recent_song3_btn->Margin = System::Windows::Forms::Padding(4);
			this->recent_song3_btn->Name = L"recent_song3_btn";
			this->recent_song3_btn->Size = System::Drawing::Size(771, 44);
			this->recent_song3_btn->TabIndex = 28;
			this->recent_song3_btn->UseVisualStyleBackColor = false;
			this->recent_song3_btn->Visible = false;
			// 
			// recent_song2_btn
			// 
			this->recent_song2_btn->BackColor = System::Drawing::Color::Black;
			this->recent_song2_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->recent_song2_btn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->recent_song2_btn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->recent_song2_btn->ForeColor = System::Drawing::Color::White;
			this->recent_song2_btn->Location = System::Drawing::Point(72, 82);
			this->recent_song2_btn->Margin = System::Windows::Forms::Padding(4);
			this->recent_song2_btn->Name = L"recent_song2_btn";
			this->recent_song2_btn->Size = System::Drawing::Size(771, 44);
			this->recent_song2_btn->TabIndex = 27;
			this->recent_song2_btn->UseVisualStyleBackColor = false;
			this->recent_song2_btn->Visible = false;
			// 
			// recent_song1_btn
			// 
			this->recent_song1_btn->BackColor = System::Drawing::Color::Black;
			this->recent_song1_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->recent_song1_btn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->recent_song1_btn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->recent_song1_btn->ForeColor = System::Drawing::Color::White;
			this->recent_song1_btn->Location = System::Drawing::Point(72, 32);
			this->recent_song1_btn->Margin = System::Windows::Forms::Padding(4);
			this->recent_song1_btn->Name = L"recent_song1_btn";
			this->recent_song1_btn->Size = System::Drawing::Size(771, 44);
			this->recent_song1_btn->TabIndex = 26;
			this->recent_song1_btn->UseVisualStyleBackColor = false;
			this->recent_song1_btn->Visible = false;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::Transparent;
			this->label9->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.25F, System::Drawing::FontStyle::Bold));
			this->label9->ForeColor = System::Drawing::Color::Gainsboro;
			this->label9->Location = System::Drawing::Point(23, 1);
			this->label9->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(265, 27);
			this->label9->TabIndex = 23;
			this->label9->Text = L"Recently Played Songs";
			// 
			// Browse_panel
			// 
			this->Browse_panel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Browse_panel.BackgroundImage")));
			this->Browse_panel->Controls->Add(this->search_browser);
			this->Browse_panel->Controls->Add(this->label13);
			this->Browse_panel->Controls->Add(this->back_frm_brwsr_to_home_btn);
			this->Browse_panel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Browse_panel->Location = System::Drawing::Point(0, 0);
			this->Browse_panel->Margin = System::Windows::Forms::Padding(4);
			this->Browse_panel->Name = L"Browse_panel";
			this->Browse_panel->Size = System::Drawing::Size(1179, 639);
			this->Browse_panel->TabIndex = 0;
			// 
			// search_browser
			// 
			this->search_browser->BackColor = System::Drawing::Color::Transparent;
			this->search_browser->Controls->Add(this->searched_song_btn3);
			this->search_browser->Controls->Add(this->searched_song_btn2);
			this->search_browser->Controls->Add(this->searched_song_btn1);
			this->search_browser->Controls->Add(this->searchbar_panel);
			this->search_browser->Location = System::Drawing::Point(32, 118);
			this->search_browser->Margin = System::Windows::Forms::Padding(4);
			this->search_browser->Name = L"search_browser";
			this->search_browser->Size = System::Drawing::Size(844, 438);
			this->search_browser->TabIndex = 26;
			// 
			// searched_song_btn3
			// 
			this->searched_song_btn3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->searched_song_btn3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->searched_song_btn3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->searched_song_btn3->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->searched_song_btn3->ForeColor = System::Drawing::Color::White;
			this->searched_song_btn3->Location = System::Drawing::Point(33, 197);
			this->searched_song_btn3->Margin = System::Windows::Forms::Padding(4);
			this->searched_song_btn3->Name = L"searched_song_btn3";
			this->searched_song_btn3->Size = System::Drawing::Size(771, 44);
			this->searched_song_btn3->TabIndex = 31;
			this->searched_song_btn3->UseVisualStyleBackColor = false;
			this->searched_song_btn3->Visible = false;
			this->searched_song_btn3->Click += gcnew System::EventHandler(this, &Home2::searched_song_btn3_Click);
			// 
			// searched_song_btn2
			// 
			this->searched_song_btn2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->searched_song_btn2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->searched_song_btn2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->searched_song_btn2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->searched_song_btn2->ForeColor = System::Drawing::Color::White;
			this->searched_song_btn2->Location = System::Drawing::Point(33, 138);
			this->searched_song_btn2->Margin = System::Windows::Forms::Padding(4);
			this->searched_song_btn2->Name = L"searched_song_btn2";
			this->searched_song_btn2->Size = System::Drawing::Size(771, 44);
			this->searched_song_btn2->TabIndex = 30;
			this->searched_song_btn2->UseVisualStyleBackColor = false;
			this->searched_song_btn2->Visible = false;
			this->searched_song_btn2->Click += gcnew System::EventHandler(this, &Home2::searched_song_btn2_Click);
			// 
			// searched_song_btn1
			// 
			this->searched_song_btn1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->searched_song_btn1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->searched_song_btn1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->searched_song_btn1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->searched_song_btn1->ForeColor = System::Drawing::Color::White;
			this->searched_song_btn1->Location = System::Drawing::Point(33, 83);
			this->searched_song_btn1->Margin = System::Windows::Forms::Padding(4);
			this->searched_song_btn1->Name = L"searched_song_btn1";
			this->searched_song_btn1->Size = System::Drawing::Size(771, 44);
			this->searched_song_btn1->TabIndex = 29;
			this->searched_song_btn1->UseVisualStyleBackColor = false;
			this->searched_song_btn1->Visible = false;
			this->searched_song_btn1->Click += gcnew System::EventHandler(this, &Home2::searched_song_btn1_Click);
			// 
			// searchbar_panel
			// 
			this->searchbar_panel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(17)), static_cast<System::Int32>(static_cast<System::Byte>(17)),
				static_cast<System::Int32>(static_cast<System::Byte>(17)));
			this->searchbar_panel->Controls->Add(this->button2);
			this->searchbar_panel->Controls->Add(this->searchbar_TB);
			this->searchbar_panel->Location = System::Drawing::Point(19, 12);
			this->searchbar_panel->Margin = System::Windows::Forms::Padding(4);
			this->searchbar_panel->Name = L"searchbar_panel";
			this->searchbar_panel->Size = System::Drawing::Size(805, 30);
			this->searchbar_panel->TabIndex = 0;
			// 
			// button2
			// 
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.25F, System::Drawing::FontStyle::Bold));
			this->button2->ForeColor = System::Drawing::Color::White;
			this->button2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.Image")));
			this->button2->Location = System::Drawing::Point(768, -2);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(31, 32);
			this->button2->TabIndex = 18;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Home2::button2_Click);
			// 
			// searchbar_TB
			// 
			this->searchbar_TB->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(17)), static_cast<System::Int32>(static_cast<System::Byte>(17)),
				static_cast<System::Int32>(static_cast<System::Byte>(17)));
			this->searchbar_TB->ForeColor = System::Drawing::Color::White;
			this->searchbar_TB->Location = System::Drawing::Point(4, 2);
			this->searchbar_TB->Margin = System::Windows::Forms::Padding(4);
			this->searchbar_TB->Name = L"searchbar_TB";
			this->searchbar_TB->Size = System::Drawing::Size(755, 22);
			this->searchbar_TB->TabIndex = 0;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->BackColor = System::Drawing::Color::Transparent;
			this->label13->Font = (gcnew System::Drawing::Font(L"Century Gothic", 15.25F, System::Drawing::FontStyle::Bold));
			this->label13->ForeColor = System::Drawing::Color::Gainsboro;
			this->label13->Location = System::Drawing::Point(44, 76);
			this->label13->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(109, 30);
			this->label13->TabIndex = 25;
			this->label13->Text = L"Browse!";
			// 
			// back_frm_brwsr_to_home_btn
			// 
			this->back_frm_brwsr_to_home_btn->BackColor = System::Drawing::Color::Transparent;
			this->back_frm_brwsr_to_home_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->back_frm_brwsr_to_home_btn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->back_frm_brwsr_to_home_btn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.25F, System::Drawing::FontStyle::Bold));
			this->back_frm_brwsr_to_home_btn->ForeColor = System::Drawing::Color::White;
			this->back_frm_brwsr_to_home_btn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"back_frm_brwsr_to_home_btn.Image")));
			this->back_frm_brwsr_to_home_btn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->back_frm_brwsr_to_home_btn->Location = System::Drawing::Point(3, 4);
			this->back_frm_brwsr_to_home_btn->Margin = System::Windows::Forms::Padding(4);
			this->back_frm_brwsr_to_home_btn->Name = L"back_frm_brwsr_to_home_btn";
			this->back_frm_brwsr_to_home_btn->Size = System::Drawing::Size(101, 48);
			this->back_frm_brwsr_to_home_btn->TabIndex = 15;
			this->back_frm_brwsr_to_home_btn->Text = L"Back";
			this->back_frm_brwsr_to_home_btn->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->back_frm_brwsr_to_home_btn->UseVisualStyleBackColor = false;
			this->back_frm_brwsr_to_home_btn->Click += gcnew System::EventHandler(this, &Home2::back_frm_brwsr_to_home_btn_Click);
			// 
			// panel_playlist_collection
			// 
			this->panel_playlist_collection->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel_playlist_collection.BackgroundImage")));
			this->panel_playlist_collection->Controls->Add(this->playlist_btn5);
			this->panel_playlist_collection->Controls->Add(this->playlist_btn2);
			this->panel_playlist_collection->Controls->Add(this->playlist_btn3);
			this->panel_playlist_collection->Controls->Add(this->playlist_btn4);
			this->panel_playlist_collection->Controls->Add(this->playlist_btn1);
			this->panel_playlist_collection->Controls->Add(this->label15);
			this->panel_playlist_collection->Controls->Add(this->bck_home_from_playlists_collection);
			this->panel_playlist_collection->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel_playlist_collection->Location = System::Drawing::Point(0, 0);
			this->panel_playlist_collection->Margin = System::Windows::Forms::Padding(4);
			this->panel_playlist_collection->Name = L"panel_playlist_collection";
			this->panel_playlist_collection->Size = System::Drawing::Size(1179, 639);
			this->panel_playlist_collection->TabIndex = 3;
			// 
			// playlist_btn5
			// 
			this->playlist_btn5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->playlist_btn5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->playlist_btn5->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->playlist_btn5->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->playlist_btn5->ForeColor = System::Drawing::Color::White;
			this->playlist_btn5->Location = System::Drawing::Point(41, 347);
			this->playlist_btn5->Margin = System::Windows::Forms::Padding(4);
			this->playlist_btn5->Name = L"playlist_btn5";
			this->playlist_btn5->Size = System::Drawing::Size(771, 44);
			this->playlist_btn5->TabIndex = 29;
			this->playlist_btn5->UseVisualStyleBackColor = false;
			this->playlist_btn5->Visible = false;
			this->playlist_btn5->Click += gcnew System::EventHandler(this, &Home2::playlist_btn5_Click);
			// 
			// playlist_btn2
			// 
			this->playlist_btn2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->playlist_btn2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->playlist_btn2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->playlist_btn2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->playlist_btn2->ForeColor = System::Drawing::Color::White;
			this->playlist_btn2->Location = System::Drawing::Point(41, 169);
			this->playlist_btn2->Margin = System::Windows::Forms::Padding(4);
			this->playlist_btn2->Name = L"playlist_btn2";
			this->playlist_btn2->Size = System::Drawing::Size(771, 44);
			this->playlist_btn2->TabIndex = 28;
			this->playlist_btn2->UseVisualStyleBackColor = false;
			this->playlist_btn2->Visible = false;
			this->playlist_btn2->Click += gcnew System::EventHandler(this, &Home2::playlist_btn2_Click);
			// 
			// playlist_btn3
			// 
			this->playlist_btn3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->playlist_btn3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->playlist_btn3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->playlist_btn3->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->playlist_btn3->ForeColor = System::Drawing::Color::White;
			this->playlist_btn3->Location = System::Drawing::Point(41, 229);
			this->playlist_btn3->Margin = System::Windows::Forms::Padding(4);
			this->playlist_btn3->Name = L"playlist_btn3";
			this->playlist_btn3->Size = System::Drawing::Size(771, 44);
			this->playlist_btn3->TabIndex = 27;
			this->playlist_btn3->UseVisualStyleBackColor = false;
			this->playlist_btn3->Visible = false;
			this->playlist_btn3->Click += gcnew System::EventHandler(this, &Home2::playlist_btn3_Click);
			// 
			// playlist_btn4
			// 
			this->playlist_btn4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->playlist_btn4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->playlist_btn4->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->playlist_btn4->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->playlist_btn4->ForeColor = System::Drawing::Color::White;
			this->playlist_btn4->Location = System::Drawing::Point(41, 288);
			this->playlist_btn4->Margin = System::Windows::Forms::Padding(4);
			this->playlist_btn4->Name = L"playlist_btn4";
			this->playlist_btn4->Size = System::Drawing::Size(771, 44);
			this->playlist_btn4->TabIndex = 26;
			this->playlist_btn4->UseVisualStyleBackColor = false;
			this->playlist_btn4->Visible = false;
			this->playlist_btn4->Click += gcnew System::EventHandler(this, &Home2::playlist_btn4_Click);
			// 
			// playlist_btn1
			// 
			this->playlist_btn1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->playlist_btn1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->playlist_btn1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->playlist_btn1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->playlist_btn1->ForeColor = System::Drawing::Color::White;
			this->playlist_btn1->Location = System::Drawing::Point(41, 112);
			this->playlist_btn1->Margin = System::Windows::Forms::Padding(4);
			this->playlist_btn1->Name = L"playlist_btn1";
			this->playlist_btn1->Size = System::Drawing::Size(771, 44);
			this->playlist_btn1->TabIndex = 25;
			this->playlist_btn1->UseVisualStyleBackColor = false;
			this->playlist_btn1->Visible = false;
			this->playlist_btn1->Click += gcnew System::EventHandler(this, &Home2::playlist_btn1_Click);
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->BackColor = System::Drawing::Color::Transparent;
			this->label15->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.25F, System::Drawing::FontStyle::Bold));
			this->label15->ForeColor = System::Drawing::Color::Gainsboro;
			this->label15->Location = System::Drawing::Point(36, 65);
			this->label15->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(154, 27);
			this->label15->TabIndex = 24;
			this->label15->Text = L"Your Playlists";
			// 
			// bck_home_from_playlists_collection
			// 
			this->bck_home_from_playlists_collection->BackColor = System::Drawing::Color::Transparent;
			this->bck_home_from_playlists_collection->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bck_home_from_playlists_collection->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->bck_home_from_playlists_collection->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.25F, System::Drawing::FontStyle::Bold));
			this->bck_home_from_playlists_collection->ForeColor = System::Drawing::Color::White;
			this->bck_home_from_playlists_collection->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bck_home_from_playlists_collection.Image")));
			this->bck_home_from_playlists_collection->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->bck_home_from_playlists_collection->Location = System::Drawing::Point(0, 0);
			this->bck_home_from_playlists_collection->Margin = System::Windows::Forms::Padding(4);
			this->bck_home_from_playlists_collection->Name = L"bck_home_from_playlists_collection";
			this->bck_home_from_playlists_collection->Size = System::Drawing::Size(101, 48);
			this->bck_home_from_playlists_collection->TabIndex = 19;
			this->bck_home_from_playlists_collection->Text = L"Back";
			this->bck_home_from_playlists_collection->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->bck_home_from_playlists_collection->UseVisualStyleBackColor = false;
			this->bck_home_from_playlists_collection->Click += gcnew System::EventHandler(this, &Home2::bck_home_from_playlists_collection_Click);
			// 
			// songs_to_be_selected_panel
			// 
			this->songs_to_be_selected_panel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"songs_to_be_selected_panel.BackgroundImage")));
			this->songs_to_be_selected_panel->Controls->Add(this->add_song_implemented_btn);
			this->songs_to_be_selected_panel->Controls->Add(this->song5_chbx);
			this->songs_to_be_selected_panel->Controls->Add(this->song4_chbx);
			this->songs_to_be_selected_panel->Controls->Add(this->song3_chbx);
			this->songs_to_be_selected_panel->Controls->Add(this->song2_chbx);
			this->songs_to_be_selected_panel->Controls->Add(this->song1_chbx);
			this->songs_to_be_selected_panel->Controls->Add(this->label12);
			this->songs_to_be_selected_panel->Controls->Add(this->button8);
			this->songs_to_be_selected_panel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->songs_to_be_selected_panel->Location = System::Drawing::Point(0, 0);
			this->songs_to_be_selected_panel->Margin = System::Windows::Forms::Padding(4);
			this->songs_to_be_selected_panel->Name = L"songs_to_be_selected_panel";
			this->songs_to_be_selected_panel->Size = System::Drawing::Size(1179, 639);
			this->songs_to_be_selected_panel->TabIndex = 4;
			// 
			// add_song_implemented_btn
			// 
			this->add_song_implemented_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->add_song_implemented_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->add_song_implemented_btn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->add_song_implemented_btn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->add_song_implemented_btn->ForeColor = System::Drawing::Color::White;
			this->add_song_implemented_btn->Location = System::Drawing::Point(788, 517);
			this->add_song_implemented_btn->Name = L"add_song_implemented_btn";
			this->add_song_implemented_btn->Size = System::Drawing::Size(132, 44);
			this->add_song_implemented_btn->TabIndex = 30;
			this->add_song_implemented_btn->Text = L"ADD";
			this->add_song_implemented_btn->UseVisualStyleBackColor = false;
			this->add_song_implemented_btn->Click += gcnew System::EventHandler(this, &Home2::add_song_implemented_btn_Click);
			// 
			// song5_chbx
			// 
			this->song5_chbx->AutoSize = true;
			this->song5_chbx->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->song5_chbx->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->song5_chbx->ForeColor = System::Drawing::Color::White;
			this->song5_chbx->Location = System::Drawing::Point(89, 362);
			this->song5_chbx->MinimumSize = System::Drawing::Size(600, 45);
			this->song5_chbx->Name = L"song5_chbx";
			this->song5_chbx->Size = System::Drawing::Size(600, 45);
			this->song5_chbx->TabIndex = 29;
			this->song5_chbx->Text = L"Lift Me Up-Rihanna";
			this->song5_chbx->UseVisualStyleBackColor = false;
			// 
			// song4_chbx
			// 
			this->song4_chbx->AutoSize = true;
			this->song4_chbx->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->song4_chbx->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->song4_chbx->ForeColor = System::Drawing::Color::White;
			this->song4_chbx->Location = System::Drawing::Point(89, 307);
			this->song4_chbx->MinimumSize = System::Drawing::Size(600, 45);
			this->song4_chbx->Name = L"song4_chbx";
			this->song4_chbx->Size = System::Drawing::Size(600, 45);
			this->song4_chbx->TabIndex = 28;
			this->song4_chbx->Text = L"Hold On-Justin Bieber";
			this->song4_chbx->UseVisualStyleBackColor = false;
			// 
			// song3_chbx
			// 
			this->song3_chbx->AutoSize = true;
			this->song3_chbx->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->song3_chbx->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->song3_chbx->ForeColor = System::Drawing::Color::White;
			this->song3_chbx->Location = System::Drawing::Point(89, 252);
			this->song3_chbx->MinimumSize = System::Drawing::Size(600, 45);
			this->song3_chbx->Name = L"song3_chbx";
			this->song3_chbx->Size = System::Drawing::Size(600, 45);
			this->song3_chbx->TabIndex = 27;
			this->song3_chbx->Text = L"Ft Jay Z Jail-Kanye West";
			this->song3_chbx->UseVisualStyleBackColor = false;
			// 
			// song2_chbx
			// 
			this->song2_chbx->AutoSize = true;
			this->song2_chbx->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->song2_chbx->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->song2_chbx->ForeColor = System::Drawing::Color::White;
			this->song2_chbx->Location = System::Drawing::Point(89, 197);
			this->song2_chbx->MinimumSize = System::Drawing::Size(600, 45);
			this->song2_chbx->Name = L"song2_chbx";
			this->song2_chbx->Size = System::Drawing::Size(600, 45);
			this->song2_chbx->TabIndex = 26;
			this->song2_chbx->Text = L"Everything I Wanted-Billie Eilish";
			this->song2_chbx->UseVisualStyleBackColor = false;
			// 
			// song1_chbx
			// 
			this->song1_chbx->AutoSize = true;
			this->song1_chbx->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->song1_chbx->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->song1_chbx->ForeColor = System::Drawing::Color::White;
			this->song1_chbx->Location = System::Drawing::Point(89, 137);
			this->song1_chbx->MinimumSize = System::Drawing::Size(600, 45);
			this->song1_chbx->Name = L"song1_chbx";
			this->song1_chbx->Size = System::Drawing::Size(600, 45);
			this->song1_chbx->TabIndex = 25;
			this->song1_chbx->Text = L"Before I Let Go-Beyonce";
			this->song1_chbx->UseVisualStyleBackColor = false;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->BackColor = System::Drawing::Color::Transparent;
			this->label12->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.25F, System::Drawing::FontStyle::Bold));
			this->label12->ForeColor = System::Drawing::Color::Gainsboro;
			this->label12->Location = System::Drawing::Point(36, 65);
			this->label12->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(154, 27);
			this->label12->TabIndex = 24;
			this->label12->Text = L"Your Playlists";
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::Color::Transparent;
			this->button8->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button8->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.25F, System::Drawing::FontStyle::Bold));
			this->button8->ForeColor = System::Drawing::Color::White;
			this->button8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button8.Image")));
			this->button8->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button8->Location = System::Drawing::Point(0, 0);
			this->button8->Margin = System::Windows::Forms::Padding(4);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(101, 48);
			this->button8->TabIndex = 19;
			this->button8->Text = L"Back";
			this->button8->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button8->UseVisualStyleBackColor = false;
			// 
			// songs_panel
			// 
			this->songs_panel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"songs_panel.BackgroundImage")));
			this->songs_panel->Controls->Add(this->sort_btn);
			this->songs_panel->Controls->Add(this->app_song8_btn);
			this->songs_panel->Controls->Add(this->app_song7_btn);
			this->songs_panel->Controls->Add(this->app_song6_btn);
			this->songs_panel->Controls->Add(this->app_song5_btn);
			this->songs_panel->Controls->Add(this->app_song2_btn);
			this->songs_panel->Controls->Add(this->app_song3_btn);
			this->songs_panel->Controls->Add(this->app_song4_btn);
			this->songs_panel->Controls->Add(this->app_song1_btn);
			this->songs_panel->Controls->Add(this->label_songs);
			this->songs_panel->Controls->Add(this->bck_frm_songs_panel_btn);
			this->songs_panel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->songs_panel->Location = System::Drawing::Point(0, 0);
			this->songs_panel->Margin = System::Windows::Forms::Padding(4);
			this->songs_panel->Name = L"songs_panel";
			this->songs_panel->Size = System::Drawing::Size(1179, 639);
			this->songs_panel->TabIndex = 5;
			// 
			// sort_btn
			// 
			this->sort_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->sort_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->sort_btn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->sort_btn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.25F, System::Drawing::FontStyle::Bold));
			this->sort_btn->ForeColor = System::Drawing::Color::White;
			this->sort_btn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->sort_btn->Location = System::Drawing::Point(734, 58);
			this->sort_btn->Margin = System::Windows::Forms::Padding(4);
			this->sort_btn->Name = L"sort_btn";
			this->sort_btn->Size = System::Drawing::Size(80, 48);
			this->sort_btn->TabIndex = 33;
			this->sort_btn->Text = L"Sort";
			this->sort_btn->UseCompatibleTextRendering = true;
			this->sort_btn->UseVisualStyleBackColor = false;
			this->sort_btn->Click += gcnew System::EventHandler(this, &Home2::sort_btn_Click);
			// 
			// app_song8_btn
			// 
			this->app_song8_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->app_song8_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->app_song8_btn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->app_song8_btn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->app_song8_btn->ForeColor = System::Drawing::Color::White;
			this->app_song8_btn->Location = System::Drawing::Point(41, 524);
			this->app_song8_btn->Margin = System::Windows::Forms::Padding(4);
			this->app_song8_btn->Name = L"app_song8_btn";
			this->app_song8_btn->Size = System::Drawing::Size(771, 44);
			this->app_song8_btn->TabIndex = 32;
			this->app_song8_btn->UseVisualStyleBackColor = false;
			this->app_song8_btn->Click += gcnew System::EventHandler(this, &Home2::app_song8_btn_Click);
			// 
			// app_song7_btn
			// 
			this->app_song7_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->app_song7_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->app_song7_btn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->app_song7_btn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->app_song7_btn->ForeColor = System::Drawing::Color::White;
			this->app_song7_btn->Location = System::Drawing::Point(41, 466);
			this->app_song7_btn->Margin = System::Windows::Forms::Padding(4);
			this->app_song7_btn->Name = L"app_song7_btn";
			this->app_song7_btn->Size = System::Drawing::Size(771, 44);
			this->app_song7_btn->TabIndex = 31;
			this->app_song7_btn->UseVisualStyleBackColor = false;
			this->app_song7_btn->Click += gcnew System::EventHandler(this, &Home2::app_song7_btn_Click);
			// 
			// app_song6_btn
			// 
			this->app_song6_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->app_song6_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->app_song6_btn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->app_song6_btn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->app_song6_btn->ForeColor = System::Drawing::Color::White;
			this->app_song6_btn->Location = System::Drawing::Point(41, 407);
			this->app_song6_btn->Margin = System::Windows::Forms::Padding(4);
			this->app_song6_btn->Name = L"app_song6_btn";
			this->app_song6_btn->Size = System::Drawing::Size(771, 44);
			this->app_song6_btn->TabIndex = 30;
			this->app_song6_btn->UseVisualStyleBackColor = false;
			this->app_song6_btn->Click += gcnew System::EventHandler(this, &Home2::app_song6_btn_Click);
			// 
			// app_song5_btn
			// 
			this->app_song5_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->app_song5_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->app_song5_btn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->app_song5_btn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->app_song5_btn->ForeColor = System::Drawing::Color::White;
			this->app_song5_btn->Location = System::Drawing::Point(41, 347);
			this->app_song5_btn->Margin = System::Windows::Forms::Padding(4);
			this->app_song5_btn->Name = L"app_song5_btn";
			this->app_song5_btn->Size = System::Drawing::Size(771, 44);
			this->app_song5_btn->TabIndex = 29;
			this->app_song5_btn->UseVisualStyleBackColor = false;
			this->app_song5_btn->Click += gcnew System::EventHandler(this, &Home2::app_song5_btn_Click);
			// 
			// app_song2_btn
			// 
			this->app_song2_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->app_song2_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->app_song2_btn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->app_song2_btn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->app_song2_btn->ForeColor = System::Drawing::Color::White;
			this->app_song2_btn->Location = System::Drawing::Point(41, 169);
			this->app_song2_btn->Margin = System::Windows::Forms::Padding(4);
			this->app_song2_btn->Name = L"app_song2_btn";
			this->app_song2_btn->Size = System::Drawing::Size(771, 44);
			this->app_song2_btn->TabIndex = 28;
			this->app_song2_btn->UseVisualStyleBackColor = false;
			this->app_song2_btn->Click += gcnew System::EventHandler(this, &Home2::app_song2_btn_Click);
			// 
			// app_song3_btn
			// 
			this->app_song3_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->app_song3_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->app_song3_btn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->app_song3_btn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->app_song3_btn->ForeColor = System::Drawing::Color::White;
			this->app_song3_btn->Location = System::Drawing::Point(41, 229);
			this->app_song3_btn->Margin = System::Windows::Forms::Padding(4);
			this->app_song3_btn->Name = L"app_song3_btn";
			this->app_song3_btn->Size = System::Drawing::Size(771, 44);
			this->app_song3_btn->TabIndex = 27;
			this->app_song3_btn->UseVisualStyleBackColor = false;
			this->app_song3_btn->Click += gcnew System::EventHandler(this, &Home2::app_song3_btn_Click);
			// 
			// app_song4_btn
			// 
			this->app_song4_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->app_song4_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->app_song4_btn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->app_song4_btn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->app_song4_btn->ForeColor = System::Drawing::Color::White;
			this->app_song4_btn->Location = System::Drawing::Point(41, 288);
			this->app_song4_btn->Margin = System::Windows::Forms::Padding(4);
			this->app_song4_btn->Name = L"app_song4_btn";
			this->app_song4_btn->Size = System::Drawing::Size(771, 44);
			this->app_song4_btn->TabIndex = 26;
			this->app_song4_btn->UseVisualStyleBackColor = false;
			this->app_song4_btn->Click += gcnew System::EventHandler(this, &Home2::app_song4_btn_Click);
			// 
			// app_song1_btn
			// 
			this->app_song1_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->app_song1_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->app_song1_btn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->app_song1_btn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->app_song1_btn->ForeColor = System::Drawing::Color::White;
			this->app_song1_btn->Location = System::Drawing::Point(41, 112);
			this->app_song1_btn->Margin = System::Windows::Forms::Padding(4);
			this->app_song1_btn->Name = L"app_song1_btn";
			this->app_song1_btn->Size = System::Drawing::Size(771, 44);
			this->app_song1_btn->TabIndex = 25;
			this->app_song1_btn->UseVisualStyleBackColor = false;
			this->app_song1_btn->Click += gcnew System::EventHandler(this, &Home2::app_song1_btn_Click);
			// 
			// label_songs
			// 
			this->label_songs->AutoSize = true;
			this->label_songs->BackColor = System::Drawing::Color::Transparent;
			this->label_songs->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.25F, System::Drawing::FontStyle::Bold));
			this->label_songs->ForeColor = System::Drawing::Color::Gainsboro;
			this->label_songs->Location = System::Drawing::Point(36, 65);
			this->label_songs->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_songs->Name = L"label_songs";
			this->label_songs->Size = System::Drawing::Size(78, 27);
			this->label_songs->TabIndex = 24;
			this->label_songs->Text = L"Songs";
			// 
			// bck_frm_songs_panel_btn
			// 
			this->bck_frm_songs_panel_btn->BackColor = System::Drawing::Color::Transparent;
			this->bck_frm_songs_panel_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bck_frm_songs_panel_btn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->bck_frm_songs_panel_btn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.25F, System::Drawing::FontStyle::Bold));
			this->bck_frm_songs_panel_btn->ForeColor = System::Drawing::Color::White;
			this->bck_frm_songs_panel_btn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bck_frm_songs_panel_btn.Image")));
			this->bck_frm_songs_panel_btn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->bck_frm_songs_panel_btn->Location = System::Drawing::Point(0, 0);
			this->bck_frm_songs_panel_btn->Margin = System::Windows::Forms::Padding(4);
			this->bck_frm_songs_panel_btn->Name = L"bck_frm_songs_panel_btn";
			this->bck_frm_songs_panel_btn->Size = System::Drawing::Size(101, 48);
			this->bck_frm_songs_panel_btn->TabIndex = 19;
			this->bck_frm_songs_panel_btn->Text = L"Back";
			this->bck_frm_songs_panel_btn->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->bck_frm_songs_panel_btn->UseVisualStyleBackColor = false;
			this->bck_frm_songs_panel_btn->Click += gcnew System::EventHandler(this, &Home2::back_frm_brwsr_to_home_btn_Click);
			// 
			// Home2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1179, 639);
			this->Controls->Add(this->Bottom_panel);
			this->Controls->Add(this->Side_panel);
			this->Controls->Add(this->Home_panel);
			this->Controls->Add(this->Browse_panel);
			this->Controls->Add(this->panel_playlist_collection);
			this->Controls->Add(this->songs_to_be_selected_panel);
			this->Controls->Add(this->Fav_playlist_panel);
			this->Controls->Add(this->Activity_panel);
			this->Controls->Add(this->Add_new_pl_panel);
			this->Controls->Add(this->Playlist_panel);
			this->Controls->Add(this->songs_panel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Home2";
			this->Text = L"Home2";
			this->Side_panel->ResumeLayout(false);
			this->Side_panel->PerformLayout();
			this->search_panel->ResumeLayout(false);
			this->search_panel->PerformLayout();
			this->Bottom_panel->ResumeLayout(false);
			this->last_played_song_panel->ResumeLayout(false);
			this->last_played_song_panel->PerformLayout();
			this->Home_panel->ResumeLayout(false);
			this->Home_panel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->Playlist_panel->ResumeLayout(false);
			this->Playlist_panel->PerformLayout();
			this->playlists_panel->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->Add_new_pl_panel->ResumeLayout(false);
			this->Add_new_pl_panel->PerformLayout();
			this->Fav_playlist_panel->ResumeLayout(false);
			this->Fav_playlist_panel->PerformLayout();
			this->Activity_panel->ResumeLayout(false);
			this->search_history_panel->ResumeLayout(false);
			this->search_history_panel->PerformLayout();
			this->recently_played_panel->ResumeLayout(false);
			this->recently_played_panel->PerformLayout();
			this->Browse_panel->ResumeLayout(false);
			this->Browse_panel->PerformLayout();
			this->search_browser->ResumeLayout(false);
			this->searchbar_panel->ResumeLayout(false);
			this->searchbar_panel->PerformLayout();
			this->panel_playlist_collection->ResumeLayout(false);
			this->panel_playlist_collection->PerformLayout();
			this->songs_to_be_selected_panel->ResumeLayout(false);
			this->songs_to_be_selected_panel->PerformLayout();
			this->songs_panel->ResumeLayout(false);
			this->songs_panel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	

private: System::Void back_frm_brwsr_to_home_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	Home_panel->Show();
	Home_panel->BringToFront();
}
private: System::Void back_frm_artists_to_home_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	Home_panel->Show();
	Home_panel->BringToFront();
}
private: System::Void back_frm_pl_to_home_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	Home_panel->Show();
	Home_panel->BringToFront();
}
private: System::Void add_playlist_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	Add_new_pl_panel->Show();
	Add_new_pl_panel->BringToFront();

}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	hide_delete_songs_buttons();
	hide_songs_buttons();
	playlist fav_p = current_user.get_fav_playlist();
	SinglyLinkedListNode* temp = fav_p.get_songs().getHead();
	int count = fav_p.get_songs().getCount();
	std::string songs_number = "NO. Songs : " + std::to_string(count);
	songs_count->Text = gcnew String{ songs_number.c_str() };
	String^ str;
	Playlist_name->Text = "Your favorite Playlist";
	if (count > 0) {
		str = gcnew String{ temp->getData().getName().c_str() };
		song_btn_1->Text = str;
		song_btn_1->Visible = true;
	}
	if (count > 1) {
		temp = temp->getNext();
		str = gcnew String{ temp->getData().getName().c_str() };
		song_btn_2->Text = str;
		song_btn_2->Visible = true;
	}
	if (count > 2) {
		temp = temp->getNext();
		str = gcnew String{ temp->getData().getName().c_str() };
		song_btn_3->Text = str;
		song_btn_3->Visible = true;
	}
	if (count > 3) {
		temp = temp->getNext();
		str = gcnew String{ temp->getData().getName().c_str() };
		song_btn_4->Text = str;
		song_btn_4->Visible = true;
	}
	if (count > 4) {
		temp = temp->getNext();
		str = gcnew String{ temp->getData().getName().c_str() };
		song_btn_5->Text = str;
		song_btn_5->Visible = true;
	}
	
	Fav_playlist_panel->Show();
	Fav_playlist_panel->BringToFront();
}
private: System::Void back_to_pl_panel_Click(System::Object^ sender, System::EventArgs^ e) {
	Playlist_panel->Show();
	Playlist_panel->BringToFront();
}
private: System::Void back_to_pl_frm_fav_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	Playlist_panel->Show();
	Playlist_panel->BringToFront();
}
private: System::Void back_from_act_to_home_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	Home_panel->Show();
	Home_panel->BringToFront();
}
private: System::Void browse_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	Browse_panel->Show();
	Browse_panel->BringToFront();
}
private: System::Void activity_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	int count = 0;
	std::stack<song> recently_played = current_user.recently_played_songs();
	if (!recently_played.empty()) {
		song* temp = &recently_played.top();
		String^ str;
		while (!recently_played.empty()) {
			temp = &recently_played.top();
			if (count == 0) {
				str = gcnew String{ temp->getName().c_str() };
				recent_song1_btn->Text = str;
				recent_song1_btn->Visible = true;
			}
			if (count == 1) {
				str = gcnew String{ temp->getName().c_str() };
				recent_song2_btn->Text = str;
				recent_song2_btn->Visible = true;
			}
			if (count == 2) {
				str = gcnew String{ temp->getName().c_str() };
				recent_song3_btn->Text = str;
				recent_song3_btn->Visible = true;
			}
			if (count == 3) {
				str = gcnew String{ temp->getName().c_str() };
				recent_song4_btn->Text = str;
				recent_song4_btn->Visible = true;
			}
			if (count == 4) {
				str = gcnew String{ temp->getName().c_str() };
				recent_song5_btn->Text = str;
				recent_song5_btn->Visible = true;
			}
			if (count == 5) {
				str = gcnew String{ temp->getName().c_str() };
				recent_song6_btn->Text = str;
				recent_song6_btn->Visible = true;
			}
			if (count == 6) {
				str = gcnew String{ temp->getName().c_str() };
				recent_song7_btn->Text = str;
				recent_song7_btn->Visible = true;
			}
			recently_played.pop();
			count++;
		}
	}
	else {
		recent_song1_btn->Text = "No recently played functions";
	}
	
	
	////////////////////////////////////////////////////////////////
	std::stack<std::string> search_history = current_user.get_search_history();
	if (!search_history.empty()) {
		int count = search_history.size();
		std::string name = search_history.top();
		String^ str;
		if (count > 0) {
			str = gcnew String{ name.c_str() };
			searched_lbl1->Text = str;
			searched_lbl1->Visible = true;
		}
		if (count > 1) {
			search_history.pop();
			name = search_history.top();
			str = gcnew String{ name.c_str() };
			searched_lbl2->Text = str;
			searched_lbl2->Visible = true;
		}
		if (count > 2) {
			search_history.pop();
			name = search_history.top();
			str = gcnew String{ name.c_str() };
			searched_lbl3->Text = str;
			searched_lbl3->Visible = true;
		}
	}
	
	Activity_panel->Show();
	Activity_panel->BringToFront();
}
private: System::Void playlists_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	Playlist_panel->Show();
	Playlist_panel->BringToFront();
}

private: System::Void create_playlist_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string playlist_name = msclr::interop::marshal_as<std::string>(TB_playlist_name->Text);
	current_user.create_playlist(playlist_name);
	Playlist_panel->Show();
	Playlist_panel->BringToFront();
}
private: System::Void my_playlists_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	hide_playlists_buttons();
	std::queue<playlist> user_playlists = current_user.get_playlists();
	int count = user_playlists.size();
	if (!user_playlists.empty()) {
		playlist temp = user_playlists.front();
		String^ str;
		if (count > 0) {
			str = gcnew String{ temp.get_name().c_str() };
			playlist_btn1->Text = str;
			playlist_btn1->Visible = true;
		}
		if (count > 1) {
			user_playlists.pop();
			temp = user_playlists.front();
			str = gcnew String{ temp.get_name().c_str() };
			playlist_btn2->Text = str;
			playlist_btn2->Visible = true;
		}
		if (count > 2) {
			user_playlists.pop();
			temp = user_playlists.front();
			str = gcnew String{ temp.get_name().c_str() };
			playlist_btn3->Text = str;
			playlist_btn3->Visible = true;
		}
		if (count > 3) {
			user_playlists.pop();
			temp = user_playlists.front();
			str = gcnew String{ temp.get_name().c_str() };
			playlist_btn4->Text = str;
			playlist_btn4->Visible = true;
		}
		if (count > 4) {
			user_playlists.pop();
			temp = user_playlists.front();
			str = gcnew String{ temp.get_name().c_str() };
			playlist_btn5->Text = str;
			playlist_btn5->Visible = true;
		}
	}
	panel_playlist_collection->Show();
	panel_playlist_collection->BringToFront();
}
private: System::Void bck_home_from_playlists_collection_Click(System::Object^ sender, System::EventArgs^ e) {
	Playlist_panel->Show();
	Playlist_panel->BringToFront();
}

private: System::Void playlist_btn1_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string playlist_name = msclr::interop::marshal_as<std::string>(playlist_btn1->Text);
	display_songs_in_playlist(playlist_name);

	Fav_playlist_panel->Show();
	Fav_playlist_panel->BringToFront();
}
private: System::Void add_song_to_playlist_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	songs_to_be_selected_panel->BringToFront();
	songs_to_be_selected_panel->Show();
}
private: System::Void add_song_implemented_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string song_name;
	std::string playlist_name = msclr::interop::marshal_as<std::string>(Playlist_name->Text);
	playlist* p = current_user.get_playlist_by_name(playlist_name);
	if (song1_chbx->Checked == true) {
		song_name = msclr::interop::marshal_as<std::string>(song1_chbx->Text);
		song s(song_name);
		p->add_song_to_playlist(s);
	}
	if (song2_chbx->Checked == true) {
		song_name = msclr::interop::marshal_as<std::string>(song2_chbx->Text);
		song s(song_name);
		p->add_song_to_playlist(s);
	}
	if (song3_chbx->Checked == true) {
		song_name = msclr::interop::marshal_as<std::string>(song3_chbx->Text);
		song s(song_name);
		p->add_song_to_playlist(s);
	}
	if (song4_chbx->Checked == true) {
		song_name = msclr::interop::marshal_as<std::string>(song4_chbx->Text);
		song s(song_name);
		p->add_song_to_playlist(s);
	}
	if (song5_chbx->Checked == true) {
		song_name = msclr::interop::marshal_as<std::string>(song5_chbx->Text);
		song s(song_name);
		p->add_song_to_playlist(s);
	}
	UncheckAll();
	Playlist_panel->BringToFront();
	Playlist_panel->Show();
}
private: System::Void song_btn_1_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string song_name = msclr::interop::marshal_as<std::string>(song_btn_1->Text);
	play_song(song_name);
}
private: System::Void song_btn_2_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string song_name = msclr::interop::marshal_as<std::string>(song_btn_2->Text);
	play_song(song_name);
}
private: System::Void song_btn_3_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string song_name = msclr::interop::marshal_as<std::string>(song_btn_3->Text);
	play_song(song_name);
}
private: System::Void song_btn_4_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string song_name = msclr::interop::marshal_as<std::string>(song_btn_4->Text);
	play_song(song_name);
}
private: System::Void song_btn_5_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string song_name = msclr::interop::marshal_as<std::string>(song_btn_5->Text);
	play_song(song_name);
}
private: System::Void pause_play_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	// TO DO
}
private: System::Void shuffle_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	if (type_no == 3) {
		type_no = 1;
	}
	else {
		type_no++;
	}
	playlist p;
	if (Playlist_name->Text == "Your favorite Playlist") {
		p = current_user.get_fav_playlist();		
	}
	else {
		std::string playlist_name = msclr::interop::marshal_as<std::string>(Playlist_name->Text);
		playlist* p_copy = new playlist ( *current_user.get_playlist_by_name(playlist_name));
		p = *p_copy;
	}
	SinglyLinkedList* shuffled = p.Shuffle_playist(type_no);
	SinglyLinkedListNode* temp = shuffled->getHead();
	int count = p.get_songs().getCount();
	std::string songs_number = "NO. Songs : " + std::to_string(count);
	songs_count->Text = gcnew String{ songs_number.c_str() };

	String^ str;
	if (count > 0) {
		str = gcnew String{ temp->getData().getName().c_str() };
		song_btn_1->Text = str;
		song_btn_1->Visible = true;
	}
	if (count > 1) {
		temp = temp->getNext();
		str = gcnew String{ temp->getData().getName().c_str() };
		song_btn_2->Text = str;
		song_btn_2->Visible = true;
	}
	if (count > 2) {
		temp = temp->getNext();
		str = gcnew String{ temp->getData().getName().c_str() };
		song_btn_3->Text = str;
		song_btn_3->Visible = true;
	}
	if (count > 3) {
		temp = temp->getNext();
		str = gcnew String{ temp->getData().getName().c_str() };
		song_btn_4->Text = str;
		song_btn_4->Visible = true;
	}
	if (count > 4) {
		temp = temp->getNext();
		str = gcnew String{ temp->getData().getName().c_str() };
		song_btn_5->Text = str;
		song_btn_5->Visible = true;
	}
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	// search button click function
	std::string search_text = msclr::interop::marshal_as<std::string>(searchbar_TB->Text);
	SinglyLinkedList* l = current_user.search(search_text);

	SinglyLinkedListNode* temp = l->getHead();

	int count = l->getCount();

	String^ str;
	if (count > 0) {
		str = gcnew String{ temp->getData().getName().c_str() };
		searched_song_btn1->Text = str;
		searched_song_btn1->Visible = true;
	}
	if (count > 1) {
		temp = temp->getNext();
		str = gcnew String{ temp->getData().getName().c_str() };
		searched_song_btn2->Text = str;
		searched_song_btn2->Visible = true;
	}
	if (count > 2) {
		temp = temp->getNext();
		str = gcnew String{ temp->getData().getName().c_str() };
		searched_song_btn3->Text = str;
		searched_song_btn3->Visible = true;
	}
}
private: System::Void searched_song_btn1_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string song_name = msclr::interop::marshal_as<std::string>(searched_song_btn1->Text);
	play_song(song_name);
}
private: System::Void searched_song_btn2_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string song_name = msclr::interop::marshal_as<std::string>(searched_song_btn2->Text);
	play_song(song_name);
}
private: System::Void searched_song_btn3_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string song_name = msclr::interop::marshal_as<std::string>(searched_song_btn3->Text);
	play_song(song_name);
}
private: System::Void app_song1_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string song_name = msclr::interop::marshal_as<std::string>(app_song1_btn->Text);
	play_song(song_name);

}
private: System::Void app_song2_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string song_name = msclr::interop::marshal_as<std::string>(app_song2_btn->Text);
	play_song(song_name);
}
private: System::Void app_song3_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string song_name = msclr::interop::marshal_as<std::string>(app_song3_btn->Text);
	play_song(song_name);
}
private: System::Void app_song4_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string song_name = msclr::interop::marshal_as<std::string>(app_song4_btn->Text);
	play_song(song_name);
}
private: System::Void app_song5_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string song_name = msclr::interop::marshal_as<std::string>(app_song5_btn->Text);
	play_song(song_name);
}
private: System::Void app_song6_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string song_name = msclr::interop::marshal_as<std::string>(app_song6_btn->Text);
	play_song(song_name);
}
private: System::Void app_song7_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string song_name = msclr::interop::marshal_as<std::string>(app_song7_btn->Text);
	play_song(song_name);
}
private: System::Void app_song8_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string song_name = msclr::interop::marshal_as<std::string>(app_song8_btn->Text);
	play_song(song_name);
}
private: System::Void song_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	playlist p = current_user.get_app_songs();
	display_songs(p);
	songs_panel->Show();
	songs_panel->BringToFront();
}
private: System::Void sort_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	playlist p = current_user.get_app_songs();
	if (sort_flag) {
		p.sort_number_of_plays();
		sort_flag = false;
	}
	else {
		p.reverse_sort_number_of_plays();
		sort_flag = true;
	}

	display_songs(p);

}
private: System::Void delete_song1_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string song_name = msclr::interop::marshal_as<std::string>(song_btn_1->Text);
	std::string playlist_name = msclr::interop::marshal_as<std::string>(Playlist_name->Text);
	playlist* user_playlist = current_user.get_playlist_by_name(playlist_name);
	int pos= user_playlist->get_position_of_song(song_name);
	user_playlist->delete_song_from_playlist(pos);
	display_songs_in_playlist(playlist_name);
}
private: System::Void delete_song2_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string song_name = msclr::interop::marshal_as<std::string>(song_btn_2->Text);
	std::string playlist_name = msclr::interop::marshal_as<std::string>(Playlist_name->Text);
	playlist* user_playlist = current_user.get_playlist_by_name(playlist_name);
	int pos = user_playlist->get_position_of_song(song_name);
	user_playlist->delete_song_from_playlist(pos);
	display_songs_in_playlist(playlist_name);
}
private: System::Void delete_song3_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string song_name = msclr::interop::marshal_as<std::string>(song_btn_3->Text);
	std::string playlist_name = msclr::interop::marshal_as<std::string>(Playlist_name->Text);
	playlist* user_playlist = current_user.get_playlist_by_name(playlist_name);
	int pos = user_playlist->get_position_of_song(song_name);
	user_playlist->delete_song_from_playlist(pos);
	display_songs_in_playlist(playlist_name);
}
private: System::Void delete_song4_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string song_name = msclr::interop::marshal_as<std::string>(song_btn_4->Text);
	std::string playlist_name = msclr::interop::marshal_as<std::string>(Playlist_name->Text);
	playlist* user_playlist = current_user.get_playlist_by_name(playlist_name);
	int pos = user_playlist->get_position_of_song(song_name);
	user_playlist->delete_song_from_playlist(pos);
	display_songs_in_playlist(playlist_name);
}
private: System::Void delete_song5_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string song_name = msclr::interop::marshal_as<std::string>(song_btn_5->Text);
	std::string playlist_name = msclr::interop::marshal_as<std::string>(Playlist_name->Text);
	playlist* user_playlist = current_user.get_playlist_by_name(playlist_name);
	int pos = user_playlist->get_position_of_song(song_name);
	user_playlist->delete_song_from_playlist(pos);
	display_songs_in_playlist(playlist_name);
}
private: System::Void logout_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	current_user.store();
}
private: System::Void playlist_btn2_Click(System::Object^ sender, System::EventArgs^ e) {
	///////
	std::string playlist_name = msclr::interop::marshal_as<std::string>(playlist_btn2->Text);
	display_songs_in_playlist(playlist_name);

	Fav_playlist_panel->Show();
	Fav_playlist_panel->BringToFront();
}
private: System::Void playlist_btn3_Click(System::Object^ sender, System::EventArgs^ e) {
	////////
	std::string playlist_name = msclr::interop::marshal_as<std::string>(playlist_btn3->Text);
	display_songs_in_playlist(playlist_name);

	Fav_playlist_panel->Show();
	Fav_playlist_panel->BringToFront();
}
private: System::Void playlist_btn4_Click(System::Object^ sender, System::EventArgs^ e) {
	/////////
	std::string playlist_name = msclr::interop::marshal_as<std::string>(playlist_btn4->Text);
	display_songs_in_playlist(playlist_name);

	Fav_playlist_panel->Show();
	Fav_playlist_panel->BringToFront();
}
private: System::Void playlist_btn5_Click(System::Object^ sender, System::EventArgs^ e) {
	//////////
	std::string playlist_name = msclr::interop::marshal_as<std::string>(playlist_btn5->Text);
	display_songs_in_playlist(playlist_name);

	Fav_playlist_panel->Show();
	Fav_playlist_panel->BringToFront();
}
};
}
