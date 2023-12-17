#include <iostream>
#include <fstream>
#include <string>

struct Buku {
    std::string judulBuku;
    std::string penulis;
    int tahunTerbit;
    int jumlah;
};

int main(){
    Buku buku[20];
    Buku buku2[20];
    buku[0] = {"Buku_A", "Penulis_E", 2000, 3};
    buku[1] = {"Buku_C", "Penulis_H", 1998, 4};
    buku[2] = {"Buku_B", "Penulis_F", 2010, 6};
    buku[3] = {"Buku_D", "Penulis_I", 2005, 4};
    buku[4] = {"Buku_E", "Penulis_G", 1995, 3};

    std::ofstream outfile;
    outfile.open("file.txt");
    outfile << buku[0].judulBuku <<" "<< buku[0].penulis <<" "<< buku[0].tahunTerbit <<" "<< buku[0].jumlah << std::endl;
    outfile << buku[1].judulBuku <<" "<< buku[1].penulis <<" "<< buku[1].tahunTerbit <<" "<< buku[1].jumlah << std::endl;
    outfile.close();

    std::ifstream infile;
    infile.open("file.txt");

    infile >> buku2[0].judulBuku >> buku2[0].penulis >> buku2[0].tahunTerbit >> buku2[0].jumlah;
    infile >> buku2[1].judulBuku >> buku2[1].penulis >> buku2[1].tahunTerbit >> buku2[1].jumlah;

    std::cout<<buku2[0].judulBuku <<" "<< buku2[0].penulis <<" "<< buku2[0].tahunTerbit <<" "<< buku2[0].jumlah << std::endl;
    std::cout<<buku2[1].judulBuku <<" "<< buku2[1].penulis <<" "<< buku2[1].tahunTerbit <<" "<< buku2[1].jumlah << std::endl;

    return 0;
}
