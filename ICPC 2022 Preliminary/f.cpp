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


int main(){
    
    map<string, int> blood, year;

    blood["A+"] = 0; blood["A-"] = 0; blood["AB+"] = 0; blood["AB-"] = 0;
    blood["B+"] = 0; blood["B-"] = 0; blood["O+"] = 0; blood["O-"] = 0;
    
    map<string, int> cnt;
    vector<pair<pair<string, string>, pair<string, string>>> v;

    int n; cin>>n;
    while(n--){
        getchar();
        string s; getline(cin, s);
        string date = "", mail = "", dob = "", bg = "";
        int curr = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == ' '){
                curr++;
                continue;
            }
            if(curr == 0){
                if(s[i] != '#' && s[i] != ':' && s[i] != '/') date += s[i];
            }
            else if(curr == 1){
                mail += s[i];
            }
            else if(curr == 2){
                i += 6;
                dob += s.substr(i, 4);
                i += 3;
            }
            else if(curr == 3){
                bg += s[i];
            }
        }
        cnt[mail]++;
        v.pb({{mail, date}, {dob, bg}});
    }
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++){
        string mail = v[i].ff.ff;
        i = i + cnt[mail] - 1;
        blood[v[i].ss.ss]++;
        year[v[i].ss.ff]++;
    }
    for(auto it : blood) cout<< it.ff << " " << it.ss << '\n';
    for(auto it : year) cout<< it.ff << " " << it.ss << '\n';
}
