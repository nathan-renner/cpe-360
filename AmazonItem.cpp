#include <iostream>
using namespace std;

class AmazonItemsForSale {
public:
   // 1. What is the physical look and feel of items of this type?
   // ("attributes")
   float price;
   int sellerId;
   
   // 2. When we create a new object, what does it look like?
   // constructor: special function that "initializes" attributes to a default.
   AmazonItemsForSale() {
      price = 0.0;
      sellerId = 100;
   }
   
   // 3. What functions are allowed for items of this type?
   void addThisItemToCart() {
      // implement this function
      cout << "Adding this to the cart..." << endl;
   }
};

int main() {
   
   AmazonItemsForSale item1;
   
   cout << "Price of item1: " << item1.price << endl;
   item1.price = 38.50;
   item1.sellerId = 900;
   item1.addThisItemToCart();
   cout << "Price now: " << item1.price << ", sellerId: " << item1.sellerId << endl;
   
   // ===============================================================================
   // Creating variables that have NO NAMES
   // These kinds of variables reside in the "Heap": a special zone in the memory
   // ===============================================================================
   
   // First, create a pointer
   // <pointer> = new <type>;
   AmazonItemsForSale *customer;
   
   // Get a new item from the heap
   // customer = new AmazonItemForSale;
   customer = new AmazonItemsForSale; //nameless, just an address

   // Arrow opperator substitues the dot opperator for pointers.
   customer->price = 38.50;
   customer->sellerId = 900;
   
   // Another Example
   AmazonItemsForSale *another;
   another = new AmazonItemsForSale;
   another->price = 100;
   another->sellerId = 123;
   
   cout << "First box in the heap: " << endl;
   cout << customer->price << ", " << customer->sellerId << endl;
   cout << "Second box in the heap: " << endl;
   cout << another->price << ", " << another->sellerId << endl;   
   
   // Ground a pointer
   customer = NULL;
}
