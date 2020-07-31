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



bool used[10];
vector<ll> nums;

int calc(int a, int b, int key)
{
    if (key==1)
        return a + b;
    else if (key==2)
        return a - b;
    return a * b;
}

bool recur(int ind, int ans)
{
    if (ind==5)
    {
        return ans == 23;
    }
    for (int i = 0; i < 5; i++)
    {
        if (!used[i])
        {
            used[i] = 1;
            if (recur(ind+1,ans+nums[i]) or recur(ind+1, ans-nums[i]) or recur(ind+1, ans*nums[i]))
            {
                return 1;
            }
            used[i] = 0;
        }
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (1)
    {
        ll k;
        bool f = 0;
        nums.clear();
        for (int i = 0; i < 5; i++)
        {
            cin >> k;
            used[i] = 0;
            nums.push_back(k);
        }
        sort(nums.begin(), nums.end());
        if (nums[0]==0 and nums[4]==0)
            break;
        for (int i = 0; i < 5; i++)
        {
            used[i] = 1;
            if (recur(1, nums[i])) 
            {
                f = 1;
                break;
            }
            used[i] = 0;
        }
        if (f)
        {
            cout << "Possible" << '\n';
        }
        else
        {
            cout << "Impossible" << '\n';
        }
    }
    
}