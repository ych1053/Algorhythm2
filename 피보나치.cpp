#include <iostream>

int f(int n) {

	int a = 1;
	int b = 1;
	int r = 0;

	for (int i = 2; i <= n; ++i) {
		r = a + b;
		a = b;
		b = r;
	}
	return r;
}

int main() {
	int n = 2;
	std::cout << f(n) << std::endl;
	return 0;
}
