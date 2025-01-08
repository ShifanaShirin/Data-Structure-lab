#include <stdio.h>
#include <stdlib.h>

struct node {
    	int data;
    	struct node* next;
    	struct node* prev;
};

struct node* head = NULL;

// Function declarations
void insertBegining(int value);
void insertEnd(int value);
void insertPosition(int value, int pos);
void deleteBegining();
void deleteEnd();
void deletePosition(int pos);
void search(int key);
void display();

// Create a new node
struct node* createNode(int value) {
    	struct node* newNode = (struct node*)malloc(sizeof(struct node));
    	newNode->data = value;
    	newNode->next = NULL;
    	newNode->prev = NULL;
    	return newNode;
}

// Insert at the beginning
void insertBegining(int value) {
    	struct node* newNode = createNode(value);
    	if (head == NULL) {
        	head = newNode;
    	} else {
        	newNode->next = head;
        	head->prev = newNode;
        	head = newNode;
    	}
    	printf("Inserted %d at the beginning.\n", value);
    	display();
}

// Insert at the end
void insertEnd(int value) {
    	struct node* newNode = createNode(value);
    	if (newNode == NULL) {
        	printf("Memory allocation failed\n");
        	return;
    	}
    	if (head == NULL) {
        	head = newNode;
    	} else {
        	struct node* temp = head;
       	 	while (temp->next != NULL) {
            	temp = temp->next;
        	}
        	newNode->next = NULL;
        	newNode->prev = temp;
        	temp->next = newNode;
    	}
    	printf("%d inserted at the end.\n", value);
    	display();
}

// Insert at a specific position
void insertPosition(int value, int pos) {
    	if (pos < 1) {
        	printf("Invalid position!\n");
        	return;
    	}
    	if (pos == 1) {
        	insertBegining(value);
        	return;
    	}

    	struct node* newNode = createNode(value);
    	if (newNode == NULL) {
        	printf("Memory allocation failed\n");
        	return;
    	}

    	struct node* temp = head;
    	for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        	temp = temp->next;
    	}

    	if (temp == NULL) {
        	printf("Position %d is out of bounds. Node not inserted\n", pos);
        	free(newNode);
        	return;
    	}

    	newNode->next = temp->next;
   	if (temp->next != NULL) {
        	temp->next->prev = newNode;  
    	}
    	temp->next = newNode;
    	newNode->prev = temp;

    	printf("%d inserted at position %d.\n", value, pos);
    	display();
	}

// Delete from the beginning
void deleteBegining() {
    	if (head == NULL) {
        	printf("List is empty! Nothing to delete.\n");
        	return;
    	}

    	struct node* temp = head;
    	head = head->next;
    	if (head != NULL) {
        	head->prev = NULL;
    	}
    	free(temp);
    	printf("Node deleted from the beginning.\n");
    	display();
}

// Delete from the end
void deleteEnd() {
    	if (head == NULL) {
        	printf("List is empty! Nothing to delete.\n");
        	return;
    	}

    	if (head->next == NULL) {
        	free(head);
        	head = NULL;
       		printf("Node deleted from the end.\n");
        	display();
        	return;
    	}

    	struct node* temp = head;
    	while (temp->next != NULL) {
        	temp = temp->next;
    	}

    	temp->prev->next = NULL;
    	free(temp);
    	printf("Node deleted from the end.\n");
    	display();
}

// Delete from a specific position
void deletePosition(int pos) {
    	if (head == NULL) {
        	printf("List is empty.\n");
        	return;
    	}

    	if (pos == 1) {
        	deleteBegining();
        	return;
    	}

    	struct node* temp = head;
    	for (int i = 1; i < pos && temp != NULL; i++) {
        	temp = temp->next;
    	}

    	if (temp == NULL) {
        	printf("Invalid position.\n");
    	} else {
        	if (temp->next != NULL) {
            	temp->next->prev = temp->prev;
        }
        if (temp->prev != NULL) {
            	temp->prev->next = temp->next;
        	}
        	printf("Deleted %d from position %d.\n", temp->data, pos);
        	free(temp);
    	}
   	 display();
}

// Search for a key
void search(int key) {
    	struct node* temp = head;
    	int pos = 1;
   	while (temp != NULL) {
        	if (temp->data == key) {
            		printf("Value %d found at position %d.\n", key, pos);
            		return;
       		}
       	 	temp = temp->next;
        	pos++;
    	}
    	printf("Value %d not found.\n", key);
}

// Display the list
void display() {
    	if (head == NULL) {
        	printf("List is empty!\n");
        	return;
    	}
    	struct node* temp = head;
    	printf("\nLinked List elements: ");
    	while (temp != NULL) {
        	printf("%d ", temp->data);
        	if (temp->next != NULL) printf("-> ");
        	temp = temp->next;
    	}
    	printf("\n");
}

// Main function
int main() {
    	int choice, subchoice, value, position;
    	do {
        	printf("Choose the operation:\n1. Insertion\n2. Deletion\n3. Search\n4. Display\n5. Exit\n");
        	scanf("%d", &choice);
        	switch (choice) {
            	case 1:
                	printf("Choose the Insertion method:\n1. Insert at beginning\n2. Insert at end\n3. Insert at any position\n");
                	scanf("%d", &subchoice);
                	switch (subchoice) {
                   	case 1:
                        	printf("\nEnter the value to be inserted at the beginning: ");
                        	scanf("%d", &value);
                        	insertBegining(value);
                        	break;
                    	case 2:
                        	printf("Enter the value to be inserted at the end: ");
                        	scanf("%d", &value);
                        	insertEnd(value);
                        	break;
                    	case 3:
                        	printf("Enter the value and position to be inserted: ");
                        	scanf("%d %d", &value, &position);
                        	insertPosition(value, position);
                        	break;
                    	default:
                        	printf("Invalid Choice!!!\n");
                        	break;
                	}
                	break;
            	case 2:
                	printf("Choose the Deletion method:\n1. Delete from beginning\n2. Delete from end\n3. Delete from any position\n");
                	scanf("%d", &subchoice);
                	switch (subchoice) {
                    	case 1:
                        	deleteBegining();
                        	break;
                    	case 2:
                        	deleteEnd();
                        	break;
                    	case 3:
                        	printf("Enter the position to be deleted: ");
                        	scanf("%d", &position);
                        	deletePosition(position);
                        	break;
                    	default:
                        	printf("Invalid Choice!!!\n");
                       		break;
               		}
                	break;
            	case 3:
                	printf("Enter the value to search: ");
                	scanf("%d", &value);
                	search(value);
               		break;
            	case 4:
                	display();
                	break;
            	case 5:
                	printf("Exiting...\n");
                	break;
            	default:
                	printf("Invalid Choice!!!\n");
                	break;
        	}
    	} while (choice != 5);
    	return 0;
}
