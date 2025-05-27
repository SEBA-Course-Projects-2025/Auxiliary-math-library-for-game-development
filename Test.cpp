#include <gtest/gtest.h>
#include "library.h"

TEST(MyLibTest, AddsCorrectly) {
    EXPECT_EQ(add(2, 3), 5);
}