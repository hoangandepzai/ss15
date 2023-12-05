#include <stdio.h>
#include <string.h>

// Khai báo c?u trúc student
struct Student {
    char hoTen[50];
    int tuoi;
    char soDienThoai[15];
    char email[50];
};

// Hàm nh?p thông tin sinh viên
void nhapThongTinSinhVien(struct Student *sv) {
    printf("Nhap ho va ten: ");
    fgets(sv->hoTen, sizeof(sv->hoTen), stdin);

    printf("Nhap tuoi: ");
    scanf("%d", &(sv->tuoi));

    fflush(stdin); // Xóa b? nh? ð?m ð? tránh l?i khi nh?p s? ði?n tho?i và email
    printf("Nhap so dien thoai: ");
    fgets(sv->soDienThoai, sizeof(sv->soDienThoai), stdin);

    printf("Nhap email: ");
    fgets(sv->email, sizeof(sv->email), stdin);
}

// Hàm in thông tin sinh viên
void inThongTinSinhVien(const struct Student *sv) {
    printf("\nThong tin sinh vien:\n");
    printf("Ho va ten: %s", sv->hoTen);
    printf("Tuoi: %d\n", sv->tuoi);
    printf("So dien thoai: %s", sv->soDienThoai);
    printf("Email: %s", sv->email);
}

// Hàm thêm sinh viên vào m?ng t?i v? trí
void themSinhVien(struct Student *students, int *soLuong, int viTri) {
    nhapThongTinSinhVien(&students[*soLuong]);
    (*soLuong)++;
}

// Hàm s?a thông tin sinh viên t?i v? trí
void suaThongTinSinhVien(struct Student *students, int soLuong, int viTri) {
    if (viTri >= 0 && viTri < soLuong) {
        nhapThongTinSinhVien(&students[viTri]);
    } else {
        printf("Vi tri khong hop le!\n");
    }
}

// Hàm xóa sinh viên kh?i m?ng t?i v? trí
void xoaSinhVien(struct Student *students, int *soLuong, int viTri) {
    if (viTri >= 0 && viTri < *soLuong) {
        for (int i = viTri; i < *soLuong - 1; ++i) {
            students[i] = students[i + 1];
        }
        (*soLuong)--;
    } else {
        printf("Vi tri khong hop le!\n");
    }
}

// Hàm in thông tin t?t c? sinh viên trong m?ng
void inDanhSachSinhVien(const struct Student *students, int soLuong) {
    printf("\nDanh sach sinh vien:\n");
    for (int i = 0; i < soLuong; ++i) {
        inThongTinSinhVien(&students[i]);
    }
}

int main() {
    struct Student students[100]; // Gi? s? có t?i ða 100 sinh viên
    int soLuongSinhVien = 0; // S? lý?ng sinh viên hi?n t?i trong m?ng

    int luaChon;
    do {
        printf("\nMenu:\n");
        printf("1. Them sinh vien\n");
        printf("2. Sua thong tin sinh vien\n");
        printf("3. Xoa sinh vien\n");
        printf("4. In danh sach sinh vien\n");
        printf("0. Thoat\n");

        printf("Nhap lua chon cua ban: ");
        scanf("%d", &luaChon);
        fflush(stdin);

        switch (luaChon) {
            case 1:
                themSinhVien(students, &soLuongSinhVien, soLuongSinhVien);
                break;
            case 2:
                if (soLuongSinhVien > 0) {
                    int viTri;
                    printf("Nhap vi tri can sua: ");
                    scanf("%d", &viTri);
                    fflush(stdin);
                    suaThongTinSinhVien(students, soLuongSinhVien, viTri);
                } else {
                    printf("Danh sach sinh vien rong!\n");
                }
                break;
            case 3:
                if (soLuongSinhVien > 0) {
                    int viTri;
                    printf("Nhap vi tri can xoa: ");
                    scanf("%d", &viTri);
                    fflush(stdin);
                    xoaSinhVien(students, &soLuongSinhVien, viTri);
                } else {
                    printf("Danh sach sinh vien rong!\n");
                }
                break;
            case 4:
                inDanhSachSinhVien(students, soLuongSinhVien);
                break;
            case 0:
                printf("Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }

    } while (luaChon != 0);

    return 0;
}

