
#pragma once

namespace SIMD {
  template <typename T, unsigned int N>
  class Type {
    T vals[N];

    public:
    template <typename... Ts>
    Type(Ts... args) : vals {args...} { }

    template <typename T2>
    Type(const T2 &a) {
      for (unsigned int i = 0; i < N; ++i) {
        vals[i] = a[i];
      }
    }

    T operator[](unsigned int i) const {
      return vals[i];
    }

    T& operator[](unsigned int i) {
      return vals[i];
    }

    friend Type<T, N> operator-(const Type<T, N> &a) {
      Type<T, N> out;
      for (unsigned int i = 0; i < N; ++i) {
        out[i] = -a[i];
      }
      return out;
    }

    friend Type<T, N> operator~(const Type<T, N> &a) {
      Type<T, N> out;
      for (unsigned int i = 0; i < N; ++i) {
        out[i] = ~a[i];
      }
      return out;
    }

    template <typename T2>
    friend Type<T, N> operator+(const Type<T, N> &a, const Type<T2, N> &b) {
      Type<T, N> out;
      for (unsigned int i = 0; i < N; ++i) {
        out[i] = a[i] + b[i];
      }
      return out;
    }

    template <typename T2>
    friend Type<T, N> operator-(const Type<T, N> &a, const Type<T2, N> &b) {
      Type<T, N> out;
      for (unsigned int i = 0; i < N; ++i) {
        out[i] = a[i] - b[i];
      }
      return out;
    }

    template <typename T2>
    friend Type<T, N> operator*(const Type<T, N> &a, const Type<T2, N> &b) {
      Type<T, N> out;
      for (unsigned int i = 0; i < N; ++i) {
        out[i] = a[i] * b[i];
      }
      return out;
    }

    template <typename T2>
    friend Type<T, N> operator/(const Type<T, N> &a, const Type<T2, N> &b) {
      Type<T, N> out;
      for (unsigned int i = 0; i < N; ++i) {
        out[i] = a[i] / b[i];
      }
      return out;
    }

    template <typename T2>
    friend Type<T, N> operator%(const Type<T, N> &a, const Type<T2, N> &b) {
      Type<T, N> out;
      for (unsigned int i = 0; i < N; ++i) {
        out[i] = a[i] % b[i];
      }
      return out;
    }

    template <typename T2>
    friend Type<T, N> operator&(const Type<T, N> &a, const Type<T2, N> &b) {
      Type<T, N> out;
      for (unsigned int i = 0; i < N; ++i) {
        out[i] = a[i] & b[i];
      }
      return out;
    }

    template <typename T2>
    friend Type<T, N> operator|(const Type<T, N> &a, const Type<T2, N> &b) {
      Type<T, N> out;
      for (unsigned int i = 0; i < N; ++i) {
        out[i] = a[i] | b[i];
      }
      return out;
    }

    template <typename T2>
    friend Type<T, N> operator^(const Type<T, N> &a, const Type<T2, N> &b) {
      Type<T, N> out;
      for (unsigned int i = 0; i < N; ++i) {
        out[i] = a[i] ^ b[i];
      }
      return out;
    }

    template <typename T2>
    friend Type<T, N> operator<<(const Type<T, N> &a, const Type<T2, N> &b) {
      Type<T, N> out;
      for (unsigned int i = 0; i < N; ++i) {
        out[i] = a[i] << b[i];
      }
      return out;
    }

    template <typename T2>
    friend Type<T, N> operator>>(const Type<T, N> &a, const Type<T2, N> &b) {
      Type<T, N> out;
      for (unsigned int i = 0; i < N; ++i) {
        out[i] = a[i] >> b[i];
      }
      return out;
    }

    template <typename T2>
    friend Type<T, N> operator<<(const Type<T, N> &a, const T2 &b) {
      Type<T, N> out;
      for (unsigned int i = 0; i < N; ++i) {
        out[i] = a[i] << b;
      }
      return out;
    }

    template <typename T2>
    friend Type<T, N> operator>>(const Type<T, N> &a, const T2 &b) {
      Type<T, N> out;
      for (unsigned int i = 0; i < N; ++i) {
        out[i] = a[i] >> b;
      }
      return out;
    }

    friend Type<T, N>& operator++(Type<T, N> &a) {
      for (unsigned int i = 0; i < N; ++i) {
        a.vals[i]++;
      }
      return a;
    }

