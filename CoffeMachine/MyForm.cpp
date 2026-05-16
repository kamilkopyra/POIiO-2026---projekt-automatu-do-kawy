#include "MainWindow.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

int main(array<String^>^ args) {
    String^ connectionString = "Data Source=coffemachine.db;Version=3;";

    try
    {
        SQLiteConnection connection(connectionString);
        connection.Open();

        Console::WriteLine("Polaczono z baza");

        String^ sql = "SELECT * FROM drinks";
        SQLiteCommand^ command = gcnew SQLiteCommand(sql, % connection);
        SQLiteDataReader^ reader = command->ExecuteReader();

        while (reader->Read())
        {
            // Pobieramy wartość i rzutujemy na String^
            Console::WriteLine(reader["name"]->ToString());
        }

        reader->Close();
    }
    catch (Exception^ ex)
    {
        Console::WriteLine("Wystapil blad: " + ex->Message);
    }
    std::cin.get();
    return 0;
}