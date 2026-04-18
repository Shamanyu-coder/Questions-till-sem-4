#include <iostream>
using namespace std;
class base
{
public:
    int a, b;


    void input()
    {
        cout << "enter a and b";
        cin >> a >> b;
    }
};
class derived : public base
{
public:
    void output()
    {
        cout << "sum of two number :" << a + b;
    }
};
int main()
{
    derived obj;
    obj.input();
    obj.output();
    return 0;
}
