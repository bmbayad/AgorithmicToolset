#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
	double value = 0.0;
	double W = capacity;
	int size = weights.size();

	vector<double> V(size);
	vector<double> value_per_unit_weight_vector(size);
	for (size_t i = 0; i < size; i++)
	{
		value_per_unit_weight_vector[i] = (double)values[i]/weights[i];
	}


	for (size_t i = 0; i < size; i++)
	{
		if (W == 0) {
			return value;
		}
		
		
		int max_i = std::distance(std::begin(value_per_unit_weight_vector), std::max_element(std::begin(value_per_unit_weight_vector), std::end(value_per_unit_weight_vector)));
		double a;
		if (weights[max_i] > 0) {
			if (W > weights[max_i]) {
				a = weights[max_i];
			}
			else {
				a = W;
			}

			value = value + a*value_per_unit_weight_vector[max_i];
			value_per_unit_weight_vector[max_i] = values[max_i]  - (a*value_per_unit_weight_vector[max_i]);

			weights[max_i] -= a;
			V[max_i] += a;
			W-=a;
		}

	}

	// write your code here

	return value;
}

int main() {
	int n;
	int capacity;
	std::cin >> n >> capacity;
	vector<int> values(n);
	vector<int> weights(n);
	for (int i = 0; i < n; i++) {
		std::cin >> values[i] >> weights[i];
	}

	double optimal_value = get_optimal_value(capacity, weights, values);

	std::cout.precision(10);
	std::cout << optimal_value << std::endl;
	return 0;
}
