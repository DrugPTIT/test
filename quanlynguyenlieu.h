#ifndef QUANLYSACH_H
#define QUANLYSACH_H

#include <iostream>
using namespace std;

void QuanLySach() {
    Sach sach; // Đảm bảo rằng lớp Sach đã được định nghĩa trong Sach.h
    int choice;
    do {
        cout << "\n--- Quan Ly Sach ---\n";
        cout << "1. Nhap Sach Moi\n";
        cout << "2. Xem Danh Sach Sach\n";
        cout << "3. Tim Kiem Sach\n";
        cout << "4. Sua Thong Tin Sach\n";
        cout << "5. Xoa Sach\n";
        cout << "6. Tao Canh Bao Sach Sap Het\n";
        cout << "7. Cap Nhat So Luong Sach\n";
        cout << "0. Quay lai\n";
        cout << "Chon chuc nang: ";
        cin >> choice;

        switch (choice) {
            case 1:
                sach.ThemSachMoi();
                break;
            case 2:
                sach.XemDanhSachSach();
                break;
            case 3:
                sach.TimKiemSach();
                break;
            case 4:
                sach.SuaThongTinSach();
                break;
            case 5:
                sach.XoaSach();
                break;
            case 6:
                sach.TaoCanhBao();
                break;
            case 7:
                sach.CapNhatSoLuong();
                break;
            case 0:
                cout << "Quay lai menu chinh.\n";
                break;
            default:
                cout << "Chuc nang khong hop le. Vui long chon lai.\n";
                break;
        }
    } while (choice != 0);
}

#endif
