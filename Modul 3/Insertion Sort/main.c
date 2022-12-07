#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int validasiInt();
void cetakArray();
void salinArray();
void seedArray();
void seedArraySearching();
int partition();
void quickSort();
void insertionSort();
void bubbleSort();
void pilihanMenu();
void Sorting();
double sequentialSearch();
double binarySearch();
void Searching();
void cetakQuit();
void error();

int validasiInt(int *var)
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

void cetakArray(int arr[], int n)
{
    int i;
    for (i = 1; i <= n; i++)
    {
        printf("Angka ke-%d : %d", i, arr[i]);
        printf("\n");
    }
}

void salinArray(int asal[], int target[], int n)
{
    int i;
    for (i - 0; i < n; i++)
    {
        target[i] = asal[i];
    }
}

void seedArray(int arr[], int n)
{
    int i;
    srand(time(NULL));
    for (i = 0; i < n; i++)
    {
        arr[i] = rand() %64000;
    }
}

void seedArraySearching(int arr[], int n)
{
    int i;
    srand(time(NULL));
    for (i = 0; i < n; i++)
    {
        arr[i] = rand() %1000;
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int temp;
    int i = (low - 1);
    int j;
    for (j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    int pi = partition(arr, low, high);
    if (low < high)
    {
        pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void insertionSort(int arr[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];

        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void pilihanMenu()
{
    printf("=                [1] 1000               =\n");
    printf("=                [2] 16000              =\n");
    printf("=                [3] 64000              =\n");
    printf("=========================================\n");
}

void Sorting()
{
    clock_t waktu, waktu1;
    double detik1, detik2, detik3;
    int i, n, pilihan;

    system("cls");
    printf("=========================================\n");
    printf("=              MENU SORTING             =\n");
    printf("=========================================\n");
    pilihanMenu();
    printf("\nMasukkan pilihan: ");
    if (!validasiInt(&pilihan))
    {
        printf("\nError.., Input Tidak Valid!\n");
        sleep(1);
        Sorting();
    }
    else
    {
        if (pilihan == 1)
        {
            n = 1000;
        }
        else if (pilihan == 2)
        {
            n = 16000;
        }
        else if (pilihan == 3)
        {
            n = 64000;
        }
        else
        {
            printf("\nError.., Input Tidak Valid!\n");
            sleep(1);
            system("cls");
            error();
        }
    }
    int arr1[n];
    int arr2[n];
    int arr3[n];

    seedArray(arr1, n);
    printf("\nArray %d data random sebelum disort:\n", n);
    cetakArray(arr1, n);
    salinArray(arr1, arr2, n);
    salinArray(arr1, arr3, n);

    waktu = clock();
    insertionSort(arr1, n);
    waktu1 = clock();
    detik1 = (double)(waktu1 - waktu) / CLOCKS_PER_SEC;

    waktu = clock();
    bubbleSort(arr2, n);
    waktu1 = clock();
    detik2 = ((double) (waktu1 - waktu)) / CLOCKS_PER_SEC;

    waktu = clock();
    quickSort(arr3, 0, n - 1);
    waktu1 = clock();
    detik3 = ((double) (waktu1 - waktu)) / CLOCKS_PER_SEC;
    sleep(2);
    system("pause");
    printf("\n==================================================================================");
    printf("\nArray %d data random sesudah disort:\n", n);
    cetakArray(arr1, n);
    printf("\n==================================================================================");
    printf("\nPerbandingan Waktu:\n");
    printf("Insertion Sort Memerlukan %f Detik Untuk Mensortir Data\n", detik1);
    printf("Bubble Sort Memerlukan %f Detik Untuk Mensortir Data\n", detik2);
    printf("Quick Sort Memerlukan %f Detik Untuk Mensortir Data\n", detik3);
    if (detik1 <= detik2 && detik1 <= detik3)
    {
        printf("\nInsertion Sort yang paling cepat\n");
    }
    else if (detik2 <= detik1 && detik1 <= detik3)
    {
        printf("\nBubble Sort yang paling cepat\n");
    }
    else
    {
        printf("Quick Sort yang paling cepat\n");
    }
    error();
}

double sequentialSearch(int arr[], int n, int angkaDicari)
{
   clock_t waktu;
   double detik;
   int i, counter = 0;

   waktu = clock();
   for (i = 1; i < n; i++)
   {
       if (arr[i] == angkaDicari)
       {
           counter++;
       }
       printf("Angka ke-%d : %d", i, arr[i]);
       printf("\n");
   }
   waktu = clock() - waktu;
   detik = (double)(waktu) / CLOCKS_PER_SEC;
   if (counter == 0)
   {
       printf("\n_____________________________________");
       printf("\nTidak Ada Angka Yang Sesuai, pada sequential search!");
   }
   else
   {
       int indexAngkaDicari[counter];
       counter = 0;

       for (i = 1; i < n; i++)
       {
           if (arr[i] == angkaDicari)
           {
               indexAngkaDicari[counter] = i;
               counter++;
           }
       }
       printf("\n____________________________________");
       printf("\n\nAngka Ditemukan Pada Index sequential search: ");
       for (i = 1; i < counter; i++)
       {
           if (i == 0 && i == counter - 1)
           {
               printf(" %d.", indexAngkaDicari[i]);
           }
           else
           {
               if (i == counter - 1)
               {
                   printf(" %d.", indexAngkaDicari[i]);
               }
               else
               {
                   printf(" %d.", indexAngkaDicari[i]);
               }
           }
       }
   }
   return detik;
}

double binarySearch(int arr[], int low, int high, int angkaDicari)
{
    clock_t waktu;
    double detik;
    int i, counter = 0;

    waktu = clock();
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == angkaDicari)
        {
            counter++;
            for (i = mid + 1; i < high + 1 && arr[i] == angkaDicari; i++)
            {
                counter++;
            }
            for (i = mid - 1; i < high + 1 && arr[i] == angkaDicari; i++)
            {
                counter++;
            }
            break;
        }
        else if (arr[mid] > angkaDicari)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    waktu = clock() - waktu;
    detik = (double)(waktu) / CLOCKS_PER_SEC;

    if (counter == 0)
    {
        printf("\n\nTidak Angka Yang Sesuai pada binary search!");
    }
    else
    {
        int indexAngkaDicari[counter];
        counter = 0;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] == angkaDicari)
            {
                indexAngkaDicari[counter] = mid;
                counter++;
                for (i = mid + 1; i < high + 1 && arr[i] == angkaDicari; i++)
                {
                    indexAngkaDicari[counter] = i;
                    counter++;
                }
                for (i = mid - 1; i > 0 && arr[i] == angkaDicari; i--)
                {
                    indexAngkaDicari[counter] = i;
                    counter++;
                }
                break;
            }
            else if (arr[mid] > angkaDicari)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        printf("\n\nAngka Ditemukan Pada Index binary search: ");
        bubbleSort(indexAngkaDicari, counter);
        for (i = 1; i < counter; i++)
        {
            if (i == 0 && i < counter - 1)
            {
                printf(" %d.", indexAngkaDicari[i]);
            }
            else
            {
                if (i == counter - 1)
                {
                    printf(" %d.", indexAngkaDicari[i]);
                }
                else
                {
                    printf(" %d.", indexAngkaDicari[i]);
                }
            }
        }
    }
    return detik;
}

void Searching()
{
    clock_t waktu;
    double detik1, detik2;
    int i, n;
    int angkaDicari, pilihan;

    system("cls");
    printf("=========================================\n");
    printf("=             MENU SEARCHING            =\n");
    printf("=========================================\n");
    pilihanMenu();
    printf("\nMasukkan pilihan: ");
    if (!validasiInt(&pilihan))
    {
        printf("\nError.., Input Tidak Valid!\n");
        sleep(1);
        Searching();
    }
    else
    {
        if (pilihan == 1)
        {
            n = 1000;
        }
        else if (pilihan == 2)
        {
            n = 16000;
        }
        else if (pilihan == 3)
        {
            n = 64000;
        }
        else
        {
            printf("\nError.., Input Tidak Valid!\n");
            sleep(1);
            system("cls");
            error();
        }
    }
    int arr1[n];
    int arr2[n];
    seedArraySearching(arr1, n);
    cetakArray(arr1, n);

    printf("\nMasukkan Angka Yang Ingin Dicari: ");
    if (!validasiInt(&angkaDicari))
    {
        printf("\nError.., Input Tidak Valid!\n");
        sleep(1);
        Searching();
    }
    else
    {
        if (angkaDicari < 0)
        {
            printf("Inputan tidak boleh dibawah '0'");
        }
        else
        {

        }
    }
    system("cls");

    bubbleSort(arr1, n);
    detik1 = sequentialSearch(arr1, n, angkaDicari);
    detik2 = binarySearch(arr1, 0, n - 1, angkaDicari);

    printf("\n\n==================================================================================");
    printf("\n\nPerbandingan Waktu: \n");
    printf("\nSequential Search Membutuhkan %f Detik Untuk Mencari Data", detik1);
    printf("\nBinary Search Membutuhkan %f Detik Untuk Mencari Data\n", detik2);
    if (detik1 <= detik2)
    {
        printf("Sequential Search Lebih Cepat Dari Binary Search\n");
    }
    else
    {
        printf("Binary Search Lebih Cepat Dari Sequential Search\n");
    }
    error();
}

void cetakQuit()
{
    system("cls");
    printf("===============================================\n");
    printf("= TERIMA KASIH TELAH MENGGUNAKAN PROGRAM KAMI =\n");
    printf("===============================================\n");
}

int main()
{
    int pilihan;
    system("cls");
    printf("<===================================================>\n");
    printf("<            PROGRAM SORTING DAN SEARCHING          >\n");
    printf("<                    KELOMPOK 22                    >\n");
    printf("<===================================================>\n");
    printf("<                    Daftar Menu                    >\n");
    printf("<                   [1] Sorting                     >\n");
    printf("<                   [2] Searching                   >\n");
    printf("<                   [3] Keluar                      >\n");
    printf("<===================================================>\n");
    printf("\nMasukkan pilihan: ");
    if (!validasiInt(&pilihan))
    {
        printf("\nError.., Input Tidak Valid!\n");
        sleep(1);
        main();
    }
    else
    {
        if (pilihan == 1)
        {
            Sorting();
        }
        else if (pilihan == 2)
        {
            Searching();
        }
        else if (pilihan == 3)
        {
            cetakQuit();
            exit(0);
        }
        else
        {
            printf("\nError.., Input Tidak Valid!\n");
            error();
        }
    }
}

void error()
{
    int pilihan;
    printf("\n___________________________________________________\n");
    printf("\nSilahkan memilih langkah selanjutnya\n");
    printf(" [1] Kembali ke Menu Utama\n");
    printf(" [2] Keluar\n");
    printf("\nMasukkan pilihan: ");
    if (!validasiInt(&pilihan))
    {
        printf("\nError.., Input Tidak Valid!\n");
        error();
    }
    else
    {
        if (pilihan == 1)
        {
            main();
        }
        else if (pilihan == 2)
        {
            cetakQuit();
        }
        else
        {
            printf("\nError.., Input Tidak Valid!\n");
            error();
        }
    }
}

