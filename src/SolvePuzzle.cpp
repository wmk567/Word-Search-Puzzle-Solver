#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <windows.h>
using namespace std;

int main(int argc, char* argv[]){
    using std::chrono::steady_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;
    using std::chrono::nanoseconds;
    
    string namafile;
    namafile = argv[1];
    ifstream file_matriks(namafile); // membaca file untuk mencari baris, kolom, jumlah kata
    ifstream file_matriks2(namafile); // membaca file untuk dimasukkan ke program
    string baris1;
    string baristemp;
    string baristemp2;
    int col;
    int temp;
    int wordsearch = 0;
    int row = 0;
    int jumlahhuruf = 0;
    int isihuruf;

    getline(file_matriks,baristemp);
    temp = baristemp.length();
    col = (baristemp.length()+1)/2;
    if (temp != 0){
        row++;
    }
    
    while(temp != 0){
        getline(file_matriks,baristemp);
        temp = baristemp.length();
        if (temp != 0){
            row++;
        }
    }
    cout << "jumlah kolom : " << col << "\n";
    cout << "jumlah baris : " << row << "\n";

    getline(file_matriks,baristemp);
    temp = baristemp.length();
    if (temp != 0){
        wordsearch++;
    }
    while(temp!=0){
        getline(file_matriks,baristemp);
        temp = baristemp.length();
        if (temp != 0){
            wordsearch++;
        }
    }

    cout << "jumlah kata  : " << wordsearch << "\n";

    char **data1;
    data1 = new char*[row];
    for (int temp2 = 0; temp2<row; temp2++){
        data1[temp2] = new char[col];
    }

    string *data2;
    data2 = new string[wordsearch];

    int **data3;
    data3 = new int*[row];
    for (int temp2_2 = 0; temp2_2<row; temp2_2++){
        data3[temp2_2] = new int[col];
    }

    for(int temp3_2 = 0; temp3_2<row; temp3_2++){
        for(int temp4_2 = 0; temp4_2<col; temp4_2++){
            data3[temp3_2][temp4_2] = 15;
        }
    }

    int tempcol;

    for(int temp3 = 0; temp3<row; temp3++){
        getline(file_matriks2,baristemp2);
        tempcol = 0;
        for(int temp4 = 0; temp4<baristemp2.length(); temp4++){
            if (isspace(baristemp2[temp4]) == false){
                data1[temp3][tempcol] = baristemp2[temp4];
                tempcol++;
            }
        }
    }

    getline(file_matriks2,baristemp2);

    for(int temp5 = 0; temp5<wordsearch; temp5++){
        getline(file_matriks2,baristemp2);
        data2[temp5] = baristemp2;
        jumlahhuruf += baristemp2.length();
    }

    cout << "jumlah huruf : " << jumlahhuruf << "\n";
    
    for (int x = 0; x < row; x++){
        for (int y = 0; y<col; y++){
            cout<<data1[x][y]<<" ";
        }
        cout<<"\n";
    }

    for (int z=0; z<wordsearch; z++){
        cout<<data2[z]<<"\n";
    }

    cout << "\n";

    string simpan;
    int found; // Digunakan untuk membandingkan huruf
    int foundfinal; // Digunakan untuk mengecek jika kata sudah ditemukan
    int totalstep = 0;
    int k = 35;
    int foundcount = 0;
    int word_id; // Digunakan untuk menyimpan huruf berapa yang diperiksa

    auto t1 = steady_clock::now();
    cout << "Hasil Pencarian : ";
    for(int data_id = 0; data_id<wordsearch; data_id++){
        simpan = data2[data_id];

        // mencari kata horizontal dari kiri ke kanan

        for(int puzzle_id_y = 0; puzzle_id_y<row; puzzle_id_y++){
            for(int puzzle_id_x = 0; puzzle_id_x<col-simpan.length()+1; puzzle_id_x++){
                found = 1;
                word_id = 0;
                while(word_id<simpan.length()){
                    totalstep++;
                    if(simpan[word_id]!=data1[puzzle_id_y][puzzle_id_x+word_id]){
                        found = 0;
                    }
                    word_id++;
                }
                if(found==1){
                    for(int word_id_2=0; word_id_2<simpan.length(); word_id_2++){
                        data3[puzzle_id_y][puzzle_id_x+word_id_2] = k;
                    }
                    foundcount++;
                    k+=8;
                    if (k > 230){
                        k = 64;
                    }
                }
            }
        }

        // mencari kata horizontal dari kanan ke kiri
        for(int puzzle_id_y = 0; puzzle_id_y<row; puzzle_id_y++){
            for(int puzzle_id_x = col-1; puzzle_id_x>=simpan.length()-1; puzzle_id_x--){
                found = 1;
                word_id = 0;
                while(word_id<simpan.length()){
                    totalstep++;
                    if(simpan[word_id]!=data1[puzzle_id_y][puzzle_id_x-word_id]){
                        found = 0;
                    }
                    word_id++;
                }
                if(found==1){
                    for(int word_id_2=0; word_id_2<simpan.length(); word_id_2++){
                        data3[puzzle_id_y][puzzle_id_x-word_id_2] = k;
                    }
                    foundcount++;
                    k+=8;
                    if (k > 230){
                        k = 64;
                    }
                }
            }
        }

        // mencari kata vertikal dari atas ke bawah
        for(int puzzle_id_y = 0; puzzle_id_y<row-simpan.length()+1; puzzle_id_y++){
            for(int puzzle_id_x = 0; puzzle_id_x<col; puzzle_id_x++){
                found = 1;
                word_id = 0;
                while(word_id<simpan.length()){
                    totalstep++;
                    if(simpan[word_id]!=data1[puzzle_id_y+word_id][puzzle_id_x]){
                        found = 0;
                    }
                    word_id++;
                }
                if(found==1){
                    for(int word_id_2=0; word_id_2<simpan.length(); word_id_2++){
                        data3[puzzle_id_y+word_id_2][puzzle_id_x] = k;
                    }
                    foundcount++;
                    k+=8;
                    if (k > 230){
                        k = 64;
                    }
                }
            }
        }

        // mencari kata vertikal dari bawah ke atas
        for(int puzzle_id_y = row-1; puzzle_id_y>=simpan.length()-1; puzzle_id_y--){
            for(int puzzle_id_x = 0; puzzle_id_x<col; puzzle_id_x++){
                found = 1;
                word_id = 0;
                while(word_id<simpan.length()){
                    totalstep++;
                    if(simpan[word_id]!=data1[puzzle_id_y-word_id][puzzle_id_x]){
                        found = 0;
                    }
                    word_id++;
                }
                if(found==1){
                    for(int word_id_2=0; word_id_2<simpan.length(); word_id_2++){
                        data3[puzzle_id_y-word_id_2][puzzle_id_x] = k;
                    }
                    foundcount++;
                    k+=8;
                    if (k > 230){
                        k = 64;
                    }
                }
            }
        }

        // mencari kata diagonal dari kiri atas ke kanan bawah
        for(int puzzle_id_y = 0; puzzle_id_y<row-simpan.length()+1; puzzle_id_y++){
            for(int puzzle_id_x = 0; puzzle_id_x<col-simpan.length()+1; puzzle_id_x++){
                found = 1;
                word_id = 0;
                while(word_id<simpan.length()){
                    totalstep++;
                    if(simpan[word_id]!=data1[puzzle_id_y+word_id][puzzle_id_x+word_id]){
                        found = 0;
                    }
                    word_id++;
                }
                if(found==1){
                    for(int word_id_2=0; word_id_2<simpan.length(); word_id_2++){
                        data3[puzzle_id_y+word_id_2][puzzle_id_x+word_id_2] = k;
                    }
                    foundcount++;
                    k+=8;
                    if (k > 230){
                        k = 64;
                    }
                }
            }
        }

        // mencari kata diagonal dari kanan atas ke kiri bawah
        for(int puzzle_id_y = 0; puzzle_id_y<row-simpan.length()+1; puzzle_id_y++){
            for(int puzzle_id_x = col-1; puzzle_id_x>=simpan.length()-1; puzzle_id_x--){
                found = 1;
                word_id = 0;
                while(word_id<simpan.length()){
                    totalstep++;
                    if(simpan[word_id]!=data1[puzzle_id_y+word_id][puzzle_id_x-word_id]){
                        found = 0;
                    }
                    word_id++;
                }
                if(found==1){
                    for(int word_id_2=0; word_id_2<simpan.length(); word_id_2++){
                        data3[puzzle_id_y+word_id_2][puzzle_id_x-word_id_2] = k;
                    }
                    foundcount++;
                    k+=8;
                    if (k > 230){
                        k = 64;
                    }
                }
            }
        }

        // mencari kata diagonal dari kiri bawah ke kanan atas
        for(int puzzle_id_y = row-1; puzzle_id_y>=simpan.length()-1; puzzle_id_y--){
            for(int puzzle_id_x = 0; puzzle_id_x<col-simpan.length()+1; puzzle_id_x++){
                found = 1;
                word_id = 0;
                while(word_id<simpan.length()){
                    totalstep++;
                    if(simpan[word_id]!=data1[puzzle_id_y-word_id][puzzle_id_x+word_id]){
                        found = 0;
                    }
                    word_id++;
                }
                if(found==1){
                    for(int word_id_2=0; word_id_2<simpan.length(); word_id_2++){
                        data3[puzzle_id_y-word_id_2][puzzle_id_x+word_id_2] = k;
                    }
                    foundcount++;
                    k+=8;
                    if (k > 230){
                        k = 64;
                    }
                }
            }
        }
        
        // mencari kata diagonal dari kanan bawah ke kiri atas
        for(int puzzle_id_y = row-1; puzzle_id_y>=simpan.length()-1; puzzle_id_y--){
            for(int puzzle_id_x = col-1; puzzle_id_x>=simpan.length()-1; puzzle_id_x--){
                found = 1;
                word_id = 0;
                while(word_id<simpan.length()){
                    totalstep++;
                    if(simpan[word_id]!=data1[puzzle_id_y-word_id][puzzle_id_x-word_id]){
                        found = 0;
                    }
                    word_id++;
                }
                if(found==1){
                    for(int word_id_2=0; word_id_2<simpan.length(); word_id_2++){
                        data3[puzzle_id_y-word_id_2][puzzle_id_x-word_id_2] = k;
                    }
                    foundcount++;
                    k+=8;
                    if (k > 230){
                        k = 64;
                    }
                }
            }
        }
    }
    
    auto t2 = steady_clock::now();

    cout << "\n";
    for(int temp_final_1 = 0; temp_final_1 < row; temp_final_1++){
        for(int temp_final_2 = 0; temp_final_2 < col; temp_final_2++){
            printf("%c[38;5;%dm%c ", 0x1B, data3[temp_final_1][temp_final_2], data1[temp_final_1][temp_final_2]);
        }
        cout << "\n";
    }

    
    auto time = duration_cast<nanoseconds>(t2-t1);
    cout << "\e[37mjumlah kata yang ditemukan : " << foundcount << "\n";
    printf("%c[%dmwaktu yang dibutuhkan : %d ns\n", 0x1B, 37, time.count());
    cout << "langkah yang dibutuhkan : " << totalstep << "\n";
    cout << "perbandingan langkah dengan jumlah huruf : " << totalstep / jumlahhuruf << "\n";

}