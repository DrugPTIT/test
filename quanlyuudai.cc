#include "UuDai.h"
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

// Khởi tạo mặc định cho lớp UuDai
UuDai::UuDai() : IdUuDai(""), MoTa(""), PhanTramGiam(0), NgayBatDau(""), NgayKetThuc("") {}

// Khởi tạo với tham số cho lớp UuDai
UuDai::UuDai(string idUuDai, string moTa, int phanTramGiam, string ngayBatDau, string ngayKetThuc)
    : IdUuDai(idUuDai), MoTa(moTa), PhanTramGiam(phanTramGiam), NgayBatDau(ngayBatDau), NgayKetThuc(ngayKetThuc) {}

// Hàm lấy ID của ưu đãi
string UuDai::getIdUuDai() const {
    return IdUuDai;
}

// Hàm kiểm tra ID ưu đãi có tồn tại trong file không
bool UuDai::KiemTraTonTaiIdUuDai(const string& id) {
    ifstream file("./logs/QuanLyUuDai.txt");
    string line;
    while (getline(file, line)) {
        if (line.find("ID: " + id) != string::npos) {
            return true;
        }
    }
    return false;
}

// Hàm tạo chương trình khuyến mãi mới
void UuDai::TaoChuongTrinhMoi() {
    do {
        cout << "Nhap ID uu dai (3 ky tu, ky tu dau la chu in hoa va 2 ky tu sau la so): ";
        cin >> IdUuDai;

        // Kiểm tra định dạng ID ưu đãi
        if (IdUuDai.length() != 3 || !isupper(IdUuDai[0]) || !isdigit(IdUuDai[1]) || !isdigit(IdUuDai[2])) {
            cout << "ID uu dai khong hop le. Vui long nhap ID khac.\n";
            continue;
        }

        if (KiemTraTonTaiIdUuDai(IdUuDai)) {
            cout << "ID uu dai da ton tai. Vui long nhap ID khac.\n";
        } else {
            break;
        }
    } while (true);

    cout << "Nhap mo ta: ";
    cin.ignore();
    getline(cin, MoTa);
    cout << "Nhap phan tram giam: ";
    cin >> PhanTramGiam;
    cout << "Nhap ngay bat dau (dd/mm/yyyy): ";
    cin >> NgayBatDau;
    cout << "Nhap ngay ket thuc (dd/mm/yyyy): ";
    cin >> NgayKetThuc;
    cout << "Uu dai moi da duoc tao thanh cong!\n";
}

// Hàm lưu thông tin ưu đãi vào file
void UuDai::LuuThongTinUuDai() {
    ofstream file("./logs/QuanLyUuDai.txt", ios::app); // Mở file ở chế độ ghi thêm
    if (file.is_open()) {
        file << "ID: " << getIdUuDai() << ", Mo ta: " << MoTa 
             << ", Phan tram giam: " << PhanTramGiam 
             << "%, Ngay bat dau: " << NgayBatDau 
             << ", Ngay ket thuc: " << NgayKetThuc << endl;
        file.close();
        cout << "Thong tin uu dai da duoc luu vao file.\n";
    } else {
        cout << "Khong the mo file de luu thong tin uu dai.\n";
    }
}

// Hàm sửa thông tin ưu đãi
void UuDai::SuaThongTinChuongTrinh() {
    string id;
    cout << "Nhap ID uu dai can sua: ";
    cin >> id;

    ifstream fileIn("./logs/QuanLyUuDai.txt");
    ofstream fileOut("./logs/temp.txt");
    string line;
    bool found = false;

    while (getline(fileIn, line)) {
        if (line.find("ID: " + id) != string::npos) {
            found = true;
            cout << "Nhap mo ta moi: ";
            cin.ignore();
            getline(cin, MoTa);
            cout << "Nhap phan tram giam moi: ";
            cin >> PhanTramGiam;
            cout << "Nhap ngay bat dau moi (dd/mm/yyyy): ";
            cin >> NgayBatDau;
            cout << "Nhap ngay ket thuc moi (dd/mm/yyyy): ";
            cin >> NgayKetThuc;
            fileOut << "ID: " << id << ", Mo ta: " << MoTa 
                    << ", Phan tram giam: " << PhanTramGiam 
                    << "%, Ngay bat dau: " << NgayBatDau 
                    << ", Ngay ket thuc: " << NgayKetThuc << endl;
            cout << "Thong tin uu dai da duoc cap nhat.\n";
        } else {
            fileOut << line << endl;
        }
    }

    fileIn.close();
    fileOut.close();
    remove("./logs/QuanLyUuDai.txt");
    rename("./logs/temp.txt", "./logs/QuanLyUuDai.txt");

    if (!found) {
        cout << "Khong tim thay ID uu dai can sua.\n";
    }
}

// Hàm xóa chương trình khuyến mãi hết hạn
void UuDai::XoaChuongTrinhHetHan() {
    string id;
    cout << "Nhap ID uu dai can xoa: ";
    cin >> id;

    ifstream fileIn("./logs/QuanLyUuDai.txt");
    ofstream fileOut("./logs/temp.txt");
    string line;
    bool found = false;

    while (getline(fileIn, line)) {
        if (line.find("ID: " + id) != string::npos) {
            found = true;
            cout << "Uu dai da duoc xoa thanh cong.\n";
        } else {
            fileOut << line << endl;
        }
    }

    fileIn.close();
    fileOut.close();
    remove("./logs/QuanLyUuDai.txt");
    rename("./logs/temp.txt", "./logs/QuanLyUuDai.txt");

    if (!found) {
        cout << "Khong tim thay uu dai can xoa.\n";
    }
}

// Hàm quản lý thời gian hiệu lực
void UuDai::QuanLyThoiGianHieuLuc() {
    cout << "Quan ly thoi gian hieu luc cho cac uu dai:\n";
    // Logic to check expiration and update or notify
    // Placeholder for functionality to manage validity
}

// Hàm xem danh sách ưu đãi
void UuDai::XemDanhSachUuDai() {
    ifstream file("./logs/QuanLyUuDai.txt");
    string line;

    if (file.is_open()) {
        cout << "\n--- Danh sach uu dai ---\n";
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "Khong the mo file de xem danh sach uu dai.\n";
    }
}

// Hàm tìm kiếm ưu đãi theo ID
void UuDai::TimKiemUuDaiTheoId() {
    string id;
    cout << "Nhap ID uu dai can tim: ";
    cin >> id;

    ifstream file("./logs/QuanLyUuDai.txt");
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
        cout << "Khong tim thay uu dai voi ID: " << id << endl;
    }

    file.close();
}
