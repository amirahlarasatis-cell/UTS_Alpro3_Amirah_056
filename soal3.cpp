#include <iostream>
#include <string>
using namespace std;

int main() {
    string kode;
    int hari, pelanggan, kelipatan, poin = 0;
    
    string namaHari[] = {"", "Hari Kerja", "Akhir Pekan", "Hari Libur Nasional"};
    string namaPelanggan[] = {"", "Biasa", "Silver", "Gold"};
    
    int tabelPoin[4][4] = {
        {0, 0, 0, 0},
        {0, 1, 2, 3},
        {0, 2, 3, 5},
        {0, 3, 5, 7}
    };
    
    cout << "Masukkan kode transaksi (8 digit): ";
    cin >> kode;
    
    if (kode.length() != 8) {
        cout << "Error: Kode harus 8 digit!
";
        return 1;
    }
    
    
    hari = (kode[0] - '0') * 10 + (kode[1] - '0');
    pelanggan = (kode[2] - '0') * 10 + (kode[3] - '0');
    

    kelipatan = (kode[4] - '0') * 1000 + 
                (kode[5] - '0') * 100 + 
                (kode[6] - '0') * 10 + 
                (kode[7] - '0');
    
    if (hari < 1 || hari > 3 || pelanggan < 1 || pelanggan > 3) {
        cout << "Error: Kode tidak valid!
";
        return 1;
    }
    
    poin = kelipatan * tabelPoin[hari][pelanggan];
    
    cout << "
Jenis Hari: " << namaHari[hari] << endl;
    cout << "Jenis Pelanggan: " << namaPelanggan[pelanggan] << endl;
    cout << "Jumlah Belanja: Rp " << (long long)kelipatan * 100000 << endl;
    cout << "Total Poin: " << poin << endl;
    
    return 0;
}

/*


Input kode 8 digit dipotong jadi 3 bagian:
- Digit 1-2 → jenis hari (01=kerja, 02=weekend, 03=libur nasional)
- Digit 3-4 → jenis member (01=biasa, 02=silver, 03=gold)
- Digit 5-8 → jumlah belanja dalam kelipatan Rp100.000

Konversi char ke int secara manual:
Setiap karakter angka di-kurangi karakter '0' (ASCII 48).
Contoh: '3' - '0' = 51 - 48 = 3

Untuk 2 digit: (digit_pertama × 10) + digit_kedua
Untuk 4 digit: (d1×1000) + (d2×100) + (d3×10) + d4

Contoh: 03020115
→ hari = ('0'-'0')×10 + ('3'-'0') = 0×10 + 3 = 3 (libur)
→ pelanggan = ('0'-'0')×10 + ('2'-'0') = 0×10 + 2 = 2 (silver)
→ kelipatan = 0×1000 + 1×100 + 1×10 + 5 = 115

Rate poin per 100rb:
- Hari kerja: biasa=1, silver=2, gold=3
- Akhir pekan: biasa=2, silver=3, gold=5
- Libur nasional: biasa=3, silver=5, gold=7

Rumus akhir: kelipatan × rate = total poin
Contoh: 115 × 5 = 575 poin

*/
