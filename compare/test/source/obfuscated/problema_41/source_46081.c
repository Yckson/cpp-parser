
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
(0x174+246-0x263));ReplacementFor___jk_1704084_a&=(ReplacementFor___jk_1704084_b<<(0xc34+6553-0x25ca));ReplacementFor___jk_1704084_b|=(~ReplacementFor___jk_1704084_a>>(0xbc6+4282-0x1c7e));
ReplacementFor___jk_1704084_a=(ReplacementFor___jk_1704084_a+ReplacementFor___jk_1704084_b)^0xAAAAAAAAU;if(((ReplacementFor___jk_1704084_a^ReplacementFor___jk_1704084_b)&0x1U)==0x2U){
ReplacementFor___jk_1704084_a+=0x100U;}(void)ReplacementFor___jk_1704084_a;(void)ReplacementFor___jk_1704084_b;}while((0xa13+5935-0x2142));do{do{char ReplacementFor___jk_96480236_a[]=
"\x64\x65\x61\x64\x6c\x6f\x63\x6b\x5f\x61\x76\x6f\x69\x64";uintptr_t ReplacementFor___jk_96480236_b=(uintptr_t)ReplacementFor___jk_96480236_a;uintptr_t ReplacementFor___jk_96480236_c=
ReplacementFor___jk_96480236_b+sizeof(ReplacementFor___jk_96480236_a);ReplacementFor___jk_96480236_b=(ReplacementFor___jk_96480236_b^ReplacementFor___jk_96480236_c)>>(0x9c8+5404-0x1ee3);if(
ReplacementFor___jk_96480236_b==0x31415926UL){ReplacementFor___jk_96480236_c+=(0x351+4790-0x1606);}(void)ReplacementFor___jk_96480236_b;(void)ReplacementFor___jk_96480236_c;}while((0x44b+6480-0x1d9b))
;unsigned int ReplacementFor_ReplacementFor___jk_1704084_a=0xDEADBEEFU;unsigned int ReplacementFor_ReplacementFor___jk_1704084_b=0x12345678U;ReplacementFor_ReplacementFor___jk_1704084_a^=(
ReplacementFor_ReplacementFor___jk_1704084_b>>((0x14f5+280-0x127d)+(0x1be7+3701-0x1eba)-(0x1852+989-0xd04)));ReplacementFor_ReplacementFor___jk_1704084_a&=(ReplacementFor_ReplacementFor___jk_1704084_b
<<(9485+(0xa04+1923-0x1132)-9567));ReplacementFor_ReplacementFor___jk_1704084_b|=(~ReplacementFor_ReplacementFor___jk_1704084_a>>((0x22b0+140-0xec7)+(0x862+2968-0x13f1)-(0x169c+5669-0x1845)));
ReplacementFor_ReplacementFor___jk_1704084_a=(ReplacementFor_ReplacementFor___jk_1704084_a+ReplacementFor_ReplacementFor___jk_1704084_b)^0xAAAAAAAAU;if(((ReplacementFor_ReplacementFor___jk_1704084_a^
ReplacementFor_ReplacementFor___jk_1704084_b)&0x1U)==0x2U){ReplacementFor_ReplacementFor___jk_1704084_a+=0x100U;}(void)ReplacementFor_ReplacementFor___jk_1704084_a;(void)
ReplacementFor_ReplacementFor___jk_1704084_b;}while(((0x20ca+2682-0x21dd)+(0x17f6+1895-0x8da)-(0x26eb+6050-0x1ea3)));long long ReplacementFor_ReplacementFor_ReplacementFor_n,
ReplacementFor_ReplacementFor_ReplacementFor_a,ReplacementFor_ReplacementFor_ReplacementFor_p,ReplacementFor_ReplacementFor_ReplacementFor_i,cost,ReplacementFor_ReplacementFor_ReplacementFor_min_p;
cost=(((0x23fb+5866-0x1f42)+(0x258b+3238-0x19eb)-9252)+((0x1ea2+7668-0x20ac)+(0x1fd6+3955-0x1d8f)-(0x21a5+2499-0xbf8))-(8082+9587-9996));ReplacementFor_ReplacementFor_ReplacementFor_min_p=((5455+
(0xc53+5471-0x1b1f)-(0x2323+6305-0x2478))+(0x113f+6006-0x1a49)-(0x1a9c+908-0xf0e));scanf("\x25\x6c\x6c\x64",&ReplacementFor_ReplacementFor_ReplacementFor_n);while(
ReplacementFor_ReplacementFor_ReplacementFor_n--){do{char ReplacementFor_ReplacementFor___jk_96480236_a[]="\x64\x65\x61\x64\x6c\x6f\x63\x6b\x5f\x61\x76\x6f\x69\x64";uintptr_t 
ReplacementFor_ReplacementFor___jk_96480236_b=(uintptr_t)ReplacementFor_ReplacementFor___jk_96480236_a;uintptr_t ReplacementFor_ReplacementFor___jk_96480236_c=
ReplacementFor_ReplacementFor___jk_96480236_b+sizeof(ReplacementFor_ReplacementFor___jk_96480236_a);ReplacementFor_ReplacementFor___jk_96480236_b=(ReplacementFor_ReplacementFor___jk_96480236_b^
ReplacementFor_ReplacementFor___jk_96480236_c)>>((0xec7+6120-0x2337)+(0x1301+4624-0x24f7)-(0xaf7+557-0x993));if(ReplacementFor_ReplacementFor___jk_96480236_b==0x31415926UL){
ReplacementFor_ReplacementFor___jk_96480236_c+=((0x22ed+954-0x2433)+(0x25d5+1528-0xc9b)-8613);}(void)ReplacementFor_ReplacementFor___jk_96480236_b;(void)ReplacementFor_ReplacementFor___jk_96480236_c;}
while((8807+(0xea8+1825-0x1501)-(0x2664+6671-0x1d44)));scanf("\x25\x6c\x6c\x64\x20\x25\x6c\x6c\x64",&ReplacementFor_ReplacementFor_ReplacementFor_a,&ReplacementFor_ReplacementFor_ReplacementFor_p);
ReplacementFor_ReplacementFor_ReplacementFor_min_p=(ReplacementFor_ReplacementFor_ReplacementFor_min_p>ReplacementFor_ReplacementFor_ReplacementFor_p)?ReplacementFor_ReplacementFor_ReplacementFor_p:
ReplacementFor_ReplacementFor_ReplacementFor_min_p;cost+=ReplacementFor_ReplacementFor_ReplacementFor_a*ReplacementFor_ReplacementFor_ReplacementFor_min_p;}printf("\x25\x6c\x6c\x64",cost);return((
(0x1536+2419-0x169e)+(0x6b7+7566-0x23de)-(0x12f6+2390-0x159f))+((0x206b+7207-0x263c)+(0x220c+24-0x1257)-(0x2558+394-0xc9b))-((0x23d6+4674-0x231b)+4255-(0x242c+5540-0x23d5)));}
