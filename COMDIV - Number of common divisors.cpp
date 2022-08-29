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
const int mx = 5e5 + 123 ;
const double eps = 1e-7 ;
 

 

bitset<mx>vis ; 
vector<ll> prime ; 
void sieve()
{
        vis[1]=1; 
        for(int i=3;i*i<mx;i+=2)
        {
                if(!vis[i])
                {
                        for(int j=i*i;j<mx;j+=2*i)
                        {
                                vis[j] = 1 ;  
                        }
                }
        } 
        prime.push_back(2) ; 
        for(int i=3;i<mx;i+=2) 
        {
                if(!vis[i]) prime.push_back(i) ;  
        }
}

vector<pair<ll,ll>> prime_factorization(ll n)
{
        vector<pair<ll,ll>>factors; 
        ll val = n ; 
        for(auto i:prime)
        {
                if(i*i>val) break ; 
                if(n%i==0)
                {
                        int cnt = 0 ; 
                        while(n%i==0)
                        {
                                cnt ++ ; 
                                n/=i ; 
                        }
                        factors.push_back({i,cnt}) ; 
                }
        }
        if(n!=1)
        {
                factors.push_back({n,1}) ; 
        }
        return factors ; 
}


ll sumofDivisors(ll n)
{
        ll SOD = 1 ; 
        vector<pair<ll,ll>> pf = prime_factorization(n) ; 
        for(auto it:pf)
        { 
                ll up = bin_expo(it.first,it.second+1,infLL) -1 ; 
                ll down = it.first - 1; 
                SOD *= up/down ; 
        }
        return SOD ; 
}

ll numberofDivisors(ll n)
{
        ll NOD = 1 ; 
        vector<pair<ll,ll>> pf = prime_factorization(n) ; 
        for(auto it:pf)
        { 
                NOD *= it.second+1 ;  
        }
        return NOD ;
}
 
void solution()
{ 
        ll a , b ; 
        scanf("%lld %lld",&a,&b) ; 
        ll ans = numberofDivisors(__gcd(a,b))  ;
        printf("%lld\n",ans) ; 
}
 
 
int main()
{
        fastIO;
        // file() ;
        sieve() ; 
        int _ = 1; scanf("%d",&_) ; 
        while (_--) solution();
        return 0;
}
