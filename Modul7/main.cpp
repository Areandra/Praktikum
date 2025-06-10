#include <iostream>
#include <cstring>
using namespace std;

int main() {
    // Inisialisasi variabel a
    cout << "Inisialisasi variabel a : \n";
    int a = 10;
    cout << "Alamat a : " << &a << "\n";
    cout << "Nilai yang disimpan di alamat yang ditunjuk oleh a : " << a << endl;
    cout << "\n";

    // Inisialisasi reference refb
    cout << "Inisialisasi reference refb dengan mereferensikan variabel b : \n";
    int b = 10;
    int &refb = b;
    cout << "Alamat b : " << &b << "\n";
    cout << "Nilai yang disimpan di b : " << b << "\n";
    cout << "Alamat refb : " << &refb << "\n";
    cout << "Nilai yang disimpan di refb : " << refb << "\n\n";

    // Inisialisasi pointer angka1
    cout << "Inisialisasi pointer angka1 dengan menunjuk langsung alamat variabel angka : \n";
    int angka = 10;
    int *angka1 = &angka;
    cout << "Alamat angka1 : " << angka1 << "\n";
    cout << "Nilai yang disimpan di alamat yang ditunjuk oleh angka1 : " << *angka1 << "\n\n";

    // Inisialisasi pointer tipe data int dengan alokasi memori secara dinamis
    cout << "Inisialisasi pointer type data int dengan alokasi memori secara dinamis";
    int *AInt = new int;
    *AInt  = 1;
    cout << "Alamat AInt : " << AInt << "\n";
    cout << "Nilai yang disimpan di alamat yang ditunjuk oleh Aint : " << *AInt << "\n";
    delete AInt;
    cout << "\n";

    // Inisialisasi pointer tipe char
    cout << "Inisialisasi pointer type char (style string) alokasi memori secara dinamis";
    char* car = new char[6];
    strcpy(car, "Hello");
    cout << "Alamat car : " << static_cast<void*>(car) << "\n";
    cout << "Nilai yang disimpan di alamat yang ditunjuk oleh car : " << car << "\n";
    delete[] car;
    cout << "\n";
   
    // Inisialisasi pointer tipe string
    cout << "Inisialisasi pointer type string alokasi memori secara dinamis";
    string* str = new string("Hello World");
    cout << "Alamat str : " << str << "\n";
    cout << "Nilai yang disimpan di alamat yang ditunjuk oleh str : " << *str << "\n";
    delete str;
    cout << "\n";

    // Inisialisasi pointer struct
    cout << "Inisialisasi pointer type struct alokasi memori secara dinamis";
    struct Person
    {
        string name;
        int age;
    };
    Person *person = new Person;
    person->name = "Usma";
    person->age = 20;
    cout << "Alamat struct Person : " << person << "\n";
    cout << "Nama : " << person->name << "\n";
    cout << "Umur : " << person->age << "\n";
    delete person;
    cout << "\n";

    // Inisialisasi pointer class
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
    rect->display();
    delete rect;
    cout << "\n";

    return 0;
}
