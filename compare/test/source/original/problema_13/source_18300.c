#include <stdio.h>
int main()
{
    int n, Max, c = 0, f = -1, b = 0, t = 0, r = 0, z;
    scanf( "%d", &n );
    int a[n];
    for( z = 0; z < n; ++z )
    {
        scanf( "%d", &a[z] );
        if( z == 0 )Max = a[z];
        if( a[z] >= Max )Max = a[z];
    }
    while( 1 ){
    for( z = 0; z < n; ++z )
    {
        if( a[z] == c ){ ++c; a[z] = -1; ++r; }
        else if( a[z] < c && a[z] != -1 ){ ++c; a[z]=-1; ++r; }
    }
    ++f;
    if( r == n )break;
    for( z = n - 1; z >= 0; --z )
    {
        if( a[z] == c ){ ++c; a[z] = -1; ++r; }
        else if( a[z] < c && a[z] != -1 ){ ++c; a[z]=-1; ++r; }
    }
    ++b;
    if( r == n )break;
}
printf( "%d", f + b );
}