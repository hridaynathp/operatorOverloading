/*
    Operator overloading: overloading a left bit shift operator <<
    We can not directly print custom object with cout directly
    we alway use some member function which prints the things we need to display
    
    But we make << to print our object with help of operator overloading
    
    Imagin the statment: cout<<obj<<endl;
    here cout is object of ostream and it only overloaded to work with basic types
    such that, int, string, bool, float ect..., Its not by default overloaded for custom 
    objects and we need to overload it, as per our requirement.
    
    operator << is left to right associative means in above eg, 
    it will execute like (cout<<obj)<<endl; (it will offcourse fail here as we are using custom obj)
    
    here while implementing << operator, as first parameter is of type ostream and not of our class
    we need to implement it as seperate function which can access members of our class, 
    so answer is friend function.
    
    Following is the implementation:


*/
#include <iostream>

using namespace std;
class Person{
    int id;
    string name;
public:
    Person():id(0),name(""){}
    Person(int id, string name):id(id),name(name){}
    void print(){cout<<"id: "<<id<<" name: "<<name<<endl;}

    friend ostream& operator<<(ostream& ostrm, const Person &per){
        ostrm<<"id:"<<per.id<<" name:"<<per.name;
        return ostrm;
    }
};

int main()
{
    Person p1(1,"Vishal");
    p1.print(); // This is how we usually print.
    cout<<p1<<endl; // To make this work.
    return 0;
}
