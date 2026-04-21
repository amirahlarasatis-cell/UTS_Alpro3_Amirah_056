#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, poinA = 0, poinB = 0, streakA = 0, streakB = 0;
    string hasil;
    
    cout<< "jumlah babak: ";
    cin >> n;
    
    cout<<"hasil: ";
    while (cin >> hasil && (int)hasil.length() != n) {
        cout << "Input salah! Harus " << n << " karakter. Ulangi: ";
    }
    
    for (int i = 0; i < n; i++) {
        char c = hasil[i];
        
        if (c == 'A' || c == 'a') {
            poinA += 3 + (streakA++ % 3 == 2 ? 2 : 0);
            streakB = 0;
            
        } else if (c == 'B' || c == 'b') {
            poinB += 3 + (streakB++ % 3 == 2 ? 2 : 0);
            streakA = 0;
            
        } else { 
            poinA++;
            poinB++;
            streakA = streakB = 0;
        }
    }
    
    cout << "Poin A: " << poinA << endl;
    cout << "Poin B: " << poinB << endl;
    
    cout << (poinA > poinB ? "Pemenangnya adalah pemain A" :
             poinB > poinA ? "Pemenangnya adalah pemain B" : 
             "Hasil Pertandingan Seri!") << endl;
    
    return 0;
}

/*


Input:
- N = jumlah babak
- String hasil (case insensitive, panjang harus pas N)

Aturan poin:
- A/a atau B/b menang : +3 poin
- C/c (seri)          : masing-masing +1 poin
- Bonus               : tiap 3 kemenangan beruntun, tambah +2

pake logika or:
- `c == 'A' || c == 'a'` → benar kalau huruf A besar atau kecil
- `c == 'B' || c == 'b'` → benar kalau huruf B besar atau kecil  
- else                  → otomatis C/c (seri)

Jadi input "ABaaAbb", "abAAABB", "AbAaAbB" semua kebaca sama saja.

Cara kerja:

1. Input N, lalu loop input string sampai panjangnya pas N.
   Kalau kurang/lebih, minta ulang terus.

2. Loop proses tiap karakter:
   - Cek pakai OR biar case insensitive tanpa konversi
   - Hitung poin + bonus dalam 1 baris
   
   streak++ % 3 == 2 artinya streak ke-3,6,9,...
   (pas increment, nilai jadi 3,4,5,... dan 5%3=2)

3. Output

pada test case 1:
jumlah babak: 7
hasil: aBaAaBb (unsensitive case)

Proses:
'a'→A menang, A=3, streakA=1
'B'→B menang, B=3, streakB=1
'a'→A menang, A=6, streakA=1
'A'→A menang, A=9, streakA=2
'a'→A menang, A=14+2bonus, streakA=3
'B'→B menang, B=6, streakB=1
'b'→B menang, B=9, streakB=2

Output:
Poin A: 14
Poin B: 9
Pemenangnya adalah pemain A

*/
