void ratingIput (string iss[], int totl[], int size)
{
    int i, rate;
    cout << "Please rank the following issues on their importance to you, where 1 is least important and 10 is most important:" << endl;

    for (i=0; i<size; i++)
    {
        cout << iss[i] << ": ";
        cin  >> rate;

        totl[i] = totl[i] + rate;
    }
}