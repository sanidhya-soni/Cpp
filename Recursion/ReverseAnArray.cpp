#include <iostream>
using namespace std;

void reverse(int a[], int l, int r)
{
    if(l >= r)
        return;
    
    swap(a[l], a[r]);

    reverse(a, l + 1, r - 1);
}

int main()
{
    int a[] = {5, 4, 3, 2, 1};
    int len = sizeof(a)/sizeof(0);

    // for(int i = 0; i < len; i++)
    // {
    //     cout << *(a + i) << endl;
    // }

    reverse(a, 0, len - 1);

    for(int i = 0; i < len; i++)
    {
        cout << *(a + i) << endl;
    }

    return 0;
}
