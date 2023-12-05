#include <stdio.h>
// Khai báo c?u trúc student
struct Student {
    char hoTen[50];
    int tuoi;
    char soDienThoai[15];
    char email[50];
};
int main() {
    // Kh?i t?o m?t ð?i tý?ng sinh viên
    struct Student sinhVien;
    // Gán giá tr? cho thông tin c?a sinh viên
    printf("Nhap ho va ten: ");
    fgets(sinhVien.hoTen, sizeof(sinhVien.hoTen), stdin);
    printf("Nhap tuoi: ");
    scanf("%d", &sinhVien.tuoi);
    fflush(stdin); // Xóa b? nh? ð?m ð? tránh l?i khi nh?p s? ði?n tho?i và email
    printf("Nhap so dien thoai: ");
    fgets(sinhVien.soDienThoai, sizeof(sinhVien.soDienThoai), stdin);
    printf("Nhap email: ");
    fgets(sinhVien.email, sizeof(sinhVien.email), stdin);
    // Hi?n th? thông tin sinh viên
    printf("\nThong tin sinh vien:\n");
    printf("Ho va ten: %s", sinhVien.hoTen);
    printf("Tuoi: %d\n", sinhVien.tuoi);
    printf("So dien thoai: %s", sinhVien.soDienThoai);
    printf("Email: %s", sinhVien.email);
    return 0;
}

