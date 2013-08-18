
// @snippet<sh19910711/contest:unit-tests.cpp>
#define __MY_UNIT_TEST__
#include "./main.cpp"
#include <gtest/gtest.h>

/*
 *  # Example
 *
 *  int add( int x, int y ) {
 *    return x + y;
 *  }
 *
 *  TEST(AddTest, Test1) {
 *    ASSERT_EQ(2, add(1, 1));
 *  }
 */

namespace test {
  using namespace solution;
  Solver solver;

  TEST(sample_input, 1) {
    ASSERT_EQ(solver.calc_visited_cells(4, 4, 3, 2, 3, 4), 3);
  }
  TEST(sample_input, 2) {
    ASSERT_EQ(solver.calc_visited_cells(4, 4, 3, 2, 4, 4), 4);
  }
  TEST(sample_input, 3) {
    ASSERT_EQ(solver.calc_visited_cells(4, 4, 3, 2, 2, 3), 11);
  }
  TEST(sample_input, 4) {
    ASSERT_EQ(solver.calc_visited_cells(2, 3, 1, 1, 1, 3), 3);  
  }
  TEST(sample_input, 5) {
    ASSERT_EQ(solver.calc_visited_cells(2, 3, 1, 1, 1, 1), 1); 
  }

  TEST(input, test1) {
    /*
       .....
       VVVVT
       VVSVV
       VVVVV
       VVVVV
       */
    ASSERT_EQ(solver.calc_visited_cells(5, 5, 3, 3, 2, 5), 20);
  }

  TEST(input, test1_2) {
    /*
       .....
       VVVT.
       VVSVV
       VVVVV
       VVVVV
       */
    ASSERT_EQ(solver.calc_visited_cells(5, 5, 3, 3, 2, 4), 19);
  }

  TEST(input, test2) {
    /*
       .....
       .VVVT
       VVSVV
       VVVVV
       */
    ASSERT_EQ(solver.calc_visited_cells(4, 5, 3, 3, 2, 5), 14);
  }

  TEST(input, test3) {
    /*
       VVVVV
       TVVVV
       VVSVV
       VVVVV
       */
    ASSERT_EQ(solver.calc_visited_cells(4, 5, 3, 3, 2, 1), 20);
  }

  TEST(input, test4) {
    /*
       TVVVV
       VVSVV
       VVVVV
       */
    ASSERT_EQ(solver.calc_visited_cells(3, 5, 2, 3, 1, 1), 15);
  }

  TEST(input, test5) {
    /*
       .....
       VT.SV
       VVVVV
       VVVVV
       VVVVV
       */
    ASSERT_EQ(solver.calc_visited_cells(5, 5, 2, 4, 2, 2), 19);
  }

  TEST(input, test6) {
    /* T...S */
    ASSERT_EQ(solver.calc_visited_cells(1, 5, 1, 5, 1, 1), 5);
  }

  TEST(input, test7) {
    /* S...T */
    ASSERT_EQ(solver.calc_visited_cells(1, 5, 1, 1, 1, 5), 5);
  }

  TEST(input, test6_1) {
    /* .TVSV */
    ASSERT_EQ(solver.calc_visited_cells(1, 5, 1, 4, 1, 2), 4);
  }

  TEST(input, test7_1) {
    /* .SVT. */
    ASSERT_EQ(solver.calc_visited_cells(1, 5, 1, 2, 1, 4), 3);
  }

  TEST(input, test8) {
    /*
     * T
     * .
     * .
     * .
     * S
     */
    ASSERT_EQ(solver.calc_visited_cells(5, 1, 5, 1, 1, 1), 5);
  }

  TEST(input, test9) {
    /*
     * S 
     * .
     * .
     * .
     * T
     */
    ASSERT_EQ(solver.calc_visited_cells(5, 1, 1, 1, 5, 1), 5);
  }

  TEST(input, test8_2) {
    /*
     * . 
     * T
     * V
     * S
     * V 
     */
    ASSERT_EQ(solver.calc_visited_cells(5, 1, 4, 1, 2, 1), 4);
  }

  TEST(input, test9_2) {
    /*
     * . 
     * S
     * V 
     * T
     * .
     */
    ASSERT_EQ(solver.calc_visited_cells(5, 1, 2, 1, 4, 1), 3);
  }

