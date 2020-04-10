#include <bits/stdc++.h>
#include <iostream>
using namespace std;


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, k, buff, tmp;
    cin >> n >> k;
    k--;
    int perm[n];
    int has[n];
    int comb = 1;
    has[0] = 0;
    for(int i = 1; i < n; ++i)
    {
        has[i] = 0;
        comb *= i;
    }
  //  cout << "Comb Done" << endl;
    for(int i = 0; i < n; ++i)
    {
        buff = k / comb;
        tmp = 0;
        for(int g = 0; g < n; ++g)
        {
            if(has[g] == 0)tmp++;
            if(tmp == buff + 1)
            {
                has[g] = 1;
                perm[i] = g;
                break;
            }
        }
        k = k % comb;
        if(i != n - 1)comb /= n - i - 1;
    }
  //  cout << "Comb Found" << endl;
    for(int i = 0; i < n; ++i)
    {
        cout << perm[i] + 1<< " ";
    }
}

