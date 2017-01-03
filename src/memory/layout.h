
#pragma once

#include <vector>
#include <pp/foreach.h>
#include <pp/typed_expression.h>
#include <pp/count.h>

#define AOS_NODE_PROP(x) PAIR(x);
#define VOS_PROP(x) std::vector<TYPEOF(x)> STRIP(x);
#define SOA_PROP1(x) PAIR(x)[1];
#define SOA_PROP2(x) PAIR(x)[2];
#define SOA_PROP3(x) PAIR(x)[3];
#define SOA_PROP4(x) PAIR(x)[4];
#define SOA_PROP5(x) PAIR(x)[5];
#define SOA_PROP6(x) PAIR(x)[6];
#define SOA_PROP7(x) PAIR(x)[7];
#define SOA_PROP8(x) PAIR(x)[8];
#define SOA_PROP9(x) PAIR(x)[9];
#define SOA_PROP10(x) PAIR(x)[10];
#define SOA_PROP11(x) PAIR(x)[11];
#define SOA_PROP12(x) PAIR(x)[12];
#define SOA_PROP13(x) PAIR(x)[13];
#define SOA_PROP14(x) PAIR(x)[14];
#define SOA_PROP15(x) PAIR(x)[15];
#define SOA_PROP16(x) PAIR(x)[16];
#define SOA_PROP17(x) PAIR(x)[17];
#define SOA_PROP18(x) PAIR(x)[18];
#define SOA_PROP19(x) PAIR(x)[19];
#define SOA_PROP20(x) PAIR(x)[20];

#define DECLARE_LAYOUT(name, ...) \
  typedef struct { \
    APPLY_EACH(AOS_NODE_PROP, __VA_ARGS__) \
  } name ## _aos_node_t; \
  \
  typedef std::vector<name ## _aos_node_t> name ## _vos_t; \
  typedef name ## _aos_node_t* name ## _aos_t; \
  typedef struct { \
    APPLY_EACH(VOS_PROP, __VA_ARGS__) \
  } name ## _sov_t;

#define DECLARE_FIXED_SOA(name, size, ...) \
  typedef struct { \
    APPLY_EACH(PASTE(SOA_PROP, size), __VA_ARGS__) \
  } name ## _soa ## size ## _t; 

#define FIXED_SOA_MEMBERS(size, ...) APPLY_EACH(PASTE(SOA_PROP, size), __VA_ARGS__)
#define SOV_MEMBERS(...) APPLY_EACH(VOS_PROP, __VA_ARGS__)
#define AOS_MEMBERS(...) APPLY_EACH(AOS_NODE_PROP, __VA_ARGS__)
