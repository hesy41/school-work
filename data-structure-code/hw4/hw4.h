/*  homework4_Binary_Search_Tree_exerscise: BST_ex.h
    author: Siyi He
    created 2020-11-1
*/

#include <iostream>
using namespace std;

#ifndef HW4_H
#define HW4_H

typedef int ItemType;
struct TreeNode;

class TreeType
{
    public:
        TreeType();
        ~TreeType();
        TreeType(const TreeType& originalTree);
        void MakeEmpty();
        bool IsEmpty() const;
        bool IsFull() const;
        int GetLength() const;
        ItemType GetItem(ItemType item, bool& found);
        void PutItem(ItemType item);
        void DeleteItem(ItemType item);
        void Print() const;

        /*check whether a binary tree is binary search tree
          return ture if it is a BST*/
        bool IsBST() const;

        /*print the ancestors of a given node
          the BST will not be changed*/
        void PrintAncestors(ItemType target) const;

        /*delete the smallest item in the BST
          precon: a binary search tree
          postcon: a binary seach tree that has been deleted the smallest item */
        void deleteSmallest();

        /*get items stored in the non-leaf nodes of the tree
          precon: a binary search tree
          postcon: an array stored with all nodes */
        ItemType* GetNodes() const;
        
        /*find the root of the violation
          return an array of the nodes found in violation*/
        ItemType* FindViolators() const;
        
    private:
        TreeNode* root;
};

#endif