
#include <assert.h>
#include <simd/types.h>
#include <iostream>

int main(int argc, char** argv) {
  using namespace SIMD;

  for (unsigned int i = 0; i < 10000; ++i) {
    int a1 = rand();
    int b1 = rand();
    int c1 = rand();
    int d1 = rand();
    int a2 = rand();
    int b2 = rand();
    int c2 = rand();
    int d2 = rand();
    int a3, b3, c3, d3;
    int constant = rand();

    Int<4> i1, i2, i3, i4;

    i1.set({a1, b1, c1, d1});
    i2.set({a2, b2, c2, d2});

    #define TEST_BINARY_OPERATION(op) \
    i3.set({ \
      a1 op a2, \
      b1 op b2, \
      c1 op c2, \
      d1 op d2 \
    }); \
    assert(all((i1 op i2) == i3)); \
    i3.set({ \
      a1 op constant, \
      b1 op constant, \
      c1 op constant, \
      d1 op constant \
    }); \
    assert(all((i1 op constant) == i3)); \
    i3.set({ \
      constant op a1, \
      constant op b1, \
      constant op c1, \
      constant op d1 \
    }); \
    assert(all((constant op i1) == i3));

    #define TEST_UNARY_OPERATION(op) \
    i3.set({ \
      op a1, \
      op b1, \
      op c1, \
      op d1 \
    }); \
    assert(all((op i1) == i3));

    #define TEST_ASSIGMENT_OPERATION(op) \
    a3 = a1; \
    b3 = b1; \
    c3 = c1; \
    d3 = d1; \
    a3 op a2; \
    b3 op b2; \
    c3 op c2; \
    d3 op d2; \
    i4 = i1; \
    i4 op i2; \
    i3.set({a3, b3, c3, d3}); \
    assert(all(i3 == i4));

    TEST_UNARY_OPERATION(-)
    TEST_BINARY_OPERATION(+)
    TEST_BINARY_OPERATION(-)
    TEST_BINARY_OPERATION(*)
    TEST_BINARY_OPERATION(/)
    TEST_BINARY_OPERATION(%)
    TEST_BINARY_OPERATION(>)
    TEST_BINARY_OPERATION(<)
    TEST_BINARY_OPERATION(>=)
    TEST_BINARY_OPERATION(<=)
    TEST_BINARY_OPERATION(==)
    TEST_BINARY_OPERATION(!=)
    TEST_BINARY_OPERATION(<<)
    TEST_BINARY_OPERATION(>>)
    TEST_BINARY_OPERATION(&)
    TEST_UNARY_OPERATION(~)
    TEST_BINARY_OPERATION(|)
    TEST_UNARY_OPERATION(!)
    TEST_BINARY_OPERATION(&&)
    TEST_BINARY_OPERATION(||)
    TEST_ASSIGMENT_OPERATION(+=)
    TEST_ASSIGMENT_OPERATION(-=)
    TEST_ASSIGMENT_OPERATION(/=)
    TEST_ASSIGMENT_OPERATION(*=)
  }
}