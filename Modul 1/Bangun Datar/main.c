#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

void segitiga(float sisi1, float sisi2, float sisi3);
void ketupat(float diagonal1, float diagonal2, float sisi);
void genjang(float alas, float tinggi, float sisigen);
void trapesium(float sisibawah, float sisiatas, float sisisamping1, float sisisamping2,  float tinggi);
void lingkaran(float jari);

int main(){
    int a, b, menu;
    float c, d, e, f ,g;
    char kembali;

    do{
        system ("cls");
        printf("============================================\n");
	    printf("=== Program Menghitung Luas dan Keliling ===\n");
	    printf("===    Praktikum Algoritma Pemrograman   ===\n");
	    printf("===             Kelompok 22              ===\n");
    	printf("============================================\n\n");


        printf("=======================================\n");
        printf("=====          ~MENU~             =====\n");
        printf("=======================================\n");
	    printf(">>>>     [1] Segitiga Sembarang    <<<<\n");
	    printf(">>>>     [2] Belah Ketupat         <<<<\n");
	    printf(">>>>     [3] Jajar Genjang         <<<<\n");
	    printf(">>>>     [4] Trapesium             <<<<\n");
	    printf(">>>>     [5] Lingkaran             <<<<\n");
	    printf("=======================================\n\n");

        printf("Masukkan pilihan : ");
        scanf("%d", &menu);

        switch (menu)
        {
        case 1:
            segitiga(a, b, c);
            break;
        case 2:
            ketupat(a, b, c);
            break;
        case 3:
            genjang(a, b, c);
            break;
        case 4:
            trapesium(a, b, c, d, e);
            break;
        case 5:
            lingkaran(a);
            break;
        default:
        fflush (stdin);
        printf("\n");
        printf("Pilihan yang anda pilih tidak tersedia \n");
        printf("Tekan enter untuk ulang");
        getchar();
        kembali= 'y' ;
        continue;
        }
        printf("Apakah anda ingin mengulang (y/t)");
        scanf("%s", &kembali);
        system("cls");
    }
        while (kembali == 'y' || kembali == 'Y');
        system("cls");
        printf("==============================================================\n");
        printf("=====          TERIMAKASIH SUDAH MENGGUNAKAN             =====\n");
        printf("==============================================================\n");
        return 0;
}

void segitiga(float sisi1, float sisi2, float sisi3)
{
    system("cls");
    printf("Keliling dan Luas Segitiga Sembarang \n");

    float semiPerimeter, kll, luas;
    float cekSisi1, cekSisi2, cekSisi3;

    printf("Masukan Sisi 1 : ");
    cekSisi1 = scanf("%f", &sisi1);
    printf("Masukan Sisi 2 : ");
    cekSisi2 = scanf("%f", &sisi2);
    printf("Masukan Sisi 3 : ");
    cekSisi3 = scanf("%f", &sisi3);

    if (cekSisi1 == 0 || cekSisi2 == 0 || cekSisi3 == 0)
    {
        fflush(stdin);
        printf ("Bilangan Hanya Berupa Bilangan\n");
        printf ("Tekan enter untuk ulang --> ");
        getchar();
        segitiga(sisi1, sisi2, sisi3);
    }
    else
    {
        kll = sisi1 + sisi2 + sisi3;
        semiPerimeter = (sisi1 + sisi2 + sisi3) /2;
        luas = sqrt ((semiPerimeter+sisi1)*(semiPerimeter+sisi2)*(semiPerimeter+sisi3));

        printf("\n");
        printf("Hasil Keliling Segitiga Sembarang Yaitu  : %.2f \n", kll);
        printf("Hasil Luas Segitiga Sembarang Yaitu      : %.2f \n", luas);
        printf("\n");
    }
}

void ketupat(float diagonal1, float diagonal2, float sisi)
{
    system("cls");
    printf("Keliling dan Luas Belah Ketupat \n");

    float kll, luas;
    float cekDiagonal1, cekDiagonal2, cekSisi;

    printf("Masukan Diagonal Pertama : ");
    cekDiagonal1 = scanf("%f", &diagonal1);
    printf("Masukan Diagonal Kedua   : ");
    cekDiagonal2 = scanf("%f", &diagonal2);
    printf("Masukan Panjang Sisi     : ");
    cekSisi = scanf("%f", &sisi);

    if (cekDiagonal1 == 0 || cekDiagonal2 == 0 || cekSisi == 0)
    {
        fflush(stdin);
        printf ("Bilangan Hanya Berupa Bilangan\n");
        printf ("Tekan enter untuk ulang --> ");
        getchar();
        ketupat(diagonal1, diagonal2, sisi);
    }
    else
    {
        kll = 4*sisi;
        luas = (diagonal1*diagonal2)/2;

        printf("\n");
        printf("Hasil Keliling Belah Ketupat Yaitu  : %.0f \n", kll);
        printf("Hasil Luas Belah Ketupat Yaitu      : %.0f \n", luas);
        printf("\n");
    }
}

