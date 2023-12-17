#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Struktur untuk informasi buku
struct Buku
{
    string judulBuku;
    string penulis;
    int tahunTerbit;
};

// Struktur untuk informasi peminjaman
struct Peminjaman
{
    string namaPeminjam;
    string judulBuku;
    int id;
    string tanggalPinjam;
    string tanggalKembali;
};

// Struktur basis data peminjaman buku
struct DatabasePeminjaman
{
    Peminjaman dataPeminjaman[100]; // Asumsi maksimal 100 peminjaman
    int jumlahPeminjaman;
};

// Fungsi untuk menyimpan informasi peminjaman ke dalam basis data
void tambahPeminjaman(DatabasePeminjaman &database, const Peminjaman &peminjaman)
{
    if (database.jumlahPeminjaman < 100)
    {
        database.dataPeminjaman[database.jumlahPeminjaman] = peminjaman;
        database.jumlahPeminjaman++;
        cout << "Informasi peminjaman berhasil ditambahkan." << endl;
    }
    else
    {
        cerr << "Basis data penuh, tidak dapat menambahkan peminjaman baru." << endl;
    }
}

// Fungsi untuk menampilkan semua informasi peminjaman dari basis data
void tampilkanSemuaPeminjaman(const DatabasePeminjaman &database)
{
    cout << "Daftar Peminjaman:" << endl;
    for (int i = 0; i < database.jumlahPeminjaman; i++)
    {
        cout << "ID: " << database.dataPeminjaman[i].id
             << ", Peminjam: " << database.dataPeminjaman[i].namaPeminjam
             << ", Jud
