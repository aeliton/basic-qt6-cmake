#include <gtest/gtest.h>

TEST(Hello, IsHello)
{
  ASSERT_EQ(std::string("hello"), "hello");
}
