int searchJudulPeminjam(Peminjam peminjam[], int size, string search){
    int i = 0;
    while (i != size){
        if (peminjam[i].judulBuku == search){
            return i;
        }
        i++;
    }
}
