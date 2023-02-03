//      BISMILLAH-IR-RAHMAN-IR-RAHIM

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
#define el << '\n'
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
        if (pow == 0) return 1;
        ll ret = bin_expo(base, pow / 2, m) % m;
        if (pow & 1) return (ret % m * ret % m * base % m) % m;
        else return (ret % m * ret % m) % m;
}
ll mod_add(ll a, ll b, ll m) { return ((a % m) + (b % m)) % m; }
ll mod_sub(ll a, ll b, ll m) { return ((a % m) - (b % m)) % m; }
ll mod_mul(ll a, ll b, ll m) { return ((a % m) * (b % m)) % m; }
ll mod_div(ll a, ll b, ll m) { return ((a % m) * bin_expo(b, m - 2, m)) % m; }
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int dx[] = {0, 0, +1, -1, +1, -1, -1, +1};
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1};
const ll infLL = 4e18 + 123;
const ll inf = 1e17 + 7;
const ll mod = 1e9 + 7;
const ll mod2 = 1e9 + 9;
const int mx = 1e3 + 123;
const double eps = 1e-7;

// forever-striver


struct Node {

        Node * links[10] ;
        bool isend = false ;
        bool containsKey(int digit) {
                return (links[digit]!=NULL) ;
        }
        Node * get(int digit) {
                return links[digit] ;
        }
        void put(int digit , Node * node) {
                links[digit] = node ;
        }
        void setEnd() {
                isend = true ;
        }
        bool isEND() {
                return isend ;
        }
};

class Trie {
private:
        Node * root ;
public:
        Trie() {
                root = new Node() ;
        }
        bool insert(string s) {
                Node * node = root ;
                for(int i=0;i<s.size();i++) {
                        if(!node->containsKey(s[i]-'0')) {
                                node->put(s[i]-'0' , new Node()) ;
                        }
                        node = node->get(s[i]-'0') ;
                        if(node->isEND()) {
                                return false ;
                        }
                }
                node->setEnd() ;
                return true ;
        }
};

void solution() {

        int n;
        cin >> n ;
        Trie T ;
        vector<string>vs(n) ;
        for(int i=0;i<n;i++) {
                cin >> vs[i] ;
        }
        sort(vs.begin(),vs.end()) ;
        for(int i=0;i<n;i++) {
                if(!(T.insert(vs[i]))) {
                        cout << "NO" el ;
                        return ;
                }
        }
        cout << "YES" el ;
}

int main() {
        fastIO;
        // file() ;
        ll _ = 1; cin >> _;
        while (_--) solution();
        return 0;
}
