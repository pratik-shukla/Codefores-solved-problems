#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
#define d  double
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

ll n;
d a;

d get(d first)
{
    ll now = 2;
    d prev = a, curr = first, next;

    while (now < n)
    {
        next = 2 * (curr + 1) - prev;
        now += 1;
        prev = curr;
        curr = next;
        if (curr < 0)
            return -1;
    }
    return curr;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin >> n >> a)
    {
        d l = 0, r = 1500, mid, ans;
        ans = LLONG_MAX;
        for (int i = 0; i < 500; i++)
        {
                mid = (r +l) / 2;
                d t = get(mid);
                if (t == -1)
                {
                    l = mid;
                }
                else
                {
                    r = mid ;
                    ans = min(ans, t);
                }
            }
            cout << fixed << setprecision(2) <<ans << '\n';
        }
    }