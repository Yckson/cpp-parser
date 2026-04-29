int f() {
    for (int i = 0, j = 10; i < j; i++, j--) {
        if (i == j) break;
    }
    return 0;
}