//CODSOFT C++ Programming
//Moksh Pohoja
//Dr. Akhilesh Das Gupta Institute of Technology
//Task 3 Student Grading System

#include<iostream>
#include<string>
using namespace std;

class student{
        char  name[50];
        float grades;

    public:
        void getdata()
        {
            cout<<"\nEnter name";
            cin>>name;
            cout<<"\nEnter grades";
            cin>>grades;
        }
        void putdata()
        {
            cout<<name<<" : "<<grades<<endl;
        }
        float ret_grades()
        {
            return grades;
        }
};
int main()
{
    const int MAx_STUD =50;
    student stud[MAx_STUD];
    double avg;
    float high,low,sum;
    int num;
    cout<<"Enter total no of students";
    cin>>num;

    for(int i=0;i<num;i++)
    {
        cout<<"Enter details of student "<<i+1;
        stud[i].getdata();
    }
    high =stud[0].ret_grades();
    low =stud[0].ret_grades();
    sum=0;
    for(int i=0;i<num;i++)
    {
        sum+=stud[i].ret_grades();
        if(stud[i].ret_grades() > high)
            high = stud[i].ret_grades();
        if(stud[i].ret_grades() <low)
            low = stud[i].ret_grades();
    }

    cout<<"Class grades:\n";
    for(int i=0;i<num;i++)
    {
        stud[i].putdata();
    }
    cout<<num;
    avg= (double)sum/num;
    cout<<"Average grade: "<<avg;
    cout<<"\nHighest grade: "<<high;
    cout<<"\nLowest grade: "<<low;
}