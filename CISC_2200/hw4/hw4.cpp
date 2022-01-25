/*  homework4_Binary_Search_Tree_exerscise: BST_ex.cpp
    author: Siyi He
    created 2020-11-1
    issue: I have tried to put countNode in the member function, but there is an error says "TreeType::countNode" 
           type does not match, why?? solved
*/

#include <iostream>
#include <fstream>
#include "hw4.h"
using namespace std;

void copyTree(TreeNode*&, const TreeNode*);
void killTree(TreeNode*& node);
int countNode(TreeNode* root);
void retrieve(TreeNode* root, ItemType& item, bool& found);
void PrintTree(TreeNode* tree);
void insert(TreeNode*& tree, ItemType item);
void deletetion(TreeNode*& tree, ItemType item);
void deleteNode(TreeNode*& tree);
void GetPredecessor(TreeNode* tree, ItemType& data);

struct TreeNode
{
    ItemType info;
    TreeNode* left;
    TreeNode* right;
};

TreeType::TreeType()
{
    root = new TreeNode;
    root = NULL;
}

TreeType::TreeType(const TreeType& originalTree)
{
    copyTree(root, originalTree.root);
}

void copyTree(TreeNode*& copyRoot, const TreeNode* originalRoot)
{
    if (originalRoot==NULL)
        copyRoot = NULL;
    else{
        copyRoot = new TreeNode;
        copyRoot->info = originalRoot->info;
        copyTree(copyRoot->left, originalRoot->left);
        copyTree(copyRoot->right, originalRoot->right);
    }
}

TreeType::~TreeType()
{
    killTree(root);
}

void killTree(TreeNode*& root)
{
    if (root != NULL)
    {
        killTree(root->left);
        killTree(root->right);
        delete root;
    }
}

bool TreeType::IsEmpty() const 
{
    return (root == NULL);
}

bool TreeType::IsFull() const 
{
    TreeNode* node;
    //test if there is more room on the free stone
    //if there is, then this tree is not full
    try 
    {
        node = new TreeNode;
        delete node;
        return false;
    }
    catch (std::bad_alloc exception)
    {
        //if there is no room, then system automatically throw bad_alloc message
        return true;
    }
}

int TreeType::GetLength() const 
{
    return countNode(root);
}

int countNode(TreeNode* tree)
{
    if (tree != NULL)
        return countNode(tree->right)+countNode(tree->left)+1;
    else
        return 0;
}

ItemType TreeType::GetItem(ItemType item, bool& found)
{
    retrieve(root, item, found);
    return item;
}

void retrieve(TreeNode* tree, ItemType& item, bool& found)
{
    if (tree==NULL)
        found=false;
    else
    {
        if(item < tree->info) // item is in the left part of the tree
            retrieve(tree->left, item, found);
        else if (item > tree->info) // item is in the left part of the tree
            retrieve(tree->right, item, found);
        else // item is found
            found =true;
    }
}

void TreeType::Print() const
{
  PrintTree(root);
}

void PrintTree(TreeNode* tree)
{
  if (tree != NULL)
  {
    PrintTree(tree->left);  
    cout << tree->info;
    cout << " ";
    PrintTree(tree->right); 
  }
}

/*problem 5*/
void storeNode(ItemType* array, int& count, TreeNode* root);

ItemType* TreeType::GetNodes() const
{
    ItemType* array;
    array = new ItemType[GetLength()/2];
    int count = 0;

    storeNode(array, count, root);
    return array;
}

void storeNode(ItemType* array, int& count, TreeNode* root)
{
    if (root->left !=NULL || root->right != NULL)
    {
        array[count]=root->info;
        count++;
        storeNode(array, count, root->left);
        storeNode(array, count, root->right);
    }
}


/* problem 4: DeleteSmallest */
void deleteSmallestHypo(TreeNode*& root);

void TreeType::deleteSmallest()
{
    deleteSmallestHypo(root);
}

void deleteSmallestHypo(TreeNode*& root)
{
    //the smallest item must be the leaf on the very left
    
    if (root->left != NULL)
    {
        deleteSmallestHypo(root->left);
    }
    else 
        deletetion(root, root->info); //use DeleteItem to delete
}

/*problem 3*/
void printAncestorsHypo(TreeNode *root, ItemType target);

void TreeType::PrintAncestors(ItemType target) const 
{
    //bool IsPrint;
    printAncestorsHypo(root, target);
}
void printAncestorsHypo(TreeNode *root, ItemType target)
{
    if (root == NULL)
        return;//no tartget can be found in a empty tree
    
    if (target < root->info)
    {
        cout<< root->info << " ";
        printAncestorsHypo(root->left, target);
    }
    else if (target > root->info)
    {
        //TreeNode* temp = root;
        printAncestorsHypo(root->right, target);
        cout << root->info << " ";
    }
    else
    {
        cout << root->info << " ";
    }
}

/*problem 2*/
bool isBSTUtil(TreeNode* node); 

bool TreeType::IsBST() const
{ 
    return isBSTUtil(root); 
} 
bool isBSTUtil(TreeNode* node)
{ 
    if (node==NULL) 
        return true; 
            
    if ((node->right)->info < node->info || (node->left)->info > node->info) 
        return false; 

    return isBSTUtil(node->left) && isBSTUtil(node->right);
}

/*bonus*/
void storeViolators(ItemType* array, int& count, TreeNode* root);

ItemType* TreeType::FindViolators() const
{
    int count = 0;
    ItemType* array;
    array = new ItemType[GetLength()/2]; //violators are parents of the bad nodes --> non-leaf nodes --> no more than length/2

    storeViolators(array, count, root);
    return array;
}

void storeViolators(ItemType* array, int& count, TreeNode* root)
{
    if (root == NULL)
        return;

    if ((root->right)->info < root->info || (root->left)->info > root->info)
    {
        array[count]=root->info;
        count ++;
        storeNode(array, count, root->left);
        storeNode(array, count, root->right);
    }
}

/*else*/
void TreeType::MakeEmpty()
{
    killTree(root);
    root = NULL;
}

void TreeType::PutItem(ItemType item)
{
    insert(root, item);
}

void insert(TreeNode*& tree, ItemType item)
{
    if (tree == NULL)
    {
        tree = new TreeNode;
        tree->info = item;
        tree->left = NULL;
        tree->right = NULL;
    }
    else if (tree->info > item) // if item is smaller than the node, we turn to the left subtree
        insert(tree->left, item);
    else
        insert(tree->right, item);
}

void TreeType::DeleteItem(ItemType item)
{
    deletetion(root, item);
}

void deletetion(TreeNode*& tree, ItemType item)
{
    if (item < tree->info)
        deletetion(tree->left, item);   
    else if (item > tree->info)
        deletetion(tree->right, item);  
    else
        deleteNode(tree);  
}

void deleteNode(TreeNode*& tree)
{
    ItemType data;
    TreeNode* tempPtr;

    tempPtr = tree;
    if (tree->left == NULL)
    {
        tree = tree->right;
        delete tempPtr;
    }
    else if (tree->right == NULL)
    {
        tree = tree->left;
        delete tempPtr;
    }
    else
    {
        GetPredecessor(tree->left, data);
        tree->info = data;
        deletetion(tree->left, data);
    }
}

void GetPredecessor(TreeNode* tree, ItemType& data)
{
  while (tree->right != NULL)
    tree = tree->right;
  data = tree->info;
} 

