/*
    Operator overloading: Assignemnt operator
    
    If we directlry assign the custom object of its type to another like,
    p2 = p1, yes it will definately work BUT
    
    it will never work as you expect if there are pointers inside your class, 

    if you dont write your own assignment operator then default assignment operator
    will just blindly copy the content inside pointer (that is address), and then the new object
    initialised with older will always gets changed when you do change in any of object's pointer.
    
    This is not what we want, hense following the implementation of assignemnt opearator.
*/

#include <iostream>

using namespace std;

class Person{
    int id;
    string name;
public:
    Person():id(0),name("NA"){}
    Person(int id, string name):id(id),name(name){}
    void print(){
        cout<<"ID:"<<id<<" Name:"<<name<<endl;
    }

    Person& operator=(const Person& other){
        cout<<"Assignment operator working..."<<endl;
        id = other.id;
        name = other.name;
        return *this;
    }
};
int main()
{
    Person p1(1,"Rahul");
    p1.print();

    Person p2;
    p2 = p1;

    p2.print();

    return 0;
}
