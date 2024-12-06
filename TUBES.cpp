#include "TUBES.h"

void createListKaryawan(ListKaryawan &L){
//  IS : List Karyawan kosong
//  FS : List Karyawan diinisialisasi dengan NULL
    firstKaryawan(L) = NULL;
}
void createListProjek(ListProjek &L){
//  IS : List Projek kosong
//  FS : List Projek diinisialisasi dengan NULL pada awal dan akhir
    firstProjek(L) = NULL;
    lastProjek(L) = NULL;
}
void createListRelasi(ListRelasi &L){
//  IS : Tidak ada elemen karyawan
//  FS : Elemen karyawan dengan data terisi dan next menunjuk NULL
    firstRelasi(L) = NULL;
}
adrKaryawan createElemenKaryawan(infotypeKaryawan X){
//  IS : Tidak ada elemen karyawan
//  FS : Elemen karyawan dengan data terisi dan next menunjuk NULL
    adrKaryawan K = new ElmKaryawan;
    infoKaryawan(K) = X;
    nextKaryawan(K) = NULL;
}
adrProjek createElemenProjek(infotypeProjek X){
//  IS : Tidak ada elemen projek
//  FS : Elemen projek dengan data terisi dan next/prev menunjuk NULL
    adrProjek P = new ElmProjek;
    infoProjek(P) = X;
    nextProjek(P) = NULL;
    prevProjek(P) = NULL;
}
adrRelasi createElemenRelasi(adrKaryawan K, adrProjek P){
//  IS : Tidak ada elemen relasi
//  FS : Elemen relasi dibuat dengan relasi antara karyawan dan projek
    adrRelasi R = new ElmRelasi;
    adrK(R) = K;
    adrP(R) = P;
    nextRelasi(R) = NULL;
}

void insertLastKaryawan(ListKaryawan &L, adrKaryawan K){
//  IS : List Karyawan sebelum elemen baru ditambahkan
//  FS : Elemen karyawan baru ditambahkan ke akhir list
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
//  IS : List Projek sebelum elemen baru ditambahkan
//  FS : Elemen projek baru ditambahkan ke awal list
    if (firstProjek(L) == NULL) {
        firstProjek(L) = P;
        lastProjek(L) = P;
    } else {
        nextProjek(P) = firstProjek(L);
        prevProjek(firstProjek(L)) = P;
        firstProjek(L) = P;
    }
}
void insertFirstRelasi(ListRelasi &L, adrRelasi R){
    // IS : List Relasi sebelum elemen baru ditambahkan di awal
    // FS : Elemen baru ditambahkan sebagai elemen pertama dalam List Relasi
    if (firstRelasi(L) == NULL) {
        firstRelasi(L) = R;
    } else {
        nextRelasi(R) = firstRelasi(L);
        firstRelasi(L) = R;
    }
}

void insertAfterRelasi(ListRelasi &L, adrRelasi R){
// IS : List Relasi sebelum elemen baru ditambahkan setelah Prec
// FS : Elemen baru ditambahkan setelah elemen Prec dalam List Relasi
    adrRelasi P = firstRelasi(L);
    while (nextRelasi(P) != R) {
        P = nextRelasi(P);
    }
    nextRelasi(R) = nextRelasi(P);
    nextRelasi(P) = R;
}

void insertLastRelasi(ListRelasi &L, adrRelasi R){
// IS : List Relasi sebelum elemen baru ditambahkan di akhir
// FS : Elemen baru ditambahkan sebagai elemen terakhir dalam List Relasi
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
//  IS : List Karyawan sebelum elemen pertama dihapus
//  FS : Elemen pertama karyawan dihapus, list diperbarui
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
//  IS : List Projek sebelum elemen terakhir dihapus
//  FS : Elemen terakhir projek dihapus, list diperbarui
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
//  IS : List relasi mungkin kosong atau memiliki elemen, dan relasi pertama siap dihapus.
//  FS : Elemen pertama dalam list relasi dihapus. Jika list kosong, tidak ada perubahan.
    if (firstRelasi(L) == NULL) {
        cout << "List Relasi Kosong!" << endl;
    } else {
        R = firstRelasi(L);
        firstRelasi(L) = nextRelasi(R);
        nextRelasi(R) = NULL;
    }
}
void deleteLastRelasi(ListRelasi &L, adrRelasi R){
//  IS : List relasi mungkin kosong atau memiliki elemen, dan relasi terakhir siap dihapus.
//  FS : Elemen terakhir dalam list relasi dihapus. Jika list kosong, tidak ada perubahan.
    if (firstRelasi(L) == NULL) {
        cout << "List Relasi Kosong!" << endl;
    } else if (nextRelasi(firstRelasi(L)) == NULL) {
        R = firstRelasi(L);
        firstRelasi(L) = NULL;
    } else {
        adrRelasi temp = firstRelasi(L);
        while (nextRelasi(nextRelasi(temp)) != NULL) {
            temp = nextRelasi(temp);
        }
        R = nextRelasi(temp);
        nextRelasi(temp) = NULL;
    }
}
void deleteAfterRelasi(ListRelasi &L, adrRelasi R){
//  IS : List relasi mungkin kosong atau memiliki elemen, dan elemen setelah `Prec` siap dihapus.
//  FS : Elemen setelah `Prec` dihapus dari list relasi. Jika tidak ada elemen setelah `Prec`, tidak ada perubahan.
    adrRelasi P = firstRelasi(L);
    while (nextRelasi(P) != R) {
        P = nextRelasi(P);
    }
    adrRelasi Q;
    Q = nextRelasi(P);
    nextRelasi(P) = nextRelasi(Q);
    nextRelasi(Q) = NULL;
}

