#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

void Penjumlahan(float angka1,float angka2);
void Pengurangan(float angka1,float angka2);
void Perkalian(float angka1,float angka2);
void Pembagian(float angka1,float angka2);
void modulus(int angka1,int angka2);

int main(){
    int a, b, menu;
    float c, d, hasil;
    char kembali;


    do{
        printf("\t\t\t__________________________________________\n");
        printf("\t\t\t|========================================|\n");
        printf("\t\t\t|             SELAMAT DATANG             |\n");
        printf("\t\t\t|========================================|\n");
        printf("\t\t\t|      PROGRAM KALKULATOR SEDERHANA      |\n");
        printf("\t\t\t|========================================|\n");
        printf("\t\t\t|               1. Penjumlahan           |\n");
        printf("\t\t\t|               2. Pengurangan           |\n");
        printf("\t\t\t|               3. Perkalian             |\n");
        printf("\t\t\t|               4. Pembagian             |\n");
        printf("\t\t\t|               5. Modulus               |\n");
        printf("\t\t\t==========================================\n\n");
        printf("Pilih menu : ");
        scanf("%d", &menu);
        system("cls");
    switch(menu){
        case 1: Penjumlahan(a, b); break;
        case 2: Pengurangan(a, b); break;
        case 3: Perkalian(a, b); break;
        case 4: Pembagian(c, b); break;
        case 5: Modulus(c, d); break;
    default:
        printf("Menu yang ada pilih tidak sesuai!!\n\n");
        getchar();
        kembali = 'y';
        continue;
    }
    printf("Apakah anda ingin mengulang(y/t)?\n");
    printf("\ty. ya\n");
    printf("\tt. tidak\n");
    printf("Silahkan pilih : ");
    scanf("%s",&kembali);
    system("cls");

    }while(kembali=='y'||kembali=='Y');
    printf("\n\t==========================================");
    printf("\n\tTerimakasih telah menggunakan program kami");
    printf("\n\t==========================================\n\n\n");
    return 0;
}

void Penjumlahan(float angka1, float angka2){
    system("cls");
    printf("\nPENJUMLAHAN\n");
    printf("____\n");
    float hasil;
    float cekAngka1, cekAngka2;

    printf("\t\t\t Masukkan angka pertama : ");
    cekAngka1 = scanf("%f", &angka1);
    printf("\t\t\t Masukkan angka kedua   : ");
    cekAngka2 = scanf("%f", &angka2);

    if(cekAngka1 == 0 || cekAngka2 ==0){
        fflush(stdin);
        printf("\n\t\t\t Tekan tombol apa saja untuk ulang-->");
        getchar();
        Penjumlahan(angka1,angka2);
    }else{
        hasil = angka1 + angka2;
        printf("\n\t\t\t %.1f", angka1);
        printf("\n\t\t\t %.1f", angka2);
        printf("\n\t\t\t --------------- +\n");
        printf("\n\t\t\t %.1f", hasil);
        printf("\n\t\t\t Hasil:\t %.1f\n\n", hasil);
    }
}

void Pengurangan(float angka1, float angka2){
    system("cls");
    printf("PENGURANGAN\n");
    printf("____\n");

    float hasil;
    float cekAngka1, cekAngka2;

    printf("\t\t\t Masukkan angka pertama : ");
    cekAngka1 = scanf("%f", &angka1);
    printf("\t\t\t Masukkan angka kedua   : ");
    cekAngka2 = scanf("%f", &angka2);

    if(cekAngka1 == 0 || cekAngka2 ==0){
        fflush(stdin);
        printf("\n\t\t\t Tekan tombol apa saja untuk ulang-->");
        getchar();
        Penjumlahan(angka1,angka2);
    }else{
        hasil = angka1 - angka2;
        printf("\n\t\t\t %.1f", angka1);
        printf("\n\t\t\t %.1f", angka2);
        printf("\n\t\t\t --------------- +\n");
        printf("\n\t\t\t %.1f", hasil);
        printf("\n\t\t\t Hasil:\t %.1f\n\n", hasil);
    }
}

void Perkalian(float angka1, float angka2){
    system("cls");
    printf("PERKALIAN\n");
    printf("____\n");

    float hasil;
    float cekAngka1, cekAngka2;

    printf("\t\t\t Masukkan angka pertama : ");
    cekAngka1 = scanf("%f", &angka1);
    printf("\n\t\t\t Masukkan angka kedua   : ");
    cekAngka2 = scanf("%f", &angka2);

    if(cekAngka1 == 0 || cekAngka2 ==0){
        fflush(stdin);
        printf("\n\t Tekan tombol apa saja untuk ulang-->");
        getchar();
        Penjumlahan(angka1,angka2);
    }else{
        hasil = angka1 * angka2;
        printf("\n\t\t\t %.1f", angka1);
        printf("\n\t\t\t %.1f", angka2);
        printf("\n\t\t\t --------------- +\n");
        printf("\n\t\t\t %.1f", hasil);
        printf("\n\t\t\t Hasil:\t %.1f\n\n", hasil);
    }
}

void Pembagian(float angka1, float angka2){
    system("cls");
    printf("PEMBAGIAN\n");
    printf("____\n");

    float hasil;
    float cekAngka1, cekAngka2;

    printf("\t\t\t Masukkan angka pertama : ");
    cekAngka1 = scanf("%f", &angka1);
    printf("\t\t\t Masukkan angka kedua   : ");
    cekAngka2 = scanf("%f", &angka2);

    if(cekAngka1 == 0 || cekAngka2 ==0){
        fflush(stdin);
        printf("\n\t\t\t Tekan tombol apa saja untuk ulang-->");
        getchar();
        Penjumlahan(angka1,angka2);
    }else{
        hasil = angka1 / angka2;
        printf("\n\t\t\t %.1f", angka1);
        printf("\n\t\t\t %.1f", angka2);
        printf("\n\t\t\t --------------- +\n");
        printf("\n\t\t\t %.1f", hasil);
        printf("\n\t\t\t Hasil:\t %.1f\n\n", hasil);
    }
}
void Modulus(int angka1, int angka2){
    system("cls");
    printf("MODULUS\n");
    printf("____\n");

    int hasil;
    int cekAngka1, cekAngka2;

    printf("\t\t\t Masukkan angka pertama : ");
    cekAngka1 = scanf("%d", &angka1);
    printf("\n\t\t\t Masukkan angka kedua   : ");
    cekAngka2 = scanf("%d", &angka2);

    if(cekAngka1 == 1 || cekAngka2 ==1){
        fflush(stdin);
        printf("\n\t\t\t Tekan tombol apa saja untuk ulang-->");
        getchar();
        Penjumlahan(angka1,angka2);
    }else{
        hasil = angka1 % angka2;
        printf("\n\t\t\t %d", angka1);
        printf("\n\t\t\t %d", angka2);
        printf("\n\t\t\t --------------- +\n");
        printf("\n\t\t\t %d", hasil);
        printf("\n\t\t\t Hasil:\t %d\n\n", hasil);
    }
}
