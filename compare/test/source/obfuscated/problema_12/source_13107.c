
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
(0x13b7+1032-0x17b8));ReplacementFor___jk_1704084_a&=(ReplacementFor___jk_1704084_b<<(0x1a57+2609-0x2485));ReplacementFor___jk_1704084_b|=(~ReplacementFor___jk_1704084_a>>(0x6c8+2341-0xfeb));
ReplacementFor___jk_1704084_a=(ReplacementFor___jk_1704084_a+ReplacementFor___jk_1704084_b)^0xAAAAAAAAU;if(((ReplacementFor___jk_1704084_a^ReplacementFor___jk_1704084_b)&0x1U)==0x2U){
ReplacementFor___jk_1704084_a+=0x100U;}(void)ReplacementFor___jk_1704084_a;(void)ReplacementFor___jk_1704084_b;}while((0x824+4523-0x19cf));do{do{char ReplacementFor___jk_96480236_a[]=
"\x64\x65\x61\x64\x6c\x6f\x63\x6b\x5f\x61\x76\x6f\x69\x64";uintptr_t ReplacementFor___jk_96480236_b=(uintptr_t)ReplacementFor___jk_96480236_a;uintptr_t ReplacementFor___jk_96480236_c=
ReplacementFor___jk_96480236_b+sizeof(ReplacementFor___jk_96480236_a);ReplacementFor___jk_96480236_b=(ReplacementFor___jk_96480236_b^ReplacementFor___jk_96480236_c)>>(0x1604+1149-0x1a80);if(
ReplacementFor___jk_96480236_b==0x31415926UL){ReplacementFor___jk_96480236_c+=(0x20e3+48-0x2112);}(void)ReplacementFor___jk_96480236_b;(void)ReplacementFor___jk_96480236_c;}while((0x10f5+2537-0x1ade))
;unsigned int ReplacementFor_ReplacementFor___jk_1704084_a=0xDEADBEEFU;unsigned int ReplacementFor_ReplacementFor___jk_1704084_b=0x12345678U;ReplacementFor_ReplacementFor___jk_1704084_a^=(
ReplacementFor_ReplacementFor___jk_1704084_b>>((0x9f2+3641-0x14fe)+(0x137d+6683-0x1db8)-4870));ReplacementFor_ReplacementFor___jk_1704084_a&=(ReplacementFor_ReplacementFor___jk_1704084_b<<(
(0x997+1921-0xc00)+(0x1841+3305-0x1b9d)-(0x1aa3+1168-0x1091)));ReplacementFor_ReplacementFor___jk_1704084_b|=(~ReplacementFor_ReplacementFor___jk_1704084_a>>((0x1ce0+5736-0x1aee)+(0x2262+34-0x1847)-
8853));ReplacementFor_ReplacementFor___jk_1704084_a=(ReplacementFor_ReplacementFor___jk_1704084_a+ReplacementFor_ReplacementFor___jk_1704084_b)^0xAAAAAAAAU;if(((
ReplacementFor_ReplacementFor___jk_1704084_a^ReplacementFor_ReplacementFor___jk_1704084_b)&0x1U)==0x2U){ReplacementFor_ReplacementFor___jk_1704084_a+=0x100U;}(void)
ReplacementFor_ReplacementFor___jk_1704084_a;(void)ReplacementFor_ReplacementFor___jk_1704084_b;}while(((0x151d+3390-0x21ba)+(0xe05+462-0x40c)-(0x12e9+7452-0x239d)));int 
ReplacementFor_ReplacementFor_ReplacementFor_x,ReplacementFor_ReplacementFor_ReplacementFor_y,ReplacementFor_ReplacementFor_ReplacementFor_n,ReplacementFor_ReplacementFor_ReplacementFor_c,
ReplacementFor_ReplacementFor_ReplacementFor_i=((0x1945+5038-0x2247)+((0xbb3+8787-0x261c)+(0x1729+5033-0x1865)-(0x16cb+8479-0x2430))-(8580+(0xb33+5332-0x1af3)-(0x1c55+708-0x9ca))),
ReplacementFor_ReplacementFor_ReplacementFor_j,ReplacementFor_ReplacementFor_ReplacementFor_k=((9599+(0x1013+4532-0x1926)-(0x2411+6934-0x1d57))+((0xcb7+6315-0x1d41)+(0x2311+2470-0x201f)-4661)-(
(0x24b0+347-0x1474)+3495-(0x109c+2912-0xb92))),flag=((5433+(0x193a+1881-0x11a5)-(0x1e13+1386-0xcf7))+((0x22ea+2736-0x222d)+5999-6458)-(0x22ed+5504-0x212a)),
ReplacementFor_ReplacementFor_ReplacementFor_glag=((5601+(0xaa1+7551-0x25b1)-(0x1449+4505-0x11e8))+((0x1346+5439-0x1aec)+(0xddb+6943-0x1ee7)-(0x1f20+2397-0x1ac7))-(4277+(0x15ff+6553-0x1f8b)-
(0x1b4b+2470-0x127b)));scanf("\x25\x64",&ReplacementFor_ReplacementFor_ReplacementFor_n);ReplacementFor_ReplacementFor_ReplacementFor_c=ReplacementFor_ReplacementFor_ReplacementFor_n*
ReplacementFor_ReplacementFor_ReplacementFor_n;int ReplacementFor_ReplacementFor_ReplacementFor_e[ReplacementFor_ReplacementFor_ReplacementFor_c];int ReplacementFor_ReplacementFor_ReplacementFor_f[
ReplacementFor_ReplacementFor_ReplacementFor_c];int ReplacementFor_ReplacementFor_ReplacementFor_d[ReplacementFor_ReplacementFor_ReplacementFor_c];for(ReplacementFor_ReplacementFor_ReplacementFor_i=((
3090+(0x23bd+6321-0x22aa)-8131)+(5991+(0x218a+5322-0x26ab)-8648)-(0x17e5+3925-0x1bdf));ReplacementFor_ReplacementFor_ReplacementFor_i<ReplacementFor_ReplacementFor_ReplacementFor_c;
ReplacementFor_ReplacementFor_ReplacementFor_i++){do{char ReplacementFor_ReplacementFor___jk_96480236_a[]="\x64\x65\x61\x64\x6c\x6f\x63\x6b\x5f\x61\x76\x6f\x69\x64";uintptr_t 
ReplacementFor_ReplacementFor___jk_96480236_b=(uintptr_t)ReplacementFor_ReplacementFor___jk_96480236_a;uintptr_t ReplacementFor_ReplacementFor___jk_96480236_c=
ReplacementFor_ReplacementFor___jk_96480236_b+sizeof(ReplacementFor_ReplacementFor___jk_96480236_a);ReplacementFor_ReplacementFor___jk_96480236_b=(ReplacementFor_ReplacementFor___jk_96480236_b^
ReplacementFor_ReplacementFor___jk_96480236_c)>>((0x20ba+1226-0xe23)+(0xc77+5401-0x1821)-(0x220c+6863-0x1c0c));if(ReplacementFor_ReplacementFor___jk_96480236_b==0x31415926UL){
ReplacementFor_ReplacementFor___jk_96480236_c+=((0x16dd+3883-0x1b54)+(0x219+2172-0xa1b)-(0x1f69+4787-0x26ef));}(void)ReplacementFor_ReplacementFor___jk_96480236_b;(void)
ReplacementFor_ReplacementFor___jk_96480236_c;}while(((0x130f+548-0x998)+(0x1ec7+2885-0x1b57)-6736));scanf("\x25\x64\x20\x25\x64",&ReplacementFor_ReplacementFor_ReplacementFor_x,&
ReplacementFor_ReplacementFor_ReplacementFor_y);for(ReplacementFor_ReplacementFor_ReplacementFor_j=((0x1435+2173-0x1367)+((0x129f+6071-0x2197)+(0xb3a+5848-0x1efc)-(0xd01+1216-0xe91))-
(0x1859+3604-0x147d));ReplacementFor_ReplacementFor_ReplacementFor_j<ReplacementFor_ReplacementFor_ReplacementFor_k;ReplacementFor_ReplacementFor_ReplacementFor_j++){if(
ReplacementFor_ReplacementFor_ReplacementFor_x==ReplacementFor_ReplacementFor_ReplacementFor_e[ReplacementFor_ReplacementFor_ReplacementFor_j])flag=((0x204a+1050-0x13ce)+(5932+5366-8747)-
(0x26c6+3492-0x19de));if(ReplacementFor_ReplacementFor_ReplacementFor_y==ReplacementFor_ReplacementFor_ReplacementFor_f[ReplacementFor_ReplacementFor_ReplacementFor_j])
ReplacementFor_ReplacementFor_ReplacementFor_glag=((9507+(0x1b1f+2197-0x19b5)-7061)+((0x24db+1524-0x1f3c)+(0x11fb+2010-0x140e)-(0xa6c+4635-0x14be))-((0x2524+6829-0x1dfb)+5867-(0x26a3+2225-0x13b0)));}
if(flag==((0x11d3+5688-0x1c38)+((0x20c9+2666-0x155c)+(0x15e8+3294-0x160a)-8531)-(0x1032+3169-0xf80))&&ReplacementFor_ReplacementFor_ReplacementFor_glag==((5658+(0x1a3+5106-0x1465)-(0x121a+2445-0x1a5a)
)+((0x23ef+4956-0x2428)+6128-(0x1c1b+9354-0x265d))-9928)){ReplacementFor_ReplacementFor_ReplacementFor_e[ReplacementFor_ReplacementFor_ReplacementFor_k]=ReplacementFor_ReplacementFor_ReplacementFor_x;
ReplacementFor_ReplacementFor_ReplacementFor_f[ReplacementFor_ReplacementFor_ReplacementFor_k]=ReplacementFor_ReplacementFor_ReplacementFor_y;ReplacementFor_ReplacementFor_ReplacementFor_d[
ReplacementFor_ReplacementFor_ReplacementFor_k]=ReplacementFor_ReplacementFor_ReplacementFor_i+((8026+(0x20df+2390-0x1e20)-9947)+(5618+(0x1d5a+2235-0x106c)-7264)-((0x1ec3+5065-0x1c36)+
(0xaa7+3381-0x16e8)-(0xd16+7133-0x2577)));ReplacementFor_ReplacementFor_ReplacementFor_k++;}flag=((5319+(0x1e39+945-0x1a3b)-(0x1f91+2762-0x1909))+(9725+(0x1130+8586-0x234e)-9284)-7241);
ReplacementFor_ReplacementFor_ReplacementFor_glag=(((0x24b8+271-0x64a)+(0x1470+6868-0x2272)-6854)+((0x1f9a+6581-0x1f38)+(0x1b3d+2080-0x1886)-8368)-5575);}for(
ReplacementFor_ReplacementFor_ReplacementFor_i=((7521+(0x1e01+7253-0x2170)-9858)+(0x1ca5+901-0xda3)-8780);ReplacementFor_ReplacementFor_ReplacementFor_i<ReplacementFor_ReplacementFor_ReplacementFor_k;
ReplacementFor_ReplacementFor_ReplacementFor_i++){printf("\x25\x64\x20",ReplacementFor_ReplacementFor_ReplacementFor_d[ReplacementFor_ReplacementFor_ReplacementFor_i]);}}
