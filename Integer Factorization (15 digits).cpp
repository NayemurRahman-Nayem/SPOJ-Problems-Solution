// Bismillahir Rahmanir Rahim
 
 
#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
using u64 = uint64_t;
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
#define pb push_back
#define el << '\n' ;
#define all(a) (a).begin(),(a).end()
#define allr(a) (a).begin(),(a).end()
#define F first
#define S second
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds ;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
#define pb push_back
#define PI 3.14159265358979323
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define fastIO	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0) ;
ull bin_expo(ull base, ull pow, ull m) {
    if (pow == 0) return 1;ull ret = bin_expo(base, pow / 2, m) % m ;
    if (pow & 1) return (ret % m * ret % m * base % m) % m;else return (ret % m * ret % m) % m ; }
ll mod_add(ll a, ll b, ll m) { return ((a % m) + (b % m)) % m ; }
ll mod_sub(ll a, ll b, ll m) { return (a-b+m)%m ; }
ll mod_mul(ll a, ll b, ll m) { return ((a % m) * (b % m)) % m ; }
ll mod_div(ll a, ll b, ll m) { return ((a % m) * bin_expo(b, m - 2, m)) % m ; }
ll aModB(ll a , ll b) { if(a<0 ) { return ((a+(abs(a)/b)*b)+b)%b ; } else { return a%b; } }
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b) ; }
int dx[] = {0, 0, +1, -1, +1, -1, -1, +1} ;
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1} ;
const ll infLL = 4e18 + 123 ;
const ll inf = 1e12 + 7 ;
const ll mod = 1e9 + 7 ;
const ll mod2 = 998244353 ;
const ll mx = 4e7 + 10 ;
ll LOG = 21 ; 
 
// ---------------------------------------------------------------------------------------------------------------------
 
bool vis[mx] ; 
vl prime ; 
void sieve() {

    for(ll i=2;i<mx;i++) {
        if(vis[i]==0) {
            for(ll j=i*i;j<mx;j+=i) {
                vis[j] = 1 ;
            }
        }
    }
    prime.pb(2) ; 
    for(ll i=3;i<mx;i+=2) {
        if(vis[i]==0) {
            prime.pb(i) ; 
        }
    }
}

vector<pair<ll,ll>> primefact(ll n) {
    vector<pair<ll,ll>> fact ; 
    for(auto it:prime) {
        if(it*it>n) {
            break ; 
        }
        int cnt = 0; 
        while(n%it==0) {
            cnt ++ ; 
            n/=it ; 
        }
        if(cnt) {
            fact.pb({it,cnt}) ; 
        }
    }
    if(n>1) {
        fact.pb({n,1}) ; 
    }
    return fact ; 
}
 
void solution(ll n) {
    
    vector<pair<ll,ll>> ans = primefact(n) ; 
    for(auto it:ans) {
        cout << it.first << "^" << it.second << " " ; 
    }
    cout << endl ; 
}             
 
int main() { 
    fastIO ;
    #ifndef ONLINE_JUDGE
    file() ;
    #endif
    sieve() ; 
    int t = 0 ; 
    int cs = 1 ;
    ll n ; 
    while(cin >> n) {
        if(n==0) {
            break ; 
        }
        solution(n) ; 
    }
    return 0 ;
} 
