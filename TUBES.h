#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED
#include <iostream>
using namespace std;

#define nextKaryawan(P) P->nextKaryawan
#define firstKaryawan(L) L.firstKaryawan
#define infoKaryawan(P) P->infoKaryawan
#define nextProjek(P) P->nextProjek
#define prevProjek(P) P->prevProjek
#define infoProjek(P) P->infoProjek
#define firstProjek(L) L.firstProjek
#define lastProjek(L) L.lastProjek
#define nextRelasi(P) P->nextRelasi
#define firstRelasi(L) L.firstRelasi
#define adrK(P) P->adrK
#define adrP(P) P->adrP

typedef struct Karyawan infotypeKaryawan;
typedef struct Projek infotypeProjek;

struct Karyawan {
    string id_karyawan;
    string nama_karyawan;
    string  alamat_karyawan;
    int64_t telp_karyawan;
    string email_karyawan;
};

struct Projek {
    string id_projek;
    string nama_projek;
    string jenis_projek;
    int durasi_projek;
    int64_t anggaran_projek;
};

typedef struct ElmKaryawan *adrKaryawan;
typedef struct ElmProjek *adrProjek;
typedef struct ElmRelasi *adrRelasi;

struct ElmKaryawan{
    infotypeKaryawan infoKaryawan;
    adrKaryawan nextKaryawan;
};

struct ElmProjek {
    infotypeProjek infoProjek;
    adrProjek nextProjek;
    adrProjek prevProjek;
};

struct ElmRelasi {
    adrKaryawan adrK;
    adrProjek adrP;
    adrRelasi nextRelasi;
};

struct ListKaryawan {
    adrKaryawan firstKaryawan;
};

struct ListProjek {
    adrProjek firstProjek;
    adrProjek lastProjek;
};

struct ListRelasi {
    adrRelasi firstRelasi;
};

void createListKaryawan(ListKaryawan &L);
void createListProjek(ListProjek &L);
void createListRelasi(ListRelasi &L);

adrKaryawan createElemenKaryawan(infotypeKaryawan X);
adrProjek createElemenProjek(infotypeProjek X);
adrRelasi createElemenRelasi(adrKaryawan K, adrProjek P);

void insertLastKaryawan(ListKaryawan &L, adrKaryawan K);
void insertFirstProjek(ListProjek &L, adrProjek P);
void insertFirstRelasi(ListRelasi &L, adrRelasi R);
void insertAfterRelasi(ListRelasi &L, adrRelasi R);
void insertLastRelasi(ListRelasi &L, adrRelasi R);

void deleteFirstKaryawan(ListKaryawan &L, ListRelasi &R);
void deleteLastProjek(ListProjek &L, ListRelasi &R);
void deleteFirstRelasi(ListRelasi &L);
void deleteLastRelasi(ListRelasi &L);
void deleteAfterRelasi(ListRelasi &L);

void showDataKaryawan(ListKaryawan L);
void showDataProjek(ListProjek L);
void showAllDataWithRelasi(ListKaryawan K, ListRelasi R);

adrKaryawan searchDataKaryawan(ListKaryawan L, string id_karyawan);
adrProjek searchDataProjek(ListProjek L, string id_projek);
adrRelasi searchDataRelasi(ListRelasi L, adrKaryawan K, adrProjek P);

void relationKaryawanToProjek(adrKaryawan K, adrProjek P, ListRelasi &R);

void deleteRelasiKaryawan(adrKaryawan K, ListRelasi &R);
void deleteRelasiProjek(adrProjek P, ListRelasi &R);
void deleteRelasiKaryawanProjek(adrKaryawan K, adrProjek P, ListRelasi &R);

int countDataProjekFromKaryawan(string ID, ListRelasi R);
void TampilanMainMenu();
void TampilanMenukaryawan();
void TampilanMenuproyek();
#endif // TUBES_H_INCLUDED
