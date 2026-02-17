#pragma once

namespace lab4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for cart
	/// </summary>
	public ref class cart : public System::Windows::Forms::Form
	{
	public:
		cart(void)
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
		~cart()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ h1;
	protected:
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ name1;
	private: System::Windows::Forms::Label^ price1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Button^ button2;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(cart::typeid));
			this->h1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->name1 = (gcnew System::Windows::Forms::Label());
			this->price1 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// h1
			// 
			this->h1->AutoSize = true;
			this->h1->Location = System::Drawing::Point(36, 41);
			this->h1->Name = L"h1";
			this->h1->Size = System::Drawing::Size(145, 25);
			this->h1->TabIndex = 0;
			this->h1->Text = L"Shopping cart";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->Location = System::Drawing::Point(41, 103);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(306, 233);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// name1
			// 
			this->name1->AutoSize = true;
			this->name1->ForeColor = System::Drawing::Color::Firebrick;
			this->name1->Location = System::Drawing::Point(374, 103);
			this->name1->Name = L"name1";
			this->name1->Size = System::Drawing::Size(128, 25);
			this->name1->TabIndex = 2;
			this->name1->Text = L"Red Garage";
			// 
			// price1
			// 
			this->price1->AutoSize = true;
			this->price1->Location = System::Drawing::Point(374, 311);
			this->price1->Name = L"price1";
			this->price1->Size = System::Drawing::Size(66, 25);
			this->price1->TabIndex = 3;
			this->price1->Text = L"8.45$";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(374, 156);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(222, 25);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Manufacturer: Garage";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(374, 246);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(111, 25);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Type: Red";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(374, 184);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(227, 25);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Deliver: Garage Group";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(374, 214);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(252, 25);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Expiration date: 21.02.28";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(897, 214);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(116, 42);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Delete";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(374, 501);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(252, 25);
			this->label5->TabIndex = 15;
			this->label5->Text = L"Expiration date: 21.02.28";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(374, 471);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(227, 25);
			this->label6->TabIndex = 14;
			this->label6->Text = L"Deliver: Garage Group";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(374, 533);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(136, 25);
			this->label7->TabIndex = 13;
			this->label7->Text = L"Type: Yellow";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(374, 443);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(222, 25);
			this->label8->TabIndex = 12;
			this->label8->Text = L"Manufacturer: Garage";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(374, 598);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(66, 25);
			this->label9->TabIndex = 11;
			this->label9->Text = L"8.45$";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->ForeColor = System::Drawing::Color::Firebrick;
			this->label10->Location = System::Drawing::Point(374, 390);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(153, 25);
			this->label10->TabIndex = 10;
			this->label10->Text = L"Yellow Garage";
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->Location = System::Drawing::Point(41, 390);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(306, 233);
			this->pictureBox2->TabIndex = 9;
			this->pictureBox2->TabStop = false;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(897, 484);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(116, 42);
			this->button2->TabIndex = 16;
			this->button2->Text = L"Delete";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// cart
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1096, 720);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->price1);
			this->Controls->Add(this->name1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->h1);
			this->Name = L"cart";
			this->Text = L"cart";
			this->Load += gcnew System::EventHandler(this, &cart::CartForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		void loadCartItems() {
			String^ connString = "Data Source=(LocalDB)\\MSSQLLocalDB;Initial Catalog=drinks_shop;Integrated Security=True;";
			SqlConnection^ sqlConn = gcnew SqlConnection(connString);
			try {
				sqlConn->Open();
				String^ query = "SELECT name, price FROM Drinks WHERE isInCart = 1";
				SqlCommand^ cmd = gcnew SqlCommand(query, sqlConn);
				SqlDataReader^ reader = cmd->ExecuteReader();
				int itemIndex = 0;
				while (reader->Read()) {
					String^ name = reader->GetString(0);
					double price = reader->GetDouble(1);
					if (itemIndex == 0) {
						name1->Text = name;
						price1->Text = price.ToString("C");
					}
					else if (itemIndex == 1) {
						label10->Text = name;
						label9->Text = price.ToString("C");
					}
					itemIndex++;
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show("Database Error: " + ex->Message);
			}
			finally {
				sqlConn->Close();
			}
		}
		private: System::Void CartForm_Load(System::Object^ sender, System::EventArgs^ e) {
			loadCartItems();
		}
	};
}
