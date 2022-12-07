#include <stdio.h>
#include <string.h>

float input();
void keluar();
void pilihan_ulang();
float perhitungan_median();
int perhitungan_modus();
float perhitungan_mean();
void sorting_nilai();
void median();
void modus();
void mean();
void menu_utama();
int main();

float input(int desimal, int min, int batas_akhir){
    char masukkan[100];
    int i = 0;
    int belakang = 0;
    int isi_depan = 0;
    int isi_belakang = 0;
    int status = 0;
    int titik = 0;
    int minus = 0;
    int salah = 0;
    float hasil;

    scanf("%[^\n]", &masukkan);
    fflush(stdin);

    while(masukkan[i] != '\0'){
        if(masukkan[0] == '.'){
            salah = 1;
            masukkan[0] = '\0';
        }else if(masukkan[i]>='0' && masukkan[i]<='9' || masukkan[i] == '.' || (masukkan[0] == '-' && min == 1)){
            if((masukkan[i] == '.') && (desimal == 1)){
                titik = titik + 1;
                if(titik > 1 || masukkan[i+1] == '\0'){
                    salah = 1;
                    masukkan[i] = '\0';
                }
                status = 1;
            }else if((masukkan[i] == '.') && (desimal == 0)){
                salah = 1;
                masukkan[i] = '\0';
            }

            if(masukkan[0] == '-' && min == 1){
                minus = 1;
            }else if(masukkan[0] == '-' && min == 0){
                salah = 1;
                masukkan[i] = '\0';
            }

            if(masukkan[i]>='0' && masukkan[i]<='9'){
                if(status == 1){
                    isi_belakang = (isi_belakang * 10) + (masukkan[i] - 48);
                    belakang = belakang + 1;
                }else{
                    isi_depan = (isi_depan * 10) + (masukkan[i] - 48);
                }
            }
            i++;
        }else{
            salah = 1;
            masukkan[i] = '\0';
        }
    }
    if(titik == 1){
        hasil = (float)isi_depan + (isi_belakang / (pow(10, belakang)));
    }else{
        hasil = isi_depan;
    }
    if(minus == 1 && min == 1){
        hasil = hasil - (hasil * 2);
    }else if(minus == 1 && min == 0){
        salah = 1;
        masukkan[i] = '\0';
    }

    if(salah == 1){
        printf(" Inputan salah! \n Masukkan angka yang benar : ");
        return input(desimal, min, batas_akhir);
    }else if(min == 0 && hasil == 0){
        printf(" Inputan tidak boleh kosong! \n Masukkan nilai yang benar : ");
        return input(desimal, min, batas_akhir);
    }else if(batas_akhir != 0 && hasil > batas_akhir){
        printf(" Inputan tidak boleh lebih dari %d ! \n Masukkan nilai yang benar : ", batas_akhir);
        return input(desimal, min, batas_akhir);
    }else{
        return hasil;
    }
}

void keluar(){
    printf("\n Terima Kasih Sudah Menggunakan Program Ini  :) \n");
     sleep(1);
    system("exit");
}

void pilihan_ulang(int ulang){
    char huruf_ulang[1];

    printf("\n Apakah Ingin Mengulangi Program ini? ya/menu/keluar(y/n/e) : ");
    scanf("%s", &huruf_ulang);
    fflush(stdin);

    if((strcmp(huruf_ulang, "y") != 0) && (strcmp(huruf_ulang, "n") != 0) && (strcmp(huruf_ulang, "e") != 0)){
        printf(" Inputan anda salah! \n Input dengan benar\n");
        pilihan_ulang(ulang);
    }else if((strcmp(huruf_ulang, "y") == 0)){
        system("cls");
        if(ulang == 1){
            median();
        }else if(ulang == 2){
            modus();
        }else if(ulang == 3){
            mean();
        }
    }else if((strcmp(huruf_ulang, "n") == 0)){
        system("cls");
        menu_utama();
    }else{
        keluar();
    }
}

float perhitungan_median(float data[], int jumlah){
    float hasil;
    int tengah = jumlah / 2;

    if(jumlah % 2 == 0){
        hasil = (data[tengah-1] + data[tengah]) / 2;
    }else{
        hasil = data[tengah];
    }
    return hasil;
}

int perhitungan_modus(float bil[], int jumlah, float mod[]){
    int n_angka[jumlah];
    int i, j;
    int jumlah_tmp;
    int max = 0;
    int z = 0;
    int status;
    int a = 0;

    for(i = 0; i < jumlah; i++){
        mod[i] = 0;
        jumlah_tmp = 0;
        for(j = 0; j < jumlah; j++){
            if(bil[i] == bil[j]){
                jumlah_tmp++;
            }
        }
        if(jumlah_tmp > max){
            max = jumlah_tmp;
        }
        n_angka[i] = jumlah_tmp;
    }


    for(i = 0; i < jumlah; i++){
        status = 0;
        if(n_angka[i] == max){
            z++;
            for(j = 0; j < jumlah; j++){
                if(bil[i] == mod[j]){
                    status = 1;
                }
            }
            if(status == 0){
                mod[a] = bil[i];
                a++;
            }
        }
    }

    if(jumlah == z){
        return 0;
    }else{
        return a;
    }
}

