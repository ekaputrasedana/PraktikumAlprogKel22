#include <stdio.h>
#include <stdlib.h>

int main()
{
    int menu;
    char kembali;

    do
    {
        system("cls");
        printf("======================================================\n");
        printf("=== Program Mengoperasikan Matematika Pada Matriks ===\n");
        printf("===         Praktikum Algoritma Pemrograman        ===\n");
        printf("===                   Kelompok 22                  ===\n");
        printf("======================================================\n\n");

        printf("==========================================\n");
        printf("=====            ~MENU~              =====\n");
        printf("==========================================\n");
        printf(">>>>     [1] Metode Penjumlahan       <<<<\n");
        printf(">>>>     [2] Metode Perkalian         <<<<\n");
        printf(">>>>     [3] Metode Transpose         <<<<\n");
        printf("==========================================\n\n");

        printf("Masukkan pilihan : ");
        scanf("%d", &menu);

        switch (menu)
        {
        case 1:
            penjumlahan();
            break;
        case 2:
            perkalian();
            break;
        case 3:
            transpose();
            break;
        default:
            fflush(stdin);
            printf("\n");
            printf("Pilihan yang anda pilih tidak tersedia \n");
            printf("Tekan enter untuk ulang");
            getchar();
            kembali = 'y';
            continue;
        }
        printf("Apakah anda ingin mengulang (y/t)");
        scanf("%s", &kembali);
        system("cls");
    } while (kembali == 'y' || kembali == 'Y');
    system("cls");
    printf("==============================================================\n");
    printf("=====          TERIMAKASIH SUDAH MENGGUNAKAN             =====\n");
    printf("==============================================================\n");
    return 0;
}

int validasiInt(int *var)
{
    char buff[10];
    char cek;
    fflush(stdin);
    if (fgets(buff, sizeof(buff), stdin) != NULL)
    {
        if (sscanf(buff, "%d %c", var, &cek) == 1)
        {
            return 1;
        }
    }
    return 0;
}

void ReValidasiInt(int *var)
{
    while (1)
    {
        if (validasiInt(var))
            break;
        printf("Input salah!\n");
        printf("Ulangi Masukan Angka!");
        printf("\n");
    }
}

void penjumlahan()
{
    system("cls");
    printf("Penjumlahan Matriks \n");

    int i, j, baris, kolom, matriks1[10][10], matriks2[10][10], hasil[10][10];

    printf("Masukkan jumlah baris matriks: ");
    ReValidasiInt(&baris);
    printf("Masukkan jumlah kolom matriks: ");
    ReValidasiInt(&kolom);

    printf("Masukkan elemen matrix pertama: \n");
    for (i = 0; i < baris; i++)
    {
        for (j = 0; j < kolom; j++)
        {
            ReValidasiInt(&matriks1[i][j]);
        }
    }

    printf("Masukkan elemen matrix kedua: \n");
    for (i = 0; i < baris; i++)
    {
        for (j = 0; j < kolom; j++)
        {
            ReValidasiInt(&matriks2[i][j]);
        }
    }

    printf("hasil penjumlahan matriks: \n");
    for (i = 0; i < baris; i++)
    {
        for (j = 0; j < kolom; j++)
        {
            hasil[i][j] = matriks1[i][j] + matriks2[i][j];
            printf("%d \t", hasil[i][j]);
        }
        printf("\n");
    }
}

void perkalian()
{
    system("cls");
    printf("Penjumlahan Matriks \n");

    int matriks1[10][10], matriks2[10][10], hasil[10][10];
    int i, j, k, baris1, kolom1, baris2, kolom2, jumlah = 0;

    printf("Masukkan jumlah baris matriks pertama: ");
    ReValidasiInt(&baris1);
    printf("Masukkan jumlah kolom matriks pertama: ");
    ReValidasiInt(&kolom1);
    printf("Masukkan jumlah baris matriks kedua: ");
    ReValidasiInt(&baris2);
    printf("Masukkan jumlah kolom matriks kedua: ");
    ReValidasiInt(&kolom2);

    if(kolom1 != baris2)
    {
        printf("Matriks tidak dapat dikalikan satu sama lain.\n");
    }
    else
    {
        printf("Masukkan elemen matriks pertama: \n");
        for(i = 0; i < baris1; i++)
        {
            for(j = 0; j < kolom1; j++)
            {
                ReValidasiInt(&matriks1[i][j]);
            }
        }

        printf("Masukkan elemen matriks kedua: \n");
        for(i = 0; i < baris2; i++)
        {
            for(j = 0; j < kolom2; j++)
            {
                ReValidasiInt(&matriks2[i][j]);
            }
        }

    for(i = 0; i < baris1; i++)
    {
      for(j = 0; j < baris2; j++)
      {
        for(k = 0; k < kolom2; k++)
        {
            jumlah = jumlah + matriks1[i][k] * matriks2[k][j];
        }
        hasil[i][j] = jumlah;
        jumlah = 0;
      }
    }

    printf("Hasil perkalian matriks: \n");
    for(i = 0; i < baris1; i++)
    {
        for(j = 0; j < baris2; j++)
        {
            printf("%d\t", hasil[i][j]);
        }
        printf("\n");
    }
    }
}

void transpose()
{
    system("cls");
    printf("Transpose Matriks \n");

    int i, j, baris, kolom;
    int matriks[10][10];
    int transpose[10][10];

    printf("Masukkan jumlah baris matriks: ");
    ReValidasiInt(&baris);
    printf("Masukkan jumlah kolom matriks: ");
    ReValidasiInt(&kolom);

    printf("Masukkan elemen matriks:\n");
    for(i = 0; i < baris; i++)
    {
        for(j = 0; j < kolom; j++)
        {
            ReValidasiInt(&matriks[i][j]);
        }
    }
    for (i = 0; i < baris; i ++)
    {
        for(j = 0; j < kolom; j++)
        {
            transpose[j][i] = matriks[i][j];
        }
    }
    printf("Hasil transpose matriks:\n");
    for (i = 0; i < baris; i ++)
    {
        for(j = 0; j < kolom; j++)
        {
            printf("%d\t",transpose[i][j]);
        }
        printf("\n");
    }
}
