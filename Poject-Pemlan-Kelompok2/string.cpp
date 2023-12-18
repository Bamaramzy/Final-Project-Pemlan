bool panjangnama(string nama){
    int panjang = nama.size();
    if (panjang < 4){
        cout<<"Nama terlalu pendek\n";
        system("pause");
        return false;
    }
    else if (panjang > 50){
        cout<<"Nama terlalu panjang\n";
        system("pause");
        return false;
    }
    else {
        return true;
    }
}

string replace2Underscore(string& S) {
    string s1, s2;
    char c1 = ' ';
    char c2 = '_';
    for (char c : S) {
        if (c == c1) {
            s1 += c2;
            s2 += c1;
        } else if (c == c2) {
            s1 += c1;
            s2 += c2;
        } else {
            s1 += c;
            s2 += c;
        }
    }
    return s1;
}

string replace2Space(string& S) {
    string s1, s2;
    char c1 = '_';
    char c2 = ' ';
    for (char c : S) {
        if (c == c1) {
            s1 += c2;
            s2 += c1;
        } else if (c == c2) {
            s1 += c1;
            s2 += c2;
        } else {
            s1 += c;
            s2 += c;
        }
    }
    return s1;
}
