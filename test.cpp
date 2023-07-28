#include <iostream>

void swap(int &x, int &y)
{
    int tmp = x;
    x = y;
    y = tmp;
    return;
}

int main()
{
    int x = 12;
    int y = 1234;
    swap(x, y);
    std::cout << x << " " << y;
}