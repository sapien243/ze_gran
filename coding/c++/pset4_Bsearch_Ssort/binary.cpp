#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    vector<int> arr = {2, 4, 5, 7, 8, 9, 12, 14, 17, 19, 22, 25, 27, 28, 33, 37};
    int n = arr.size(), num = 42;
    int max = n - 1, min = 0, mid = 0;
    while (max >= min)
    {
        mid = (max + min) / 2;
        cout << min << " " << mid << " " << max << endl;
        if (num == arr[mid])
        {
            cout << arr[mid] << endl;
            break;
        }
        else if (num < arr[mid])
            max = mid - 1;
        else if (num > arr[mid])
            min = mid + 1;
    }
    return 0;
}