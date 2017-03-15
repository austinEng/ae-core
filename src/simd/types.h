
#pragma once

#include <initializer_list>
#include <algorithm>

namespace SIMD {
  template <typename T, unsigned int N>
  class Type {
    T vals[N];

    public:

    void set(const std::initializer_list<T> &init) {
      std::copy(init.begin(), init.end(), vals);
    }

    template <typename T2>
    operator Type<T2, N>() const {
       Type<T2, N> a;
       for (unsigned int i = 0; i < N; ++i) {
         a[i] = vals[i];
       }
       return a;
    }

    T operator[](unsigned int i) const {
      return vals[i];
    }

    T& operator[](unsigned int i) {
      return vals[i];
    }

    friend Type<T, N>& operator++(Type<T, N> &a) {
      for (unsigned int i = 0; i < N; ++i) a.vals[i]++;
      return a;
    }

    friend Type<T, N>& operator--(Type<T, N> &a) {
      for (unsigned int i = 0; i < N; ++i) a.vals[i]--;
      return a;
    }

    friend Type<T, N>& operator++(Type<T, N> &a, int b) {
      for (unsigned int i = 0; i < N; ++i) a.vals[i]++(b);
      return a;
    }

    friend Type<T, N>& operator--(Type<T, N> &a, int b) {
      for (unsigned int i = 0; i < N; ++i) a.vals[i]--(b);
      return a;
    }

    template <typename T2>
    Type<T, N>& operator=(const Type<T2, N> &a) {
      for (unsigned int i = 0; i < N; ++i) vals[i] = a[i];
      return *this;
    }

    template <typename T2>
    Type<T, N>& operator=(const T2 &a) {
      for (unsigned int i = 0; i < N; ++i) vals[i] = a;
      return *this;
    }

  };

  #define UNARY(name, operator)                                                 \
  template <typename T1, typename T2, unsigned int N>                           \
  inline Type<T2, N>& name(const Type<T1, N> &a, Type<T2, N> &out) {            \
    for (unsigned int i = 0; i < N; ++i) out[i] = operator a[i];                \
    return out;                                                                 \
  }

  #define TWO_OPERAND(name, operator)                                                           \
  template <typename T1, typename T2, typename T3, unsigned int N>                              \
  inline Type<T3, N>& name(const Type<T1, N> &a, const Type<T2, N> &b, Type<T3, N> &out) {      \
    for (unsigned int i = 0; i < N; ++i) out[i] = a[i] operator b[i];                           \
    return out;                                                                                 \
  }                                                                                             \
  template <typename T1, typename T2, typename T3, unsigned int N>                              \
  inline Type<T3, N>& name(const Type<T1, N> &a, const T2 &b, Type<T3, N> &out) {               \
    for (unsigned int i = 0; i < N; ++i) out[i] = a[i] operator b;                              \
    return out;                                                                                 \
  }                                                                                             \
  template <typename T1, typename T2, typename T3, unsigned int N>                              \
  inline Type<T3, N>& name(const T1 &a, const Type<T2, N> &b, Type<T3, N> &out) {               \
    for (unsigned int i = 0; i < N; ++i) out[i] = a operator b[i];                              \
    return out;                                                                                 \
  }                                                                             
  
  TWO_OPERAND(AND, &)
  TWO_OPERAND(OR, |)
  TWO_OPERAND(XOR, ^)
  UNARY(COMPLEMENT, ~)
  TWO_OPERAND(LEFT_SHIFT, <<)
  TWO_OPERAND(RIGHT_SHIFT, >>)

  TWO_OPERAND(lAND, &&)
  TWO_OPERAND(lOR, ||)
  UNARY(NOT, !)
  
  TWO_OPERAND(EQUAL, ==)
  TWO_OPERAND(NOT_EQUAL, !=)
  TWO_OPERAND(GREATER_THAN, >)
  TWO_OPERAND(LESS_THAN, <)
  TWO_OPERAND(GREATER_THAN_OR_EQUAL, >=)
  TWO_OPERAND(LESS_THAN_OR_EQUAL, <=)

  TWO_OPERAND(ADD, +)
  TWO_OPERAND(SUBTRACT, -)
  TWO_OPERAND(MULTIPLY, *)
  TWO_OPERAND(DIVIDE, /)
  TWO_OPERAND(MODULUS, %)

  UNARY(NEGATE, -)

  #define UNARY_OPERATOR(op, func)                      \
  template <typename T, unsigned int N>                 \
  Type<T, N> op(const Type<T, N> &a) {                  \
    Type<T, N> out;                                     \
    func(a, out);                                       \
    return out;                                         \
  }

  #define BINARY_OPERATOR(op, func)                                  \
  template <typename T, typename T2, unsigned int N>                 \
  Type<T, N> op(const Type<T, N> &a, const Type<T2, N> &b) {         \
    Type<T, N> out;                                                  \
    func(a, b, out);                                                 \
    return out;                                                      \
  }                                                                  \
  template <typename T, typename T2, unsigned int N>                 \
  Type<T, N> op(const Type<T, N> &a, const T2 &b) {                  \
    Type<T, N> out;                                                  \
    func(a, b, out);                                                 \
    return out;                                                      \
  }                                                                  \
  template <typename T, typename T2, unsigned int N>                 \
  Type<T, N> op(const T2 &b, const Type<T, N> &a) {                  \
    Type<T, N> out;                                                  \
    func(b, a, out);                                                 \
    return out;                                                      \
  }

