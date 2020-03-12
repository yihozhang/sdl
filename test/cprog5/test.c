
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
bool x306 = true;
int32_t x307 = 0;
x307 = 233;
x307 = 235330;
x307 = 237448203;
x307 = -932931516;
int32_t x312 = -932931516 & 4194303;
int32_t x313 = x27[x312];
int32_t x314 = x313;
bool x315 = true;
for (;;) {
bool x316 = x315;
bool x320;
if (x316) {
int32_t x317 = x314;
bool x318 = x317 != -1;
x320 = x318;
} else {
x320 = false;
}
if (!x320) break;
int32_t x322 = x314;
bool x323 = true;
int32_t* x324 = x4;
int32_t x325 = x324[x322];
bool x326 = 0 == x325;
if (x326) {
} else {
x323 = false;
}
int32_t* x330 = x8;
int32_t x331 = x330[x322];
bool x332 = 0 == x331;
if (x332) {
} else {
x323 = false;
}
int32_t* x336 = x12;
int32_t x337 = x336[x322];
bool x338 = 0 == x337;
if (x338) {
} else {
x323 = false;
}
int32_t* x342 = x16;
int32_t x343 = x342[x322];
bool x344 = 0 == x343;
if (x344) {
} else {
x323 = false;
}
bool x348 = x323;
if (x348) {
bool x349 = true;
if (x326) {
} else {
x349 = false;
}
if (x332) {
} else {
x349 = false;
}
if (x338) {
} else {
x349 = false;
}
if (x344) {
} else {
x349 = false;
}
bool x362 = x349;
if (x362) {
x306 = false;
} else {
}
bool x366 = x306;
x315 = x366;
} else {
}
int32_t* x370 = x21;
int32_t x371 = x370[x322];
x314 = x371;
}
bool x375 = x306;
int32_t x394 = 233 & 4194303;
if (x375) {
x3[0] = 0;
x7[0] = 0;
x11[0] = 0;
x15[0] = 0;
x18 += 1;
int32_t x383 = 0;
int32_t x384 = 0;
x384 = 233;
x384 = 235330;
x384 = 237448203;
x384 = -932931516;
int32_t x389 = x313;
x27[x312] = 0;
x20[0] = x313;
int32_t x392 = 0;
x392 = 233;
int32_t x395 = x29[x394];
int32_t x396 = x395;
x29[x394] = 0;
x24[0] = x395;
} else {
}
int32_t x401 = x18;
for(int x403=0; x403 < x401; x403++) {
int32_t* x404 = x4;
int32_t* x406 = x8;
int32_t* x408 = x12;
int32_t* x410 = x16;
bool x412 = true;
int32_t x413 = 0;
int32_t x405 = x404[x403];
int32_t x414 = x405 + 233;
x413 = x414;
int32_t x407 = x406[x403];
int32_t x416 = x414 * 1009;
int32_t x417 = x416 + x407;
int32_t x418 = x417 + 233;
x413 = x418;
int32_t x409 = x408[x403];
int32_t x420 = x418 * 1009;
int32_t x421 = x420 + x409;
int32_t x422 = x421 + 233;
x413 = x422;
int32_t x411 = x410[x403];
int32_t x424 = x422 * 1009;
int32_t x425 = x424 + x411;
int32_t x426 = x425 + 233;
x413 = x426;
int32_t* x429 = x127;
int32_t x428 = x426 & 16383;
int32_t x430 = x429[x428];
int32_t x431 = x430;
bool x432 = true;
for (;;) {
bool x433 = x432;
bool x437;
if (x433) {
int32_t x434 = x431;
bool x435 = x434 != -1;
x437 = x435;
} else {
x437 = false;
}
if (!x437) break;
int32_t x439 = x431;
bool x440 = true;
int32_t* x441 = x103;
int32_t x442 = x441[x439];
bool x443 = x405 == x442;
if (x443) {
} else {
x440 = false;
}
int32_t* x447 = x107;
int32_t x448 = x447[x439];
bool x449 = x407 == x448;
if (x449) {
} else {
x440 = false;
}
int32_t* x453 = x111;
int32_t x454 = x453[x439];
bool x455 = x409 == x454;
if (x455) {
} else {
x440 = false;
}
int32_t* x459 = x115;
int32_t x460 = x459[x439];
bool x461 = x411 == x460;
if (x461) {
} else {
x440 = false;
}
bool x465 = x440;
if (x465) {
bool x466 = true;
if (x443) {
} else {
x466 = false;
}
if (x449) {
} else {
x466 = false;
}
if (x455) {
} else {
x466 = false;
}
if (x461) {
} else {
x466 = false;
}
bool x479 = x466;
if (x479) {
x412 = false;
} else {
}
bool x483 = x412;
x432 = x483;
} else {
}
int32_t* x487 = x120;
int32_t x488 = x487[x439];
x431 = x488;
}
bool x492 = x412;
if (x492) {
int32_t x495 = x117;
int32_t x496 = x100;
bool x497 = x495 == x496;
if (x497) {
x100 *= 4;
int32_t x499 = x100;
printf("buffer.resize %d\n",x499);
} else {
}
int32_t* x503 = x103;
x503[x495] = x405;
int32_t* x505 = x107;
x505[x495] = x407;
int32_t* x507 = x111;
x507[x495] = x409;
int32_t* x509 = x115;
x509[x495] = x411;
x117 += 1;
int32_t x512 = x495;
int32_t x513 = 0;
x513 = x414;
x513 = x418;
x513 = x422;
x513 = x426;
int32_t x518 = x430;
x429[x428] = x495;
int32_t* x520 = x120;
x520[x495] = x430;
int32_t x522 = 0;
x522 = x414;
int32_t* x525 = x129;
int32_t x524 = x414 & 16383;
int32_t x526 = x525[x524];
int32_t x527 = x526;
x525[x524] = x495;
int32_t* x529 = x124;
x529[x495] = x526;
} else {
}

}
bool x535 = true;
int32_t x548 = 233 & 16383;
int32_t x738 = 234 & 16383;
int32_t x956 = 235 & 16383;
int32_t x1007 = 234 & 4194303;
int32_t x1266 = 236 & 16383;
int32_t x1737 = 240 & 16383;
int32_t x1951 = 237 & 16383;
for (;;) {
bool x536 = x535;
if (!x536) break;
int32_t x538 = x117;
bool x539 = x538 == 0;
bool x545;
if (x539) {
x545 = false;
} else {
int32_t x541 = x145;
bool x542 = x541 == 0;
bool x543 = !x542;
x545 = x543;
}
if (x545) {
int32_t x546 = 0;
x546 = 233;
int32_t* x549 = x129;
int32_t x550 = x549[x548];
int32_t x551 = x550;
for (;;) {
int32_t x552 = x551;
bool x553 = x552 != -1;
if (!x553) break;
int32_t x555 = x551;
bool x556 = true;
int32_t* x557 = x103;
int32_t x558 = x557[x555];
bool x559 = 0 == x558;
if (x559) {
} else {
x556 = false;
}
bool x563 = x556;
if (x563) {
int32_t x564 = x145;
for(int x566=0; x566 < x564; x566++) {
int32_t* x567 = x143;
int32_t* x569 = x111;
int32_t* x571 = x115;
bool x573 = false;
int32_t x574 = 0;
x574 = 234;
int32_t x568 = x567[x566];
int32_t x576 = 236106 + x568;
int32_t x577 = x576 + 233;
x574 = x577;
int32_t x570 = x569[x555];
int32_t x579 = x577 * 1009;
int32_t x580 = x579 + x570;
int32_t x581 = x580 + 233;
x574 = x581;
int32_t x572 = x571[x555];
int32_t x583 = x581 * 1009;
int32_t x584 = x583 + x572;
int32_t x585 = x584 + 233;
x574 = x585;
int32_t* x588 = x28;
int32_t x587 = x585 & 4194303;
int32_t x589 = x588[x587];
int32_t x590 = x589;
bool x591 = true;
for (;;) {
bool x592 = x591;
bool x596;
if (x592) {
int32_t x593 = x590;
bool x594 = x593 != -1;
x596 = x594;
} else {
x596 = false;
}
if (!x596) break;
int32_t x598 = x590;
bool x599 = true;
int32_t* x600 = x4;
int32_t x601 = x600[x598];
bool x602 = 1 == x601;
if (x602) {
} else {
x599 = false;
}
int32_t* x606 = x8;
int32_t x607 = x606[x598];
bool x608 = x568 == x607;
if (x608) {
} else {
x599 = false;
}
int32_t* x612 = x12;
int32_t x613 = x612[x598];
bool x614 = x570 == x613;
if (x614) {
} else {
x599 = false;
}
int32_t* x618 = x16;
int32_t x619 = x618[x598];
bool x620 = x572 == x619;
if (x620) {
} else {
x599 = false;
}
bool x624 = x599;
if (x624) {
x573 = true;
x591 = false;
} else {
}
int32_t* x629 = x21;
int32_t x630 = x629[x598];
x590 = x630;
}
bool x634 = x573;
if (x634) {
} else {
bool x636 = true;
int32_t x637 = 0;
x637 = 234;
x637 = x577;
x637 = x581;
x637 = x585;
int32_t* x643 = x69;
int32_t x642 = x585 & 16383;
int32_t x644 = x643[x642];
int32_t x645 = x644;
bool x646 = true;
for (;;) {
bool x647 = x646;
bool x651;
if (x647) {
int32_t x648 = x645;
bool x649 = x648 != -1;
x651 = x649;
} else {
x651 = false;
}
if (!x651) break;
int32_t x653 = x645;
bool x654 = true;
int32_t* x655 = x45;
int32_t x656 = x655[x653];
bool x657 = 1 == x656;
if (x657) {
} else {
x654 = false;
}
int32_t* x661 = x49;
int32_t x662 = x661[x653];
bool x663 = x568 == x662;
if (x663) {
} else {
x654 = false;
}
int32_t* x667 = x53;
int32_t x668 = x667[x653];
bool x669 = x570 == x668;
if (x669) {
} else {
x654 = false;
}
int32_t* x673 = x57;
int32_t x674 = x673[x653];
bool x675 = x572 == x674;
if (x675) {
} else {
x654 = false;
}
bool x679 = x654;
if (x679) {
bool x680 = true;
if (x657) {
} else {
x680 = false;
}
if (x663) {
} else {
x680 = false;
}
if (x669) {
} else {
x680 = false;
}
if (x675) {
} else {
x680 = false;
}
bool x693 = x680;
if (x693) {
x636 = false;
} else {
}
bool x697 = x636;
x646 = x697;
} else {
}
int32_t* x701 = x62;
int32_t x702 = x701[x653];
x645 = x702;
}
bool x706 = x636;
if (x706) {
int32_t x709 = x59;
int32_t x710 = x42;
bool x711 = x709 == x710;
if (x711) {
x42 *= 4;
int32_t x713 = x42;
printf("buffer.resize %d\n",x713);
} else {
}
int32_t* x717 = x45;
x717[x709] = 1;
int32_t* x719 = x49;
x719[x709] = x568;
int32_t* x721 = x53;
x721[x709] = x570;
int32_t* x723 = x57;
x723[x709] = x572;
x59 += 1;
int32_t x726 = x709;
int32_t x727 = 0;
x727 = 234;
x727 = x577;
x727 = x581;
x727 = x585;
int32_t x732 = x644;
x643[x642] = x709;
int32_t* x734 = x62;
x734[x709] = x644;
int32_t x736 = 0;
x736 = 234;
int32_t* x739 = x71;
int32_t x740 = x739[x738];
int32_t x741 = x740;
x739[x738] = x709;
int32_t* x743 = x66;
x743[x709] = x740;
} else {
}
}

}
} else {
}
int32_t* x753 = x124;
int32_t x754 = x753[x555];
x551 = x754;
}
} else {
}
bool x764;
if (x539) {
x764 = false;
} else {
int32_t x760 = x162;
bool x761 = x760 == 0;
bool x762 = !x761;
x764 = x762;
}
if (x764) {
int32_t x765 = 0;
x765 = 234;
int32_t* x767 = x129;
int32_t x768 = x767[x738];
int32_t x769 = x768;
for (;;) {
int32_t x770 = x769;
bool x771 = x770 != -1;
if (!x771) break;
int32_t x773 = x769;
bool x774 = true;
int32_t* x775 = x103;
int32_t x776 = x775[x773];
bool x777 = 1 == x776;
if (x777) {
} else {
x774 = false;
}
bool x781 = x774;
if (x781) {
int32_t x782 = x162;
for(int x784=0; x784 < x782; x784++) {
int32_t* x785 = x107;
int32_t* x787 = x111;
int32_t* x789 = x160;
bool x791 = false;
int32_t x792 = 0;
x792 = 235;
int32_t x786 = x785[x773];
int32_t x794 = 237115 + x786;
int32_t x795 = x794 + 233;
x792 = x795;
int32_t x788 = x787[x773];
int32_t x797 = x795 * 1009;
int32_t x798 = x797 + x788;
int32_t x799 = x798 + 233;
x792 = x799;
int32_t x790 = x789[x784];
int32_t x801 = x799 * 1009;
int32_t x802 = x801 + x790;
int32_t x803 = x802 + 233;
x792 = x803;
int32_t* x806 = x28;
int32_t x805 = x803 & 4194303;
int32_t x807 = x806[x805];
int32_t x808 = x807;
bool x809 = true;
for (;;) {
bool x810 = x809;
bool x814;
if (x810) {
int32_t x811 = x808;
bool x812 = x811 != -1;
x814 = x812;
} else {
x814 = false;
}
if (!x814) break;
int32_t x816 = x808;
bool x817 = true;
int32_t* x818 = x4;
int32_t x819 = x818[x816];
bool x820 = 2 == x819;
if (x820) {
} else {
x817 = false;
}
int32_t* x824 = x8;
int32_t x825 = x824[x816];
bool x826 = x786 == x825;
if (x826) {
} else {
x817 = false;
}
int32_t* x830 = x12;
int32_t x831 = x830[x816];
bool x832 = x788 == x831;
if (x832) {
} else {
x817 = false;
}
int32_t* x836 = x16;
int32_t x837 = x836[x816];
bool x838 = x790 == x837;
if (x838) {
} else {
x817 = false;
}
bool x842 = x817;
if (x842) {
x791 = true;
x809 = false;
} else {
}
int32_t* x847 = x21;
int32_t x848 = x847[x816];
x808 = x848;
}
bool x852 = x791;
if (x852) {
} else {
bool x854 = true;
int32_t x855 = 0;
x855 = 235;
x855 = x795;
x855 = x799;
x855 = x803;
int32_t* x861 = x69;
int32_t x860 = x803 & 16383;
int32_t x862 = x861[x860];
int32_t x863 = x862;
bool x864 = true;
for (;;) {
bool x865 = x864;
bool x869;
if (x865) {
int32_t x866 = x863;
bool x867 = x866 != -1;
x869 = x867;
} else {
x869 = false;
}
if (!x869) break;
int32_t x871 = x863;
bool x872 = true;
int32_t* x873 = x45;
int32_t x874 = x873[x871];
bool x875 = 2 == x874;
if (x875) {
} else {
x872 = false;
}
int32_t* x879 = x49;
int32_t x880 = x879[x871];
bool x881 = x786 == x880;
if (x881) {
} else {
x872 = false;
}
int32_t* x885 = x53;
int32_t x886 = x885[x871];
bool x887 = x788 == x886;
if (x887) {
} else {
x872 = false;
}
int32_t* x891 = x57;
int32_t x892 = x891[x871];
bool x893 = x790 == x892;
if (x893) {
} else {
x872 = false;
}
bool x897 = x872;
if (x897) {
bool x898 = true;
if (x875) {
} else {
x898 = false;
}
if (x881) {
} else {
x898 = false;
}
if (x887) {
} else {
x898 = false;
}
if (x893) {
} else {
x898 = false;
}
bool x911 = x898;
if (x911) {
x854 = false;
} else {
}
bool x915 = x854;
x864 = x915;
} else {
}
int32_t* x919 = x62;
int32_t x920 = x919[x871];
x863 = x920;
}
bool x924 = x854;
if (x924) {
int32_t x927 = x59;
int32_t x928 = x42;
bool x929 = x927 == x928;
if (x929) {
x42 *= 4;
int32_t x931 = x42;
printf("buffer.resize %d\n",x931);
} else {
}
int32_t* x935 = x45;
x935[x927] = 2;
int32_t* x937 = x49;
x937[x927] = x786;
int32_t* x939 = x53;
x939[x927] = x788;
int32_t* x941 = x57;
x941[x927] = x790;
x59 += 1;
int32_t x944 = x927;
int32_t x945 = 0;
x945 = 235;
x945 = x795;
x945 = x799;
x945 = x803;
int32_t x950 = x862;
x861[x860] = x927;
int32_t* x952 = x62;
x952[x927] = x862;
int32_t x954 = 0;
x954 = 235;
int32_t* x957 = x71;
int32_t x958 = x957[x956];
int32_t x959 = x958;
x957[x956] = x927;
int32_t* x961 = x66;
x961[x927] = x958;
} else {
}
}

}
} else {
}
int32_t* x971 = x124;
int32_t x972 = x971[x773];
x769 = x972;
}
} else {
}
bool x982;
if (x539) {
x982 = false;
} else {
int32_t x978 = x18;
bool x979 = x978 == 0;
bool x980 = !x979;
x982 = x980;
}
bool x987;
if (x982) {
int32_t x983 = x88;
bool x984 = x983 == 0;
bool x985 = !x984;
x987 = x985;
} else {
x987 = false;
}
if (x987) {
int32_t x988 = 0;
x988 = 233;
int32_t* x990 = x129;
int32_t x991 = x990[x548];
int32_t x992 = x991;
for (;;) {
int32_t x993 = x992;
bool x994 = x993 != -1;
if (!x994) break;
int32_t x996 = x992;
bool x997 = true;
int32_t* x998 = x103;
int32_t x999 = x998[x996];
bool x1000 = 0 == x999;
if (x1000) {
} else {
x997 = false;
}
bool x1004 = x997;
if (x1004) {
int32_t x1005 = 0;
x1005 = 234;
int32_t* x1008 = x30;
int32_t x1009 = x1008[x1007];
int32_t x1010 = x1009;
for (;;) {
int32_t x1011 = x1010;
bool x1012 = x1011 != -1;
if (!x1012) break;
int32_t x1014 = x1010;
bool x1015 = true;
int32_t* x1016 = x4;
int32_t x1017 = x1016[x1014];
bool x1018 = 1 == x1017;
if (x1018) {
} else {
x1015 = false;
}
bool x1022 = x1015;
if (x1022) {
int32_t* x1023 = x8;
int32_t* x1025 = x12;
int32_t* x1027 = x16;
bool x1029 = false;
int32_t x1030 = 0;
x1030 = 234;
int32_t x1024 = x1023[x1014];
int32_t x1032 = 236106 + x1024;
int32_t x1033 = x1032 + 233;
x1030 = x1033;
int32_t x1026 = x1025[x1014];
int32_t x1035 = x1033 * 1009;
int32_t x1036 = x1035 + x1026;
int32_t x1037 = x1036 + 233;
x1030 = x1037;
int32_t x1028 = x1027[x1014];
int32_t x1039 = x1037 * 1009;
int32_t x1040 = x1039 + x1028;
int32_t x1041 = x1040 + 233;
x1030 = x1041;
int32_t* x1044 = x127;
int32_t x1043 = x1041 & 16383;
int32_t x1045 = x1044[x1043];
int32_t x1046 = x1045;
bool x1047 = true;
for (;;) {
bool x1048 = x1047;
bool x1052;
if (x1048) {
int32_t x1049 = x1046;
bool x1050 = x1049 != -1;
x1052 = x1050;
} else {
x1052 = false;
}
if (!x1052) break;
int32_t x1054 = x1046;
bool x1055 = true;
int32_t* x1056 = x103;
int32_t x1057 = x1056[x1054];
bool x1058 = 1 == x1057;
if (x1058) {
} else {
x1055 = false;
}
int32_t* x1062 = x107;
int32_t x1063 = x1062[x1054];
bool x1064 = x1024 == x1063;
if (x1064) {
} else {
x1055 = false;
}
int32_t* x1068 = x111;
int32_t x1069 = x1068[x1054];
bool x1070 = x1026 == x1069;
if (x1070) {
} else {
x1055 = false;
}
int32_t* x1074 = x115;
int32_t x1075 = x1074[x1054];
bool x1076 = x1028 == x1075;
if (x1076) {
} else {
x1055 = false;
}
bool x1080 = x1055;
if (x1080) {
x1029 = true;
x1047 = false;
} else {
}
int32_t* x1085 = x120;
int32_t x1086 = x1085[x1054];
x1046 = x1086;
}
bool x1090 = x1029;
if (x1090) {
} else {
int32_t x1092 = x88;
for(int x1094=0; x1094 < x1092; x1094++) {
int32_t* x1095 = x8;
int32_t* x1097 = x86;
int32_t* x1099 = x115;
bool x1101 = false;
int32_t x1102 = 0;
x1102 = 236;
int32_t x1096 = x1095[x1014];
int32_t x1104 = 238124 + x1096;
int32_t x1105 = x1104 + 233;
x1102 = x1105;
int32_t x1098 = x1097[x1094];
int32_t x1107 = x1105 * 1009;
int32_t x1108 = x1107 + x1098;
int32_t x1109 = x1108 + 233;
x1102 = x1109;
int32_t x1100 = x1099[x996];
int32_t x1111 = x1109 * 1009;
int32_t x1112 = x1111 + x1100;
int32_t x1113 = x1112 + 233;
x1102 = x1113;
int32_t* x1116 = x28;
int32_t x1115 = x1113 & 4194303;
int32_t x1117 = x1116[x1115];
int32_t x1118 = x1117;
bool x1119 = true;
for (;;) {
bool x1120 = x1119;
bool x1124;
if (x1120) {
int32_t x1121 = x1118;
bool x1122 = x1121 != -1;
x1124 = x1122;
} else {
x1124 = false;
}
if (!x1124) break;
int32_t x1126 = x1118;
bool x1127 = true;
int32_t* x1128 = x4;
int32_t x1129 = x1128[x1126];
bool x1130 = 3 == x1129;
if (x1130) {
} else {
x1127 = false;
}
int32_t* x1134 = x8;
int32_t x1135 = x1134[x1126];
bool x1136 = x1096 == x1135;
if (x1136) {
} else {
x1127 = false;
}
int32_t* x1140 = x12;
int32_t x1141 = x1140[x1126];
bool x1142 = x1098 == x1141;
if (x1142) {
} else {
x1127 = false;
}
int32_t* x1146 = x16;
int32_t x1147 = x1146[x1126];
bool x1148 = x1100 == x1147;
if (x1148) {
} else {
x1127 = false;
}
bool x1152 = x1127;
if (x1152) {
x1101 = true;
x1119 = false;
} else {
}
int32_t* x1157 = x21;
int32_t x1158 = x1157[x1126];
x1118 = x1158;
}
bool x1162 = x1101;
if (x1162) {
} else {
bool x1164 = true;
int32_t x1165 = 0;
x1165 = 236;
x1165 = x1105;
x1165 = x1109;
x1165 = x1113;
int32_t* x1171 = x69;
int32_t x1170 = x1113 & 16383;
int32_t x1172 = x1171[x1170];
int32_t x1173 = x1172;
bool x1174 = true;
for (;;) {
bool x1175 = x1174;
bool x1179;
if (x1175) {
int32_t x1176 = x1173;
bool x1177 = x1176 != -1;
x1179 = x1177;
} else {
x1179 = false;
}
if (!x1179) break;
int32_t x1181 = x1173;
bool x1182 = true;
int32_t* x1183 = x45;
int32_t x1184 = x1183[x1181];
bool x1185 = 3 == x1184;
if (x1185) {
} else {
x1182 = false;
}
int32_t* x1189 = x49;
int32_t x1190 = x1189[x1181];
bool x1191 = x1096 == x1190;
if (x1191) {
} else {
x1182 = false;
}
int32_t* x1195 = x53;
int32_t x1196 = x1195[x1181];
bool x1197 = x1098 == x1196;
if (x1197) {
} else {
x1182 = false;
}
int32_t* x1201 = x57;
int32_t x1202 = x1201[x1181];
bool x1203 = x1100 == x1202;
if (x1203) {
} else {
x1182 = false;
}
bool x1207 = x1182;
if (x1207) {
bool x1208 = true;
if (x1185) {
} else {
x1208 = false;
}
if (x1191) {
} else {
x1208 = false;
}
if (x1197) {
} else {
x1208 = false;
}
if (x1203) {
} else {
x1208 = false;
}
bool x1221 = x1208;
if (x1221) {
x1164 = false;
} else {
}
bool x1225 = x1164;
x1174 = x1225;
} else {
}
int32_t* x1229 = x62;
int32_t x1230 = x1229[x1181];
x1173 = x1230;
}
bool x1234 = x1164;
if (x1234) {
int32_t x1237 = x59;
int32_t x1238 = x42;
bool x1239 = x1237 == x1238;
if (x1239) {
x42 *= 4;
int32_t x1241 = x42;
printf("buffer.resize %d\n",x1241);
} else {
}
int32_t* x1245 = x45;
x1245[x1237] = 3;
int32_t* x1247 = x49;
x1247[x1237] = x1096;
int32_t* x1249 = x53;
x1249[x1237] = x1098;
int32_t* x1251 = x57;
x1251[x1237] = x1100;
x59 += 1;
int32_t x1254 = x1237;
int32_t x1255 = 0;
x1255 = 236;
x1255 = x1105;
x1255 = x1109;
x1255 = x1113;
int32_t x1260 = x1172;
x1171[x1170] = x1237;
int32_t* x1262 = x62;
x1262[x1237] = x1172;
int32_t x1264 = 0;
x1264 = 236;
int32_t* x1267 = x71;
int32_t x1268 = x1267[x1266];
int32_t x1269 = x1268;
x1267[x1266] = x1237;
int32_t* x1271 = x66;
x1271[x1237] = x1268;
} else {
}
}

}
}
} else {
}
int32_t* x1283 = x25;
int32_t x1284 = x1283[x1014];
x1010 = x1284;
}
} else {
}
int32_t* x1290 = x124;
int32_t x1291 = x1290[x996];
x992 = x1291;
}
} else {
}
int32_t x1297 = x18;
bool x1298 = x1297 == 0;
bool x1300;
if (x1298) {
x1300 = false;
} else {
bool x540 = !x539;
x1300 = x540;
}
bool x1305;
if (x1300) {
int32_t x1301 = x88;
bool x1302 = x1301 == 0;
bool x1303 = !x1302;
x1305 = x1303;
} else {
x1305 = false;
}
if (x1305) {
int32_t x1306 = 0;
x1306 = 233;
int32_t* x1308 = x30;
int32_t x1309 = x1308[x394];
int32_t x1310 = x1309;
for (;;) {
int32_t x1311 = x1310;
bool x1312 = x1311 != -1;
if (!x1312) break;
int32_t x1314 = x1310;
bool x1315 = true;
int32_t* x1316 = x4;
int32_t x1317 = x1316[x1314];
bool x1318 = 0 == x1317;
if (x1318) {
} else {
x1315 = false;
}
bool x1322 = x1315;
if (x1322) {
int32_t x1323 = 0;
x1323 = 234;
int32_t* x1325 = x129;
int32_t x1326 = x1325[x738];
int32_t x1327 = x1326;
for (;;) {
int32_t x1328 = x1327;
bool x1329 = x1328 != -1;
if (!x1329) break;
int32_t x1331 = x1327;
bool x1332 = true;
int32_t* x1333 = x103;
int32_t x1334 = x1333[x1331];
bool x1335 = 1 == x1334;
if (x1335) {
} else {
x1332 = false;
}
bool x1339 = x1332;
if (x1339) {
int32_t x1340 = x88;
for(int x1342=0; x1342 < x1340; x1342++) {
int32_t* x1343 = x107;
int32_t* x1345 = x86;
int32_t* x1347 = x16;
bool x1349 = false;
int32_t x1350 = 0;
x1350 = 236;
int32_t x1344 = x1343[x1331];
int32_t x1352 = 238124 + x1344;
int32_t x1353 = x1352 + 233;
x1350 = x1353;
int32_t x1346 = x1345[x1342];
int32_t x1355 = x1353 * 1009;
int32_t x1356 = x1355 + x1346;
int32_t x1357 = x1356 + 233;
x1350 = x1357;
int32_t x1348 = x1347[x1314];
int32_t x1359 = x1357 * 1009;
int32_t x1360 = x1359 + x1348;
int32_t x1361 = x1360 + 233;
x1350 = x1361;
int32_t* x1364 = x28;
int32_t x1363 = x1361 & 4194303;
int32_t x1365 = x1364[x1363];
int32_t x1366 = x1365;
bool x1367 = true;
for (;;) {
bool x1368 = x1367;
bool x1372;
if (x1368) {
int32_t x1369 = x1366;
bool x1370 = x1369 != -1;
x1372 = x1370;
} else {
x1372 = false;
}
if (!x1372) break;
int32_t x1374 = x1366;
bool x1375 = true;
int32_t* x1376 = x4;
int32_t x1377 = x1376[x1374];
bool x1378 = 3 == x1377;
if (x1378) {
} else {
x1375 = false;
}
int32_t* x1382 = x8;
int32_t x1383 = x1382[x1374];
bool x1384 = x1344 == x1383;
if (x1384) {
} else {
x1375 = false;
}
int32_t* x1388 = x12;
int32_t x1389 = x1388[x1374];
bool x1390 = x1346 == x1389;
if (x1390) {
} else {
x1375 = false;
}
int32_t* x1394 = x16;
int32_t x1395 = x1394[x1374];
bool x1396 = x1348 == x1395;
if (x1396) {
} else {
x1375 = false;
}
bool x1400 = x1375;
if (x1400) {
x1349 = true;
x1367 = false;
} else {
}
int32_t* x1405 = x21;
int32_t x1406 = x1405[x1374];
x1366 = x1406;
}
bool x1410 = x1349;
if (x1410) {
} else {
bool x1412 = true;
int32_t x1413 = 0;
x1413 = 236;
x1413 = x1353;
x1413 = x1357;
x1413 = x1361;
int32_t* x1419 = x69;
int32_t x1418 = x1361 & 16383;
int32_t x1420 = x1419[x1418];
int32_t x1421 = x1420;
bool x1422 = true;
for (;;) {
bool x1423 = x1422;
bool x1427;
if (x1423) {
int32_t x1424 = x1421;
bool x1425 = x1424 != -1;
x1427 = x1425;
} else {
x1427 = false;
}
if (!x1427) break;
int32_t x1429 = x1421;
bool x1430 = true;
int32_t* x1431 = x45;
int32_t x1432 = x1431[x1429];
bool x1433 = 3 == x1432;
if (x1433) {
} else {
x1430 = false;
}
int32_t* x1437 = x49;
int32_t x1438 = x1437[x1429];
bool x1439 = x1344 == x1438;
if (x1439) {
} else {
x1430 = false;
}
int32_t* x1443 = x53;
int32_t x1444 = x1443[x1429];
bool x1445 = x1346 == x1444;
if (x1445) {
} else {
x1430 = false;
}
int32_t* x1449 = x57;
int32_t x1450 = x1449[x1429];
bool x1451 = x1348 == x1450;
if (x1451) {
} else {
x1430 = false;
}
bool x1455 = x1430;
if (x1455) {
bool x1456 = true;
if (x1433) {
} else {
x1456 = false;
}
if (x1439) {
} else {
x1456 = false;
}
if (x1445) {
} else {
x1456 = false;
}
if (x1451) {
} else {
x1456 = false;
}
bool x1469 = x1456;
if (x1469) {
x1412 = false;
} else {
}
bool x1473 = x1412;
x1422 = x1473;
} else {
}
int32_t* x1477 = x62;
int32_t x1478 = x1477[x1429];
x1421 = x1478;
}
bool x1482 = x1412;
if (x1482) {
int32_t x1485 = x59;
int32_t x1486 = x42;
bool x1487 = x1485 == x1486;
if (x1487) {
x42 *= 4;
int32_t x1489 = x42;
printf("buffer.resize %d\n",x1489);
} else {
}
int32_t* x1493 = x45;
x1493[x1485] = 3;
int32_t* x1495 = x49;
x1495[x1485] = x1344;
int32_t* x1497 = x53;
x1497[x1485] = x1346;
int32_t* x1499 = x57;
x1499[x1485] = x1348;
x59 += 1;
int32_t x1502 = x1485;
int32_t x1503 = 0;
x1503 = 236;
x1503 = x1353;
x1503 = x1357;
x1503 = x1361;
int32_t x1508 = x1420;
x1419[x1418] = x1485;
int32_t* x1510 = x62;
x1510[x1485] = x1420;
int32_t x1512 = 0;
x1512 = 236;
int32_t* x1514 = x71;
int32_t x1515 = x1514[x1266];
int32_t x1516 = x1515;
x1514[x1266] = x1485;
int32_t* x1518 = x66;
x1518[x1485] = x1515;
} else {
}
}

}
} else {
}
int32_t* x1528 = x124;
int32_t x1529 = x1528[x1331];
x1327 = x1529;
}
} else {
}
int32_t* x1535 = x25;
int32_t x1536 = x1535[x1314];
x1310 = x1536;
}
} else {
}
if (x539) {
} else {
int32_t x1542 = 0;
x1542 = 236;
int32_t* x1544 = x129;
int32_t x1545 = x1544[x1266];
int32_t x1546 = x1545;
for (;;) {
int32_t x1547 = x1546;
bool x1548 = x1547 != -1;
if (!x1548) break;
int32_t x1550 = x1546;
bool x1551 = true;
int32_t* x1552 = x103;
int32_t x1553 = x1552[x1550];
bool x1554 = 3 == x1553;
if (x1554) {
} else {
x1551 = false;
}
bool x1558 = x1551;
if (x1558) {
int32_t* x1559 = x107;
int32_t* x1561 = x111;
int32_t x1560 = x1559[x1550];
int32_t x1562 = x1561[x1550];
bool x1563 = x1560 <= x1562;
bool x1630;
if (x1563) {
int32_t* x1564 = x115;
bool x1566 = false;
int32_t x1567 = 0;
x1567 = 240;
int32_t x1569 = 242160 + x1560;
int32_t x1570 = x1569 + 233;
x1567 = x1570;
int32_t x1572 = x1570 * 1009;
int32_t x1573 = x1572 + x1562;
int32_t x1574 = x1573 + 233;
x1567 = x1574;
int32_t x1565 = x1564[x1550];
int32_t x1576 = x1574 * 1009;
int32_t x1577 = x1576 + x1565;
int32_t x1578 = x1577 + 233;
x1567 = x1578;
int32_t* x1581 = x28;
int32_t x1580 = x1578 & 4194303;
int32_t x1582 = x1581[x1580];
int32_t x1583 = x1582;
bool x1584 = true;
for (;;) {
bool x1585 = x1584;
bool x1589;
if (x1585) {
int32_t x1586 = x1583;
bool x1587 = x1586 != -1;
x1589 = x1587;
} else {
x1589 = false;
}
if (!x1589) break;
int32_t x1591 = x1583;
bool x1592 = true;
int32_t* x1593 = x4;
int32_t x1594 = x1593[x1591];
bool x1595 = 7 == x1594;
if (x1595) {
} else {
x1592 = false;
}
int32_t* x1599 = x8;
int32_t x1600 = x1599[x1591];
bool x1601 = x1560 == x1600;
if (x1601) {
} else {
x1592 = false;
}
int32_t* x1605 = x12;
int32_t x1606 = x1605[x1591];
bool x1607 = x1562 == x1606;
if (x1607) {
} else {
x1592 = false;
}
int32_t* x1611 = x16;
int32_t x1612 = x1611[x1591];
bool x1613 = x1565 == x1612;
if (x1613) {
} else {
x1592 = false;
}
bool x1617 = x1592;
if (x1617) {
x1566 = true;
x1584 = false;
} else {
}
int32_t* x1622 = x21;
int32_t x1623 = x1622[x1591];
x1583 = x1623;
}
bool x1627 = x1566;
bool x1628 = !x1627;
x1630 = x1628;
} else {
x1630 = false;
}
if (x1630) {
int32_t* x1631 = x115;
bool x1633 = true;
int32_t x1634 = 0;
x1634 = 240;
int32_t x1569 = 242160 + x1560;
int32_t x1570 = x1569 + 233;
x1634 = x1570;
int32_t x1572 = x1570 * 1009;
int32_t x1573 = x1572 + x1562;
int32_t x1574 = x1573 + 233;
x1634 = x1574;
int32_t x1576 = x1574 * 1009;
int32_t x1632 = x1631[x1550];
int32_t x1638 = x1576 + x1632;
int32_t x1639 = x1638 + 233;
x1634 = x1639;
int32_t* x1642 = x69;
int32_t x1641 = x1639 & 16383;
int32_t x1643 = x1642[x1641];
int32_t x1644 = x1643;
bool x1645 = true;
for (;;) {
bool x1646 = x1645;
bool x1650;
if (x1646) {
int32_t x1647 = x1644;
bool x1648 = x1647 != -1;
x1650 = x1648;
} else {
x1650 = false;
}
if (!x1650) break;
int32_t x1652 = x1644;
bool x1653 = true;
int32_t* x1654 = x45;
int32_t x1655 = x1654[x1652];
bool x1656 = 7 == x1655;
if (x1656) {
} else {
x1653 = false;
}
int32_t* x1660 = x49;
int32_t x1661 = x1660[x1652];
bool x1662 = x1560 == x1661;
if (x1662) {
} else {
x1653 = false;
}
int32_t* x1666 = x53;
int32_t x1667 = x1666[x1652];
bool x1668 = x1562 == x1667;
if (x1668) {
} else {
x1653 = false;
}
int32_t* x1672 = x57;
int32_t x1673 = x1672[x1652];
bool x1674 = x1632 == x1673;
if (x1674) {
} else {
x1653 = false;
}
bool x1678 = x1653;
if (x1678) {
bool x1679 = true;
if (x1656) {
} else {
x1679 = false;
}
if (x1662) {
} else {
x1679 = false;
}
if (x1668) {
} else {
x1679 = false;
}
if (x1674) {
} else {
x1679 = false;
}
bool x1692 = x1679;
if (x1692) {
x1633 = false;
} else {
}
bool x1696 = x1633;
x1645 = x1696;
} else {
}
int32_t* x1700 = x62;
int32_t x1701 = x1700[x1652];
x1644 = x1701;
}
bool x1705 = x1633;
if (x1705) {
int32_t x1708 = x59;
int32_t x1709 = x42;
bool x1710 = x1708 == x1709;
if (x1710) {
x42 *= 4;
int32_t x1712 = x42;
printf("buffer.resize %d\n",x1712);
} else {
}
int32_t* x1716 = x45;
x1716[x1708] = 7;
int32_t* x1718 = x49;
x1718[x1708] = x1560;
int32_t* x1720 = x53;
x1720[x1708] = x1562;
int32_t* x1722 = x57;
x1722[x1708] = x1632;
x59 += 1;
int32_t x1725 = x1708;
int32_t x1726 = 0;
x1726 = 240;
x1726 = x1570;
x1726 = x1574;
x1726 = x1639;
int32_t x1731 = x1643;
x1642[x1641] = x1708;
int32_t* x1733 = x62;
x1733[x1708] = x1643;
int32_t x1735 = 0;
x1735 = 240;
int32_t* x1738 = x71;
int32_t x1739 = x1738[x1737];
int32_t x1740 = x1739;
x1738[x1737] = x1708;
int32_t* x1742 = x66;
x1742[x1708] = x1739;
} else {
}
} else {
}
} else {
}
int32_t* x1750 = x124;
int32_t x1751 = x1750[x1550];
x1546 = x1751;
}
}
if (x539) {
} else {
int32_t x1757 = 0;
x1757 = 236;
int32_t* x1759 = x129;
int32_t x1760 = x1759[x1266];
int32_t x1761 = x1760;
for (;;) {
int32_t x1762 = x1761;
bool x1763 = x1762 != -1;
if (!x1763) break;
int32_t x1765 = x1761;
bool x1766 = true;
int32_t* x1767 = x103;
int32_t x1768 = x1767[x1765];
bool x1769 = 3 == x1768;
if (x1769) {
} else {
x1766 = false;
}
bool x1773 = x1766;
if (x1773) {
int32_t* x1774 = x107;
int32_t* x1776 = x111;
int32_t x1775 = x1774[x1765];
int32_t x1777 = x1776[x1765];
bool x1778 = x1775 > x1777;
bool x1844;
if (x1778) {
int32_t* x1779 = x115;
bool x1781 = false;
int32_t x1782 = 0;
x1782 = 237;
int32_t x1784 = 239133 + x1775;
int32_t x1785 = x1784 + 233;
x1782 = x1785;
int32_t x1787 = x1785 * 1009;
int32_t x1788 = x1787 + 233;
x1782 = x1788;
int32_t x1780 = x1779[x1765];
int32_t x1790 = x1788 * 1009;
int32_t x1791 = x1790 + x1780;
int32_t x1792 = x1791 + 233;
x1782 = x1792;
int32_t* x1795 = x28;
int32_t x1794 = x1792 & 4194303;
int32_t x1796 = x1795[x1794];
int32_t x1797 = x1796;
bool x1798 = true;
for (;;) {
bool x1799 = x1798;
bool x1803;
if (x1799) {
int32_t x1800 = x1797;
bool x1801 = x1800 != -1;
x1803 = x1801;
} else {
x1803 = false;
}
if (!x1803) break;
int32_t x1805 = x1797;
bool x1806 = true;
int32_t* x1807 = x4;
int32_t x1808 = x1807[x1805];
bool x1809 = 4 == x1808;
if (x1809) {
} else {
x1806 = false;
}
int32_t* x1813 = x8;
int32_t x1814 = x1813[x1805];
bool x1815 = x1775 == x1814;
if (x1815) {
} else {
x1806 = false;
}
int32_t* x1819 = x12;
int32_t x1820 = x1819[x1805];
bool x1821 = 0 == x1820;
if (x1821) {
} else {
x1806 = false;
}
int32_t* x1825 = x16;
int32_t x1826 = x1825[x1805];
bool x1827 = x1780 == x1826;
if (x1827) {
} else {
x1806 = false;
}
bool x1831 = x1806;
if (x1831) {
x1781 = true;
x1798 = false;
} else {
}
int32_t* x1836 = x21;
int32_t x1837 = x1836[x1805];
x1797 = x1837;
}
bool x1841 = x1781;
bool x1842 = !x1841;
x1844 = x1842;
} else {
x1844 = false;
}
if (x1844) {
int32_t* x1845 = x115;
bool x1847 = true;
int32_t x1848 = 0;
x1848 = 237;
int32_t x1784 = 239133 + x1775;
int32_t x1785 = x1784 + 233;
x1848 = x1785;
int32_t x1787 = x1785 * 1009;
int32_t x1788 = x1787 + 233;
x1848 = x1788;
int32_t x1790 = x1788 * 1009;
int32_t x1846 = x1845[x1765];
int32_t x1852 = x1790 + x1846;
int32_t x1853 = x1852 + 233;
x1848 = x1853;
int32_t* x1856 = x69;
int32_t x1855 = x1853 & 16383;
int32_t x1857 = x1856[x1855];
int32_t x1858 = x1857;
bool x1859 = true;
for (;;) {
bool x1860 = x1859;
bool x1864;
if (x1860) {
int32_t x1861 = x1858;
bool x1862 = x1861 != -1;
x1864 = x1862;
} else {
x1864 = false;
}
if (!x1864) break;
int32_t x1866 = x1858;
bool x1867 = true;
int32_t* x1868 = x45;
int32_t x1869 = x1868[x1866];
bool x1870 = 4 == x1869;
if (x1870) {
} else {
x1867 = false;
}
int32_t* x1874 = x49;
int32_t x1875 = x1874[x1866];
bool x1876 = x1775 == x1875;
if (x1876) {
} else {
x1867 = false;
}
int32_t* x1880 = x53;
int32_t x1881 = x1880[x1866];
bool x1882 = 0 == x1881;
if (x1882) {
} else {
x1867 = false;
}
int32_t* x1886 = x57;
int32_t x1887 = x1886[x1866];
bool x1888 = x1846 == x1887;
if (x1888) {
} else {
x1867 = false;
}
bool x1892 = x1867;
if (x1892) {
bool x1893 = true;
if (x1870) {
} else {
x1893 = false;
}
if (x1876) {
} else {
x1893 = false;
}
if (x1882) {
} else {
x1893 = false;
}
if (x1888) {
} else {
x1893 = false;
}
bool x1906 = x1893;
if (x1906) {
x1847 = false;
} else {
}
bool x1910 = x1847;
x1859 = x1910;
} else {
}
int32_t* x1914 = x62;
int32_t x1915 = x1914[x1866];
x1858 = x1915;
}
bool x1919 = x1847;
if (x1919) {
int32_t x1922 = x59;
int32_t x1923 = x42;
bool x1924 = x1922 == x1923;
if (x1924) {
x42 *= 4;
int32_t x1926 = x42;
printf("buffer.resize %d\n",x1926);
} else {
}
int32_t* x1930 = x45;
x1930[x1922] = 4;
int32_t* x1932 = x49;
x1932[x1922] = x1775;
int32_t* x1934 = x53;
x1934[x1922] = 0;
int32_t* x1936 = x57;
x1936[x1922] = x1846;
x59 += 1;
int32_t x1939 = x1922;
int32_t x1940 = 0;
x1940 = 237;
x1940 = x1785;
x1940 = x1788;
x1940 = x1853;
int32_t x1945 = x1857;
x1856[x1855] = x1922;
int32_t* x1947 = x62;
x1947[x1922] = x1857;
int32_t x1949 = 0;
x1949 = 237;
int32_t* x1952 = x71;
int32_t x1953 = x1952[x1951];
int32_t x1954 = x1953;
x1952[x1951] = x1922;
int32_t* x1956 = x66;
x1956[x1922] = x1953;
} else {
}
} else {
}
} else {
}
int32_t* x1964 = x124;
int32_t x1965 = x1964[x1765];
x1761 = x1965;
}
}
if (x539) {
} else {
int32_t x1971 = 0;
x1971 = 237;
int32_t* x1973 = x129;
int32_t x1974 = x1973[x1951];
int32_t x1975 = x1974;
for (;;) {
int32_t x1976 = x1975;
bool x1977 = x1976 != -1;
if (!x1977) break;
int32_t x1979 = x1975;
bool x1980 = true;
int32_t* x1981 = x103;
int32_t x1982 = x1981[x1979];
bool x1983 = 4 == x1982;
if (x1983) {
} else {
x1980 = false;
}
bool x1987 = x1980;
if (x1987) {
int32_t* x1988 = x115;
int32_t* x1990 = x111;
int32_t x1989 = x1988[x1979];
int32_t x1991 = x1990[x1979];
bool x1992 = x1989 > x1991;
bool x2060;
if (x1992) {
int32_t* x1993 = x107;
bool x1996 = false;
int32_t x1997 = 0;
x1997 = 237;
int32_t x1994 = x1993[x1979];
int32_t x1999 = 239133 + x1994;
int32_t x2000 = x1999 + 233;
x1997 = x2000;
int32_t x1995 = x1991 + 1;
int32_t x2002 = x2000 * 1009;
int32_t x2003 = x2002 + x1995;
int32_t x2004 = x2003 + 233;
x1997 = x2004;
int32_t x2006 = x2004 * 1009;
int32_t x2007 = x2006 + x1989;
int32_t x2008 = x2007 + 233;
x1997 = x2008;
int32_t* x2011 = x28;
int32_t x2010 = x2008 & 4194303;
int32_t x2012 = x2011[x2010];
int32_t x2013 = x2012;
bool x2014 = true;
for (;;) {
bool x2015 = x2014;
bool x2019;
if (x2015) {
int32_t x2016 = x2013;
bool x2017 = x2016 != -1;
x2019 = x2017;
} else {
x2019 = false;
}
if (!x2019) break;
int32_t x2021 = x2013;
bool x2022 = true;
int32_t* x2023 = x4;
int32_t x2024 = x2023[x2021];
bool x2025 = 4 == x2024;
if (x2025) {
} else {
x2022 = false;
}
int32_t* x2029 = x8;
int32_t x2030 = x2029[x2021];
bool x2031 = x1994 == x2030;
if (x2031) {
} else {
x2022 = false;
}
int32_t* x2035 = x12;
int32_t x2036 = x2035[x2021];
bool x2037 = x1995 == x2036;
if (x2037) {
} else {
x2022 = false;
}
int32_t* x2041 = x16;
int32_t x2042 = x2041[x2021];
bool x2043 = x1989 == x2042;
if (x2043) {
} else {
x2022 = false;
}
bool x2047 = x2022;
if (x2047) {
x1996 = true;
x2014 = false;
} else {
}
int32_t* x2052 = x21;
int32_t x2053 = x2052[x2021];
x2013 = x2053;
}
bool x2057 = x1996;
bool x2058 = !x2057;
x2060 = x2058;
} else {
x2060 = false;
}
if (x2060) {
int32_t* x2061 = x107;
bool x2063 = true;
int32_t x2064 = 0;
x2064 = 237;
int32_t x2062 = x2061[x1979];
int32_t x2066 = 239133 + x2062;
int32_t x2067 = x2066 + 233;
x2064 = x2067;
int32_t x1995 = x1991 + 1;
int32_t x2069 = x2067 * 1009;
int32_t x2070 = x2069 + x1995;
int32_t x2071 = x2070 + 233;
x2064 = x2071;
int32_t x2073 = x2071 * 1009;
int32_t x2074 = x2073 + x1989;
int32_t x2075 = x2074 + 233;
x2064 = x2075;
int32_t* x2078 = x69;
int32_t x2077 = x2075 & 16383;
int32_t x2079 = x2078[x2077];
int32_t x2080 = x2079;
bool x2081 = true;
for (;;) {
bool x2082 = x2081;
bool x2086;
if (x2082) {
int32_t x2083 = x2080;
bool x2084 = x2083 != -1;
x2086 = x2084;
} else {
x2086 = false;
}
if (!x2086) break;
int32_t x2088 = x2080;
bool x2089 = true;
int32_t* x2090 = x45;
int32_t x2091 = x2090[x2088];
bool x2092 = 4 == x2091;
if (x2092) {
} else {
x2089 = false;
}
int32_t* x2096 = x49;
int32_t x2097 = x2096[x2088];
bool x2098 = x2062 == x2097;
if (x2098) {
} else {
x2089 = false;
}
int32_t* x2102 = x53;
int32_t x2103 = x2102[x2088];
bool x2104 = x1995 == x2103;
if (x2104) {
} else {
x2089 = false;
}
int32_t* x2108 = x57;
int32_t x2109 = x2108[x2088];
bool x2110 = x1989 == x2109;
if (x2110) {
} else {
x2089 = false;
}
bool x2114 = x2089;
if (x2114) {
bool x2115 = true;
if (x2092) {
} else {
x2115 = false;
}
if (x2098) {
} else {
x2115 = false;
}
if (x2104) {
} else {
x2115 = false;
}
if (x2110) {
} else {
x2115 = false;
}
bool x2128 = x2115;
if (x2128) {
x2063 = false;
} else {
}
bool x2132 = x2063;
x2081 = x2132;
} else {
}
int32_t* x2136 = x62;
int32_t x2137 = x2136[x2088];
x2080 = x2137;
}
bool x2141 = x2063;
if (x2141) {
int32_t x2144 = x59;
int32_t x2145 = x42;
bool x2146 = x2144 == x2145;
if (x2146) {
x42 *= 4;
int32_t x2148 = x42;
printf("buffer.resize %d\n",x2148);
} else {
}
int32_t* x2152 = x45;
x2152[x2144] = 4;
int32_t* x2154 = x49;
x2154[x2144] = x2062;
int32_t* x2156 = x53;
x2156[x2144] = x1995;
int32_t* x2158 = x57;
x2158[x2144] = x1989;
x59 += 1;
int32_t x2161 = x2144;
int32_t x2162 = 0;
x2162 = 237;
x2162 = x2067;
x2162 = x2071;
x2162 = x2075;
int32_t x2167 = x2079;
x2078[x2077] = x2144;
int32_t* x2169 = x62;
x2169[x2144] = x2079;
int32_t x2171 = 0;
x2171 = 237;
int32_t* x2173 = x71;
int32_t x2174 = x2173[x1951];
int32_t x2175 = x2174;
x2173[x1951] = x2144;
int32_t* x2177 = x66;
x2177[x2144] = x2174;
} else {
}
} else {
}
} else {
}
int32_t* x2185 = x124;
int32_t x2186 = x2185[x1979];
x1975 = x2186;
}
}
if (x539) {
} else {
int32_t x2192 = 0;
x2192 = 237;
int32_t* x2194 = x129;
int32_t x2195 = x2194[x1951];
int32_t x2196 = x2195;
for (;;) {
int32_t x2197 = x2196;
bool x2198 = x2197 != -1;
if (!x2198) break;
int32_t x2200 = x2196;
bool x2201 = true;
int32_t* x2202 = x103;
int32_t x2203 = x2202[x2200];
bool x2204 = 4 == x2203;
if (x2204) {
} else {
x2201 = false;
}
bool x2208 = x2201;
if (x2208) {
int32_t* x2209 = x115;
int32_t* x2211 = x111;
int32_t x2210 = x2209[x2200];
int32_t x2212 = x2211[x2200];
bool x2213 = x2210 <= x2212;
bool x2281;
if (x2213) {
int32_t* x2214 = x107;
bool x2217 = false;
int32_t x2218 = 0;
x2218 = 236;
int32_t x2215 = x2214[x2200];
int32_t x2220 = 238124 + x2215;
int32_t x2221 = x2220 + 233;
x2218 = x2221;
int32_t x2223 = x2221 * 1009;
int32_t x2224 = x2223 + x2212;
int32_t x2225 = x2224 + 233;
x2218 = x2225;
int32_t x2216 = x2210 + 1;
int32_t x2227 = x2225 * 1009;
int32_t x2228 = x2227 + x2216;
int32_t x2229 = x2228 + 233;
x2218 = x2229;
int32_t* x2232 = x28;
int32_t x2231 = x2229 & 4194303;
int32_t x2233 = x2232[x2231];
int32_t x2234 = x2233;
bool x2235 = true;
for (;;) {
bool x2236 = x2235;
bool x2240;
if (x2236) {
int32_t x2237 = x2234;
bool x2238 = x2237 != -1;
x2240 = x2238;
} else {
x2240 = false;
}
if (!x2240) break;
int32_t x2242 = x2234;
bool x2243 = true;
int32_t* x2244 = x4;
int32_t x2245 = x2244[x2242];
bool x2246 = 3 == x2245;
if (x2246) {
} else {
x2243 = false;
}
int32_t* x2250 = x8;
int32_t x2251 = x2250[x2242];
bool x2252 = x2215 == x2251;
if (x2252) {
} else {
x2243 = false;
}
int32_t* x2256 = x12;
int32_t x2257 = x2256[x2242];
bool x2258 = x2212 == x2257;
if (x2258) {
} else {
x2243 = false;
}
int32_t* x2262 = x16;
int32_t x2263 = x2262[x2242];
bool x2264 = x2216 == x2263;
if (x2264) {
} else {
x2243 = false;
}
bool x2268 = x2243;
if (x2268) {
x2217 = true;
x2235 = false;
} else {
}
int32_t* x2273 = x21;
int32_t x2274 = x2273[x2242];
x2234 = x2274;
}
bool x2278 = x2217;
bool x2279 = !x2278;
x2281 = x2279;
} else {
x2281 = false;
}
if (x2281) {
int32_t* x2282 = x107;
bool x2284 = true;
int32_t x2285 = 0;
x2285 = 236;
int32_t x2283 = x2282[x2200];
int32_t x2287 = 238124 + x2283;
int32_t x2288 = x2287 + 233;
x2285 = x2288;
int32_t x2290 = x2288 * 1009;
int32_t x2291 = x2290 + x2212;
int32_t x2292 = x2291 + 233;
x2285 = x2292;
int32_t x2216 = x2210 + 1;
int32_t x2294 = x2292 * 1009;
int32_t x2295 = x2294 + x2216;
int32_t x2296 = x2295 + 233;
x2285 = x2296;
int32_t* x2299 = x69;
int32_t x2298 = x2296 & 16383;
int32_t x2300 = x2299[x2298];
int32_t x2301 = x2300;
bool x2302 = true;
for (;;) {
bool x2303 = x2302;
bool x2307;
if (x2303) {
int32_t x2304 = x2301;
bool x2305 = x2304 != -1;
x2307 = x2305;
} else {
x2307 = false;
}
if (!x2307) break;
int32_t x2309 = x2301;
bool x2310 = true;
int32_t* x2311 = x45;
int32_t x2312 = x2311[x2309];
bool x2313 = 3 == x2312;
if (x2313) {
} else {
x2310 = false;
}
int32_t* x2317 = x49;
int32_t x2318 = x2317[x2309];
bool x2319 = x2283 == x2318;
if (x2319) {
} else {
x2310 = false;
}
int32_t* x2323 = x53;
int32_t x2324 = x2323[x2309];
bool x2325 = x2212 == x2324;
if (x2325) {
} else {
x2310 = false;
}
int32_t* x2329 = x57;
int32_t x2330 = x2329[x2309];
bool x2331 = x2216 == x2330;
if (x2331) {
} else {
x2310 = false;
}
bool x2335 = x2310;
if (x2335) {
bool x2336 = true;
if (x2313) {
} else {
x2336 = false;
}
if (x2319) {
} else {
x2336 = false;
}
if (x2325) {
} else {
x2336 = false;
}
if (x2331) {
} else {
x2336 = false;
}
bool x2349 = x2336;
if (x2349) {
x2284 = false;
} else {
}
bool x2353 = x2284;
x2302 = x2353;
} else {
}
int32_t* x2357 = x62;
int32_t x2358 = x2357[x2309];
x2301 = x2358;
}
bool x2362 = x2284;
if (x2362) {
int32_t x2365 = x59;
int32_t x2366 = x42;
bool x2367 = x2365 == x2366;
if (x2367) {
x42 *= 4;
int32_t x2369 = x42;
printf("buffer.resize %d\n",x2369);
} else {
}
int32_t* x2373 = x45;
x2373[x2365] = 3;
int32_t* x2375 = x49;
x2375[x2365] = x2283;
int32_t* x2377 = x53;
x2377[x2365] = x2212;
int32_t* x2379 = x57;
x2379[x2365] = x2216;
x59 += 1;
int32_t x2382 = x2365;
int32_t x2383 = 0;
x2383 = 236;
x2383 = x2288;
x2383 = x2292;
x2383 = x2296;
int32_t x2388 = x2300;
x2299[x2298] = x2365;
int32_t* x2390 = x62;
x2390[x2365] = x2300;
int32_t x2392 = 0;
x2392 = 236;
int32_t* x2394 = x71;
int32_t x2395 = x2394[x1266];
int32_t x2396 = x2395;
x2394[x1266] = x2365;
int32_t* x2398 = x66;
x2398[x2365] = x2395;
} else {
}
} else {
}
} else {
}
int32_t* x2406 = x124;
int32_t x2407 = x2406[x2200];
x2196 = x2407;
}
}
int32_t x2413 = x59;
bool x2414 = x2413 == 0;
if (x2414) {
x535 = false;
} else {
for(int x2418=0; x2418 < x2413; x2418++) {
int32_t* x2419 = x45;
int32_t* x2421 = x49;
int32_t* x2423 = x53;
int32_t* x2425 = x57;
bool x2427 = true;
int32_t x2428 = 0;
int32_t x2420 = x2419[x2418];
int32_t x2429 = x2420 + 233;
x2428 = x2429;
int32_t x2422 = x2421[x2418];
int32_t x2431 = x2429 * 1009;
int32_t x2432 = x2431 + x2422;
int32_t x2433 = x2432 + 233;
x2428 = x2433;
int32_t x2424 = x2423[x2418];
int32_t x2435 = x2433 * 1009;
int32_t x2436 = x2435 + x2424;
int32_t x2437 = x2436 + 233;
x2428 = x2437;
int32_t x2426 = x2425[x2418];
int32_t x2439 = x2437 * 1009;
int32_t x2440 = x2439 + x2426;
int32_t x2441 = x2440 + 233;
x2428 = x2441;
int32_t* x2444 = x28;
int32_t x2443 = x2441 & 4194303;
int32_t x2445 = x2444[x2443];
int32_t x2446 = x2445;
bool x2447 = true;
for (;;) {
bool x2448 = x2447;
bool x2452;
if (x2448) {
int32_t x2449 = x2446;
bool x2450 = x2449 != -1;
x2452 = x2450;
} else {
x2452 = false;
}
if (!x2452) break;
int32_t x2454 = x2446;
bool x2455 = true;
int32_t* x2456 = x4;
int32_t x2457 = x2456[x2454];
bool x2458 = x2420 == x2457;
if (x2458) {
} else {
x2455 = false;
}
int32_t* x2462 = x8;
int32_t x2463 = x2462[x2454];
bool x2464 = x2422 == x2463;
if (x2464) {
} else {
x2455 = false;
}
int32_t* x2468 = x12;
int32_t x2469 = x2468[x2454];
bool x2470 = x2424 == x2469;
if (x2470) {
} else {
x2455 = false;
}
int32_t* x2474 = x16;
int32_t x2475 = x2474[x2454];
bool x2476 = x2426 == x2475;
if (x2476) {
} else {
x2455 = false;
}
bool x2480 = x2455;
if (x2480) {
bool x2481 = true;
if (x2458) {
} else {
x2481 = false;
}
if (x2464) {
} else {
x2481 = false;
}
if (x2470) {
} else {
x2481 = false;
}
if (x2476) {
} else {
x2481 = false;
}
bool x2494 = x2481;
if (x2494) {
x2427 = false;
} else {
}
bool x2498 = x2427;
x2447 = x2498;
} else {
}
int32_t* x2502 = x21;
int32_t x2503 = x2502[x2454];
x2446 = x2503;
}
bool x2507 = x2427;
if (x2507) {
int32_t x2510 = x18;
int32_t x2511 = x1;
bool x2512 = x2510 == x2511;
if (x2512) {
x1 *= 4;
int32_t x2514 = x1;
printf("buffer.resize %d\n",x2514);
} else {
}
int32_t* x2518 = x4;
x2518[x2510] = x2420;
int32_t* x2520 = x8;
x2520[x2510] = x2422;
int32_t* x2522 = x12;
x2522[x2510] = x2424;
int32_t* x2524 = x16;
x2524[x2510] = x2426;
x18 += 1;
int32_t x2527 = x2510;
int32_t x2528 = 0;
x2528 = x2429;
x2528 = x2433;
x2528 = x2437;
x2528 = x2441;
int32_t x2533 = x2445;
x2444[x2443] = x2510;
int32_t* x2535 = x21;
x2535[x2510] = x2445;
int32_t x2537 = 0;
x2537 = x2429;
int32_t* x2540 = x30;
int32_t x2539 = x2429 & 4194303;
int32_t x2541 = x2540[x2539];
int32_t x2542 = x2541;
x2540[x2539] = x2510;
int32_t* x2544 = x25;
x2544[x2510] = x2541;
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
for(int x2575=0; x2575 < 16384; x2575++) {
int32_t* x2576 = x69;
x2576[x2575] = -1;

}
for(int x2580=0; x2580 < 16384; x2580++) {
int32_t* x2581 = x71;
x2581[x2580] = -1;

}
}
}
for(int x2589=0; x2589 < 16384; x2589++) {
int32_t* x2590 = x127;
x2590[x2589] = -1;

}
for(int x2594=0; x2594 < 16384; x2594++) {
int32_t* x2595 = x129;
x2595[x2594] = -1;

}
for(int x2599=0; x2599 < 16384; x2599++) {
int32_t* x2600 = x69;
x2600[x2599] = -1;

}
for(int x2604=0; x2604 < 16384; x2604++) {
int32_t* x2605 = x71;
x2605[x2604] = -1;

}
int32_t x2610 = x18;
FILE *x2609 = fopen("loop.out","w");
for(int x2612=0; x2612 < x2610; x2612++) {
int32_t* x2613 = x4;
int32_t x2614 = x2613[x2612];
int32_t x2615 = fprintf(x2609,"%d",x2614);
int32_t x2616 = fprintf(x2609,"\t");
int32_t* x2617 = x8;
int32_t x2618 = x2617[x2612];
int32_t x2619 = fprintf(x2609,"%d",x2618);
int32_t x2620 = fprintf(x2609,"\t");
int32_t* x2621 = x12;
int32_t x2622 = x2621[x2612];
int32_t x2623 = fprintf(x2609,"%d",x2622);
int32_t x2624 = fprintf(x2609,"\t");
int32_t* x2625 = x16;
int32_t x2626 = x2625[x2612];
int32_t x2627 = fprintf(x2609,"%d",x2626);
int32_t x2628 = fprintf(x2609,"\n");

}
fclose(x2609);
for(int x2632=0; x2632 < 4194304; x2632++) {
int32_t* x2633 = x94;
x2633[x2632] = -1;

}
for(int x2637=0; x2637 < 4194304; x2637++) {
int32_t* x2638 = x168;
x2638[x2637] = -1;

}
for(int x2642=0; x2642 < 4194304; x2642++) {
int32_t* x2643 = x151;
x2643[x2642] = -1;

}
for(int x2647=0; x2647 < 4194304; x2647++) {
int32_t* x2648 = x28;
x2648[x2647] = -1;

}
for(int x2652=0; x2652 < 4194304; x2652++) {
int32_t* x2653 = x30;
x2653[x2652] = -1;

}
}
/*****************************************
  End of C Generated Code                  
*******************************************/

