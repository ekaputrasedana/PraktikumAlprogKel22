#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
void reset();
int input();
int input_bulan();

int main()
{
    char validasi, pilihan;
    int lp,i,pp,bunga;
    float ap, bb, ta, tb, totalangsuran;

    system("cls");
    printf("|==============================================================================|");
    printf("\n|---------------------|                                 |----------------------|");
    printf("\n|---------------------|  PROGRAM PENGHITUNGAN ANGSURAN  |----------------------|");
    printf("\n|===============================| KELOMPOK 22  |===============================|");

    printf("\n\n\tMasukkan Besar Pokok Pinjaman Anda (juta) :Rp");
        fflush(stdin);
        pp=input();
    printf("\n\tMasukkan Besar Bunga :");
        fflush(stdin);
        bunga=input();
    printf("\n\tMasukkan Lama Pinjaman (bulan) :");
        fflush(stdin);
        lp=input_bulan();
    system("cls");
    printf("===============================================================================");
    printf("\n|-----------------------------|  DETAIL INPUTAN  |----------------------------|");
    printf("\n===============================================================================");

    printf("\n|Besar Pokok Pinjaman\t\t\t\t:%d %%\t\t\t      |",bunga);
    printf("\n|Lama Pinjaman\t\t\t\t\t:%d Bulan\t\t      |",lp);
    printf("\n===============================================================================");
    printf("\n|-----------------------------|  DETAIL ANGSURAN  |---------------------------|");
    printf("\n_______________________________________________________________________________");
    printf("\n Bulan\t    Bunga \t      Angsuran Pokok \t    Angsuran PerBulan    ");
    printf("\n===============================================================================");

    ap=pp/lp;
    for(i=1; i<=lp; i++){
        bb=(pp-((i-1) * ap)) *bunga/100/12;
        ta=ap+bb;

        tb=tb+bb;
        totalangsuran=totalangsuran+ta;
    printf("\n| %d\t   Rp.%1.f\t\t Rp.%1.f\t\tRp.%1.f\t      |",i, bb, ap, ta);
    }

    printf("\n===============================================================================");
    printf("\nTotal Bunga\t\t\t\t\t\t:Rp.%1.f\t|",tb);
    printf("\nTotal Angsuran\t\t\t\t\t\t:Rp.%1.f\t|",totalangsuran);
    printf("\n===============================================================================");
    reset();
    return 0;
}
int input(){
    int bilangan;
    char karakter;
    if (scanf("%d%c",&bilangan, &karakter)!= 2 || bilangan<=0 || karakter != '\n' || karakter == ','){
        fflush(stdin);
    printf("Input Salah!\nSilahkan Masukkan Angka Yang Benar :");
        return input();
    }else{
        return bilangan;
    }
}
int input_bulan(){
    int bulan;
    char karakter;
    if (scanf("%d%c", &bulan, &karakter)!= 2 || bulan<=0 || bulan>12 || karakter != '\n' || karakter == ','){
        fflush(stdin);
    printf("Input Salah!\nMasukkan jumlah bulan yang benar(Max 12):");
        return input_bulan();
    }else{
        return bulan;
    }
}

void reset(){
    char pilihan[1];
printf("\nIngin Menghitung Kembali?[y/t] ");
gets(pilihan);
    if (!(strcmp(pilihan,"Y")) || !(strcmp(pilihan,"y"))){
        system("cls");
        main();
    }else if (!(strcmp(pilihan,"T")) || !(strcmp(pilihan,"t"))){
        return;
    }else {
        system("cls");
printf("Inputan Salah!\n\a");
    }
}