  TEST(input, sampe_input_2_2) {
    /*
       ........
       ..SVVVVV
       .......T
       ........
       */
    ASSERT_EQ(solver.calc_visited_cells(4, 8, 2, 3, 3, 8), 7);
  }

  TEST(input, sampe_input_2_3) {
    /*
       ........
       ..SVVVVV
       .......V
       .......V
       .......V
       .......T
       ........
       */
    ASSERT_EQ(solver.calc_visited_cells(7, 8, 2, 3, 6, 8), 10);
  }

  TEST(input, sampe_input_2_4) {
    /*
       ........
       ..SVVVVV
       .......V
       .......V
       .......V
       .......V
       .......T
       */
    ASSERT_EQ(solver.calc_visited_cells(7, 8, 2, 3, 7, 8), 11);
  }

  TEST(input, test_10) {
    /*
       ........
       ..SVVVVV
       .......V
       .......V
       .......V
       .......V
       .....TVV
       */
    ASSERT_EQ(solver.calc_visited_cells(7, 8, 2, 3, 7, 6), 13);
  }

  TEST(input, test_11) {
    /*
       ........
       ..SVVVVV
       .......V
       .......V
       .......V
       T......V
       VVVVVVVV
       */
    ASSERT_EQ(solver.calc_visited_cells(7, 8, 2, 3, 6, 1), 19);
  }

  TEST(input, test_12) {
    /*
       ........
       ..SVVVVV
       .......V
       .......V
       TVVVVVVV
       VVVVVVVV
       VVVVVVVV
       */
    ASSERT_EQ(solver.calc_visited_cells(7, 8, 2, 3, 5, 1), 32);
  }

  TEST(input, test_12_1) {
    /*
       ........
       ..SVVVVV
       .......V
       .......V
       ...TVVVV
       VVVVVVVV
       VVVVVVVV
       */
    ASSERT_EQ(solver.calc_visited_cells(7, 8, 2, 3, 5, 4), 29);
  }

  TEST(input, test_12_2) {
    /*
       ........
       ..SVVVVV
       .......V
       T......V
       VVVVVVVV
       VVVVVVVV
       VVVVVVVV
       */
    ASSERT_EQ(solver.calc_visited_cells(7, 8, 2, 3, 4, 1), 33);
  }

  TEST(input, test_12_3) {
    /*
       ........
       ..SVVVVV
       .......V
       VVVT...V
       VVVVVVVV
       VVVVVVVV
       VVVVVVVV
       */
    ASSERT_EQ(solver.calc_visited_cells(7, 8, 2, 3, 4, 4), 36);
  }

  TEST(input, test_12_4) {
    /*
       ........
       T.SVVVVV
       VVVVVVVV
       VVVVVVVV
       VVVVVVVV
       VVVVVVVV
       VVVVVVVV
       */
    ASSERT_EQ(solver.calc_visited_cells(7, 8, 2, 3, 2, 1), 40 + 7);
  }

  TEST(input, test_13_bottom) {
    /*
       .....
       .SVT.
       */
    ASSERT_EQ(solver.calc_visited_cells(2, 5, 2, 2, 2, 4), 3);
  }

  TEST(input, test_13_bottom_2) {
    /*
       ..VVV
       .TVSV
       */
    ASSERT_EQ(solver.calc_visited_cells(2, 5, 2, 4, 2, 2), 7);
  }

  TEST(input, test_14_2x2_1) {
    /*
       SV
       .T
       */
    ASSERT_EQ(solver.calc_visited_cells(2, 2, 1, 1, 2, 2), 3);
  }

  TEST(input, test_14_2x2_2) {
    /*
       .S
       .T
       */
    ASSERT_EQ(solver.calc_visited_cells(2, 2, 1, 2, 2, 2), 2);
  }

  TEST(input, test_14_2x2_3) {
    /*
       ..
       ST
       */
    ASSERT_EQ(solver.calc_visited_cells(2, 2, 2, 1, 2, 2), 2);
  }

  TEST(input, test_14_2x2_4) {
    /*
       T.
       VS
       */
    ASSERT_EQ(solver.calc_visited_cells(2, 2, 2, 2, 1, 1), 3);
  }

  TEST(input, test_14_2x2_5) {
    /*
       VT
       VS
       */
    ASSERT_EQ(solver.calc_visited_cells(2, 2, 2, 2, 1, 2), 4);
  }

