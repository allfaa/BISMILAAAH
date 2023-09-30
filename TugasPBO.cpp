#include <iostream>
#include <iomanip>
using namespace std;

// Definisikan struktur nasabah untuk menyimpan informasi nasabah
struct nasabah
{
    char nama[50];
    char alamat[30];
    long int norek;
    double saldo;
    char tanggal_lahir[12];
    char nomor_telepon[15];
};

int main()
{
    int n = 0; // Inisialisasi jumlah nasabah
    nasabah nas[50][5]; // Array multidimensi untuk menyimpan informasi nasabah (batas 50 nasabah dengan 5 data per nasabah)
    int pil, x, pos; // Variabel-variabel untuk pilihan menu, kontrol loop, dan indeks posisi nasabah
    long int no; // Nomor rekening
    double setor, tarik; // Variabel untuk jumlah setoran dan penarikan
    bool ketemu = false; // Indikator apakah nasabah ditemukan atau tidak

    while (true) // Loop utama
    {
        system("cls"); // Membersihkan layar (Windows)
        cout << " ____________________________________________________ " << endl;
        cout << "|                   MENU NASABAH                     |" << endl;
        cout << "|____________________2200018235______________________|" << endl;
        cout << "|____________________________________________________|" << endl;
        cout << "|    1. Pendaftaran Nasabah                          |" << endl;
        cout << "|    2. Menabung                                     |" << endl;
        cout << "|    3. Penarikan                                    |" << endl;
        cout << "|    4. Cetak Daftar Nasabah                         |" << endl;
        cout << "|    5. Cari Nasabah                                 |" << endl;
        cout << "|    6. Keluar                                       |" << endl;
        cout << "|____________________________________________________|" << endl;
        cout << " Pilihan Anda : "; cin >> pil; // Meminta pilihan dari pengguna

        switch (pil)
        {
        case 1: // Pilihan 1: Pendaftaran Nasabah
        {
            do
            {
                cout << endl;
                cout << "======================================================" << endl;
                cout << " Masukan Nomer Rekening : "; cin >> no;
                ketemu = false;
                for (int i = 0; i < n; i++)
                {
                    if (no == nas[i][0].norek)
                    {
                        ketemu = true;
                        break;
                    }
                }
                if (ketemu)
                {
                    cout << " Nomer Rekening Tersebut Sudah Ada, Ulangi Lagi" << endl;
                }
                else
                {
                    cout << "======================================================" << endl;
                    cout << " Masukan Nama Anda      : "; cin >> nas[n][0].nama;
                    cout << " Masukan Alamat         : "; cin >> nas[n][0].alamat;
                    cout << " Masukan Tanggal Lahir  : "; cin >> nas[n][0].tanggal_lahir;
                    cout << " Masukan Nomor Telepon  : "; cin >> nas[n][0].nomor_telepon;
                    cout << " Masukan Saldo Awal     : Rp."; cin >> nas[n][0].saldo;
                    nas[n][0].norek = no;
                    n = n + 1; // Menambah jumlah nasabah
                }
            } while (ketemu);

            cout << "======================================================" << endl;
            cout << " Masukan Sembarang Angka Untuk Kembali Ke Menu Utama : "; cin >> x;
            break;
        }
        case 2: // Pilihan 2: Menabung
        {
            cout << endl;
            cout << "======================================================" << endl;
            cout << " Masukan Nomer Rekening  : "; cin >> no;
            ketemu = false;
            for (int i = 0; i < n; i++)
            {
                if (no == nas[i][0].norek)
                {
                    pos = i;
                    ketemu = true;
                    break;
                }
            }
            if (ketemu)
            {
                cout << "======================================================" << endl;
                cout << " Masukan Nominal Setoran : Rp."; cin >> setor;
                nas[pos][0].saldo = nas[pos][0].saldo + setor;
                cout << " Setoran Behasil" << endl;
                cout << " Jumlah Saldo Anda       : Rp." << nas[pos][0].saldo << endl;
                cout << endl;
            }
            else
            {
                cout << " Nomer Rekening Tidak Ditemukan" << endl << endl;
            }
            cout << " Masukan Sembarang Angka Untuk Kembali Ke Menu Utama : "; cin >> x;
            break;
        }
        case 3: // Pilihan 3: Penarikan
        {
            cout << endl;
            cout << "======================================================" << endl;
            cout << " Masukan Nomer Rekening   : "; cin >> no;
            ketemu = false;
            for (int i = 0; i < n; i++)
            {
                if (no == nas[i][0].norek)
                {
                    pos = i;
                    ketemu = true;
                    break;
                }
            }
            if (ketemu)
            {
                cout << "======================================================" << endl;
                cout << " Masukan Jumlah Penarikan : Rp."; cin >> tarik;
                if (tarik < nas[pos][0].saldo)
                {
                    nas[pos][0].saldo = nas[pos][0].saldo - tarik;
                    cout << " Penarikan Berhasil" << endl;
                    cout << " Sisa Saldo Anda          : Rp." << nas[pos][0].saldo << endl;
                    cout << endl;
                }
                else
                {
                    cout << " Maaf Saldo Anda Tidak Mencukupi" << endl;
                }
            }
            else
            {
                cout << " Nomer Rekening Tidak Ditemukan" << endl << endl;
            }
            cout << " Masukan Sembarang Angka Untuk Kembali Ke Menu Utama : "; cin >> x;
            break;
        }
        case 4: // Pilihan 4: Cetak Daftar Nasabah
        {
            cout << endl;
            cout << " ============================================================================================================ " << endl;
            cout << "                                                 DAFTAR NASABAH BANK                        " << endl;
            cout << "|====|=================|==============|==============|=================|=================|===================|" << endl;
            cout << "| No |   No Rekening   |     Nama     |    Alamat    |   Tanggal Lahir |  Nomor Telepon  |   Total Saldo     |" << endl;
            cout << "|====|=================|==============|==============|=================|=================|===================|" << endl;
            for (int i = 0; i < n; i++)
            {
            	// Cetak informasi nasabah ke layar dalam format tabel
                cout << setw(4) << i + 1; // Mencetak nomor urut nasabah dengan lebar 4 karakter dan menambahkan 1 karena indeks dimulai dari 0
                cout << setw(16) << nas[i][0].norek;  // Mencetak nomor rekening dengan lebar 16 karakter
                cout << setw(13) << nas[i][0].nama; // Mencetak nama dengan lebar 13 karakter
                cout << setw(16) << nas[i][0].alamat;  // Mencetak alamat dengan lebar 16 karakter
                cout << setw(18) << nas[i][0].tanggal_lahir; // Mencetak tanggal lahir dengan lebar 18 karakter
                cout << setw(18) << nas[i][0].nomor_telepon; // Mencetak nomor telepon dengan lebar 18 karakter
                cout << setw(18) << ((nas[i][0].saldo) + (nas[i][0].saldo * 0.1)) << endl;   // Mencetak total saldo setelah ditambahkan bunga sebesar 10%
            }
            cout << "|====|=================|==============|==============|=================|=================|===================|" << endl;
            cout << endl;
            cout << " Jumlah Total Saldo Diatas Setelah Ditambah Bunga 10%" << endl << endl;
            cout << " Masukan Sembarang Angka Untuk Kembali Ke Menu Utama : "; cin >> x;
            break;
        }
        case 5: // Pilihan 5: Cari Nasabah
        {
            cout << endl;
            cout << "======================================================" << endl;
            cout << " Masukan Nomer Rekening Yang Akan Dicari : "; cin >> no;
            cout << endl;
            ketemu = false;
            for (int i = 0; i < n; i++)
            {
                if (no == nas[i][0].norek)
                {
                    pos = i;
                    ketemu = true;
                    break;
                }
            }
            if (ketemu)
            {
                cout << " Nomer Rekening            : " << nas[pos][0].norek << endl;
                cout << " Nama Nasabah              : " << nas[pos][0].nama << endl;
                cout << " Alamat                    : " << nas[pos][0].alamat << endl;
                cout << " Tanggal Lahir             : " << nas[pos][0].tanggal_lahir << endl;
                cout << " Nomor Telepon             : " << nas[pos][0].nomor_telepon << endl;
                cout << " Saldo                     : Rp." << nas[pos][0].saldo << endl;
                cout << " Total  Saldo Setelah Bunga : Rp." << ((nas[pos][0].saldo) + (nas[pos][0].saldo * 0.1)) << endl << endl;
            }
            else
            {
                cout << " Nomer Rekening Tidak Ditemukan" << endl << endl;
            }
            cout << " Masukan Sembarang Angka Untuk Kembali Ke Menu Utama : "; cin >> x;
            break;
        }
        case 6: // Pilihan 6: Keluar
        {
            cout << endl << " Terima Kasih Telah Bertransaksi Disini......" << endl << endl;
            return 0; // Keluar dari program
        }
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    }

    return 0;
}
