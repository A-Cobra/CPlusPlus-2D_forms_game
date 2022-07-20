#pragma once
#include "Controladora2.h"
#include "FileNivel2.h"
namespace BoomingTrashFinal {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm2 : public System::Windows::Forms::Form
	{
	public:
		MyForm2(void)
		{
			InitializeComponent();
			//Buffer
			g = pictureBox1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, pictureBox1->ClientRectangle);
			//Bitmaps
			bmpHeroe2 = gcnew Bitmap("personaje2.png");
			bmpEnemigo2 = gcnew Bitmap("enemigo2.png");
			bmpBarco = gcnew Bitmap("barco.png");
			bmpBasura2 = gcnew Bitmap("basura2.png");
			bmpMap2 = gcnew Bitmap("mapa2.jpg");
			bmpEnemigo2->MakeTransparent();
			//SoundPlayer
			spMusic = gcnew SoundPlayer("music.wav");
			//Controladora
			control = new ControladoraNivel2(bmpHeroe2, bmpEnemigo2, bmpBarco);
		}
	private:
		int tiempito = 50;
		//Buffer
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;

		//Bitmaps
		Bitmap^ bmpHeroe2;
		Bitmap^ bmpEnemigo2;
		Bitmap^ bmpBasura2;
		Bitmap^ bmpMap2;
		Bitmap^ bmpBarco;

		//SoundPlayer
		SoundPlayer^ spMusic;

		//Controladora
		ControladoraNivel2* control;

