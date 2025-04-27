#include <iostream>

using namespace std;

int main() {
    int baris, kolom;
    cout << "Masukkan jumlah baris: ";
    cin >> baris;
    cout << "Masukkan jumlah kolom: ";
    cin >> kolom;

    int matriks1[baris][kolom], matriks2[kolom][baris], hasil[baris][baris];

    cout << "Ukuran matriks 1: " << baris << " x " << kolom << endl
         << "Otomatis Ukuran matriks 2: " << kolom << " x " << baris << endl;

    cout << "Generate random elemen matriks 1:\n";
    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
        {
            matriks1[i][j] = rand() % 10;
            cout << "Matriks 1 [" << i << "][" << j << "] : " << matriks1[i][j] << endl;
        }
    }

    cout << "Generate random elemen matriks 2:\n";
    for (int i = 0; i < kolom; i++)
    {
        for (int j = 0; j < baris; j++)
        {
            matriks2[i][j] = rand() % 10;
            cout << "Matriks 2 [" << i << "][" << j << "] : " << matriks2[i][j] << endl;
        }
    }

    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < baris; j++) {
            hasil[i][j] = 0;
            for (int k = 0; k < kolom; k++) {
                hasil[i][j] += matriks1[i][k] * matriks2[k][j];
            }
        }
    }

    cout << "\nHasil Perkalian Matriks:\n";
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < baris; j++)
            cout << hasil[i][j] << "\t";
        cout << endl;
    }
}

