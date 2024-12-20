#include <stdio.h>
#include <string.h>

int main() {
    struct Dish {
        int id;
        char name[100];
        double price;
    };

    int choice;
    struct Dish menu[100] = {
        {1, "bun cha", 35},
        {2, "banh canh", 20},
        {3, "bun dau mam tom", 50},
        {4, "banh cuon", 15},
        {5, "banh mi", 10}
    };
    int stt = 5; 
    int size = 5;
    int viTri;

    do {
        printf("\n--------MENU--------\n");
        printf("1. In ra menu.\n");
        printf("2. Them mon an vao menu.\n");
        printf("3. Sua mon an trong menu.\n");
        printf("4. Xoa mon an khoi menu.\n");
        printf("5. Sap xep menu theo gia tien.\n");
        printf("6. Tim kiem mon an trong menu.\n");
        printf("7. Thoat.\n");
        printf("Nhap lua chon cua ban: ");
        if (scanf("%d", &choice) != 1) {
            printf("Nhap sai, vui long nhap so nguyen!\n");
            while (getchar() != '\n'); 
            continue;
        }
        getchar(); 

        switch (choice) {
            case 1: 
                printf("\nDanh sach mon an:\n");
                for (int i = 0; i < size; i++) {
                    printf("%d. %s - %.2lf VND\n", menu[i].id, menu[i].name, menu[i].price);
                }
                break;

            case 2: 
                if (size < 100) {
                    printf("Nhap ten mon an: ");
                    fgets(menu[stt].name, sizeof(menu[stt].name), stdin);
                    menu[stt].name[strcspn(menu[stt].name, "\n")] = '\0';
                    printf("Nhap gia tien: ");
                    if (scanf("%lf", &menu[stt].price) != 1) {
                        printf("Gia tien khong hop le!\n");
                        while (getchar() != '\n'); 
                        break;
                    }
                    menu[stt].id = stt + 1;
                    stt++;
                    size++;
                    printf("Them mon an thanh cong!\n");
                } else {
                    printf("Danh sach da day, khong the them!\n");
                }
                break;

            case 3: 
                printf("Nhap vi tri mon an muon sua (1-%d): ", size);
                if (scanf("%d", &viTri) != 1 || viTri < 1 || viTri > size) {
                    printf("Vi tri khong hop le!\n");
                    while (getchar() != '\n');
                    break;
                }
                getchar();
                printf("Nhap ten moi: ");
                fgets(menu[viTri - 1].name, sizeof(menu[viTri - 1].name), stdin);
                menu[viTri - 1].name[strcspn(menu[viTri - 1].name, "\n")] = '\0';
                printf("Nhap gia tien moi: ");
                if (scanf("%lf", &menu[viTri - 1].price) != 1) {
                    printf("Gia tien khong hop le!\n");
                    while (getchar() != '\n');
                }
                printf("Sua thanh cong!\n");
                break;

            case 4:
                printf("Nhap vi tri mon an muon xoa (1-%d): ", size);
                if (scanf("%d", &viTri) != 1 || viTri < 1 || viTri > size) {
                    printf("Vi tri khong hop le!\n");
                    while (getchar() != '\n'); 
                    break;
                }
                for (int i = viTri - 1; i < size - 1; i++) {
                    menu[i] = menu[i + 1];
                }
                size--;
                printf("Xoa thanh cong!\n");
                break;

            case 5: 
                for (int i = size - 1; i > 0; i--) {
                    for (int j = 0; j < i; j++) {
                        if (menu[j].price < menu[j + 1].price) {
                            struct Dish temp = menu[j];
                            menu[j] = menu[j + 1];
                            menu[j + 1] = temp;
                        }
                    }
                }
                printf("Sap xep thanh cong!\n");
                break;

            case 6: {
                printf("Nhap ten mon an can tim: ");
                char search[100];
                fgets(search, sizeof(search), stdin);
                search[strcspn(search, "\n")] = '\0';
                int found = 0;
                for (int i = 0; i < size; i++) {
                    if (strstr(menu[i].name, search) != NULL) {
                        printf("%d. %s - %.2lf VND\n", menu[i].id, menu[i].name, menu[i].price);
                        found = 1;
                    }
                }
                if (!found) {
                    printf("Khong tim thay mon an!\n");
                }
                break;
            }

            case 7: 
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 7);

    return 0;
}

