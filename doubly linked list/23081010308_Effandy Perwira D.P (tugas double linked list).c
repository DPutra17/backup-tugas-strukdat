#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//========================================================

struct node {
    int data;
    struct node *right;
    struct node *left;
};
typedef struct node node;

// Function prototypes
void tambahAwal(node **head);
void tambahData(node **head);
void tambahAkhir(node **head);
void hapusAwal(node **head);
void hapusData(node **head);
void hapusAkhir(node **head);
void tranverse(node *head);
void searchData(node *head);
void countData(node *head);
void sumData(node *head);

//========================================================

int main() {
    node *head;
    int pilih;

    head = NULL;
    do {
        system("cls");
        printf("Masukkan pilihan\n");
        printf("1. Tambah data di awal\n");
        printf("2. Tambah data di tengah list\n");
        printf("3. Tambah data di akhir\n");
        printf("4. Hapus data di awal\n");
        printf("5. Hapus data di tengah\n");
        printf("6. Hapus data di akhir\n");
        printf("7. Cetak isi list\n");
        printf("8. Cari data dalam list\n");
        printf("9. Hitung jumlah data dalam list\n");
        printf("10. Hitung jumlahan data dalam list\n");
        printf("MASUKKAN PILIHAN (isi 99 untuk keluar) : ");
        fflush(stdin);
        scanf("%d", &pilih);

        if (pilih == 1)
            tambahAwal(&head);
        else if (pilih == 2)
            tambahData(&head);
        else if (pilih == 3)
            tambahAkhir(&head);
        else if (pilih == 4)
            hapusAwal(&head);
        else if (pilih == 5)
            hapusData(&head);
        else if (pilih == 6)
            hapusAkhir(&head);
        else if (pilih == 7) {
            tranverse(head);
            getch();
        } else if (pilih == 8) {
            searchData(head);
            getch();
        } else if (pilih == 9) {
            countData(head);
            getch();
        } else if (pilih == 10) {
            sumData(head);
            getch();
        }
    } while (pilih != 99);

    return 0;
}

//========================================================

void tambahAwal(node **head) {
    int bil;
    node *pNew;

    system("cls");
    fflush(stdin);
    printf("Masukkan bilangan : ");
    fflush(stdin);
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));

    // Jika alokasi memori berhasil, tambahkan node baru di awal linked list
    if (pNew != NULL) {
        pNew->data = bil;
        pNew->right = *head;
        if (*head != NULL) {
            (*head)->left = pNew;
        }
        pNew->left = NULL;
        *head = pNew;
    }
    else {
        // Jika alokasi memori gagal
        printf("Alokasi memori gagal");
        getch();
    }
}

//========================================================

void tambahAkhir(node **head) {
    int bil;
    node *pNew, *pCur;

    system("cls");
    fflush(stdin);
    printf("Masukkan bilangan : ");
    fflush(stdin);
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));

    // Jika alokasi memori berhasil, tambahkan node baru di akhir linked list
    if (pNew != NULL) {
        pNew->data = bil;
        pNew->right = NULL;
        // Jika list kosong, node baru menjadi node pertama
        if (*head == NULL) {
            *head = pNew;
        }
        // Jika list tidak kosong, cari node terakhir dan tambahkan di belakang
        else {
            pCur = *head;
            while (pCur->right != NULL) {
                pCur = pCur->right;
            }
            pNew->left = pCur;
            pNew->right = pCur->right;
            pCur->right = pNew;
        }
    }
    else {
        // Jika alokasi memori gagal
        printf("Alokasi memori gagal");
        getch();
    }
}

//========================================================

void tambahData(node **head) {
    int pos, bil;
    node *pNew, *pCur;

    system("cls");
    tranverse(*head);
    printf("\nPosisi penyisipan setelah data bernilai : ");
    fflush(stdin);
    scanf("%d", &pos);
    printf("\nBilangan : ");
    fflush(stdin);
    scanf("%d", &bil);

    // Cari node dengan nilai tertentu untuk penyisipan
    pCur = *head;
    while (pCur != NULL && pCur->data != pos) {
        pCur = pCur->right;
    }

    pNew = (node *)malloc(sizeof(node));

    // Jika node yang dicari tidak ditemukan
    if (pCur == NULL) {
        printf("\nNode tidak ditemukan");
        getch();
    } else if (pNew == NULL) {
        // Jika alokasi memori gagal
        printf("\nAlokasi memori gagal");
        getch();
    } else {
        // Sisipkan node baru setelah node dengan nilai yang ditemukan
        pNew->data = bil;
        pNew->left = pCur;
        pNew->right = pCur->right;
        pCur->right->left = pNew;
        pCur->right = pNew;
    }
}

