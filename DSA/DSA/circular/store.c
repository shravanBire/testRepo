void swap(struct node* second){
    struct node *pre=second->prev;
    struct node *cur=second;
    struct node *nex=second->next;
    struct node *nex2=nex->next;
    pre->next=nex;
    nex->prev=pre;
    nex->next=cur;
    cur->prev=nex;
    cur->next=nex2;
    nex2->prev=cur;
}
void sort(struct node *tail){
    struct node *head=tail->next;
    struct node *first=head->next,*second=head->next;
    while(first->next!=tail){
        while(second->next!=tail){
            if((second->data)>(second->next->data)){
                swap(second);
            }
            second=second->next;
        }
        first=first->next;
        second=first->next;
    }
}