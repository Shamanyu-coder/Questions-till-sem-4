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
class intermediate
{
public:
    int c = 5;

    void output()
    {
        cout << "sum of two number :" << c;
    }
};
class derived : public base, public intermediate
{
public:
    int d;
    void disp()
    {

        d = a + b;
    };
    int main()
    {
        derived obj;
        obj.input();
        obj.output();
        return 0;
    }
