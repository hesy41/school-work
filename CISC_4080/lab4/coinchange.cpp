/*CISC_4080-lab4: coinchange.cpp
  author: Diana Rivas & Siyi He
  started on April 7, 2022
  bug found:
  */

//Compile using g++ -std=c++11
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void PrintVector (const vector<int> & v){
	cout <<"[";
	for (auto e:v){
		cout<<e<<" ";
	}
	cout <<"]";

}

/* check if we can use values in L[left...right] to make a sum of value, and find
the best solution, i.e., smallest set of coins tht make this value
 @param L, first, last: specify a sub-vector where coins/values are chosen from
 @param value: the sum/value we want to make
 @pre-condition: all parameters are initialized, L[] and value are non-negative
 @post-condition: return true/false depending on the checking result, if return true,
   used vector contains coins that make up the value, with the minimul # of elements from 
   L [first...last]
*/
bool CoinChange (vector<int> & L, int first, int last, int value, vector<int> & used)
{

    if (value==0)
    {
 	used.clear();
	return true;
    }

   if (first>last) //no more coins to use
   {
	used.clear();
	return false;
   }

   if (value<0)
   {
	used.clear();
	return false;
   }

   //general case below
   vector<int> used1;
   bool ret1= CoinChange (L, first, last-1, value-L[last], used1);
   if (ret1) 
        // used1 include all values from L[first...last-1] that add up to valeu-L[last]
        used1.push_back (L[last]);
        //now: used1 include all coins used from L[first...last} that add up to value

   vector<int> used2;
   // If not using L[last]... 
   bool ret2 = CoinChange (L, first, last-1, value, used2);

   if (ret1 && ret2) 
   {
	if (used1.size() > used2.size())
		used = used2;
	else
		used = used1;
        return true;
   } 
   else if (ret1) 
   {
	used = used1;
	return true;
   } 
   else if (ret2)
   {
	used = used2;
	return true;
   } 
   else 
   {
	used.clear();
	return false;
   }

} 

vector<vector<int>> subsets(const vector<int> & a, int first, int last)
{
	vector< vector<int> > ans;
	int n=a.size();
	//if the length of a[ﬁrst…last] is n
	//then the function should return a vector of 2^n vectors
	int ans_size=pow(2,n);
	for (int bit_string = 0; bit_string < ans_size ; bit_string ++)
	{
		vector<int> chosen;
		for (int j=0; j<n; j++)
		{
			if((bit_string &(1<<j))!=0)
				chosen.push_back(a[j]);
		}
		ans.push_back(chosen);
	}

	return ans;
}

bool CoinChangeK (const vector<int> & coins, int first, int last, int value, int K)
{
   return true;
}

bool UnlimitedCoinChange (const vector<int> & coins, int value, vector<int>& bestSolution)
{
   
   return true;
}

int main()
{
   vector<int> coins{2,5,3,10};
   vector<int> used;

   vector<int> values{4, 6,15, 18, 30, 41}; //use this to test
   
   //test subset
   vector< vector<int> > test_subset=subsets(values,0, values.size()-1);
   cout<< "hah";
   for(int i=0; i<test_subset.size(); i++)
	{
		PrintVector(test_subset[i]);
		cout<<endl;
	}

   //This part demo the CoinChange function: optimization problem
/*
   for (auto v: values) {
   //Todo: replace CoinChange with your CoinChangeUnlimited function... 
   	if (CoinChange (coins, 0, coins.size()-1, v, used))
   	{
		cout <<"value="<<v <<" True\n";
		//display used vector
        	for (int i=0;i<used.size();i++)
			cout <<used[i]<<" ";
        	cout<<endl;
   	}
   	else 
		cout <<"Value=" << v<<" False"<<endl;
   }
*/

   //Test CoinChangeK
  cout <<"Enter coinchangek or unlimited to test the corresponding function:";
  string command;

  cin >> command;

  if (command=="coinchangek"){  
  	//we cannot make 20 using 2 or fewer coins
  	if (CoinChangeK (coins, 0, coins.size()-1, 20, 2)!=false || 
      		CoinChangeK (coins, 0, coins.size()-1, 5, 1)!=true)
  	{
		cout <<"fail coinchangek tests\n";
       		return 1; //faild coinchangeK test 
  	}
	else{
		cout <<"pass coinchangek tests\n";
		return 0; //pass coinchangeK test
	}
  } else if (command=="unlimited"){
   	//Test UnlimitedCoinChange 
	vector<int> bestSolution;

   	if (UnlimitedCoinChange (coins, 1,bestSolution)!=false) {
      		cout <<"Failed UnlimitedCoinChange case 1\n";
		return 1; //failed unlimited test 
	}

   	if (UnlimitedCoinChange (coins, 15, bestSolution)!=true) {
		cout <<"Failed UnlimitedCoinChange case 2\n";
		return 1;
	}
	vector<int> expectedSol{5,10}; 
        sort (bestSolution.begin(), bestSolution.end());
	if (bestSolution!=expectedSol){
		cout <<"Failed UnlimitedCoinChange case 2\n";
		return 1;

	}


   	if (UnlimitedCoinChange (coins, 30, bestSolution)!=true) {
		cout <<"Failed UnlimitedCoinChange case 3\n";
		return 1;
	}
	vector<int> expectedSol3{10,10,10}; 
        sort (bestSolution.begin(), bestSolution.end());
	if (bestSolution!=expectedSol3){
		cout <<"Failed UnlimitedCoinChange case 3\n";
		return 1;

	}

        cout <<"Pass unlimitedCoinChange cases\n";
        return 0;
  }

}
