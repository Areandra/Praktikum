#include <iostream>
using namespace std;

int main() {
    int arr[2][2][2][2];

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 2; l++) {
                    cin >> arr[i][j][k][l];
                }
            }
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 2; l++) {
                    cout << "arr[" << i << "][" << j << "][" << k << "][" << l << "] = "
                         << arr[i][j][k][l] << "\n";
                }
            }
        }
    }

    return 0;
}
