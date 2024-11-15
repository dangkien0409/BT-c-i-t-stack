#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//mỗi thanh gỗ 
typedef struct ThanhGo {
    char kichThuoc[20];
    int tuoiGo;
    struct ThanhGo *next;
} ThanhGo;

//mỗi loại gỗ 
typedef struct LoaiGo {
    char tenLoai[20];
    ThanhGo *top; 
    struct LoaiGo *next;
} LoaiGo;

// một loại gỗ mới
LoaiGo* taoLoaiGo(char *tenLoai) {
    LoaiGo *loaiGo = (LoaiGo*) malloc(sizeof(LoaiGo));
    strcpy(loaiGo->tenLoai, tenLoai);
    loaiGo->top = NULL;
    loaiGo->next = NULL;
    return loaiGo;
}

// Thêm một thanh gỗ vào loại gỗ
void themThanhGo(LoaiGo *loaiGo, char *kichThuoc, int tuoiGo) {
    ThanhGo *thanhGo = (ThanhGo*) malloc(sizeof(ThanhGo));
    strcpy(thanhGo->kichThuoc, kichThuoc);
    thanhGo->tuoiGo = tuoiGo;
    thanhGo->next = loaiGo->top;
    loaiGo->top = thanhGo;
}

// Tìm loại gỗ trong danh sách
LoaiGo* timLoaiGo(LoaiGo *khoGo, char *tenLoai) {
    LoaiGo *hienTai = khoGo;
    while (hienTai != NULL) {
        if (strcmp(hienTai->tenLoai, tenLoai) == 0) {
            return hienTai;
        }
        hienTai = hienTai->next;
    }
    return NULL;
}

// Thêm loại gỗ mới vào kho
void themLoaiGo(LoaiGo **khoGo, char *tenLoai, char *kichThuoc, int tuoiGo) {
    LoaiGo *loaiGo = timLoaiGo(*khoGo, tenLoai);
    if (loaiGo == NULL) {
        loaiGo = taoLoaiGo(tenLoai);
        loaiGo->next = *khoGo;
        *khoGo = loaiGo;
    }
    themThanhGo(loaiGo, kichThuoc, tuoiGo);
}

// Đếm số thanh gỗ có cùng tuổi trong một loại gỗ
int demSoLuongTheoTuoi(LoaiGo *loaiGo, int tuoiGo) {
    int dem = 0;
    ThanhGo *hienTai = loaiGo->top;
    while (hienTai != NULL) {
        if (hienTai->tuoiGo == tuoiGo) {
            dem++;
        }
        hienTai = hienTai->next;
    }
    return dem;
}

// In thông tin về kho gỗ
void inKhoGo(LoaiGo *khoGo) {
    LoaiGo *hienTai = khoGo;
    while (hienTai != NULL) {
        printf("Loai go: %s\n", hienTai->tenLoai);
        ThanhGo *thanhHienTai = hienTai->top;
        while (thanhHienTai != NULL) {
            printf("- Kich thuoc: %s, Tuoi go: %d\n", thanhHienTai->kichThuoc, thanhHienTai->tuoiGo);
            thanhHienTai = thanhHienTai->next;
        }
        printf("\n");
        hienTai = hienTai->next;
    }
}

int main() {
    LoaiGo *khoGo = NULL; // tạo kho gỗ

    // Thêm gỗ vào kho
    themLoaiGo(&khoGo, "Cam Xe", "20x5x5", 5);
    themLoaiGo(&khoGo, "Cam Xe", "25x5x5", 5);
    themLoaiGo(&khoGo, "Cam Xe", "30x5x5", 10);
    themLoaiGo(&khoGo, "Go Do", "30x6x6", 7);
    themLoaiGo(&khoGo, "Go Do", "35x6x6", 7);
    themLoaiGo(&khoGo, "Go Do", "35x6x6", 10);

    
    inKhoGo(khoGo);

    // Đếm số thanh gỗ cùng tuổi
    int tuoiCanDem = 5;
    LoaiGo *loaiGoCanDem = timLoaiGo(khoGo, "Cam Xe");
    if (loaiGoCanDem != NULL) {
        int soLuong = demSoLuongTheoTuoi(loaiGoCanDem, tuoiCanDem);
        printf("So luong thanh go co tuoi %d trong loai go '%s': %d\n", tuoiCanDem, loaiGoCanDem->tenLoai, soLuong);
    } else {
        printf("Khong tim thay loai go '%s'\n", "Cam Xe");
    }

    return 0;
}
