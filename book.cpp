// Class Requirements:
// 1. Base class: Book

// Data Members:

// int book_id → unique identifier for book

// string title → book title

// string author → author name

// double price → book price

// Functions:

// Constructor to initialize values

// virtual void display() → display book details

// virtual ~Book() → virtual destructor

// 2. Derived class: EBook (inherits from Book)

// Data Members:

// double file_size_MB → size of file in MB

// string format → file format (e.g., PDF, EPUB)

// Functions:

// Constructor to initialize all values

// Override display() to show eBook details

// void applyDiscount() → reduce price by 10% if file_size_MB > 50

// 3. Derived class: PrintedBook (inherits from Book)

// Data Members:

// int page_count → number of pages

// string cover_type → Hardbound / Paperback

// Functions:

// Constructor to initialize all values

// Override display() to show PrintedBook details

// void shippingCharge() →

// Add ₹50 if cover_type == "Paperback"

// Add ₹100 if cover_type == "Hardbound"

// 4. Custom Exception Class: BookNotFoundException

// Definition:

// A class derived from exception.

// Override const char* what() const noexcept to return "Book not found!".

// Main Function (main())

// Use vector<Book*> library; to store multiple books (EBook/PrintedBook).

// Provide a menu-driven interface:

// Add an EBook

// Add a PrintedBook

// Display all Books (apply discount/shipping charge where needed)

// Search a Book by Title → If not found, throw BookNotFoundException.

// Exit

// Use dynamic_cast for runtime polymorphism when applying applyDiscount() or shippingCharge().


#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<typeinfo>
#include<exception>
using namespace std;


class myException :public exception{
    public:
     const char * message;
     myException(const char * msg):message(msg){};
     const char* what() const noexcept override{
        return message;
     }

    

};

class Book{
    // int book_id → unique identifier for book

// string title → book title

// string author → author name

// double price → book price
    
 protected:
 int book_id;
 string title;
 string author;
 double price;


 // Constructor to initialize values

// virtual void display() → display book details

// virtual ~Book() → virtual destructor

public:

Book(int book_id, string title, string author,double price){
    if(price<=0){
        throw myException("invalid price");
    }
    this->book_id=book_id;
    this->title=title;
    this->author=author;
    this->price=price;

}

virtual void display(){
    cout<<" the book id is:\n"<<book_id<<endl;
    cout<<" the title of book is :\n"<<title<<endl;
    cout<<" the author is :\n"<<author<<endl;
    cout<<" the price is:\n"<<price<<endl;
}

double getPrice(){
    return price;
}
virtual ~ Book(){}


 
   

};
//2. Derived class: EBook (inherits from Book)

// Data Members:

// double file_size_MB → size of file in MB

// string format → file format (e.g., PDF, EPUB)

// Functions:

// Constructor to initialize all values

// Override display() to show eBook details

// void applyDiscount() → reduce price by 10% if file_size_MB > 50

class Ebook :public Book{
    protected:
    double file_size;
    string format;

    public:

    Ebook(int book_id, string title, string author,double price,double file_size,string format):Book(book_id,title,author,price){
       
        if(file_size<=0){
            throw myException("invalid file_size");
        }
        
        this->file_size=file_size;
        this->format=format;

    }

    void display() override{
         Book::display();
        cout<<"the file size is : "<<file_size<<endl;
        cout<<"the file format is "<<format<<endl;
    }

    void applyDiscount(){
       
      if(file_size>50){
            cout<<"the discounted price is:";
            price=price-price*(0.9);
            cout<<price;
        }
    }
    
};

//3. Derived class: PrintedBook (inherits from Book)

// Data Members:

// int page_count → number of pages

// string cover_type → Hardbound / Paperback

// Functions:

// Constructor to initialize all values

// Override display() to show PrintedBook details

// void shippingCharge() →

// Add ₹50 if cover_type == "Paperback"

// Add ₹100 if cover_type == "Hardbound"


class PrintedBook:public Book{
    protected:
    int page_count;
    string cover_type;

    public :
    PrintedBook(int book_id, string title, string author,double price,int page_count,string cover_type):Book(book_id,title,author,price){
        this->page_count=page_count;
        this->cover_type=cover_type;
    }

    void display()override{
        cout<<"the no pages : "<<page_count<<endl;
        cout<<"cover type: "<<cover_type;
    }
    void shippingCharge(){
        cout<<"the shipping charges are:"<<endl;
        if(cover_type=="paperback"){
           price=price+50;
           cout<<price;

        }
        else if(cover_type=="hardcover"){
         price=price+100;
         cout<<price;
        }
    }


};
 




// Main Function (main())

// Use vector<Book*> library; to store multiple books (EBook/PrintedBook).

// Provide a menu-driven interface:

// Add an EBook

// Add a PrintedBook

// Display all Books (apply discount/shipping charge where needed)

// Search a Book by Title → If not found, throw BookNotFoundException.

// Exit


int main(){
    vector<Book*> book;
    int choice;

    bool exit=false;
    while(!exit){
        
        cout<<"enter the option->"<<endl;
        cout<<"1. Add an E-Book:"<<endl;
        cout<<"2. Add a PrintedBook "<<endl;
        cout<<"3. display all books"<<endl;
        cin>>choice;
        try{
        switch (choice)
        {
            case 1:{
                int book_id;
                string title;
                string author;
                double price;
                double file_size;
                string format;

                cout<<"enter the book id:"<<endl;
                cin>>book_id;
                cin.ignore();
                cout<<"enter the title of book:"<<endl;
                getline(cin,title);
                cout<<"enter the author of book :"<<endl;
                getline(cin,author);
                cout<<"enter the price of book:"<<endl;
                cin>>price;
                cout<<"enter the file size in mb:"<<endl;
                cin>>file_size;
                cin.ignore();
                cout<<"enter the format of file:"<<endl;
                getline(cin,format);

                book.push_back(new Ebook(book_id,title,author,price,file_size,format));

                  break;
               
            }
          
             case 2:{
                int book_id;
                string title;
                string author;
                double price;
                int page_count;
                string cover_type;

                cout<<"enter the book id:"<<endl;
                cin>>book_id;
                cin.ignore();
                cout<<"enter the title of book:"<<endl;
                getline(cin,title);
                cout<<"enter the author of book :"<<endl;
                getline(cin,author);
                cout<<"enter the price of book:"<<endl;
                cin>>price;
                cout<<"enter the no of pages:"<<endl;
                cin>>page_count;
                cin.ignore();
                cout<<"enter the type of cover:"<<endl;
                getline(cin,cover_type);

                book.push_back(new PrintedBook(book_id,title,author,price,page_count,cover_type));
              break; 
            }
             
             case 3:{
                for(auto B : book){

                    if(Ebook * Eb = dynamic_cast<Ebook*>(B)){
                        Eb ->display();
                        Eb ->applyDiscount();

                    }
                    else if (PrintedBook * pb =dynamic_cast<PrintedBook*>(B)){
                         pb->display();
                         pb->shippingCharge();
                    }
                   
                    
                }

               

                   break;
               
            }
          
             case 4:{
                exit=true;
                break;
            }
        }
    }catch(myException mx){
        cout<< "the exception caught :"<<mx.what()<<endl;

    }
        
    }

}
