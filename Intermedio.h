#pragma once
#include "Nivel1.h"
#include "Nivel2.h"
namespace BoomingTrashFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Intermedio
	/// </summary>
	public ref class Intermedio : public System::Windows::Forms::Form
	{
	public:
		Intermedio(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Intermedio()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(55, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(145, 48);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Nivel 1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Intermedio::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(55, 84);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(145, 48);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Nivel 2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Intermedio::button2_Click);
			// 
			// Intermedio
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(260, 144);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"Intermedio";
			this->Text = L"Intermedio";
			this->Load += gcnew System::EventHandler(this, &Intermedio::Intermedio_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Intermedio_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Form^ nivel1 = gcnew MyForm();
		nivel1->Show();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		Form^ nivel2 = gcnew MyForm2();
		nivel2->Show();
	}
	};
}
