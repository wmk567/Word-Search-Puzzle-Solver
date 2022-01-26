# Tugas Kecil 1 IF2211 Strategi Algoritma
### Word Search Puzzle Solver Dengan Algoritma Brute Force

Dibuat Oleh : William Manuel Kurniawan
NIM : 13520020
Bahasa Pemrograman : C++

## Deskripsi

Program ini menyelesaikan sebuah word search puzzle yang dicatat dalam sebuah file .txt .
Program memiliki 2 versi, 1 menggunakan teknik heuristik dan yang lain tidak menggunakan teknik heuristik.

Kebutuhan : compiler C++ (direkomendasikan versi terbaru)

Untuk menjalankan program, file .cpp harus diubah menjadi file .exe dengan menjalankan perintah berikut :

```bash
g++ SolvePuzzle.cpp -o SolvePuzzle
g++ SolvePuzzle_Heuristic.cpp -o SolvePuzzle_Heuristic
```

Atau membuka folder bin yang memiliki file .exe yang dihasilkan dari perintah di atas.

Setelah file .exe disiapkan, program bisa dijalankan di terminal Windows dengan perintah berikut :

```bash
.\SolvePuzzle <nama file>
```

dan

```bash
.\SolvePuzzle_Heuristic <nama file>
```

Atau dapat dijalankan pada WSL dengan perintah berikut :
```bash
solvepuzzle.exe <nama file>
```

dan

```bash
solvepuzzle_heuristic.exe <nama file>
```

Bagian <nama file> dapat ditulis hanya sebagai <nama_file>.txt jika file .txt berada pada folder yang sama dengan file .exe . Jika file .txt berada di folder yang berbeda, maka lokasi file harus ditulis pada <nama file>.  

Agar file .txt dapat dibaca dengan benar, format penulisan file harus mengikuti contoh yang terdapat pada folder test dengan kata yang dicari dan puzzle dipisahkan dengan 1 baris kosong dan disisakan 1 baris kosong di bagian akhir file.

### Catatan Tambahan : Warna tidak keluar

Sebagian terminal tidak dapat mengeluarkan warna hasil dari word search puzzle atau belum diatur untuk mengeluarkan warna. Biasanya, warna dapat keluar dengan langsung pada terminal VS code tetapi tidak keluar pada Command Prompt dan Windows Powershell. Agar warna keluar pada Command Propt dan Windows Powershell, jalankan perintah berikut di Powershell:

```bash
Set-ItemProperty HKCU:\Console VirtualTerminalLevel -Type DWORD 1
```

Atau jalankan perintah berikut di Command Prompt:

```bash
reg add HKCU\Console /v VirtualTerminalLevel /t REG_DWORD /d 1
```