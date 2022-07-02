#include<iostream>
#include<cstdint>

using namespace std;

const uint64_t modulo = (uint64_t)(1e9 + 7);

uint64_t power(uint64_t a, uint64_t b){
	uint64_t s = 1;
	while(b > 0){
		if(b & 1)
			s = (s * (a % modulo)) % modulo;
		a = ((a % modulo) * (a % modulo)) % modulo;
		b >>= 1;
	}
	return s;
}

int main(){
	uint64_t a, b;
	cin >> a >> b;

	cout << power(a, b);
	return 0;
}