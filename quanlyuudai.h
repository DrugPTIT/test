#ifndef QUANLYUUDAI_H
#define QUANLYUUDAI_H
#include "./UuDai.h"
#include <iostream>
using namespace std;

void QuanLyUuDai() {
    UuDai u;
    int choice;
    do {
        cout << "\n--- Quan Ly Uu Dai ---\n";
        cout << "1. Tao Chuong Trinh Moi\n";
        cout << "2. Xem Danh Sach Uu Dai\n";
        cout << "3. Tim Kiem Uu Dai Theo Id\n";
        cout << "4. Xoa Chuong Trinh Het Han\n";
        cout << "5. Sua Thong Tin Chuong Trinh\n";
        cout << "6. Quan Ly Thoi Gian Hieu Luc\n";
        cout << "0. Quay lai\n";
        cout << "Chon chuc nang: ";
        cin >> choice;

        switch (choice) {
            case 1:
                u.TaoChuongTrinhMoi();
                u.LuuThongTinUuDai();
                break;
            case 2:
                u.XemDanhSachUuDai();
                break;
            case 3:
                u.TimKiemUuDaiTheoId();
                break;
            case 4:
                u.XoaChuongTrinhHetHan();
                break;
            case 5:
                u.SuaThongTinChuongTrinh();
                break;
            case 6:
                u.QuanLyThoiGianHieuLuc();
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
