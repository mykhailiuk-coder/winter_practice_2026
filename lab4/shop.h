#pragma once
#include "MyForm1.h"
#include "cart.h"
#include "login.h"



namespace lab4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for dynamic_shop
	/// </summary>
	public ref class dynamic_shop : public System::Windows::Forms::Form
	{
	public:
		dynamic_shop(void)
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
		~dynamic_shop()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::FlowLayoutPanel^ container;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ shop_btn;


	protected:

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
			this->container = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->shop_btn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// container
			// 
			this->container->AutoScroll = true;
			this->container->Location = System::Drawing::Point(12, 101);
			this->container->Name = L"container";
			this->container->Size = System::Drawing::Size(1508, 846);
			this->container->TabIndex = 0;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(32, 45);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(1200, 31);
			this->textBox1->TabIndex = 1;
			this->textBox1->Text = L"I am looking for ...";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &dynamic_shop::textBox1_TextChanged);
			// 
			// shop_btn
			// 
			this->shop_btn->Location = System::Drawing::Point(1247, 44);
			this->shop_btn->Name = L"shop_btn";
			this->shop_btn->Size = System::Drawing::Size(188, 40);
			this->shop_btn->TabIndex = 2;
			this->shop_btn->Text = L"Shopping cart";
			this->shop_btn->UseVisualStyleBackColor = true;
			this->shop_btn->Click += gcnew System::EventHandler(this, &dynamic_shop::shop_btn_Click);
			// 
			// dynamic_shop
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1532, 959);
			this->Controls->Add(this->shop_btn);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->container);
			this->Name = L"dynamic_shop";
			this->Text = L"dynamic_shop";
			this->Load += gcnew System::EventHandler(this, &dynamic_shop::dynamic_shop_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		void OnDynamicBuyClick(System::Object^ sender, System::EventArgs^ e) {
			Button^ clickedBtn = safe_cast<Button^>(sender);
			String^ drinkName = clickedBtn->Tag->ToString(); // Отримуємо назву з Tag

			String^ connString = "Data Source=(LocalDB)\\MSSQLLocalDB;Initial Catalog=drinks_shop;Integrated Security=True;";
			SqlConnection^ sqlConn = gcnew SqlConnection(connString);
			try {
				sqlConn->Open();
				String^ query = "UPDATE Drinks SET isInCart = 1 WHERE name = @name";
				SqlCommand^ cmd = gcnew SqlCommand(query, sqlConn);
				cmd->Parameters->AddWithValue("@name", drinkName);

				if (cmd->ExecuteNonQuery() > 0) {
					clickedBtn->Text = L"In cart";
					clickedBtn->Enabled = false;
					MessageBox::Show(drinkName + " added to cart!");
				}
			}
			catch (Exception^ ex) { MessageBox::Show(ex->Message); }
			finally { sqlConn->Close(); }
		}

		void LoadDynamicProducts() {
			// Очищаємо контейнер перед завантаженням
			this->container->Controls->Clear();

			String^ connString = "Data Source=(LocalDB)\\MSSQLLocalDB;Initial Catalog=drinks_shop;Integrated Security=True;";
			SqlConnection^ sqlConn = gcnew SqlConnection(connString);

			try {
				sqlConn->Open();
				String^ query = "SELECT name, price, volume, isInCart, image FROM Drinks";
				SqlCommand^ cmd = gcnew SqlCommand(query, sqlConn);
				SqlDataReader^ reader = cmd->ExecuteReader();

				while (reader->Read()) {
					// Створюємо головну панель картки
					Panel^ card = gcnew Panel();
					card->Size = System::Drawing::Size(220, 320);
					card->BorderStyle = BorderStyle::FixedSingle;
					card->Margin = System::Windows::Forms::Padding(10);

					// PictureBox для фото
					PictureBox^ pb = gcnew PictureBox();
					pb->Size = System::Drawing::Size(200, 200);
					pb->Location = System::Drawing::Point(10, 10);
					pb->SizeMode = PictureBoxSizeMode::Zoom;
					String^ imgPath = reader["image"]->ToString();
					if (IO::File::Exists(imgPath)) pb->Image = Image::FromFile(imgPath);

					// Label для назви
					Label^ lblName = gcnew Label();
					lblName->Text = reader["name"]->ToString();
					lblName->Location = System::Drawing::Point(10, 220);
					lblName->AutoSize = true;
					lblName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, FontStyle::Bold));

					// Label для ціни та об'єму
					Label^ lblInfo = gcnew Label();
					lblInfo->Text = reader["price"]->ToString() + "$   |   " + reader["volume"]->ToString() + "L";
					lblInfo->Location = System::Drawing::Point(10, 250);
					lblInfo->AutoSize = true;

					// Кнопка замовлення
					Button^ btn = gcnew Button();
					btn->Size = System::Drawing::Size(200, 30);
					btn->Location = System::Drawing::Point(10, 280);
					btn->Tag = reader["name"]->ToString(); // Зберігаємо ім'я для SQL запиту

					if (Convert::ToBoolean(reader["isInCart"])) {
						btn->Text = L"In cart";
						btn->Enabled = false;
					}
					else {
						btn->Enabled = true;
						btn->Text = L"Add to cart";
						btn->Click += gcnew System::EventHandler(this, &dynamic_shop::OnDynamicBuyClick);
					}

					// Додаємо елементи на картку, а картку в контейнер
					card->Controls->Add(pb);
					card->Controls->Add(lblName);
					card->Controls->Add(lblInfo);
					card->Controls->Add(btn);
					this->container->Controls->Add(card);
				}
			}
			catch (Exception^ ex) { MessageBox::Show("Error: " + ex->Message); }
			finally { sqlConn->Close(); }
		}
#pragma endregion
		private: System::Void dynamic_shop_Load(System::Object^ sender, System::EventArgs^ e) {
			LoadDynamicProducts();
		}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		String^ query = textBox1->Text->Trim()->ToLower();
		for each (Control^ ctrl in container->Controls) {
			if (dynamic_cast<Panel^>(ctrl) != nullptr) {
				Panel^ card = safe_cast<Panel^>(ctrl);
				Label^ lblName = safe_cast<Label^>(card->Controls[1]); // Ім'я знаходиться на другій позиції
				if (lblName->Text->ToLower()->Contains(query)) {
					card->Visible = true;
				}
				else {
					card->Visible = false;
				}
			}
		}
	}

private: System::Void shop_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	// 1. Створюємо екземпляр форми кошика
	lab4::cart^ cartForm = gcnew lab4::cart();

	// 2. Підписуємося на подію закриття вікна кошика
	cartForm->FormClosed += gcnew FormClosedEventHandler(this, &dynamic_shop::OnCartClosed);

	// 3. Показуємо форму
	cartForm->Show();
}

private: System::Void OnCartClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	this->LoadDynamicProducts();
}
};
}
