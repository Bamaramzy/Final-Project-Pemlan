void readBuku(Buku buku[], int size){
    ifstream infile;
    infile.open("dbBuku.txt");
    for (int i = 0; i < size ; i++){
        infile >> buku[i].judulBuku >> buku[i].penulis >> buku[i].tahunTerbit >> buku[i].jumlah;
        buku[i].judulBuku = replace2Space(buku[i].judulBuku);
        buku[i].penulis = replace2Space(buku[i].penulis);
    }
    infile.close();
}

void readPeminjam(Peminjam peminjam[], int size){
    ifstream infile;
    infile.open("dbPeminjam.txt");
    for (int i = 0; i < size ; i++){
        infile >> peminjam[i].index >> peminjam[i].namaPeminjam >> peminjam[i].judulBuku;
        peminjam[i].judulBuku = replace2Space(peminjam[i].judulBuku);
        peminjam[i].namaPeminjam = replace2Space(peminjam[i].namaPeminjam);
    }
    infile.close();
}

void displayBuku(Buku buku[], int size){
    for (int i = 0; i < size; ++i){
        cout << i+1 << " -- " << buku[i].judulBuku << " -- " << buku[i].penulis << " -- " << buku[i].tahunTerbit << endl;
    }
    cout << endl;
}

void displayPeminjam(Peminjam peminjam[]){
    int size = 0;
    for (int i = 0; peminjam[i].index == i+1 ; i++){
        size++;
        if (peminjam[i].namaPeminjam == " "){
            break;
        }
    }
    for (int i = 0; i < size; ++i){
        cout << i+1 << " -- " << peminjam[i].namaPeminjam << " -- " << peminjam[i].judulBuku << endl;
    }
    cout << endl;
}



void writeBuku(Buku buku[], int size, int pilihan, bool kembali){
    readBuku(buku, size);
    if(kembali){
       buku[pilihan].jumlah = buku[pilihan].jumlah + 1;
    }
    else{
        buku[pilihan].jumlah = buku[pilihan].jumlah - 1;
    }
    ofstream outfile;
    outfile.open("dbBuku.txt");
    for (int i = 0; i != size; i++){
        buku[i].judulBuku = replace2Underscore(buku[i].judulBuku);
        buku[i].penulis = replace2Underscore(buku[i].penulis);
        outfile << buku[i].judulBuku << " " << buku[i].penulis << " " << buku[i].tahunTerbit <<" "<<buku[i].jumlah << endl;
    }
}


void writePeminjam(Peminjam peminjam[], Buku buku[]){
    ulang:
    system("CLS");
    int size = 0;
    int nomorbuku = 0;
    string nama;
    for (int i = 0; peminjam[i].index == i+1 ; i++){
        size++;
    }

    cout<<"Masukkan nama: ";
    cin.ignore();
    getline(cin, nama);
    
    if (panjangnama(nama)){
        peminjam[size].namaPeminjam = nama;
    }
    else {
        goto ulang;
    }

    displayBuku(buku, 10);
    cout<<"Masukkan nomor buku: ";
    cin>>nomorbuku;

    nomorbuku = nomorbuku - 1;
    
    if (buku[nomorbuku].jumlah == 0){
        cout<<"Stok Buku Habis!\n";
        return;
    }
    peminjam[size].index = size+1;
    peminjam[size].judulBuku = buku[nomorbuku].judulBuku;


    ofstream outfile;
    outfile.open("dbPeminjam.txt");
    for (int i = 0; i != size + 1; i++){
        outfile << i+1 <<" "<< replace2Underscore(peminjam[i].namaPeminjam) <<" "<< replace2Underscore(peminjam[i].judulBuku) << endl;
    }
    outfile.close();

    writeBuku(buku, 10, nomorbuku, false);
}

void kembali(Buku buku[], Peminjam peminjam[]){
    int size = 0;
    int nomor;
    for (int i = 0; peminjam[i].index == i+1 ; i++){
        size++;
    }

    displayPeminjam(peminjam);
    cout<<"Masukkan Nomor Anda: ";
    cin>>nomor;
    nomor = nomor - 1;

    for (int i = nomor; i != size; i++){
        peminjam[i].judulBuku = peminjam[i+1].judulBuku;
        peminjam[i].namaPeminjam = peminjam[i+1].namaPeminjam;
    }
    int nomorbuku = searchJudulPeminjam(peminjam, size, peminjam[nomor].judulBuku);
    writeBuku(buku, 10, nomorbuku, true);

    ofstream outfile;
    outfile.open("dbPeminjam.txt");
    for (int i = 0; i != size - 1; i++){
        peminjam[i].judulBuku = replace2Underscore(peminjam[i].judulBuku);
        peminjam[i].namaPeminjam = replace2Underscore(peminjam[i].namaPeminjam);
        outfile << i+1 <<" "<< peminjam[i].namaPeminjam<<" "<< peminjam[i].judulBuku << endl;
    }
    peminjam[nomor].index = 0;
    outfile << peminjam[nomor].index; 
    outfile.close();

}

