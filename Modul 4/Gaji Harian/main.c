#include <stdio.h>
#include <stdlib.h>

struct pegawai{
    int jam_kerja;
    int jam_lembur;
    int gaji_pokok;
    int gaji_lembur;
    int gaji;
}karyawan;

int gajiperjam = 10625;
int gajilembur = 85000;

int main()
{
    int menu;
    char kembali;

    do
    {
        system("cls");
        printf("|=======================================================|\n");
        printf("|   Program Menghitung Gaji Harian Menggunakan Struct   |\n");
        printf("|            Praktikum Algoritma Pemrograman            |\n");
        printf("|                       Kelompok 22                     |\n");
        printf("|=======================================================|\n");

        printf("Tekan Enter Untuk Melanjutkan...");
        getch();

        inputjam();
        hasil();

        printf("Apakah anda ingin mengulang (y/t)");
        scanf("%s", &kembali);
        system("cls");
    } while (kembali == 'y' || kembali == 'Y');
    system("cls");
    printf("|============================================================|\n");
    printf("|              TERIMAKASIH SUDAH MENGGUNAKAN                 |\n");
    printf("|============================================================|\n");
    return 0;
}

void inputjam()
{
    system("cls");
    int cekInput;

    printf("\nMasukkan Jam kerja : ");
    cekInput = scanf("%d", &karyawan.jam_kerja);

    if (cekInput == 0)
    {
        fflush(stdin);
        printf("Input Salah, Bilangan Harus Berupa Bilangan Angka!\n");
        printf("Tekan enter untuk ulang --> ");
        getchar();
        inputjam(karyawan.jam_kerja);
    }
    else
    {
        hitunggaji();
    }
}

void hitunggaji()
{
    if (karyawan.jam_kerja>8)
    {
        karyawan.gaji_pokok = 8 * gajiperjam;
        karyawan.gaji_lembur = (karyawan.jam_kerja-8) * (gajilembur);
        karyawan.gaji = karyawan.gaji_pokok + karyawan.gaji_lembur;
    }
    else
    {
        karyawan.gaji_pokok = karyawan.jam_kerja * gajiperjam;
        karyawan.jam_lembur = 0;
        karyawan.gaji = karyawan.gaji_pokok;
    }
}

void hasil()
{
    hitunggaji();
    {
        printf("\n|================|\n");
        printf("|  Rincian Gaji  |\n");
        printf("|================|\n");
        printf("\nJam kerja: %d", karyawan.jam_kerja);
        printf("\nGaji pokok: %d", karyawan.gaji_pokok);
        printf("\nGaji lembur: %d", karyawan.gaji_lembur);
        printf("\nTotal gaji: %d\n\n", karyawan.gaji);
    }

}
