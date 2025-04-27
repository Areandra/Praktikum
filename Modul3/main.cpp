#include <iostream>

using namespace std;

class Persegi {
protected:
    int panjangSisi;

public:
    int luas() {
        return panjangSisi * panjangSisi;
    }

    int keliling() {
        return 4 * panjangSisi;
    }

    void TampilPersegi() {
        cout << "Luas Persegi: " << luas() << ", Keliling: " << keliling() << endl;
    }
};

class Kubus : public Persegi {
public:
    void setSisi(int s) {
        panjangSisi = s;
    }

    int volume() {
        return panjangSisi * panjangSisi * panjangSisi;
    }

    void TampilKubus() {
        cout << "Luas Permukaan Persegi: " << luas()
             << ", Volume: " << volume() << " satuan kubik" << endl;
        TampilPersegi();
    }
};

int main() {
    Kubus k;
    k.setSisi(5);
    k.TampilKubus();

    return 0;
}
