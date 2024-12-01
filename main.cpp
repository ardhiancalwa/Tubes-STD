#include "TUBES.h"

int main()
{
    ListKaryawan kywn;
    adrKaryawan adrkar;
    infotypeKaryawan infkar;
    ListProjek prjk;
    adrProjek adrprjk;
    infotypeProjek infprjk;
    ListRelasi rls;
    int N;

    int karyawanOption, projekOption, option;
    createListKaryawan(kywn);
    createListProjek(prjk);
    createListRelasi(rls);


    TampilanMainMenu();
    cin >> option;
    while (option < 7){
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
                        cout << "Kontak: ";
                        cin >> infkar.telp_karyawan;
                        cout << "Email: ";
                        cin >> infkar.email_karyawan ;
                        adrkar = createElemenKaryawan(infkar);
                        insertLastKaryawan(kywn, adrkar);
                }


            case 2:
//            searchDataKaryawan();

            case 3:
//            deleteFirstKaryawan();

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
                    cout << "Durasi: ";
                    cin >> infprjk.durasi_projek;
                    cout << "Anggaran: ";
                    cin >> infprjk.anggaran_projek;
                    adrprjk = createElemenProjek(infprjk);
                    insertFirstProjek(prjk, adrprjk);

                }


            case 2:
//            searchDataProjek();

            case 3:
//            deleteLastProjek();

            default:
                break;
            }
            TampilanMenuproyek();
            cin >> projekOption;
        }
        break;

    case 3:
//        showAllDataWithRelasi();

    case 4:
        showDataKaryawan(kywn);

    case 5:
        showDataProjek(prjk);

    case 6:
//        countDataProjekFromKaryawan();

    default:
        break;
    }
        TampilanMainMenu();
        cin >> option;
    }

}
