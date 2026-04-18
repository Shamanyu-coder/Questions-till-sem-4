#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node(int data)
    {
        val = data;
        next = NULL;
    }
};
// void InsertAtHead(Node *&head, int val)
// {
//     // new node create
//     Node *new_node = new Node(val);
//     new_node->next = head;
//     head = new_node;
// }
void InsertAtTail(Node *&tail, int val)
{
    Node *new_node = new Node(val);
    tail->next = new_node;
    tail = new_node;
}
// traversing in linked list
void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        // cout << temp->next;
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    Node *new_node = new Node(10);
    Node *head = new_node;
    Node *tail = new_node;
    display(head);
    InsertAtTail(tail, 20);
    display(head);
    InsertAtTail(tail, 30);
    display(head);
}
