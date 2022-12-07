#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void menu();       // tampilan awalnya
void inputData();  // input data mahasiswa
void inputNim();   // input nim mahasiswa
int  cekSlot();    // jika data dari nama dan nim mahasisawa itu sudah terdaftar
void printHasil(); // jika data tersebut berhasil di tambahkan
void restart();    // untuk kembali ke menu awal atau keluar
void tampilkan();  // tampilan pada filenya dan tampilan data mahasiswa
void clear_buffer();
void changeEndl();
int input(int *select);
int validation(int *var, char *prompt); // untuk validasi

char namaMhs[1000];
char nimMhs[20];
char cekNim[20];

int main (void){
	menu();
}

void menu (void){
int pil;
system("cls");
fflush(stdin);
    printf("=======================================\n");
    printf("=                                     =\n");
    printf("=        Program Data Mahasiswa       =\n");
    printf("=   Praktikum Algoritma Pemrograman   =\n");
    printf("=             Kelompok 22             =\n");
    printf("=                                     =\n");
    printf("=======================================\n");
    printf("\n");
    printf("=======================================\n");
    printf("=          Menu Yang Tersedia         =\n");
    printf("=    [1] Input Data Mahasiswa         =\n");
    printf("=    [2] Tampilkan Data Mahasiswa     =\n");
    printf("=    [0] Keluar                       =\n");
    printf("=======================================\n\n");
    validation(&pil,"Masukkan Pilihan Anda      : ");
    switch(pil){
    	case 1:
    	inputData();
    	restart();
    	break;

    	case 2:
    	tampilkan();
    	restart();
    	break;

    	case 0:
    	printf("Terimakasih sampai jumpa!\n");
    	break;

    	default:
    	printf("Pilihan Tidak Tersedia!\n");
    	system("pause");
    	menu();
    	break;
    }
}

void inputData(void){
	fflush(stdin);
	system("cls");
    printf("=======================================\n");
    printf("====    Input Data Mahasiswa       ====\n");
    printf("=======================================\n\n");
	int i, len=0, count, check, tes=0;
	printf("Masukkan Nama Mahasiswa    : ");
	do{
        scanf("%c",&namaMhs[len]);
        len++;
    } while(namaMhs[len-1] != '\n');

    namaMhs[len-1] = '\0';
    count = len-2;

    for (i = 0 ; i < len-1 ; i ++ ){
        if ((namaMhs[i]>=65 && namaMhs[i]<=90) || (namaMhs[i]>=97 && namaMhs[i]<=122)){
        	tes++;
            continue;
        }else if(namaMhs[i]==32){
        	continue;
        }else{
            check=1;
            fflush(stdin);
            break;
        }
	}

	if(check==1){
		printf("Nama Hanya Bisa Berupa Huruf!\n");
		fflush(stdin);
		inputData();
	}else if(tes==0){
		printf("Nama Tidak Valid!\n");
		inputData();
	}else{
		inputNim();
	}
}

void inputNim(void){
	fflush(stdin);
	int i, len=0, count, check;
	printf("Masukkan NIM Mahasiswa     : ");
	do{
        scanf("%c",&nimMhs[len]);
        len++;
    } while(nimMhs[len-1] != '\n');

    nimMhs[len-1] = '\0';
    count = len-2;

    for (i = 0 ; i < len-1 ; i ++ ){
        if (nimMhs[i] >= 48 && nimMhs[i]<=57){
            continue;
        } else {
            check=1;
            break;
        }
	}

	if(check==1){
		printf("NIM Mahasiswa Harus dalam Bentuk Angka!\n");
		fflush(stdin);
		inputNim();
	}else{
		printHasil();
	}
}

int cekSlot(void){
	int validNim;
	FILE *fp;
	fp = fopen("dataMahasiswa.txt","r");
	if(fp == NULL){
		fclose(fp);
		return 1;
	}else{
		while(fgets(cekNim,255,fp)){
			changeEndl();
			if(strcmp(cekNim,nimMhs) == 0){
				printf("Data yang diinputkan Sudah Terdaftar!\n\a");
				fclose(fp);
				return 0;
			}
		}
		fclose(fp);
		return 1;
	}
}

void printHasil(void){
	int hasil;
	hasil = cekSlot();
	if(hasil){
		FILE *fq;
		fq=fopen("dataMahasiswa.txt","a+");
		fprintf(fq,"%s\n", namaMhs);
		fprintf(fq,"%s\n", nimMhs);
		fclose(fq);
		printf("Data Berhasil Ditambahkan\n");
	}
}

void restart (void)
{
    char reset;
    printf("\nIngin Kembali Ke Menu Awal?\n\n");
    printf("[1]. Kembali Ke Menu Awal\n");
    printf("[2]. Keluar\n");
    printf("Pilihan Anda : ");
    scanf("%c", &reset);
    if(reset=='1')
    {
        system("cls");
        menu();
    }else if(reset=='2')
    {
        system("cls");
        printf("Terimakasih, Sampai jumpa!");
    }else{
        printf("\nPilihan Tidak Tersedia\n");
        restart();
    }
}

void tampilkan(void){
	int i=0,j,k,l, panjang;
    struct tampil{
        char name[100];
        char nim[20];
    };
    struct tampil out[1000];
    struct tampil temp;
    FILE *fp;
    fp=fopen("dataMahasiswa.txt","r");
    while(fgets(out[i].name,255,fp)){
        panjang = strlen(out[i].name);
        out[i].name[panjang-1]='\0';
        fgets(out[i].nim,255,fp);
        panjang = strlen(out[i].nim);
        out[i].nim[panjang-1]='\0';
        i++;

    }
    for (k = 0; k < i-1; k++)
         for (j = 0; j < i-k-1; j++)
            if (atof(out[j].nim) > atof(out[j+1].nim)){
                temp = out[j];
                out[j] = out[j+1];
                out[j+1] = temp;
    }
    system("cls");
    printf("=======================================\n");
    printf("====         Data Mahasiswa        ====\n");
    printf("=======================================\n\n");
    for(l=0 ; l<i ; l++){
        printf("Nama Mahasiswa : %s\n", out[l].name);
        printf("NIM Mahasiswa  : %s\n\n", out[l].nim);
    }
    fclose(fp);
	fflush(stdin);
    i=0;
}

void clear_buffer(){
    char c;
    while ((c = getchar()) != '\n' && c != EOF) ;
}

void changeEndl (void){
	int i;
	for(i=0 ; cekNim[i]!='\n' ; i++);
		cekNim[i]='\0';
}

int input(int *select){
    char buff[1024];
    char term;
    if(fgets(buff, sizeof(buff), stdin) != NULL && sscanf(buff, "%d %c", select, &term) == 1){
        return 1;
    }
    printf("Inputan Salah, Masukan Angka!\n");
    return 0;
}

int validation(int *var, char *prompt){
    while(1){
        printf(prompt);
        if(input(var))
        break;
    }
}

