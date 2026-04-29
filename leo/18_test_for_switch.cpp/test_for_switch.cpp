int f(int x) {
    for (int i = 0; i < x; i++) {
        if (i % 2 == 0) continue;

        try {
            if (i == 5) throw i;
        } catch (...) {
            break;
        }
    }

    switch(x) {
        case 0:
            return 0;
        default:
            return x > 0 ? x : -x;
    }
}