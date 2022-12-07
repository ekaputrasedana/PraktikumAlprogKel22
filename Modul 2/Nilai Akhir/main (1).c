#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int input_nilai();
int input_absen();
void reset();

int main(){
	double absensi,tugas1,tugas2,tugas3,quiz,uts,uas,nilai_akhir;
	printf("<<<<<================================>>>>>\n");
	printf("|| PROGRAM MENENTUKAN INDEX NILAI AKHIR ||\n");
	printf("||              Kelompok 22             ||\n");
	printf("<<<<<================================>>>>>\n\n");


	printf("Masukkan Jumlah Absensi = ");
	absensi=input_absen();
	printf("Masukkan Nilai Tugas 1  = ");
	tugas1=input_nilai();
	printf("Masukkan Nilai Tugas 2  = ");
	tugas2=input_nilai();
	printf("Masukkan Nilai Tugas 3  = ");
	tugas3=input_nilai();
	printf("Masukkan Nilai Quiz     = ");
	quiz=input_nilai();
	printf("Masukkan Nilai UTS      = ");
	uts=input_nilai();
	printf("Masukkan Nilai UAS      = ");
	uas=input_nilai();

	nilai_akhir=(((absensi*100)/15)*0.05)+(quiz*0.15)+(((tugas1+tugas2+tugas3)/3)*0.2)+(uts*0.3)+(uas*0.3);
	if(nilai_akhir>=0 && nilai_akhir<45 ){
		printf("\nNilai Akhir : %.2lf \n",nilai_akhir);
        printf("Indeks Nilai : E");
	}
	else if(nilai_akhir>=45 && nilai_akhir<50 ){
		printf("\nNilai Akhir : %.2lf \n",nilai_akhir);
        printf("Indeks Nilai : D");
	}
	else if(nilai_akhir>=50 && nilai_akhir<55 ){
		printf("\nNilai Akhir : %.2lf \n",nilai_akhir);
        printf("Indeks Nilai : D+");
	}
	else if(nilai_akhir>=55 && nilai_akhir<60 ){
		printf("\nNilai Akhir : %.2lf \n",nilai_akhir);
        printf("Indeks Nilai : C");
	}
	else if(nilai_akhir>=60 && nilai_akhir<65 ){
		printf("\nNilai Akhir : %.2lf \n",nilai_akhir);
        printf("Indeks Nilai : C+");
	}
	else if(nilai_akhir>=65 && nilai_akhir<75){
		printf("\nNilai Akhir : %.2lf \n",nilai_akhir);
        printf("Indeks Nilai : B");
	}
	else if(nilai_akhir>=75 && nilai_akhir<80){
		printf("\nNilai Akhir : %.2lf \n",nilai_akhir);
        printf("Indeks Nilai : B+");
	}
	else if(nilai_akhir>=80){
		printf("\nNilai Akhir : %.2lf \n",nilai_akhir);
        printf("Indeks Nilai : A");
	}
	reset();
}

int input_nilai(){
    double angka;
    char karakter;
    if (scanf("%lf%c",&angka,&karakter)!= 2 || angka<0 || angka>100 || karakter != '\n' || karakter == ','){
        fflush(stdin);
        printf("Data yang diinputkan Invalid!\n");
        printf("Masukkan nilai yang benar (Max 100) : ");
        return input_nilai();
    } else {
        return angka;
    }
}

int input_absen(){
    double absen;
    char karakter;
    if (scanf("%lf%c",&absen,&karakter)!= 2 || absen<0 || absen>15 || karakter != '\n' || karakter == ','){
        fflush(stdin);
        printf("Data yang diinputkan Invalid!\n");
        printf("Masukkan jumlah absensi yang benar (Max 15) : ");
        return input_absen();
    } else {
        return absen;
    }
}

void reset(){
    int valid_reset;
    char parameter[1];
    printf("\nKembali menghitung nilai akhir?[y/n] : ");
    gets(parameter);

        system("cls");
        printf("=======================================\n");
        printf("||===     SEKIAN TERIMA KASIH     ===||\n");
        printf("=======================================\n");

     if (!(strcmp(parameter,"Y")) || !(strcmp(parameter,"y"))){
        system("cls");
        main();
    } else if (!(strcmp(parameter,"N")) || !(strcmp(parameter,"n"))){
        return;
    } else {
        system("cls");
        printf("Data yang diinput Invalid!\n\a");
        reset();
    }

}
