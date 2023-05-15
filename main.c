#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Kar��la�t�rma fonksiyonu
int karsilastir(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Binary Search algoritmas�
int binarySearch(int dizi[], int elemanSayisi, int aranan) {
    int sol = 0;
    int sag = elemanSayisi - 1;

    while (sol <= sag) {
        int orta = sol + (sag - sol) / 2;

        if (dizi[orta] == aranan)
            return orta;
        else if (dizi[orta] < aranan)
            sol = orta + 1;
        else
            sag = orta - 1;
    }

    return -1;
}

int main() {
	setlocale(LC_ALL, "turkish");
    int dizi[] = { 4, 8, 3, 84, 47, 76, 9, 24, 68 };
    int elemanSayisi = sizeof(dizi) / sizeof(dizi[0]);
    int aranan, sonuc;

    // Diziyi s�ralama
    qsort(dizi, elemanSayisi, sizeof(int), karsilastir);

    printf("Aranacak eleman� girin: ");
    scanf("%d", &aranan);

    sonuc = binarySearch(dizi, elemanSayisi, aranan);

    if (sonuc == -1)
        printf("Eleman bulunamad�.\n");
    else
        printf("Eleman %d. indekste bulundu.\n", sonuc);

    return 0;
}

