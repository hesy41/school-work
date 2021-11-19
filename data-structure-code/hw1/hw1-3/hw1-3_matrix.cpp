/*homework1-problem3_matrix.cpp
  author: Siyi He
  create on 2021-9-17
*/
#include <iostream>
#include "hw1-3_matrix.h"
using namespace std;

matrixC::matrixC():row(2),column(2)
{
 Matrix = new int*[row];
 if (Matrix)
 {
  for(int i = 0; i < row; i++) 
  {
    Matrix[i] = new int[column];
    assert(Matrix[i]); 
  }
 }
  for (int i=0; i<row; i++) //initialing all element in matrix to be 0
  {
    for (int j=0; j<column;j++)
    {
      Matrix[i][j]=0;
    }
  } 
}
matrixC::matrixC(int r, int c):row(r),column(c)
{
  Matrix = new int*[row];
  if (Matrix)
  {
    for(int i = 0; i < row; i++) 
    {
      Matrix[i] = new int[column];
      assert(Matrix[i]); 
    }
  }

  for (int i=0; i<r; i++) //initialing all element in matrix to be 0
  {
    for (int j=0; j<c;j++)
    {
      Matrix[i][j]=0;
    }
  }
}

/*matrixC::~matrixC()
{
  //delete [] Matrix; //the first way of destructor: not standard

  for(int i = 0; i < row; i++)//second way of the destructor: standard for the 2d dynamic array
  {
    delete []Matrix[i];
  }
  delete [] Matrix; 
}*/

istream& operator>> (istream& input, matrixC&m)
{
  for (int i=0; i<m.row;i++)
  {
    cout << "enter the elements in row "<<i+1 << ": ";
    for (int j=0; j<m.column; j++)
    {
      input >> m.Matrix[i][j];
    }
  }
  return input;
}

ostream& operator<<(ostream& output, const matrixC& m)
{
  for (int i=0; i<m.row;i++)
  {
    for (int j=0; j<m.column; j++)
    {
      if(j==0)
      {
        output << "( ";
      }
      output << m.Matrix[i][j] << " ";

      if(j==m.column-1)
      {
        output << ")" <<endl;
      }
    }
  }
  return output;
}

/*function of matrices addition
  precondition: 2 matrices passing in
  postcondition: return failure message when the size dont match
                 return a matrice sum (matrixC) when the addition is possiable */
matrixC matrixC::add(const matrixC m)
{
  matrixC sum(m.row,m.column);
  if ((*this).column !=m.column || (*this).row != m.row)//check the size of two matrices
  {
    cout << "addition failure: two matrices have different size" << endl;
    exit(EXIT_FAILURE);
  }
  else
  {
    cout << "the sum of two matrices is:"<< endl;
    for (int i=0; i<m.row; i++)
    {
      for (int j=0; j<m.column;j++)
      {
        sum.Matrix[i][j]=(*this).Matrix[i][j] + m.Matrix[i][j];
      }
    }
  }

  return sum;
}

/*function of matrices multification
  precondition: 2 matrices passing in
  postcondition: return failure message when the size dont match multification requirements
                 return a matrice product (matrixC) when the multifiction is possiable */
matrixC matrixC::multiply(const matrixC m)
{
  int r=(*this).row;
  int c=m.column;
  matrixC product(r,c);
  
  if ((*this).column !=m.row)//check the size of two matrices
  {
    cout << "Multification failure: size does not match" << endl;
    exit(EXIT_FAILURE);
  }
  else
  {
    cout << "the product of two matrices is:" << endl; 
    for (int i=0; i<r; i++)
    {
      for (int j=0; j<c;j++)
      {
        for (int k=0; k<(*this).column;k++)
        {
          product.Matrix[i][j]+= (*this).Matrix[i][k] * m.Matrix[k][j];
        }
      }
    }
  }

  return product;
}