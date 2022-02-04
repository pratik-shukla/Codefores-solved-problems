#include <iostream>
#include <bits/stdc++.h>
#define ll int
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
// the little guy below helps me to create unordered set of vectors
// just declare it like this ---> unordered_set<vector<int>, VectorHash>>
// credits:: https://stackoverflow.com/users/2069064/barry
struct VectorHash
{
    size_t operator()(const std::vector<int> &v) const
    {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i : v)
        {
            seed ^= hasher(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> ab(n), cd(m), cdn;
    for (int i = 0; i<n; i++)
        cin >> ab[i].first >> ab[i].second;
    for (int i = 0; i < m; i++)
        cin >> cd[i].first >> cd[i].second;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (cd[j].first >=ab[i].first && cd[j].second>=ab[i].second){
                cdn.push_back({cd[j].first-ab[i].first, cd[j].second-ab[i].second});
            }
        }
    }
    ll maxx = 1e6 + 1;
    vector<ll> neu(maxx, -1);
    for (auto i:cdn){
        neu[i.second]=max(neu[i.second], i.first);
    }
    for (int i = maxx - 2; i >= 0; i--)
        neu[i] = max(neu[i], neu[i + 1]);
    ll ans = maxx;
    for (int i=0; i<maxx; i++){
        ans = min(ans, i + neu[i] + 1);
    }
    cout << ans;
}