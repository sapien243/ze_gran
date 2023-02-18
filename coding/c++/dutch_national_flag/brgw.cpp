#include <iostream>

using namespace std;

int main(void)
{
    char temp = 'o', arr[] = "brgwbrgwbrgwbrgwbrgwbrgwbrgwbrgwbrgwbrgw";
    //                        0                                      (i,j,k,l,n)
    //                        bbbbbbbbbbrrrrrrrrrrggggggggggwwwwwwwwww
    //                     (0,i)       (j)       (k)       (l)       (n)
    int n = 40;
    int i = n /*b rt fst*/, j = n /*r rt fst*/;
    int k = n /*r rt fst*/, l = n /*r rt fst*/;
    while (i != 0)
    {
        i--;
        if (arr[i] == 'b')
            continue;
        else if (arr[i] == 'r')
        {
            j--;
            temp = arr[i], arr[i] = arr[j], arr[j] = temp;
        }
        else if (arr[i] == 'g')
        {
            j--, k--;
            temp = arr[i], arr[i] = arr[j], arr[j] = arr[k], arr[k] = temp;
        }
        else if (arr[i] == 'w')
        {
            j--, k--, l--;
            temp = arr[i], arr[i] = arr[j], arr[j] = arr[k], arr[k] = arr[l], arr[l] = temp;
        }
    }
    cout << arr << endl;

    return 0;
}