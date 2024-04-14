#include <vector>
#include <iostream>
#include <gtest/gtest.h>
#include "../src/linreg.h"

// test to ensure slopes are calculated correctly
TEST(LinregTest, CalculateSlope){
    std::vector<double> x_vals = {1, 2, 3, 4, 5};
    std::vector<double> y_vals = {3, 5, 7, 9, 11};
    LinearRegression model(x_vals, y_vals);
    EXPECT_EQ(model.get_slope(), 2);
}

TEST(LinregTest, CalculateYintercept){
    std::vector<double> x_vals = {1, 2, 3, 4, 5};
    std::vector<double> y_vals = {5, 8, 11, 14, 17};
    LinearRegression model(x_vals, y_vals);   
    EXPECT_EQ(model.get_intercept(), 2);
}

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
