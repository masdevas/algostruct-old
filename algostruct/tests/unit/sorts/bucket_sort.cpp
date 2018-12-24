#include <gtest/gtest.h>
#include <algorithm>
#include "sorts/bucket_sort.h"
#include "data_generation.h"

TEST(TEST_BUCKET_SORT, RANDOM_TEST) {
    size_t size = 100000;
    DataType lower_bound = INT64_MIN / 10, upper_bound = INT64_MAX / 10;
    auto data = GenerateRandomVector(size, lower_bound, upper_bound);
    auto copy_of_data = data;
    auto comp = [](const DataType& data_first, const DataType& data_second) {
        return data_first < data_second;
    };
    BucketSort(data.begin(), data.end(), lower_bound, upper_bound, comp);
    //std::sort(copy_of_data.begin(), copy_of_data.end(), comp);
    //EXPECT_EQ(data, copy_of_data);
}