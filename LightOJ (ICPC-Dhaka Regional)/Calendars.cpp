// Problem link: https://lightoj.com/problem/calendars
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
#include <climits>

using namespace std;

#define ll long long int

#define pii pair<int, int>
#define pli pair<ll, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define psi pair<string, int>
#define psl pair<string, ll>
#define piii pair<pair<int, int>, int>
#define pipii pair<int, pair<int, int>>
#define pipll pair<int, pair<ll, ll>>
#define plpii pair<ll, pair<int, int>>
#define plpll pair<ll, pair<ll, ll>>
#define piipii pair<pair<int, int>, pair<int, int>>
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define vvb vector<vector<bool>>
#define vs vector<string>
#define vvvi vector<vector<vector<int>>>
#define vvvll vector<vector<vector<ll>>>
#define vvs vector<vector<string>>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<ll, ll>>
#define vpli vector<pair<ll, int>>
#define vpil vector<pair<int, ll>>
#define vpipii vector<pair<int, pair<int, int>>>
#define vpipll vector<pair<int, pair<ll, ll>>>
#define vvpii vector<vector<pair<int, int>>>
#define vvpll vector<vector<pair<ll, ll>>>
#define vplpii vector<pair<ll, pair<int, int>>>
#define vplpll vector<pair<ll, pair<ll, ll>>>
#define vvpil vector<vector<pair<int, ll>>>
#define pb push_back
#define pf push_front
#define ff first
#define ss second

const ll mod = 1e9 + 7;
//const ll mod = 998244353;
const double pi = acos(-1.0);
const double PI = 3.1415926535897;
const double eps = 1e-6;

void zahid(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();

    int n; cin >> n;
    vvll cal(n + 1), sum(n + 1);
    for(int i = 1; i <= n; i++){
        int m; cin >> m;
        cal[i].resize(m + 1, 0);
        sum[i].resize(m + 1, 0);
        for(int j = 1; j <= m; j++){
            cin >> cal[i][j];
            sum[i][j] = cal[i][j];
            sum[i][j] += sum[i][j - 1];
        }
    }
    int q; cin >> q;
    for(int i = 1; i <= q; i++){
        ll a, b, d, m, y;
        cin >> a >> b >> d >> m >> y;
        
        ll tot_days = sum[a][sum[a].size() - 1] * (y - 1);
        tot_days += sum[a][m - 1];
        tot_days += d;

        ll dd = 0, mm = 0, yy = 0;
        yy += tot_days / sum[b][sum[b].size() - 1];
        ll rem = tot_days % sum[b][sum[b].size() - 1];
        
        if(rem == 0){
            dd = sum[b][sum[b].size() - 1] - sum[b][sum[b].size() - 2];
            mm = sum[b].size() - 1;
        }
        else{
            yy++;
            int ind = -1;
            int lo = 0, hi = sum[b].size() - 1;
            while(lo <= hi){
                int m = (lo + hi) / 2;
                if(sum[b][m] < rem){
                    ind = m;
                    lo = m + 1;
                }
                else{
                    hi = m - 1;
                }
            }

            mm = ind + 1;
            dd = rem - sum[b][ind];
        }
        cout << "Query " << i << ": " << dd << " " << mm << " " << yy << '\n';
    }
}
