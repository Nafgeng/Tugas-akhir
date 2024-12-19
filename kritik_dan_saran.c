#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Tipe data struct untuk kritik/saran
typedef struct {
    char nama[50];
    char kritikSaran[200];
    int jenis; // Ganti enum dengan tipe data integer
} KritikSaran;

// Tipe data union untuk menyimpan data kritik/saran
typedef union {
    KritikSaran data;
    char* pesan;
} DataKritikSaran;

// Fungsi untuk memindahkan memori untuk data kritik/saran
DataKritikSaran* memindahkanDataKritikSaran() {
    return (DataKritikSaran*) malloc(sizeof(DataKritikSaran));
}

// Fungsi untuk memasukkan data kritik/saran
void masukkanDataKritikSaran(DataKritikSaran* data) {
    printf("Masukkan nama: ");
    fgets(data->data.nama, sizeof(data->data.nama), stdin);
    data->data.nama[strcspn(data->data.nama, "\n")] = 0;

    printf("Masukkan kritik/saran: ");
    fgets(data->data.kritikSaran, sizeof(data->data.kritikSaran), stdin);
    data->data.kritikSaran[strcspn(data->data.kritikSaran, "\n")] = 0;

    printf("Masukkan jenis kritik/saran (1 untuk kritik, 2 untuk saran): ");
    scanf("%d", &data->data.jenis);

    if (data->data.jenis != 1 && data->data.jenis != 2) {
        printf("Jenis kritik/saran tidak valid.\n");
        exit(1);
    }
}

// Fungsi untuk menampilkan data kritik/saran
void tampilkanDataKritikSaran(DataKritikSaran* data) {
    printf("Nama: %s\n", data->data.nama);
    printf("Kritik/Saran: %s\n", data->data.kritikSaran);

    if (data->data.jenis == 1) {
        printf("Jenis: Kritik\n");
    } else if (data->data.jenis == 2) {
        printf("Jenis: Saran\n");
    }
}

int main() {
    DataKritikSaran* data = memindahkanDataKritikSaran();

    printf("Selamat datang di program kritik dan saran!\n");
    printf("Silakan masukkan kritik/saran Anda:\n");

    masukkanDataKritikSaran(data);
    tampilkanDataKritikSaran(data);

    free(data);

    return 0;
}
