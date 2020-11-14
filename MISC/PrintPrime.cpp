#include <iostream>
using namespace std;

bool checkprime(int value){
    int i;
    if(value == 0 || value == 1){
        return false;
    }
    else{
        for(i=2;i<value;i++){
            if(value%i == 0){
                return false;
            }
        }
        return true;
    }
    return true;
}

void printPrime(int limit){
    int currentVal = 0;
    while(currentVal<=limit){
        if(checkprime(currentVal)){
            cout<<currentVal<<endl;
        }
        currentVal ++;
    }
}

int main(){
    int limit;
    cout<<"Please enter the limit of printing prime numbers : ";
    cin>>limit;
    cout<<endl;
    cout<<"Below numbers are Prime : "<<endl;
    printPrime(limit);
    return 0;
}