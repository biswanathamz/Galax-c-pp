// """Code is contributed by Kaustav Ghosh (https://github.com/kaustavcs) """
#include <iostream>
#include <stdio.h>
#include<stdlib.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};

struct Node *insertEmpty(struct Node *last, int data)
{
    if(last!=NULL)
    return last;
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    last=temp;
    last->next=last;
    return last;
}

struct Node *insertBegin(struct Node *last, int data)
{
    if (last == NULL){
        return insertEmpty(last,data);
    }
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=last->next;
    last->next=temp;
    return last;
}

struct Node *insertEnd(struct Node *last, int data){
    if(last==NULL){
        return insertEmpty(last,data);
    }
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->next=last->next;
    last->next=temp;
    last=temp;
    return last;
}

struct Node *insertAfter(struct Node *last, int data, int item){
    if(last==NULL){
        return NULL;
    }
    struct Node *temp, *p;
    p=last->next;
    do
    {
        if(p->data==item){
            temp=(struct Node *)malloc(sizeof(struct Node));
            temp->data=data;
            temp->next=p->next;
            p->next=temp;
            if(p==last){
                last =temp;
            }
                return last;
        }
            p=p->next;
        
    } while (p!=last->next);
    cout<<item<<" is not found in the list"<<endl;
    return last;
    
}
struct Node *deleteElement(struct Node *last, int data){
    if(last==NULL){
        return NULL;
    }
       int pos = 0;
    struct Node *current, *prev;
   if(last->data == data) {
      if(last->next != last) {
         current = last;
         while(current->next!=last) {
            current = current->next;
         }
         
         current->next = last->next;
         last = last->next;
         return last;
      } else {
         last = NULL;
         
         return last;
      }
   
   } else if(last->data != data && last->next == NULL) {
      cout<<"Not Found"<<endl;
      return last;
   }

   current = last;

   while(current->next != last && current->data != data) {
      prev = current;
      current = current->next;
   }        

   if(current->data == data) {
      prev->next = prev->next->next;
   } else
      cout<<"Not Found"<<endl;  

return last;
}

void displayLL(struct Node *last){
    struct Node *temp;
    if(last==NULL){
        cout<<"Empty List"<<endl;
        return;
    }
    temp=last->next;
    do
    {
        cout<<temp->data<<",";
        temp=temp->next;
    } while (temp!=last->next);
    cout<<endl;
    
}

int main() 
{ 
	int input,valinput,loopBreak=0,valoc;
    struct Node *last = NULL;
    while(1){
        cout<<"Menu : (Enter accordingly)"<<endl;
        cout<<"Enter 1 to add a node at the end of the linked list"<<endl;
        cout<<"Enter 2 to add a node at the beginning of the linked list"<<endl;
        cout<<"Enter 3 to add a node at the after an element of the linked list"<<endl;
        cout<<"Enter 4 to delete a element by value of the Linked List"<<endl;
        cout<<"Enter 9 to display linked list"<<endl;
        cin>>input;
        switch(input){
            case 1:
                cout<<"Enter the integer value to add in the list : ";
                cin>>valinput;
                last=insertEnd(last,valinput);
                break;
            case 2:
                cout<<"Enter the integer value to add in the list : ";
                cin>>valinput;
                last=insertBegin(last,valinput);
                break;
            case 3:
                cout<<"Enter the integer value to add in the list : ";
                cin>>valinput;
                cout<<"Enter the value after which it will insert: ";
                cin>>valoc;
                last=insertAfter(last,valinput,valoc);
                break;
            case 4:
                cout<<"Enter the value of element to delete in the list : ";
                cin>>valinput;
                last=deleteElement(last,valinput);
                break;
            case 9:
                displayLL(last);
                break;
            default:
                loopBreak = 1;
        }
        if(loopBreak){
            break;
        }
    }
    return 0;
} 
