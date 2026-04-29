int f() {
    auto g = [](int x) {
        if (x > 0) return x;
        return -x;
    };
    return g(5);
}