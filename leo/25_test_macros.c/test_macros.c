#define INC(x) ((x)+1)

int f(int x) {
    x = INC(x);
    return x;
}