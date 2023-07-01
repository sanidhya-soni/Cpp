#include<iostream>
using namespace std;

int main() {

    // int arr[10] = {1, 2, 3, 4};
    // int* p = arr;
    // cout << sizeof(arr) << endl;
    // cout << sizeof(&p) << endl;
    // cout << 2[arr] << endl;
    // cout << *(arr + 1) << endl;

    // char ch[4] = "San";

    // cout << ch << endl;

    // printf("%s", ch);

    // char ch[3] = "ka";
    // char ch = 'k';
    // char (*cptr)[3] = &ch[0];
    // char *cptr = &ch[0];
    // char *cptr = &ch;
    // cout << endl << cptr << endl;


    // int a = 10;
    // int *b = &a;
    // int **c = &b;
    // int ***d = &c;
    // int ****e = &d;
    // int *****f = &e;

    // cout << endl << ***d << endl;

    // cout << &a << endl;
    // cout << *c << endl;
    // cout << &b << endl;
    // cout << c << endl;


    // Reference Variabbles

    int a = 10;
    int &b = a;

    cout << a << endl;
    cout << b << endl;

    a++;

    cout << a << endl;
    cout << b << endl;

    b++;

    cout << a << endl;
    cout << b << endl;

    return 0;
}
