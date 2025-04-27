#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string dosenWali;
    string mataKuliah[3];
};

int main() {
    Mahasiswa mhs;

    cout << "Masukkan nama mahasiswa: ";
    getline(cin, mhs.nama);

    cout << "Masukkan nama dosen wali: ";
    getline(cin, mhs.dosenWali);

    cout << "Masukkan 3 mata kuliah yang diambil:\n";
    for (int i = 0; i < 3 ; i++) {
        cout << "- Mata kuliah ke-" << i+1 << ": ";
        getline(cin, mhs.mataKuliah[i]);
    }

    cout << "\nData Mahasiswa\n"
         << "Nama : " << mhs.nama << endl
         << "Dosen Wali : " << mhs.dosenWali << endl
         << "Mata Kuliah :\n";
         
    for (int i = 0; i < 3; i++) {
        cout << "  " << i+1 << ". " << mhs.mataKuliah[i] << endl;
    }

    return 0;
}
