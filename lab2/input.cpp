// input and display the array
#include<iostream>
using namespace std;

int main(){
    int size;
    cout<<"enter the size of array";
    cin>>size;

    int *arr =new int(size);
    cout<<"enter the array"<<endl;
    // take the array element
    for(int i=0; i<5;i++){
        cin>>arr[i];
    }
    //display the array
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";;
    }
    return 0;
}