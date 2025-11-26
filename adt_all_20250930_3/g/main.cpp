#if __has_include(<yoniha/all.h>)
#include <yoniha/all.h>
using namespace atcoder;
#else
#include <bits/stdc++.h>
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif
#endif
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = (int)((n) - 1); i >= 0; i--)
template <typename T> bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template <typename T> bool chmin(T &a,const T &b){if(a>b){a=b;return true;}return false;}

// using mint = modint;

signed main(){
  int n, m; cin >> n >> m;
  vector<deque<int>> a(m);
  rep(i, m){
    int k; cin >> k;
    while(k--){
      int ai; cin >> ai; ai--;
      a.at(i).emplace_back(ai);
    }
  }
  deque<int> possible;
  vector<vector<int>> index(n);
  rep(i, m){
    int val = a.at(i).front();
    index.at(val).emplace_back(i);
    if(index.at(val).size() == 2) possible.emplace_back(val);
  }
  rep(i, n){
    if(possible.empty()){
      cout << "No" << '\n';
      return 0;
    }
    int target = possible.front(); possible.pop_front();
    for(auto& i : index.at(target)){
      a.at(i).pop_front();
      if(!a.at(i).empty()){
        int val = a.at(i).front();
        index.at(val).emplace_back(i);
        if(index.at(val).size() == 2) possible.emplace_back(val);
      }
    }
  }
  cout << "Yes" << '\n';
}
