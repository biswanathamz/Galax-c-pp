#include<iostream>
using namespace std;
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp; 
}

void bubble(int *ptr, int n){
    int i,j;
    for (i=0;i<n-1;i++)
        for(j=0;j<n-i-1;j++)
            if(*(ptr+j)>*(ptr+j+1))
                swap((ptr+j),(ptr+j+1));
}

void print(int *ptr, int n){
    int i =0;
    for (i=0;i<n;i++)
        cout<<*(ptr+i)<<" ";
}

int main(){
    int i,noOfElement;
    int* ptr;
    cout<<"Please enter length of the array"<<endl;
    cin>>noOfElement;
    ptr = (int*) malloc(noOfElement*sizeof(int));
    for (i=0;i<noOfElement;i++){
        cout<<"Enter "<<i<<" element:";
        cin>>*(ptr+i);
    }
    bubble(ptr,noOfElement);
    print(ptr,noOfElement);
}