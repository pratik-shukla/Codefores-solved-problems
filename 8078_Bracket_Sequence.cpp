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
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    ll t,c=0;
    cin>>t;
    while (t--)
    {
        c++;
        string s;
        cin>>s;
        ll ans[s.length()];
        stack<pair<char,int>> st;
        ll curr = 0;
        for (ll i = s.length() - 1; i >= 0; i--)
        {
            ans[i]=0;
            if (st.empty())
            {
                st.push({s[i], i});
                curr = 0;
                ans[i] = 0;
            }
            else
            {
                if (s[i] ==')' or s[i] ==']' or s[i] =='}' or s[i] =='>' )
                {
                    st.push({s[i],i});
                    ans[i] = 0;
                    curr = 0;
                }
                else
                {
                    if (s[i] == '(' and st.top().first==')' or s[i] == '[' and st.top().first==']' or s[i] == '{' and st.top().first=='}' or s[i] == '<' and st.top().first=='>')
                    {
                        curr += 2;
                        ans[i] = curr ;
                        if (st.top().second<s.length()-1)
                        {
                            ans[i] += ans[st.top().second + 1];
                        }
                        curr = ans[i];
                        st.pop();
                    }
                    else
                    {
                        st.push({s[i], i});
                        curr = 0;
                    }
                    
                }
                
            }
        }
        cout << "Case " << c << ":" << '\n';
        //if (!st.empty()) cout << st.top().first << '\n';
        for (auto i:ans)
            cout << i << '\n';
    }
    
}
/*
Check answer output format!!
 Extra test case which might be failing ::
 Input:
 --------------
 2
((()))
(()())
-------------------
-----------------------
Output:
------------
Case 1:
6
4
2
0
0
0
Case 2:
6
4
0
2
0
0

*/