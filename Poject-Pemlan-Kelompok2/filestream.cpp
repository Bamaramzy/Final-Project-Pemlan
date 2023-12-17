// main.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

struct Buku
{
    string judulBuku;
    string penulis;
    int tahunTerbit;
    int jumlah;
};

struct Peminjam
{
    string namaPeminjam;
    string judulBuku;
};

class Library
{
public:
    void displayAllBooks(Buku buku[], int size);
    void displayAllPeminjam(Peminjam peminjam[], int size);
    void sortByTitle(Buku buku[], int size);
    void readBooksFromFile(Buku buku[], int &size, const string &filename);
    void readPeminjamFromFile(Peminjam peminjam[], int &size, const string &filename);
};

void Library::displayAllBooks(Buku buku[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << buku[i].judulBuku << " " << buku[i].penulis << " " << buku[i].tahunTerbit << " " << buku[i].jumlah << endl;
    }
}

void Library::displayAllPeminjam(Peminjam peminjam[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << peminjam[i].namaPeminjam << " " << peminjam[i].judulBuku << endl;
    }
}

void Library::sortByTitle(Buku buku[], int size)
{
    sort(buku, buku + size, [](const Buku &a, const Buku &b)
         { return a.judulBuku < b.judulBuku; });
}

void Library::readBooksFromFile(Buku buku[], int &size, const string &filename)
{
    ifstream infile(filename);
    if (!infile)
    {
        cerr << "File " << filename << " tidak dapat dibuka.\n";
        return;
    }

    size = 0;
    while (infile >> buku[size].judulBuku >> buku[size].penulis >> buku[size].tahunTerbit >> buku[size].jumlah)
    {
        ++size;
        if (size >= 20) // Memastikan tidak melebihi kapasitas array
            break;
    }

    infile.close();
}

void Library::readPeminjamFromFile(Peminjam peminjam[], int &size, const string &filename)
{
    ifstream infile(filename);
    if (!infile)
    {
        cerr << "File " << filename << " tidak dapat dibuka.\n";
        return;
    }

    size = 0;
    while (infile >> peminjam[size].namaPeminjam >> peminjam[size].judulBuku)
    {
        ++size;
        if (size >= 20) // Memastikan tidak melebihi kapasitas array
            break;
    }

    infile.close();
}

int main()
{
    const int maxSize = 20;
    Buku buku[maxSize];
    Peminjam peminjam[maxSize];

    int sizeBuku = 0;
    int sizePeminjam = 0;

    Library library;

    // Membaca data buku dari file
    library.readBooksFromFile(buku, sizeBuku, "dbBuku.txt");

    // Membaca data peminjam dari file
    library.readPeminjamFromFile(peminjam, sizePeminjam, "dbPeminjam.txt");

    // Menampilkan data buku
    cout << "Data Buku:\n";
    library.displayAllBooks(buku, sizeBuku);

    // Menampilkan data peminjam
    cout << "\nData Peminjam:\n";
    library.displayAllPeminjam(peminjam, sizePeminjam);

    return 0;
}
