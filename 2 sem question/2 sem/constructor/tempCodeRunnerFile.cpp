#include <iostream>
using namespace std;
class student
{
    int age;
    int uid;
    string name;

public:
    student() // constructor
    {
        cout << "enter age ,uid ,name";
        cin >> age >> uid >> name;
    }
    void display() // member function
    {
        cout << "name :" << name;
        cout << "Age " << age;
        cout << "uid " << uid;
    }
};
int main()
{
    student s;
    s.display();
    return 0;
}