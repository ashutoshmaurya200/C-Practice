// sum and average of array
#include<iostream>
using namespace std;

int main(){
    int size ;
    cout<<"enter the size of array";
    cin>>size;
    int *arr= new int(size);
    int sum=0;

    for(int i=0;i<size;i++){
        cin>>arr[i];
    }

    //sum of array

    for(int i=0;i<size;i++){
        sum =sum+arr[i];
    }
    cout<<"the sum of the array:"<<sum<<endl;

    // avaerage of the array 

    int average = sum/size;
    cout<<"the average of array:"<<average<<endl;
    return 0;
}