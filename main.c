// Nama: Fauzan Juniar Mulyana 
// Kelas: 1A-D4
// Prodi: D4 Teknik informatika
// Tanggal: 5 April 2025
// Nama File: main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Case6.h"

int main() {
    int pilihan, i;
    char inputKota[NAMA], inputNama[NAMA];

    insertKota("Bandung");
    insertKota("Jakarta");
    insertKota("Depok");
    insertKota("Garut");
    insertKota("Bogor");

    do {
        printf("\nMenu:\n1. Entry Nama\n2. Delete Nama\n3. Delete Kota\n4. Tampilkan data\n5. Keluar\nPilihan: ");
        scanf("%d", &pilihan);
        clearBuffer();

        switch (pilihan) {
            case 1: {
                tampilkanSemuaDataSebelumInput();
                getNonEmptyInput("Masukkan nama kota: ", inputKota, NAMA);
                inputKota[strcspn(inputKota, "\n")] = '\0';

                Kota *currentKota = isKotaExist(inputKota);
                if (!currentKota) {
                    for(i = 0; inputKota[i]; i++) {
                        if(i == 0 || inputKota[i-1] == ' ')
                            inputKota[i] = toupper(inputKota[i]);
                        else
                            inputKota[i] = tolower(inputKota[i]);
                    }
                    insertKota(inputKota);
                    currentKota = tailKota;
                }

                getNonEmptyInput("Masukkan nama: ", inputNama, NAMA);
                inputNama[strcspn(inputNama, "\n")] = '\0';

                for(i = 0; inputNama[i]; i++) {
                    if(i == 0 || inputNama[i-1] == ' ')
                        inputNama[i] = toupper(inputNama[i]);
                    else
                        inputNama[i] = tolower(inputNama[i]);
                }

                insertNamaKeKota(currentKota, inputNama);
                printf("Nama Berhasil Ditambahkan");
                waitForEnter();
                break;
            }
            case 2: {
                tampilkanSemuaDataSebelumInput();
                getNonEmptyInput("Masukkan nama yang akan dihapus: ", inputNama, NAMA);
                inputNama[strcspn(inputNama, "\n")] = '\0';

                int deletedCount = hapusNamaGlobal(inputNama);
                if (deletedCount > 0)
                    printf("Berhasil menghapus %d entri nama '%s'\n", deletedCount, inputNama);
                else
                    printf("Nama '%s' tidak ditemukan\n", inputNama);
                waitForEnter();
                break;
            } 
			case 3: {
    			tampilkanSemuaDataSebelumInput();
			    getNonEmptyInput("Masukkan kota yang akan dihapus: ", inputKota, NAMA);
    
    			// Case-insensitive search
    			Kota *kotaToDelete = isKotaExist(inputKota);
    
    			if (kotaToDelete) {
        			deleteKota(kotaToDelete);
        			printf("Kota '%s' berhasil dihapus!\n", inputKota);
    			} else {
        			printf("Kota '%s' tidak ditemukan!\n", inputKota);
    			}
    			waitForEnter();
    			break;
			}			
            case 4: {
                int subPilihan;
                printf("\nTampilkan Data:\n1. Tampilkan Semua Kota\n2. Cari Salah Satu Kota\nPilihan: ");
                scanf("%d", &subPilihan);
                clearBuffer();

                if (subPilihan == 1) {
                    printf("\nData Seluruh Kota:\n");
                    tampilkanSemuaKota();
                } else if (subPilihan == 2) {
                    char cariKota[NAMA];
                    printf("Masukkan nama kota: ");
                    fgets(cariKota, NAMA, stdin);
                    cariKota[strcspn(cariKota, "\n")] = '\0';
                    printf("\nHasil Pencarian:\n");
                    tampilkanKota(cariKota);
                } else
                    printf("Pilihan tidak valid!\n");
                waitForEnter();
                break;
            }
            case 5:
                exit(0);
            default:
                printf("Pilihan tidak valid!\n");
        }
        clearScreen();
    } while (1);
    return 0;
}
