#include <iostream>
#include <stdlib.h>
using namespace std;

class Chunk{
public:
   int value;
   Chunk *next;
   
   Chunk() {
      value = 0;
      next = NULL;      
   }
};

// Stack of "Chunks"
class Stack {
public:
   Chunk *top;
   
   Stack(){
      top = NULL;
   }
   
   // add element
   void push(int x) {
      Chunk *another;
      another = new Chunk;
      another->value = x;
      
      if (top == NULL){
         top = another;
      }
      else {
         another->next = top;
         top = another;
      }
   }
   
   // remove element
   void pop() {
      if (top == NULL){
         cout << "Empty stack, nothing to delete." << endl;
         return;
      }
      else {
         Chunk *another;
         another = top;
         top = top -> next;
         
         cout << "About to delete: " << another->value << endl;
         delete another;
      }
   }
   
   // display elements
   void display() {
      if (top == NULL){
         cout << "Empty Stack: nothing to display" << endl;
         return;
      }
      else {
         Chunk *another;
         another = top;
         while (another != NULL){
            cout << another->value << " -> ";
            another = another->next;
         }
         cout << "NULL" << endl;
      }
   }
};

int main(){

   Stack myStack;
   int choice, value;
   
   // we add 5, 6, 3, 9, 10
   myStack.push(5);
   myStack.push(6);
   myStack.push(3);
   myStack.push(9);
   myStack.push(10);
   
   myStack.display();

   while (1) {
      cout << "Press 1 to add" << endl;
      cout << "Press 2 to pop" << endl;
      cout << "Press 3 to display" << endl;
      cout << "Press anything else to quit" << endl;
      cin >> choice;
      
      switch (choice) {
         case 1:
            cout << "Add what?" << endl;
            cin >> value;
            myStack.push(value);
            break;
            
         case 2:
            myStack.pop();
            break;
            
         case 3:
            cout << "--------------------" << endl;
            myStack.display();
            cout << "--------------------" << endl;
            break;
         
         default:
            cout << "Goodbye" << endl;
            exit(1);
      }
   }
}