void showDataKaryawan(ListKaryawan L){
//  IS : Memulai iterasi dari elemen pertama dalam List Karyawan
//  FS : Semua data karyawan dalam list telah ditampilkan atau list kosong
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
//  IS : Memulai iterasi dari elemen pertama dalam List Projek
//  FS : Semua data projek dalam list telah ditampilkan atau list kosong
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
void showAllDataWithRelasi(ListKaryawan K, ListRelasi R){
//  IS : Iterasi melalui List Relasi untuk menampilkan hubungan antara karyawan dan projek
//  FS : Semua data karyawan, projek, dan relasi yang ada telah ditampilkan
    adrKaryawan q;

    adrRelasi e;
    q = firstKaryawan(K);

    if (q == NULL) {
        cout << "========================" << endl;
        cout << "       data kosong" << endl;
        cout << "========================" << endl;
    }else {
        while (q != NULL){
                cout << "==========================="<< endl;
                cout << "ID karyawan:" << infoKaryawan(q).id_karyawan << endl;
                cout << "Nama karyawan :" << infoKaryawan(q).nama_karyawan<< endl;
                cout << "List projek yang dimiliki: " << endl;
            e = firstRelasi(R);
            while (e != NULL){
                if (infoKaryawan(q).id_karyawan == infoKaryawan(adrK(e)).id_karyawan){
                    cout << "-" << infoProjek(adrP(e)).id_projek << endl;
                }
                e = nextRelasi(e);
            }
            cout << "==========================="<< endl;
            q = nextKaryawan(q);
        }

    }

}

adrKaryawan searchDataKaryawan(ListKaryawan L, string id_karyawan){
//  IS : Memulai pencarian dari elemen pertama dalam List Karyawan
//  FS : Elemen dengan ID ditemukan untuk return adrKaryawan, Tidak ada elemen dengan ID yang sesuai untuk return NULL
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
//  IS : Memulai pencarian dari elemen pertama dalam List Projek
//  FS : Elemen dengan ID ditemukan untuk return adrProjek, Tidak ada elemen dengan ID yang sesuai untuk return NULL
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
//  IS : Memulai pencarian dari elemen pertama dalam List Relasi
//  FS : Elemen relasi yang sesuai ditemukan atau NULL jika tidak ditemukan

}

void relationKaryawanToProjek(ListKaryawan K, ListProjek P, ListRelasi &R){
//  IS : Relasi antara karyawan dan projek belum dibuat
//  FS : Relasi antara karyawan dan projek telah ditambahkan ke List Relasi
}

int countDataProjekFromKaryawan(string ID, ListRelasi R){
//  IS : Memulai penghitungan jumlah projek dari relasi karyawan
//  FS : Jumlah projek yang dimiliki karyawan tertentu telah dihitung
    adrRelasi p;
    int jumlah = 0;
    while (p!= NULL){
        if (infoKaryawan(adrK(p)).id_karyawan == ID){
            jumlah = jumlah + 1;
        }
        p = nextRelasi(p);
    }
    return jumlah;


}

void TampilanMainMenu(){
//  IS : Program berada dalam keadaan siap menampilkan menu utama.
//  FS : Menu utama ditampilkan kepada pengguna untuk memilih opsi.
    cout << "\n--Menu Pilihan Utama--\n";
    cout << "1. Karyawan" << endl;
    cout << "2. Projek" << endl;
    cout << "3. Tampilkan Semua Data Karyawan and Projek" << endl;
    cout << "4. Tampilkan Data Karyawan" << endl;
    cout << "5. Tampilkan Data Projek" << endl;
    cout << "6. Tampilkan Jumlah Data Projek Pada Karyawan Tertentu" << endl;
    cout << "7. Keluar" << endl;
    cout <<"Pilih(1/2/3/4/5/6/7): ";
}

void TampilanMenukaryawan(){
//  IS : Program berada dalam keadaan siap menampilkan menu karyawan.
//  FS : Menu karyawan ditampilkan kepada pengguna untuk memilih opsi.
        cout << "\n--Menu Pilihan Karyawan--\n" << endl;
        cout << "1. Tambahkan Data Karyawan" << endl;
        cout << "2. Mencari Data Karyawan" << endl;
        cout << "3. Hapus Data Karyawan" << endl;
        cout << "4. Kembali" << endl;
        cout <<"Pilih(1/2/3/4): ";

}

void TampilanMenuproyek(){
//  IS : Program berada dalam keadaan siap menampilkan menu projek.
//  FS : Menu projek ditampilkan kepada pengguna untuk memilih opsi.
        cout << "\n--Menu Pilihan Projek--\n" << endl;
        cout << "1. Tambahkan Data Projek"<< endl;
        cout << "2. Mencari Data Projek"<< endl;
        cout << "3. Hapus Data Projek"<< endl;
        cout << "4. Kembali"<< endl;
        cout <<"Pilih(1/2/3/4): ";

}
