#include <iostream>

using namespace std;

int main(void)
{
    char temp = 'o', arr[] = "rwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwbrwb";
    //				     (0,i,j)					    			(k,n)
    //				    	  rrrrrrrrrrrrrwwwwwwwwwwwwwbbbbbbbbbbbbb
    //						 (0)          (i)		  (j,k)		    (n)
    int n = 39;
    int i = 0 /*r rt lmt*/, j = i /*w rt lmt*/, k = n /*b lt fst*/;
    while (j != k)
    {
        if (arr[j] == 'r')
        {
            temp = arr[i], arr[i] = arr[j], arr[j] = temp;
            i++, j++;
        }
        else if (arr[j] == 'w')
            j++;
        else if (arr[j] == 'b')
        {
            k--;
            temp = arr[j], arr[j] = arr[k], arr[k] = temp;
        }
    }
    cout << arr << endl;

    return 0;
}