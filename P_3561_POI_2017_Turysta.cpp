// Author: xiaruize
// #define ONLINE_JUDGE
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define debug(x) cerr << "On Line:" << __LINE__ << #x << "=" << x << endl
bool start_of_memory_use;
#else
#define debug(x)
#endif
namespace __DEBUG_UTIL__
{
    using namespace std;
    /* Primitive Datatypes Print */
    void print(const char *x) { cerr << x; }
    void print(bool x) { cerr << (x ? "T" : "F"); }
    void print(char x) { cerr << '\'' << x << '\''; }
    void print(signed short int x) { cerr << x; }
    void print(unsigned short int x) { cerr << x; }
    void print(signed int x) { cerr << x; }
    void print(unsigned int x) { cerr << x; }
    void print(signed long int x) { cerr << x; }
    void print(unsigned long int x) { cerr << x; }
    void print(signed long long int x) { cerr << x; }
    void print(unsigned long long int x) { cerr << x; }
    void print(float x) { cerr << x; }
    void print(double x) { cerr << x; }
    void print(long double x) { cerr << x; }
    void print(string x) { cerr << '\"' << x << '\"'; }
    template <size_t N>
    void print(bitset<N> x) { cerr << x; }
    void print(vector<bool> v)
    { /* Overloaded this because stl optimizes vector<bool> by using
          _Bit_reference instead of bool to conserve space. */
        int f = 0;
        cerr << '{';
        for (auto &&i : v)
            cerr << (f++ ? "," : "") << (i ? "T" : "F");
        cerr << "}";
    }
    /* Templates Declarations to support nested datatypes */
    template <typename T>
    void print(T &&x);
    template <typename T>
    void print(vector<vector<T>> mat);
    template <typename T, size_t N, size_t M>
    void print(T (&mat)[N][M]);
    template <typename F, typename S>
    void print(pair<F, S> x);
    template <typename T, size_t N>
    struct Tuple;
    template <typename T>
    struct Tuple<T, 1>;
    template <typename... Args>
    void print(tuple<Args...> t);
    template <typename... T>
    void print(priority_queue<T...> pq);
    template <typename T>
    void print(stack<T> st);
    template <typename T>
    void print(queue<T> q);
    /* Template Datatypes Definitions */
    template <typename T>
    void print(T &&x)
    {
        /*  This works for every container that supports range-based loop
            i.e. vector, set, map, oset, omap, dequeue */
        int f = 0;
        cerr << '{';
        for (auto &&i : x)
            cerr << (f++ ? "," : ""), print(i);
        cerr << "}";
    }
    template <typename T>
    void print(vector<vector<T>> mat)
    {
        int f = 0;
        cerr << "\n~~~~~\n";
        for (auto &&i : mat)
        {
            cerr << setw(2) << left << f++, print(i), cerr << "\n";
        }
        cerr << "~~~~~\n";
    }
    template <typename T, size_t N, size_t M>
    void print(T (&mat)[N][M])
    {
        int f = 0;
        cerr << "\n~~~~~\n";
        for (auto &&i : mat)
        {
            cerr << setw(2) << left << f++, print(i), cerr << "\n";
        }
        cerr << "~~~~~\n";
    }
    template <typename F, typename S>
    void print(pair<F, S> x)
    {
        cerr << '(';
        print(x.first);
        cerr << ',';
        print(x.second);
        cerr << ')';
    }
    template <typename T, size_t N>
    struct Tuple
    {
        static void printTuple(T t)
        {
            Tuple<T, N - 1>::printTuple(t);
            cerr << ",", print(get<N - 1>(t));
        }
    };
    template <typename T>
    struct Tuple<T, 1>
    {
        static void printTuple(T t) { print(get<0>(t)); }
    };
    template <typename... Args>
    void print(tuple<Args...> t)
    {
        cerr << "(";
        Tuple<decltype(t), sizeof...(Args)>::printTuple(t);
        cerr << ")";
    }
    template <typename... T>
    void print(priority_queue<T...> pq)
    {
        int f = 0;
        cerr << '{';
        while (!pq.empty())
            cerr << (f++ ? "," : ""), print(pq.top()), pq.pop();
        cerr << "}";
    }
    template <typename T>
    void print(stack<T> st)
    {
        int f = 0;
        cerr << '{';
        while (!st.empty())
            cerr << (f++ ? "," : ""), print(st.top()), st.pop();
        cerr << "}";
    }
    template <typename T>
    void print(queue<T> q)
    {
        int f = 0;
        cerr << '{';
        while (!q.empty())
            cerr << (f++ ? "," : ""), print(q.front()), q.pop();
        cerr << "}";
    }
    /* Printer functions */
    void printer(const char *) {} /* Base Recursive */
    template <typename T, typename... V>
    void printer(const char *names, T &&head, V &&...tail)
    {
        /* Using && to capture both lvalues and rvalues */
        int i = 0;
        for (size_t bracket = 0; names[i] != '\0' and (names[i] != ',' or bracket != 0); i++)
            if (names[i] == '(' or names[i] == '<' or names[i] == '{')
                bracket++;
            else if (names[i] == ')' or names[i] == '>' or names[i] == '}')
                bracket--;
        cerr.write(names, i) << " = ";
        print(head);
        if (sizeof...(tail))
            cerr << " ||", printer(names + i + 1, tail...);
        else
            cerr << "]\n";
    }
    /* PrinterArr */
    void printerArr(const char *) {} /* Base Recursive */
    template <typename T, typename... V>
    void printerArr(const char *names, T arr[], size_t N, V... tail)
    {
        size_t ind = 0;
        for (; names[ind] and names[ind] != ','; ind++)
            cerr << names[ind];
        for (ind++; names[ind] and names[ind] != ','; ind++)
            ;
        cerr << " = {";
        for (size_t i = 0; i < N; i++)
            cerr << (i ? "," : ""), print(arr[i]);
        cerr << "}";
        if (sizeof...(tail))
            cerr << " ||", printerArr(names + ind + 1, tail...);
        else
            cerr << "]\n";
    }
}
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#define debugArr(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printerArr(#__VA_ARGS__, __VA_ARGS__)
clock_t start_clock = clock();
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
#define ull unsigned long long
#define ALL(a) (a).begin(), (a).end()
#define pii pair<int, int>
#define pis pair<int, string>
#define sz(a) (int)((a).size())
#define Yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define No cout << "No" << endl
#define NO cout << "NO" << endl
#define mms(arr, n) memset(arr, n, sizeof(arr))
#define rep(i, a, n) for (int i = (a); i <= (n); ++i)
#define per(i, n, a) for (int i = (n); i >= (a); --i)
template <class _Tx, class _Ty>
inline void chkmi(_Tx &x, const _Ty &y)
{
    if (y < x)
        x = y;
}
template <class _Tx, class _Ty>
inline void chkmx(_Tx &x, const _Ty &y)
{
    if (x < y)
        x = y;
}
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1000000007;
const int N = 2e3 + 10;

