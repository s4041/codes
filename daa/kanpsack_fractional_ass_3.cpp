#include <bits/stdc++.h>
using namespace std;

// Define a custom comparison function for sorting items by value-to-weight ratio
bool compareItems(pair<int, int> item1, pair<int, int> item2)
{
    double ratio1 = static_cast<double>(item1.first) / item1.second;
    double ratio2 = static_cast<double>(item2.first) / item2.second;
    return ratio1 > ratio2;
}

int main()
{
    int n; // Number of items
    cin >> n;
    vector<pair<int, int>> items(n); // Create a vector of pairs to store item values and weights

    // Input the values and weights of the items
    for (int i = 0; i < n; i++)
    {
        cin >> items[i].first >> items[i].second;
    }

    int knapsackCapacity; // Capacity of the knapsack
    cin >> knapsackCapacity;

    // Sort the items by value-to-weight ratio in descending order
    sort(items.begin(), items.end(), compareItems);

    double maxValue = 0; // Initialize the maximum value

    // Iterate through the sorted items and determine how much to take
    for (int i = 0; i < n; i++)
    {
        int value = items[i].first;
        int weight = items[i].second;

        if (knapsackCapacity >= weight)
        {
            // If the item can fit entirely in the knapsack, add its value to the total
            maxValue += value;
            knapsackCapacity -= weight;
        }
        else
        {
            // If the item cannot fit entirely, add a fraction based on available capacity
            double fraction = static_cast<double>(knapsackCapacity) / weight;
            maxValue += fraction * value;
            knapsackCapacity = 0; // The knapsack is now full
            break;
        }
    }

    cout << maxValue << endl; // Output the maximum value that can be obtained
}
