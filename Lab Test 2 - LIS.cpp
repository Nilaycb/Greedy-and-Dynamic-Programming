#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, j, v;

    cout << "Enter Input length: ";
    cin >> n;

    int arr[n];

    cout << "Input = ";
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
            if(arr[i] < arr[j])
            {
                prev[j] = (len[i]+1 >= len[j]) ? i : prev[j];
                len[j] = max(len[i]+1, len[j]);
            }
        }
    }

    int l = *max_element(len, len+n);
    int mx_indx = distance(len, max_element(len, len+n));
    vector<int> lis;

    v = mx_indx;
    for(i=0; i<l; i++)
    {
        lis.push_back(arr[v]);
        v = prev[v];
    }

    reverse(lis.begin(), lis.end());

    cout << "Length of LIS = " << l << endl;
    cout << "The LIS is ";
    for(i=0; i<lis.size(); i++)
    {
        cout << lis[i];

        if(i != lis.size()-1)
            cout << ", ";
    }
    cout << endl;

    return 0;
}
