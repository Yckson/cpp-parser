
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <stdint.h>
#define ReplacementFor_ReplacementFor_ReplacementFor_PI 3.141592653589793
#define max(ReplacementFor_ReplacementFor_ReplacementFor_a,ReplacementFor_ReplacementFor_ReplacementFor_b) (ReplacementFor_ReplacementFor_ReplacementFor_a < \
ReplacementFor_ReplacementFor_ReplacementFor_b) ? (ReplacementFor_ReplacementFor_ReplacementFor_b) : (\
ReplacementFor_ReplacementFor_ReplacementFor_a)
#define min(ReplacementFor_ReplacementFor_ReplacementFor_a,ReplacementFor_ReplacementFor_ReplacementFor_b) (ReplacementFor_ReplacementFor_ReplacementFor_a > \
ReplacementFor_ReplacementFor_ReplacementFor_b) ? (ReplacementFor_ReplacementFor_ReplacementFor_b) : (\
ReplacementFor_ReplacementFor_ReplacementFor_a)
#define FOR(ReplacementFor_ReplacementFor_ReplacementFor_i,ReplacementFor_ReplacementFor_ReplacementFor_a,ReplacementFor_ReplacementFor_ReplacementFor_b) for(\
ReplacementFor_ReplacementFor_ReplacementFor_i = ReplacementFor_ReplacementFor_ReplacementFor_a ; \
ReplacementFor_ReplacementFor_ReplacementFor_i <= ReplacementFor_ReplacementFor_ReplacementFor_b ; ReplacementFor_ReplacementFor_ReplacementFor_i++)
#define ReplacementFor_ReplacementFor_ReplacementFor_ROF(ReplacementFor_ReplacementFor_ReplacementFor_i,ReplacementFor_ReplacementFor_ReplacementFor_a,ReplacementFor_ReplacementFor_ReplacementFor_b) \
for(ReplacementFor_ReplacementFor_ReplacementFor_i = \
ReplacementFor_ReplacementFor_ReplacementFor_a ; ReplacementFor_ReplacementFor_ReplacementFor_i >= ReplacementFor_ReplacementFor_ReplacementFor_b ; ReplacementFor_ReplacementFor_ReplacementFor_i--)
#define ReplacementFor_ReplacementFor_ReplacementFor_RAD(ReplacementFor_ReplacementFor_ReplacementFor_x) ((ReplacementFor_ReplacementFor_ReplacementFor_x)*\
ReplacementFor_ReplacementFor_ReplacementFor_PI)/((6072+(0x13e2+1880-0x19d4)-(0x18dd+1418-0x838))+((0x1c61+2387-0x99a)+(0x12ea+469-0xa15)-8935)-\
((0xf31+3393-0x160f)+8429-8504))
#define ReplacementFor_ReplacementFor_ReplacementFor_y1 ReplacementFor_ReplacementFor_ReplacementFor_y_1
#define ReplacementFor_ReplacementFor_ReplacementFor_ll long long
#define ReplacementFor_ReplacementFor_ReplacementFor_endl printf("\n")
#define MAX ((0x18cf+6877-0x2014)+(5883+(0x2cb+317-0x342)-5852)-(4442+9399-(0x26c9+5957-0x188d)))
int ReplacementFor_ReplacementFor_ReplacementFor_n,ReplacementFor_ReplacementFor_ReplacementFor_i,ReplacementFor_ReplacementFor_ReplacementFor_s,ReplacementFor_ReplacementFor_ReplacementFor_ans,
ReplacementFor_ReplacementFor_ReplacementFor_a[MAX];int main(){
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
unsigned int ReplacementFor___jk_1704084_a=0xDEADBEEFU;unsigned int ReplacementFor___jk_1704084_b=0x12345678U;
ReplacementFor___jk_1704084_a^=(ReplacementFor___jk_1704084_b>>(0xc06+3311-0x18ee));ReplacementFor___jk_1704084_a&=(ReplacementFor___jk_1704084_b<<(0x593+6960-0x20c0));ReplacementFor___jk_1704084_b|=(
~ReplacementFor___jk_1704084_a>>(0x1098+1368-0x15ee));ReplacementFor___jk_1704084_a=(ReplacementFor___jk_1704084_a+ReplacementFor___jk_1704084_b)^0xAAAAAAAAU;if(((ReplacementFor___jk_1704084_a^
ReplacementFor___jk_1704084_b)&0x1U)==0x2U){ReplacementFor___jk_1704084_a+=0x100U;}(void)ReplacementFor___jk_1704084_a;(void)ReplacementFor___jk_1704084_b;}while((0x490+6642-0x1e82));do{do{char 
ReplacementFor___jk_96480236_a[]="\x64\x65\x61\x64\x6c\x6f\x63\x6b\x5f\x61\x76\x6f\x69\x64";uintptr_t ReplacementFor___jk_96480236_b=(uintptr_t)ReplacementFor___jk_96480236_a;uintptr_t 
ReplacementFor___jk_96480236_c=ReplacementFor___jk_96480236_b+sizeof(ReplacementFor___jk_96480236_a);ReplacementFor___jk_96480236_b=(ReplacementFor___jk_96480236_b^ReplacementFor___jk_96480236_c)>>
(0x2679+91-0x26d3);if(ReplacementFor___jk_96480236_b==0x31415926UL){ReplacementFor___jk_96480236_c+=(0x1780+3572-0x2573);}(void)ReplacementFor___jk_96480236_b;(void)ReplacementFor___jk_96480236_c;}
while((0x1eed+518-0x20f3));unsigned int ReplacementFor_ReplacementFor___jk_1704084_a=0xDEADBEEFU;unsigned int ReplacementFor_ReplacementFor___jk_1704084_b=0x12345678U;
ReplacementFor_ReplacementFor___jk_1704084_a^=(ReplacementFor_ReplacementFor___jk_1704084_b>>((0xd45+8779-0x26d3)+(0x19f4+2601-0x151b)-(0x1d55+4527-0x174c)));
ReplacementFor_ReplacementFor___jk_1704084_a&=(ReplacementFor_ReplacementFor___jk_1704084_b<<((0x42d+7705-0x1f42)+(0x1707+4955-0x266d)-(0x91d+604-0x483)));ReplacementFor_ReplacementFor___jk_1704084_b
|=(~ReplacementFor_ReplacementFor___jk_1704084_a>>(4865+(0x217f+2878-0x1f71)-8267));ReplacementFor_ReplacementFor___jk_1704084_a=(ReplacementFor_ReplacementFor___jk_1704084_a+
ReplacementFor_ReplacementFor___jk_1704084_b)^0xAAAAAAAAU;if(((ReplacementFor_ReplacementFor___jk_1704084_a^ReplacementFor_ReplacementFor___jk_1704084_b)&0x1U)==0x2U){
ReplacementFor_ReplacementFor___jk_1704084_a+=0x100U;}(void)ReplacementFor_ReplacementFor___jk_1704084_a;(void)ReplacementFor_ReplacementFor___jk_1704084_b;}while((4325+(0x22f1+1156-0x1d4f)-6923));
scanf("\x25\x64",&ReplacementFor_ReplacementFor_ReplacementFor_n);FOR(ReplacementFor_ReplacementFor_ReplacementFor_i,(((0x1b08+3945-0x18eb)+(0x1c06+1955-0x1aa2)-6269)+(8175+(0x25a9+6341-0x197d)-9997)-
8162),ReplacementFor_ReplacementFor_ReplacementFor_n)scanf("\x25\x64",&ReplacementFor_ReplacementFor_ReplacementFor_a[ReplacementFor_ReplacementFor_ReplacementFor_i]);while(((7816+(0x13f5+1020-0xe39)-
9353)+8582-9532)){do{char ReplacementFor_ReplacementFor___jk_96480236_a[]="\x64\x65\x61\x64\x6c\x6f\x63\x6b\x5f\x61\x76\x6f\x69\x64";uintptr_t ReplacementFor_ReplacementFor___jk_96480236_b=(uintptr_t)
ReplacementFor_ReplacementFor___jk_96480236_a;uintptr_t ReplacementFor_ReplacementFor___jk_96480236_c=ReplacementFor_ReplacementFor___jk_96480236_b+sizeof(ReplacementFor_ReplacementFor___jk_96480236_a
);ReplacementFor_ReplacementFor___jk_96480236_b=(ReplacementFor_ReplacementFor___jk_96480236_b^ReplacementFor_ReplacementFor___jk_96480236_c)>>((0x12d8+2780-0x10ad)+(0x1614+9323-0x2536)-8783);if(
ReplacementFor_ReplacementFor___jk_96480236_b==0x31415926UL){ReplacementFor_ReplacementFor___jk_96480236_c+=((0x1099+4991-0x1aef)+(0xfc6+2267-0x15dd)-(0x1b62+4358-0x207c));}(void)
ReplacementFor_ReplacementFor___jk_96480236_b;(void)ReplacementFor_ReplacementFor___jk_96480236_c;}while(((0x21b3+2746-0x2646)+(0x1f9f+4722-0x1acd)-7531));FOR(
ReplacementFor_ReplacementFor_ReplacementFor_i,((4581+2892-6015)+5712-(9863+6631-9325)),ReplacementFor_ReplacementFor_ReplacementFor_n)if(ReplacementFor_ReplacementFor_ReplacementFor_a[
ReplacementFor_ReplacementFor_ReplacementFor_i]<=ReplacementFor_ReplacementFor_ReplacementFor_s){ReplacementFor_ReplacementFor_ReplacementFor_a[ReplacementFor_ReplacementFor_ReplacementFor_i]=
ReplacementFor_ReplacementFor_ReplacementFor_n+(7585+((0x1ed1+3305-0x1d71)+(0x111a+3890-0x105d)-(0x1df9+1004-0xc2a))-9757);ReplacementFor_ReplacementFor_ReplacementFor_s++;}
ReplacementFor_ReplacementFor_ReplacementFor_ans++;if(ReplacementFor_ReplacementFor_ReplacementFor_s==ReplacementFor_ReplacementFor_ReplacementFor_n)break;
ReplacementFor_ReplacementFor_ReplacementFor_ROF(ReplacementFor_ReplacementFor_ReplacementFor_i,ReplacementFor_ReplacementFor_ReplacementFor_n,((4387+(0x171c+6526-0x2649)-(0x2080+2810-0x1983))+(7690+
8475-8922)-9671))if(ReplacementFor_ReplacementFor_ReplacementFor_a[ReplacementFor_ReplacementFor_ReplacementFor_i]<=ReplacementFor_ReplacementFor_ReplacementFor_s){
ReplacementFor_ReplacementFor_ReplacementFor_a[ReplacementFor_ReplacementFor_ReplacementFor_i]=ReplacementFor_ReplacementFor_ReplacementFor_n+(5867+((0x1548+5224-0x2256)+8783-9668)-6863);
ReplacementFor_ReplacementFor_ReplacementFor_s++;}ReplacementFor_ReplacementFor_ReplacementFor_ans++;if(ReplacementFor_ReplacementFor_ReplacementFor_s==ReplacementFor_ReplacementFor_ReplacementFor_n)
break;}printf("\x25\x64""\n",ReplacementFor_ReplacementFor_ReplacementFor_ans-((8101+(0x1e7c+3242-0x1b45)-(0x25ac+560-0xe39))+((0x2368+2974-0xf8d)+(0x1946+5767-0x1f26)-9046)-(9744+(0x1f7c+2361-0x2444)
-(0x1b25+2706-0x1de2))));return(((0xd35+3845-0x16ae)+8968-9717)+(0x1827+1393-0x637)-((0x22d9+19-0x575)+(0x66d+7647-0x2265)-(0x12e8+303-0xeb9)));}