    friend Type<T, N>& operator--(Type<T, N> &a) {
      for (unsigned int i = 0; i < N; ++i) {
        a.vals[i]--;
      }
      return a;
    }

    friend Type<T, N>& operator++(Type<T, N> &a, int b) {
      for (unsigned int i = 0; i < N; ++i) {
        a.vals[i]++(b);
      }
      return a;
    }

    friend Type<T, N>& operator--(Type<T, N> &a, int b) {
      for (unsigned int i = 0; i < N; ++i) {
        a.vals[i]--(b);
      }
      return a;
    }

    template <typename T2>
    friend Type<T, N>& operator+=(Type<T, N> &a, const Type<T2, N> &b) {
      for (unsigned int i = 0; i < N; ++i) {
        a[i] += b[i];
      }
      return a;
    }

    template <typename T2>
    friend Type<T, N>& operator-=(Type<T, N> &a, const Type<T2, N> &b) {
      for (unsigned int i = 0; i < N; ++i) {
        a[i] -= b[i];
      }
      return a;
    }

    template <typename T2>
    friend Type<T, N>& operator*=(Type<T, N> &a, const Type<T2, N> &b) {
      for (unsigned int i = 0; i < N; ++i) {
        a[i] *= b[i];
      }
      return a;
    }

    template <typename T2>
    friend Type<T, N>& operator/=(Type<T, N> &a, const Type<T2, N> &b) {
      for (unsigned int i = 0; i < N; ++i) {
        a[i] /= b[i];
      }
      return a;
    }

    template <typename T2>
    Type<T, N>& operator=(const Type<T2, N> &a) {
      for (unsigned int i = 0; i < N; ++i) {
        vals[i] = a[i];
      }
      return *this;
    }

    friend bool any(const Type<T, N> &a) {
       for (unsigned int i = 0; i < N; ++i) {
         if (a[i]) return true;
       }
       return false;
    }

    friend bool all(const Type<T, N> &a) {
      for (unsigned int i = 0; i < N; ++i) {
        if (!a[i]) return false;
      }
      return true;
    }

    friend Type<bool, N> operator!(const Type<T, N> &a) {
      Type<bool, N> out;
      for (unsigned int i = 0; i < N; ++i) {
        out[i] = !a[i];
      }
      return out;
    }

    template <typename T2>
    friend Type<bool, N> operator&&(const Type<T, N> &a, const Type<T2, N> &b) {
      Type<bool, N> out;
      for (unsigned int i = 0; i < N; ++i) {
        out[i] = a[i] && b[i];
      }
      return out;
    }

    template <typename T2>
    friend Type<bool, N> operator||(const Type<T, N> &a, const Type<T2, N> &b) {
      Type<bool, N> out;
      for (unsigned int i = 0; i < N; ++i) {
        out[i] = a[i] && b[i];
      }
      return out;
    }
    
    template <typename T2>
    friend Type<bool, N> operator==(const Type<T, N> &a, const Type<T2, N> &b) {
      Type<bool, N> out;
      for (unsigned int i = 0; i < N; ++i) {
        out[i] = a[i] == b[i];
      }
      return out;
    }

    template <typename T2>
    friend Type<bool, N> operator!=(const Type<T, N> &a, const Type<T2, N> &b) {
      Type<bool, N> out;
      for (unsigned int i = 0; i < N; ++i) {
        out[i] = a[i] != b[i];
      }
      return out;
    }

    template <typename T2>
    friend Type<bool, N> operator<(const Type<T, N> &a, const Type<T2, N> &b) {
      Type<bool, N> out;
      for (unsigned int i = 0; i < N; ++i) {
        out[i] = a[i] < b[i];
      }
      return out;
    }

    template <typename T2>
    friend Type<bool, N> operator>(const Type<T, N> &a, const Type<T2, N> &b) {
      Type<bool, N> out;
      for (unsigned int i = 0; i < N; ++i) {
        out[i] = a[i] > b[i];
      }
      return out;
    }

    template <typename T2>
    friend Type<bool, N> operator<=(const Type<T, N> &a, const Type<T2, N> &b) {
      Type<bool, N> out;
      for (unsigned int i = 0; i < N; ++i) {
        out[i] = a[i] <= b[i];
      }
      return out;
    }

    template <typename T2>
    friend Type<bool, N> operator>=(const Type<T, N> &a, const Type<T2, N> &b) {
      Type<bool, N> out;
      for (unsigned int i = 0; i < N; ++i) {
        out[i] = a[i] >= b[i];
      }
      return out;
    }
  };


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