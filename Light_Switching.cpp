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
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
const int mx = 2e5 + 123 ;
const double eps = 1e-7 ;



int a[mx] , n , m ;
int T ;


struct info {
    ll prop, sum;
} sgtree[mx * 3];



void compress(int node , int start , int end )  
{
        int left = node * 2 ; 
        int right = node * 2 + 1  ; 
        if(sgtree[node].prop) 
        {
                sgtree[node].sum = (end-start+1) - sgtree[node].sum ;
                if(end!=start)
                {
                        sgtree[left].prop^=1 ; 
                        sgtree[right].prop^=1 ;
                } 
                sgtree[node].prop = 0 ; 
        }

}


void update(int node , int start , int end , int l , int r)
{
        compress(node,start,end) ; 
        if(l>end or r<start) return ; 
        else if(l<=start and end<=r)
        {
                sgtree[node].prop^=1 ; 
                compress(node,start,end) ; 
                return ;
        }
        int left = node * 2 ; 
        int right = node * 2 + 1 ; 
        int mid = (start+end)/2 ; 
        update(left,start,mid,l,r) ; 
        update(right,mid+1,end,l,r) ; 
        sgtree[node].sum = sgtree[left].sum + sgtree[right].sum ; 
}



ll query(int node , int start ,int end , int l , int r)
{
        compress(node,start,end) ; 
        if(l>end or r<start) return 0 ; 
        else if(l<=start and end<=r)
        {
                return sgtree[node].sum ; 
        }
        int left = node * 2 ; 
        int right = node * 2 + 1 ; 
        int mid = (start+end)/2 ; 
        ll p1 = query(left,start,mid,l,r) ; 
        ll p2 = query(right,mid+1,end,l,r) ;
        return p1 + p2 ;  
}




void solution()
{
        cin >> n >> m ;
        for(int i=0;i<m;i++)
        {
                int cs ;
                cin >> cs ;
                if(cs==0)
                {
                        int l , r ; 
                        cin >> l >> r; 
                        update(1,1,n,l,r) ; 
                }
                else
                {
                        int l , r ; 
                        cin >> l >> r ; 
                        cout << query(1,1,n,l,r) << endl ; 
                }
        }
}


int main()
{
        fastIO;
        // file() ;
        int _ = 1; //cin >> _;
        while (_--) solution();
        return 0;
}
