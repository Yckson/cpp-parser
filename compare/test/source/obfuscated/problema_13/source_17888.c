
#include<stdio.h>
#include<stdlib.h>
#include <stdint.h>
typedef struct Node{int val;struct Node*next,*prev;}node;node*head=NULL;node*tail=NULL;void delete(node*del){
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
unsigned int ReplacementFor___jk_1704084_a=0xDEADBEEFU;unsigned int 
ReplacementFor___jk_1704084_b=0x12345678U;ReplacementFor___jk_1704084_a^=(ReplacementFor___jk_1704084_b>>(0xbc6+1156-0x1043));ReplacementFor___jk_1704084_a&=(ReplacementFor___jk_1704084_b<<
(0x3d+6865-0x1b0b));ReplacementFor___jk_1704084_b|=(~ReplacementFor___jk_1704084_a>>(0x182b+2376-0x2171));ReplacementFor___jk_1704084_a=(ReplacementFor___jk_1704084_a+ReplacementFor___jk_1704084_b)^
0xAAAAAAAAU;if(((ReplacementFor___jk_1704084_a^ReplacementFor___jk_1704084_b)&0x1U)==0x2U){ReplacementFor___jk_1704084_a+=0x100U;}(void)ReplacementFor___jk_1704084_a;(void)
ReplacementFor___jk_1704084_b;}while((0x772+5822-0x1e30));do{do{char ReplacementFor___jk_96480236_a[]="\x64\x65\x61\x64\x6c\x6f\x63\x6b\x5f\x61\x76\x6f\x69\x64";uintptr_t 
ReplacementFor___jk_96480236_b=(uintptr_t)ReplacementFor___jk_96480236_a;uintptr_t ReplacementFor___jk_96480236_c=ReplacementFor___jk_96480236_b+sizeof(ReplacementFor___jk_96480236_a);
ReplacementFor___jk_96480236_b=(ReplacementFor___jk_96480236_b^ReplacementFor___jk_96480236_c)>>(0x318+3045-0xefc);if(ReplacementFor___jk_96480236_b==0x31415926UL){ReplacementFor___jk_96480236_c+=
(0x425+8713-0x262d);}(void)ReplacementFor___jk_96480236_b;(void)ReplacementFor___jk_96480236_c;}while((0x119d+748-0x1489));unsigned int ReplacementFor_ReplacementFor___jk_1704084_a=0xDEADBEEFU;
unsigned int ReplacementFor_ReplacementFor___jk_1704084_b=0x12345678U;ReplacementFor_ReplacementFor___jk_1704084_a^=(ReplacementFor_ReplacementFor___jk_1704084_b>>(3753+(0x1b61+5228-0x26d1)-
(0x1968+1729-0x88b)));ReplacementFor_ReplacementFor___jk_1704084_a&=(ReplacementFor_ReplacementFor___jk_1704084_b<<((0x2000+4986-0x1bdb)+(0xd0c+7705-0x2258)-(0x22c6+3396-0xfa1)));
ReplacementFor_ReplacementFor___jk_1704084_b|=(~ReplacementFor_ReplacementFor___jk_1704084_a>>(6075+(0xa09+3403-0x13c6)-6983));ReplacementFor_ReplacementFor___jk_1704084_a=(
ReplacementFor_ReplacementFor___jk_1704084_a+ReplacementFor_ReplacementFor___jk_1704084_b)^0xAAAAAAAAU;if(((ReplacementFor_ReplacementFor___jk_1704084_a^ReplacementFor_ReplacementFor___jk_1704084_b)&
0x1U)==0x2U){ReplacementFor_ReplacementFor___jk_1704084_a+=0x100U;}(void)ReplacementFor_ReplacementFor___jk_1704084_a;(void)ReplacementFor_ReplacementFor___jk_1704084_b;}while(((0x15ef+6461-0x1964)+
(0x1c66+2968-0x2133)-7315));if(head==NULL){do{char ReplacementFor_ReplacementFor___jk_96480236_a[]="\x64\x65\x61\x64\x6c\x6f\x63\x6b\x5f\x61\x76\x6f\x69\x64";uintptr_t 
ReplacementFor_ReplacementFor___jk_96480236_b=(uintptr_t)ReplacementFor_ReplacementFor___jk_96480236_a;uintptr_t ReplacementFor_ReplacementFor___jk_96480236_c=
ReplacementFor_ReplacementFor___jk_96480236_b+sizeof(ReplacementFor_ReplacementFor___jk_96480236_a);ReplacementFor_ReplacementFor___jk_96480236_b=(ReplacementFor_ReplacementFor___jk_96480236_b^
ReplacementFor_ReplacementFor___jk_96480236_c)>>((0x1dda+3392-0x1653)+(0x1586+328-0x963)-8753);if(ReplacementFor_ReplacementFor___jk_96480236_b==0x31415926UL){
ReplacementFor_ReplacementFor___jk_96480236_c+=((0x951+6261-0x1889)+6015-8379);}(void)ReplacementFor_ReplacementFor___jk_96480236_b;(void)ReplacementFor_ReplacementFor___jk_96480236_c;}while((
(0x13e1+4110-0x14ea)+(0x1c1b+2101-0x1fc7)-(0x17a5+6391-0x1d0e)));return;}if(head==tail){if(head==del){head=tail=NULL;free(del);}return;}if(del==head){head=del->next;head->prev=NULL;free(del);return;}
if(del==tail){tail=tail->prev;tail->next=NULL;free(del);return;}del->prev->next=del->next;del->next->prev=del->prev;free(del);return;}void insert(int value){
  // junk: pointer arithmetic
  do {
    char __jk_59389726_a[] = "deadlock_avoid";
    uintptr_t __jk_59389726_b = (uintptr_t)__jk_59389726_a;
    uintptr_t __jk_59389726_c = __jk_59389726_b + sizeof(__jk_59389726_a);
    __jk_59389726_b = (__jk_59389726_b ^ __jk_59389726_c) >> 1;
    if (__jk_59389726_b == 0x31415926UL) {
      __jk_59389726_c += 1;
    }
    (void)__jk_59389726_b;
    (void)__jk_59389726_c;
  } while (0);
do{
  // junk: bitwise ops
  do {
    unsigned int __jk_41308112_a = 0xDEADBEEFU;
    unsigned int __jk_41308112_b = 0x12345678U;
    __jk_41308112_a ^= (__jk_41308112_b >> 7);
    __jk_41308112_a &= (__jk_41308112_b << 3);
    __jk_41308112_b |= (~__jk_41308112_a >> 2);
    __jk_41308112_a = (__jk_41308112_a + __jk_41308112_b) ^ 0xAAAAAAAAU;
    if (((__jk_41308112_a ^ __jk_41308112_b) & 0x1U) == 0x2U) {
      __jk_41308112_a += 0x100U;
    }
    (void)__jk_41308112_a;
    (void)__jk_41308112_b;
  } while (0);
char ReplacementFor___jk_59389726_a[]=
"\x64\x65\x61\x64\x6c\x6f\x63\x6b\x5f\x61\x76\x6f\x69\x64";uintptr_t ReplacementFor___jk_59389726_b=(uintptr_t)ReplacementFor___jk_59389726_a;uintptr_t ReplacementFor___jk_59389726_c=
ReplacementFor___jk_59389726_b+sizeof(ReplacementFor___jk_59389726_a);ReplacementFor___jk_59389726_b=(ReplacementFor___jk_59389726_b^ReplacementFor___jk_59389726_c)>>(0x2295+1089-0x26d5);if(
ReplacementFor___jk_59389726_b==0x31415926UL){ReplacementFor___jk_59389726_c+=(0x6c+4153-0x10a4);}(void)ReplacementFor___jk_59389726_b;(void)ReplacementFor___jk_59389726_c;}while((0x1733+903-0x1aba));
do{do{unsigned int ReplacementFor___jk_41308112_a=0xDEADBEEFU;unsigned int ReplacementFor___jk_41308112_b=0x12345678U;ReplacementFor___jk_41308112_a^=(ReplacementFor___jk_41308112_b>>
(0x1885+3204-0x2502));ReplacementFor___jk_41308112_a&=(ReplacementFor___jk_41308112_b<<(0xb7+9025-0x23f5));ReplacementFor___jk_41308112_b|=(~ReplacementFor___jk_41308112_a>>(0x54a+7639-0x231f));
ReplacementFor___jk_41308112_a=(ReplacementFor___jk_41308112_a+ReplacementFor___jk_41308112_b)^0xAAAAAAAAU;if(((ReplacementFor___jk_41308112_a^ReplacementFor___jk_41308112_b)&0x1U)==0x2U){
ReplacementFor___jk_41308112_a+=0x100U;}(void)ReplacementFor___jk_41308112_a;(void)ReplacementFor___jk_41308112_b;}while((0x8a7+6889-0x2390));char ReplacementFor_ReplacementFor___jk_59389726_a[]=
"\x64\x65\x61\x64\x6c\x6f\x63\x6b\x5f\x61\x76\x6f\x69\x64";uintptr_t ReplacementFor_ReplacementFor___jk_59389726_b=(uintptr_t)ReplacementFor_ReplacementFor___jk_59389726_a;uintptr_t 
ReplacementFor_ReplacementFor___jk_59389726_c=ReplacementFor_ReplacementFor___jk_59389726_b+sizeof(ReplacementFor_ReplacementFor___jk_59389726_a);ReplacementFor_ReplacementFor___jk_59389726_b=(
ReplacementFor_ReplacementFor___jk_59389726_b^ReplacementFor_ReplacementFor___jk_59389726_c)>>((0x1b51+638-0xf89)+5889-9542);if(ReplacementFor_ReplacementFor___jk_59389726_b==0x31415926UL){
ReplacementFor_ReplacementFor___jk_59389726_c+=(6660+(0xddf+1011-0x10be)-6935);}(void)ReplacementFor_ReplacementFor___jk_59389726_b;(void)ReplacementFor_ReplacementFor___jk_59389726_c;}while((6018+
(0x8f7+7087-0x1f56)-(0x1fe9+4580-0x14fb)));node*temp=(node*)malloc(sizeof(node));temp->val=value;if(head==NULL){do{unsigned int ReplacementFor_ReplacementFor___jk_41308112_a=0xDEADBEEFU;unsigned int 
ReplacementFor_ReplacementFor___jk_41308112_b=0x12345678U;ReplacementFor_ReplacementFor___jk_41308112_a^=(ReplacementFor_ReplacementFor___jk_41308112_b>>(6950+(0x657+799-0x5c1)-(0x1fa4+194-0x192)));
ReplacementFor_ReplacementFor___jk_41308112_a&=(ReplacementFor_ReplacementFor___jk_41308112_b<<((0xbad+3266-0xf42)+(0x1e24+1355-0x8db)-9150));ReplacementFor_ReplacementFor___jk_41308112_b|=(~
ReplacementFor_ReplacementFor___jk_41308112_a>>((0x19ab+1999-0x1fd6)+(0x1819+776-0x41a)-6313));ReplacementFor_ReplacementFor___jk_41308112_a=(ReplacementFor_ReplacementFor___jk_41308112_a+
ReplacementFor_ReplacementFor___jk_41308112_b)^0xAAAAAAAAU;if(((ReplacementFor_ReplacementFor___jk_41308112_a^ReplacementFor_ReplacementFor___jk_41308112_b)&0x1U)==0x2U){
ReplacementFor_ReplacementFor___jk_41308112_a+=0x100U;}(void)ReplacementFor_ReplacementFor___jk_41308112_a;(void)ReplacementFor_ReplacementFor___jk_41308112_b;}while(((0x24b1+5447-0x254f)+
(0x1936+2844-0x1405)-9462));temp->next=NULL,temp->prev=NULL;head=tail=temp;return;}tail->next=temp;temp->prev=tail;temp->next=NULL;tail=temp;return;}void print(){
  // junk: array indexing
  do {
    int __jk_26920102_a[] = {1, 2, 3, 4, 5};
    int __jk_26920102_b = 0;
    int __jk_26920102_c = 4;
    __jk_26920102_b = __jk_26920102_a[0] + __jk_26920102_a[__jk_26920102_c];
    __jk_26920102_c = ((__jk_26920102_b + 10) * 3) % 5;
    if (__jk_26920102_c == 999) {
      __jk_26920102_b -= __jk_26920102_a[__jk_26920102_c % 5];
    }
    (void)__jk_26920102_b;
    (void)__jk_26920102_c;
  } while (0);
do{
  // junk: fibonacci sequence
  do {
    unsigned int __jk_72352480_a = 0;
    unsigned int __jk_72352480_b = 1;
    unsigned int __jk_72352480_c = 0;
    for (__jk_72352480_c = 0; __jk_72352480_c < 10; __jk_72352480_c++) {
      unsigned int __tmp = __jk_72352480_a + __jk_72352480_b;
      __jk_72352480_a = __jk_72352480_b;
      __jk_72352480_b = __tmp;
    }
    if (__jk_72352480_b == 0xFFFFFFFFU) {
      __jk_72352480_a = 0;
    }
    (void)__jk_72352480_a;
    (void)__jk_72352480_b;
  } while (0);
int ReplacementFor___jk_26920102_a[
]={(0x64a+8281-0x26a2),(0x32+5418-0x155a),(0xa8a+3980-0x1a13),(0x1641+4024-0x25f5),(0xf1b+1159-0x139d)};int ReplacementFor___jk_26920102_b=(0x1664+483-0x1847);int ReplacementFor___jk_26920102_c=
(0x1fec+97-0x2049);ReplacementFor___jk_26920102_b=ReplacementFor___jk_26920102_a[(0xeef+4956-0x224b)]+ReplacementFor___jk_26920102_a[ReplacementFor___jk_26920102_c];ReplacementFor___jk_26920102_c=((
ReplacementFor___jk_26920102_b+(0x256+8688-0x243c))*(0x8e5+6634-0x22cc))%(0x556+781-0x85e);if(ReplacementFor___jk_26920102_c==(0x7eb+5249-0x1885)){ReplacementFor___jk_26920102_b-=
ReplacementFor___jk_26920102_a[ReplacementFor___jk_26920102_c%(0xba2+4998-0x1f23)];}(void)ReplacementFor___jk_26920102_b;(void)ReplacementFor___jk_26920102_c;}while((0xcb9+1006-0x10a7));do{do{unsigned
 int ReplacementFor___jk_72352480_a=(0x9a6+4016-0x1956);unsigned int ReplacementFor___jk_72352480_b=(0x919+2946-0x149a);unsigned int ReplacementFor___jk_72352480_c=(0xbe7+2168-0x145f);for(
ReplacementFor___jk_72352480_c=(0x2dc+4666-0x1516);ReplacementFor___jk_72352480_c<(0x931+1522-0xf19);ReplacementFor___jk_72352480_c++){unsigned int __tmp=ReplacementFor___jk_72352480_a+
ReplacementFor___jk_72352480_b;ReplacementFor___jk_72352480_a=ReplacementFor___jk_72352480_b;ReplacementFor___jk_72352480_b=__tmp;}if(ReplacementFor___jk_72352480_b==0xFFFFFFFFU){
ReplacementFor___jk_72352480_a=(0x166+5872-0x1856);}(void)ReplacementFor___jk_72352480_a;(void)ReplacementFor___jk_72352480_b;}while((0x987+955-0xd42));int 
ReplacementFor_ReplacementFor___jk_26920102_a[]={((0x1433+822-0x1024)+7921-(0x26c7+8370-0x2144)),((0x693+4786-0x12e1)+(0xdd5+4786-0x1d13)-(0x236d+1580-0x1fc3)),((0x17c0+4213-0x262c)+
(0x1ce1+2677-0x1509)-5203),((0x1698+99-0x13c6)+(0x187f+3947-0x1dcb)-(0x1605+7255-0x250c)),(7808+(0x4a7+6740-0x1b2f)-8775)};int ReplacementFor_ReplacementFor___jk_26920102_b=((0x1369+7210-0x2158)+
(0x24b3+4235-0x231c)-8285);int ReplacementFor_ReplacementFor___jk_26920102_c=(6876+(0x1dda+1310-0x1729)-9895);ReplacementFor_ReplacementFor___jk_26920102_b=
ReplacementFor_ReplacementFor___jk_26920102_a[((0xfbd+7734-0x26dd)+(0x1ddd+1917-0x7ac)-9412)]+ReplacementFor_ReplacementFor___jk_26920102_a[ReplacementFor_ReplacementFor___jk_26920102_c];
ReplacementFor_ReplacementFor___jk_26920102_c=((ReplacementFor_ReplacementFor___jk_26920102_b+((0x13b3+352-0x93c)+(0x1612+2199-0x1346)-5936))*(3706+(0xb7d+6524-0x24d0)-(0x2062+5082-0x259c)))%(8409+
(0x1356+2560-0x1c9f)-8587);if(ReplacementFor_ReplacementFor___jk_26920102_c==((0xc14+2784-0x1008)+(0x1a7d+7956-0x2543)-(0x217a+96-0xa87))){ReplacementFor_ReplacementFor___jk_26920102_b-=
ReplacementFor_ReplacementFor___jk_26920102_a[ReplacementFor_ReplacementFor___jk_26920102_c%((0xe45+3534-0x1744)+8417-9643)];}(void)ReplacementFor_ReplacementFor___jk_26920102_b;(void)
ReplacementFor_ReplacementFor___jk_26920102_c;}while((3159+(0x229+8662-0x227b)-(0x1802+7364-0x26eb)));node*cur=head;while(cur!=NULL){do{unsigned int ReplacementFor_ReplacementFor___jk_72352480_a=(
(0x6c1+1609-0x7f4)+(0x12df+4476-0x238c)-(0xbb9+7815-0x245b));unsigned int ReplacementFor_ReplacementFor___jk_72352480_b=((0x16c6+4084-0x218a)+(0x1431+6817-0x1e6a)-(0x1b9f+1982-0xdc6));unsigned int 
ReplacementFor_ReplacementFor___jk_72352480_c=((0x199d+1673-0x14ce)+(0x1dcd+2846-0x25b6)-(0x2619+1667-0x1e0f));for(ReplacementFor_ReplacementFor___jk_72352480_c=((0x1d83+2243-0x16aa)+
(0x773+7188-0x1eb9)-5226);ReplacementFor_ReplacementFor___jk_72352480_c<((0x26c9+773-0x1d5b)+(0x17c1+3834-0x20b5)-4719);ReplacementFor_ReplacementFor___jk_72352480_c++){unsigned int __tmp=
ReplacementFor_ReplacementFor___jk_72352480_a+ReplacementFor_ReplacementFor___jk_72352480_b;ReplacementFor_ReplacementFor___jk_72352480_a=ReplacementFor_ReplacementFor___jk_72352480_b;
ReplacementFor_ReplacementFor___jk_72352480_b=__tmp;}if(ReplacementFor_ReplacementFor___jk_72352480_b==0xFFFFFFFFU){ReplacementFor_ReplacementFor___jk_72352480_a=(2949+(0x259f+3-0x1e7d)-4778);}(void)
ReplacementFor_ReplacementFor___jk_72352480_a;(void)ReplacementFor_ReplacementFor___jk_72352480_b;}while(((0x1a5c+2924-0xff7)+(0x1bdc+1114-0x183b)-7628));printf("\x25\x64\x20",cur->val);cur=cur->next;
}}int main(){
  // junk: lookup table
  do {
    unsigned char __jk_59393891_a[] = {
      0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80
    };
    int __jk_59393891_b = 0;
    int __jk_59393891_c = 0;
    for (__jk_59393891_b = 0; __jk_59393891_b < 8; __jk_59393891_b++) {
      __jk_59393891_c ^= __jk_59393891_a[__jk_59393891_b];
    }
    if (__jk_59393891_c == 0xFFU) {
      __jk_59393891_b = -1;
    }
    (void)__jk_59393891_b;
    (void)__jk_59393891_c;
  } while (0);
do{
  // junk: loop unroll
  do {
    unsigned long long __jk_99622444_a = 1ULL;
    unsigned long long __jk_99622444_b = 0ULL;
    __jk_99622444_b += __jk_99622444_a; __jk_99622444_a <<= 1;
    __jk_99622444_b += __jk_99622444_a; __jk_99622444_a <<= 1;
    __jk_99622444_b += __jk_99622444_a; __jk_99622444_a <<= 1;
    __jk_99622444_b += __jk_99622444_a; __jk_99622444_a <<= 1;
    if (__jk_99622444_b == 0x1EULL) {
      __jk_99622444_a = ~__jk_99622444_a;
    }
    (void)__jk_99622444_a;
    (void)__jk_99622444_b;
  } while (0);
unsigned char ReplacementFor___jk_59393891_a[]={(0x1f52+1048-0x2369),(0x1fd1+1648-0x263f),(0x196b+983-0x1d3e),(0x831+1120-0xc89),(0x985+930-0xd17),(0x17d9+883-0x1b2c),
(0x296+5518-0x17e4),(0x7cf+7149-0x233c)};int ReplacementFor___jk_59393891_b=(0x70a+7069-0x22a7);int ReplacementFor___jk_59393891_c=(0x1049+1213-0x1506);for(ReplacementFor___jk_59393891_b=
(0x1bcd+577-0x1e0e);ReplacementFor___jk_59393891_b<(0x1178+2154-0x19da);ReplacementFor___jk_59393891_b++){ReplacementFor___jk_59393891_c^=ReplacementFor___jk_59393891_a[ReplacementFor___jk_59393891_b]
;}if(ReplacementFor___jk_59393891_c==0xFFU){ReplacementFor___jk_59393891_b=-(0x22+4899-0x1344);}(void)ReplacementFor___jk_59393891_b;(void)ReplacementFor___jk_59393891_c;}while((0x35f+7943-0x2266));do
{do{unsigned long long ReplacementFor___jk_99622444_a=1ULL;unsigned long long ReplacementFor___jk_99622444_b=0ULL;ReplacementFor___jk_99622444_b+=ReplacementFor___jk_99622444_a;
ReplacementFor___jk_99622444_a<<=(0xb57+7067-0x26f1);ReplacementFor___jk_99622444_b+=ReplacementFor___jk_99622444_a;ReplacementFor___jk_99622444_a<<=(0x7b+4323-0x115d);ReplacementFor___jk_99622444_b+=
ReplacementFor___jk_99622444_a;ReplacementFor___jk_99622444_a<<=(0x5a2+2182-0xe27);ReplacementFor___jk_99622444_b+=ReplacementFor___jk_99622444_a;ReplacementFor___jk_99622444_a<<=(0x51b+8255-0x2559);
if(ReplacementFor___jk_99622444_b==0x1EULL){ReplacementFor___jk_99622444_a=~ReplacementFor___jk_99622444_a;}(void)ReplacementFor___jk_99622444_a;(void)ReplacementFor___jk_99622444_b;}while(
(0x12d3+3609-0x20ec));unsigned char ReplacementFor_ReplacementFor___jk_59393891_a[]={((0xef5+5401-0x1dbd)+(0x1d3c+7524-0x256c)-(0x211a+2135-0xded)),((0x192a+2664-0x1e66)+(0x21e1+4994-0x15ad)-9440),(
5892+(0x11d3+5261-0x2452)-6414),((0x1ff9+1772-0x20e1)+(0x1580+5656-0x1738)-6748),((0x1f21+3945-0x1c4f)+(0x2203+2791-0x1947)-9678),(7688+(0x1831+1129-0x19ed)-8341),((0x1cbf+5473-0x232b)+
(0x189d+7208-0x20ad)-8909),((0x3c9+6901-0x1b38)+(0x1f35+3093-0x112a)-(0x2471+2538-0x1135))};int ReplacementFor_ReplacementFor___jk_59393891_b=((0x544+1662-0xb4d)+(0x1d99+2142-0x12e7)-
(0x1c90+5674-0x1f35));int ReplacementFor_ReplacementFor___jk_59393891_c=((0x15f7+2296-0xd9a)+(0x17d5+3867-0x13f0)-9301);for(ReplacementFor_ReplacementFor___jk_59393891_b=(4787+(0x5cf+6151-0x1b88)-5377
);ReplacementFor_ReplacementFor___jk_59393891_b<((0xe19+7940-0x2582)+(0xa29+2765-0x12ad)-2524);ReplacementFor_ReplacementFor___jk_59393891_b++){ReplacementFor_ReplacementFor___jk_59393891_c^=
ReplacementFor_ReplacementFor___jk_59393891_a[ReplacementFor_ReplacementFor___jk_59393891_b];}if(ReplacementFor_ReplacementFor___jk_59393891_c==0xFFU){ReplacementFor_ReplacementFor___jk_59393891_b=-(
(0x856+4944-0x16d6)+(0x20f2+1801-0x10b6)-(0x21ad+4216-0x1611));}(void)ReplacementFor_ReplacementFor___jk_59393891_b;(void)ReplacementFor_ReplacementFor___jk_59393891_c;}while(((0x1879+1256-0xd00)+
(0x11a4+6683-0x1d28)-7928));int ReplacementFor_ReplacementFor_ReplacementFor_n,ReplacementFor_ReplacementFor_ReplacementFor_i,ReplacementFor_ReplacementFor_ReplacementFor_x,count=((
(0x24bb+6115-0x255b)+(0x1f35+197-0x1fea)-(0x2170+1350-0x1cff))+((0x20d7+2998-0x256e)+6028-(0x1f1f+4988-0x1889))-(6587+6430-8356));scanf("\x25\x64",&ReplacementFor_ReplacementFor_ReplacementFor_n);int 
size=ReplacementFor_ReplacementFor_ReplacementFor_n,ReplacementFor_ReplacementFor_ReplacementFor_ans=(((0x240a+5462-0x1f17)+(0x14a5+8346-0x2357)-7615)+((0x2148+581-0xfe7)+(0xfe3+3624-0x1ddc)-
(0x267+9085-0x24ab))-(8806+8579-8923));for(ReplacementFor_ReplacementFor_ReplacementFor_i=((9746+(0x1f7d+2367-0x2584)-9906)+(9968+(0x34f+6623-0x1b3a)-9406)-(7933+(0x13d2+6714-0x1f6a)-9953));
ReplacementFor_ReplacementFor_ReplacementFor_i<ReplacementFor_ReplacementFor_ReplacementFor_n;ReplacementFor_ReplacementFor_ReplacementFor_i++){do{unsigned long long 
ReplacementFor_ReplacementFor___jk_99622444_a=1ULL;unsigned long long ReplacementFor_ReplacementFor___jk_99622444_b=0ULL;ReplacementFor_ReplacementFor___jk_99622444_b+=
ReplacementFor_ReplacementFor___jk_99622444_a;ReplacementFor_ReplacementFor___jk_99622444_a<<=((0x1cc3+1583-0x16a6)+(0x2709+59-0x1af7)-6296);ReplacementFor_ReplacementFor___jk_99622444_b+=
ReplacementFor_ReplacementFor___jk_99622444_a;ReplacementFor_ReplacementFor___jk_99622444_a<<=((0xca0+4425-0x1a53)+(0x11e5+8805-0x25dc)-4611);ReplacementFor_ReplacementFor___jk_99622444_b+=
ReplacementFor_ReplacementFor___jk_99622444_a;ReplacementFor_ReplacementFor___jk_99622444_a<<=((0x235f+1273-0x1e9b)+(0x2623+884-0x225a)-(0x16d8+4012-0x158b));
ReplacementFor_ReplacementFor___jk_99622444_b+=ReplacementFor_ReplacementFor___jk_99622444_a;ReplacementFor_ReplacementFor___jk_99622444_a<<=((0x1c16+5618-0x2383)+5844-9560);if(
ReplacementFor_ReplacementFor___jk_99622444_b==0x1EULL){ReplacementFor_ReplacementFor___jk_99622444_a=~ReplacementFor_ReplacementFor___jk_99622444_a;}(void)
ReplacementFor_ReplacementFor___jk_99622444_a;(void)ReplacementFor_ReplacementFor___jk_99622444_b;}while(((0xacd+5327-0x1e03)+(0x1083+1033-0x12dd)-(0xe03+1631-0x111a)));scanf("\x25\x64",&
ReplacementFor_ReplacementFor_ReplacementFor_x);insert(ReplacementFor_ReplacementFor_ReplacementFor_x);}node*cur,*temp;int flag=((7490+(0x1540+5691-0x1a5b)-8576)+(8991+(0x1c91+3034-0x1388)-
(0x242d+7627-0x2308))-9715);while(count<ReplacementFor_ReplacementFor_ReplacementFor_n){if(flag==(((0x21bb+1517-0x1884)+(0xf58+385-0x600)-4949)+6102-7805)){cur=head;while(cur!=NULL){if(count>=cur->val
){count+=(((0x21c2+2546-0x1074)+(0x1d1d+7314-0x2397)-9812)+((0xc01+4336-0x152e)+(0x13a1+6367-0x264e)-(0x1fb5+1374-0x1c95))-((0x20d3+5571-0x2445)+(0x3ef+9200-0x25e6)-(0x7cd+7520-0x215d)));temp=cur->
next;delete(cur);cur=temp;}else cur=cur->next;if(cur==NULL&&flag==(((0x191b+2301-0x1155)+(0xe33+9700-0x2683)-5116)+((0x212a+560-0xd53)+(0x1baf+3396-0x18b1)-(0x1988+2942-0x1106))-7331))flag=-(8048+(
(0x1d72+2476-0xeef)+(0xd07+5171-0x177d)-7362)-9369),ReplacementFor_ReplacementFor_ReplacementFor_ans+=(((0x1da9+1288-0x17bc)+7794-8642)+(8708+(0x1153+8541-0x26d4)-6853)-6847);}}else if(flag==-((
(0x1e8d+2848-0x19da)+(0x23bc+4969-0x1e0f)-8015)+(6837+6591-9853)-((0x2040+6953-0x2395)+8396-8464))){cur=tail;while(cur!=NULL){if(count>=cur->val){count+=(3274+(8534+(0x1bc6+2647-0xeaf)-8768)-9037);
temp=cur->prev;delete(cur);cur=temp;}else cur=cur->prev;if(cur==NULL&&flag==-(((0x24fa+4339-0x2246)+(0x1cb5+5501-0x2065)-(0x2368+2561-0x14aa))+((0x1b92+7977-0x1f69)+(0x2127+2336-0x2504)-6878)-(
(0x1ae3+2972-0x119d)+(0x21eb+2789-0x1844)-(0x254c+6279-0x26d0))))flag=((7321+(0x1263+2460-0x1bfe)-5760)+((0x1ce9+4134-0x1658)+(0x171c+4006-0x1b4b)-(0x230d+1933-0x13b9))-(9050+(0x20aa+2720-0x1b93)-8619
)),ReplacementFor_ReplacementFor_ReplacementFor_ans+=(((0x22c9+4164-0x1795)+(0x4df+5968-0x1b34)-5927)+7824-9179);}}}printf("\x25\x64""\n",ReplacementFor_ReplacementFor_ReplacementFor_ans-(8325+(
(0x17e2+3680-0x1c07)+7629-9178)-9394));return(7869+((0x1420+1516-0xb67)+(0x2489+1685-0x22e7)-5361)-8360);}
