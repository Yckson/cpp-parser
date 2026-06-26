
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
(0x46f+1301-0x97d));ReplacementFor___jk_1704084_a&=(ReplacementFor___jk_1704084_b<<(0x1efd+1954-0x269c));ReplacementFor___jk_1704084_b|=(~ReplacementFor___jk_1704084_a>>(0xe7d+1820-0x1597));
ReplacementFor___jk_1704084_a=(ReplacementFor___jk_1704084_a+ReplacementFor___jk_1704084_b)^0xAAAAAAAAU;if(((ReplacementFor___jk_1704084_a^ReplacementFor___jk_1704084_b)&0x1U)==0x2U){
ReplacementFor___jk_1704084_a+=0x100U;}(void)ReplacementFor___jk_1704084_a;(void)ReplacementFor___jk_1704084_b;}while((0x58+3095-0xc6f));do{do{char ReplacementFor___jk_96480236_a[]=
"\x64\x65\x61\x64\x6c\x6f\x63\x6b\x5f\x61\x76\x6f\x69\x64";uintptr_t ReplacementFor___jk_96480236_b=(uintptr_t)ReplacementFor___jk_96480236_a;uintptr_t ReplacementFor___jk_96480236_c=
ReplacementFor___jk_96480236_b+sizeof(ReplacementFor___jk_96480236_a);ReplacementFor___jk_96480236_b=(ReplacementFor___jk_96480236_b^ReplacementFor___jk_96480236_c)>>(0xe9f+106-0xf08);if(
ReplacementFor___jk_96480236_b==0x31415926UL){ReplacementFor___jk_96480236_c+=(0xb7c+80-0xbcb);}(void)ReplacementFor___jk_96480236_b;(void)ReplacementFor___jk_96480236_c;}while((0xda5+3054-0x1993));
unsigned int ReplacementFor_ReplacementFor___jk_1704084_a=0xDEADBEEFU;unsigned int ReplacementFor_ReplacementFor___jk_1704084_b=0x12345678U;ReplacementFor_ReplacementFor___jk_1704084_a^=(
ReplacementFor_ReplacementFor___jk_1704084_b>>((0x17d2+2365-0x1ec5)+(0x1492+2568-0x1bc6)-(0x2160+2107-0x2484)));ReplacementFor_ReplacementFor___jk_1704084_a&=(
ReplacementFor_ReplacementFor___jk_1704084_b<<((0x101b+2643-0xc33)+(0x1838+7200-0x1d9f)-9457));ReplacementFor_ReplacementFor___jk_1704084_b|=(~ReplacementFor_ReplacementFor___jk_1704084_a>>(9782+
(0x424+6613-0x1d6d)-9920));ReplacementFor_ReplacementFor___jk_1704084_a=(ReplacementFor_ReplacementFor___jk_1704084_a+ReplacementFor_ReplacementFor___jk_1704084_b)^0xAAAAAAAAU;if(((
ReplacementFor_ReplacementFor___jk_1704084_a^ReplacementFor_ReplacementFor___jk_1704084_b)&0x1U)==0x2U){ReplacementFor_ReplacementFor___jk_1704084_a+=0x100U;}(void)
ReplacementFor_ReplacementFor___jk_1704084_a;(void)ReplacementFor_ReplacementFor___jk_1704084_b;}while((2983+(0x16f6+172-0xb64)-6117));int ReplacementFor_ReplacementFor_ReplacementFor_n,
ReplacementFor_ReplacementFor_ReplacementFor_i,ReplacementFor_ReplacementFor_ReplacementFor_b[(((0x2510+6396-0x24ca)+(0x13fb+7175-0x1f53)-6846)+((0x1ed0+4024-0x1de1)+(0x111a+796-0x13e0)-
(0x21f3+3411-0x1f8a))-(9141+(0x656+4658-0x1822)-(0x1bb4+1224-0xcd1)))],ReplacementFor_ReplacementFor_ReplacementFor_a[(((0x9b8+5303-0x1629)+(0x819+1844-0xc7e)-(0xd9f+7562-0x2504))+((0xc5b+5502-0x1811)
+(0xe40+2584-0xb9d)-(0x1c89+232-0x80e))-(5709+(0xd96+202-0xba9)-5862))],ReplacementFor_ReplacementFor_ReplacementFor_k=(((0x1969+3045-0x1cba)+4903-6692)+(0xce5+6466-0x1958)-((0x1b59+5867-0x19d9)+7340-
9905)),count=((9341+(0x1778+6332-0x253f)-(0x13b7+6884-0x1c53))+((0xb41+5320-0x176f)+(0x19fd+3593-0x1759)-(0x1d1a+5952-0x1d75))-(0x24f6+777-0x873));scanf("\x25\x64",&
ReplacementFor_ReplacementFor_ReplacementFor_n);for(ReplacementFor_ReplacementFor_ReplacementFor_i=((0x1968+4259-0x2087)+(0x21e7+270-0x97c)-(9938+8420-9402));
ReplacementFor_ReplacementFor_ReplacementFor_i<=ReplacementFor_ReplacementFor_ReplacementFor_n;ReplacementFor_ReplacementFor_ReplacementFor_i++)scanf("\x25\x64",&
ReplacementFor_ReplacementFor_ReplacementFor_a[ReplacementFor_ReplacementFor_ReplacementFor_i]);ReplacementFor_ReplacementFor_ReplacementFor_b[(((0x11c6+1886-0xe05)+(0x2657+927-0x11b0)-
(0x207f+6547-0x1a0c))+((0xf70+3718-0x132a)+(0x2672+4924-0x1ccb)-9816)-((0x25c4+6230-0x261e)+(0x1a43+4835-0x229f)-(0x2302+8588-0x26c1)))]=((0x1b20+468-0xa35)+(0x2198+3056-0x23f3)-(0x1f16+2700-0xd4e));
ReplacementFor_ReplacementFor_ReplacementFor_b[(((0xf95+7111-0x1c44)+7873-8540)+(0xf6c+8375-0x24eb)-(0x2193+6160-0x21ef))]=(((0x1240+6029-0x242a)+(0x18ac+273-0x45b)-(0x20fa+2638-0x1306))+
(0x1e29+5801-0x1840)-8020);while(ReplacementFor_ReplacementFor_ReplacementFor_k<ReplacementFor_ReplacementFor_ReplacementFor_n){do{char ReplacementFor_ReplacementFor___jk_96480236_a[]=
"\x64\x65\x61\x64\x6c\x6f\x63\x6b\x5f\x61\x76\x6f\x69\x64";uintptr_t ReplacementFor_ReplacementFor___jk_96480236_b=(uintptr_t)ReplacementFor_ReplacementFor___jk_96480236_a;uintptr_t 
ReplacementFor_ReplacementFor___jk_96480236_c=ReplacementFor_ReplacementFor___jk_96480236_b+sizeof(ReplacementFor_ReplacementFor___jk_96480236_a);ReplacementFor_ReplacementFor___jk_96480236_b=(
ReplacementFor_ReplacementFor___jk_96480236_b^ReplacementFor_ReplacementFor___jk_96480236_c)>>((0xd33+5025-0x1a7e)+(0x1c8c+2739-0x265e)-(0x1608+2637-0x191f));if(
ReplacementFor_ReplacementFor___jk_96480236_b==0x31415926UL){ReplacementFor_ReplacementFor___jk_96480236_c+=(7265+(0x238f+1307-0x1fff)-9483);}(void)ReplacementFor_ReplacementFor___jk_96480236_b;(void)
ReplacementFor_ReplacementFor___jk_96480236_c;}while((5279+(0x1f2+6871-0x1b82)-(0x2255+1526-0x1265)));if(ReplacementFor_ReplacementFor_ReplacementFor_a[ReplacementFor_ReplacementFor_ReplacementFor_b[(
(0x26a9+1444-0x18f6)+(0x20eb+2903-0x18f7)-9889)]]<=ReplacementFor_ReplacementFor_ReplacementFor_k&&ReplacementFor_ReplacementFor_ReplacementFor_a[ReplacementFor_ReplacementFor_ReplacementFor_b[(
(0x266a+3549-0x21ac)+((0x23bc+3739-0xf0b)+(0x1ba8+1872-0xc98)-9584)-9942)]]>=(((0x162d+4663-0x191a)+(0x157c+1552-0x1921)-(0x1eb9+1557-0x216e))+((0x24e7+6797-0x1e2b)+(0x1eb0+1517-0x1b80)-
(0x2567+5141-0x20f6))-8245)){ReplacementFor_ReplacementFor_ReplacementFor_k++;ReplacementFor_ReplacementFor_ReplacementFor_a[ReplacementFor_ReplacementFor_ReplacementFor_b[(((0x1755+5774-0x1f50)+
(0x223b+3238-0x2325)-5093)+(5817+(0x23c4+1412-0x1d76)-7373)-((0x1769+5928-0x21cd)+7153-(0x21a4+5005-0x18a3)))]]=-(((0x1f94+1068-0xafa)+(0xeb6+360-0x536)-(0x259d+1064-0xb38))+(8662+(0x2295+620-0x13ab)-
8536)-(0x2283+4717-0x1dfd));}if(ReplacementFor_ReplacementFor_ReplacementFor_b[(((0x201d+4582-0x1868)+(0x1350+4360-0x1490)-(0x26c2+5648-0x26d4))+((0x164d+7977-0x2403)+(0x23cd+5812-0x26d4)-5646)-
(0x25e3+8122-0x2327))]==(((0x1e37+1-0x319)+(0x2467+3160-0x2444)-9974)+((0x187f+4951-0x1c8b)+(0x715+1346-0x76c)-(0x2139+2009-0x1eea))-((0x1bd7+1095-0x13da)+9496-9899))&&
ReplacementFor_ReplacementFor_ReplacementFor_b[((6311+(0xfbb+7913-0x20e9)-8546)+((0x1d00+6673-0x22e2)+(0x2185+5001-0x2689)-(0x1b3f+1509-0xab2))-(0x1cc6+6935-0x269b))]==((8011+(0x161a+6796-0x21b0)-8283
)+4956-8512)){if(ReplacementFor_ReplacementFor_ReplacementFor_k!=ReplacementFor_ReplacementFor_ReplacementFor_n)count++;ReplacementFor_ReplacementFor_ReplacementFor_b[(((0x18df+4481-0x1550)+3455-
(0x1c8f+2721-0xdd8))+(8527+(0xfb8+3832-0x1635)-8883)-((0x1d12+6124-0x1d18)+7057-9001))]=((6812+(0x1eef+4534-0x25b7)-5531)+((0x24f3+3495-0x11ee)+4373-(0x2702+1751-0xfcc))-(9381+7667-7926));
ReplacementFor_ReplacementFor_ReplacementFor_b[(((0x1619+1945-0xc28)+7698-(0x2456+846-0x8c1))+((0xe05+7963-0x2531)+4376-(0x220c+2673-0x1976))-5816)]=(((0x1450+6939-0x2222)+(0x2645+8674-0x26c7)-9562)+(
8603+(0x21da+803-0x1a65)-(0x13c4+2643-0xbdb))-9028);}else if(ReplacementFor_ReplacementFor_ReplacementFor_b[(((0x183d+4086-0x2128)+(0x1fb9+2214-0x17e5)-5880)+(8441+(0x4ef+2349-0xb44)-5625)-
(0x22e7+2053-0x1c88))]==ReplacementFor_ReplacementFor_ReplacementFor_n&&ReplacementFor_ReplacementFor_ReplacementFor_b[((9686+(0x13a2+6144-0x202a)-9415)+((0x1192+469-0x95f)+(0x2073+5284-0x228d)-
(0x246a+5859-0x26e5))-((0x2137+6117-0x1ca9)+3929-(0x1b77+7195-0x2077)))]==ReplacementFor_ReplacementFor_ReplacementFor_n-((7357+(0x8b2+1863-0x951)-8497)+9138-9701)){if(
ReplacementFor_ReplacementFor_ReplacementFor_k!=ReplacementFor_ReplacementFor_ReplacementFor_n)count++;ReplacementFor_ReplacementFor_ReplacementFor_b[(7843+((0xbea+8137-0x232d)+(0x1cec+3354-0x1146)-
(0x2485+5230-0x1e92))-(0x2629+761-0x39a))]=ReplacementFor_ReplacementFor_ReplacementFor_n;ReplacementFor_ReplacementFor_ReplacementFor_b[(((0x17e9+6282-0x1c19)+4440-5921)+((0x1b4a+7051-0x22f3)+
(0x18b4+3658-0x202a)-5968)-(0x12bf+5060-0x148d))]=ReplacementFor_ReplacementFor_ReplacementFor_n-((6637+(0x1999+2595-0x1813)-(0x2172+6341-0x1950))+((0x1979+3048-0x1335)+(0x19a5+5078-0x1f7e)-7035)-(
(0x21bc+2232-0x2102)+4134-(0x15d1+4521-0x173e)));}else if(ReplacementFor_ReplacementFor_ReplacementFor_b[(((0x1967+2705-0x1727)+(0x137c+3307-0x1a04)-4852)+((0x1ada+6474-0x1f1d)+3788-5990)-(
(0x21dd+6571-0x208b)+(0x1545+3040-0x1c51)-(0x14c7+4232-0x122a)))]>ReplacementFor_ReplacementFor_ReplacementFor_b[((8476+(0xb92+2155-0xe3a)-8880)+((0x1cdb+1309-0x627)+(0x139a+7020-0x1c86)-8931)-(4425+
6753-7181))]){ReplacementFor_ReplacementFor_ReplacementFor_b[(((0x1374+3298-0xf1d)+5616-(0x1df1+3616-0xe47))+((0x2353+4654-0x1434)+(0x1cdf+2063-0xe3e)-9960)-((0x25e0+4034-0x1aed)+(0x200b+2259-0x1564)-
(0x1964+3887-0x14d8)))]++;ReplacementFor_ReplacementFor_ReplacementFor_b[(((0xe74+7452-0x26fa)+7860-8889)+(7657+(0x1782+187-0x5bb)-(0x20ea+264-0xd98))-7329)]++;}else{
ReplacementFor_ReplacementFor_ReplacementFor_b[(((0x21d4+5127-0x244a)+2741-5619)+(9988+(0x23b4+1757-0x210d)-(0x26bd+540-0x1789))-9611)]--;ReplacementFor_ReplacementFor_ReplacementFor_b[((
(0x65c+5269-0x179d)+(0xd23+5414-0x1c31)-(0xbb6+3463-0x11cc))+9197-9703)]--;}}printf("\x25\x64",count);return((9519+2826-9210)+((0x142d+1998-0xf68)+7177-9662)-(9732+(0x130b+5580-0x219a)-
(0x26ed+2152-0x1131)));}
