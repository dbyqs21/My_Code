#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> input_o;
	vector<int> input_e;
	for (auto i = 0; i < n; ++i) {
		int temp;
		cin >> temp;
		if (i % 2 == 0)
			input_o.push_back(temp);
		else
			input_e.push_back(temp);
	}
	vector<int> result;
	if (n % 2 == 0) {
		reverse(input_e.begin(), input_e.end());
		result.insert(result.begin(), input_o.begin(), input_o.end());
		result.insert(result.begin(), input_e.begin(), input_e.end());
	}
	else {
		reverse(input_o.begin(), input_o.end());
		result.insert(result.begin(), input_e.begin(), input_e.end());
		result.insert(result.begin(), input_o.begin(), input_o.end());
	}
	for (auto i = 0; i < n - 1; ++i) {
		cout << result[i] << " ";
	}
	cout << result.at(n - 1) << endl;
	system("pause");
	return 0;
}