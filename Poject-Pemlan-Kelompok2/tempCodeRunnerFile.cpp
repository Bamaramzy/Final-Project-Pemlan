#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream myFile;
    string output, buffer;
    bool isData = false;
    int no;
    string nama;

    myFile.open("data.txt");

    while (!isData && getline(myFile, buffer))
    {
        getline(myFile, buffer);
        output.append("\n" + buffer);
        if (buffer == "data")
        {
            isData = true;
        }
    }

    cout << output << endl;

    getline(myFile, buffer);
    int jumlah_data = 0;
    while (!myFile.eof())
    {
        myFile >> no;
        myFile >> nama;

        cout << no << "\t" << nama << endl;
    }
    cout << "jumlah data = " << jumlah_data << endl;

    myFile.close();

    cin.get();
    return 0;
}
