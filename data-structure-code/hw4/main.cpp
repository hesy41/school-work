/*  homework4_Binary_Search_Tree_exerscise: main-hw4.cpp
    author: Siyi He
    created 2020-11-8
*/

#include <iostream>
#include "hw4.h"
#include "hw4.cpp"
using namespace std;

int main(){

    TreeType tree;
    int* nodes;
    int* violators;
    tree.PutItem(8);
    tree.PutItem(5);
    tree.PutItem(23);
    tree.PutItem(2);
    tree.PutItem(6);

    cout << "the original tree is: " << endl;
    tree.Print();
    cout<<endl;

    //test IsBST
    /* if (tree.IsBST())
        cout << "It is BST! " << endl;
    else
        cout << "It is not BST! " << endl;
    cout << endl; */

    //test PrintAncestors
    cout << "the the ancestors of node 6 is: " <<endl;
    tree.PrintAncestors(6);
    cout<<endl;


    //test GetNodes
    cout << "the list of (non-leaf) nodes of the tree is: " <<endl;
    nodes = tree.GetNodes();
    for (int i=0; i<tree.GetLength()/2; i++)
    {
        cout << nodes[i] << " ";
    }
    cout << endl;

    //test deleteSmallest
    cout << "The tree after we deleted the smallest element is: " << endl;
    tree.deleteSmallest();
    tree.Print();
    cout<< endl;

    //test find Violators
    //there will not be violators with the right putItem
    /* cout << "the list of violators of the tree is: " <<endl;
    violators = tree.FindViolators();
    for (int i=0; i<tree.GetLength()/2; i++)
    {
        cout << violators[i] << " ";
    } */

    return 0;
}