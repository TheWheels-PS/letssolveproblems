// 진법 변환 2
#include <bits/stdc++.h>

using namespace std;

void print(int number){
	if(number >= 10){
		cout << (char)(number + 55);	
	}
	else cout << number;
}

int main(void){
 	vector<int> vec;	
	int n, digit_limit; 
	cin >> n >> digit_limit;	
	
	while(1){
		vec.push_back(n % digit_limit);
		n /= digit_limit;
		if(n == 0) break;
	}	
	
	for(int i = vec.size() - 1; i >= 0; i--){
		print(vec[i]);
	}
	return 0;
}