/* 
 Creator: Siyi He
 last modified: 23 Mar Tue
 */ 
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;


string remove_punct(string str);
// Function: remove_punct
// Precondition: a string that may or may not have punctuation.
// Postcondition: returns a (possibly shorter) string with punctuaton
// removed.

string convert_lower(string str);
// Precondition: a string that may have mixed case in it.
// Postcondition: returns a lowercase string

void swap(char& c1, char& c2);
// Precondition: two characters that have to swapped.
// Postcondition: c1 is in c2 and c2 is in c1 when swapped.

string reverse(string str);
// Precondition: a string to be reversed
// Postcondition: returns a string that is the
// reverse of the input string.

void display(vector<string> vstrings);
// Precondition: a vector of strings to print. 
// Postcondition: Use a tab character for space. strings are printed one per line.

bool is_palindrome(string str);
// Precondition: a string to be tested
// Postcondition: returns a bool that is true if the input is a palindrome
// returns false otherwise.

int main() {

   //variables
   vector<string>palindrome;
   vector<string>not_palindroms;
   string inputStr;

   //use a loop to get input string and classify into the matched vector
   while (true)
   {
      //input the string
      cout << "Enter your palindrome or type quit: " << endl;
      getline(cin,inputStr);

      if (inputStr == "quit" || inputStr == "Quit")
         break;

      //check whehther the string is palindromes and classified into the matched vector
      if (is_palindrome(inputStr) == true)
      {
         palindrome.push_back(inputStr);
      }
      else 
      {
         not_palindroms.push_back(inputStr);
      }
   }

   //output
   cout << "Palindromes:" << endl; /*output the palindoromes list */
   display(palindrome);

   cout << "NOT Palindromes:" << endl;/*output the not palindoromes list */
   display(not_palindroms);

	return 0;
}

//function def

/* is_palindrome
goal: check whether a string is palindrome or not
precondition: a string
postcondition: the unchange string with a boolean value showing whether it is palindorme 
(true => the string is palundorme)
*/
bool is_palindrome(string str)
{
   string reversed_str;
   str = remove_punct(str);
   str = convert_lower(str);
   reversed_str = reverse(str);

   if (reversed_str == str)
      return true;
   else
      return false;
}

/* display
goal: to output the vetor containing string on the screen
precondition: a vector with string
postcondition: ouput the vector with each string in a seperate line
*/
void display(vector<string> vstrings)
{
   for (int i=0; i<vstrings.size(); i++)
   {
      cout << '\t' << vstrings[i] << endl;
   }
}

/*remove_punct
goal: to remove all the punctuation and space in the string and return the clean new string
precondidion: a string 
postconcotion: a string without punctuation and space
*/
string remove_punct(string str)
{
   string clean_str;

   // check whether the char is a lettler or number 
   for (int i=0; i<str.length(); i++)
   {
      if (isalnum(str[i])) // if the testing char is a number or letter, add it to the clean_str
      {
         clean_str += str[i];
      }
   }

   return clean_str;
}

/*convert_lower
goal: convert all the letter in the string into lower case
pre: a string that may contains captial case
post: a string without any captial letters 
*/
string convert_lower(string str)
{
   string lowerStr;

   //loop over the string and convert each letter
   for (int i=0; i<str.length(); i++)
   {
      lowerStr += tolower(str[i]); // convert all the char to lower
   }

   return lowerStr;
}

/* swap
goal: exchange the two value 
pre: two character that need to be swap
post: two character swapped
*/
void swap(char& c1, char& c2)
{
   char temp;
   temp = c1;
   c1 = c2;
   c2 = temp;
}

/* reverse
goal return a stirng that is the revsered version of the orginal string 
pre: a string to be reversed 
post: return a reversed string 
*/
string reverse(string str)
{
   string reversedStr;

   // loop from the last index of the original string and put to the reversedStr from the beginning
   for (int i=str.length()-1; i>=0; i--) 
   {
      reversedStr += str[i]; 
   }

   return reversedStr;
}