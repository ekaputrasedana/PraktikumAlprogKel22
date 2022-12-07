#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char isi[100], temp;
int pilihan, geser, i;
int sleep();
void reset1();
void reset2();

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

void error()
{
	printf("Error, Input Tidak Valid!\n\n");
}

void enkripsi()
{
	fflush(stdin);
	printf("======================================\n");
	printf(">              ENKRIPSI              <\n");
	printf("======================================\n\n");
	printf("Jumlah Pergeseran  : ");
	if (!validInt(&geser))
	{
		error();
		sleep(1);
		system("cls");
		enkripsi();
	}
	printf("Input Plaintext    : ");
	gets(isi);
	for (i = 0; isi[i] != '\0'; ++i)
	{
		temp = isi[i];
		if (temp >= 'a' && temp <= 'z')
		{
			temp = temp + geser;
			if (temp > 'z')
			{
				temp = temp - 'z' + 'a' - 1;
			}
			isi[i] = temp;
		}
		else if (temp >= 'A' && temp <= 'Z')
		{
			temp = temp + geser;
			if (temp > 'Z')
			{
				temp = temp - 'Z' + 'A' - 1;
			}
			isi[i] = temp;
		}
	}
	printf("\n======================================\n");
	printf("Hasil Enkripsi     : %s\n", isi);
	printf("======================================\n\n");
	reset2();
}

void dekripsi()
{
	fflush(stdin);
	printf("======================================\n");
	printf(">               DEKRIPSI             <\n");
	printf("======================================\n\n");
	printf("Jumlah Pergeseran : ");
	if (!validInt(&geser))
	{
		error();
		sleep(1);
		system("cls");
		dekripsi();
	}
	printf("Input Ciphertext  : ");
	gets(isi);
	for (i = 0; isi[i] != '\0'; ++i)
	{
		temp = isi[i];
		if (temp >= 'a' && temp <= 'z')
		{
			temp = temp - geser;
			if (temp < 'a')
			{
				temp = temp + 'z' - 'a' + 1;
			}
			isi[i] = temp;
		}
		else if (temp >= 'A' && temp <= 'Z')
		{
			temp = temp - geser;
			if (temp < 'A')
			{
				temp = temp + 'Z' - 'A' + 1;
			}
			isi[i] = temp;
		}
	}
	printf("\n======================================\n");
	printf("Hasil Dekripsi    : %s\n", isi);
	printf("======================================\n\n");
	reset1();
}

int main()
{
	fflush(stdin);
	system("cls");
	printf("===================================================\n");
	printf(">           PROGRAM ENKRISPI DAN DEKRIPSI         <\n");
	printf(">                   KELOMPOK 22                   <\n");
	printf("===================================================\n");
	printf(">                   Anggota :                     <\n");
    printf(">           I Made Bagus Wahyu Mahendra           <\n");
    printf(">           I Gusti Ngurah Yuwanda Ryan           <\n");
    printf(">           Ni Putu Nadila Sinthadewi             <\n");
    printf(">           I Kadek Bagus Tresna Verdhyawan       <\n");
    printf(">           Ni Wayan Devi Pratiwi                 <\n");
    printf(">           I Putu Eka Putra Sedana               <\n");
	printf("===================================================\n");
	printf(">                   Daftar Menu                   <\n");
	printf(">                  [1] Enkripsi                   <\n");
	printf(">                  [2] Dekripsi                   <\n");
	printf(">                  [3] Keluar                     <\n");
	printf("===================================================\n");
	printf("Masukkan Pilihan Menu [1-3] : ");

	if (!validInt(&pilihan))
	{
		error();
		sleep(1);
		main();
	}
	switch (pilihan)
	{
	case 1:
		system("cls");
		enkripsi();
		break;
	case 2:
		system("cls");
		dekripsi();
		break;
	case 3:
		system("cls");
		printf("\nTerimakasih Telah Menggunakan Program Ini!");
		exit(0);
		break;
	default:
		error();
		sleep(1);
		system("cls");
		main();
	}
	return 0;
}

void reset1()
{
	char pil[1];
	printf("Lanjut Enkripsi? [Y/N] : ");
	scanf("%s", &pil);

	if (!strcmp(pil, "y") || !strcmp(pil, "Y"))
	{
		system("cls");
		enkripsi();
	}
	else if (!strcmp(pil, "n") || !strcmp(pil, "N"))
	{
		main();
	}
	else
	{
		error();
		sleep(1);
		reset1();
	}
}

void reset2()
{
	char pil[1];
	printf("Lanjut Dekripsi? [Y/X]  : ");
	scanf("%s", &pil);

	if (!strcmp(pil, "y") || !strcmp(pil, "Y"))
	{
		system("cls");
		dekripsi();
	}
	else if (!strcmp(pil, "x") || !strcmp(pil, "X"))
	{
		main();
	}
	else
	{
		error();
		sleep(1);
		reset2();
	}
}