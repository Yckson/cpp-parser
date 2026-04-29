int f(int x) {
    if (x < 0) goto neg;
    if (x == 0) goto zero;
    return 1;

neg:
    return -1;

zero:
    return 0;
}