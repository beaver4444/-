#pragma once

namespace AuthSystem {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class RegisterForm : public System::Windows::Forms::Form
    {
    public:
        RegisterForm(void)
        {
            InitializeComponent();
        }

        property String^ Username {
            String^ get() { return txtUsername->Text; }
        }

        property String^ Password {
            String^ get() { return txtPassword->Text; }
        }

        property String^ ConfirmPassword {
            String^ get() { return txtConfirmPassword->Text; }
        }

    protected:
        ~RegisterForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::TextBox^ txtUsername;
        System::Windows::Forms::TextBox^ txtPassword;
        System::Windows::Forms::TextBox^ txtConfirmPassword;
        System::Windows::Forms::Button^ btnOK;
        System::Windows::Forms::Button^ btnCancel;
        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::Label^ label2;
        System::Windows::Forms::Label^ label3;
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->txtUsername = (gcnew System::Windows::Forms::TextBox());
            this->txtPassword = (gcnew System::Windows::Forms::TextBox());
            this->txtConfirmPassword = (gcnew System::Windows::Forms::TextBox());
            this->btnOK = (gcnew System::Windows::Forms::Button());
            this->btnCancel = (gcnew System::Windows::Forms::Button());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // txtUsername
            // 
            this->txtUsername->Location = System::Drawing::Point(160, 37);
            this->txtUsername->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->txtUsername->Name = L"txtUsername";
            this->txtUsername->Size = System::Drawing::Size(265, 22);
            this->txtUsername->TabIndex = 0;
            // 
            // txtPassword
            // 
            this->txtPassword->Location = System::Drawing::Point(160, 86);
            this->txtPassword->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->txtPassword->Name = L"txtPassword";
            this->txtPassword->PasswordChar = '*';
            this->txtPassword->Size = System::Drawing::Size(265, 22);
            this->txtPassword->TabIndex = 1;
            // 
            // txtConfirmPassword
            // 
            this->txtConfirmPassword->Location = System::Drawing::Point(160, 135);
            this->txtConfirmPassword->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->txtConfirmPassword->Name = L"txtConfirmPassword";
            this->txtConfirmPassword->PasswordChar = '*';
            this->txtConfirmPassword->Size = System::Drawing::Size(265, 22);
            this->txtConfirmPassword->TabIndex = 2;
            // 
            // btnOK
            // 
            this->btnOK->DialogResult = System::Windows::Forms::DialogResult::OK;
            this->btnOK->Location = System::Drawing::Point(43, 185);
            this->btnOK->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->btnOK->Name = L"btnOK";
            this->btnOK->Size = System::Drawing::Size(153, 37);
            this->btnOK->TabIndex = 3;
            this->btnOK->Text = L"Зарегистрироваться";
            this->btnOK->UseVisualStyleBackColor = true;
            // 
            // btnCancel
            // 
            this->btnCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
            this->btnCancel->Location = System::Drawing::Point(286, 185);
            this->btnCancel->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->btnCancel->Name = L"btnCancel";
            this->btnCancel->Size = System::Drawing::Size(139, 37);
            this->btnCancel->TabIndex = 4;
            this->btnCancel->Text = L"Отмена";
            this->btnCancel->UseVisualStyleBackColor = true;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(40, 41);
            this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(49, 16);
            this->label1->TabIndex = 5;
            this->label1->Text = L"Логин:";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(40, 90);
            this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(59, 16);
            this->label2->TabIndex = 6;
            this->label2->Text = L"Пароль:";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(40, 139);
            this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(116, 16);
            this->label3->TabIndex = 7;
            this->label3->Text = L"Подтверждение:";
            // 
            // RegisterForm
            // 
            this->AcceptButton = this->btnOK;
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->CancelButton = this->btnCancel;
            this->ClientSize = System::Drawing::Size(467, 246);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->btnCancel);
            this->Controls->Add(this->btnOK);
            this->Controls->Add(this->txtConfirmPassword);
            this->Controls->Add(this->txtPassword);
            this->Controls->Add(this->txtUsername);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
            this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->MaximizeBox = false;
            this->MinimizeBox = false;
            this->Name = L"RegisterForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
            this->Text = L"Регистрация";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    };
}