// Bismillahir Rahmanir Rahim
 
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
typedef pair
<ll, ll> pll ;
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
const ll mx = 1e5 + 10 ;
ll LOG = 21 ; 

// Nayemur Rahman Nayem  
// ------------------------------------------------------------------------------------------------------------------

int dp[10][55][55][2] ; 
set<int>st = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59 } ; 


int solve(int index , int oddsum , int evensum , int fixed , string &s) {
    if(index==s.size()) {
        int diff = evensum - oddsum ; 
        if(s.size()&1) {
            diff = oddsum - evensum ; 
        }        
        if(diff<0) {
            return 0 ; 
        }
        if(st.find(diff)!=st.end()) {
            return 1 ; 
        }   
        else {
            return 0 ; 
        }
    }
    if(dp[index][oddsum][evensum][fixed]!=-1)  {
        return dp[index][oddsum][evensum][fixed] ; 
    }
    int res = 0 ; 
    if(fixed==1) {
        int val = s[index] - '0' ;
        for(int i=0;i<=val;i++) {
            int x , y ; 
            x = oddsum ; 
            y = evensum ; 
            if(index&1) {
                x += i ; 
            }
            else {
                y += i ; 
            }
            if(i==val) {
                res += solve(index+1,x,y,1,s) ; 
            }   
            else {
                res += solve(index+1,x,y,0,s) ; 
            }
        }
    }
    else {
        for(int i=0;i<10;i++) {
            int x , y ; 
            x = oddsum ; 
            y = evensum ; 
            if(index&1) {
                x += i ; 
            }
            else {
                y += i ; 
            }
            res += solve(index+1,x,y,0,s) ; 
        }   
    }
    return dp[index][oddsum][evensum][fixed] = res ; 
}

void solution(int cs) {
    ll a , b ; 
    cin >> a >> b ; 
    memset(dp,-1,sizeof(dp)) ; 
    string s = to_string(b) ; 
    ll up = solve(0,0,0,1,s) ; 
    if(a>0) --a ;  
    s = to_string(a) ;  
    memset(dp,-1,sizeof(dp)) ; 
    ll down = solve(0,0,0,1,s) ;    
    cout << up - down el ;  
} 

int main() { 
    fastIO ; 
    #ifndef ONLINE_JUDGE 
    file() ; 
    #endif 
    int cs = 1 ; 
    cin >> cs ;  
    for(ll i=1;i<=cs;i++) solution(i) ; 
    return 0 ; 
} 
