// linear search of element 

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
void linerSearch(int arr[],int n,int ele){
   
    for(int i=0;i<n;i++){
        if(arr[i]==ele){
            cout<<"yes";
            break;
        }

        }
    }
    


int main(){
    int size;
    cout<<"enter the size of array";
    cin>>size;
    int *arr= new int(size);
    cout<<"give the array"<<endl;
    takearray(arr, size);
    display(arr , size);

    int element;
    cout<<"enter the element to be search"<<endl;
    cin>>element;

   linerSearch(arr,size ,element);

}