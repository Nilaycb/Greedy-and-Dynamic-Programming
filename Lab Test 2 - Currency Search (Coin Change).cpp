#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, x, j;

    cout << "Total Currency: ";
    cin >> n;

    int c[n];

    cout << "Currency value: ";
    for(i=0; i<n; i++)
    {
        cin >> c[i];
    }

    cout << "Item Price: ";
    cin >> x;

    int b[n+1][x+1];
    int p[n+1][x+1];

    for(i=0; i<n+1; i++)
    {
        for(j=0; j<x+1; j++)
        {
            if(j==0)
            {
                b[i][j] = 0;
                p[i][j] = 0;
            }
            else if(i==0 && j!=0)
            {
                b[i][j] = 0;
                p[i][j] = INT_MAX;
            }
            else if(c[i-1] <= j)
            {
                b[i][j] = (p[i-1][j] < p[i][j-c[i-1]]+1) ? 2 : 1;
                p[i][j] = min(p[i-1][j], p[i][j-c[i-1]]+1);
            }
            else
            {
                b[i][j] = 2;
                p[i][j] = p[i-1][j];
            }
        }
    }

    int l = p[n][x];
    vector<int> s;

    i = n;
    j = x;

    while((i != INT_MAX) || (j != 0))
    {
        if(b[i][j] == 2)
        {
            i -= 1;
        }
        else if(b[i][j] == 1)
        {
            j = j - c[i-1];
            s.push_back(c[i-1]);
        }
        else
        {
            break;
        }
    }

    int sum=0;

    for(i=0; i<s.size(); i++)
    {
        sum += s[i];
    }

    if(sum == x)
    {
        cout << "You can buy the item with " << s.size() << " notes = ";
        for(j=0; j<s.size(); j++)
        {
            cout << s[j];

            if(j != s.size()-1)
                cout << ", ";
        }
        cout << endl;
    }
    else
    {
        cout << "You can't but the item." << endl;
    }

    return 0;
}
