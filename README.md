# LinRegLib
A library for simple Linear Regression written in C++

# Roadmap/ToDo:
<ul>
  <li>Flesh out unit tests.</li>
  <li>Add Multiple Linear Regressions</li>
</ul>

<h2>API:</h2>
<h3>The LinearRegression Class</h3>

A `LinearRegression` object represents a simple linear regression model.
### Class Attributes:
<dl>
  <dt><code>private vector&lt;double&gt; x_vals_</code></dt>
  <dd>A vector of all of the independent variables in the dataset</dd>
  <dt><code>private vector&lt;double&gt; y_vals_</code></dt>
  <dd>A vector of all of the dependent variables in the dataset</dd>
  <dt><code>private size_t size_</code></dt>
  <dd>The number of variables in the data set. Does not count dependent and independent variables seprately. For example, if <code>x_vals_ = {1, 2, 3, 4, 5}</code> and <code>y_vals_ = {2, 4, 6, 8, 10}</code>, <code>size_ = 5</code>.</dd>
  <dt><code>private double slope_</code></dt>
  <dd>The slope of the linear regression</dd>
  <dt><code>private double y_intercept_</code></dt>
  <dd>The y-intercept of the linear regression</dd>
</dl>

### Public Methods:
<dl>
  <dt><code>LinearRegression()</code></dt>
  <dd>The default constructor for a linear regression. Sets <code>size_</code>, <code>slope_</code> and <code>y_intercept_</code> to zero.</dt>
  <dt><code>LinearRegression(std::vector&lt;double&gt; &x, std::vector&lt;double&gt; &y)</code></dt>
  <dd>Generic constructor for the linear regression. Automatically sets the data and fits the model to <code>x</code> and <code>y</code>. Throws an error if <code>x</code> and <code>y</code> are not the same size.</dd>
  <dt><code>int set_data(std::vector&lt;double&gt; &x, std::vector&lt;double&gt; &y)</code></dt>
  <dd>Sets <code>x_values_</code> to <code>x</code> and <code>y_values_</code> to <code>y</code>. If <code>x</code> and <code>y</code> are not the same size, the attributes are not set and function returns -1.</dd>
  <dt><code>void fit()</code></dt>
  <dd>Fits the data provided with <code>set_value</code> to the model by calculating the slope and y-intercept with it</dd>
  <dt><code>void fit(std::vector<double> &x, std::vector<double> &y)</code></dt>
  <dd>Sets the model's data to <code>x</code> and <code>y</code>, and fits the data. Throws an error if <code>x</code> and <code>y</code> are not the same size.</dd>
  <dt><code>double calc_val(double independent)</code></dt>
  <dd>Calculates and returns the expected value for <code>independent</code></dd>
  <dt><code>double calc_r2();</code></dt>
    <dd>Calculates and returns the coefficient of determination.</dd>
</dl>
