int f(int x) {
    if (x < 0) goto a;
    else goto b;

    try {
        if (x == 1) goto c;
    } catch (...) {
        goto d;
    }

    x = x + 1;
    goto fim;

a:
b:
c:
d:
fim:
    return x;
}
