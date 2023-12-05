#include <stdio.h>

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

// Hàm xu?t thông tin sinh viên
void xuatThongTinSinhVien(const struct Student *sv) {
    printf("\nThong tin sinh vien:\n");
    printf("Ho va ten: %s", sv->hoTen);
    printf("Tuoi: %d\n", sv->tuoi);
    printf("So dien thoai: %s", sv->soDienThoai);
    printf("Email: %s", sv->email);
}

int main() {
    // Kh?i t?o m?t ð?i tý?ng sinh viên
    struct Student sinhVien;

    // G?i hàm nh?p thông tin sinh viên
    nhapThongTinSinhVien(&sinhVien);

    // G?i hàm xu?t thông tin sinh viên
    xuatThongTinSinhVien(&sinhVien);

    return 0;
}

