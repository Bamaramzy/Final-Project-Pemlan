#include <iostream>
#include <fstream>
#include <string>

using namespace std;
struct Buku {
    std::string judulBuku;
    std::string penulis;
    int tahunTerbit;
    int jumlah;
};

struct Peminjam
{
    int index;
    string namaPeminjam;
    string judulBuku;
};

#include "searching.cpp"
#include "sorting.cpp"
#include "string.cpp"
#include "filestream.cpp"

int main(){
    int pilihan;
    const int MAX_BUKU = 10;
    const int MAX_PEMINJAM = 100;

    menu:
    system("CLS");
    Buku buku[MAX_BUKU];
    Peminjam peminjam[MAX_PEMINJAM];
    readBuku(buku, MAX_BUKU);
    readPeminjam(peminjam, MAX_PEMINJAM);
    cout<<"Aplikasi Perpustakaan Manga\n";
    cout<<"1. Lihat Daftar Buku\n";
    cout<<"2. Lihat Daftar Peminjam\n";
    cout<<"3. Pinjam Buku\n";
    cout<<"4. Pengembalian Buku\n";
    cout<<"99. Keluar\n\n";
    cout<<"Pilihan anda: ";
    cin>>pilihan;

    switch(pilihan){
        case 1: 
            system("CLS");
            displayBuku(buku, MAX_BUKU);
            system("pause");
            break;
        case 2:
            system("CLS");
            displayPeminjam(peminjam);
            system("pause");
            break;
        case 3:
            writePeminjam(peminjam, buku);
            system("pause");
            break;
        case 4:
            kembali(buku, peminjam);
            system("pause:");
            break;
        case 99:
            cout <<"Terima kasih!";
            return 0;
    }
    goto menu;
}
