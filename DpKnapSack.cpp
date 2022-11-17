#include <iostream>
using namespace std;
// max function to find out maximum values from the given 2 values
int max(int x, int y)
{
    return (x > y) ? x : y; // max function to find max function among 2 differnt values
}
// 0/1 Knapsack function definition
int knapSack(int k_capacity, int w[], int p[], int n)
{
    int i, j;
    int A[n + 1][k_capacity + 1]; // 2D array which will store the values(Matrix)
    // scan for every object
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= k_capacity; j++)
        { //..........intialize the matrix
            if (i == 0 || j == 0)
            {
                A[i][j] = 0;
            } //............initialize the first row and first column of the
            else if (w[i - 1] <= j)
            { //..................till the weight is grater than w[i-1] execute the else
                A[i][j] = max(A[i - 1][j], p[i - 1] + A[i - 1][j - w[i - 1]]);
            } //.......... calculating max value for every entry

            else
            {
                A[i][j] = A[i - 1][j];
            } //............copy the values from above row
        }
    }
    int profit = A[n][k_capacity];
    // cout<<"profit is:"<<profit<<"\n";
    // return A[n][k_capacity];//..............last box of matrix holda a maximum profit
    return A[n][k_capacity];
}
int main()
{
    cout << "Enter the number of objects for a Knapsack:"; // accept the number of objects  from user
    int n, K_capacity;
    cin >> n;
    int p[n], w[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Profit and weight for item using space " << i+1 << ":"; // accept the profit and weight values
        cin >> p[i];
        cin >> w[i];
    }
    cout << "Enter the capacity of knapsack"; // enter the knapsack capacity
    cin >> K_capacity;
    cout << "Maximum Profit is:" << knapSack(K_capacity, w, p, n);
    // fuction call for knapsack
    return 0;
}
