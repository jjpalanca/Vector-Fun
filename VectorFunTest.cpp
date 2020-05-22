/**
 * This class has many test methods for testing the functions
 * that must be in a file named VectorFun.hpp
 *
 * Author  Rick Mercer and Your Name
 */
#include <vector>
#include <string>
#include "catch.hpp"
#include "VectorFun.hpp"
using namespace std;

TEST_CASE("testSortOfSort1") {
    vector<int> x = {2, 4, 3, 1};
    sortOfSort(x);
    REQUIRE(1 == x[0]);
    REQUIRE(4 == x[3]);

    vector<int> y = {48,12,13,56};
    sortOfSort(y);
    REQUIRE(12 == y[0]);
    REQUIRE(56 == y[3]);

    vector<int> z = {1};
    sortOfSort(z);
    REQUIRE(1 == z[0]);
}


TEST_CASE("testNumberOfPairs1") {
    vector<string> s1{"a", "b", "c"};
    REQUIRE(0 == numberOfPairs(s1));
    vector<string> s2{"a"};
    REQUIRE(0 == numberOfPairs(s2));
    vector<string> s3{""};
    REQUIRE(0 == numberOfPairs(s3));
    vector<int> s4{1, 1, 1};
    REQUIRE(2 == numberOfPairs(s4));
    vector<int> s5{1, 2, 1, 2, 1};
    REQUIRE(0 == numberOfPairs(s5));
    vector<string> s6{"a", "b", "c"};
    REQUIRE(0 == numberOfPairs(s6));
    vector<string> s7{"a", "a", "b", "b"};
    REQUIRE(2 == numberOfPairs(s7));
}


TEST_CASE("testSumIsGreater") {
    vector<double> x1 = {1.1, 2.2, 3.3};
    REQUIRE(sumGreaterThan(x1, 4.0));
    vector<double> x2 = {1.1, 2.2, 3.3};
    REQUIRE(!sumGreaterThan(x2, 6.6));
    vector<double> x3 = {1.1, 2.2, 4.4};
    REQUIRE(!sumGreaterThan(x3, 10.0));
    vector<double> x4 = { };
    REQUIRE(sumGreaterThan(x4, 4.0));
}

TEST_CASE("testSumIsGreater2") {
    vector<double> x2 = {1.1, 2.2, 3.3};
    REQUIRE(!sumGreaterThan(x2, 6.6));
}

TEST_CASE("testFrequency") {
    vector<int> nums{1, 1, 1, 3, 3, 5, 6, 6, 10, 10, 10};
    vector<int> result = frequency(nums);
    REQUIRE(0 == result[0]);
    REQUIRE(3 == result[1]);
    REQUIRE(0 == result[2]);
    REQUIRE(2 == result[3]);
    REQUIRE(0 == result[4]);
    REQUIRE(1 == result[5]);
    REQUIRE(2 == result[6]);
    REQUIRE(0 == result[7]);
    REQUIRE(0 == result[8]);
    REQUIRE(0 == result[9]);
    REQUIRE(3 == result[10]);
}

TEST_CASE("testFailedHowMany") {
    vector<string> strs{"a", "C", "X", "x", "b", "a", "b", "abc",
                        "b", "a", "aBC", "abc", "1234", "1234",
                        "b", "a", "12"};
    vector<string> str{ };
    REQUIRE(4 == howMany(strs, "b"));
    REQUIRE(4 == howMany(strs, "a"));
    REQUIRE(1 == howMany(strs, "C"));
    REQUIRE(1 == howMany(strs, "X"));
    REQUIRE(1 == howMany(strs, "x"));
    REQUIRE(2 == howMany(strs, "abc"));
    REQUIRE(1 == howMany(strs, "aBC"));
    REQUIRE(2 == howMany(strs, "1234"));
    REQUIRE(0 == howMany(strs, "SDFISFDES"));
    REQUIRE(0 == howMany(str, "b"));
}

TEST_CASE("testEvensLeft") {
    vector<int> a = {1, 2, 3, 4, 5, 6, 7};
    evensLeft(a);
// left side of the array at indexes 0..2 is even
    for (int i = 0; i <= 2; i++)
        REQUIRE(0 == a[i] % 2);
// right side of the array at indexes 3..6 is odd
    for (int i = 3; i <= 6; i++)
        REQUIRE(1 == a[i] % 2);
}


TEST_CASE("testShiftNTimes") {
    vector<int> a = {1, 2, 3};
    shiftNTimes(a, 1);
    REQUIRE(2 == a[0]);
    REQUIRE(3 == a[1]);
    REQUIRE(1 == a[2]);

    vector<int> b = {5, 4, 7, 12, 54, 3};
    shiftNTimes(b, 4);
    REQUIRE(54 == b[0]);
    REQUIRE(3 == b[1]);
    REQUIRE(5 == b[2]);
    REQUIRE(4 == b[3]);
    REQUIRE(7 == b[4]);
    REQUIRE(12 == b[5]);

    vector<int> c = {53};
    shiftNTimes(c,10);
    REQUIRE(53 == c[0]);

}


TEST_CASE("testRange") {
    vector<int> x = { 4 };
    REQUIRE(0 == range(x));

    vector<int> x2 = {43, 7, 87, 31, 5, 65, 20};
    REQUIRE(82 == range(x2));

    vector<int> x3 = {1, 2, -3, 4};
    REQUIRE(7 == range(x3));

    vector<int> x4 = {-10, -5, -1, 0, -6};
    REQUIRE(10 == range(x4));
}


TEST_CASE("fizzBuzz") {
    vector<string> strs = fizzBuzz(1, 6);
    REQUIRE("1" == strs[0]);
    REQUIRE("2" == strs[1]);
    REQUIRE("Fizz" == strs[2]);
    REQUIRE("4" == strs[3]);
    REQUIRE("Buzz" == strs[4]);

    vector<string> strs2 = fizzBuzz(1, 8);
    REQUIRE("1" == strs2[0]);
    REQUIRE("2" == strs2[1]);
    REQUIRE("Fizz" == strs2[2]);
    REQUIRE("4" == strs2[3]);
    REQUIRE("Buzz" == strs2[4]);
    REQUIRE("Fizz" == strs2[5]);
    REQUIRE("7" == strs2[6]);

    vector<string> strs3 = fizzBuzz(14, 21);
    REQUIRE("14" == strs3[0]);
    REQUIRE("FizzBuzz" == strs3[1]);
    REQUIRE("16" == strs3[2]);
    REQUIRE("17" == strs3[3]);
    REQUIRE("Fizz" == strs3[4]);
    REQUIRE("19" == strs3[5]);
    REQUIRE("Buzz" == strs3[6]);
}