// Nama: Fauzan Juniar Mulyana 
// Kelas: 1A-D4
// Prodi: D4 Teknik informatika
// Tanggal: 5 April 2025
// Nama File: config.h
#ifndef BOOLEAN_H
#define BOOLEAN_H
#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef enum { false, true } boolean;

void clearBuffer();
void waitForEnter();
void clearScreen();
void getNonEmptyInput(const char *prompt, char *buffer, int bufferSize);

#endif
