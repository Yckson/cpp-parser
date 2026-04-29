int f(int x) {
    switch(x) {
        case 1:
        case 2:
            x++;
            break;
        case 3:
            x += 2;
        default:
            x = 0;
    }
    return x;
}