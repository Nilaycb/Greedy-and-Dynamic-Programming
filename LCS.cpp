#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i, j;
    string x, y;
    vector<char> LCS;

    cout << "Enter 1st sequence: ";
    getline(cin, x);
    cout << "Enter 2st sequence: ";
    getline(cin, y);
    cout << endl;

    int b[x.size()+1][y.size()+1];
    int c[x.size()+1][y.size()+1];

    // b[i][j] = 0 means nothing
    // b[i][j] = 1 means left
    // b[i][j] = 2 means up
    // b[i][j] = 3 means diagonal (also means taken as LCS element)

    for(i=0; i<x.size()+1; i++)
    {
        for(j=0; j<y.size()+1; j++)
        {
            if(i==0 || j==0)
            {
                b[i][j] = 0;
                c[i][j] = 0;
            }
            else if(x[i-1] == y[j-1])
            {
                b[i][j] = 3;
                c[i][j] = c[i-1][j-1]+1;
            }
            else
            {
                b[i][j] = (c[i-1][j] >= c[i][j-1]) ? 2 : 1;
                c[i][j] = max(c[i][j-1], c[i-1][j]);
            }
        }
    }

    i = x.size();
    j = y.size();

    while((i != 0) || (j != 0))
    {
        if(b[i][j] == 1)
        {
            j -= 1;
        }
        else if(b[i][j] == 2)
        {
            i -= 1;
        }
        else if(b[i][j] == 3)
        {
            i -= 1;
            j -= 1;
            LCS.push_back(x[i]);
        }
        else
        {
            break;
        }
    }

    reverse(LCS.begin(), LCS.end());

    cout << "The Longest Common Subsequence is ";
    for(i=0; i<LCS.size(); i++)
    {
        cout << LCS[i];
    }
    cout << endl;

    cout << "The Length of LCS is " << c[x.size()][y.size()] << endl;

    return 0;
}