float perhitungan_mean(float data[], int jumlah){
    float hasil = 0;
    int i;

    for(i = 0; i < jumlah; i++){
        hasil = hasil + data[i];
    }

    hasil = hasil / jumlah;

    return hasil;
}

void sorting_nilai(float data[], int jumlah){
    int i, j;
    float temp;
    for(i = 0; i < jumlah - 1; i++){
	    for(j = 0; j < jumlah - 1; j++){
		    if(data[j+1] < data[j]){
			    temp      = data[j];
			    data[j]   = data[j+1];
    			data[j+1] = temp;
		    }
    	}
	}
}

void median(){
    int jumlah;
    int i;
    float hasil_median;
	printf(" =========================================\n");
	printf("|                 MEDIAN                  |\n");
	printf(" =========================================\n");
    printf(" Masukkan jumlah data : ");
    jumlah = input(0, 0, 0);

    float data[jumlah];
    float *alamat;
    alamat = &data;

    printf("\n");
    printf("  Masukkan Data\n");
    for(i = 0; i < jumlah; i++){
        printf("  - Masukkan Data Angka ke-%d : ", i+1);
        alamat[i] = input(1,0,0);
    }

    sorting_nilai(data, jumlah);

    printf("\n");
    printf("  Hasil data terurut\n");
    for(i = 0; i < jumlah; i++){
        printf(" - Angka ke-%d : %.2f\n", i+1, data[i]);
    }

    hasil_median = perhitungan_median(data, jumlah);

    printf("\n");
    printf(" Hasil Median dari data tersebut adalah %.2f\n", hasil_median);
	printf(" =========================================\n");

    pilihan_ulang(1);
}

void modus(){
    int jumlah;
    int i;
    float hasil_modus;
	printf(" =========================================\n");
	printf("|                  MODUS                  |\n");
	printf(" =========================================\n");
    printf(" Masukkan jumlah data : ");
    jumlah = input(0, 0, 0);

    float data[jumlah];
    float *alamat;
    alamat = &data;

    printf("\n");
    printf("  Masukkan Data\n");
    for(i = 0; i < jumlah; i++){
        printf("  - Masukkan Data Angka ke-%d : ", i+1);
        alamat[i] = input(1,0,0);
    }

    float mod[jumlah];

    hasil_modus = perhitungan_modus(data, jumlah, mod);

    printf("\n");
    printf("  Hasil\n");
    if(hasil_modus == 0){
        printf(" Tidak ada modus dalam data tersebut\n");
    }else{
        printf("  Modus : ");
        for(i = 0; i < hasil_modus; i++){
            if(i == 0){
                printf("%.2f", mod[i]);
            }else{
                printf(", %.2f", mod[i]);
            }
        }
    }
	printf("\n =========================================\n");

    pilihan_ulang(2);
}

void mean(){
    int jumlah;
    int i;
    float hasil_mean;
	printf(" =========================================\n");
	printf("|                  MEAN                   |\n");
	printf(" =========================================\n");
    printf(" Masukkan jumlah data : ");
    jumlah = input(0, 0, 0);
    float data[jumlah];
    float *alamat;
    alamat = &data;

    printf("\n");
    printf("  Masukkan Data\n");
    for(i = 0; i < jumlah; i++){
        printf(" - Masukkan Data Angka ke-%d : ", i+1);
        alamat[i] = input(1,0,0);

    }
    hasil_mean = perhitungan_mean(data, jumlah);

    printf("\n");
    printf(" Hasil Mean dari data tersebut adalah %.2f\n", hasil_mean);
	printf(" =========================================\n");

    pilihan_ulang(3);
}

void menu_utama(){
    int pilihan;
	printf("<=========================================>\n");
	printf("|            PROGRAM STATISTIKA           |\n");
    printf("|                KELOMPOK 22              |\n");
	printf("|=========================================|\n");
	printf("|             Menu Pilihan :              |\n");
	printf("|      1. Median                          |\n");
	printf("|      2. Modus                           |\n");
	printf("|      3. Mean                            |\n");
	printf("|      4. Keluar                          |\n");
	printf("<=========================================>\n");
	printf("  Masukkan Pilihan : ");
    pilihan = input(0,0,4);

    if(pilihan == 1){
        system("cls");
        median();
    }else if(pilihan == 2){
        system("cls");
        modus();
    }else if(pilihan == 3){
        system("cls");
        mean();
    }else if(pilihan == 4){
        keluar();
    }
}

int main(){
    system("cls");
    menu_utama();

    return 0;
}
