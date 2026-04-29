int f(int x) {
    try {
        if (x == 0) throw 1;
        if (x < 0) throw 2;
        return x;
    } catch (int e) {
        return -e;
    } catch (...) {
        return 0;
    }
}