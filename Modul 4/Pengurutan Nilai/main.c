#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main();
int sorting();
int readAsistenin();
void menu_utama();
void sortData();
void putToFile();
void ulang();
void keluar();

struct mahasiswa{
	char nama[100];
	int nilai;
};

int main(){
    system("cls");
    menu_utama();

    return 0;
}

void menu_utama(){
	struct mahasiswa siswa[50];
	struct mahasiswa temp;
	int a = 0;
	int i, j, k;
	int sort;
	char tempNama[100];
	int tempNilai;

    printf("======================================================\n");
    printf("=====     PROGRAM PENGURUTAN NILAI MAHASISWA     =====\n");
    printf("=====    PRAKTIKUM ALGORITMA DAN PEMROGRAMAN     =====\n");
    printf("=====                KELOMPOK 22                 =====\n");
    printf("======================================================\n");
    printf("Mengecek file asistenin.txt...");
    sleep(1);
	printf("\n\n");

	a = readAsistenin(siswa);

	printf("\n");
	sort = sorting();

	if(sort == 1){
		sortData(siswa, a);
		printf("\n");
		putToFile(siswa, a);

		printf("Data hasil sorting berhasil disimpan ke dalam file asistenout.txt!\n");
	}
	ulang();
}

int readAsistenin(struct mahasiswa siswa[]){
	int a = 0;
	FILE *in = fopen("asistenin.txt","r");
	if(!in){
		printf("File asistenin.txt tidak ditemukan!\n");
		printf("Silahkan buat file asistenin.txt terlebih dahulu!\n");
		system("exit");
	}else{
		printf("File asistenin.txt ditemukan \n");
        printf("Nilai Mahasiswa : \n");
		while(!feof(in)){
			printf("    ");
		    fscanf(in,"%[^\n]\n", &siswa[a].nama);
		    fscanf(in,"%d\n", &siswa[a].nilai);
            fflush(stdin);
		    printf("%d. %s : %d\n", a+1, siswa[a].nama, siswa[a].nilai);
		    a++;
		}
	}
	fclose(in);
	return a;
}

int sorting(){
    char huruf_sort[1];
	int hasil = 0;

    printf("Apakah anda ingin melakukan pengurutan nilai ? [Y/N] --> ");
    scanf("%s", &huruf_sort);
    fflush(stdin);

    if((strcmp(huruf_sort, "Y") != 0) && (strcmp(huruf_sort, "y") != 0) &&
       (strcmp(huruf_sort, "N") != 0) && (strcmp(huruf_sort, "n") != 0)){
        printf("Inputan anda salah! Input dengan benar \n");
        printf("===========================================================\n");
        sorting();
    }else if((strcmp(huruf_sort, "Y") == 0)){
		hasil = 1;
    }else if((strcmp(huruf_sort, "y") == 0)){
		hasil = 1;
    }else{
		hasil = 0;
    }
    return hasil;
}

void sortData(struct mahasiswa siswa[], int a){
	struct mahasiswa temp;
	int i, j;
	for(i = 0; i < a - 1; i++){
		for(j = 0; j < a - 1; j++){
			if(siswa[j+1].nilai > siswa[j].nilai){
				temp = siswa[j+1];
				siswa[j+1] = siswa[j];
    			siswa[j] = temp;
			}
    	}
	}
}

void putToFile(struct mahasiswa siswa[], int a){
	int i;
	FILE *out = fopen("asistenout.txt","w");
	fprintf(out, "Nilai Mata Kuliah Algoritma dan Pemrograman \n");
	for(i = 0; i < a; i++){
		fprintf(out,"%d. %s %d\n", i+1, siswa[i].nama, siswa[i].nilai);
	}
	fclose(out);
}

void ulang(){
    char huruf_ulang[1];
    printf("==================================================================\n");
    printf("Apakah anda ingin mengulangi program ini? Ya/Keluar [Y/E] --> ");
    scanf("%s", &huruf_ulang);
    fflush(stdin);

    if((strcmp(huruf_ulang, "Y") != 0) && (strcmp(huruf_ulang, "y") != 0) &&
       (strcmp(huruf_ulang, "E") != 0) && (strcmp(huruf_ulang, "e") != 0)){
        printf("Inputan anda salah! Input dengan benar\n");
        ulang();
    }else if((strcmp(huruf_ulang, "Y") == 0)){
        system("cls");
		menu_utama();
    }else if((strcmp(huruf_ulang, "y") == 0)){
 		system("cls");
		menu_utama();
    }else{
		keluar();
    }
}

void keluar(){
    system("cls");
    printf("====================================================\n");
    printf(">>>>>TERIMA KASIH SUDAH MENGGUNAKAN PROGRAM INI<<<<<\n");
    printf("====================================================\n");
    system("exit");
}
