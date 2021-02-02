#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* rlink;
    struct node* llink;
}*first;
void insertNodeAtfront(int n)
{
    struct node *newNode, *temp;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=n;
    newNode->rlink=NULL;
    newNode->llink=NULL;
    temp=first;
    if(first==NULL)
    {
        first=newNode;
        return;
    }
        newNode->rlink=first; 
        newNode->llink=NULL;
        first->llink=newNode;
        first=newNode;
        printf("DATA INSERTED SUCCESSFULLY\n");   
}
void deleteFirstNode()
{
    if(first==NULL)
    {
        printf("no elements in the list\n");
    }
    else
    {
        struct node *toDelete;
        toDelete=first;
        first=first->rlink;
        printf("\nData deleted = %d\n",toDelete->data);
        free(toDelete);
        printf("SUCCESSFULLY DELETED FIRST NODE FROM LIST\n");
    }
}
void display()
{
    struct node * temp=first;
    if(first==NULL)
    {
        printf("no elements in the list\n");
    }
    else
    {
        printf("List elements are\n");
        while(temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->rlink;
        }   
    }
}
void deleteatgivenposition(int pos)
{
    struct node *temp=first,*pre;
    int i;
    if(pos==1)
    {
        deleteFirstNode();
        return;
    }
    for(i=1;i<pos&&temp!=NULL;i++)
    {
        temp=temp->rlink;
    }
    if(temp->rlink!=NULL)
    {
        temp->llink->rlink=temp->rlink;  
        temp->rlink->llink=temp->llink;  
        printf("%d deleted successfully",temp->data);
        free(temp);
        return;
    }
    if(temp->rlink==NULL)
    {
        temp->llink->rlink=NULL;
        printf("%d is deleted",temp->data);
        free(temp);
    }
}
void reverse()
{
    struct node *cur,*pre,*rlink;
    cur=first;
    pre=NULL;
    rlink=NULL;
    while(cur!=NULL)
    {
        rlink=cur->rlink;
        cur->rlink=pre;
        pre=cur;
        cur=rlink;
    }
    first=pre;
}
int search(int key)
{
    struct node *tmp=first;
    while(tmp->rlink!=NULL||tmp->rlink==NULL)
    {
        if(key==tmp->data)
        {
            return 1;    
        }
    tmp=tmp->rlink;
    }   
}
int count()
{
    if(first==NULL)
    {
        printf("list is empty\n");
        return 0;
    }
    struct node *temp;
    temp=first;
    int n=1;
    while(temp->rlink!=NULL)
    {
        temp=temp->rlink;
        n++;
    }
    return n;
}
int main()
{
    int x=1,n,data,key,new_val,c,a;
    while(x)
    {
        printf("Enter 1 to insert new node at the front\nEnter 2 to delete first node\nEnter 3 to delete at position \nEnter 4 to reverse the linked list\nEnter 5 to display\nEnter 6 to count\nEnter 7 to Search\nEnter 0 to end\n");
        scanf("%d",&x);
        switch(x)
        {
            case 1:
            printf("\nEnter data to insert at front of the list: \n");
            scanf("%d",&data);
            insertNodeAtfront(data);
            break;
            case 2:
            deleteFirstNode();
            break;
            case 3:
            printf("Enter the position : ");
            scanf("%d",&n);
            deleteatgivenposition(n);
            break;
            case 4:
            reverse();
            display();
            break;
            case 5:
            display();
            break;
            case 6:
            c=count();
            printf("no of nodes are=%d\n",c);
            break;
            case 7:
            printf("enter the element to be searched\n");
            scanf("%d",&key);
            a=search(key);
            if(a==1)
            printf("Successfull search\n");
            else
            printf("unSuccessfull search\n");
            break;
            default : break;
        }
    }
return 0;
}
