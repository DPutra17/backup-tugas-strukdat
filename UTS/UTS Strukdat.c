#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//========================================================

struct node {
    int data;
    char nama[50];
    char jenisKelamin[10];
    struct node *next;
};
typedef struct node node;


void tambahAwal(node **pList);
void tambahData(node **pList);
void hapusAwal(node **pList);
void hapusData(node **pList);
void tranverse(node *pList);
void countData(node *pList);

//========================================================

int main() {
    node *pList = NULL;
    int pilih;
    do {
        system("cls");
        printf("Masukkan pilihan\n");
        printf("1. Tambah data di awal\n");
        printf("2. Tambah data di tengah\n");
        printf("3. Hapus data di awal\n");
        printf("4. Hapus data di tengah\n");
        printf("5. Cetak isi list\n");
        printf("6. Hitung jumlah data dalam list\n");
        printf("MASUKKAN PILIHAN (isi 99 untuk keluar) : ");
        fflush(stdin);
        scanf("%d", &pilih);
        if (pilih == 1)
            tambahAwal(&pList);
        else if (pilih == 2)
            tambahData(&pList);
        else if (pilih == 3)
            hapusAwal(&pList);
        else if (pilih == 4)
            hapusData(&pList);
        else if (pilih == 5) {
            tranverse(pList);
        } else if (pilih == 6) {
            countData(pList);
            getch();
        }
    } while (pilih != 99);
    return 0;
}

//========================================================

void tambahAwal(node **pList) {
    int bil;
    char nama[50], jenisKelamin[10];
    node *pNew, *pWalker;

    system("cls");
    fflush(stdin);
    printf("Masukkan bilangan : ");
    scanf("%d", &bil);

    printf("Masukkan nama : ");
    fflush(stdin);
    scanf("%s", nama);

    printf("Masukkan jenis kelamin : ");
    fflush(stdin);
    scanf("%s", jenisKelamin);

    pNew = (node *)malloc(sizeof(node));
    if (pNew != NULL) {
        pNew->data = bil;
        strcpy(pNew->nama, nama);
        strcpy(pNew->jenisKelamin, jenisKelamin);

        if (*pList == NULL) {
            pNew->next = pNew;
            *pList = pNew;
        } else {
            pWalker = *pList;
            while (pWalker->next != *pList) {
                pWalker = pWalker->next;
            }
            pWalker->next = pNew;
            pNew->next = *pList;
            *pList = pNew;
        }
    } else {
        printf("Alokasi memori gagal");
        getch();
    }
}

//========================================================

void tambahData(node **pList) {
    int pos, bil;
    char nama[50], jenisKelamin[10];
    node *pNew, *pCur;

    system("cls");
    tranverse(*pList);
    printf("\nPosisi penyisipan setelah data bernilai : ");
    fflush(stdin);
    scanf("%d", &pos);
    printf("Masukkan bilangan : ");
    fflush(stdin);
    scanf("%d", &bil);
    printf("Masukkan nama : ");
    fflush(stdin);
    scanf("%s", nama);
    printf("Masukkan jenis kelamin : ");
    fflush(stdin);
    scanf("%s", jenisKelamin);

    pNew = (node *)malloc(sizeof(node));
    if (pNew != NULL) {
        pNew->data = bil;
        strcpy(pNew->nama, nama);
        strcpy(pNew->jenisKelamin, jenisKelamin);

        pCur = *pList;
        while (pCur->data != pos && pCur->next != *pList) {
            pCur = pCur->next;
        }

        if (pCur->data == pos) {
            pNew->next = pCur->next;
            pCur->next = pNew;
        } else {
            printf("\nNode tidak ditemukan");
            free(pNew);
            getch();
        }
    } else {
        printf("Alokasi memori gagal");
        getch();
    }
}

//========================================================

void hapusAwal(node **pList) {
    if (*pList == NULL) {
        printf("List kosong, tidak ada data yang dapat dihapus\n");
        getch();
        return;
    }

    node *temp = *pList;
    node *pWalker = *pList;

    if (pWalker->next == *pList) {
        *pList = NULL;
    } else {
        while (pWalker->next != *pList) {
            pWalker = pWalker->next;
        }
        pWalker->next = (*pList)->next;
        *pList = (*pList)->next;
    }

    free(temp);
    system("cls");
    printf("Node pertama telah dihapus\n");
    getch();
}

//========================================================

void hapusData(node **pList) {
    int pos;
    node *pCur, *pPrev;

    system("cls");
    tranverse(*pList);
    printf("\nMasukkan data yang ingin dihapus: ");
    fflush(stdin);
    scanf("%d", &pos);

    if (*pList == NULL) {
        printf("List kosong, tidak ada data yang dapat dihapus\n");
        getch();
        return;
    }

    pCur = *pList;
    if (pCur->data == pos) {
        hapusAwal(pList);
        return;
    }

    while (pCur->data != pos && pCur->next != *pList) {
        pPrev = pCur;
        pCur = pCur->next;
    }

    if (pCur->data == pos) {
        pPrev->next = pCur->next;
        free(pCur);
    } else {
        printf("\nNode tidak ditemukan");
        getch();
    }

    system("cls");
    printf("Node dengan data %d telah dihapus\n", pos);
    getch();
}

//========================================================

void tranverse(node *pList) {
    node *pWalker;
    system("cls");
    if (pList == NULL) {
        printf("List kosong.\n");
        getch();
        return;
    }

    printf("List berisi:\n");
    pWalker = pList;
    do {
        printf("Data: %d, Nama: %s, Jenis Kelamin: %s -> ", pWalker->data, pWalker->nama, pWalker->jenisKelamin);
        pWalker = pWalker->next;
    } while (pWalker != pList);

    printf("Data: %d, Nama: %s, Jenis Kelamin: %s -> ", pWalker->data, pWalker->nama, pWalker->jenisKelamin);
    getch();
}


//========================================================

void countData(node *pList) {
    int count = 0;
    node *pWalker;

    system("cls");
    if (pList == NULL) {
        printf("List kosong.\n");
        getch();
        return;
    }

    pWalker = pList;
    do {
        count++;
        pWalker = pWalker->next;
    } while (pWalker != pList);

    printf("\nTotal jumlah node dalam linked list: %d\n", count);
    getch();
}

