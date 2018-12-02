#include<bits/stdc++.h>
using namespace std;

int lcs(string x, string y)
{
    int c[x.size()+1][y.size()+1];

    int i, j;
    for(i=0; i<x.size()+1; i++)
    {
        for(j=0; j<y.size()+1; j++)
        {
            if(i==0 || j==0)
            {
                c[i][j] = 0;
            }
            else if(x[i-1] == y[j-1])
            {
                c[i][j] = c[i-1][j-1]+1;
            }
            else
            {
                c[i][j] = max(c[i][j-1], c[i-1][j]);
            }
        }
    }

    return c[x.size()][y.size()];
}

int main()
{
    int t, n, i, j, mw=0, mc=0, wc=0;

    cin >> t;

    while(t--)
    {
        mw=0;
        mc=0;
        wc=0;

        cin >> n;
        getchar();
        string M, W, C;

        getline(cin, M);
        getline(cin, W);
        getline(cin, C);

        mw = lcs(M, W);
        mc = lcs(M, C);
        wc = lcs(W, C);

        if(mw >= mc && mw >= wc)
            cout << "Magneto's and Wolverine's DNAs have most Correlation. " << endl;
        else if(mc >= mw && mc >= wc)
            cout << "Magneto's and Cyclops's DNAs have most Correlation." << endl;
        else if(wc >= mw && wc >= mc)
            cout << "Wolverine's and Cyclops's DNAs have most Correlation." << endl;
        else
            cout << "No relations." << endl;
    }

    return 0;
}
