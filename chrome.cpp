#include <iostream>
using namespace std;

class ChromeTab {
public:
   // attributes
   int length, width;
   ChromeTab *next;
   
   // constructor
   ChromeTab() {
      length = 100;
      width = 50;
      next = NULL;
   }
   
   // functions: let's not use them yet
};

int main() {
   // first tab
   ChromeTab *first;
   first = new ChromeTab;
   first->length = 200;
   first->width = 100;
   
   // =========================================================
   // ADDING TABS
   // =========================================================
   
   // second tab
   first->next = new ChromeTab;
   first->next->length = 400;
   first->next->width = 400;
   
   // third tab
   first->next->next = new ChromeTab;
   first->next->next->length = 1000;
   first->next->next->width = 300;
   
   // let's add a new chunk, such that this is now the first tab.
   ChromeTab *another;
   another = new ChromeTab;
   
   // let's get this new (another) tab to point to current first tab
   another->next = first;
   first = another;
   
   // let's add something in the MIDDLE
   another = new ChromeTab;
   another->next = first->next->next;
   first->next->next = another;
   
   // =========================================================
   // REMOVING TABS
   // =========================================================
 
   // delete <pointer>; DELETES THE WHOLE CHUNK, not just the pointer
   
   // delete the last tab
   delete first->next->next->next->next; // pointer still remains, so set to null
   first->next->next->next->next = NULL;
   
   // delete 3rd box
   another = first->next->next;
   first->next->next = first->next->next->next;
   delete another;
   
   // =========================================================
   // let's loop through the structure and print;
   // =========================================================
   
   another = first;
   while (another != NULL){
      cout << "--------" << endl;
      cout << "Length: " << another->length << endl;
      cout << "Width: " << another->width << endl;
      another = another->next;      
   }
   
     
}
