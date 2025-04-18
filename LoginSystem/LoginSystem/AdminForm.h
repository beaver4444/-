#pragma once
#include "UserDatabase.h"

namespace AuthSystem {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class AdminForm : public System::Windows::Forms::Form
    {
    public:
        AdminForm(String^ username, UserDatabase^ db)
        {
            InitializeComponent();
            this->Text = String::Format("Администратор: {0}", username);
            this->db = db;
            RefreshUserList();
        }

    protected:
        ~AdminForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        UserDatabase^ db;
        System::Windows::Forms::ListBox^ userListBox;
        System::Windows::Forms::Button^ btnMakeAdmin;
        System::Windows::Forms::Button^ btnRemoveAdmin;
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->userListBox = (gcnew System::Windows::Forms::ListBox());
            this->btnMakeAdmin = (gcnew System::Windows::Forms::Button());
            this->btnRemoveAdmin = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // userListBox
            // 
            this->userListBox->FormattingEnabled = true;
            this->userListBox->Location = System::Drawing::Point(20, 20);
            this->userListBox->Name = L"userListBox";
            this->userListBox->Size = System::Drawing::Size(300, 160);
            this->userListBox->TabIndex = 0;
            // 
            // btnMakeAdmin
            // 
            this->btnMakeAdmin->Location = System::Drawing::Point(20, 190);
            this->btnMakeAdmin->Name = L"btnMakeAdmin";
            this->btnMakeAdmin->Size = System::Drawing::Size(140, 30);
            this->btnMakeAdmin->TabIndex = 1;
            this->btnMakeAdmin->Text = L"Сделать админом";
            this->btnMakeAdmin->UseVisualStyleBackColor = true;
            this->btnMakeAdmin->Click += gcnew System::EventHandler(this, &AdminForm::btnMakeAdmin_Click);
            // 
            // btnRemoveAdmin
            // 
            this->btnRemoveAdmin->Location = System::Drawing::Point(180, 190);
            this->btnRemoveAdmin->Name = L"btnRemoveAdmin";
            this->btnRemoveAdmin->Size = System::Drawing::Size(140, 30);
            this->btnRemoveAdmin->TabIndex = 2;
            this->btnRemoveAdmin->Text = L"Убрать админа";
            this->btnRemoveAdmin->UseVisualStyleBackColor = true;
            this->btnRemoveAdmin->Click += gcnew System::EventHandler(this, &AdminForm::btnRemoveAdmin_Click);
            // 
            // AdminForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(340, 240);
            this->Controls->Add(this->btnRemoveAdmin);
            this->Controls->Add(this->btnMakeAdmin);
            this->Controls->Add(this->userListBox);
            this->Name = L"AdminForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Панель администратора";
            this->ResumeLayout(false);
        }
#pragma endregion

    private:
        void RefreshUserList()
        {
            userListBox->Items->Clear();
            userListBox->Items->AddRange(db->GetAllUsers()->ToArray());
        }

        System::Void btnMakeAdmin_Click(System::Object^ sender, System::EventArgs^ e) {
            if (userListBox->SelectedItem != nullptr)
            {
                String^ selectedUser = userListBox->SelectedItem->ToString();
                String^ username = selectedUser->Substring(0, selectedUser->IndexOf(" "));

                if (db->ChangeUserRole(username, "admin"))
                {
                    MessageBox::Show("Пользователь " + username + " теперь администратор",
                        "Успех", MessageBoxButtons::OK, MessageBoxIcon::Information);
                    RefreshUserList();
                }
                else
                {
                    MessageBox::Show("Не удалось изменить роль пользователя",
                        "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
                }
            }
            else
            {
                MessageBox::Show("Выберите пользователя из списка",
                    "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
            }
        }

        System::Void btnRemoveAdmin_Click(System::Object^ sender, System::EventArgs^ e) {
            if (userListBox->SelectedItem != nullptr)
            {
                String^ selectedUser = userListBox->SelectedItem->ToString();
                String^ username = selectedUser->Substring(0, selectedUser->IndexOf(" "));

                if (username == "admin")
                {
                    MessageBox::Show("Нельзя изменить роль главного администратора",
                        "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
                    return;
                }

                if (db->ChangeUserRole(username, "user"))
                {
                    MessageBox::Show("Пользователь " + username + " теперь обычный пользователь",
                        "Успех", MessageBoxButtons::OK, MessageBoxIcon::Information);
                    RefreshUserList();
                }
                else
                {
                    MessageBox::Show("Не удалось изменить роль пользователя",
                        "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
                }
            }
            else
            {
                MessageBox::Show("Выберите пользователя из списка",
                    "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
            }
        }
    };
}