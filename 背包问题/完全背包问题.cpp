/*
有 N 件物品和一个容量是 V 的背包。每件物品无限使用。第 i 件物品的体积是 vi，价值是 wi。
求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。输出最大价值。
输入格式
第一行两个整数，N，V，用空格隔开，分别表示物品数量和背包容积。
接下来有 N 行，每行两个整数 vi,wi，用空格隔开，分别表示第 i 件物品的体积和价值。
输出格式
输出一个整数，表示最大价值。
*/

#include <iostream>

using namespace std;

const int N = 1001;

int v[N], w[N];
int f[N];

int main()
{
    int number, volume;
    cin >> number >> volume;

    for (int i = 1; i <= number; i++)
    {
        cin >> v[i] >> w[i];
    }

    // 动态规划求解, f[j]表示总体积小于等于j的最大价值(i表示之选择前i个物品)
    for (int i = 1; i <= number; i++)
    {
        for (int j = v[i]; j <= volume; j++)
        {
            // 对其进行优化，当确定了f[i][j]后，f[i][j+v[i]]= max(f[i-1][j+v[i],]f[i][j]+w[i])
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }

    cout << f[volume] << endl;
    return 0;
}