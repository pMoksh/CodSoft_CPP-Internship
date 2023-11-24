//CODSOFT C++ Programming
//Moksh Pohoja
//Dr. Akhilesh Das Gupta Institute of Technology
//Task 2 Simple Calculator

#include<iostream>
using namespace std;

int main()
{
    double num1, num2, result=0;
    char operat;
    cout<<"Enter first number \n";
    cin>>num1;
    cout<<"Enter second number \n";
    cin>>num2;
    cout<<"Enter operation to be performed(+,-,*,/)\n";
    cin>>operat;
    switch (operat)
    {
    case '+':
        result= num1+num2;
        break;
    case '-':
        result= num1-num2;
        break;
    case '*':
        result=num1 * num2;
        break;
    case '/':
        
        if(num2==0)
         { 
            cout<<"Cannot dividde by zero\n";
            return 1;
         }
         result=num1/num2;
        break;
    default:
        cout<<"Enter correct operation\nTry Again";
        return 1;
    }
    cout<<num1<<" "<<operat<<" "<<num2<<" = "<<result;
    return 0;
}