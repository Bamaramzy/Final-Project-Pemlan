// library.cpp

#include "library.h"
using namespace std;

void Library::displayAllBooks() {
    ifstream file("database_buku.txt");
    string line;

    cout << "Judul_Buku\tPenulis\tTahun_Terbit\n";
    cout << "--------------------------------\n";

    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

void Library::displayAllPeminjam() {
    ifstream file("database_peminjam.txt");
    string line;

    cout << "Nama_Peminjam\tJudul_Buku\n";
    cout << "--------------------------\n";

    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

void Library::borrowBook() {
    string borrower, bookTitle;

    cout << "Masukkan Nama Peminjam: ";
    cin.ignore();
    getline(cin, borrower);

    cout << "Masukkan Judul Buku yang ingin dipinjam: ";
    getline(cin, bookTitle);

    ofstream peminjamFile("database_peminjam.txt", ios::app);
    peminjamFile << borrower << '\t' << bookTitle << '\n';
    peminjamFile.close();

    cout << "Buku '" << bookTitle << "' berhasil dipinjam oleh " << borrower << ".\n";
}
