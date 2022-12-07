#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#define phi 3.14


float luasPermukaan_tabung (float r, float t);
float volume_tabung (float r, float t);
int tampilan_tabung();
float luasPermukaan_bola (float r);
float volume_bola (float r);
int tampilan_bola();
float luasPermukaan_LimasSegiEmpat (float s, float t);
float volume_LimasSegiEmpat (float s, float t);
int tampilan_LimasSegiEmpat();
float luasPermukaan_PrismaSegitiga (float a, float t, float m, float t_prisma);
float volume_PrismaSegitiga (float a, float t, float t_prisma);
int tampilan_PrismaSegitiga();
float luasPermukaan_Kerucut (float r, float t);
float volume_Kerucut (float r, float t);
int tampilan_Kerucut();


int main()
{
    atas();
    menu();
return 0;
}

int atas (){

 printf("=======================================\n");
 printf("===        Program Menghitung       ===\n");
 printf("===     Luas Permukaan & Volume     ===\n");
 printf("===           Bangun Ruang          ===\n");
 printf("=== Praktikum Algoritma Pemrograman ===\n");
 printf("===           Kelompok 22           ===\n");
 printf("=======================================\n\n");

 return 0;
}

int menu (){
char nama[20];
char pilihan;
char kembali;


do{
    printf("=======================================\n");
    printf("====           ~MENU~             =====\n");
    printf("=======================================\n");
    printf(">>>>     [A] Tabung                <<<<\n");
    printf(">>>>     [B] Bola                  <<<<\n");
    printf(">>>>     [C] Limas Segi Empat      <<<<\n");
    printf(">>>>     [D] Prisma Segitiga       <<<<\n");
    printf(">>>>     [E] Kerucut               <<<<\n");
    printf(">>>>     [F] Selesai               <<<<\n");
    printf("=======================================\n\n");

 printf("Nama kamu : "); scanf("%[^\n]s", &nama);
 printf("Halo, %s Selamat Datang \n\n", nama);
 printf("Masukkan pilihan : "); scanf(" %c", &pilihan);
 printf("\n\n");

 if (pilihan=='A'){
        tampilan_tabung();
        exit(0);
 }
 else if (pilihan=='B'){
        tampilan_bola();
        exit(0);
 }
 else if (pilihan=='C'){
        tampilan_LimasSegiEmpat();
        exit(0);
 }
 else if (pilihan=='D'){
        tampilan_PrismaSegitiga();
        exit(0);
 }
 else if (pilihan=='E'){
        tampilan_Kerucut();
        exit(0);
 }
 else if (pilihan=='F'){
        printf("Thank You and See You <3 \n\n");
        exit(0);
 }
 else {
        system("cls");
        getchar();
        kembali='y';
        printf("Input Anda Salah \n");
        printf("Masukkan Ulang Input\n");
}
}while(kembali='y');
return 0;
}

float InputCek (){
    float pilih;
    char cek;

if (cek=scanf("%f%c", &pilih, &cek)!=2){
    fflush (stdin);
    printf("Input Salah");
    return InputCek();
}
else {
    if (pilih>=0){
        return pilih;
    }
    else {
        fflush(stdin);
        printf("Ulang Masukkan Pilihan:");
        return InputCek();
    }
}
return pilih;

}


float luasPermukaan_tabung (float r, float t){
    float hasil = 2*phi*r*(r+t);

    return hasil;
}

float volume_tabung (float r, float t){
    float hasil = phi*r*r*t;

    return hasil;
}

int tampilan_tabung(){
    float jari2, tinggi;
    char x;

    system("cls");
    printf("=======================================\n");
    printf("========         Tabung        ========\n");
    printf("========      Menghitung :     ========\n");
    printf(">>>>     [A] Luas Permukaan        <<<<\n");
    printf(">>>>     [B] Volume                <<<<\n");
    printf(">>>>     [C] Kembali ke menu       <<<<\n");
    printf("=======================================\n\n");


    printf("Masukkan pilihan kamu : "); scanf(" %c", &x);
        if (x=='A'){
            printf("Masukkan jari-jari tabung : "); jari2=InputCek();
            //scanf("%f", &jari2);
            printf("Masukkan tinggi tabung : "); tinggi=InputCek();
            //scanf(" %f", &tinggi);
            printf("Luas Permukaan Tabung : %f \n", luasPermukaan_tabung(jari2, tinggi));
        }
        else if (x=='B'){
            printf("Masukkan jari-jari tabung : "); scanf("%f", &jari2);
            printf("Masukkan tinggi tabung : "); scanf(" %f", &tinggi);
            printf("Volume Tabung : %f \n", volume_tabung(jari2, tinggi));
        }
        else if(x=='C'){
            system("cls");
            menu();
        }
        else {
            system("cls");\
            getchar();
            printf("Input Anda Salah \n");
            printf ("Tekan enter untuk ulang --> ");
            getchar();
            tampilan_tabung();
        }
    return 0;
}

