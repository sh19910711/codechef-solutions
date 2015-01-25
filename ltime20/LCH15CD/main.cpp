// @snippet <contest-base-simple#0.0.5:header.cpp>
/* default headers {{{ */
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <limits>
#include <cstdio>
#include <cmath>

#if __cplusplus >= 201103L
#include <memory>
#include <array>
#endif
/* }}} */
// @snippet <contest-base-simple#0.0.5:solution/template-typedef.cpp>
namespace solution {

  using namespace std;

  /* primitives {{{ */
  typedef long long Int;
  typedef long double Double;
  /* }}} */

}
// @snippet <contest-base-simple#0.0.5:solution/template-constants.cpp>
namespace solution {
  // const Int N = 1000000 + 11;

}
// @snippet <contest-base-simple#0.0.5:solution/template-storages.cpp>
namespace solution {

  struct Input {
    Int N;
    Int D;
  };

  struct Output {
    Int res;
  };

}
// @snippet <contest-base-simple#0.0.5:solution/solution-io.cpp>
namespace solution {

  struct SolutionIO {

    Input in;
    Output out;

    template <class Stream> bool input( Stream& s ) {
      if ( s >> in.N >> in.D ) {
        return true;
      }
      return false;
    }

    template <class Stream> bool output( Stream& s ) {
      return s << out.res << endl;
    }

  };

}
// @snippet <contest-base-simple#0.0.5:solution/solution.cpp>
namespace solution {

  struct Solution: SolutionIO {

    Solution() {}

    typedef array<Int, 11> IntArray;

    Int N;
    Int D;
    IntArray P;
    IntArray A;

    bool solve() {
      this->N = in.N;
      this->D = in.D;
      P[0] = 1;
      for ( int i = 1; i < 11; ++ i ) {
        P[i] = P[i] * D;
      }
      out.res = find_min();
      return true;
    }

    Int find_min() {
    }

    typedef vector<Int> IntVector;
    typedef pair<Int, IntVector> Node;
    typedef priority_queue<Node, vector<Node>, greater<Node>> Queue;
    typedef map<IntVector, Int> Map;

    Int xor_sum( const IntVector& v ) {
      Int res = 0;
      for ( auto& x : v ) {
        res ^= x;
      }
      return res;
    }

    Int add_sum( const IntVector& v ) {
      Int res = 0;
      for ( auto& x : v ) {
        res += x;
      }
      return res;
    }

    Int calc_cost( const IntVector& v ) {
      return xor_sum(v) * add_sum(v);
    }

    Int find_min_1( const Int& N, const Int& D ) {
      Int res = numeric_limits<Int>::max();
      Queue q;
      const IntVector spos(N, 0);
      const IntVector gpos(N, D - 1);
      Node s(0, spos);
      Map m;
      const Int dpos[2] = {-1, 1};

      m[spos] = 0;
      q.push(s);

      while ( ! q.empty() ) {
        const Node& cur = q.top();
        q.pop();

        const Int& cost = cur.first;
        IntVector pos = cur.second;

        if ( cost >= res ) continue;

        if ( pos == gpos ) {
          if ( cost < res ) {
            res = cost;
          }
          continue;
        }

        for ( int i = 0; i < N; ++ i ) {
          for ( int j = 0; j < 2; ++ j ) {
            pos[i] += dpos[j];
            if ( pos[i] >= 0 && pos[i] < D ) {
              Int ncost = cost + calc_cost(pos);
              if ( m.count(pos) ) {
                auto& memo = m[pos];
                if ( ncost < memo ) {
                  memo = ncost;
                  q.emplace(ncost, pos);
                }
              } else {
                m[pos] = ncost;
                q.emplace(ncost, pos);
              }
            }
            pos[i] -= dpos[j];
          }
        }
      }

      return res;
    }

    /* action methods {{{ */
    void before_action( const int& t_id ) {}

    void after_action( const int& t_id ) {}

    bool action( const int& t_id = -1 ) {
      before_action(t_id);
      bool res = input(std::cin) && solve() && output(std::cout);
      after_action(t_id);
      return res;
    }
    /* }}} */
  };

}
// @snippet <contest-base-simple#0.0.5:solution/runner-normal.cpp>
/* Runner Class {{{ */
namespace solution {

  struct Runner {
    static int run() {
      int q;
      if ( cin >> q ) {
        for ( int i = 0; i < q; ++ i ) {
          Solution* sol = new Solution;
          sol->action();
          delete sol;
        }
      }
      return 0;
    }
  };

}
/* }}} */
// @snippet <contest-base-simple#0.0.5:main_func.cpp>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  return solution::Runner::run();
}
// @snippet <contest-base-simple#0.0.5:main.cpp>

