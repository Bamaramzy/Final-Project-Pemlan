bool panjangnama(string nama){
    int panjang = nama.size();
    if (panjang < 4){
        cout<<"Nama terlalu pendek";
        return false;
    }
    else if (panjang > 50){
        cout<<"Nama terlalu panjang";
        return true;
    }
}
