#ifndef QUANLYSACH_H
#define QUANLYSACH_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Sach {
private:
    string IdSach; // ID của sách
    string TenSach; // Tên của sách
    string TacGia; // Tác giả của sách
    int SoLuongTonKho; // Số lượng sách tồn kho
    int MucCanhBao; // Mức tồn kho tối thiểu để cảnh báo

public:
    Sach();
    Sach(string idSach, string tenSach, string tacGia, int soLuongTonKho, int mucCanhBao);

    // Getter methods
    string getIdSach() const;
    string getTenSach() const;
    string getTacGia() const;
    int getSoLuongTonKho() const;
    int getMucCanhBao() const;

    // Setter methods
    void setSoLuongTonKho(int soLuong);
    void setMucCanhBao(int mucCanhBao);

    // Chức năng quản lý sách
    void ThemSachMoi();
    void SuaThongTinSach();
    void XoaSach();
    void TaoCanhBao(); // Cảnh báo khi sách sắp hết
    void QuanLyNhapSach(); // Quản lý nhập sách mới
    void XemDanhSachSach();
    void TimKiemSach();
    void LuuThongTinSach();

    // Hàm kiểm tra ID sách có tồn tại trong file không
    bool KiemTraTonTaiIdSach(const string& id);
};

#endif
