#include <bits/stdc++.h>
#include <iostream>
using namespace std;


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, k, num, f, buff;
    num = 0;
    cin >> n >> k;
    int perm [k];
    int has[n + 1];
    f = 1;
    for(int i = 0; i < k; ++i)
    {
        cin >> perm[i];
    }
    for(int i = 0; i < n + 1; ++i)
    {
        if(i > n - k)f *= i;
        has[i] = 0;
    }
    //cout << f << " " << num <<  endl;
    for(int pos = 0; pos < k; ++pos)
    {
        buff = 0;
        f /= (n - pos);
        for(int i = perm[pos] - 1; i > 0; --i)
        {
            if(has[i] == 0) buff++;
        }
        num += buff * f;
        //cout << f << " " << num <<  endl;
       // cout << num  << " " <<  f << endl;
        has[perm[pos]] = 1;
    }
    cout << num + 1;
}


