#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
// the little guy below helps me to create unordered set of vectors
// just declare it like this ---> unordered_set<vector<int>, VectorHash>>
// credits:: https://stackoverflow.com/users/2069064/barry
struct VectorHash
{
    size_t operator()(const std:: vector<int> &v) const
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
vector<string> vec_splitter(string s)
{
    s += ',';
    vector<string> res;
    while (!s.empty())
    {
        res.push_back(s.substr(0, s.find(',')));
        s = s.substr(s.find(',') + 1);
    }
    return res;
}
void debug_out(
    vector<string> __attribute__((unused)) args,
    __attribute__((unused)) int idx,
    __attribute__((unused)) int LINE_NUM)
{
    cerr << endl;
}
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T)
{
    if (idx > 0)
        cerr << ", ";
    else
        cerr << "Line(" << LINE_NUM << ") ";
    stringstream ss;
    ss << H;
    cerr << args[idx] << " = " << ss.str();
    debug_out(args, idx + 1, LINE_NUM, T...);
}
#ifdef XOX
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__),
0, __LINE__, __VA_ARGS__)
#else
#define debug(...) 42
#endif
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, a, b;
    while (cin>>n>>a>>b)
    {
        unordered_set<ll> k;
        ll curr = 0;
        //k.insert(0);
        vector<ll> t;
        //t.push_back(0);
        while(1)
        {
            //cout << curr << '\n';
            curr = (a * curr%n * curr%n + b )%n;
            ll prev = k.size();
            k.insert(curr);
            if (prev==k.size())
                break;
            else
            {
                t.push_back(curr);
            }
            
        }
        ll correction = 0;
        for (auto i:t)
        {
            if (i==curr)
                break;
            correction++;
        }
        cout << n - k.size()+correction << '\n';
    }
    
}