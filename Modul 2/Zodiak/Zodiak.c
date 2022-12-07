#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main();
char *zodiak;
int tanggal, bulan;


void menu()
{
    printf("===============================================\n");
    printf(">           PROGRAM PENCARI ZODIAK            <\n");
    printf(">                KELOMPOK 22                  <\n");
    printf("===============================================\n");
    printf(">                 Anggota :                   <\n");
    printf(">           I Made Bagus Wahyu Mahendra       <\n");
    printf(">           I Gusti Ngurah Yuwanda Ryan       <\n");
    printf(">           Ni Putu Nadila Sinthadewi         <\n");
    printf(">           I Kadek Bagus Tresna Verdhyawan   <\n");
    printf(">           Ni Wayan Devi Pratiwi             <\n");
    printf(">           I Putu Eka Putra Sedana           <\n");
    printf("===============================================\n");
    printf(">    Bulan dan Tanggal Pada Kalender Masehi   <\n");
    printf("===============================================\n");
    printf(">            [1]  Januari   (1-31)            <\n");
    printf(">            [2]  Februari  (1-29)            <\n");
    printf(">            [3]  Maret     (1-31)            <\n");
    printf(">            [4]  April     (1-30)            <\n");
    printf(">            [5]  Mei       (1-31)            <\n");
    printf(">            [6]  Juni      (1-30)            <\n");
    printf(">            [7]  Juli      (1-31)            <\n");
    printf(">            [8]  Agustus   (1-31)            <\n");
    printf(">            [9]  September (1-30)            <\n");
    printf(">            [10] Oktober   (1-31)            <\n");
    printf(">            [11] November  (1-30)            <\n");
    printf(">            [12] Desember  (1-31)            <\n");
    printf("===============================================\n");
}

void reset()
{
    char pil[1];
    printf("\n Apakah anda ingin kembali ke program? [Y/X] : ");
    scanf("%s", &pil);

    if (!strcmp(pil, "y") || !strcmp(pil, "Y"))
    {
        system("cls");
        main();
    }
    else if (!strcmp(pil, "x") || !strcmp(pil, "X"))
    {
        exit(0);
    }
    else
    {
        printf("\nError, Input Tidak Valid!\n");
        reset();
    }
}

int validInt(int *var)
{
    char buff[1024];
    char check;
    if (fgets(buff, sizeof(buff), stdin) != NULL)
    {
        if (sscanf(buff, "%d %c", var, &check) == 1)
        {
            return 1;
        }
    }
    return 0;
}

void reVldInt(int *var, char *prompt)
{
    while (1)
    {
        printf(prompt);
        if (validInt(var))
            break;
        printf("Input hanya boleh berupa angka!! \n");
        printf("\n");
    }
}

