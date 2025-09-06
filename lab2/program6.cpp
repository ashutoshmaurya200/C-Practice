// count even and odd numbers in an array 
#include<iostream>
using namespace std;


void takearray(int arr[] ,int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
// even and odd

void even(int arr[],int n){
   cout<<"the even numbers are:";
    for(int i=0;i<n;i++){
     if (arr[i]%2==0){
        cout<<arr[i]<<endl;
     }
   }
   
}

void odd(int arr[],int n){
    cout<<"the odd numbers are:";
    
    for(int i=0;i<n;i++){
    
     if (arr[i]%2!=0){
        cout<<arr[i]<<endl;
     }
}
}


int main(){
    int size;
    cout<<"enter the size "<<endl;
    cin>>size;

    int *arr =new int(size);
    cout<<"enter the array elements"<<endl;
    takearray(arr,size);
    display(arr, size);
    // even number display
    even(arr,size);
    odd(arr,size);
    return 0;
    

}