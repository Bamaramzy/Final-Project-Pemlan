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
};

// Fungsi untuk menyimpan informasi buku ke dalam file
void simpanInfoBuku(const Buku &buku, const string &namaFile)
{
    ofstream fileOutput(namaFile, ios::app); // ios::app untuk menambahkan ke akhir file
    if (fileOutput.is_open())
    {
        fileOutput << buku.judulBuku << "," << buku.penulis << "," << buku.tahunTerbit << endl;
        fileOutput.close();
        cout << "Informasi buku berhasil disimpan." << endl;
    }
    else
    {
        cerr << "Gagal membuka file untuk menyimpan informasi buku." << endl;
    }
}

// Fungsi untuk menyimpan informasi peminjaman ke dalam file
void simpanInfoPeminjaman(const Peminjaman &peminjaman, const string &namaFile)
{
    ofstream fileOutput(namaFile, ios::app);
    if (fileOutput.is_open())
    {
        fileOutput << peminjaman.namaPeminjam << "," << peminjaman.judulBuku << endl;
        fileOutput.close();
        cout << "Informasi peminjaman berhasil disimpan." << endl;
    }
    else
    {
        cerr << "Gagal membuka file untuk menyimpan informasi peminjaman." << endl;
    }
}

// Fungsi untuk membaca dan menampilkan informasi dari file
void bacaDanTampilkanInfo(const string &namaFile)
{
    ifstream fileInput(namaFile);
    if (fileInput.is_open())
    {
        string line;
        cout << "Isi File " << namaFile << ":" << endl;
        while (getline(fileInput, line))
        {
            cout << line << endl;
        }
        fileInput.close();
    }
    else
    {
        cerr << "Gagal membuka file untuk membaca informasi." << endl;
    }
}

// Fungsi untuk menghitung jumlah buku
int hitungJumlahBuku(const string &namaFile)
{
    ifstream fileInput(namaFile);
    if (fileInput.is_open())
    {
        string line;
        int jumlahBuku = 0;
        while (getline(fileInput, line))
        {
            jumlahBuku++;
        }
        fileInput.close();
        return jumlahBuku;
    }
    else
    {
        cerr << "Gagal membuka file untuk menghitung jumlah buku." << endl;
        return -1; // Mengembalikan nilai negatif jika terjadi kesalahan
    }
}

int main()
{
    // Contoh penggunaan
    Buku buku1 = {"Harry Potter", "J.K. Rowling", 1997};
    Peminjaman peminjaman1 = {"John Doe", "Harry Potter"};

    string namaFileBuku = "informasi_buku.txt";
    string namaFilePeminjaman = "informasi_peminjaman.txt";

    // Simpan informasi buku dan peminjaman ke dalam file
    simpanInfoBuku(buku1, namaFileBuku);
    simpanInfoPeminjaman(peminjaman1, namaFilePeminjaman);

    // Baca dan tampilkan informasi dari file
    bacaDanTampilkanInfo(namaFileBuku);
    bacaDanTampilkanInfo(namaFilePeminjaman);

    // Hitung dan tampilkan jumlah buku
    int jumlahBuku = hitungJumlahBuku(namaFileBuku);
    if (jumlahBuku >= 0)
    {
        cout << "Jumlah buku: " << jumlahBuku << endl;
    }
    else
    {
        cerr << "Gagal menghitung jumlah buku." << endl;
    }

    return 0;
}
