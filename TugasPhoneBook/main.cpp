#include <iostream>
#include <conio.h>

using namespace std;

void isiPhonebook(string nama[], string noTelp[]){
    cout << "Mengisi Phonebook:" << endl;
    int posisisIterasi = 0;
    for (int i = 0; i < 50; i++) {
        if (nama[i] == "") {
            break;
        }
    }
    if (posisisIterasi < 50)
    {
        cout << "Massukkan Data ke-" << posisisIterasi+1 << " dalam Phonebook: \n";
        cout << "Masukkan Nama: ";
        cin >> nama[posisisIterasi];
        cout << "Masukkan No Telepon: ";
        cin >> noTelp[posisisIterasi];
        cout << "Data Tersimpan!" << endl;
        return;
    }
    cout << "PhoneBook Penuh!" << endl;
}

void cariPhonebook(string nama[], string noTelp[]){
    cout << "Cari Phonebook:" << endl;
    string cariNama;
    cout << "Masukkan Nama yang dicari: ";
    cin >> cariNama;
    for (int i = 0; i < 50; i++) {
        if (nama[i] == cariNama) {
            cout << "Data Ditemukan!" << endl;
            cout << "Nama: " << nama[i] << endl;
            cout << "No Telepon: " << noTelp[i] << endl;
            return;
        }
    }
    cout << "Data Tidak Ditemukan!" << endl;
}

int main() {
    string nama[50];
    string noTelp[50];

    do {
        cout << "Menu Phonebook:" << endl;
        cout << "1. Isi Phonebook" << endl;
        cout << "2. Cari Phonebook" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih Menu: ";

        switch (getch()) {
            case '1':
                system("cls");
                isiPhonebook(nama, noTelp);
                system("PAUSE");
                system("cls");
                break;
            case '2':
                system("cls");
                cariPhonebook(nama, noTelp);
                system("PAUSE");
                system("cls");
                break;
            case '3':
                cout << "Keluar dari program." << endl;
                return 0;
            default:
                system("cls");
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (true);
}