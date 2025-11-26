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
  int n; cin >> n;
  vector<int> a(n); for(auto&& ai : a) cin >> ai, ai--;
  deque<int> q;
  vector<bool> is(n, false);
  int ans = 0;
  for(int i = 0; i + 1 < n; i += 2){
    if(a.at(i) != a.at(i + 1)){
      while(!q.empty()){
        is.at(q.front()) = false;
        q.pop_front();
      }
      continue;
    }
    while(is.at(a.at(i))){
      is.at(q.front()) = false;
      q.pop_front();
    }
    is.at(a.at(i)) = true;
    q.emplace_back(a.at(i));
    
    chmax(ans, (int)q.size());
  }
  for(auto&& isi : is) isi = false;
  q.clear();
  for(int i = 1; i + 1 < n; i += 2){
    if(a.at(i) != a.at(i + 1)){
      while(!q.empty()){
        is.at(q.front()) = false;
        q.pop_front();
      }
      continue;
    }
    while(is.at(a.at(i))){
      is.at(q.front()) = false;
      q.pop_front();
    }
    is.at(a.at(i)) = true;
    q.emplace_back(a.at(i));
    
    chmax(ans, (int)q.size());
  }
  cout << ans * 2 << '\n';
}
