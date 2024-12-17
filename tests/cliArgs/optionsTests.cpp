#include "cliArgs/options.hpp"
#include "cliArgs/usage.hpp"
#include <atomic>
#include <gtest/gtest.h>
#include <string>
#include <vector>

class OptionsTest : public ::testing::Test {
protected:
  void SetUp() override {
    // Setup code if needed
  }

  void TearDown() override {
    // Cleanup code if needed
  }
};

// simple test 1 + 1 = 2 success
TEST_F(OptionsTest, test1And1Success) {
  int a = 1;
  int b = 1;
  EXPECT_EQ(a + b, 2);
}

// simple test 1 + 1 = 3 fail
TEST_F(OptionsTest, test1And1Fail) {
  int a = 1;
  int b = 1;
  EXPECT_EQ(a + b, 3);
}
