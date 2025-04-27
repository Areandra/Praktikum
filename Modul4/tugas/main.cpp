#include <iostream>

using namespace std;

// deklarasi fungsi untuk menampilkan isi array dengan parameter data array dan panjang array
string isiArray(int arr[], int n) {
    // deklarasi string untuk menampung isi array yang di inisialisasi dengan tanda kurung siku sebagai pembuka
    string isi = "[ ";
    // pengulangan untuk menampung isi array ke dalam string
    for (int i = 0; i < n; i++) {
        // menambahkan elemen array ke dalam string
        // dimana jika elemen terakhir maka tidak perlu menambahkan koma
        isi += to_string(arr[i]) + ((i == n - 1) ? "" : ", ");
    } 
    // menambahkan tanda kurung siku sebagai penutup   
    isi += " ]";
    // mengembalikan string yang berisi isi array
    return isi;
} 

// deklarasi fungsi bublesort dengan parrams data array dan panjang array
void bubbleSort(int arr[], int n) {
    // deklarasi bool untuk menampung status pertukaran elemen
    bool tukar;
    // pengulangan untuk mengulang putaran penyortian
    for (int i = 0; i < n - 1; i++) {
        // menampilkan posisi iterasi
        cout << "\nIterasi - " << i+1 << " :\n";
        // pengulangan untuk membandingkan elemen dalam array dari awal hingga 1 - pos terakhir pada pengulangan sebelumnya
        for (int j = 0; j < n - i - 1; j++) {
            // menampilkan posisi proses
            cout << "Proses - " << j+1 << ": " << isiArray(arr, n) << "\nMembandingan Elemen Pada index ( [" << j << "] = " << arr[j] << " & " << "[" << j+1 << "] = " << arr[j+1] << " )" << " : ";

            // jika elemen saat ini lebih besar dari elemen berikutnya
            if (arr[j] > arr[j + 1]) {
                // maka tukar elemen saat ini dengan elemen berikutnya
                swap(arr[j], arr[j + 1]);
                // lalu ubah flag tukar menjadi true
                tukar = true;
            }
            // menampilkan isi array sebelum iterasi selesai
            cout << "\n[" << (tukar ? "Terjadi Pertukaran" : "Tidak Terjadi Pertukaran") << "] Elemen Dalam Array: " << isiArray(arr, n) << endl;
            // reset flag tukar
            tukar = false;
        }
    }
}

// deklarasi fungsi selectionsort dengan parrams data array dan panjang array
void selectionSort(int arr[], int n) {
    // deklarasi bool untuk menampung status pos
    bool pindah;
    // pengulangan untuk mengulang putaran penyortian
    for (int i = 0; i < n - 1; i++) {
        // inisialisasi posisi elemen terkecil dimulai dengan posisi elemen pertama
        int pos = i;
        // menampilkan posisi iterasi
        cout << "\nIterasi - " << i+1 << " Pivot [ " << i << " ] = " << arr[i] << " : " << isiArray(arr, n)  << "\n";
        // pengulangan untuk mencari elemen terkecil dalam array
        for (int j = i + 1; j < n; j++) {
            pindah = false;
            // menampilkan posisi proses
            cout << "Proses - " << j << ": "
                 << "\nMembandingan Elemen Pada index ( [" << pos << "] = " << arr[pos] << " & " << "[" << j << "] = " << arr[j] << " )" << " : ";
            // jika elemen saat ini lebih kecil dari elemen terkecil
            if (arr[j] < arr[pos]) {
                // maka simpan posisi elemen terkecil
                pos = j;
                // ubah flag pindah menjadi true
                pindah = true;
            }
            // menampilkan posisi elemen terkecil
            cout << "Posisi Inndex Elemen Terkecil " << (pindah ? "Pindah : [" : ": [") << pos << "] = " << arr[pos] << endl;
        }
        // saat pengulangan untuk mencari elemen terkecil selesai tukar elemen terkecil dengan elemen pertama
        swap(arr[i], arr[pos]);
        // lalu tampikan array setelah ditukar
        cout << (pos == i ? "Tidak Terjadi Pertukaran " : ("Menukar Elemen Antara [ Pivot ] & [ Posis Elemen Terkecil ]\n")) 
             << "Elemen Dalam Array " << (pos == i ? ":" : "Setelah Pertukaran : ") << isiArray(arr, n) << endl;
    }
}

