#pragma once

namespace AuthSystem {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class UserForm : public System::Windows::Forms::Form
    {
    public:
        UserForm(String^ username)
        {
            InitializeComponent();
            this->Text = String::Format("Пользователь: {0}", username);
        }

    protected:
        ~UserForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:

    private: System::Windows::Forms::TabControl^ tabControl1;
    private: System::Windows::Forms::TabPage^ tabPage1;
    private: System::Windows::Forms::TabPage^ tabPage2;
           System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
            this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
            this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
            this->tabControl1->SuspendLayout();
            this->SuspendLayout();
            // 
            // tabControl1
            // 
            this->tabControl1->Controls->Add(this->tabPage1);
            this->tabControl1->Controls->Add(this->tabPage2);
            this->tabControl1->Location = System::Drawing::Point(0, 0);
            this->tabControl1->Name = L"tabControl1";
            this->tabControl1->SelectedIndex = 0;
            this->tabControl1->Size = System::Drawing::Size(657, 420);
            this->tabControl1->TabIndex = 1;
            // 
            // tabPage1
            // 
            this->tabPage1->Location = System::Drawing::Point(4, 25);
            this->tabPage1->Name = L"tabPage1";
            this->tabPage1->Padding = System::Windows::Forms::Padding(3);
            this->tabPage1->Size = System::Drawing::Size(649, 391);
            this->tabPage1->TabIndex = 0;
            this->tabPage1->Text = L"игры";
            this->tabPage1->UseVisualStyleBackColor = true;
            // 
            // tabPage2
            // 
            this->tabPage2->Location = System::Drawing::Point(4, 25);
            this->tabPage2->Name = L"tabPage2";
            this->tabPage2->Padding = System::Windows::Forms::Padding(3);
            this->tabPage2->Size = System::Drawing::Size(649, 391);
            this->tabPage2->TabIndex = 1;
            this->tabPage2->Text = L"избранное";
            this->tabPage2->UseVisualStyleBackColor = true;
            // 
            // UserForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(657, 423);
            this->Controls->Add(this->tabControl1);
            this->Margin = System::Windows::Forms::Padding(4);
            this->Name = L"UserForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"UserForm";
            this->tabControl1->ResumeLayout(false);
            this->ResumeLayout(false);

        }
#pragma endregion
    };
}