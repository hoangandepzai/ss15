#include <stdio.h>
// Khai b�o c?u tr�c student
struct Student {
    char hoTen[50];
    int tuoi;
    char soDienThoai[15];
    char email[50];
};
int main() {
    // Kh?i t?o m?t �?i t�?ng sinh vi�n
    struct Student sinhVien;
    // G�n gi� tr? cho th�ng tin c?a sinh vi�n
    printf("Nhap ho va ten: ");
    fgets(sinhVien.hoTen, sizeof(sinhVien.hoTen), stdin);
    printf("Nhap tuoi: ");
    scanf("%d", &sinhVien.tuoi);
    fflush(stdin); // X�a b? nh? �?m �? tr�nh l?i khi nh?p s? �i?n tho?i v� email
    printf("Nhap so dien thoai: ");
    fgets(sinhVien.soDienThoai, sizeof(sinhVien.soDienThoai), stdin);
    printf("Nhap email: ");
    fgets(sinhVien.email, sizeof(sinhVien.email), stdin);
    // Hi?n th? th�ng tin sinh vi�n
    printf("\nThong tin sinh vien:\n");
    printf("Ho va ten: %s", sinhVien.hoTen);
    printf("Tuoi: %d\n", sinhVien.tuoi);
    printf("So dien thoai: %s", sinhVien.soDienThoai);
    printf("Email: %s", sinhVien.email);
    return 0;
}

