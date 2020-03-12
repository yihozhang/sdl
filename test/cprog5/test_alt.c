
      #include <string.h>
      #include <fcntl.h>
      #include <errno.h>
      #include <err.h>
      #include <sys/mman.h>
      #include <sys/stat.h>
      #include <stdio.h>
      #include <stdint.h>
      #include <unistd.h>
      #ifndef MAP_FILE
      #define MAP_FILE MAP_SHARED
      #endif
      int fsize(int fd) {
        struct stat stat;
        int res = fstat(fd,&stat);
        return stat.st_size;
      }
      int printll(FILE* f, char* s) {
        while (*s != '\n' && *s != '\0' && *s != '\t') {
          fputc(*s++, f);
        }
        return 0;
      }
      long hash(char *str0, int len)
      {
        unsigned char* str = (unsigned char*)str0;
        unsigned long hash = 5381;
        int c;

        while ((c = *str++) && c != '\t' && c != '\n' && len--)
          hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

        return hash;
      }
      // void swap(void **a, void **b) {
      //   void *t = *a;
      //   *a = *b
      //   *b = t;
      // }
      // void swap_int(int32_t *a, int32_t *b) {
      //   int32_t t = *a;
      //   *a = *b
      //   *b = t;
      // }
      #define SWAP(x, y) do { typeof(x) SWAP = x; x = y; y = SWAP; } while (0)
      size_t tpch_strlen(const char* str) {
        const char* start = str;
        while (*str != '\n' && (*str != '\t') && (*str != '\0')) str++;
        return str - start;
      }
      int tpch_strcmp(const char *s1, const char *s2) {
        size_t l1 = tpch_strlen(s1);
        size_t l2 = tpch_strlen(s2);
        if (l1 > l2) l1 = l2;
        return strncmp(s1,s2,l1);
      }
      int tpch_streq(const char *s1, const char *s2) {
        if (s1 == s2) return 1;
        while (*s1 != '\n' && *s1 != '\t' && *s1 != '\0') {
          if (*s1 != *s2) return 0;
          s1++; s2++;
        }
        return *s2 == '\n' || *s2 == '\t' || *s2 == '\0';
      }
      void Snippet(char*);
      int main(int argc, char *argv[])
      {
        if (argc != 2) {
          printf("usage: query <filename>\n");
          return 0;
        }
        Snippet(argv[1]);
        return 0;
      }

      
