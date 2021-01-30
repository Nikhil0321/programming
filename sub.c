#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
} *first;
void insertNodeAtEnd(int n)
{
    struct node *newNode, *temp;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = n;
    newNode->next = NULL;
    temp = first;
    if(first==NULL)
    {
		first=newNode;
		return;
    }
    while(temp->next != NULL)
    temp = temp->next;
    temp->next = newNode;
    printf("DATA INSERTED SUCCESSFULLY\n");
}
void deleteFirstNode()
{
    if(first==NULL)
    {
        printf("no elements in the list");
    }
    else
    {
        struct node *toDelete;
        toDelete = first;
        first = first->next;
        printf("\nData deleted = %d\n", toDelete->data);
        free(toDelete);
        printf("SUCCESSFULLY DELETED FIRST NODE FROM LIST\n");
    }
}
void display()
{
    struct node * temp=first;
    if(first==NULL)
    {
        printf("no elements in the list");
    }
    else
    {
        printf("List elements are\n");
        while(temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }
    }
}
void insertAtPosition(int info,int pos)
{
    struct node *tmp=first,*new_node;
    int i;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=info;
    new_node->next=NULL;
    if(pos==1)
    {
        new_node->next=tmp;
        first=new_node;
        return;
    }
    for(i=1;i<pos-1;i++)
    {
        tmp=tmp->next;
    }
    new_node->next=tmp->next;
    tmp->next=new_node;
}
void reverse()
{
    struct node *cur,*pre,*next;
    cur=first;
    pre=NULL;
    next=NULL;
    while(cur!=NULL)
    {
        next=cur->next;
        cur->next=pre;
        pre=cur;
        cur=next;
    }
    first=pre;
}
int main()
{
    int x=1,n,data,key,new_val;
    while(x)
    {
        printf("Enter 1 to insert new node at the end\nEnter 2 to delete first node\nEnter 3 to enter at position \nEnter 4 to enter to reverse the linked list\nEnter 5 to display\nEnter 0 to end\n");
        scanf("%d",&x);
        switch(x)
        {
        case 1:
            printf("\nEnter data to insert at end of the list: \n");
            scanf("%d", &data);
            insertNodeAtEnd(data);
            break;
        case 2:deleteFirstNode();
            break;
	    case 3:
            printf("Enter the position : ");
            scanf("%d",&n);
            printf("\nEnter the data : ");
            scanf("%d",&data);
            insertAtPosition(data,n);
            break;
        case 4:
            reverse();
            display();
            break;
        case 5: display();
            break;
        default : break;
		}
    }
    return 0;
}