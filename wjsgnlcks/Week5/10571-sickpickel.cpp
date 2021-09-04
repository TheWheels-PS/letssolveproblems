#include <bits/stdc++.h>
#define Max 201

using namespace std;

int dp[Max];
pair<double, double> diamond[Max];

void solve(){
	
	int N, answer = 0;
	cin >> N;
	
	for(int i = 1; i <= N; i++){
		cin >> diamond[i].first >> diamond[i].second;
	}
		
	for(int i = 1; i <= N; i++){
		dp[i] = 1;
		for(int j = 1; j < i; j++){
			if(diamond[j].first < diamond[i].first && diamond[j].second > diamond[i].second) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		answer = max(answer, dp[i]);
	}
	
	cout << answer << "\n";
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);	
	int T; cin >> T;
	while(T--) solve();
	return 0;
}