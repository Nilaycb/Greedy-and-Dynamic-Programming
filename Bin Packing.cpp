#include<bits/stdc++.h>
using namespace std;

int firstFit(int arr[], int n, int c)
{
    int bins=0, i, bin_rem[n];

    for(i=0; i<n; i++)
    {
        int j;
        for(j=0; j<bins; j++)
        {
            if(bin_rem[j] >= arr[i])
            {
                bin_rem[j] -= arr[i];
                break;
            }
        }

        if(j == bins)
        {
            bin_rem[bins] = c - arr[i];
            bins++;
        }
    }

    return bins;
}

int firstFitDec(int arr[], int n, int c)
{
    sort(arr, arr+n, greater<int>());

    return firstFit(arr, n, c);
}

int main()
{
    int i, n, c;

    cout << "Enter the size of the Bin: ";
    cin >> n;

    int arr[n];

    cout << "Enter Bin weight: ";
    for(i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter Bin capacity: ";
    cin >> c;
    cout << endl;

    int low_bnd = firstFitDec(arr, n, c);

    cout << "We need minimum " << low_bnd << " bins to accommodate all items." << endl;

    return 0;
}
