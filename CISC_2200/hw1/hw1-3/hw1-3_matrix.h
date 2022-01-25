/*homework1-problem3_matrix.h
  author: Siyi He
  create on 2021-9-17
*/
#include<iostream>
using namespace std;

#ifndef MATRIXC_H
#define MATRIXC_H

class matrixC
{
    public:
    matrixC();
    matrixC(int row, int column);//constrtuctor
    //~matrixC();//destructor 
    friend istream& operator>>(istream&input, matrixC&m);//read in function 
    friend ostream& operator<<(ostream& output, const matrixC& m);//display()
    matrixC add(const matrixC m);//matrices addition 
    matrixC multiply(const matrixC m);//matrices multification 

    private:
    int row;
    int column;
    int** Matrix;
};

#endif