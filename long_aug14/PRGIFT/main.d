import std.stdio;
import std.string;
import std.array;
import std.math;

immutable long N_MAX = 50 + 1;
immutable string YES = "YES";
immutable string NO = "NO";

// Solution {{{
struct Solution {
  int N;
  int K;
  auto A = new long [N_MAX];

  bool input(T)(T s) {
    if ( readf(" %s", &N) && readf(" %s", &K) ) {
      A.length = N;
      for ( int i = 0; i < N; ++ i ) {
        readf(" %s", &A[i]);
      }
      return true;
    }
    return false;
  }

  bool ok;

  void output() {
    if ( ok ) {
      writeln(YES);
    } else {
      writeln(NO);
    }
  }

  void run() {
    int tests;
    readf(" %s", &tests);
    for ( int i = 0; i < tests; ++ i ) {
      input(stdin);
      init();
      solve();
      output();
    }
  }

  void init() {
    
  }
  
  void solve() {
    ok = is_ok(N, K, A);
  }

  static int count_even(R)( R r ) {
    int res = 0;
    for ( ; ! r.empty; r.popFront() ) {
      if ( r.front % 2 == 0 ) res ++;
    }
    return res;
  }

  unittest {
    {
      assert(count_even([1, 2, 3]) == 1);
      assert(count_even([1]) == 0);
      assert(count_even([1, 2, 2]) == 2);
      assert(count_even([2, 2, 1]) == 2);
    }
  }

  bool is_ok( long N, long K, long[] A ) {
    return count_even(A) >= K;
  }
}
// }}}

// main() {{{
Solution s;
void main() {
  s.run();
}
// }}}
