
    #include<stdio.h>  
    #include<stdlib.h>  
    struct node  
    {  
        struct node *prev;  
        struct node *next;  
        int data;  
    };  
    struct node *head;  
    void insertion_beginning();  
    void deletion_beginning();  
    void deletion_specified();  
    void display();  
    void search(); 
    int countNodes();
    void reverse();
    void main ()  
    {  
    int choice =0;  
        while(choice != 9)  
        {  
            printf("\n*********Main Menu*********\n");  
            printf("\nChoose one option from the following list ...\n");  
            printf("\n===============================================\n");  
            printf("\n1.Insert in begining\n 2.Delete from Beginning\n 3.Delete the node after the given data\n4.Search\n5.display 6.count\n 7.reverse\n 8.Exit\n");  
            printf("\nEnter your choice?\n");  
            scanf("\n%d",&choice);  
            switch(choice)  
            {  
                case 1: insertion_beginning();  
                    break;  
                case 2: deletion_beginning();  
                    break;  
                case 3: deletion_specified();  
                    break;  
                case 4: search();  
                    break;  
                case 5: display();  
                    break;  
                case 6 : countNodes();
                   break;
                case 7 : reverse();
                    break;
                case 8: exit(0);  
                    break;  
                default:  
                printf("Please enter valid choice..");  
            }  
        }  
    }  
    void insertion_beginning()  
    {  
       struct node *ptr;   
       int item;  
       ptr = (struct node *)malloc(sizeof(struct node));  
       if(ptr == NULL)  
       {  
           printf("\nOVERFLOW");  
       }  
       else  
       {  
        printf("\nEnter Item value");  
        scanf("%d",&item);  
          
       if(head==NULL)  
       {  
           ptr->next = NULL;  
           ptr->prev=NULL;  
           ptr->data=item;  
           head=ptr;  
       }  
       else   
       {  
           ptr->data=item;  
           ptr->prev=NULL;  
           ptr->next = head;  
           head->prev=ptr;  
           head=ptr;  
       }  
       printf("\nNode inserted\n");  
    }  
         
    }  
    
    void deletion_beginning()  
    {  
        struct node *ptr;  
        if(head == NULL)  
        {  
            printf("\n UNDERFLOW");  
        }  
        else if(head->next == NULL)  
        {  
            head = NULL;   
            free(head);  
            printf("\nnode deleted\n");  
        }  
        else  
        {  
            ptr = head;  
            head = head -> next;  
            head -> prev = NULL;  
            free(ptr);  
            printf("\nnode deleted\n");  
        }  
      
    }  
    
    void deletion_specified()  
    {  
        struct node *ptr, *temp;  
        int val;  
        printf("\n Enter the data after which the node is to be deleted : ");  
        scanf("%d", &val);  
        ptr = head;  
        while(ptr -> data != val)  
        ptr = ptr -> next;  
        if(ptr -> next == NULL)  
        {  
            printf("\nCan't delete\n");  
        }  
        else if(ptr -> next -> next == NULL)  
        {  
            ptr ->next = NULL;  
        }  
        else  
        {   
            temp = ptr -> next;  
            ptr -> next = temp -> next;  
            temp -> next -> prev = ptr;  
            free(temp);  
            printf("\nnode deleted\n");  
        }     
    }  
    void display()  
    {  
        struct node *ptr;  
        printf("\n printing values...\n");  
        ptr = head;  
        while(ptr != NULL)  
        {  
            printf("%d\n",ptr->data);  
            ptr=ptr->next;  
        }  
    }   
    void search()  
    {  
        struct node *ptr;  
        int item,i=0,flag;  
        ptr = head;   
        if(ptr == NULL)  
        {  
            printf("\nEmpty List\n");  
        }  
        else  
        {   
            printf("\nEnter item which you want to search?\n");   
            scanf("%d",&item);  
            while (ptr!=NULL)  
            {  
                if(ptr->data == item)  
                {  
                    printf("\nitem found at location %d ",i+1);  
                    flag=0;  
                    break;  
                }   
                else  
                {  
                    flag=1;  
                }  
                i++;  
                ptr = ptr -> next;  
            }  
            if(flag==1)  
            {  
                printf("\nItem not found\n");  
             }  
        }     
              
    }  



void reverse()
{  
    struct node *current = head, *temp = NULL;
    while(current != NULL) {  
        temp = current->next;  
        current->next = current->previous;  
        current->previous = temp;  
        current = current->previous;  
    }  
    temp = head;  
    head = tail;  
    tail = temp;  
}  

int countNodes() 
{  
    int counter = 0; 
    struct node *current = head;  
      
    while(current != NULL) 
    {  
        counter++;  
        current = current->next;  
    }  
    return counter;  
}  