float luasPermukaan_bola (float r){
    float hasil = 4*phi*r*r;

    return hasil;
}

float volume_bola (float r){
    float hasil = (4*phi*r*r*r)/3;

    return hasil;
}

int tampilan_bola(){
    float jari2;
    int ulang;
    char x;

    system("cls");
    printf("=======================================\n");
    printf("========         Bola          ========\n");
    printf("========      Menghitung :     ========\n");
    printf(">>>>     [A] Luas Permukaan        <<<<\n");
    printf(">>>>     [B] Volume                <<<<\n");
    printf(">>>>     [C] Kembali ke menu       <<<<\n");
    printf("=======================================\n\n");

    printf("Masukkan pilihan kamu : "); scanf(" %c", &x);
        if (x=='A'){
            printf("Masukkan jari-jari bola : "); jari2=InputCek();
            //scanf("%f", &jari2);
            printf("Luas Permukaan Bola : %f \n", luasPermukaan_bola(jari2));
        }
        else if (x=='B'){
            printf("Masukkan jari-jari bola : "); jari2=InputCek();
            //scanf("%f", &jari2);
            printf("Volume Bola : %f \n", volume_bola(jari2));
        }
         else if(x=='C'){
            system("cls");
            menu();
        }
        else {
            system("cls");
            getchar();
            printf("Input Anda Salah \n");
            printf ("Tekan enter untuk ulang --> ");
            getchar();
            tampilan_bola();
        }
    return 0;
}

float luasPermukaan_LimasSegiEmpat (float s, float t){
    float luas_alas = s*s;
    float t_segitiga = sqrt((t*t)+((s/2)*(s/2)));
    float luas_segitiga = (s*t_segitiga)/2 ;
    float hasil = luas_alas + (4*luas_segitiga);

    return hasil;
}

float volume_LimasSegiEmpat (float s, float t){
    float luas_alas = s*s;
    float hasil = (luas_alas*t)/3;

    return hasil;
}

int tampilan_LimasSegiEmpat(){
    float sisi, tinggi_limas;
    char x;

    system("cls");
    printf("=======================================\n");
    printf("========    Limas Segi Empat   ========\n");
    printf("========      Menghitung :     ========\n");
    printf(">>>>     [A] Luas Permukaan        <<<<\n");
    printf(">>>>     [B] Volume                <<<<\n");
    printf(">>>>     [C] Kembali ke menu       <<<<\n");
    printf("=======================================\n\n");

    printf("Masukkan pilihan kamu : "); scanf(" %c", &x);
        if (x=='A'){
            printf("Masukkan panjang segi empat : "); sisi=InputCek();
            //scanf("%f", &sisi);
            printf("Masukkan tinggi limas : "); tinggi_limas=InputCek();
            //scanf(" %f", &tinggi_limas);
            printf("Luas Permukaan Limas Segi Empat : %f \n", luasPermukaan_LimasSegiEmpat(sisi, tinggi_limas));
        }
        else if (x=='B'){
            printf("Masukkan panjang segi empat : "); sisi=InputCek();
            //scanf("%f", &sisi);
            printf("Masukkan tinggi limas : "); tinggi_limas=InputCek();
            //scanf(" %f", &tinggi_limas);
            printf("Volume Limas Segi Empat : %f \n", volume_LimasSegiEmpat(sisi, tinggi_limas));
        }
         else if(x=='C'){
            system("cls");
            menu();
        }
        else {
            system("cls");
            getchar();
            printf("Input Anda Salah \n");
            printf ("Tekan enter untuk ulang --> ");
            getchar();
            tampilan_LimasSegiEmpat();
        }
    return 0;
}

float luasPermukaan_PrismaSegitiga (float a, float t, float m, float t_prisma){
    float luas_alasSegitiga = (a*t)/2 ;
    float kll_alasSegitiga = a+t+m ;
    float hasil = (2*luas_alasSegitiga) + (kll_alasSegitiga*t_prisma);

    return hasil;
}

