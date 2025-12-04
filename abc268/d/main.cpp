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
  vector<string> s(n), t(m);
  for(auto&& si : s) cin >> si;
  for(auto&& ti : t) cin >> ti;

  // cout << "input ok" << endl;

  sort(all(s)); sort(all(t));

  int s_len_sum = 0; for(auto&& si : s) s_len_sum += si.size();
  vector space(0, vector<int>());
  for(int len = 3; len <= 16; len++){
    // 余ってるのはleft = len - s_len_sum - (n - 1)個
    // つまり、(n - 1)^leftを全探索すればよい
    int left = len - s_len_sum - (n - 1);
    int bit = 1; rep(i, left) bit *= (n - 1);
    // cout << bit << endl;
    rep(i, bit){
      vector<int> cur(n - 1, 1);
      int w = i;
      rep(j, left){
        cur.at(w % (n - 1))++;
        w /= n - 1;
      }
      if(reduce(all(cur)) + s_len_sum == len) space.emplace_back(cur);
    }
  }
  sort(all(space));
  space.erase(unique(all(space)), space.end());
  // cout << "space made" << endl;
  do{
    for(auto&& spacei : space){
      string ans;
      rep(i, n - 1) ans += s.at(i) + string(spacei.at(i), '_');
      ans += s.at(n - 1);
      if(!binary_search(all(t), ans)){
        cout << ans << '\n';
        return 0;
      }
    }
  }while(next_permutation(all(s)));
  cout << -1 << '\n';
}
