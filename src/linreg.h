#ifndef LinRegLib
#define LinRegLib

#include <vector>

class LinearRegression{
    protected:
        size_t size_;
        double slope_;
        double y_intercept_;
        std::vector<double> y_vals_;

    public:  
        virtual double calc_r2() = 0;
        // simple getters
        double get_slope() {return slope_;}
        double get_intercept() {return y_intercept_;}
        double get_size() {return size_;}
};
 

class SimpleLinearRegression : public LinearRegression{
    private:
        std::vector<double> x_vals_;
        double calc_slope(double sum_x, double sum_y, double xy_sum, double x_square_sum);
        double calc_intercept(double x_sum, double y_sum);
    public:
        SimpleLinearRegression();
        SimpleLinearRegression(std::vector<double> &x, std::vector<double> &y);
        int set_data(std::vector<double> &x, std::vector<double> &y);
        void fit();  
        void fit(std::vector<double> &x, std::vector<double> &y);
        double calc_val(double independent);   
        double calc_r2();
};

#endif
