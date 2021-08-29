// 여왕벌
#include <bits/stdc++.h>

using namespace std;

int M, N;

void printAns(vector<int>& update){
	for(int i = M - 1; i < 2 * M - 1; i++){
		cout << update[i] + 1 << " ";
	}
	cout << "\n";
	
	for(int i = 1; i < M; i++){
		cout << update[M - i - 1] + 1 << " ";
		
		for(int j = M; j < 2 * M - 1; j++){
			cout << update[j] + 1 << " ";
		}
		cout << "\n";
	}	
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);	cout.tie(NULL);
	cin >> M >> N;
	vector<int> update(2 * M - 1, 0);	
	
	for(int i = 0; i < N; i++){
		int count0, count1, count2;
		cin >> count0 >> count1 >> count2;
		update[count0] += 1;
		update[count0 + count1] += 1;
	}
	for(int i = 1; i < 2 * M - 1; i++){
		update[i] += update[i - 1];
	}
	printAns(update);	
	return 0;
}