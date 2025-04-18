#pragma once
#include <fstream>
#include <vector>
#include <string>

namespace AuthSystem {

    using namespace System;
    using namespace System::IO;
    using namespace System::Collections::Generic;

    public ref class UserDatabase
    {
    public:
        UserDatabase(String^ filename)
        {
            this->filename = filename;
            LoadDatabase();
        }

        bool UserExists(String^ username)
        {
            for each (UserData ^ user in users)
            {
                if (user->Username == username)
                {
                    return true;
                }
            }
            return false;
        }

        bool ValidateUser(String^ username, String^ password)
        {
            for each (UserData ^ user in users)
            {
                if (user->Username == username && user->Password == password)
                {
                    return true;
                }
            }
            return false;
        }

        String^ GetUserRole(String^ username)
        {
            for each (UserData ^ user in users)
            {
                if (user->Username == username)
                {
                    return user->Role;
                }
            }
            return "user";
        }

        void AddUser(String^ username, String^ password, String^ role)
        {
            UserData^ newUser = gcnew UserData();
            newUser->Username = username;
            newUser->Password = password;
            newUser->Role = role;

            users->Add(newUser);
            SaveDatabase();
        }

        bool ChangeUserRole(String^ username, String^ newRole)
        {
            for each (UserData ^ user in users)
            {
                if (user->Username == username)
                {
                    user->Role = newRole;
                    SaveDatabase();
                    return true;
                }
            }
            return false;
        }

        List<String^>^ GetAllUsers()
        {
            List<String^>^ userList = gcnew List<String^>();
            for each (UserData ^ user in users)
            {
                userList->Add(String::Format("{0} ({1})", user->Username, user->Role));
            }
            return userList;
        }

    private:
        ref class UserData
        {
        public:
            property String^ Username;
            property String^ Password;
            property String^ Role;
        };

        String^ filename;
        List<UserData^>^ users;

        void LoadDatabase()
        {
            users = gcnew List<UserData^>();

            try
            {
                if (File::Exists(filename))
                {
                    StreamReader^ reader = gcnew StreamReader(filename);

                    while (!reader->EndOfStream)
                    {
                        String^ line = reader->ReadLine();
                        array<String^>^ parts = line->Split('|');

                        if (parts->Length == 3)
                        {
                            UserData^ user = gcnew UserData();
                            user->Username = parts[0];
                            user->Password = parts[1];
                            user->Role = parts[2];
                            users->Add(user);
                        }
                    }

                    reader->Close();
                }
            }
            catch (Exception^ e)
            {
                users->Clear();
            }
        }

        void SaveDatabase()
        {
            try
            {
                StreamWriter^ writer = gcnew StreamWriter(filename, false);

                for each (UserData ^ user in users)
                {
                    writer->WriteLine("{0}|{1}|{2}", user->Username, user->Password, user->Role);
                }

                writer->Close();
            }
            catch (Exception^ e)
            {
                // Ошибка при сохранении
            }
        }
    };
}