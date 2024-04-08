#include <vector>
#include <cmath>
#include <stdexcept>
#include <iostream>
#include "linreg.h"

// general constuctor for the LinearRegression class
LinearRegression::LinearRegression(){
    // set all private variables to default values
    x_vals_ = std::vector<double>();
    y_vals_ = std::vector<double>();
    slope_ = 0;
    y_intercept_ = 0;
}

// general constuctor for the LinearRegression class, accepts two inputs, and attempts to set them to the x and y variable
LinearRegression::LinearRegression(std::vector<double> &x, std::vector<double> &y){
    // attempt to set the data to the provided x and y 
    if (set_data(x, y) == -1)
        throw std::length_error("X input and Y input must have the same size");
}

// sets the data of a linear regression, returns zero if the data is sent sucessfully, otherwise returns -1
int LinearRegression::set_data(std::vector<double> &x, std::vector<double> &y){
    // ensure the x and y values are the same size
    size_t size = x.size();
    if (size != y.size())
        return -1;
    // set the values and size
    x_vals_ = x;
    y_vals_ = y;
    size_ = size;
    return 0;
}

// calculates the slope of the linear regression, given the sum of all x values, the sum of all y values, the sum of all x^2 values, and the sum of all x * y values
double LinearRegression::calc_slope(double x_sum, double y_sum, double xy_sum, double x_square_sum){
    return (xy_sum - ((x_sum * y_sum) / size_)) / (x_square_sum - ((x_sum * x_sum) / size_));
}

// calculates the y-intercept of the linear regression, given the sum of all x values, the sum of all y values, the sum of all x^2 values, and the sum of all x * y values
double LinearRegression::calc_intercept(double x_sum, double y_sum){
    // calculate the mean of x and the mean of y
    double x_avg = x_sum / size_;
    double y_avg = y_sum / size_;
    // calculate the y intercept
    return y_avg - (x_avg * slope_);
}

// returns the calculated r^2 value for the model
double LinearRegression::calc_r2(){
    // calculate the average of y values
    double y_avg = 0;
    for (int i = 0; i < size_; i++)
        y_avg += y_vals_[i];
    y_avg /= size_;
    // calculate rss and tss
    double rss = 0;
    double tss = 0;
    double expected, y;
    for (int i = 0; i < size_; i++){
        expected = calc_val(x_vals_[i]);
        y = y_vals_[i];
        rss += (y - expected) * (y - expected);
        tss += (y - y_avg) * (y- y_avg);
    }
    // calculate r^2
    return 1 - (rss / tss);
}

// returns the predicted value for a given independent variable
double LinearRegression::calc_val(double x){
    return (x * slope_) + y_intercept_;
}

// fits the linear regression to the given data
void LinearRegression::fit(){
    // calculate the sums
    double x_sum = 0;
    double y_sum = 0; 
    double xy_sum = 0;
    double x_square_sum = 0;
    double x, y;
    for (int i = 0; i < size_; i++){
        x = x_vals_[i];
        y = y_vals_[i];
        x_sum += x;
        y_sum += y;
        xy_sum += x * y;
        x_square_sum += x * x;
    }
    slope_ = calc_slope(x_sum, y_sum, xy_sum, x_square_sum);
    y_intercept_ = calc_intercept(x_sum, y_sum);
}
