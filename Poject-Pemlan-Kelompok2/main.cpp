// main.cpp

#include "library.h"
using namespace std;

int main() {
    Library library;
    int choice;

    do {
        cout << "1. Tampilkan semua data buku\n";
        cout << "2. Tampilkan semua data peminjam\n";
        cout << "3. Pinjam buku\n";
        cout << "4. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> choice;

        switch (choice) {
            case 1:
                library.displayAllBooks();
                break;
            case 2:
                library.displayAllPeminjam();
                break;
            case 3:
                library.borrowBook();
                break;
            case 4:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Opsi tidak valid. Silakan pilih kembali.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}
