if (head == NULL || head->exp >= valueExp) {
        new->cof = valueCof;
        new->exp = valueExp;
        new->next = head;
        head=new;
    }

    struct node* current = head;
    while (current->next != NULL && current->next->exp < valueExp) {
        current = current->next;
    }

    new->cof = valueCof;
    new->exp = valueExp;
    new->next=NULL;
    new->next = current->next;
    current->next = new;