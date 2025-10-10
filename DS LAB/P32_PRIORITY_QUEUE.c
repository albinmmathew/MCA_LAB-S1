#include <stdio.h>
#define SIZE 10

int pq[SIZE];  // Priority Queue array
int n = 0;     // Number of elements in the queue

// Function to insert element into priority queue
void insert(int item) {
    if (n == SIZE) {
        printf("Priority Queue Overflow!\n");
        return;
    }

    int i;
    // Insert in sorted order (ascending priority)
    for (i = n - 1; i >= 0 && item < pq[i]; i--) {
        pq[i + 1] = pq[i];
    }
    pq[i + 1] = item;
    n++;
    printf("%d inserted into priority queue.\n", item);
}

// Function to delete the highest priority element
void delete() {
    if (n == 0) {
        printf("Priority Queue Underflow!\n");
        return;
    }

    // Since array is sorted in ascending order,
    // the element with highest priority (smallest value) is at index 0
    printf("%d deleted from priority queue.\n", pq[0]);

    // Shift all elements to left
    for (int i = 0; i < n - 1; i++) {
        pq[i] = pq[i + 1];
    }
    n--;
}

// Function to display the priority queue
void display() {
    if (n == 0) {
        printf("Priority Queue is empty.\n");
        return;
    }

    printf("Priority Queue: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", pq[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int choice, item;
    while (1) {
        printf("\n--- Priority Queue Menu ---\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &item);
                insert(item);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    
    return 0;}
}
