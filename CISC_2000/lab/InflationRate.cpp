//This program calculates the inflation rate given two Consumer Price Index values and prints it to the monitor.

#include <iostream>
using namespace std;

//golbal varible 
const int MAX_RATES = 20;

//phototype 
double InflationRate(float old_cpi, float new_cpi);
void getCPIValues (float& old_cpi, float& new_cpi);
void sort_array (double rates[], int counter);
void swap_values (double& start, double& mini);
double findMedianRate (double rates[], int counter);

int main()   //C++ programs start by executing the function main
{
   float old_cpi, new_cpi;
   double rate, rate_total, rate_ave, inflationRates[MAX_RATES],MedianRate;
   int counter = 0;
   char answer;

   do
   {
      getCPIValues (old_cpi, new_cpi); 
    
      //calculate inflation rate
      rate = InflationRate(old_cpi, new_cpi);
      cout << "Inflation rate is " << rate << endl;

      //store in array
      inflationRates[counter] = rate;

      //running check
      cout << "Try again? (y or Y): ";
      cin  >> answer;

      //total rate
      rate_total = rate_total + rate;
      if (rate != 0)
         counter = counter + 1;

      // make sure the program does not overflow the array
      if (counter == MAX_RATES) 
      {
         answer = 'n';
      } 

   } while (answer == 'y' || answer == 'Y');

   //average cal
   rate_ave = rate_total / counter;
   cout << "Average rate is " << rate_ave << endl;

   //array sorting
   sort_array(inflationRates,counter);

   //find Median Rate
   MedianRate = findMedianRate (inflationRates, counter);
   cout << "Median rate is " << MedianRate << endl;

   return 0;
}

//function def
void getCPIValues (float& old_cpi, float& new_cpi)
{
   bool vaild;
  do
  {
      vaild = true;
      cout << "Enter the old and new consumer price indices: ";
      cin  >> old_cpi >> new_cpi; 

      if (old_cpi <= 0 || new_cpi <= 0)
      {
         cout << "Error: CPI values must be greater than 0" << endl;
         vaild = false ;
      }
  }while (vaild == false);
}

//function def
double InflationRate(float old_cpi, float new_cpi)
{
   double r;

   if (old_cpi <= 0.0 || new_cpi <= 0.0)
   {
      return 0;
   }
   else 
   {
      r = (new_cpi - old_cpi) / old_cpi * 100;
      return r;
   }
}

//function def
void sort_array (double rates[], int counter)
{
   int miniIndex=0, start, i,r, size = counter;

   for (start = 0; start<size ; start++)
   {
      //find the smallest
      for (i=start; i < size; i++ )
      {
         miniIndex = start;
         for (r=start+1; r< size; r++ )
         {
            if (rates[r] < rates[miniIndex])
            {
               miniIndex = r;
            }
         }
      }
      //replace the smallest one with the starter
      swap_values (rates[start], rates [miniIndex]);
   }

   //debug: print the sorted array
   //for (i= 0; i<size; i++)
   //{
   //   cout << rates[i] <<endl;
   //}
   
}

//function def
void swap_values (double& start, double& mini)
{
   double temp;

   temp = start;
   start = mini;
   mini = temp;
}

//function def
double findMedianRate (double rates[], int counter)
{
   double medianRate;
   int median,median_even;

   if (counter == 20)
   {
      counter = counter -2;
   }  

   if (counter == 2)
   {
      medianRate = (rates[0]+ rates[1]) / 2;
   }
   else if (counter % 2 == 0) //when the number of rates is even
   {
      median = counter/2;
      median_even = median + 1;
      medianRate = (rates[median] + rates[median_even])/2;
   }
   else  //the number of rates is odd
   {
      median = counter/2;
      medianRate = rates[median];
   }

   return medianRate;
}