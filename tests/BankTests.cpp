#include <gtest/gtest.h>
#include "../include/Bank.h"


// testing default constructor
TEST(BankTest, BankDefaultConstructor) {
  Bank cBank;
  EXPECT_EQ(0, cBank.getBalance());
}

// testing parametrized constructor
TEST(BankTest, BankParameterizedConstructor) {
  Bank cBank(1000);
  EXPECT_EQ(1000, cBank.getBalance());
  Bank cBank2(0);
  EXPECT_EQ(0, cBank2.getBalance());
}

// testing parameterized constructor exceptions
TEST(BankTest, BankParameterizedConstructorExceptions) {
  EXPECT_THROW(Bank cBank(-1), std::invalid_argument);
  EXPECT_THROW(Bank cBank2(-200000), std::invalid_argument);

}

// testing getBalance
TEST(BankTest, getBalance) {
  Bank cBank(2000000);
  EXPECT_EQ(2000000, cBank.getBalance());
}

// testing add
TEST(BankTest, add) {
  Bank cBank(100);
  cBank.add(100);
  EXPECT_EQ(200, cBank.getBalance());
}

// testing subtract
TEST(BankTest, subtract) {
  Bank cBank(100);
  cBank.subtract(100);
  EXPECT_EQ(0, cBank.getBalance());
}

// testing subtract
TEST(BankTest, clear) {
  Bank cBank(100);
  cBank.clear();
  EXPECT_EQ(0, cBank.getBalance());
}


// testing operator<<
TEST(BankTest, insertionOperator) {
  Bank cBank(100);
  std::ostringstream oString;
  oString << cBank;
  EXPECT_EQ("100", oString.str());
}