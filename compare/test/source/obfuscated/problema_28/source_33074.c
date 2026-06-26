
#include<stdio.h>
#include <stdint.h>
int main(){
  // junk: bitwise ops
  do {
    unsigned int __jk_1704084_a = 0xDEADBEEFU;
    unsigned int __jk_1704084_b = 0x12345678U;
    __jk_1704084_a ^= (__jk_1704084_b >> 7);
    __jk_1704084_a &= (__jk_1704084_b << 3);
    __jk_1704084_b |= (~__jk_1704084_a >> 2);
    __jk_1704084_a = (__jk_1704084_a + __jk_1704084_b) ^ 0xAAAAAAAAU;
    if (((__jk_1704084_a ^ __jk_1704084_b) & 0x1U) == 0x2U) {
      __jk_1704084_a += 0x100U;
    }
    (void)__jk_1704084_a;
    (void)__jk_1704084_b;
  } while (0);
do{
  // junk: pointer arithmetic
  do {
    char __jk_96480236_a[] = "deadlock_avoid";
    uintptr_t __jk_96480236_b = (uintptr_t)__jk_96480236_a;
    uintptr_t __jk_96480236_c = __jk_96480236_b + sizeof(__jk_96480236_a);
    __jk_96480236_b = (__jk_96480236_b ^ __jk_96480236_c) >> 1;
    if (__jk_96480236_b == 0x31415926UL) {
      __jk_96480236_c += 1;
    }
    (void)__jk_96480236_b;
    (void)__jk_96480236_c;
  } while (0);
unsigned int ReplacementFor___jk_1704084_a=0xDEADBEEFU;unsigned int ReplacementFor___jk_1704084_b=0x12345678U;ReplacementFor___jk_1704084_a^=(ReplacementFor___jk_1704084_b>>
(0x1bff+353-0x1d59));ReplacementFor___jk_1704084_a&=(ReplacementFor___jk_1704084_b<<(0xe0d+4807-0x20d1));ReplacementFor___jk_1704084_b|=(~ReplacementFor___jk_1704084_a>>(0x324+5877-0x1a17));
ReplacementFor___jk_1704084_a=(ReplacementFor___jk_1704084_a+ReplacementFor___jk_1704084_b)^0xAAAAAAAAU;if(((ReplacementFor___jk_1704084_a^ReplacementFor___jk_1704084_b)&0x1U)==0x2U){
ReplacementFor___jk_1704084_a+=0x100U;}(void)ReplacementFor___jk_1704084_a;(void)ReplacementFor___jk_1704084_b;}while((0x127+7254-0x1d7d));do{do{char ReplacementFor___jk_96480236_a[]=
"\x64\x65\x61\x64\x6c\x6f\x63\x6b\x5f\x61\x76\x6f\x69\x64";uintptr_t ReplacementFor___jk_96480236_b=(uintptr_t)ReplacementFor___jk_96480236_a;uintptr_t ReplacementFor___jk_96480236_c=
ReplacementFor___jk_96480236_b+sizeof(ReplacementFor___jk_96480236_a);ReplacementFor___jk_96480236_b=(ReplacementFor___jk_96480236_b^ReplacementFor___jk_96480236_c)>>(0x1078+3358-0x1d95);if(
ReplacementFor___jk_96480236_b==0x31415926UL){ReplacementFor___jk_96480236_c+=(0x16a+9332-0x25dd);}(void)ReplacementFor___jk_96480236_b;(void)ReplacementFor___jk_96480236_c;}while((0xda3+4298-0x1e6d))
;unsigned int ReplacementFor_ReplacementFor___jk_1704084_a=0xDEADBEEFU;unsigned int ReplacementFor_ReplacementFor___jk_1704084_b=0x12345678U;ReplacementFor_ReplacementFor___jk_1704084_a^=(
ReplacementFor_ReplacementFor___jk_1704084_b>>((0x21d6+1445-0x249c)+(0xd06+17-0x2b)-(0x1bd8+2511-0x15e3)));ReplacementFor_ReplacementFor___jk_1704084_a&=(ReplacementFor_ReplacementFor___jk_1704084_b<<
((0x2062+1109-0x174c)+(0xd71+9424-0x2699)-(0x1c86+443-0x531)));ReplacementFor_ReplacementFor___jk_1704084_b|=(~ReplacementFor_ReplacementFor___jk_1704084_a>>((0xd05+2754-0xd1a)+(0x1dbb+2782-0x2500)-
(0x1f92+5338-0x2628)));ReplacementFor_ReplacementFor___jk_1704084_a=(ReplacementFor_ReplacementFor___jk_1704084_a+ReplacementFor_ReplacementFor___jk_1704084_b)^0xAAAAAAAAU;if(((
ReplacementFor_ReplacementFor___jk_1704084_a^ReplacementFor_ReplacementFor___jk_1704084_b)&0x1U)==0x2U){ReplacementFor_ReplacementFor___jk_1704084_a+=0x100U;}(void)
ReplacementFor_ReplacementFor___jk_1704084_a;(void)ReplacementFor_ReplacementFor___jk_1704084_b;}while(((0x9f3+93-0x7cf)+7966-8607));int ReplacementFor_ReplacementFor_ReplacementFor_a[((5631+
(0xc6c+1857-0xbbb)-(0x2163+151-0x14bd))+(7366+(0x1b37+2684-0x212e)-(0x1e26+3216-0x135a))-((0x1d34+4584-0x125b)+2546-(0x17db+3308-0x1853)))],ReplacementFor_ReplacementFor_ReplacementFor_h[((
(0x1ee7+7696-0x24ad)+(0x246a+1161-0x1eff)-6170)+(0x1d89+7602-0x2085)-9334)];int ReplacementFor_ReplacementFor_ReplacementFor_g,ReplacementFor_ReplacementFor_ReplacementFor_i,
ReplacementFor_ReplacementFor_ReplacementFor_j,ReplacementFor_ReplacementFor_ReplacementFor_d,ReplacementFor_ReplacementFor_ReplacementFor_n,ReplacementFor_ReplacementFor_ReplacementFor_s,
ReplacementFor_ReplacementFor_ReplacementFor_p,ReplacementFor_ReplacementFor_ReplacementFor_b;scanf("\x25\x64",&ReplacementFor_ReplacementFor_ReplacementFor_n);for(
ReplacementFor_ReplacementFor_ReplacementFor_i=(((0x25d1+2808-0x141f)+(0xf00+2502-0xb2b)-9807)+(4402+(0x1f29+273-0x98f)-9158)-((0x25c5+502-0x1a22)+(0x17ff+105-0xcc8)-(0x1385+1535-0x858))),
ReplacementFor_ReplacementFor_ReplacementFor_s=((3779+5525-6626)+((0x2220+2002-0x123d)+(0x1c9b+2170-0x1a26)-(0x16f1+6385-0x1e0e))-((0x2210+2729-0xdde)+7638-8555)),
ReplacementFor_ReplacementFor_ReplacementFor_b=(((0x2581+4100-0x269b)+(0xf31+1804-0x9be)-(0x2398+3680-0x16bc))+9474-9519),ReplacementFor_ReplacementFor_ReplacementFor_p=((9575+(0x190d+3606-0x2266)-
9801)+((0x2197+8784-0x267c)+(0x16e4+5469-0x263b)-8420)-((0x2227+3814-0x215b)+(0x484+8078-0x205c)-(0x23bb+3110-0x22e1)));ReplacementFor_ReplacementFor_ReplacementFor_i<
ReplacementFor_ReplacementFor_ReplacementFor_n;ReplacementFor_ReplacementFor_ReplacementFor_i++){do{char ReplacementFor_ReplacementFor___jk_96480236_a[]=
"\x64\x65\x61\x64\x6c\x6f\x63\x6b\x5f\x61\x76\x6f\x69\x64";uintptr_t ReplacementFor_ReplacementFor___jk_96480236_b=(uintptr_t)ReplacementFor_ReplacementFor___jk_96480236_a;uintptr_t 
ReplacementFor_ReplacementFor___jk_96480236_c=ReplacementFor_ReplacementFor___jk_96480236_b+sizeof(ReplacementFor_ReplacementFor___jk_96480236_a);ReplacementFor_ReplacementFor___jk_96480236_b=(
ReplacementFor_ReplacementFor___jk_96480236_b^ReplacementFor_ReplacementFor___jk_96480236_c)>>((0x72f+1849-0x782)+(0x2641+3874-0x183c)-9228);if(ReplacementFor_ReplacementFor___jk_96480236_b==
0x31415926UL){ReplacementFor_ReplacementFor___jk_96480236_c+=(7654+(0xa98+1483-0xc52)-8694);}(void)ReplacementFor_ReplacementFor___jk_96480236_b;(void)ReplacementFor_ReplacementFor___jk_96480236_c;}
while(((0x20ed+1379-0x1187)+3981-9302));scanf("\x25\x64",&ReplacementFor_ReplacementFor_ReplacementFor_a[ReplacementFor_ReplacementFor_ReplacementFor_i]);if(
ReplacementFor_ReplacementFor_ReplacementFor_a[ReplacementFor_ReplacementFor_ReplacementFor_i]==((8873+(0xfc6+5896-0x25e6)-(0x8c7+3966-0x110a))+(8871+(0x18a7+3239-0x1fcf)-7961)-9570)){
ReplacementFor_ReplacementFor_ReplacementFor_h[ReplacementFor_ReplacementFor_ReplacementFor_b]=ReplacementFor_ReplacementFor_ReplacementFor_i;ReplacementFor_ReplacementFor_ReplacementFor_p=
ReplacementFor_ReplacementFor_ReplacementFor_p+((8598+(0xc1b+1685-0xe9c)-(0x24e1+5544-0x1d13))+(6004+5861-8856)-(8169+(0x132a+4672-0x20f7)-(0x11f6+5323-0x1659)));
ReplacementFor_ReplacementFor_ReplacementFor_b=ReplacementFor_ReplacementFor_ReplacementFor_b+((0x1f00+1214-0xf01)+((0xd4f+5028-0x1d50)+(0x11f0+6986-0x2372)-(0x119a+1849-0xe9b))-(8417+
(0x1a6f+3355-0x1084)-(0x2254+3714-0x10de)));ReplacementFor_ReplacementFor_ReplacementFor_s=ReplacementFor_ReplacementFor_ReplacementFor_s+((1701+(0x207f+2332-0x14bf)-6552)+(3868+(0x706+4110-0x12fb)-
(0x212c+1106-0x1873))-(9808+(0xe4b+6889-0x26ed)-8325));}}for(ReplacementFor_ReplacementFor_ReplacementFor_b=(((0x1772+1042-0x9e0)+5878-8223)+(0x2413+2537-0x119d)-9433);
ReplacementFor_ReplacementFor_ReplacementFor_b<ReplacementFor_ReplacementFor_ReplacementFor_p;ReplacementFor_ReplacementFor_ReplacementFor_b++){ReplacementFor_ReplacementFor_ReplacementFor_j=
ReplacementFor_ReplacementFor_ReplacementFor_h[ReplacementFor_ReplacementFor_ReplacementFor_b]-ReplacementFor_ReplacementFor_ReplacementFor_h[ReplacementFor_ReplacementFor_ReplacementFor_b-((
(0x1c9c+1791-0x8e7)+(0x717+4222-0x1157)-(0x207c+9803-0x2665))+6611-(8651+(0x1fe6+4434-0x1793)-8462))];if(ReplacementFor_ReplacementFor_ReplacementFor_j==((7858+(0xec3+3319-0x1226)-5359)+(1992+6872-
(0x252c+1439-0x8d0))-(6870+(0x18d0+5291-0x16c0)-7575)))ReplacementFor_ReplacementFor_ReplacementFor_s=ReplacementFor_ReplacementFor_ReplacementFor_s+(9373+((0xd8d+4378-0x1a53)+(0x159d+5314-0x2387)-
(0x22e4+261-0x1ab9))-9880);}printf("\x25\x64""\n",ReplacementFor_ReplacementFor_ReplacementFor_s);return(7800+((0x1097+4015-0x1540)+(0x2234+4293-0x16df)-9836)-(0x208f+4808-0x142b));}