float volume_PrismaSegitiga (float a, float t, float t_prisma){
    float luas_alasSegitiga = (a*t)/2 ;
    float hasil = luas_alasSegitiga*t_prisma;

    return hasil;
}

int tampilan_PrismaSegitiga(){
    float panjang_alas, tinggi_alas, sisi_miring, tinggi_prisma;
    char x;

    system("cls");
    printf("=======================================\n");
    printf("========    Prisma Segitiga    ========\n");
    printf("========      Menghitung :     ========\n");
    printf(">>>>     [A] Luas Permukaan        <<<<\n");
    printf(">>>>     [B] Volume                <<<<\n");
    printf(">>>>     [C] Kembali ke menu       <<<<\n");
    printf("=======================================\n\n");

    printf("Masukkan pilihan kamu : "); scanf(" %c", &x);
        if (x=='A'){
            printf("Masukkan panjang alas : "); panjang_alas=InputCek();
            //scanf("%f", &panjang_alas);
            printf("Masukkan tinggi alas : "); tinggi_alas=InputCek();
            //scanf(" %f", &tinggi_alas);
            printf("Masukkan sisi miring : "); sisi_miring=InputCek();
            //scanf(" %f", &sisi_miring);
            printf("Masukkan tinggi prisma segitiga : "); tinggi_prisma=InputCek();
            //scanf(" %f", &tinggi_prisma);
            printf("Luas Permukaan Prisma Segitiga : %f \n", luasPermukaan_PrismaSegitiga(panjang_alas, tinggi_alas, sisi_miring, tinggi_prisma));
        }
        else if (x=='B'){
            printf("Masukkan panjang alas : "); panjang_alas=InputCek();
            //scanf("%f", &panjang_alas);
            printf("Masukkan tinggi alas : "); tinggi_alas=InputCek();
            //scanf(" %f", &tinggi_alas);
            printf("Masukkan tinggi prisma segitiga : "); tinggi_prisma=InputCek();
            //scanf(" %f", &tinggi_prisma);
            printf("Volume Limas Prisma Segitiga : %f \n", volume_PrismaSegitiga(panjang_alas, tinggi_alas, tinggi_prisma));
        }
           else if(x=='C'){
            system("cls");
            menu();
        }
            else {
            system("cls");
            getchar();
            printf("Input Anda Salah \n");
            printf ("Tekan enter untuk ulang --> ");
            getchar();
            tampilan_PrismaSegitiga();
        }
    return 0;
}

float luasPermukaan_Kerucut (float r, float t){
    float s = sqrt((r*r)+(t*t));
    float hasil = (phi*r*r)+(phi*r*s);

    return hasil;
}
float volume_Kerucut (float r, float t){
    float hasil = (phi*r*r*t)/3 ;

    return hasil;
}

int tampilan_Kerucut(){
    float jari2, tinggi_kerucut;
    char x;

    system("cls");
    printf("=======================================\n");
    printf("========       Kerucut         ========\n");
    printf("========      Menghitung :     ========\n");
    printf(">>>>     [A] Luas Permukaan        <<<<\n");
    printf(">>>>     [B] Volume                <<<<\n");
    printf(">>>>     [C] Kembali ke menu       <<<<\n");
    printf("=======================================\n\n");

    printf("Masukkan pilihan kamu : "); scanf(" %c", &x);
        if (x=='A'){
            printf("Masukkan jari-jari kerucut : "); jari2=InputCek();
            //scanf("%f", &jari2);
            printf("Masukkan tinggi kerucut : "); tinggi_kerucut=InputCek();
            //scanf(" %f", &tinggi_kerucut);
            printf("Luas Permukaan Kerucut : %f \n", luasPermukaan_Kerucut(jari2, tinggi_kerucut));
        }
        else if (x=='B'){
            printf("Masukkan jari-jari kerucut : "); jari2=InputCek();
            //scanf("%f", &jari2);
            printf("Masukkan tinggi kerucut : "); tinggi_kerucut=InputCek();
            //scanf(" %f", &tinggi_kerucut);
            printf("Volume Limas Kerucut : %f \n", volume_Kerucut(jari2, tinggi_kerucut));
        }
        else if(x=='C'){
            system("cls");
            menu();
        }
        else {
            system("cls");
            getchar();
            printf("Input Anda Salah \n");
            printf ("Tekan enter untuk ulang --> ");
            getchar();
            tampilan_Kerucut();
        }
    return 0;
    }
