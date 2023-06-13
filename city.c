//Khushi Desai
//21BCP264
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_CITY_NAME 50

struct city {
    char name[MAX_CITY_NAME];
    int x, y;
    struct city *next;
};

struct city *head = NULL;

// Function prototypes
void insert();
void deleteByName();
void deleteByCoord();
void searchByName();
void searchByCoord();
void printNearbyCities();

int main() {
    int choice;

    while (1) {
        printf("1. Insert a record\n");
        printf("2. Delete a record by name\n");
        printf("3. Delete a record by coordinate\n");
        printf("4. Search a record by name\n");
        printf("5. Search a record by coordinate\n");
        printf("6. Print all records \n");
        printf("7. Print all records within a given distance of a specified point\n");
        printf("8. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                deleteByName();
                break;
            case 3:
                deleteByCoord();
                break;
            case 4:
                searchByName();
                break;
            case 5:
                searchByCoord();
                break;
            case 6:
                printAllCities();
                break;

            case 7:
                printNearbyCities();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

void insert() {
    struct city *newCity = (struct city*)malloc(sizeof(struct city));

    if (newCity == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter city name: ");
    scanf("%s", newCity->name);
    printf("Enter city coordinates (x y): ");
    scanf("%d %d", &newCity->x, &newCity->y);

    newCity->next = NULL;

    if (head == NULL) {
        head = newCity;
        printf("Record inserted\n");
        return;
    }

    struct city *temp = head;
    struct city *prev = NULL;

    while (temp != NULL && strcmp(temp->name, newCity->name) < 0) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL) {
        newCity->next = head;
        head = newCity;
    } else {
        prev->next = newCity;
        newCity->next = temp;
    }

    printf("Record inserted\n");

    //print all the cities
    struct city *temp1 = head;
    while (temp1 != NULL) {
        printf("%s (%d, %d)\n", temp1->name, temp1->x, temp1->y);
        temp1 = temp1->next;
    }

}

void deleteByName() {
    if (head == NULL) {
        printf("Database is empty\n");
        return;
    }

    char name[MAX_CITY_NAME];
    printf("Enter city name to delete: ");
    scanf("%s", name);

    struct city *temp = head;
    struct city *prev = NULL;
    int found = 0;

    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            found = 1;
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    if (!found) {
        printf("Record not found\n");
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Record deleted\n");
}

void deleteByCoord() {
    if (head == NULL) {
        printf("Database is empty\n");
        return;
    }

    int x, y;
    printf("Enter city coordinates to delete (x y): ");
    scanf("%d %d", &x, &y);

    struct city *temp = head;
    struct city *prev = NULL;
    int found = 0;
    
    while (temp != NULL) {
        if (temp->x == x && temp->y == y) {
            found = 1;
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    if (!found) {
        printf("Record not found\n");
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Record deleted\n");
}

void searchByName() {
    if (head == NULL) {
        printf("Database is empty\n");
        return;
    }

    char name[MAX_CITY_NAME];
    printf("Enter city name to search: ");
    scanf("%s", name);

    struct city *temp = head;
    int found = 0;

    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            found = 1;
            break;
        }
        temp = temp->next;
    }

    if (!found) {
        printf("Record not found\n");
        return;
    }

    printf("City name: %s (%d, %d)\n", temp->name, temp->x, temp->y);
}

void searchByCoord() {
    if (head == NULL) {
        printf("Database is empty\n");
        return;
    }

    int x, y;
    printf("Enter city coordinates to search (x y): ");
    scanf("%d %d", &x, &y);

    struct city *temp = head;
    int found = 0;

    while (temp != NULL) {
        if (temp->x == x && temp->y == y) {
            found = 1;
            break;
        }
        temp = temp->next;
    }

    if (!found) {
        printf("Record not found\n");
        return;
    }

    printf("City name: %s (%d, %d)\n", temp->name, temp->x, temp->y);
}

void printAllCities() {
    if (head == NULL) {
        printf("Database is empty\n");
        return;
    }

    struct city *temp = head;
    while (temp != NULL) {
        printf("City name: %s (%d, %d)\n", temp->name, temp->x, temp->y);
        temp = temp->next;
    }
}


void printNearbyCities() {
    if (head == NULL) {
        printf("Database is empty\n");
        return;
    }

    int x, y, distance;
    printf("Enter city coordinates (x y): ");
    scanf("%d %d", &x, &y);
    printf("Enter distance: ");
    scanf("%d", &distance);

    struct city *temp = head;
    int found = 0;

    while (temp != NULL) {
        int dist = sqrt(pow(temp->x - x, 2) + pow(temp->y - y, 2));
        if (dist <= distance) {
            printf("City name: %s (%d, %d)\n", temp->name, temp->x, temp->y);
            found = 1;
        }
        temp = temp->next;
    }

    if (!found) {
        printf("No nearby cities found\n");
    }
}


