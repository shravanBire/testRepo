#include<stdio.h>
#include<stdlib.h>

// Define the structure for a node in the linked list
struct node{
    int data; // Data part of the node
    struct node* link; // Pointer to the next node
};

// Function to create a linked list and insert a new node at the end
struct node* createll(struct node* head, int dta){
    // Allocate memory for a new node
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = dta; // Set the data for the new node
    newnode->link = NULL; // Initialize the link to NULL
  // changes done
    // If the list is empty, the new node becomes the head
    if(head == NULL){
        head = newnode;
    }
    else{
        // Traverse to the end of the list and link the new node
        struct node* temp = head;
        while(temp->link != NULL){
            temp = temp->link;
        }
        temp->link = newnode; // Link the new node
    }
    return head; // Return the updated head
}

// Function to create a linked list based on user input
struct node* create(){
    int a;
    printf("ENTER NUMBER OF ELEMENT:-");
    scanf("%d", &a); // Read the number of elements
    struct node *head = NULL; // Initialize head to NULL
    struct node *cur; // Pointer to traverse the list

    // Loop to create nodes based on user input
    for(int i = 0; i < a; i++){
        int b;
        printf("\nENTER DATA:-");
        scanf("%d", &b); // Read data for the new node
        struct node* new = malloc(sizeof(struct node)); // Allocate memory for new node
        new->data = b; // Set the data for the new node
        new->link = NULL; // Initialize the link to NULL

        // If the list is empty, set the new node as head
        if(head == NULL){
            head = new;
        }
        else{
            cur->link = new; // Link the new node to the current node
        }
        cur = new; // Move current pointer to the new node
    }
    return head; // Return the head of the list
}

// Function to display the elements of the linked list
void show(struct node *head){
    struct node *temp = head; // Temporary pointer to traverse the list
    if(head == NULL){
        printf("\nList is empty"); // If the list is empty
    }
    while(temp != NULL){
        printf("%d ", temp->data); // Print the data of each node
        temp = temp->link; // Move to the next node
    }
    printf("\n"); // New line after printing the list
}

// Function to find and print the middle element of the linked list
void middle_list(struct node *head){
    struct node *start = head; // Pointer to traverse from the start
    struct node *end = head; // Pointer to traverse from the end
    int i = 1;

    // Traverse the list to find the middle element
    while(end->link != NULL){
        start = start->link; // Move start pointer
        for(int j = 1; j < i * 2; j++){ // Move end pointer
            if(end->link == NULL){
                break;
            }
            else{
                end = end->link;
            }
        }
        i++;
    }
    printf("\n%d", start->data); // Print the middle element
}

struct node *reverse_list(struct node *head){
    struct node *prev=NULL;
    struct node *next=head->link;
    struct node *cur=head;
    while(cur->link!=NULL){
        cur->link=prev;
        prev=cur;
        cur=next;
        next=next->link;
    }
    cur->link=prev;
    head=cur;
    return(head);
}

struct node *rotate_list(struct node *head,int pos){
    struct node *joint=head;
    while(pos!=1){
        head=head->link;
        pos--;
    }
    struct node *end=head;
    head=head->link;
    struct node *cur=head;
    while(cur->link!=NULL){
        cur=cur->link;
    }
    cur->link=joint;
    end->link=NULL;
    return(head);
}

struct node *nthend(struct node *head,int pos){
    struct node *guard=head;
    struct node *ele=head;
    while(pos != 1){
        guard=guard->link;
        pos--;
    }
    while(guard->link!=NULL){
        ele=ele->link;
        guard=guard->link;
    }
    return(ele);
}//printf("%d",nthend(head,2)->data);

void duplicate(struct node *head){
    struct node *temp=head;
    struct node *cur=head;
    struct node *temp2;
    while(temp!=NULL){
        int a=temp->data;
        temp2=cur->link;
        if(a==temp2->data){
            cur->link=cur->link->link;
            if(a==cur->link->data){
                continue;
            }
        }
        temp=temp->link;
        cur=cur->link;
    }
}

void nafterm(struct node *head,int m,int n){
    struct node *temp=head;
    int a=1,b=0;
    while(temp!=NULL){
        if(a!=m){
            temp=temp->link;
            a++;
            continue;
        }
        if(b!=n){
            temp->link=temp->link->link;
            b++;
            continue;
        }
        temp=temp->link;
        a=1;
        b=0;
    }

}

struct node* pairswap(struct node *head){
    struct node *temp,*prev=head,*next=head->link;
    while(next!=NULL){
        if(prev==head){
            prev->link=next->link;
            next->link=prev;
            head=next;
            temp=prev;
            prev=prev->link;
            next=prev->link;
        }
        else{
            prev->link=next->link;
            temp->link=next;
            next->link=prev;
            temp=prev;
            prev=prev->link;
            if(prev==NULL){
                break;
            }
            next=prev->link;
        }
    }
    return(head);
}

struct node* grprev(struct node *head,int grp){
    
}

struct node* lastoccdel(struct node* head,int a){
    struct node *note=NULL;
    struct node *temp=head->link;
    struct node *cur=head;
    while(cur->link!=NULL){
        if(temp->data==a){
            note=cur;
        }
        temp=temp->link;
        cur=cur->link;
    }
    if(head->data==a && note==NULL){
        head=head->link;
        return(head);
    }
    else{
        note->link=note->link->link;
        return(head);
    }
}

struct node* sublistrev(struct node* head,int x,int y){
    int p1=0; 
    struct node* head2=NULL;
    struct node* temp1=head; 
    while(p1!=(x-1)){
        temp1=temp1->link;
        p1++;
    }
    struct node* temp2=temp1;
    while(p1!=y){
        temp2=temp2->link;
        p1++;
    }
    return head;
}

void main(){
    struct node *head;
    head=create(head);
    show(head);
    head=sublistrev(head,3,6);
    show(head);
}