// deklarasi fungsi quicksort dengan parrams data array, index terkecil dan index terbesar 
// untuk membatasi area perbandingan antara index terkecil dan terbesar pada perulangan
void quickSort(int arr[],int n, int low, int high) {
    // jika index terkecil lebih kecil dari index terbesar
    if (low < high) {
        // maka deklarasi flag tukar dan proses
        bool tukar;
        int proses = 1;
        // inisialisasi pivot dengan elemen tengah dari array
        int pivot = arr[(low + high) / 2];
        // inisialisasi int i dan j untuk menulusuri elemen yang ada di kiri dan kanan dari pivot
        int i = low, j = high;
        
        // menampilkan Proses Pertama Dimulai
        if (pivot == ((n-1)/2)) cout << "Iterasi Pertama :";
        
        // menampilkan posisi pivot dan nilainya
        cout << "\nPivot [" << ((low + high) / 2) << "] = " << pivot << "\nElemen Array Saat ini : " << isiArray(arr, n) ;
        // pengulangan untuk mengulang putaran pengurutan selama index terkecil lebih kecil atau sama dengan index terbesar
        while (i <= j) {
        // menampilkan posisi proses
            cout << "\nProses - " << proses++;
            // menampilkan posisi pencarian berdasarkan sisi
            cout << "\nElemen Disisi Kiri Start [" << i << "] :\nMencari Elemen Yang Lebih Besar Dari Pivot :";
            // perulangan yang menaikan index iterasi yang ada di kiri untuk mencari elemen yang lebih besar dari pivot
            while (arr[i] < pivot) {
            // menampilkan pos pencarian
                cout << "\nPosisi Pencarian : [" << i << "] = " << arr[i];
                // menaikan index
                i++;
            }
            // menampilkan posisi elemen di temukan
            cout << "\nPosisi Elemen Di Temukan : [" << i << "] = " << arr[i];

            //menampilkan posisi pencarian berdasarkan sisi
            cout << "\nElemen Disisi Kanan Start [" << j << "] :\nMencari Elemen Yang Lebih Kecil Dari Pivot :";
            // perulangan yang menurunkan index iterasi yang ada di kanan untuk mencari elemen yang lebih kecil dari pivot, 
            while (arr[j] > pivot) {
                // menampilkan pos pencarian
                cout << "\nPosisi Pencarian : [" << j << "] = " << arr[j];
                // menurunkan index
                j--;
            }
            // menampilkan posisi elemen di temukan
            cout << "\nPosisi Elemen Di Temukan : [" << j << "] = " << arr[j];
            // contoh :
            // 0, 1, 4, 2, ... <=    data di sebelah kiri pivot dimana 5 merupakan elemen pada index pertama
            //       /\              jika elemen saat itu lebih kecil dari 2 maka index i akan dinaikkan dan berhenti di naikkan saat
            //      pivot            elemen pada index i lebih besar dari pivot untuk menyimpan pos elemen tersebut yang akan di tukar dengan
            //                       elemen yang nilainya lebih kecil dari pivot yang ada di sebalah kanan dari pivot, 
            //                       yang proses pencarian posnya sama dengan proses sebelummnya

            // jika index terkecil lebih kecil atau sama dengan index terbesar
            // untuk menghindari pertukaran yang iterasinya saling melewati
            if (i <= j) {
                // jika index terkecil dan terbesar tidak sama (Menghindari Pertukaran Yang Tidak Perlu) 
                if (i != j) {
                    // maka tukar elemen di posisi kiri pivot dengan elemen di posisi kanan pivot
                    swap(arr[i], arr[j]);
                    // set flag tukar ke true
                    tukar = true;
                }
                // tampilkan pesan pertukaran elemen
                cout << (tukar ? "\nTukar Elemen Yang Telah Ditemukan Yang Berada Dikiri [" + to_string(i) + "] " + "dan Kanan [" + to_string(j) + "] " : "\nTidak Terjadi Pertukaran") << "\nElemen Array " << (tukar ? "Setelah Ditukar : " : ": ")  << isiArray(arr, n);
                // lalu naikankan index i dan turunkan index j untuk untuk membatasi area iterasi pada setiap sisi pivot, 
                // yaitu 1 posisi setelah posisi pertukaran (i) dan 1 posisi sebelum posisi pertukaran (j)
                i++; j--;
                // reset flag tukar
                tukar = false;
            }
            // menampilkan pesan bahwa index saling melewati
            else cout << "\nIndex Saling Melewati [ NEXT ]";
        }
        // menampilkan pesan bahwa iterasi berlanjut
        cout << "\n\nIterasi Selanjutnya [ ";
        // jika index terkecil lebih kecil dari j
        if (low < j) {
            // menampilkan posisi rekursi   
            cout << "Sebelah Kiri Pivot Sebelumnya ] :";
            // Rekursi untuk mengurutkan subarray di sebelah kiri pivot sebelumnya
            quickSort(arr, n, low, j);
        }
        // jika index terkecil lebih kecil dari high
        if (i < high) {
            // Menampilkan Posisi Rekursi
            cout << "Sebelah Kanan Pivot Sebelumnya ] :";
            // Rekursi untuk mengurutkan subarray di sebelah kanan pivot sebelumnya
            quickSort(arr, n, i, high);
        }
    }
}

