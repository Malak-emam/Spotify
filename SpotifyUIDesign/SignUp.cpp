#include "SignUp.h"



using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	SpotifyUIDesign::SignUp form;
	Application::Run(% form);
}