#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

// Function to insert an element into the array and sort it in ascending order
void insert(int arr[], int *idx, int element) {
    int i, j;
    arr[*idx] = element;
    (*idx)++;
    for (i = 0; i < *idx; i++) {
        for (j = i+1; j < *idx; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Function to delete an element from the array
void delete(int arr[], int *idx, int element) {
    int i, j, found = 0;
    for (i = 0; i < *idx; i++) {
        if (arr[i] == element) {
            found = 1;
            break;
        }
    }
    if (found) {
        for (j = i; j < *idx-1; j++) {
            arr[j] = arr[j+1];
        }
        (*idx)--;
    }
}

// Function to show the contents of the array
void display(int arr[], int idx) {
    int i;
    for (i = 0; i < idx; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to update an element in the array and adjust the order if needed
void update(int arr[], int idx, int element, int new_element) {
    int i, j, found = 0;
    for (i = 0; i < idx; i++) {
        if (arr[i] == element) {
            found = 1;
            break;
        }
    }
    if (found) {
        arr[i] = new_element;
        for (i = 0; i < idx; i++) {
            for (j = i+1; j < idx; j++) {
                if (arr[i] > arr[j]) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
}

// Sample main method to use the four functions
int main() {
    int arr[SIZE];
    int idx = 0;

    // Insert elements into the array
    insert(arr, &idx, 4);
    insert(arr, &idx, 2);
    insert(arr, &idx, 1);
    insert(arr, &idx, 3);
    printf("Array after insertions: ");
    display(arr, idx);

    // Delete an element from the array
    delete(arr, &idx, 2);
    printf("Array after deletion: ");
    display(arr, idx);

    // Update an element in the array
    update(arr, idx, 3, 5);
    printf("Array after update: ");
    display(arr, idx);

    return 0;
}
