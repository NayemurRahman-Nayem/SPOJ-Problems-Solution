//      Bismillah-ir-Rahman-ir-Rahim


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
typedef pair<float, float> pff ;
typedef pair<double, double> pdd ;
typedef pair<ll, ll> pll ;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds ;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
#define pb push_back
#define PI 3.14159265358979323
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define fastIO	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
ll bin_expo(ll base, ll pow, ll m)
{       if (pow == 0) return 1;
        ll ret = bin_expo(base, pow / 2, m) % m;
        if (pow & 1)return (ret % m * ret % m * base % m) % m;
        else return (ret % m * ret % m) % m;}
ll mod_add(ll a, ll b, ll m) { return ( ( a % m ) + ( b % m ) ) % m ; }
ll mod_sub(ll a, ll b, ll m) { return ( ( a % m ) - ( b % m ) ) % m ; }
ll mod_mul(ll a, ll b, ll m) { return ( ( a % m ) * ( b % m ) ) % m ; }
ll mod_div(ll a, ll b, ll m) { return ( ( a % m ) * bin_expo(b, m - 2, m) ) % m ; }
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int dx[] = {0, 0, +1, -1, +1, -1, -1, +1};
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1};
const ll infLL = 4e18 + 123 ;
const ll inf = 1e17 + 7 ;
const ll mod = 1e9 + 7 ;
const ll mod2 = 1e9 + 9 ;
const int mx = 1e6 + 123 ;
const double eps = 1e-7 ;


const int N = 200 ; 
ll a[N][N] , I[N][N]  ; 


void mul(ll A[][N] , ll B[][N] , ll dim)
{
        ll res[dim][dim] ; 
        for(int i=0;i<dim;i++)
        {
                for(int j=0;j<dim;j++)
                {
                        res[i][j] = 0 ; 
                        for(int k=0;k<dim;k++)
                        {
                                res[i][j] += (A[i][k]%mod * B[k][j]%mod)%mod ; 
                                res[i][j]%=mod ; 
                        }
                }
        }
        for(int i=0;i<dim;i++)
        {
                for(int j=0;j<dim;j++)
                {
                        A[i][j] = res[i][j] ; 
                }
        }
}



void power(ll A[][N] , ll dim , ll n)
{
        for(int i=0;i<dim;i++)
        {
                for(int j=0;j<dim;j++)
                {
                        if(i==j) I[i][j] = 1 ; 
                        else I[i][j] = 0 ; 
                }
        }
        while(n)
        {
                if(n&1)
                {
                        mul(I,A,dim) ; 
                        n-- ; 
                }
                else 
                {
                        mul(A,A,dim) ; 
                        n/=2 ; 
                }
        }
        for(int i=0;i<dim;i++)
        {
                for(int j=0;j<dim;j++)
                {
                        A[i][j] = I[i][j] ; 
                }
        }
}


void solution()
{
        ll dim , n ; 
        cin >> dim >> n ;
        for(int i=0;i<dim;i++)
        {
                for(int j=0;j<dim;j++)
                {
                        cin >> a[i][j] ; 
                }
        }
        power(a,dim,n) ; 
        for(int i=0;i<dim;i++)
        {
                for(int j=0;j<dim;j++)
                {
                        cout << a[i][j] << ' ' ; 
                }
                cout << endl ; 
        }
}       


int main()
{
        fastIO ;
        // file() ;
        int _ = 1; cin >> _ ;
        while (_--) solution() ;
        return 0 ;
}
