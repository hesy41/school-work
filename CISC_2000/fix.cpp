#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Customer 
{
    public:
        // Constructor
        Customer ()
        {
            this->acct_number = this->getNextAcctNumber();
        }
        Customer(string name, string address) : cust_name(name), cust_address(address)
        {
           this->acct_number = this->getNextAcctNumber();;
        }

        // Accessor to get the account number
        long getAcctNumber() const
        {
            return acct_number;
        }

        //Accessor to get the customer name
        string getCustName() const 
        { 
            return cust_name; 
        }

        // Accessor to get the customer  address
        string getCustAddress() const 
        {
            return cust_address;
        }

        // Set a customer name and address
        void set(string name, string address);

        // Set a customer address
        void setAddress(string cust_address) {  cust_address = cust_address; }

        // Get the next account number for the next customer.
        static unsigned long getNextAcctNumber() { return ++nextAcctNum; }


        // input operator
        friend istream & operator >> (istream& ins, Customer&cust);

        // output operator
        friend ostream& operator << (ostream& outs, const Customer &cust);

    private:
      string cust_name;                           // customer name

      unsigned long acct_number;                  // account number

      string cust_address;                        // customer address

      static unsigned long nextAcctNum;
};

const int MAX_CUSTOMERS=20; // Change this to a smaller number to test.

// Declare the class variable nextAcctNum
unsigned long Customer::nextAcctNum=10000;

// set the customer name and address
// @param name: the customer name
// @param address: the account address
void Customer::set(string name, string address)
{
    this->cust_name=name;
    this->cust_address=address;
}

// input operator reads customer as a name and address on two separate lines.
// name
// address1
istream& operator>>(istream& ins, Customer& cust)
{
     getline(ins, cust.cust_name);
     getline(ins, cust.cust_address);
     return ins;
}

// output operator
ostream &operator << (ostream& out, const Customer& cust) 
{
     out << cust.acct_number << ": " << cust.cust_name << "\n" << cust.cust_address << endl;
     return out;
}

int main()
{
    Customer custList[MAX_CUSTOMERS];
    ifstream infile;
    string filename,input;

    cout << "Enter the name of the file for input: ";
    cin >> filename;

    infile.open(filename);
    if (infile.fail()) {
        cout << "Error: failed to open file: " << filename;
        exit(1);
    }

    // Read in customer list.
    int size = 0;
    while (infile >> custList[size]) {
        if (++size == MAX_CUSTOMERS)
            break;
    }

    // Get customer address changes
    for (int i = 0;  i < size; i++)
    {   
        char answer;
        cout << "Address change for " << custList[i].getAcctNumber() << "? (y or n) : ";
        cin >> answer;
        if (answer == 'y') {
            cin.ignore();  // newline
            getline(cin, input);
            custList[i].setAddress(input);
        }
    }

    // Write out customer list.
    for (int i = 0; i < size; i++)
    {
        cout << custList[i];
    }

    return 0;
}


