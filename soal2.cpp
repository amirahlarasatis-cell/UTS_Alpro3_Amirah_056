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
