struct node2{
    int data;
    struct node2* link;
};
struct node2* create(){
    int a;
    printf("ENTER NUMBER OF ELEMENT:-");
    scanf("%d",&a);
    struct node2 *head=NULL;
    struct node2 *cur;
    for(int i=0;i<a;i++){
        int b;
        printf("\nENTER DATA:-");
        scanf("%d",&b);
        struct node2* new=malloc(sizeof(struct node2));
        new->data=b;
        new->link=NULL;
        if(head==NULL){
            head=new;
        }
        else{
            cur->link=new;
        }
        cur=new;
    }
    return head;
}