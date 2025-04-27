#include <iostream>

using namespace std;

struct dosen {
    string nama[12] = {"Rebecca", "Carrot", "Ace", "Sabo", "Brook", "Zoro",
                       "Nami", "Luffy", "Chopper", "Sanji", "Usop", "Robin"};
};

struct  mahasiswa {
    string nama;
    dosen dosenwali;
};

struct matkul {
    string nama;
    dosen dosenPengamu[12];

};

int main() {
    
}