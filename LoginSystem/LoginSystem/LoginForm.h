#pragma once

namespace AuthSystem {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class LoginForm : public System::Windows::Forms::Form
    {
    public:
        LoginForm(void)
        {
            InitializeComponent();
        }

        property String^ Username {
            String^ get() { return txtUsername->Text; }
        }

        property String^ Password {
            String^ get() { return txtPassword->Text; }
        }

    protected:
        ~LoginForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::TextBox^ txtUsername;
        System::Windows::Forms::TextBox^ txtPassword;
        System::Windows::Forms::Button^ btnOK;
        System::Windows::Forms::Button^ btnCancel;
        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::Label^ label2;
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->txtUsername = (gcnew System::Windows::Forms::TextBox());
            this->txtPassword = (gcnew System::Windows::Forms::TextBox());
            this->btnOK = (gcnew System::Windows::Forms::Button());
            this->btnCancel = (gcnew System::Windows::Forms::Button());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // txtUsername
            // 
            this->txtUsername->Location = System::Drawing::Point(120, 30);
            this->txtUsername->Name = L"txtUsername";
            this->txtUsername->Size = System::Drawing::Size(200, 20);
            this->txtUsername->TabIndex = 0;
            // 
            // txtPassword
            // 
            this->txtPassword->Location = System::Drawing::Point(120, 70);
            this->txtPassword->Name = L"txtPassword";
            this->txtPassword->PasswordChar = '*';
            this->txtPassword->Size = System::Drawing::Size(200, 20);
            this->txtPassword->TabIndex = 1;
            // 
            // btnOK
            // 
            this->btnOK->DialogResult = System::Windows::Forms::DialogResult::OK;
            this->btnOK->Location = System::Drawing::Point(120, 110);
            this->btnOK->Name = L"btnOK";
            this->btnOK->Size = System::Drawing::Size(90, 30);
            this->btnOK->TabIndex = 2;
            this->btnOK->Text = L"Войти";
            this->btnOK->UseVisualStyleBackColor = true;
            // 
            // btnCancel
            // 
            this->btnCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
            this->btnCancel->Location = System::Drawing::Point(230, 110);
            this->btnCancel->Name = L"btnCancel";
            this->btnCancel->Size = System::Drawing::Size(90, 30);
            this->btnCancel->TabIndex = 3;
            this->btnCancel->Text = L"Отмена";
            this->btnCancel->UseVisualStyleBackColor = true;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(30, 33);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(41, 13);
            this->label1->TabIndex = 4;
            this->label1->Text = L"Логин:";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(30, 73);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(48, 13);
            this->label2->TabIndex = 5;
            this->label2->Text = L"Пароль:";
            // 
            // LoginForm
            // 
            this->AcceptButton = this->btnOK;
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->CancelButton = this->btnCancel;
            this->ClientSize = System::Drawing::Size(350, 170);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->btnCancel);
            this->Controls->Add(this->btnOK);
            this->Controls->Add(this->txtPassword);
            this->Controls->Add(this->txtUsername);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
            this->MaximizeBox = false;
            this->MinimizeBox = false;
            this->Name = L"LoginForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
            this->Text = L"Вход в систему";
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion
    };
}