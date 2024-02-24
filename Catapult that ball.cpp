#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef vector<int> vi ;
typedef vector<ll> vl ;
using u64 = unsigned long long ;
using uint64 = unsigned long long ;
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
ll bin_expo(ll base, ll pow, ll m) {
    if (pow == 0) return 1;ll ret = bin_expo(base, pow / 2, m) % m ;
    if (pow & 1) return (ret % m * ret % m * base % m) % m;else return (ret % m * ret % m) % m ; }
ll mod_add(ll a, ll b, ll m) { return ((a % m) + (b % m)) % m ; }
ll mod_sub(ll a, ll b, ll m) { return (a-b+m)%m ; }
ll mod_mul(ll a, ll b, ll m) { return ((a % m) * (b % m)) % m ; }
ll mod_div(ll a, ll b, ll m) { return ((a % m) * bin_expo(b, m - 2, m)) % m ; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a ; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b) ; }
ll NEGMOD(ll a , ll m) { return ((a%m)+m)%m ; }
int dx[] = {0, 0, +1, -1, +1, -1, -1, +1} ;
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1} ;
const ll infLL = 4e18 + 123 ;
const ll inf = 1e12 + 7 ;
const ll mod = 1e9 + 7 ;
const ll mod2 = 998244353 ;
const ll mx = 3e5 + 10 ;
const int LOG = 21 ;

// -----------------------------------------------------------------------------------------------------


ll spt[mx][LOG] ;
ll lg[mx] , a[mx] ;

ll query(ll l, ll r) {
    if(l>=r) return a[l] ; 
    ll length = r - l + 1 ;
    ll k = lg[length] ;
    return max(spt[l][k],spt[r-(1<<k)+1][k]) ;
}

void solution(int cs) {
    ll n , q ;
    cin >> n >> q ;
    lg[1] = 0 ;
    for(ll i=2;i<=n;i++) {
        lg[i] = lg[i/2] + 1 ;
    }
    for(ll i=1;i<=n;i++) {
        cin >> a[i] ;
        spt[i][0] = a[i] ;
    }
    for(ll k=1;k<=lg[n];k++) {
        for(ll i=1;i+(1<<k)-1<=n;i++) {
            spt[i][k] = max(spt[i][k-1],spt[i+(1<<(k-1))][k-1]) ;
        }
    }
    ll ans = 0 ; 
    for(ll i=0;i<q;i++) {
        ll l , r ;
        cin >> l >> r ;
        if(l>r) {
            swap(l,r) ; 
        }
        if(r-l<=1) {
            ans ++ ; 
            continue ; 
        }
        ll m = query(l+1,r-1) ;
        if(m<=a[l]) {
            ans ++ ; 
        }
    }
    cout << ans el ; 
}

int main() {
    fastIO ;
    #ifndef ONLINE_JUDGE
    file() ;
    #endif
    int cs = 1 ;
    //cin >> cs ;
    for(ll i=1;i<=cs;i++) solution(i) ;
    return 0 ;
}
