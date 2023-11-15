// Bismillahir Rahmanir Rahim


#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef unsigned long long ull ;
typedef vector<int> vi ;
typedef vector<ll> vl ;
typedef vector<vi> vvi ;
typedef vector<vl> vvl ;
using u64 = unsigned long long ; 
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
ll aModB(ll a , ll b) { if(a<0 ) { return ((a+(abs(a)/b)*b)+b)%b ; } else { return a%b; } }
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b) ; }
int dx[] = {0, 0, +1, -1, +1, -1, -1, +1} ;
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1} ;
const ll infLL = 4e18 + 123 ;
const ll inf = 1e12 + 7 ;
const ll mod = 1e9 + 7 ;
const ll mod2 = 998244353 ;
const ll mx = 3e4 + 10 ;
ll LOG = 21 ; 

// ---------------------------------------------------------------------------------------------------------------------

ll a[mx] , n , m ;

struct Node {
    vi v ; 
} mergeSortTree[mx * 4];

Node Operation(Node x , Node y) {        
    int i = 0 , j = 0 ;
    Node ans ;  
    while(i<x.v.size() and j<y.v.size()) {
        if(x.v[i]<y.v[j]) {
            ans.v.pb(x.v[i]) ; 
            i ++ ; 
        }
        else {
            ans.v.pb(y.v[j]) ; 
            j++ ; 
        }
    }
    while(i<x.v.size()) {
        ans.v.pb(x.v[i]) ; 
        i++ ; 
    }
    while(j<y.v.size()) {
        ans.v.pb(y.v[j]) ; 
        j++ ; 
    }
    return ans ; 
}

void build(int node , int start , int end) {
    if(start==end) {
        mergeSortTree[node].v.push_back(a[end])  ;
        return ;
    }
    int mid = (start+end) / 2 ;
    int left = node*2 ;
    int right = node*2 + 1 ;
    build(left,start,mid) ;
    build(right,mid+1,end) ;
    mergeSortTree[node] = Operation(mergeSortTree[left],mergeSortTree[right]) ; 
}
ll query(int node, int start, int end , int l,  int r , int k )
{
    if (l > end || r < start) {
        return 0;
    }
    if (start >= l and end <= r) {
        return mergeSortTree[node].v.size() - (upper_bound(mergeSortTree[node].v.begin(),mergeSortTree[node].v.end(),k)-mergeSortTree[node].v.begin()) ; 
    } 
    int mid = (start+end) / 2 ;
    int left = node*2 ;
    int right = node*2 + 1 ;
    ll p1 = query(left, start , mid, l , r , k ); 
    ll p2 = query(right, mid + 1, end , l , r , k );
    return p1+p2 ; 
}

void solution(int cs) {

    cin >> n ; 
    for(int i=1;i<=n;i++) {
        cin >> a[i] ; 
    }
    build(1,1,n) ; 
    cin >> m ; 
    for(int i=1;i<=m;i++) {
        int l , r , k ; 
        cin >> l >> r >> k ; 
        cout << query(1,1,n,l,r,k) el ; 
    }
}              
int main() { 
    fastIO ;
    #ifndef ONLINE_JUDGE
    file() ;
    #endif
    int t = 0 ; 
    int cs = 1 ;
    //cin >> cs ;  
    for(ll i=1;i<=cs;i++) solution(i) ; 
    return 0 ;
}
