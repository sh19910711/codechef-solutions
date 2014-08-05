#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits>
using namespace std;

typedef long long Int;
typedef pair<Int, Int> Node; // rem, customer_id
typedef priority_queue <Node, vector<Node>, greater<Node>> TableQueue;

const Int N_MAX = 200 + 11;
const Int M_MAX = 400 + 11;
const Int C_MAX = 400 + 11;

Int N;
Int M;
Int C[M_MAX];

void input() {
  cin >> N >> M;
  for ( int i = 0; i < M; ++ i ) {
    cin >> C[i];
  }
  for ( int i = 0; i < M; ++ i ) C[i] --;
}


TableQueue Q;
Int R[C_MAX]; // rem count
bool D[C_MAX]; // using

void init() {
  Q = TableQueue();
  fill(R, R + C_MAX, 0);
  fill(D, D + C_MAX, false);
}

Int solve() {
  Int res = 0;
  for ( int i = 0; i < M; ++ i ) R[C[i]] ++;
  for ( int i = 0; i < M; ++ i ) {
    const auto& c_id = C[i];
    if ( D[c_id] ) continue;
    D[c_id] = true;
    R[c_id] --;
    res ++;
    if ( Q.size() >= N ) {
      auto rm = Q.top();
      const auto& rm_c_id = rm.second;
      Q.pop();
      D[rm_c_id] = false;
    }
    Q.push(Node(R[c_id], c_id));
  }
  return res;
}

int main() {
  int tests;
  cin >> tests;
  for ( int i = 0; i < tests; ++ i ) {
    init();
    input();
    cout << solve() << endl;
  }
  return 0;
}
