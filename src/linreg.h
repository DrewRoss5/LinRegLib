#include <vector>

class LinearRegression{
    private:
        std::vector<double> x_vals_;
        std::vector<double> y_vals_;
        size_t size_;
        double slope_;
        double y_intercept_;
        double calc_slope(double sum_x, double sum_y, double xy_sum, double x_square_sum);
        double calc_intercept(double x_sum, double y_sum);
    public:
        LinearRegression();
        LinearRegression(std::vector<double> &x, std::vector<double> &y);
        int set_data(std::vector<double> &x, std::vector<double> &y);
        void fit();  
        double calc_val(double independent);   
        double calc_r2();
        // getters
        double get_slope() {return slope_;}
        double get_intercept() {return y_intercept_;}
        double get_size() {return size_;}
};