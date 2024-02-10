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
const ll mx = 1e5 + 10 ;
ll LOG = 21 ;

// -----------------------------------------------------------------------------------------------------


vector<int> manacher_odd(string s) {
    int n = s.size() ;
    s = "$" + s + "^" ;
    vector<int> p(n + 2) ;
    int l = 1, r = 1 ;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)])) ;
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++ ;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i] ;
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1) ;
}

vector<int> manacher(string s) {
    string t ; 
    for(auto c: s) {
        t += string("#") + c ;
    }
    auto res = manacher_odd(t + "#") ;
    return vector<int>(begin(res) + 1, end(res) - 1) ;
}

void solution(int cs) {
    string s ; 
    cin >> s ; 
    vector<int> v = manacher(s) ; 
    int ans = 0 ; 
    for(auto i=0;i<v.size();i++) {
        if(i%2==0) {         // char 
            if(v[i]>2) {
                int val = v[i]/2 ; 
                ans += v[i]-val ;
            }
            else {
                ans ++ ; 
            }
        }
        else {               // # char 
            if(v[i]>1) {
                int val = v[i]/2 + (v[i]%2) ; 
                ans += v[i] - val ; 
            }
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
const ll mx = 1e5 + 10 ;
ll LOG = 21 ;

// -----------------------------------------------------------------------------------------------------


vector<int> manacher_odd(string s) {
    int n = s.size() ;
    s = "$" + s + "^" ;
    vector<int> p(n + 2) ;
    int l = 1, r = 1 ;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)])) ;
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++ ;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i] ;
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1) ;
}

vector<int> manacher(string s) {
    string t ; 
    for(auto c: s) {
        t += string("#") + c ;
    }
    auto res = manacher_odd(t + "#") ;
    return vector<int>(begin(res) + 1, end(res) - 1) ;
}

void solution(int cs) {
    string s ; 
    cin >> s ; 
    vector<int> v = manacher(s) ; 
    int ans = 0 ; 
    for(auto i=0;i<v.size();i++) {
        if(i%2==0) {         // char 
            if(v[i]>2) {
                int val = v[i]/2 ; 
                ans += v[i]-val ;
            }
            else {
                ans ++ ; 
            }
        }
        else {               // # char 
            if(v[i]>1) {
                int val = v[i]/2 + (v[i]%2) ; 
                ans += v[i] - val ; 
            }
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
