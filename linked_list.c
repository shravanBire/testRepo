#include<stdio.h>
#include<stdlib.h>

// Define a structure to represent a polynomial term
struct poly {
    int coef;           // Coefficient of the polynomial term
    int pow;            // Power of the polynomial term
    struct poly* next;  // Pointer to the next term in the polynomial
};

// Function to create a new polynomial node and insert it in sorted order
struct poly* create(int coef, int pow, struct poly* head) {
    // Allocate memory for a new polynomial node
    struct poly* node = malloc(sizeof(struct poly));
    node->coef = coef;
    node->pow = pow;
    node->next = NULL;

    // If the list is empty, return the new node as the head
    if (head == NULL) {
        head = node;
        return head;
    } else {
        // If the new node has a higher power than the head, insert at the beginning
        if (head->pow <= node->pow) {
            node->next = head;
            head = node;
            return head;
        }
        struct poly* cur = head; // Current node pointer
        struct poly* prev = NULL; // Previous node pointer

        // Traverse the list to find the correct insertion point
        while (cur->next != NULL) {
            if (cur->pow <= node->pow) {
                prev->next = node; // Insert the new node
                node->next = cur;  // Link the new node to the current node
                return head;
            }
            prev = cur;         // Move previous pointer
            cur = cur->next;   // Move current pointer
        }
        // If reached the end of the list, insert the new node at the end
        cur->next = node;
        return head;
    }
}

// Function to add two polynomials
struct poly* addition(struct poly* head1, struct poly* head2) {
    struct poly* head3 = NULL; // Resultant polynomial

    // Traverse both polynomial lists
    while (head1 != NULL && head2 != NULL) {
        // If head1 has a higher power, add it to head3
        if (head1->pow > head2->pow) {
            head3 = create(head1->coef, head1->pow, head3);
            head1 = head1->next; // Move to the next term in head1
        } 
        // If head2 has a higher power, add it to head3
        else if (head1->pow < head2->pow) {
            head3 = create(head2->coef, head2->pow, head3);
            head2 = head2->next; // Move to the next term in head2
        } 
        // If both have the same power, add their coefficients
        else {
            int coef = head1->coef + head2->coef; // Sum coefficients
            head3 = create(coef, head1->pow, head3); // Add to head3
            head1 = head1->next; // Move to the next term in both
            head2 = head2->next;
        }
    }

    // If there are remaining terms in head1, add them to head3
    while (head1 != NULL) {
        head3 = create(head1->coef, head1->pow, head3);
        head1 = head1->next;
    }

    // If there are remaining terms in head2, add them to head3
    while (head2 != NULL) {
        head3 = create(head2->coef, head2->pow, head3);
        head2 = head2->next;
    }

    return head3; // Return the resultant polynomial
}

// Function to multiply two polynomials
struct poly* multiplication(struct poly* head1, struct poly* head2) {
    struct poly* head3 = NULL; // Resultant polynomial
    struct poly* tempHead2; // Temporary pointer for traversing head2

    // Traverse each term in head1
    while (head1 != NULL) {
        tempHead2 = head2; // Reset tempHead2 for each term in head1
        // Multiply the current term of head1 with each term of head2
        while (tempHead2 != NULL) {
            int coef = head1->coef * tempHead2->coef; // Multiply coefficients
            int pow = head1->pow + tempHead2->pow; // Add powers
            head3 = create(coef, pow, head3); // Add the result to head3
            tempHead2 = tempHead2->next; // Move to the next term in head2
        }
        head1 = head1->next; // Move to the next term in head1
}

void show(struct poly* head){
    struct poly* temp=head;
    while(temp!=NULL){
        printf("%d*x^%d ",temp->coef,temp->pow);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    struct poly* head1 = NULL;
    head1 = create(1,5, head1);
    head1 = create(2,3, head1);

    struct poly* head2 = NULL;
    head2 = create(4,3, head2);
    head2 = create(3,2, head2);
    head2 = create(5,1, head2);

    show(head1);
    show(head2);

    struct poly* head3 =NULL;
    head3 = multiplication(head1,head2);
    show(head3);
}