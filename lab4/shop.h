#pragma once
#include "cart.h"

namespace lab4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Button^ cart_btn;

	private: System::Windows::Forms::Button^ search_btn;
	private: System::Windows::Forms::TextBox^ search_bar;
	private: System::Windows::Forms::Button^ buy_btn1;
	private: System::Windows::Forms::Button^ buy_btn2;
	private: System::Windows::Forms::Button^ buy_btn3;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm1::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->cart_btn = (gcnew System::Windows::Forms::Button());
			this->search_btn = (gcnew System::Windows::Forms::Button());
			this->search_bar = (gcnew System::Windows::Forms::TextBox());
			this->buy_btn1 = (gcnew System::Windows::Forms::Button());
			this->buy_btn2 = (gcnew System::Windows::Forms::Button());
			this->buy_btn3 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(99, 151);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(300, 300);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm1::pictureBox1_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(438, 151);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(300, 300);
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &MyForm1::pictureBox2_Click);
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(777, 151);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(300, 300);
			this->pictureBox3->TabIndex = 2;
			this->pictureBox3->TabStop = false;
			this->pictureBox3->Click += gcnew System::EventHandler(this, &MyForm1::pictureBox3_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(99, 478);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(128, 25);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Red Garage";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(438, 478);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(153, 25);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Yellow Garage";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(777, 478);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(154, 25);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Lemon Garage";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(345, 478);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(54, 25);
			this->label4->TabIndex = 6;
			this->label4->Text = L"0.5L";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(684, 478);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(54, 25);
			this->label5->TabIndex = 7;
			this->label5->Text = L"0.5L";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(1023, 478);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(54, 25);
			this->label6->TabIndex = 8;
			this->label6->Text = L"0.3L";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(99, 519);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(66, 25);
			this->label7->TabIndex = 9;
			this->label7->Text = L"8.45$";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(438, 519);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(66, 25);
			this->label8->TabIndex = 10;
			this->label8->Text = L"8.45$";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(777, 519);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(66, 25);
			this->label9->TabIndex = 11;
			this->label9->Text = L"6.25$";
			// 
			// cart_btn
			// 
			this->cart_btn->Location = System::Drawing::Point(913, 78);
			this->cart_btn->Name = L"cart_btn";
			this->cart_btn->Size = System::Drawing::Size(164, 40);
			this->cart_btn->TabIndex = 12;
			this->cart_btn->Text = L"Shopping cart";
			this->cart_btn->UseVisualStyleBackColor = true;
			// 
			// search_btn
			// 
			this->search_btn->Location = System::Drawing::Point(646, 73);
			this->search_btn->Name = L"search_btn";
			this->search_btn->Size = System::Drawing::Size(92, 40);
			this->search_btn->TabIndex = 13;
			this->search_btn->Text = L"Search";
			this->search_btn->UseVisualStyleBackColor = true;
			this->search_btn->Click += gcnew System::EventHandler(this, &MyForm1::search_btn_Click);
			// 
			// search_bar
			// 
			this->search_bar->Location = System::Drawing::Point(99, 78);
			this->search_bar->Name = L"search_bar";
			this->search_bar->Size = System::Drawing::Size(530, 31);
			this->search_bar->TabIndex = 14;
			this->search_bar->Text = L"I am looking for...";
			// 
			// buy_btn1
			// 
			this->buy_btn1->Location = System::Drawing::Point(99, 569);
			this->buy_btn1->Name = L"buy_btn1";
			this->buy_btn1->Size = System::Drawing::Size(300, 40);
			this->buy_btn1->TabIndex = 15;
			this->buy_btn1->Text = L"Add to cart";
			this->buy_btn1->UseVisualStyleBackColor = true;
			this->buy_btn1->Click += gcnew System::EventHandler(this, &MyForm1::buy_btn1_Click);
			// 
			// buy_btn2
			// 
			this->buy_btn2->Location = System::Drawing::Point(443, 569);
			this->buy_btn2->Name = L"buy_btn2";
			this->buy_btn2->Size = System::Drawing::Size(294, 40);
			this->buy_btn2->TabIndex = 16;
			this->buy_btn2->Text = L"Add to cart";
			this->buy_btn2->UseVisualStyleBackColor = true;
			this->buy_btn2->Click += gcnew System::EventHandler(this, &MyForm1::buy_btn2_Click);
			// 
			// buy_btn3
			// 
			this->buy_btn3->Location = System::Drawing::Point(782, 569);
			this->buy_btn3->Name = L"buy_btn3";
			this->buy_btn3->Size = System::Drawing::Size(295, 40);
			this->buy_btn3->TabIndex = 17;
			this->buy_btn3->Text = L"Add to cart";
			this->buy_btn3->UseVisualStyleBackColor = true;
			this->buy_btn3->Click += gcnew System::EventHandler(this, &MyForm1::buy_btn3_Click);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1215, 744);
			this->Controls->Add(this->buy_btn3);
			this->Controls->Add(this->buy_btn2);
			this->Controls->Add(this->buy_btn1);
			this->Controls->Add(this->search_bar);
			this->Controls->Add(this->search_btn);
			this->Controls->Add(this->cart_btn);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm1";
			this->Text = L"MyForm1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void pictureBox3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void buy_btn1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ connString = "Data Source=(LocalDB)\\MSSQLLocalDB;Initial Catalog=drinks_shop;Integrated Security=True;";
		SqlConnection^ sqlConn = gcnew SqlConnection(connString);
		try {
			sqlConn->Open();
			String^ query = "UPDATE Drinks SET isInCart = 1 WHERE name = @name";
			SqlCommand^ cmd = gcnew SqlCommand(query, sqlConn);
			cmd->Parameters->AddWithValue("@name", "red_garage");
			int rowsAffected = cmd->ExecuteNonQuery();
			this->buy_btn1->Text = "In cart";
			this->buy_btn1->Enabled = false;

			if (rowsAffected > 0) {
				MessageBox::Show("Red Garage added to cart!");
				cart^ cartForm = gcnew cart();
				cartForm->Show();
			}
			else {
				MessageBox::Show("Error: Drink 'red_garage' not found in database.");
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Database Error: " + ex->Message);
		}
		finally {
			sqlConn->Close();
		}
	}
	private: System::Void buy_btn2_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ connString = "Data Source=(LocalDB)\\MSSQLLocalDB;Initial Catalog=drinks_shop;Integrated Security=True;";
		SqlConnection^ sqlConn = gcnew SqlConnection(connString);
		try {
			sqlConn->Open();
			String^ query = "UPDATE Drinks SET isInCart = 1 WHERE TRIM(name) = @name";
			SqlCommand^ cmd = gcnew SqlCommand(query, sqlConn);
			cmd->Parameters->AddWithValue("@name", "yellow_garage");
			cmd->ExecuteNonQuery();
			this->buy_btn2->Text = "In cart";
			this->buy_btn2->Enabled = false;
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error: " + ex->Message);
		}
		MessageBox::Show("Yellow Garage added to cart!");
		cart^ cartForm = gcnew cart();
		cartForm->Show();
	}
	private: System::Void buy_btn3_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ connString = "Data Source=(LocalDB)\\MSSQLLocalDB;Initial Catalog=drinks_shop;Integrated Security=True;";
		SqlConnection^ sqlConn = gcnew SqlConnection(connString);
		try {
			sqlConn->Open();
			String^ query = "UPDATE Drinks SET isInCart = 1 WHERE TRIM(name) = @name";
			SqlCommand^ cmd = gcnew SqlCommand(query, sqlConn);
			cmd->Parameters->AddWithValue("@name", "lemon_garage");
			cmd->ExecuteNonQuery();
			this->buy_btn3->Text = "In cart";
			this->buy_btn3->Enabled = false;
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error: " + ex->Message);
		}
		MessageBox::Show("Lemon Garage added to cart!");
		cart^ cartForm = gcnew cart();
		cartForm->Show();
	}
	private: System::Void search_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		//MessageBox::Show("Searching...");
		String^ query = search_bar->Text->Trim()->ToLower();

		this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
		this->pictureBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
		this->pictureBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;

		if (String::IsNullOrEmpty(query) || query == "i am looking for...") {
			MessageBox::Show("Please enter a search query.");
			return;
		}
		if (query->Contains("red")) {
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			MessageBox::Show("Found: Red Garage\nPrice: 8.45$\nVolume: 0.5L");
		}
		else if (query->Contains("yellow")) {
			this->pictureBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			MessageBox::Show("Found: Yellow Garage\nPrice: 8.45$\nVolume: 0.5L");
		}
		else if (query->Contains("lemon")) {
			this->pictureBox3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			MessageBox::Show("Found: Lemon Garage\nPrice: 8.45$\nVolume: 0.5L");

		}
		else {
			MessageBox::Show("No results for: " + query);
		}
	}
	};
}
