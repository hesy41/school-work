#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Count the number of spaces and punctuation characters in the input string.
// return the counts to the calling function
// @param : string input
// @param : To Do.
// @param : To Do.
// TODO: complete function header and body
void countSpacePunct(string input, int &space, int &punct)
{
  
    for (int i=0; i< input.length(); i++)
    {
      if (i == 0)
      {
        space = 0;
        punct = 0;
      }
      if (ispunct(input[i])==true)
        punct=punct+1;
      if (isspace(input[i])==true)
        space=space+1;
    }
    
    cout << space << " " << punct << endl;
     
    
}

int main()
{
  int spaceCnt, punctCnt;
  string quote;
  
  // To Do: read in the quote
  cout << "Enter a quote: ";
  getline(cin,quote);
  
  countSpacePunct (quote, spaceCnt, punctCnt);
  
  
  cout << "Number of spaces: " << spaceCnt << endl;
  cout << "Number of punctuation: " << punctCnt << endl;

  return 0;
}