#include <iostream>
#include <string>
using namespace std;

int main() {
    string nomor;
    
    cout << "Masukkan nomor kartu digital: ";
    cin >> nomor;
    
    int panjang = nomor.length();
    string tipe = "";
    bool formatValid = false;
    

    if (panjang == 14 && nomor[0] == '6' && nomor[1] == '5') {
        tipe = "NUSANTARA";
        formatValid = true;
    }
    else if (panjang == 16) {
        if ((nomor[0] == '7' && nomor[1] == '7') || (nomor[0] == '7' && nomor[1] == '8')) {
            tipe = "GARUDA";
            formatValid = true;
        }
    }
    else if (panjang == 15 && nomor[0] == '9' && nomor[1] == '1') {
        tipe = "MERDEKA";
        formatValid = true;
    }
    

    if (!formatValid) {
        cout << "Tipe kartu: UNKNOWN" << endl;
        cout << "Nomor kartu TIDAK VALID." << endl;
        return 0;
    }
    
    cout << "Tipe kartu: " << tipe << endl;
    

    int total = 0;
    bool ganda = false;  
    

      for (int i = panjang - 1; i >= 0; i--) {
        int digit = nomor[i] - '0';  
        
        if (ganda) {
            digit = digit * 2;
            

                if (digit > 9) {
                digit = (digit / 10) + (digit % 10);
            }
        }
        
        total = total + digit;
        ganda = !ganda;  
    }
    

      if (total % 10 == 0) {
        cout << "Nomor kartu VALID." << endl;
    } else {
        cout << "Nomor kartu TIDAK VALID." << endl;
    }
    
    return 0;
}
