#include <iostream>
#include <vector>

using namespace std;

vector<int> join(vector<int> arr1, vector<int> arr2);
vector<int> mergeSort(vector<int> arr);

int main()
{
    vector<int> arr1 = {10, 9, 4, 1, 5, 3, 2, 7, 8, 6, 1, 10, 3};
    vector<int> arrm = mergeSort(arr1);
    int n = arrm.size();
    for (int i = 0; i < n; i++)
        cout << arrm[i] << " ";
    cout << endl;
    return 0;
}

vector<int> mergeSort(vector<int> arr)
{
    int n = arr.size();
    if (n == 1)
        return arr;
    else
    {
        vector<int> left(arr.begin(), arr.begin() + (n / 2));
        vector<int> riht(arr.begin() + (n / 2), arr.end());
        left = mergeSort(left), riht = mergeSort(riht);
        return join(left, riht);
    }
}

vector<int> join(vector<int> arr1, vector<int> arr2)
{
    int a = 0, b = 0, m = arr1.size(), n = arr2.size();
    vector<int> arro;
    while (true)
    {
        if (arr1[a] <= arr2[b])
            arro.push_back(arr1[a]), a++;
        else
            arro.push_back(arr2[b]), b++;

        if (a == m)
        {
            arro.insert(arro.end(), arr2.begin() + b, arr2.end());
            break;
        }
        if (b == n)
        {
            arro.insert(arro.end(), arr1.begin() + a, arr1.end());
            break;
        }
    }
    return arro;
}