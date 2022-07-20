#pragma once
#include "Controladora.h"
#include "Botella.h"
#include "FileNivel1.h"
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
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//Buffer
			g = pictureBox1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, pictureBox1->ClientRectangle);
			//Bitmaps
			bmpHeroe = gcnew Bitmap("personaje.png");
			bmpEnemigo = gcnew Bitmap("enemigo.png");
			bmpBotella = gcnew Bitmap("botella.png");
			bmpMap = gcnew Bitmap("mapa.jpeg");
			//bmpEnemigo->MakeTransparent();
			//SoundPlayer
			spMusic = gcnew SoundPlayer("music.wav");
			//Controladora
			control = new ControladoraNivel1(bmpHeroe, bmpEnemigo);

			//Experimentacion
			botella1 = new Botella(250, 250);
			vector<Botella*> botellasAgregadas;
			contadorDeSegundos = 0;
			botellasTiradas = 0;
			botellasTiradasPor1 = 0;
			bmpBomba = gcnew Bitmap("bomba.png");
		}
	private:
		int tiempito = 50;
		//Buffer
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;

		//Bitmaps
		Bitmap^ bmpHeroe;
		Bitmap^ bmpEnemigo;
		Bitmap^ bmpBotella;
		Bitmap^ bmpMap;

		//SoundPlayer
		SoundPlayer^ spMusic;

		//Controladora
		ControladoraNivel1* control;
		//Experimentación
		Botella* botella1;
		int contadorDeSegundos;
		int botellasTiradas;
		int botellasTiradasPor1;
		Bitmap^ bmpBomba;

		//file
		File1* archivo;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ labelhp;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ labeltiempo;
	private: System::Windows::Forms::Timer^ timer2;
	private: System::Windows::Forms::Label^ botella;
	private: System::Windows::Forms::Label^ labelBotellas;
	private: System::Windows::Forms::Timer^ timerBasura;
	private: System::Windows::Forms::Label^ labelBotellasRecogidas;

	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
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
			this->botella = (gcnew System::Windows::Forms::Label());
			this->labelBotellas = (gcnew System::Windows::Forms::Label());
			this->timerBasura = (gcnew System::Windows::Forms::Timer(this->components));
			this->labelBotellasRecogidas = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			//
			// timer1
			//
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			//
			// pictureBox1
			//
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(-3, -39);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1333, 750);
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
			this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick);
			//
			// botella
			//
			this->botella->AutoSize = true;
			this->botella->Location = System::Drawing::Point(616, 32);
			this->botella->Name = L"botella";
			this->botella->Size = System::Drawing::Size(116, 16);
			this->botella->TabIndex = 5;
			this->botella->Text = L"botellasPasadas: ";
			//
			// labelBotellas
			//
			this->labelBotellas->AutoSize = true;
			this->labelBotellas->Location = System::Drawing::Point(738, 32);
			this->labelBotellas->Name = L"labelBotellas";
			this->labelBotellas->Size = System::Drawing::Size(14, 16);
			this->labelBotellas->TabIndex = 6;
			this->labelBotellas->Text = L"0";
			//
			// timerBasura
			//
			this->timerBasura->Enabled = true;
			this->timerBasura->Interval = 1000;
			this->timerBasura->Tick += gcnew System::EventHandler(this, &MyForm::timerBasura_Tick);
			//
			// labelBotellasRecogidas
			//
			this->labelBotellasRecogidas->AutoSize = true;
			this->labelBotellasRecogidas->Location = System::Drawing::Point(997, 32);
			this->labelBotellasRecogidas->Name = L"labelBotellasRecogidas";
			this->labelBotellasRecogidas->Size = System::Drawing::Size(55, 16);
			this->labelBotellasRecogidas->TabIndex = 7;
			this->labelBotellasRecogidas->Text = L"Puntaje:";
			//
			// label3
			//
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(1072, 32);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(14, 16);
			this->label3->TabIndex = 8;
			this->label3->Text = L"0";
			//
			// MyForm
			//
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1329, 705);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->labelBotellasRecogidas);
			this->Controls->Add(this->labelBotellas);
			this->Controls->Add(this->botella);
			this->Controls->Add(this->labeltiempo);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->labelhp);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {//Timer Principal
		//Contador
		contadorDeSegundos += timer1->Interval;
		botellasTiradas = control->getNumeroBotellasTiradas();

		//Borrar
		buffer->Graphics->Clear(Color::WhiteSmoke);

		//Colision
		control->colision();

		//Mover
		srand(time(NULL));
		control->moverTodos(buffer->Graphics, bmpBotella);

		//Dibujar
		//

		botellasTiradasPor1 = control->getEnemigo(0)->get_i();
		buffer->Graphics->DrawImage(bmpMap, 0, 0, this->Width, this->Height);
		control->dibujarTodos(buffer->Graphics, bmpHeroe, bmpEnemigo, bmpBotella);
		labelhp->Text = Convert::ToString(control->getHeroe()->getHp());
		labeltiempo->Text = Convert::ToString(tiempito);
		labelBotellas->Text = Convert::ToString(control->getBotellasPasadas());;

		label3->Text = Convert::ToString(control->getBotellasRecogidas());
		//label3->Text = "No hay";

		////Experimentar aqui arriba
		//if (contadorDeSegundos % 1000 == 0) {
		//	//Experimentacion con botellas
		//	for (size_t i = 0; i < control->getNumeroEnemigos(); i++)
		//	{
		//		control->todosTiranBasura(buffer->Graphics, bmpBotella);
		//	}

		//botella1->setX(control->getEnemigo(1)->getX());
		//botella1->setY(control->getEnemigo(1)->getY() + 30);
		//botella1->dibujar(buffer->Graphics, bmpBotella);
		//}
		//Experimentacion con botellas

		//Movimiento de Botellas
		if (contadorDeSegundos % 2000 == 0) {
			//Esto está bien
			control->todosTiranBasura(buffer->Graphics, bmpBotella);
		}

		control->moverBotellas(buffer->Graphics, bmpBotella);

		//Movimiento de Bombas
		if (contadorDeSegundos % 3000 == 0) {
			//Esto está bien
			control->todosTiranBombas(buffer->Graphics, bmpBomba);
		}

		control->moverBombas(buffer->Graphics, bmpBomba);

		//labelBotellas->Text = Convert::ToString(control->getBotellasPasadas());

		//Condiciones
		if (control->getHeroe()->getHp() == 0)
		{
			timer1->Enabled = false;
			timer2->Enabled = false;
			MessageBox::Show("Perdiste");
			spMusic->Stop();
			this->Close();
		}
		else if (tiempito == 0 && 5 >= control->getHeroe()->getHp() > 0 && control->getBotellasRecogidas() >= 50) {
			timer1->Enabled = false;
			timer2->Enabled = false;
			MessageBox::Show("Pasaste al segundo nivel!!!" + "\n" + "\nPuntaje: " + control->getBotellasRecogidas() + "\nVidas: " + control->getHeroe()->getHp() + "\nBotellas Pasadas: " + control->getBotellasPasadas());
			spMusic->Stop();
			this->Close();
			archivo = new File1(control);
		}
		else if (tiempito == 0 && control->getBotellasRecogidas() < 50) {
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
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::A:
			control->getHeroe()->mover(buffer->Graphics, 'A'); break;
		case Keys::D:
			control->getHeroe()->mover(buffer->Graphics, 'D'); break;
		case Keys::W:
			control->getHeroe()->mover(buffer->Graphics, 'W'); break;
		case Keys::S:
			control->getHeroe()->mover(buffer->Graphics, 'S'); break;
		}
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		timerBasura->Interval = 1000;
		timerBasura->Enabled = true;
		spMusic->PlayLooping();
	}
	private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
		tiempito--;
	}
	private: System::Void timerBasura_Tick(System::Object^ sender, System::EventArgs^ e) {
		//	Botella* b = new Botella(bmpBotella->Width / 4, bmpBotella->Height, 650, 510, 2);
			//control->agregaBotellas(b);
	}
	};
}