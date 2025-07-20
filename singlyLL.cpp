#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
    node(int data1, node *next1)
    {
        data = data1;
        next = next1;
    }
    node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};
node *con2l(vector<int> &a)
{
    node *head = new node(a[0]);
    node *mover = head;
    for (int i = 1; i < a.size(); i++)
    {
        node *temp = new node(a[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
void print(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

node *removeHead(node *head)
{
    if (head == NULL)
        return head;
    node *temp = head;
    head = head->next;
    free(temp); // delete temp;
    return head;
}

node *removeAtpos(node *head, int i)
{
    int c = 0;
    if (head == NULL)
        return head;

    // Case 1: remove head
    if (i == 1)
    {
        node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    node *temp = head;
    while (temp != NULL && c < i - 2)
    {
        temp = temp->next;
        c++;
    }

    // If position is invalid (greater than length)
    if (temp == NULL || temp->next == NULL)
        return head;

    // Remove the node at position i
    node *del = temp->next;
    temp->next = del->next;

    free(del);
    return head;
}

node *removetail(node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;

    node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}
node *removeval(node *head, int val)
{
    if (head == NULL)
        return NULL;
    if (head->data == val)
    {
        node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    node *temp = head;
    node *prev = NULL;
    while (temp->next != NULL)
    {
        if (temp->next->data == val)
        {
            prev->next = prev->next->next;
            free(temp);
            temp->next = NULL;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
node *insAthead(node *head, int i)
{   
    node *temp =  new node(i,head);
    return temp;
}
node *insAttail(node *head, int i)
{
    if(head==NULL)
    {
    return new node(i);
    }
    node *temp = head;
    while (temp->next!=NULL )
    { 
         temp = temp->next;
    }
    node *temp1 =  new node(i);
    temp->next= temp1; 
    return head;
}
node *insAtpos(node *head, int i,int pos)
{   int c=0;

    if(head==NULL)
    { if(pos==1)
       {
        return new node(i);
       }
       else
       return NULL;
    }

    if(pos==1) 
    {
        node* temp=new node(i,head);
        return temp;
    }

    node *temp = head;
    while (temp!=NULL )
    {   c++;
        if(c==pos-1)
        {
        node* newnode=new node(i);
        newnode->next=temp->next;
        temp->next=newnode;
        break;
        }
        temp=temp->next;
    }
    return head;
}
node*insAfval(node*head,int i,int posval)
{
    if(head==NULL) return NULL;
    node*temp=head;
    while(temp->next!=NULL)
    {
        if(temp->data==posval)
        {
        node* newnode=new node(i);
        newnode->next=temp->next;
        temp->next=newnode;
        break;
        }
        temp=temp->next; 
    }
    return head;
}
int main()
{
    int i, c, val,pos,posval;
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8};
    node *head = con2l(a);
    while(1)
    {
    cout << "1.remove head\n2.remove at tail\n3.remove at pos\n4.remove at val\n5.insert at head\n6.insert at tail\n7.insert at pos\n8.print value\n9.insert after value\n10.exist\n";
    cin >> c;
    switch (c)
    {
    case 1:
        print(removeHead(head));
        break;
    case 2:
        print(removetail(head));
        break;
    case 3:
        cout << "enter pos";
        cin >> i;
        print(removeAtpos(head, i));
        break;
    case 4:
        cout << "enter value to be delete";
        cin >> val;
        print(removeval(head, val));
        break;
    case 5:
        cout << "enter value to be add at head";
        cin >> i;
        print(insAthead(head, i));
        break;
    case 6:
        cout << "enter value to be add at tail";
        cin >> i;
        print(insAttail(head, i));
        break;
    case 7:
        cout << "enter value to be add";
        cin >> i;
        cout << "enter pos to be add";
        cin >> pos;
        print(insAtpos(head, i,pos));
        break;
    case 8:print(head);
         break;  
    case 9: 
        cout << "enter value to be add after value";
        cin >> posval;
        cout << "enter value";
        cin >> i;
        print(insAfval(head, i,posval));
        break;   
    case 10:
        exit(0);
        break;
    default:
        cout << "wrong";
    }
}
}