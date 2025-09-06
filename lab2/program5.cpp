// reverse array and display the result

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

// function to reverse the array 
void reverse_Array(int arr[],int n){
   int start=0;
   int end=n-1;
   while(start<end){
    swap(arr[start],arr[end]);
    start++;
    end--;
   }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}


int main(){
    int size;
    cout<<"enter the size";
    cin>>size;

    int*arr =new int(size);
    cout<<"enter the array"<<endl;

    takearray(arr,size);
    reverse_Array(arr,size);
    



}