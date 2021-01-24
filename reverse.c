void reverse()
{
    struct node *prev,*cur;
    if(head!=NULL)
    {
        prev=head;
        cur=head->next;
        head=head->next;
        prev->next=NULL; 
        while(head!=NULL)
        {
            head=head->next;
            cur->next=prev;
            prev=cur;
            cur=head;
        }
        head=prev;
        printf("REVERSED\n");
    }
}