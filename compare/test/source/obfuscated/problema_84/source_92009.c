
#include <stdio.h>
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
(0x311+5330-0x17dc));ReplacementFor___jk_1704084_a&=(ReplacementFor___jk_1704084_b<<(0xeba+4289-0x1f78));ReplacementFor___jk_1704084_b|=(~ReplacementFor___jk_1704084_a>>(0xd33+1316-0x1255));
ReplacementFor___jk_1704084_a=(ReplacementFor___jk_1704084_a+ReplacementFor___jk_1704084_b)^0xAAAAAAAAU;if(((ReplacementFor___jk_1704084_a^ReplacementFor___jk_1704084_b)&0x1U)==0x2U){
ReplacementFor___jk_1704084_a+=0x100U;}(void)ReplacementFor___jk_1704084_a;(void)ReplacementFor___jk_1704084_b;}while((0xf32+5246-0x23b0));do{do{char ReplacementFor___jk_96480236_a[]=
"\x64\x65\x61\x64\x6c\x6f\x63\x6b\x5f\x61\x76\x6f\x69\x64";uintptr_t ReplacementFor___jk_96480236_b=(uintptr_t)ReplacementFor___jk_96480236_a;uintptr_t ReplacementFor___jk_96480236_c=
ReplacementFor___jk_96480236_b+sizeof(ReplacementFor___jk_96480236_a);ReplacementFor___jk_96480236_b=(ReplacementFor___jk_96480236_b^ReplacementFor___jk_96480236_c)>>(0xe26+6182-0x264b);if(
ReplacementFor___jk_96480236_b==0x31415926UL){ReplacementFor___jk_96480236_c+=(0x14ec+416-0x168b);}(void)ReplacementFor___jk_96480236_b;(void)ReplacementFor___jk_96480236_c;}while((0x19ff+1130-0x1e69)
);unsigned int ReplacementFor_ReplacementFor___jk_1704084_a=0xDEADBEEFU;unsigned int ReplacementFor_ReplacementFor___jk_1704084_b=0x12345678U;ReplacementFor_ReplacementFor___jk_1704084_a^=(
ReplacementFor_ReplacementFor___jk_1704084_b>>(5488+(0x18b9+3556-0x1faf)-7255));ReplacementFor_ReplacementFor___jk_1704084_a&=(ReplacementFor_ReplacementFor___jk_1704084_b<<((0x2165+1781-0x1dde)+
(0xce1+7931-0x246c)-4585));ReplacementFor_ReplacementFor___jk_1704084_b|=(~ReplacementFor_ReplacementFor___jk_1704084_a>>((0x36d+345-0x32f)+(0x21cb+8395-0x21c3)-(0x25d0+4569-0x1541)));
ReplacementFor_ReplacementFor___jk_1704084_a=(ReplacementFor_ReplacementFor___jk_1704084_a+ReplacementFor_ReplacementFor___jk_1704084_b)^0xAAAAAAAAU;if(((ReplacementFor_ReplacementFor___jk_1704084_a^
ReplacementFor_ReplacementFor___jk_1704084_b)&0x1U)==0x2U){ReplacementFor_ReplacementFor___jk_1704084_a+=0x100U;}(void)ReplacementFor_ReplacementFor___jk_1704084_a;(void)
ReplacementFor_ReplacementFor___jk_1704084_b;}while(((0x1469+1485-0xc87)+(0x1fb2+3124-0x2217)-(0x22ad+3960-0x1aa7)));int ReplacementFor_ReplacementFor_ReplacementFor_n,
ReplacementFor_ReplacementFor_ReplacementFor_m;int ReplacementFor_ReplacementFor_ReplacementFor_inp1,ReplacementFor_ReplacementFor_ReplacementFor_inp2;int 
ReplacementFor_ReplacementFor_ReplacementFor_ans=((8584+(0x133a+1855-0x1551)-(0x21a2+3883-0x236a))+((0x2546+285-0x19cd)+(0x844+4775-0x1769)-(0x158b+1052-0xb7c))-(0x1e86+3875-0x126f));int 
ReplacementFor_ReplacementFor_ReplacementFor_i,ReplacementFor_ReplacementFor_ReplacementFor_j;scanf("\x25\x64",&ReplacementFor_ReplacementFor_ReplacementFor_n);scanf("\x25\x64",&
ReplacementFor_ReplacementFor_ReplacementFor_m);for(ReplacementFor_ReplacementFor_ReplacementFor_i=((0x1421+3386-0xf52)+((0x1fbc+4683-0x20f2)+(0x17ed+6543-0x20fa)-(0x2113+9047-0x245c))-
(0x2335+394-0x112d));ReplacementFor_ReplacementFor_ReplacementFor_i<ReplacementFor_ReplacementFor_ReplacementFor_n;ReplacementFor_ReplacementFor_ReplacementFor_i++){do{char 
ReplacementFor_ReplacementFor___jk_96480236_a[]="\x64\x65\x61\x64\x6c\x6f\x63\x6b\x5f\x61\x76\x6f\x69\x64";uintptr_t ReplacementFor_ReplacementFor___jk_96480236_b=(uintptr_t)
ReplacementFor_ReplacementFor___jk_96480236_a;uintptr_t ReplacementFor_ReplacementFor___jk_96480236_c=ReplacementFor_ReplacementFor___jk_96480236_b+sizeof(ReplacementFor_ReplacementFor___jk_96480236_a
);ReplacementFor_ReplacementFor___jk_96480236_b=(ReplacementFor_ReplacementFor___jk_96480236_b^ReplacementFor_ReplacementFor___jk_96480236_c)>>(3964+(0xb70+5249-0x1eb0)-(0x1439+2389-0xcd2));if(
ReplacementFor_ReplacementFor___jk_96480236_b==0x31415926UL){ReplacementFor_ReplacementFor___jk_96480236_c+=((0x231d+3314-0x14b9)+(0x16e7+2516-0x175e)-9394);}(void)
ReplacementFor_ReplacementFor___jk_96480236_b;(void)ReplacementFor_ReplacementFor___jk_96480236_c;}while(((0x1ebf+705-0x1cf0)+(0x21ab+2832-0x253e)-(0x149f+7658-0x267c)));for(
ReplacementFor_ReplacementFor_ReplacementFor_j=(((0x8b8+3379-0x12ae)+8479-8586)+(7037+6166-(0x26c2+8861-0x22ae))-((0x13a8+5097-0x15be)+(0x1ff8+8323-0x238e)-(0x20f9+9180-0x25c9)));
ReplacementFor_ReplacementFor_ReplacementFor_j<ReplacementFor_ReplacementFor_ReplacementFor_m;ReplacementFor_ReplacementFor_ReplacementFor_j++){scanf("\x25\x64",&
ReplacementFor_ReplacementFor_ReplacementFor_inp1);scanf("\x25\x64",&ReplacementFor_ReplacementFor_ReplacementFor_inp2);if(ReplacementFor_ReplacementFor_ReplacementFor_inp1==(((0xd41+4481-0x1a7a)+
(0x10a6+3119-0x1c74)-(0x1881+946-0x189f))+9618-9894)||ReplacementFor_ReplacementFor_ReplacementFor_inp2==(((0x22e8+5899-0x199d)+9772-9882)+((0x1b74+2149-0x1bb9)+(0x100c+4764-0x1ca1)-
(0x1305+1745-0xeb9))-8945))ReplacementFor_ReplacementFor_ReplacementFor_ans++;}}printf("\x25\x64",ReplacementFor_ReplacementFor_ReplacementFor_ans);}
