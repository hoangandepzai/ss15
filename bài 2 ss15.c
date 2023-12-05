#include <stdio.h>

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

// H�m xu?t th�ng tin sinh vi�n
void xuatThongTinSinhVien(const struct Student *sv) {
    printf("\nThong tin sinh vien:\n");
    printf("Ho va ten: %s", sv->hoTen);
    printf("Tuoi: %d\n", sv->tuoi);
    printf("So dien thoai: %s", sv->soDienThoai);
    printf("Email: %s", sv->email);
}

int main() {
    // Kh?i t?o m?t �?i t�?ng sinh vi�n
    struct Student sinhVien;

    // G?i h�m nh?p th�ng tin sinh vi�n
    nhapThongTinSinhVien(&sinhVien);

    // G?i h�m xu?t th�ng tin sinh vi�n
    xuatThongTinSinhVien(&sinhVien);

    return 0;
}

