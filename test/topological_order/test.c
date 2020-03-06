
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
int32_t x5 = 0;
int32_t x6 = 4194304;
int32_t* x7 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x8 = 0;
int32_t* x9 = (int32_t*)malloc(4194304 * sizeof(int32_t));
for(int x11=0; x11 < 4194304; x11++) {
x9[x11] = -1;

}
int32_t x15 = 4194304;
int32_t x16 = 4194304;
int32_t* x17 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x18 = 0;
int32_t x19 = 4194304;
int32_t* x20 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x21 = 0;
int32_t x22 = 0;
int32_t x23 = 4194304;
int32_t* x24 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x25 = 0;
int32_t* x26 = (int32_t*)malloc(4194304 * sizeof(int32_t));
for(int x27=0; x27 < 4194304; x27++) {
x26[x27] = -1;

}
int32_t x31 = 4194304;
int32_t x32 = 4194304;
int32_t* x33 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x34 = 0;
int32_t x35 = 4194304;
int32_t* x36 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x37 = 0;
int32_t x38 = 0;
int32_t x39 = 4194304;
int32_t* x40 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x41 = 0;
int32_t x42 = 4194304;
int32_t* x43 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x44 = 0;
int32_t* x45 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x46 = (int32_t*)malloc(4194304 * sizeof(int32_t));
for(int x47=0; x47 < 4194304; x47++) {
x45[x47] = -1;

}
for(int x51=0; x51 < 4194304; x51++) {
x46[x51] = -1;

}
int32_t x55 = 4194304;
int32_t x56 = 4194304;
int32_t* x57 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x58 = 0;
int32_t x59 = 4194304;
int32_t* x60 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x61 = 0;
int32_t x62 = 0;
int32_t x63 = 4194304;
int32_t* x64 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x65 = 0;
int32_t x66 = 4194304;
int32_t* x67 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x68 = 0;
int32_t* x69 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x70 = (int32_t*)malloc(4194304 * sizeof(int32_t));
for(int x71=0; x71 < 4194304; x71++) {
x69[x71] = -1;

}
for(int x75=0; x75 < 4194304; x75++) {
x70[x75] = -1;

}
int32_t x79 = 4194304;
int32_t x80 = 4194304;
int32_t* x81 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x82 = 0;
int32_t x83 = 4194304;
int32_t* x84 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x85 = 0;
int32_t x86 = 0;
int32_t x87 = 4194304;
int32_t* x88 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x89 = 0;
int32_t x90 = 4194304;
int32_t* x91 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x92 = 0;
int32_t* x93 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x94 = (int32_t*)malloc(4194304 * sizeof(int32_t));
for(int x95=0; x95 < 4194304; x95++) {
x93[x95] = -1;

}
for(int x99=0; x99 < 4194304; x99++) {
x94[x99] = -1;

}
int32_t x103 = 4194304;
int32_t x104 = 4194304;
int32_t* x105 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x106 = 0;
int32_t x107 = 4194304;
int32_t* x108 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x109 = 0;
int32_t x110 = 0;
int32_t x111 = 4194304;
int32_t* x112 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x113 = 0;
int32_t x114 = 4194304;
int32_t* x115 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x116 = 0;
int32_t* x117 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x118 = (int32_t*)malloc(4194304 * sizeof(int32_t));
for(int x119=0; x119 < 4194304; x119++) {
x117[x119] = -1;

}
for(int x123=0; x123 < 4194304; x123++) {
x118[x123] = -1;

}
int32_t x127 = 4194304;
int32_t x128 = 4194304;
int32_t* x129 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x130 = 0;
int32_t x131 = 4194304;
int32_t* x132 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x133 = 0;
int32_t x134 = 0;
int32_t x135 = 4194304;
int32_t* x136 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x137 = 0;
int32_t x138 = 4194304;
int32_t* x139 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x140 = 0;
int32_t* x141 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x142 = (int32_t*)malloc(4194304 * sizeof(int32_t));
for(int x143=0; x143 < 4194304; x143++) {
x141[x143] = -1;

}
for(int x147=0; x147 < 4194304; x147++) {
x142[x147] = -1;

}
int32_t x151 = 4194304;
int32_t x152 = 4194304;
int32_t* x153 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x154 = 0;
int32_t x155 = 4194304;
int32_t* x156 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x157 = 0;
int32_t x158 = 0;
int32_t x159 = 4194304;
int32_t* x160 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x161 = 0;
int32_t x162 = 4194304;
int32_t* x163 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x164 = 0;
int32_t x165 = 4194304;
int32_t* x166 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x167 = 0;
int32_t* x168 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x169 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x170 = (int32_t*)malloc(4194304 * sizeof(int32_t));
for(int x171=0; x171 < 4194304; x171++) {
x168[x171] = -1;

}
for(int x175=0; x175 < 4194304; x175++) {
x169[x175] = -1;

}
for(int x179=0; x179 < 4194304; x179++) {
x170[x179] = -1;

}
int32_t x183 = 4194304;
int32_t x184 = 4194304;
int32_t* x185 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x186 = 0;
int32_t x187 = 4194304;
int32_t* x188 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x189 = 0;
int32_t x190 = 0;
int32_t x191 = 4194304;
int32_t* x192 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x193 = 0;
int32_t x194 = 4194304;
int32_t* x195 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x196 = 0;
int32_t* x197 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x198 = (int32_t*)malloc(4194304 * sizeof(int32_t));
for(int x199=0; x199 < 4194304; x199++) {
x197[x199] = -1;

}
for(int x203=0; x203 < 4194304; x203++) {
x198[x203] = -1;

}
int32_t x207 = 4194304;
int32_t x208 = 4194304;
int32_t* x209 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x210 = 0;
int32_t x211 = 4194304;
int32_t* x212 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x213 = 0;
int32_t x214 = 0;
int32_t x215 = 4194304;
int32_t* x216 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x217 = 0;
int32_t x218 = 4194304;
int32_t* x219 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x220 = 0;
int32_t* x221 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x222 = (int32_t*)malloc(4194304 * sizeof(int32_t));
for(int x223=0; x223 < 4194304; x223++) {
x221[x223] = -1;

}
for(int x227=0; x227 < 4194304; x227++) {
x222[x227] = -1;

}
int32_t x231 = 4194304;
int32_t x232 = 4194304;
int32_t* x233 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x234 = 0;
int32_t x235 = 4194304;
int32_t* x236 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x237 = 0;
int32_t x238 = 0;
int32_t x239 = 4194304;
int32_t* x240 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x241 = 0;
int32_t x242 = 4194304;
int32_t* x243 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x244 = 0;
int32_t* x245 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x246 = (int32_t*)malloc(4194304 * sizeof(int32_t));
for(int x247=0; x247 < 4194304; x247++) {
x245[x247] = -1;

}
for(int x251=0; x251 < 4194304; x251++) {
x246[x251] = -1;

}
int32_t x255 = 4194304;
int32_t x256 = 4194304;
int32_t* x257 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x258 = 0;
int32_t x259 = 4194304;
int32_t* x260 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x261 = 0;
int32_t x262 = 0;
int32_t x263 = 4194304;
int32_t* x264 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t x265 = 0;
int32_t* x266 = (int32_t*)malloc(4194304 * sizeof(int32_t));
for(int x267=0; x267 < 4194304; x267++) {
x266[x267] = -1;

}
int32_t x274 = 0;
int32_t x271 = open("./edge.facts",0);
int32_t x272 = fsize(x271);
char* x273 = mmap(0, x272, PROT_READ, MAP_FILE | MAP_SHARED, x271, 0);
for (;;) {
int32_t x275 = x274;
bool x276 = x275 < x272;
if (!x276) break;
int32_t x278 = x274;
for (;;) {
int32_t x279 = x274;
char x280 = x273[x279];
bool x281 = x280 != '\t';
if (!x281) break;
x274 += 1;
}
int32_t x286 = x274;
x274 += 1;
char* x289 = x273+x278;
int32_t x290 = atoi(x289);
int32_t x291 = x274;
for (;;) {
int32_t x292 = x274;
char x293 = x273[x292];
bool x294 = x293 != '\n';
if (!x294) break;
x274 += 1;
}
int32_t x299 = x274;
x274 += 1;
char* x302 = x273+x291;
int32_t x303 = atoi(x302);
int32_t x304 = x158;
int32_t x305 = x151;
bool x306 = x304 == x305;
if (x306) {
x151 *= 4;
int32_t x308 = x151;
printf("buffer.resize %d\n",x308);
} else {
}
x153[x304] = x290;
x156[x304] = x303;
x158 += 1;
int32_t x315 = 1;
x315 *= x290;
x315 *= x303;
int32_t x318 = x315;
int32_t x319 = x318 & 4194303;
int32_t x320 = x168[x319];
int32_t x321 = x320;
x168[x319] = x304;
x160[x304] = x320;
int32_t x324 = 1;
x324 *= x303;
int32_t x326 = x324;
int32_t x327 = x326 & 4194303;
int32_t x328 = x169[x327];
int32_t x329 = x328;
x169[x327] = x304;
x163[x304] = x328;
int32_t x332 = 1;
x332 *= x290;
int32_t x334 = x332;
int32_t x335 = x334 & 4194303;
int32_t x336 = x170[x335];
int32_t x337 = x336;
x170[x335] = x304;
x166[x304] = x336;
}
int32_t x342 = x158;
bool x343 = x342 == 0;
if (x343) {
} else {
for(int x346=0; x346 < x342; x346++) {
bool x349 = true;
int32_t x350 = 1;
int32_t x347 = x156[x346];
x350 *= x347;
int32_t x348 = x153[x346];
x350 *= x348;
int32_t x353 = x350;
int32_t x354 = x353 & 4194303;
int32_t x355 = x221[x354];
int32_t x356 = x355;
bool x357 = true;
for (;;) {
bool x358 = x357;
bool x362;
if (x358) {
int32_t x359 = x356;
bool x360 = x359 != -1;
x362 = x360;
} else {
x362 = false;
}
if (!x362) break;
int32_t x364 = x356;
int32_t x365 = x216[x364];
x356 = x365;
bool x367 = true;
int32_t x368 = x209[x364];
bool x369 = x347 == x368;
if (x369) {
} else {
x367 = false;
}
int32_t x373 = x212[x364];
bool x374 = x348 == x373;
if (x374) {
} else {
x367 = false;
}
bool x378 = x367;
if (x378) {
bool x379 = true;
if (x369) {
} else {
x379 = false;
}
if (x374) {
} else {
x379 = false;
}
bool x386 = x379;
if (x386) {
x349 = false;
} else {
}
bool x390 = x349;
x357 = x390;
} else {
}
}
bool x396 = x349;
if (x396) {
int32_t x399 = x214;
int32_t x400 = x207;
bool x401 = x399 == x400;
if (x401) {
x207 *= 4;
int32_t x403 = x207;
printf("buffer.resize %d\n",x403);
} else {
}
x209[x399] = x347;
x212[x399] = x348;
x214 += 1;
int32_t x410 = 1;
x410 *= x347;
x410 *= x348;
int32_t x413 = x410;
int32_t x414 = x413 & 4194303;
int32_t x415 = x221[x414];
int32_t x416 = x415;
x221[x414] = x399;
x216[x399] = x415;
int32_t x419 = 1;
x419 *= x348;
int32_t x421 = x419;
int32_t x422 = x421 & 4194303;
int32_t x423 = x222[x422];
int32_t x424 = x423;
x222[x422] = x399;
x219[x399] = x423;
} else {
}

}
}
int32_t x433 = x214;
for(int x435=0; x435 < x433; x435++) {
bool x438 = true;
int32_t x439 = 1;
int32_t x436 = x209[x435];
x439 *= x436;
int32_t x437 = x212[x435];
x439 *= x437;
int32_t x442 = x439;
int32_t x443 = x442 & 4194303;
int32_t x444 = x245[x443];
int32_t x445 = x444;
bool x446 = true;
for (;;) {
bool x447 = x446;
bool x451;
if (x447) {
int32_t x448 = x445;
bool x449 = x448 != -1;
x451 = x449;
} else {
x451 = false;
}
if (!x451) break;
int32_t x453 = x445;
int32_t x454 = x240[x453];
x445 = x454;
bool x456 = true;
int32_t x457 = x233[x453];
bool x458 = x436 == x457;
if (x458) {
} else {
x456 = false;
}
int32_t x462 = x236[x453];
bool x463 = x437 == x462;
if (x463) {
} else {
x456 = false;
}
bool x467 = x456;
if (x467) {
bool x468 = true;
if (x458) {
} else {
x468 = false;
}
if (x463) {
} else {
x468 = false;
}
bool x475 = x468;
if (x475) {
x438 = false;
} else {
}
bool x479 = x438;
x446 = x479;
} else {
}
}
bool x485 = x438;
if (x485) {
int32_t x488 = x238;
int32_t x489 = x231;
bool x490 = x488 == x489;
if (x490) {
x231 *= 4;
int32_t x492 = x231;
printf("buffer.resize %d\n",x492);
} else {
}
x233[x488] = x436;
x236[x488] = x437;
x238 += 1;
int32_t x499 = 1;
x499 *= x436;
x499 *= x437;
int32_t x502 = x499;
int32_t x503 = x502 & 4194303;
int32_t x504 = x245[x503];
int32_t x505 = x504;
x245[x503] = x488;
x240[x488] = x504;
int32_t x508 = 1;
x508 *= x437;
int32_t x510 = x508;
int32_t x511 = x510 & 4194303;
int32_t x512 = x246[x511];
int32_t x513 = x512;
x246[x511] = x488;
x243[x488] = x512;
} else {
}

}
bool x520 = true;
for (;;) {
bool x521 = x520;
if (!x521) break;
int32_t x523 = x238;
bool x524 = x523 == 0;
bool x530;
if (x524) {
x530 = false;
} else {
int32_t x526 = x214;
bool x527 = x526 == 0;
bool x528 = !x527;
x530 = x528;
}
if (x530) {
for(int x532=0; x532 < x523; x532++) {
int32_t x534 = 1;
int32_t x533 = x233[x532];
x534 *= x533;
int32_t x536 = x534;
int32_t x537 = x536 & 4194303;
int32_t x538 = x222[x537];
int32_t x539 = x538;
int32_t x592 = x236[x532];
for (;;) {
int32_t x540 = x539;
bool x541 = x540 != -1;
if (!x541) break;
int32_t x543 = x539;
int32_t x544 = x219[x543];
x539 = x544;
bool x546 = true;
int32_t x547 = x212[x543];
bool x548 = x533 == x547;
if (x548) {
} else {
x546 = false;
}
bool x552 = x546;
if (x552) {
bool x554 = false;
int32_t x555 = 1;
int32_t x553 = x209[x543];
x555 *= x553;
x555 *= x533;
int32_t x558 = x555;
int32_t x559 = x558 & 4194303;
int32_t x560 = x245[x559];
int32_t x561 = x560;
bool x562 = true;
for (;;) {
bool x563 = x562;
bool x567;
if (x563) {
int32_t x564 = x561;
bool x565 = x564 != -1;
x567 = x565;
} else {
x567 = false;
}
if (!x567) break;
int32_t x569 = x561;
int32_t x570 = x240[x569];
x561 = x570;
bool x572 = true;
int32_t x573 = x233[x569];
bool x574 = x553 == x573;
if (x574) {
} else {
x572 = false;
}
int32_t x578 = x236[x569];
bool x579 = x533 == x578;
if (x579) {
} else {
x572 = false;
}
bool x583 = x572;
if (x583) {
x554 = true;
x562 = false;
} else {
}
}
bool x590 = x554;
bool x632;
if (x590) {
x632 = false;
} else {
bool x593 = false;
int32_t x594 = 1;
x594 *= x592;
x594 *= x553;
int32_t x597 = x594;
int32_t x598 = x597 & 4194303;
int32_t x599 = x221[x598];
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
int32_t x609 = x216[x608];
x600 = x609;
bool x611 = true;
int32_t x612 = x209[x608];
bool x613 = x592 == x612;
if (x613) {
} else {
x611 = false;
}
int32_t x617 = x212[x608];
bool x618 = x553 == x617;
if (x618) {
} else {
x611 = false;
}
bool x622 = x611;
if (x622) {
x593 = true;
x601 = false;
} else {
}
}
bool x629 = x593;
bool x630 = !x629;
x632 = x630;
}
if (x632) {
bool x633 = true;
int32_t x634 = 1;
x634 *= x592;
x634 *= x553;
int32_t x637 = x634;
int32_t x638 = x637 & 4194303;
int32_t x639 = x117[x638];
int32_t x640 = x639;
bool x641 = true;
for (;;) {
bool x642 = x641;
bool x646;
if (x642) {
int32_t x643 = x640;
bool x644 = x643 != -1;
x646 = x644;
} else {
x646 = false;
}
if (!x646) break;
int32_t x648 = x640;
int32_t x649 = x112[x648];
x640 = x649;
bool x651 = true;
int32_t x652 = x105[x648];
bool x653 = x592 == x652;
if (x653) {
} else {
x651 = false;
}
int32_t x657 = x108[x648];
bool x658 = x553 == x657;
if (x658) {
} else {
x651 = false;
}
bool x662 = x651;
if (x662) {
bool x663 = true;
if (x653) {
} else {
x663 = false;
}
if (x658) {
} else {
x663 = false;
}
bool x670 = x663;
if (x670) {
x633 = false;
} else {
}
bool x674 = x633;
x641 = x674;
} else {
}
}
bool x680 = x633;
if (x680) {
int32_t x683 = x110;
int32_t x684 = x103;
bool x685 = x683 == x684;
if (x685) {
x103 *= 4;
int32_t x687 = x103;
printf("buffer.resize %d\n",x687);
} else {
}
x105[x683] = x592;
x108[x683] = x553;
x110 += 1;
int32_t x694 = 1;
x694 *= x592;
x694 *= x553;
int32_t x697 = x694;
int32_t x698 = x697 & 4194303;
int32_t x699 = x117[x698];
int32_t x700 = x699;
x117[x698] = x683;
x112[x683] = x699;
int32_t x703 = 1;
x703 *= x553;
int32_t x705 = x703;
int32_t x706 = x705 & 4194303;
int32_t x707 = x118[x706];
int32_t x708 = x707;
x118[x706] = x683;
x115[x683] = x707;
} else {
}
} else {
}
} else {
}
}

}
} else {
}
int32_t x723 = x214;
bool x724 = x723 == 0;
bool x726;
if (x724) {
x726 = false;
} else {
bool x525 = !x524;
x726 = x525;
}
if (x726) {
for(int x728=0; x728 < x723; x728++) {
int32_t x730 = 1;
int32_t x729 = x209[x728];
x730 *= x729;
int32_t x732 = x730;
int32_t x733 = x732 & 4194303;
int32_t x734 = x246[x733];
int32_t x735 = x734;
int32_t x749 = x212[x728];
for (;;) {
int32_t x736 = x735;
bool x737 = x736 != -1;
if (!x737) break;
int32_t x739 = x735;
int32_t x740 = x243[x739];
x735 = x740;
bool x742 = true;
int32_t x743 = x236[x739];
bool x744 = x729 == x743;
if (x744) {
} else {
x742 = false;
}
bool x748 = x742;
if (x748) {
bool x751 = false;
int32_t x752 = 1;
x752 *= x749;
int32_t x750 = x233[x739];
x752 *= x750;
int32_t x755 = x752;
int32_t x756 = x755 & 4194303;
int32_t x757 = x221[x756];
int32_t x758 = x757;
bool x759 = true;
for (;;) {
bool x760 = x759;
bool x764;
if (x760) {
int32_t x761 = x758;
bool x762 = x761 != -1;
x764 = x762;
} else {
x764 = false;
}
if (!x764) break;
int32_t x766 = x758;
int32_t x767 = x216[x766];
x758 = x767;
bool x769 = true;
int32_t x770 = x209[x766];
bool x771 = x749 == x770;
if (x771) {
} else {
x769 = false;
}
int32_t x775 = x212[x766];
bool x776 = x750 == x775;
if (x776) {
} else {
x769 = false;
}
bool x780 = x769;
if (x780) {
x751 = true;
x759 = false;
} else {
}
}
bool x787 = x751;
if (x787) {
} else {
bool x789 = true;
int32_t x790 = 1;
x790 *= x749;
x790 *= x750;
int32_t x793 = x790;
int32_t x794 = x793 & 4194303;
int32_t x795 = x117[x794];
int32_t x796 = x795;
bool x797 = true;
for (;;) {
bool x798 = x797;
bool x802;
if (x798) {
int32_t x799 = x796;
bool x800 = x799 != -1;
x802 = x800;
} else {
x802 = false;
}
if (!x802) break;
int32_t x804 = x796;
int32_t x805 = x112[x804];
x796 = x805;
bool x807 = true;
int32_t x808 = x105[x804];
bool x809 = x749 == x808;
if (x809) {
} else {
x807 = false;
}
int32_t x813 = x108[x804];
bool x814 = x750 == x813;
if (x814) {
} else {
x807 = false;
}
bool x818 = x807;
if (x818) {
bool x819 = true;
if (x809) {
} else {
x819 = false;
}
if (x814) {
} else {
x819 = false;
}
bool x826 = x819;
if (x826) {
x789 = false;
} else {
}
bool x830 = x789;
x797 = x830;
} else {
}
}
bool x836 = x789;
if (x836) {
int32_t x839 = x110;
int32_t x840 = x103;
bool x841 = x839 == x840;
if (x841) {
x103 *= 4;
int32_t x843 = x103;
printf("buffer.resize %d\n",x843);
} else {
}
x105[x839] = x749;
x108[x839] = x750;
x110 += 1;
int32_t x850 = 1;
x850 *= x749;
x850 *= x750;
int32_t x853 = x850;
int32_t x854 = x853 & 4194303;
int32_t x855 = x117[x854];
int32_t x856 = x855;
x117[x854] = x839;
x112[x839] = x855;
int32_t x859 = 1;
x859 *= x750;
int32_t x861 = x859;
int32_t x862 = x861 & 4194303;
int32_t x863 = x118[x862];
int32_t x864 = x863;
x118[x862] = x839;
x115[x839] = x863;
} else {
}
}
} else {
}
}

}
} else {
}
int32_t x879 = x110;
bool x880 = x879 == 0;
if (x880) {
x520 = false;
} else {
for(int x884=0; x884 < x879; x884++) {
bool x887 = true;
int32_t x888 = 1;
int32_t x885 = x105[x884];
x888 *= x885;
int32_t x886 = x108[x884];
x888 *= x886;
int32_t x891 = x888;
int32_t x892 = x891 & 4194303;
int32_t x893 = x221[x892];
int32_t x894 = x893;
bool x895 = true;
for (;;) {
bool x896 = x895;
bool x900;
if (x896) {
int32_t x897 = x894;
bool x898 = x897 != -1;
x900 = x898;
} else {
x900 = false;
}
if (!x900) break;
int32_t x902 = x894;
int32_t x903 = x216[x902];
x894 = x903;
bool x905 = true;
int32_t x906 = x209[x902];
bool x907 = x885 == x906;
if (x907) {
} else {
x905 = false;
}
int32_t x911 = x212[x902];
bool x912 = x886 == x911;
if (x912) {
} else {
x905 = false;
}
bool x916 = x905;
if (x916) {
bool x917 = true;
if (x907) {
} else {
x917 = false;
}
if (x912) {
} else {
x917 = false;
}
bool x924 = x917;
if (x924) {
x887 = false;
} else {
}
bool x928 = x887;
x895 = x928;
} else {
}
}
bool x934 = x887;
if (x934) {
int32_t x937 = x214;
int32_t x938 = x207;
bool x939 = x937 == x938;
if (x939) {
x207 *= 4;
int32_t x941 = x207;
printf("buffer.resize %d\n",x941);
} else {
}
x209[x937] = x885;
x212[x937] = x886;
x214 += 1;
int32_t x948 = 1;
x948 *= x885;
x948 *= x886;
int32_t x951 = x948;
int32_t x952 = x951 & 4194303;
int32_t x953 = x221[x952];
int32_t x954 = x953;
x221[x952] = x937;
x216[x937] = x953;
int32_t x957 = 1;
x957 *= x886;
int32_t x959 = x957;
int32_t x960 = x959 & 4194303;
int32_t x961 = x222[x960];
int32_t x962 = x961;
x222[x960] = x937;
x219[x937] = x961;
} else {
}

}
SWAP(x238,x110);
SWAP(x231,x103);
SWAP(x234,x106);
SWAP(x232,x104);
SWAP(x233,x105);
SWAP(x237,x109);
SWAP(x235,x107);
SWAP(x236,x108);
SWAP(x241,x113);
SWAP(x239,x111);
SWAP(x240,x112);
SWAP(x244,x116);
SWAP(x242,x114);
SWAP(x243,x115);
SWAP(x245,x117);
SWAP(x246,x118);
x110 = 0;
x113 = 0;
x116 = 0;
for(int x988=0; x988 < 4194304; x988++) {
x117[x988] = -1;

}
for(int x992=0; x992 < 4194304; x992++) {
x118[x992] = -1;

}
}
}
for(int x1000=0; x1000 < 4194304; x1000++) {
x245[x1000] = -1;

}
for(int x1004=0; x1004 < 4194304; x1004++) {
x246[x1004] = -1;

}
for(int x1008=0; x1008 < 4194304; x1008++) {
x117[x1008] = -1;

}
for(int x1012=0; x1012 < 4194304; x1012++) {
x118[x1012] = -1;

}
int32_t x1017 = x214;
FILE *x1016 = fopen("is_after.out","w");
for(int x1019=0; x1019 < x1017; x1019++) {
int32_t x1020 = x209[x1019];
int32_t x1021 = fprintf(x1016,"%d",x1020);
int32_t x1022 = fprintf(x1016,"\t");
int32_t x1023 = x212[x1019];
int32_t x1024 = fprintf(x1016,"%d",x1023);
int32_t x1025 = fprintf(x1016,"\n");

}
fclose(x1016);
if (x343) {
} else {
for(int x1029=0; x1029 < x342; x1029++) {
bool x1032 = true;
int32_t x1033 = 1;
int32_t x1030 = x153[x1029];
x1033 *= x1030;
int32_t x1031 = x156[x1029];
x1033 *= x1031;
int32_t x1036 = x1033;
int32_t x1037 = x1036 & 4194303;
int32_t x1038 = x93[x1037];
int32_t x1039 = x1038;
bool x1040 = true;
for (;;) {
bool x1041 = x1040;
bool x1045;
if (x1041) {
int32_t x1042 = x1039;
bool x1043 = x1042 != -1;
x1045 = x1043;
} else {
x1045 = false;
}
if (!x1045) break;
int32_t x1047 = x1039;
int32_t x1048 = x88[x1047];
x1039 = x1048;
bool x1050 = true;
int32_t x1051 = x81[x1047];
bool x1052 = x1030 == x1051;
if (x1052) {
} else {
x1050 = false;
}
int32_t x1056 = x84[x1047];
bool x1057 = x1031 == x1056;
if (x1057) {
} else {
x1050 = false;
}
bool x1061 = x1050;
if (x1061) {
bool x1062 = true;
if (x1052) {
} else {
x1062 = false;
}
if (x1057) {
} else {
x1062 = false;
}
bool x1069 = x1062;
if (x1069) {
x1032 = false;
} else {
}
bool x1073 = x1032;
x1040 = x1073;
} else {
}
}
bool x1079 = x1032;
if (x1079) {
int32_t x1082 = x86;
int32_t x1083 = x79;
bool x1084 = x1082 == x1083;
if (x1084) {
x79 *= 4;
int32_t x1086 = x79;
printf("buffer.resize %d\n",x1086);
} else {
}
x81[x1082] = x1030;
x84[x1082] = x1031;
x86 += 1;
int32_t x1093 = 1;
x1093 *= x1030;
x1093 *= x1031;
int32_t x1096 = x1093;
int32_t x1097 = x1096 & 4194303;
int32_t x1098 = x93[x1097];
int32_t x1099 = x1098;
x93[x1097] = x1082;
x88[x1082] = x1098;
int32_t x1102 = 1;
x1102 *= x1030;
int32_t x1104 = x1102;
int32_t x1105 = x1104 & 4194303;
int32_t x1106 = x94[x1105];
int32_t x1107 = x1106;
x94[x1105] = x1082;
x91[x1082] = x1106;
} else {
}

}
}
int32_t x1116 = x86;
for(int x1118=0; x1118 < x1116; x1118++) {
bool x1121 = true;
int32_t x1122 = 1;
int32_t x1119 = x81[x1118];
x1122 *= x1119;
int32_t x1120 = x84[x1118];
x1122 *= x1120;
int32_t x1125 = x1122;
int32_t x1126 = x1125 & 4194303;
int32_t x1127 = x141[x1126];
int32_t x1128 = x1127;
bool x1129 = true;
for (;;) {
bool x1130 = x1129;
bool x1134;
if (x1130) {
int32_t x1131 = x1128;
bool x1132 = x1131 != -1;
x1134 = x1132;
} else {
x1134 = false;
}
if (!x1134) break;
int32_t x1136 = x1128;
int32_t x1137 = x136[x1136];
x1128 = x1137;
bool x1139 = true;
int32_t x1140 = x129[x1136];
bool x1141 = x1119 == x1140;
if (x1141) {
} else {
x1139 = false;
}
int32_t x1145 = x132[x1136];
bool x1146 = x1120 == x1145;
if (x1146) {
} else {
x1139 = false;
}
bool x1150 = x1139;
if (x1150) {
bool x1151 = true;
if (x1141) {
} else {
x1151 = false;
}
if (x1146) {
} else {
x1151 = false;
}
bool x1158 = x1151;
if (x1158) {
x1121 = false;
} else {
}
bool x1162 = x1121;
x1129 = x1162;
} else {
}
}
bool x1168 = x1121;
if (x1168) {
int32_t x1171 = x134;
int32_t x1172 = x127;
bool x1173 = x1171 == x1172;
if (x1173) {
x127 *= 4;
int32_t x1175 = x127;
printf("buffer.resize %d\n",x1175);
} else {
}
x129[x1171] = x1119;
x132[x1171] = x1120;
x134 += 1;
int32_t x1182 = 1;
x1182 *= x1119;
x1182 *= x1120;
int32_t x1185 = x1182;
int32_t x1186 = x1185 & 4194303;
int32_t x1187 = x141[x1186];
int32_t x1188 = x1187;
x141[x1186] = x1171;
x136[x1171] = x1187;
int32_t x1191 = 1;
x1191 *= x1119;
int32_t x1193 = x1191;
int32_t x1194 = x1193 & 4194303;
int32_t x1195 = x142[x1194];
int32_t x1196 = x1195;
x142[x1194] = x1171;
x139[x1171] = x1195;
} else {
}

}
bool x1203 = true;
for (;;) {
bool x1204 = x1203;
if (!x1204) break;
int32_t x1206 = x134;
bool x1207 = x1206 == 0;
bool x1213;
if (x1207) {
x1213 = false;
} else {
int32_t x1209 = x86;
bool x1210 = x1209 == 0;
bool x1211 = !x1210;
x1213 = x1211;
}
if (x1213) {
for(int x1215=0; x1215 < x1206; x1215++) {
int32_t x1217 = 1;
int32_t x1216 = x132[x1215];
x1217 *= x1216;
int32_t x1219 = x1217;
int32_t x1220 = x1219 & 4194303;
int32_t x1221 = x94[x1220];
int32_t x1222 = x1221;
int32_t x1275 = x129[x1215];
for (;;) {
int32_t x1223 = x1222;
bool x1224 = x1223 != -1;
if (!x1224) break;
int32_t x1226 = x1222;
int32_t x1227 = x91[x1226];
x1222 = x1227;
bool x1229 = true;
int32_t x1230 = x81[x1226];
bool x1231 = x1216 == x1230;
if (x1231) {
} else {
x1229 = false;
}
bool x1235 = x1229;
if (x1235) {
bool x1237 = false;
int32_t x1238 = 1;
x1238 *= x1216;
int32_t x1236 = x84[x1226];
x1238 *= x1236;
int32_t x1241 = x1238;
int32_t x1242 = x1241 & 4194303;
int32_t x1243 = x141[x1242];
int32_t x1244 = x1243;
bool x1245 = true;
for (;;) {
bool x1246 = x1245;
bool x1250;
if (x1246) {
int32_t x1247 = x1244;
bool x1248 = x1247 != -1;
x1250 = x1248;
} else {
x1250 = false;
}
if (!x1250) break;
int32_t x1252 = x1244;
int32_t x1253 = x136[x1252];
x1244 = x1253;
bool x1255 = true;
int32_t x1256 = x129[x1252];
bool x1257 = x1216 == x1256;
if (x1257) {
} else {
x1255 = false;
}
int32_t x1261 = x132[x1252];
bool x1262 = x1236 == x1261;
if (x1262) {
} else {
x1255 = false;
}
bool x1266 = x1255;
if (x1266) {
x1237 = true;
x1245 = false;
} else {
}
}
bool x1273 = x1237;
bool x1315;
if (x1273) {
x1315 = false;
} else {
bool x1276 = false;
int32_t x1277 = 1;
x1277 *= x1275;
x1277 *= x1236;
int32_t x1280 = x1277;
int32_t x1281 = x1280 & 4194303;
int32_t x1282 = x93[x1281];
int32_t x1283 = x1282;
bool x1284 = true;
for (;;) {
bool x1285 = x1284;
bool x1289;
if (x1285) {
int32_t x1286 = x1283;
bool x1287 = x1286 != -1;
x1289 = x1287;
} else {
x1289 = false;
}
if (!x1289) break;
int32_t x1291 = x1283;
int32_t x1292 = x88[x1291];
x1283 = x1292;
bool x1294 = true;
int32_t x1295 = x81[x1291];
bool x1296 = x1275 == x1295;
if (x1296) {
} else {
x1294 = false;
}
int32_t x1300 = x84[x1291];
bool x1301 = x1236 == x1300;
if (x1301) {
} else {
x1294 = false;
}
bool x1305 = x1294;
if (x1305) {
x1276 = true;
x1284 = false;
} else {
}
}
bool x1312 = x1276;
bool x1313 = !x1312;
x1315 = x1313;
}
if (x1315) {
bool x1316 = true;
int32_t x1317 = 1;
x1317 *= x1275;
x1317 *= x1236;
int32_t x1320 = x1317;
int32_t x1321 = x1320 & 4194303;
int32_t x1322 = x197[x1321];
int32_t x1323 = x1322;
bool x1324 = true;
for (;;) {
bool x1325 = x1324;
bool x1329;
if (x1325) {
int32_t x1326 = x1323;
bool x1327 = x1326 != -1;
x1329 = x1327;
} else {
x1329 = false;
}
if (!x1329) break;
int32_t x1331 = x1323;
int32_t x1332 = x192[x1331];
x1323 = x1332;
bool x1334 = true;
int32_t x1335 = x185[x1331];
bool x1336 = x1275 == x1335;
if (x1336) {
} else {
x1334 = false;
}
int32_t x1340 = x188[x1331];
bool x1341 = x1236 == x1340;
if (x1341) {
} else {
x1334 = false;
}
bool x1345 = x1334;
if (x1345) {
bool x1346 = true;
if (x1336) {
} else {
x1346 = false;
}
if (x1341) {
} else {
x1346 = false;
}
bool x1353 = x1346;
if (x1353) {
x1316 = false;
} else {
}
bool x1357 = x1316;
x1324 = x1357;
} else {
}
}
bool x1363 = x1316;
if (x1363) {
int32_t x1366 = x190;
int32_t x1367 = x183;
bool x1368 = x1366 == x1367;
if (x1368) {
x183 *= 4;
int32_t x1370 = x183;
printf("buffer.resize %d\n",x1370);
} else {
}
x185[x1366] = x1275;
x188[x1366] = x1236;
x190 += 1;
int32_t x1377 = 1;
x1377 *= x1275;
x1377 *= x1236;
int32_t x1380 = x1377;
int32_t x1381 = x1380 & 4194303;
int32_t x1382 = x197[x1381];
int32_t x1383 = x1382;
x197[x1381] = x1366;
x192[x1366] = x1382;
int32_t x1386 = 1;
x1386 *= x1275;
int32_t x1388 = x1386;
int32_t x1389 = x1388 & 4194303;
int32_t x1390 = x198[x1389];
int32_t x1391 = x1390;
x198[x1389] = x1366;
x195[x1366] = x1390;
} else {
}
} else {
}
} else {
}
}

}
} else {
}
int32_t x1406 = x86;
bool x1407 = x1406 == 0;
bool x1409;
if (x1407) {
x1409 = false;
} else {
bool x1208 = !x1207;
x1409 = x1208;
}
if (x1409) {
for(int x1411=0; x1411 < x1406; x1411++) {
int32_t x1413 = 1;
int32_t x1412 = x84[x1411];
x1413 *= x1412;
int32_t x1415 = x1413;
int32_t x1416 = x1415 & 4194303;
int32_t x1417 = x142[x1416];
int32_t x1418 = x1417;
int32_t x1432 = x81[x1411];
for (;;) {
int32_t x1419 = x1418;
bool x1420 = x1419 != -1;
if (!x1420) break;
int32_t x1422 = x1418;
int32_t x1423 = x139[x1422];
x1418 = x1423;
bool x1425 = true;
int32_t x1426 = x129[x1422];
bool x1427 = x1412 == x1426;
if (x1427) {
} else {
x1425 = false;
}
bool x1431 = x1425;
if (x1431) {
bool x1434 = false;
int32_t x1435 = 1;
x1435 *= x1432;
int32_t x1433 = x132[x1422];
x1435 *= x1433;
int32_t x1438 = x1435;
int32_t x1439 = x1438 & 4194303;
int32_t x1440 = x93[x1439];
int32_t x1441 = x1440;
bool x1442 = true;
for (;;) {
bool x1443 = x1442;
bool x1447;
if (x1443) {
int32_t x1444 = x1441;
bool x1445 = x1444 != -1;
x1447 = x1445;
} else {
x1447 = false;
}
if (!x1447) break;
int32_t x1449 = x1441;
int32_t x1450 = x88[x1449];
x1441 = x1450;
bool x1452 = true;
int32_t x1453 = x81[x1449];
bool x1454 = x1432 == x1453;
if (x1454) {
} else {
x1452 = false;
}
int32_t x1458 = x84[x1449];
bool x1459 = x1433 == x1458;
if (x1459) {
} else {
x1452 = false;
}
bool x1463 = x1452;
if (x1463) {
x1434 = true;
x1442 = false;
} else {
}
}
bool x1470 = x1434;
if (x1470) {
} else {
bool x1472 = true;
int32_t x1473 = 1;
x1473 *= x1432;
x1473 *= x1433;
int32_t x1476 = x1473;
int32_t x1477 = x1476 & 4194303;
int32_t x1478 = x197[x1477];
int32_t x1479 = x1478;
bool x1480 = true;
for (;;) {
bool x1481 = x1480;
bool x1485;
if (x1481) {
int32_t x1482 = x1479;
bool x1483 = x1482 != -1;
x1485 = x1483;
} else {
x1485 = false;
}
if (!x1485) break;
int32_t x1487 = x1479;
int32_t x1488 = x192[x1487];
x1479 = x1488;
bool x1490 = true;
int32_t x1491 = x185[x1487];
bool x1492 = x1432 == x1491;
if (x1492) {
} else {
x1490 = false;
}
int32_t x1496 = x188[x1487];
bool x1497 = x1433 == x1496;
if (x1497) {
} else {
x1490 = false;
}
bool x1501 = x1490;
if (x1501) {
bool x1502 = true;
if (x1492) {
} else {
x1502 = false;
}
if (x1497) {
} else {
x1502 = false;
}
bool x1509 = x1502;
if (x1509) {
x1472 = false;
} else {
}
bool x1513 = x1472;
x1480 = x1513;
} else {
}
}
bool x1519 = x1472;
if (x1519) {
int32_t x1522 = x190;
int32_t x1523 = x183;
bool x1524 = x1522 == x1523;
if (x1524) {
x183 *= 4;
int32_t x1526 = x183;
printf("buffer.resize %d\n",x1526);
} else {
}
x185[x1522] = x1432;
x188[x1522] = x1433;
x190 += 1;
int32_t x1533 = 1;
x1533 *= x1432;
x1533 *= x1433;
int32_t x1536 = x1533;
int32_t x1537 = x1536 & 4194303;
int32_t x1538 = x197[x1537];
int32_t x1539 = x1538;
x197[x1537] = x1522;
x192[x1522] = x1538;
int32_t x1542 = 1;
x1542 *= x1432;
int32_t x1544 = x1542;
int32_t x1545 = x1544 & 4194303;
int32_t x1546 = x198[x1545];
int32_t x1547 = x1546;
x198[x1545] = x1522;
x195[x1522] = x1546;
} else {
}
}
} else {
}
}

}
} else {
}
int32_t x1562 = x190;
bool x1563 = x1562 == 0;
if (x1563) {
x1203 = false;
} else {
for(int x1567=0; x1567 < x1562; x1567++) {
bool x1570 = true;
int32_t x1571 = 1;
int32_t x1568 = x185[x1567];
x1571 *= x1568;
int32_t x1569 = x188[x1567];
x1571 *= x1569;
int32_t x1574 = x1571;
int32_t x1575 = x1574 & 4194303;
int32_t x1576 = x93[x1575];
int32_t x1577 = x1576;
bool x1578 = true;
for (;;) {
bool x1579 = x1578;
bool x1583;
if (x1579) {
int32_t x1580 = x1577;
bool x1581 = x1580 != -1;
x1583 = x1581;
} else {
x1583 = false;
}
if (!x1583) break;
int32_t x1585 = x1577;
int32_t x1586 = x88[x1585];
x1577 = x1586;
bool x1588 = true;
int32_t x1589 = x81[x1585];
bool x1590 = x1568 == x1589;
if (x1590) {
} else {
x1588 = false;
}
int32_t x1594 = x84[x1585];
bool x1595 = x1569 == x1594;
if (x1595) {
} else {
x1588 = false;
}
bool x1599 = x1588;
if (x1599) {
bool x1600 = true;
if (x1590) {
} else {
x1600 = false;
}
if (x1595) {
} else {
x1600 = false;
}
bool x1607 = x1600;
if (x1607) {
x1570 = false;
} else {
}
bool x1611 = x1570;
x1578 = x1611;
} else {
}
}
bool x1617 = x1570;
if (x1617) {
int32_t x1620 = x86;
int32_t x1621 = x79;
bool x1622 = x1620 == x1621;
if (x1622) {
x79 *= 4;
int32_t x1624 = x79;
printf("buffer.resize %d\n",x1624);
} else {
}
x81[x1620] = x1568;
x84[x1620] = x1569;
x86 += 1;
int32_t x1631 = 1;
x1631 *= x1568;
x1631 *= x1569;
int32_t x1634 = x1631;
int32_t x1635 = x1634 & 4194303;
int32_t x1636 = x93[x1635];
int32_t x1637 = x1636;
x93[x1635] = x1620;
x88[x1620] = x1636;
int32_t x1640 = 1;
x1640 *= x1568;
int32_t x1642 = x1640;
int32_t x1643 = x1642 & 4194303;
int32_t x1644 = x94[x1643];
int32_t x1645 = x1644;
x94[x1643] = x1620;
x91[x1620] = x1644;
} else {
}

}
SWAP(x134,x190);
SWAP(x127,x183);
SWAP(x130,x186);
SWAP(x128,x184);
SWAP(x129,x185);
SWAP(x133,x189);
SWAP(x131,x187);
SWAP(x132,x188);
SWAP(x137,x193);
SWAP(x135,x191);
SWAP(x136,x192);
SWAP(x140,x196);
SWAP(x138,x194);
SWAP(x139,x195);
SWAP(x141,x197);
SWAP(x142,x198);
x190 = 0;
x193 = 0;
x196 = 0;
for(int x1671=0; x1671 < 4194304; x1671++) {
x197[x1671] = -1;

}
for(int x1675=0; x1675 < 4194304; x1675++) {
x198[x1675] = -1;

}
}
}
for(int x1683=0; x1683 < 4194304; x1683++) {
x141[x1683] = -1;

}
for(int x1687=0; x1687 < 4194304; x1687++) {
x142[x1687] = -1;

}
for(int x1691=0; x1691 < 4194304; x1691++) {
x197[x1691] = -1;

}
for(int x1695=0; x1695 < 4194304; x1695++) {
x198[x1695] = -1;

}
int32_t x1699 = x86;
for(int x1701=0; x1701 < x1699; x1701++) {
int32_t x1702 = x81[x1701];
int32_t x1703 = fprintf(x1016,"%d",x1702);
int32_t x1704 = fprintf(x1016,"\t");
int32_t x1705 = x84[x1701];
int32_t x1706 = fprintf(x1016,"%d",x1705);
int32_t x1707 = fprintf(x1016,"\n");

}
fclose(x1016);
if (x343) {
} else {
for(int x1711=0; x1711 < x342; x1711++) {
bool x1713 = true;
int32_t x1714 = 1;
int32_t x1712 = x153[x1711];
x1714 *= x1712;
int32_t x1716 = x1714;
int32_t x1717 = x1716 & 4194303;
int32_t x1718 = x9[x1717];
int32_t x1719 = x1718;
bool x1720 = true;
for (;;) {
bool x1721 = x1720;
bool x1725;
if (x1721) {
int32_t x1722 = x1719;
bool x1723 = x1722 != -1;
x1725 = x1723;
} else {
x1725 = false;
}
if (!x1725) break;
int32_t x1727 = x1719;
int32_t x1728 = x7[x1727];
x1719 = x1728;
bool x1730 = true;
int32_t x1731 = x3[x1727];
bool x1732 = x1712 == x1731;
if (x1732) {
} else {
x1730 = false;
}
bool x1736 = x1730;
if (x1736) {
bool x1737 = true;
if (x1732) {
} else {
x1737 = false;
}
bool x1741 = x1737;
if (x1741) {
x1713 = false;
} else {
}
bool x1745 = x1713;
x1720 = x1745;
} else {
}
}
bool x1751 = x1713;
if (x1751) {
int32_t x1754 = x5;
int32_t x1755 = x1;
bool x1756 = x1754 == x1755;
if (x1756) {
x1 *= 4;
int32_t x1758 = x1;
printf("buffer.resize %d\n",x1758);
} else {
}
x3[x1754] = x1712;
x5 += 1;
int32_t x1764 = 1;
x1764 *= x1712;
int32_t x1766 = x1764;
int32_t x1767 = x1766 & 4194303;
int32_t x1768 = x9[x1767];
int32_t x1769 = x1768;
x9[x1767] = x1754;
x7[x1754] = x1768;
} else {
}

}
}
if (x343) {
} else {
for(int x1778=0; x1778 < x342; x1778++) {
bool x1780 = true;
int32_t x1781 = 1;
int32_t x1779 = x156[x1778];
x1781 *= x1779;
int32_t x1783 = x1781;
int32_t x1784 = x1783 & 4194303;
int32_t x1785 = x9[x1784];
int32_t x1786 = x1785;
bool x1787 = true;
for (;;) {
bool x1788 = x1787;
bool x1792;
if (x1788) {
int32_t x1789 = x1786;
bool x1790 = x1789 != -1;
x1792 = x1790;
} else {
x1792 = false;
}
if (!x1792) break;
int32_t x1794 = x1786;
int32_t x1795 = x7[x1794];
x1786 = x1795;
bool x1797 = true;
int32_t x1798 = x3[x1794];
bool x1799 = x1779 == x1798;
if (x1799) {
} else {
x1797 = false;
}
bool x1803 = x1797;
if (x1803) {
bool x1804 = true;
if (x1799) {
} else {
x1804 = false;
}
bool x1808 = x1804;
if (x1808) {
x1780 = false;
} else {
}
bool x1812 = x1780;
x1787 = x1812;
} else {
}
}
bool x1818 = x1780;
if (x1818) {
int32_t x1821 = x5;
int32_t x1822 = x1;
bool x1823 = x1821 == x1822;
if (x1823) {
x1 *= 4;
int32_t x1825 = x1;
printf("buffer.resize %d\n",x1825);
} else {
}
x3[x1821] = x1779;
x5 += 1;
int32_t x1831 = 1;
x1831 *= x1779;
int32_t x1833 = x1831;
int32_t x1834 = x1833 & 4194303;
int32_t x1835 = x9[x1834];
int32_t x1836 = x1835;
x9[x1834] = x1821;
x7[x1821] = x1835;
} else {
}

}
}
int32_t x1845 = x5;
bool x1846 = x1845 == 0;
if (x1846) {
} else {
for(int x1849=0; x1849 < x1845; x1849++) {
bool x1851 = false;
int32_t x1852 = 1;
int32_t x1850 = x3[x1849];
x1852 *= x1850;
int32_t x1854 = x1852;
int32_t x1855 = x1854 & 4194303;
int32_t x1856 = x170[x1855];
int32_t x1857 = x1856;
bool x1858 = true;
for (;;) {
bool x1859 = x1858;
bool x1863;
if (x1859) {
int32_t x1860 = x1857;
bool x1861 = x1860 != -1;
x1863 = x1861;
} else {
x1863 = false;
}
if (!x1863) break;
int32_t x1865 = x1857;
int32_t x1866 = x166[x1865];
x1857 = x1866;
bool x1868 = true;
int32_t x1869 = x153[x1865];
bool x1870 = x1850 == x1869;
if (x1870) {
} else {
x1868 = false;
}
bool x1874 = x1868;
if (x1874) {
x1851 = true;
x1858 = false;
} else {
}
}
bool x1881 = x1851;
bool x1916;
if (x1881) {
x1916 = false;
} else {
bool x1883 = false;
int32_t x1884 = 1;
x1884 *= x1850;
int32_t x1886 = x1884;
int32_t x1887 = x1886 & 4194303;
int32_t x1888 = x169[x1887];
int32_t x1889 = x1888;
bool x1890 = true;
for (;;) {
bool x1891 = x1890;
bool x1895;
if (x1891) {
int32_t x1892 = x1889;
bool x1893 = x1892 != -1;
x1895 = x1893;
} else {
x1895 = false;
}
if (!x1895) break;
int32_t x1897 = x1889;
int32_t x1898 = x163[x1897];
x1889 = x1898;
bool x1900 = true;
int32_t x1901 = x156[x1897];
bool x1902 = x1850 == x1901;
if (x1902) {
} else {
x1900 = false;
}
bool x1906 = x1900;
if (x1906) {
x1883 = true;
x1890 = false;
} else {
}
}
bool x1913 = x1883;
bool x1914 = !x1913;
x1916 = x1914;
}
if (x1916) {
bool x1917 = true;
int32_t x1918 = 1;
x1918 *= x1850;
x1918 *= 0;
int32_t x1921 = x1918;
int32_t x1922 = x1921 & 4194303;
int32_t x1923 = x26[x1922];
int32_t x1924 = x1923;
bool x1925 = true;
for (;;) {
bool x1926 = x1925;
bool x1930;
if (x1926) {
int32_t x1927 = x1924;
bool x1928 = x1927 != -1;
x1930 = x1928;
} else {
x1930 = false;
}
if (!x1930) break;
int32_t x1932 = x1924;
int32_t x1933 = x24[x1932];
x1924 = x1933;
bool x1935 = true;
int32_t x1936 = x17[x1932];
bool x1937 = x1850 == x1936;
if (x1937) {
} else {
x1935 = false;
}
int32_t x1941 = x20[x1932];
bool x1942 = 0 == x1941;
if (x1942) {
} else {
x1935 = false;
}
bool x1946 = x1935;
if (x1946) {
bool x1947 = true;
if (x1937) {
} else {
x1947 = false;
}
if (x1942) {
} else {
x1947 = false;
}
bool x1954 = x1947;
if (x1954) {
x1917 = false;
} else {
}
bool x1958 = x1917;
x1925 = x1958;
} else {
}
}
bool x1964 = x1917;
if (x1964) {
int32_t x1967 = x22;
int32_t x1968 = x15;
bool x1969 = x1967 == x1968;
if (x1969) {
x15 *= 4;
int32_t x1971 = x15;
printf("buffer.resize %d\n",x1971);
} else {
}
x17[x1967] = x1850;
x20[x1967] = 0;
x22 += 1;
int32_t x1978 = 1;
x1978 *= x1850;
x1978 *= 0;
int32_t x1981 = x1978;
int32_t x1982 = x1981 & 4194303;
int32_t x1983 = x26[x1982];
int32_t x1984 = x1983;
x26[x1982] = x1967;
x24[x1967] = x1983;
} else {
}
} else {
}

}
}
bool x1995;
if (x1846) {
x1995 = false;
} else {
bool x344 = !x343;
x1995 = x344;
}
if (x1995) {
for(int x1996=0; x1996 < x1845; x1996++) {
bool x1998 = false;
int32_t x1999 = 1;
int32_t x1997 = x3[x1996];
x1999 *= x1997;
int32_t x2001 = x1999;
int32_t x2002 = x2001 & 4194303;
int32_t x2003 = x170[x2002];
int32_t x2004 = x2003;
bool x2005 = true;
for (;;) {
bool x2006 = x2005;
bool x2010;
if (x2006) {
int32_t x2007 = x2004;
bool x2008 = x2007 != -1;
x2010 = x2008;
} else {
x2010 = false;
}
if (!x2010) break;
int32_t x2012 = x2004;
int32_t x2013 = x166[x2012];
x2004 = x2013;
bool x2015 = true;
int32_t x2016 = x153[x2012];
bool x2017 = x1997 == x2016;
if (x2017) {
} else {
x2015 = false;
}
bool x2021 = x2015;
if (x2021) {
x1998 = true;
x2005 = false;
} else {
}
}
bool x2028 = x1998;
bool x2062;
if (x2028) {
bool x2029 = false;
int32_t x2030 = 1;
x2030 *= x1997;
int32_t x2032 = x2030;
int32_t x2033 = x2032 & 4194303;
int32_t x2034 = x169[x2033];
int32_t x2035 = x2034;
bool x2036 = true;
for (;;) {
bool x2037 = x2036;
bool x2041;
if (x2037) {
int32_t x2038 = x2035;
bool x2039 = x2038 != -1;
x2041 = x2039;
} else {
x2041 = false;
}
if (!x2041) break;
int32_t x2043 = x2035;
int32_t x2044 = x163[x2043];
x2035 = x2044;
bool x2046 = true;
int32_t x2047 = x156[x2043];
bool x2048 = x1997 == x2047;
if (x2048) {
} else {
x2046 = false;
}
bool x2052 = x2046;
if (x2052) {
x2029 = true;
x2036 = false;
} else {
}
}
bool x2059 = x2029;
bool x2060 = !x2059;
x2062 = x2060;
} else {
x2062 = false;
}
if (x2062) {
bool x2063 = true;
int32_t x2064 = 1;
x2064 *= x1997;
x2064 *= 1;
int32_t x2067 = x2064;
int32_t x2068 = x2067 & 4194303;
int32_t x2069 = x26[x2068];
int32_t x2070 = x2069;
bool x2071 = true;
for (;;) {
bool x2072 = x2071;
bool x2076;
if (x2072) {
int32_t x2073 = x2070;
bool x2074 = x2073 != -1;
x2076 = x2074;
} else {
x2076 = false;
}
if (!x2076) break;
int32_t x2078 = x2070;
int32_t x2079 = x24[x2078];
x2070 = x2079;
bool x2081 = true;
int32_t x2082 = x17[x2078];
bool x2083 = x1997 == x2082;
if (x2083) {
} else {
x2081 = false;
}
int32_t x2087 = x20[x2078];
bool x2088 = 1 == x2087;
if (x2088) {
} else {
x2081 = false;
}
bool x2092 = x2081;
if (x2092) {
bool x2093 = true;
if (x2083) {
} else {
x2093 = false;
}
if (x2088) {
} else {
x2093 = false;
}
bool x2100 = x2093;
if (x2100) {
x2063 = false;
} else {
}
bool x2104 = x2063;
x2071 = x2104;
} else {
}
}
bool x2110 = x2063;
if (x2110) {
int32_t x2113 = x22;
int32_t x2114 = x15;
bool x2115 = x2113 == x2114;
if (x2115) {
x15 *= 4;
int32_t x2117 = x15;
printf("buffer.resize %d\n",x2117);
} else {
}
x17[x2113] = x1997;
x20[x2113] = 1;
x22 += 1;
int32_t x2124 = 1;
x2124 *= x1997;
x2124 *= 1;
int32_t x2127 = x2124;
int32_t x2128 = x2127 & 4194303;
int32_t x2129 = x26[x2128];
int32_t x2130 = x2129;
x26[x2128] = x2113;
x24[x2113] = x2129;
} else {
}
} else {
}

}
} else {
}
int32_t x2141 = x22;
for(int x2143=0; x2143 < x2141; x2143++) {
bool x2146 = true;
int32_t x2147 = 1;
int32_t x2144 = x17[x2143];
x2147 *= x2144;
int32_t x2145 = x20[x2143];
x2147 *= x2145;
int32_t x2150 = x2147;
int32_t x2151 = x2150 & 4194303;
int32_t x2152 = x45[x2151];
int32_t x2153 = x2152;
bool x2154 = true;
for (;;) {
bool x2155 = x2154;
bool x2159;
if (x2155) {
int32_t x2156 = x2153;
bool x2157 = x2156 != -1;
x2159 = x2157;
} else {
x2159 = false;
}
if (!x2159) break;
int32_t x2161 = x2153;
int32_t x2162 = x40[x2161];
x2153 = x2162;
bool x2164 = true;
int32_t x2165 = x33[x2161];
bool x2166 = x2144 == x2165;
if (x2166) {
} else {
x2164 = false;
}
int32_t x2170 = x36[x2161];
bool x2171 = x2145 == x2170;
if (x2171) {
} else {
x2164 = false;
}
bool x2175 = x2164;
if (x2175) {
bool x2176 = true;
if (x2166) {
} else {
x2176 = false;
}
if (x2171) {
} else {
x2176 = false;
}
bool x2183 = x2176;
if (x2183) {
x2146 = false;
} else {
}
bool x2187 = x2146;
x2154 = x2187;
} else {
}
}
bool x2193 = x2146;
if (x2193) {
int32_t x2196 = x38;
int32_t x2197 = x31;
bool x2198 = x2196 == x2197;
if (x2198) {
x31 *= 4;
int32_t x2200 = x31;
printf("buffer.resize %d\n",x2200);
} else {
}
x33[x2196] = x2144;
x36[x2196] = x2145;
x38 += 1;
int32_t x2207 = 1;
x2207 *= x2144;
x2207 *= x2145;
int32_t x2210 = x2207;
int32_t x2211 = x2210 & 4194303;
int32_t x2212 = x45[x2211];
int32_t x2213 = x2212;
x45[x2211] = x2196;
x40[x2196] = x2212;
int32_t x2216 = 1;
x2216 *= x2144;
int32_t x2218 = x2216;
int32_t x2219 = x2218 & 4194303;
int32_t x2220 = x46[x2219];
int32_t x2221 = x2220;
x46[x2219] = x2196;
x43[x2196] = x2220;
} else {
}

}
bool x2228 = true;
for (;;) {
bool x2229 = x2228;
if (!x2229) break;
int32_t x2231 = x86;
bool x2232 = x2231 == 0;
bool x2238;
if (x2232) {
x2238 = false;
} else {
int32_t x2234 = x214;
bool x2235 = x2234 == 0;
bool x2236 = !x2235;
x2238 = x2236;
}
bool x2243;
if (x2238) {
int32_t x2239 = x38;
bool x2240 = x2239 == 0;
bool x2241 = !x2240;
x2243 = x2241;
} else {
x2243 = false;
}
if (x2243) {
for(int x2245=0; x2245 < x2231; x2245++) {
bool x2248 = false;
int32_t x2249 = 1;
int32_t x2246 = x84[x2245];
x2249 *= x2246;
int32_t x2247 = x81[x2245];
x2249 *= x2247;
int32_t x2252 = x2249;
int32_t x2253 = x2252 & 4194303;
int32_t x2254 = x221[x2253];
int32_t x2255 = x2254;
bool x2256 = true;
for (;;) {
bool x2257 = x2256;
bool x2261;
if (x2257) {
int32_t x2258 = x2255;
bool x2259 = x2258 != -1;
x2261 = x2259;
} else {
x2261 = false;
}
if (!x2261) break;
int32_t x2263 = x2255;
int32_t x2264 = x216[x2263];
x2255 = x2264;
bool x2266 = true;
int32_t x2267 = x209[x2263];
bool x2268 = x2246 == x2267;
if (x2268) {
} else {
x2266 = false;
}
int32_t x2272 = x212[x2263];
bool x2273 = x2247 == x2272;
if (x2273) {
} else {
x2266 = false;
}
bool x2277 = x2266;
if (x2277) {
x2248 = true;
x2256 = false;
} else {
}
}
bool x2284 = x2248;
bool x2324;
if (x2284) {
bool x2285 = false;
int32_t x2286 = 1;
x2286 *= x2246;
x2286 *= x2247;
int32_t x2289 = x2286;
int32_t x2290 = x2289 & 4194303;
int32_t x2291 = x93[x2290];
int32_t x2292 = x2291;
bool x2293 = true;
for (;;) {
bool x2294 = x2293;
bool x2298;
if (x2294) {
int32_t x2295 = x2292;
bool x2296 = x2295 != -1;
x2298 = x2296;
} else {
x2298 = false;
}
if (!x2298) break;
int32_t x2300 = x2292;
int32_t x2301 = x88[x2300];
x2292 = x2301;
bool x2303 = true;
int32_t x2304 = x81[x2300];
bool x2305 = x2246 == x2304;
if (x2305) {
} else {
x2303 = false;
}
int32_t x2309 = x84[x2300];
bool x2310 = x2247 == x2309;
if (x2310) {
} else {
x2303 = false;
}
bool x2314 = x2303;
if (x2314) {
x2285 = true;
x2293 = false;
} else {
}
}
bool x2321 = x2285;
bool x2322 = !x2321;
x2324 = x2322;
} else {
x2324 = false;
}
if (x2324) {
int32_t x2325 = 1;
x2325 *= x2247;
int32_t x2327 = x2325;
int32_t x2328 = x2327 & 4194303;
int32_t x2329 = x46[x2328];
int32_t x2330 = x2329;
for (;;) {
int32_t x2331 = x2330;
bool x2332 = x2331 != -1;
if (!x2332) break;
int32_t x2334 = x2330;
int32_t x2335 = x43[x2334];
x2330 = x2335;
bool x2337 = true;
int32_t x2338 = x33[x2334];
bool x2339 = x2247 == x2338;
if (x2339) {
} else {
x2337 = false;
}
bool x2343 = x2337;
if (x2343) {
bool x2346 = false;
int32_t x2347 = 1;
x2347 *= x2246;
int32_t x2344 = x36[x2334];
int32_t x2345 = x2344 + 1;
x2347 *= x2345;
int32_t x2350 = x2347;
int32_t x2351 = x2350 & 4194303;
int32_t x2352 = x26[x2351];
int32_t x2353 = x2352;
bool x2354 = true;
for (;;) {
bool x2355 = x2354;
bool x2359;
if (x2355) {
int32_t x2356 = x2353;
bool x2357 = x2356 != -1;
x2359 = x2357;
} else {
x2359 = false;
}
if (!x2359) break;
int32_t x2361 = x2353;
int32_t x2362 = x24[x2361];
x2353 = x2362;
bool x2364 = true;
int32_t x2365 = x17[x2361];
bool x2366 = x2246 == x2365;
if (x2366) {
} else {
x2364 = false;
}
int32_t x2370 = x20[x2361];
bool x2371 = x2345 == x2370;
if (x2371) {
} else {
x2364 = false;
}
bool x2375 = x2364;
if (x2375) {
x2346 = true;
x2354 = false;
} else {
}
}
bool x2382 = x2346;
if (x2382) {
} else {
bool x2384 = true;
int32_t x2385 = 1;
x2385 *= x2246;
x2385 *= x2345;
int32_t x2388 = x2385;
int32_t x2389 = x2388 & 4194303;
int32_t x2390 = x69[x2389];
int32_t x2391 = x2390;
bool x2392 = true;
for (;;) {
bool x2393 = x2392;
bool x2397;
if (x2393) {
int32_t x2394 = x2391;
bool x2395 = x2394 != -1;
x2397 = x2395;
} else {
x2397 = false;
}
if (!x2397) break;
int32_t x2399 = x2391;
int32_t x2400 = x64[x2399];
x2391 = x2400;
bool x2402 = true;
int32_t x2403 = x57[x2399];
bool x2404 = x2246 == x2403;
if (x2404) {
} else {
x2402 = false;
}
int32_t x2408 = x60[x2399];
bool x2409 = x2345 == x2408;
if (x2409) {
} else {
x2402 = false;
}
bool x2413 = x2402;
if (x2413) {
bool x2414 = true;
if (x2404) {
} else {
x2414 = false;
}
if (x2409) {
} else {
x2414 = false;
}
bool x2421 = x2414;
if (x2421) {
x2384 = false;
} else {
}
bool x2425 = x2384;
x2392 = x2425;
} else {
}
}
bool x2431 = x2384;
if (x2431) {
int32_t x2434 = x62;
int32_t x2435 = x55;
bool x2436 = x2434 == x2435;
if (x2436) {
x55 *= 4;
int32_t x2438 = x55;
printf("buffer.resize %d\n",x2438);
} else {
}
x57[x2434] = x2246;
x60[x2434] = x2345;
x62 += 1;
int32_t x2445 = 1;
x2445 *= x2246;
x2445 *= x2345;
int32_t x2448 = x2445;
int32_t x2449 = x2448 & 4194303;
int32_t x2450 = x69[x2449];
int32_t x2451 = x2450;
x69[x2449] = x2434;
x64[x2434] = x2450;
int32_t x2454 = 1;
x2454 *= x2246;
int32_t x2456 = x2454;
int32_t x2457 = x2456 & 4194303;
int32_t x2458 = x70[x2457];
int32_t x2459 = x2458;
x70[x2457] = x2434;
x67[x2434] = x2458;
} else {
}
}
} else {
}
}
} else {
}

}
} else {
}
int32_t x2476 = x62;
bool x2477 = x2476 == 0;
if (x2477) {
x2228 = false;
} else {
for(int x2481=0; x2481 < x2476; x2481++) {
bool x2484 = true;
int32_t x2485 = 1;
int32_t x2482 = x57[x2481];
x2485 *= x2482;
int32_t x2483 = x60[x2481];
x2485 *= x2483;
int32_t x2488 = x2485;
int32_t x2489 = x2488 & 4194303;
int32_t x2490 = x26[x2489];
int32_t x2491 = x2490;
bool x2492 = true;
for (;;) {
bool x2493 = x2492;
bool x2497;
if (x2493) {
int32_t x2494 = x2491;
bool x2495 = x2494 != -1;
x2497 = x2495;
} else {
x2497 = false;
}
if (!x2497) break;
int32_t x2499 = x2491;
int32_t x2500 = x24[x2499];
x2491 = x2500;
bool x2502 = true;
int32_t x2503 = x17[x2499];
bool x2504 = x2482 == x2503;
if (x2504) {
} else {
x2502 = false;
}
int32_t x2508 = x20[x2499];
bool x2509 = x2483 == x2508;
if (x2509) {
} else {
x2502 = false;
}
bool x2513 = x2502;
if (x2513) {
bool x2514 = true;
if (x2504) {
} else {
x2514 = false;
}
if (x2509) {
} else {
x2514 = false;
}
bool x2521 = x2514;
if (x2521) {
x2484 = false;
} else {
}
bool x2525 = x2484;
x2492 = x2525;
} else {
}
}
bool x2531 = x2484;
if (x2531) {
int32_t x2534 = x22;
int32_t x2535 = x15;
bool x2536 = x2534 == x2535;
if (x2536) {
x15 *= 4;
int32_t x2538 = x15;
printf("buffer.resize %d\n",x2538);
} else {
}
x17[x2534] = x2482;
x20[x2534] = x2483;
x22 += 1;
int32_t x2545 = 1;
x2545 *= x2482;
x2545 *= x2483;
int32_t x2548 = x2545;
int32_t x2549 = x2548 & 4194303;
int32_t x2550 = x26[x2549];
int32_t x2551 = x2550;
x26[x2549] = x2534;
x24[x2534] = x2550;
} else {
}

}
SWAP(x38,x62);
SWAP(x31,x55);
SWAP(x34,x58);
SWAP(x32,x56);
SWAP(x33,x57);
SWAP(x37,x61);
SWAP(x35,x59);
SWAP(x36,x60);
SWAP(x41,x65);
SWAP(x39,x63);
SWAP(x40,x64);
SWAP(x44,x68);
SWAP(x42,x66);
SWAP(x43,x67);
SWAP(x45,x69);
SWAP(x46,x70);
x62 = 0;
x65 = 0;
x68 = 0;
for(int x2577=0; x2577 < 4194304; x2577++) {
x69[x2577] = -1;

}
for(int x2581=0; x2581 < 4194304; x2581++) {
x70[x2581] = -1;

}
}
}
for(int x2589=0; x2589 < 4194304; x2589++) {
x45[x2589] = -1;

}
for(int x2593=0; x2593 < 4194304; x2593++) {
x46[x2593] = -1;

}
for(int x2597=0; x2597 < 4194304; x2597++) {
x69[x2597] = -1;

}
for(int x2601=0; x2601 < 4194304; x2601++) {
x70[x2601] = -1;

}
int32_t x2606 = x22;
FILE *x2605 = fopen("indices.out","w");
for(int x2608=0; x2608 < x2606; x2608++) {
int32_t x2609 = x17[x2608];
int32_t x2610 = fprintf(x2605,"%d",x2609);
int32_t x2611 = fprintf(x2605,"\t");
int32_t x2612 = x20[x2608];
int32_t x2613 = fprintf(x2605,"%d",x2612);
int32_t x2614 = fprintf(x2605,"\n");

}
fclose(x2605);
for(int x2618=0; x2618 < 4194304; x2618++) {
x168[x2618] = -1;

}
for(int x2622=0; x2622 < 4194304; x2622++) {
x169[x2622] = -1;

}
for(int x2626=0; x2626 < 4194304; x2626++) {
x170[x2626] = -1;

}
for(int x2630=0; x2630 < 4194304; x2630++) {
x221[x2630] = -1;

}
for(int x2634=0; x2634 < 4194304; x2634++) {
x222[x2634] = -1;

}
for(int x2638=0; x2638 < 4194304; x2638++) {
x93[x2638] = -1;

}
for(int x2642=0; x2642 < 4194304; x2642++) {
x94[x2642] = -1;

}
for(int x2646=0; x2646 < 4194304; x2646++) {
x9[x2646] = -1;

}
bool x2650 = x2606 == 0;
if (x2650) {
} else {
for(int x2652=0; x2652 < x2606; x2652++) {
bool x2656 = false;
int32_t x2657 = 1;
int32_t x2653 = x17[x2652];
x2657 *= x2653;
int32_t x2654 = x20[x2652];
int32_t x2655 = x2654 + 1;
x2657 *= x2655;
int32_t x2660 = x2657;
int32_t x2661 = x2660 & 4194303;
int32_t x2662 = x26[x2661];
int32_t x2663 = x2662;
bool x2664 = true;
for (;;) {
bool x2665 = x2664;
bool x2669;
if (x2665) {
int32_t x2666 = x2663;
bool x2667 = x2666 != -1;
x2669 = x2667;
} else {
x2669 = false;
}
if (!x2669) break;
int32_t x2671 = x2663;
int32_t x2672 = x24[x2671];
x2663 = x2672;
bool x2674 = true;
int32_t x2675 = x17[x2671];
bool x2676 = x2653 == x2675;
if (x2676) {
} else {
x2674 = false;
}
int32_t x2680 = x20[x2671];
bool x2681 = x2655 == x2680;
if (x2681) {
} else {
x2674 = false;
}
bool x2685 = x2674;
if (x2685) {
x2656 = true;
x2664 = false;
} else {
}
}
bool x2692 = x2656;
if (x2692) {
} else {
bool x2694 = true;
int32_t x2695 = 1;
x2695 *= x2653;
x2695 *= x2654;
int32_t x2698 = x2695;
int32_t x2699 = x2698 & 4194303;
int32_t x2700 = x266[x2699];
int32_t x2701 = x2700;
bool x2702 = true;
for (;;) {
bool x2703 = x2702;
bool x2707;
if (x2703) {
int32_t x2704 = x2701;
bool x2705 = x2704 != -1;
x2707 = x2705;
} else {
x2707 = false;
}
if (!x2707) break;
int32_t x2709 = x2701;
int32_t x2710 = x264[x2709];
x2701 = x2710;
bool x2712 = true;
int32_t x2713 = x257[x2709];
bool x2714 = x2653 == x2713;
if (x2714) {
} else {
x2712 = false;
}
int32_t x2718 = x260[x2709];
bool x2719 = x2654 == x2718;
if (x2719) {
} else {
x2712 = false;
}
bool x2723 = x2712;
if (x2723) {
bool x2724 = true;
if (x2714) {
} else {
x2724 = false;
}
if (x2719) {
} else {
x2724 = false;
}
bool x2731 = x2724;
if (x2731) {
x2694 = false;
} else {
}
bool x2735 = x2694;
x2702 = x2735;
} else {
}
}
bool x2741 = x2694;
if (x2741) {
int32_t x2744 = x262;
int32_t x2745 = x255;
bool x2746 = x2744 == x2745;
if (x2746) {
x255 *= 4;
int32_t x2748 = x255;
printf("buffer.resize %d\n",x2748);
} else {
}
x257[x2744] = x2653;
x260[x2744] = x2654;
x262 += 1;
int32_t x2755 = 1;
x2755 *= x2653;
x2755 *= x2654;
int32_t x2758 = x2755;
int32_t x2759 = x2758 & 4194303;
int32_t x2760 = x266[x2759];
int32_t x2761 = x2760;
x266[x2759] = x2744;
x264[x2744] = x2760;
} else {
}
}

}
}
int32_t x2773 = x262;
FILE *x2772 = fopen("index.out","w");
for(int x2775=0; x2775 < x2773; x2775++) {
int32_t x2776 = x257[x2775];
int32_t x2777 = fprintf(x2772,"%d",x2776);
int32_t x2778 = fprintf(x2772,"\t");
int32_t x2779 = x260[x2775];
int32_t x2780 = fprintf(x2772,"%d",x2779);
int32_t x2781 = fprintf(x2772,"\n");

}
fclose(x2772);
for(int x2785=0; x2785 < 4194304; x2785++) {
x26[x2785] = -1;

}
}
/*****************************************
  End of C Generated Code                  
*******************************************/

