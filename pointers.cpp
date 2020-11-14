#include <iostream>
using namespace std;
#define MAX 10;   // this is a MACRO, not a variable. Max just gets replaced with 10 at runtime.
                  // essentially they are just labels for numbers.
                  // they don't get their own place in memory as a variable would.

int main () {
   int var = 10;
   int another = 5;
   int *pal;
    
   // pal is a pointer
   // pal can ONLY store addresses, and never literal values
    
   // referencing a pointer ******************
   pal = &var; // now pal knows the address of var
   
   // dereferencing a pointer *******************
   // var = var + 20;  OR
   *pal = *pal + 20; // pal goes to the position of var and changes the value of var to 20
   cout << "Value of var after pal paid a visit: " << var << endl;
   
   
   // =====================================================================================
   
   // now lets get pal to grab the address of another (pal will forget about var)
   
   pal = &another;
   *pal = 500;
   cout << "Another is now: " << another << endl;
}