		//File
		File2* archivo;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ labelhp;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ labeltiempo;
	private: System::Windows::Forms::Timer^ timer2;
	private: System::Windows::Forms::Label^ basura;
	private: System::Windows::Forms::Label^ labelBasura;
	private: System::Windows::Forms::Timer^ timerBasura;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ punt;

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm2()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->labelhp = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->labeltiempo = (gcnew System::Windows::Forms::Label());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->basura = (gcnew System::Windows::Forms::Label());
			this->labelBasura = (gcnew System::Windows::Forms::Label());
			this->timerBasura = (gcnew System::Windows::Forms::Timer(this->components));
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->punt = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			//
			// timer1
			//
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm2::timer1_Tick);
			//
			// pictureBox1
			//
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(-1, -1);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1333, 729);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			//
			// label1
			//
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(41, 32);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(42, 16);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Vidas";
			//
			// labelhp
			//
			this->labelhp->AutoSize = true;
			this->labelhp->Location = System::Drawing::Point(115, 32);
			this->labelhp->Name = L"labelhp";
			this->labelhp->Size = System::Drawing::Size(14, 16);
			this->labelhp->TabIndex = 2;
			this->labelhp->Text = L"0";
			//
			// label2
			//
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(172, 32);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(57, 16);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Tiempo:";
			//
			// labeltiempo
			//
			this->labeltiempo->AutoSize = true;
			this->labeltiempo->Location = System::Drawing::Point(245, 32);
			this->labeltiempo->Name = L"labeltiempo";
			this->labeltiempo->Size = System::Drawing::Size(14, 16);
			this->labeltiempo->TabIndex = 4;
			this->labeltiempo->Text = L"0";
			//
			// timer2
			//
			this->timer2->Enabled = true;
			this->timer2->Interval = 1000;
			this->timer2->Tick += gcnew System::EventHandler(this, &MyForm2::timer2_Tick);
			//
			// basura
			//
			this->basura->AutoSize = true;
			this->basura->Location = System::Drawing::Point(616, 32);
			this->basura->Name = L"basura";
			this->basura->Size = System::Drawing::Size(107, 16);
			this->basura->TabIndex = 5;
			this->basura->Text = L"Basura Pasada: ";
			//
			// labelBasura
			//
			this->labelBasura->AutoSize = true;
			this->labelBasura->Location = System::Drawing::Point(738, 32);
			this->labelBasura->Name = L"labelBasura";
			this->labelBasura->Size = System::Drawing::Size(14, 16);
			this->labelBasura->TabIndex = 6;
			this->labelBasura->Text = L"0";
			this->labelBasura->Click += gcnew System::EventHandler(this, &MyForm2::labelBasura_Click);
			//
			// timerBasura
			//
			this->timerBasura->Enabled = true;
			this->timerBasura->Interval = 1000;
			this->timerBasura->Tick += gcnew System::EventHandler(this, &MyForm2::timerBasura_Tick);
			//
			// label3
			//
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(941, 32);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(58, 16);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Puntaje: ";
			//
			// punt
			//
			this->punt->AutoSize = true;
			this->punt->Location = System::Drawing::Point(1025, 32);
			this->punt->Name = L"punt";
			this->punt->Size = System::Drawing::Size(14, 16);
			this->punt->TabIndex = 8;
			this->punt->Text = L"0";
			//
			// MyForm2
			//
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1329, 723);
			this->Controls->Add(this->punt);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->labelBasura);
			this->Controls->Add(this->basura);
			this->Controls->Add(this->labeltiempo);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->labelhp);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm2";
			this->Text = L"MyForm2";
			this->Load += gcnew System::EventHandler(this, &MyForm2::MyForm2_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm2::MyForm2_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		//Borrar
		buffer->Graphics->Clear(Color::WhiteSmoke);

		//Colision
		control->colision();

		//Mover
		srand(time(NULL));
		control->moverTodos(buffer->Graphics);

		//Dibujar
		buffer->Graphics->DrawImage(bmpMap2, 0, 0, this->Width, this->Height);
		control->dibujarTodos(buffer->Graphics, bmpHeroe2, bmpEnemigo2, bmpBarco, bmpBasura2);
		labelhp->Text = Convert::ToString(control->getHeroe2()->getHp());
		labeltiempo->Text = Convert::ToString(tiempito);
		labelBasura->Text = Convert::ToString(control->getBasuraPasada());
		punt->Text = Convert::ToString(control->getBasuraRecogida());

		//Condiciones
		if (control->getHeroe2()->getHp() == 0)
		{
			timer1->Enabled = false;
			timer2->Enabled = false;
			MessageBox::Show("Perdiste");
			spMusic->Stop();
			this->Close();
		}
		else if (tiempito == 0 && 5 >= control->getHeroe2()->getHp() > 0 && control->getBasuraRecogida() >= 50) {
			timer1->Enabled = false;
			timer2->Enabled = false;
			MessageBox::Show("Ganaste!!" + "\n" + "\nPuntaje: " + control->getBasuraRecogida() + "\nVidas : " + control->getHeroe2()->getHp() + "\nBasura Pasada : " + control->getBasuraPasada());
			spMusic->Stop();
			this->Close();
			archivo = new File2(control);
		}
		else if (tiempito == 0 && control->getBasuraRecogida() < 50) {
			timer1->Enabled = false;
			timer2->Enabled = false;
			MessageBox::Show("Perdiste");
			spMusic->Stop();
			this->Close();
		}
		else {
			//Renderizar
			buffer->Render(g);
		}
	}
	private: System::Void MyForm2_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::A:
			control->getHeroe2()->mover(buffer->Graphics, 'A'); break;
		case Keys::D:
			control->getHeroe2()->mover(buffer->Graphics, 'D'); break;
		case Keys::W:
			control->getHeroe2()->mover(buffer->Graphics, 'W'); break;
		case Keys::S:
			control->getHeroe2()->mover(buffer->Graphics, 'S'); break;
		}
	}
	private: System::Void MyForm2_Load(System::Object^ sender, System::EventArgs^ e) {
		timerBasura->Interval = 2 * 1000;
		timerBasura->Enabled = true;
		spMusic->PlayLooping();
	}
	private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
		tiempito--;
	}
	private: System::Void timerBasura_Tick(System::Object^ sender, System::EventArgs^ e) {
		Basura2* b = new Basura2(bmpBasura2->Width / 4, bmpBasura2->Height);
		control->agregaBasura(b);
	}
	private: System::Void labelBasura_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
