int f(int x) {
    switch(x) {
        case 1:
        case 2:
            x += 1;
        case 3:
            x += 2;
            break;
        default:
            x = 0;
    }
    return x;
}