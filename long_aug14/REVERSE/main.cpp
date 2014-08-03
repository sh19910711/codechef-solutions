#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <set>
using namespace std;

typedef long long Int;
typedef pair<Int, Int> Edge;
typedef vector<Edge> EdgeVector;
typedef vector<Int> IntVector;
typedef set<Int> IntSet;
typedef pair<Int, Int> Node;
typedef vector<Node> NodeVector;
typedef priority_queue<Node, NodeVector, greater<Node>> NodeQueue;

const Int N_MAX = 100000 + 11;
const Int M_MAX = 100000 + 11;
const Int INF = numeric_limits<Int>::max();

Int N;
Int M;
Int U[M_MAX];
Int V[M_MAX];

template <class Func> void rep( int n, Func f ) {
  for ( int i = 0; i < n; ++ i ) f(i);
}

void input() {
  auto a = "test";
  if ( cin >> N >> M ) {
    rep(M, [&](int i) { cin >> U[i] >> V[i]; });
  }
}


EdgeVector G[N_MAX];
IntSet C[N_MAX];
NodeQueue Q;
Int D[N_MAX];

void init() {
  fill(G, G + N_MAX, EdgeVector());
  fill(C, C + N_MAX, IntSet());
  Q = NodeQueue();
  fill(D, D + N_MAX, INF);
}

Int find_min() {
  Int res = INF;
  Q.push(Node(0, 0));
  D[0] = 0;

  while ( ! Q.empty() ) {
    auto node = Q.top();
    Q.pop();

    const auto& steps = node.first;
    const auto& cur = node.second;

    if ( cur == N - 1 ) res = min(res, steps);

    for ( const auto& e : G[cur] ) {
      const auto& to = e.first;
      const auto& cost = e.second;
      Int next_cost = steps + cost;
      if ( next_cost >= D[to] ) continue;
      D[to] = next_cost;
      Q.push(Node(steps + cost, to));
    }
  }

  if ( res == INF ) return -1;
  return res;
}

Int solve() {
  rep(M, [&](int i){ G[U[i] - 1].push_back(Edge(V[i] - 1, 0)); });
  rep(M, [&](int i){ C[U[i] - 1].insert(V[i] - 1); });
  rep(M, [&](int i){ if ( ! C[V[i] - 1].count(U[i] - 1) ) G[V[i] - 1].push_back(Edge(U[i] - 1, 1)); });
  return find_min();
}

int main() {
  init();
  input();
  cout << solve() << endl;
  return 0;
}