  #define ASSIGNMENT_OPERATOR(name, op)                                     \
  template <typename T, typename T2, unsigned int N>                        \
  Type<T, N>& name(Type<T, N> &a, const Type<T2, N> &b) {                   \
    for (unsigned int i = 0; i < N; ++i) a[i] op b[i];                      \
    return a;                                                               \
  }                                                                         \
  template <typename T, typename T2, unsigned int N>                        \
  Type<T, N>& name(Type<T, N> &a, const T2 &b) {                            \
    for (unsigned int i = 0; i < N; ++i) a[i] op b;                         \
    return a;                                                               \
  }

  UNARY_OPERATOR(operator-, NEGATE)
  UNARY_OPERATOR(operator~, COMPLEMENT)

  BINARY_OPERATOR(operator+, ADD)
  BINARY_OPERATOR(operator-, SUBTRACT)
  BINARY_OPERATOR(operator*, MULTIPLY)
  BINARY_OPERATOR(operator/, DIVIDE)
  BINARY_OPERATOR(operator%, MODULUS)
  
  BINARY_OPERATOR(operator&, AND)
  BINARY_OPERATOR(operator|, OR)
  BINARY_OPERATOR(operator^, XOR)
  BINARY_OPERATOR(operator<<, LEFT_SHIFT)
  BINARY_OPERATOR(operator>>, RIGHT_SHIFT)

  ASSIGNMENT_OPERATOR(operator+=, +=)
  ASSIGNMENT_OPERATOR(operator-=, -=)
  ASSIGNMENT_OPERATOR(operator*=, *=)
  ASSIGNMENT_OPERATOR(operator/=, /=)

  UNARY_OPERATOR(operator!, NOT)
  BINARY_OPERATOR(operator&&, lAND)
  BINARY_OPERATOR(operator||, lOR)
  BINARY_OPERATOR(operator==, EQUAL)
  BINARY_OPERATOR(operator!=, NOT_EQUAL)
  BINARY_OPERATOR(operator>, GREATER_THAN)
  BINARY_OPERATOR(operator<, LESS_THAN)
  BINARY_OPERATOR(operator>=, GREATER_THAN_OR_EQUAL)
  BINARY_OPERATOR(operator<=, LESS_THAN_OR_EQUAL)

  #undef UNARY
  #undef TWO_OPERAND
  #undef UNARY_OPERATOR
  #undef BINARY_OPERATOR

  template <typename T, unsigned int N>
  bool any(const Type<T, N> &a) {
    for (unsigned int i = 0; i < N; ++i) if (a[i]) return true;
    return false;
  }

  template <typename T, unsigned int N>
  bool all(const Type<T, N> &a) {
    for (unsigned int i = 0; i < N; ++i) if (!a[i]) return false;
    return true;
  }

  template <typename T1, typename T2, typename T3, unsigned int N>              
  inline Type<T3, N> & min(const Type<T1, N> &a, const Type<T2, N> &b, Type<T3, N> &out) {  
    for (unsigned int i = 0; i < N; ++i) out[i] = a[i] < b[i] ? a[i] : b[i]; 
    return out;
  }                                                                    
  template <typename T1, typename T2, typename T3, unsigned int N>     
  inline Type<T3, N> & min(const Type<T1, N> &a, const T2 &b, Type<T3, N> &out) {       
    for (unsigned int i = 0; i < N; ++i) out[i] = a[i] < b ? a[i] : b;  
    return out;     
  }                                                                             
  template <typename T1, typename T2, typename T3, unsigned int N>              
  inline Type<T3, N> & min(const T1 &a, const Type<T2, N> &b, Type<T3, N> &out) {       
    for (unsigned int i = 0; i < N; ++i) out[i] = a < b[i] ? a : b[i]; 
    return out;     
  }

  template <typename T1, typename T2, typename T3, unsigned int N>              
  inline Type<T3, N> & max(const Type<T1, N> &a, const Type<T2, N> &b, Type<T3, N> &out) {  
    for (unsigned int i = 0; i < N; ++i) out[i] = a[i] > b[i] ? a[i] : b[i]; 
    return out;
  }                                                                    
  template <typename T1, typename T2, typename T3, unsigned int N>     
  inline Type<T3, N> & max(const Type<T1, N> &a, const T2 &b, Type<T3, N> &out) {       
    for (unsigned int i = 0; i < N; ++i) out[i] = a[i] > b ? a[i] : b;    
    return out;   
  }                                                                             
  template <typename T1, typename T2, typename T3, unsigned int N>              
  inline Type<T3, N> & max(const T1 &a, const Type<T2, N> &b, Type<T3, N> &out) {       
    for (unsigned int i = 0; i < N; ++i) out[i] = a > b[i] ? a : b[i]; 
    return out;        
  }

  template <unsigned int N>
  using Bool = Type<bool, N>;

  template <unsigned int N>
  using Short = Type<short, N>;

  template <unsigned int N>
  using Uint = Type<unsigned int, N>;

  template <unsigned int N>
  using Int = Type<int, N>;

  template <unsigned int N>
  using Float = Type<float, N>;

  template <unsigned int N>
  using Double = Type<double, N>;
}