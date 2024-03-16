// binarytrees_dhirenmahajan_extracredit.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Dhiren Mahajan
//M14536148


#include <iostream>

using namespace std;



class Node {
public:
   int key;
   Node* left;
   Node* right;

   Node(int nodeKey) {
      key = nodeKey;
      left = nullptr;
      right = nullptr;
   }
};

class BinarySearchTree {
private:
   Node* root;

public:
    BinarySearchTree() {
        root = nullptr;
    }


    void Insert(int item) {
   // Check if tree is empty
        Node* newNode=new Node(item);
       if (root == nullptr) {
          root = newNode;
       }
       else {
          Node* currentNode = root;
          while (currentNode) {
             if (newNode->key < currentNode->key) {
                // If no left child exists, add the new node
                // here; otherwise repeat from the left child.
                if (currentNode->left == nullptr) {
                   currentNode->left = newNode;
                   currentNode = nullptr;
                }
                else {
                   currentNode = currentNode->left;
                }
             }
             else {
                // If no right child exists, add the new node
                // here; otherwise repeat from the right child.
                if (currentNode->right == nullptr) {
                   currentNode->right = newNode;
                   currentNode = nullptr;
                }
                else {
                   currentNode = currentNode->right;
                }
             }
          }
       }
    }

    Node* Find(int item){
        Node* currNode=root;
        while (currNode!=NULL){
            if (currNode->key==item){
                return currNode;
            }
            else if(currNode->key<item){
                currNode=currNode->right;
            }
            else{
                currNode=currNode->left;
            }
        }
        return NULL;
   }

   void Remove(int key) {
   Node* aar = NULL;
   Node* current = root;
   while (current!=NULL) { // Search for node
      if (current->key == key) { // Node found
         if (current->left==NULL && current->right==NULL) { // Remove leaf
            if (aar==NULL) // Node is root
               root = NULL;
            else if (aar->left ==current){
               aar->left = NULL;
            }
            else
               aar->right = NULL;
         }
         else if (current->right==NULL) {                // Remove node with only left child
            if (aar==NULL) // Node is root
               root = current->left;
            else if (aar->left == current)
               aar->left = current->left;
            else
               aar->right = current->left;
         }
         else if (current->left  ==NULL) {                // Remove node with only right child
            if (aar==NULL) // Node is root
               root = current->right;
            else if (aar->left == current)
               aar->left = current->right;
            else
               aar->right = current->right;
         }
         else {                                      // Remove node with two children
            // Find successor (leftmost child of right subtree)
            Node* suc;
            suc = current->right;
            while (suc->left!=NULL)
               suc = suc->left;
            Node* successorData = suc;
            Remove(suc->key);     // Remove successor
            current=successorData;
         }
         return; // Node found and removed
        }
      else if (current->key < key) { // Search right
         aar = current;
         current = current->right;
      }
      else {                     // Search left
         aar = current;
         current = current->left;
      }
   }
   return; // Node not found
}

    void GetAllDescending(struct Node *root) {
      if (root != NULL) {
        // Traverse left
        GetAllDescending(root->right);
        // Traverse root
        cout << root->key << endl;
        // Traverse right
        GetAllDescending(root->left);
      }
    }

    void GetAllAscending(struct Node *root) {
      if (root != NULL) {
        // Traverse left
        GetAllAscending(root->left);
        // Traverse root
        cout << root->key << endl;
        // Traverse right
        GetAllAscending(root->right);
      }
    }

    Node* getRoot(){
        return root;
    }

    void Emptytree(Node *node)
    {
        if (node == NULL) return;

        /* first delete both subtrees */
        Emptytree(node->left);
        Emptytree(node->right);

        /* then delete the node */
        cout << "Deleting node: " << node->key<<endl;
        delete node;

    }

    int Size(Node* node)
    {
    if (node == NULL)
        return 0;
    else
        return(Size(node->left) + 1 + Size(node->right));
    }




};

int main()
{
    BinarySearchTree a;
    while (true){
        int choice;
        cout << " Tree Menu" << endl;
        cout << "--------------------------------" << endl;
        cout << "Enter 1: Insert an element" << endl;
        cout << "Enter 2: Delete an element" << endl;
        cout << "Enter 3: Search an element" << endl;
        cout << "Enter 4: Display" << endl;
        cout << "Enter 5: Get size of tree" << endl;
        cout << "Enter 6: Delete tree" << endl<< endl;
   
        cin>>choice;
        cout<<endl;
        if (choice==1){
            int item;
            cout<<"Enter the element you want to add: ";
            cin>>item;
            a.Insert(item);
        }
        else if(choice==2){
            int item1;
            cout<<"Enter the element you want to delete: ";
            cin>>item1;
            a.Remove(item1);
        }
        else if(choice==3){
            int item2;
            cout<<"Enter the element you want to search: ";
            cin>>item2;
            a.Find(item2);
        }
        else if(choice==4){
            int item3;
            cout<<"Enter 1 to display items in ascending or 2 to display items in desceding: ";
            cin>>item3;
            cout<<endl;
            if (item3==1){
                Node* root=a.getRoot();
                a.GetAllAscending(root);
                cout<<endl<<endl;
            }
            else{
                Node* root=a.getRoot();
                a.GetAllDescending(root);
                cout<<endl<<endl;
            }
        }
        else if(choice==5){
            Node* root=a.getRoot();
            int Size=a.Size(root);
            cout<<"Size is: "<<Size<<endl<<endl;
        }
        else{
            Node* root=a.getRoot();
            a.Emptytree(root);
        }
        int x;
        cout<<"\n\nEnter 1 to Continue \nEnter 2 to Exit: ";
        cin>>x;
        cout<<endl<<endl;
        if (x==1){
            continue;
        }
        else{
            break;
        }
    }
    return 0;
}
