// Problem link: https://algo.codemarshal.org/contests/icpc-dhaka-22-preli-mock/problems/C
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
#include <cmath>
#include <climits>
#include <sstream>
#include <string>

using namespace std;

#define ll long long int

#define pii pair<int, int>
#define pli pair<ll, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define psi pair<string, int>
#define psl pair<string, ll>
#define piii pair<pair<int, int>, int>
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define vvb vector<vector<bool>>
#define vs vector<string>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<ll, ll>>
#define vpli vector<pair<ll, int>>
#define vpil vector<pair<int, ll>>
#define vvpii vector<vector<pair<int, int>>>
#define vvpll vector<vector<pair<ll, ll>>>
#define vvpli vector<vector<pair<ll, int>>>
#define vvpil vector<vector<pair<int, ll>>>
#define si stack<int>
#define sll stack<ll>
#define qi queue<int>
#define qll queue<ll>
#define pb push_back
#define pf push_front
#define ff first
#define ss second

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
    
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vi a(n+1), pens(n+1, 0);
        vvi al(n+1);
        for(int i=1; i<=n; i++){
            pens[i] = i;
            al[i].pb(i);
        }
        for(int i=1; i<=n; i++){
            cin>>a[i];
        }
        int q; cin>>q;
        while(q--){
            int qt; cin>>qt;
            if(qt == 1){
                int x, y; cin>>x>>y;
                if(a[x]!=0 && a[y]!=0){
                    if(a[x] > a[y]){
                        a[x] += a[y];
                        a[y] = 0;
                        for(int j=0; j<al[y].size(); j++){
                            al[x].pb(al[y][j]);
                            pens[al[y][j]] = x;
                        }
                        al[y].clear();
                    }
                    else if(a[x] < a[y]){
                        a[y] += a[x];
                        a[x] = 0;
                        for(int j=0; j<al[x].size(); j++){
                            al[y].pb(al[x][j]);
                            pens[al[x][j]] = y;
                        }
                        al[x].clear();
                    }
                }
            }
            else if(qt == 2){
                int x; cin>>x;
                cout<< al[x].size() << '\n';
            }
            else if(qt == 3){
                int x; cin>>x;
                cout<< pens[x] << '\n';
            }
        }
    }
}
