//

#include<iostream>
using namespace std;

class person{
    private:
    string name;
    int age;
    string city;
    // default constructor
    public:
    person(){
        cout<<"----default constructor intialized"<<endl;

        name= "webnam";
        age=20;
        city = "mumbai";
    
    }
    // display th info

    void display(){
        cout<< name<<endl;
        cout<<age<<endl;
        cout<<city<<endl;
    }
    // parameterized constructor
    person( string name,int age, string city){
        this->name=name;
        this->age=age;
        this->city=city;


    }
    void setter(string newname){

        
        this->name=newname;
        cout<<"setter id invoked"<<endl;
    }
    void getter(){
        cout<<"the new name:"<<name;
        
    }

};



int main(){
    person p2;
    p2.display();
    person p1("raghav",30,"pbh");
    
    p1.display();

    p1.setter("sita");
    p1.getter();

   

    return 0;

}