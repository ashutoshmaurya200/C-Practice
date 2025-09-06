// create the student class

#include<iostream>
using namespace std;

class student{
    private:
    int rollno;
    int marks1;
    int marks2;
    int marks3;
    int total_grade;
    float percentage;
    public:

    void accept (){
        cout<<"enter the roll no:"<<endl;
        cin>>rollno;
        cout<<"enter the marks1:"<<endl;
        cin>>marks1;
        cout<<"enter the marks2:"<<endl;
        cin>>marks2;
        cout<<"enter the marks3:"<<endl;
        cin>>marks3;

    }

    void display(){
        cout<<"roll no"<<rollno<<endl;
        cout<<"marks1:"<<marks1<<endl;
        cout<<"marks2:"<<marks2<<endl;
        cout<<"marks3:"<<marks3<<endl;

    }
    void per_grade(){
        
        total_grade= marks1+marks2+marks3;
        percentage= (total_grade/3);
        cout<<total_grade<<endl;
        cout<<percentage<<"%"<<endl;
    }



};

int main(){
    student s1;
    s1.accept();
    s1.display();
    s1.per_grade();



    return 0;
}