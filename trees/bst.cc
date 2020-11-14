#include <iostream>
using namespace std;

class TreeChunk {
public:
   int data;
   TreeChunk *left, *right;
   
   TreeChunk () {
      data = 0;
      left = right = NULL;
   }
};

class BST {
public:
   TreeChunk *root;
   
   BST () {
      root = NULL;
   }

   void add(int x){
      if (root == NULL){
         root = new TreeChunk;
         root->data = x;
         cout << "Added: " << x << endl;
         return;
      }
      
      TreeChunk *slow, *fast;
      slow = fast = root;
      
      while (fast != NULL){
         if (x < fast->data){
            slow = fast;
            fast = fast->left;
         }
         else if (x > fast->data) {
            slow = fast;
            fast = fast->right;
         }
         else {
            cout << "No duplicates allowed." << endl;
            return;
         }
      }
      if (x < slow->data){
         slow->left = new TreeChunk;
         slow->left->data = x;
      }
      else {
         slow->right = new TreeChunk;
         slow->right->data = x;
      }
      cout << "Added: " << x << endl;
   }
   
   bool search(int key, TreeChunk *start){
      //base case
      if (root == NULL){
         cout << "Empty tree." << endl;
         return false;
      }
      if (start == NULL) {
         cout << "Could not find value: " << key << endl;
         return false;
      }
      else{
         if (key == start->data) {
            cout << "Success: " << key << " in the tree." << endl;
            return true;
         }
         if (key < start->data)
            search(key, start->left);
         else
            search (key, start->right);
      }
   }
   
   void preorder(TreeChunk *start) {
      //base case
      if (start == NULL)
         return;
      else {
         //root, left, right
         cout << start->data << " ";
         preorder(start->left);
         preorder(start->right);
      }
   }
   
   void postorder(TreeChunk *start) {
      //base case
      if (start == NULL)
         return;
      else {
         //left, right, root
         postorder(start->left);
         postorder(start->right);
         cout << start->data << " ";
      }
   }
   
   void inorder(TreeChunk *start) {
      //base case
      if (root == NULL){
         cout << "Empty tree" << endl;
      }
      if (start == NULL)
         return;
      else {
         //left, root, right
         inorder(start->left);
         cout << start->data << " ";
         inorder(start->right);
      }
   }
   
   void deleteNode(int key){
      if (root == NULL){
         cout << "Empty tree, nothing to delete." << endl;
         return;
      }
      
      // Search and find node
      TreeChunk *slow, *fast;
      slow = fast = root;
      
      // Check for existence
      while (fast != NULL && fast->data != key){
         if (key < fast->data){
            slow = fast;
            fast = fast->left;
         }
         else{
            slow = fast;
            fast = fast->right;
         }
      }
      if (fast == NULL){
         cout << key << " does not exist in this tree." << endl;
         return;
      }
      
      // Classify into cases and delete
      if (fast->right == NULL && fast->left == NULL){
         cout << key <<": Case 1" << endl;
         if (root->data == key){
            cout << "Deleting: " << root->data << endl;
            root = NULL;
            delete root;
         }
         else if (slow->right == fast){
            slow->right = NULL;
            cout << "Deleting: " << fast->data << endl;
            delete fast;
         }
         else {
            slow->left = NULL;
            cout << "Deleting: " << fast->data << endl;
            delete fast;
         }
      }
      else if ((fast->right == NULL && fast->left != NULL) || (fast->right != NULL && fast->left == NULL)){
         cout << key << ": Case 2" << endl;

         if (fast->left != NULL){
            if (root->data == key){
               root = root->left;
               cout << "Deleting: " << slow->data << endl;
               delete slow;
            }
            else if (slow->left == fast){
               slow->left = fast->left;
               cout << "Deleting: " << fast->data << endl;
               delete fast;
            }
            else if (slow->right == fast){
               slow->right = fast->left;
               cout << "Deleting: " << fast->data << endl;
               delete fast;
            }
         }
         if (fast->right != NULL) {
            if (root->data == key){
               root = root->right;
               cout << "Deleting: " << slow->data << endl;
               delete slow;
            }
            else if (slow->left == fast){
               slow->left = fast->right;
               cout << "Deleting: " << fast->data << endl;
               delete fast;
            }
            else if (slow->right == fast){
               slow->right = fast->right;
               cout << "Deleting: " << fast->data << endl;
               delete fast;
            }
         }
      }
      else{
         cout << key << ": Case 3" << endl;
         slow = fast;
         fast = fast->right;
         
         while(fast->left != NULL)
            fast = fast->left;
         
         int val = fast->data;
         deleteNode(val);
         slow->data = val;
      }
   }
};

int main() {
   BST tree;
   int choice, num, search;
   
   while(1){
      cout << "Press 1 to add" << endl;
      cout << "Press 2 to delete" << endl;
      cout << "Press 3 to search" << endl;
      cout << "Press 4 to display" << endl;
      cout << "Press any key to quit" << endl;
      cin >> choice;
      
      switch (choice){
         case 1:  cout << "What number do you want to add? ";
                  cin >> num;
                  cout << endl;
                  tree.add(num);
                  cout << "Tree (in order): ";
                  tree.inorder(tree.root);
                  cout << "\n" << endl;
                  break;
         case 2:  cout << "What number do you want to delete? ";
                  cin >> num;
                  cout << endl;
                  tree.deleteNode(num);
                  cout << "Tree (in order): ";
                  tree.inorder(tree.root);
                  cout << "\n" << endl;
                  break;
         case 3:  cout << "What number do you want to search for? ";
                  cin >> num;
                  cout << endl;
                  tree.search(num, tree.root);
                  cout << "\n" << endl;
                  break;
         case 4:  cout << "What kind of display? (1: preorder, 2: postorder, 3: inorder): ";
                  cin >> search;
                  switch(search){
                     case 1:  tree.preorder(tree.root);  break;
                     case 2:  tree.postorder(tree.root); break;
                     case 3:  tree.inorder(tree.root);   break;
                  }
                  cout << "\n" << endl;
                  break;
         default: cout << "Goodbye" << endl;
                  cout << "\n" << endl;
                  return 0;
      }
      cout << "==========================================" << endl;
   }
}
