
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
int32_t x10 = 0;
int32_t x11 = 4194304;
int32_t* x12 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x13 = x12;
int32_t x14 = 0;
int32_t x15 = 4194304;
int32_t* x16 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x17 = x16;
int32_t x18 = 0;
int32_t* x19 = (int32_t*)malloc(16384 * sizeof(int32_t));
int32_t* x20 = x19;
int32_t* x21 = (int32_t*)malloc(16384 * sizeof(int32_t));
int32_t* x22 = x21;
for(int x24=0; x24 < 16384; x24++) {
int32_t* x25 = x20;
x25[x24] = -1;

}
for(int x29=0; x29 < 16384; x29++) {
int32_t* x30 = x22;
x30[x29] = -1;

}
int32_t x34 = 4194304;
int32_t x35 = 4194304;
int32_t* x36 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x37 = x36;
int32_t x38 = 0;
int32_t x39 = 4194304;
int32_t* x40 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x41 = x40;
int32_t x42 = 0;
int32_t x43 = 0;
int32_t x44 = 4194304;
int32_t* x45 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x46 = x45;
int32_t x47 = 0;
int32_t x48 = 4194304;
int32_t* x49 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x50 = x49;
int32_t x51 = 0;
int32_t* x52 = (int32_t*)malloc(16384 * sizeof(int32_t));
int32_t* x53 = x52;
int32_t* x54 = (int32_t*)malloc(16384 * sizeof(int32_t));
int32_t* x55 = x54;
for(int x56=0; x56 < 16384; x56++) {
int32_t* x57 = x53;
x57[x56] = -1;

}
for(int x61=0; x61 < 16384; x61++) {
int32_t* x62 = x55;
x62[x61] = -1;

}
int32_t x66 = 4194304;
int32_t x67 = 4194304;
int32_t* x68 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x69 = x68;
int32_t x70 = 0;
int32_t x71 = 4194304;
int32_t* x72 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x73 = x72;
int32_t x74 = 0;
int32_t x75 = 0;
int32_t x76 = 4194304;
int32_t* x77 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x78 = x77;
int32_t x79 = 0;
int32_t* x80 = (int32_t*)malloc(16384 * sizeof(int32_t));
int32_t* x81 = x80;
for(int x82=0; x82 < 16384; x82++) {
int32_t* x83 = x81;
x83[x82] = -1;

}
int32_t x87 = 4194304;
int32_t x88 = 4194304;
int32_t* x89 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x90 = x89;
int32_t x91 = 0;
int32_t x92 = 4194304;
int32_t* x93 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x94 = x93;
int32_t x95 = 0;
int32_t x96 = 0;
int32_t x97 = 4194304;
int32_t* x98 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x99 = x98;
int32_t x100 = 0;
int32_t* x101 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x102 = x101;
for(int x104=0; x104 < 4194304; x104++) {
int32_t* x105 = x102;
x105[x104] = -1;

}
int32_t x109 = 4194304;
int32_t x110 = 4194304;
int32_t* x111 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x112 = x111;
int32_t x113 = 0;
int32_t x114 = 4194304;
int32_t* x115 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x116 = x115;
int32_t x117 = 0;
int32_t x118 = 0;
int32_t x119 = 4194304;
int32_t* x120 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x121 = x120;
int32_t x122 = 0;
int32_t* x123 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x124 = x123;
for(int x125=0; x125 < 4194304; x125++) {
int32_t* x126 = x124;
x126[x125] = -1;

}
int32_t x130 = 4194304;
int32_t x131 = 4194304;
int32_t* x132 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x133 = x132;
int32_t x134 = 0;
int32_t x135 = 4194304;
int32_t* x136 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x137 = x136;
int32_t x138 = 0;
int32_t x139 = 0;
int32_t x140 = 4194304;
int32_t* x141 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x142 = x141;
int32_t x143 = 0;
int32_t* x144 = (int32_t*)malloc(16384 * sizeof(int32_t));
int32_t* x145 = x144;
for(int x146=0; x146 < 16384; x146++) {
int32_t* x147 = x145;
x147[x146] = -1;

}
int32_t x151 = 4194304;
int32_t x152 = 4194304;
int32_t* x153 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x154 = x153;
int32_t x155 = 0;
int32_t x156 = 4194304;
int32_t* x157 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x158 = x157;
int32_t x159 = 0;
int32_t x160 = 0;
int32_t x161 = 4194304;
int32_t* x162 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x163 = x162;
int32_t x164 = 0;
int32_t x165 = 4194304;
int32_t* x166 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x167 = x166;
int32_t x168 = 0;
int32_t* x169 = (int32_t*)malloc(16384 * sizeof(int32_t));
int32_t* x170 = x169;
int32_t* x171 = (int32_t*)malloc(16384 * sizeof(int32_t));
int32_t* x172 = x171;
for(int x173=0; x173 < 16384; x173++) {
int32_t* x174 = x170;
x174[x173] = -1;

}
for(int x178=0; x178 < 16384; x178++) {
int32_t* x179 = x172;
x179[x178] = -1;

}
int32_t x183 = 4194304;
int32_t x184 = 4194304;
int32_t* x185 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x186 = x185;
int32_t x187 = 0;
int32_t x188 = 4194304;
int32_t* x189 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x190 = x189;
int32_t x191 = 0;
int32_t x192 = 0;
int32_t x193 = 4194304;
int32_t* x194 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x195 = x194;
int32_t x196 = 0;
int32_t x197 = 4194304;
int32_t* x198 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x199 = x198;
int32_t x200 = 0;
int32_t* x201 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x202 = x201;
int32_t* x203 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x204 = x203;
for(int x205=0; x205 < 4194304; x205++) {
int32_t* x206 = x202;
x206[x205] = -1;

}
for(int x210=0; x210 < 4194304; x210++) {
int32_t* x211 = x204;
x211[x210] = -1;

}
int32_t x215 = 4194304;
int32_t x216 = 4194304;
int32_t* x217 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x218 = x217;
int32_t x219 = 0;
int32_t x220 = 4194304;
int32_t* x221 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x222 = x221;
int32_t x223 = 0;
int32_t x224 = 0;
int32_t x225 = 4194304;
int32_t* x226 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x227 = x226;
int32_t x228 = 0;
int32_t x229 = 4194304;
int32_t* x230 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x231 = x230;
int32_t x232 = 0;
int32_t* x233 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x234 = x233;
int32_t* x235 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x236 = x235;
for(int x237=0; x237 < 4194304; x237++) {
int32_t* x238 = x234;
x238[x237] = -1;

}
for(int x242=0; x242 < 4194304; x242++) {
int32_t* x243 = x236;
x243[x242] = -1;

}
int32_t x247 = 4194304;
int32_t x248 = 4194304;
int32_t* x249 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x250 = x249;
int32_t x251 = 0;
int32_t x252 = 4194304;
int32_t* x253 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x254 = x253;
int32_t x255 = 0;
int32_t x256 = 0;
int32_t x257 = 4194304;
int32_t* x258 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x259 = x258;
int32_t x260 = 0;
int32_t x261 = 4194304;
int32_t* x262 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x263 = x262;
int32_t x264 = 0;
int32_t* x265 = (int32_t*)malloc(16384 * sizeof(int32_t));
int32_t* x266 = x265;
int32_t* x267 = (int32_t*)malloc(16384 * sizeof(int32_t));
int32_t* x268 = x267;
for(int x269=0; x269 < 16384; x269++) {
int32_t* x270 = x266;
x270[x269] = -1;

}
for(int x274=0; x274 < 16384; x274++) {
int32_t* x275 = x268;
x275[x274] = -1;

}
int32_t x282 = 0;
int32_t x279 = open("base.facts",0);
int32_t x280 = fsize(x279);
char* x281 = mmap(0, x280, PROT_READ, MAP_FILE | MAP_SHARED, x279, 0);
for (;;) {
int32_t x283 = x282;
bool x284 = x283 < x280;
if (!x284) break;
int32_t x286 = x282;
for (;;) {
int32_t x287 = x282;
char x288 = x281[x287];
bool x289 = x288 != '\t';
if (!x289) break;
x282 += 1;
}
int32_t x294 = x282;
x282 += 1;
char* x297 = x281+x286;
int32_t x298 = atoi(x297);
int32_t x299 = x282;
for (;;) {
int32_t x300 = x282;
char x301 = x281[x300];
bool x302 = x301 != '\n';
if (!x302) break;
x282 += 1;
}
int32_t x307 = x282;
x282 += 1;
char* x310 = x281+x299;
int32_t x311 = atoi(x310);
int32_t x312 = x192;
int32_t x313 = x183;
bool x314 = x312 == x313;
if (x314) {
x183 *= 4;
int32_t x316 = x183;
printf("buffer.resize %d\n",x316);
} else {
}
int32_t* x320 = x186;
x320[x312] = x298;
int32_t* x322 = x190;
x322[x312] = x311;
x192 += 1;
int32_t x325 = x312;
int32_t x326 = 0;
int32_t x327 = x298 + 233;
x326 = x327;
int32_t x329 = x327 * 1009;
int32_t x330 = x329 + x311;
int32_t x331 = x330 + 233;
x326 = x331;
int32_t* x334 = x202;
int32_t x333 = x331 & 4194303;
int32_t x335 = x334[x333];
int32_t x336 = x335;
x334[x333] = x312;
int32_t* x338 = x195;
x338[x312] = x335;
int32_t x340 = 0;
x340 = x327;
int32_t* x343 = x204;
int32_t x342 = x327 & 4194303;
int32_t x344 = x343[x342];
int32_t x345 = x344;
x343[x342] = x312;
int32_t* x347 = x199;
x347[x312] = x344;
}
int32_t x351 = x192;
bool x352 = x351 == 0;
if (x352) {
} else {
for(int x355=0; x355 < x351; x355++) {
int32_t* x356 = x186;
int32_t* x358 = x190;
bool x360 = true;
int32_t x361 = 0;
int32_t x357 = x356[x355];
int32_t x362 = x357 + 233;
x361 = x362;
int32_t x359 = x358[x355];
int32_t x364 = x362 * 1009;
int32_t x365 = x364 + x359;
int32_t x366 = x365 + 233;
x361 = x366;
int32_t* x369 = x234;
int32_t x368 = x366 & 4194303;
int32_t x370 = x369[x368];
int32_t x371 = x370;
bool x372 = true;
for (;;) {
bool x373 = x372;
bool x377;
if (x373) {
int32_t x374 = x371;
bool x375 = x374 != -1;
x377 = x375;
} else {
x377 = false;
}
if (!x377) break;
int32_t x379 = x371;
bool x380 = true;
int32_t* x381 = x218;
int32_t x382 = x381[x379];
bool x383 = x357 == x382;
if (x383) {
} else {
x380 = false;
}
int32_t* x387 = x222;
int32_t x388 = x387[x379];
bool x389 = x359 == x388;
if (x389) {
} else {
x380 = false;
}
bool x393 = x380;
if (x393) {
bool x394 = true;
if (x383) {
} else {
x394 = false;
}
if (x389) {
} else {
x394 = false;
}
bool x401 = x394;
if (x401) {
x360 = false;
} else {
}
bool x405 = x360;
x372 = x405;
} else {
}
int32_t* x409 = x227;
int32_t x410 = x409[x379];
x371 = x410;
}
bool x414 = x360;
if (x414) {
int32_t x417 = x224;
int32_t x418 = x215;
bool x419 = x417 == x418;
if (x419) {
x215 *= 4;
int32_t x421 = x215;
printf("buffer.resize %d\n",x421);
} else {
}
int32_t* x425 = x218;
x425[x417] = x357;
int32_t* x427 = x222;
x427[x417] = x359;
x224 += 1;
int32_t x430 = x417;
int32_t x431 = 0;
x431 = x362;
x431 = x366;
int32_t x434 = x370;
x369[x368] = x417;
int32_t* x436 = x227;
x436[x417] = x370;
int32_t x438 = 0;
x438 = x362;
int32_t* x441 = x236;
int32_t x440 = x362 & 4194303;
int32_t x442 = x441[x440];
int32_t x443 = x442;
x441[x440] = x417;
int32_t* x445 = x231;
x445[x417] = x442;
} else {
}

}
}
int32_t x453 = x224;
for(int x455=0; x455 < x453; x455++) {
int32_t* x456 = x218;
int32_t* x458 = x222;
bool x460 = true;
int32_t x461 = 0;
int32_t x457 = x456[x455];
int32_t x462 = x457 + 233;
x461 = x462;
int32_t x459 = x458[x455];
int32_t x464 = x462 * 1009;
int32_t x465 = x464 + x459;
int32_t x466 = x465 + 233;
x461 = x466;
int32_t* x469 = x20;
int32_t x468 = x466 & 16383;
int32_t x470 = x469[x468];
int32_t x471 = x470;
bool x472 = true;
for (;;) {
bool x473 = x472;
bool x477;
if (x473) {
int32_t x474 = x471;
bool x475 = x474 != -1;
x477 = x475;
} else {
x477 = false;
}
if (!x477) break;
int32_t x479 = x471;
bool x480 = true;
int32_t* x481 = x4;
int32_t x482 = x481[x479];
bool x483 = x457 == x482;
if (x483) {
} else {
x480 = false;
}
int32_t* x487 = x8;
int32_t x488 = x487[x479];
bool x489 = x459 == x488;
if (x489) {
} else {
x480 = false;
}
bool x493 = x480;
if (x493) {
bool x494 = true;
if (x483) {
} else {
x494 = false;
}
if (x489) {
} else {
x494 = false;
}
bool x501 = x494;
if (x501) {
x460 = false;
} else {
}
bool x505 = x460;
x472 = x505;
} else {
}
int32_t* x509 = x13;
int32_t x510 = x509[x479];
x471 = x510;
}
bool x514 = x460;
if (x514) {
int32_t x517 = x10;
int32_t x518 = x1;
bool x519 = x517 == x518;
if (x519) {
x1 *= 4;
int32_t x521 = x1;
printf("buffer.resize %d\n",x521);
} else {
}
int32_t* x525 = x4;
x525[x517] = x457;
int32_t* x527 = x8;
x527[x517] = x459;
x10 += 1;
int32_t x530 = x517;
int32_t x531 = 0;
x531 = x462;
x531 = x466;
int32_t x534 = x470;
x469[x468] = x517;
int32_t* x536 = x13;
x536[x517] = x470;
int32_t x538 = 0;
x538 = x462;
int32_t* x541 = x22;
int32_t x540 = x462 & 16383;
int32_t x542 = x541[x540];
int32_t x543 = x542;
x541[x540] = x517;
int32_t* x545 = x17;
x545[x517] = x542;
} else {
}

}
bool x551 = true;
for (;;) {
bool x552 = x551;
if (!x552) break;
int32_t x554 = x10;
bool x555 = x554 == 0;
bool x561;
if (x555) {
x561 = false;
} else {
int32_t x557 = x224;
bool x558 = x557 == 0;
bool x559 = !x558;
x561 = x559;
}
if (x561) {
for(int x563=0; x563 < x554; x563++) {
int32_t* x564 = x8;
int32_t x566 = 0;
int32_t x565 = x564[x563];
int32_t x567 = x565 + 233;
x566 = x567;
int32_t* x570 = x236;
int32_t x569 = x567 & 4194303;
int32_t x571 = x570[x569];
int32_t x572 = x571;
for (;;) {
int32_t x573 = x572;
bool x574 = x573 != -1;
if (!x574) break;
int32_t x576 = x572;
bool x577 = true;
int32_t* x578 = x218;
int32_t x579 = x578[x576];
bool x580 = x565 == x579;
if (x580) {
} else {
x577 = false;
}
bool x584 = x577;
if (x584) {
int32_t* x585 = x8;
int32_t* x587 = x222;
bool x589 = false;
int32_t x590 = 0;
int32_t x586 = x585[x563];
int32_t x591 = x586 + 233;
x590 = x591;
int32_t x588 = x587[x576];
int32_t x593 = x591 * 1009;
int32_t x594 = x593 + x588;
int32_t x595 = x594 + 233;
x590 = x595;
int32_t* x598 = x20;
int32_t x597 = x595 & 16383;
int32_t x599 = x598[x597];
int32_t x600 = x599;
bool x601 = true;
for (;;) {
bool x602 = x601;
bool x606;
if (x602) {
int32_t x603 = x600;
bool x604 = x603 != -1;
x606 = x604;
} else {
x606 = false;
}
if (!x606) break;
int32_t x608 = x600;
bool x609 = true;
int32_t* x610 = x4;
int32_t x611 = x610[x608];
bool x612 = x586 == x611;
if (x612) {
} else {
x609 = false;
}
int32_t* x616 = x8;
int32_t x617 = x616[x608];
bool x618 = x588 == x617;
if (x618) {
} else {
x609 = false;
}
bool x622 = x609;
if (x622) {
x589 = true;
x601 = false;
} else {
}
int32_t* x627 = x13;
int32_t x628 = x627[x608];
x600 = x628;
}
bool x632 = x589;
bool x682;
if (x632) {
x682 = false;
} else {
int32_t* x634 = x4;
bool x636 = false;
int32_t x637 = 0;
int32_t x635 = x634[x563];
int32_t x638 = x635 + 233;
x637 = x638;
int32_t x640 = x638 * 1009;
int32_t x641 = x640 + x588;
int32_t x642 = x641 + 233;
x637 = x642;
int32_t* x645 = x234;
int32_t x644 = x642 & 4194303;
int32_t x646 = x645[x644];
int32_t x647 = x646;
bool x648 = true;
for (;;) {
bool x649 = x648;
bool x653;
if (x649) {
int32_t x650 = x647;
bool x651 = x650 != -1;
x653 = x651;
} else {
x653 = false;
}
if (!x653) break;
int32_t x655 = x647;
bool x656 = true;
int32_t* x657 = x218;
int32_t x658 = x657[x655];
bool x659 = x635 == x658;
if (x659) {
} else {
x656 = false;
}
int32_t* x663 = x222;
int32_t x664 = x663[x655];
bool x665 = x588 == x664;
if (x665) {
} else {
x656 = false;
}
bool x669 = x656;
if (x669) {
x636 = true;
x648 = false;
} else {
}
int32_t* x674 = x227;
int32_t x675 = x674[x655];
x647 = x675;
}
bool x679 = x636;
bool x680 = !x679;
x682 = x680;
}
if (x682) {
int32_t* x683 = x4;
bool x685 = true;
int32_t x686 = 0;
int32_t x684 = x683[x563];
int32_t x687 = x684 + 233;
x686 = x687;
int32_t x689 = x687 * 1009;
int32_t x690 = x689 + x588;
int32_t x691 = x690 + 233;
x686 = x691;
int32_t* x694 = x53;
int32_t x693 = x691 & 16383;
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
int32_t* x706 = x37;
int32_t x707 = x706[x704];
bool x708 = x684 == x707;
if (x708) {
} else {
x705 = false;
}
int32_t* x712 = x41;
int32_t x713 = x712[x704];
bool x714 = x588 == x713;
if (x714) {
} else {
x705 = false;
}
bool x718 = x705;
if (x718) {
bool x719 = true;
if (x708) {
} else {
x719 = false;
}
if (x714) {
} else {
x719 = false;
}
bool x726 = x719;
if (x726) {
x685 = false;
} else {
}
bool x730 = x685;
x697 = x730;
} else {
}
int32_t* x734 = x46;
int32_t x735 = x734[x704];
x696 = x735;
}
bool x739 = x685;
if (x739) {
int32_t x742 = x43;
int32_t x743 = x34;
bool x744 = x742 == x743;
if (x744) {
x34 *= 4;
int32_t x746 = x34;
printf("buffer.resize %d\n",x746);
} else {
}
int32_t* x750 = x37;
x750[x742] = x684;
int32_t* x752 = x41;
x752[x742] = x588;
x43 += 1;
int32_t x755 = x742;
int32_t x756 = 0;
x756 = x687;
x756 = x691;
int32_t x759 = x695;
x694[x693] = x742;
int32_t* x761 = x46;
x761[x742] = x695;
int32_t x763 = 0;
x763 = x687;
int32_t* x766 = x55;
int32_t x765 = x687 & 16383;
int32_t x767 = x766[x765];
int32_t x768 = x767;
x766[x765] = x742;
int32_t* x770 = x50;
x770[x742] = x767;
} else {
}
} else {
}
} else {
}
int32_t* x778 = x231;
int32_t x779 = x778[x576];
x572 = x779;
}

}
} else {
}
int32_t x787 = x224;
bool x788 = x787 == 0;
bool x790;
if (x788) {
x790 = false;
} else {
bool x556 = !x555;
x790 = x556;
}
if (x790) {
for(int x792=0; x792 < x787; x792++) {
int32_t* x793 = x222;
int32_t x795 = 0;
int32_t x794 = x793[x792];
int32_t x796 = x794 + 233;
x795 = x796;
int32_t* x799 = x22;
int32_t x798 = x796 & 16383;
int32_t x800 = x799[x798];
int32_t x801 = x800;
for (;;) {
int32_t x802 = x801;
bool x803 = x802 != -1;
if (!x803) break;
int32_t x805 = x801;
bool x806 = true;
int32_t* x807 = x4;
int32_t x808 = x807[x805];
bool x809 = x794 == x808;
if (x809) {
} else {
x806 = false;
}
bool x813 = x806;
if (x813) {
int32_t* x814 = x218;
int32_t* x816 = x8;
bool x818 = false;
int32_t x819 = 0;
int32_t x815 = x814[x792];
int32_t x820 = x815 + 233;
x819 = x820;
int32_t x817 = x816[x805];
int32_t x822 = x820 * 1009;
int32_t x823 = x822 + x817;
int32_t x824 = x823 + 233;
x819 = x824;
int32_t* x827 = x234;
int32_t x826 = x824 & 4194303;
int32_t x828 = x827[x826];
int32_t x829 = x828;
bool x830 = true;
for (;;) {
bool x831 = x830;
bool x835;
if (x831) {
int32_t x832 = x829;
bool x833 = x832 != -1;
x835 = x833;
} else {
x835 = false;
}
if (!x835) break;
int32_t x837 = x829;
bool x838 = true;
int32_t* x839 = x218;
int32_t x840 = x839[x837];
bool x841 = x815 == x840;
if (x841) {
} else {
x838 = false;
}
int32_t* x845 = x222;
int32_t x846 = x845[x837];
bool x847 = x817 == x846;
if (x847) {
} else {
x838 = false;
}
bool x851 = x838;
if (x851) {
x818 = true;
x830 = false;
} else {
}
int32_t* x856 = x227;
int32_t x857 = x856[x837];
x829 = x857;
}
bool x861 = x818;
if (x861) {
} else {
bool x863 = true;
int32_t x864 = 0;
x864 = x820;
x864 = x824;
int32_t* x868 = x53;
int32_t x867 = x824 & 16383;
int32_t x869 = x868[x867];
int32_t x870 = x869;
bool x871 = true;
for (;;) {
bool x872 = x871;
bool x876;
if (x872) {
int32_t x873 = x870;
bool x874 = x873 != -1;
x876 = x874;
} else {
x876 = false;
}
if (!x876) break;
int32_t x878 = x870;
bool x879 = true;
int32_t* x880 = x37;
int32_t x881 = x880[x878];
bool x882 = x815 == x881;
if (x882) {
} else {
x879 = false;
}
int32_t* x886 = x41;
int32_t x887 = x886[x878];
bool x888 = x817 == x887;
if (x888) {
} else {
x879 = false;
}
bool x892 = x879;
if (x892) {
bool x893 = true;
if (x882) {
} else {
x893 = false;
}
if (x888) {
} else {
x893 = false;
}
bool x900 = x893;
if (x900) {
x863 = false;
} else {
}
bool x904 = x863;
x871 = x904;
} else {
}
int32_t* x908 = x46;
int32_t x909 = x908[x878];
x870 = x909;
}
bool x913 = x863;
if (x913) {
int32_t x916 = x43;
int32_t x917 = x34;
bool x918 = x916 == x917;
if (x918) {
x34 *= 4;
int32_t x920 = x34;
printf("buffer.resize %d\n",x920);
} else {
}
int32_t* x924 = x37;
x924[x916] = x815;
int32_t* x926 = x41;
x926[x916] = x817;
x43 += 1;
int32_t x929 = x916;
int32_t x930 = 0;
x930 = x820;
x930 = x824;
int32_t x933 = x869;
x868[x867] = x916;
int32_t* x935 = x46;
x935[x916] = x869;
int32_t x937 = 0;
x937 = x820;
int32_t* x940 = x55;
int32_t x939 = x820 & 16383;
int32_t x941 = x940[x939];
int32_t x942 = x941;
x940[x939] = x916;
int32_t* x944 = x50;
x944[x916] = x941;
} else {
}
}
} else {
}
int32_t* x952 = x17;
int32_t x953 = x952[x805];
x801 = x953;
}

}
} else {
}
int32_t x961 = x43;
bool x962 = x961 == 0;
if (x962) {
x551 = false;
} else {
for(int x966=0; x966 < x961; x966++) {
int32_t* x967 = x37;
int32_t* x969 = x41;
bool x971 = true;
int32_t x972 = 0;
int32_t x968 = x967[x966];
int32_t x973 = x968 + 233;
x972 = x973;
int32_t x970 = x969[x966];
int32_t x975 = x973 * 1009;
int32_t x976 = x975 + x970;
int32_t x977 = x976 + 233;
x972 = x977;
int32_t* x980 = x234;
int32_t x979 = x977 & 4194303;
int32_t x981 = x980[x979];
int32_t x982 = x981;
bool x983 = true;
for (;;) {
bool x984 = x983;
bool x988;
if (x984) {
int32_t x985 = x982;
bool x986 = x985 != -1;
x988 = x986;
} else {
x988 = false;
}
if (!x988) break;
int32_t x990 = x982;
bool x991 = true;
int32_t* x992 = x218;
int32_t x993 = x992[x990];
bool x994 = x968 == x993;
if (x994) {
} else {
x991 = false;
}
int32_t* x998 = x222;
int32_t x999 = x998[x990];
bool x1000 = x970 == x999;
if (x1000) {
} else {
x991 = false;
}
bool x1004 = x991;
if (x1004) {
bool x1005 = true;
if (x994) {
} else {
x1005 = false;
}
if (x1000) {
} else {
x1005 = false;
}
bool x1012 = x1005;
if (x1012) {
x971 = false;
} else {
}
bool x1016 = x971;
x983 = x1016;
} else {
}
int32_t* x1020 = x227;
int32_t x1021 = x1020[x990];
x982 = x1021;
}
bool x1025 = x971;
if (x1025) {
int32_t x1028 = x224;
int32_t x1029 = x215;
bool x1030 = x1028 == x1029;
if (x1030) {
x215 *= 4;
int32_t x1032 = x215;
printf("buffer.resize %d\n",x1032);
} else {
}
int32_t* x1036 = x218;
x1036[x1028] = x968;
int32_t* x1038 = x222;
x1038[x1028] = x970;
x224 += 1;
int32_t x1041 = x1028;
int32_t x1042 = 0;
x1042 = x973;
x1042 = x977;
int32_t x1045 = x981;
x980[x979] = x1028;
int32_t* x1047 = x227;
x1047[x1028] = x981;
int32_t x1049 = 0;
x1049 = x973;
int32_t* x1052 = x236;
int32_t x1051 = x973 & 4194303;
int32_t x1053 = x1052[x1051];
int32_t x1054 = x1053;
x1052[x1051] = x1028;
int32_t* x1056 = x231;
x1056[x1028] = x1053;
} else {
}

}
SWAP(x10,x43);
SWAP(x1,x34);
SWAP(x5,x38);
SWAP(x2,x35);
SWAP(x4,x37);
SWAP(x9,x42);
SWAP(x6,x39);
SWAP(x8,x41);
SWAP(x14,x47);
SWAP(x11,x44);
SWAP(x13,x46);
SWAP(x18,x51);
SWAP(x15,x48);
SWAP(x17,x50);
SWAP(x20,x53);
SWAP(x22,x55);
x43 = 0;
x47 = 0;
x51 = 0;
for(int x1081=0; x1081 < 16384; x1081++) {
int32_t* x1082 = x53;
x1082[x1081] = -1;

}
for(int x1086=0; x1086 < 16384; x1086++) {
int32_t* x1087 = x55;
x1087[x1086] = -1;

}
}
}
for(int x1095=0; x1095 < 16384; x1095++) {
int32_t* x1096 = x20;
x1096[x1095] = -1;

}
for(int x1100=0; x1100 < 16384; x1100++) {
int32_t* x1101 = x22;
x1101[x1100] = -1;

}
for(int x1105=0; x1105 < 16384; x1105++) {
int32_t* x1106 = x53;
x1106[x1105] = -1;

}
for(int x1110=0; x1110 < 16384; x1110++) {
int32_t* x1111 = x55;
x1111[x1110] = -1;

}
int32_t x1116 = x224;
FILE *x1115 = fopen("tc.out","w");
for(int x1118=0; x1118 < x1116; x1118++) {
int32_t* x1119 = x218;
int32_t x1120 = x1119[x1118];
int32_t x1121 = fprintf(x1115,"%d",x1120);
int32_t x1122 = fprintf(x1115,"\t");
int32_t* x1123 = x222;
int32_t x1124 = x1123[x1118];
int32_t x1125 = fprintf(x1115,"%d",x1124);
int32_t x1126 = fprintf(x1115,"\n");

}
fclose(x1115);
for(int x1130=0; x1130 < 4194304; x1130++) {
int32_t* x1131 = x234;
x1131[x1130] = -1;

}
for(int x1135=0; x1135 < 4194304; x1135++) {
int32_t* x1136 = x236;
x1136[x1135] = -1;

}
if (x352) {
} else {
for(int x1140=0; x1140 < x351; x1140++) {
int32_t* x1141 = x186;
int32_t* x1143 = x190;
bool x1145 = true;
int32_t x1146 = 0;
int32_t x1142 = x1141[x1140];
int32_t x1147 = x1142 + 233;
x1146 = x1147;
int32_t x1144 = x1143[x1140];
int32_t x1149 = x1147 * 1009;
int32_t x1150 = x1149 + x1144;
int32_t x1151 = x1150 + 233;
x1146 = x1151;
int32_t* x1154 = x124;
int32_t x1153 = x1151 & 4194303;
int32_t x1155 = x1154[x1153];
int32_t x1156 = x1155;
bool x1157 = true;
for (;;) {
bool x1158 = x1157;
bool x1162;
if (x1158) {
int32_t x1159 = x1156;
bool x1160 = x1159 != -1;
x1162 = x1160;
} else {
x1162 = false;
}
if (!x1162) break;
int32_t x1164 = x1156;
bool x1165 = true;
int32_t* x1166 = x112;
int32_t x1167 = x1166[x1164];
bool x1168 = x1142 == x1167;
if (x1168) {
} else {
x1165 = false;
}
int32_t* x1172 = x116;
int32_t x1173 = x1172[x1164];
bool x1174 = x1144 == x1173;
if (x1174) {
} else {
x1165 = false;
}
bool x1178 = x1165;
if (x1178) {
bool x1179 = true;
if (x1168) {
} else {
x1179 = false;
}
if (x1174) {
} else {
x1179 = false;
}
bool x1186 = x1179;
if (x1186) {
x1145 = false;
} else {
}
bool x1190 = x1145;
x1157 = x1190;
} else {
}
int32_t* x1194 = x121;
int32_t x1195 = x1194[x1164];
x1156 = x1195;
}
bool x1199 = x1145;
if (x1199) {
int32_t x1202 = x118;
int32_t x1203 = x109;
bool x1204 = x1202 == x1203;
if (x1204) {
x109 *= 4;
int32_t x1206 = x109;
printf("buffer.resize %d\n",x1206);
} else {
}
int32_t* x1210 = x112;
x1210[x1202] = x1142;
int32_t* x1212 = x116;
x1212[x1202] = x1144;
x118 += 1;
int32_t x1215 = x1202;
int32_t x1216 = 0;
x1216 = x1147;
x1216 = x1151;
int32_t x1219 = x1155;
x1154[x1153] = x1202;
int32_t* x1221 = x121;
x1221[x1202] = x1155;
} else {
}

}
}
int32_t x1229 = x118;
for(int x1231=0; x1231 < x1229; x1231++) {
int32_t* x1232 = x112;
int32_t* x1234 = x116;
bool x1236 = true;
int32_t x1237 = 0;
int32_t x1233 = x1232[x1231];
int32_t x1238 = x1233 + 233;
x1237 = x1238;
int32_t x1235 = x1234[x1231];
int32_t x1240 = x1238 * 1009;
int32_t x1241 = x1240 + x1235;
int32_t x1242 = x1241 + 233;
x1237 = x1242;
int32_t* x1245 = x145;
int32_t x1244 = x1242 & 16383;
int32_t x1246 = x1245[x1244];
int32_t x1247 = x1246;
bool x1248 = true;
for (;;) {
bool x1249 = x1248;
bool x1253;
if (x1249) {
int32_t x1250 = x1247;
bool x1251 = x1250 != -1;
x1253 = x1251;
} else {
x1253 = false;
}
if (!x1253) break;
int32_t x1255 = x1247;
bool x1256 = true;
int32_t* x1257 = x133;
int32_t x1258 = x1257[x1255];
bool x1259 = x1233 == x1258;
if (x1259) {
} else {
x1256 = false;
}
int32_t* x1263 = x137;
int32_t x1264 = x1263[x1255];
bool x1265 = x1235 == x1264;
if (x1265) {
} else {
x1256 = false;
}
bool x1269 = x1256;
if (x1269) {
bool x1270 = true;
if (x1259) {
} else {
x1270 = false;
}
if (x1265) {
} else {
x1270 = false;
}
bool x1277 = x1270;
if (x1277) {
x1236 = false;
} else {
}
bool x1281 = x1236;
x1248 = x1281;
} else {
}
int32_t* x1285 = x142;
int32_t x1286 = x1285[x1255];
x1247 = x1286;
}
bool x1290 = x1236;
if (x1290) {
int32_t x1293 = x139;
int32_t x1294 = x130;
bool x1295 = x1293 == x1294;
if (x1295) {
x130 *= 4;
int32_t x1297 = x130;
printf("buffer.resize %d\n",x1297);
} else {
}
int32_t* x1301 = x133;
x1301[x1293] = x1233;
int32_t* x1303 = x137;
x1303[x1293] = x1235;
x139 += 1;
int32_t x1306 = x1293;
int32_t x1307 = 0;
x1307 = x1238;
x1307 = x1242;
int32_t x1310 = x1246;
x1245[x1244] = x1293;
int32_t* x1312 = x142;
x1312[x1293] = x1246;
} else {
}

}
bool x1318 = true;
for (;;) {
bool x1319 = x1318;
if (!x1319) break;
int32_t x1321 = x139;
bool x1322 = x1321 == 0;
bool x1328;
if (x1322) {
x1328 = false;
} else {
int32_t x1324 = x192;
bool x1325 = x1324 == 0;
bool x1326 = !x1325;
x1328 = x1326;
}
if (x1328) {
for(int x1330=0; x1330 < x1321; x1330++) {
int32_t* x1331 = x137;
int32_t x1333 = 0;
int32_t x1332 = x1331[x1330];
int32_t x1334 = x1332 + 233;
x1333 = x1334;
int32_t* x1337 = x204;
int32_t x1336 = x1334 & 4194303;
int32_t x1338 = x1337[x1336];
int32_t x1339 = x1338;
for (;;) {
int32_t x1340 = x1339;
bool x1341 = x1340 != -1;
if (!x1341) break;
int32_t x1343 = x1339;
bool x1344 = true;
int32_t* x1345 = x186;
int32_t x1346 = x1345[x1343];
bool x1347 = x1332 == x1346;
if (x1347) {
} else {
x1344 = false;
}
bool x1351 = x1344;
if (x1351) {
int32_t* x1352 = x133;
int32_t* x1354 = x190;
bool x1356 = false;
int32_t x1357 = 0;
int32_t x1353 = x1352[x1330];
int32_t x1358 = x1353 + 233;
x1357 = x1358;
int32_t x1355 = x1354[x1343];
int32_t x1360 = x1358 * 1009;
int32_t x1361 = x1360 + x1355;
int32_t x1362 = x1361 + 233;
x1357 = x1362;
int32_t* x1365 = x124;
int32_t x1364 = x1362 & 4194303;
int32_t x1366 = x1365[x1364];
int32_t x1367 = x1366;
bool x1368 = true;
for (;;) {
bool x1369 = x1368;
bool x1373;
if (x1369) {
int32_t x1370 = x1367;
bool x1371 = x1370 != -1;
x1373 = x1371;
} else {
x1373 = false;
}
if (!x1373) break;
int32_t x1375 = x1367;
bool x1376 = true;
int32_t* x1377 = x112;
int32_t x1378 = x1377[x1375];
bool x1379 = x1353 == x1378;
if (x1379) {
} else {
x1376 = false;
}
int32_t* x1383 = x116;
int32_t x1384 = x1383[x1375];
bool x1385 = x1355 == x1384;
if (x1385) {
} else {
x1376 = false;
}
bool x1389 = x1376;
if (x1389) {
x1356 = true;
x1368 = false;
} else {
}
int32_t* x1394 = x121;
int32_t x1395 = x1394[x1375];
x1367 = x1395;
}
bool x1399 = x1356;
if (x1399) {
} else {
bool x1401 = true;
int32_t x1402 = 0;
x1402 = x1358;
x1402 = x1362;
int32_t* x1406 = x81;
int32_t x1405 = x1362 & 16383;
int32_t x1407 = x1406[x1405];
int32_t x1408 = x1407;
bool x1409 = true;
for (;;) {
bool x1410 = x1409;
bool x1414;
if (x1410) {
int32_t x1411 = x1408;
bool x1412 = x1411 != -1;
x1414 = x1412;
} else {
x1414 = false;
}
if (!x1414) break;
int32_t x1416 = x1408;
bool x1417 = true;
int32_t* x1418 = x69;
int32_t x1419 = x1418[x1416];
bool x1420 = x1353 == x1419;
if (x1420) {
} else {
x1417 = false;
}
int32_t* x1424 = x73;
int32_t x1425 = x1424[x1416];
bool x1426 = x1355 == x1425;
if (x1426) {
} else {
x1417 = false;
}
bool x1430 = x1417;
if (x1430) {
bool x1431 = true;
if (x1420) {
} else {
x1431 = false;
}
if (x1426) {
} else {
x1431 = false;
}
bool x1438 = x1431;
if (x1438) {
x1401 = false;
} else {
}
bool x1442 = x1401;
x1409 = x1442;
} else {
}
int32_t* x1446 = x78;
int32_t x1447 = x1446[x1416];
x1408 = x1447;
}
bool x1451 = x1401;
if (x1451) {
int32_t x1454 = x75;
int32_t x1455 = x66;
bool x1456 = x1454 == x1455;
if (x1456) {
x66 *= 4;
int32_t x1458 = x66;
printf("buffer.resize %d\n",x1458);
} else {
}
int32_t* x1462 = x69;
x1462[x1454] = x1353;
int32_t* x1464 = x73;
x1464[x1454] = x1355;
x75 += 1;
int32_t x1467 = x1454;
int32_t x1468 = 0;
x1468 = x1358;
x1468 = x1362;
int32_t x1471 = x1407;
x1406[x1405] = x1454;
int32_t* x1473 = x78;
x1473[x1454] = x1407;
} else {
}
}
} else {
}
int32_t* x1481 = x199;
int32_t x1482 = x1481[x1343];
x1339 = x1482;
}

}
} else {
}
int32_t x1490 = x75;
bool x1491 = x1490 == 0;
if (x1491) {
x1318 = false;
} else {
for(int x1495=0; x1495 < x1490; x1495++) {
int32_t* x1496 = x69;
int32_t* x1498 = x73;
bool x1500 = true;
int32_t x1501 = 0;
int32_t x1497 = x1496[x1495];
int32_t x1502 = x1497 + 233;
x1501 = x1502;
int32_t x1499 = x1498[x1495];
int32_t x1504 = x1502 * 1009;
int32_t x1505 = x1504 + x1499;
int32_t x1506 = x1505 + 233;
x1501 = x1506;
int32_t* x1509 = x124;
int32_t x1508 = x1506 & 4194303;
int32_t x1510 = x1509[x1508];
int32_t x1511 = x1510;
bool x1512 = true;
for (;;) {
bool x1513 = x1512;
bool x1517;
if (x1513) {
int32_t x1514 = x1511;
bool x1515 = x1514 != -1;
x1517 = x1515;
} else {
x1517 = false;
}
if (!x1517) break;
int32_t x1519 = x1511;
bool x1520 = true;
int32_t* x1521 = x112;
int32_t x1522 = x1521[x1519];
bool x1523 = x1497 == x1522;
if (x1523) {
} else {
x1520 = false;
}
int32_t* x1527 = x116;
int32_t x1528 = x1527[x1519];
bool x1529 = x1499 == x1528;
if (x1529) {
} else {
x1520 = false;
}
bool x1533 = x1520;
if (x1533) {
bool x1534 = true;
if (x1523) {
} else {
x1534 = false;
}
if (x1529) {
} else {
x1534 = false;
}
bool x1541 = x1534;
if (x1541) {
x1500 = false;
} else {
}
bool x1545 = x1500;
x1512 = x1545;
} else {
}
int32_t* x1549 = x121;
int32_t x1550 = x1549[x1519];
x1511 = x1550;
}
bool x1554 = x1500;
if (x1554) {
int32_t x1557 = x118;
int32_t x1558 = x109;
bool x1559 = x1557 == x1558;
if (x1559) {
x109 *= 4;
int32_t x1561 = x109;
printf("buffer.resize %d\n",x1561);
} else {
}
int32_t* x1565 = x112;
x1565[x1557] = x1497;
int32_t* x1567 = x116;
x1567[x1557] = x1499;
x118 += 1;
int32_t x1570 = x1557;
int32_t x1571 = 0;
x1571 = x1502;
x1571 = x1506;
int32_t x1574 = x1510;
x1509[x1508] = x1557;
int32_t* x1576 = x121;
x1576[x1557] = x1510;
} else {
}

}
SWAP(x139,x75);
SWAP(x130,x66);
SWAP(x134,x70);
SWAP(x131,x67);
SWAP(x133,x69);
SWAP(x138,x74);
SWAP(x135,x71);
SWAP(x137,x73);
SWAP(x143,x79);
SWAP(x140,x76);
SWAP(x142,x78);
SWAP(x145,x81);
x75 = 0;
x79 = 0;
for(int x1596=0; x1596 < 16384; x1596++) {
int32_t* x1597 = x81;
x1597[x1596] = -1;

}
}
}
for(int x1605=0; x1605 < 16384; x1605++) {
int32_t* x1606 = x145;
x1606[x1605] = -1;

}
for(int x1610=0; x1610 < 16384; x1610++) {
int32_t* x1611 = x81;
x1611[x1610] = -1;

}
int32_t x1616 = x118;
FILE *x1615 = fopen("tcl.out","w");
for(int x1618=0; x1618 < x1616; x1618++) {
int32_t* x1619 = x112;
int32_t x1620 = x1619[x1618];
int32_t x1621 = fprintf(x1615,"%d",x1620);
int32_t x1622 = fprintf(x1615,"\t");
int32_t* x1623 = x116;
int32_t x1624 = x1623[x1618];
int32_t x1625 = fprintf(x1615,"%d",x1624);
int32_t x1626 = fprintf(x1615,"\n");

}
fclose(x1615);
for(int x1630=0; x1630 < 4194304; x1630++) {
int32_t* x1631 = x124;
x1631[x1630] = -1;

}
if (x352) {
} else {
for(int x1635=0; x1635 < x351; x1635++) {
int32_t* x1636 = x186;
int32_t* x1638 = x190;
bool x1640 = true;
int32_t x1641 = 0;
int32_t x1637 = x1636[x1635];
int32_t x1642 = x1637 + 233;
x1641 = x1642;
int32_t x1639 = x1638[x1635];
int32_t x1644 = x1642 * 1009;
int32_t x1645 = x1644 + x1639;
int32_t x1646 = x1645 + 233;
x1641 = x1646;
int32_t* x1649 = x102;
int32_t x1648 = x1646 & 4194303;
int32_t x1650 = x1649[x1648];
int32_t x1651 = x1650;
bool x1652 = true;
for (;;) {
bool x1653 = x1652;
bool x1657;
if (x1653) {
int32_t x1654 = x1651;
bool x1655 = x1654 != -1;
x1657 = x1655;
} else {
x1657 = false;
}
if (!x1657) break;
int32_t x1659 = x1651;
bool x1660 = true;
int32_t* x1661 = x90;
int32_t x1662 = x1661[x1659];
bool x1663 = x1637 == x1662;
if (x1663) {
} else {
x1660 = false;
}
int32_t* x1667 = x94;
int32_t x1668 = x1667[x1659];
bool x1669 = x1639 == x1668;
if (x1669) {
} else {
x1660 = false;
}
bool x1673 = x1660;
if (x1673) {
bool x1674 = true;
if (x1663) {
} else {
x1674 = false;
}
if (x1669) {
} else {
x1674 = false;
}
bool x1681 = x1674;
if (x1681) {
x1640 = false;
} else {
}
bool x1685 = x1640;
x1652 = x1685;
} else {
}
int32_t* x1689 = x99;
int32_t x1690 = x1689[x1659];
x1651 = x1690;
}
bool x1694 = x1640;
if (x1694) {
int32_t x1697 = x96;
int32_t x1698 = x87;
bool x1699 = x1697 == x1698;
if (x1699) {
x87 *= 4;
int32_t x1701 = x87;
printf("buffer.resize %d\n",x1701);
} else {
}
int32_t* x1705 = x90;
x1705[x1697] = x1637;
int32_t* x1707 = x94;
x1707[x1697] = x1639;
x96 += 1;
int32_t x1710 = x1697;
int32_t x1711 = 0;
x1711 = x1642;
x1711 = x1646;
int32_t x1714 = x1650;
x1649[x1648] = x1697;
int32_t* x1716 = x99;
x1716[x1697] = x1650;
} else {
}

}
}
int32_t x1724 = x96;
for(int x1726=0; x1726 < x1724; x1726++) {
int32_t* x1727 = x90;
int32_t* x1729 = x94;
bool x1731 = true;
int32_t x1732 = 0;
int32_t x1728 = x1727[x1726];
int32_t x1733 = x1728 + 233;
x1732 = x1733;
int32_t x1730 = x1729[x1726];
int32_t x1735 = x1733 * 1009;
int32_t x1736 = x1735 + x1730;
int32_t x1737 = x1736 + 233;
x1732 = x1737;
int32_t* x1740 = x170;
int32_t x1739 = x1737 & 16383;
int32_t x1741 = x1740[x1739];
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
int32_t* x1752 = x154;
int32_t x1753 = x1752[x1750];
bool x1754 = x1728 == x1753;
if (x1754) {
} else {
x1751 = false;
}
int32_t* x1758 = x158;
int32_t x1759 = x1758[x1750];
bool x1760 = x1730 == x1759;
if (x1760) {
} else {
x1751 = false;
}
bool x1764 = x1751;
if (x1764) {
bool x1765 = true;
if (x1754) {
} else {
x1765 = false;
}
if (x1760) {
} else {
x1765 = false;
}
bool x1772 = x1765;
if (x1772) {
x1731 = false;
} else {
}
bool x1776 = x1731;
x1743 = x1776;
} else {
}
int32_t* x1780 = x163;
int32_t x1781 = x1780[x1750];
x1742 = x1781;
}
bool x1785 = x1731;
if (x1785) {
int32_t x1788 = x160;
int32_t x1789 = x151;
bool x1790 = x1788 == x1789;
if (x1790) {
x151 *= 4;
int32_t x1792 = x151;
printf("buffer.resize %d\n",x1792);
} else {
}
int32_t* x1796 = x154;
x1796[x1788] = x1728;
int32_t* x1798 = x158;
x1798[x1788] = x1730;
x160 += 1;
int32_t x1801 = x1788;
int32_t x1802 = 0;
x1802 = x1733;
x1802 = x1737;
int32_t x1805 = x1741;
x1740[x1739] = x1788;
int32_t* x1807 = x163;
x1807[x1788] = x1741;
int32_t x1809 = 0;
x1809 = x1733;
int32_t* x1812 = x172;
int32_t x1811 = x1733 & 16383;
int32_t x1813 = x1812[x1811];
int32_t x1814 = x1813;
x1812[x1811] = x1788;
int32_t* x1816 = x167;
x1816[x1788] = x1813;
} else {
}

}
bool x1822 = true;
for (;;) {
bool x1823 = x1822;
if (!x1823) break;
int32_t x1825 = x192;
bool x1826 = x1825 == 0;
bool x1832;
if (x1826) {
x1832 = false;
} else {
int32_t x1828 = x160;
bool x1829 = x1828 == 0;
bool x1830 = !x1829;
x1832 = x1830;
}
if (x1832) {
for(int x1834=0; x1834 < x1825; x1834++) {
int32_t* x1835 = x190;
int32_t x1837 = 0;
int32_t x1836 = x1835[x1834];
int32_t x1838 = x1836 + 233;
x1837 = x1838;
int32_t* x1841 = x172;
int32_t x1840 = x1838 & 16383;
int32_t x1842 = x1841[x1840];
int32_t x1843 = x1842;
for (;;) {
int32_t x1844 = x1843;
bool x1845 = x1844 != -1;
if (!x1845) break;
int32_t x1847 = x1843;
bool x1848 = true;
int32_t* x1849 = x154;
int32_t x1850 = x1849[x1847];
bool x1851 = x1836 == x1850;
if (x1851) {
} else {
x1848 = false;
}
bool x1855 = x1848;
if (x1855) {
int32_t* x1856 = x186;
int32_t* x1858 = x158;
bool x1860 = false;
int32_t x1861 = 0;
int32_t x1857 = x1856[x1834];
int32_t x1862 = x1857 + 233;
x1861 = x1862;
int32_t x1859 = x1858[x1847];
int32_t x1864 = x1862 * 1009;
int32_t x1865 = x1864 + x1859;
int32_t x1866 = x1865 + 233;
x1861 = x1866;
int32_t* x1869 = x102;
int32_t x1868 = x1866 & 4194303;
int32_t x1870 = x1869[x1868];
int32_t x1871 = x1870;
bool x1872 = true;
for (;;) {
bool x1873 = x1872;
bool x1877;
if (x1873) {
int32_t x1874 = x1871;
bool x1875 = x1874 != -1;
x1877 = x1875;
} else {
x1877 = false;
}
if (!x1877) break;
int32_t x1879 = x1871;
bool x1880 = true;
int32_t* x1881 = x90;
int32_t x1882 = x1881[x1879];
bool x1883 = x1857 == x1882;
if (x1883) {
} else {
x1880 = false;
}
int32_t* x1887 = x94;
int32_t x1888 = x1887[x1879];
bool x1889 = x1859 == x1888;
if (x1889) {
} else {
x1880 = false;
}
bool x1893 = x1880;
if (x1893) {
x1860 = true;
x1872 = false;
} else {
}
int32_t* x1898 = x99;
int32_t x1899 = x1898[x1879];
x1871 = x1899;
}
bool x1903 = x1860;
if (x1903) {
} else {
bool x1905 = true;
int32_t x1906 = 0;
x1906 = x1862;
x1906 = x1866;
int32_t* x1910 = x266;
int32_t x1909 = x1866 & 16383;
int32_t x1911 = x1910[x1909];
int32_t x1912 = x1911;
bool x1913 = true;
for (;;) {
bool x1914 = x1913;
bool x1918;
if (x1914) {
int32_t x1915 = x1912;
bool x1916 = x1915 != -1;
x1918 = x1916;
} else {
x1918 = false;
}
if (!x1918) break;
int32_t x1920 = x1912;
bool x1921 = true;
int32_t* x1922 = x250;
int32_t x1923 = x1922[x1920];
bool x1924 = x1857 == x1923;
if (x1924) {
} else {
x1921 = false;
}
int32_t* x1928 = x254;
int32_t x1929 = x1928[x1920];
bool x1930 = x1859 == x1929;
if (x1930) {
} else {
x1921 = false;
}
bool x1934 = x1921;
if (x1934) {
bool x1935 = true;
if (x1924) {
} else {
x1935 = false;
}
if (x1930) {
} else {
x1935 = false;
}
bool x1942 = x1935;
if (x1942) {
x1905 = false;
} else {
}
bool x1946 = x1905;
x1913 = x1946;
} else {
}
int32_t* x1950 = x259;
int32_t x1951 = x1950[x1920];
x1912 = x1951;
}
bool x1955 = x1905;
if (x1955) {
int32_t x1958 = x256;
int32_t x1959 = x247;
bool x1960 = x1958 == x1959;
if (x1960) {
x247 *= 4;
int32_t x1962 = x247;
printf("buffer.resize %d\n",x1962);
} else {
}
int32_t* x1966 = x250;
x1966[x1958] = x1857;
int32_t* x1968 = x254;
x1968[x1958] = x1859;
x256 += 1;
int32_t x1971 = x1958;
int32_t x1972 = 0;
x1972 = x1862;
x1972 = x1866;
int32_t x1975 = x1911;
x1910[x1909] = x1958;
int32_t* x1977 = x259;
x1977[x1958] = x1911;
int32_t x1979 = 0;
x1979 = x1862;
int32_t* x1982 = x268;
int32_t x1981 = x1862 & 16383;
int32_t x1983 = x1982[x1981];
int32_t x1984 = x1983;
x1982[x1981] = x1958;
int32_t* x1986 = x263;
x1986[x1958] = x1983;
} else {
}
}
} else {
}
int32_t* x1994 = x167;
int32_t x1995 = x1994[x1847];
x1843 = x1995;
}

}
} else {
}
int32_t x2003 = x256;
bool x2004 = x2003 == 0;
if (x2004) {
x1822 = false;
} else {
for(int x2008=0; x2008 < x2003; x2008++) {
int32_t* x2009 = x250;
int32_t* x2011 = x254;
bool x2013 = true;
int32_t x2014 = 0;
int32_t x2010 = x2009[x2008];
int32_t x2015 = x2010 + 233;
x2014 = x2015;
int32_t x2012 = x2011[x2008];
int32_t x2017 = x2015 * 1009;
int32_t x2018 = x2017 + x2012;
int32_t x2019 = x2018 + 233;
x2014 = x2019;
int32_t* x2022 = x102;
int32_t x2021 = x2019 & 4194303;
int32_t x2023 = x2022[x2021];
int32_t x2024 = x2023;
bool x2025 = true;
for (;;) {
bool x2026 = x2025;
bool x2030;
if (x2026) {
int32_t x2027 = x2024;
bool x2028 = x2027 != -1;
x2030 = x2028;
} else {
x2030 = false;
}
if (!x2030) break;
int32_t x2032 = x2024;
bool x2033 = true;
int32_t* x2034 = x90;
int32_t x2035 = x2034[x2032];
bool x2036 = x2010 == x2035;
if (x2036) {
} else {
x2033 = false;
}
int32_t* x2040 = x94;
int32_t x2041 = x2040[x2032];
bool x2042 = x2012 == x2041;
if (x2042) {
} else {
x2033 = false;
}
bool x2046 = x2033;
if (x2046) {
bool x2047 = true;
if (x2036) {
} else {
x2047 = false;
}
if (x2042) {
} else {
x2047 = false;
}
bool x2054 = x2047;
if (x2054) {
x2013 = false;
} else {
}
bool x2058 = x2013;
x2025 = x2058;
} else {
}
int32_t* x2062 = x99;
int32_t x2063 = x2062[x2032];
x2024 = x2063;
}
bool x2067 = x2013;
if (x2067) {
int32_t x2070 = x96;
int32_t x2071 = x87;
bool x2072 = x2070 == x2071;
if (x2072) {
x87 *= 4;
int32_t x2074 = x87;
printf("buffer.resize %d\n",x2074);
} else {
}
int32_t* x2078 = x90;
x2078[x2070] = x2010;
int32_t* x2080 = x94;
x2080[x2070] = x2012;
x96 += 1;
int32_t x2083 = x2070;
int32_t x2084 = 0;
x2084 = x2015;
x2084 = x2019;
int32_t x2087 = x2023;
x2022[x2021] = x2070;
int32_t* x2089 = x99;
x2089[x2070] = x2023;
} else {
}

}
SWAP(x160,x256);
SWAP(x151,x247);
SWAP(x155,x251);
SWAP(x152,x248);
SWAP(x154,x250);
SWAP(x159,x255);
SWAP(x156,x252);
SWAP(x158,x254);
SWAP(x164,x260);
SWAP(x161,x257);
SWAP(x163,x259);
SWAP(x168,x264);
SWAP(x165,x261);
SWAP(x167,x263);
SWAP(x170,x266);
SWAP(x172,x268);
x256 = 0;
x260 = 0;
x264 = 0;
for(int x2114=0; x2114 < 16384; x2114++) {
int32_t* x2115 = x266;
x2115[x2114] = -1;

}
for(int x2119=0; x2119 < 16384; x2119++) {
int32_t* x2120 = x268;
x2120[x2119] = -1;

}
}
}
for(int x2128=0; x2128 < 16384; x2128++) {
int32_t* x2129 = x170;
x2129[x2128] = -1;

}
for(int x2133=0; x2133 < 16384; x2133++) {
int32_t* x2134 = x172;
x2134[x2133] = -1;

}
for(int x2138=0; x2138 < 16384; x2138++) {
int32_t* x2139 = x266;
x2139[x2138] = -1;

}
for(int x2143=0; x2143 < 16384; x2143++) {
int32_t* x2144 = x268;
x2144[x2143] = -1;

}
int32_t x2149 = x96;
FILE *x2148 = fopen("tcr.out","w");
for(int x2151=0; x2151 < x2149; x2151++) {
int32_t* x2152 = x90;
int32_t x2153 = x2152[x2151];
int32_t x2154 = fprintf(x2148,"%d",x2153);
int32_t x2155 = fprintf(x2148,"\t");
int32_t* x2156 = x94;
int32_t x2157 = x2156[x2151];
int32_t x2158 = fprintf(x2148,"%d",x2157);
int32_t x2159 = fprintf(x2148,"\n");

}
fclose(x2148);
for(int x2163=0; x2163 < 4194304; x2163++) {
int32_t* x2164 = x102;
x2164[x2163] = -1;

}
for(int x2168=0; x2168 < 4194304; x2168++) {
int32_t* x2169 = x202;
x2169[x2168] = -1;

}
for(int x2173=0; x2173 < 4194304; x2173++) {
int32_t* x2174 = x204;
x2174[x2173] = -1;

}
}
/*****************************************
  End of C Generated Code                  
*******************************************/

