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
    deleteRelasiKaryawan(firstKaryawan(L), R);
    if (firstKaryawan(L) == NULL) {
        cout << "========================" << endl;
        cout << "  List Karyawan Kosong" << endl;
        cout << "========================" << endl;
    } else if (nextKaryawan(firstKaryawan(L)) == NULL) {
        K = firstKaryawan(L);
        firstKaryawan(L) = NULL;
        delete K;
    } else {
        K = firstKaryawan(L);
        firstKaryawan(L) = nextKaryawan(firstKaryawan(L));
        nextKaryawan(K) = NULL;
        delete K;
    }
}
void deleteLastProjek(ListProjek &L, ListRelasi &R){
//  IS : List Projek sebelum elemen terakhir dihapus
//  FS : Elemen terakhir projek dihapus, list diperbarui
    adrProjek P;
    if(firstProjek(L) == NULL) {
        cout << "========================" << endl;
        cout << "   List Projek Kosong" << endl;
        cout << "========================" << endl;
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
void deleteFirstRelasi(ListRelasi &L){
//  IS : List relasi mungkin kosong atau memiliki elemen, dan relasi pertama siap dihapus.
//  FS : Elemen pertama dalam list relasi dihapus. Jika list kosong, tidak ada perubahan.
    adrRelasi R;
    if (firstRelasi(L) == NULL) {
        cout << "========================" << endl;
        cout << "   List Relasi Kosong" << endl;
        cout << "========================" << endl;
    } else if (nextRelasi(firstRelasi(L)) == NULL){
         R = firstRelasi(L);
        firstRelasi(L) = NULL;

    }else {
        R = firstRelasi(L);
        firstRelasi(L) = nextRelasi(R);
        nextRelasi(R) = NULL;
        adrK(R) = NULL;
        adrP(R) = NULL;
    }
}
void deleteLastRelasi(ListRelasi &L){
//  IS : List relasi mungkin kosong atau memiliki elemen, dan relasi terakhir siap dihapus.
//  FS : Elemen terakhir dalam list relasi dihapus. Jika list kosong, tidak ada perubahan.
    adrRelasi R;
    if (firstRelasi(L) == NULL) {
        cout << "========================" << endl;
        cout << "   List Relasi Kosong" << endl;
        cout << "========================" << endl;
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
void deleteAfterRelasi(ListRelasi &L){
//  IS : List relasi mungkin kosong atau memiliki elemen, dan elemen setelah `Prec` siap dihapus.
//  FS : Elemen setelah `Prec` dihapus dari list relasi. Jika tidak ada elemen setelah `Prec`, tidak ada perubahan.
    adrRelasi R;
    adrRelasi P = firstRelasi(L);
    while (nextRelasi(P) != R && P != NULL) {
        P = nextRelasi(P);
    }
    adrRelasi Q;
    Q = nextRelasi(P);
    nextRelasi(P) = nextRelasi(Q);
    nextRelasi(Q) = NULL;
}

void showDataKaryawan(ListKaryawan L) {
    // IS: Memulai iterasi dari elemen pertama dalam List Karyawan.
    // FS: Semua data karyawan dalam list telah ditampilkan atau list kosong.
    adrKaryawan K = firstKaryawan(L);
    if (K == NULL) {
        cout << "+=============================+\n";
        cout << "|   List Karyawan Kosong      |\n";
        cout << "+=============================+\n";
        return;
    }

    cout << "\n+=== DAFTAR KARYAWAN ===+\n";
    int nomor = 1;
    while (K != NULL) {
        Karyawan karyawan = infoKaryawan(K);

        cout << "\nKaryawan ke-" << nomor << ":\n";
        cout << "ID       : " << karyawan.id_karyawan << endl;
        cout << "Nama     : " << karyawan.nama_karyawan << endl;
        cout << "Alamat   : " << karyawan.alamat_karyawan << endl;
        cout << "Kontak   : " << karyawan.telp_karyawan << endl;
        cout << "Email    : " << karyawan.email_karyawan << endl;

        K = nextKaryawan(K);
        nomor++;
    }

    cout << "\nTotal Karyawan: " << nomor - 1 << endl;
}
void showDataProjek(ListProjek L) {
    // IS: Memulai iterasi dari elemen pertama dalam List Projek.
    // FS: Semua data projek dalam list telah ditampilkan atau list kosong.
    adrProjek P = firstProjek(L);

    if (P == NULL) {
        cout << "+=============================+\n";
        cout << "|       List Projek Kosong    |\n";
        cout << "+=============================+\n";
        return;
    }

    cout << "\n+=== DAFTAR PROJEK ===+\n";
    int nomor = 1;

    while (P != NULL) {
        Projek projek = infoProjek(P);

        cout << "\nProjek ke-" << nomor << ":\n";
        cout << "ID       : " << projek.id_projek << endl;
        cout << "Nama     : " << projek.nama_projek << endl;
        cout << "Jenis    : " << projek.jenis_projek << endl;
        cout << "Durasi   : " << projek.durasi_projek << " bulan" << endl;
        cout << "Anggaran : Rp " << projek.anggaran_projek << endl;

        P = nextProjek(P);
        nomor++;
    }

    cout << "\nTotal Projek: " << nomor - 1 << endl;
}

void showAllDataWithRelasi(ListKaryawan K, ListRelasi R) {
    // IS: Iterasi melalui List Relasi untuk menampilkan hubungan antara karyawan dan projek.
    // FS: Semua data karyawan, projek, dan relasi yang ada telah ditampilkan.
    adrKaryawan q = firstKaryawan(K);
    adrRelasi e;
    bool isProjek;

    if (q == NULL) {
        cout << "+=============================+\n";
        cout << "|        Data Kosong          |\n";
        cout << "+=============================+\n";
        return;
    }

    cout << "\n+=== DATA KARYAWAN DAN RELASI ===+\n";

    while (q != NULL) {
        cout << "\n+-----------------------------+\n";
        cout << "ID Karyawan   : " << infoKaryawan(q).id_karyawan << endl;
        cout << "Nama Karyawan : " << infoKaryawan(q).nama_karyawan << endl;
        cout << "List Projek   : " << endl;

        e = firstRelasi(R);
        isProjek = true;  // Reset isProjek untuk setiap karyawan

        while (e != NULL) {
            if (infoKaryawan(q).id_karyawan == infoKaryawan(adrK(e)).id_karyawan) {
                cout << "  - ID Projek: " << infoProjek(adrP(e)).id_projek
                     << " | Nama Projek: " << infoProjek(adrP(e)).nama_projek << endl;
                isProjek = false;
            }
            e = nextRelasi(e);
        }

        if (isProjek) {
            cout << "  Tidak memiliki projek saat ini." << endl;
        }

        cout << "+-----------------------------+\n";
        q = nextKaryawan(q);
    }

    cout << "\n+=== END OF DATA ===+\n";
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
    adrRelasi L1;
    L1 = firstRelasi(L);
    while (L1 != NULL && (adrK(L1) != K || adrP(L1) != P)){
        L1 = nextRelasi(L1);
    }
    return L1;
}


void relationKaryawanToProjek(adrKaryawan K, adrProjek P, ListRelasi &R){
//  IS : Relasi antara karyawan dan projek belum dibuat
//  FS : Relasi antara karyawan dan projek telah ditambahkan ke List Relasi
    adrRelasi makeRelasi = createElemenRelasi(K, P);
    if (firstRelasi(R) == NULL) {
        firstRelasi(R) = makeRelasi;
    }else {
        insertLastRelasi(R, makeRelasi);
    }
}
void deleteRelasiKaryawan(adrKaryawan K, ListRelasi &R) {
// IS : Terdapat sebuah list relasi (R) yang mungkin berisi hubungan antara karyawan (K) dan proyek (P).
// FS : Relasi antara K dan P berhasil dihapus dari list relasi (R), atau list tetap tidak berubah jika relasi tidak ditemukan.
    adrRelasi adrR = firstRelasi(R);
    while (adrR != NULL) {
        if (firstRelasi(R) == adrR){
            deleteFirstRelasi(R);
        } else if(nextRelasi(adrR) == NULL){
            deleteLastRelasi(R);
        } else {
            deleteAfterRelasi(R);
        }
        adrR = nextRelasi(adrR);
    }


}
void deleteRelasiProjek( adrProjek P, ListRelasi &R) {
// IS : Terdapat sebuah list relasi (R) yang mungkin berisi hubungan antara karyawan (K) dan proyek (P).
// FS : Relasi antara K dan P berhasil dihapus dari list relasi (R), atau list tetap tidak berubah jika relasi tidak ditemukan.
    adrRelasi adrR = firstRelasi(R);
    while (adrR != NULL) {
        if (firstRelasi(R) == adrR){
            deleteFirstRelasi(R);
        } else if(nextRelasi(adrR) == NULL){
            deleteLastRelasi(R);
        } else {
            deleteAfterRelasi(R);
        }
        adrR = nextRelasi(adrR);
    }

}
void deleteRelasiKaryawanProjek(adrKaryawan K, adrProjek P, ListRelasi &R) {
// IS : Terdapat sebuah list relasi (R) yang mungkin berisi hubungan antara karyawan (K) dan proyek (P).
// FS : Relasi antara K dan P berhasil dihapus dari list relasi (R), atau list tetap tidak berubah jika relasi tidak ditemukan.
    adrRelasi adrR = searchDataRelasi(R, K, P);
    if (firstRelasi(R) == adrR){
        deleteFirstRelasi(R);
    } else if(nextRelasi(adrR) == NULL){
        deleteLastRelasi(R);
    } else {
        deleteAfterRelasi(R);
    }

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

void TampilanMainMenu() {
    // IS: Program berada dalam keadaan siap menampilkan menu utama.
    // FS: Menu utama ditampilkan kepada pengguna untuk memilih opsi.
    cout << "\n+========================================+\n";
    cout << "|           MENU PILIHAN UTAMA           |\n";
    cout << "+========================================+\n";
    cout << "| [1] Karyawan                           |\n";
    cout << "| [2] Projek                             |\n";
    cout << "| [3] Tampilkan Data Karyawan            |\n";
    cout << "| [4] Tampilkan Data Projek              |\n";
    cout << "| [5] Hubungkan Karyawan dengan Proyek   |\n";
    cout << "| [6] Tampilkan Semua Data               |\n";
    cout << "|     Karyawan dan Projek                |\n";
    cout << "| [7] Jumlah Projek Per Karyawan         |\n";
    cout << "| [8] Keluar                             |\n";
    cout << "+========================================+\n";
    cout << "Pilih menu (1-8): ";
}

void TampilanMenukaryawan() {
    // IS: Program berada dalam keadaan siap menampilkan menu karyawan.
    // FS: Menu karyawan ditampilkan kepada pengguna untuk memilih opsi.
    cout << "\n+========================================+\n";
    cout << "|         MENU PILIHAN KARYAWAN          |\n";
    cout << "+========================================+\n";
    cout << "| [1] Tambahkan Data Karyawan            |\n";
    cout << "| [2] Mencari Data Karyawan              |\n";
    cout << "| [3] Hapus Data Karyawan                |\n";
    cout << "| [4] Kembali                            |\n";
    cout << "+========================================+\n";
    cout << "Pilih menu (1-4): ";
}

void TampilanMenuproyek() {
    // IS: Program berada dalam keadaan siap menampilkan menu projek.
    // FS: Menu projek ditampilkan kepada pengguna untuk memilih opsi.
    cout << "\n+========================================+\n";
    cout << "|          MENU PILIHAN PROJEK           |\n";
    cout << "+========================================+\n";
    cout << "| [1] Tambahkan Data Projek              |\n";
    cout << "| [2] Mencari Data Projek                |\n";
    cout << "| [3] Hapus Data Projek                  |\n";
    cout << "| [4] Kembali                            |\n";
    cout << "+========================================+\n";
    cout << "Pilih menu (1-4): ";
}

