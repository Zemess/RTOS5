#include "gtest/gtest.h"
#include "TimeParser.h"

constexpr int H(int h) { return h * 3600;}
constexpr int M(int m) { return m * 60;}

TEST(TimeParser, ValidTimes) {
    EXPECT_EQ(time_parse("000120"), 80);                // 00:01:20 -> 80 seconds
    EXPECT_EQ(time_parse("235959"), H(23) + M(59) + 59);               // MAX valid time
}

TEST(TimeParser, RangeErrors) {
    EXPECT_EQ(time_parse("246000"), TP_ERR_RANGEH);    // Invalid hour
    EXPECT_EQ(time_parse("006000"), TP_ERR_RANGEM);     // Invalid minute
    EXPECT_EQ(time_parse("005960"), TP_ERR_RANGES);     // Invalid second
}

TEST(TimeParser, LengthAndDigits) {
    EXPECT_EQ(time_parse("01234"), TP_ERR_LEN);
    EXPECT_EQ(time_parse("01A020"), TP_ERR_NAN);
    EXPECT_EQ(time_parse(nullptr), TP_ERR_NULL);
}

TEST(TimeParser, ZeroTotal) {
    EXPECT_EQ(time_parse("000000"), TP_ERR_ZERO);       // Total time is zero
}