#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

struct data_mahasiswa {
    string nama;
    string nrp;
    int umur;
    string asal;
    string jenis_kelamin;
    string universitas;
    double ipk;
    string passion;
    string mbti;
    string instagram;
};

void Menampilkan_data(const vector<data_mahasiswa>& data) {
    for (int i = 0; i < data.size(); i++) {
        cout << "Data ke-" << i + 1 << ":" << endl;
        cout << "Nama: " << data[i].nama << endl;
        cout << "NRP: " << data[i].nrp << endl;
        cout << "Umur: " << data[i].umur << endl;
        cout << "Asal: " << data[i].asal << endl;
        cout << "Jenis Kelamin: " << data[i].jenis_kelamin << endl;
        cout << "Universitas: " << data[i].universitas << endl;
        cout << "IPK: " << data[i].ipk << endl;
        cout << "Passion: " << data[i].passion << endl;
        cout << "MBTI: " << data[i].mbti << endl;
        cout << "Instagram: " << data[i].instagram << endl;
    }
}

void Menambahkan_data(vector<data_mahasiswa>& data) {
    data_mahasiswa d;
    cout << "Masukkan nama: ";
    cin.ignore();
    getline(cin, d.nama);
    cout << "Masukkan NRP: ";
    getline(cin, d.nrp);

    // Check if NRP already exists
    for (int i = 0; i < data.size(); i++) {
        if (d.nrp == data[i].nrp) {
            cout << "NRP sudah ada dalam database. Data tidak ditambahkan." << endl;
            return;
        }
    }

    cout << "Masukkan umur: ";
    cin >> d.umur;
    cout << "Masukkan asal: ";
    cin.ignore();
    getline(cin, d.asal);
    cout << "Masukkan jenis kelamin: ";
    getline(cin, d.jenis_kelamin);
    cout << "Masukkan universitas: ";
    getline(cin, d.universitas);
    cout << "Masukkan IPK: ";
    cin >> d.ipk;
    cout << "Masukkan passion: ";
    cin.ignore();
    getline(cin, d.passion);
    cout << "Masukkan MBTI: ";
    getline(cin, d.mbti);
    cout << "Masukkan Instagram: ";
    getline(cin, d.instagram);

    data.push_back(d);

    cout << "Data berhasil ditambahkan." << endl;
}

void Menghapus_data(vector<data_mahasiswa>& data) {
    int indeks;
    cout << "Masukkan indeks data yang ingin dihapus: ";
    cin >> indeks;

    if (indeks >= 0 && indeks < data.size()) {
        data.erase(data.begin() + indeks);
        cout << "Data berhasil dihapus." << endl;
    } else {
        cout << "Indeks data tidak valid." << endl;
    }
}

void Mengubah_data(vector<data_mahasiswa>& data) {
    int indeks;
    cout << "Masukkan indeks data yang ingin diubah: ";
    cin >> indeks;

    if (indeks >= 0 && indeks < data.size()) {
        data_mahasiswa d;
        cout << "Masukkan nama baru: ";
        cin.ignore();
        getline(cin, d.nama);
        cout << "Masukkan NRP baru: ";
        getline(cin, d.nrp);
        cout << "Masukkan umur baru: ";
        cin >> d.umur;
        cout << "Masukkan asal baru: ";
        cin.ignore();
        getline(cin, d.asal);
        cout << "Masukkan jenis kelamin baru: ";
        getline(cin, d.jenis_kelamin);
        cout << "Masukkan universitas baru: ";
        getline(cin, d.universitas);
        cout << "Masukkan IPK baru: ";
        cin >> d.ipk;
        cout << "Masukkan passion baru: ";
        cin.ignore();
        getline(cin, d.passion);
        cout << "Masukkan MBTI baru: ";
        getline(cin, d.mbti);
        cout << "Masukkan Instagram baru: ";
        getline(cin, d.instagram);

        data[indeks] = d;

        cout << "Data berhasil diubah." << endl;
    } else {
        cout << "Indeks data tidak valid." << endl;
    }
}

void Mencari_data(const vector<data_mahasiswa>& data) {
    string Mencari;
    cout << "Masukkan NRP yang ingin dicari: ";
    cin.ignore();
    getline(cin, Mencari);

    for (int i = 0; i < data.size(); i++) {
        if (Mencari == data[i].nrp) {
            cout << "Data ditemukan:" << endl;
            cout << "Data ke-" << i + 1 << ":" << endl;
            cout << "Nama: " << data[i].nama << endl;
            cout << "NRP: " << data[i].nrp << endl;
            cout << "Umur: " << data[i].umur << endl;
            cout << "Asal: " << data[i].asal << endl;
            cout << "Jenis Kelamin: " << data[i].jenis_kelamin << endl;
            cout << "Universitas: " << data[i].universitas << endl;
            cout << "IPK: " << data[i].ipk << endl;
            cout << "Passion: " << data[i].passion << endl;
            cout << "MBTI: " << data[i].mbti << endl;
            cout << "Instagram: " << data[i].instagram << endl;
            return; // Keluar dari fungsi setelah menemukan data
        }
    }

    cout << "Data tidak ditemukan." << endl;
}

int main() {
    vector<data_mahasiswa> data;

    int pilihan;
    do {
        cout << "Menu:" << endl;
        cout << "1. Menampilkan data" << endl;
        cout << "2. Menambahkan data" << endl;
        cout << "3. Menghapus data" << endl;
        cout << "4. Mengubah data" << endl;
        cout << "5. Mencari data" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                Menampilkan_data(data);
                break;
            case 2:
                Menambahkan_data(data);
                break;
            case 3:
                Menghapus_data(data);
                break;
            case 4:
                Mengubah_data(data);
                break;
            case 5:
                Mencari_data(data);
                break;
            case 6:
                cout << "Terima kasih telah menggunakan program ini." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
    } while (pilihan != 6);

    return 0;
}
