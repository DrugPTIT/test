#ifndef QUANLYSACH_H
#define QUANLYSACH_H

#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

class Sach {
private:
    string IdSach;
    string TenSach;
    int SoLuongTonKho;
    int MucCanhBao;

public:
    Sach();
    Sach(string idSach, string tenSach, int soLuongTonKho, int mucCanhBao);
    string getIdSach() const;
    int getSoLuongTonKho() const;
    bool KiemTraTonTaiIdSach(const string& id);
    void ThemSachMoi();
    void LuuThongTinSach();
    void SuaThongTinSach();
    void XoaSach();
    void XemDanhSachSach();
    void TimKiemSach();
    void CapNhatSoLuong();
    void TaoCanhBao();
};

Sach::Sach() : IdSach(""), TenSach(""), SoLuongTonKho(0), MucCanhBao(0) {}

Sach::Sach(string idSach, string tenSach, int soLuongTonKho, int mucCanhBao)
    : IdSach(idSach), TenSach(tenSach), SoLuongTonKho(soLuongTonKho), MucCanhBao(mucCanhBao) {}

string Sach::getIdSach() const {
    return IdSach;
}

int Sach::getSoLuongTonKho() const {
    return SoLuongTonKho;
}

bool Sach::KiemTraTonTaiIdSach(const string& id) {
    ifstream file("./logs/QuanLySach.txt");
    string line;
    while (getline(file, line)) {
        if (line.find("ID: " + id) != string::npos) {
            return true;
        }
    }
    return false;
}

void Sach::ThemSachMoi() {
    do {
        cout << "Nhap ID sach: ";
        cin >> IdSach;

        if (KiemTraTonTaiIdSach(IdSach)) {
            cout << "ID sach da ton tai. Vui long nhap ID khac.\n";
        } else {
            break;
        }
    } while (true);

    cout << "Nhap ten sach: ";
    cin.ignore();
    getline(cin, TenSach);
    cout << "Nhap so luong ton kho: ";
    cin >> SoLuongTonKho;
    cout << "Nhap muc canh bao: ";
    cin >> MucCanhBao;

    cout << "Sach moi da duoc them thanh cong!\n";
    LuuThongTinSach();
}

void Sach::LuuThongTinSach() {
    ofstream file("./logs/QuanLySach.txt", ios::app);
    if (file.is_open()) {
        file << "ID: " << IdSach << ", Ten: " << TenSach
             << ", So luong ton kho: " << SoLuongTonKho << ", Muc canh bao: " << MucCanhBao << endl;
        file.close();
        cout << "Thong tin sach da duoc luu vao file.\n";
    } else {
        cout << "Khong the mo file de luu thong tin sach.\n";
    }
}

void Sach::SuaThongTinSach() {
    string id;
    cout << "Nhap ID sach can sua: ";
    cin >> id;

    ifstream fileIn("./logs/QuanLySach.txt");
    ofstream fileOut("./logs/temp.txt");
    string line;
    bool found = false;

    while (getline(fileIn, line)) {
        if (line.find("ID: " + id) != string::npos) {
            found = true;
            cout << "Nhap ten sach moi: ";
            cin.ignore();
            getline(cin, TenSach);
            cout << "Nhap so luong ton kho moi: ";
            cin >> SoLuongTonKho;
            cout << "Nhap muc canh bao moi: ";
            cin >> MucCanhBao;

            fileOut << "ID: " << id << ", Ten: " << TenSach
                    << ", So luong ton kho: " << SoLuongTonKho << ", Muc canh bao: " << MucCanhBao << endl;
            cout << "Thong tin sach da duoc cap nhat.\n";
        } else {
            fileOut << line << endl;
        }
    }

    fileIn.close();
    fileOut.close();
    remove("./logs/QuanLySach.txt");
    rename("./logs/temp.txt", "./logs/QuanLySach.txt");

    if (!found) {
        cout << "Khong tim thay ID sach can sua.\n";
    }
}

void Sach::XoaSach() {
    string id;
    cout << "Nhap ID sach can xoa: ";
    cin >> id;

    ifstream fileIn("./logs/QuanLySach.txt");
    ofstream fileOut("./logs/temp.txt");
    string line;
    bool found = false;

    while (getline(fileIn, line)) {
        if (line.find("ID: " + id) != string::npos) {
            found = true;
            cout << "Sach da duoc xoa thanh cong.\n";
        } else {
            fileOut << line << endl;
        }
    }

    fileIn.close();
    fileOut.close();
    remove("./logs/QuanLySach.txt");
    rename("./logs/temp.txt", "./logs/QuanLySach.txt");

    if (!found) {
        cout << "Khong tim thay sach can xoa.\n";
    }
}

void Sach::XemDanhSachSach() {
    ifstream file("./logs/QuanLySach.txt");
    string line;

    if (file.is_open()) {
        cout << "\n--- Danh sach sach ---\n";
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "Khong the mo file de xem danh sach sach.\n";
    }
}

void Sach::TimKiemSach() {
    string id;
    cout << "Nhap ID sach can tim: ";
    cin >> id;

    ifstream file("./logs/QuanLySach.txt");
    string line;
    bool found = false;

    while (getline(file, line)) {
        if (line.find("ID: " + id) != string::npos) {
            cout << line << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Khong tim thay sach voi ID: " << id << endl;
    }

    file.close();
}

void Sach::CapNhatSoLuong() {
    int amount;
    cout << "Nhap so luong sach can nhap: ";
    cin >> amount;
    SoLuongTonKho += amount;
    cout << "So luong sach sau khi nhap: " << SoLuongTonKho << endl;
    LuuThongTinSach();
}

void Sach::TaoCanhBao() {
    if (SoLuongTonKho < MucCanhBao) {
        cout << "Canh bao: So luong sach " << TenSach << " duoi muc canh bao.\n";
    }
}

#endif