int n;
bool g[N][N];
int dfn[N], low[N], bel[N];
vector<int> col[N], res[N], cir[N];
stack<int> st;
int tot, cnt;

void tarjan(int u)
{
    dfn[u] = low[u] = ++tot;
    st.push(u);
    rep(v, 1, n)
    {
        if (g[u][v])
        {
            if (!dfn[v])
            {
                tarjan(v);
                low[u] = min(low[u], low[v]);
            }
            else if (!bel[v])
                low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u])
    {
        cnt++;
        while (st.top() != u)
        {
            bel[st.top()] = cnt;
            st.pop();
        }
        bel[st.top()] = cnt;
        st.pop();
    }
}

vector<int> calc(vector<int> &vec)
{
    if (sz(vec) == 1)
        return vec;
    vector<int> pt;
    for (auto v : vec)
    {
        int pos = 0;
        while (pos < sz(pt) && !g[v][pt[pos]])
            pos++;
        pt.insert(pt.begin() + pos, v);
    }
    int pos = 0;
    vector<int> res;
    while (!g[pt[pos]][pt[0]])
    {
        res.push_back(pt[pos]);
        pos++;
    }
    res.push_back(pt[pos]);
    pos++;
    while (pos < sz(pt))
    {
        int t = pos;
        while (find_if(ALL(res), [&](int x)
                       { return g[pt[t]][x]; }) == res.end())
            t++;
        int p = 0;
        while (p < sz(res) - 1 && !(g[res[p]][pt[pos]] && g[pt[t]][res[p + 1]]))
            p++;
        res.insert(p == sz(res) ? res.begin() : res.begin() + p + 1, pt.begin() + pos, pt.begin() + t + 1);
        pos = t + 1;
    }
    return res;
}

void solve()
{
    cin >> n;
    rep(i, 1, n)
    {
        rep(j, 1, i - 1)
        {
            int x;
            cin >> x;
            g[j][i] = x;
            g[i][j] = x ^ 1;
        }
    }
    rep(i, 1, n) if (!dfn[i])
        tarjan(i);
    rep(i, 1, n) col[bel[i]].push_back(i);
    rep(i, 1, cnt)
    {
        auto vec = calc(col[i]);
        cir[i] = vec;
        for (auto v : vec)
        {
            auto it = find_if(ALL(vec), [&](int x)
                              { return x == v; });
            res[v].insert(res[v].end(), it, vec.end());
            res[v].insert(res[v].end(), vec.begin(), it);
            per(j, i - 1, 1) res[v].insert(res[v].end(), ALL(cir[j]));
        }
    }
    rep(i, 1, n)
    {
        cout << sz(res[i]) << ' ';
        for (auto v : res[i])
            cout << v << ' ';
        cout << endl;
    }
}

#ifndef ONLINE_JUDGE
bool end_of_memory_use;
#endif

signed main()
{
#ifndef ONLINE_JUDGE
    auto start_clock = chrono::high_resolution_clock::now();
#endif
    // freopen(".in","r",stdin);
    // freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int testcase = 1;
    // cin >> testcase;
    while (testcase--)
        solve();
#ifndef ONLINE_JUDGE
    auto end_clock = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end_clock - start_clock);
    cerr << "Memory use:" << (&end_of_memory_use - &start_of_memory_use) / 1024.0 / 1024.0 << "MiB" << endl;
    cerr << "Time use:" << duration.count() * 0.001 << "ms" << endl;
#endif
    return 0;
}
