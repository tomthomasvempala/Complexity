#include <bits/stdc++.h>
using namespace std;

int fibo(int n)
{
    if (n < 2)
    {
        return 1;
    }
    return fibo(n - 1) + fibo(n - 2);
}

// Driver code
int main()
{

    freopen("gen_inputs/ip.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int i = 0; i < n; i++)
            {
                cout << v[i] << " ";
            }
            cout << endl;
        }
    }

    // Function call
    return 0;
}