/*****************************************
  Emitting C Generated Code                  
*******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
void Snippet(char*  x0) {
int32_t x1 = 4194304;
int32_t x2 = 4194304;
int32_t* x3 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x4 = 0;
int32_t x5 = 4194304;
int32_t* x6 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x7 = 0;
int32_t x8 = 4194304;
int32_t* x9 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x10 = 0;
int32_t x11 = 4194304;
int32_t* x12 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x13 = 0;
int32_t x14 = 0;
int32_t x15 = 4194304;
int32_t* x16 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x17 = 0;
int32_t x18 = 4194304;
int32_t* x19 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x20 = 0;
int32_t* x21 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x22 = (int32_t*)malloc(4194304 * sizeof(int32_t));
for(int x24=0; x24 < 4194304; x24++) {
x21[x24] = -1;

}
for(int x28=0; x28 < 4194304; x28++) {
x22[x28] = -1;

}
int32_t x32 = 4194304;
int32_t x33 = 4194304;
int32_t* x34 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x35 = 0;
int32_t x36 = 4194304;
int32_t* x37 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x38 = 0;
int32_t x39 = 4194304;
int32_t* x40 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x41 = 0;
int32_t x42 = 4194304;
int32_t* x43 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x44 = 0;
int32_t x45 = 0;
int32_t x46 = 4194304;
int32_t* x47 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x48 = 0;
int32_t x49 = 4194304;
int32_t* x50 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x51 = 0;
int32_t* x52 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x53 = (int32_t*)malloc(4194304 * sizeof(int32_t));
for(int x54=0; x54 < 4194304; x54++) {
x52[x54] = -1;

}
for(int x58=0; x58 < 4194304; x58++) {
x53[x58] = -1;

}
int32_t x62 = 4194304;
int32_t x63 = 4194304;
int32_t* x64 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x65 = 0;
int32_t x66 = 0;
int32_t x67 = 4194304;
int32_t* x68 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x69 = 0;
int32_t* x70 = (int32_t*)malloc(4194304 * sizeof(int32_t));
for(int x71=0; x71 < 4194304; x71++) {
x70[x71] = -1;

}
int32_t x75 = 4194304;
int32_t x76 = 4194304;
int32_t* x77 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x78 = 0;
int32_t x79 = 4194304;
int32_t* x80 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x81 = 0;
int32_t x82 = 4194304;
int32_t* x83 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x84 = 0;
int32_t x85 = 4194304;
int32_t* x86 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x87 = 0;
int32_t x88 = 0;
int32_t x89 = 4194304;
int32_t* x90 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x91 = 0;
int32_t x92 = 4194304;
int32_t* x93 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x94 = 0;
int32_t* x95 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x96 = (int32_t*)malloc(4194304 * sizeof(int32_t));
for(int x97=0; x97 < 4194304; x97++) {
x95[x97] = -1;

}
for(int x101=0; x101 < 4194304; x101++) {
x96[x101] = -1;

}
int32_t x105 = 4194304;
int32_t x106 = 4194304;
int32_t* x107 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x108 = 0;
int32_t x109 = 0;
int32_t x110 = 4194304;
int32_t* x111 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x112 = 0;
int32_t* x113 = (int32_t*)malloc(4194304 * sizeof(int32_t));
for(int x114=0; x114 < 4194304; x114++) {
x113[x114] = -1;

}
int32_t x118 = 4194304;
int32_t x119 = 4194304;
int32_t* x120 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x121 = 0;
int32_t x122 = 0;
int32_t x123 = 4194304;
int32_t* x124 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x125 = 0;
int32_t* x126 = (int32_t*)malloc(4194304 * sizeof(int32_t));
for(int x127=0; x127 < 4194304; x127++) {
x126[x127] = -1;

}
int32_t x134 = 0;
int32_t x131 = open("high.facts",0);
int32_t x132 = fsize(x131);
char* x133 = mmap(0, x132, PROT_READ, MAP_FILE | MAP_SHARED, x131, 0);
for (;;) {
int32_t x135 = x134;
bool x136 = x135 < x132;
if (!x136) break;
int32_t x138 = x134;
for (;;) {
int32_t x139 = x134;
char x140 = x133[x139];
bool x141 = x140 != '\n';
if (!x141) break;
x134 += 1;
}
int32_t x146 = x134;
x134 += 1;
char* x149 = x133+x138;
int32_t x150 = atoi(x149);
printf("INSERT INTO HASHTABLE");
printf("%d ",x150);
printf("\n");
int32_t x154 = x109;
int32_t x155 = x105;
bool x156 = x154 == x155;
if (x156) {
x105 *= 4;
int32_t x158 = x105;
printf("buffer.resize %d\n",x158);
} else {
}
x107[x154] = x150;
x109 += 1;
int32_t x164 = 0;
int32_t x165 = x150 + 23333;
x164 = x165;
int32_t x167 = x165 & 4194303;
int32_t x168 = x113[x167];
int32_t x169 = x168;
x113[x167] = x154;
x111[x154] = x168;
}
int32_t x177 = 0;
int32_t x174 = open("low.facts",0);
int32_t x175 = fsize(x174);
char* x176 = mmap(0, x175, PROT_READ, MAP_FILE | MAP_SHARED, x174, 0);
for (;;) {
int32_t x178 = x177;
bool x179 = x178 < x175;
if (!x179) break;
int32_t x181 = x177;
for (;;) {
int32_t x182 = x177;
char x183 = x176[x182];
bool x184 = x183 != '\n';
if (!x184) break;
x177 += 1;
}
int32_t x189 = x177;
x177 += 1;
char* x192 = x176+x181;
int32_t x193 = atoi(x192);
printf("INSERT INTO HASHTABLE");
printf("%d ",x193);
printf("\n");
int32_t x197 = x66;
int32_t x198 = x62;
bool x199 = x197 == x198;
if (x199) {
x62 *= 4;
int32_t x201 = x62;
printf("buffer.resize %d\n",x201);
} else {
}
x64[x197] = x193;
x66 += 1;
int32_t x207 = 0;
int32_t x208 = x193 + 23333;
x207 = x208;
int32_t x210 = x208 & 4194303;
int32_t x211 = x70[x210];
int32_t x212 = x211;
x70[x210] = x197;
x68[x197] = x211;
}
int32_t x220 = 0;
int32_t x217 = open("med.facts",0);
int32_t x218 = fsize(x217);
char* x219 = mmap(0, x218, PROT_READ, MAP_FILE | MAP_SHARED, x217, 0);
for (;;) {
int32_t x221 = x220;
bool x222 = x221 < x218;
if (!x222) break;
int32_t x224 = x220;
for (;;) {
int32_t x225 = x220;
char x226 = x219[x225];
bool x227 = x226 != '\n';
if (!x227) break;
x220 += 1;
}
int32_t x232 = x220;
x220 += 1;
char* x235 = x219+x224;
int32_t x236 = atoi(x235);
printf("INSERT INTO HASHTABLE");
printf("%d ",x236);
printf("\n");
int32_t x240 = x122;
int32_t x241 = x118;
bool x242 = x240 == x241;
if (x242) {
x118 *= 4;
int32_t x244 = x118;
printf("buffer.resize %d\n",x244);
} else {
}
x120[x240] = x236;
x122 += 1;
int32_t x250 = 0;
int32_t x251 = x236 + 23333;
x250 = x251;
int32_t x253 = x251 & 4194303;
int32_t x254 = x126[x253];
int32_t x255 = x254;
x126[x253] = x240;
x124[x240] = x254;
}
bool x260 = true;
int32_t x261 = 0;
x261 = 23333;
x261 = -1558899686;
x261 = 1001258975;
x261 = 1303102324;
int32_t x266 = 1303102324 & 4194303;
int32_t x267 = x21[x266];
int32_t x268 = x267;
bool x269 = true;
for (;;) {
bool x270 = x269;
bool x274;
if (x270) {
int32_t x271 = x268;
bool x272 = x271 != -1;
x274 = x272;
} else {
x274 = false;
}
if (!x274) break;
int32_t x276 = x268;
bool x277 = true;
int32_t x278 = x3[x276];
bool x279 = 0 == x278;
if (x279) {
} else {
x277 = false;
}
int32_t x283 = x6[x276];
bool x284 = 0 == x283;
if (x284) {
} else {
x277 = false;
}
int32_t x288 = x9[x276];
bool x289 = 0 == x288;
if (x289) {
} else {
x277 = false;
}
int32_t x293 = x12[x276];
bool x294 = 0 == x293;
if (x294) {
} else {
x277 = false;
}
bool x298 = x277;
if (x298) {
bool x299 = true;
if (x279) {
} else {
x299 = false;
}
if (x284) {
} else {
x299 = false;
}
if (x289) {
} else {
x299 = false;
}
if (x294) {
} else {
x299 = false;
}
bool x312 = x299;
if (x312) {
x260 = false;
} else {
}
bool x316 = x260;
x269 = x316;
} else {
}
int32_t x320 = x16[x276];
x268 = x320;
}
bool x324 = x260;
int32_t x348 = 23333 & 4194303;
int32_t x349 = x22[x348];
if (x324) {
printf("INSERT INTO HASHTABLE");
printf("%d ",0);
printf("%d ",0);
printf("%d ",0);
printf("%d ",0);
printf("\n");
x3[0] = 0;
x6[0] = 0;
x9[0] = 0;
x12[0] = 0;
x14 += 1;
int32_t x338 = 0;
x338 = 23333;
x338 = -1558899686;
x338 = 1001258975;
x338 = 1303102324;
int32_t x343 = x267;
x21[x266] = 0;
x16[0] = x267;
int32_t x346 = 0;
x346 = 23333;
int32_t x350 = x349;
x22[x348] = 0;
x19[0] = x349;
} else {
}
int32_t x355 = x14;
for(int x357=0; x357 < x355; x357++) {
printf("loop");
printf(" SCAN FIND TUPLE");
int32_t x360 = x3[x357];
printf("%d ",x360);
int32_t x362 = x6[x357];
printf("%d ",x362);
int32_t x364 = x9[x357];
printf("%d ",x364);
int32_t x366 = x12[x357];
printf("%d ",x366);
printf("\n");
bool x369 = true;
int32_t x370 = 0;
int32_t x371 = x360 + 23333;
x370 = x371;
int32_t x373 = x371 * 19260817;
int32_t x374 = x373 + x362;
int32_t x375 = x374 + 23333;
x370 = x375;
int32_t x377 = x375 * 19260817;
int32_t x378 = x377 + x364;
int32_t x379 = x378 + 23333;
x370 = x379;
int32_t x381 = x379 * 19260817;
int32_t x382 = x381 + x366;
int32_t x383 = x382 + 23333;
x370 = x383;
int32_t x385 = x383 & 4194303;
int32_t x386 = x95[x385];
int32_t x387 = x386;
bool x388 = true;
for (;;) {
bool x389 = x388;
bool x393;
if (x389) {
int32_t x390 = x387;
bool x391 = x390 != -1;
x393 = x391;
} else {
x393 = false;
}
if (!x393) break;
int32_t x395 = x387;
bool x396 = true;
int32_t x397 = x77[x395];
bool x398 = x360 == x397;
if (x398) {
} else {
x396 = false;
}
int32_t x402 = x80[x395];
bool x403 = x362 == x402;
if (x403) {
} else {
x396 = false;
}
int32_t x407 = x83[x395];
bool x408 = x364 == x407;
if (x408) {
} else {
x396 = false;
}
int32_t x412 = x86[x395];
bool x413 = x366 == x412;
if (x413) {
} else {
x396 = false;
}
bool x417 = x396;
if (x417) {
bool x418 = true;
if (x398) {
} else {
x418 = false;
}
if (x403) {
} else {
x418 = false;
}
if (x408) {
} else {
x418 = false;
}
if (x413) {
} else {
x418 = false;
}
bool x431 = x418;
if (x431) {
x369 = false;
} else {
}
bool x435 = x369;
x388 = x435;
} else {
}
int32_t x439 = x90[x395];
x387 = x439;
}
bool x443 = x369;
if (x443) {
printf("INSERT INTO HASHTABLE");
printf("%d ",x360);
printf("%d ",x362);
printf("%d ",x364);
printf("%d ",x366);
printf("\n");
int32_t x452 = x88;
int32_t x453 = x75;
bool x454 = x452 == x453;
if (x454) {
x75 *= 4;
int32_t x456 = x75;
printf("buffer.resize %d\n",x456);
} else {
}
x77[x452] = x360;
x80[x452] = x362;
x83[x452] = x364;
x86[x452] = x366;
x88 += 1;
int32_t x465 = 0;
x465 = x371;
x465 = x375;
x465 = x379;
x465 = x383;
int32_t x470 = x386;
x95[x385] = x452;
x90[x452] = x386;
int32_t x473 = 0;
x473 = x371;
int32_t x475 = x371 & 4194303;
int32_t x476 = x96[x475];
int32_t x477 = x476;
x96[x475] = x452;
x93[x452] = x476;
} else {
}

}
bool x484 = true;
int32_t x485 = 0;
int32_t x501 = x96[x348];
int32_t x684 = 23334 & 4194303;
int32_t x685 = x53[x684];
int32_t x710 = x96[x684];
int32_t x893 = 23335 & 4194303;
int32_t x894 = x53[x893];
int32_t x948 = x22[x684];
int32_t x1188 = 23336 & 4194303;
int32_t x1189 = x53[x1188];
int32_t x1457 = x96[x1188];
int32_t x1635 = 23340 & 4194303;
int32_t x1636 = x53[x1635];
int32_t x1830 = 23337 & 4194303;
int32_t x1831 = x53[x1830];
int32_t x1849 = x96[x1830];
for (;;) {
bool x486 = x484;
if (!x486) break;
int32_t x488 = x485;
printf("LOOP COUNT: %d\n",x488);
x485 += 1;
int32_t x491 = x88;
bool x492 = x491 == 0;
bool x498;
if (x492) {
x498 = false;
} else {
int32_t x494 = x109;
bool x495 = x494 == 0;
bool x496 = !x495;
x498 = x496;
}
if (x498) {
int32_t x499 = 0;
x499 = 23333;
int32_t x502 = x501;
for (;;) {
int32_t x503 = x502;
bool x504 = x503 != -1;
if (!x504) break;
int32_t x506 = x502;
bool x507 = true;
int32_t x508 = x77[x506];
bool x509 = 0 == x508;
if (x509) {
} else {
x507 = false;
}
bool x513 = x507;
if (x513) {
printf("@delta_loop");
printf(" INDEX SCAN FIND TUPLE");
printf("%d ",x508);
int32_t x517 = x80[x506];
printf("%d ",x517);
int32_t x519 = x83[x506];
printf("%d ",x519);
int32_t x521 = x86[x506];
printf("%d ",x521);
printf("\n");
int32_t x524 = x109;
for(int x526=0; x526 < x524; x526++) {
printf("high");
printf(" SCAN FIND TUPLE");
int32_t x529 = x107[x526];
printf("%d ",x529);
printf("\n");
bool x532 = false;
int32_t x533 = 0;
x533 = 23334;
int32_t x535 = -1539662202 + x529;
int32_t x536 = x535 + 23333;
x533 = x536;
int32_t x538 = x536 * 19260817;
int32_t x539 = x538 + x519;
int32_t x540 = x539 + 23333;
x533 = x540;
int32_t x542 = x540 * 19260817;
int32_t x543 = x542 + x521;
int32_t x544 = x543 + 23333;
x533 = x544;
int32_t x546 = x544 & 4194303;
int32_t x547 = x21[x546];
int32_t x548 = x547;
bool x549 = true;
for (;;) {
bool x550 = x549;
bool x554;
if (x550) {
int32_t x551 = x548;
bool x552 = x551 != -1;
x554 = x552;
} else {
x554 = false;
}
if (!x554) break;
int32_t x556 = x548;
bool x557 = true;
int32_t x558 = x3[x556];
bool x559 = 1 == x558;
if (x559) {
} else {
x557 = false;
}
int32_t x563 = x6[x556];
bool x564 = x529 == x563;
if (x564) {
} else {
x557 = false;
}
int32_t x568 = x9[x556];
bool x569 = x519 == x568;
if (x569) {
} else {
x557 = false;
}
int32_t x573 = x12[x556];
bool x574 = x521 == x573;
if (x574) {
} else {
x557 = false;
}
bool x578 = x557;
if (x578) {
x532 = true;
x549 = false;
} else {
}
int32_t x583 = x16[x556];
x548 = x583;
}
bool x587 = x532;
if (x587) {
} else {
bool x589 = true;
int32_t x590 = 0;
x590 = 23334;
x590 = x536;
x590 = x540;
x590 = x544;
int32_t x595 = x52[x546];
int32_t x596 = x595;
bool x597 = true;
for (;;) {
bool x598 = x597;
bool x602;
if (x598) {
int32_t x599 = x596;
bool x600 = x599 != -1;
x602 = x600;
} else {
x602 = false;
}
if (!x602) break;
int32_t x604 = x596;
bool x605 = true;
int32_t x606 = x34[x604];
bool x607 = 1 == x606;
if (x607) {
} else {
x605 = false;
}
int32_t x611 = x37[x604];
bool x612 = x529 == x611;
if (x612) {
} else {
x605 = false;
}
int32_t x616 = x40[x604];
bool x617 = x519 == x616;
if (x617) {
} else {
x605 = false;
}
int32_t x621 = x43[x604];
bool x622 = x521 == x621;
if (x622) {
} else {
x605 = false;
}
bool x626 = x605;
if (x626) {
bool x627 = true;
if (x607) {
} else {
x627 = false;
}
if (x612) {
} else {
x627 = false;
}
if (x617) {
} else {
x627 = false;
}
if (x622) {
} else {
x627 = false;
}
bool x640 = x627;
if (x640) {
x589 = false;
} else {
}
bool x644 = x589;
x597 = x644;
} else {
}
int32_t x648 = x47[x604];
x596 = x648;
}
bool x652 = x589;
if (x652) {
printf("INSERT INTO HASHTABLE");
printf("%d ",1);
printf("%d ",x529);
printf("%d ",x519);
printf("%d ",x521);
printf("\n");
int32_t x661 = x45;
int32_t x662 = x32;
bool x663 = x661 == x662;
if (x663) {
x32 *= 4;
int32_t x665 = x32;
printf("buffer.resize %d\n",x665);
} else {
}
x34[x661] = 1;
x37[x661] = x529;
x40[x661] = x519;
x43[x661] = x521;
x45 += 1;
int32_t x674 = 0;
x674 = 23334;
x674 = x536;
x674 = x540;
x674 = x544;
int32_t x679 = x595;
x52[x546] = x661;
x47[x661] = x595;
int32_t x682 = 0;
x682 = 23334;
int32_t x686 = x685;
x53[x684] = x661;
x50[x661] = x685;
} else {
}
}

}
} else {
}
int32_t x697 = x93[x506];
x502 = x697;
}
} else {
}
bool x707;
if (x492) {
x707 = false;
} else {
int32_t x703 = x122;
bool x704 = x703 == 0;
bool x705 = !x704;
x707 = x705;
}
if (x707) {
int32_t x708 = 0;
x708 = 23334;
int32_t x711 = x710;
for (;;) {
int32_t x712 = x711;
bool x713 = x712 != -1;
if (!x713) break;
int32_t x715 = x711;
bool x716 = true;
int32_t x717 = x77[x715];
bool x718 = 1 == x717;
if (x718) {
} else {
x716 = false;
}
bool x722 = x716;
if (x722) {
printf("@delta_loop");
printf(" INDEX SCAN FIND TUPLE");
printf("%d ",x717);
int32_t x726 = x80[x715];
printf("%d ",x726);
int32_t x728 = x83[x715];
printf("%d ",x728);
int32_t x730 = x86[x715];
printf("%d ",x730);
printf("\n");
int32_t x733 = x122;
int32_t x744 = -1520401385 + x726;
int32_t x745 = x744 + 23333;
int32_t x747 = x745 * 19260817;
int32_t x748 = x747 + x728;
int32_t x749 = x748 + 23333;
int32_t x751 = x749 * 19260817;
for(int x735=0; x735 < x733; x735++) {
printf("med");
printf(" SCAN FIND TUPLE");
int32_t x738 = x120[x735];
printf("%d ",x738);
printf("\n");
bool x741 = false;
int32_t x742 = 0;
x742 = 23335;
x742 = x745;
x742 = x749;
int32_t x752 = x751 + x738;
int32_t x753 = x752 + 23333;
x742 = x753;
int32_t x755 = x753 & 4194303;
int32_t x756 = x21[x755];
int32_t x757 = x756;
bool x758 = true;
for (;;) {
bool x759 = x758;
bool x763;
if (x759) {
int32_t x760 = x757;
bool x761 = x760 != -1;
x763 = x761;
} else {
x763 = false;
}
if (!x763) break;
int32_t x765 = x757;
bool x766 = true;
int32_t x767 = x3[x765];
bool x768 = 2 == x767;
if (x768) {
} else {
x766 = false;
}
int32_t x772 = x6[x765];
bool x773 = x726 == x772;
if (x773) {
} else {
x766 = false;
}
int32_t x777 = x9[x765];
bool x778 = x728 == x777;
if (x778) {
} else {
x766 = false;
}
int32_t x782 = x12[x765];
bool x783 = x738 == x782;
if (x783) {
} else {
x766 = false;
}
bool x787 = x766;
if (x787) {
x741 = true;
x758 = false;
} else {
}
int32_t x792 = x16[x765];
x757 = x792;
}
bool x796 = x741;
if (x796) {
} else {
bool x798 = true;
int32_t x799 = 0;
x799 = 23335;
x799 = x745;
x799 = x749;
x799 = x753;
int32_t x804 = x52[x755];
int32_t x805 = x804;
bool x806 = true;
for (;;) {
bool x807 = x806;
bool x811;
if (x807) {
int32_t x808 = x805;
bool x809 = x808 != -1;
x811 = x809;
} else {
x811 = false;
}
if (!x811) break;
int32_t x813 = x805;
bool x814 = true;
int32_t x815 = x34[x813];
bool x816 = 2 == x815;
if (x816) {
} else {
x814 = false;
}
int32_t x820 = x37[x813];
bool x821 = x726 == x820;
if (x821) {
} else {
x814 = false;
}
int32_t x825 = x40[x813];
bool x826 = x728 == x825;
if (x826) {
} else {
x814 = false;
}
int32_t x830 = x43[x813];
bool x831 = x738 == x830;
if (x831) {
} else {
x814 = false;
}
bool x835 = x814;
if (x835) {
bool x836 = true;
if (x816) {
} else {
x836 = false;
}
if (x821) {
} else {
x836 = false;
}
if (x826) {
} else {
x836 = false;
}
if (x831) {
} else {
x836 = false;
}
bool x849 = x836;
if (x849) {
x798 = false;
} else {
}
bool x853 = x798;
x806 = x853;
} else {
}
int32_t x857 = x47[x813];
x805 = x857;
}
bool x861 = x798;
if (x861) {
printf("INSERT INTO HASHTABLE");
printf("%d ",2);
printf("%d ",x726);
printf("%d ",x728);
printf("%d ",x738);
printf("\n");
int32_t x870 = x45;
int32_t x871 = x32;
bool x872 = x870 == x871;
if (x872) {
x32 *= 4;
int32_t x874 = x32;
printf("buffer.resize %d\n",x874);
} else {
}
x34[x870] = 2;
x37[x870] = x726;
x40[x870] = x728;
x43[x870] = x738;
x45 += 1;
int32_t x883 = 0;
x883 = 23335;
x883 = x745;
x883 = x749;
x883 = x753;
int32_t x888 = x804;
x52[x755] = x870;
x47[x870] = x804;
int32_t x891 = 0;
x891 = 23335;
int32_t x895 = x894;
x53[x893] = x870;
x50[x870] = x894;
} else {
}
}

}
} else {
}
int32_t x906 = x93[x715];
x711 = x906;
}
} else {
}
bool x916;
if (x492) {
x916 = false;
} else {
int32_t x912 = x14;
bool x913 = x912 == 0;
bool x914 = !x913;
x916 = x914;
}
bool x921;
if (x916) {
int32_t x917 = x66;
bool x918 = x917 == 0;
bool x919 = !x918;
x921 = x919;
} else {
x921 = false;
}
if (x921) {
int32_t x922 = 0;
x922 = 23333;
int32_t x924 = x501;
for (;;) {
int32_t x925 = x924;
bool x926 = x925 != -1;
if (!x926) break;
int32_t x928 = x924;
bool x929 = true;
int32_t x930 = x77[x928];
bool x931 = 0 == x930;
if (x931) {
} else {
x929 = false;
}
bool x935 = x929;
if (x935) {
printf("@delta_loop");
printf(" INDEX SCAN FIND TUPLE");
printf("%d ",x930);
int32_t x939 = x80[x928];
printf("%d ",x939);
int32_t x941 = x83[x928];
printf("%d ",x941);
int32_t x943 = x86[x928];
printf("%d ",x943);
printf("\n");
int32_t x946 = 0;
x946 = 23334;
int32_t x949 = x948;
for (;;) {
int32_t x950 = x949;
bool x951 = x950 != -1;
if (!x951) break;
int32_t x953 = x949;
bool x954 = true;
int32_t x955 = x3[x953];
bool x956 = 1 == x955;
if (x956) {
} else {
x954 = false;
}
bool x960 = x954;
if (x960) {
printf("loop");
printf(" INDEX SCAN FIND TUPLE");
printf("%d ",x955);
int32_t x964 = x6[x953];
printf("%d ",x964);
int32_t x966 = x9[x953];
printf("%d ",x966);
int32_t x968 = x12[x953];
printf("%d ",x968);
printf("\n");
bool x971 = false;
int32_t x972 = 0;
x972 = 23334;
int32_t x974 = -1539662202 + x964;
int32_t x975 = x974 + 23333;
x972 = x975;
int32_t x977 = x975 * 19260817;
int32_t x978 = x977 + x966;
int32_t x979 = x978 + 23333;
x972 = x979;
int32_t x981 = x979 * 19260817;
int32_t x982 = x981 + x968;
int32_t x983 = x982 + 23333;
x972 = x983;
int32_t x985 = x983 & 4194303;
int32_t x986 = x95[x985];
int32_t x987 = x986;
bool x988 = true;
for (;;) {
bool x989 = x988;
bool x993;
if (x989) {
int32_t x990 = x987;
bool x991 = x990 != -1;
x993 = x991;
} else {
x993 = false;
}
if (!x993) break;
int32_t x995 = x987;
bool x996 = true;
int32_t x997 = x77[x995];
bool x998 = 1 == x997;
if (x998) {
} else {
x996 = false;
}
int32_t x1002 = x80[x995];
bool x1003 = x964 == x1002;
if (x1003) {
} else {
x996 = false;
}
int32_t x1007 = x83[x995];
bool x1008 = x966 == x1007;
if (x1008) {
} else {
x996 = false;
}
int32_t x1012 = x86[x995];
bool x1013 = x968 == x1012;
if (x1013) {
} else {
x996 = false;
}
bool x1017 = x996;
if (x1017) {
x971 = true;
x988 = false;
} else {
}
int32_t x1022 = x90[x995];
x987 = x1022;
}
bool x1026 = x971;
if (x1026) {
} else {
int32_t x1028 = x66;
int32_t x1039 = -1501140568 + x964;
int32_t x1040 = x1039 + 23333;
int32_t x1042 = x1040 * 19260817;
for(int x1030=0; x1030 < x1028; x1030++) {
printf("low");
printf(" SCAN FIND TUPLE");
int32_t x1033 = x64[x1030];
printf("%d ",x1033);
printf("\n");
bool x1036 = false;
int32_t x1037 = 0;
x1037 = 23336;
x1037 = x1040;
int32_t x1043 = x1042 + x1033;
int32_t x1044 = x1043 + 23333;
x1037 = x1044;
int32_t x1046 = x1044 * 19260817;
int32_t x1047 = x1046 + x943;
int32_t x1048 = x1047 + 23333;
x1037 = x1048;
int32_t x1050 = x1048 & 4194303;
int32_t x1051 = x21[x1050];
int32_t x1052 = x1051;
bool x1053 = true;
for (;;) {
bool x1054 = x1053;
bool x1058;
if (x1054) {
int32_t x1055 = x1052;
bool x1056 = x1055 != -1;
x1058 = x1056;
} else {
x1058 = false;
}
if (!x1058) break;
int32_t x1060 = x1052;
bool x1061 = true;
int32_t x1062 = x3[x1060];
bool x1063 = 3 == x1062;
if (x1063) {
} else {
x1061 = false;
}
int32_t x1067 = x6[x1060];
bool x1068 = x964 == x1067;
if (x1068) {
} else {
x1061 = false;
}
int32_t x1072 = x9[x1060];
bool x1073 = x1033 == x1072;
if (x1073) {
} else {
x1061 = false;
}
int32_t x1077 = x12[x1060];
bool x1078 = x943 == x1077;
if (x1078) {
} else {
x1061 = false;
}
bool x1082 = x1061;
if (x1082) {
x1036 = true;
x1053 = false;
} else {
}
int32_t x1087 = x16[x1060];
x1052 = x1087;
}
bool x1091 = x1036;
if (x1091) {
} else {
bool x1093 = true;
int32_t x1094 = 0;
x1094 = 23336;
x1094 = x1040;
x1094 = x1044;
x1094 = x1048;
int32_t x1099 = x52[x1050];
int32_t x1100 = x1099;
bool x1101 = true;
for (;;) {
bool x1102 = x1101;
bool x1106;
if (x1102) {
int32_t x1103 = x1100;
bool x1104 = x1103 != -1;
x1106 = x1104;
} else {
x1106 = false;
}
if (!x1106) break;
int32_t x1108 = x1100;
bool x1109 = true;
int32_t x1110 = x34[x1108];
bool x1111 = 3 == x1110;
if (x1111) {
} else {
x1109 = false;
}
int32_t x1115 = x37[x1108];
bool x1116 = x964 == x1115;
if (x1116) {
} else {
x1109 = false;
}
int32_t x1120 = x40[x1108];
bool x1121 = x1033 == x1120;
if (x1121) {
} else {
x1109 = false;
}
int32_t x1125 = x43[x1108];
bool x1126 = x943 == x1125;
if (x1126) {
} else {
x1109 = false;
}
bool x1130 = x1109;
if (x1130) {
bool x1131 = true;
if (x1111) {
} else {
x1131 = false;
}
if (x1116) {
} else {
x1131 = false;
}
if (x1121) {
} else {
x1131 = false;
}
if (x1126) {
} else {
x1131 = false;
}
bool x1144 = x1131;
if (x1144) {
x1093 = false;
} else {
}
bool x1148 = x1093;
x1101 = x1148;
} else {
}
int32_t x1152 = x47[x1108];
x1100 = x1152;
}
bool x1156 = x1093;
if (x1156) {
printf("INSERT INTO HASHTABLE");
printf("%d ",3);
printf("%d ",x964);
printf("%d ",x1033);
printf("%d ",x943);
printf("\n");
int32_t x1165 = x45;
int32_t x1166 = x32;
bool x1167 = x1165 == x1166;
if (x1167) {
x32 *= 4;
int32_t x1169 = x32;
printf("buffer.resize %d\n",x1169);
} else {
}
x34[x1165] = 3;
x37[x1165] = x964;
x40[x1165] = x1033;
x43[x1165] = x943;
x45 += 1;
int32_t x1178 = 0;
x1178 = 23336;
x1178 = x1040;
x1178 = x1044;
x1178 = x1048;
int32_t x1183 = x1099;
x52[x1050] = x1165;
x47[x1165] = x1099;
int32_t x1186 = 0;
x1186 = 23336;
int32_t x1190 = x1189;
x53[x1188] = x1165;
x50[x1165] = x1189;
} else {
}
}

}
}
} else {
}
int32_t x1203 = x19[x953];
x949 = x1203;
}
} else {
}
int32_t x1209 = x93[x928];
x924 = x1209;
}
} else {
}
int32_t x1215 = x14;
bool x1216 = x1215 == 0;
bool x1218;
if (x1216) {
x1218 = false;
} else {
bool x493 = !x492;
x1218 = x493;
}
bool x1223;
if (x1218) {
int32_t x1219 = x66;
bool x1220 = x1219 == 0;
bool x1221 = !x1220;
x1223 = x1221;
} else {
x1223 = false;
}
if (x1223) {
int32_t x1224 = 0;
x1224 = 23333;
int32_t x1226 = x349;
for (;;) {
int32_t x1227 = x1226;
bool x1228 = x1227 != -1;
if (!x1228) break;
int32_t x1230 = x1226;
bool x1231 = true;
int32_t x1232 = x3[x1230];
bool x1233 = 0 == x1232;
if (x1233) {
} else {
x1231 = false;
}
bool x1237 = x1231;
if (x1237) {
printf("loop");
printf(" INDEX SCAN FIND TUPLE");
printf("%d ",x1232);
int32_t x1241 = x6[x1230];
printf("%d ",x1241);
int32_t x1243 = x9[x1230];
printf("%d ",x1243);
int32_t x1245 = x12[x1230];
printf("%d ",x1245);
printf("\n");
int32_t x1248 = 0;
x1248 = 23334;
int32_t x1250 = x710;
for (;;) {
int32_t x1251 = x1250;
bool x1252 = x1251 != -1;
if (!x1252) break;
int32_t x1254 = x1250;
bool x1255 = true;
int32_t x1256 = x77[x1254];
bool x1257 = 1 == x1256;
if (x1257) {
} else {
x1255 = false;
}
bool x1261 = x1255;
if (x1261) {
printf("@delta_loop");
printf(" INDEX SCAN FIND TUPLE");
printf("%d ",x1256);
int32_t x1265 = x80[x1254];
printf("%d ",x1265);
int32_t x1267 = x83[x1254];
printf("%d ",x1267);
int32_t x1269 = x86[x1254];
printf("%d ",x1269);
printf("\n");
int32_t x1272 = x66;
int32_t x1283 = -1501140568 + x1265;
int32_t x1284 = x1283 + 23333;
int32_t x1286 = x1284 * 19260817;
for(int x1274=0; x1274 < x1272; x1274++) {
printf("low");
printf(" SCAN FIND TUPLE");
int32_t x1277 = x64[x1274];
printf("%d ",x1277);
printf("\n");
bool x1280 = false;
int32_t x1281 = 0;
x1281 = 23336;
x1281 = x1284;
int32_t x1287 = x1286 + x1277;
int32_t x1288 = x1287 + 23333;
x1281 = x1288;
int32_t x1290 = x1288 * 19260817;
int32_t x1291 = x1290 + x1245;
int32_t x1292 = x1291 + 23333;
x1281 = x1292;
int32_t x1294 = x1292 & 4194303;
int32_t x1295 = x21[x1294];
int32_t x1296 = x1295;
bool x1297 = true;
for (;;) {
bool x1298 = x1297;
bool x1302;
if (x1298) {
int32_t x1299 = x1296;
bool x1300 = x1299 != -1;
x1302 = x1300;
} else {
x1302 = false;
}
if (!x1302) break;
int32_t x1304 = x1296;
bool x1305 = true;
int32_t x1306 = x3[x1304];
bool x1307 = 3 == x1306;
if (x1307) {
} else {
x1305 = false;
}
int32_t x1311 = x6[x1304];
bool x1312 = x1265 == x1311;
if (x1312) {
} else {
x1305 = false;
}
int32_t x1316 = x9[x1304];
bool x1317 = x1277 == x1316;
if (x1317) {
} else {
x1305 = false;
}
int32_t x1321 = x12[x1304];
bool x1322 = x1245 == x1321;
if (x1322) {
} else {
x1305 = false;
}
bool x1326 = x1305;
if (x1326) {
x1280 = true;
x1297 = false;
} else {
}
int32_t x1331 = x16[x1304];
x1296 = x1331;
}
bool x1335 = x1280;
if (x1335) {
} else {
bool x1337 = true;
int32_t x1338 = 0;
x1338 = 23336;
x1338 = x1284;
x1338 = x1288;
x1338 = x1292;
int32_t x1343 = x52[x1294];
int32_t x1344 = x1343;
bool x1345 = true;
for (;;) {
bool x1346 = x1345;
bool x1350;
if (x1346) {
int32_t x1347 = x1344;
bool x1348 = x1347 != -1;
x1350 = x1348;
} else {
x1350 = false;
}
if (!x1350) break;
int32_t x1352 = x1344;
bool x1353 = true;
int32_t x1354 = x34[x1352];
bool x1355 = 3 == x1354;
if (x1355) {
} else {
x1353 = false;
}
int32_t x1359 = x37[x1352];
bool x1360 = x1265 == x1359;
if (x1360) {
} else {
x1353 = false;
}
int32_t x1364 = x40[x1352];
bool x1365 = x1277 == x1364;
if (x1365) {
} else {
x1353 = false;
}
int32_t x1369 = x43[x1352];
bool x1370 = x1245 == x1369;
if (x1370) {
} else {
x1353 = false;
}
bool x1374 = x1353;
if (x1374) {
bool x1375 = true;
if (x1355) {
} else {
x1375 = false;
}
if (x1360) {
} else {
x1375 = false;
}
if (x1365) {
} else {
x1375 = false;
}
if (x1370) {
} else {
x1375 = false;
}
bool x1388 = x1375;
if (x1388) {
x1337 = false;
} else {
}
bool x1392 = x1337;
x1345 = x1392;
} else {
}
int32_t x1396 = x47[x1352];
x1344 = x1396;
}
bool x1400 = x1337;
if (x1400) {
printf("INSERT INTO HASHTABLE");
printf("%d ",3);
printf("%d ",x1265);
printf("%d ",x1277);
printf("%d ",x1245);
printf("\n");
int32_t x1409 = x45;
int32_t x1410 = x32;
bool x1411 = x1409 == x1410;
if (x1411) {
x32 *= 4;
int32_t x1413 = x32;
printf("buffer.resize %d\n",x1413);
} else {
}
x34[x1409] = 3;
x37[x1409] = x1265;
x40[x1409] = x1277;
x43[x1409] = x1245;
x45 += 1;
int32_t x1422 = 0;
x1422 = 23336;
x1422 = x1284;
x1422 = x1288;
x1422 = x1292;
int32_t x1427 = x1343;
x52[x1294] = x1409;
x47[x1409] = x1343;
int32_t x1430 = 0;
x1430 = 23336;
int32_t x1432 = x1189;
x53[x1188] = x1409;
x50[x1409] = x1189;
} else {
}
}

}
} else {
}
int32_t x1443 = x93[x1254];
x1250 = x1443;
}
} else {
}
int32_t x1449 = x19[x1230];
x1226 = x1449;
}
} else {
}
if (x492) {
} else {
int32_t x1455 = 0;
x1455 = 23336;
int32_t x1458 = x1457;
for (;;) {
int32_t x1459 = x1458;
bool x1460 = x1459 != -1;
if (!x1460) break;
int32_t x1462 = x1458;
bool x1463 = true;
int32_t x1464 = x77[x1462];
bool x1465 = 3 == x1464;
if (x1465) {
} else {
x1463 = false;
}
bool x1469 = x1463;
if (x1469) {
printf("@delta_loop");
printf(" INDEX SCAN FIND TUPLE");
printf("%d ",x1464);
int32_t x1473 = x80[x1462];
printf("%d ",x1473);
int32_t x1475 = x83[x1462];
printf("%d ",x1475);
int32_t x1477 = x86[x1462];
printf("%d ",x1477);
printf("\n");
bool x1480 = x1473 <= x1475;
bool x1539;
if (x1480) {
bool x1481 = false;
int32_t x1482 = 0;
x1482 = 23340;
int32_t x1484 = -1424097300 + x1473;
int32_t x1485 = x1484 + 23333;
x1482 = x1485;
int32_t x1487 = x1485 * 19260817;
int32_t x1488 = x1487 + x1475;
int32_t x1489 = x1488 + 23333;
x1482 = x1489;
int32_t x1491 = x1489 * 19260817;
int32_t x1492 = x1491 + x1477;
int32_t x1493 = x1492 + 23333;
x1482 = x1493;
int32_t x1495 = x1493 & 4194303;
int32_t x1496 = x21[x1495];
int32_t x1497 = x1496;
bool x1498 = true;
for (;;) {
bool x1499 = x1498;
bool x1503;
if (x1499) {
int32_t x1500 = x1497;
bool x1501 = x1500 != -1;
x1503 = x1501;
} else {
x1503 = false;
}
if (!x1503) break;
int32_t x1505 = x1497;
bool x1506 = true;
int32_t x1507 = x3[x1505];
bool x1508 = 7 == x1507;
if (x1508) {
} else {
x1506 = false;
}
int32_t x1512 = x6[x1505];
bool x1513 = x1473 == x1512;
if (x1513) {
} else {
x1506 = false;
}
int32_t x1517 = x9[x1505];
bool x1518 = x1475 == x1517;
if (x1518) {
} else {
x1506 = false;
}
int32_t x1522 = x12[x1505];
bool x1523 = x1477 == x1522;
if (x1523) {
} else {
x1506 = false;
}
bool x1527 = x1506;
if (x1527) {
x1481 = true;
x1498 = false;
} else {
}
int32_t x1532 = x16[x1505];
x1497 = x1532;
}
bool x1536 = x1481;
bool x1537 = !x1536;
x1539 = x1537;
} else {
x1539 = false;
}
if (x1539) {
bool x1540 = true;
int32_t x1541 = 0;
x1541 = 23340;
int32_t x1484 = -1424097300 + x1473;
int32_t x1485 = x1484 + 23333;
x1541 = x1485;
int32_t x1487 = x1485 * 19260817;
int32_t x1488 = x1487 + x1475;
int32_t x1489 = x1488 + 23333;
x1541 = x1489;
int32_t x1491 = x1489 * 19260817;
int32_t x1492 = x1491 + x1477;
int32_t x1493 = x1492 + 23333;
x1541 = x1493;
int32_t x1495 = x1493 & 4194303;
int32_t x1546 = x52[x1495];
int32_t x1547 = x1546;
bool x1548 = true;
for (;;) {
bool x1549 = x1548;
bool x1553;
if (x1549) {
int32_t x1550 = x1547;
bool x1551 = x1550 != -1;
x1553 = x1551;
} else {
x1553 = false;
}
if (!x1553) break;
int32_t x1555 = x1547;
bool x1556 = true;
int32_t x1557 = x34[x1555];
bool x1558 = 7 == x1557;
if (x1558) {
} else {
x1556 = false;
}
int32_t x1562 = x37[x1555];
bool x1563 = x1473 == x1562;
if (x1563) {
} else {
x1556 = false;
}
int32_t x1567 = x40[x1555];
bool x1568 = x1475 == x1567;
if (x1568) {
} else {
x1556 = false;
}
int32_t x1572 = x43[x1555];
bool x1573 = x1477 == x1572;
if (x1573) {
} else {
x1556 = false;
}
bool x1577 = x1556;
if (x1577) {
bool x1578 = true;
if (x1558) {
} else {
x1578 = false;
}
if (x1563) {
} else {
x1578 = false;
}
if (x1568) {
} else {
x1578 = false;
}
if (x1573) {
} else {
x1578 = false;
}
bool x1591 = x1578;
if (x1591) {
x1540 = false;
} else {
}
bool x1595 = x1540;
x1548 = x1595;
} else {
}
int32_t x1599 = x47[x1555];
x1547 = x1599;
}
bool x1603 = x1540;
if (x1603) {
printf("INSERT INTO HASHTABLE");
printf("%d ",7);
printf("%d ",x1473);
printf("%d ",x1475);
printf("%d ",x1477);
printf("\n");
int32_t x1612 = x45;
int32_t x1613 = x32;
bool x1614 = x1612 == x1613;
if (x1614) {
x32 *= 4;
int32_t x1616 = x32;
printf("buffer.resize %d\n",x1616);
} else {
}
x34[x1612] = 7;
x37[x1612] = x1473;
x40[x1612] = x1475;
x43[x1612] = x1477;
x45 += 1;
int32_t x1625 = 0;
x1625 = 23340;
x1625 = x1485;
x1625 = x1489;
x1625 = x1493;
int32_t x1630 = x1546;
x52[x1495] = x1612;
x47[x1612] = x1546;
int32_t x1633 = 0;
x1633 = 23340;
int32_t x1637 = x1636;
x53[x1635] = x1612;
x50[x1612] = x1636;
} else {
}
} else {
}
} else {
}
int32_t x1646 = x93[x1462];
x1458 = x1646;
}
}
if (x492) {
} else {
int32_t x1652 = 0;
x1652 = 23336;
int32_t x1654 = x1457;
for (;;) {
int32_t x1655 = x1654;
bool x1656 = x1655 != -1;
if (!x1656) break;
int32_t x1658 = x1654;
bool x1659 = true;
int32_t x1660 = x77[x1658];
bool x1661 = 3 == x1660;
if (x1661) {
} else {
x1659 = false;
}
bool x1665 = x1659;
if (x1665) {
printf("@delta_loop");
printf(" INDEX SCAN FIND TUPLE");
printf("%d ",x1660);
int32_t x1669 = x80[x1658];
printf("%d ",x1669);
int32_t x1671 = x83[x1658];
printf("%d ",x1671);
int32_t x1673 = x86[x1658];
printf("%d ",x1673);
printf("\n");
bool x1676 = x1669 > x1671;
bool x1734;
if (x1676) {
bool x1677 = false;
int32_t x1678 = 0;
x1678 = 23337;
int32_t x1680 = -1481879751 + x1669;
int32_t x1681 = x1680 + 23333;
x1678 = x1681;
int32_t x1683 = x1681 * 19260817;
int32_t x1684 = x1683 + 23333;
x1678 = x1684;
int32_t x1686 = x1684 * 19260817;
int32_t x1687 = x1686 + x1673;
int32_t x1688 = x1687 + 23333;
x1678 = x1688;
int32_t x1690 = x1688 & 4194303;
int32_t x1691 = x21[x1690];
int32_t x1692 = x1691;
bool x1693 = true;
for (;;) {
bool x1694 = x1693;
bool x1698;
if (x1694) {
int32_t x1695 = x1692;
bool x1696 = x1695 != -1;
x1698 = x1696;
} else {
x1698 = false;
}
if (!x1698) break;
int32_t x1700 = x1692;
bool x1701 = true;
int32_t x1702 = x3[x1700];
bool x1703 = 4 == x1702;
if (x1703) {
} else {
x1701 = false;
}
int32_t x1707 = x6[x1700];
bool x1708 = x1669 == x1707;
if (x1708) {
} else {
x1701 = false;
}
int32_t x1712 = x9[x1700];
bool x1713 = 0 == x1712;
if (x1713) {
} else {
x1701 = false;
}
int32_t x1717 = x12[x1700];
bool x1718 = x1673 == x1717;
if (x1718) {
} else {
x1701 = false;
}
bool x1722 = x1701;
if (x1722) {
x1677 = true;
x1693 = false;
} else {
}
int32_t x1727 = x16[x1700];
x1692 = x1727;
}
bool x1731 = x1677;
bool x1732 = !x1731;
x1734 = x1732;
} else {
x1734 = false;
}
if (x1734) {
bool x1735 = true;
int32_t x1736 = 0;
x1736 = 23337;
int32_t x1680 = -1481879751 + x1669;
int32_t x1681 = x1680 + 23333;
x1736 = x1681;
int32_t x1683 = x1681 * 19260817;
int32_t x1684 = x1683 + 23333;
x1736 = x1684;
int32_t x1686 = x1684 * 19260817;
int32_t x1687 = x1686 + x1673;
int32_t x1688 = x1687 + 23333;
x1736 = x1688;
int32_t x1690 = x1688 & 4194303;
int32_t x1741 = x52[x1690];
int32_t x1742 = x1741;
bool x1743 = true;
for (;;) {
bool x1744 = x1743;
bool x1748;
if (x1744) {
int32_t x1745 = x1742;
bool x1746 = x1745 != -1;
x1748 = x1746;
} else {
x1748 = false;
}
if (!x1748) break;
int32_t x1750 = x1742;
bool x1751 = true;
int32_t x1752 = x34[x1750];
bool x1753 = 4 == x1752;
if (x1753) {
} else {
x1751 = false;
}
int32_t x1757 = x37[x1750];
bool x1758 = x1669 == x1757;
if (x1758) {
} else {
x1751 = false;
}
int32_t x1762 = x40[x1750];
bool x1763 = 0 == x1762;
if (x1763) {
} else {
x1751 = false;
}
int32_t x1767 = x43[x1750];
bool x1768 = x1673 == x1767;
if (x1768) {
} else {
x1751 = false;
}
bool x1772 = x1751;
if (x1772) {
bool x1773 = true;
if (x1753) {
} else {
x1773 = false;
}
if (x1758) {
} else {
x1773 = false;
}
if (x1763) {
} else {
x1773 = false;
}
if (x1768) {
} else {
x1773 = false;
}
bool x1786 = x1773;
if (x1786) {
x1735 = false;
} else {
}
bool x1790 = x1735;
x1743 = x1790;
} else {
}
int32_t x1794 = x47[x1750];
x1742 = x1794;
}
bool x1798 = x1735;
if (x1798) {
printf("INSERT INTO HASHTABLE");
printf("%d ",4);
printf("%d ",x1669);
printf("%d ",0);
printf("%d ",x1673);
printf("\n");
int32_t x1807 = x45;
int32_t x1808 = x32;
bool x1809 = x1807 == x1808;
if (x1809) {
x32 *= 4;
int32_t x1811 = x32;
printf("buffer.resize %d\n",x1811);
} else {
}
x34[x1807] = 4;
x37[x1807] = x1669;
x40[x1807] = 0;
x43[x1807] = x1673;
x45 += 1;
int32_t x1820 = 0;
x1820 = 23337;
x1820 = x1681;
x1820 = x1684;
x1820 = x1688;
int32_t x1825 = x1741;
x52[x1690] = x1807;
x47[x1807] = x1741;
int32_t x1828 = 0;
x1828 = 23337;
int32_t x1832 = x1831;
x53[x1830] = x1807;
x50[x1807] = x1831;
} else {
}
} else {
}
} else {
}
int32_t x1841 = x93[x1658];
x1654 = x1841;
}
}
if (x492) {
} else {
int32_t x1847 = 0;
x1847 = 23337;
int32_t x1850 = x1849;
for (;;) {
int32_t x1851 = x1850;
bool x1852 = x1851 != -1;
if (!x1852) break;
int32_t x1854 = x1850;
bool x1855 = true;
int32_t x1856 = x77[x1854];
bool x1857 = 4 == x1856;
if (x1857) {
} else {
x1855 = false;
}
bool x1861 = x1855;
if (x1861) {
printf("@delta_loop");
printf(" INDEX SCAN FIND TUPLE");
printf("%d ",x1856);
int32_t x1865 = x80[x1854];
printf("%d ",x1865);
int32_t x1867 = x83[x1854];
printf("%d ",x1867);
int32_t x1869 = x86[x1854];
printf("%d ",x1869);
printf("\n");
bool x1872 = x1869 > x1867;
bool x1932;
if (x1872) {
bool x1874 = false;
int32_t x1875 = 0;
x1875 = 23337;
int32_t x1877 = -1481879751 + x1865;
int32_t x1878 = x1877 + 23333;
x1875 = x1878;
int32_t x1873 = x1867 + 1;
int32_t x1880 = x1878 * 19260817;
int32_t x1881 = x1880 + x1873;
int32_t x1882 = x1881 + 23333;
x1875 = x1882;
int32_t x1884 = x1882 * 19260817;
int32_t x1885 = x1884 + x1869;
int32_t x1886 = x1885 + 23333;
x1875 = x1886;
int32_t x1888 = x1886 & 4194303;
int32_t x1889 = x21[x1888];
int32_t x1890 = x1889;
bool x1891 = true;
for (;;) {
bool x1892 = x1891;
bool x1896;
if (x1892) {
int32_t x1893 = x1890;
bool x1894 = x1893 != -1;
x1896 = x1894;
} else {
x1896 = false;
}
if (!x1896) break;
int32_t x1898 = x1890;
bool x1899 = true;
int32_t x1900 = x3[x1898];
bool x1901 = 4 == x1900;
if (x1901) {
} else {
x1899 = false;
}
int32_t x1905 = x6[x1898];
bool x1906 = x1865 == x1905;
if (x1906) {
} else {
x1899 = false;
}
int32_t x1910 = x9[x1898];
bool x1911 = x1873 == x1910;
if (x1911) {
} else {
x1899 = false;
}
int32_t x1915 = x12[x1898];
bool x1916 = x1869 == x1915;
if (x1916) {
} else {
x1899 = false;
}
bool x1920 = x1899;
if (x1920) {
x1874 = true;
x1891 = false;
} else {
}
int32_t x1925 = x16[x1898];
x1890 = x1925;
}
bool x1929 = x1874;
bool x1930 = !x1929;
x1932 = x1930;
} else {
x1932 = false;
}
if (x1932) {
bool x1933 = true;
int32_t x1934 = 0;
x1934 = 23337;
int32_t x1877 = -1481879751 + x1865;
int32_t x1878 = x1877 + 23333;
x1934 = x1878;
int32_t x1873 = x1867 + 1;
int32_t x1880 = x1878 * 19260817;
int32_t x1881 = x1880 + x1873;
int32_t x1882 = x1881 + 23333;
x1934 = x1882;
int32_t x1884 = x1882 * 19260817;
int32_t x1885 = x1884 + x1869;
int32_t x1886 = x1885 + 23333;
x1934 = x1886;
int32_t x1888 = x1886 & 4194303;
int32_t x1939 = x52[x1888];
int32_t x1940 = x1939;
bool x1941 = true;
for (;;) {
bool x1942 = x1941;
bool x1946;
if (x1942) {
int32_t x1943 = x1940;
bool x1944 = x1943 != -1;
x1946 = x1944;
} else {
x1946 = false;
}
if (!x1946) break;
int32_t x1948 = x1940;
bool x1949 = true;
int32_t x1950 = x34[x1948];
bool x1951 = 4 == x1950;
if (x1951) {
} else {
x1949 = false;
}
int32_t x1955 = x37[x1948];
bool x1956 = x1865 == x1955;
if (x1956) {
} else {
x1949 = false;
}
int32_t x1960 = x40[x1948];
bool x1961 = x1873 == x1960;
if (x1961) {
} else {
x1949 = false;
}
int32_t x1965 = x43[x1948];
bool x1966 = x1869 == x1965;
if (x1966) {
} else {
x1949 = false;
}
bool x1970 = x1949;
if (x1970) {
bool x1971 = true;
if (x1951) {
} else {
x1971 = false;
}
if (x1956) {
} else {
x1971 = false;
}
if (x1961) {
} else {
x1971 = false;
}
if (x1966) {
} else {
x1971 = false;
}
bool x1984 = x1971;
if (x1984) {
x1933 = false;
} else {
}
bool x1988 = x1933;
x1941 = x1988;
} else {
}
int32_t x1992 = x47[x1948];
x1940 = x1992;
}
bool x1996 = x1933;
if (x1996) {
printf("INSERT INTO HASHTABLE");
printf("%d ",4);
printf("%d ",x1865);
printf("%d ",x1873);
printf("%d ",x1869);
printf("\n");
int32_t x2005 = x45;
int32_t x2006 = x32;
bool x2007 = x2005 == x2006;
if (x2007) {
x32 *= 4;
int32_t x2009 = x32;
printf("buffer.resize %d\n",x2009);
} else {
}
x34[x2005] = 4;
x37[x2005] = x1865;
x40[x2005] = x1873;
x43[x2005] = x1869;
x45 += 1;
int32_t x2018 = 0;
x2018 = 23337;
x2018 = x1878;
x2018 = x1882;
x2018 = x1886;
int32_t x2023 = x1939;
x52[x1888] = x2005;
x47[x2005] = x1939;
int32_t x2026 = 0;
x2026 = 23337;
int32_t x2028 = x1831;
x53[x1830] = x2005;
x50[x2005] = x1831;
} else {
}
} else {
}
} else {
}
int32_t x2037 = x93[x1854];
x1850 = x2037;
}
}
if (x492) {
} else {
int32_t x2043 = 0;
x2043 = 23337;
int32_t x2045 = x1849;
for (;;) {
int32_t x2046 = x2045;
bool x2047 = x2046 != -1;
if (!x2047) break;
int32_t x2049 = x2045;
bool x2050 = true;
int32_t x2051 = x77[x2049];
bool x2052 = 4 == x2051;
if (x2052) {
} else {
x2050 = false;
}
bool x2056 = x2050;
if (x2056) {
printf("@delta_loop");
printf(" INDEX SCAN FIND TUPLE");
printf("%d ",x2051);
int32_t x2060 = x80[x2049];
printf("%d ",x2060);
int32_t x2062 = x83[x2049];
printf("%d ",x2062);
int32_t x2064 = x86[x2049];
printf("%d ",x2064);
printf("\n");
bool x2067 = x2064 <= x2062;
bool x2127;
if (x2067) {
bool x2069 = false;
int32_t x2070 = 0;
x2070 = 23336;
int32_t x2072 = -1501140568 + x2060;
int32_t x2073 = x2072 + 23333;
x2070 = x2073;
int32_t x2075 = x2073 * 19260817;
int32_t x2076 = x2075 + x2062;
int32_t x2077 = x2076 + 23333;
x2070 = x2077;
int32_t x2068 = x2064 + 1;
int32_t x2079 = x2077 * 19260817;
int32_t x2080 = x2079 + x2068;
int32_t x2081 = x2080 + 23333;
x2070 = x2081;
int32_t x2083 = x2081 & 4194303;
int32_t x2084 = x21[x2083];
int32_t x2085 = x2084;
bool x2086 = true;
for (;;) {
bool x2087 = x2086;
bool x2091;
if (x2087) {
int32_t x2088 = x2085;
bool x2089 = x2088 != -1;
x2091 = x2089;
} else {
x2091 = false;
}
if (!x2091) break;
int32_t x2093 = x2085;
bool x2094 = true;
int32_t x2095 = x3[x2093];
bool x2096 = 3 == x2095;
if (x2096) {
} else {
x2094 = false;
}
int32_t x2100 = x6[x2093];
bool x2101 = x2060 == x2100;
if (x2101) {
} else {
x2094 = false;
}
int32_t x2105 = x9[x2093];
bool x2106 = x2062 == x2105;
if (x2106) {
} else {
x2094 = false;
}
int32_t x2110 = x12[x2093];
bool x2111 = x2068 == x2110;
if (x2111) {
} else {
x2094 = false;
}
bool x2115 = x2094;
if (x2115) {
x2069 = true;
x2086 = false;
} else {
}
int32_t x2120 = x16[x2093];
x2085 = x2120;
}
bool x2124 = x2069;
bool x2125 = !x2124;
x2127 = x2125;
} else {
x2127 = false;
}
if (x2127) {
bool x2128 = true;
int32_t x2129 = 0;
x2129 = 23336;
int32_t x2072 = -1501140568 + x2060;
int32_t x2073 = x2072 + 23333;
x2129 = x2073;
int32_t x2075 = x2073 * 19260817;
int32_t x2076 = x2075 + x2062;
int32_t x2077 = x2076 + 23333;
x2129 = x2077;
int32_t x2068 = x2064 + 1;
int32_t x2079 = x2077 * 19260817;
int32_t x2080 = x2079 + x2068;
int32_t x2081 = x2080 + 23333;
x2129 = x2081;
int32_t x2083 = x2081 & 4194303;
int32_t x2134 = x52[x2083];
int32_t x2135 = x2134;
bool x2136 = true;
for (;;) {
bool x2137 = x2136;
bool x2141;
if (x2137) {
int32_t x2138 = x2135;
bool x2139 = x2138 != -1;
x2141 = x2139;
} else {
x2141 = false;
}
if (!x2141) break;
int32_t x2143 = x2135;
bool x2144 = true;
int32_t x2145 = x34[x2143];
bool x2146 = 3 == x2145;
if (x2146) {
} else {
x2144 = false;
}
int32_t x2150 = x37[x2143];
bool x2151 = x2060 == x2150;
if (x2151) {
} else {
x2144 = false;
}
int32_t x2155 = x40[x2143];
bool x2156 = x2062 == x2155;
if (x2156) {
} else {
x2144 = false;
}
int32_t x2160 = x43[x2143];
bool x2161 = x2068 == x2160;
if (x2161) {
} else {
x2144 = false;
}
bool x2165 = x2144;
if (x2165) {
bool x2166 = true;
if (x2146) {
} else {
x2166 = false;
}
if (x2151) {
} else {
x2166 = false;
}
if (x2156) {
} else {
x2166 = false;
}
if (x2161) {
} else {
x2166 = false;
}
bool x2179 = x2166;
if (x2179) {
x2128 = false;
} else {
}
bool x2183 = x2128;
x2136 = x2183;
} else {
}
int32_t x2187 = x47[x2143];
x2135 = x2187;
}
bool x2191 = x2128;
if (x2191) {
printf("INSERT INTO HASHTABLE");
printf("%d ",3);
printf("%d ",x2060);
printf("%d ",x2062);
printf("%d ",x2068);
printf("\n");
int32_t x2200 = x45;
int32_t x2201 = x32;
bool x2202 = x2200 == x2201;
if (x2202) {
x32 *= 4;
int32_t x2204 = x32;
printf("buffer.resize %d\n",x2204);
} else {
}
x34[x2200] = 3;
x37[x2200] = x2060;
x40[x2200] = x2062;
x43[x2200] = x2068;
x45 += 1;
int32_t x2213 = 0;
x2213 = 23336;
x2213 = x2073;
x2213 = x2077;
x2213 = x2081;
int32_t x2218 = x2134;
x52[x2083] = x2200;
x47[x2200] = x2134;
int32_t x2221 = 0;
x2221 = 23336;
int32_t x2223 = x1189;
x53[x1188] = x2200;
x50[x2200] = x1189;
} else {
}
} else {
}
} else {
}
int32_t x2232 = x93[x2049];
x2045 = x2232;
}
}
int32_t x2238 = x45;
bool x2239 = x2238 == 0;
if (x2239) {
x484 = false;
} else {
for(int x2243=0; x2243 < x2238; x2243++) {
printf("@new_loop");
printf(" SCAN FIND TUPLE");
int32_t x2246 = x34[x2243];
printf("%d ",x2246);
int32_t x2248 = x37[x2243];
printf("%d ",x2248);
int32_t x2250 = x40[x2243];
printf("%d ",x2250);
int32_t x2252 = x43[x2243];
printf("%d ",x2252);
printf("\n");
bool x2255 = true;
int32_t x2256 = 0;
int32_t x2257 = x2246 + 23333;
x2256 = x2257;
int32_t x2259 = x2257 * 19260817;
int32_t x2260 = x2259 + x2248;
int32_t x2261 = x2260 + 23333;
x2256 = x2261;
int32_t x2263 = x2261 * 19260817;
int32_t x2264 = x2263 + x2250;
int32_t x2265 = x2264 + 23333;
x2256 = x2265;
int32_t x2267 = x2265 * 19260817;
int32_t x2268 = x2267 + x2252;
int32_t x2269 = x2268 + 23333;
x2256 = x2269;
int32_t x2271 = x2269 & 4194303;
int32_t x2272 = x21[x2271];
int32_t x2273 = x2272;
bool x2274 = true;
for (;;) {
bool x2275 = x2274;
bool x2279;
if (x2275) {
int32_t x2276 = x2273;
bool x2277 = x2276 != -1;
x2279 = x2277;
} else {
x2279 = false;
}
if (!x2279) break;
int32_t x2281 = x2273;
bool x2282 = true;
int32_t x2283 = x3[x2281];
bool x2284 = x2246 == x2283;
if (x2284) {
} else {
x2282 = false;
}
int32_t x2288 = x6[x2281];
bool x2289 = x2248 == x2288;
if (x2289) {
} else {
x2282 = false;
}
int32_t x2293 = x9[x2281];
bool x2294 = x2250 == x2293;
if (x2294) {
} else {
x2282 = false;
}
int32_t x2298 = x12[x2281];
bool x2299 = x2252 == x2298;
if (x2299) {
} else {
x2282 = false;
}
bool x2303 = x2282;
if (x2303) {
bool x2304 = true;
if (x2284) {
} else {
x2304 = false;
}
if (x2289) {
} else {
x2304 = false;
}
if (x2294) {
} else {
x2304 = false;
}
if (x2299) {
} else {
x2304 = false;
}
bool x2317 = x2304;
if (x2317) {
x2255 = false;
} else {
}
bool x2321 = x2255;
x2274 = x2321;
} else {
}
int32_t x2325 = x16[x2281];
x2273 = x2325;
}
bool x2329 = x2255;
if (x2329) {
printf("INSERT INTO HASHTABLE");
printf("%d ",x2246);
printf("%d ",x2248);
printf("%d ",x2250);
printf("%d ",x2252);
printf("\n");
int32_t x2338 = x14;
int32_t x2339 = x1;
bool x2340 = x2338 == x2339;
if (x2340) {
x1 *= 4;
int32_t x2342 = x1;
printf("buffer.resize %d\n",x2342);
} else {
}
x3[x2338] = x2246;
x6[x2338] = x2248;
x9[x2338] = x2250;
x12[x2338] = x2252;
x14 += 1;
int32_t x2351 = 0;
x2351 = x2257;
x2351 = x2261;
x2351 = x2265;
x2351 = x2269;
int32_t x2356 = x2272;
x21[x2271] = x2338;
x16[x2338] = x2272;
int32_t x2359 = 0;
x2359 = x2257;
int32_t x2361 = x2257 & 4194303;
int32_t x2362 = x22[x2361];
int32_t x2363 = x2362;
x22[x2361] = x2338;
x19[x2338] = x2362;
} else {
}

}
SWAP(x88,x45);
SWAP(x75,x32);
SWAP(x78,x35);
SWAP(x76,x33);
SWAP(x77,x34);
SWAP(x81,x38);
SWAP(x79,x36);
SWAP(x80,x37);
SWAP(x84,x41);
SWAP(x82,x39);
SWAP(x83,x40);
SWAP(x87,x44);
SWAP(x85,x42);
SWAP(x86,x43);
SWAP(x91,x48);
SWAP(x89,x46);
SWAP(x90,x47);
SWAP(x94,x51);
SWAP(x92,x49);
SWAP(x93,x50);
SWAP(x95,x52);
SWAP(x96,x53);
x45 = 0;
x48 = 0;
x51 = 0;
for(int x2395=0; x2395 < 4194304; x2395++) {
x52[x2395] = -1;

}
for(int x2399=0; x2399 < 4194304; x2399++) {
x53[x2399] = -1;

}
}
}
for(int x2407=0; x2407 < 4194304; x2407++) {
x95[x2407] = -1;

}
for(int x2411=0; x2411 < 4194304; x2411++) {
x96[x2411] = -1;

}
for(int x2415=0; x2415 < 4194304; x2415++) {
x52[x2415] = -1;

}
for(int x2419=0; x2419 < 4194304; x2419++) {
x53[x2419] = -1;

}
int32_t x2424 = x14;
FILE *x2423 = fopen("loop.out","w");
for(int x2426=0; x2426 < x2424; x2426++) {
int32_t x2427 = x3[x2426];
int32_t x2428 = fprintf(x2423,"%d",x2427);
int32_t x2429 = fprintf(x2423,"\t");
int32_t x2430 = x6[x2426];
int32_t x2431 = fprintf(x2423,"%d",x2430);
int32_t x2432 = fprintf(x2423,"\t");
int32_t x2433 = x9[x2426];
int32_t x2434 = fprintf(x2423,"%d",x2433);
int32_t x2435 = fprintf(x2423,"\t");
int32_t x2436 = x12[x2426];
int32_t x2437 = fprintf(x2423,"%d",x2436);
int32_t x2438 = fprintf(x2423,"\n");

}
fclose(x2423);
for(int x2442=0; x2442 < 4194304; x2442++) {
x70[x2442] = -1;

}
for(int x2446=0; x2446 < 4194304; x2446++) {
x126[x2446] = -1;

}
for(int x2450=0; x2450 < 4194304; x2450++) {
x113[x2450] = -1;

}
for(int x2454=0; x2454 < 4194304; x2454++) {
x21[x2454] = -1;

}
for(int x2458=0; x2458 < 4194304; x2458++) {
x22[x2458] = -1;

}
}
/*****************************************
  End of C Generated Code                  
*******************************************/

