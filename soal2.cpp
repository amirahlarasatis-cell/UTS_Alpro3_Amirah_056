#include <iostream>
#include <string>
using namespace std;

int main() {
    string kode;
    int jamKeluar;
    
    cout << "Masukkan kode parkir digital (10 digit): ";
    cin >> kode;
    
    cout << "Masukkan jam keluar (format HHMM): ";
    cin >> jamKeluar;
    

  
    int jenisKode = (kode[0] - '0') * 10 + (kode[1] - '0');
    
    int jamMasukInt = (kode[2] - '0') * 1000 + 
                      (kode[3] - '0') * 100 + 
                      (kode[4] - '0') * 10 + 
                      (kode[5] - '0');
    

    int lokasi = (kode[6] - '0') * 1000 + 
                 (kode[7] - '0') * 100 + 
                 (kode[8] - '0') * 10 + 
                 (kode[9] - '0');
    
    
    string jenisKendaraan = "";
    int tarifPertama = 0;
    int tarifBerikutnya = 0;
    
    if (jenisKode == 10) {
        jenisKendaraan = "Mobil pribadi";
        tarifPertama = 5000;
        tarifBerikutnya = 3000;
    }
    else if (jenisKode == 20) {
        jenisKendaraan = "Motor";
        tarifPertama = 3000;
        tarifBerikutnya = 2000;
    }
    else if (jenisKode == 30) {
        jenisKendaraan = "Bus";
        tarifPertama = 10000;
        tarifBerikutnya = 7000;
    }
    
    
    
    int jamM = jamMasukInt / 100;       
    int menitM = jamMasukInt % 100;     
    int jamK = jamKeluar / 100;         
    int menitK = jamKeluar % 100;       
    

    int totalMenitMasuk = jamM * 60 + menitM;
    int totalMenitKeluar = jamK * 60 + menitK;
    int selisihMenit = totalMenitKeluar - totalMenitMasuk;
    

    int durasiJam = selisihMenit / 60;
    if (selisihMenit % 60 > 0) {
        durasiJam = durasiJam + 1;
    }
    
    
    
    int totalBiaya = 0;
    
    if (durasiJam >= 1) {
        totalBiaya = tarifPertama;                    
        
        int jamSisa = durasiJam - 1;                   
        if (jamSisa > 0) {
            totalBiaya = totalBiaya + (jamSisa * tarifBerikutnya);  
        }
    }
    
   

  
    cout << endl;
    cout << "--- Ringkasan Parkir ---" << endl;
    cout << "Jenis kendaraan: " << jenisKendaraan << endl;
    

    cout << "Waktu masuk: ";
    if (jamM < 10) { cout << "0"; }
    cout << jamM << ":";
    if (menitM < 10) { cout << "0"; }
    cout << menitM << endl;
    

    cout << "Waktu keluar: ";
    if (jamK < 10) { cout << "0"; }
    cout << jamK << ":";
    if (menitK < 10) { cout << "0"; }
    cout << menitK << endl;
    
    cout << "Durasi parkir: " << durasiJam << " jam" << endl;
    cout << "Lokasi parkir: " << lokasi << endl;
    cout << "Total biaya: Rp " << totalBiaya << endl;
    
    return 0;
}
/*
KODE PARKIR (10 digit): 2014506325 (contoh)

Digit 1-2 → jenis kendaraan:
10 = Mobil pribadi
20 = Motor  
30 = Bus

Digit 3-6 → waktu masuk format HHMM (misal 1450 = jam 14:50)

Digit 7-10 → nomor lokasi parkir (cuma dicetak, ga dipake buat hitung)


Tarif parkir:

Mobil: jam pertama Rp5000, jam berikutnya Rp3000 per jam
Motor: jam pertama Rp3000, jam berikutnya Rp2000 per jam
Bus: jam pertama Rp10000, jam berikutnya Rp7000 per jam


alur program:

1. Input kode parkir 10 digit dan jam keluar (format HHMM)

2. Pecah kode jadi 3 bagian pake konversi char ke int manual:
- Digit 1-2 → jenis kendaraan (buat tentuin tarif)
- Digit 3-6 → jam masuk (dalam format angka HHMM)
- Digit 7-10 → nomor lokasi

3. Tentuin nama kendaraan dan tarif sesuai kode jenisnya

4. Ubah jam masuk dan jam keluar dari format HHMM ke total menit:
Misal 1430 → (14 × 60) + 30 = 870 menit
Ini biar gampang ngitung selisihnya

5. Hitung selisih waktu (keluar - masuk) dalam menit, lalu konversi ke jam.
Kalau ada sisa menitnya (ga bulat), dibuletin ke atas (+1 jam).
Contoh: 3 jam 15 menit dihitung 4 jam. Ini standar tempat parkir pada umumnya.

6. Hitung biaya:
Jam pertama bayar tarif pertama, sisanya (kalau ada) dikali tarif berikutnya.
Contoh motor parkir 4 jam: 3000 + (3 × 2000) = 9000

7. Cetak ringkasan lengkap: jenis kendaraan, waktu masuk, waktu keluar,
durasi, lokasi, dan total biaya.


CONTOH 
Input:
Kode: 2014506325
Jam keluar: 1850

Proses:
- Jenis: 20 → Motor
- Jam masuk: 1450 → jam 14, menit 50
- Jam keluar: 1850 → jam 18, menit 50
- Selisih: (18×60+50) - (14×60+50) = 1130 - 890 = 240 menit = 4 jam
- Biaya: 3000 + (3 × 2000) = 9000

Output:
Jenis kendaraan: Motor
Waktu masuk: 14:50
Waktu keluar: 18:50
Durasi parkir: 4 jam
Lokasi parkir: 6325
Total biaya: Rp 9000

*/
