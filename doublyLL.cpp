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
node *removeHead(node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    node *temp = head;
    head = head->next;
    head->back = nullptr;
    temp->next = nullptr;
    free(temp);
    return head;
}
node *removetail(node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    node *tail = temp->back;
    tail->next = nullptr;
    temp->back = nullptr;
    delete temp;
    return head;
}
node *removeAtpos(node *head, int i)
{
    // for head and head next pointer
    if (head == NULL)
        return NULL;

    if (i == 1)
    {
        node *nextNode = head->next;
        if (nextNode != NULL)
        {
            nextNode->back = NULL;
        }
        delete head;
        return nextNode;
    }

    int c = 0;
    node *temp = head;
    while (temp != NULL)
    {
        c++;
        if (c == i)
            break;
        temp = temp->next;
    }
    node *prev = temp->back;
    node *front = temp->next;
    if (prev == NULL && front == NULL)
    {
        return NULL;
    }

    else if (prev == NULL)
    {
        return removeHead(head);
    }

    else if (front == NULL)
    {
        return removetail(head);
    }
prev->next=front;
front->back=prev;
temp->back=nullptr;
temp->next=nullptr;
free(temp);
return head;
}
node *removeval(node *head, int val)
{
    if (head == NULL)
        return NULL;
    node *temp = head;
    while (temp->data == val)
    {
        temp = temp->next;
    }
    node *tail = temp->back;
    tail->next = temp->next;
    temp->back = nullptr;
    delete temp;
    return head;
}
int main()
{
    int c, i, val;
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8};
    node *head = con2dl(a);
    print(head);
    while (1)
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
        default:
            cout << "wrong";
        }
    }
    return 0;
}
