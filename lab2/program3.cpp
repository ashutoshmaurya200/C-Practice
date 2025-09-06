#include<iostream>
using namespace std;

int maximum(int arr[] ,int n){
    int max=INT16_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max= arr[i];
        }
    }
    return max;
}
int minimum(int arr[],int n){
    int min=INT16_MAX;
    for(int i=0;i<n;i++){
        if (arr[i]<min)
        min=arr[i];
    }
    return min;
}



int main(){
    int size;
    cout<<"enter the size";
    cin>>size;

    int *arr=new int(size);
    // taking array
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"the minimum of array:"<<minimum(arr, size)<<" "<<"the maximum of array"<<maximum(arr ,size)<<endl;
    return 0;
}