
#include <assert.h>
#include <simd/types.h>
#include <iostream>

int main(int argc, char** argv) {
  using namespace SIMD;

  Float<4> f1;
  f1.set({1.f, 2.f, 3.f, 4.f});
  Float<4> f2 = f1;
  assert(all(f1 == f2));

  f1 = -f1;
  assert(!any(f1 == f2));

  Int<4> i1 = f1;
  assert(all(i1 == f1));

  Int<4> i2 = i1 << 1;
  assert(all(i2 == (i1 * 2)));
}