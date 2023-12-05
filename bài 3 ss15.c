#include <stdio.h>
#include <string.h>

// Khai b�o c?u tr�c student
struct Student {
    char hoTen[50];
    int tuoi;
    char soDienThoai[15];
    char email[50];
};

// H�m nh?p th�ng tin sinh vi�n
void nhapThongTinSinhVien(struct Student *sv) {
    printf("Nhap ho va ten: ");
    fgets(sv->hoTen, sizeof(sv->hoTen), stdin);

    printf("Nhap tuoi: ");
    scanf("%d", &(sv->tuoi));

    fflush(stdin); // X�a b? nh? �?m �? tr�nh l?i khi nh?p s? �i?n tho?i v� email
    printf("Nhap so dien thoai: ");
    fgets(sv->soDienThoai, sizeof(sv->soDienThoai), stdin);

    printf("Nhap email: ");
    fgets(sv->email, sizeof(sv->email), stdin);
}

// H�m in th�ng tin sinh vi�n
void inThongTinSinhVien(const struct Student *sv) {
    printf("\nThong tin sinh vien:\n");
    printf("Ho va ten: %s", sv->hoTen);
    printf("Tuoi: %d\n", sv->tuoi);
    printf("So dien thoai: %s", sv->soDienThoai);
    printf("Email: %s", sv->email);
}

// H�m th�m sinh vi�n v�o m?ng t?i v? tr�
void themSinhVien(struct Student *students, int *soLuong, int viTri) {
    nhapThongTinSinhVien(&students[*soLuong]);
    (*soLuong)++;
}

// H�m s?a th�ng tin sinh vi�n t?i v? tr�
void suaThongTinSinhVien(struct Student *students, int soLuong, int viTri) {
    if (viTri >= 0 && viTri < soLuong) {
        nhapThongTinSinhVien(&students[viTri]);
    } else {
        printf("Vi tri khong hop le!\n");
    }
}

// H�m x�a sinh vi�n kh?i m?ng t?i v? tr�
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

// H�m in th�ng tin t?t c? sinh vi�n trong m?ng
void inDanhSachSinhVien(const struct Student *students, int soLuong) {
    printf("\nDanh sach sinh vien:\n");
    for (int i = 0; i < soLuong; ++i) {
        inThongTinSinhVien(&students[i]);
    }
}

int main() {
    struct Student students[100]; // Gi? s? c� t?i �a 100 sinh vi�n
    int soLuongSinhVien = 0; // S? l�?ng sinh vi�n hi?n t?i trong m?ng

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

