#include <iostream>
using namespace std;

class Queue {
    private:
        int front, rear, size;
        int* queueptr;
    public:
     Queue(){
        cout<<"Please enter the max length of this stack : ";
        cin>>this->size;
        this->queueptr = (int*) malloc(this->size*sizeof(int));
        this->front = -1;
        this->rear = -1;
    }
    bool is_full(){
        if(this->front > (this->size-1)){
           return true;
        }
        return false;
    }
    bool is_empty(){
        if(this->front == -1 && this->rear == -1){
            return true;
        } 
        return false;
    }
    void enqueue(){
        int element;
        cout<<"Please enter element(int) to add in the queue : ";
        cin>>element;
        if (this->is_full()){
            cout<<"Queue is full !";
        }
        else if(this->is_empty()){
            this->front = 0;
            this->rear = 0;
        }
        else{
            this->front++;
        }
        *(this->queueptr+this->front) = element;
    }

    void dequeue(){
        int element;
        cout<<"Please enter element(int) to add in the queue : ";
        cin>>element;
        if()   
    }
};

int main(){
    int input_var,loop_var=0;
    Queue queueobj;
    while(loop_var==0){
        cout<<"Enter 1 for add or 2 for get and others for exit :";
        cin>>input_var;
        switch(input_var){
            case 1:
                queueobj.enqueue();
                break;
            case 2:
                break;
            default:
                loop_var=1;
        }
    }
    return 0;
}