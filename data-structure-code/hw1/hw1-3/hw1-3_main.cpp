/*homework1-problem3_main.cpp
  author: Siyi He
  create on 2021-9-17
  bug existing: "pointer being freed was not allocated"
  bug existing: the destructor should use the loop and delete twice but it doesn't work
                I simply delete the base function and it could run the right outcome.
*/
#include <iostream>
#include "hw1-3_matrix.h"
#include "hw1-3_matrix.cpp"
using namespace std;

int main(){
  int row1, column1, row2, column2;

  cout << "Enter the number of rows for your first matrix: ";
  cin  >> row1;
  cout << "Enter the number of columns for your first matrix: ";
  cin  >> column1;
  matrixC matrix1(row1,column1);//create the first matrix 
  cin >> matrix1;//read in the matrix

  cout << "Enter the number of rows for your second matrix: ";
  cin  >> row2;
  cout << "Enter the number of columns for your second  matrix: ";
  cin  >> column2;
  matrixC matrix2(row2,column2);//create the second matrix
  cin  >> matrix2; //read in the matrix

  cout << matrix2.add(matrix1) << endl; //do matrix addition 
  cout << matrix1.multiply(matrix2) << endl;//do matrix multification 
  
  return 0;
}