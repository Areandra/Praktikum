#include <iostream>
using namespace std;

int main() {
    cout << "-------------------------------------------------------------\n";
    cout << "Inisialisasi variabel a : \n";
    int a = 10;
    cout << "Alamat a : " << &a << "\n";
    cout << "Nilai yang disimpan di alamat yang ditunjuk oleh a : " << a << endl;
    cout << "-------------------------------------------------------------\n\n";

    cout << "-------------------------------------------------------------\n";
    cout << "Inisialisasi reference refb dengan mereferensikan variabel b : \n";
    int b = 10;
    int &refb = b;
    cout << "Alamat b : " << &b << "\n";
    cout << "Nilai yang disimpan di b : " << b << "\n";
    cout << "Alamat refb : " << &refb << "\n";
    cout << "Nilai yang disimpan di refb : " << refb << "\n\n";
    refb = 20;
    cout << "Nilai refb yang dirubah menjadi 20 : \n";
    cout << "Alamat b : " << &b << "\n";
    cout << "Nilai yang disimpan di b : " << b << "\n";
    cout << "Alamat refb : " << &refb << "\n";
    cout << "Nilai yang disimpan di refb : " << refb << "\n";
    cout << "-------------------------------------------------------------\n\n";

    cout << "-------------------------------------------------------------\n";
    cout << "Inisialisasi pointer angka1 dengan menunjuk langsung alamat variabel angka : \n";
    int angka = 10;
    int *angka1 = &angka;
    cout << "Nilai *angka1 dirubah menjadi 20 : \n";
    cout << "Nilai angka : " << &angka << "\n";
    cout << "Nilai yang disimpan di alamat yang ditunjuk oleh angka1 : " << angka << "\n";
    cout << "Alamat angka1 : " << angka1 << "\n";
    cout << "Nilai yang disimpan di alamat yang ditunjuk oleh angka1 : " << *angka1 << "\n\n";
    *angka1 = 20;
    cout << "Nilai *angka1 dirubah menjadi 20 : \n";
    cout << "Nilai angka : " << &angka << "\n";
    cout << "Nilai yang disimpan di alamat yang ditunjuk oleh angka1 : " << angka << "\n";
    cout << "Alamat angka1 : " << angka1 << "\n";
    cout << "Nilai yang disimpan di alamat yang ditunjuk oleh angka1 : " << *angka1 << "\n";
    cout << "-------------------------------------------------------------\n";

    cout << "-------------------------------------------------------------\n";
    cout << "Inisialisasi pointer class alokasi memori secara dinamis : \n";
    class Rectangle {
        private:
            int width;
            int height;
        public:
            Rectangle(int w, int h) {
                width = w;
                height = h;
            }
            int calculateArea() {
                return width * height;
            }
            void display() {
                cout << "Rectangle Information : \n";
                cout << "Width : " << width << "\n";
                cout << "Height : " << height << "\n";
                cout << "Area : " << calculateArea() << "\n";
            }
    };

    Rectangle* rect = new Rectangle(5, 10);
    cout << "Alamat class Rectangle : " << rect << "\n";
    rect->calculateArea();
    (*rect).display();

    delete rect;
    cout << "-------------------------------------------------------------\n";

    return 0;
}
