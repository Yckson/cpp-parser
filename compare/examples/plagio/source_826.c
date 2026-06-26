
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
(0xd46+4334-0x1e2d));ReplacementFor___jk_1704084_a&=(ReplacementFor___jk_1704084_b<<(0xa7c+522-0xc83));ReplacementFor___jk_1704084_b|=(~ReplacementFor___jk_1704084_a>>(0x15+4418-0x1155));
ReplacementFor___jk_1704084_a=(ReplacementFor___jk_1704084_a+ReplacementFor___jk_1704084_b)^0xAAAAAAAAU;if(((ReplacementFor___jk_1704084_a^ReplacementFor___jk_1704084_b)&0x1U)==0x2U){
ReplacementFor___jk_1704084_a+=0x100U;}(void)ReplacementFor___jk_1704084_a;(void)ReplacementFor___jk_1704084_b;}while((0x9d7+3325-0x16d4));do{do{char ReplacementFor___jk_96480236_a[]=
"\x64\x65\x61\x64\x6c\x6f\x63\x6b\x5f\x61\x76\x6f\x69\x64";uintptr_t ReplacementFor___jk_96480236_b=(uintptr_t)ReplacementFor___jk_96480236_a;uintptr_t ReplacementFor___jk_96480236_c=
ReplacementFor___jk_96480236_b+sizeof(ReplacementFor___jk_96480236_a);ReplacementFor___jk_96480236_b=(ReplacementFor___jk_96480236_b^ReplacementFor___jk_96480236_c)>>(0x322+8666-0x24fb);if(
ReplacementFor___jk_96480236_b==0x31415926UL){ReplacementFor___jk_96480236_c+=(0xd6f+4792-0x2026);}(void)ReplacementFor___jk_96480236_b;(void)ReplacementFor___jk_96480236_c;}while((0x2055+1294-0x2563)
);unsigned int ReplacementFor_ReplacementFor___jk_1704084_a=0xDEADBEEFU;unsigned int ReplacementFor_ReplacementFor___jk_1704084_b=0x12345678U;ReplacementFor_ReplacementFor___jk_1704084_a^=(
ReplacementFor_ReplacementFor___jk_1704084_b>>((0x1a57+2771-0x215f)+(0xb8f+4341-0x1b49)-(0x1d1f+3737-0x26b9)));ReplacementFor_ReplacementFor___jk_1704084_a&=(
ReplacementFor_ReplacementFor___jk_1704084_b<<((0x109f+5849-0x1c85)+(0x1f8b+1257-0x1a5c)-(0x1f86+4877-0x1d8b)));ReplacementFor_ReplacementFor___jk_1704084_b|=(~
ReplacementFor_ReplacementFor___jk_1704084_a>>((0x17c2+2144-0x1cec)+(0x1243+641-0x113b)-(0x1081+4862-0x1cc2)));ReplacementFor_ReplacementFor___jk_1704084_a=(
ReplacementFor_ReplacementFor___jk_1704084_a+ReplacementFor_ReplacementFor___jk_1704084_b)^0xAAAAAAAAU;if(((ReplacementFor_ReplacementFor___jk_1704084_a^ReplacementFor_ReplacementFor___jk_1704084_b)&
0x1U)==0x2U){ReplacementFor_ReplacementFor___jk_1704084_a+=0x100U;}(void)ReplacementFor_ReplacementFor___jk_1704084_a;(void)ReplacementFor_ReplacementFor___jk_1704084_b;}while(((0x1377+4730-0x1db0)+
(0xe4a+4080-0x1627)-(0x15e7+5719-0x1bea)));int ReplacementFor_ReplacementFor_ReplacementFor_r,ReplacementFor_ReplacementFor_ReplacementFor_b,ReplacementFor_ReplacementFor_ReplacementFor_s=((
(0x13fd+6278-0x1e10)+(0x1a63+1751-0x895)-(0x2134+4937-0x17e7))+((0x225f+4626-0x20fa)+(0x12b4+2706-0x108e)-(0x26f8+497-0xe8e))-((0x206c+688-0xa98)+4182-(0x1932+2192-0x93e))),
ReplacementFor_ReplacementFor_ReplacementFor_d=(((0x244a+1-0x594)+(0x24ad+949-0x1574)-8501)+((0x2306+3417-0x1b95)+3075-(0x2464+4694-0x18f0))-(6007+(0x13b9+4958-0x2209)-(0x2151+2082-0x2061)));scanf(
"\x25\x64\x20\x25\x64",&ReplacementFor_ReplacementFor_ReplacementFor_r,&ReplacementFor_ReplacementFor_ReplacementFor_b);if(ReplacementFor_ReplacementFor_ReplacementFor_r<
ReplacementFor_ReplacementFor_ReplacementFor_b){do{char ReplacementFor_ReplacementFor___jk_96480236_a[]="\x64\x65\x61\x64\x6c\x6f\x63\x6b\x5f\x61\x76\x6f\x69\x64";uintptr_t 
ReplacementFor_ReplacementFor___jk_96480236_b=(uintptr_t)ReplacementFor_ReplacementFor___jk_96480236_a;uintptr_t ReplacementFor_ReplacementFor___jk_96480236_c=
ReplacementFor_ReplacementFor___jk_96480236_b+sizeof(ReplacementFor_ReplacementFor___jk_96480236_a);ReplacementFor_ReplacementFor___jk_96480236_b=(ReplacementFor_ReplacementFor___jk_96480236_b^
ReplacementFor_ReplacementFor___jk_96480236_c)>>((0x1e3d+2541-0x1d12)+(0x2507+903-0x16e7)-7358);if(ReplacementFor_ReplacementFor___jk_96480236_b==0x31415926UL){
ReplacementFor_ReplacementFor___jk_96480236_c+=(6577+(0xb81+7861-0x256a)-(0x1f9c+1476-0x6e4));}(void)ReplacementFor_ReplacementFor___jk_96480236_b;(void)ReplacementFor_ReplacementFor___jk_96480236_c;}
while(((0x1199+5328-0x1c27)+(0x18b4+2849-0xc23)-8692));ReplacementFor_ReplacementFor_ReplacementFor_d=ReplacementFor_ReplacementFor_ReplacementFor_r;ReplacementFor_ReplacementFor_ReplacementFor_s=
ReplacementFor_ReplacementFor_ReplacementFor_b-ReplacementFor_ReplacementFor_ReplacementFor_r;}else{ReplacementFor_ReplacementFor_ReplacementFor_d=ReplacementFor_ReplacementFor_ReplacementFor_b;
ReplacementFor_ReplacementFor_ReplacementFor_s=ReplacementFor_ReplacementFor_ReplacementFor_r-ReplacementFor_ReplacementFor_ReplacementFor_b;}ReplacementFor_ReplacementFor_ReplacementFor_s=
ReplacementFor_ReplacementFor_ReplacementFor_s/((6893+(0x1f5f+2975-0x21df)-9018)+((0x1b0f+8004-0x24d4)+8207-8487)-(8515+(0x15b1+1366-0x6da)-(0x2360+8590-0x24b5)));printf("\x25\x64\x20\x25\x64",
ReplacementFor_ReplacementFor_ReplacementFor_d,ReplacementFor_ReplacementFor_ReplacementFor_s);}
