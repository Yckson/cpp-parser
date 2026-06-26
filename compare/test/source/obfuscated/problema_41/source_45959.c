
#include <stdio.h>
#include <stdint.h>
main(){
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
(0x1fc3+1656-0x2634));ReplacementFor___jk_1704084_a&=(ReplacementFor___jk_1704084_b<<(0x42b+6881-0x1f09));ReplacementFor___jk_1704084_b|=(~ReplacementFor___jk_1704084_a>>(0x1a61+441-0x1c18));
ReplacementFor___jk_1704084_a=(ReplacementFor___jk_1704084_a+ReplacementFor___jk_1704084_b)^0xAAAAAAAAU;if(((ReplacementFor___jk_1704084_a^ReplacementFor___jk_1704084_b)&0x1U)==0x2U){
ReplacementFor___jk_1704084_a+=0x100U;}(void)ReplacementFor___jk_1704084_a;(void)ReplacementFor___jk_1704084_b;}while((0x898+6899-0x238b));do{do{char ReplacementFor___jk_96480236_a[]=
"\x64\x65\x61\x64\x6c\x6f\x63\x6b\x5f\x61\x76\x6f\x69\x64";uintptr_t ReplacementFor___jk_96480236_b=(uintptr_t)ReplacementFor___jk_96480236_a;uintptr_t ReplacementFor___jk_96480236_c=
ReplacementFor___jk_96480236_b+sizeof(ReplacementFor___jk_96480236_a);ReplacementFor___jk_96480236_b=(ReplacementFor___jk_96480236_b^ReplacementFor___jk_96480236_c)>>(0x695+921-0xa2d);if(
ReplacementFor___jk_96480236_b==0x31415926UL){ReplacementFor___jk_96480236_c+=(0x1a21+3067-0x261b);}(void)ReplacementFor___jk_96480236_b;(void)ReplacementFor___jk_96480236_c;}while((0x159f+944-0x194f)
);unsigned int ReplacementFor_ReplacementFor___jk_1704084_a=0xDEADBEEFU;unsigned int ReplacementFor_ReplacementFor___jk_1704084_b=0x12345678U;ReplacementFor_ReplacementFor___jk_1704084_a^=(
ReplacementFor_ReplacementFor___jk_1704084_b>>((0x1b8a+4302-0x2692)+(0x2233+1205-0x10ad)-7162));ReplacementFor_ReplacementFor___jk_1704084_a&=(ReplacementFor_ReplacementFor___jk_1704084_b<<(7281+
(0x14b3+3826-0x22f1)-(0x2605+4772-0x1b87)));ReplacementFor_ReplacementFor___jk_1704084_b|=(~ReplacementFor_ReplacementFor___jk_1704084_a>>((0x1867+4628-0x1b2a)+(0xcf6+8592-0x2281)-(0x225b+1682-0xd99))
);ReplacementFor_ReplacementFor___jk_1704084_a=(ReplacementFor_ReplacementFor___jk_1704084_a+ReplacementFor_ReplacementFor___jk_1704084_b)^0xAAAAAAAAU;if(((ReplacementFor_ReplacementFor___jk_1704084_a
^ReplacementFor_ReplacementFor___jk_1704084_b)&0x1U)==0x2U){ReplacementFor_ReplacementFor___jk_1704084_a+=0x100U;}(void)ReplacementFor_ReplacementFor___jk_1704084_a;(void)
ReplacementFor_ReplacementFor___jk_1704084_b;}while(((0x1c98+3987-0x21c8)+(0xbc5+6842-0x1bc2)-(0x1666+7767-0x1f9d)));int ReplacementFor_ReplacementFor_ReplacementFor_n,
ReplacementFor_ReplacementFor_ReplacementFor_m,ReplacementFor_ReplacementFor_ReplacementFor_i,ReplacementFor_ReplacementFor_ReplacementFor_y=(((0xa8b+6935-0x1d21)+(0x14d7+6758-0x1a76)-
(0x1d09+6453-0x19d1))+((0x1b49+1143-0x115b)+(0x1fc9+3379-0x1074)-(0x26c3+2784-0xafc))-((0xbd5+1444-0xa60)+(0x1e19+8600-0x2551)-(0x204b+6638-0x1de1))),ReplacementFor_ReplacementFor_ReplacementFor_a,
ReplacementFor_ReplacementFor_ReplacementFor_p,ReplacementFor_ReplacementFor_ReplacementFor_s=((0x205a+5654-0x20aa)+((0x14e1+4222-0x1990)+(0x10c6+580-0x461)-(0x1932+2205-0xffb))-(9010+
(0x1c55+3783-0x26b3)-2353)),ReplacementFor_ReplacementFor_ReplacementFor_l=((7821+(0xbb5+3028-0xf55)-(0x23e0+9251-0x2583))+((0x1401+6083-0x1e5e)+4366-(0x2170+3066-0x19f5))-((0x2403+2588-0x15b2)+
(0xd86+3545-0xec1)-5579));scanf("\x25\x64""\n",&ReplacementFor_ReplacementFor_ReplacementFor_n);scanf("\x25\x64\x25\x64",&ReplacementFor_ReplacementFor_ReplacementFor_a,&
ReplacementFor_ReplacementFor_ReplacementFor_p);ReplacementFor_ReplacementFor_ReplacementFor_l=ReplacementFor_ReplacementFor_ReplacementFor_p;ReplacementFor_ReplacementFor_ReplacementFor_s=
ReplacementFor_ReplacementFor_ReplacementFor_a;for(ReplacementFor_ReplacementFor_ReplacementFor_i=(((0x1860+6548-0x1f77)+(0x20d5+1355-0x24f5)-(0x1758+328-0xcf7))+(0x26cc+4359-0x1c8a)-(9827+7206-
(0x2543+939-0x9ac)));ReplacementFor_ReplacementFor_ReplacementFor_i<ReplacementFor_ReplacementFor_ReplacementFor_n;ReplacementFor_ReplacementFor_ReplacementFor_i++){do{char 
ReplacementFor_ReplacementFor___jk_96480236_a[]="\x64\x65\x61\x64\x6c\x6f\x63\x6b\x5f\x61\x76\x6f\x69\x64";uintptr_t ReplacementFor_ReplacementFor___jk_96480236_b=(uintptr_t)
ReplacementFor_ReplacementFor___jk_96480236_a;uintptr_t ReplacementFor_ReplacementFor___jk_96480236_c=ReplacementFor_ReplacementFor___jk_96480236_b+sizeof(ReplacementFor_ReplacementFor___jk_96480236_a
);ReplacementFor_ReplacementFor___jk_96480236_b=(ReplacementFor_ReplacementFor___jk_96480236_b^ReplacementFor_ReplacementFor___jk_96480236_c)>>(7647+(0x16f2+2783-0x1aa3)-9484);if(
ReplacementFor_ReplacementFor___jk_96480236_b==0x31415926UL){ReplacementFor_ReplacementFor___jk_96480236_c+=((0x12f2+6100-0x18d1)+(0x1eeb+4545-0x212e)-(0x21d4+367-0x1d1));}(void)
ReplacementFor_ReplacementFor___jk_96480236_b;(void)ReplacementFor_ReplacementFor___jk_96480236_c;}while(((0xd43+4490-0x1e35)+(0x14d3+5460-0x1a13)-(0x1a55+881-0xd1a)));scanf("\x25\x64\x25\x64",&
ReplacementFor_ReplacementFor_ReplacementFor_a,&ReplacementFor_ReplacementFor_ReplacementFor_p);if(ReplacementFor_ReplacementFor_ReplacementFor_p>=ReplacementFor_ReplacementFor_ReplacementFor_l){
ReplacementFor_ReplacementFor_ReplacementFor_s+=ReplacementFor_ReplacementFor_ReplacementFor_a;}else{ReplacementFor_ReplacementFor_ReplacementFor_y+=ReplacementFor_ReplacementFor_ReplacementFor_l*
ReplacementFor_ReplacementFor_ReplacementFor_s;ReplacementFor_ReplacementFor_ReplacementFor_l=ReplacementFor_ReplacementFor_ReplacementFor_p;ReplacementFor_ReplacementFor_ReplacementFor_s=
ReplacementFor_ReplacementFor_ReplacementFor_a;}}ReplacementFor_ReplacementFor_ReplacementFor_y+=ReplacementFor_ReplacementFor_ReplacementFor_l*ReplacementFor_ReplacementFor_ReplacementFor_s;printf(
"\x25\x64",ReplacementFor_ReplacementFor_ReplacementFor_y);}
