#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>

int validasi(int *var);
void ulang();
void hitung_kubus_struct();
void hitung_kubus_union();
void cover();

int panjang_sisi;

struct unsur_kubus{
	int sisi;
	int luas_permukaan;
	int volume;
};

union unsur_kbs{
	int sisi;
	int luas_permukaan;
	int volume;
};

int main();
void clean(){
	while (getchar() != '\n');
}


int validasi(int *var){
    if (scanf("%d", var) !=1){
		clean();
		printf("\n");
        printf("\t\t    Mohon Maaf Input Salah!\n");
        printf("\t\t    Silakan Input Ulang (ANGKA)\n");
        printf("\t\t    Masukkan pilihan dengan benar: ");
        validasi(var);
    }
    return 1;
}

void ulang(){
	char pil[10];
	printf("\t\t   Apakah Anda ingin mengulang?\n");
	printf("\t\t   (ya/tidak): ");
	scanf("%s", &pil);
	if(strcmp(pil, "ya")==0){
		system("cls");
		main();
	}else if(strcmp(pil, "tidak")==0){
		printf("\t\t|*|---------------------------\t|*|\n");
		printf("\t\t|*|\t***Terima kasih!***\t|*|");
		exit(0);
	}else{
		printf("\t\t|*|---------------------------\t|*|\n");
		printf("\t\t|*|Mohon maaf, INPUT SALAH!\t|*|\n");
		printf("\t\t|*|Silakan inputkan kembali\t|*|\n");
		printf("\t\t|*|---------------------------\t|*|\n");
		ulang();
	}
}
void hitung_kubus_struct(){
	struct unsur_kubus struct_kubus;
	system("cls");
	printf("\t\t ================================= \n");
	printf("\t\t|*|PROGRAM KUBUS DENGAN STRUCT\t|*|\n");
	printf("\t\t|*|===========================\t|*|\n");
	printf("\t\t    Masukkan panjang sisi kubus: ");
	validasi(&panjang_sisi);

	struct_kubus.sisi = panjang_sisi;
	struct_kubus.luas_permukaan = 6*panjang_sisi*panjang_sisi;
	struct_kubus.volume = panjang_sisi*panjang_sisi*panjang_sisi;

    printf("\t\t|*|---------------------------\t|*|\n");
	printf("\t\t|*|Panjang sisi\t\t:%d\t|*|\n", struct_kubus.sisi);
	printf("\t\t|*|Luas permukaan\t:%d\t|*|\n", struct_kubus.luas_permukaan);
	printf("\t\t|*|Volume\t\t:%d\t|*|\n", struct_kubus.volume);
	printf("\t\t|*|Memori\t\t:%d\t|*|\n", sizeof(struct_kubus));
	printf("\t\t|*|---------------------------\t|*|\n");

	ulang();
}

void hitung_kubus_union(){
	union unsur_kbs union_kubus[3];
	system("cls");
	printf("\t\t=================================\n");
	printf("\t\t|*|PROGRAM KUBUS DENGAN UNION\t|*|\n");
	printf("\t\t|*|===========================\t|*|\n");
	printf("\t\t    Masukkan panjang sisi: ");
	validasi(&panjang_sisi);
	union_kubus[0].sisi = panjang_sisi;
	union_kubus[1].luas_permukaan = 6*panjang_sisi*panjang_sisi;
	union_kubus[2].volume = panjang_sisi*panjang_sisi*panjang_sisi;

	printf("\t\t|*|---------------------------\t|*|\n");
	printf("\t\t|*|Panjang sisi\t\t:%d\t|*|\n", union_kubus[0].sisi);
	printf("\t\t|*|Luas permukaan\t:%d\t|*|\n", union_kubus[1].luas_permukaan);
	printf("\t\t|*|Volume\t\t:%d\t|*|\n", union_kubus[2].volume);
	printf("\t\t|*|Memori\t\t:%d\t|*|\n", sizeof(union_kubus[0]));
	printf("\t\t|*|---------------------------\t|*|\n");
	ulang();
}

void cover(){
    printf("\t\t|*|===============================================|*|\n");
    printf("\t\t|*|      PROGRAM KUBUS STRUCT DAN KUBUS UNION     |*|\n");
    printf("\t\t|*|                 KELOMPOK 22                   |*|\n");
    printf("\t\t|*|===============================================|*|\n");
    printf("\t\t|*|                 Anggota :                     |*|\n");
    printf("\t\t|*|           I Made Bagus Wahyu Mahendra         |*|\n");
    printf("\t\t|*|           I Gusti Ngurah Yuwanda Ryan         |*|\n");
    printf("\t\t|*|           Ni Putu Nadila Sinthadewi           |*|\n");
    printf("\t\t|*|           I Kadek Bagus Tresna Verdhyawan     |*|\n");
    printf("\t\t|*|           Ni Wayan Devi Pratiwi               |*|\n");
    printf("\t\t|*|           I Putu Eka Putra Sedana             |*|\n");

}




int main(){
	int pilihan;

	cover();
    printf("\t\t|*|===============================================|*|\n");
	printf("\t\t|*|                *** M E N U ***                |*|\n");
	printf("\t\t|*|-----------------------------------------------|*|\n");
	printf("\t\t|*|1.Kubus dengan struct                          |*|\n");
	printf("\t\t|*|2.Kubus dengan union                           |*|\n");
	printf("\t\t|*|3.Keluar                                       |*|\n");
	printf("\t\t=====================================================\n");
	printf("\t\t>>  Masukkan pilihan menu yang diinginkan: ");
	validasi(&pilihan);
	switch (pilihan){
		case 1:
			hitung_kubus_struct();
			break;
		case 2:
			hitung_kubus_union();
			break;
		case 3:
			printf("\t\t|*|===============================================|*|\n");
			printf("\t\t|*|       ***Terima kasih telah mencoba!***       |*|\n");
			printf("\t\t|*|===============================================|*|\n");
			exit(0);
		default:
			printf("\t\t INPUT SALAH! silakan input ulang\n\t\t");
			system("pause");
			system("cls");
			main();
	}
}
