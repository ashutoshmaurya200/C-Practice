// frequency of arrya elements 

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

int frequency(int arr[],int n){
    int count=0;
    for(int i=0;i<n;i++){
        

        }
    }

  






int main(){
    int size;
    cout<<"enter the size "<<endl;
    cin>>size;

    int *arr =new int(size);
    cout<<"enter the array elements"<<endl;
    takearray(arr,size);
    frequency(arr,size);
    
    

    return 0;
    

}