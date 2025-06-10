#include <iostream>

using namespace std;

int main() {
    int arr[] = {2, 4, 6, 8, 10};
    int* p = arr;
    for (int i; i < 5; i++) {
        cout << "Data ke - " << i+1 << " : " << *(p + i) << endl;
    }
}