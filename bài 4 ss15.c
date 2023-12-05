#include <stdio.h>
#include <string.h>

// Khai báo c?u trúc sách
struct Book {
    int maSach;
    char tenSach[100];
    char tacGia[50];
    float giaTien;
    char theLoai[50];
};

// Hàm nh?p thông tin sách
void nhapThongTinSach(struct Book *books, int *soLuong) {
    printf("Nhap so luong sach: ");
    scanf("%d", soLuong);
    fflush(stdin);

    for (int i = 0; i < *soLuong; ++i) {
        printf("\nNhap thong tin cho sach thu %d:\n", i + 1);
        printf("Nhap ma sach: ");
        scanf("%d", &books[i].maSach);
        fflush(stdin);

        printf("Nhap ten sach: ");
        fgets(books[i].tenSach, sizeof(books[i].tenSach), stdin);

        printf("Nhap tac gia: ");
        fgets(books[i].tacGia, sizeof(books[i].tacGia), stdin);

        printf("Nhap gia tien: ");
        scanf("%f", &books[i].giaTien);
        fflush(stdin);

        printf("Nhap the loai: ");
        fgets(books[i].theLoai, sizeof(books[i].theLoai), stdin);
    }
}

// Hàm hi?n th? thông tin sách
void hienThiThongTinSach(const struct Book *books, int soLuong) {
    printf("\nDanh sach sach:\n");
    for (int i = 0; i < soLuong; ++i) {
        printf("\nThong tin sach thu %d:\n", i + 1);
        printf("Ma sach: %d\n", books[i].maSach);
        printf("Ten sach: %s", books[i].tenSach);
        printf("Tac gia: %s", books[i].tacGia);
        printf("Gia tien: %.2f\n", books[i].giaTien);
        printf("The loai: %s", books[i].theLoai);
    }
}

// Hàm thêm sách vào v? trí
void themSach(struct Book *books, int *soLuong, int viTri) {
    if (*soLuong < 100) {
        printf("\nNhap thong tin cho sach moi:\n");
        printf("Nhap ma sach: ");
        scanf("%d", &books[*soLuong].maSach);
        fflush(stdin);

        printf("Nhap ten sach: ");
        fgets(books[*soLuong].tenSach, sizeof(books[*soLuong].tenSach), stdin);

        printf("Nhap tac gia: ");
        fgets(books[*soLuong].tacGia, sizeof(books[*soLuong].tacGia), stdin);

        printf("Nhap gia tien: ");
        scanf("%f", &books[*soLuong].giaTien);
        fflush(stdin);

        printf("Nhap the loai: ");
        fgets(books[*soLuong].theLoai, sizeof(books[*soLuong].theLoai), stdin);

        (*soLuong)++;
    } else {
        printf("Danh sach da day, khong the them sach moi!\n");
    }
}

// Hàm xóa sách theo m? sách
void xoaSach(struct Book *books, int *soLuong, int maSach) {
    int viTri = -1;

    for (int i = 0; i < *soLuong; ++i) {
        if (books[i].maSach == maSach) {
            viTri = i;
            break;
        }
    }

    if (viTri != -1) {
        for (int i = viTri; i < *soLuong - 1; ++i) {
            books[i] = books[i + 1];
        }
        (*soLuong)--;
    } else {
        printf("Khong tim thay sach co ma sach %d!\n", maSach);
    }
}

// Hàm c?p nh?t thông tin sách theo m? sách
void capNhatThongTinSach(struct Book *books, int soLuong, int maSach) {
    int viTri = -1;

    for (int i = 0; i < soLuong; ++i) {
        if (books[i].maSach == maSach) {
            viTri = i;
            break;
        }
    }

    if (viTri != -1) {
        printf("\nNhap thong tin moi cho sach co ma sach %d:\n", maSach);
        printf("Nhap ten sach: ");
        fgets(books[viTri].tenSach, sizeof(books[viTri].tenSach), stdin);

        printf("Nhap tac gia: ");
        fgets(books[viTri].tacGia, sizeof(books[viTri].tacGia), stdin);

        printf("Nhap gia tien: ");
        scanf("%f", &books[viTri].giaTien);
        fflush(stdin);

        printf("Nhap the loai: ");
        fgets(books[viTri].theLoai, sizeof(books[viTri].theLoai), stdin);
    } else {
        printf("Khong tim thay sach co ma sach %d!\n", maSach);
    }
}

