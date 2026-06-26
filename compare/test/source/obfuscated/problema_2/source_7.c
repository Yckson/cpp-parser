
#include <stdio.h>
#include <stdint.h>
int main(int argc,char const*argv[]){
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
unsigned int ReplacementFor___jk_1704084_a=0xDEADBEEFU;unsigned int ReplacementFor___jk_1704084_b=0x12345678U;ReplacementFor___jk_1704084_a^=(
ReplacementFor___jk_1704084_b>>(0x63f+4195-0x169b));ReplacementFor___jk_1704084_a&=(ReplacementFor___jk_1704084_b<<(0x11f9+5014-0x258c));ReplacementFor___jk_1704084_b|=(~ReplacementFor___jk_1704084_a
>>(0x58c+5371-0x1a85));ReplacementFor___jk_1704084_a=(ReplacementFor___jk_1704084_a+ReplacementFor___jk_1704084_b)^0xAAAAAAAAU;if(((ReplacementFor___jk_1704084_a^ReplacementFor___jk_1704084_b)&0x1U)==
0x2U){ReplacementFor___jk_1704084_a+=0x100U;}(void)ReplacementFor___jk_1704084_a;(void)ReplacementFor___jk_1704084_b;}while((0x1844+2678-0x22ba));do{do{char ReplacementFor___jk_96480236_a[]=
"\x64\x65\x61\x64\x6c\x6f\x63\x6b\x5f\x61\x76\x6f\x69\x64";uintptr_t ReplacementFor___jk_96480236_b=(uintptr_t)ReplacementFor___jk_96480236_a;uintptr_t ReplacementFor___jk_96480236_c=
ReplacementFor___jk_96480236_b+sizeof(ReplacementFor___jk_96480236_a);ReplacementFor___jk_96480236_b=(ReplacementFor___jk_96480236_b^ReplacementFor___jk_96480236_c)>>(0x8f8+4093-0x18f4);if(
ReplacementFor___jk_96480236_b==0x31415926UL){ReplacementFor___jk_96480236_c+=(0x12c+6961-0x1c5c);}(void)ReplacementFor___jk_96480236_b;(void)ReplacementFor___jk_96480236_c;}while((0x7b4+4170-0x17fe))
;unsigned int ReplacementFor_ReplacementFor___jk_1704084_a=0xDEADBEEFU;unsigned int ReplacementFor_ReplacementFor___jk_1704084_b=0x12345678U;ReplacementFor_ReplacementFor___jk_1704084_a^=(
ReplacementFor_ReplacementFor___jk_1704084_b>>((0xae7+1514-0xf69)+(0x1695+1443-0xa78)-(0x1b07+7577-0x257f)));ReplacementFor_ReplacementFor___jk_1704084_a&=(ReplacementFor_ReplacementFor___jk_1704084_b
<<(7497+(0x9fd+5995-0x1e7b)-(0x26bd+183-0x741)));ReplacementFor_ReplacementFor___jk_1704084_b|=(~ReplacementFor_ReplacementFor___jk_1704084_a>>((0x23cf+1282-0x1846)+(0x1e67+3209-0x1f0b)-7278));
ReplacementFor_ReplacementFor___jk_1704084_a=(ReplacementFor_ReplacementFor___jk_1704084_a+ReplacementFor_ReplacementFor___jk_1704084_b)^0xAAAAAAAAU;if(((ReplacementFor_ReplacementFor___jk_1704084_a^
ReplacementFor_ReplacementFor___jk_1704084_b)&0x1U)==0x2U){ReplacementFor_ReplacementFor___jk_1704084_a+=0x100U;}(void)ReplacementFor_ReplacementFor___jk_1704084_a;(void)
ReplacementFor_ReplacementFor___jk_1704084_b;}while(((0x1812+4257-0x1bf8)+(0x2280+905-0x12bc)-8200));int ReplacementFor_ReplacementFor_ReplacementFor_a,ReplacementFor_ReplacementFor_ReplacementFor_b;
scanf("\x25\x64\x25\x64",&ReplacementFor_ReplacementFor_ReplacementFor_a,&ReplacementFor_ReplacementFor_ReplacementFor_b);int tmp=ReplacementFor_ReplacementFor_ReplacementFor_a<
ReplacementFor_ReplacementFor_ReplacementFor_b?ReplacementFor_ReplacementFor_ReplacementFor_a:ReplacementFor_ReplacementFor_ReplacementFor_b;printf("\x25\x64\x20\x25\x64""\n",tmp,(
ReplacementFor_ReplacementFor_ReplacementFor_a+ReplacementFor_ReplacementFor_ReplacementFor_b)/((8399+(0x10f5+6029-0x22fa)-7219)+(8085+(0x17cc+2423-0x1268)-9474)-(9450+(0x1bcd+7311-0x2519)-9373))-tmp)
;return(((0x259c+5388-0x216f)+(0x6e5+7380-0x1db4)-(0x1375+8285-0x21b0))+((0x1101+6808-0x1f83)+(0x1002+2908-0x182c)-(0x1637+727-0x141b))-((0x1b30+6185-0x1976)+(0x19d0+9296-0x245d)-(0x1fc5+1607-0x9d7)))
;}
