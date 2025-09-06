// second largest element of the array 

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
// function of maximum array 
int second_maximum(int arr[] ,int n){
    int max=INT16_MIN;
    int smax=INT16_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max= arr[i];
        }
    }
    for(int i=0;i<n;i++){
        if (arr[i]>smax&& arr[i]!=max){
            smax=arr[i];
        }

    }
    return smax;
}



int main(){
    int size;
    cout<<"enter the size "<<endl;
    cin>>size;

    int *arr =new int(size);
    cout<<"enter the array elements"<<endl;
    takearray(arr,size);
    cout<<second_maximum (arr,size);
    

    return 0;
    

}