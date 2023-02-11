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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}


int main(){

    zahid();

    int cs = 1;
    int t; cin>>t;
    while(t--){
        string y = "Peaceful", n = "Fight";
        int a, b, c, k; cin>>a>>b>>c>>k;
        if(a == b && b == c) cout<< "Case " << cs << ": " << y << '\n';
        else{
            int cnt = 0;
            if(a >= k) cnt++; if(b >= k) cnt++; if(c >= k) cnt++;
          
            if((a + b + c) % 3 == 0 && cnt >= 2){
                if(a % k == b % k && b % k == c % k){
                    if(((a/k) + (b/k) + (c/k)) % 3 == 0) cout<< "Case " << cs << ": " << y << '\n';
                    else cout<< "Case " << cs << ": " << n << '\n';
                }
                else cout<< "Case " << cs << ": " << n << '\n';
            }
            else cout<< "Case " << cs << ": " << n << '\n';
        }
        cs++;
    }
}
