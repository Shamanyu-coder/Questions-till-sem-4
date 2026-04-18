#include <iostream>
using namespace std;
class shape
{
public:
    double radius, side;
    void inputcircle()
    {
        cout << "enter radius :" << endl;
        cin >> radius;
    }
    void inputsquare()
    {
        cout << "enter side :" << endl;
        cin >> side;
    }
};
class circle : public shape
{
public:
    void areaofcircle()
    {
        cout << "area of radius  " << 3.14 * radius * radius << " square units" << endl;
    }
};
class square : public shape
{
public:
    void areaofsquare()
    {
        cout << "area of square " << side * side << " square units" << endl;
    }
};
int main()
{
    circle obj;
    obj.inputcircle();
    obj.areaofcircle();
    square obj1;
    obj1.inputsquare();
    obj1.areaofsquare();
    return 0;
}
