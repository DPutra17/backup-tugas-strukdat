#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//========================================================

struct node {
    int data;
    struct node *next;
};
typedef struct node node;

// Function prototypes
void tambahAwal(node **pList);
void tambahData(node **pList);
void hapusAwal(node **pList);
void hapusData(node **pList);
void tranverse(node *pList);
void searchData(node *pList);
void countData(node *pList);
void sumData(node *pList);

//========================================================

int main() {
    node *pList;
    int pilih;

    pList = NULL;
    do {
        system("cls");
        printf("Masukkan pilihan\n");
        printf("1. Tambah data di awal\n");
        printf("2. Tambah data di tengah pList\n");
        printf("3. Hapus data di awal\n");
        printf("4. Hapus data di tengah\n");
        printf("5. Cetak isi pList\n");
        printf("6. Cari data dalam pList\n");
        printf("7. Hitung jumlah data dalam pList\n");
        printf("8. Hitung jumlahan data dalam pList\n");
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
            getch();
        } else if (pilih == 6) {
            searchData(pList);
            getch();
        } else if (pilih == 7) {
            countData(pList);
            getch();
        } else if (pilih == 8) {
            sumData(pList);
            getch();
        }
    } while (pilih != 99);

    return 0;
}

//========================================================

void tambahAwal(node **pList) {
    int bil;
    node *pNew;

    system("cls");
    fflush(stdin);
    printf("Masukkan bilangan : ");
    fflush(stdin);
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));

    pNew->data = bil;

    if (*pList == NULL) {
        pNew->next = pNew;
        *pList = pNew;
    }

    else{
        // Jika alokasi memori gagal
        printf("Alokasi memori gagal");
        getch();
    }
}

//========================================================

void tambahData(node **pList) {
    int pos, bil;
    node *pNew, *pPre;

    system("cls");
    tranverse(*pList);
    printf("\nPosisi penyisipan setelah data bernilai : ");
    fflush(stdin);
    scanf("%d", &pos);
    printf("\nBilangan : ");
    fflush(stdin);
    scanf("%d", &bil);

    if (*pList == NULL) {
        printf("\nList kosong\n");
        return;
    }

    pPre = *pList;

    do {
        if (pPre->data == pos) {
            break;
        }
        pPre = pPre->next;
    } while (pPre != *pList);

    // Jika node yang dicari tidak ditemukan (kembali ke node awal)
    if (pPre->data != pos) {
        printf("\nNode tidak ditemukan\n");
        return;
    }

    // Sisipkan node baru setelah node dengan nilai yang ditemukan

    if (pNew == NULL) {
        printf("\nAlokasi memori gagal\n");
        return;
    }
    else {
    pNew = (node *)malloc(sizeof(node));
    pNew->data = bil;
    pNew->next = pPre->next;
    pPre->next = pNew;
    }
}

//========================================================

void hapusAwal(node **pList) {
    int bil;
    node *pCur, *pPre;

    // Jika pList kosong
    if (*pList == NULL) {
        printf("Tidak ada data yang dapat dihapus\n");
        getch();
        return;
    }
    else {
        // Hapus node pertama
        pPre = *pList;
        while (pPre->next != *pList){
            pPre = pPre->next;
        }
        pCur = *pList;
        *pList = (*pList)->next;
        free(pCur);
        pPre->next = *pList;
        system("cls");
        printf("node awal berhasil dihapus\n");
    }
    getch();
}

//========================================================

void hapusData(node **pList) {
    int bil;
    node *pCur, *pPre;

    system("cls");
    tranverse(*pList);
    printf("\nnilai data yang ingin dihapus : ");
    fflush(stdin);
    scanf("%d", &bil);

    // Jika pList kosong
    if (*pList == NULL) {
        printf("Tidak ada data yang dapat dihapus\n");
        getch();
        return;
    }
    pCur = *pList;
    pPre = NULL;

    // Cari node dengan nilai tertentu
    while(pCur != NULL && pCur->data != bil){
        pPre = pCur;
        pCur = pCur->next;
    }
    // Jika node tidak ditemukan
    if (pCur == NULL) {
        printf("Node dengan nilai %d tidak ditemukan.\n", bil);
        getch();
        return;
    }
    // Hapus node yang ditemukan
    if (pPre == NULL){
        *pList = pCur->next;
    }
    else{
        pPre->next = pCur->next;
    }
    free(pCur);
    system("cls");
    printf("node telah dihapus\n");
    getch();
}

//========================================================

void tranverse(node *pList) {
    node *pWalker;

    system("cls");
    if (pList == NULL) {
        printf("List kosong.\n");
        return;
    }

    printf("List berisi:\n");

    pWalker = pList;
    printf("%d -> ", pWalker->data);
    pWalker = pWalker->next;

    while (pWalker != pList) {
        printf("%d -> ", pWalker->data);
        pWalker = pWalker->next;
    }


    printf("%d\n", pList->data);
}

//========================================================

void searchData(node *pList) {
    int bil;
    node *pCur = pList;

    if (pList == NULL) {
        printf("List kosong.");
        getch();
        return;
    }

    system("cls");
    printf("\nMasukkan data yang dicari: ");
    fflush(stdin);
    scanf("%d", &bil);

    do {
        if (pCur->data == bil) {
            printf("Data %d ditemukan.\n", bil);
            getch();
            return;
        }
        pCur = pCur->next;
    } while (pCur != pList);

    printf("Data tidak ditemukan.\n");
    getch();
}

//========================================================

void countData(node *pList) {
    int count = 0;
    node *pCur = pList;

    if (pList == NULL) {
        printf("Jumlah data dalam list: 0\n");
        getch();
        return;
    }

    do {
        count++;
        pCur = pCur->next;
    } while (pCur != pList);

    printf("Jumlah data dalam list: %d\n", count);
    getch();
}

//========================================================

void sumData(node *pList) {
    int sum = 0;
    node *pCur = pList;

    if (pList == NULL) {
        printf("Perjumlah total dari semua data: 0\n");
        getch();
        return;
    }

    do {
        sum += pCur->data;
        pCur = pCur->next;
    } while (pCur != pList);

    printf("Perjumlah total dari semua data: %d\n", sum);
    getch();
}
