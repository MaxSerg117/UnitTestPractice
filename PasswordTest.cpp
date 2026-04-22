#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
protected:
    PasswordTest() {}
    virtual ~PasswordTest() {}
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST(PasswordTest, single_letter_password)
{
    Password my_password;
    int actual = my_password.count_leading_characters("Z");
    ASSERT_EQ(1, actual);
}

TEST(PasswordTest, multi_letter_password)
{
    Password my_password;
    int actual = my_password.count_leading_characters("Zzz");
    ASSERT_EQ(2, actual);
}

TEST(PasswordTest, empty_letter_password)
{
    Password my_password;
    int actual = my_password.count_leading_characters("");
    ASSERT_EQ(0, actual);
}

TEST(PasswordTest, all_same_characters)
{
    Password my_password;
    int actual = my_password.count_leading_characters("aaaaaa");
    ASSERT_EQ(6, actual);
}

TEST(PasswordTest, no_repetition)
{
    Password my_password;
    int actual = my_password.count_leading_characters("abc");
    ASSERT_EQ(1, actual);
}

TEST(PasswordTest, mixed_case_true)
{
    Password my_password;
    bool actual = my_password.has_mixed_case("AbC");
    ASSERT_TRUE(actual);
}

TEST(PasswordTest, only_uppercase)
{
    Password my_password;
    bool actual = my_password.has_mixed_case("ABC");
    ASSERT_FALSE(actual);
}

TEST(PasswordTest, only_lowercase)
{
    Password my_password;
    bool actual = my_password.has_mixed_case("abc");
    ASSERT_FALSE(actual);
}

TEST(PasswordTest, empty_string_mixed_case)
{
    Password my_password;
    bool actual = my_password.has_mixed_case("");
    ASSERT_FALSE(actual);
}

TEST(PasswordTest, unique_characters_basic)
{
    unsigned int actual = unique_characters("hello");
    ASSERT_EQ(4, actual); // h, e, l, o
}

TEST(PasswordTest, unique_characters_all_unique)
{
    unsigned int actual = unique_characters("abc");
    ASSERT_EQ(3, actual);
}

TEST(PasswordTest, unique_characters_empty)
{
    unsigned int actual = unique_characters("");
    ASSERT_EQ(0, actual);
}