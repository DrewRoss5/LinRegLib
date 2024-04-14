#include <vector>
#include <iostream>
#include <gtest/gtest.h>
#include "../src/linreg.h"

// test to ensure slopes are calculated accurately
TEST(SimpleLinearRegression, CalculateSlope){
    std::vector<double> x_vals = {1, 2, 3, 4, 5};
    std::vector<double> y_vals = {3, 5, 7, 9, 11};
    LinearRegression model(x_vals, y_vals);
    EXPECT_EQ(model.get_slope(), 2);
    x_vals = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    y_vals = {16, 31, 46, 61, 76, 91, 106, 121, 136, 151};
    model.fit(x_vals, y_vals);
    EXPECT_EQ(model.get_slope(), 15);
    x_vals = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    y_vals = {1.5, 4, 6, 7, 10.5, 13, 12, 20, 18, 20, 24, 24, 27, 27, 31};
    model.fit(x_vals, y_vals);
    EXPECT_NEAR(model.get_slope(), 2.064, 0.001);
}

// test to ensure the y intercept is calculated accurately
TEST(SimpleLinearRegression, CalculateYintercept){
    std::vector<double> x_vals = {1, 2, 3, 4, 5};
    std::vector<double> y_vals = {5, 8, 11, 14, 17};
    LinearRegression model(x_vals, y_vals);   
    EXPECT_EQ(model.get_intercept(), 2);
    x_vals = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    y_vals = {5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    model.fit(x_vals, y_vals);
    EXPECT_EQ(model.get_intercept(), 4);
    x_vals = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    y_vals = {1.5, 4, 6, 7, 10.5, 13, 12, 20, 18, 20, 24, 24, 27, 27, 31};
    model.fit(x_vals, y_vals);
    EXPECT_NEAR(model.get_intercept(), -0.1810, 0.001);
}

// test to ensure that r^2 values are calculated accurately
TEST(SimpleLinearRegression, CalculateR2){
    std::vector<double> x_vals = {1, 2, 3, 4, 5};
    std::vector<double> y_vals = {5, 8, 11, 14, 17};
    LinearRegression model(x_vals, y_vals); 
    EXPECT_EQ(model.calc_r2(), 1);
    x_vals = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    y_vals = {1.5, 4, 6, 7, 10.5, 13, 12, 20, 18, 20, 24, 24, 27, 27, 31};
    model.fit(x_vals, y_vals);
    EXPECT_NEAR(model.calc_r2(), 0.9781, 0.001);
}

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
