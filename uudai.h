#ifndef UUDAI_H
#define UUDAI_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class UuDai {
private:
    string IdUuDai; // ID của ưu đãi
    string MoTa; // Mô tả của chương trình khuyến mãi
    int PhanTramGiam; // Phần trăm giảm giá
    string NgayBatDau; // Ngày bắt đầu của chương trình
    string NgayKetThuc; // Ngày kết thúc của chương trình

public:
    UuDai();
    UuDai(string IdUuDai, string MoTa, int PhanTramGiam, string NgayBatDau, string NgayKetThuc);

    void TaoChuongTrinhMoi();
    void SuaThongTinChuongTrinh();
    void XoaChuongTrinhHetHan();
    void QuanLyThoiGianHieuLuc();

    void LuuThongTinUuDai();
    void XemDanhSachUuDai();
    void TimKiemUuDaiTheoId();

    string getIdUuDai() const;

    // Hàm kiểm tra ID ưu đãi có tồn tại trong file không
    bool KiemTraTonTaiIdUuDai(const string& id);
};

#endif
