# include <cstdio>
#include <cstdlib>
#define TESTE(a, b) (a + b)

int f0() {
    int x = 2;
    x = x + 5;
    if(x < 0) {
        x++;
        x--;
        x+=x;
    }
    x = 0;
    x = 1;
    return 3;
}

void f1(int a) {
    a = a % 10;
    do {
        a = a + 1;
        a = a / 2;
    }
    while(a > 0);
}

int f2(int b) {
    b = b << 1;
    b = b >> 1;
    b = b * b;
    if(b > 0) {
        b = b + b;
        b -= 7;
    }
    else if(b < 1) {
        b = b * b * b;
        b++;
    }
    else
        b--;
    return -1;
}

void f3() {
    int y = 9;
    y++;
    y--;
    while(y > 0) y--;
}

void f4() {
    int i, y = 9;
    y++;
    y--;
    for(i = 0; i < y; i++) y = y * 2;
}

unsigned int f5(unsigned n) {
    init:
        unsigned int a = 0;
    loop1:
        a += 1;
    loop2:
        a += 1;
        if(a < n / 2) goto loop2;
        else if(a < n) goto loop1;
        else goto end;
    end:
        return a;
}

int main(int argc, char* argv[]) {
    int a, b;
    a = 15;
    b = 10;
    f1(a);
    b = f2(b);
    switch(a) {
        case 0:
            a++;
            break;
        case 1:
            a--;
            break;
        case 2:
            a = a * 2;
        case 4:
            a = a << 1;
        case 5:
        case 6:
        case 7:
            a = b * b * b;
            break;
        default:
            a = a + b + a + b;
            if(a == b) a = a + 1;
            else if(a > b) b = b + 1;
            else if(b > a) b = a * b;
            else a = b;
            a = a;
    }
    b = a + b + argc;
    a = (a > b) ? (a + a) : (b + 5 + 8 + 13);
    for(a = 0; a < 100; a++) {
        a = a - a + a;
        a = a - a - a + a + a;
        for(b = 0; b < 1000; b++) {
            b = b - b + b;
            b = b - b - b + b + b;
            while(a < b) {
                a *= 1;
                b /= 1;
            }
            a = a + b - b - a + a;
        }
    }
    ++a;
    --b;
    return 0;
}
