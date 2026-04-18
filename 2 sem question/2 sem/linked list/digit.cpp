#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    // constructor
    Node(int data)
    {
        val = data;
        next = NULL;
    }
};
int main()
{
    Node *n = new Node(5);
    // Node *nl = new Node(3);
    cout << n->val << "\t" << n->next;
    cout << endl;
    // cout << nl->val << "\t" << nl->next;
    return 0;
}