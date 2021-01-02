#include <bits/stdc++.h>
#include <time.h>
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll>  P;
//vector<vector<ll> >v;
const int maxn = 2e6 + 5000;
ll  n,m;
ll a[maxn];
int vis[maxn];
int xx[4] = {1,-1,1,-1};
int yy[4] = {-1,1,1,-1};
priority_queue<int,vector<int>,greater<int> >q;
ll ans ;
ll f[900000] ;
int main() {
    while(cin >> n) {
        set<int>s;
        memset(f,0,sizeof(f));
        ll Max = 0;
        for(int i = 1; i <= n; i++) cin >> a[i],Max = max(a[i],Max),s.insert(a[i]);
        if(a[1] <= a[n]) {
            cout << -1 << endl;
            continue;
        }
        vector<int>v;
        for(auto d:s) {
            if(d > a[n] && d < a[1]) v.push_back(d);
        }
        reverse(v.begin(),v.end());
        f[a[1] ^ a[n]] = 1;
        for(int i = 0; i < v.size(); i++) {
            for(int j = 0; j  <= 8000; j++) {
                f[j] |= f[v[i] ^ j];
            }
//            f[i] = max(f[i - 1] ^ v[i],f[i - 1]);
        }
        for(int i = 8000; i >= 0; i--) {
            if(f[i]) {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}