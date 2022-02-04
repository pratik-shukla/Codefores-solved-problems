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


vector<ll> adj[200002];
ll inDegree[200002];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;
    cin >> n;
    vector<ll> a, b;
    ll ans_f = 0;
    for (int i = 0; i < n; i++)
    {
        inDegree[i] = 0;
        cin >> k;
        a.push_back(k);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        k--;
        b.push_back(k);
    }
    for (int i = 0; i < n; i++)
    {
        if (b[i]>-1)
        {
            adj[i].push_back(b[i]);
            inDegree[b[i]]++;
        }
    }
    queue<ll> q;
    vector<ll> ans,ansFinal,neg;
    for (int i = 0; i < n; i++)
    {
        //cout << i << " ";
        if (b[i]!=-1 and !inDegree[i])
        {
            q.push(i);
            ans.push_back(i);
        }
    }
    while (!q.empty())
    {
        ll node = q.front();
        q.pop();
        for (auto i:adj[node])
        {
            inDegree[i]--;
            if (!inDegree[i])
            {
                q.push(i);
                ans.push_back(i);
            }
        }
    }
    //reverse(ans.begin(), ans.end());
    for (auto i:ans)
    {
        if (a[i]>=0)
        {
            ans_f += a[i];
            a[b[i]] += a[i];
            ansFinal.push_back(i);
            //cout << i + 1 << " ";
        }
    }
    for (auto i : ans)
    {
        if (a[i] < 0)
        {
            neg.push_back(i);
            //cout << i + 1 << " ";
        }
    }
    reverse(neg.begin(), neg.end());
    for (auto i:neg)
    {
        ans_f += a[i];
        a[b[i]] += a[i];
        ansFinal.push_back(i);
    }
    cout << ans_f<<'\n';
    for (auto i:ansFinal)
        cout << i+1 << " ";
}