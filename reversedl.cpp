#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
    node *back;
    node(int data1, node *next1, node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }
    node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};
node *con2dl(vector<int> a)
{
    node *head = new node(a[0]);
    node *mover = head;
    for (int i = 1; i < a.size(); i++)
    {
        node *temp = new node(a[i], nullptr, mover);
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
node*reverse( node*head)
{   node*temp=head;
    node*last=nullptr;
    while(temp)
    {
     last=temp->back;
     temp->back=temp->next;
     temp->next=last;
     temp=temp->back;
    }
 return last->back;
}
// node *reverse(vector<int> a)
int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8};
    node *head = con2dl(a);
    print(head);
    head=reverse(head);
    print(head);
}