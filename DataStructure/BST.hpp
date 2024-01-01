#include <iostream> 
using namespace std; 

struct treeNode{
    int data; 
    treeNode *left; 
    treeNode *right; 

    treeNode(): data(0), left(nullptr), right(nullptr){}
    treeNode(int data): data(data), left(nullptr), right(nullptr){}

    static treeNode *search(treeNode *a, int data){
        if (a->data == data || a == nullptr){
            return a; 
        }
        if (data < a->data){
            return search(a->left, data); 
        }
        else{
            return search(a->right, data); 
        }
    }

    static void insert(treeNode * &a, int x){
        if (a == nullptr){
            a = new treeNode(x); 
        }
        else if (x < a->data){
            insert(a->left, x); 
        }
        else{
            insert(a->right, x); 
        }
    }

    static void traverse(treeNode *a){
        if (a != nullptr){
            traverse(a->left); 
            cout << a->data << " "; 
            traverse(a->right); 
        }
    }

    static treeNode* findMin(treeNode *a){
        if (a->left == nullptr){
            return a; 
        }
        else{
            return findMin(a->left); 
        }
    }

    static treeNode* findMax(treeNode *a){
        if (a->right == nullptr){
            return a; 
        }
        else{
            return findMax(a->right); 
        }
    }

    treeNode* deleteNode(treeNode* root, int key) {
        if (root == nullptr){
            return nullptr; 
        }

        if (key < root->data){
            root->left = deleteNode(root->left, key); 
            
        }
        else if (key > root->data){
            root->right = deleteNode(root->right, key); 
            
        }
        else{
            //if left node or right node is nullptr
            if (root->right == nullptr){
                treeNode *tmp = root->left; 
                delete root; 
                return tmp; 
            }
            else if (root->left == nullptr){
                treeNode *tmp = root->right; 
                delete root; 
                return tmp; 
            }
            //case when node to be deleted has left and right childrens. 
            else{
                treeNode *succ = root->right; 
                while (succ->left != nullptr){
                    succ = succ->left; 
                }
                root->data = succ->data;   
                root->right = deleteNode(root->right, root->data); 
            }
        }
        return root; 
    }
};