// fungsi untuk menyimpan array ke dalam array lain
void saveArray(int arr[], int arr2[], int n) {
    // pengulangan untuk menyimpan array ke dalam array lain
    for (int i = 0; i < n; i++) {
        // menyimpan elemen array ke dalam array lain
        arr2[i] = arr[i];
    }
}

// deklarasi fungsi untuk meminta input elemen array dengan parameter data array dan panjang array
void inputArray(int arr[], int arr2[], int n) {
    // pengulangan untuk input elemen array
    for (int i = 0; i < n; i++) {
        // menampilkan pesan untuk meminta input elemen array
        cout << "Masukkan Elemen Ke-" << i + 1 << ": ";
        //  menginput elemen array
        cin >> arr[i];
    }
    saveArray(arr, arr2, n);
}


void resetArray(int arr[], int arr2[], int n) {
    // pengulangan untuk mengisi array dengan array yang sudah disimpan
    for (int i = 0; i < n; i++) {
        // mengisi elemen array dengan array yang sudah disimpan
        arr[i] = arr2[i];
    }
}


void pause(string pesan, int arr[], int arr2[], int n) {
    // menampilkan pesan untuk meminta input untuk melanjutkan
    cout << pesan;
    // pause sistem
    cin.ignore();
    cin.get();
    // bersihkan layar
    system("cls");
    
    // reset array untuk menghindari kesalahan data pada array yang sudah diurutkan
    resetArray(arr, arr2, n);
}

// / fungsi utama
int main() {
    // deklarasi panjang array
    int n;
    
    // menampilkan pesan untuk meminta input panjang array
    cout << "Masukkan Panjang Array: ";    
    // meminta input panjang array
    cin >> n;

    
    // deklarasi array yang akan diurutkan
    int arr[n];
    int saveArr[n];

    
    // meminta input elemen array
    inputArray(arr, saveArr, n);
    
    // bersihkan layar
    system("cls");

    // menampilkan isi array sebelum diurutkan
    cout << "Array Sebelum Diurutkan: " << isiArray(arr, n) << endl;

    // memanggil fungsi bubbleSort unuk mengurutkan array
    bubbleSort(arr, n);
    //menampilkan isi array setelah diurutkan
    cout << "\n\nArray setelah diurutkan dengan Bubble Sort: " << isiArray(arr, n) << endl;

    // memanggil fungsi pause
    pause("\nTekan Enter untuk melanjutkan...", arr, saveArr, n);

    // menampilkan isi array sebelum diurutkan
    cout << "Array sebelum diurutkan: " << isiArray(arr, n) << endl;

    // memanggil fungsi selectionSort untuk mengurutkan array
    selectionSort(arr, n);
    //menampilkan isi array setelah diurutkan
    cout << "\n\nArray setelah diurutkan dengan Selection Sort: " << isiArray(arr, n) << endl;

    // memanggil fungsi pause
    pause("\nTekan Enter untuk melanjutkan...", arr, saveArr, n);

    // menampilkan isi array sebelum diurutkan
    cout << "Array sebelum diurutkan: " << isiArray(arr, n) << endl;

    // memanggil fungsi quickSort untuk mengurutkan array
    quickSort(arr, n, 0, n - 1);
    //menampilkan isi array setelah diurutkan
    cout << "\n\nArray setelah diurutkan dengan Quick Sort: " << isiArray(arr, n) << endl;

    // program selesai
    return 0;
}

