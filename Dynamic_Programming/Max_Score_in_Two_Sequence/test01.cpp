#include <iostream>
#include <vector>


template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T> &v){
	for(size_t i=0; i < v.size(); ++i){
			os << v[i] << " ";
	}
	os << "\n";
	return os;
}

int f(std::vector<std::vector<int>> v){
	int n = v.size();
	std::vector<std::vector<int>> dp(n, std::vector<int>(2));
	

	for(int i = 0; i < n; ++i){
		
	}
	return 0;
}

int main(int argc, char *argv[]){
	int n;
	int cost; // cost of switching between two sequence
	int a, b;
	std::cin >> n;
	std::cin >> cost;
	// start at v.first
	std::vector<std::vector<int>> v(n, std::vector<int>(2));
	for(int i = 0; i < n; ++i){
		std::cin >> v[0][i] >> v[1][i];
	}
	
	std::cout << f(v);
	return 0;
}
