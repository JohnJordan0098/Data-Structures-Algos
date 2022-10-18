#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int data;
        node* next;
};
node* head=NULL;
node* createNode(int element)
{
    node* temp=new node();
    temp->data=element;
    temp->next=NULL;
    return temp;
}
node* insertAtBeg(int data)
{
    node* temp=createNode(data);
    if(head!=NULL)
        temp->next=head;
    head=temp;
    return head;
}
node* insertAtEnd(int data)
{
    node* temp=createNode(data);
    node* current=head;
    if(head!=NULL)
    {
        while(current->next!=NULL)
            current=current->next;
        current->next=temp;
    }
    else
        head=temp;
    return head;
}
void printll()
{
    node* current=head;
    if(head==NULL)
    {
        cout<<"The linked list is empty\n";
    }
    else
    {
        while(current!=NULL)
        {
            cout<<current->data<<" ";
            current=current->next;
            cout<<endl;
        }
    }   
}
node* deleteAtBeg()
{
    if(head==NULL)
    {
        cout<<"The linked list is empty\n";
        return head;
    }
    else
    {
        head=head->next;
        return head;
    }
}
node* deleteAtEnd()
{
    if(head==NULL)
    {
        cout<<"The linked list is empty\n";
        return head;
    }
    else
    {
        node* temp1;
        node* temp2;
        temp1=head;
        temp2=head;
        while(temp1->next!=NULL)
        {
            temp2=temp1;
            temp1=temp2->next;
        }
        if(temp1==head)
            head=NULL;
        else
        {
            temp2->next=NULL;
        }
        cout<<"The last node is deleted successfully\n";
        free(temp1);
    }
    return head;
}
node* insertAtAny(int p,int data)
{
    if(head==NULL)
    {
        cout<<"The linked list is empty\nInsertion can't possible\n";
        return head;
    }
    node* temp=createNode(data);
    node *size,*temp1,*temp2;
    size=head;
    int c=0,i;
    while(size!=NULL)
    {
        c++;
        size=size->next;
    }
    temp2=head;
    temp1=temp2->next;
    if(p!=1 && p<c+1)
    {
        for(i=0;i<p-2;i++)
        {
            temp2=temp1;
            temp1=temp2->next;
        }
        temp->next=temp1;
        temp2->next=temp;
    }
    else
    {
        cout<<"Insertion can't possible\n";
    }
    return head;
}
node* deleteAtAny(int p)
{
    if(head==NULL)
    {
        cout<<"Linked list is empty\nDeletion is not possible\n";
    }
    node* size,*temp1,*temp2,*temp3;
    size=head;
    int c=0,i;
    while(size!=NULL)
    {
        size=size->next;
        c++;
    }
    temp3=head;
    temp2=temp3->next;
    temp1=temp2->next;
    if(p!=1 && p<c)
    {
        for(i=0;i<p-2;i++)
        {
            temp3=temp3->next;
            temp2=temp3->next;
            temp1=temp2->next;
        }
        temp3->next=temp1;
        free(temp2);
    }
    else
    {
        cout<<"Deletion is not possible\n";
    }
    return head;
}
void search(int x)
{
    node* curr=head;
    int p=1;
    while(curr!=NULL)
    {
        if(curr->data==x)
        {
            cout<<"Element found,position is:"<<p<<endl;
            return;
        }
        p++;
        curr=curr->next;
    }
    if(curr==NULL)
        cout<<"Element not found\n";
    return;
}
node* reverse()
{
    node* pre,*curr,*nex;
    curr=head;
    pre=NULL;
    while(curr!=NULL)
    {
        nex=curr->next;
        curr->next=pre;
        pre=curr;
        curr=nex;
    }
    head=pre;
    return head;
}
int main()
{
	int ch,num,p;
	while(1)
	{
		cout<<"1.InsertAtBeg\n2.InsertAtEnd\n3.Display\n4.DeleteAtBeg\n5.DeleteAtEnd\n6.InsertAtAny\n7.DeleteAtAny\n8.Search\n9.Reverse\n10.Exit\n";
		cout<<"Enter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Enter the element:";
				cin>>num;
				insertAtBeg(num);
				break;
			case 2:
				cout<<"Enter the element:";
				cin>>num;
				insertAtEnd(num);
				break;
			case 3:
				printll();
				break;
			case 4:
				deleteAtBeg();
				break;
			case 5:
				deleteAtEnd();
				break;
			case 6:
				cout<<"Enter the position to insert:";
				cin>>p;
			    cout<<"Enter the data:";
				cin>>num;
				insertAtAny(p,num);
				break;
			case 7:
				cout<<"Enter the position to delete:";
				cin>>p;
				deleteAtAny(p);
				break;
			case 8:
				cout<<"Enter the element to search:";
				cin>>num;
				search(num);
				break;
            case 9:
                reverse();
                cout<<"The linked list is reversed successfully\n";
                break;
			case 10:
				exit(1);
				break;
			default:
				printf("The choice is wrong");
			
		}
	}
}
