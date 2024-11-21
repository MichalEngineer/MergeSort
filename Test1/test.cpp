#include "../MergeSort/Sort.cpp"
#include "../MergeSort/sort.h"
#include <gtest/gtest.h>
/// @brief Test sortowania dla tablicy juz posortowanej.
TEST(Tests, alreadydone) {
    std::vector<int> t = { 1, 2, 3, 4, 5 };
    MergeSort::Sort(t);
    std::vector<int> expected = { 1, 2, 3, 4, 5 };
    ASSERT_EQ(t, expected);
}
/// @brief Test sortowania dla tablicy juz posortowanej odwrotnie.
TEST(Tests, reverseOrder) {
    std::vector<int> t = { 10, 6, 5, 2, 1 };
    MergeSort::Sort(t);
    std::vector<int> expected = { 1, 2, 5, 6, 10 };
    ASSERT_EQ(t, expected);
}
/// @brief Test sortowania dla tablicy losowej.
TEST(Tests, randomOrder) {
    std::vector<int> t = { 3, 1, 4, 5, 2 };
    MergeSort::Sort(t);
    std::vector<int> expected = { 1, 2, 3, 4, 5 };
    ASSERT_EQ(t, expected);
}
/// @brief Test sortowania dla tablicy z negetywnymi numerami.
TEST(Tests, negnumb) {
    std::vector<int> t = { -12, -8, -4, -16, -2 };
    MergeSort::Sort(t);
    std::vector<int> expected = { -16, -12, -8, -4, -2 };
    ASSERT_EQ(t, expected);
}
/// @brief Test sortowania dla tablicy z mieszanymi liczbami.
TEST(Tests, negposnumb) {
    std::vector<int> t = { -53, 20, -14, 5, 2 };
    MergeSort::Sort(t);
    std::vector<int> expected = { -53, -14, 2, 5, 20 };
    ASSERT_EQ(t, expected);
}
/// @brief Test sortowania dla tablicy pustej.
TEST(Tests, empty) {
    std::vector<int> t = {};
    MergeSort::Sort(t);
    std::vector<int> expected = {};
    ASSERT_EQ(t, expected);
}
/// @brief Test sortowania dla tablicy jednoliczbowej.
TEST(Tests, onenumb) {
    std::vector<int> t = { 42 };
    MergeSort::Sort(t);
    std::vector<int> expected = { 42 };
    ASSERT_EQ(t, expected);
}
/// @brief Test sortowania dla tablicy z powtarzajacymi sie numerami.
TEST(Tests, duplicates) {
    std::vector<int> t = { 2, 1, 2, 8, 1 ,8 };
    MergeSort::Sort(t);
    std::vector<int> expected = { 1, 1, 2, 2, 8 ,8 };
    ASSERT_EQ(t, expected);
}
/// @brief Test sortowania dla tablicy z powtarzajacymi sie numerami ale negatynej.
TEST(Tests, negativeDuplicates) {
    std::vector<int> t = { -2, -1, -2, -8, -1 ,-8 };
    MergeSort::Sort(t);
    std::vector<int> expected = { -8, -8, -2, -2, -1, -1 };
    ASSERT_EQ(t, expected);
}
/// @brief Test sortowania dla tablicy z dwoma numerami.
TEST(Tests, twonumb) {
    std::vector<int> t = {1,2 };
    MergeSort::Sort(t);
    std::vector<int> expected = { 1,2 };
    ASSERT_EQ(t, expected);
}
/// @brief Test sortowania dla bardzo du¿ej tablicy .
TEST(Tests, hundred) {
    std::vector<int> t(101);
    std::vector<int> expected(101);
    for (int i = 0;i < 101;i++) {
        expected[i] = i*2;
    }
    for (int i = 0;i < 101;i++) {
        t[i] = i*2;
    }
    t[0] = 2;
    t[1] = 0;
    MergeSort::Sort(t);
    ASSERT_EQ(t, expected);
}
/// @brief Test sortowania dla bardzo du¿ej tablicy a ujemnymi liczbami i duplikatami.
TEST(Tests, hundredmix) {
    std::vector<int> t(201);
    std::vector<int> expected(201);
    for (int i = -100;i < 101;i++) {
        int index = i + 100; 
        expected[index] = i * 2;
        t[index] = i * 2;
    }
    t[20] = 16;
    expected[20] = 16;
    t[20] = 6;
    expected[20] = 6;
    std::sort(expected.begin(), expected.end());
    MergeSort::Sort(t);
    ASSERT_EQ(t, expected);
}
