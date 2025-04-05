// Nama: Fauzan Juniar Mulyana 
// Kelas: 1A-D4
// Prodi: D4 Teknik informatika
// Tanggal: 5 April 2025
// Nama File: config.c
#include <ctype.h> 
#include "config.h"

// Menunggu user untuk menekan Enter untuk lanjut
void waitForEnter() {
    printf("\nTekan Enter untuk melanjutkan...");
    clearBuffer();
}

// Untuk Clear Buffer
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Membersihkan layar
void clearScreen() {
    system("cls || clear");
}


void getNonEmptyInput(const char *prompt, char *buffer, int bufferSize) {
    int len;
    char *trimmed;
    do {
        printf("%s", prompt);
        fgets(buffer, bufferSize, stdin);
        
        // Hapus newline dan karakter berlebih
        len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        } else {
            clearBuffer();
        }
        
        // Trim spasi di awal dan akhir
        trimmed = buffer;
        while (isspace((unsigned char)*trimmed)) trimmed++;
        char *end = trimmed + strlen(trimmed) - 1;
        while (end > trimmed && isspace((unsigned char)*end)) end--;
        *(end + 1) = '\0';
        
        strcpy(buffer, trimmed);
        
        if (strlen(buffer) == 0) {
            printf("Input tidak boleh kosong!\n");
        } else {
            break;
        }
    } while (1);
}
