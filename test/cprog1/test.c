
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
int32_t* x4 = x3;
int32_t x5 = 0;
int32_t x6 = 4194304;
int32_t* x7 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x8 = x7;
int32_t x9 = 0;
int32_t x10 = 4194304;
int32_t* x11 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x12 = x11;
int32_t x13 = 0;
int32_t x14 = 4194304;
int32_t* x15 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x16 = x15;
int32_t x17 = 0;
int32_t x18 = 0;
int32_t x19 = 4194304;
int32_t* x20 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x21 = x20;
int32_t x22 = 0;
int32_t x23 = 4194304;
int32_t* x24 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x25 = x24;
int32_t x26 = 0;
int32_t* x27 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x28 = x27;
int32_t* x29 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x30 = x29;
for(int x32=0; x32 < 4194304; x32++) {
int32_t* x33 = x28;
x33[x32] = -1;

}
for(int x37=0; x37 < 4194304; x37++) {
int32_t* x38 = x30;
x38[x37] = -1;

}
int32_t x42 = 4194304;
int32_t x43 = 4194304;
int32_t* x44 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x45 = x44;
int32_t x46 = 0;
int32_t x47 = 4194304;
int32_t* x48 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x49 = x48;
int32_t x50 = 0;
int32_t x51 = 4194304;
int32_t* x52 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x53 = x52;
int32_t x54 = 0;
int32_t x55 = 4194304;
int32_t* x56 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x57 = x56;
int32_t x58 = 0;
int32_t x59 = 0;
int32_t x60 = 4194304;
int32_t* x61 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x62 = x61;
int32_t x63 = 0;
int32_t x64 = 4194304;
int32_t* x65 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x66 = x65;
int32_t x67 = 0;
int32_t* x68 = (int32_t*)malloc(16384 * sizeof(int32_t));
int32_t* x69 = x68;
int32_t* x70 = (int32_t*)malloc(16384 * sizeof(int32_t));
int32_t* x71 = x70;
for(int x73=0; x73 < 16384; x73++) {
int32_t* x74 = x69;
x74[x73] = -1;

}
for(int x78=0; x78 < 16384; x78++) {
int32_t* x79 = x71;
x79[x78] = -1;

}
int32_t x83 = 4194304;
int32_t x84 = 4194304;
int32_t* x85 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x86 = x85;
int32_t x87 = 0;
int32_t x88 = 0;
int32_t x89 = 4194304;
int32_t* x90 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x91 = x90;
int32_t x92 = 0;
int32_t* x93 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x94 = x93;
for(int x95=0; x95 < 4194304; x95++) {
int32_t* x96 = x94;
x96[x95] = -1;

}
int32_t x100 = 4194304;
int32_t x101 = 4194304;
int32_t* x102 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x103 = x102;
int32_t x104 = 0;
int32_t x105 = 4194304;
int32_t* x106 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x107 = x106;
int32_t x108 = 0;
int32_t x109 = 4194304;
int32_t* x110 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x111 = x110;
int32_t x112 = 0;
int32_t x113 = 4194304;
int32_t* x114 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x115 = x114;
int32_t x116 = 0;
int32_t x117 = 0;
int32_t x118 = 4194304;
int32_t* x119 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x120 = x119;
int32_t x121 = 0;
int32_t x122 = 4194304;
int32_t* x123 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x124 = x123;
int32_t x125 = 0;
int32_t* x126 = (int32_t*)malloc(16384 * sizeof(int32_t));
int32_t* x127 = x126;
int32_t* x128 = (int32_t*)malloc(16384 * sizeof(int32_t));
int32_t* x129 = x128;
for(int x130=0; x130 < 16384; x130++) {
int32_t* x131 = x127;
x131[x130] = -1;

}
for(int x135=0; x135 < 16384; x135++) {
int32_t* x136 = x129;
x136[x135] = -1;

}
int32_t x140 = 4194304;
int32_t x141 = 4194304;
int32_t* x142 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x143 = x142;
int32_t x144 = 0;
int32_t x145 = 0;
int32_t x146 = 4194304;
int32_t* x147 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x148 = x147;
int32_t x149 = 0;
int32_t* x150 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x151 = x150;
for(int x152=0; x152 < 4194304; x152++) {
int32_t* x153 = x151;
x153[x152] = -1;

}
int32_t x157 = 4194304;
int32_t x158 = 4194304;
int32_t* x159 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x160 = x159;
int32_t x161 = 0;
int32_t x162 = 0;
int32_t x163 = 4194304;
int32_t* x164 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x165 = x164;
int32_t x166 = 0;
int32_t* x167 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x168 = x167;
for(int x169=0; x169 < 4194304; x169++) {
int32_t* x170 = x168;
x170[x169] = -1;

}
int32_t x177 = 0;
int32_t x174 = open("high.facts",0);
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
int32_t x194 = x145;
int32_t x195 = x140;
bool x196 = x194 == x195;
if (x196) {
x140 *= 4;
int32_t x198 = x140;
printf("buffer.resize %d\n",x198);
} else {
}
int32_t* x202 = x143;
x202[x194] = x193;
x145 += 1;
int32_t x205 = x194;
int32_t x206 = 0;
int32_t x207 = x193 + 233;
x206 = x207;
int32_t* x210 = x151;
int32_t x209 = x207 & 4194303;
int32_t x211 = x210[x209];
int32_t x212 = x211;
x210[x209] = x194;
int32_t* x214 = x148;
x214[x194] = x211;
}
int32_t x221 = 0;
int32_t x218 = open("low.facts",0);
int32_t x219 = fsize(x218);
char* x220 = mmap(0, x219, PROT_READ, MAP_FILE | MAP_SHARED, x218, 0);
for (;;) {
int32_t x222 = x221;
bool x223 = x222 < x219;
if (!x223) break;
int32_t x225 = x221;
for (;;) {
int32_t x226 = x221;
char x227 = x220[x226];
bool x228 = x227 != '\n';
if (!x228) break;
x221 += 1;
}
int32_t x233 = x221;
x221 += 1;
char* x236 = x220+x225;
int32_t x237 = atoi(x236);
int32_t x238 = x88;
int32_t x239 = x83;
bool x240 = x238 == x239;
if (x240) {
x83 *= 4;
int32_t x242 = x83;
printf("buffer.resize %d\n",x242);
} else {
}
int32_t* x246 = x86;
x246[x238] = x237;
x88 += 1;
int32_t x249 = x238;
int32_t x250 = 0;
int32_t x251 = x237 + 233;
x250 = x251;
int32_t* x254 = x94;
int32_t x253 = x251 & 4194303;
int32_t x255 = x254[x253];
int32_t x256 = x255;
x254[x253] = x238;
int32_t* x258 = x91;
x258[x238] = x255;
}
int32_t x265 = 0;
int32_t x262 = open("med.facts",0);
int32_t x263 = fsize(x262);
char* x264 = mmap(0, x263, PROT_READ, MAP_FILE | MAP_SHARED, x262, 0);
for (;;) {
int32_t x266 = x265;
bool x267 = x266 < x263;
if (!x267) break;
int32_t x269 = x265;
for (;;) {
int32_t x270 = x265;
char x271 = x264[x270];
bool x272 = x271 != '\n';
if (!x272) break;
x265 += 1;
}
int32_t x277 = x265;
x265 += 1;
char* x280 = x264+x269;
int32_t x281 = atoi(x280);
int32_t x282 = x162;
int32_t x283 = x157;
bool x284 = x282 == x283;
if (x284) {
x157 *= 4;
int32_t x286 = x157;
printf("buffer.resize %d\n",x286);
} else {
}
int32_t* x290 = x160;
x290[x282] = x281;
x162 += 1;
int32_t x293 = x282;
int32_t x294 = 0;
int32_t x295 = x281 + 233;
x294 = x295;
int32_t* x298 = x168;
int32_t x297 = x295 & 4194303;
int32_t x299 = x298[x297];
int32_t x300 = x299;
x298[x297] = x282;
int32_t* x302 = x165;
x302[x282] = x299;
}
int32_t x306 = x88;
bool x307 = x306 == 0;
bool x313;
if (x307) {
x313 = false;
} else {
int32_t x309 = x162;
bool x310 = x309 == 0;
bool x311 = !x310;
x313 = x311;
}
bool x318;
if (x313) {
int32_t x314 = x145;
bool x315 = x314 == 0;
bool x316 = !x315;
x318 = x316;
} else {
x318 = false;
}
int32_t x443 = 233 & 4194303;
if (x318) {
for(int x320=0; x320 < x306; x320++) {
int32_t x321 = x162;
for(int x323=0; x323 < x321; x323++) {
int32_t x324 = x145;
for(int x326=0; x326 < x324; x326++) {
int32_t* x327 = x86;
int32_t* x329 = x160;
int32_t* x331 = x143;
bool x333 = true;
int32_t x334 = 0;
x334 = 233;
int32_t x328 = x327[x320];
int32_t x336 = 235097 + x328;
int32_t x337 = x336 + 233;
x334 = x337;
int32_t x330 = x329[x323];
int32_t x339 = x337 * 1009;
int32_t x340 = x339 + x330;
int32_t x341 = x340 + 233;
x334 = x341;
int32_t x332 = x331[x326];
int32_t x343 = x341 * 1009;
int32_t x344 = x343 + x332;
int32_t x345 = x344 + 233;
x334 = x345;
int32_t* x348 = x28;
int32_t x347 = x345 & 4194303;
int32_t x349 = x348[x347];
int32_t x350 = x349;
bool x351 = true;
for (;;) {
bool x352 = x351;
bool x356;
if (x352) {
int32_t x353 = x350;
bool x354 = x353 != -1;
x356 = x354;
} else {
x356 = false;
}
if (!x356) break;
int32_t x358 = x350;
bool x359 = true;
int32_t* x360 = x4;
int32_t x361 = x360[x358];
bool x362 = 0 == x361;
if (x362) {
} else {
x359 = false;
}
int32_t* x366 = x8;
int32_t x367 = x366[x358];
bool x368 = x328 == x367;
if (x368) {
} else {
x359 = false;
}
int32_t* x372 = x12;
int32_t x373 = x372[x358];
bool x374 = x330 == x373;
if (x374) {
} else {
x359 = false;
}
int32_t* x378 = x16;
int32_t x379 = x378[x358];
bool x380 = x332 == x379;
if (x380) {
} else {
x359 = false;
}
bool x384 = x359;
if (x384) {
bool x385 = true;
if (x362) {
} else {
x385 = false;
}
if (x368) {
} else {
x385 = false;
}
if (x374) {
} else {
x385 = false;
}
if (x380) {
} else {
x385 = false;
}
bool x398 = x385;
if (x398) {
x333 = false;
} else {
}
bool x402 = x333;
x351 = x402;
} else {
}
int32_t* x406 = x21;
int32_t x407 = x406[x358];
x350 = x407;
}
bool x411 = x333;
if (x411) {
int32_t x414 = x18;
int32_t x415 = x1;
bool x416 = x414 == x415;
if (x416) {
x1 *= 4;
int32_t x418 = x1;
printf("buffer.resize %d\n",x418);
} else {
}
int32_t* x422 = x4;
x422[x414] = 0;
int32_t* x424 = x8;
x424[x414] = x328;
int32_t* x426 = x12;
x426[x414] = x330;
int32_t* x428 = x16;
x428[x414] = x332;
x18 += 1;
int32_t x431 = x414;
int32_t x432 = 0;
x432 = 233;
x432 = x337;
x432 = x341;
x432 = x345;
int32_t x437 = x349;
x348[x347] = x414;
int32_t* x439 = x21;
x439[x414] = x349;
int32_t x441 = 0;
x441 = 233;
int32_t* x444 = x30;
int32_t x445 = x444[x443];
int32_t x446 = x445;
x444[x443] = x414;
int32_t* x448 = x25;
x448[x414] = x445;
} else {
}

}

}

}
} else {
}
int32_t x460 = x18;
for(int x462=0; x462 < x460; x462++) {
int32_t* x463 = x4;
int32_t* x465 = x8;
int32_t* x467 = x12;
int32_t* x469 = x16;
bool x471 = true;
int32_t x472 = 0;
int32_t x464 = x463[x462];
int32_t x473 = x464 + 233;
x472 = x473;
int32_t x466 = x465[x462];
int32_t x475 = x473 * 1009;
int32_t x476 = x475 + x466;
int32_t x477 = x476 + 233;
x472 = x477;
int32_t x468 = x467[x462];
int32_t x479 = x477 * 1009;
int32_t x480 = x479 + x468;
int32_t x481 = x480 + 233;
x472 = x481;
int32_t x470 = x469[x462];
int32_t x483 = x481 * 1009;
int32_t x484 = x483 + x470;
int32_t x485 = x484 + 233;
x472 = x485;
int32_t* x488 = x127;
int32_t x487 = x485 & 16383;
int32_t x489 = x488[x487];
int32_t x490 = x489;
bool x491 = true;
for (;;) {
bool x492 = x491;
bool x496;
if (x492) {
int32_t x493 = x490;
bool x494 = x493 != -1;
x496 = x494;
} else {
x496 = false;
}
if (!x496) break;
int32_t x498 = x490;
bool x499 = true;
int32_t* x500 = x103;
int32_t x501 = x500[x498];
bool x502 = x464 == x501;
if (x502) {
} else {
x499 = false;
}
int32_t* x506 = x107;
int32_t x507 = x506[x498];
bool x508 = x466 == x507;
if (x508) {
} else {
x499 = false;
}
int32_t* x512 = x111;
int32_t x513 = x512[x498];
bool x514 = x468 == x513;
if (x514) {
} else {
x499 = false;
}
int32_t* x518 = x115;
int32_t x519 = x518[x498];
bool x520 = x470 == x519;
if (x520) {
} else {
x499 = false;
}
bool x524 = x499;
if (x524) {
bool x525 = true;
if (x502) {
} else {
x525 = false;
}
if (x508) {
} else {
x525 = false;
}
if (x514) {
} else {
x525 = false;
}
if (x520) {
} else {
x525 = false;
}
bool x538 = x525;
if (x538) {
x471 = false;
} else {
}
bool x542 = x471;
x491 = x542;
} else {
}
int32_t* x546 = x120;
int32_t x547 = x546[x498];
x490 = x547;
}
bool x551 = x471;
if (x551) {
int32_t x554 = x117;
int32_t x555 = x100;
bool x556 = x554 == x555;
if (x556) {
x100 *= 4;
int32_t x558 = x100;
printf("buffer.resize %d\n",x558);
} else {
}
int32_t* x562 = x103;
x562[x554] = x464;
int32_t* x564 = x107;
x564[x554] = x466;
int32_t* x566 = x111;
x566[x554] = x468;
int32_t* x568 = x115;
x568[x554] = x470;
x117 += 1;
int32_t x571 = x554;
int32_t x572 = 0;
x572 = x473;
x572 = x477;
x572 = x481;
x572 = x485;
int32_t x577 = x489;
x488[x487] = x554;
int32_t* x579 = x120;
x579[x554] = x489;
int32_t x581 = 0;
x581 = x473;
int32_t* x584 = x129;
int32_t x583 = x473 & 16383;
int32_t x585 = x584[x583];
int32_t x586 = x585;
x584[x583] = x554;
int32_t* x588 = x124;
x588[x554] = x585;
} else {
}

}
bool x594 = true;
int32_t x602 = 233 & 16383;
int32_t x789 = 234 & 16383;
int32_t x1128 = 234 & 4194303;
int32_t x1561 = 235 & 16383;
int32_t x1892 = 235 & 4194303;
int32_t x2331 = 236 & 16383;
for (;;) {
bool x595 = x594;
if (!x595) break;
int32_t x597 = x117;
bool x598 = x597 == 0;
if (x598) {
} else {
int32_t x600 = 0;
x600 = 233;
int32_t* x603 = x129;
int32_t x604 = x603[x602];
int32_t x605 = x604;
for (;;) {
int32_t x606 = x605;
bool x607 = x606 != -1;
if (!x607) break;
int32_t x609 = x605;
bool x610 = true;
int32_t* x611 = x103;
int32_t x612 = x611[x609];
bool x613 = 0 == x612;
if (x613) {
} else {
x610 = false;
}
bool x617 = x610;
if (x617) {
int32_t* x618 = x107;
int32_t* x620 = x111;
int32_t* x622 = x115;
bool x624 = false;
int32_t x625 = 0;
x625 = 234;
int32_t x619 = x618[x609];
int32_t x627 = 236106 + x619;
int32_t x628 = x627 + 233;
x625 = x628;
int32_t x621 = x620[x609];
int32_t x630 = x628 * 1009;
int32_t x631 = x630 + x621;
int32_t x632 = x631 + 233;
x625 = x632;
int32_t x623 = x622[x609];
int32_t x634 = x632 * 1009;
int32_t x635 = x634 + x623;
int32_t x636 = x635 + 233;
x625 = x636;
int32_t* x639 = x28;
int32_t x638 = x636 & 4194303;
int32_t x640 = x639[x638];
int32_t x641 = x640;
bool x642 = true;
for (;;) {
bool x643 = x642;
bool x647;
if (x643) {
int32_t x644 = x641;
bool x645 = x644 != -1;
x647 = x645;
} else {
x647 = false;
}
if (!x647) break;
int32_t x649 = x641;
bool x650 = true;
int32_t* x651 = x4;
int32_t x652 = x651[x649];
bool x653 = 1 == x652;
if (x653) {
} else {
x650 = false;
}
int32_t* x657 = x8;
int32_t x658 = x657[x649];
bool x659 = x619 == x658;
if (x659) {
} else {
x650 = false;
}
int32_t* x663 = x12;
int32_t x664 = x663[x649];
bool x665 = x621 == x664;
if (x665) {
} else {
x650 = false;
}
int32_t* x669 = x16;
int32_t x670 = x669[x649];
bool x671 = x623 == x670;
if (x671) {
} else {
x650 = false;
}
bool x675 = x650;
if (x675) {
x624 = true;
x642 = false;
} else {
}
int32_t* x680 = x21;
int32_t x681 = x680[x649];
x641 = x681;
}
bool x685 = x624;
if (x685) {
} else {
bool x687 = true;
int32_t x688 = 0;
x688 = 234;
x688 = x628;
x688 = x632;
x688 = x636;
int32_t* x694 = x69;
int32_t x693 = x636 & 16383;
int32_t x695 = x694[x693];
int32_t x696 = x695;
bool x697 = true;
for (;;) {
bool x698 = x697;
bool x702;
if (x698) {
int32_t x699 = x696;
bool x700 = x699 != -1;
x702 = x700;
} else {
x702 = false;
}
if (!x702) break;
int32_t x704 = x696;
bool x705 = true;
int32_t* x706 = x45;
int32_t x707 = x706[x704];
bool x708 = 1 == x707;
if (x708) {
} else {
x705 = false;
}
int32_t* x712 = x49;
int32_t x713 = x712[x704];
bool x714 = x619 == x713;
if (x714) {
} else {
x705 = false;
}
int32_t* x718 = x53;
int32_t x719 = x718[x704];
bool x720 = x621 == x719;
if (x720) {
} else {
x705 = false;
}
int32_t* x724 = x57;
int32_t x725 = x724[x704];
bool x726 = x623 == x725;
if (x726) {
} else {
x705 = false;
}
bool x730 = x705;
if (x730) {
bool x731 = true;
if (x708) {
} else {
x731 = false;
}
if (x714) {
} else {
x731 = false;
}
if (x720) {
} else {
x731 = false;
}
if (x726) {
} else {
x731 = false;
}
bool x744 = x731;
if (x744) {
x687 = false;
} else {
}
bool x748 = x687;
x697 = x748;
} else {
}
int32_t* x752 = x62;
int32_t x753 = x752[x704];
x696 = x753;
}
bool x757 = x687;
if (x757) {
int32_t x760 = x59;
int32_t x761 = x42;
bool x762 = x760 == x761;
if (x762) {
x42 *= 4;
int32_t x764 = x42;
printf("buffer.resize %d\n",x764);
} else {
}
int32_t* x768 = x45;
x768[x760] = 1;
int32_t* x770 = x49;
x770[x760] = x619;
int32_t* x772 = x53;
x772[x760] = x621;
int32_t* x774 = x57;
x774[x760] = x623;
x59 += 1;
int32_t x777 = x760;
int32_t x778 = 0;
x778 = 234;
x778 = x628;
x778 = x632;
x778 = x636;
int32_t x783 = x695;
x694[x693] = x760;
int32_t* x785 = x62;
x785[x760] = x695;
int32_t x787 = 0;
x787 = 234;
int32_t* x790 = x71;
int32_t x791 = x790[x789];
int32_t x792 = x791;
x790[x789] = x760;
int32_t* x794 = x66;
x794[x760] = x791;
} else {
}
}
} else {
}
int32_t* x802 = x124;
int32_t x803 = x802[x609];
x605 = x803;
}
}
bool x813;
if (x598) {
x813 = false;
} else {
int32_t x809 = x18;
bool x810 = x809 == 0;
bool x811 = !x810;
x813 = x811;
}
if (x813) {
int32_t x814 = 0;
x814 = 234;
int32_t* x816 = x129;
int32_t x817 = x816[x789];
int32_t x818 = x817;
for (;;) {
int32_t x819 = x818;
bool x820 = x819 != -1;
if (!x820) break;
int32_t x822 = x818;
bool x823 = true;
int32_t* x824 = x103;
int32_t x825 = x824[x822];
bool x826 = 1 == x825;
if (x826) {
} else {
x823 = false;
}
bool x830 = x823;
if (x830) {
int32_t* x831 = x107;
int32_t* x833 = x111;
int32_t x832 = x831[x822];
int32_t x834 = x833[x822];
bool x835 = x832 < x834;
if (x835) {
int32_t x836 = 0;
x836 = 233;
int32_t* x838 = x30;
int32_t x839 = x838[x443];
int32_t x840 = x839;
for (;;) {
int32_t x841 = x840;
bool x842 = x841 != -1;
if (!x842) break;
int32_t x844 = x840;
bool x845 = true;
int32_t* x846 = x4;
int32_t x847 = x846[x844];
bool x848 = 0 == x847;
if (x848) {
} else {
x845 = false;
}
bool x852 = x845;
if (x852) {
int32_t* x853 = x107;
int32_t* x856 = x111;
int32_t* x858 = x16;
bool x860 = false;
int32_t x861 = 0;
x861 = 234;
int32_t x854 = x853[x822];
int32_t x855 = x854 + 1;
int32_t x863 = 236106 + x855;
int32_t x864 = x863 + 233;
x861 = x864;
int32_t x857 = x856[x822];
int32_t x866 = x864 * 1009;
int32_t x867 = x866 + x857;
int32_t x868 = x867 + 233;
x861 = x868;
int32_t x859 = x858[x844];
int32_t x870 = x868 * 1009;
int32_t x871 = x870 + x859;
int32_t x872 = x871 + 233;
x861 = x872;
int32_t* x875 = x28;
int32_t x874 = x872 & 4194303;
int32_t x876 = x875[x874];
int32_t x877 = x876;
bool x878 = true;
for (;;) {
bool x879 = x878;
bool x883;
if (x879) {
int32_t x880 = x877;
bool x881 = x880 != -1;
x883 = x881;
} else {
x883 = false;
}
if (!x883) break;
int32_t x885 = x877;
bool x886 = true;
int32_t* x887 = x4;
int32_t x888 = x887[x885];
bool x889 = 1 == x888;
if (x889) {
} else {
x886 = false;
}
int32_t* x893 = x8;
int32_t x894 = x893[x885];
bool x895 = x855 == x894;
if (x895) {
} else {
x886 = false;
}
int32_t* x899 = x12;
int32_t x900 = x899[x885];
bool x901 = x857 == x900;
if (x901) {
} else {
x886 = false;
}
int32_t* x905 = x16;
int32_t x906 = x905[x885];
bool x907 = x859 == x906;
if (x907) {
} else {
x886 = false;
}
bool x911 = x886;
if (x911) {
x860 = true;
x878 = false;
} else {
}
int32_t* x916 = x21;
int32_t x917 = x916[x885];
x877 = x917;
}
bool x921 = x860;
bool x991;
if (x921) {
x991 = false;
} else {
int32_t* x923 = x8;
int32_t* x925 = x12;
bool x927 = false;
int32_t x928 = 0;
x928 = 233;
int32_t x924 = x923[x844];
int32_t x930 = 235097 + x924;
int32_t x931 = x930 + 233;
x928 = x931;
int32_t x926 = x925[x844];
int32_t x933 = x931 * 1009;
int32_t x934 = x933 + x926;
int32_t x935 = x934 + 233;
x928 = x935;
int32_t x937 = x935 * 1009;
int32_t x938 = x937 + x859;
int32_t x939 = x938 + 233;
x928 = x939;
int32_t* x942 = x127;
int32_t x941 = x939 & 16383;
int32_t x943 = x942[x941];
int32_t x944 = x943;
bool x945 = true;
for (;;) {
bool x946 = x945;
bool x950;
if (x946) {
int32_t x947 = x944;
bool x948 = x947 != -1;
x950 = x948;
} else {
x950 = false;
}
if (!x950) break;
int32_t x952 = x944;
bool x953 = true;
int32_t* x954 = x103;
int32_t x955 = x954[x952];
bool x956 = 0 == x955;
if (x956) {
} else {
x953 = false;
}
int32_t* x960 = x107;
int32_t x961 = x960[x952];
bool x962 = x924 == x961;
if (x962) {
} else {
x953 = false;
}
int32_t* x966 = x111;
int32_t x967 = x966[x952];
bool x968 = x926 == x967;
if (x968) {
} else {
x953 = false;
}
int32_t* x972 = x115;
int32_t x973 = x972[x952];
bool x974 = x859 == x973;
if (x974) {
} else {
x953 = false;
}
bool x978 = x953;
if (x978) {
x927 = true;
x945 = false;
} else {
}
int32_t* x983 = x120;
int32_t x984 = x983[x952];
x944 = x984;
}
bool x988 = x927;
bool x989 = !x988;
x991 = x989;
}
if (x991) {
bool x992 = true;
int32_t x993 = 0;
x993 = 234;
x993 = x864;
x993 = x868;
x993 = x872;
int32_t* x999 = x69;
int32_t x998 = x872 & 16383;
int32_t x1000 = x999[x998];
int32_t x1001 = x1000;
bool x1002 = true;
for (;;) {
bool x1003 = x1002;
bool x1007;
if (x1003) {
int32_t x1004 = x1001;
bool x1005 = x1004 != -1;
x1007 = x1005;
} else {
x1007 = false;
}
if (!x1007) break;
int32_t x1009 = x1001;
bool x1010 = true;
int32_t* x1011 = x45;
int32_t x1012 = x1011[x1009];
bool x1013 = 1 == x1012;
if (x1013) {
} else {
x1010 = false;
}
int32_t* x1017 = x49;
int32_t x1018 = x1017[x1009];
bool x1019 = x855 == x1018;
if (x1019) {
} else {
x1010 = false;
}
int32_t* x1023 = x53;
int32_t x1024 = x1023[x1009];
bool x1025 = x857 == x1024;
if (x1025) {
} else {
x1010 = false;
}
int32_t* x1029 = x57;
int32_t x1030 = x1029[x1009];
bool x1031 = x859 == x1030;
if (x1031) {
} else {
x1010 = false;
}
bool x1035 = x1010;
if (x1035) {
bool x1036 = true;
if (x1013) {
} else {
x1036 = false;
}
if (x1019) {
} else {
x1036 = false;
}
if (x1025) {
} else {
x1036 = false;
}
if (x1031) {
} else {
x1036 = false;
}
bool x1049 = x1036;
if (x1049) {
x992 = false;
} else {
}
bool x1053 = x992;
x1002 = x1053;
} else {
}
int32_t* x1057 = x62;
int32_t x1058 = x1057[x1009];
x1001 = x1058;
}
bool x1062 = x992;
if (x1062) {
int32_t x1065 = x59;
int32_t x1066 = x42;
bool x1067 = x1065 == x1066;
if (x1067) {
x42 *= 4;
int32_t x1069 = x42;
printf("buffer.resize %d\n",x1069);
} else {
}
int32_t* x1073 = x45;
x1073[x1065] = 1;
int32_t* x1075 = x49;
x1075[x1065] = x855;
int32_t* x1077 = x53;
x1077[x1065] = x857;
int32_t* x1079 = x57;
x1079[x1065] = x859;
x59 += 1;
int32_t x1082 = x1065;
int32_t x1083 = 0;
x1083 = 234;
x1083 = x864;
x1083 = x868;
x1083 = x872;
int32_t x1088 = x1000;
x999[x998] = x1065;
int32_t* x1090 = x62;
x1090[x1065] = x1000;
int32_t x1092 = 0;
x1092 = 234;
int32_t* x1094 = x71;
int32_t x1095 = x1094[x789];
int32_t x1096 = x1095;
x1094[x789] = x1065;
int32_t* x1098 = x66;
x1098[x1065] = x1095;
} else {
}
} else {
}
} else {
}
int32_t* x1106 = x25;
int32_t x1107 = x1106[x844];
x840 = x1107;
}
} else {
}
} else {
}
int32_t* x1115 = x124;
int32_t x1116 = x1115[x822];
x818 = x1116;
}
} else {
}
int32_t x1122 = x18;
bool x1123 = x1122 == 0;
bool x1125;
if (x1123) {
x1125 = false;
} else {
bool x599 = !x598;
x1125 = x599;
}
if (x1125) {
int32_t x1126 = 0;
x1126 = 234;
int32_t* x1129 = x30;
int32_t x1130 = x1129[x1128];
int32_t x1131 = x1130;
for (;;) {
int32_t x1132 = x1131;
bool x1133 = x1132 != -1;
if (!x1133) break;
int32_t x1135 = x1131;
bool x1136 = true;
int32_t* x1137 = x4;
int32_t x1138 = x1137[x1135];
bool x1139 = 1 == x1138;
if (x1139) {
} else {
x1136 = false;
}
bool x1143 = x1136;
if (x1143) {
int32_t* x1144 = x8;
int32_t* x1146 = x12;
int32_t x1145 = x1144[x1135];
int32_t x1147 = x1146[x1135];
bool x1148 = x1145 < x1147;
if (x1148) {
int32_t x1149 = 0;
x1149 = 233;
int32_t* x1151 = x129;
int32_t x1152 = x1151[x602];
int32_t x1153 = x1152;
for (;;) {
int32_t x1154 = x1153;
bool x1155 = x1154 != -1;
if (!x1155) break;
int32_t x1157 = x1153;
bool x1158 = true;
int32_t* x1159 = x103;
int32_t x1160 = x1159[x1157];
bool x1161 = 0 == x1160;
if (x1161) {
} else {
x1158 = false;
}
bool x1165 = x1158;
if (x1165) {
int32_t* x1166 = x8;
int32_t* x1169 = x12;
int32_t* x1171 = x115;
bool x1173 = false;
int32_t x1174 = 0;
x1174 = 234;
int32_t x1167 = x1166[x1135];
int32_t x1168 = x1167 + 1;
int32_t x1176 = 236106 + x1168;
int32_t x1177 = x1176 + 233;
x1174 = x1177;
int32_t x1170 = x1169[x1135];
int32_t x1179 = x1177 * 1009;
int32_t x1180 = x1179 + x1170;
int32_t x1181 = x1180 + 233;
x1174 = x1181;
int32_t x1172 = x1171[x1157];
int32_t x1183 = x1181 * 1009;
int32_t x1184 = x1183 + x1172;
int32_t x1185 = x1184 + 233;
x1174 = x1185;
int32_t* x1188 = x28;
int32_t x1187 = x1185 & 4194303;
int32_t x1189 = x1188[x1187];
int32_t x1190 = x1189;
bool x1191 = true;
for (;;) {
bool x1192 = x1191;
bool x1196;
if (x1192) {
int32_t x1193 = x1190;
bool x1194 = x1193 != -1;
x1196 = x1194;
} else {
x1196 = false;
}
if (!x1196) break;
int32_t x1198 = x1190;
bool x1199 = true;
int32_t* x1200 = x4;
int32_t x1201 = x1200[x1198];
bool x1202 = 1 == x1201;
if (x1202) {
} else {
x1199 = false;
}
int32_t* x1206 = x8;
int32_t x1207 = x1206[x1198];
bool x1208 = x1168 == x1207;
if (x1208) {
} else {
x1199 = false;
}
int32_t* x1212 = x12;
int32_t x1213 = x1212[x1198];
bool x1214 = x1170 == x1213;
if (x1214) {
} else {
x1199 = false;
}
int32_t* x1218 = x16;
int32_t x1219 = x1218[x1198];
bool x1220 = x1172 == x1219;
if (x1220) {
} else {
x1199 = false;
}
bool x1224 = x1199;
if (x1224) {
x1173 = true;
x1191 = false;
} else {
}
int32_t* x1229 = x21;
int32_t x1230 = x1229[x1198];
x1190 = x1230;
}
bool x1234 = x1173;
if (x1234) {
} else {
bool x1236 = true;
int32_t x1237 = 0;
x1237 = 234;
x1237 = x1177;
x1237 = x1181;
x1237 = x1185;
int32_t* x1243 = x69;
int32_t x1242 = x1185 & 16383;
int32_t x1244 = x1243[x1242];
int32_t x1245 = x1244;
bool x1246 = true;
for (;;) {
bool x1247 = x1246;
bool x1251;
if (x1247) {
int32_t x1248 = x1245;
bool x1249 = x1248 != -1;
x1251 = x1249;
} else {
x1251 = false;
}
if (!x1251) break;
int32_t x1253 = x1245;
bool x1254 = true;
int32_t* x1255 = x45;
int32_t x1256 = x1255[x1253];
bool x1257 = 1 == x1256;
if (x1257) {
} else {
x1254 = false;
}
int32_t* x1261 = x49;
int32_t x1262 = x1261[x1253];
bool x1263 = x1168 == x1262;
if (x1263) {
} else {
x1254 = false;
}
int32_t* x1267 = x53;
int32_t x1268 = x1267[x1253];
bool x1269 = x1170 == x1268;
if (x1269) {
} else {
x1254 = false;
}
int32_t* x1273 = x57;
int32_t x1274 = x1273[x1253];
bool x1275 = x1172 == x1274;
if (x1275) {
} else {
x1254 = false;
}
bool x1279 = x1254;
if (x1279) {
bool x1280 = true;
if (x1257) {
} else {
x1280 = false;
}
if (x1263) {
} else {
x1280 = false;
}
if (x1269) {
} else {
x1280 = false;
}
if (x1275) {
} else {
x1280 = false;
}
bool x1293 = x1280;
if (x1293) {
x1236 = false;
} else {
}
bool x1297 = x1236;
x1246 = x1297;
} else {
}
int32_t* x1301 = x62;
int32_t x1302 = x1301[x1253];
x1245 = x1302;
}
bool x1306 = x1236;
if (x1306) {
int32_t x1309 = x59;
int32_t x1310 = x42;
bool x1311 = x1309 == x1310;
if (x1311) {
x42 *= 4;
int32_t x1313 = x42;
printf("buffer.resize %d\n",x1313);
} else {
}
int32_t* x1317 = x45;
x1317[x1309] = 1;
int32_t* x1319 = x49;
x1319[x1309] = x1168;
int32_t* x1321 = x53;
x1321[x1309] = x1170;
int32_t* x1323 = x57;
x1323[x1309] = x1172;
x59 += 1;
int32_t x1326 = x1309;
int32_t x1327 = 0;
x1327 = 234;
x1327 = x1177;
x1327 = x1181;
x1327 = x1185;
int32_t x1332 = x1244;
x1243[x1242] = x1309;
int32_t* x1334 = x62;
x1334[x1309] = x1244;
int32_t x1336 = 0;
x1336 = 234;
int32_t* x1338 = x71;
int32_t x1339 = x1338[x789];
int32_t x1340 = x1339;
x1338[x789] = x1309;
int32_t* x1342 = x66;
x1342[x1309] = x1339;
} else {
}
}
} else {
}
int32_t* x1350 = x124;
int32_t x1351 = x1350[x1157];
x1153 = x1351;
}
} else {
}
} else {
}
int32_t* x1359 = x25;
int32_t x1360 = x1359[x1135];
x1131 = x1360;
}
} else {
}
if (x598) {
} else {
int32_t x1366 = 0;
x1366 = 234;
int32_t* x1368 = x129;
int32_t x1369 = x1368[x789];
int32_t x1370 = x1369;
for (;;) {
int32_t x1371 = x1370;
bool x1372 = x1371 != -1;
if (!x1372) break;
int32_t x1374 = x1370;
bool x1375 = true;
int32_t* x1376 = x103;
int32_t x1377 = x1376[x1374];
bool x1378 = 1 == x1377;
if (x1378) {
} else {
x1375 = false;
}
bool x1382 = x1375;
if (x1382) {
int32_t* x1383 = x107;
int32_t* x1385 = x111;
int32_t x1384 = x1383[x1374];
int32_t x1386 = x1385[x1374];
bool x1387 = x1384 >= x1386;
bool x1454;
if (x1387) {
int32_t* x1388 = x115;
bool x1390 = false;
int32_t x1391 = 0;
x1391 = 235;
int32_t x1393 = 237115 + x1384;
int32_t x1394 = x1393 + 233;
x1391 = x1394;
int32_t x1396 = x1394 * 1009;
int32_t x1397 = x1396 + x1386;
int32_t x1398 = x1397 + 233;
x1391 = x1398;
int32_t x1389 = x1388[x1374];
int32_t x1400 = x1398 * 1009;
int32_t x1401 = x1400 + x1389;
int32_t x1402 = x1401 + 233;
x1391 = x1402;
int32_t* x1405 = x28;
int32_t x1404 = x1402 & 4194303;
int32_t x1406 = x1405[x1404];
int32_t x1407 = x1406;
bool x1408 = true;
for (;;) {
bool x1409 = x1408;
bool x1413;
if (x1409) {
int32_t x1410 = x1407;
bool x1411 = x1410 != -1;
x1413 = x1411;
} else {
x1413 = false;
}
if (!x1413) break;
int32_t x1415 = x1407;
bool x1416 = true;
int32_t* x1417 = x4;
int32_t x1418 = x1417[x1415];
bool x1419 = 2 == x1418;
if (x1419) {
} else {
x1416 = false;
}
int32_t* x1423 = x8;
int32_t x1424 = x1423[x1415];
bool x1425 = x1384 == x1424;
if (x1425) {
} else {
x1416 = false;
}
int32_t* x1429 = x12;
int32_t x1430 = x1429[x1415];
bool x1431 = x1386 == x1430;
if (x1431) {
} else {
x1416 = false;
}
int32_t* x1435 = x16;
int32_t x1436 = x1435[x1415];
bool x1437 = x1389 == x1436;
if (x1437) {
} else {
x1416 = false;
}
bool x1441 = x1416;
if (x1441) {
x1390 = true;
x1408 = false;
} else {
}
int32_t* x1446 = x21;
int32_t x1447 = x1446[x1415];
x1407 = x1447;
}
bool x1451 = x1390;
bool x1452 = !x1451;
x1454 = x1452;
} else {
x1454 = false;
}
if (x1454) {
int32_t* x1455 = x115;
bool x1457 = true;
int32_t x1458 = 0;
x1458 = 235;
int32_t x1393 = 237115 + x1384;
int32_t x1394 = x1393 + 233;
x1458 = x1394;
int32_t x1396 = x1394 * 1009;
int32_t x1397 = x1396 + x1386;
int32_t x1398 = x1397 + 233;
x1458 = x1398;
int32_t x1400 = x1398 * 1009;
int32_t x1456 = x1455[x1374];
int32_t x1462 = x1400 + x1456;
int32_t x1463 = x1462 + 233;
x1458 = x1463;
int32_t* x1466 = x69;
int32_t x1465 = x1463 & 16383;
int32_t x1467 = x1466[x1465];
int32_t x1468 = x1467;
bool x1469 = true;
for (;;) {
bool x1470 = x1469;
bool x1474;
if (x1470) {
int32_t x1471 = x1468;
bool x1472 = x1471 != -1;
x1474 = x1472;
} else {
x1474 = false;
}
if (!x1474) break;
int32_t x1476 = x1468;
bool x1477 = true;
int32_t* x1478 = x45;
int32_t x1479 = x1478[x1476];
bool x1480 = 2 == x1479;
if (x1480) {
} else {
x1477 = false;
}
int32_t* x1484 = x49;
int32_t x1485 = x1484[x1476];
bool x1486 = x1384 == x1485;
if (x1486) {
} else {
x1477 = false;
}
int32_t* x1490 = x53;
int32_t x1491 = x1490[x1476];
bool x1492 = x1386 == x1491;
if (x1492) {
} else {
x1477 = false;
}
int32_t* x1496 = x57;
int32_t x1497 = x1496[x1476];
bool x1498 = x1456 == x1497;
if (x1498) {
} else {
x1477 = false;
}
bool x1502 = x1477;
if (x1502) {
bool x1503 = true;
if (x1480) {
} else {
x1503 = false;
}
if (x1486) {
} else {
x1503 = false;
}
if (x1492) {
} else {
x1503 = false;
}
if (x1498) {
} else {
x1503 = false;
}
bool x1516 = x1503;
if (x1516) {
x1457 = false;
} else {
}
bool x1520 = x1457;
x1469 = x1520;
} else {
}
int32_t* x1524 = x62;
int32_t x1525 = x1524[x1476];
x1468 = x1525;
}
bool x1529 = x1457;
if (x1529) {
int32_t x1532 = x59;
int32_t x1533 = x42;
bool x1534 = x1532 == x1533;
if (x1534) {
x42 *= 4;
int32_t x1536 = x42;
printf("buffer.resize %d\n",x1536);
} else {
}
int32_t* x1540 = x45;
x1540[x1532] = 2;
int32_t* x1542 = x49;
x1542[x1532] = x1384;
int32_t* x1544 = x53;
x1544[x1532] = x1386;
int32_t* x1546 = x57;
x1546[x1532] = x1456;
x59 += 1;
int32_t x1549 = x1532;
int32_t x1550 = 0;
x1550 = 235;
x1550 = x1394;
x1550 = x1398;
x1550 = x1463;
int32_t x1555 = x1467;
x1466[x1465] = x1532;
int32_t* x1557 = x62;
x1557[x1532] = x1467;
int32_t x1559 = 0;
x1559 = 235;
int32_t* x1562 = x71;
int32_t x1563 = x1562[x1561];
int32_t x1564 = x1563;
x1562[x1561] = x1532;
int32_t* x1566 = x66;
x1566[x1532] = x1563;
} else {
}
} else {
}
} else {
}
int32_t* x1574 = x124;
int32_t x1575 = x1574[x1374];
x1370 = x1575;
}
}
bool x1581;
if (x598) {
x1581 = false;
} else {
bool x1124 = !x1123;
x1581 = x1124;
}
if (x1581) {
int32_t x1582 = 0;
x1582 = 235;
int32_t* x1584 = x129;
int32_t x1585 = x1584[x1561];
int32_t x1586 = x1585;
for (;;) {
int32_t x1587 = x1586;
bool x1588 = x1587 != -1;
if (!x1588) break;
int32_t x1590 = x1586;
bool x1591 = true;
int32_t* x1592 = x103;
int32_t x1593 = x1592[x1590];
bool x1594 = 2 == x1593;
if (x1594) {
} else {
x1591 = false;
}
bool x1598 = x1591;
if (x1598) {
int32_t* x1599 = x111;
int32_t* x1601 = x115;
int32_t x1600 = x1599[x1590];
int32_t x1602 = x1601[x1590];
bool x1603 = x1600 < x1602;
if (x1603) {
int32_t x1604 = 0;
x1604 = 234;
int32_t* x1606 = x30;
int32_t x1607 = x1606[x1128];
int32_t x1608 = x1607;
for (;;) {
int32_t x1609 = x1608;
bool x1610 = x1609 != -1;
if (!x1610) break;
int32_t x1612 = x1608;
bool x1613 = true;
int32_t* x1614 = x4;
int32_t x1615 = x1614[x1612];
bool x1616 = 1 == x1615;
if (x1616) {
} else {
x1613 = false;
}
bool x1620 = x1613;
if (x1620) {
int32_t* x1621 = x8;
int32_t* x1623 = x111;
int32_t* x1626 = x115;
bool x1628 = false;
int32_t x1629 = 0;
x1629 = 235;
int32_t x1622 = x1621[x1612];
int32_t x1631 = 237115 + x1622;
int32_t x1632 = x1631 + 233;
x1629 = x1632;
int32_t x1624 = x1623[x1590];
int32_t x1625 = x1624 + 1;
int32_t x1634 = x1632 * 1009;
int32_t x1635 = x1634 + x1625;
int32_t x1636 = x1635 + 233;
x1629 = x1636;
int32_t x1627 = x1626[x1590];
int32_t x1638 = x1636 * 1009;
int32_t x1639 = x1638 + x1627;
int32_t x1640 = x1639 + 233;
x1629 = x1640;
int32_t* x1643 = x28;
int32_t x1642 = x1640 & 4194303;
int32_t x1644 = x1643[x1642];
int32_t x1645 = x1644;
bool x1646 = true;
for (;;) {
bool x1647 = x1646;
bool x1651;
if (x1647) {
int32_t x1648 = x1645;
bool x1649 = x1648 != -1;
x1651 = x1649;
} else {
x1651 = false;
}
if (!x1651) break;
int32_t x1653 = x1645;
bool x1654 = true;
int32_t* x1655 = x4;
int32_t x1656 = x1655[x1653];
bool x1657 = 2 == x1656;
if (x1657) {
} else {
x1654 = false;
}
int32_t* x1661 = x8;
int32_t x1662 = x1661[x1653];
bool x1663 = x1622 == x1662;
if (x1663) {
} else {
x1654 = false;
}
int32_t* x1667 = x12;
int32_t x1668 = x1667[x1653];
bool x1669 = x1625 == x1668;
if (x1669) {
} else {
x1654 = false;
}
int32_t* x1673 = x16;
int32_t x1674 = x1673[x1653];
bool x1675 = x1627 == x1674;
if (x1675) {
} else {
x1654 = false;
}
bool x1679 = x1654;
if (x1679) {
x1628 = true;
x1646 = false;
} else {
}
int32_t* x1684 = x21;
int32_t x1685 = x1684[x1653];
x1645 = x1685;
}
bool x1689 = x1628;
bool x1759;
if (x1689) {
x1759 = false;
} else {
int32_t* x1691 = x12;
int32_t* x1693 = x16;
bool x1695 = false;
int32_t x1696 = 0;
x1696 = 234;
int32_t x1698 = 236106 + x1622;
int32_t x1699 = x1698 + 233;
x1696 = x1699;
int32_t x1692 = x1691[x1612];
int32_t x1701 = x1699 * 1009;
int32_t x1702 = x1701 + x1692;
int32_t x1703 = x1702 + 233;
x1696 = x1703;
int32_t x1694 = x1693[x1612];
int32_t x1705 = x1703 * 1009;
int32_t x1706 = x1705 + x1694;
int32_t x1707 = x1706 + 233;
x1696 = x1707;
int32_t* x1710 = x127;
int32_t x1709 = x1707 & 16383;
int32_t x1711 = x1710[x1709];
int32_t x1712 = x1711;
bool x1713 = true;
for (;;) {
bool x1714 = x1713;
bool x1718;
if (x1714) {
int32_t x1715 = x1712;
bool x1716 = x1715 != -1;
x1718 = x1716;
} else {
x1718 = false;
}
if (!x1718) break;
int32_t x1720 = x1712;
bool x1721 = true;
int32_t* x1722 = x103;
int32_t x1723 = x1722[x1720];
bool x1724 = 1 == x1723;
if (x1724) {
} else {
x1721 = false;
}
int32_t* x1728 = x107;
int32_t x1729 = x1728[x1720];
bool x1730 = x1622 == x1729;
if (x1730) {
} else {
x1721 = false;
}
int32_t* x1734 = x111;
int32_t x1735 = x1734[x1720];
bool x1736 = x1692 == x1735;
if (x1736) {
} else {
x1721 = false;
}
int32_t* x1740 = x115;
int32_t x1741 = x1740[x1720];
bool x1742 = x1694 == x1741;
if (x1742) {
} else {
x1721 = false;
}
bool x1746 = x1721;
if (x1746) {
x1695 = true;
x1713 = false;
} else {
}
int32_t* x1751 = x120;
int32_t x1752 = x1751[x1720];
x1712 = x1752;
}
bool x1756 = x1695;
bool x1757 = !x1756;
x1759 = x1757;
}
if (x1759) {
bool x1760 = true;
int32_t x1761 = 0;
x1761 = 235;
x1761 = x1632;
x1761 = x1636;
x1761 = x1640;
int32_t* x1767 = x69;
int32_t x1766 = x1640 & 16383;
int32_t x1768 = x1767[x1766];
int32_t x1769 = x1768;
bool x1770 = true;
for (;;) {
bool x1771 = x1770;
bool x1775;
if (x1771) {
int32_t x1772 = x1769;
bool x1773 = x1772 != -1;
x1775 = x1773;
} else {
x1775 = false;
}
if (!x1775) break;
int32_t x1777 = x1769;
bool x1778 = true;
int32_t* x1779 = x45;
int32_t x1780 = x1779[x1777];
bool x1781 = 2 == x1780;
if (x1781) {
} else {
x1778 = false;
}
int32_t* x1785 = x49;
int32_t x1786 = x1785[x1777];
bool x1787 = x1622 == x1786;
if (x1787) {
} else {
x1778 = false;
}
int32_t* x1791 = x53;
int32_t x1792 = x1791[x1777];
bool x1793 = x1625 == x1792;
if (x1793) {
} else {
x1778 = false;
}
int32_t* x1797 = x57;
int32_t x1798 = x1797[x1777];
bool x1799 = x1627 == x1798;
if (x1799) {
} else {
x1778 = false;
}
bool x1803 = x1778;
if (x1803) {
bool x1804 = true;
if (x1781) {
} else {
x1804 = false;
}
if (x1787) {
} else {
x1804 = false;
}
if (x1793) {
} else {
x1804 = false;
}
if (x1799) {
} else {
x1804 = false;
}
bool x1817 = x1804;
if (x1817) {
x1760 = false;
} else {
}
bool x1821 = x1760;
x1770 = x1821;
} else {
}
int32_t* x1825 = x62;
int32_t x1826 = x1825[x1777];
x1769 = x1826;
}
bool x1830 = x1760;
if (x1830) {
int32_t x1833 = x59;
int32_t x1834 = x42;
bool x1835 = x1833 == x1834;
if (x1835) {
x42 *= 4;
int32_t x1837 = x42;
printf("buffer.resize %d\n",x1837);
} else {
}
int32_t* x1841 = x45;
x1841[x1833] = 2;
int32_t* x1843 = x49;
x1843[x1833] = x1622;
int32_t* x1845 = x53;
x1845[x1833] = x1625;
int32_t* x1847 = x57;
x1847[x1833] = x1627;
x59 += 1;
int32_t x1850 = x1833;
int32_t x1851 = 0;
x1851 = 235;
x1851 = x1632;
x1851 = x1636;
x1851 = x1640;
int32_t x1856 = x1768;
x1767[x1766] = x1833;
int32_t* x1858 = x62;
x1858[x1833] = x1768;
int32_t x1860 = 0;
x1860 = 235;
int32_t* x1862 = x71;
int32_t x1863 = x1862[x1561];
int32_t x1864 = x1863;
x1862[x1561] = x1833;
int32_t* x1866 = x66;
x1866[x1833] = x1863;
} else {
}
} else {
}
} else {
}
int32_t* x1874 = x25;
int32_t x1875 = x1874[x1612];
x1608 = x1875;
}
} else {
}
} else {
}
int32_t* x1883 = x124;
int32_t x1884 = x1883[x1590];
x1586 = x1884;
}
} else {
}
if (x1125) {
int32_t x1890 = 0;
x1890 = 235;
int32_t* x1893 = x30;
int32_t x1894 = x1893[x1892];
int32_t x1895 = x1894;
for (;;) {
int32_t x1896 = x1895;
bool x1897 = x1896 != -1;
if (!x1897) break;
int32_t x1899 = x1895;
bool x1900 = true;
int32_t* x1901 = x4;
int32_t x1902 = x1901[x1899];
bool x1903 = 2 == x1902;
if (x1903) {
} else {
x1900 = false;
}
bool x1907 = x1900;
if (x1907) {
int32_t* x1908 = x12;
int32_t* x1910 = x16;
int32_t x1909 = x1908[x1899];
int32_t x1911 = x1910[x1899];
bool x1912 = x1909 < x1911;
if (x1912) {
int32_t x1913 = 0;
x1913 = 234;
int32_t* x1915 = x129;
int32_t x1916 = x1915[x789];
int32_t x1917 = x1916;
for (;;) {
int32_t x1918 = x1917;
bool x1919 = x1918 != -1;
if (!x1919) break;
int32_t x1921 = x1917;
bool x1922 = true;
int32_t* x1923 = x103;
int32_t x1924 = x1923[x1921];
bool x1925 = 1 == x1924;
if (x1925) {
} else {
x1922 = false;
}
bool x1929 = x1922;
if (x1929) {
int32_t* x1930 = x107;
int32_t* x1932 = x12;
int32_t* x1935 = x16;
bool x1937 = false;
int32_t x1938 = 0;
x1938 = 235;
int32_t x1931 = x1930[x1921];
int32_t x1940 = 237115 + x1931;
int32_t x1941 = x1940 + 233;
x1938 = x1941;
int32_t x1933 = x1932[x1899];
int32_t x1934 = x1933 + 1;
int32_t x1943 = x1941 * 1009;
int32_t x1944 = x1943 + x1934;
int32_t x1945 = x1944 + 233;
x1938 = x1945;
int32_t x1936 = x1935[x1899];
int32_t x1947 = x1945 * 1009;
int32_t x1948 = x1947 + x1936;
int32_t x1949 = x1948 + 233;
x1938 = x1949;
int32_t* x1952 = x28;
int32_t x1951 = x1949 & 4194303;
int32_t x1953 = x1952[x1951];
int32_t x1954 = x1953;
bool x1955 = true;
for (;;) {
bool x1956 = x1955;
bool x1960;
if (x1956) {
int32_t x1957 = x1954;
bool x1958 = x1957 != -1;
x1960 = x1958;
} else {
x1960 = false;
}
if (!x1960) break;
int32_t x1962 = x1954;
bool x1963 = true;
int32_t* x1964 = x4;
int32_t x1965 = x1964[x1962];
bool x1966 = 2 == x1965;
if (x1966) {
} else {
x1963 = false;
}
int32_t* x1970 = x8;
int32_t x1971 = x1970[x1962];
bool x1972 = x1931 == x1971;
if (x1972) {
} else {
x1963 = false;
}
int32_t* x1976 = x12;
int32_t x1977 = x1976[x1962];
bool x1978 = x1934 == x1977;
if (x1978) {
} else {
x1963 = false;
}
int32_t* x1982 = x16;
int32_t x1983 = x1982[x1962];
bool x1984 = x1936 == x1983;
if (x1984) {
} else {
x1963 = false;
}
bool x1988 = x1963;
if (x1988) {
x1937 = true;
x1955 = false;
} else {
}
int32_t* x1993 = x21;
int32_t x1994 = x1993[x1962];
x1954 = x1994;
}
bool x1998 = x1937;
if (x1998) {
} else {
bool x2000 = true;
int32_t x2001 = 0;
x2001 = 235;
x2001 = x1941;
x2001 = x1945;
x2001 = x1949;
int32_t* x2007 = x69;
int32_t x2006 = x1949 & 16383;
int32_t x2008 = x2007[x2006];
int32_t x2009 = x2008;
bool x2010 = true;
for (;;) {
bool x2011 = x2010;
bool x2015;
if (x2011) {
int32_t x2012 = x2009;
bool x2013 = x2012 != -1;
x2015 = x2013;
} else {
x2015 = false;
}
if (!x2015) break;
int32_t x2017 = x2009;
bool x2018 = true;
int32_t* x2019 = x45;
int32_t x2020 = x2019[x2017];
bool x2021 = 2 == x2020;
if (x2021) {
} else {
x2018 = false;
}
int32_t* x2025 = x49;
int32_t x2026 = x2025[x2017];
bool x2027 = x1931 == x2026;
if (x2027) {
} else {
x2018 = false;
}
int32_t* x2031 = x53;
int32_t x2032 = x2031[x2017];
bool x2033 = x1934 == x2032;
if (x2033) {
} else {
x2018 = false;
}
int32_t* x2037 = x57;
int32_t x2038 = x2037[x2017];
bool x2039 = x1936 == x2038;
if (x2039) {
} else {
x2018 = false;
}
bool x2043 = x2018;
if (x2043) {
bool x2044 = true;
if (x2021) {
} else {
x2044 = false;
}
if (x2027) {
} else {
x2044 = false;
}
if (x2033) {
} else {
x2044 = false;
}
if (x2039) {
} else {
x2044 = false;
}
bool x2057 = x2044;
if (x2057) {
x2000 = false;
} else {
}
bool x2061 = x2000;
x2010 = x2061;
} else {
}
int32_t* x2065 = x62;
int32_t x2066 = x2065[x2017];
x2009 = x2066;
}
bool x2070 = x2000;
if (x2070) {
int32_t x2073 = x59;
int32_t x2074 = x42;
bool x2075 = x2073 == x2074;
if (x2075) {
x42 *= 4;
int32_t x2077 = x42;
printf("buffer.resize %d\n",x2077);
} else {
}
int32_t* x2081 = x45;
x2081[x2073] = 2;
int32_t* x2083 = x49;
x2083[x2073] = x1931;
int32_t* x2085 = x53;
x2085[x2073] = x1934;
int32_t* x2087 = x57;
x2087[x2073] = x1936;
x59 += 1;
int32_t x2090 = x2073;
int32_t x2091 = 0;
x2091 = 235;
x2091 = x1941;
x2091 = x1945;
x2091 = x1949;
int32_t x2096 = x2008;
x2007[x2006] = x2073;
int32_t* x2098 = x62;
x2098[x2073] = x2008;
int32_t x2100 = 0;
x2100 = 235;
int32_t* x2102 = x71;
int32_t x2103 = x2102[x1561];
int32_t x2104 = x2103;
x2102[x1561] = x2073;
int32_t* x2106 = x66;
x2106[x2073] = x2103;
} else {
}
}
} else {
}
int32_t* x2114 = x124;
int32_t x2115 = x2114[x1921];
x1917 = x2115;
}
} else {
}
} else {
}
int32_t* x2123 = x25;
int32_t x2124 = x2123[x1899];
x1895 = x2124;
}
} else {
}
if (x598) {
} else {
int32_t x2130 = 0;
x2130 = 235;
int32_t* x2132 = x129;
int32_t x2133 = x2132[x1561];
int32_t x2134 = x2133;
for (;;) {
int32_t x2135 = x2134;
bool x2136 = x2135 != -1;
if (!x2136) break;
int32_t x2138 = x2134;
bool x2139 = true;
int32_t* x2140 = x103;
int32_t x2141 = x2140[x2138];
bool x2142 = 2 == x2141;
if (x2142) {
} else {
x2139 = false;
}
bool x2146 = x2139;
if (x2146) {
int32_t* x2147 = x111;
int32_t* x2149 = x115;
int32_t x2148 = x2147[x2138];
int32_t x2150 = x2149[x2138];
bool x2151 = x2148 >= x2150;
bool x2218;
if (x2151) {
int32_t* x2152 = x107;
bool x2154 = false;
int32_t x2155 = 0;
x2155 = 236;
int32_t x2153 = x2152[x2138];
int32_t x2157 = 238124 + x2153;
int32_t x2158 = x2157 + 233;
x2155 = x2158;
int32_t x2160 = x2158 * 1009;
int32_t x2161 = x2160 + x2148;
int32_t x2162 = x2161 + 233;
x2155 = x2162;
int32_t x2164 = x2162 * 1009;
int32_t x2165 = x2164 + x2150;
int32_t x2166 = x2165 + 233;
x2155 = x2166;
int32_t* x2169 = x28;
int32_t x2168 = x2166 & 4194303;
int32_t x2170 = x2169[x2168];
int32_t x2171 = x2170;
bool x2172 = true;
for (;;) {
bool x2173 = x2172;
bool x2177;
if (x2173) {
int32_t x2174 = x2171;
bool x2175 = x2174 != -1;
x2177 = x2175;
} else {
x2177 = false;
}
if (!x2177) break;
int32_t x2179 = x2171;
bool x2180 = true;
int32_t* x2181 = x4;
int32_t x2182 = x2181[x2179];
bool x2183 = 3 == x2182;
if (x2183) {
} else {
x2180 = false;
}
int32_t* x2187 = x8;
int32_t x2188 = x2187[x2179];
bool x2189 = x2153 == x2188;
if (x2189) {
} else {
x2180 = false;
}
int32_t* x2193 = x12;
int32_t x2194 = x2193[x2179];
bool x2195 = x2148 == x2194;
if (x2195) {
} else {
x2180 = false;
}
int32_t* x2199 = x16;
int32_t x2200 = x2199[x2179];
bool x2201 = x2150 == x2200;
if (x2201) {
} else {
x2180 = false;
}
bool x2205 = x2180;
if (x2205) {
x2154 = true;
x2172 = false;
} else {
}
int32_t* x2210 = x21;
int32_t x2211 = x2210[x2179];
x2171 = x2211;
}
bool x2215 = x2154;
bool x2216 = !x2215;
x2218 = x2216;
} else {
x2218 = false;
}
if (x2218) {
int32_t* x2219 = x107;
bool x2221 = true;
int32_t x2222 = 0;
x2222 = 236;
int32_t x2220 = x2219[x2138];
int32_t x2224 = 238124 + x2220;
int32_t x2225 = x2224 + 233;
x2222 = x2225;
int32_t x2227 = x2225 * 1009;
int32_t x2228 = x2227 + x2148;
int32_t x2229 = x2228 + 233;
x2222 = x2229;
int32_t x2231 = x2229 * 1009;
int32_t x2232 = x2231 + x2150;
int32_t x2233 = x2232 + 233;
x2222 = x2233;
int32_t* x2236 = x69;
int32_t x2235 = x2233 & 16383;
int32_t x2237 = x2236[x2235];
int32_t x2238 = x2237;
bool x2239 = true;
for (;;) {
bool x2240 = x2239;
bool x2244;
if (x2240) {
int32_t x2241 = x2238;
bool x2242 = x2241 != -1;
x2244 = x2242;
} else {
x2244 = false;
}
if (!x2244) break;
int32_t x2246 = x2238;
bool x2247 = true;
int32_t* x2248 = x45;
int32_t x2249 = x2248[x2246];
bool x2250 = 3 == x2249;
if (x2250) {
} else {
x2247 = false;
}
int32_t* x2254 = x49;
int32_t x2255 = x2254[x2246];
bool x2256 = x2220 == x2255;
if (x2256) {
} else {
x2247 = false;
}
int32_t* x2260 = x53;
int32_t x2261 = x2260[x2246];
bool x2262 = x2148 == x2261;
if (x2262) {
} else {
x2247 = false;
}
int32_t* x2266 = x57;
int32_t x2267 = x2266[x2246];
bool x2268 = x2150 == x2267;
if (x2268) {
} else {
x2247 = false;
}
bool x2272 = x2247;
if (x2272) {
bool x2273 = true;
if (x2250) {
} else {
x2273 = false;
}
if (x2256) {
} else {
x2273 = false;
}
if (x2262) {
} else {
x2273 = false;
}
if (x2268) {
} else {
x2273 = false;
}
bool x2286 = x2273;
if (x2286) {
x2221 = false;
} else {
}
bool x2290 = x2221;
x2239 = x2290;
} else {
}
int32_t* x2294 = x62;
int32_t x2295 = x2294[x2246];
x2238 = x2295;
}
bool x2299 = x2221;
if (x2299) {
int32_t x2302 = x59;
int32_t x2303 = x42;
bool x2304 = x2302 == x2303;
if (x2304) {
x42 *= 4;
int32_t x2306 = x42;
printf("buffer.resize %d\n",x2306);
} else {
}
int32_t* x2310 = x45;
x2310[x2302] = 3;
int32_t* x2312 = x49;
x2312[x2302] = x2220;
int32_t* x2314 = x53;
x2314[x2302] = x2148;
int32_t* x2316 = x57;
x2316[x2302] = x2150;
x59 += 1;
int32_t x2319 = x2302;
int32_t x2320 = 0;
x2320 = 236;
x2320 = x2225;
x2320 = x2229;
x2320 = x2233;
int32_t x2325 = x2237;
x2236[x2235] = x2302;
int32_t* x2327 = x62;
x2327[x2302] = x2237;
int32_t x2329 = 0;
x2329 = 236;
int32_t* x2332 = x71;
int32_t x2333 = x2332[x2331];
int32_t x2334 = x2333;
x2332[x2331] = x2302;
int32_t* x2336 = x66;
x2336[x2302] = x2333;
} else {
}
} else {
}
} else {
}
int32_t* x2344 = x124;
int32_t x2345 = x2344[x2138];
x2134 = x2345;
}
}
int32_t x2351 = x59;
bool x2352 = x2351 == 0;
if (x2352) {
x594 = false;
} else {
for(int x2356=0; x2356 < x2351; x2356++) {
int32_t* x2357 = x45;
int32_t* x2359 = x49;
int32_t* x2361 = x53;
int32_t* x2363 = x57;
bool x2365 = true;
int32_t x2366 = 0;
int32_t x2358 = x2357[x2356];
int32_t x2367 = x2358 + 233;
x2366 = x2367;
int32_t x2360 = x2359[x2356];
int32_t x2369 = x2367 * 1009;
int32_t x2370 = x2369 + x2360;
int32_t x2371 = x2370 + 233;
x2366 = x2371;
int32_t x2362 = x2361[x2356];
int32_t x2373 = x2371 * 1009;
int32_t x2374 = x2373 + x2362;
int32_t x2375 = x2374 + 233;
x2366 = x2375;
int32_t x2364 = x2363[x2356];
int32_t x2377 = x2375 * 1009;
int32_t x2378 = x2377 + x2364;
int32_t x2379 = x2378 + 233;
x2366 = x2379;
int32_t* x2382 = x28;
int32_t x2381 = x2379 & 4194303;
int32_t x2383 = x2382[x2381];
int32_t x2384 = x2383;
bool x2385 = true;
for (;;) {
bool x2386 = x2385;
bool x2390;
if (x2386) {
int32_t x2387 = x2384;
bool x2388 = x2387 != -1;
x2390 = x2388;
} else {
x2390 = false;
}
if (!x2390) break;
int32_t x2392 = x2384;
bool x2393 = true;
int32_t* x2394 = x4;
int32_t x2395 = x2394[x2392];
bool x2396 = x2358 == x2395;
if (x2396) {
} else {
x2393 = false;
}
int32_t* x2400 = x8;
int32_t x2401 = x2400[x2392];
bool x2402 = x2360 == x2401;
if (x2402) {
} else {
x2393 = false;
}
int32_t* x2406 = x12;
int32_t x2407 = x2406[x2392];
bool x2408 = x2362 == x2407;
if (x2408) {
} else {
x2393 = false;
}
int32_t* x2412 = x16;
int32_t x2413 = x2412[x2392];
bool x2414 = x2364 == x2413;
if (x2414) {
} else {
x2393 = false;
}
bool x2418 = x2393;
if (x2418) {
bool x2419 = true;
if (x2396) {
} else {
x2419 = false;
}
if (x2402) {
} else {
x2419 = false;
}
if (x2408) {
} else {
x2419 = false;
}
if (x2414) {
} else {
x2419 = false;
}
bool x2432 = x2419;
if (x2432) {
x2365 = false;
} else {
}
bool x2436 = x2365;
x2385 = x2436;
} else {
}
int32_t* x2440 = x21;
int32_t x2441 = x2440[x2392];
x2384 = x2441;
}
bool x2445 = x2365;
if (x2445) {
int32_t x2448 = x18;
int32_t x2449 = x1;
bool x2450 = x2448 == x2449;
if (x2450) {
x1 *= 4;
int32_t x2452 = x1;
printf("buffer.resize %d\n",x2452);
} else {
}
int32_t* x2456 = x4;
x2456[x2448] = x2358;
int32_t* x2458 = x8;
x2458[x2448] = x2360;
int32_t* x2460 = x12;
x2460[x2448] = x2362;
int32_t* x2462 = x16;
x2462[x2448] = x2364;
x18 += 1;
int32_t x2465 = x2448;
int32_t x2466 = 0;
x2466 = x2367;
x2466 = x2371;
x2466 = x2375;
x2466 = x2379;
int32_t x2471 = x2383;
x2382[x2381] = x2448;
int32_t* x2473 = x21;
x2473[x2448] = x2383;
int32_t x2475 = 0;
x2475 = x2367;
int32_t* x2478 = x30;
int32_t x2477 = x2367 & 4194303;
int32_t x2479 = x2478[x2477];
int32_t x2480 = x2479;
x2478[x2477] = x2448;
int32_t* x2482 = x25;
x2482[x2448] = x2479;
} else {
}

}
SWAP(x117,x59);
SWAP(x100,x42);
SWAP(x104,x46);
SWAP(x101,x43);
SWAP(x103,x45);
SWAP(x108,x50);
SWAP(x105,x47);
SWAP(x107,x49);
SWAP(x112,x54);
SWAP(x109,x51);
SWAP(x111,x53);
SWAP(x116,x58);
SWAP(x113,x55);
SWAP(x115,x57);
SWAP(x121,x63);
SWAP(x118,x60);
SWAP(x120,x62);
SWAP(x125,x67);
SWAP(x122,x64);
SWAP(x124,x66);
SWAP(x127,x69);
SWAP(x129,x71);
x59 = 0;
x63 = 0;
x67 = 0;
for(int x2513=0; x2513 < 16384; x2513++) {
int32_t* x2514 = x69;
x2514[x2513] = -1;

}
for(int x2518=0; x2518 < 16384; x2518++) {
int32_t* x2519 = x71;
x2519[x2518] = -1;

}
}
}
for(int x2527=0; x2527 < 16384; x2527++) {
int32_t* x2528 = x127;
x2528[x2527] = -1;

}
for(int x2532=0; x2532 < 16384; x2532++) {
int32_t* x2533 = x129;
x2533[x2532] = -1;

}
for(int x2537=0; x2537 < 16384; x2537++) {
int32_t* x2538 = x69;
x2538[x2537] = -1;

}
for(int x2542=0; x2542 < 16384; x2542++) {
int32_t* x2543 = x71;
x2543[x2542] = -1;

}
int32_t x2548 = x18;
FILE *x2547 = fopen("loop.out","w");
for(int x2550=0; x2550 < x2548; x2550++) {
int32_t* x2551 = x4;
int32_t x2552 = x2551[x2550];
int32_t x2553 = fprintf(x2547,"%d",x2552);
int32_t x2554 = fprintf(x2547,"\t");
int32_t* x2555 = x8;
int32_t x2556 = x2555[x2550];
int32_t x2557 = fprintf(x2547,"%d",x2556);
int32_t x2558 = fprintf(x2547,"\t");
int32_t* x2559 = x12;
int32_t x2560 = x2559[x2550];
int32_t x2561 = fprintf(x2547,"%d",x2560);
int32_t x2562 = fprintf(x2547,"\t");
int32_t* x2563 = x16;
int32_t x2564 = x2563[x2550];
int32_t x2565 = fprintf(x2547,"%d",x2564);
int32_t x2566 = fprintf(x2547,"\n");

}
fclose(x2547);
for(int x2570=0; x2570 < 4194304; x2570++) {
int32_t* x2571 = x94;
x2571[x2570] = -1;

}
for(int x2575=0; x2575 < 4194304; x2575++) {
int32_t* x2576 = x168;
x2576[x2575] = -1;

}
for(int x2580=0; x2580 < 4194304; x2580++) {
int32_t* x2581 = x151;
x2581[x2580] = -1;

}
for(int x2585=0; x2585 < 4194304; x2585++) {
int32_t* x2586 = x28;
x2586[x2585] = -1;

}
for(int x2590=0; x2590 < 4194304; x2590++) {
int32_t* x2591 = x30;
x2591[x2590] = -1;

}
}
/*****************************************
  End of C Generated Code                  
*******************************************/

