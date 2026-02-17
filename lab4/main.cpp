#include "login.h"
#include "MyForm1.h"

using namespace System;
using namespace System::Windows::Forms;

[System::STAThreadAttribute]
int main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	lab4::MyForm form;
	Application::Run(gcnew lab4::MyForm());
	return 0;
}
