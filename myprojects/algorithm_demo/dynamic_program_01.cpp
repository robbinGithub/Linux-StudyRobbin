#include <stdio.h>
#include <stdlib.h>
using namespace std;

int f( int n ){
	if(n <= 1)
		return n;
	// 先创建一个数组来保存历史数据
	int[] dp = new int[n+1];
	// 给出初始值
	dp[0] = 0;
	dp[1] = 1;
	// 通过关系式来计算出 dp[n]
	for(int i = 2; i <= n; i++){
		dp[i] = dp[i-1] + dp[-2];
	}
	// 把最终结果返回
	return dp[n];
}

int main()
{
	return 0;
}
