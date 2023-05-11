#include <stdio.h>
#include <stdlib.h>

typedef struct KUYRUK {
    int sayi;
    struct KUYRUK *sonraki;
} kuyruk;
 
kuyruk *ilk = NULL, *son, *yeni, *sil;
 
void secim();
void ekle(int);
void cikar();
void goruntule();
void bekle(); 


int main() {
 
    while (1) {
        secim();
    }
    return 0;
}
 
void secim() {
    int sayi;
 
    printf("Lutfen asagidaki islemlerden birini seciniz: \n\n");
    printf("1)Ekle\n");
    printf("2)Cikar\n");
    printf("3)Goruntuleme\n");
    printf("4)Cikis\n\n");
    int secenek;
    printf("Sectiginiz islem: ");
    scanf("%d", &secenek);
    
    switch (secenek) {
        case 1:
            printf("Eklemek istediginiz Sayiyi giriniz: ");
            scanf("%d", &sayi);
            ekle(sayi);
            break;
        case 2:
            cikar();
            break;
        case 3:
            goruntule();
            break;
        case 4:
            printf("Program Sonlandirildi!\n");
            exit(0);
            break;
        default:
            printf("Hatali Secim!\n");
    }
    bekle();
}
 
void ekle(int sayi) {
    yeni = (kuyruk*) malloc(sizeof (kuyruk));
    yeni->sayi = sayi;
    yeni->sonraki = NULL;
 
    if (ilk == NULL) {
        ilk = (kuyruk *) malloc(sizeof (kuyruk));
        ilk = yeni;
        son = ilk;
    } else {
        son->sonraki = yeni;
        son = son->sonraki;
    }
 
}
 
void cikar() {
    if (ilk == NULL) {
        printf("Kuyruk bos\n");
    } else {
        sil = (kuyruk*) malloc(sizeof (kuyruk));
        sil = ilk;
        ilk = ilk->sonraki;
        printf("%d Kuyruktan cikarildi\n", sil->sayi);
        free(sil);
    }
 
}
 
void bekle() {
    printf("Devam etmek icin Enter'a basiniz!\n");

    getchar();
    getchar();
 
}
 
void goruntule() {
    if (ilk == NULL) {
        printf("Kuyruk Bos\n");
    } else {
        kuyruk *gecici = ilk;
        while (gecici != NULL) {
            printf("%d ", gecici->sayi);
            gecici = gecici->sonraki;
        }
        printf("\n");
    }
 
}

