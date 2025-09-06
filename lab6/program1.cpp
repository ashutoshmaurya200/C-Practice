#include<iostream>
using namespace std;

class emp{
    private:
    int id;
    string name;
    int deptid;
    public:
    double basicsalary;

    public:

    emp(int id, string name, int deptid, double basicsalary){
        this->id=id;
        this->name=name;
        this->deptid=deptid;
        this->basicsalary=basicsalary;

    }



    double compute_netsalary(){
        return 0;

    }

    void display(){

        cout<< "id:"<<id <<endl<<" name:"<<name<<endl<<"deptid:"<<endl<<deptid<<"basicsalary:"<<basicsalary;
    }

    



};

class manager: public emp{
    private:
    double perfbonus;

    public:
    manager(int id, string name, int deptid, double basicsalary, double perfbonus): emp(id,name,deptid,basicsalary)
    {
        this->perfbonus=perfbonus;

    }

    double compute_netsalary()
    {
        
        return basicsalary + perfbonus;

    }

    void display(){
        cout<< " this is manager\n";
        emp::display();
        cout<<"performance bonus"<<perfbonus;

    }


};

class worker:public emp{
    private:
    int hoursWorked;
    int hourlyrate;

    public:

    worker(int id, string name, int deptid, double basicsalary,int hourseWorked, int hourlyrate): emp(id,name,deptid,basicsalary){

        this->hourlyrate=hourlyrate;
        this->hoursWorked=hourseWorked;
    }

    double compute_netsalary(){
        return basicsalary+(hoursWorked*hourlyrate);
    }

    void setter( int newhourlyrate){
        this->hourlyrate=newhourlyrate;
    }

    void getter(){
        cout<<"new hourly rate are;"<<hourlyrate;
    }

    void display(){

        cout<< "this is worker class"<<endl;
        emp::display();
        cout<<"hourslyrate:"<<hourlyrate<<endl<<"hours worked:"<<hoursWorked;
    }




};

int main(){



     manager m1(101, "Raj", 10, 50000, 15000);
     worker w1(201, "Amit", 30, 20000, 50, 200);

   
     m1.compute_netsalary();
     m1.display();

    w1.compute_netsalary();
    w1.display();








    return 0;

   






}