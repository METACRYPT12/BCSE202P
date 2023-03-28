// Tower of Hanoi

#include <iostream>

void ToH(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1)
    {
        printf("Moved disk %d from %c to %c\n", n, from_rod, to_rod);
        return;
    }
    ToH(n - 1, from_rod, aux_rod, to_rod);
    printf("Moved disk %d from %c to %c\n", n, from_rod, to_rod);
    ToH(n - 1, aux_rod, to_rod, from_rod);
    return;
}

int main()
{
    ToH(3, 'A', 'C', 'B');
    return 0;
}
