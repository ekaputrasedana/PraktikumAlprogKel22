#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void cover();
void seedarray(int arr[], int n);
void duparray(int source[],int target[],int n);
void printarray(int arr[], int n);
void bubblesort(int arr[], int n);
void bubblepointer(int arr[], int n);
void swap(int *i1, int *i2);
float hitungBubbleSort(int arr[], int n);
float hitungBubbleSortPointer(int arr[], int n);
int validasiulangprogram();
int validInt(int *var);
int ulangprogram();
void keluar();
int main();


void cover(){
    printf("===============================================\n");
    printf(">            PROGRAM BUBBLE SORT              <\n");
    printf(">                KELOMPOK 22                  <\n");
    printf("===============================================\n");
    printf(">                 Anggota :                   <\n");
    printf(">         I Made Bagus Wahyu Mahendra         <\n");
    printf(">         I Gusti Ngurah Yuwanda Ryan         <\n");
    printf(">         Ni Putu Nadila Sinthadewi           <\n");
    printf(">         I Kadek Bagus Tresna Verdhyawan     <\n");
    printf(">         Ni Wayan Devi Pratiwi               <\n");
    printf(">         I Putu Eka Putra Sedana             <\n");
    printf("===============================================\n");

    printf(">===========  MENU BUBBLESORT KEL 22  ========<\n");
    printf(">1. 1000 Angka                                <\n");
    printf(">2. 16000 Angka             	              <\n");
    printf(">3. 64000 Angka                               <\n");
    printf(">4. Keluar                                    <\n");
    printf(">=============================================<\n");
}


void seedarray(int arr[], int n){
    int i;
    srand(0);
    for (i=0;i < n;i++){
        arr[i] = rand();
    }
}

void duparray(int source[],int target[],int n){
    int i;

    for (i = 1;i <= n;i++){
        target[i] = source[1];
    }
}

void printarray(int arr[], int n){
   int i;

    for (i=1;i <=n;i++){
       printf("\n-Angka ke-%d : %d", i, arr[i]);
    }
}

void bubblesort(int arr[], int n){
    int i, j, temp;

    for (i = 0;i < n;i++){
        int flag = 0;
        for (j = 0;j < n;j++){
            if(arr[j] > arr[j+1]){
            temp = arr[j];
            arr[j]=arr[j+1];
            arr[j+1] = temp;
            }
        }
    }
}

void bubblepointer(int arr[], int n){
    int i, j;
    for (i=0;i<n;i++){
    int flag = 0;
        for (j = 0;j < n;j++){
            if(arr[j] > arr[j+1]){
            swap(& arr[j], & arr[j+1]);
            flag = 1;
            }
        }
    }
}

void swap(int *i1, int *i2){
int temp = *i1;
*i1 = * i2;
*i2  = temp;
}

float hitungBubbleSort(int arr[], int n){

clock_t start = clock();
bubblesort(arr, n);
clock_t end = clock();
float detik = (float)(end - start) / CLOCKS_PER_SEC;
return detik;
}

float hitungBubbleSortPointer(int arr[], int n){
clock_t start = clock();
bubblepointer(arr, n);
clock_t end = clock();
float detik = (float)(end - start) / CLOCKS_PER_SEC;
return detik;
}

int validasiulangprogram(){
    int nilai;
    int check;

    if(scanf("%i%c", &nilai, &check) != 2 || check != '\n'){
    fflush(stdin);
    printf("Nilai yang anda masukkan tidak valid!\n");
    printf("Silahkan masukkan ulang :\n");
    return nilai;
    }

    else if(nilai < 0 || nilai >3){
    printf("Nilai yang anda masukkan tidak valid!\n");
    printf("Silahkan pilih antara 1-2 :");
    return nilai;
    }
    else{
    return nilai;}
}

int validInt(int *var){
	char buff[1024];
	char check;
	if (fgets(buff, sizeof(buff), stdin) !=NULL) {
		if (sscanf(buff, "%d %c", var, &check) ==1){
			return 1;
		}
	}
	return 0;
}

int ulangprogram(){
int pilih;

    system("cls");
    printf("Ingin mengulang program?\n");
    printf("1 iya,\t\t 2 tidak\n");
    printf("Masukkan angka yang anda pilih");
    pilih = validasiulangprogram();
    system("cls");
    if(pilih==2){
        printf ("Terimakasih telah menggunakan program kami");
        }
    else {
    main();
    }
}

void keluar(){
printf("Terima kasih telah menggunakan program kami");
}

int main(){

int n, pilihan;
char menu, cek;

    cover ();
    printf("Masukkan pililhan menu untuk di sorting : ");
    if (!validInt(&pilihan)){
            //validasiulangprogram();
            system("cls");
            main();
        }else{
            if (pilihan == 1){
                n = 1000;
            }else if (pilihan == 2){
                n = 16000;
            }else if (pilihan == 3){
                n = 64000;
            }else if (pilihan == 4){
            	//system("clear");
                keluar();
                exit(0);
            }else{
                printf("Input Invalid)");
                system("pause");
                system("cls");
                //sleep(1);
                //system("clear");
                main();
            }
        }


    system("cls");
    int arr[n];
    int arr2[n];
    seedarray(arr, n);
    printf("Memuat %d data acak", n);
    printarray(arr,n);
    duparray(arr, arr2, n);

    float detik1 = hitungBubbleSortPointer(arr, n);
    float detik2 = hitungBubbleSort(arr2, n);
    printf("\n\n");

    printf("\nTekan enter untuk mengurutkan data\n");
    system("pause");
    system("cls");
    printf("\nMenampilkan %d data yang telah disorting");
    printarray(arr, n);

    printf("\nBubble Sort Cara Biasa : %f\n", detik2);
    printf("Bubble Sort Pointer    : %f\n\n", detik1);

    if (detik1 == detik2) {
        printf("\nBubble Sort tanpa Pointer dengan Bubble Sort Pointer sama cepatnya");
    }
    else if (detik1<detik2) {
        printf("\nBubble Sort pointer yang paling cepat\n");
    }
    else if (detik1>detik2){
        printf("\nBubble Sort tanpa pointer yang paling cepat\n");
    }

system("pause");
ulangprogram();

}

