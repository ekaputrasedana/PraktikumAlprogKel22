#include <stdio.h>

int main()
{
    int menu;
    char kembali;

    do
    {
        system("cls");
        printf("=============================================\n");
        printf("=== Program Menampilkan Bilangan Fibonaci ===\n");
        printf("===    Praktikum Algoritma Pemrograman    ===\n");
        printf("===              Kelompok 22              ===\n");
        printf("===========================================\n\n");

        printf("=====================================\n");
        printf("=====          MENU             =====\n");
        printf("=====================================\n");
        printf(">>     [1] Metode Rekursif         <<\n");
        printf(">>     [2] Metode Iteratif         <<\n");
        printf("=====================================\n\n");

        printf("Masukkan pilihan : ");
        scanf("%d", &menu);

        switch (menu)
        {
        case 1:
            rekursif();
            break;
        case 2:
            iteratif();
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

int fibonacciRekursif(int number)
{
  if(number == 0)
    {
    return 0;
    }
    else if (number == 1)
    {
        return 1;
    }
    else
    {
        return fibonacciRekursif(number - 1) + fibonacciRekursif(number - 2);
    }
}

void rekursif()
{
    system("cls");
    printf("Fibonacci Menggunakan Metode Rekursif \n");

    int batas, angka, i;
    int cekBatas;

    printf("Masukkan Batas : ");
    cekBatas = scanf("%d", &batas);

    if (cekBatas == 0)
    {
        fflush(stdin);
        printf("Input Salah, Bilangan Harus Berupa Bilangan\n");
        printf("Tekan enter untuk ulang --> ");
        getchar();
        rekursif(batas);
    }
    else
    {
        printf("Hasilnya adalah : \n");
        for (i = 0; i < batas; i++)
        {
            printf(" %d ", fibonacciRekursif(i));
        }
        printf("\n");
    }
}

void iteratif()
{
    system("cls");
    printf("Fibonacci Menggunakan Metode Iteratif \n");

    int batas, angka, hasil, f1 = 0, f2 = 1, n;
    int cekBatas;

    printf("Masukkan Batas : ");
    cekBatas = scanf("%d", &batas);
    printf("Hasilnya adalah : \n");

    if (cekBatas == 0)
    {
        fflush(stdin);
        printf("Input Salah, Bilangan Harus Berupa Bilangan\n");
        printf("Tekan enter untuk ulang --> ");
        getchar();
        iteratif(batas);
    }
    else
    {
        for (angka = 1; angka <= batas; angka++)
        {
            if (angka == 1)
            {
                hasil = f1;
            }
            else if (angka == 2)
            {
                hasil = f2;
            }
            else
            {
                hasil = f1 + f2;
                f1 = f2;
                f2 = hasil;
            }
            printf(" %d ", hasil);
        }
        printf("\n");
    }
}
