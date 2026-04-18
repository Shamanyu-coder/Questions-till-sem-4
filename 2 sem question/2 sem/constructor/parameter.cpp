#include <iostream>
using namespace std;
class parameter
{
    int a, b;

public:
    parameter(int x, int y)
    {
        a = x;
        b = y;
    }
    int sum()
    {
        return a + b;
    }
    int product()
    {
        return a * b;
    }
};
int main()
{
    parameter p(5, 10);
    cout << "the sum of x and y is : "
         << p.sum() << endl;
    cout << "the product of x and y is : " << p.product();
    return 0;
}
