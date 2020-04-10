#include <bits/stdc++.h>
#include <iostream>
using namespace std;


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, tmp;
    cin >> n;
    int perm[n];
    int has[n];
    for(int i = 0; i < n; ++i)
    {
        cin >> perm[i];
        has[i] = 0;
    }
    bool easy = true;
    for(int i = n - 1; i > 0; --i)
    {
        if(perm[i] > perm[i - 1])
        {
            easy = false;
            tmp = i - 1;
            break;
        }
    }
    if(easy)
    {
        for(int i = 0; i < n; ++i)
        {
            cout << i + 1 << " ";
        }
        return 0;
    }
    int mn = n + 1;
    for(int i = tmp; i < n; ++i)
    {
        if(perm[i] > perm[tmp] && perm[i] < mn)
        {
            mn = perm[i];
        }
    }
    perm[tmp] = mn;
    for(int i = 0; i <= tmp; ++i)
    {
        has[perm[i] - 1] = 1;
    }

    for(int i = 0; i < n; ++i)
    {
        if(has[i] == 0)
        {
            perm[++tmp] = i + 1;
        }
    }
    for(int i = 0; i < n; ++i)
    {
        cout << perm[i] << " ";
    }
}



