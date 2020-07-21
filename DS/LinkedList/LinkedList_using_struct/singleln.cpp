#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
};
void insert_node_at_begin(struct node **head, int data){
    struct node *newNode;
    newNode = (struct node *) malloc(sizeof(struct node));
    newNode->data = data;
    if(*head == NULL){
        newNode->next = NULL;
        *head = newNode;
    }
    else{
        newNode->next = *head;
        *head = newNode;
    }
    cout<<data<<" is added into list, Position : at Beginning"<<endl;
}
void insert_node_at_end(struct node **head,int data){
    struct node *temp;
    struct node *newNode;
    newNode = (struct node*) malloc(sizeof(struct node));
    newNode->next = NULL;
    newNode->data = data;
    if(*head==NULL){
        *head = newNode;
    }
    else{
        temp = *head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout<<data<<" is added into list, Position : at END"<<endl;
}
void displayLL(struct node *head){
    struct node *temp;
    if(head == NULL){
        cout<<"Linked List is empty"<<endl;
    } 
    else{
        cout<< "Printing elements of linked list : ";
        temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
    cout<<endl;
}
int main(){
    int input,valinput,loopBreak=0;
    struct node *head;
    while(1){
        cout<<"Menu : (Enter accordingly)"<<endl;
        cout<<"Enter 1 to add a node at the end of the linked list"<<endl;
        cout<<"Enter 2 to add a node at the beginning of the linked list"<<endl;
        cout<<"Enter 5 to display linked list"<<endl;
        cin>>input;
        switch(input){
            case 1:
                cout<<"Enter the integer value to add in the list : ";
                cin>>valinput;
                insert_node_at_end(&head,valinput);
                break;
            case 2:
                cout<<"Enter the integer value to add in the list : ";
                cin>>valinput;
                insert_node_at_begin(&head,valinput);
                break;
            case 5:
                displayLL(head);
                break;
            default:
                loopBreak = 1;
        }
        if(loopBreak){
            break;
        }
    }
    return 1;
}