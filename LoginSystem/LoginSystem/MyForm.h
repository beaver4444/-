#pragma once
#include "LoginForm.h"
#include "RegisterForm.h"
#include "AdminForm.h"
#include "UserForm.h"
#include "UserDatabase.h"

namespace AuthSystem {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();
            db = gcnew UserDatabase("users.txt");

            // Создаем тестового администратора, если его нет
            if (!db->UserExists("admin")) {
                db->AddUser("admin", "admin123", "admin");
            }
        }

    protected:
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::Button^ btnLogin;
        System::Windows::Forms::Button^ btnRegister;
        System::Windows::Forms::Button^ btnExit;
        System::ComponentModel::Container^ components;
        UserDatabase^ db;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->btnLogin = (gcnew System::Windows::Forms::Button());
            this->btnRegister = (gcnew System::Windows::Forms::Button());
            this->btnExit = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // btnLogin
            // 
            this->btnLogin->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->btnLogin->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->btnLogin->Location = System::Drawing::Point(100, 62);
            this->btnLogin->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->btnLogin->Name = L"btnLogin";
            this->btnLogin->Size = System::Drawing::Size(267, 49);
            this->btnLogin->TabIndex = 0;
            this->btnLogin->Text = L"Войти в систему";
            this->btnLogin->UseVisualStyleBackColor = false;
            this->btnLogin->Click += gcnew System::EventHandler(this, &MyForm::btnLogin_Click);
            // 
            // btnRegister
            // 
            this->btnRegister->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                static_cast<System::Int32>(static_cast<System::Byte>(224)));
            this->btnRegister->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->btnRegister->Location = System::Drawing::Point(100, 135);
            this->btnRegister->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->btnRegister->Name = L"btnRegister";
            this->btnRegister->Size = System::Drawing::Size(267, 49);
            this->btnRegister->TabIndex = 1;
            this->btnRegister->Text = L"Зарегистрироваться";
            this->btnRegister->UseVisualStyleBackColor = false;
            this->btnRegister->Click += gcnew System::EventHandler(this, &MyForm::btnRegister_Click);
            // 
            // btnExit
            // 
            this->btnExit->BackColor = System::Drawing::SystemColors::Control;
            this->btnExit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->btnExit->Location = System::Drawing::Point(100, 209);
            this->btnExit->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->btnExit->Name = L"btnExit";
            this->btnExit->Size = System::Drawing::Size(267, 49);
            this->btnExit->TabIndex = 2;
            this->btnExit->Text = L"Выход";
            this->btnExit->UseVisualStyleBackColor = false;
            this->btnExit->Click += gcnew System::EventHandler(this, &MyForm::btnExit_Click);
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
                static_cast<System::Int32>(static_cast<System::Byte>(240)));
            this->ClientSize = System::Drawing::Size(525, 316);
            this->Controls->Add(this->btnExit);
            this->Controls->Add(this->btnRegister);
            this->Controls->Add(this->btnLogin);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->MaximizeBox = false;
            this->MinimizeBox = false;
            this->Name = L"MyForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Система авторизации";
            this->ResumeLayout(false);

        }
#pragma endregion

    private:
        System::Void btnLogin_Click(System::Object^ sender, System::EventArgs^ e) {
            LoginForm^ loginForm = gcnew LoginForm();

            if (loginForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
                String^ username = loginForm->Username;
                String^ password = loginForm->Password;

                if (db->ValidateUser(username, password)) {
                    String^ role = db->GetUserRole(username);

                    if (role == "admin") {
                        AdminForm^ adminForm = gcnew AdminForm(username, db);
                        adminForm->Show();
                        this->Hide();
                    }
                    else {
                        UserForm^ userForm = gcnew UserForm(username);
                        userForm->Show();
                        this->Hide();
                    }
                }
                else {
                    MessageBox::Show("Неверный логин или пароль", "Ошибка авторизации",
                        MessageBoxButtons::OK, MessageBoxIcon::Error);
                }
            }
        }

        System::Void btnRegister_Click(System::Object^ sender, System::EventArgs^ e) {
            RegisterForm^ registerForm = gcnew RegisterForm();

            if (registerForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
                String^ username = registerForm->Username;
                String^ password = registerForm->Password;
                String^ confirmPassword = registerForm->ConfirmPassword;

                if (password != confirmPassword) {
                    MessageBox::Show("Пароли не совпадают", "Ошибка регистрации",
                        MessageBoxButtons::OK, MessageBoxIcon::Error);
                    return;
                }

                if (username->Length < 3 || password->Length < 3) {
                    MessageBox::Show("Логин и пароль должны быть не менее 3 символов", "Ошибка регистрации",
                        MessageBoxButtons::OK, MessageBoxIcon::Error);
                    return;
                }

                if (db->UserExists(username)) {
                    MessageBox::Show("Этот логин уже занят", "Ошибка регистрации",
                        MessageBoxButtons::OK, MessageBoxIcon::Error);
                }
                else {
                    db->AddUser(username, password, "user");
                    MessageBox::Show("Регистрация прошла успешно!", "Успешно",
                        MessageBoxButtons::OK, MessageBoxIcon::Information);
                }
            }
        }

        System::Void btnExit_Click(System::Object^ sender, System::EventArgs^ e) {
            Application::Exit();
        }
    };
}