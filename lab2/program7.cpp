// bubble sort 
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

//bubble sort ascending order

void bubble_sort(int arr[],int n){
for(int i=0;i<n;i++){
    if(arr[i]>arr[i+1]){
        swap(arr[i],arr[i+1]);
    }
}
 for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}
int main(){
    int size;
    cout<<"enter the size "<<endl;
    cin>>size;

    int *arr =new int(size);
    cout<<"enter the array elements"<<endl;
    takearray(arr,size);
    
    cout<<"after the sorting ";
    bubble_sort (arr,size);

        return 0;
    

}