void genjang(float alas, float tinggi, float sisigen)
{
    system("cls");
    printf("Keliling dan Luas Belah Ketupat \n");

    float kll, luas;
    float cekAlas, cekTinggi, cekSisi;

    printf("Masukan Nilai Atas            : ");
    cekAlas = scanf("%f", &alas);
    printf("Masukan Nilai Tinggi          : ");
    cekTinggi = scanf("%f", &tinggi);
    printf("Masukan Nilai Sisi Miring     : ");
    cekSisi = scanf("%f", &sisigen);

    if (cekAlas == 0 || cekTinggi == 0 || cekSisi == 0)
    {
        fflush(stdin);
        printf ("Bilangan Hanya Berupa Bilangan\n");
        printf ("Tekan enter untuk ulang --> ");
        getchar();
        ketupat(alas, tinggi, sisigen);
    }
    else
    {
        kll = 2*(alas+tinggi);
        luas = alas*tinggi;

        printf("\n");
        printf("Hasil Keliling Jajar Genjang Yaitu  : %.0f \n", kll);
        printf("Hasil Luas Jajar Genjang Yaitu      : %.0f \n", luas);
        printf("\n");
    }
}

void trapesium(float sisibawah, float sisiatas, float sisisamping1, float sisisamping2,  float tinggi)
{
    system("cls");
    printf("Keliling dan Luas Trapesium \n");

    float kll, luas;
    float cekSisibawah, cekSisiatas, cekSisisamping1, cekSisisamping2, cekTinggi;

    printf("Masukan Nilai Sisi Atas        : ");
    cekSisiatas = scanf("%f", &sisiatas);
    printf("Masukan Nilai Sisi Bawah       : ");
    cekSisibawah = scanf("%f", &sisibawah);
    printf("Masukan Nilai Sisi Samping 1   : ");
    cekSisisamping1 = scanf("%f", &sisisamping1);
    printf("Masukan Nilai Sisi Samping 2   : ");
    cekSisisamping2 = scanf("%f", &sisisamping2);
    printf("Masukan Nilai Tinggi           : ");
    cekTinggi = scanf("%f", &tinggi);

    if (cekSisibawah == 0 || cekSisiatas == 0 || cekSisisamping1 == 0 || cekSisisamping2 == 0 || tinggi == 0)
    {
        fflush(stdin);
        printf ("Bilangan Hanya Berupa Bilangan\n");
        printf ("Tekan enter untuk ulang --> ");
        getchar();
        trapesium(sisibawah, sisiatas, sisisamping1, sisisamping2, tinggi);
    }
    else
    {
        kll = sisibawah+sisisamping1+sisisamping2+sisiatas;
        luas = (sisiatas+sisibawah)*tinggi*1/2;

        printf("\n");
        printf("Hasil Keliling Trapesium Yaitu  : %.0f \n", kll);
        printf("Hasil Luas Trapesium Yaitu      : %.0f \n\n", luas);
        printf("\n");
    }
}

void lingkaran(float jari)
{
    system("cls");
    printf("Keliling dan Luas Lingkaran \n");

    float kll, luas, phi;
    float cekJari;
    phi = 3.14;

    printf("Masukan Nilai Jari-Jari : ");
    cekJari = scanf("%f", &jari);

    if (cekJari == 0 )
    {
        fflush(stdin);
        printf ("Bilangan Hanya Berupa Bilangan\n");
        printf ("Tekan enter untuk ulang --> ");
        getchar();
        lingkaran(jari);
    }
    else
    {
        kll = 2*phi*jari;
        luas = phi *jari*jari;

        printf("\n");
        printf("Hasil Keliling Lingkaran Yaitu  : %.2f \n", kll);
        printf("Hasil Luas Lingkaran Yaitu      : %.2f \n\n", luas);
        printf("\n");
    }
}
