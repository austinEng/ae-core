
#pragma once

#include "count.h"

#define PASTE(a, b) a ## b

#define APPLY_EACH(FN, ...) APPLY_EACH_INC(FN, PP_NARG(__VA_ARGS__), __VA_ARGS__)
#define APPLY_EACH_INC(FN, CT, ...) PASTE(APPLY_, CT) (FN, __VA_ARGS__)
#define APPLY_1(FN, _1) FN(_1)
#define APPLY_2(FN, _1, ...) FN(_1) APPLY_1(FN, __VA_ARGS__)
#define APPLY_3(FN, _1, ...) FN(_1) APPLY_2(FN, __VA_ARGS__)
#define APPLY_4(FN, _1, ...) FN(_1) APPLY_3(FN, __VA_ARGS__)
#define APPLY_5(FN, _1, ...) FN(_1) APPLY_4(FN, __VA_ARGS__)
#define APPLY_6(FN, _1, ...) FN(_1) APPLY_5(FN, __VA_ARGS__)
#define APPLY_7(FN, _1, ...) FN(_1) APPLY_6(FN, __VA_ARGS__)
#define APPLY_8(FN, _1, ...) FN(_1) APPLY_7(FN, __VA_ARGS__)
#define APPLY_9(FN, _1, ...) FN(_1) APPLY_8(FN, __VA_ARGS__)