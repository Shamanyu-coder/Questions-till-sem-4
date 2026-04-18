// #include <iostream>
// using namespace std;
// class Node
// {
// public:
//     int val;
//     Node *next;
//     // constructor
//     Node(int data)
//     {
//         val = data;
//         next = NULL;
//     }
// };

// void InsertAtHead(Node *&head, int val)
// {
//     // new node create
//     Node *new_node = new Node(val);
//     new_node->next = head;
//     head = new_node;
// }
// // traversing in linked list
// void display(Node *&head)
// {
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->val << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }
// int main()
// {
//     Node *new_node = new Node(10);
//     display(new_node);
//     Node *head = new_node;
//     InsertAtHead(head, 20);
//     display(head);
//     InsertAtHead(head, 30);
//     display(head);
// }
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
void InsertAtHead(Node *&head, int val)
{
    Node *n = new Node(val);
    n->next = head;
    head = n;
}
void Display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << "\t";
        temp = temp->next;
    }
    cout << endl;
}
int search(Node *head, int x)
{
    Node *n = head;
    while (n != NULL)
    {
        if (n->val == x)
        {
            return 1;
        }
        n = n->next;
    }
    return -1;
}
int main()
{
    Node *n = new Node(10);
    int x = 80;
    Display(n);
    InsertAtHead(n, 20);
    Display(n);
    InsertAtHead(n, 30);
    Display(n);
    int result = search(n, x);
    if (result == 1)
    {
        cout << "elemt found";
    }
    else
    {
        cout << "elemnt not found";
    }

    return 0;
}
