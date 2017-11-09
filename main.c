#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *dizi = "bugun hava cok guzel";

void dizi_uzunlugu()
{
    system("CLS");
    printf("%d\n", strlen(dizi));
}

void kelime_kelime_ayirma()
{
    system("CLS");
    int i = 0;

    while(dizi[i] != '\0')
    {
        if(dizi[i] == ' ')
            printf("\n");
        else
            printf("%c", dizi[i]);

        i += 1;
    }
    printf("\n");
}

void tersten_yazdirma()
{
    system("CLS");
    int i;

    for(i = strlen(dizi)-1; i >= 0; --i)
        printf("%c", dizi[i]);
    printf("\n");
}

void en_cok_tekrar_eden()
{
    system("CLS");
    int j, a, b, c;
    int i = 0;
    char *hafiza = "abcdefghijklmnopqrstuvwyzx";
    int kayit[50];

    while(hafiza[i] != '\0')
    {
        kayit[i] = hafiza[i];
        kayit[i] = 1;
        i += 1;
    }
    kayit[i] = '\0';

    for(i = 0; dizi[i] != '\0'; ++i)
    {
        for(j = 0; hafiza[j]; ++j)
        {
            if(dizi[i] == hafiza[j])
                kayit[j] += 1;
        }
    }

    a = kayit[0];

    for (i = 1; kayit[i] != '\0'; ++i)
    {
        b = kayit[i];

        if(a > b)
            c = a;
        else
        {
            c = b;
            a = b;
        }

    }

    for(i = 0; kayit[i] != '\0'; ++i)
    {
        if(kayit[i] == c)
            break;
    }

    printf("En cok tekrar eden karakter = %c\n", hafiza[i]);
    printf("Takrar sayisi = %d\n", kayit[i]-1);
}

void kelime_degisme()
{
    system("CLS");
    char ara_kelime[10];
    char yerel_dizi_basi[20] = "bugun hava ";
    char yerel_dizi_sonu[20] = " guzel";
    char yerel_dizi[50];


    printf("Cok yerine yazmak istediginiz kelime: ");
    scanf("%s", &ara_kelime);

    strcat(yerel_dizi_basi, ara_kelime);
    strcat(yerel_dizi_basi, yerel_dizi_sonu);

    printf("%s\n", yerel_dizi_basi);
}

int main()
{
    int secim;

    Tekrar:

    printf("\nDizi uzerinde yapmak istediginiz islemi seciniz: \n");
    printf("\n1 - Dizi uzunlugunu yazdir\n");
    printf("2 - Dizinin kelimelerini ayir\n");
    printf("3 - Diziyi tersten yazdir\n");
    printf("4 - Dizide en cok tekrar eden karakteri yazdir\n");
    printf("5 - Dizideki cok kelimesini degistir\n");
    printf("0 - Cikis yap\n");

    scanf("%d", &secim);

    switch(secim)
    {
        case 1: dizi_uzunlugu(); goto Tekrar;
        case 2: kelime_kelime_ayirma(); goto Tekrar;
        case 3: tersten_yazdirma(); goto Tekrar;
        case 4: en_cok_tekrar_eden(); goto Tekrar;
        case 5: kelime_degisme(); goto Tekrar;
        case 0: goto Son;
        default: system("CLS"); goto Tekrar;

    }
        Son:
            printf("\n\t\t\tFatih Kahraman");
    return 0;
}
