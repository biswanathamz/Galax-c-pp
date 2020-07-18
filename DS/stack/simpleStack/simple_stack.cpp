#include <iostream>
using namespace std;

class Stack {
    private:
        int maxLength,top;
        int* stackPtr;
    public:
        Stack(){
            cout<<"Please enter the max length of this stack : ";
            cin>>this->maxLength;
            this->stackPtr = (int*) malloc(this->maxLength*sizeof(int));
            this->top = -1;
        }
        int is_empty(){
            return (this->top == -1) ? 1:0;
        }
        int is_full(){
            return (this->top == this->maxLength-1) ? 1:0;
        }
        void push(){
            int input_var; 
            if(!this->is_full()){
                cout<<"Enter your input in integer : ";
                cin>>input_var;
                this->top++;
                *(this->stackPtr+this->top)=input_var;
                cout<<input_var<<" is pushed in this stack"<<endl;
            }
            else{
                cout<<"Stack is full"<<endl;
            }
        }
        void pop(){
            if(!this->is_empty()){
                cout<<"Poped element is : "<<*(this->stackPtr+this->top)<<endl;
                this->top--;
            }
            else{
                cout<<"Stack is Empty"<<endl;
            }
        }
};

int main(){
    int input_var,loop_var=0;
    Stack stackobj;
    while(loop_var==0){
        cout<<"Enter 1 for push or 2 for pop and others for exit :";
        cin>>input_var;
        switch(input_var){
            case 1:
                stackobj.push();
                break;
            case 2:
                stackobj.pop();
                break;
            default:
                loop_var=1;
        }
    }
    return 0;
}