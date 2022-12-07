#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void DesimalkeBiner();
void BinerkeDesimal();
void reset();
int input();

int main(){
	int pilihan;
        system("cls");
        printf("===============================================\n");
        printf("=====   PROGRAM KONVERSI BILANGAN BINER   =====\n");
        printf("===== PRAKTIKUM ALGORITMA DAN PEMROGRAMAN =====\n");
        printf("=====           KELOMPOK 22               =====\n");
        printf("===============================================\n");
        printf("===============================================\n");
        printf("==========   >>MENU PILIHAN<<       ===========\n");
        printf("===============================================\n");
        printf(">>  [1] Konversi Bilangan Desimal ke Biner   <<\n");
        printf(">>  [2] Konversi Bilangan Biner ke Desimal   <<\n");
        printf("===============================================\n\n");
        printf("Masukkan pilihan --> : ");

        pilihan=input();

        switch(pilihan){
            case 1: {
                DesimalkeBiner();
                reset();
                break;
            }
            case 2: {
                BinerkeDesimal();
                reset();
                break;
            }
            default: {
                fflush(stdin);
			    printf("Pilihan yang anda input salah!\n");
			    printf("Tekan enter untuk mengulang");
			    getchar();
			    printf("\n\n");
			    main();
			    break;
            }
        }
    }

void DesimalkeBiner(){
	int bil,i=1,k;
	int j;
	int biner[1000];
	system("cls");
    printf("==============================================\n");
    printf(">>>>  Konversi Bilangan Desimal ke Biner  <<<<\n");
    printf("==============================================\n\n");

    printf("Masukkan Bilangan Desimal  : ");
    bil=input();
    while(bil>0){
    	biner[i]=bil%2;
    	bil=bil/2;
    	i++;
    	k=i;
    }
    printf("Bilangan Biner dari angka yang anda input adalah  :");
    for(j=k-1;j>0;j--)
	{
		printf("%d",biner[j]);
	}	printf("\n");
}

void BinerkeDesimal(){
	int biner,desimal,dua;
    dua=1;
    desimal=0;
	system("cls");
    printf("==============================================\n");
    printf(">>>>  Konversi Bilangan Biner ke Desimal  <<<<\n");
    printf("==============================================\n\n");

    printf("Masukkan Bilangan Biner : ");
    biner=input();
    do{
        desimal+=(biner%2)*dua;
        dua*=2;
        biner/=10;
    }while (biner);
        printf("Bilangan Desimalnya adalah : %d\n\n",desimal);
	}


void reset(){
    int valid_reset;
    char parameter;
    printf("Apakah anda ingin kembali ke Menu?[Y/N] --> ");
    scanf("%c", &parameter);
    if (parameter=='Y' || parameter=='y'){
        main();
    } else if (parameter=='N' || parameter =='n'){
    	system("cls");
        printf("====================================================\n");
        printf(">>>>>TERIMA KASIH SUDAH MENGGUNAKAN PROGRAM INI<<<<<\n");
        printf("====================================================\n");
        return;
    } else {
        reset();
    }
}

int input(){
    double angka;
    char karakter;
    if (scanf("%lf%c",&angka,&karakter)!= 2  || karakter != '\n' || karakter == ','){
    	fflush(stdin);
        printf("Input tidak sesuai! \n");
        printf("Masukkan angka : ");
        return input();
    } else {
        return angka;
	}
}
