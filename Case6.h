// Nama: Fauzan Juniar Mulyana 
// Kelas: 1A-D4
// Prodi: D4 Teknik informatika
// Tanggal: 5 April 2025
// Nama File: Case6.h
#ifndef CASE6_H
#define CASE6_H
#include "SLL.h"
#define NAMA 20

typedef struct NamaKota {
    char kt[NAMA];
    List p;
    struct NamaKota *next;
    struct NamaKota *prev;
} Kota;

extern Kota *headKota;
extern Kota *tailKota;
extern int jumlahKota;

Kota* isKotaExist(const char *kt);
void insertKota(char *kt);
void deleteKota(Kota *node);
void insertNamaKeKota(Kota *kotaPtr, char *nm);
int hapusNamaGlobal(const char *nm);
void tampilkanSemuaKota();
void tampilkanKota(char *inputKt);
void tampilkanSemuaDataSebelumInput();

/* Aksesor untuk Kota */
#define kt(P) (P)->kt
#define next(P) (P)->next
#define prev(P) (P)->prev
#define list(P) (P)->p

#endif
