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

struct Rerooting {
    /* start 問題ごとに書き換え */
    struct DP {  // DP の型
        int sum, cnt;
        DP(int sum_, int cnt_) : sum(sum_), cnt(cnt_) {}
    };
    const DP identity = DP(0, 0);  // 単位元(末端の値は add_root(identity) になるので注意)
    function<DP(DP, DP)> merge = [](DP dp_cum, DP d) -> DP {
        return DP(dp_cum.sum + d.sum, dp_cum.cnt + d.cnt);
    };
    function<DP(DP)> add_root = [](DP d) -> DP {
        return DP(d.sum + d.cnt, d.cnt + 1);
    };
    /* end 問題ごとに書き換え */
    // グラフの定義
    struct Edge {
        int to;
    };
    using Graph = vector<vector<Edge>>;
    vector<vector<DP>> dp;  // dp[v][i]: vから出るi番目の有向辺に対応する部分木のDP
    vector<DP> ans;         // ans[v]: 頂点vを根とする木の答え
    Graph G;
    Rerooting(int N) : G(N) {
        dp.resize(N);
        ans.assign(N, identity);
    }
    void add_edge(int a, int b) {
        G[a].push_back({b});
    }
    void build() {
        dfs(0);            // 普通に木DP
        bfs(0, identity);  // 残りの部分木に対応するDPを計算
    }
    DP dfs(int v, int p = -1) {  // 頂点v, 親p
        DP dp_cum = identity;
        int deg = G[v].size();
        dp[v] = vector<DP>(deg, identity);
        for (int i = 0; i < deg; i++) {
            int u = G[v][i].to;
            if (u == p) continue;
            dp[v][i] = dfs(u, v);
            dp_cum = merge(dp_cum, dp[v][i]);
        }
        return add_root(dp_cum);
    }
    void bfs(int v, const DP& dp_p, int p = -1) {  // bfs だが、実装が楽なので中身は dfs になっている
        int deg = G[v].size();
        for (int i = 0; i < deg; i++) {  // 前のbfsで計算した有向辺に対応する部分木のDPを保存
            if (G[v][i].to == p) dp[v][i] = dp_p;
        }
        vector<DP> dp_l(deg + 1, identity), dp_r(deg + 1, identity);  // 累積merge
        for (int i = 0; i < deg; i++) {
            dp_l[i + 1] = merge(dp_l[i], dp[v][i]);
        }
        for (int i = deg - 1; i >= 0; i--) {
            dp_r[i] = merge(dp_r[i + 1], dp[v][i]);
        }
        ans[v] = add_root(dp_l[deg]);  // 頂点 v の答え
        for (int i = 0; i < deg; i++) {  // 一つ隣の頂点に対しても同様に計算
            int u = G[v][i].to;
            if (u == p) continue;
            bfs(u, add_root(merge(dp_l[i], dp_r[i + 1])), v);
        }
    }
};

signed main(){
  int n; cin >> n;
  Rerooting r(n);
  rep(i, n - 1){
    int u, v; cin >> u >> v; u--; v--;
    r.add_edge(u, v);
    r.add_edge(v, u);
  }
  r.build();
  for(auto ansi : r.ans) println("{}", ansi.sum);
}
