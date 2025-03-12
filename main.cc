#include <bits/stdc++.h>
#include "QuanLyNguyenLieu.h"
#include "QuanLyUuDai.h"

using namespace std;

int main() {
    int choice;
    do {
        cout << "\n--- He Thong Quan Ly ---\n";
        cout << "1. Quan Ly Nguyen Lieu\n";
        cout << "2. Quan Ly Uu Dai\n";
        cout << "0. Thoat\n";
        cout << "Chon chuc nang: ";
        cin >> choice;
        cout << "\n";

        switch (choice) {
            case 1:
                QuanLyNguyenLieu();
                break;
            case 2:
                QuanLyUuDai();
                break;
            case 0:
                cout << "Thoat chuong trinh!\n";
                break;
            default:
                cout << "Chuc nang khong hop le. Vui long chon lai.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}
