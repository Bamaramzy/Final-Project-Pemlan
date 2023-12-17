void tukar(Buku &a, Buku &b) {
    Buku temp = a;
    a = b;
    b = temp;
}

int partisi(Buku arr[], int low, int high, int pilihan) {
    string pivot;
    switch (pilihan) {
        case 1: // Judul Buku
            pivot = arr[high].judulBuku;
            break;
        case 2: // Penulis
            pivot = arr[high].penulis;
            break;
        case 3: // Tahun Terbit
            pivot = to_string(arr[high].tahunTerbit);
            break;
    }

    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        string current;
        switch (pilihan) {
            case 1: // Judul Buku
                current = arr[j].judulBuku;
                break;
            case 2: // Penulis
                current = arr[j].penulis;
                break;
            case 3: // Tahun Terbit
                current = to_string(arr[j].tahunTerbit);
                break;
        }

        if (current <= pivot) {
            i++;
            tukar(arr[i], arr[j]);
        }
    }
    tukar(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(Buku arr[], int low, int high, int pilihan) {
    if (low < high) {
        int pi = partisi(arr, low, high, pilihan);
        quickSort(arr, low, pi - 1, pilihan);
        quickSort(arr, pi + 1, high, pilihan);
    }
}
