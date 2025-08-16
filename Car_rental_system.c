#include <stdio.h>
#include <string.h>

struct Car {
    int id;
    char model[20];
    float rentPerDay;
    int available;   // 1 = available, 0 = rented
};

struct Customer {
    char name[20];
    int carId;
    int days;
    float bill;
};

int main() {
    struct Car cars[3] = {
        {1, "Suzuki", 500.0, 1},
        {2, "Hyundai", 1000.0, 1},
        {3, "Toyota", 5000.0, 1}
    };
    struct Customer cust;

    int choice, carId, days;

    while (1) {
        printf("\n=== Car Rental System ===\n");
        printf("1. View Cars\n");
        printf("2. Rent a Car\n");
        printf("3. Return Car\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\n--- Available Cars ---\n");
            for (int i = 0; i < 3; i++) {
                printf("ID: %d | Model: %s | Rent: %.2f | %s\n",
                       cars[i].id, cars[i].model, cars[i].rentPerDay,
                       cars[i].available ? "Available" : "Rented");
            }
        }
        else if (choice == 2) {
            printf("Enter your name: ");
            scanf("%s", cust.name);

            printf("Enter Car ID to rent: ");
            scanf("%d", &carId);

            if (carId < 1 || carId > 3 || cars[carId-1].available == 0) {
                printf("Car not available!\n");
            } else {
                printf("Enter number of days: ");
                scanf("%d", &days);

                cust.carId = carId;
                cust.days = days;
                cust.bill = days * cars[carId-1].rentPerDay;
                cars[carId-1].available = 0;

                printf("Car rented successfully to %s!\n", cust.name);
                printf("Total Bill: %.2f\n", cust.bill);
            }
        }
        else if (choice == 3) {
            printf("Enter Car ID to return: ");
            scanf("%d", &carId);

            if (carId < 1 || carId > 3 || cars[carId-1].available == 1) {
                printf("Invalid return!\n");
            } else {
                cars[carId-1].available = 1;
                printf("Car returned successfully!\n");
            }
        }
        else if (choice == 0) {
            printf("Exiting...\n");
            break;
        }
        else {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
