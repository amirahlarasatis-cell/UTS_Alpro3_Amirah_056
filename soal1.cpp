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
/*


step 1: cek kartu

Dari input nomornya, program liat panjangnya berapa digit dan angka awalnya apa.
- Kalau 14 digit & mulai dari 65 -> NUSANTARA
- Kalau 16 digit & mulai dari 77/78 -> GARUDA
- Kalau 15 digit & mulai dari 91 -> MERDEKA
- Ga cocok semua ->h UNKNOWN. langsung  invalid.

step 2: cek validitas



Ambil nomor dari belakang (digit terakhir), lalu gerak ke depan. Setiap digit selang-seling dikali 2
Digit paling belakang ga dikali, digit ke-2 dari belakang dikali 2, ke-3 ga dikali, ke-4 dikali lagi, dst.

kalau hasil kali 2-nya lebih dari 9 (misal 8×2=16), maka digit-digitnya dijumlahin jadi satu angka (16 → 1+6=7).
Terus semua hasilnya dijumlahin semuanya.
Kalau hasil akhirnya habis dibagi 10, berarti nomornya valid. Kalau ga habis dibagi 10, berarti ada yang salah.

bisa deteksi error, Karena algoritma ini dirancang supaya 1 perubahan digit bakal ngubah hasil total
jadi ga kelipatan 10 lagi. Jadi kesalahan ketik biasanya langsung ketahuan.

Contoh : misal ada nomor yang valid dan totalnya 60. 60 habis dibagi 10 maka valid.
Kalau kita ubah 1 digit jadi totalnya 61, ya ga habis dibagi 10 → langsung ketahau invalid.

Intinya cuma itung-itungan dari belakang ke depan, selang-seling dikali 2, trus cek apakah jumlahnya kelipatan 10.

*/
