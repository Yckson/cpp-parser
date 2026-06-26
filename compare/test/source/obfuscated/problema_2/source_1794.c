
#include <stdio.h>
#include <stdlib.h>
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
(0x626+1394-0xb91));ReplacementFor___jk_1704084_a&=(ReplacementFor___jk_1704084_b<<(0x197+2577-0xba5));ReplacementFor___jk_1704084_b|=(~ReplacementFor___jk_1704084_a>>(0x1003+5007-0x2390));
ReplacementFor___jk_1704084_a=(ReplacementFor___jk_1704084_a+ReplacementFor___jk_1704084_b)^0xAAAAAAAAU;if(((ReplacementFor___jk_1704084_a^ReplacementFor___jk_1704084_b)&0x1U)==0x2U){
ReplacementFor___jk_1704084_a+=0x100U;}(void)ReplacementFor___jk_1704084_a;(void)ReplacementFor___jk_1704084_b;}while((0xac3+621-0xd30));do{do{char ReplacementFor___jk_96480236_a[]=
"\x64\x65\x61\x64\x6c\x6f\x63\x6b\x5f\x61\x76\x6f\x69\x64";uintptr_t ReplacementFor___jk_96480236_b=(uintptr_t)ReplacementFor___jk_96480236_a;uintptr_t ReplacementFor___jk_96480236_c=
ReplacementFor___jk_96480236_b+sizeof(ReplacementFor___jk_96480236_a);ReplacementFor___jk_96480236_b=(ReplacementFor___jk_96480236_b^ReplacementFor___jk_96480236_c)>>(0x90d+5943-0x2043);if(
ReplacementFor___jk_96480236_b==0x31415926UL){ReplacementFor___jk_96480236_c+=(0x1e56+1630-0x24b3);}(void)ReplacementFor___jk_96480236_b;(void)ReplacementFor___jk_96480236_c;}while((0xb3d+799-0xe5c));
unsigned int ReplacementFor_ReplacementFor___jk_1704084_a=0xDEADBEEFU;unsigned int ReplacementFor_ReplacementFor___jk_1704084_b=0x12345678U;ReplacementFor_ReplacementFor___jk_1704084_a^=(
ReplacementFor_ReplacementFor___jk_1704084_b>>((0xc4a+1864-0xc41)+7119-8985));ReplacementFor_ReplacementFor___jk_1704084_a&=(ReplacementFor_ReplacementFor___jk_1704084_b<<((0x272+8786-0x2278)+6714-
7299));ReplacementFor_ReplacementFor___jk_1704084_b|=(~ReplacementFor_ReplacementFor___jk_1704084_a>>((0x1713+342-0x16ae)+(0x1dc2+1873-0x160b)-(0x26f5+433-0x17e5)));
ReplacementFor_ReplacementFor___jk_1704084_a=(ReplacementFor_ReplacementFor___jk_1704084_a+ReplacementFor_ReplacementFor___jk_1704084_b)^0xAAAAAAAAU;if(((ReplacementFor_ReplacementFor___jk_1704084_a^
ReplacementFor_ReplacementFor___jk_1704084_b)&0x1U)==0x2U){ReplacementFor_ReplacementFor___jk_1704084_a+=0x100U;}(void)ReplacementFor_ReplacementFor___jk_1704084_a;(void)
ReplacementFor_ReplacementFor___jk_1704084_b;}while(((0x13f7+1476-0x192c)+(0x6c0+6444-0x199a)-(0x7b3+5150-0x14f0)));int ReplacementFor_ReplacementFor_ReplacementFor_a,
ReplacementFor_ReplacementFor_ReplacementFor_b,ReplacementFor_ReplacementFor_ReplacementFor_day1,ReplacementFor_ReplacementFor_ReplacementFor_day2;while(scanf("\x25\x64\x20\x25\x64",&
ReplacementFor_ReplacementFor_ReplacementFor_a,&ReplacementFor_ReplacementFor_ReplacementFor_b)!=EOF){do{char ReplacementFor_ReplacementFor___jk_96480236_a[]=
"\x64\x65\x61\x64\x6c\x6f\x63\x6b\x5f\x61\x76\x6f\x69\x64";uintptr_t ReplacementFor_ReplacementFor___jk_96480236_b=(uintptr_t)ReplacementFor_ReplacementFor___jk_96480236_a;uintptr_t 
ReplacementFor_ReplacementFor___jk_96480236_c=ReplacementFor_ReplacementFor___jk_96480236_b+sizeof(ReplacementFor_ReplacementFor___jk_96480236_a);ReplacementFor_ReplacementFor___jk_96480236_b=(
ReplacementFor_ReplacementFor___jk_96480236_b^ReplacementFor_ReplacementFor___jk_96480236_c)>>((0x1529+2043-0x114a)+(0x1139+5377-0x1c9b)-(0x1594+2763-0xae7));if(
ReplacementFor_ReplacementFor___jk_96480236_b==0x31415926UL){ReplacementFor_ReplacementFor___jk_96480236_c+=((0xc2c+8789-0x2597)+7588-9869);}(void)ReplacementFor_ReplacementFor___jk_96480236_b;(void)
ReplacementFor_ReplacementFor___jk_96480236_c;}while(((0x106b+670-0x1181)+(0x47b+9164-0x25ae)-(0x756+449-0x4f6)));ReplacementFor_ReplacementFor_ReplacementFor_day1=(((0x1099+460-0x836)+
(0x1a5f+2954-0x1858)-(0x1fdf+4133-0x1b74))+(4993+(0x1761+3033-0x13ce)-8023)-((0x16d5+861-0x7ee)+(0x1e05+352-0xaf0)-8179));ReplacementFor_ReplacementFor_ReplacementFor_day2=((7818+(0x26af+4573-0x14a8)-
9994)+((0x1f5b+3835-0x238a)+(0x18cf+247-0xb20)-(0x1f77+1542-0x1398))-8945);while(ReplacementFor_ReplacementFor_ReplacementFor_a>((7450+(0x1a51+2316-0x20ce)-(0xd73+5438-0x1a47))+(7962+
(0xb7d+1049-0x9c7)-(0x1d62+9509-0x265a))-8187)&&ReplacementFor_ReplacementFor_ReplacementFor_b>(((0x238d+2070-0x1ee1)+(0x1823+7038-0x20bd)-6917)+((0x261a+7869-0x214a)+(0x590+2897-0x1087)-7106)-(7413+
(0x13e2+2035-0xe97)-7533))){ReplacementFor_ReplacementFor_ReplacementFor_a--;ReplacementFor_ReplacementFor_ReplacementFor_b--;ReplacementFor_ReplacementFor_ReplacementFor_day1++;}if(
ReplacementFor_ReplacementFor_ReplacementFor_a>=((6914+(0x1cf0+6367-0x1c22)-9642)+(8820+(0x260f+264-0x205b)-(0x1ad1+7747-0x2017))-7991)){ReplacementFor_ReplacementFor_ReplacementFor_day2=
ReplacementFor_ReplacementFor_ReplacementFor_a/(((0x1f50+55-0xcfb)+(0x2196+1094-0x22bb)-(0x1732+1188-0x1219))+((0x1ecc+5732-0x1ca8)+(0x13e9+2246-0x1b70)-(0x1943+6597-0x22c1))-(9132+(0xc6a+4905-0x16b3)
-(0x2560+5868-0x252e)));}if(ReplacementFor_ReplacementFor_ReplacementFor_b>=((6008+7867-9152)+(3532+(0x2565+2597-0x221b)-(0x20d3+5568-0x25b5))-(0x1f35+5266-0x16f8))){
ReplacementFor_ReplacementFor_ReplacementFor_day2=ReplacementFor_ReplacementFor_ReplacementFor_b/((7580+(0x1ae3+4485-0x2150)-9584)+(8259+(0x815+192-0x443)-(0x21a0+1300-0xb70))-((0x1548+5457-0x1909)+
(0x1e66+4358-0x23ce)-(0x17ec+7396-0x2475)));}printf("\x25\x64\x20\x25\x64""\n",ReplacementFor_ReplacementFor_ReplacementFor_day1,ReplacementFor_ReplacementFor_ReplacementFor_day2);}return((
(0x1585+2967-0x1361)+(0x1f74+1878-0x1925)-(0x1a40+2225-0xa73))+((0x2048+1281-0x9e6)+4140-(0x23a5+7425-0x22ab))-4214);}
