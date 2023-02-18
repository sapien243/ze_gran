#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    vector<int> arr = {4, 2, 6, 1, 3, 7, 5};
    int n = arr.size(), temp = 0;
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (arr[min] > arr[j])
                min = j;
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
        for (int k = 0; k < n; k++)
            cout << arr[k];
        cout << endl;
    }
    return 0;
}