#include <gtest/gtest.h>
#include "../src/util.h"

TEST(util, gcd) {
    ASSERT_EQ(2, gcd(4, 10));
    EXPECT_EQ(6, gcd(30, 18));
}

