#include <iostream>
using namespace std;

// chunk definition
class Chunk {
public:
   int value
   Chunk *next;
   
   Chunk(){
      value = 0;
      next = NULL;
   }
};

// LL of chunks
class LinkedList {
public:
   Chunk *head;
   int length;
   
   LinkedList() {
      head = NULL;
      length = 0;
   }
   
   // Add something to the list
   void addAtPosition(int value, int position) {
      // check if position is valid
      if (position > 0 && position <= length + 1) {
         Chunk *temp = new Chunk;
         temp->value = value;
         
         if (position == 1) {
            temp->next = head;
            head = temp;
         }
         else if (position > 1 && position <= length) {
            Chunk *helper = head;
            // take helper to (position - 1)
            for (int i = 1; i < position - 1; i++){
               helper = helper->next;
               cout << "Helper at: " << helper->value << endl; // debug help
            }
            temp->next = helper->next;
            helper->next = temp;
         }
         else {
            Chunk *helper = head;
            while(helper->next != NULL)
               helper = helper->next;
            helper->next = temp;
         }
         length++; // IMPORTANT
      }
      else {
         cout << "Invalid position." << endl;
      }
   }
   
   // Remove something from the list
   void removeFromPosition(int position) {
      if (position > 0 && position <= length){
         if (position == 1 && length == 1){
            delete head;
            head = NULL;
         }
         else if (position == 1 && length > 1){
            Chunk *temp = head;
            head = temp->next;
            delete temp;
         }
         else {
            Chunk *temp, *helper;
            temp = helper = head;
            
            for (int i = 1; i <= position; i++){
               helper = temp;
               temp = temp->next;
            }
            helper->next = temp->next;
            delete temp;
         }
         length--;
      }
      else {
         cout << "Invalid position." << endl;
      }
   }
   
   // Display the list's contents
   void displayContents() {
      // the same as stack and queue
   }
   
};

int main() {
   LinkedList LL;
   int value = 100;
   int position = 3;
   
   LL.addAtPosition(value, position);
   LL.removeFromPosition(position);
}








