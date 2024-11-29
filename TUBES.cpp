#include "TUBES.h"

void createListKaryawan(ListKaryawan &L){
    firstKaryawan(L) = NULL;
}
void createListProjek(ListProjek &L){
    firstProjek(L) = NULL;
    lastProjek(L) = NULL;
}
void createListRelasi(ListRelasi &L){
    firstRelasi(L) = NULL;
}
adrKaryawan createElemenKaryawan(infotypeKaryawan X){
    adrKaryawan K = new ElmKaryawan;
    infoKaryawan(K) = X;
    nextKaryawan(K) = NULL;
}
adrProjek createElemenProjek(infotypeProjek X){
    adrProjek P = new ElmProjek;
    infoProjek(P) = X;
    nextProjek(P) = NULL;
    prevProjek(P) = NULL;
}
adrRelasi createElemenRelasi(adrKaryawan K, adrProjek P){
    adrRelasi R = new ElmRelasi;
    adrK(R) = K;
    adrP(R) = P;
    nextRelasi(R) = NULL;
}

void insertLastKaryawan(ListKaryawan &L, adrKaryawan K){
    adrKaryawan newK = firstKaryawan(L);

    if (firstKaryawan(L) == NULL) {
        firstKaryawan(L) = K;
    } else {
        while (nextKaryawan(newK) != NULL) {
            newK = nextKaryawan(newK);
        }
        nextKaryawan(newK) = K;
    }
}
void insertFirstProjek(ListProjek &L, adrProjek P){
    if (firstProjek(L) == NULL) {
        firstProjek(L) = P;
        lastProjek(L) = P;
    } else {
        nextProjek(P) = firstProjek(L);
        prevProjek(firstProjek(L)) = P;
        firstProjek(L) = P;
    }
}
void insertLastRelasi(ListRelasi &L, adrRelasi R){
    adrRelasi newR = firstRelasi(L);

    if (firstRelasi(L) == NULL) {
        firstRelasi(L) = R;
    } else {
        while (nextRelasi(newR) != NULL) {
            newR = nextRelasi(newR);
        }
        nextRelasi(newR) = R;
    }
}

void deleteFirstKaryawan(ListKaryawan &L, ListRelasi &R){
    adrKaryawan K;
    if (firstKaryawan(L) == NULL) {
        cout << "List Karyawan Kosong" << endl;
    } else if (nextKaryawan(firstKaryawan(L)) == NULL) {
        K = firstKaryawan(L);
        firstKaryawan(L) = NULL;
    } else {
        K = firstKaryawan(L);
        firstKaryawan(L) = nextKaryawan(firstKaryawan(L));
        nextKaryawan(K) = NULL;
    }
}
void deleteLastProjek(ListProjek &L, ListRelasi &R,adrProjek P){
    if(firstProjek(L) == NULL) {
        cout << "List Projek Kosong" << endl;
    } else if (nextProjek(firstProjek(L)) == NULL) {
        P = firstProjek(L);
        firstProjek(L) = NULL;
        lastProjek(L) = NULL;
    } else {
        P = lastProjek(L);
        lastProjek(L) = prevProjek(lastProjek(L));
        nextProjek(lastProjek(L)) = NULL;
        prevProjek(P) = NULL;
    }
}
void deleteFirstRelasi(ListRelasi &L, adrRelasi R){

}
void deleteLastRelasi(ListRelasi &L, adrRelasi R){

}
void deleteAfterRelasi(ListRelasi &L, adrRelasi Prec,adrRelasi R){

}

void showDataKaryawan(ListKaryawan L){
    adrKaryawan K = firstKaryawan(L);
    if (firstKaryawan(L) == NULL) {
        cout << "List Karyawan Kosong" << endl;
    } else {
        while (K != NULL) {
            cout << "ID: " << infoKaryawan(K).id_karyawan << endl;
            cout << "Nama: " << infoKaryawan(K).nama_karyawan << endl;
            cout << "Alamat: " << infoKaryawan(K).alamat_karyawan << endl;
            cout << "Kontak: " << infoKaryawan(K).telp_karyawan << endl;
            cout << "Email: " << infoKaryawan(K).email_karyawan << endl;
            K = nextKaryawan(K);
        }
    }
}
void showDataProjek(ListProjek L){
    adrProjek P = firstProjek(L);
    if (firstProjek(L) == NULL) {
        cout << "List Projek Kosong" << endl;
    } else {
        while (P != NULL){
            cout << "ID: " << infoProjek(P).id_projek << endl;
            cout << "Nama: " << infoProjek(P).nama_projek << endl;
            cout << "Jenis: " << infoProjek(P).jenis_projek << endl;
            cout << "Durasi: " << infoProjek(P).durasi_projek << endl;
            cout << "Anggaran: " << infoProjek(P).anggaran_projek << endl;
            P = nextProjek(P);
        }
    }
}
void showAllDataWithRelasi(ListKaryawan K, ListProjek P, ListRelasi R){

}

adrKaryawan searchDataKaryawan(ListKaryawan L, string id_karyawan){
    adrKaryawan K = firstKaryawan(L);
    while (K != NULL) {
        if(infoKaryawan(K).id_karyawan == id_karyawan) {
            return K;
        }
        K = nextKaryawan(K);
    }
    return NULL;
}
adrProjek searchDataProjek(ListProjek L, string id_projek){
    adrProjek P = firstProjek(L);
    while (P != NULL) {
        if(infoProjek(P).id_projek == id_projek) {
            return P;
        }
        P = nextProjek(P);
    }
    return NULL;
}
adrRelasi searchDataRelasi(ListRelasi L, adrKaryawan K, adrProjek P){

}

void relationKaryawanToProjek(ListKaryawan K, ListProjek P, ListRelasi &R){

}

int countDataProjekFromKaryawan(ListKaryawan K, ListProjek P, ListRelasi R){

}

void mainMenu(int option){
    int karyawanOption, projekOption;
    cout << "\n--Menu Pilihan Utama--\n";
    cout << "1. Karyawan";
    cout << "2. Projek";
    cout << "3. Tampilkan Semua Data Karyawan and Projek";
    cout << "4. Tampilkan Data Karyawan";
    cout << "5. Tampilkan Data Projek";
    cout << "6. Tampilkan Jumlah Data Projek Pada Karyawan Tertentu";
    cout << "7. Keluar";

    switch(option){
    case 1:
        cout << "\n--Menu Pilihan Karyawan--\n";
        cout << "1. Tambahkan Data Karyawan";
        cout << "2. Mencari Data Karyawan";
        cout << "3. Hapus Data Karyawan";
        cout << "4. Kembali";
        switch(karyawanOption){
        case 1:
//            insertLastKaryawan();
            break;
        case 2:
//            searchDataKaryawan();
            break;
        case 3:
//            deleteFirstKaryawan();
            break;
        default:
            break;
        }
        break;

    case 2:
        cout << "\n--Menu Pilihan Projek--\n";
        cout << "1. Tambahkan Data Projek";
        cout << "2. Mencari Data Projek";
        cout << "3. Hapus Data Projek";
        cout << "4. Kembali";
        switch(projekOption){
        case 1:
//            insertFirstProjek();
            break;
        case 2:
//            searchDataProjek();
            break;
        case 3:
//            deleteLastProjek();
            break;
        default:
            break;
        }
        break;
    case 3:
//        showAllDataWithRelasi();
        break;
    case 4:
//        showDataKaryawan();
        break;
    case 5:
//        showDataProjek();
        break;
    case 6:
//        countDataProjekFromKaryawan();
        break;
    default:
        break;
    }
}
