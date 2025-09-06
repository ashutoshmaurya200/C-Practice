#include<iostream>
using namespace std;

class Book{
    private:
    string bname;
    int id;
    string author;
    float price;
    // default constructor
    public:
    Book(){
        cout<<"----default constructor intialized"<<endl;

        bname= "ikigai";
        id=101;
        author="japanese";
        price=45.50;
    
    }
    // display th info

    void display(){
        cout<< bname<<endl;
        cout<<id<<endl;
        cout<<author<<endl;
        cout<<price<<endl;
    }
    // parameterized constructor
    Book( string bname,int id, string author,float price){
        this->bname=bname;
        this->id=id;
        this->author=author;
        this-> price=price;


    }
    void setter(float newprice,string changeauthor){

        
        this->price=newprice;
        this->author=changeauthor;
        cout<<"setter id invoked"<<endl;
    }
    void getter(){
        cout<<"the new price:"<<price<<endl;
        cout<<"the new author:"<<author<<endl;
        
    }

};



int main(){
    Book p2;
    p2.display();
    Book p1("the splendid suns",102,"khan",40.34);
    
    p1.display();

    p1.setter(78.98,"americans");
    p1.getter();

   

    return 0;

}