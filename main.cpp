#include "TUBES.h"
#include <limits>

int main()
{
    //deklarasi list
    ListKaryawan kywn;
    ListProjek prjk;
    ListRelasi rls;

    //deklarasi address
    adrKaryawan adrkar;
    adrProjek adrprjk;
    adrKaryawan findKar;
    adrProjek findProj;
    adrKaryawan rlsKar;
    adrProjek rlsProj;

    //deklarasi infotype
    infotypeKaryawan infkar;
    infotypeProjek infprjk;

    char tambahProjek;
    int N;

    int karyawanOption, projekOption, option;
    createListKaryawan(kywn);
    createListProjek(prjk);
    createListRelasi(rls);


    TampilanMainMenu();
    cin >> option;
    while (option < 8){
        switch(option){
        case 1:
            TampilanMenukaryawan();
            cin >> karyawanOption;
            while (karyawanOption < 4){
            switch(karyawanOption){
            case 1:
                cout <<"Masukan berapa banyak data karyawan yang ingin di input: ";
                cin >> N;
                for(int i = 0; i < N; i++){
                        cout <<"===================="<<endl;
                        cout << "ID: ";
                        cin >> infkar.id_karyawan;
                        cout << "Nama: ";
                        cin >> infkar.nama_karyawan;
                        cout << "Alamat: ";
                        cin >> infkar.alamat_karyawan;
                        // Validasi input untuk kontak
                        while (true) {
                            cout << "Kontak: ";
                            cin >> infkar.telp_karyawan;

                            // Cek apakah input berupa integer
                            if (cin.fail()) {
                                cin.clear(); // Menghapus error flag
                                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Menghapus input yang salah
                                cout << "Input tidak valid. Kontak harus berupa angka. Silakan coba lagi.\n";
                            } else {
                                break;
                            }
                        }
                        cout << "Email: ";
                        cin >> infkar.email_karyawan ;
                        adrkar = createElemenKaryawan(infkar);
                        insertLastKaryawan(kywn, adrkar);
                }
                break;
            case 2:
                cout << "Masukkan ID Karyawan yang ingin di cari: ";
                cin >> infkar.id_karyawan;
                findKar = searchDataKaryawan(kywn, infkar.id_karyawan);
                if (findKar == NULL) {
                    cout << "=========================================" << endl;
                    cout << "  Data Tidak Ditemukan pada ID Tersebut" << endl;
                    cout << "=========================================" << endl;
                } else {
                    cout << "===========================================" << endl;
                    cout << "  Data Karyawan pada ID tersebut Ditemukan" << endl;
                    cout << "===========================================" << endl;
                    cout << "ID\t: " << infoKaryawan(findKar).id_karyawan << endl;
                    cout << "Nama\t: " << infoKaryawan(findKar).nama_karyawan << endl;
                    cout << "Alamat\t: " << infoKaryawan(findKar).alamat_karyawan << endl;
                    cout << "Kontak\t: " << infoKaryawan(findKar).telp_karyawan << endl;
                    cout << "Email\t: " << infoKaryawan(findKar).email_karyawan << endl;
                }
                break;
            case 3:
                deleteFirstKaryawan(kywn, rls);
                break;
            default:
                break;
            }
            TampilanMenukaryawan();
            cin >> karyawanOption;
            }
            break;

        case 2:
            TampilanMenuproyek();
            cin >> projekOption;
            while (projekOption < 4){
            switch(projekOption){
            case 1:
                cout <<"Masukan berapa banyak data projek yang ingin di input: ";
                cin >> N;
                for(int i = 0; i < N; i++){
                    cout <<"===================="<<endl;
                    cout << "ID: ";
                    cin >> infprjk.id_projek;
                    cout << "Nama: ";
                    cin >> infprjk.nama_projek ;
                    cout << "Jenis: ";
                    cin >> infprjk.jenis_projek ;
                    // Validasi untuk input durasi
                    while (true) {
                        cout << "Durasi (dalam bulan): ";
                        cin >> infprjk.durasi_projek;
                        if (cin.fail()) {
                            cin.clear(); // Menghapus error flag
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Membersihkan input buffer
                            cout << "Input tidak valid. Durasi harus berupa angka. Silakan coba lagi.\n";
                        } else {
                            break; // Input valid
                        }
                    }
                    // Validasi untuk input anggaran
                    while (true) {
                        cout << "Anggaran (dalam rupiah): ";
                        cin >> infprjk.anggaran_projek;
                        if (cin.fail()) {
                            cin.clear(); // Menghapus error flag
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Membersihkan input buffer
                            cout << "Input tidak valid. Anggaran harus berupa angka. Silakan coba lagi.\n";
                        } else {
                            break; // Input valid
                        }
                    }
                    adrprjk = createElemenProjek(infprjk);
                    insertFirstProjek(prjk, adrprjk);

                }
                break;

            case 2:
                cout << "Masukkan ID Projek yang ingin di cari: ";
                cin >> infprjk.id_projek;
                findProj = searchDataProjek(prjk, infprjk.id_projek);
                if (findProj == NULL) {
                    cout << "=========================================" << endl;
                    cout << "  Data Tidak Ditemukan pada ID Tersebut" << endl;
                    cout << "=========================================" << endl;
                } else {
                    cout << "=========================================" << endl;
                    cout << " Data Projek pada ID tersebut Ditemukan" << endl;
                    cout << "=========================================" << endl;
                    cout << "ID\t: " << infoProjek(findProj).id_projek << endl;
                    cout << "Nama\t: " << infoProjek(findProj).nama_projek << endl;
                    cout << "Alamat\t: " << infoProjek(findProj).jenis_projek << endl;
                    cout << "Kontak\t: " << infoProjek(findProj).durasi_projek << endl;
                    cout << "Email\t: " << infoProjek(findProj).anggaran_projek << endl;
                }
                break;
            case 3:
                deleteLastProjek(prjk, rls);
                break;
            default:
                break;
            }
            TampilanMenuproyek();
            cin >> projekOption;
        }
        break;

    case 3:
        showDataKaryawan(kywn);
        break;
    case 4:
        showDataProjek(prjk);
        break;
    case 5:
        cout << "+========================================+\n";
        cout << "|          Relasi Karyawan-Projek        |\n";
        cout << "+========================================+\n";

        cout << "Masukkan ID Karyawan: ";
        cin >> infkar.id_karyawan;
        rlsKar = searchDataKaryawan(kywn, infkar.id_karyawan);
        if(rlsKar == NULL){
            cout << "Karyawan dengan ID tersebut tidak ditemukan!\n";
            continue;
        }
        do {
            // Input ID Proyek
            cout << "Masukkan ID Proyek: ";
            cin >> infprjk.id_projek;
            rlsProj = searchDataProjek(prjk, infprjk.id_projek);
            if(rlsProj == NULL){
                cout << "Proyek dengan ID tersebut tidak ditemukan!\n";
            }else{
                relationKaryawanToProjek(rlsKar, rlsProj,rls);
                cout << "Relasi antara karyawan \"" << infoKaryawan(rlsKar).nama_karyawan << "\" dan proyek \"" << infoProjek(rlsProj).nama_projek << "\" berhasil dibuat.\n";
            }
            // Tanya apakah ingin menambah proyek lain untuk karyawan ini
            cout << "Tambah proyek lain untuk karyawan ini? (y/n): ";
            cin >> tambahProjek;
        } while (tolower(tambahProjek) == 'y');
        break;
    case 6:
        showAllDataWithRelasi(kywn, rls);
        break;
    case 7:
        countDataProjekFromKaryawan(infkar.id_karyawan, rls);
        break;
    default:
        break;
    }
        TampilanMainMenu();
        cin >> option;
    }

}
