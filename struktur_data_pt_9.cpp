#include <iostream>
#include <string>

using namespace std;

struct Mahasiswa
{
    int id;
    string nama;
    string nim;
    string gender;
    float nilai;
    Mahasiswa *next;
};

Mahasiswa *head = nullptr;
int idCounter = 1;

void push(string nama, string nim, string gender, float nilai)
{
    Mahasiswa *newNode = new Mahasiswa();
    newNode->id = idCounter++;
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->gender = gender;
    newNode->nilai = nilai;
    newNode->next = head;
    head = newNode;
    cout << "Data berhasil dimasukkan ke stack dengan ID: " << newNode->id << ".\n\n";
}

void displayStackWithID()
{
    if (head == nullptr)
    {
        cout << "Stack kosong, tidak ada data yang bisa ditampilkan.\n\n";
        return;
    }

    Mahasiswa *current = head;
    cout << "Data mahasiswa dalam stack:\n";
    while (current != nullptr)
    {
        cout << "ID: " << current->id << " | Nama: " << current->nama << " | NIM: " << current->nim
             << " | Gender: " << current->gender << " | Nilai Struktur Data: " << current->nilai << endl;
        current = current->next;
    }
    cout << "\n";
}

void deleteByID(int id)
{
    if (head == nullptr)
    {
        cout << "Stack kosong, tidak ada data yang bisa dihapus.\n\n";
        return;
    }

    Mahasiswa *temp = head;
    Mahasiswa *prev = nullptr;

    if (temp != nullptr && temp->id == id)
    {
        head = temp->next;
        cout << "Data mahasiswa dengan ID: " << id << " dan NIM: " << temp->nim << " dihapus.\n\n";
        delete temp;
        return;
    }

    while (temp != nullptr && temp->id != id)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "Data dengan ID " << id << " tidak ditemukan.\n\n";
        return;
    }

    prev->next = temp->next;
    cout << "Data mahasiswa dengan ID: " << id << " dan NIM: " << temp->nim << " dihapus.\n\n";
    delete temp;
}

void printStack()
{
    if (head == nullptr)
    {
        cout << "Stack kosong, tidak ada data yang bisa dicetak.\n\n";
        return;
    }

    Mahasiswa *current = head;
    cout << "Data mahasiswa dalam stack:\n";
    while (current != nullptr)
    {
        cout << "Nama: " << current->nama << " | NIM: " << current->nim
             << " | Gender: " << current->gender << " | Nilai Struktur Data: " << current->nilai << endl;
        current = current->next;
    }
    cout << "\n";
}

int main()
{
    int pilihan;
    string nama, nim, gender;
    float nilai;
    int idHapus;

    do
    {
        cout << "---------------------------\n";
        cout << "Linked List Data Mahasiswa:\n";
        cout << "1. Insert Data\n";
        cout << "2. Hapus Data\n";
        cout << "3. Cetak Data\n";
        cout << "4. Exit\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan)
        {
        case 1:
            cout << "---------------------------\n";
            cout << "Masukkan Nama: ";
            getline(cin, nama);
            cout << "Masukkan NIM: ";
            getline(cin, nim);
            cout << "Masukkan Gender (L/P): ";
            getline(cin, gender);
            cout << "Masukkan Nilai Struktur Data: ";
            cin >> nilai;
            push(nama, nim, gender, nilai);
            break;

        case 2:
            if (head == nullptr)
            {
                cout << "Stack kosong, tidak ada data yang bisa dihapus.\n\n";
            }
            else
            {
                displayStackWithID();
                cout << "---------------------------\n";
                cout << "Masukkan ID mahasiswa yang ingin dihapus: ";
                cin >> idHapus;
                deleteByID(idHapus);
            }
            break;

        case 3:
            printStack();
            break;

        case 4:
            cout << "Terima kasih!\n";
            break;

        default:
            cout << "Pilihan tidak valid, coba lagi.\n\n";
            break;
        }
    } while (pilihan != 4);

    return 0;
}
