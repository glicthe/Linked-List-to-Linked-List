// Nama: Fauzan Juniar Mulyana 
// Kelas: 1A-D4
// Prodi: D4 Teknik informatika
// Tanggal: 5 April 2025
// Nama File: Case6.c
#include "Case6.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Kota *headKota = NULL;
Kota *tailKota = NULL;
int jumlahKota = 0;

Kota* isKotaExist(const char *kt) {
    Kota *current = headKota;
    while (current != NULL) {
        if (strcasecmp(kt(current), kt) == 0) {
            return current;
        }
        current = next(current);
    }
    return NULL;
}

void insertKota(char *kt) {
    Kota *newNode = (Kota*)malloc(sizeof(Kota));
    strcpy(kt(newNode), kt);
    list(newNode) = createList();
    next(newNode) = NULL;
    prev(newNode) = tailKota;

    if (tailKota != NULL) {
        next(tailKota) = newNode;
    } else {
        headKota = newNode;
    }
    tailKota = newNode;
    jumlahKota++;
}

void deleteKota(Kota *node) {
    if (node == NULL) return;

    if (prev(node) != NULL) {
        next(prev(node)) = next(node);
    } else {
        headKota = next(node); 
    }

    if (next(node) != NULL) {
        prev(next(node)) = prev(node);
    } else {
        tailKota = prev(node); 
    }

    deleteList(&list(node));
    
    free(node);
    jumlahKota--;
}

void insertNamaKeKota(Kota *kotaPtr, char *nm) {
    if (kotaPtr == NULL) {
        printf("Kota tidak valid!\n");
        return;
    }
    InsertAkhir(&kotaPtr->p, nm);
}

int hapusNamaGlobal(const char *nm) {
    int totalDeleted = 0;
    Kota *currentCity = headKota;

    while (currentCity != NULL) {
        List *L = &list(currentCity);
        address prev = NULL;
        address current = first(*L);

        while (current != NULL) {
            if (strcasecmp(nm(current), nm) == 0) {
                address toDelete = current;
                if (prev == NULL)
                    first(*L) = q(current);
                else
                    q(prev) = q(current);

                current = q(current);
                free(toDelete);
                totalDeleted++;
            } else {
                prev = current;
                current = q(current);
            }
        }
        currentCity = next(currentCity);
    }

    return totalDeleted;
}

void tampilkanSemuaKota() {
    Kota *current = headKota;
    while (current != NULL) {
        printf("%s", kt(current));
        address namaCurrent = first(list(current));
        while (namaCurrent != NULL) {
            printf(" -> %s", nm(namaCurrent));
            namaCurrent = q(namaCurrent);
        }
        printf("\n");
        current = next(current);
    }
}

void tampilkanKota(char *inputKt) {
    Kota *current = headKota;
    int found = 0;
    while (current != NULL) {
        if (strcasecmp(kt(current), inputKt) == 0) {
            printf("%s", kt(current));
            address namaCurrent = first(list(current));
            while (namaCurrent != NULL) {
                printf(" -> %s", nm(namaCurrent));
                namaCurrent = q(namaCurrent);
            }
            printf("\n");
            found = 1;
            break;
        }
        current = next(current);
    }
    if (!found)
        printf("Kota '%s' tidak ditemukan\n", inputKt);
}

void tampilkanSemuaDataSebelumInput() {
    printf("\n=== DATA SAAT INI ===\n");
    tampilkanSemuaKota();
    printf("=====================\n\n");
}
