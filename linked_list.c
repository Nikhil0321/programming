#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
} *first;
void addAtBeginning(int n)
{
    struct node *tmp,*newNode;
    newNode=(struct node *)malloc(sizeof(struct node));
    newNode->data=n;
    newNode->next=NULL;
    if(first==NULL)
    {
        first=newNode;
        return;
    }
    else
    {
        tmp=first;
        newNode->next=first;
        first=newNode;
    }
}
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
    // Traverse to the last node
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
void search()
{
    struct node *tmp;
    int key;
    tmp=first;
    printf("Enter the data to search:");
    scanf("%d",&key);
        while(tmp!=NULL)
        {
            if(tmp->data==key)
            {
                printf("Element found");
                return;
            }
            tmp=tmp->next;
        }
        printf("Not found");
}
void display_middle()
{
    struct node *p,*q;
    p=first;
    q=first;
    if(first==NULL)
    {
        printf("List is Empty");
        return;
    }
    else
    {
        while(p&&q&&q->next)
        {
            p=p->next;
            q=q->next->next;
        }    
    printf("%d",p->data);
    }
}
void delete_last()
{
    struct node *tmp,*pre=NULL;
    tmp=first;
    if(tmp==NULL)
    {
        printf("List is Empty\n");
        return;
    }
    else if(first->next==NULL)
    {
        free(first);
        first=NULL;
        return;
    }
    else
    {
        while(tmp->next!=NULL)
        {
            pre=tmp;
            tmp=tmp->next;
        }
        pre->next=NULL;
        printf("Deleted node with data %d from end\n",tmp->data);
        free(tmp);

    }
    
}
void insert_after(int key,int new_val)
{
    struct node *new_node,*tmp=first;
    while(tmp!=NULL)
    {
        if(tmp->data==key)
            break;
        tmp=tmp->next;
    }
    if(tmp==NULL)
    {
        printf("Key not found\n");
        return;
    }
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=new_val;
    new_node->next=tmp->next;
    tmp->next=new_node;
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
    int x=1,pos,data,key,new_val;
    while(x)
    {
        printf("Enter 1 to add at Beginning\nEnter 2 to insert new node at the end\nEnter 3 to delete first node\nEnter 4 to display list \nEnter 5 to search element \nEnter 6 to display middle element\nEnter 7 to delete last node\nEnter 8 to insert after the data\nEnter 9 to enter at position\nEnter 10 to reverse a linked list\nEnter 0 to end\n");
        scanf("%d",&x);
        switch(x)
        {
        case 1:
            printf(
            "Enter data to insert at the beginning of the list: \n");
            scanf("%d",&data);
            addAtBeginning(data);
            break;
        case 2:
            printf("\nEnter data to insert at end of the list: \n");
            scanf("%d", &data);
            insertNodeAtEnd(data);
            break;
        case 3:deleteFirstNode();
            break;
        case 4: display();
            break;
        case 5: 
            search();
            break;
        case 6:
            display_middle();
            break;
        case 7:
            delete_last();
            break;
        case 8:
            printf("Enter key to search for : ");
            scanf("%d",&key);
            printf("\nData to add : ");
            scanf("%d",&new_val);
            insert_after(key,new_val);
            break;
	    case 9:
            printf("Enter the position : ");
            scanf("%d",&pos);
            printf("\nEnter the data : ");
            scanf("%d",&data);
            insertAtPosition(data,pos);
            break;
        case 10:
            reverse();
            display();
            break;
        default : break;
    }
    }
    return 0;
}