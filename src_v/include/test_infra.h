#ifndef __TEST_INFRA_H__
#define __TEST_INFRA_H__

#define ASSERT(condition, ret, jumpto, msg, ...) \
    if (!(condition)) { \
        printf(msg, __VA_ARGS__ ); \
        ret = 1; \
        goto jumpto; \
    }

#endif