void cariZodiak()
{
    if (bulan == 1)
    {
        if (tanggal >= 1 && tanggal <= 19)
        {
            zodiak = "Capricorn";
        }
        else if (tanggal >= 20 && tanggal <= 31)
        {
            zodiak = "Aquarius";
        }
        else
        {
            printf("\nTanggal tidak sampai %d\n", tanggal);
            zodiak = "Tidak Valid";
        }
    }
    else if (bulan == 2)
    {
        if (tanggal > 0 && tanggal < 19)
        {
            zodiak = "Aquarius";
        }
        else if (tanggal > 18 && tanggal < 29)
        {
            zodiak = "Pisces";
        }
        else
        {
            printf("\nTanggal tidak sampai %d\n", tanggal);
            zodiak = "Tidak Valid";
        }
    }
    else if (bulan == 3)
    {
        if (tanggal > 0 && tanggal < 21)
        {
            zodiak = "Pisces";
        }
        else if (tanggal > 20 && tanggal < 32)
        {
            zodiak = "Aries";
        }
        else
        {
            printf("\nTanggal tidak sampai %d\n", tanggal);
            zodiak = "Tidak Valid";
        }
    }
    else if (bulan == 4)
    {
        if (tanggal > 0 && tanggal < 20)
        {
            zodiak = "Aries";
        }
        else if (tanggal > 20 && tanggal < 31)
        {
            zodiak = "Taurus";
        }
        else
        {
            printf("\nTanggal tidak sampai %d\n", tanggal);
            zodiak = "Tidak Valid";
        }
    }
    else if (bulan == 5)
    {
        if (tanggal > 0 && tanggal < 21)
        {
            zodiak = "Taurus";
        }
        else if (tanggal > 20 && tanggal < 31)
        {
            zodiak = "Gemini";
        }
        else
        {
            printf("\nTanggal tidak sampai %d\n", tanggal);
            zodiak = "Tidak Valid";
        }
    }
    else if (bulan == 6)
    {
        if (tanggal > 0 && tanggal < 21)
        {
            zodiak = "Gemini";
        }
        else if (tanggal > 20 && tanggal < 31)
        {
            zodiak = "Cancer";
        }
        else
        {
            printf("\nTanggal tidak sampai %d\n", tanggal);
            zodiak = "Tidak Valid";
        }
    }
    else if (bulan == 7)
    {
        if (tanggal > 0 && tanggal < 23)
        {
            zodiak = "Cancer";
        }
        else if (tanggal > 22 && tanggal < 32)
        {
            zodiak = "Leo";
        }
        else
        {
            printf("\nTanggal tidak sampai %d\n", tanggal);
            zodiak = "Tidak Valid";
        }
    }
    else if (bulan == 8)
    {
        if (tanggal > 0 && tanggal < 23)
        {
            zodiak = "Leo";
        }
        else if (tanggal > 22 && tanggal < 32)
        {
            zodiak = "Virgo";
        }
        else
        {
            printf("\nTanggal tidak sampai %d\n", tanggal);
            zodiak = "Tidak Valid";
        }
    }
    else if (bulan == 9)
    {
        if (tanggal > 0 && tanggal < 23)
        {
            zodiak = "Virgo";
        }
        else if (tanggal > 22 && tanggal < 31)
        {
            zodiak = "Libra";
        }
        else
        {
            printf("\nTanggal tidak sampai %d\n", tanggal);
            zodiak = "Tidak Valid";
        }
    }
    else if (bulan == 10)
    {
        if (tanggal > 0 && tanggal < 23)
        {
            zodiak = "Libra";
        }
        else if (tanggal > 22 && tanggal < 32)
        {
            zodiak = "Scorpio";
        }
        else
        {
            printf("\nTanggal tidak sampai %d\n", tanggal);
            zodiak = "Tidak Valid";
        }
    }
    else if (bulan == 11)
    {
        if (tanggal > 0 && tanggal < 22)
        {
            zodiak = "Scorpio";
        }
        else if (tanggal > 22 && tanggal < 31)
        {
            zodiak = "Sagitarius";
        }
        else
        {
            printf("\nTanggal tidak sampai %d\n", tanggal);
            zodiak = "Tidak Valid";
        }
    }
    else if (bulan == 12)
    {
        if (tanggal > 0 && tanggal < 22)
        {
            zodiak = "Sagitarius";
        }
        else if (tanggal > 21 && tanggal < 32)
        {
            zodiak = "Carpicorn";
        }
        else
        {
            printf("\nTanggal tidak sampai %d\n", tanggal);
            zodiak = "Tidak Valid";
        }
    }
    else
    {
        printf("\nInput Bulan Tidak Valid\n");
        zodiak = "Tidak Valid";
    }
    printf("===============================================\n");
    printf(">      Maka Zodiak Anda Adalah %s      <\n", zodiak);
    printf("===============================================\n");
}

int main()
{
    fflush(stdin);
    system("cls");
    menu();
    reVldInt(&tanggal, "\nMasukan Tanggal: ");
    fflush(stdin);
    reVldInt(&bulan, "\nMasukan Bulan  : ");
    fflush(stdin);
    cariZodiak();
    reset();
    return 0;
}