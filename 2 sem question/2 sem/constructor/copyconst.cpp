#include <iostream>
using namespace std;
class copyconst
{
    int a, b;

public:
    copyconst(int x, int y)
    {
        a = x;
        b = y;
    }
    copyconst(copyconst &xyz) //
    {
        a = xyz.a;
        b = xyz.b;
    }
    void display()
    {
        cout << "the sum of x and y is : "
             << a + b << endl;
        cout << "the product of x and y is : " << a * b << endl;
    }
};
int main()
{
    copyconst p(5, 10);
    p.display();
    // copy constructor
    copyconst q(p);
    q.display();
    return 0;
}