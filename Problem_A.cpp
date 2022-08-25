//      بسم الله الرحمن الرحيم
//      All praise is due to ALLAH alone

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef pair<float, float> pff;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define el << '\n'
#define pb push_back
#define PI 3.14159265358979323
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define fastIO        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
ll bin_expo(ll base, ll pow, ll m)
{       if (pow == 0) return 1;
        ll ret = bin_expo(base, pow / 2, m) % m;
        if (pow & 1)return (ret % m * ret % m * base % m) % m;
        else return (ret % m * ret % m) % m;}
ll mod_add(ll a, ll b, ll m) { return (a % m + b % m) % m; }
ll mod_sub(ll a, ll b, ll m) { return (a % m - b % m) % m; }
ll mod_mul(ll a, ll b, ll m) { return (a % m * b % m) % m; }
ll mod_div(ll a, ll b, ll m) { return (a % m * bin_expo(b, m - 2, m)) % m; }
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int dx[] = {0, 0, +1, -1, +1, -1, -1, +1} ;
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1} ;
const ll infLL = 1e18 ;
const ll inf = 1e17 + 7 ;
const ll mod = 1e9 + 7 ;
const int mx = 1e6 + 123 ;
const double eps = 1e-7 ;



int tree[mx*3][3];
int Lazy[mx*3];



void Build(int node, int left, int right)
{
        if (left == right)
        {
                tree[node][0] = 1;
                tree[node][1] = tree[node][2] = 0;
                return;
        }
        int mid = (left + right) >> 1;
        Build(node*2, left, mid);
        Build((node*2)+1, mid + 1, right);
        tree[node][1] = tree[node][2] = 0;
        tree[node][0] = tree[node*2][0] + tree[(node*2)+1][0];
}

void swap1(int &a, int &b, int &c)
{
        int ta = a, tb = b, tc = c;
        a = tc;
        b = ta;
        c = tb;
}
void swap2(int &a, int &b, int &c)
{
        int ta = a, tb = b, tc = c;
        c = ta;
        a = tb;
        b = tc;
}

void propagate(int node, int left, int right)
{
        if (left != right)
        {
                Lazy[node*2] = (Lazy[node] + Lazy[node*2]) % 3;
                Lazy[(node*2)+1] = (Lazy[node] + Lazy[(node*2)+1]) % 3;
        }
        if (Lazy[node] == 1)
        {
                swap1(tree[node][0], tree[node][1], tree[node][2]);
        }
        if (Lazy[node] == 2)
        {
                swap2(tree[node][0], tree[node][1], tree[node][2]);
        }

        Lazy[node] = 0;
}

int Query(int node, int left, int right, int start, int end)
{

        if (Lazy[node])
                propagate(node, left, right);
        if (start > right || end < left)
                return 0;
        if (start <= left && end >= right)
        {
                return tree[node][0];
        }
        int mid = (left + right) >> 1;
        int p1 = Query(node*2, left, mid, start, end);
        int p2 = Query((node*2)+1, mid + 1, right, start, end);
        return p1 + p2;
}

void Update(int node, int left, int right, int start, int end)
{
        if (Lazy[node])
                propagate(node, left, right);

        if (start > right || end < left)
                return;
        if (left >= start && right <= end)
        {
                if (left != right)
                {
                        Lazy[node*2] = (1 + Lazy[node*2]) % 3;
                        Lazy[(node*2)+1] = (1 + Lazy[(node*2)+1]) % 3;
                }

                swap1(tree[node][0], tree[node][1], tree[node][2]);
                return;
        }
        int mid = (left + right) >> 1;
        Update(node*2, left, mid, start, end);
        Update((node*2)+1, mid + 1, right, start, end);
        tree[node][0] = tree[node*2][0] + tree[(node*2)+1][0];
        tree[node][1] = tree[node*2][1] + tree[(node*2)+1][1];
        tree[node][2] = tree[node*2][2] + tree[(node*2)+1][2];
}

void solution()
{
        int n, q;
        cin >> n >> q ;  
        Build(1, 1, n);
        while (q--)
        {
                int cs, l, r;
                cin >> cs >> l >> r ;  
                l++;
                r++;
                if (cs == 0)
                {
                        Update(1, 1, n, l, r);
                }
                else
                {
                        int ans = Query(1, 1, n, l, r) ;
                        cout << ans << endl ;  
                }
        }
}

int main()
{
        fastIO;
        // file() ;
        int _ = 1; // cin >> _;
        while (_--)
                solution();
        return 0;
}
