#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 0xFF

typedef struct {
	char FName[24], MI, LName[16];
	unsigned int ID;
	char course[8];
	int yearLevel;
} studtype;

typedef struct {
	studtype stud[SIZE];
	int count;
} ArrayList;

void insert(ArrayList *list, studtype element) {
    // If the list is empty, add the element at the beginning
    if (list->count == 0) {
        list->stud[0] = element;
        list->count++;
        return;
    }

    // If the list is full, do not insert the element
    if (list->count == SIZE) {
        printf("ArrayList is full, cannot insert element.\n");
        return;
    }

    // Find the position to insert the element
    int pos = 0;
    while (pos < list->count && strcmp(list->stud[pos].LName, element.LName) <= 0) {
        pos++;
    }

    // Shift the elements to the right to make room for the new element
    for (int i = list->count - 1; i >= pos; i--) {
        list->stud[i+1] = list->stud[i];
    }

    // Insert the element and update the count
    list->stud[pos] = element;
    list->count = list->count + 1;
}

void delete(ArrayList *list, unsigned int ID) {
    // Find the position of the element with the given ID
    int pos = -1;
    for (int i = 0; i < list->count; i++) {
        if (list->stud[i].ID == ID) {
            pos = i;
            break;
        }
    }

    // If the element is not found, print an error message and return
    if (pos == -1) {
        printf("Element with ID %d not found.\n", ID);
        return;
    }

    // Shift the elements to the left to remove the element
    for (int i = pos; i < list->count - 1; i++) {
        list->stud[i] = list->stud[i+1];
    }

    // Update the count
    list->count = list->count - 1;
}

void display(ArrayList list) {
    for (int i = 0; i < list.count; i++) {
        printf("ID: %d Name: %s %c %s Course: %s Year Level: %d \n", list.stud[i].ID, list.stud[i].FName, list.stud[i].MI, list.stud[i].LName, list.stud[i].course, list.stud[i].yearLevel);
    }
}

int main(){
    ArrayList studArray;

    //Adding initial data to the list
    studArray.stud[0].ID = 1;
    strcpy(studArray.stud[0].LName, "Cena");
    studArray.stud[0].MI = 'M';
    strcpy(studArray.stud[0].FName, "John");
    strcpy(studArray.stud[0].course, "BSIT");
    studArray.stud[0].yearLevel = 3;

    studArray.stud[1].ID = 2;
    strcpy(studArray.stud[1].LName, "Ecleo");
    studArray.stud[1].MI = 'M';
    strcpy(studArray.stud[1].FName, "Joss");
    strcpy(studArray.stud[1].course, "BSCS");
    studArray.stud[1].yearLevel = 2;

    studArray.count = 2;
    
    printf("Before Insertion:\n");
    display(studArray); 

    studtype newStud;
    newStud.ID = 3;
    strcpy(newStud.FName, "Daniel");
    newStud.MI = 'C';
    strcpy(newStud.LName, "Dan");
    strcpy(newStud.course, "BSIS");
    newStud.yearLevel = 1;

    insert(&studArray, newStud);

    printf("After Insertion:\n");
    display(studArray); 

    printf("After deletion:\n");
    delete(&studArray, 1);
    display(studArray);

    return 0;
}
