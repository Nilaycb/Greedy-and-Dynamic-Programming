#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, j, l, max_indx;
    vector<int> LDS;

    cout << "Enter the length of Series: ";
    cin >> n;

    int arr[n];

    cout << "Enter values of the Series: ";
    for(i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    cout << endl;

    int len[n], prev[n];
    fill_n(len, n, 1);
    fill_n(prev, n, -1);

    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(arr[i] > arr[j]) // for LIS change this condition to arr[i] < arr[j]
            {
                prev[j] = (len[i]+1 >= len[j]) ? i : prev[j];
                len[j] = max(len[j], len[i]+1);
            }
        }
    }

    l = *max_element(len, len+n);
    max_indx = distance(len, max_element(len, len+n));

    int v = max_indx;
    for(i=0; i<l; i++)
    {
        LDS.push_back(arr[v]);
        v = prev[v];
    }

    reverse(LDS.begin(), LDS.end());

    cout << "Length of LDS = " << l << endl;
    cout << "The LDS is ";
    for(i=0; i<LDS.size(); i++)
    {
        cout << LDS[i];

        if(i != LDS.size()-1)
            cout << ", ";
        else
            cout << endl;
    }

    return 0;
}
