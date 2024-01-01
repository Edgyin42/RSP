#include "BST.hpp"


int main(){

    treeNode *root = new treeNode(1); 
    treeNode::insert(root, 2);
    treeNode::insert(root, 5);
    treeNode::insert(root, 6);
    treeNode::insert(root, 9);
    treeNode::insert(root, 3);
    treeNode::insert(root, 7);
    treeNode::insert(root, 8);
    treeNode::traverse(root);
}