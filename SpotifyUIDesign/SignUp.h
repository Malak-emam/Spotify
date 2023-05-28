#pragma once
#include"Home2.h"
#include <string>
#include <fstream>
#include <sstream>



namespace SpotifyUIDesign {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Summary for SignUp
	/// </summary>
	public ref class SignUp : public System::Windows::Forms::Form
	{

	
	public:
		Form^ activeForm;
	private: System::Windows::Forms::Button^ button1;
	public:
	private: System::Windows::Forms::Label^ gen_Pass_value;
	private: System::Windows::Forms::Label^ gen_ID_value;
	private: System::Windows::Forms::Label^ Invalid_credentials_lbl;
	private: System::Windows::Forms::Button^ sign_up_with_google_btn;
	private: System::Windows::Forms::Panel^ sign_up_with_google_panel;
	private: System::Windows::Forms::Button^ s_up_google_btn2;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ continue_btn2;
	private: System::Windows::Forms::Label^ g_pass_lbl;
	private: System::Windows::Forms::Label^ g_id_lbl;



	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::TextBox^ email_TB;

	private: System::Windows::Forms::Panel^ panel6;


	private: System::Windows::Forms::Label^ password_googl_lbl;
	private: System::Windows::Forms::Label^ Email_lbl;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::TextBox^ password_TB;
	private: System::Windows::Forms::Label^ Invalid_google_lbl;

















	public:

	public:
		SignUp^ instance;
		SignUp(void)
		{
			instance = this;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

		}
		user signup(std::string phone_number, std::string first_name, std::string last_name)
		{
			std::fstream f;
			f.open(first_name + last_name + "000.txt", std::ios::app);

			if (f.is_open()) {
				f << "ID : " << first_name + last_name + "000" << "\n"
					<< "Password : " << first_name + last_name + "000" << "\n"
					<< "First Name : " << first_name << "\n"
					<< "Last Name : " << last_name << "\n"
					<< "Phone Number : " << phone_number << "\n"
					<< "----------------------------" << "\n"
					<< "Favorite Playlist"<< "\n";
				f.close();

			}
			user u1(first_name, last_name, phone_number);
			return u1;
		}
		bool endsWith(std::string const& str, std::string const& suffix) {
			if (str.length() < suffix.length()) {
				return false;
			}
			return str.compare(str.length() - suffix.length(), suffix.length(), suffix) == 0;
		}
		user* signUpWithGoogle(std::string email, std::string password) {
			if (email != "" && password != "") {
				std::string suffix = "@gmail.com";
				if (endsWith(email, suffix)) {
					int pos = email.find("@");
					std::string prefix = email.substr(0, pos);
					std::fstream f;
					f.open(prefix + "000.txt", std::ios::app);
					if (f.is_open()) {
						f << "ID : " << prefix + "000" << "\n"
							<< "Password : " << prefix + "000" << "\n"
							<< "First Name : " << prefix << "\n"
							<< "Last Name : " << "000" << "\n"
							<< "Phone Number : " << "000000000000" << "\n";
						f.close();
					}
					user* myuser = new user(prefix,"","000000000000");
					return myuser;
				}
				else {
					return NULL;
				}
			}

		}

		user* login(std::string uniqueID, std::string password) {
			if (uniqueID != password)
				return NULL;
			std::ifstream ff((uniqueID + ".txt").c_str());
			if (!ff.good())
				return NULL;


			std::ifstream infile(uniqueID + ".txt");
			std::string line, data;
			user* myuser;
			std::string personalInfo[5];
			int i = 0;
			int pos;
			while (std::getline(infile, line))
			{
				if (i < 5)
				{
					std::istringstream iss(line);
					if (line == "")
						break;
					pos = line.find(":");
					data = line.substr(pos + 2);
					//std::cout << data << endl;
					personalInfo[i] = data;
					i++;
				}
				else if (i == 5) {
					myuser = new user(personalInfo[2], personalInfo[3], personalInfo[4]);
					//cout << line << endl;
					std::getline(infile, line);
					i++;
				}
				else if (!(line.substr(0, 3) == "---")) {
					song s(line);
					myuser->add_to_fav_playlist(s);
				}
			}
			myuser->load();
			return myuser;
		}
	
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SignUp()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ LoadingPage;
	private: System::Windows::Forms::Panel^ Sign_up;
	private: System::Windows::Forms::Panel^ LogIn;
	private: System::Windows::Forms::Panel^ PickFavArtists;
	private: System::Windows::Forms::Panel^ bottom_load2;
	private: System::Windows::Forms::Panel^ bottomloadbg;


	private: System::Windows::Forms::Timer^ timer1;
private: System::Windows::Forms::Label^ id_lbl;




	private: System::Windows::Forms::Label^ spotifylabel;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ Login_btn;
	private: System::Windows::Forms::Label^ newacc_lbl;

	private: System::Windows::Forms::Panel^ Passwordpanel;
	private: System::Windows::Forms::TextBox^ PassTB;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ IDpanel;
	private: System::Windows::Forms::TextBox^ ID_TB;
	private: System::Windows::Forms::Label^ signup_lbl;
	private: System::Windows::Forms::Label^ forgot_lbl;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::PictureBox^ pictureBox2;


	private: System::Windows::Forms::Panel^ FN_panel;
	private: System::Windows::Forms::Panel^ LN_panel;
	private: System::Windows::Forms::TextBox^ LN_TB;



	private: System::Windows::Forms::TextBox^ FN_TB;



	private: System::Windows::Forms::Label^ PN_lbl;
	private: System::Windows::Forms::Label^ LN_lbl;
	private: System::Windows::Forms::Label^ FN_lbl;
	private: System::Windows::Forms::Panel^ PN_panel;
	private: System::Windows::Forms::TextBox^ PN_TB;
	private: System::Windows::Forms::Button^ signup_btn;

	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::Panel^ Priv_Info_panel;
	private: System::Windows::Forms::Label^ gen_Pass;
	private: System::Windows::Forms::Label^ gen_ID;
	private: System::Windows::Forms::Panel^ vertical_line;
	private: System::Windows::Forms::PictureBox^ beyonce_pic;


	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ PickFav_lbl;
	private: System::Windows::Forms::CheckBox^ weeknd_chbx;



	private: System::Windows::Forms::PictureBox^ weeknd_pic;
	private: System::Windows::Forms::CheckBox^ kanye_chbx;


	private: System::Windows::Forms::PictureBox^ kanye_pic;
	private: System::Windows::Forms::CheckBox^ billie_chbx;


	private: System::Windows::Forms::PictureBox^ billie_pic;
	private: System::Windows::Forms::CheckBox^ jb_chbx;
	private: System::Windows::Forms::CheckBox^ harrys_chbx;



	private: System::Windows::Forms::PictureBox^ jb_pic;
	private: System::Windows::Forms::PictureBox^ harrys_pic;
	private: System::Windows::Forms::CheckBox^ rihanna_chbx;



	private: System::Windows::Forms::PictureBox^ rihanna_pic;
private: System::Windows::Forms::CheckBox^ am_chbx;


	private: System::Windows::Forms::PictureBox^ am_pic;
	private: System::Windows::Forms::CheckBox^ beyonce_chbx;


private: System::Windows::Forms::Button^ next_to_home_btn;
private: System::Windows::Forms::Button^ skip_btn;


















	private: System::ComponentModel::IContainer^ components;
	protected:

	protected:

	private:
		//user* current_user;
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(SignUp::typeid));
			this->LoadingPage = (gcnew System::Windows::Forms::Panel());
			this->bottom_load2 = (gcnew System::Windows::Forms::Panel());
			this->bottomloadbg = (gcnew System::Windows::Forms::Panel());
			this->Sign_up = (gcnew System::Windows::Forms::Panel());
			this->sign_up_with_google_btn = (gcnew System::Windows::Forms::Button());
			this->Priv_Info_panel = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->gen_Pass_value = (gcnew System::Windows::Forms::Label());
			this->gen_ID_value = (gcnew System::Windows::Forms::Label());
			this->gen_Pass = (gcnew System::Windows::Forms::Label());
			this->gen_ID = (gcnew System::Windows::Forms::Label());
			this->vertical_line = (gcnew System::Windows::Forms::Panel());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->signup_btn = (gcnew System::Windows::Forms::Button());
			this->PN_panel = (gcnew System::Windows::Forms::Panel());
			this->PN_TB = (gcnew System::Windows::Forms::TextBox());
			this->FN_panel = (gcnew System::Windows::Forms::Panel());
			this->FN_TB = (gcnew System::Windows::Forms::TextBox());
			this->LN_panel = (gcnew System::Windows::Forms::Panel());
			this->LN_TB = (gcnew System::Windows::Forms::TextBox());
			this->PN_lbl = (gcnew System::Windows::Forms::Label());
			this->LN_lbl = (gcnew System::Windows::Forms::Label());
			this->FN_lbl = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->LogIn = (gcnew System::Windows::Forms::Panel());
			this->Invalid_credentials_lbl = (gcnew System::Windows::Forms::Label());
			this->forgot_lbl = (gcnew System::Windows::Forms::Label());
			this->signup_lbl = (gcnew System::Windows::Forms::Label());
			this->Login_btn = (gcnew System::Windows::Forms::Button());
			this->newacc_lbl = (gcnew System::Windows::Forms::Label());
			this->Passwordpanel = (gcnew System::Windows::Forms::Panel());
			this->PassTB = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->IDpanel = (gcnew System::Windows::Forms::Panel());
			this->ID_TB = (gcnew System::Windows::Forms::TextBox());
			this->id_lbl = (gcnew System::Windows::Forms::Label());
			this->spotifylabel = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->PickFavArtists = (gcnew System::Windows::Forms::Panel());
			this->next_to_home_btn = (gcnew System::Windows::Forms::Button());
			this->skip_btn = (gcnew System::Windows::Forms::Button());
			this->weeknd_chbx = (gcnew System::Windows::Forms::CheckBox());
			this->weeknd_pic = (gcnew System::Windows::Forms::PictureBox());
			this->kanye_chbx = (gcnew System::Windows::Forms::CheckBox());
			this->kanye_pic = (gcnew System::Windows::Forms::PictureBox());
			this->billie_chbx = (gcnew System::Windows::Forms::CheckBox());
			this->billie_pic = (gcnew System::Windows::Forms::PictureBox());
			this->jb_chbx = (gcnew System::Windows::Forms::CheckBox());
			this->harrys_chbx = (gcnew System::Windows::Forms::CheckBox());
			this->jb_pic = (gcnew System::Windows::Forms::PictureBox());
			this->harrys_pic = (gcnew System::Windows::Forms::PictureBox());
			this->rihanna_chbx = (gcnew System::Windows::Forms::CheckBox());
			this->rihanna_pic = (gcnew System::Windows::Forms::PictureBox());
			this->am_chbx = (gcnew System::Windows::Forms::CheckBox());
			this->am_pic = (gcnew System::Windows::Forms::PictureBox());
			this->beyonce_chbx = (gcnew System::Windows::Forms::CheckBox());
			this->beyonce_pic = (gcnew System::Windows::Forms::PictureBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->PickFav_lbl = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->sign_up_with_google_panel = (gcnew System::Windows::Forms::Panel());
			this->Invalid_google_lbl = (gcnew System::Windows::Forms::Label());
			this->s_up_google_btn2 = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->continue_btn2 = (gcnew System::Windows::Forms::Button());
			this->g_pass_lbl = (gcnew System::Windows::Forms::Label());
			this->g_id_lbl = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->email_TB = (gcnew System::Windows::Forms::TextBox());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->password_TB = (gcnew System::Windows::Forms::TextBox());
			this->password_googl_lbl = (gcnew System::Windows::Forms::Label());
			this->Email_lbl = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->LoadingPage->SuspendLayout();
			this->Sign_up->SuspendLayout();
			this->Priv_Info_panel->SuspendLayout();
			this->PN_panel->SuspendLayout();
			this->FN_panel->SuspendLayout();
			this->LN_panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->LogIn->SuspendLayout();
			this->Passwordpanel->SuspendLayout();
			this->IDpanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->PickFavArtists->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->weeknd_pic))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kanye_pic))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->billie_pic))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->jb_pic))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->harrys_pic))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rihanna_pic))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->am_pic))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->beyonce_pic))->BeginInit();
			this->sign_up_with_google_panel->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->SuspendLayout();
			// 
			// LoadingPage
			// 
			this->LoadingPage->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"LoadingPage.BackgroundImage")));
			this->LoadingPage->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->LoadingPage->Controls->Add(this->bottom_load2);
			this->LoadingPage->Controls->Add(this->bottomloadbg);
			this->LoadingPage->Dock = System::Windows::Forms::DockStyle::Fill;
			this->LoadingPage->Location = System::Drawing::Point(0, 0);
			this->LoadingPage->Margin = System::Windows::Forms::Padding(4);
			this->LoadingPage->Name = L"LoadingPage";
			this->LoadingPage->Size = System::Drawing::Size(1179, 639);
			this->LoadingPage->TabIndex = 0;
			this->LoadingPage->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &SignUp::LoadingPage_Paint);
			// 
			// bottom_load2
			// 
			this->bottom_load2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(216)),
				static_cast<System::Int32>(static_cast<System::Byte>(87)));
			this->bottom_load2->Location = System::Drawing::Point(0, 626);
			this->bottom_load2->Margin = System::Windows::Forms::Padding(4);
			this->bottom_load2->Name = L"bottom_load2";
			this->bottom_load2->Size = System::Drawing::Size(57, 11);
			this->bottom_load2->TabIndex = 1;
			// 
			// bottomloadbg
			// 
			this->bottomloadbg->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(14)), static_cast<System::Int32>(static_cast<System::Byte>(14)),
				static_cast<System::Int32>(static_cast<System::Byte>(14)));
			this->bottomloadbg->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->bottomloadbg->Location = System::Drawing::Point(0, 628);
			this->bottomloadbg->Margin = System::Windows::Forms::Padding(4);
			this->bottomloadbg->Name = L"bottomloadbg";
			this->bottomloadbg->Size = System::Drawing::Size(1179, 11);
			this->bottomloadbg->TabIndex = 0;
			// 
			// Sign_up
			// 
			this->Sign_up->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(17)), static_cast<System::Int32>(static_cast<System::Byte>(17)),
				static_cast<System::Int32>(static_cast<System::Byte>(17)));
			this->Sign_up->Controls->Add(this->sign_up_with_google_btn);
			this->Sign_up->Controls->Add(this->Priv_Info_panel);
			this->Sign_up->Controls->Add(this->vertical_line);
			this->Sign_up->Controls->Add(this->checkBox1);
			this->Sign_up->Controls->Add(this->signup_btn);
			this->Sign_up->Controls->Add(this->PN_panel);
			this->Sign_up->Controls->Add(this->FN_panel);
			this->Sign_up->Controls->Add(this->LN_panel);
			this->Sign_up->Controls->Add(this->PN_lbl);
			this->Sign_up->Controls->Add(this->LN_lbl);
			this->Sign_up->Controls->Add(this->FN_lbl);
			this->Sign_up->Controls->Add(this->label2);
			this->Sign_up->Controls->Add(this->pictureBox2);
			this->Sign_up->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Sign_up->Location = System::Drawing::Point(0, 0);
			this->Sign_up->Margin = System::Windows::Forms::Padding(4);
			this->Sign_up->Name = L"Sign_up";
			this->Sign_up->Size = System::Drawing::Size(1179, 639);
			this->Sign_up->TabIndex = 0;
			this->Sign_up->Click += gcnew System::EventHandler(this, &SignUp::Sign_up_Click);
			// 
			// sign_up_with_google_btn
			// 
			this->sign_up_with_google_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(11)),
				static_cast<System::Int32>(static_cast<System::Byte>(194)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->sign_up_with_google_btn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"sign_up_with_google_btn.BackgroundImage")));
			this->sign_up_with_google_btn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->sign_up_with_google_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->sign_up_with_google_btn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->sign_up_with_google_btn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sign_up_with_google_btn->Location = System::Drawing::Point(260, 550);
			this->sign_up_with_google_btn->Margin = System::Windows::Forms::Padding(4);
			this->sign_up_with_google_btn->Name = L"sign_up_with_google_btn";
			this->sign_up_with_google_btn->Size = System::Drawing::Size(253, 44);
			this->sign_up_with_google_btn->TabIndex = 13;
			this->sign_up_with_google_btn->UseVisualStyleBackColor = false;
			this->sign_up_with_google_btn->Click += gcnew System::EventHandler(this, &SignUp::sign_up_with_google_btn_Click);
			// 
			// Priv_Info_panel
			// 
			this->Priv_Info_panel->Controls->Add(this->button1);
			this->Priv_Info_panel->Controls->Add(this->gen_Pass_value);
			this->Priv_Info_panel->Controls->Add(this->gen_ID_value);
			this->Priv_Info_panel->Controls->Add(this->gen_Pass);
			this->Priv_Info_panel->Controls->Add(this->gen_ID);
			this->Priv_Info_panel->Location = System::Drawing::Point(629, 185);
			this->Priv_Info_panel->Margin = System::Windows::Forms::Padding(4);
			this->Priv_Info_panel->Name = L"Priv_Info_panel";
			this->Priv_Info_panel->Size = System::Drawing::Size(533, 375);
			this->Priv_Info_panel->TabIndex = 12;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(11)), static_cast<System::Int32>(static_cast<System::Byte>(194)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->Enabled = false;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(380, 316);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(135, 44);
			this->button1->TabIndex = 13;
			this->button1->Text = L"Continue";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &SignUp::button1_Click);
			// 
			// gen_Pass_value
			// 
			this->gen_Pass_value->AutoSize = true;
			this->gen_Pass_value->BackColor = System::Drawing::Color::Transparent;
			this->gen_Pass_value->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15, System::Drawing::FontStyle::Bold));
			this->gen_Pass_value->ForeColor = System::Drawing::Color::White;
			this->gen_Pass_value->Location = System::Drawing::Point(62, 260);
			this->gen_Pass_value->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->gen_Pass_value->Name = L"gen_Pass_value";
			this->gen_Pass_value->Size = System::Drawing::Size(0, 35);
			this->gen_Pass_value->TabIndex = 8;
			// 
			// gen_ID_value
			// 
			this->gen_ID_value->AutoSize = true;
			this->gen_ID_value->BackColor = System::Drawing::Color::Transparent;
			this->gen_ID_value->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15, System::Drawing::FontStyle::Bold));
			this->gen_ID_value->ForeColor = System::Drawing::Color::White;
			this->gen_ID_value->Location = System::Drawing::Point(62, 104);
			this->gen_ID_value->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->gen_ID_value->Name = L"gen_ID_value";
			this->gen_ID_value->Size = System::Drawing::Size(0, 35);
			this->gen_ID_value->TabIndex = 7;
			// 
			// gen_Pass
			// 
			this->gen_Pass->AutoSize = true;
			this->gen_Pass->BackColor = System::Drawing::Color::Transparent;
			this->gen_Pass->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15, System::Drawing::FontStyle::Bold));
			this->gen_Pass->ForeColor = System::Drawing::Color::White;
			this->gen_Pass->Location = System::Drawing::Point(55, 198);
			this->gen_Pass->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->gen_Pass->Name = L"gen_Pass";
			this->gen_Pass->Size = System::Drawing::Size(184, 35);
			this->gen_Pass->TabIndex = 6;
			this->gen_Pass->Text = L"Your Password";
			// 
			// gen_ID
			// 
			this->gen_ID->AutoSize = true;
			this->gen_ID->BackColor = System::Drawing::Color::Transparent;
			this->gen_ID->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15, System::Drawing::FontStyle::Bold));
			this->gen_ID->ForeColor = System::Drawing::Color::White;
			this->gen_ID->Location = System::Drawing::Point(55, 46);
			this->gen_ID->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->gen_ID->Name = L"gen_ID";
			this->gen_ID->Size = System::Drawing::Size(192, 35);
			this->gen_ID->TabIndex = 5;
			this->gen_ID->Text = L"Your Unique ID";
			// 
			// vertical_line
			// 
			this->vertical_line->BackColor = System::Drawing::Color::WhiteSmoke;
			this->vertical_line->Location = System::Drawing::Point(596, 215);
			this->vertical_line->Margin = System::Windows::Forms::Padding(4);
			this->vertical_line->Name = L"vertical_line";
			this->vertical_line->Size = System::Drawing::Size(7, 295);
			this->vertical_line->TabIndex = 11;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->BackColor = System::Drawing::Color::Transparent;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 8.25F));
			this->checkBox1->ForeColor = System::Drawing::Color::White;
			this->checkBox1->Location = System::Drawing::Point(49, 517);
			this->checkBox1->Margin = System::Windows::Forms::Padding(4);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(245, 23);
			this->checkBox1->TabIndex = 10;
			this->checkBox1->Text = L"I agree to terms and conditions";
			this->checkBox1->UseVisualStyleBackColor = false;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &SignUp::checkBox1_CheckedChanged);
			// 
			// signup_btn
			// 
			this->signup_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(11)), static_cast<System::Int32>(static_cast<System::Byte>(194)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->signup_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->signup_btn->Enabled = false;
			this->signup_btn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->signup_btn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->signup_btn->Location = System::Drawing::Point(51, 550);
			this->signup_btn->Margin = System::Windows::Forms::Padding(4);
			this->signup_btn->Name = L"signup_btn";
			this->signup_btn->Size = System::Drawing::Size(135, 44);
			this->signup_btn->TabIndex = 9;
			this->signup_btn->Text = L"SIGN UP";
			this->signup_btn->UseVisualStyleBackColor = false;
			this->signup_btn->Click += gcnew System::EventHandler(this, &SignUp::signup_btn_Click);
			// 
			// PN_panel
			// 
			this->PN_panel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->PN_panel->Controls->Add(this->PN_TB);
			this->PN_panel->Location = System::Drawing::Point(49, 448);
			this->PN_panel->Margin = System::Windows::Forms::Padding(4);
			this->PN_panel->Name = L"PN_panel";
			this->PN_panel->Size = System::Drawing::Size(491, 54);
			this->PN_panel->TabIndex = 8;
			// 
			// PN_TB
			// 
			this->PN_TB->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->PN_TB->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->PN_TB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F));
			this->PN_TB->ForeColor = System::Drawing::Color::White;
			this->PN_TB->Location = System::Drawing::Point(16, 16);
			this->PN_TB->Margin = System::Windows::Forms::Padding(4);
			this->PN_TB->Name = L"PN_TB";
			this->PN_TB->Size = System::Drawing::Size(448, 20);
			this->PN_TB->TabIndex = 0;
			this->PN_TB->Text = L"Phone Number";
			this->PN_TB->Click += gcnew System::EventHandler(this, &SignUp::PN_TB_Click);
			// 
			// FN_panel
			// 
			this->FN_panel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->FN_panel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->FN_panel->Controls->Add(this->FN_TB);
			this->FN_panel->Location = System::Drawing::Point(49, 226);
			this->FN_panel->Margin = System::Windows::Forms::Padding(4);
			this->FN_panel->Name = L"FN_panel";
			this->FN_panel->Size = System::Drawing::Size(491, 54);
			this->FN_panel->TabIndex = 4;
			// 
			// FN_TB
			// 
			this->FN_TB->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->FN_TB->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->FN_TB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F));
			this->FN_TB->ForeColor = System::Drawing::Color::White;
			this->FN_TB->Location = System::Drawing::Point(21, 15);
			this->FN_TB->Margin = System::Windows::Forms::Padding(4);
			this->FN_TB->Name = L"FN_TB";
			this->FN_TB->Size = System::Drawing::Size(443, 20);
			this->FN_TB->TabIndex = 0;
			this->FN_TB->Text = L"First Name";
			this->FN_TB->Click += gcnew System::EventHandler(this, &SignUp::FN_TB_Click);
			// 
			// LN_panel
			// 
			this->LN_panel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->LN_panel->Controls->Add(this->LN_TB);
			this->LN_panel->Location = System::Drawing::Point(49, 341);
			this->LN_panel->Margin = System::Windows::Forms::Padding(4);
			this->LN_panel->Name = L"LN_panel";
			this->LN_panel->Size = System::Drawing::Size(491, 54);
			this->LN_panel->TabIndex = 4;
			// 
			// LN_TB
			// 
			this->LN_TB->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->LN_TB->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->LN_TB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F));
			this->LN_TB->ForeColor = System::Drawing::Color::White;
			this->LN_TB->Location = System::Drawing::Point(16, 16);
			this->LN_TB->Margin = System::Windows::Forms::Padding(4);
			this->LN_TB->Name = L"LN_TB";
			this->LN_TB->Size = System::Drawing::Size(448, 20);
			this->LN_TB->TabIndex = 0;
			this->LN_TB->Text = L"Last Name";
			this->LN_TB->Click += gcnew System::EventHandler(this, &SignUp::LN_TB_Click);
			// 
			// PN_lbl
			// 
			this->PN_lbl->AutoSize = true;
			this->PN_lbl->BackColor = System::Drawing::Color::Transparent;
			this->PN_lbl->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15, System::Drawing::FontStyle::Bold));
			this->PN_lbl->ForeColor = System::Drawing::Color::White;
			this->PN_lbl->Location = System::Drawing::Point(43, 412);
			this->PN_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->PN_lbl->Name = L"PN_lbl";
			this->PN_lbl->Size = System::Drawing::Size(194, 35);
			this->PN_lbl->TabIndex = 6;
			this->PN_lbl->Text = L"Phone Number";
			// 
			// LN_lbl
			// 
			this->LN_lbl->AutoSize = true;
			this->LN_lbl->BackColor = System::Drawing::Color::Transparent;
			this->LN_lbl->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15, System::Drawing::FontStyle::Bold));
			this->LN_lbl->ForeColor = System::Drawing::Color::White;
			this->LN_lbl->Location = System::Drawing::Point(43, 300);
			this->LN_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->LN_lbl->Name = L"LN_lbl";
			this->LN_lbl->Size = System::Drawing::Size(139, 35);
			this->LN_lbl->TabIndex = 5;
			this->LN_lbl->Text = L"Last Name";
			// 
			// FN_lbl
			// 
			this->FN_lbl->AutoSize = true;
			this->FN_lbl->BackColor = System::Drawing::Color::Transparent;
			this->FN_lbl->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15, System::Drawing::FontStyle::Bold));
			this->FN_lbl->ForeColor = System::Drawing::Color::White;
			this->FN_lbl->Location = System::Drawing::Point(43, 185);
			this->FN_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->FN_lbl->Name = L"FN_lbl";
			this->FN_lbl->Size = System::Drawing::Size(143, 35);
			this->FN_lbl->TabIndex = 4;
			this->FN_lbl->Text = L"First Name";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(497, 52);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(319, 106);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Spotify";
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->pictureBox2->ImageLocation = L"";
			this->pictureBox2->Location = System::Drawing::Point(315, 33);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(175, 139);
			this->pictureBox2->TabIndex = 2;
			this->pictureBox2->TabStop = false;
			// 
			// LogIn
			// 
			this->LogIn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(17)), static_cast<System::Int32>(static_cast<System::Byte>(17)),
				static_cast<System::Int32>(static_cast<System::Byte>(17)));
			this->LogIn->Controls->Add(this->Invalid_credentials_lbl);
			this->LogIn->Controls->Add(this->forgot_lbl);
			this->LogIn->Controls->Add(this->signup_lbl);
			this->LogIn->Controls->Add(this->Login_btn);
			this->LogIn->Controls->Add(this->newacc_lbl);
			this->LogIn->Controls->Add(this->Passwordpanel);
			this->LogIn->Controls->Add(this->label1);
			this->LogIn->Controls->Add(this->IDpanel);
			this->LogIn->Controls->Add(this->id_lbl);
			this->LogIn->Controls->Add(this->spotifylabel);
			this->LogIn->Controls->Add(this->pictureBox1);
			this->LogIn->Dock = System::Windows::Forms::DockStyle::Fill;
			this->LogIn->Location = System::Drawing::Point(0, 0);
			this->LogIn->Margin = System::Windows::Forms::Padding(4);
			this->LogIn->Name = L"LogIn";
			this->LogIn->Size = System::Drawing::Size(1179, 639);
			this->LogIn->TabIndex = 0;
			this->LogIn->Visible = false;
			this->LogIn->Click += gcnew System::EventHandler(this, &SignUp::LogIn_Click);
			// 
			// Invalid_credentials_lbl
			// 
			this->Invalid_credentials_lbl->AutoSize = true;
			this->Invalid_credentials_lbl->ForeColor = System::Drawing::Color::Red;
			this->Invalid_credentials_lbl->Location = System::Drawing::Point(480, 206);
			this->Invalid_credentials_lbl->Name = L"Invalid_credentials_lbl";
			this->Invalid_credentials_lbl->Size = System::Drawing::Size(186, 16);
			this->Invalid_credentials_lbl->TabIndex = 10;
			this->Invalid_credentials_lbl->Text = L"! Invalid unique Id or password";
			this->Invalid_credentials_lbl->Visible = false;
			// 
			// forgot_lbl
			// 
			this->forgot_lbl->AutoSize = true;
			this->forgot_lbl->BackColor = System::Drawing::Color::Transparent;
			this->forgot_lbl->Cursor = System::Windows::Forms::Cursors::Hand;
			this->forgot_lbl->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.25F, System::Drawing::FontStyle::Underline));
			this->forgot_lbl->ForeColor = System::Drawing::Color::White;
			this->forgot_lbl->Location = System::Drawing::Point(263, 512);
			this->forgot_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->forgot_lbl->Name = L"forgot_lbl";
			this->forgot_lbl->Size = System::Drawing::Size(172, 21);
			this->forgot_lbl->TabIndex = 9;
			this->forgot_lbl->Text = L"Forgot ID or password\?";
			this->forgot_lbl->Click += gcnew System::EventHandler(this, &SignUp::forgot_lbl_Click);
			// 
			// signup_lbl
			// 
			this->signup_lbl->AutoSize = true;
			this->signup_lbl->BackColor = System::Drawing::Color::Transparent;
			this->signup_lbl->Cursor = System::Windows::Forms::Cursors::Hand;
			this->signup_lbl->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.25F, System::Drawing::FontStyle::Underline));
			this->signup_lbl->ForeColor = System::Drawing::Color::White;
			this->signup_lbl->Location = System::Drawing::Point(496, 564);
			this->signup_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->signup_lbl->Name = L"signup_lbl";
			this->signup_lbl->Size = System::Drawing::Size(65, 21);
			this->signup_lbl->TabIndex = 8;
			this->signup_lbl->Text = L"Sign Up";
			this->signup_lbl->Click += gcnew System::EventHandler(this, &SignUp::signup_lbl_Click);
			// 
			// Login_btn
			// 
			this->Login_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(11)), static_cast<System::Int32>(static_cast<System::Byte>(194)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->Login_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Login_btn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->Login_btn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Login_btn->Location = System::Drawing::Point(757, 496);
			this->Login_btn->Margin = System::Windows::Forms::Padding(4);
			this->Login_btn->Name = L"Login_btn";
			this->Login_btn->Size = System::Drawing::Size(135, 44);
			this->Login_btn->TabIndex = 7;
			this->Login_btn->Text = L"LOG IN";
			this->Login_btn->UseVisualStyleBackColor = false;
			this->Login_btn->Click += gcnew System::EventHandler(this, &SignUp::Login_btn_Click);
			// 
			// newacc_lbl
			// 
			this->newacc_lbl->AutoSize = true;
			this->newacc_lbl->BackColor = System::Drawing::Color::Transparent;
			this->newacc_lbl->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F, System::Drawing::FontStyle::Bold));
			this->newacc_lbl->ForeColor = System::Drawing::Color::White;
			this->newacc_lbl->Location = System::Drawing::Point(261, 560);
			this->newacc_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->newacc_lbl->Name = L"newacc_lbl";
			this->newacc_lbl->Size = System::Drawing::Size(218, 25);
			this->newacc_lbl->TabIndex = 6;
			this->newacc_lbl->Text = L"Don\'t have an account\?";
			// 
			// Passwordpanel
			// 
			this->Passwordpanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->Passwordpanel->Controls->Add(this->PassTB);
			this->Passwordpanel->Location = System::Drawing::Point(267, 404);
			this->Passwordpanel->Margin = System::Windows::Forms::Padding(4);
			this->Passwordpanel->Name = L"Passwordpanel";
			this->Passwordpanel->Size = System::Drawing::Size(625, 54);
			this->Passwordpanel->TabIndex = 5;
			// 
			// PassTB
			// 
			this->PassTB->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->PassTB->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->PassTB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F));
			this->PassTB->ForeColor = System::Drawing::Color::White;
			this->PassTB->Location = System::Drawing::Point(28, 17);
			this->PassTB->Margin = System::Windows::Forms::Padding(4);
			this->PassTB->Name = L"PassTB";
			this->PassTB->Size = System::Drawing::Size(568, 20);
			this->PassTB->TabIndex = 1;
			this->PassTB->Text = L"Password";
			this->PassTB->UseSystemPasswordChar = true;
			this->PassTB->Click += gcnew System::EventHandler(this, &SignUp::PassTB_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15, System::Drawing::FontStyle::Bold));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(260, 351);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(124, 35);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Password";
			// 
			// IDpanel
			// 
			this->IDpanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->IDpanel->Controls->Add(this->ID_TB);
			this->IDpanel->Location = System::Drawing::Point(267, 279);
			this->IDpanel->Margin = System::Windows::Forms::Padding(4);
			this->IDpanel->Name = L"IDpanel";
			this->IDpanel->Size = System::Drawing::Size(625, 54);
			this->IDpanel->TabIndex = 3;
			// 
			// ID_TB
			// 
			this->ID_TB->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->ID_TB->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->ID_TB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F));
			this->ID_TB->ForeColor = System::Drawing::Color::White;
			this->ID_TB->Location = System::Drawing::Point(21, 20);
			this->ID_TB->Margin = System::Windows::Forms::Padding(4);
			this->ID_TB->Name = L"ID_TB";
			this->ID_TB->Size = System::Drawing::Size(568, 20);
			this->ID_TB->TabIndex = 0;
			this->ID_TB->Text = L"Unique ID";
			this->ID_TB->Click += gcnew System::EventHandler(this, &SignUp::ID_TB_Click);
			// 
			// id_lbl
			// 
			this->id_lbl->AutoSize = true;
			this->id_lbl->BackColor = System::Drawing::Color::Transparent;
			this->id_lbl->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15, System::Drawing::FontStyle::Bold));
			this->id_lbl->ForeColor = System::Drawing::Color::White;
			this->id_lbl->Location = System::Drawing::Point(260, 226);
			this->id_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->id_lbl->Name = L"id_lbl";
			this->id_lbl->Size = System::Drawing::Size(132, 35);
			this->id_lbl->TabIndex = 2;
			this->id_lbl->Text = L"Unique ID";
			// 
			// spotifylabel
			// 
			this->spotifylabel->AutoSize = true;
			this->spotifylabel->BackColor = System::Drawing::Color::Transparent;
			this->spotifylabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->spotifylabel->ForeColor = System::Drawing::Color::White;
			this->spotifylabel->Location = System::Drawing::Point(497, 52);
			this->spotifylabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->spotifylabel->Name = L"spotifylabel";
			this->spotifylabel->Size = System::Drawing::Size(319, 106);
			this->spotifylabel->TabIndex = 1;
			this->spotifylabel->Text = L"Spotify";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->pictureBox1->ImageLocation = L"";
			this->pictureBox1->Location = System::Drawing::Point(315, 33);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(175, 139);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// PickFavArtists
			// 
			this->PickFavArtists->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(14)), static_cast<System::Int32>(static_cast<System::Byte>(14)),
				static_cast<System::Int32>(static_cast<System::Byte>(14)));
			this->PickFavArtists->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->PickFavArtists->Controls->Add(this->next_to_home_btn);
			this->PickFavArtists->Controls->Add(this->skip_btn);
			this->PickFavArtists->Controls->Add(this->weeknd_chbx);
			this->PickFavArtists->Controls->Add(this->weeknd_pic);
			this->PickFavArtists->Controls->Add(this->kanye_chbx);
			this->PickFavArtists->Controls->Add(this->kanye_pic);
			this->PickFavArtists->Controls->Add(this->billie_chbx);
			this->PickFavArtists->Controls->Add(this->billie_pic);
			this->PickFavArtists->Controls->Add(this->jb_chbx);
			this->PickFavArtists->Controls->Add(this->harrys_chbx);
			this->PickFavArtists->Controls->Add(this->jb_pic);
			this->PickFavArtists->Controls->Add(this->harrys_pic);
			this->PickFavArtists->Controls->Add(this->rihanna_chbx);
			this->PickFavArtists->Controls->Add(this->rihanna_pic);
			this->PickFavArtists->Controls->Add(this->am_chbx);
			this->PickFavArtists->Controls->Add(this->am_pic);
			this->PickFavArtists->Controls->Add(this->beyonce_chbx);
			this->PickFavArtists->Controls->Add(this->beyonce_pic);
			this->PickFavArtists->Controls->Add(this->label4);
			this->PickFavArtists->Controls->Add(this->PickFav_lbl);
			this->PickFavArtists->Dock = System::Windows::Forms::DockStyle::Fill;
			this->PickFavArtists->Location = System::Drawing::Point(0, 0);
			this->PickFavArtists->Margin = System::Windows::Forms::Padding(4);
			this->PickFavArtists->Name = L"PickFavArtists";
			this->PickFavArtists->Size = System::Drawing::Size(1179, 639);
			this->PickFavArtists->TabIndex = 0;
			// 
			// next_to_home_btn
			// 
			this->next_to_home_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(11)), static_cast<System::Int32>(static_cast<System::Byte>(194)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->next_to_home_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->next_to_home_btn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->next_to_home_btn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->next_to_home_btn->Location = System::Drawing::Point(968, 564);
			this->next_to_home_btn->Margin = System::Windows::Forms::Padding(4);
			this->next_to_home_btn->Name = L"next_to_home_btn";
			this->next_to_home_btn->Size = System::Drawing::Size(135, 44);
			this->next_to_home_btn->TabIndex = 26;
			this->next_to_home_btn->Text = L"NEXT";
			this->next_to_home_btn->UseVisualStyleBackColor = false;
			this->next_to_home_btn->Click += gcnew System::EventHandler(this, &SignUp::next_to_home_btn_Click);
			// 
			// skip_btn
			// 
			this->skip_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(11)), static_cast<System::Int32>(static_cast<System::Byte>(194)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->skip_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->skip_btn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->skip_btn->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->skip_btn->Location = System::Drawing::Point(968, 74);
			this->skip_btn->Margin = System::Windows::Forms::Padding(4);
			this->skip_btn->Name = L"skip_btn";
			this->skip_btn->Size = System::Drawing::Size(135, 44);
			this->skip_btn->TabIndex = 25;
			this->skip_btn->Text = L"SKIP>>";
			this->skip_btn->UseVisualStyleBackColor = false;
			this->skip_btn->Click += gcnew System::EventHandler(this, &SignUp::skip_btn_Click);
			// 
			// weeknd_chbx
			// 
			this->weeknd_chbx->AutoSize = true;
			this->weeknd_chbx->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->weeknd_chbx->ForeColor = System::Drawing::Color::White;
			this->weeknd_chbx->Location = System::Drawing::Point(892, 508);
			this->weeknd_chbx->Margin = System::Windows::Forms::Padding(4);
			this->weeknd_chbx->Name = L"weeknd_chbx";
			this->weeknd_chbx->Size = System::Drawing::Size(128, 27);
			this->weeknd_chbx->TabIndex = 22;
			this->weeknd_chbx->Text = L"The Weeknd";
			this->weeknd_chbx->UseVisualStyleBackColor = true;
			// 
			// weeknd_pic
			// 
			this->weeknd_pic->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"weeknd_pic.BackgroundImage")));
			this->weeknd_pic->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->weeknd_pic->Location = System::Drawing::Point(872, 379);
			this->weeknd_pic->Margin = System::Windows::Forms::Padding(4);
			this->weeknd_pic->Name = L"weeknd_pic";
			this->weeknd_pic->Size = System::Drawing::Size(177, 119);
			this->weeknd_pic->TabIndex = 21;
			this->weeknd_pic->TabStop = false;
			// 
			// kanye_chbx
			// 
			this->kanye_chbx->AutoSize = true;
			this->kanye_chbx->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->kanye_chbx->ForeColor = System::Drawing::Color::White;
			this->kanye_chbx->Location = System::Drawing::Point(413, 303);
			this->kanye_chbx->Margin = System::Windows::Forms::Padding(4);
			this->kanye_chbx->Name = L"kanye_chbx";
			this->kanye_chbx->Size = System::Drawing::Size(122, 27);
			this->kanye_chbx->TabIndex = 20;
			this->kanye_chbx->Text = L"Kanye West";
			this->kanye_chbx->UseVisualStyleBackColor = true;
			// 
			// kanye_pic
			// 
			this->kanye_pic->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"kanye_pic.BackgroundImage")));
			this->kanye_pic->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->kanye_pic->Location = System::Drawing::Point(395, 172);
			this->kanye_pic->Margin = System::Windows::Forms::Padding(4);
			this->kanye_pic->Name = L"kanye_pic";
			this->kanye_pic->Size = System::Drawing::Size(177, 119);
			this->kanye_pic->TabIndex = 19;
			this->kanye_pic->TabStop = false;
			// 
			// billie_chbx
			// 
			this->billie_chbx->AutoSize = true;
			this->billie_chbx->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->billie_chbx->ForeColor = System::Drawing::Color::White;
			this->billie_chbx->Location = System::Drawing::Point(653, 303);
			this->billie_chbx->Margin = System::Windows::Forms::Padding(4);
			this->billie_chbx->Name = L"billie_chbx";
			this->billie_chbx->Size = System::Drawing::Size(110, 27);
			this->billie_chbx->TabIndex = 18;
			this->billie_chbx->Text = L"Billie Eilish";
			this->billie_chbx->UseVisualStyleBackColor = true;
			// 
			// billie_pic
			// 
			this->billie_pic->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"billie_pic.BackgroundImage")));
			this->billie_pic->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->billie_pic->Location = System::Drawing::Point(617, 172);
			this->billie_pic->Margin = System::Windows::Forms::Padding(4);
			this->billie_pic->Name = L"billie_pic";
			this->billie_pic->Size = System::Drawing::Size(177, 119);
			this->billie_pic->TabIndex = 17;
			this->billie_pic->TabStop = false;
			// 
			// jb_chbx
			// 
			this->jb_chbx->AutoSize = true;
			this->jb_chbx->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->jb_chbx->ForeColor = System::Drawing::Color::White;
			this->jb_chbx->Location = System::Drawing::Point(891, 298);
			this->jb_chbx->Margin = System::Windows::Forms::Padding(4);
			this->jb_chbx->Name = L"jb_chbx";
			this->jb_chbx->Size = System::Drawing::Size(129, 27);
			this->jb_chbx->TabIndex = 16;
			this->jb_chbx->Text = L"Justin Bieber";
			this->jb_chbx->UseVisualStyleBackColor = true;
			// 
			// harrys_chbx
			// 
			this->harrys_chbx->AutoSize = true;
			this->harrys_chbx->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->harrys_chbx->ForeColor = System::Drawing::Color::White;
			this->harrys_chbx->Location = System::Drawing::Point(148, 512);
			this->harrys_chbx->Margin = System::Windows::Forms::Padding(4);
			this->harrys_chbx->Name = L"harrys_chbx";
			this->harrys_chbx->Size = System::Drawing::Size(125, 27);
			this->harrys_chbx->TabIndex = 16;
			this->harrys_chbx->Text = L"Harry Styles";
			this->harrys_chbx->UseVisualStyleBackColor = true;
			// 
			// jb_pic
			// 
			this->jb_pic->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"jb_pic.BackgroundImage")));
			this->jb_pic->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->jb_pic->Location = System::Drawing::Point(872, 167);
			this->jb_pic->Margin = System::Windows::Forms::Padding(4);
			this->jb_pic->Name = L"jb_pic";
			this->jb_pic->Size = System::Drawing::Size(177, 119);
			this->jb_pic->TabIndex = 15;
			this->jb_pic->TabStop = false;
			// 
			// harrys_pic
			// 
			this->harrys_pic->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"harrys_pic.BackgroundImage")));
			this->harrys_pic->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->harrys_pic->Location = System::Drawing::Point(124, 379);
			this->harrys_pic->Margin = System::Windows::Forms::Padding(4);
			this->harrys_pic->Name = L"harrys_pic";
			this->harrys_pic->Size = System::Drawing::Size(177, 119);
			this->harrys_pic->TabIndex = 15;
			this->harrys_pic->TabStop = false;
			// 
			// rihanna_chbx
			// 
			this->rihanna_chbx->AutoSize = true;
			this->rihanna_chbx->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rihanna_chbx->ForeColor = System::Drawing::Color::White;
			this->rihanna_chbx->Location = System::Drawing::Point(431, 510);
			this->rihanna_chbx->Margin = System::Windows::Forms::Padding(4);
			this->rihanna_chbx->Name = L"rihanna_chbx";
			this->rihanna_chbx->Size = System::Drawing::Size(95, 27);
			this->rihanna_chbx->TabIndex = 14;
			this->rihanna_chbx->Text = L"Rihanna";
			this->rihanna_chbx->UseVisualStyleBackColor = true;
			// 
			// rihanna_pic
			// 
			this->rihanna_pic->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"rihanna_pic.BackgroundImage")));
			this->rihanna_pic->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->rihanna_pic->Location = System::Drawing::Point(395, 379);
			this->rihanna_pic->Margin = System::Windows::Forms::Padding(4);
			this->rihanna_pic->Name = L"rihanna_pic";
			this->rihanna_pic->Size = System::Drawing::Size(177, 119);
			this->rihanna_pic->TabIndex = 13;
			this->rihanna_pic->TabStop = false;
			// 
			// am_chbx
			// 
			this->am_chbx->AutoSize = true;
			this->am_chbx->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->am_chbx->ForeColor = System::Drawing::Color::White;
			this->am_chbx->Location = System::Drawing::Point(639, 510);
			this->am_chbx->Margin = System::Windows::Forms::Padding(4);
			this->am_chbx->Name = L"am_chbx";
			this->am_chbx->Size = System::Drawing::Size(150, 27);
			this->am_chbx->TabIndex = 12;
			this->am_chbx->Text = L"Arctic Monkeys";
			this->am_chbx->UseVisualStyleBackColor = true;
			// 
			// am_pic
			// 
			this->am_pic->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"am_pic.BackgroundImage")));
			this->am_pic->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->am_pic->Location = System::Drawing::Point(629, 379);
			this->am_pic->Margin = System::Windows::Forms::Padding(4);
			this->am_pic->Name = L"am_pic";
			this->am_pic->Size = System::Drawing::Size(177, 119);
			this->am_pic->TabIndex = 11;
			this->am_pic->TabStop = false;
			// 
			// beyonce_chbx
			// 
			this->beyonce_chbx->AutoSize = true;
			this->beyonce_chbx->BackColor = System::Drawing::Color::Transparent;
			this->beyonce_chbx->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->beyonce_chbx->ForeColor = System::Drawing::Color::White;
			this->beyonce_chbx->Location = System::Drawing::Point(169, 304);
			this->beyonce_chbx->Margin = System::Windows::Forms::Padding(4);
			this->beyonce_chbx->Name = L"beyonce_chbx";
			this->beyonce_chbx->Size = System::Drawing::Size(97, 27);
			this->beyonce_chbx->TabIndex = 10;
			this->beyonce_chbx->Text = L"Beyoncé";
			this->beyonce_chbx->UseVisualStyleBackColor = false;
			// 
			// beyonce_pic
			// 
			this->beyonce_pic->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"beyonce_pic.BackgroundImage")));
			this->beyonce_pic->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->beyonce_pic->Cursor = System::Windows::Forms::Cursors::Hand;
			this->beyonce_pic->Location = System::Drawing::Point(129, 172);
			this->beyonce_pic->Margin = System::Windows::Forms::Padding(4);
			this->beyonce_pic->Name = L"beyonce_pic";
			this->beyonce_pic->Size = System::Drawing::Size(177, 119);
			this->beyonce_pic->TabIndex = 9;
			this->beyonce_pic->TabStop = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(512, 92);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(154, 28);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Select at least 5";
			// 
			// PickFav_lbl
			// 
			this->PickFav_lbl->AutoSize = true;
			this->PickFav_lbl->BackColor = System::Drawing::Color::Transparent;
			this->PickFav_lbl->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold));
			this->PickFav_lbl->ForeColor = System::Drawing::Color::White;
			this->PickFav_lbl->Location = System::Drawing::Point(405, 33);
			this->PickFav_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->PickFav_lbl->Name = L"PickFav_lbl";
			this->PickFav_lbl->Size = System::Drawing::Size(398, 41);
			this->PickFav_lbl->TabIndex = 7;
			this->PickFav_lbl->Text = L"Pick Your Favourite Artists!";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 15;
			this->timer1->Tick += gcnew System::EventHandler(this, &SignUp::timer1_Tick);
			// 
			// sign_up_with_google_panel
			// 
			this->sign_up_with_google_panel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(17)),
				static_cast<System::Int32>(static_cast<System::Byte>(17)), static_cast<System::Int32>(static_cast<System::Byte>(17)));
			this->sign_up_with_google_panel->Controls->Add(this->Invalid_google_lbl);
			this->sign_up_with_google_panel->Controls->Add(this->s_up_google_btn2);
			this->sign_up_with_google_panel->Controls->Add(this->panel2);
			this->sign_up_with_google_panel->Controls->Add(this->panel3);
			this->sign_up_with_google_panel->Controls->Add(this->panel5);
			this->sign_up_with_google_panel->Controls->Add(this->panel6);
			this->sign_up_with_google_panel->Controls->Add(this->password_googl_lbl);
			this->sign_up_with_google_panel->Controls->Add(this->Email_lbl);
			this->sign_up_with_google_panel->Controls->Add(this->label11);
			this->sign_up_with_google_panel->Controls->Add(this->pictureBox3);
			this->sign_up_with_google_panel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->sign_up_with_google_panel->Location = System::Drawing::Point(0, 0);
			this->sign_up_with_google_panel->Margin = System::Windows::Forms::Padding(4);
			this->sign_up_with_google_panel->Name = L"sign_up_with_google_panel";
			this->sign_up_with_google_panel->Size = System::Drawing::Size(1179, 639);
			this->sign_up_with_google_panel->TabIndex = 1;
			// 
			// Invalid_google_lbl
			// 
			this->Invalid_google_lbl->AutoSize = true;
			this->Invalid_google_lbl->ForeColor = System::Drawing::Color::Red;
			this->Invalid_google_lbl->Location = System::Drawing::Point(48, 412);
			this->Invalid_google_lbl->Name = L"Invalid_google_lbl";
			this->Invalid_google_lbl->Size = System::Drawing::Size(186, 16);
			this->Invalid_google_lbl->TabIndex = 14;
			this->Invalid_google_lbl->Text = L"! Invalid unique Id or password";
			this->Invalid_google_lbl->Visible = false;
			// 
			// s_up_google_btn2
			// 
			this->s_up_google_btn2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(11)), static_cast<System::Int32>(static_cast<System::Byte>(194)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->s_up_google_btn2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"s_up_google_btn2.BackgroundImage")));
			this->s_up_google_btn2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->s_up_google_btn2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->s_up_google_btn2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->s_up_google_btn2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->s_up_google_btn2->Location = System::Drawing::Point(148, 448);
			this->s_up_google_btn2->Margin = System::Windows::Forms::Padding(4);
			this->s_up_google_btn2->Name = L"s_up_google_btn2";
			this->s_up_google_btn2->Size = System::Drawing::Size(253, 44);
			this->s_up_google_btn2->TabIndex = 13;
			this->s_up_google_btn2->UseVisualStyleBackColor = false;
			this->s_up_google_btn2->Click += gcnew System::EventHandler(this, &SignUp::s_up_google_btn2_Click);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->continue_btn2);
			this->panel2->Controls->Add(this->g_pass_lbl);
			this->panel2->Controls->Add(this->g_id_lbl);
			this->panel2->Controls->Add(this->label6);
			this->panel2->Controls->Add(this->label7);
			this->panel2->Location = System::Drawing::Point(629, 185);
			this->panel2->Margin = System::Windows::Forms::Padding(4);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(533, 375);
			this->panel2->TabIndex = 12;
			// 
			// continue_btn2
			// 
			this->continue_btn2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(11)), static_cast<System::Int32>(static_cast<System::Byte>(194)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->continue_btn2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->continue_btn2->Enabled = false;
			this->continue_btn2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->continue_btn2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->continue_btn2->Location = System::Drawing::Point(380, 316);
			this->continue_btn2->Margin = System::Windows::Forms::Padding(4);
			this->continue_btn2->Name = L"continue_btn2";
			this->continue_btn2->Size = System::Drawing::Size(135, 44);
			this->continue_btn2->TabIndex = 13;
			this->continue_btn2->Text = L"Continue";
			this->continue_btn2->UseVisualStyleBackColor = false;
			this->continue_btn2->Click += gcnew System::EventHandler(this, &SignUp::continue_btn2_Click);
			// 
			// g_pass_lbl
			// 
			this->g_pass_lbl->AutoSize = true;
			this->g_pass_lbl->BackColor = System::Drawing::Color::Transparent;
			this->g_pass_lbl->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15, System::Drawing::FontStyle::Bold));
			this->g_pass_lbl->ForeColor = System::Drawing::Color::White;
			this->g_pass_lbl->Location = System::Drawing::Point(62, 260);
			this->g_pass_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->g_pass_lbl->Name = L"g_pass_lbl";
			this->g_pass_lbl->Size = System::Drawing::Size(0, 35);
			this->g_pass_lbl->TabIndex = 8;
			// 
			// g_id_lbl
			// 
			this->g_id_lbl->AutoSize = true;
			this->g_id_lbl->BackColor = System::Drawing::Color::Transparent;
			this->g_id_lbl->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15, System::Drawing::FontStyle::Bold));
			this->g_id_lbl->ForeColor = System::Drawing::Color::White;
			this->g_id_lbl->Location = System::Drawing::Point(62, 104);
			this->g_id_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->g_id_lbl->Name = L"g_id_lbl";
			this->g_id_lbl->Size = System::Drawing::Size(0, 35);
			this->g_id_lbl->TabIndex = 7;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15, System::Drawing::FontStyle::Bold));
			this->label6->ForeColor = System::Drawing::Color::White;
			this->label6->Location = System::Drawing::Point(55, 198);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(184, 35);
			this->label6->TabIndex = 6;
			this->label6->Text = L"Your Password";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15, System::Drawing::FontStyle::Bold));
			this->label7->ForeColor = System::Drawing::Color::White;
			this->label7->Location = System::Drawing::Point(55, 46);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(192, 35);
			this->label7->TabIndex = 5;
			this->label7->Text = L"Your Unique ID";
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::WhiteSmoke;
			this->panel3->Location = System::Drawing::Point(596, 215);
			this->panel3->Margin = System::Windows::Forms::Padding(4);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(7, 295);
			this->panel3->TabIndex = 11;
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->panel5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->panel5->Controls->Add(this->email_TB);
			this->panel5->Location = System::Drawing::Point(49, 226);
			this->panel5->Margin = System::Windows::Forms::Padding(4);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(491, 54);
			this->panel5->TabIndex = 4;
			// 
			// email_TB
			// 
			this->email_TB->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->email_TB->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->email_TB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F));
			this->email_TB->ForeColor = System::Drawing::Color::White;
			this->email_TB->Location = System::Drawing::Point(21, 15);
			this->email_TB->Margin = System::Windows::Forms::Padding(4);
			this->email_TB->Name = L"email_TB";
			this->email_TB->Size = System::Drawing::Size(443, 20);
			this->email_TB->TabIndex = 0;
			this->email_TB->Text = L"Your email";
			// 
			// panel6
			// 
			this->panel6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->panel6->Controls->Add(this->password_TB);
			this->panel6->Location = System::Drawing::Point(49, 341);
			this->panel6->Margin = System::Windows::Forms::Padding(4);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(491, 54);
			this->panel6->TabIndex = 4;
			// 
			// password_TB
			// 
			this->password_TB->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->password_TB->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->password_TB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F));
			this->password_TB->ForeColor = System::Drawing::Color::White;
			this->password_TB->Location = System::Drawing::Point(21, 16);
			this->password_TB->Margin = System::Windows::Forms::Padding(4);
			this->password_TB->Name = L"password_TB";
			this->password_TB->Size = System::Drawing::Size(443, 20);
			this->password_TB->TabIndex = 2;
			this->password_TB->Text = L"Password";
			this->password_TB->UseSystemPasswordChar = true;
			// 
			// password_googl_lbl
			// 
			this->password_googl_lbl->AutoSize = true;
			this->password_googl_lbl->BackColor = System::Drawing::Color::Transparent;
			this->password_googl_lbl->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15, System::Drawing::FontStyle::Bold));
			this->password_googl_lbl->ForeColor = System::Drawing::Color::White;
			this->password_googl_lbl->Location = System::Drawing::Point(43, 300);
			this->password_googl_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->password_googl_lbl->Name = L"password_googl_lbl";
			this->password_googl_lbl->Size = System::Drawing::Size(124, 35);
			this->password_googl_lbl->TabIndex = 5;
			this->password_googl_lbl->Text = L"Password";
			// 
			// Email_lbl
			// 
			this->Email_lbl->AutoSize = true;
			this->Email_lbl->BackColor = System::Drawing::Color::Transparent;
			this->Email_lbl->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15, System::Drawing::FontStyle::Bold));
			this->Email_lbl->ForeColor = System::Drawing::Color::White;
			this->Email_lbl->Location = System::Drawing::Point(43, 185);
			this->Email_lbl->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Email_lbl->Name = L"Email_lbl";
			this->Email_lbl->Size = System::Drawing::Size(78, 35);
			this->Email_lbl->TabIndex = 4;
			this->Email_lbl->Text = L"Email";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->BackColor = System::Drawing::Color::Transparent;
			this->label11->Font = (gcnew System::Drawing::Font(L"Segoe UI", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->ForeColor = System::Drawing::Color::White;
			this->label11->Location = System::Drawing::Point(497, 52);
			this->label11->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(319, 106);
			this->label11->TabIndex = 3;
			this->label11->Text = L"Spotify";
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.BackgroundImage")));
			this->pictureBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->pictureBox3->ImageLocation = L"";
			this->pictureBox3->Location = System::Drawing::Point(315, 33);
			this->pictureBox3->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(175, 139);
			this->pictureBox3->TabIndex = 2;
			this->pictureBox3->TabStop = false;
			// 
			// SignUp
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1179, 639);
			this->Controls->Add(this->LoadingPage);
			this->Controls->Add(this->LogIn);
			this->Controls->Add(this->sign_up_with_google_panel);
			this->Controls->Add(this->Sign_up);
			this->Controls->Add(this->PickFavArtists);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"SignUp";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"SignUp";
			this->LoadingPage->ResumeLayout(false);
			this->Sign_up->ResumeLayout(false);
			this->Sign_up->PerformLayout();
			this->Priv_Info_panel->ResumeLayout(false);
			this->Priv_Info_panel->PerformLayout();
			this->PN_panel->ResumeLayout(false);
			this->PN_panel->PerformLayout();
			this->FN_panel->ResumeLayout(false);
			this->FN_panel->PerformLayout();
			this->LN_panel->ResumeLayout(false);
			this->LN_panel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->LogIn->ResumeLayout(false);
			this->LogIn->PerformLayout();
			this->Passwordpanel->ResumeLayout(false);
			this->Passwordpanel->PerformLayout();
			this->IDpanel->ResumeLayout(false);
			this->IDpanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->PickFavArtists->ResumeLayout(false);
			this->PickFavArtists->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->weeknd_pic))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->kanye_pic))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->billie_pic))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->jb_pic))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->harrys_pic))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rihanna_pic))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->am_pic))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->beyonce_pic))->EndInit();
			this->sign_up_with_google_panel->ResumeLayout(false);
			this->sign_up_with_google_panel->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	public: void openChildForm(Form^ childForm, System::Object^ sender) {
		if (activeForm != nullptr)
			activeForm->Close();

		activeForm = childForm;
		childForm->TopLevel = false;
		childForm->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
		childForm->Dock = System::Windows::Forms::DockStyle::Fill;
		instance->Controls->Add(childForm);
		instance->Tag = childForm;
		childForm->BringToFront();
		childForm->Show();
	}
	//loading page
	private: System::Void LoadingPage_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		bottom_load2->Width += 5;
		if (bottom_load2->Width > 884 || bottom_load2->Width > 884) {
			timer1->Stop();
			LogIn->Show();
			LogIn->BringToFront();
		}
	}
	//login page
	private: System::Void ID_TB_Click(System::Object^ sender, System::EventArgs^ e) {
		if (ID_TB->Text == "Unique ID") {
			ID_TB->Text = "";
		}
	}
	private: System::Void PassTB_Click(System::Object^ sender, System::EventArgs^ e) {
		if (PassTB->Text == "Password") {
			PassTB->Text = "";
		}
	}

	private: System::Void LogIn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (ID_TB->Text == "") {
			ID_TB->Text = "Unique ID";
		}
		if (PassTB->Text == "") {
			PassTB->Text = "Password";
		}
	}
	private: System::Void signup_lbl_Click(System::Object^ sender, System::EventArgs^ e) {
		Sign_up->Show();
		Sign_up->BringToFront();
	}
	private: System::Void forgot_lbl_Click(System::Object^ sender, System::EventArgs^ e) {
		Sign_up->Show();
		Sign_up->BringToFront();
	}
	private: System::Void Login_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		std::string ID = msclr::interop::marshal_as<std::string>(ID_TB->Text);
		std::string Pass = msclr::interop::marshal_as<std::string>(PassTB->Text);
		user* u1 = login(ID, Pass);;
		if (u1) {
			current_user = *u1;
			Home2^ newForm = gcnew Home2();
			openChildForm(newForm, sender);
		}
		else {
			// Incorrect uniqueID or password
			Invalid_credentials_lbl->Visible = true;
		}
	}

	//sign up page
	private: System::Void FN_TB_Click(System::Object^ sender, System::EventArgs^ e) {
		if (FN_TB->Text == "First Name") {
			FN_TB->Text = "";
		}
	}
	private: System::Void LN_TB_Click(System::Object^ sender, System::EventArgs^ e) {
		if (LN_TB->Text == "Last Name") {
			LN_TB->Text = "";
		}
	}

	private: System::Void PN_TB_Click(System::Object^ sender, System::EventArgs^ e) {
		if (PN_TB->Text == "Phone Number") {
			PN_TB->Text = "";
		}
	}

	private: System::Void Sign_up_Click(System::Object^ sender, System::EventArgs^ e) {
		if (FN_TB->Text == "") {
			FN_TB->Text = "First Name";
		}
		if (LN_TB->Text == "") {
			LN_TB->Text = "Last Name";
		}
		if (PN_TB->Text == "") {
			PN_TB->Text = "Phone Number";
		}
	}
	private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {

		if (checkBox1->Checked) {
			signup_btn->Enabled = true;
		}
		else {
			signup_btn->Enabled = false;
		}
	}
	private: System::Void signup_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		std::string phone_number = msclr::interop::marshal_as<std::string>(PN_TB->Text);
		std::string first_name = msclr::interop::marshal_as<std::string>(FN_TB->Text);
		std::string last_name = msclr::interop::marshal_as<std::string>(LN_TB->Text);
		current_user = signup(phone_number, first_name, last_name);
		String^ str = gcnew String{ current_user.get_user_id().c_str() };
		gen_ID_value->Text = str;
		gen_Pass_value->Text = str;
		button1->Enabled = true;
	}

	//choose fav artists page
	


	private: System::Void skip_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		Home2^ newForm = gcnew Home2();
		openChildForm(newForm, sender);
	}
	private: System::Void next_to_home_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		std::string artists[10];
		int index = 0;
		if (rihanna_chbx->Checked == true) {
			artists[index] = "Rihanna";
			index++;
		}
		if (beyonce_chbx->Checked == true) {
			artists[index] = "Beyonce";
			index++;
		}
		if (kanye_chbx->Checked == true) {
			artists[index] = "Kanye West";
			index++;
		}
		if (billie_chbx->Checked == true) {
			artists[index] = "Billie Eilish";
			index++;
		}
		if (weeknd_chbx->Checked == true) {
			artists[index] = "The Weeknd";
			index++;
		}
		if (harrys_chbx->Checked == true) {
			artists[index] = "Harry Styles";
			index++;
		}
		if (jb_chbx->Checked == true) {
			artists[index] = "Justin Bieber";
			index++;
		}
		if (am_chbx->Checked == true) {
			artists[index] = "Arctic Monkeys";
			index++;
		}
		current_user.create_fav_playlist(artists, index);
		Home2^ newForm = gcnew Home2();
		openChildForm(newForm, sender);
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	PickFavArtists->Show();
	PickFavArtists->BringToFront();
}
private: System::Void sign_up_with_google_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	sign_up_with_google_panel->Show();
	sign_up_with_google_panel->BringToFront();
}
private: System::Void s_up_google_btn2_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string email = msclr::interop::marshal_as<std::string>(email_TB->Text);
	std::string password = msclr::interop::marshal_as<std::string>(password_TB->Text);
	user* u1 = signUpWithGoogle(email, password);
	if (u1) {
		current_user = *u1;
		String^ str = gcnew String{ current_user.get_user_id().c_str() };
		g_id_lbl->Text = str;
		g_pass_lbl->Text = str;
		continue_btn2->Enabled = true;
	}
	else {
		Invalid_google_lbl->Visible = true;
	}
	
}
private: System::Void continue_btn2_Click(System::Object^ sender, System::EventArgs^ e) {
	PickFavArtists->Show();
	PickFavArtists->BringToFront();
}
};
}
