#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef unsigned long long ull ;
typedef vector<int> vi ;
typedef vector<ll> vl ;
typedef vector<vi> vvi ;
typedef vector<vl> vvl ;
typedef pair<int, int> pii ;
typedef pair<ll, ll> pll ;
typedef pair<float, float> pff ;
typedef pair<double, double> pdd ;
typedef pair<ll, ll> pll ;
#define el << '\n' ;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds ;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
#define pb push_back
#define PI 3.14159265358979323
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define fastIO	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0) ;
ll bin_expo(ll base, ll pow, ll m) {
    if (pow == 0) return 1;ll ret = bin_expo(base, pow / 2, m) % m ;
    if (pow & 1) return (ret % m * ret % m * base % m) % m;else return (ret % m * ret % m) % m ; }
ll ncr(ll n , ll r) {ll mul = 1 ; for(ll i=1;i<=r;i++) {mul = mul * (n-i+1) ; mul = mul/i ; }return mul ; }
ll mod_add(ll a, ll b, ll m) { return ((a % m) + (b % m)) % m ; }
ll mod_sub(ll a, ll b, ll m) { return (a-b+m)%m ; }
ll mod_mul(ll a, ll b, ll m) { return ((a % m) * (b % m)) % m ; }
ll mod_div(ll a, ll b, ll m) { return ((a % m) * bin_expo(b, m - 2, m)) % m ; }
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b) ; }
int dx[] = {0, 0, +1, -1, +1, -1, -1, +1} ;
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1} ;
const ll infLL = 4e18 + 123 ;
const ll inf = 1e12 + 7 ;
const ll mod = 1e9 + 7 ;
const ll mod2 = 1e9 + 9 ;
const ll mx = 1e6 + 1 ;
ll fact[mx] , inv[mx] ;
ll ncr_modmPrime(ll n , ll r , ll m) {
    fact[0] = inv[0] = 1 ; for(ll i=1;i<mx;i++) {fact[i] = mod_mul(fact[i-1],i,m)  ; }
    inv[mx-1] = bin_expo(fact[mx-1],m-2,m) ;for(ll i=mx-2;i>=1;i--) {inv[i] = mod_mul(inv[i+1],(i+1),m) ; }
    ll up = fact[n] ; ll down = mod_mul(inv[r],inv[n-r],m) ; ll ans1 = mod_mul(up,down,m) ;return ans1 ;
}

// ---------------------------------------------------------------------------------------------------------------------


bitset<mx>vis ;
vector<ll> prime ;
ll prefix[mx] ;
void sieve() {
    vis[1]=1;
    for(int i=3;i*i<mx;i+=2) {
        if(!vis[i]) {
            for(int j=i*i;j<mx;j+=2*i) {
                vis[j] = 1 ;
            }
        }
    }
    for(int i=4;i<mx;i+=2) vis[i]=1 ;
    prime.push_back(2) ;
    for(int i=3;i<mx;i+=2) {
        if(!vis[i]) prime.push_back(i) ;
    }
}


vector<pair<ll,ll>> prime_factorization(ll n) {
    vector<pair<ll,ll>>factors;
    for(auto i:prime) {
        if(i*i>n) break ;
        if(n%i==0) {
            int cnt = 0 ;
            while(n%i==0) {
                cnt ++ ;
                n/=i ;
            }
            factors.push_back({i,cnt}) ;
        }
    }
    if(n!=1) {
        factors.push_back({n,1}) ;
    }
    return factors ;
}


ll GcdSumFunction(ll n) {             // gcd(1,n) + gcd(2,n) + .... gcd(n,n)
    ll Gsum = 1 ;
    vector<pair<ll,ll>> v = prime_factorization(n) ;
    for(auto it:v) {
        ll p = it.first ;
        ll a = it.second ;
        ll pow1 = bin_expo(p,a,infLL) ;
        ll val1 = (a+1) * pow1 ;
        ll pow2 = pow1/p ;
        ll val2 = a*pow2 ;
        ll temp = val1 - val2 ;
        Gsum *= temp ;
    }
    return Gsum ;
}


void solution() {

    ll n ;
    prefix[1] = 1 ;
    for(ll i=2;i<mx;i++) {
        prefix[i] = prefix[i-1] ;
        ll Gsum = GcdSumFunction(i) ;
        prefix[i] += Gsum ;
    }
    while(cin >> n) {
        if(n==0) {
            break ;
        }
        ll sum = (n*(n+1))/2 ;
        cout << prefix[n] - sum el ;
    }
}


int main() {

    fastIO  ;
//    #ifndef ONLINE_JUDGE
//    file() ;
//    #endif
    sieve() ;
    ll _ = 1 ;
    //cin >> _ ;
    while (_--) solution() ;
    return   0 ;
}