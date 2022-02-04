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
    size_t operator()(const std :: vector<int> &v) const
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
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    ll cubes[101];
    cubes[0] = 0;
    for (int i = 1; i <= 100; i++)
    {
        cubes[i] = i * i * i;
    }
    while (1)
    {
        long double n;
        cin >> n;
        if (!n)
            break;
        long double k;
        for (int i = 0; i <= 100; i++)
        {
            if (cubes[i]>n)
                break;
            else
            {
                k = i;
            }
            
        }
        //cout << k << '\n';
        long double ans = (n - k * k * k) / ((long double)3 * (k)*k);
        cout << fixed << setprecision(4) << k+ans << '\n';
    }
    

}