#pragma once
#include <time.h>
#include <fstream>
#include "LUPMethod.h"
#include "MatrixMethod.h"
#include "RotationMethod.h"
const int WCONST = 5;
const int minrand = 0;
const int maxrand = 100;
int operations, iterations;
int op1, op2, op3;//Кількість операцій кожного із методів (1-LUP;2-Матричний;3-Обертання)
float t1, t2, t3;//Час роботи кожного із методів в с (1-LUP;2-Матричний;3-Обертання)
int it1, it2, it3;//Кількість ітерацій кожного із методів (1-LUP;2-Матричний;3-Обертання)
matrix SLARmatrix = matrix(1, 1), fr = matrix(1, 1);
namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::NumericUpDown^  Number;
	protected:

	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::CheckBox^  RotationCheck;

	private: System::Windows::Forms::CheckBox^  MatrixCheck;
	private: System::Windows::Forms::CheckBox^  LUPCheck;




	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::DataGridView^  SLAR;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::DataGridView^  LUPSol;


	private: System::Windows::Forms::DataGridView^  MatrixSol;
	private: System::Windows::Forms::DataGridView^  RotationSol;



	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  graph;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label18;



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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->Number = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->RotationCheck = (gcnew System::Windows::Forms::CheckBox());
			this->MatrixCheck = (gcnew System::Windows::Forms::CheckBox());
			this->LUPCheck = (gcnew System::Windows::Forms::CheckBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SLAR = (gcnew System::Windows::Forms::DataGridView());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->LUPSol = (gcnew System::Windows::Forms::DataGridView());
			this->MatrixSol = (gcnew System::Windows::Forms::DataGridView());
			this->RotationSol = (gcnew System::Windows::Forms::DataGridView());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->graph = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Number))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SLAR))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LUPSol))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MatrixSol))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->RotationSol))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->graph))->BeginInit();
			this->SuspendLayout();
			// 
			// Number
			// 
			this->Number->Location = System::Drawing::Point(28, 56);
			this->Number->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
			this->Number->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->Number->Name = L"Number";
			this->Number->Size = System::Drawing::Size(119, 20);
			this->Number->TabIndex = 0;
			this->Number->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->Number->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDown1_ValueChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(25, 32);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(122, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Количество уравнений";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->RotationCheck);
			this->groupBox1->Controls->Add(this->MatrixCheck);
			this->groupBox1->Controls->Add(this->LUPCheck);
			this->groupBox1->Location = System::Drawing::Point(201, 32);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(178, 98);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Методы";
			// 
			// RotationCheck
			// 
			this->RotationCheck->AutoSize = true;
			this->RotationCheck->Checked = true;
			this->RotationCheck->CheckState = System::Windows::Forms::CheckState::Checked;
			this->RotationCheck->Location = System::Drawing::Point(11, 70);
			this->RotationCheck->Name = L"RotationCheck";
			this->RotationCheck->Size = System::Drawing::Size(112, 17);
			this->RotationCheck->TabIndex = 2;
			this->RotationCheck->Text = L"Метод вращения";
			this->RotationCheck->UseVisualStyleBackColor = true;
			// 
			// MatrixCheck
			// 
			this->MatrixCheck->AutoSize = true;
			this->MatrixCheck->Checked = true;
			this->MatrixCheck->CheckState = System::Windows::Forms::CheckState::Checked;
			this->MatrixCheck->Location = System::Drawing::Point(11, 47);
			this->MatrixCheck->Name = L"MatrixCheck";
			this->MatrixCheck->Size = System::Drawing::Size(117, 17);
			this->MatrixCheck->TabIndex = 1;
			this->MatrixCheck->Text = L"Матричный метод";
			this->MatrixCheck->UseVisualStyleBackColor = true;
			// 
			// LUPCheck
			// 
			this->LUPCheck->AutoSize = true;
			this->LUPCheck->Checked = true;
			this->LUPCheck->CheckState = System::Windows::Forms::CheckState::Checked;
			this->LUPCheck->Location = System::Drawing::Point(11, 24);
			this->LUPCheck->Name = L"LUPCheck";
			this->LUPCheck->Size = System::Drawing::Size(81, 17);
			this->LUPCheck->TabIndex = 0;
			this->LUPCheck->Text = L"LUP метод";
			this->LUPCheck->UseVisualStyleBackColor = true;
			this->LUPCheck->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(28, 96);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(119, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Решить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// SLAR
			// 
			this->SLAR->AccessibleName = L"";
			this->SLAR->AllowUserToAddRows = false;
			this->SLAR->AllowUserToDeleteRows = false;
			this->SLAR->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::DisplayedCells;
			this->SLAR->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->SLAR->ColumnHeadersVisible = false;
			this->SLAR->Location = System::Drawing::Point(28, 174);
			this->SLAR->Name = L"SLAR";
			this->SLAR->RowHeadersVisible = false;
			this->SLAR->Size = System::Drawing::Size(207, 150);
			this->SLAR->TabIndex = 5;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(67, 154);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(127, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Матрица коефициентов";
			// 
			// LUPSol
			// 
			this->LUPSol->AllowUserToAddRows = false;
			this->LUPSol->AllowUserToDeleteRows = false;
			this->LUPSol->AllowUserToResizeColumns = false;
			this->LUPSol->AllowUserToResizeRows = false;
			this->LUPSol->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::DisplayedCells;
			this->LUPSol->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->LUPSol->ColumnHeadersVisible = false;
			this->LUPSol->Location = System::Drawing::Point(282, 174);
			this->LUPSol->Name = L"LUPSol";
			this->LUPSol->RowHeadersVisible = false;
			this->LUPSol->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->LUPSol->Size = System::Drawing::Size(80, 150);
			this->LUPSol->TabIndex = 7;
			this->LUPSol->Visible = false;
			// 
			// MatrixSol
			// 
			this->MatrixSol->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::DisplayedCells;
			this->MatrixSol->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->MatrixSol->ColumnHeadersVisible = false;
			this->MatrixSol->Location = System::Drawing::Point(376, 174);
			this->MatrixSol->Name = L"MatrixSol";
			this->MatrixSol->RowHeadersVisible = false;
			this->MatrixSol->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->MatrixSol->Size = System::Drawing::Size(80, 150);
			this->MatrixSol->TabIndex = 8;
			this->MatrixSol->Visible = false;
			// 
			// RotationSol
			// 
			this->RotationSol->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::DisplayedCells;
			this->RotationSol->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->RotationSol->ColumnHeadersVisible = false;
			this->RotationSol->Location = System::Drawing::Point(477, 174);
			this->RotationSol->Name = L"RotationSol";
			this->RotationSol->RowHeadersVisible = false;
			this->RotationSol->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->RotationSol->Size = System::Drawing::Size(80, 150);
			this->RotationSol->TabIndex = 9;
			this->RotationSol->Visible = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(290, 154);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(62, 13);
			this->label3->TabIndex = 10;
			this->label3->Text = L"LUP метод";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(366, 154);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(98, 13);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Матричный метод";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(470, 154);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(93, 13);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Метод вращения";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(416, 63);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(0, 13);
			this->label6->TabIndex = 13;
			// 
			// graph
			// 
			chartArea1->CursorX->AutoScroll = false;
			chartArea1->CursorY->AutoScroll = false;
			chartArea1->Name = L"ChartArea1";
			this->graph->ChartAreas->Add(chartArea1);
			this->graph->Enabled = false;
			legend1->Name = L"Legend1";
			this->graph->Legends->Add(legend1);
			this->graph->Location = System::Drawing::Point(591, 32);
			this->graph->Name = L"graph";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->Legend = L"Legend1";
			series1->Name = L"Перше рівняня";
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series2->Legend = L"Legend1";
			series2->Name = L"Друге рівняня";
			this->graph->Series->Add(series1);
			this->graph->Series->Add(series2);
			this->graph->Size = System::Drawing::Size(527, 337);
			this->graph->TabIndex = 14;
			this->graph->Text = L"chart1";
			this->graph->Click += gcnew System::EventHandler(this, &MyForm::graph_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(28, 125);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(119, 23);
			this->button2->TabIndex = 15;
			this->button2->Text = L"Сгенерировать";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(413, 96);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(135, 23);
			this->button3->TabIndex = 16;
			this->button3->Text = L"Сохранить результат";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(27, 336);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(208, 13);
			this->label7->TabIndex = 17;
			this->label7->Text = L"Количество арифметических операций:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(289, 336);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(0, 13);
			this->label8->TabIndex = 18;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(380, 336);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(0, 13);
			this->label9->TabIndex = 19;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(481, 336);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(0, 13);
			this->label10->TabIndex = 20;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(481, 356);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(0, 13);
			this->label11->TabIndex = 24;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(380, 356);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(0, 13);
			this->label12->TabIndex = 23;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(289, 356);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(0, 13);
			this->label13->TabIndex = 22;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(127, 356);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(108, 13);
			this->label14->TabIndex = 21;
			this->label14->Text = L"Время выполнения:";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(481, 375);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(0, 13);
			this->label15->TabIndex = 28;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(380, 375);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(0, 13);
			this->label16->TabIndex = 27;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(289, 375);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(0, 13);
			this->label17->TabIndex = 26;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(116, 375);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(119, 13);
			this->label18->TabIndex = 25;
			this->label18->Text = L"Количество итераций:";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(590, 396);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->graph);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->RotationSol);
			this->Controls->Add(this->MatrixSol);
			this->Controls->Add(this->LUPSol);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->SLAR);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Number);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"Программа для решения систем линейных алгебраических уравнений";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Number))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SLAR))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LUPSol))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MatrixSol))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->RotationSol))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->graph))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		srand(time(NULL));
		SLAR->ColumnCount = 2; // начальное число столбцов и строк
		SLAR->RowCount = 1;
		SLAR->AutoResizeColumns();// выравнивание ячеек	
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		int n = (int)Number->Value;
		bool badinput = false;
		SLARmatrix = matrix(n, n);
		fr = matrix(n, 1);
		matrix solcopy = matrix(1, 1);
		try // Пытаемся считать таблицу
		{
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					SLARmatrix[i][j] = Convert::ToDouble(SLAR->Rows[i]->Cells[j]->Value);

			for (int i = 0; i < n; i++)
				fr[i][0] = Convert::ToDouble(SLAR->Rows[i]->Cells[n]->Value);
		}
		catch (FormatException^ e)
		{
			badinput = true; //Сюда попадаем если в таблицу введено не число
		}
		if ((SLARmatrix.det() == 0) || (badinput) || (!((LUPCheck->Checked) || (MatrixCheck->Checked) || (RotationCheck->Checked))))//Проверка ошибок
		{
			if (badinput)
				label6->Text = L"Ошибка ввода";
			else
				if (!((LUPCheck->Checked) || (MatrixCheck->Checked) || (RotationCheck->Checked)))
					label6->Text = L"Не выбран ни один метод";
				else
					label6->Text = L"Система не совместима";
			// Дальше очистка старых данных
			LUPSol->Visible = 0;
			MatrixSol->Visible = 0;
			RotationSol->Visible = 0;
			Width = 606;
			graph->Enabled = false;
			label8->Text = "";
			label9->Text = "";
			label10->Text = "";
			label11->Text = "";
			label12->Text = "";
			label13->Text = "";			
			label15->Text = "";
			label16->Text = "";
			label17->Text = "";
		}
		else
		{
			label6->Text = L"";//Очищаем сообщение об ошибке
			if (LUPCheck->Checked)
			{
				iterations = operations = 0;//Обнуляем счетчики
				time_t start = clock();//Начинаем считать время выполнения
				matrix LUPS = LUP(SLARmatrix, fr, n);//Вызов решения
				t1 = (clock() - start) / 1000.0;//Сохраняем время выполнения
				op1 = operations;//Сохраняем количество операций
				it1 = iterations;//Сохраняем количество итераций
				label8->Text = Convert::ToString(op1);//Вывод количества операций
				label13->Text = Convert::ToString(t1);//Вывод времени работы
				label17->Text = Convert::ToString(it1);//Вывод количества итераций
				solcopy = LUPS;//Сохраняем копию ответа (нужна для графика)
							   //Далее вывод ответа
				LUPSol->Visible = true;
				LUPSol->RowCount = n;
				LUPSol->ColumnCount = 1;
				for (int i = 0; i < n; i++)
					LUPSol->Rows[i]->Cells[0]->Value = LUPS[i][0];
				LUPSol->AutoResizeColumns();//Автоматически изменить ширину колонок
			}
			else
			{
				//Если метод не выбран убираем таблицу с ответом и очищаем количество операций\время работы
				LUPSol->Visible = false;
				label8->Text = "";
				label13->Text = "";
				label17->Text = "";
			}
			//Остальные методы работают аналогично
			if (MatrixCheck->Checked)
			{
				iterations = operations = 0;
				time_t start = clock();
				matrix MatrixS = MatrixMethod(SLARmatrix, fr);
				t2 = (clock() - start) / 1000.0;
				op2 = operations;
				it2 = iterations;
				label9->Text = Convert::ToString(op2);
				label12->Text = Convert::ToString(t2);
				label16->Text = Convert::ToString(it2);
				solcopy = MatrixS;
				MatrixSol->Visible = true;
				MatrixSol->RowCount = n;
				MatrixSol->ColumnCount = 1;
				for (int i = 0; i < n; i++)
					MatrixSol->Rows[i]->Cells[0]->Value = MatrixS[i][0];
				MatrixSol->AutoResizeColumns();
			}
			else
			{
				MatrixSol->Visible = false;
				label9->Text = "";
				label12->Text = "";
				label16->Text = "";
			}
			if (RotationCheck->Checked)
			{
				iterations = operations = 0;
				time_t start = clock();
				matrix RotationS = RotationMethod(SLARmatrix, fr, n);
				t3 = (clock() - start) / 1000.0;
				op3 = operations;
				it3 = iterations;
				label10->Text = Convert::ToString(op3);
				label11->Text = Convert::ToString(t3);
				label15->Text = Convert::ToString(it3);
				solcopy = RotationS;
				RotationSol->Visible = true;
				RotationSol->RowCount = n;
				RotationSol->ColumnCount = 1;
				for (int i = 0; i < n; i++)
					RotationSol->Rows[i]->Cells[0]->Value = RotationS[i][0];
				RotationSol->AutoResizeColumns();
			}
			else
			{
				RotationSol->Visible = false;
				label10->Text = "";
				label11->Text = "";
				label15->Text = "";
			}
			if (n == 2)
			{
				//Рисуем график
				Width = 1153;//Изменяем ширину чтобы поместить график
				graph->Enabled = true;//Включаем график
				double xans = solcopy[0][0], yans = solcopy[1][0];//Координаты точек пересечения
				graph->ChartAreas[0]->AxisY->ScaleView->Zoom(yans - WCONST, yans + WCONST);//Изменяем масштаб для наглядности
				graph->ChartAreas[0]->AxisX->ScaleView->Zoom(xans - WCONST, xans + WCONST);
				graph->Series[0]->Points->Clear();//Очищаем старые графики
				graph->Series[1]->Points->Clear();
				if (SLARmatrix[0][1] != 0)
				{
					//Обычный отрезок по двум точкам
					graph->Series[0]->Points->AddXY(xans - WCONST, (fr[0][0] - SLARmatrix[0][0] * (xans + WCONST)) / SLARmatrix[0][1]);
					graph->Series[0]->Points->AddXY(xans + WCONST, (fr[0][0] - SLARmatrix[0][0] * (xans - WCONST)) / SLARmatrix[0][1]);
				}
				else
				{
					//Особый случай для вертикальной прямой
					graph->Series[0]->Points->AddXY(xans, yans - WCONST);
					graph->Series[0]->Points->AddXY(xans, yans + WCONST);
				}
				if (SLARmatrix[1][1] != 0)
				{
					//Обычный отрезок по двум точкам
					graph->Series[1]->Points->AddXY(xans - WCONST, (fr[1][0] - SLARmatrix[1][0] * (xans + WCONST)) / SLARmatrix[1][1]);
					graph->Series[1]->Points->AddXY(xans + WCONST, (fr[1][0] - SLARmatrix[1][0] * (xans - WCONST)) / SLARmatrix[1][1]);
				}
				else
				{
					//Особый случай для вертикальной прямой
					graph->Series[1]->Points->AddXY(xans, yans - WCONST);
					graph->Series[1]->Points->AddXY(xans, yans + WCONST);
				}

			}
			else
			{
				//Если график не нужен
				Width = 606;//Возвращаем исходную ширину окна
				graph->Enabled = false;//Выключаем график
			}
		}
	}
	private: System::Void numericUpDown1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		//При изменении количества уравнений обновляем таблицу с входными данными
		SLAR->RowCount = 0;//Эта строка очищает старые значения
		SLAR->ColumnCount = (int)Number->Value + 1;//Устанавливает новый размер таблицы
		SLAR->RowCount = (int)Number->Value;
		SLAR->AutoResizeColumns();//Автоматическое изменение ширины ячеек
	}
	private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	}
	private: System::Void graph_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		int n = (int)Number->Value;
		for (int i = 0; i < n; i++)
			for (int j = 0; j <= n; j++)
				SLAR->Rows[i]->Cells[j]->Value = (rand() % ((maxrand - minrand) * 10)) / 10.0 + minrand;//Забиваем таблицу случайными значениями
	}
	private: System::Void MyForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		//Сохранение результатов
		if (!((LUPSol->Visible) || (MatrixSol->Visible) || (RotationSol->Visible)))
		{
			//Нечего сохранять выводим ошибку
			label6->Text = "Нет решения для сохранения";
			return;
		}
		std::ofstream fout;
		fout.open("output.txt", std::ofstream::out);//Открываем файл для вывода
													//Вывод условия
		fout << "Условие:\n";
		for (int i = 0; i < SLARmatrix.h; i++)
		{
			for (int j = 0; j < SLARmatrix.w; j++)
			{
				if ((SLARmatrix[i][j] >= 0) && (j != 0)) fout << "+";
				fout << SLARmatrix[i][j] << "*x" << j;
			}
			fout << "=" << fr[i][0] << "\n";
		}
		//Дальше вывод результатов
		if (LUPSol->Visible)//Если таблица с решениями LUP метода то у нас есть решение для сохранения
		{
			fout << "LUP метод: операцій=" << op1 << " час=" << t1 << " кількість ітераій=" << it1 << "\n";//Вывод количества операций, итераций и время выполнения
			for (int i = 0; i < LUPSol->Rows->Count; i++)
				fout << "x" << i << "=" << Convert::ToDouble(LUPSol->Rows[i]->Cells[0]->Value) << " ";//Вывод ответов в формате xi=число
			fout << "\n";
		}
		//Данные других методов выводяться аналогично
		if (MatrixSol->Visible)
		{
			fout << "Матричний метод: операцій=" << op2 << " час=" << t2 << " кількість ітераій=" << it2 << "\n";;
			for (int i = 0; i < MatrixSol->Rows->Count; i++)
				fout << "x" << i << "=" << Convert::ToDouble(MatrixSol->Rows[i]->Cells[0]->Value) << " ";
			fout << "\n";
		}
		if (RotationSol->Visible)
		{
			fout << "Метод поворота: операцій=" << op3 << " час=" << t3 << " кількість ітераій=" << it3 << "\n";;
			for (int i = 0; i < RotationSol->Rows->Count; i++)
				fout << "x" << i << "=" << Convert::ToDouble(RotationSol->Rows[i]->Cells[0]->Value) << " ";
			fout << "\n";
		}
		MessageBox::Show("Результат сохранен в файл output.txt", "Данные сохранены");//Вывод всплывающего окна с сообщением об успешном сохранении
		fout.close();//Закрываем файл
	}
	};
}
