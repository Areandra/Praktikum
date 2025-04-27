#include <iostream>
#include <string>

using namespace std;

int main() {
    int database[2][2][2][2];

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 2; l++) {
                    cout << "Database ke-" << i + 1 << ", tabel ke-" << j + 1
                         << ", baris ke-" << k + 1 << ", kolom ke-" << l + 1 << " = ";
                    cin >> database[i][j][k][l];
                }
            }
        }
    }

    cout << "\n";

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 2; l++) {
                    cout << "Database [" << i + 1 << "][" << j + 1 << "][" << k + 1 << "][" << l + 1 << "] + "
                         << "Database [" << i + 2 << "][" << j + 1 << "][" << k + 1 << "][" << l + 1 << "] = "
                         << database[i][j][k][l] + database[i + 1][j][k][l] << endl;
                }
            }
        }
    }

    cout << "\n";
    // ... (PAUSE);
    system("PAUSE");

    return 0;
}