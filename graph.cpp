#include<bits/stdc++.h>
using namespace std;

int mat_id(char nodes[], int n, char s)
{
    int i;
    for(i=0; i<n; i++)
    {
        if(s == nodes[i])
            return i;
    }

    return -1;
}

int main()
{
    int n, i, j;

    cout << "Enter the number of nodes: ";
    cin >> n;

    char nodes[n];
    int mat[n][n], in_deg[n], out_deg[n];
    vector<int> adj[n];
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
            {
                cout << nodes[i] << "->" << nodes[j];
                adj[i].push_back(j);
            }

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
    cout << endl;


    // Shortest Path Finding using BFS algorithm
    queue<char> q;
    vector<char> path;
    int dis[n], prev[n], s_int = -1, des_int = -1;
    fill_n(dis, n, -1);
    fill_n(prev, n, -1);
    char s, des;

    cout << "Enter Source vertex: ";
    cin >> s;
    cout << "Enter Destination vertex: ";
    cin >> des;

    q.push(s);

    s_int = mat_id(nodes, n, s);
    des_int = mat_id(nodes, n, des);

    if(s == des)
    {
        cout << "Distance: 0" << endl;
    }
    else if(s_int == -1)
    {
        cout << "Source not found." << endl;
    }
    else if(des_int == -1)
    {
        cout << "Destination not found." << endl;
    }
    else
    {
        dis[s_int]=0;

        while(!q.empty())
        {
            char po=q.front();
            q.pop();
            int po_int;

            po_int = mat_id(nodes, n, po);

            for(auto k=adj[po_int].begin(); k != adj[po_int].end(); k++)
            {
                int m = *k;
                if(dis[m] == -1)
                {
                    q.push(nodes[m]);
                    dis[m] = dis[po_int]+1;
                    prev[m] = po_int;
                }
            }
        }

        if(dis[des_int] == -1)
        {
            cout << "Distance calculation not possible." << endl;
            cout << "No Path available." << endl;
        }
        else
        {
            int res=dis[s_int]-dis[des_int];
            cout << "Distance: " << abs(res) << endl;

            int last = des_int;
            path.push_back(nodes[last]);
            while (prev[last] != -1)
            {
                path.push_back(nodes[prev[last]]);
                last = prev[last];
            }

            reverse(path.begin(), path.end());
            cout << "The Path is: ";
            for(i=0; i < path.size(); i++)
            {
                cout << path[i];

                if(i+1 != path.size())
                    cout << "->";
            }
            cout << endl;
        }
    }

    return 0;
}