// Hàm s?p x?p sách theo giá (tãng d?n)
void sapXepTheoGiaTangDan(struct Book *books, int soLuong) {
    for (int i = 0; i < soLuong - 1; ++i) {
        for (int j = 0; j < soLuong - i - 1; ++j) {
            if (books[j].giaTien > books[j + 1].giaTien) {
                // Hoán ð?i v? trí
                struct Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}

// Hàm s?p x?p sách theo giá (gi?m d?n)
void sapXepTheoGiaGiamDan(struct Book *books, int soLuong) {
    for (int i = 0; i < soLuong - 1; ++i) {
        for (int j = 0; j < soLuong - i - 1; ++j) {
            if (books[j].giaTien < books[j + 1].giaTien) {
                // Hoán ð?i v? trí
                struct Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}

// Hàm t?m ki?m sách theo tên sách
void timKiemTheoTenSach(const struct Book *books, int soLuong, const char *tenSach) {
    int timThay = 0;

    for (int i = 0; i < soLuong; ++i) {
        if (strstr(books[i].tenSach, tenSach) != NULL) {
            timThay = 1;
            inThongTinSach(&books[i]);
        }
    }

    if (!timThay) {
        printf("Khong tim thay sach co ten %s!\n", tenSach);
    }
}

// Hàm t?m ki?m sách theo kho?ng giá
void timKiemTheoKhoangGia(const struct Book *books, int soLuong, float giaMin, float giaMax) {
    int timThay = 0;

    for (int i = 0; i < soLuong; ++i) {
        if (books[i].giaTien >= giaMin && books[i].giaTien <= giaMax) {
            timThay = 1;
            inThongTinSach(&books[i]);
        }
    }

    if (!timThay) {
        printf("Khong tim thay sach trong khoang gia tu %.2f den %.2f!\n", giaMin, giaMax);
    }
}

// Hàm in thông tin sách
void inThongTinSach(const struct Book *book) {
    printf("\nThong tin sach:\n");
    printf("Ma sach: %d\n", book->maSach);
    printf("Ten sach: %s", book->tenSach);
    printf("Tac gia: %s", book->tacGia);
    printf("Gia tien: %.2f\n", book->giaTien);
    printf("The loai: %s", book->theLoai);
}

int main() {
    struct Book books[100]; // Gi? s? có t?i ða 100 cu?n sách
    int soLuongSach = 0; // S? lý?ng sách hi?n t?i trong m?ng

    int luaChon;
    do {
        printf("\nMENU:\n");
        printf("1. Nhap so luong va thong tin sach\n");
        printf("2. Hien thi thong tin sach\n");
        printf("3. Them sach vao vi tri\n");
        printf("4. Xoa sach theo ma sach\n");
        printf("5. Cap nhat thong tin sach theo ma sach\n");
        printf("6. Sap xep sach theo gia (tang dan)\n");
        printf("7. Sap xep sach theo gia (giam dan)\n");
        printf("8. Tim kiem sach theo ten sach\n");
        printf("9. Tim kiem sach theo khoang gia\n");
        printf("0. Thoat\n");

        printf("Nhap lua chon cua ban: ");
        scanf("%d", &luaChon);
        fflush(stdin);

        switch (luaChon) {
            case 1:
                nhapThongTinSach(books, &soLuongSach);
                break;
            case 2:
                hienThiThongTinSach(books, soLuongSach);
                break;
            case 3: {
                int viTri;
                printf("Nhap vi tri can them: ");
                scanf("%d", &viTri);
                fflush(stdin);
                themSach(books, &soLuongSach, viTri);
                break;
            }
            case 4: {
                int maSach;
                printf("Nhap ma sach can xoa: ");
                scanf("%d", &maSach);
                fflush(stdin);
                xoaSach(books, &soLuongSach, maSach);
                break;
            }
            case 5: {
                int maSach;
                printf("Nhap ma sach can cap nhat: ");
                scanf("%d", &maSach);
                fflush(stdin);
                capNhatThongTinSach(books, soLuongSach, maSach);
                break;
            }
            case 6:
                sapXepTheoGiaTangDan(books, soLuongSach);
                break;
            case 7:
                sapXepTheoGiaGiamDan(books, soLuongSach);
                break;
            case 8: {
                char tenSach[100];
                printf("Nhap ten sach can tim kiem: ");
                fgets(tenSach, sizeof(tenSach), stdin);
                timKiemTheoTenSach(books, soLuongSach, tenSach);
                break;
            }
            case 9: {
                float giaMin, giaMax;
                printf("Nhap gia thap nhat: ");
                scanf("%f", &giaMin);
                fflush(stdin);
                printf("Nhap gia cao nhat: ");
                scanf("%f", &giaMax);
                fflush(stdin);
                timKiemTheoKhoangGia(books, soLuongSach, giaMin, giaMax);
                break;
            }
            case 0:
                printf("Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }

    } while (luaChon != 0);

    return 0;
}

