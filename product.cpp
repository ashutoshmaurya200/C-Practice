// Problem Statement – Online Store Management

// Design a menu-driven C++ program to manage products in an online store. The system should support PhysicalProduct and DigitalProduct, and include custom exceptions for invalid inputs.

// Classes Required
// 1️⃣ Base Class: Product

// Data Members

// int product_id → unique ID

// string name

// double price

// Functions

// Constructor

// virtual void display() → display product details

// Virtual destructor



#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<exception>
using namespace std;

class myException :public exception{
    public:
    const char* message;
    myException(const char * msg):message(msg){};
    const char* what() const noexcept override{
        return message;
    }

};


class Product{
  protected:
    int prod_id;
    string name;
    double price;

    public:
    Product(int prod_id, string name, double price){

          if(price<=0){
            throw myException("invalid price");
        }
        this->prod_id=prod_id;

        this->name=name;
         this->price=price;
      
       
    }

    virtual void display(){
        cout<< "the product id is : "<<prod_id<<endl<<"the name of product is : "<<name<<endl<<"the price of product is : "<<price<<endl;
    }

    int getId(){
        return prod_id;

    }

    virtual ~ Product(){};
};

// 2️⃣ Derived Class: DigitalProduct

// Data Members

// double file_size_mb

// string format → e.g., PDF, MP3, MP4

// Functions

// Constructor

// Override display()

// void applyDiscount() → if file_size_mb > 500 MB, reduce price by 15%



class DigiProduct : public Product{
    protected:
    double file_size;
    string format;

    public:
    DigiProduct(int prod_id, string name, double price,double file_size,string format):Product(prod_id,name,price){
         if(file_size<=0){
            throw myException("invalid file_size");
        }
        this->file_size=file_size;
        this->format=format;
       
    }
    void display() override{
       Product ::display();
       cout<<"the file size in mb is :"<<file_size<<endl<<"the format of file is :"<<format<<endl ;
    }
    void applyDiscount(){
        if(file_size>500){
            price=price*(0.85);
            cout<<"the discounted price is"<<price<<endl;
        }
        else{
            cout<<"the discount is not applicable "<<endl;
        }
    }
};



// 3️⃣ Derived Class: PhysicalProduct

// Data Members

// double weight_kg

// string shipping_type → Standard / Express

// Functions

// Constructor

// Override display()

// void applyShippingCharge() →

// Standard → add 50 to price

// Express → add 100 to price


class PhysicalProduct :public Product{
    protected:
    double weight ;
    string shipping_type;
    public:

    PhysicalProduct(int prod_id, string name, double price,double weigth,string shipping_type):Product(prod_id,name,price){
         if(weight<=0){
            throw myException("invalid weight");
        }
        this->weight=weight;
        this->shipping_type=shipping_type;
       
    }

    void display() override{
        Product::display();
        cout<<"the weight of product is :"<<weight<<endl<<"the shipping_type is :"<<shipping_type<<endl;
    }

    void applyShippingCharge(){
        if(shipping_type=="standard"){
            price =price+50;
            cout<<"the shipping price is"<<price;

        }
        else if(shipping_type=="express"){
            price=price +100;
            cout<<"the shipping price"<<price;
        }
    }
};





// Custom Exception Class: StoreException

// Inherits from std::exception

// Constructor accepts a message

// Override what() to return the message

// Throw exceptions for:

// Price ≤ 0

// File size ≤ 0 for digital products

// Weight ≤ 0 for physical products

// Program Requirements

// Maintain a vector<Product*> to store all products.

// Menu options:

// Add Digital Product

// Add Physical Product

// Display all products

// Exit

// When displaying products:

// Use dynamic_cast to identify type

// Apply discounts or shipping charges accordingly

// Input must be validated (avoid infinite loops on invalid input)

// All exceptions must be caught and displayed with custom messages

// Extra Challenge

// Automatically assign product_id instead of asking from user

// Allow names with spaces using getline

// Display final price after applying discount/shipping

int main(){
    vector<Product*> prod;

    bool exit=false;
    int choice;
    while(!exit){
        cout<<"choose the options :"<<endl;
        cout<<"1.Add Digital Product :"<<endl;
        cout<<"2. Add Physical Product:"<<endl;
        cout<<" 3. display the product:"<<endl;
        cout<<"4.search the product by product id : "<<endl;
        cout<<"5.exit"<<endl;

        cin>>choice;
        try{
        switch(choice){
            case 1:{
                int prod_id;
                 string name;
                  double price;
                  double file_size;
                  string format;

                  cout<<"enter the product id: ";
                  cin>>prod_id;
                  cout<<"enter the name of product; ";
                    cin.ignore();
                    getline(cin,name);
                    cout<<"enter the price: ";
                    cin>>price;
                    cout<<"the file size in mb: ";
                    cin>>file_size;
                    cout<<"the file format: ";
                    cin.ignore();
                    getline(cin,format);

                    prod.push_back(new DigiProduct( prod_id,  name,  price, file_size, format));


            }
            break;
             case 2:{
                int prod_id;
                 string name;
                  double price;
                  double weight;
                  string shipping_type;

                  cout<<"enter the product id : ";
                  cin>>prod_id;
                  cout<<"enter the name of product: ";
                    cin.ignore();
                    getline(cin,name);
                    cout<<"enter the price: ";
                    cin>>price;
                    cout<<"the product weight in kg: ";
                    cin>>weight;
                    cout<<"the shipping type standard or express: ";
                    cin.ignore();
                    getline(cin,shipping_type);

                    prod.push_back(new DigiProduct( prod_id,  name,  price, weight, shipping_type));


            }
            break;
             case 3:{
                        for(auto p:prod){
                            if(DigiProduct* Dp =dynamic_cast<DigiProduct*>(p) ){
                                Dp->display();
                                Dp->applyDiscount();
                            }
                            else if(PhysicalProduct * Pd =dynamic_cast<PhysicalProduct*>(p)){
                                Pd->display();
                                Pd->applyShippingCharge();
                            }
                        }

                       


            }
            break;
             case 4:{
                int id;
                cout<<"enter the id of the product you want to know:"<<endl;
                cin>>id;
                for(auto p:prod){
                    if(p->getId()==id){
                        p->display();
                    }
                    else{
                        cout<<"not found!";
                    }

                }
            }
            break;
             case 5:{
                exit=true;

            }
            break;
        }
    }catch(myException mx){
        cout<<"the exception cought:"<<mx.what();

    }

    }
}