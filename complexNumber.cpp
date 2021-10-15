/*
    Operator Overloading for complex numbers:
    Following functionalities are implemented in single program:
    1. Copy constructor
    2. Assignemnt operator
    3. Stream insertion operator
*/

#include <iostream>

using namespace std;
class Complexx{

    double real;
    double imaginary;
public:
    Complexx():real(0.0), imaginary(0.0){}
    Complexx(double real, double imaginary):real(real), imaginary(imaginary){}

    // Copy constructor
    Complexx(const Complexx& other){
        cout<<"Copy Constructor invoked..."<<endl;
        real = other.real;
        imaginary = other.imaginary;
    }

    // Assignment Operator
    Complexx& operator=(const Complexx& other){
        cout<<"Assignment Operator invoked..."<<endl;
        real = other.real;
        imaginary = other.imaginary;

        return *this;
    }

    // Stream operator
    friend ostream& operator<<(ostream &out, const Complexx &obj){
        out<<obj.real<<"+"<<obj.imaginary<<"i";
        return out;
    }
    // Display print function
    void print(){
        cout<<"Your Complexx number is: "<<real<<"+"<<imaginary<<"i"<<endl;
    }

};

int main()
{
    cout << "Hello world!" << endl;
    Complexx one(10.0,5.0);
    one.print();

    Complexx two = one;
    two.print();

    Complexx three;
    three = two;
    three.print();

    cout<<one<<", "<<two<<", "<<three<<endl;

    return 0;
}