//========================================================

void hapusAwal(node **head) {
    int bil;
    node *pCur;

    // Jika list kosong
    if (*head == NULL) {
        printf("Tidak ada data yang dapat dihapus\n");
        getch();
        return;
    }
    else {
        // Hapus node pertama
        pCur = *head;
        *head = pCur->right;
        pCur->right->left = NULL;
        free(pCur);

        system("cls");
        printf("node awal berhasil dihapus\n");
    }
    getch();
}

//========================================================

void hapusAkhir(node **head) {
    int bil;
    node *pCur;

    // Jika list kosong
    if (*head == NULL) {
        printf("Tidak ada data yang dapat dihapus\n");
        return;
    }

    pCur = *head;

    // Cari node terakhir
    while(pCur->right != NULL){
        pCur = pCur->right;
    }

    if(pCur->left == NULL){
        // Jika hanya ada satu node, hapus node pertama
        free(*head);
        *head = NULL;
    }
    else{
        // Hapus node terakhir
        pCur->left->right = NULL;
        free(pCur);
    }
    system("cls");
    printf("node terakhir telah dihapus\n");
    getch();
}

//========================================================

void hapusData(node **head) {
    int bil;
    node *pCur;

    system("cls");
    tranverse(*head);
    fflush(stdin);
    printf("\nMasukkan nilai node yang ingin dihapus: ");
    scanf("%d", &bil);

    if (*head == NULL) {
        printf("List kosong, tidak ada node yang dapat dihapus.\n");
        getch();
        return;
    }

    pCur = *head;
    while (pCur && pCur->data != bil) {
        pCur = pCur->right;
    }

    if (pCur == NULL) {
        printf("Node dengan nilai %d tidak ditemukan.\n", bil);
        getch();
        return;
    }

    // Jika node dengan 'bil' ditemukan
    if (pCur->left) {
        pCur->left->right = pCur->right;
    }
    else {
        // Jika node yang dihapus adalah node pertama
        *head = pCur->right;
    }
     if (pCur->right){
        pCur->right->left = pCur->left;
    }

    // Bebaskan memori node yang dihapus
    free(pCur);
    printf("Node dengan nilai %d berhasil dihapus.\n", bil);
    getch();
}

//========================================================

void tranverse(node *head){
   //traverse a linked list
	node *pWalker;

   system("cls");
	pWalker = head;
	printf("NULL <-");
	while (pWalker != NULL){
        printf(" %d ", pWalker->data);
        if(pWalker -> right != NULL) {
            printf("<->");
        }
   	pWalker = pWalker->right;
	}
   printf("-> NULL");
}

//========================================================

void searchData(node *head) {
    int target;
    node *pWalker;

    system("cls");
    printf("Masukkan data yang ingin dicari: ");
    scanf("%d", &target);

    pWalker = head;

    // Cari node dengan nilai tertentu
    while (pWalker != NULL) {
        if (pWalker->data == target) {
            printf("Data ditemukan: %d\n", pWalker->data);
            return;
        }
        pWalker = pWalker->right;
    }

    // Jika data tidak ditemukan
    printf("Data tidak ditemukan!\n");
}



//========================================================

void countData(node *head) {
    int count = 0;
    node *pWalker;

    system ("cls");
    pWalker = head;
    // Hitung jumlah node
    while (pWalker != NULL) {
        count++;
        pWalker = pWalker->right;
    }
    system("cls");
    printf("\nTotal data dalam linked list adalah: %d\n", count);
    return count;
}

//========================================================

void sumData(node *head) {
    int sum = 0;
    node *pWalker;

    system ("cls");
    pWalker = head;
    // Hitung jumlah total dari nilai node
    while (pWalker != NULL) {
        sum += pWalker->data;
        pWalker = pWalker->right;
    }
    system("cls");
    printf("\nTotal penjumlahan nilai data dalam linked list adalah: %d\n", sum);
    return sum;
}
