#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, j;

    cout << "Enter the number of nodes: ";
    cin >> n;

    char nodes[n];
    int mat[n][n], in_deg[n], out_deg[n];
    fill_n(in_deg, n, 0);
    fill_n(out_deg, n, 0);

    cout << "Enter the nodes: ";
    for(i=0; i<n; i++)
    {
        cin >> nodes[i];
    }
    cout << endl;

    cout << "Enter Adjacency Matrix for the nodes: " << endl;
    for(i=0; i<n+1; i++)
    {
        if(i == 0)
            cout << " ";
        else
            cout << nodes[i-1];

        (i!=0 || i!=n) ? cout << " " : cout << "";
    }
    cout << endl;

    for(i=0; i<n; i++)
    {
        cout << nodes[i] << " ";
        for(j=0; j<n; j++)
        {
            cin >> mat[i][j];
        }
    }
    cout << endl;

    cout << "Showing The Adjacency Matrix: " << endl;
    for(i=0; i<n+1; i++)
    {
        if(i == 0)
            cout << " ";
        else
            cout << nodes[i-1];

        (i!=0 || i!=n) ? cout << " " : cout << "";
    }
    cout << endl;

    for(i=0; i<n; i++)
    {
        cout << nodes[i] << " ";
        for(j=0; j<n; j++)
        {
            cout << mat[i][j];

            (j != n-1) ? cout << " " : cout << "";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Showing the connectivity of each node: " << endl;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(mat[i][j] == 1)
                cout << nodes[i] << "->" << nodes[j];

            if(mat[i][j]==1 && j!=n-1)
                cout << ", ";
        }
        cout << endl;
    }

    cout << "Showing the degrees of each node: " << endl;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(mat[i][j] == 1)
                out_deg[i]++;
        }
    }
    for(j=0; j<n; j++)
    {
        for(i=0; i<n; i++)
        {
            if(mat[i][j] == 1)
                in_deg[j]++;
        }
    }
    for(i=0; i<n; i++)
    {
        cout << "Indegree of " << nodes[i] << " = " << in_deg[i] << endl;
        cout << "Outdegree of " << nodes[i] << " = " << out_deg[i] << endl;
    }

    return 0;
}