  TEST(input, test_14_2x2_6) {
    /*
       ..
       TS
       */
    ASSERT_EQ(solver.calc_visited_cells(2, 2, 2, 2, 2, 1), 2);
  }

  TEST(input, test_15) {
    /*
       ...
       ..T
       SVV
       */
    ASSERT_EQ(solver.calc_visited_cells(3, 3, 3, 1, 2, 3), 4);
  }

  TEST(input, test_16_3x3_1) {
    /*
       ...
       VVT
       VVS
       */
    ASSERT_EQ(solver.calc_visited_cells(3, 3, 3, 3, 2, 3), 6);
  }

  TEST(input, test_16_3x3_2) {
    /*
       ..T
       VVV
       VVS
       */
    ASSERT_EQ(solver.calc_visited_cells(3, 3, 3, 3, 1, 3), 7);
  }

  TEST(input, test_16_3x3_3) {
    /*
       VVT
       VVV
       VSV
       */
    ASSERT_EQ(solver.calc_visited_cells(3, 3, 3, 2, 1, 3), 9);
  }

  TEST(input, test_17_4x4_1) {
    /*
       ...T
       VVVV
       VVVV
       SVVV
       */
    ASSERT_EQ(solver.calc_visited_cells(4, 4, 4, 1, 1, 4), 13);
  }

  TEST(input, test_17_4x4_2) {
    /*
       ...T
       VVVV
       VVVV
       VSVV
       */
    ASSERT_EQ(solver.calc_visited_cells(4, 4, 4, 2, 1, 4), 13);
  }

  TEST(input, test_17_4x4_3) {
    /*
       ...T
       VVVV
       VVVV
       VVSV
       */
    ASSERT_EQ(solver.calc_visited_cells(4, 4, 4, 3, 1, 4), 13);
  }

  TEST(input, test_17_4x4_4) {
    /*
       VVVT
       VVVV
       VVVV
       VVVS
       */
    ASSERT_EQ(solver.calc_visited_cells(4, 4, 4, 4, 1, 4), 16);
  }

  TEST(input, test_17_4x4_5) {
    /*
       VT..
       VVVV
       VVVV
       VVVS
       */
    ASSERT_EQ(solver.calc_visited_cells(4, 4, 4, 4, 1, 2), 14);
  }

  TEST(input, test_18_5x5_1) {
    /*
     ..TVV
     VVVVV
     VVVVV
     VVVVV
     VVVVS
    */
    ASSERT_EQ(solver.calc_visited_cells(5, 5, 5, 5, 1, 3), 23);
  }

  TEST(input, test_18_5x5_2) {
    /*
     VT...
     VVVVV
     VVVVV
     VVVVV
     VVSVV
    */
    ASSERT_EQ(solver.calc_visited_cells(5, 5, 5, 3, 1, 2), 22);
  }

  TEST(input, test_18_5x5_3) {
    /*
     VVVT.
     VVVVV
     VVVVV
     VVVVV
     VVSVV
    */
    ASSERT_EQ(solver.calc_visited_cells(5, 5, 5, 3, 1, 4), 24);
  }

  TEST(input, test_18_5x5_4) {
    /*
     .TVVV
     VVVVV
     VVVVV
     VVVVV
     VVVVS
    */
    ASSERT_EQ(solver.calc_visited_cells(5, 5, 5, 5, 1, 2), 24);
  }

  TEST(input, test_18_5x5_5) {
    /*
     ...TV
     VVVVV
     VVVVV
     VVVVV
     VVVVS
    */
    ASSERT_EQ(solver.calc_visited_cells(5, 5, 5, 5, 1, 4), 22);
  }

  TEST(input, test_19_6x6_1) {
    /*
     VVVT..
     ......
     ......
     ......
     ......
     .....S
     */
    ASSERT_EQ(solver.calc_visited_cells(6, 6, 6, 6, 1, 4), 34);
  }

  TEST(input, test_19_6x6_2) {
    /*
     ...TVV
     ......
     ......
     ......
     ......
     S.....
     */
    ASSERT_EQ(solver.calc_visited_cells(6, 6, 6, 1, 1, 4), 33);
  }

  TEST(input, test) {
    /*
       .....
       .....
       .....
       .....
       .....
       */
    ASSERT_EQ(0, 0);
  }
}

