#include <iostream>
#include <string>
#include <functional>
#include <unordered_map>

using namespace std;

struct Data {
    string nama, pin;
};

string MyHash(string pin);

string MasukkanData(unordered_map<string, Data>& dataMap)
{
    string nama, pin;
    cout << "Masukkan Nama: ";
    cin >> nama;
    cout << "Masukkan PIN: ";
    cin >> pin;
    string hashed = MyHash(pin);
    Data data;
    data.nama = nama;
    data.pin = pin;
    dataMap[hashed] = data;
    cout << "Data ditambahkan" << endl << " " << endl;
    return hashed;
}

void TampilkanSemuaData(const unordered_map<string, Data>& dataMap)
{
    for (const auto& pair : dataMap)
    {
        cout << "Semua Detail Data" << endl;
        cout << "Key: " << pair.first << endl
             << "Nama: " << pair.second.nama << endl
             << "PIN: " << pair.second.pin << endl
             << " " << endl;
    }
}

bool CariKunciAkses(const unordered_map<string, Data>& dataMap)
{
    string access;
    cout << "Masukkan Kunci Akses: ";
    cin >> access;
    if (dataMap.find(access) != dataMap.end())
    {
        cout << "---------------------------------------" << endl
             << "Detail Data: " << endl;
        cout << "Nama: " << dataMap.at(access).nama << endl;
        cout << "PIN: " << dataMap.at(access).pin << endl;
        return true;
    }
    else
    {
        cout << "Kunci yang Anda masukkan salah. Coba lagi lain kali." << endl;
        return false;
    }
}

string MyHash(string pin)
{
    hash<string> hasher;
    size_t hashedValue = hasher(pin);
    return to_string(hashedValue);
}

int main()
{
    unordered_map<string, Data> dataMap(256);
    int i = 1;

    while (i < 3)
    {
        string hashed = MasukkanData(dataMap);
        i++;
    }

    TampilkanSemuaData(dataMap);

    bool accessGranted = false;
    while (!accessGranted)
    {
        accessGranted = CariKunciAkses(dataMap);
    }
}