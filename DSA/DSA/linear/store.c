// struct node *cur;
    // for(int i=1;i<6;i++){
    //     if(head==NULL){
    //         head=malloc(sizeof(struct node));
    //         head->data=i;
    //         head->link=NULL;
    //         cur=head;
    //     }
    //     else{
    //     struct node *ele=malloc(sizeof(struct node));
    //     ele->data=i;
    //     ele->link=NULL;
    //     cur->link=ele;
    //     cur=cur->link;
    //     }
    // }





    //struct node* cur;
    // struct node* head=malloc(sizeof (struct node));
    // head->data=1;
    // head->link=NULL;
    // cur=head;

    // struct node* ele=malloc(sizeof (struct node));
    // ele->data=2;
    // ele->link=NULL;
    // cur->link=ele;
    // cur=cur->link;

    // ele=malloc(sizeof(struct node));
    // ele->data=3;
    // ele->link=NULL;
    // cur->link=ele;
    // cur=cur->link;

    // ele=malloc(sizeof(struct node));
    // ele->data=4;
    // ele->link=NULL;
    // cur->link=ele;
    // cur=cur->link;

    // ele=malloc(sizeof(struct node));
    // ele->data=5;
    // ele->link=NULL;
    // cur->link=ele;
    // cur=cur->link;

    // while(1){
    //     int choice;
    //     printf("1.insert in end\n2.insert in frount\n3.insert in mid\n4.delete in end\n5.delete in frount\n6.delete in mid\n7.sort\n8.print\n9.exit");
    //     scanf("%d",&choice);
    //     if(choice==1){
    //         head=insertend(head);
    //     }
    //     elif(choice==2){
    //         head=insertfrount(head);
    //     }
    //     elif(choice==3){
    //         int pos;
    //         printf("\nEnter position:-");
    //         scanf("%d",&pos);
    //         head=insertmid(head,pos);
            
    //     }
    //     elif(choice==4){
            
    //     }
    //     elif(choice==5){
            
    //     }
    //     elif(choice==6){
            
    //     }
    //     elif(choice==7){
            
    //     }
    //     elif(choice==8){
    //         show(head);
    //     }
    //     elif(choice==9){
    //         break;
    //     }
    //     else{
    //         printf("invalid choice");
    //     }
    // }

struct node* create(struct node *head){
    struct node *temp=head,*ele,*tail;
    int a;
    printf("\nENTER NUMBER OF ELEMENT OF LINKED LIST:-");
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        int b;
        printf("\nENTER ELEMENT:-");
        scanf("%d",&a);
        if(head==NULL){
            head->data=b;
            head->link=head;
            temp=head;
            tail=head;
        }
        else{
            ele=malloc(sizeof(struct node));
            ele->data=b;
            ele->link=head;
            temp->link=
        }
    }
}



struct node* deletefrount(struct node *head){
    struct node *temp=head;
    head=head->link;
    free(temp);
    return head;
}

void deletemid(struct node *temp){
    struct node *efree=temp->link;
    temp->link=temp->link->link;
    free(efree);
}

struct node* delete(struct node *head,struct node *tail,int a){
    struct node *temp=head->link;
    if(head->data==a){
        head=deletefrount(head);
    }
    while(temp->link!=head){
        deletemid(temp);
        temp=temp->link;
    }
    if(tail->data==a){
        free(tail->link);
        tail=temp;
    }
    return head;
}



