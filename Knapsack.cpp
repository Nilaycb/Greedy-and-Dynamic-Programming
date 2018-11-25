#include<bits/stdc++.h>
using namespace std;

int knapsack(int val[], int wt[], int n, int w)
{
    int i, j, p[n+1][w+1];

    for(i=0; i<n+1; i++)
    {
        for(j=0; j<w+1; j++)
        {
            if(i==0 || j==0)
                p[i][j] = 0;
            else if(wt[i-1] <= j)
                p[i][j] = max(val[i-1] + p[i-1][j-wt[i-1]], p[i-1][j]);
            else
                p[i][j] = p[i-1][j];
        }
    }

    return p[n][w];
}

int main()
{
    int n, w, i;

    cout << "Total Items: ";
    cin >> n;

    int val[n], wt[n];

    cout << "Enter Price: ";
    for(i=0; i<n; i++)
    {
        cin >> val[i];
    }

    cout << "Enter Weight: ";
    for(i=0; i<n; i++)
    {
        cin >> wt[i];
    }

    cout << "Knapsack Capacity: ";
    cin >> w;
    cout << endl;

    cout << "Maximum Profit: " << knapsack(val, wt, n, w) << endl;

    return 0;
}
