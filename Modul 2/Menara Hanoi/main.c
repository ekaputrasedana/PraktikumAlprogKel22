#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <math.h>

void hanoi_rekursif(int n, char x, char y, char z);
void hanoi_iteratif (int n, char x, char y, char z);
void reset();
int Cekinput();

int main() {
    int jml_cakram,pilihan,hasil;

	printf("\t\t\t\t\t=============================================\t\t\t\t\t\n");
    printf("\t\t\t\t\t===         Program Menara Hanoi          ===\t\t\t\t\t\n");
    printf("\t\t\t\t\t===   Penyeleksian Kondisi dan Perulangan ===\t\t\t\t\t\n");
    printf("\t\t\t\t\t===     Praktikum Algoritma Pemrograman   ===\t\t\t\t\t\n");
    printf("\t\t\t\t\t===             Kelompok 22               ===\t\t\t\t\t\n");
    printf("\t\t\t\t\t=============================================\t\t\t\t\t\n\n");

    printf ("Pilih Metode Perulangan : \n");
    printf ("[1] Menara Hanoi Metode Rekursif\n");
	printf ("[2] Menara Hanoi Metode Iteratif\n");
	printf ("[3] Keluar\n");
	printf ("Masukkan Pilihan (1-3) --> : ");

	fflush(stdin);
	pilihan=Cekinput();

	switch(pilihan){
		case 1 :  {
			system("cls");
            printf("\t\t\t\t\t=============================================\t\t\t\t\t\n");
            printf("\t\t\t\t\t===      Menara Hanoi Metode Rekursif     ===\t\t\t\t\t\n");
            printf("\t\t\t\t\t=============================================\t\t\t\t\t\n\n");

			printf("Masukan Jumlah Cakram : ");
			fflush(stdin);
			jml_cakram=Cekinput();

	    	printf("\nUrutan pemindahan cakram :\n\n");
    		hanoi_rekursif(jml_cakram,'1','2','3');
    		hasil=pow(2,jml_cakram)-1;
			printf ("\nMaka jumlah langkah minimum menara Hanoi adalah %d\n",hasil);
	    	reset();
			break;
		}
		case 2 :  {
			system("cls");
            printf("\t\t\t\t\t=============================================\t\t\t\t\t\n");
            printf("\t\t\t\t\t===      Menara Hanoi Metode Iteratif     ===\t\t\t\t\t\n");
            printf("\t\t\t\t\t=============================================\t\t\t\t\t\n\n");

			printf("Masukan Jumlah Cakram : ");
			fflush(stdin);
			jml_cakram=Cekinput();
	    	printf("\nUrutan pemindahan cakram :\n\n");
            hanoi_iteratif(jml_cakram,'1','2','3');

    		hasil=pow(2,jml_cakram)-1;
			printf ("\nMaka jumlah langkah minimum menara Hanoi adalah %d\n",hasil);
	    	reset();
			break;
		}
		case 3: {
			break;
	 }
		default: {
			system("cls");
			printf ("Input Pilihan Salah!\n");
			printf("Tekan enter untuk mengulang");
			getch();
			printf("\n\n");
			main();
			break;
		}
	}
}

void hanoi_rekursif(int n, char x, char y, char z){
  	if (n==1) {
    	printf("Pindahkan cakram paling atas dari tiang %c ke tiang %c\n",x,z);
	}
	else {
        hanoi_rekursif(n-1,x,z,y);
        hanoi_rekursif(1,x,y,z);
        hanoi_rekursif(n-1,y,x,z);
    }
}

void hanoi_iteratif(int n, char x, char y, char z){
    int i;
    /*char tower[]={'1','2','3'};
    if(n % 2 == 0) {
        tower[1] = '3';
        tower[2] = '2';
    }*/

	for(i=1;i<(1 << n);i++){
        printf("Pindahkan cakram paling atas dari tiang %d ke tiang %d\n",((i&(i-1))%n )+ 1,(((i|(i-1))+1)%n) + 1);
    }

}

int Cekinput(){
    int angka;
    char karakter;
    if (scanf("%d%c",&angka,&karakter)!= 2 || angka<=0  || karakter != '\n' || karakter == ','){
        fflush(stdin);
        printf("Input SALAH! \nMasukkan angka yang benar : ");
        return Cekinput();
    } else {
        return angka;
    }
}

void reset(){
    /*int valid_reset;
    char parameter[1];
    printf("Ingin Mengulang?[Y/N] ");
    gets(parameter);
    if (!(strcmp(parameter,"Y")) || !(strcmp(parameter,"y"))){
        system("cls");
        main();
    } else if (!(strcmp(parameter,"N")) || !(strcmp(parameter,"n"))){
        return;
    } else {
        system("cls");
        printf("Input Salah!\n\a");
        reset();*/

    int valid_reset;
    char parameter;
    printf("Ingin Mengulang?[Y/N] ");
    scanf("%c", &parameter);
    if (parameter=='Y' || parameter=='y'){
        system("cls");
        main();
    } else if (parameter=='N' || parameter =='n'){
        return;
    } else {
        system("cls");
        printf("Input Salah!\n\a");
        reset();

    }
}
