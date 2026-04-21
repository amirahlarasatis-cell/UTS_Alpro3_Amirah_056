#include <iostream>
#include <string>
using namespace std;

int main() {
    string kode;
    int hari, pelanggan, kelipatan, poin = 0;
    
    cout << "Masukkan kode transaksi (8 digit): ";
    cin >> kode;
    
    if ((int)kode.length() != 8) {
        cout << "Error: Kode harus 8 digit!" << endl;
        return 1;
    }
    
    hari = (kode[0] - '0') * 10 + (kode[1] - '0');
    pelanggan = (kode[2] - '0') * 10 + (kode[3] - '0');
    kelipatan = (kode[4] - '0') * 1000 + (kode[5] - '0') * 100 + 
                (kode[6] - '0') * 10 + (kode[7] - '0');
    
    if (hari < 1 || hari > 3 || pelanggan < 1 || pelanggan > 3) {
        cout << "Kode tidak valid!" << endl;
        return 1;

    }
    
    cout << "Jenis Hari: ";
    if (hari == 1) cout << "Hari Kerja";
    else if (hari == 2) cout << "Akhir Pekan";
    else cout << "Hari Libur Nasional";
    cout << endl;
    
    cout << "Jenis Pelanggan: ";
    if (pelanggan == 1) cout << "Biasa";
    else if (pelanggan == 2) cout << "Silver";
    else cout << "Gold";
    cout << endl;
    
    cout << "Jumlah Belanja: Rp " << (long long)kelipatan * 100000 << endl;
    
    // Hitung poin dengan nested if-else (tanpa array)
    if (hari == 1) {
        if (pelanggan == 1) poin = kelipatan * 1;
        else if (pelanggan == 2) poin = kelipatan * 2;
        else poin = kelipatan * 3;
    } else if (hari == 2) {
        if (pelanggan == 1) poin = kelipatan * 2;
        else if (pelanggan == 2) poin = kelipatan * 3;
        else poin = kelipatan * 5;
    } else {
        if (pelanggan == 1) poin = kelipatan * 3;
        else if (pelanggan == 2) poin = kelipatan * 5;
        else poin = kelipatan * 7;
    }
    
    cout << "Total Poin: " << poin << endl;
    
    return 0;
}

/*

input contoh: 03020115
- Digit 1-2 → jenis hari (01=kerja, 02=weekend, 03=libur nasional)
- Digit 3-4 → jenis pelanggan (01=biasa, 02=silver, 03=gold)
- Digit 5-8 → jumlah belanja dalam kelipatan Rp100.000

Cara kerja:

1. Input kode 8 digit, validasi panjangnya harus pas 8 karakter

2. Pecah kode jadi 3 bagian dengan konversi manual (char ke int):
   Setiap angka dikurangi karakter '0' (ASCII 48), jadi '3'-'0' = 3
   Untuk 2 digit: (digit1 × 10) + digit2
   Untuk 4 digit: (d1×1000) + (d2×100) + (d3×10) + d4

3. Cek kode hari dan pelanggan (harus antara 1-3)

4. Tampilkan nama hari pakai if-else:
   1=Hari Kerja, 2=Akhir Pekan, 3=Hari Libur Nasional

5. Tampilkan nama pelanggan pakai if-else:
   1=Biasa, 2=Silver, 3=Gold

6. Hitung total poin dengan nested if-else berdasarkan kombinasi hari dan pelanggan:
   - Hari kerja: biasa=1, silver=2, gold=3 (poin per 100rb)
   - Akhir pekan: biasa=2, silver=3, gold=5
   - Libur nasional: biasa=3, silver=5, gold=7
   Rumus: kelipatan × rate = total poin

7. Tampilkan hasil lengkap
Contoh test case dari soal:
- 03020115 : Libur Nasional, Silver, Rp1.500.000, 75 poin
- 01030007 : Hari Kerja, Gold, Rp700.000, 21 poin
- 02018750 : Akhir Pekan, Biasa, Rp875.000.000, 17500 poin
*/
