
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
int32_t x6 = 0;
int32_t x7 = 4194304;
int32_t* x8 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x9 = x8;
int32_t x10 = 0;
int32_t* x11 = (int32_t*)malloc(16384 * sizeof(int32_t));
int32_t* x12 = x11;
for(int x14=0; x14 < 16384; x14++) {
int32_t* x15 = x12;
x15[x14] = -1;

}
int32_t x19 = 4194304;
int32_t x20 = 4194304;
int32_t* x21 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x22 = x21;
int32_t x23 = 0;
int32_t x24 = 0;
int32_t x25 = 4194304;
int32_t* x26 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x27 = x26;
int32_t x28 = 0;
int32_t* x29 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x30 = x29;
for(int x32=0; x32 < 4194304; x32++) {
int32_t* x33 = x30;
x33[x32] = -1;

}
int32_t x37 = 4194304;
int32_t x38 = 4194304;
int32_t* x39 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x40 = x39;
int32_t x41 = 0;
int32_t x42 = 0;
int32_t x43 = 4194304;
int32_t* x44 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x45 = x44;
int32_t x46 = 0;
int32_t* x47 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x48 = x47;
for(int x49=0; x49 < 4194304; x49++) {
int32_t* x50 = x48;
x50[x49] = -1;

}
int32_t x54 = 4194304;
int32_t x55 = 4194304;
int32_t* x56 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x57 = x56;
int32_t x58 = 0;
int32_t x59 = 4194304;
int32_t* x60 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x61 = x60;
int32_t x62 = 0;
int32_t x63 = 4194304;
int32_t* x64 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x65 = x64;
int32_t x66 = 0;
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
int32_t x80 = 4194304;
int32_t* x81 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x82 = x81;
int32_t x83 = 0;
int32_t x84 = 4194304;
int32_t* x85 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x86 = x85;
int32_t x87 = 0;
int32_t x88 = 4194304;
int32_t* x89 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x90 = x89;
int32_t x91 = 0;
int32_t* x92 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x93 = x92;
int32_t* x94 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x95 = x94;
int32_t* x96 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x97 = x96;
int32_t* x98 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x99 = x98;
for(int x100=0; x100 < 4194304; x100++) {
int32_t* x101 = x93;
x101[x100] = -1;

}
for(int x105=0; x105 < 4194304; x105++) {
int32_t* x106 = x95;
x106[x105] = -1;

}
for(int x110=0; x110 < 4194304; x110++) {
int32_t* x111 = x97;
x111[x110] = -1;

}
for(int x115=0; x115 < 4194304; x115++) {
int32_t* x116 = x99;
x116[x115] = -1;

}
int32_t x120 = 4194304;
int32_t x121 = 4194304;
int32_t* x122 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x123 = x122;
int32_t x124 = 0;
int32_t x125 = 4194304;
int32_t* x126 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x127 = x126;
int32_t x128 = 0;
int32_t x129 = 0;
int32_t x130 = 4194304;
int32_t* x131 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x132 = x131;
int32_t x133 = 0;
int32_t* x134 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x135 = x134;
for(int x136=0; x136 < 4194304; x136++) {
int32_t* x137 = x135;
x137[x136] = -1;

}
int32_t x141 = 4194304;
int32_t x142 = 4194304;
int32_t* x143 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x144 = x143;
int32_t x145 = 0;
int32_t x146 = 4194304;
int32_t* x147 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x148 = x147;
int32_t x149 = 0;
int32_t x150 = 4194304;
int32_t* x151 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x152 = x151;
int32_t x153 = 0;
int32_t x154 = 4194304;
int32_t* x155 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x156 = x155;
int32_t x157 = 0;
int32_t x158 = 4194304;
int32_t* x159 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x160 = x159;
int32_t x161 = 0;
int32_t x162 = 0;
int32_t x163 = 4194304;
int32_t* x164 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x165 = x164;
int32_t x166 = 0;
int32_t x167 = 4194304;
int32_t* x168 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x169 = x168;
int32_t x170 = 0;
int32_t x171 = 4194304;
int32_t* x172 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x173 = x172;
int32_t x174 = 0;
int32_t* x175 = (int32_t*)malloc(16384 * sizeof(int32_t));
int32_t* x176 = x175;
int32_t* x177 = (int32_t*)malloc(16384 * sizeof(int32_t));
int32_t* x178 = x177;
int32_t* x179 = (int32_t*)malloc(16384 * sizeof(int32_t));
int32_t* x180 = x179;
for(int x181=0; x181 < 16384; x181++) {
int32_t* x182 = x176;
x182[x181] = -1;

}
for(int x186=0; x186 < 16384; x186++) {
int32_t* x187 = x178;
x187[x186] = -1;

}
for(int x191=0; x191 < 16384; x191++) {
int32_t* x192 = x180;
x192[x191] = -1;

}
int32_t x196 = 4194304;
int32_t x197 = 4194304;
int32_t* x198 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x199 = x198;
int32_t x200 = 0;
int32_t x201 = 0;
int32_t x202 = 4194304;
int32_t* x203 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x204 = x203;
int32_t x205 = 0;
int32_t* x206 = (int32_t*)malloc(16384 * sizeof(int32_t));
int32_t* x207 = x206;
for(int x208=0; x208 < 16384; x208++) {
int32_t* x209 = x207;
x209[x208] = -1;

}
int32_t x213 = 4194304;
int32_t x214 = 4194304;
int32_t* x215 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x216 = x215;
int32_t x217 = 0;
int32_t x218 = 0;
int32_t x219 = 4194304;
int32_t* x220 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x221 = x220;
int32_t x222 = 0;
int32_t* x223 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x224 = x223;
for(int x225=0; x225 < 4194304; x225++) {
int32_t* x226 = x224;
x226[x225] = -1;

}
int32_t x230 = 4194304;
int32_t x231 = 4194304;
int32_t* x232 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x233 = x232;
int32_t x234 = 0;
int32_t x235 = 0;
int32_t x236 = 4194304;
int32_t* x237 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x238 = x237;
int32_t x239 = 0;
int32_t* x240 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x241 = x240;
for(int x242=0; x242 < 4194304; x242++) {
int32_t* x243 = x241;
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
int32_t x256 = 4194304;
int32_t* x257 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x258 = x257;
int32_t x259 = 0;
int32_t x260 = 4194304;
int32_t* x261 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x262 = x261;
int32_t x263 = 0;
int32_t x264 = 4194304;
int32_t* x265 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x266 = x265;
int32_t x267 = 0;
int32_t x268 = 0;
int32_t x269 = 4194304;
int32_t* x270 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x271 = x270;
int32_t x272 = 0;
int32_t x273 = 4194304;
int32_t* x274 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x275 = x274;
int32_t x276 = 0;
int32_t x277 = 4194304;
int32_t* x278 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x279 = x278;
int32_t x280 = 0;
int32_t* x281 = (int32_t*)malloc(16384 * sizeof(int32_t));
int32_t* x282 = x281;
int32_t* x283 = (int32_t*)malloc(16384 * sizeof(int32_t));
int32_t* x284 = x283;
int32_t* x285 = (int32_t*)malloc(16384 * sizeof(int32_t));
int32_t* x286 = x285;
for(int x287=0; x287 < 16384; x287++) {
int32_t* x288 = x282;
x288[x287] = -1;

}
for(int x292=0; x292 < 16384; x292++) {
int32_t* x293 = x284;
x293[x292] = -1;

}
for(int x297=0; x297 < 16384; x297++) {
int32_t* x298 = x286;
x298[x297] = -1;

}
int32_t x302 = 4194304;
int32_t x303 = 4194304;
int32_t* x304 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x305 = x304;
int32_t x306 = 0;
int32_t x307 = 0;
int32_t x308 = 4194304;
int32_t* x309 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x310 = x309;
int32_t x311 = 0;
int32_t* x312 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x313 = x312;
for(int x314=0; x314 < 4194304; x314++) {
int32_t* x315 = x313;
x315[x314] = -1;

}
int32_t x322 = 0;
int32_t x319 = open("high1.facts",0);
int32_t x320 = fsize(x319);
char* x321 = mmap(0, x320, PROT_READ, MAP_FILE | MAP_SHARED, x319, 0);
for (;;) {
int32_t x323 = x322;
bool x324 = x323 < x320;
if (!x324) break;
int32_t x326 = x322;
for (;;) {
int32_t x327 = x322;
char x328 = x321[x327];
bool x329 = x328 != '\n';
if (!x329) break;
x322 += 1;
}
int32_t x334 = x322;
x322 += 1;
char* x337 = x321+x326;
int32_t x338 = atoi(x337);
int32_t x339 = x42;
int32_t x340 = x37;
bool x341 = x339 == x340;
if (x341) {
x37 *= 4;
int32_t x343 = x37;
printf("buffer.resize %d\n",x343);
} else {
}
int32_t* x347 = x40;
x347[x339] = x338;
x42 += 1;
int32_t x350 = x339;
int32_t x351 = 0;
int32_t x352 = x338 + 233;
x351 = x352;
int32_t* x355 = x48;
int32_t x354 = x352 & 4194303;
int32_t x356 = x355[x354];
int32_t x357 = x356;
x355[x354] = x339;
int32_t* x359 = x45;
x359[x339] = x356;
}
int32_t x366 = 0;
int32_t x363 = open("high2.facts",0);
int32_t x364 = fsize(x363);
char* x365 = mmap(0, x364, PROT_READ, MAP_FILE | MAP_SHARED, x363, 0);
for (;;) {
int32_t x367 = x366;
bool x368 = x367 < x364;
if (!x368) break;
int32_t x370 = x366;
for (;;) {
int32_t x371 = x366;
char x372 = x365[x371];
bool x373 = x372 != '\n';
if (!x373) break;
x366 += 1;
}
int32_t x378 = x366;
x366 += 1;
char* x381 = x365+x370;
int32_t x382 = atoi(x381);
int32_t x383 = x307;
int32_t x384 = x302;
bool x385 = x383 == x384;
if (x385) {
x302 *= 4;
int32_t x387 = x302;
printf("buffer.resize %d\n",x387);
} else {
}
int32_t* x391 = x305;
x391[x383] = x382;
x307 += 1;
int32_t x394 = x383;
int32_t x395 = 0;
int32_t x396 = x382 + 233;
x395 = x396;
int32_t* x399 = x313;
int32_t x398 = x396 & 4194303;
int32_t x400 = x399[x398];
int32_t x401 = x400;
x399[x398] = x383;
int32_t* x403 = x310;
x403[x383] = x400;
}
int32_t x410 = 0;
int32_t x407 = open("low1.facts",0);
int32_t x408 = fsize(x407);
char* x409 = mmap(0, x408, PROT_READ, MAP_FILE | MAP_SHARED, x407, 0);
for (;;) {
int32_t x411 = x410;
bool x412 = x411 < x408;
if (!x412) break;
int32_t x414 = x410;
for (;;) {
int32_t x415 = x410;
char x416 = x409[x415];
bool x417 = x416 != '\n';
if (!x417) break;
x410 += 1;
}
int32_t x422 = x410;
x410 += 1;
char* x425 = x409+x414;
int32_t x426 = atoi(x425);
int32_t x427 = x218;
int32_t x428 = x213;
bool x429 = x427 == x428;
if (x429) {
x213 *= 4;
int32_t x431 = x213;
printf("buffer.resize %d\n",x431);
} else {
}
int32_t* x435 = x216;
x435[x427] = x426;
x218 += 1;
int32_t x438 = x427;
int32_t x439 = 0;
int32_t x440 = x426 + 233;
x439 = x440;
int32_t* x443 = x224;
int32_t x442 = x440 & 4194303;
int32_t x444 = x443[x442];
int32_t x445 = x444;
x443[x442] = x427;
int32_t* x447 = x221;
x447[x427] = x444;
}
int32_t x451 = x218;
bool x452 = x451 == 0;
if (x452) {
} else {
for(int x455=0; x455 < x451; x455++) {
int32_t* x456 = x216;
bool x458 = true;
int32_t x459 = 0;
int32_t x457 = x456[x455];
int32_t x460 = x457 + 233;
x459 = x460;
int32_t* x463 = x241;
int32_t x462 = x460 & 4194303;
int32_t x464 = x463[x462];
int32_t x465 = x464;
bool x466 = true;
for (;;) {
bool x467 = x466;
bool x471;
if (x467) {
int32_t x468 = x465;
bool x469 = x468 != -1;
x471 = x469;
} else {
x471 = false;
}
if (!x471) break;
int32_t x473 = x465;
bool x474 = true;
int32_t* x475 = x233;
int32_t x476 = x475[x473];
bool x477 = x457 == x476;
if (x477) {
} else {
x474 = false;
}
bool x481 = x474;
if (x481) {
bool x482 = true;
if (x477) {
} else {
x482 = false;
}
bool x486 = x482;
if (x486) {
x458 = false;
} else {
}
bool x490 = x458;
x466 = x490;
} else {
}
int32_t* x494 = x238;
int32_t x495 = x494[x473];
x465 = x495;
}
bool x499 = x458;
if (x499) {
int32_t x502 = x235;
int32_t x503 = x230;
bool x504 = x502 == x503;
if (x504) {
x230 *= 4;
int32_t x506 = x230;
printf("buffer.resize %d\n",x506);
} else {
}
int32_t* x510 = x233;
x510[x502] = x457;
x235 += 1;
int32_t x513 = x502;
int32_t x514 = 0;
x514 = x460;
int32_t x516 = x464;
x463[x462] = x502;
int32_t* x518 = x238;
x518[x502] = x464;
} else {
}

}
}
int32_t x526 = x235;
for(int x528=0; x528 < x526; x528++) {
int32_t* x529 = x233;
bool x531 = true;
int32_t x532 = 0;
int32_t x530 = x529[x528];
int32_t x533 = x530 + 233;
x532 = x533;
int32_t* x536 = x12;
int32_t x535 = x533 & 16383;
int32_t x537 = x536[x535];
int32_t x538 = x537;
bool x539 = true;
for (;;) {
bool x540 = x539;
bool x544;
if (x540) {
int32_t x541 = x538;
bool x542 = x541 != -1;
x544 = x542;
} else {
x544 = false;
}
if (!x544) break;
int32_t x546 = x538;
bool x547 = true;
int32_t* x548 = x4;
int32_t x549 = x548[x546];
bool x550 = x530 == x549;
if (x550) {
} else {
x547 = false;
}
bool x554 = x547;
if (x554) {
bool x555 = true;
if (x550) {
} else {
x555 = false;
}
bool x559 = x555;
if (x559) {
x531 = false;
} else {
}
bool x563 = x531;
x539 = x563;
} else {
}
int32_t* x567 = x9;
int32_t x568 = x567[x546];
x538 = x568;
}
bool x572 = x531;
if (x572) {
int32_t x575 = x6;
int32_t x576 = x1;
bool x577 = x575 == x576;
if (x577) {
x1 *= 4;
int32_t x579 = x1;
printf("buffer.resize %d\n",x579);
} else {
}
int32_t* x583 = x4;
x583[x575] = x530;
x6 += 1;
int32_t x586 = x575;
int32_t x587 = 0;
x587 = x533;
int32_t x589 = x537;
x536[x535] = x575;
int32_t* x591 = x9;
x591[x575] = x537;
} else {
}

}
bool x597 = true;
for (;;) {
bool x598 = x597;
if (!x598) break;
int32_t x600 = x6;
bool x601 = x600 == 0;
bool x607;
if (x601) {
x607 = false;
} else {
int32_t x603 = x42;
bool x604 = x603 == 0;
bool x605 = !x604;
x607 = x605;
}
if (x607) {
for(int x609=0; x609 < x600; x609++) {
int32_t* x610 = x4;
bool x613 = false;
int32_t x614 = 0;
int32_t x611 = x610[x609];
int32_t x612 = x611 + 1;
int32_t x615 = x612 + 233;
x614 = x615;
int32_t* x618 = x241;
int32_t x617 = x615 & 4194303;
int32_t x619 = x618[x617];
int32_t x620 = x619;
bool x621 = true;
for (;;) {
bool x622 = x621;
bool x626;
if (x622) {
int32_t x623 = x620;
bool x624 = x623 != -1;
x626 = x624;
} else {
x626 = false;
}
if (!x626) break;
int32_t x628 = x620;
bool x629 = true;
int32_t* x630 = x233;
int32_t x631 = x630[x628];
bool x632 = x612 == x631;
if (x632) {
} else {
x629 = false;
}
bool x636 = x629;
if (x636) {
x613 = true;
x621 = false;
} else {
}
int32_t* x641 = x238;
int32_t x642 = x641[x628];
x620 = x642;
}
bool x646 = x613;
if (x646) {
} else {
int32_t x648 = 0;
bool x649 = true;
for (;;) {
bool x650 = x649;
bool x655;
if (x650) {
int32_t x651 = x648;
int32_t x652 = x42;
bool x653 = x651 < x652;
x655 = x653;
} else {
x655 = false;
}
if (!x655) break;
int32_t x657 = x648;
int32_t* x658 = x4;
int32_t* x660 = x40;
int32_t x659 = x658[x609];
int32_t x661 = x660[x657];
bool x662 = x659 < x661;
if (x662) {
if (x662) {
bool x664 = true;
int32_t x665 = 0;
int32_t x663 = x659 + 1;
int32_t x666 = x663 + 233;
x665 = x666;
int32_t* x669 = x207;
int32_t x668 = x666 & 16383;
int32_t x670 = x669[x668];
int32_t x671 = x670;
bool x672 = true;
for (;;) {
bool x673 = x672;
bool x677;
if (x673) {
int32_t x674 = x671;
bool x675 = x674 != -1;
x677 = x675;
} else {
x677 = false;
}
if (!x677) break;
int32_t x679 = x671;
bool x680 = true;
int32_t* x681 = x199;
int32_t x682 = x681[x679];
bool x683 = x663 == x682;
if (x683) {
} else {
x680 = false;
}
bool x687 = x680;
if (x687) {
bool x688 = true;
if (x683) {
} else {
x688 = false;
}
bool x692 = x688;
if (x692) {
x664 = false;
} else {
}
bool x696 = x664;
x672 = x696;
} else {
}
int32_t* x700 = x204;
int32_t x701 = x700[x679];
x671 = x701;
}
bool x705 = x664;
if (x705) {
int32_t x708 = x201;
int32_t x709 = x196;
bool x710 = x708 == x709;
if (x710) {
x196 *= 4;
int32_t x712 = x196;
printf("buffer.resize %d\n",x712);
} else {
}
int32_t* x716 = x199;
x716[x708] = x663;
x201 += 1;
int32_t x719 = x708;
int32_t x720 = 0;
x720 = x666;
int32_t x722 = x670;
x669[x668] = x708;
int32_t* x724 = x204;
x724[x708] = x670;
} else {
}
} else {
}
} else {
}
bool x732 = !x662;
x649 = x732;
x648 += 1;
}
}

}
} else {
}
int32_t x743 = x201;
bool x744 = x743 == 0;
if (x744) {
x597 = false;
} else {
for(int x748=0; x748 < x743; x748++) {
int32_t* x749 = x199;
bool x751 = true;
int32_t x752 = 0;
int32_t x750 = x749[x748];
int32_t x753 = x750 + 233;
x752 = x753;
int32_t* x756 = x241;
int32_t x755 = x753 & 4194303;
int32_t x757 = x756[x755];
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
bool x767 = true;
int32_t* x768 = x233;
int32_t x769 = x768[x766];
bool x770 = x750 == x769;
if (x770) {
} else {
x767 = false;
}
bool x774 = x767;
if (x774) {
bool x775 = true;
if (x770) {
} else {
x775 = false;
}
bool x779 = x775;
if (x779) {
x751 = false;
} else {
}
bool x783 = x751;
x759 = x783;
} else {
}
int32_t* x787 = x238;
int32_t x788 = x787[x766];
x758 = x788;
}
bool x792 = x751;
if (x792) {
int32_t x795 = x235;
int32_t x796 = x230;
bool x797 = x795 == x796;
if (x797) {
x230 *= 4;
int32_t x799 = x230;
printf("buffer.resize %d\n",x799);
} else {
}
int32_t* x803 = x233;
x803[x795] = x750;
x235 += 1;
int32_t x806 = x795;
int32_t x807 = 0;
x807 = x753;
int32_t x809 = x757;
x756[x755] = x795;
int32_t* x811 = x238;
x811[x795] = x757;
} else {
}

}
SWAP(x6,x201);
SWAP(x1,x196);
SWAP(x5,x200);
SWAP(x2,x197);
SWAP(x4,x199);
SWAP(x10,x205);
SWAP(x7,x202);
SWAP(x9,x204);
SWAP(x12,x207);
x201 = 0;
x205 = 0;
for(int x828=0; x828 < 16384; x828++) {
int32_t* x829 = x207;
x829[x828] = -1;

}
}
}
for(int x837=0; x837 < 16384; x837++) {
int32_t* x838 = x12;
x838[x837] = -1;

}
for(int x842=0; x842 < 16384; x842++) {
int32_t* x843 = x207;
x843[x842] = -1;

}
for(int x847=0; x847 < 4194304; x847++) {
int32_t* x848 = x224;
x848[x847] = -1;

}
for(int x852=0; x852 < 4194304; x852++) {
int32_t* x853 = x48;
x853[x852] = -1;

}
int32_t x857 = x235;
bool x858 = x857 == 0;
if (x858) {
} else {
for(int x861=0; x861 < x857; x861++) {
int32_t x862 = x235;
for(int x864=0; x864 < x862; x864++) {
int32_t* x865 = x233;
int32_t x866 = x865[x864];
int32_t x867 = x865[x861];
bool x868 = x866 >= x867;
if (x868) {
int32_t x869 = x235;
for(int x871=0; x871 < x869; x871++) {
int32_t* x872 = x233;
bool x876 = true;
int32_t x877 = 0;
int32_t x873 = x872[x861];
int32_t x878 = x873 + 233;
x877 = x878;
int32_t x874 = x872[x864];
int32_t x880 = x878 * 1009;
int32_t x881 = x880 + x874;
int32_t x882 = x881 + 233;
x877 = x882;
int32_t x875 = x872[x871];
int32_t x884 = x882 * 1009;
int32_t x885 = x884 + x875;
int32_t x886 = x885 + 233;
x877 = x886;
int32_t x888 = x886 * 1009;
int32_t x889 = x888 + x874;
int32_t x890 = x889 + 233;
x877 = x890;
int32_t x892 = x890 * 1009;
int32_t x893 = x892 + 233;
x877 = x893;
int32_t* x896 = x93;
int32_t x895 = x893 & 4194303;
int32_t x897 = x896[x895];
int32_t x898 = x897;
bool x899 = true;
for (;;) {
bool x900 = x899;
bool x904;
if (x900) {
int32_t x901 = x898;
bool x902 = x901 != -1;
x904 = x902;
} else {
x904 = false;
}
if (!x904) break;
int32_t x906 = x898;
bool x907 = true;
int32_t* x908 = x57;
int32_t x909 = x908[x906];
bool x910 = x873 == x909;
if (x910) {
} else {
x907 = false;
}
int32_t* x914 = x61;
int32_t x915 = x914[x906];
bool x916 = x874 == x915;
if (x916) {
} else {
x907 = false;
}
int32_t* x920 = x65;
int32_t x921 = x920[x906];
bool x922 = x875 == x921;
if (x922) {
} else {
x907 = false;
}
int32_t* x926 = x69;
int32_t x927 = x926[x906];
bool x928 = x874 == x927;
if (x928) {
} else {
x907 = false;
}
int32_t* x932 = x73;
int32_t x933 = x932[x906];
bool x934 = 0 == x933;
if (x934) {
} else {
x907 = false;
}
bool x938 = x907;
if (x938) {
bool x939 = true;
if (x910) {
} else {
x939 = false;
}
if (x916) {
} else {
x939 = false;
}
if (x922) {
} else {
x939 = false;
}
if (x928) {
} else {
x939 = false;
}
if (x934) {
} else {
x939 = false;
}
bool x955 = x939;
if (x955) {
x876 = false;
} else {
}
bool x959 = x876;
x899 = x959;
} else {
}
int32_t* x963 = x78;
int32_t x964 = x963[x906];
x898 = x964;
}
bool x968 = x876;
if (x968) {
int32_t x971 = x75;
int32_t x972 = x54;
bool x973 = x971 == x972;
if (x973) {
x54 *= 4;
int32_t x975 = x54;
printf("buffer.resize %d\n",x975);
} else {
}
int32_t* x979 = x57;
x979[x971] = x873;
int32_t* x981 = x61;
x981[x971] = x874;
int32_t* x983 = x65;
x983[x971] = x875;
int32_t* x985 = x69;
x985[x971] = x874;
int32_t* x987 = x73;
x987[x971] = 0;
x75 += 1;
int32_t x990 = x971;
int32_t x991 = 0;
x991 = x878;
x991 = x882;
x991 = x886;
x991 = x890;
x991 = x893;
int32_t x997 = x897;
x896[x895] = x971;
int32_t* x999 = x78;
x999[x971] = x897;
int32_t x1001 = 0;
x1001 = x878;
x1001 = x882;
int32_t* x1005 = x95;
int32_t x1004 = x882 & 4194303;
int32_t x1006 = x1005[x1004];
int32_t x1007 = x1006;
x1005[x1004] = x971;
int32_t* x1009 = x82;
x1009[x971] = x1006;
int32_t x1011 = 0;
x1011 = x878;
x1011 = x882;
x1011 = x886;
int32_t* x1016 = x97;
int32_t x1015 = x886 & 4194303;
int32_t x1017 = x1016[x1015];
int32_t x1018 = x1017;
x1016[x1015] = x971;
int32_t* x1020 = x86;
x1020[x971] = x1017;
int32_t x1022 = 0;
int32_t x1023 = x874 + 233;
x1022 = x1023;
int32_t* x1026 = x99;
int32_t x1025 = x1023 & 4194303;
int32_t x1027 = x1026[x1025];
int32_t x1028 = x1027;
x1026[x1025] = x971;
int32_t* x1030 = x90;
x1030[x971] = x1027;
} else {
}

}
} else {
}

}

}
}
int32_t x1044 = x75;
for(int x1046=0; x1046 < x1044; x1046++) {
int32_t* x1047 = x57;
int32_t* x1049 = x61;
int32_t* x1051 = x65;
int32_t* x1053 = x69;
int32_t* x1055 = x73;
bool x1057 = true;
int32_t x1058 = 0;
int32_t x1048 = x1047[x1046];
int32_t x1059 = x1048 + 233;
x1058 = x1059;
int32_t x1050 = x1049[x1046];
int32_t x1061 = x1059 * 1009;
int32_t x1062 = x1061 + x1050;
int32_t x1063 = x1062 + 233;
x1058 = x1063;
int32_t x1052 = x1051[x1046];
int32_t x1065 = x1063 * 1009;
int32_t x1066 = x1065 + x1052;
int32_t x1067 = x1066 + 233;
x1058 = x1067;
int32_t x1054 = x1053[x1046];
int32_t x1069 = x1067 * 1009;
int32_t x1070 = x1069 + x1054;
int32_t x1071 = x1070 + 233;
x1058 = x1071;
int32_t x1056 = x1055[x1046];
int32_t x1073 = x1071 * 1009;
int32_t x1074 = x1073 + x1056;
int32_t x1075 = x1074 + 233;
x1058 = x1075;
int32_t* x1078 = x282;
int32_t x1077 = x1075 & 16383;
int32_t x1079 = x1078[x1077];
int32_t x1080 = x1079;
bool x1081 = true;
for (;;) {
bool x1082 = x1081;
bool x1086;
if (x1082) {
int32_t x1083 = x1080;
bool x1084 = x1083 != -1;
x1086 = x1084;
} else {
x1086 = false;
}
if (!x1086) break;
int32_t x1088 = x1080;
bool x1089 = true;
int32_t* x1090 = x250;
int32_t x1091 = x1090[x1088];
bool x1092 = x1048 == x1091;
if (x1092) {
} else {
x1089 = false;
}
int32_t* x1096 = x254;
int32_t x1097 = x1096[x1088];
bool x1098 = x1050 == x1097;
if (x1098) {
} else {
x1089 = false;
}
int32_t* x1102 = x258;
int32_t x1103 = x1102[x1088];
bool x1104 = x1052 == x1103;
if (x1104) {
} else {
x1089 = false;
}
int32_t* x1108 = x262;
int32_t x1109 = x1108[x1088];
bool x1110 = x1054 == x1109;
if (x1110) {
} else {
x1089 = false;
}
int32_t* x1114 = x266;
int32_t x1115 = x1114[x1088];
bool x1116 = x1056 == x1115;
if (x1116) {
} else {
x1089 = false;
}
bool x1120 = x1089;
if (x1120) {
bool x1121 = true;
if (x1092) {
} else {
x1121 = false;
}
if (x1098) {
} else {
x1121 = false;
}
if (x1104) {
} else {
x1121 = false;
}
if (x1110) {
} else {
x1121 = false;
}
if (x1116) {
} else {
x1121 = false;
}
bool x1137 = x1121;
if (x1137) {
x1057 = false;
} else {
}
bool x1141 = x1057;
x1081 = x1141;
} else {
}
int32_t* x1145 = x271;
int32_t x1146 = x1145[x1088];
x1080 = x1146;
}
bool x1150 = x1057;
if (x1150) {
int32_t x1153 = x268;
int32_t x1154 = x247;
bool x1155 = x1153 == x1154;
if (x1155) {
x247 *= 4;
int32_t x1157 = x247;
printf("buffer.resize %d\n",x1157);
} else {
}
int32_t* x1161 = x250;
x1161[x1153] = x1048;
int32_t* x1163 = x254;
x1163[x1153] = x1050;
int32_t* x1165 = x258;
x1165[x1153] = x1052;
int32_t* x1167 = x262;
x1167[x1153] = x1054;
int32_t* x1169 = x266;
x1169[x1153] = x1056;
x268 += 1;
int32_t x1172 = x1153;
int32_t x1173 = 0;
x1173 = x1059;
x1173 = x1063;
x1173 = x1067;
x1173 = x1071;
x1173 = x1075;
int32_t x1179 = x1079;
x1078[x1077] = x1153;
int32_t* x1181 = x271;
x1181[x1153] = x1079;
int32_t x1183 = 0;
x1183 = x1059;
x1183 = x1063;
int32_t* x1187 = x284;
int32_t x1186 = x1063 & 16383;
int32_t x1188 = x1187[x1186];
int32_t x1189 = x1188;
x1187[x1186] = x1153;
int32_t* x1191 = x275;
x1191[x1153] = x1188;
int32_t x1193 = 0;
x1193 = x1059;
x1193 = x1063;
x1193 = x1067;
int32_t* x1198 = x286;
int32_t x1197 = x1067 & 16383;
int32_t x1199 = x1198[x1197];
int32_t x1200 = x1199;
x1198[x1197] = x1153;
int32_t* x1202 = x279;
x1202[x1153] = x1199;
} else {
}

}
bool x1208 = true;
for (;;) {
bool x1209 = x1208;
if (!x1209) break;
int32_t x1211 = x75;
bool x1212 = x1211 == 0;
bool x1218;
if (x1212) {
x1218 = false;
} else {
int32_t x1214 = x268;
bool x1215 = x1214 == 0;
bool x1216 = !x1215;
x1218 = x1216;
}
if (x1218) {
int32_t x1219 = x268;
for(int x1221=0; x1221 < x1219; x1221++) {
int32_t* x1222 = x254;
int32_t* x1225 = x258;
int32_t x1227 = 0;
int32_t x1223 = x1222[x1221];
int32_t x1224 = x1223 - 1;
int32_t x1228 = x1224 + 233;
x1227 = x1228;
int32_t x1226 = x1225[x1221];
int32_t x1230 = x1228 * 1009;
int32_t x1231 = x1230 + x1226;
int32_t x1232 = x1231 + 233;
x1227 = x1232;
int32_t* x1235 = x95;
int32_t x1234 = x1232 & 4194303;
int32_t x1236 = x1235[x1234];
int32_t x1237 = x1236;
for (;;) {
int32_t x1238 = x1237;
bool x1239 = x1238 != -1;
if (!x1239) break;
int32_t x1241 = x1237;
bool x1242 = true;
int32_t* x1243 = x57;
int32_t x1244 = x1243[x1241];
bool x1245 = x1224 == x1244;
if (x1245) {
} else {
x1242 = false;
}
int32_t* x1249 = x61;
int32_t x1250 = x1249[x1241];
bool x1251 = x1226 == x1250;
if (x1251) {
} else {
x1242 = false;
}
bool x1255 = x1242;
if (x1255) {
int32_t* x1256 = x250;
int32_t* x1258 = x65;
int32_t x1257 = x1256[x1221];
int32_t x1259 = x1258[x1241];
int32_t x1260 = x1259 - 1;
bool x1261 = x1257 == x1260;
bool x1266;
if (x1261) {
int32_t* x1262 = x254;
int32_t x1263 = x1262[x1221];
bool x1264 = x1263 < x1259;
x1266 = x1264;
} else {
x1266 = false;
}
bool x1349;
if (x1266) {
int32_t* x1267 = x258;
int32_t* x1269 = x69;
int32_t* x1271 = x73;
bool x1273 = false;
int32_t x1274 = 0;
int32_t x1275 = x1244 + 233;
x1274 = x1275;
int32_t x1268 = x1267[x1221];
int32_t x1277 = x1275 * 1009;
int32_t x1278 = x1277 + x1268;
int32_t x1279 = x1278 + 233;
x1274 = x1279;
int32_t x1281 = x1279 * 1009;
int32_t x1282 = x1281 + x1259;
int32_t x1283 = x1282 + 233;
x1274 = x1283;
int32_t x1270 = x1269[x1241];
int32_t x1285 = x1283 * 1009;
int32_t x1286 = x1285 + x1270;
int32_t x1287 = x1286 + 233;
x1274 = x1287;
int32_t x1272 = x1271[x1241];
int32_t x1289 = x1287 * 1009;
int32_t x1290 = x1289 + x1272;
int32_t x1291 = x1290 + 233;
x1274 = x1291;
int32_t* x1294 = x282;
int32_t x1293 = x1291 & 16383;
int32_t x1295 = x1294[x1293];
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
int32_t* x1306 = x250;
int32_t x1307 = x1306[x1304];
bool x1308 = x1244 == x1307;
if (x1308) {
} else {
x1305 = false;
}
int32_t* x1312 = x254;
int32_t x1313 = x1312[x1304];
bool x1314 = x1268 == x1313;
if (x1314) {
} else {
x1305 = false;
}
int32_t* x1318 = x258;
int32_t x1319 = x1318[x1304];
bool x1320 = x1259 == x1319;
if (x1320) {
} else {
x1305 = false;
}
int32_t* x1324 = x262;
int32_t x1325 = x1324[x1304];
bool x1326 = x1270 == x1325;
if (x1326) {
} else {
x1305 = false;
}
int32_t* x1330 = x266;
int32_t x1331 = x1330[x1304];
bool x1332 = x1272 == x1331;
if (x1332) {
} else {
x1305 = false;
}
bool x1336 = x1305;
if (x1336) {
x1273 = true;
x1297 = false;
} else {
}
int32_t* x1341 = x271;
int32_t x1342 = x1341[x1304];
x1296 = x1342;
}
bool x1346 = x1273;
bool x1347 = !x1346;
x1349 = x1347;
} else {
x1349 = false;
}
if (x1349) {
int32_t* x1350 = x258;
int32_t* x1353 = x254;
int32_t x1355 = 0;
int32_t x1351 = x1350[x1221];
int32_t x1352 = x1351 - 1;
int32_t x1356 = x1352 + 233;
x1355 = x1356;
int32_t x1358 = x1356 * 1009;
int32_t x1359 = x1358 + x1259;
int32_t x1360 = x1359 + 233;
x1355 = x1360;
int32_t x1354 = x1353[x1221];
int32_t x1362 = x1360 * 1009;
int32_t x1363 = x1362 + x1354;
int32_t x1364 = x1363 + 233;
x1355 = x1364;
int32_t* x1367 = x97;
int32_t x1366 = x1364 & 4194303;
int32_t x1368 = x1367[x1366];
int32_t x1369 = x1368;
for (;;) {
int32_t x1370 = x1369;
bool x1371 = x1370 != -1;
if (!x1371) break;
int32_t x1373 = x1369;
bool x1374 = true;
int32_t* x1375 = x57;
int32_t x1376 = x1375[x1373];
bool x1377 = x1352 == x1376;
if (x1377) {
} else {
x1374 = false;
}
int32_t* x1381 = x61;
int32_t x1382 = x1381[x1373];
bool x1383 = x1259 == x1382;
if (x1383) {
} else {
x1374 = false;
}
int32_t* x1387 = x65;
int32_t x1388 = x1387[x1373];
bool x1389 = x1354 == x1388;
if (x1389) {
} else {
x1374 = false;
}
bool x1393 = x1374;
if (x1393) {
int32_t* x1395 = x254;
int32_t* x1397 = x69;
int32_t* x1399 = x73;
bool x1401 = false;
int32_t x1402 = 0;
int32_t x1403 = x1376 + 233;
x1402 = x1403;
int32_t x1394 = x1387[x1241];
int32_t x1405 = x1403 * 1009;
int32_t x1406 = x1405 + x1394;
int32_t x1407 = x1406 + 233;
x1402 = x1407;
int32_t x1396 = x1395[x1221];
int32_t x1409 = x1407 * 1009;
int32_t x1410 = x1409 + x1396;
int32_t x1411 = x1410 + 233;
x1402 = x1411;
int32_t x1398 = x1397[x1373];
int32_t x1413 = x1411 * 1009;
int32_t x1414 = x1413 + x1398;
int32_t x1415 = x1414 + 233;
x1402 = x1415;
int32_t x1400 = x1399[x1373];
int32_t x1417 = x1415 * 1009;
int32_t x1418 = x1417 + x1400;
int32_t x1419 = x1418 + 233;
x1402 = x1419;
int32_t* x1422 = x282;
int32_t x1421 = x1419 & 16383;
int32_t x1423 = x1422[x1421];
int32_t x1424 = x1423;
bool x1425 = true;
for (;;) {
bool x1426 = x1425;
bool x1430;
if (x1426) {
int32_t x1427 = x1424;
bool x1428 = x1427 != -1;
x1430 = x1428;
} else {
x1430 = false;
}
if (!x1430) break;
int32_t x1432 = x1424;
bool x1433 = true;
int32_t* x1434 = x250;
int32_t x1435 = x1434[x1432];
bool x1436 = x1376 == x1435;
if (x1436) {
} else {
x1433 = false;
}
int32_t* x1440 = x254;
int32_t x1441 = x1440[x1432];
bool x1442 = x1394 == x1441;
if (x1442) {
} else {
x1433 = false;
}
int32_t* x1446 = x258;
int32_t x1447 = x1446[x1432];
bool x1448 = x1396 == x1447;
if (x1448) {
} else {
x1433 = false;
}
int32_t* x1452 = x262;
int32_t x1453 = x1452[x1432];
bool x1454 = x1398 == x1453;
if (x1454) {
} else {
x1433 = false;
}
int32_t* x1458 = x266;
int32_t x1459 = x1458[x1432];
bool x1460 = x1400 == x1459;
if (x1460) {
} else {
x1433 = false;
}
bool x1464 = x1433;
if (x1464) {
x1401 = true;
x1425 = false;
} else {
}
int32_t* x1469 = x271;
int32_t x1470 = x1469[x1432];
x1424 = x1470;
}
bool x1474 = x1401;
if (x1474) {
} else {
int32_t* x1476 = x262;
int32_t x1479 = 0;
int32_t x1477 = x1476[x1221];
int32_t x1480 = x1477 + 233;
x1479 = x1480;
int32_t x1478 = x1397[x1241];
int32_t x1482 = x1480 * 1009;
int32_t x1483 = x1482 + x1478;
int32_t x1484 = x1483 + 233;
x1479 = x1484;
int32_t x1486 = x1484 * 1009;
int32_t x1487 = x1486 + x1398;
int32_t x1488 = x1487 + 233;
x1479 = x1488;
int32_t* x1491 = x97;
int32_t x1490 = x1488 & 4194303;
int32_t x1492 = x1491[x1490];
int32_t x1493 = x1492;
for (;;) {
int32_t x1494 = x1493;
bool x1495 = x1494 != -1;
if (!x1495) break;
int32_t x1497 = x1493;
bool x1498 = true;
int32_t* x1499 = x57;
int32_t x1500 = x1499[x1497];
bool x1501 = x1477 == x1500;
if (x1501) {
} else {
x1498 = false;
}
int32_t* x1505 = x61;
int32_t x1506 = x1505[x1497];
bool x1507 = x1478 == x1506;
if (x1507) {
} else {
x1498 = false;
}
int32_t* x1511 = x65;
int32_t x1512 = x1511[x1497];
bool x1513 = x1398 == x1512;
if (x1513) {
} else {
x1498 = false;
}
bool x1517 = x1498;
if (x1517) {
int32_t* x1518 = x262;
int32_t* x1520 = x69;
int32_t* x1524 = x73;
bool x1526 = false;
int32_t x1527 = 0;
int32_t x1519 = x1518[x1221];
int32_t x1528 = x1519 + 233;
x1527 = x1528;
int32_t x1521 = x1520[x1241];
int32_t x1530 = x1528 * 1009;
int32_t x1531 = x1530 + x1521;
int32_t x1532 = x1531 + 233;
x1527 = x1532;
int32_t x1522 = x1520[x1373];
int32_t x1534 = x1532 * 1009;
int32_t x1535 = x1534 + x1522;
int32_t x1536 = x1535 + 233;
x1527 = x1536;
int32_t x1523 = x1520[x1497];
int32_t x1538 = x1536 * 1009;
int32_t x1539 = x1538 + x1523;
int32_t x1540 = x1539 + 233;
x1527 = x1540;
int32_t x1525 = x1524[x1497];
int32_t x1542 = x1540 * 1009;
int32_t x1543 = x1542 + x1525;
int32_t x1544 = x1543 + 233;
x1527 = x1544;
int32_t* x1547 = x282;
int32_t x1546 = x1544 & 16383;
int32_t x1548 = x1547[x1546];
int32_t x1549 = x1548;
bool x1550 = true;
for (;;) {
bool x1551 = x1550;
bool x1555;
if (x1551) {
int32_t x1552 = x1549;
bool x1553 = x1552 != -1;
x1555 = x1553;
} else {
x1555 = false;
}
if (!x1555) break;
int32_t x1557 = x1549;
bool x1558 = true;
int32_t* x1559 = x250;
int32_t x1560 = x1559[x1557];
bool x1561 = x1519 == x1560;
if (x1561) {
} else {
x1558 = false;
}
int32_t* x1565 = x254;
int32_t x1566 = x1565[x1557];
bool x1567 = x1521 == x1566;
if (x1567) {
} else {
x1558 = false;
}
int32_t* x1571 = x258;
int32_t x1572 = x1571[x1557];
bool x1573 = x1522 == x1572;
if (x1573) {
} else {
x1558 = false;
}
int32_t* x1577 = x262;
int32_t x1578 = x1577[x1557];
bool x1579 = x1523 == x1578;
if (x1579) {
} else {
x1558 = false;
}
int32_t* x1583 = x266;
int32_t x1584 = x1583[x1557];
bool x1585 = x1525 == x1584;
if (x1585) {
} else {
x1558 = false;
}
bool x1589 = x1558;
if (x1589) {
x1526 = true;
x1550 = false;
} else {
}
int32_t* x1594 = x271;
int32_t x1595 = x1594[x1557];
x1549 = x1595;
}
bool x1599 = x1526;
bool x1690;
if (x1599) {
x1690 = false;
} else {
int32_t* x1602 = x254;
int32_t* x1604 = x258;
int32_t* x1606 = x266;
bool x1614 = false;
int32_t x1615 = 0;
int32_t x1601 = x1511[x1241];
int32_t x1616 = x1601 + 233;
x1615 = x1616;
int32_t x1603 = x1602[x1221];
int32_t x1618 = x1616 * 1009;
int32_t x1619 = x1618 + x1603;
int32_t x1620 = x1619 + 233;
x1615 = x1620;
int32_t x1605 = x1604[x1221];
int32_t x1622 = x1620 * 1009;
int32_t x1623 = x1622 + x1605;
int32_t x1624 = x1623 + 233;
x1615 = x1624;
int32_t x1626 = x1624 * 1009;
int32_t x1627 = x1626 + x1523;
int32_t x1628 = x1627 + 233;
x1615 = x1628;
int32_t x1607 = x1606[x1221];
int32_t x1608 = x1524[x1241];
int32_t x1609 = x1607 + x1608;
int32_t x1610 = x1524[x1373];
int32_t x1611 = x1609 + x1610;
int32_t x1612 = x1611 + x1525;
int32_t x1613 = x1612 + 1;
int32_t x1630 = x1628 * 1009;
int32_t x1631 = x1630 + x1613;
int32_t x1632 = x1631 + 233;
x1615 = x1632;
int32_t* x1635 = x93;
int32_t x1634 = x1632 & 4194303;
int32_t x1636 = x1635[x1634];
int32_t x1637 = x1636;
bool x1638 = true;
for (;;) {
bool x1639 = x1638;
bool x1643;
if (x1639) {
int32_t x1640 = x1637;
bool x1641 = x1640 != -1;
x1643 = x1641;
} else {
x1643 = false;
}
if (!x1643) break;
int32_t x1645 = x1637;
bool x1646 = true;
int32_t* x1647 = x57;
int32_t x1648 = x1647[x1645];
bool x1649 = x1601 == x1648;
if (x1649) {
} else {
x1646 = false;
}
int32_t* x1653 = x61;
int32_t x1654 = x1653[x1645];
bool x1655 = x1603 == x1654;
if (x1655) {
} else {
x1646 = false;
}
int32_t* x1659 = x65;
int32_t x1660 = x1659[x1645];
bool x1661 = x1605 == x1660;
if (x1661) {
} else {
x1646 = false;
}
int32_t* x1665 = x69;
int32_t x1666 = x1665[x1645];
bool x1667 = x1523 == x1666;
if (x1667) {
} else {
x1646 = false;
}
int32_t* x1671 = x73;
int32_t x1672 = x1671[x1645];
bool x1673 = x1613 == x1672;
if (x1673) {
} else {
x1646 = false;
}
bool x1677 = x1646;
if (x1677) {
x1614 = true;
x1638 = false;
} else {
}
int32_t* x1682 = x78;
int32_t x1683 = x1682[x1645];
x1637 = x1683;
}
bool x1687 = x1614;
bool x1688 = !x1687;
x1690 = x1688;
}
if (x1690) {
int32_t* x1691 = x254;
int32_t* x1693 = x258;
int32_t* x1695 = x266;
bool x1701 = true;
int32_t x1702 = 0;
int32_t x1601 = x1511[x1241];
int32_t x1616 = x1601 + 233;
x1702 = x1616;
int32_t x1618 = x1616 * 1009;
int32_t x1692 = x1691[x1221];
int32_t x1704 = x1618 + x1692;
int32_t x1705 = x1704 + 233;
x1702 = x1705;
int32_t x1694 = x1693[x1221];
int32_t x1707 = x1705 * 1009;
int32_t x1708 = x1707 + x1694;
int32_t x1709 = x1708 + 233;
x1702 = x1709;
int32_t x1711 = x1709 * 1009;
int32_t x1712 = x1711 + x1523;
int32_t x1713 = x1712 + 233;
x1702 = x1713;
int32_t x1610 = x1524[x1373];
int32_t x1608 = x1524[x1241];
int32_t x1696 = x1695[x1221];
int32_t x1697 = x1696 + x1608;
int32_t x1698 = x1697 + x1610;
int32_t x1699 = x1698 + x1525;
int32_t x1700 = x1699 + 1;
int32_t x1715 = x1713 * 1009;
int32_t x1716 = x1715 + x1700;
int32_t x1717 = x1716 + 233;
x1702 = x1717;
int32_t* x1720 = x176;
int32_t x1719 = x1717 & 16383;
int32_t x1721 = x1720[x1719];
int32_t x1722 = x1721;
bool x1723 = true;
for (;;) {
bool x1724 = x1723;
bool x1728;
if (x1724) {
int32_t x1725 = x1722;
bool x1726 = x1725 != -1;
x1728 = x1726;
} else {
x1728 = false;
}
if (!x1728) break;
int32_t x1730 = x1722;
bool x1731 = true;
int32_t* x1732 = x144;
int32_t x1733 = x1732[x1730];
bool x1734 = x1601 == x1733;
if (x1734) {
} else {
x1731 = false;
}
int32_t* x1738 = x148;
int32_t x1739 = x1738[x1730];
bool x1740 = x1692 == x1739;
if (x1740) {
} else {
x1731 = false;
}
int32_t* x1744 = x152;
int32_t x1745 = x1744[x1730];
bool x1746 = x1694 == x1745;
if (x1746) {
} else {
x1731 = false;
}
int32_t* x1750 = x156;
int32_t x1751 = x1750[x1730];
bool x1752 = x1523 == x1751;
if (x1752) {
} else {
x1731 = false;
}
int32_t* x1756 = x160;
int32_t x1757 = x1756[x1730];
bool x1758 = x1700 == x1757;
if (x1758) {
} else {
x1731 = false;
}
bool x1762 = x1731;
if (x1762) {
bool x1763 = true;
if (x1734) {
} else {
x1763 = false;
}
if (x1740) {
} else {
x1763 = false;
}
if (x1746) {
} else {
x1763 = false;
}
if (x1752) {
} else {
x1763 = false;
}
if (x1758) {
} else {
x1763 = false;
}
bool x1779 = x1763;
if (x1779) {
x1701 = false;
} else {
}
bool x1783 = x1701;
x1723 = x1783;
} else {
}
int32_t* x1787 = x165;
int32_t x1788 = x1787[x1730];
x1722 = x1788;
}
bool x1792 = x1701;
if (x1792) {
int32_t x1795 = x162;
int32_t x1796 = x141;
bool x1797 = x1795 == x1796;
if (x1797) {
x141 *= 4;
int32_t x1799 = x141;
printf("buffer.resize %d\n",x1799);
} else {
}
int32_t* x1803 = x144;
x1803[x1795] = x1601;
int32_t* x1805 = x148;
x1805[x1795] = x1692;
int32_t* x1807 = x152;
x1807[x1795] = x1694;
int32_t* x1809 = x156;
x1809[x1795] = x1523;
int32_t* x1811 = x160;
x1811[x1795] = x1700;
x162 += 1;
int32_t x1814 = x1795;
int32_t x1815 = 0;
x1815 = x1616;
x1815 = x1705;
x1815 = x1709;
x1815 = x1713;
x1815 = x1717;
int32_t x1821 = x1721;
x1720[x1719] = x1795;
int32_t* x1823 = x165;
x1823[x1795] = x1721;
int32_t x1825 = 0;
x1825 = x1616;
x1825 = x1705;
int32_t* x1829 = x178;
int32_t x1828 = x1705 & 16383;
int32_t x1830 = x1829[x1828];
int32_t x1831 = x1830;
x1829[x1828] = x1795;
int32_t* x1833 = x169;
x1833[x1795] = x1830;
int32_t x1835 = 0;
x1835 = x1616;
x1835 = x1705;
x1835 = x1709;
int32_t* x1840 = x180;
int32_t x1839 = x1709 & 16383;
int32_t x1841 = x1840[x1839];
int32_t x1842 = x1841;
x1840[x1839] = x1795;
int32_t* x1844 = x173;
x1844[x1795] = x1841;
} else {
}
} else {
}
} else {
}
int32_t* x1852 = x86;
int32_t x1853 = x1852[x1497];
x1493 = x1853;
}
}
} else {
}
int32_t* x1861 = x86;
int32_t x1862 = x1861[x1373];
x1369 = x1862;
}
} else {
}
} else {
}
int32_t* x1870 = x82;
int32_t x1871 = x1870[x1241];
x1237 = x1871;
}

}
} else {
}
bool x1883;
if (x1212) {
x1883 = false;
} else {
int32_t x1879 = x268;
bool x1880 = x1879 == 0;
bool x1881 = !x1880;
x1883 = x1881;
}
if (x1883) {
for(int x1885=0; x1885 < x1211; x1885++) {
int32_t* x1886 = x61;
int32_t* x1889 = x65;
int32_t x1891 = 0;
int32_t x1887 = x1886[x1885];
int32_t x1888 = x1887 - 1;
int32_t x1892 = x1888 + 233;
x1891 = x1892;
int32_t x1890 = x1889[x1885];
int32_t x1894 = x1892 * 1009;
int32_t x1895 = x1894 + x1890;
int32_t x1896 = x1895 + 233;
x1891 = x1896;
int32_t* x1899 = x284;
int32_t x1898 = x1896 & 16383;
int32_t x1900 = x1899[x1898];
int32_t x1901 = x1900;
for (;;) {
int32_t x1902 = x1901;
bool x1903 = x1902 != -1;
if (!x1903) break;
int32_t x1905 = x1901;
bool x1906 = true;
int32_t* x1907 = x250;
int32_t x1908 = x1907[x1905];
bool x1909 = x1888 == x1908;
if (x1909) {
} else {
x1906 = false;
}
int32_t* x1913 = x254;
int32_t x1914 = x1913[x1905];
bool x1915 = x1890 == x1914;
if (x1915) {
} else {
x1906 = false;
}
bool x1919 = x1906;
if (x1919) {
int32_t* x1920 = x61;
int32_t* x1922 = x258;
int32_t x1921 = x1920[x1885];
int32_t x1923 = x1922[x1905];
bool x1924 = x1921 < x1923;
bool x1930;
if (x1924) {
int32_t* x1925 = x57;
int32_t x1926 = x1925[x1885];
int32_t x1927 = x1923 - 1;
bool x1928 = x1926 == x1927;
x1930 = x1928;
} else {
x1930 = false;
}
if (x1930) {
int32_t* x1931 = x65;
int32_t x1934 = 0;
int32_t x1932 = x1931[x1885];
int32_t x1933 = x1932 - 1;
int32_t x1935 = x1933 + 233;
x1934 = x1935;
int32_t x1937 = x1935 * 1009;
int32_t x1938 = x1937 + x1923;
int32_t x1939 = x1938 + 233;
x1934 = x1939;
int32_t x1941 = x1939 * 1009;
int32_t x1942 = x1941 + x1921;
int32_t x1943 = x1942 + 233;
x1934 = x1943;
int32_t* x1946 = x97;
int32_t x1945 = x1943 & 4194303;
int32_t x1947 = x1946[x1945];
int32_t x1948 = x1947;
for (;;) {
int32_t x1949 = x1948;
bool x1950 = x1949 != -1;
if (!x1950) break;
int32_t x1952 = x1948;
bool x1953 = true;
int32_t* x1954 = x57;
int32_t x1955 = x1954[x1952];
bool x1956 = x1933 == x1955;
if (x1956) {
} else {
x1953 = false;
}
int32_t* x1960 = x61;
int32_t x1961 = x1960[x1952];
bool x1962 = x1923 == x1961;
if (x1962) {
} else {
x1953 = false;
}
int32_t* x1966 = x65;
int32_t x1967 = x1966[x1952];
bool x1968 = x1921 == x1967;
if (x1968) {
} else {
x1953 = false;
}
bool x1972 = x1953;
if (x1972) {
int32_t* x1973 = x258;
int32_t* x1976 = x69;
int32_t* x1978 = x73;
bool x1980 = false;
int32_t x1981 = 0;
int32_t x1982 = x1955 + 233;
x1981 = x1982;
int32_t x1974 = x1973[x1905];
int32_t x1984 = x1982 * 1009;
int32_t x1985 = x1984 + x1974;
int32_t x1986 = x1985 + 233;
x1981 = x1986;
int32_t x1975 = x1960[x1885];
int32_t x1988 = x1986 * 1009;
int32_t x1989 = x1988 + x1975;
int32_t x1990 = x1989 + 233;
x1981 = x1990;
int32_t x1977 = x1976[x1952];
int32_t x1992 = x1990 * 1009;
int32_t x1993 = x1992 + x1977;
int32_t x1994 = x1993 + 233;
x1981 = x1994;
int32_t x1979 = x1978[x1952];
int32_t x1996 = x1994 * 1009;
int32_t x1997 = x1996 + x1979;
int32_t x1998 = x1997 + 233;
x1981 = x1998;
int32_t* x2001 = x282;
int32_t x2000 = x1998 & 16383;
int32_t x2002 = x2001[x2000];
int32_t x2003 = x2002;
bool x2004 = true;
for (;;) {
bool x2005 = x2004;
bool x2009;
if (x2005) {
int32_t x2006 = x2003;
bool x2007 = x2006 != -1;
x2009 = x2007;
} else {
x2009 = false;
}
if (!x2009) break;
int32_t x2011 = x2003;
bool x2012 = true;
int32_t* x2013 = x250;
int32_t x2014 = x2013[x2011];
bool x2015 = x1955 == x2014;
if (x2015) {
} else {
x2012 = false;
}
int32_t* x2019 = x254;
int32_t x2020 = x2019[x2011];
bool x2021 = x1974 == x2020;
if (x2021) {
} else {
x2012 = false;
}
int32_t* x2025 = x258;
int32_t x2026 = x2025[x2011];
bool x2027 = x1975 == x2026;
if (x2027) {
} else {
x2012 = false;
}
int32_t* x2031 = x262;
int32_t x2032 = x2031[x2011];
bool x2033 = x1977 == x2032;
if (x2033) {
} else {
x2012 = false;
}
int32_t* x2037 = x266;
int32_t x2038 = x2037[x2011];
bool x2039 = x1979 == x2038;
if (x2039) {
} else {
x2012 = false;
}
bool x2043 = x2012;
if (x2043) {
x1980 = true;
x2004 = false;
} else {
}
int32_t* x2048 = x271;
int32_t x2049 = x2048[x2011];
x2003 = x2049;
}
bool x2053 = x1980;
if (x2053) {
} else {
int32_t* x2056 = x262;
int32_t x2058 = 0;
int32_t x2055 = x1976[x1885];
int32_t x2059 = x2055 + 233;
x2058 = x2059;
int32_t x2057 = x2056[x1905];
int32_t x2061 = x2059 * 1009;
int32_t x2062 = x2061 + x2057;
int32_t x2063 = x2062 + 233;
x2058 = x2063;
int32_t x2065 = x2063 * 1009;
int32_t x2066 = x2065 + x1977;
int32_t x2067 = x2066 + 233;
x2058 = x2067;
int32_t* x2070 = x97;
int32_t x2069 = x2067 & 4194303;
int32_t x2071 = x2070[x2069];
int32_t x2072 = x2071;
for (;;) {
int32_t x2073 = x2072;
bool x2074 = x2073 != -1;
if (!x2074) break;
int32_t x2076 = x2072;
bool x2077 = true;
int32_t* x2078 = x57;
int32_t x2079 = x2078[x2076];
bool x2080 = x2055 == x2079;
if (x2080) {
} else {
x2077 = false;
}
int32_t* x2084 = x61;
int32_t x2085 = x2084[x2076];
bool x2086 = x2057 == x2085;
if (x2086) {
} else {
x2077 = false;
}
int32_t* x2090 = x65;
int32_t x2091 = x2090[x2076];
bool x2092 = x1977 == x2091;
if (x2092) {
} else {
x2077 = false;
}
bool x2096 = x2077;
if (x2096) {
int32_t* x2097 = x69;
int32_t* x2099 = x262;
int32_t* x2103 = x73;
bool x2105 = false;
int32_t x2106 = 0;
int32_t x2098 = x2097[x1885];
int32_t x2107 = x2098 + 233;
x2106 = x2107;
int32_t x2100 = x2099[x1905];
int32_t x2109 = x2107 * 1009;
int32_t x2110 = x2109 + x2100;
int32_t x2111 = x2110 + 233;
x2106 = x2111;
int32_t x2101 = x2097[x1952];
int32_t x2113 = x2111 * 1009;
int32_t x2114 = x2113 + x2101;
int32_t x2115 = x2114 + 233;
x2106 = x2115;
int32_t x2102 = x2097[x2076];
int32_t x2117 = x2115 * 1009;
int32_t x2118 = x2117 + x2102;
int32_t x2119 = x2118 + 233;
x2106 = x2119;
int32_t x2104 = x2103[x2076];
int32_t x2121 = x2119 * 1009;
int32_t x2122 = x2121 + x2104;
int32_t x2123 = x2122 + 233;
x2106 = x2123;
int32_t* x2126 = x282;
int32_t x2125 = x2123 & 16383;
int32_t x2127 = x2126[x2125];
int32_t x2128 = x2127;
bool x2129 = true;
for (;;) {
bool x2130 = x2129;
bool x2134;
if (x2130) {
int32_t x2131 = x2128;
bool x2132 = x2131 != -1;
x2134 = x2132;
} else {
x2134 = false;
}
if (!x2134) break;
int32_t x2136 = x2128;
bool x2137 = true;
int32_t* x2138 = x250;
int32_t x2139 = x2138[x2136];
bool x2140 = x2098 == x2139;
if (x2140) {
} else {
x2137 = false;
}
int32_t* x2144 = x254;
int32_t x2145 = x2144[x2136];
bool x2146 = x2100 == x2145;
if (x2146) {
} else {
x2137 = false;
}
int32_t* x2150 = x258;
int32_t x2151 = x2150[x2136];
bool x2152 = x2101 == x2151;
if (x2152) {
} else {
x2137 = false;
}
int32_t* x2156 = x262;
int32_t x2157 = x2156[x2136];
bool x2158 = x2102 == x2157;
if (x2158) {
} else {
x2137 = false;
}
int32_t* x2162 = x266;
int32_t x2163 = x2162[x2136];
bool x2164 = x2104 == x2163;
if (x2164) {
} else {
x2137 = false;
}
bool x2168 = x2137;
if (x2168) {
x2105 = true;
x2129 = false;
} else {
}
int32_t* x2173 = x271;
int32_t x2174 = x2173[x2136];
x2128 = x2174;
}
bool x2178 = x2105;
bool x2268;
if (x2178) {
x2268 = false;
} else {
int32_t* x2180 = x258;
int32_t* x2185 = x266;
bool x2192 = false;
int32_t x2193 = 0;
int32_t x2181 = x2180[x1905];
int32_t x2194 = x2181 + 233;
x2193 = x2194;
int32_t x2182 = x2084[x1885];
int32_t x2196 = x2194 * 1009;
int32_t x2197 = x2196 + x2182;
int32_t x2198 = x2197 + 233;
x2193 = x2198;
int32_t x2183 = x2090[x1885];
int32_t x2200 = x2198 * 1009;
int32_t x2201 = x2200 + x2183;
int32_t x2202 = x2201 + 233;
x2193 = x2202;
int32_t x2204 = x2202 * 1009;
int32_t x2205 = x2204 + x2102;
int32_t x2206 = x2205 + 233;
x2193 = x2206;
int32_t x2184 = x2103[x1885];
int32_t x2186 = x2185[x1905];
int32_t x2187 = x2184 + x2186;
int32_t x2188 = x2103[x1952];
int32_t x2189 = x2187 + x2188;
int32_t x2190 = x2189 + x2104;
int32_t x2191 = x2190 + 1;
int32_t x2208 = x2206 * 1009;
int32_t x2209 = x2208 + x2191;
int32_t x2210 = x2209 + 233;
x2193 = x2210;
int32_t* x2213 = x93;
int32_t x2212 = x2210 & 4194303;
int32_t x2214 = x2213[x2212];
int32_t x2215 = x2214;
bool x2216 = true;
for (;;) {
bool x2217 = x2216;
bool x2221;
if (x2217) {
int32_t x2218 = x2215;
bool x2219 = x2218 != -1;
x2221 = x2219;
} else {
x2221 = false;
}
if (!x2221) break;
int32_t x2223 = x2215;
bool x2224 = true;
int32_t* x2225 = x57;
int32_t x2226 = x2225[x2223];
bool x2227 = x2181 == x2226;
if (x2227) {
} else {
x2224 = false;
}
int32_t* x2231 = x61;
int32_t x2232 = x2231[x2223];
bool x2233 = x2182 == x2232;
if (x2233) {
} else {
x2224 = false;
}
int32_t* x2237 = x65;
int32_t x2238 = x2237[x2223];
bool x2239 = x2183 == x2238;
if (x2239) {
} else {
x2224 = false;
}
int32_t* x2243 = x69;
int32_t x2244 = x2243[x2223];
bool x2245 = x2102 == x2244;
if (x2245) {
} else {
x2224 = false;
}
int32_t* x2249 = x73;
int32_t x2250 = x2249[x2223];
bool x2251 = x2191 == x2250;
if (x2251) {
} else {
x2224 = false;
}
bool x2255 = x2224;
if (x2255) {
x2192 = true;
x2216 = false;
} else {
}
int32_t* x2260 = x78;
int32_t x2261 = x2260[x2223];
x2215 = x2261;
}
bool x2265 = x2192;
bool x2266 = !x2265;
x2268 = x2266;
}
if (x2268) {
int32_t* x2269 = x258;
int32_t* x2271 = x266;
bool x2277 = true;
int32_t x2278 = 0;
int32_t x2270 = x2269[x1905];
int32_t x2279 = x2270 + 233;
x2278 = x2279;
int32_t x2182 = x2084[x1885];
int32_t x2281 = x2279 * 1009;
int32_t x2282 = x2281 + x2182;
int32_t x2283 = x2282 + 233;
x2278 = x2283;
int32_t x2183 = x2090[x1885];
int32_t x2285 = x2283 * 1009;
int32_t x2286 = x2285 + x2183;
int32_t x2287 = x2286 + 233;
x2278 = x2287;
int32_t x2289 = x2287 * 1009;
int32_t x2290 = x2289 + x2102;
int32_t x2291 = x2290 + 233;
x2278 = x2291;
int32_t x2188 = x2103[x1952];
int32_t x2184 = x2103[x1885];
int32_t x2272 = x2271[x1905];
int32_t x2273 = x2184 + x2272;
int32_t x2274 = x2273 + x2188;
int32_t x2275 = x2274 + x2104;
int32_t x2276 = x2275 + 1;
int32_t x2293 = x2291 * 1009;
int32_t x2294 = x2293 + x2276;
int32_t x2295 = x2294 + 233;
x2278 = x2295;
int32_t* x2298 = x176;
int32_t x2297 = x2295 & 16383;
int32_t x2299 = x2298[x2297];
int32_t x2300 = x2299;
bool x2301 = true;
for (;;) {
bool x2302 = x2301;
bool x2306;
if (x2302) {
int32_t x2303 = x2300;
bool x2304 = x2303 != -1;
x2306 = x2304;
} else {
x2306 = false;
}
if (!x2306) break;
int32_t x2308 = x2300;
bool x2309 = true;
int32_t* x2310 = x144;
int32_t x2311 = x2310[x2308];
bool x2312 = x2270 == x2311;
if (x2312) {
} else {
x2309 = false;
}
int32_t* x2316 = x148;
int32_t x2317 = x2316[x2308];
bool x2318 = x2182 == x2317;
if (x2318) {
} else {
x2309 = false;
}
int32_t* x2322 = x152;
int32_t x2323 = x2322[x2308];
bool x2324 = x2183 == x2323;
if (x2324) {
} else {
x2309 = false;
}
int32_t* x2328 = x156;
int32_t x2329 = x2328[x2308];
bool x2330 = x2102 == x2329;
if (x2330) {
} else {
x2309 = false;
}
int32_t* x2334 = x160;
int32_t x2335 = x2334[x2308];
bool x2336 = x2276 == x2335;
if (x2336) {
} else {
x2309 = false;
}
bool x2340 = x2309;
if (x2340) {
bool x2341 = true;
if (x2312) {
} else {
x2341 = false;
}
if (x2318) {
} else {
x2341 = false;
}
if (x2324) {
} else {
x2341 = false;
}
if (x2330) {
} else {
x2341 = false;
}
if (x2336) {
} else {
x2341 = false;
}
bool x2357 = x2341;
if (x2357) {
x2277 = false;
} else {
}
bool x2361 = x2277;
x2301 = x2361;
} else {
}
int32_t* x2365 = x165;
int32_t x2366 = x2365[x2308];
x2300 = x2366;
}
bool x2370 = x2277;
if (x2370) {
int32_t x2373 = x162;
int32_t x2374 = x141;
bool x2375 = x2373 == x2374;
if (x2375) {
x141 *= 4;
int32_t x2377 = x141;
printf("buffer.resize %d\n",x2377);
} else {
}
int32_t* x2381 = x144;
x2381[x2373] = x2270;
int32_t* x2383 = x148;
x2383[x2373] = x2182;
int32_t* x2385 = x152;
x2385[x2373] = x2183;
int32_t* x2387 = x156;
x2387[x2373] = x2102;
int32_t* x2389 = x160;
x2389[x2373] = x2276;
x162 += 1;
int32_t x2392 = x2373;
int32_t x2393 = 0;
x2393 = x2279;
x2393 = x2283;
x2393 = x2287;
x2393 = x2291;
x2393 = x2295;
int32_t x2399 = x2299;
x2298[x2297] = x2373;
int32_t* x2401 = x165;
x2401[x2373] = x2299;
int32_t x2403 = 0;
x2403 = x2279;
x2403 = x2283;
int32_t* x2407 = x178;
int32_t x2406 = x2283 & 16383;
int32_t x2408 = x2407[x2406];
int32_t x2409 = x2408;
x2407[x2406] = x2373;
int32_t* x2411 = x169;
x2411[x2373] = x2408;
int32_t x2413 = 0;
x2413 = x2279;
x2413 = x2283;
x2413 = x2287;
int32_t* x2418 = x180;
int32_t x2417 = x2287 & 16383;
int32_t x2419 = x2418[x2417];
int32_t x2420 = x2419;
x2418[x2417] = x2373;
int32_t* x2422 = x173;
x2422[x2373] = x2419;
} else {
}
} else {
}
} else {
}
int32_t* x2430 = x86;
int32_t x2431 = x2430[x2076];
x2072 = x2431;
}
}
} else {
}
int32_t* x2439 = x86;
int32_t x2440 = x2439[x1952];
x1948 = x2440;
}
} else {
}
} else {
}
int32_t* x2448 = x275;
int32_t x2449 = x2448[x1905];
x1901 = x2449;
}

}
} else {
}
bool x2461;
if (x1212) {
x2461 = false;
} else {
int32_t x2457 = x268;
bool x2458 = x2457 == 0;
bool x2459 = !x2458;
x2461 = x2459;
}
if (x2461) {
for(int x2462=0; x2462 < x1211; x2462++) {
int32_t* x2463 = x61;
int32_t* x2466 = x65;
int32_t x2468 = 0;
int32_t x2464 = x2463[x2462];
int32_t x2465 = x2464 - 1;
int32_t x2469 = x2465 + 233;
x2468 = x2469;
int32_t x2467 = x2466[x2462];
int32_t x2471 = x2469 * 1009;
int32_t x2472 = x2471 + x2467;
int32_t x2473 = x2472 + 233;
x2468 = x2473;
int32_t* x2476 = x95;
int32_t x2475 = x2473 & 4194303;
int32_t x2477 = x2476[x2475];
int32_t x2478 = x2477;
for (;;) {
int32_t x2479 = x2478;
bool x2480 = x2479 != -1;
if (!x2480) break;
int32_t x2482 = x2478;
bool x2483 = true;
int32_t* x2484 = x57;
int32_t x2485 = x2484[x2482];
bool x2486 = x2465 == x2485;
if (x2486) {
} else {
x2483 = false;
}
int32_t* x2490 = x61;
int32_t x2491 = x2490[x2482];
bool x2492 = x2467 == x2491;
if (x2492) {
} else {
x2483 = false;
}
bool x2496 = x2483;
if (x2496) {
int32_t* x2498 = x65;
int32_t x2497 = x2490[x2462];
int32_t x2499 = x2498[x2482];
bool x2500 = x2497 < x2499;
bool x2504;
if (x2500) {
int32_t x2501 = x2484[x2462];
int32_t x2502 = x2499 - 1;
bool x2503 = x2501 == x2502;
x2504 = x2503;
} else {
x2504 = false;
}
if (x2504) {
int32_t x2507 = 0;
int32_t x2505 = x2498[x2462];
int32_t x2506 = x2505 - 1;
int32_t x2508 = x2506 + 233;
x2507 = x2508;
int32_t x2510 = x2508 * 1009;
int32_t x2511 = x2510 + x2499;
int32_t x2512 = x2511 + 233;
x2507 = x2512;
int32_t x2514 = x2512 * 1009;
int32_t x2515 = x2514 + x2497;
int32_t x2516 = x2515 + 233;
x2507 = x2516;
int32_t* x2519 = x286;
int32_t x2518 = x2516 & 16383;
int32_t x2520 = x2519[x2518];
int32_t x2521 = x2520;
for (;;) {
int32_t x2522 = x2521;
bool x2523 = x2522 != -1;
if (!x2523) break;
int32_t x2525 = x2521;
bool x2526 = true;
int32_t* x2527 = x250;
int32_t x2528 = x2527[x2525];
bool x2529 = x2506 == x2528;
if (x2529) {
} else {
x2526 = false;
}
int32_t* x2533 = x254;
int32_t x2534 = x2533[x2525];
bool x2535 = x2499 == x2534;
if (x2535) {
} else {
x2526 = false;
}
int32_t* x2539 = x258;
int32_t x2540 = x2539[x2525];
bool x2541 = x2497 == x2540;
if (x2541) {
} else {
x2526 = false;
}
bool x2545 = x2526;
if (x2545) {
int32_t* x2546 = x69;
int32_t* x2549 = x262;
int32_t x2551 = 0;
int32_t x2547 = x2546[x2462];
int32_t x2552 = x2547 + 233;
x2551 = x2552;
int32_t x2548 = x2546[x2482];
int32_t x2554 = x2552 * 1009;
int32_t x2555 = x2554 + x2548;
int32_t x2556 = x2555 + 233;
x2551 = x2556;
int32_t x2550 = x2549[x2525];
int32_t x2558 = x2556 * 1009;
int32_t x2559 = x2558 + x2550;
int32_t x2560 = x2559 + 233;
x2551 = x2560;
int32_t* x2563 = x97;
int32_t x2562 = x2560 & 4194303;
int32_t x2564 = x2563[x2562];
int32_t x2565 = x2564;
for (;;) {
int32_t x2566 = x2565;
bool x2567 = x2566 != -1;
if (!x2567) break;
int32_t x2569 = x2565;
bool x2570 = true;
int32_t* x2571 = x57;
int32_t x2572 = x2571[x2569];
bool x2573 = x2547 == x2572;
if (x2573) {
} else {
x2570 = false;
}
int32_t* x2577 = x61;
int32_t x2578 = x2577[x2569];
bool x2579 = x2548 == x2578;
if (x2579) {
} else {
x2570 = false;
}
int32_t* x2583 = x65;
int32_t x2584 = x2583[x2569];
bool x2585 = x2550 == x2584;
if (x2585) {
} else {
x2570 = false;
}
bool x2589 = x2570;
if (x2589) {
int32_t* x2590 = x69;
int32_t* x2593 = x262;
int32_t* x2596 = x73;
bool x2598 = false;
int32_t x2599 = 0;
int32_t x2591 = x2590[x2462];
int32_t x2600 = x2591 + 233;
x2599 = x2600;
int32_t x2592 = x2590[x2482];
int32_t x2602 = x2600 * 1009;
int32_t x2603 = x2602 + x2592;
int32_t x2604 = x2603 + 233;
x2599 = x2604;
int32_t x2594 = x2593[x2525];
int32_t x2606 = x2604 * 1009;
int32_t x2607 = x2606 + x2594;
int32_t x2608 = x2607 + 233;
x2599 = x2608;
int32_t x2595 = x2590[x2569];
int32_t x2610 = x2608 * 1009;
int32_t x2611 = x2610 + x2595;
int32_t x2612 = x2611 + 233;
x2599 = x2612;
int32_t x2597 = x2596[x2569];
int32_t x2614 = x2612 * 1009;
int32_t x2615 = x2614 + x2597;
int32_t x2616 = x2615 + 233;
x2599 = x2616;
int32_t* x2619 = x282;
int32_t x2618 = x2616 & 16383;
int32_t x2620 = x2619[x2618];
int32_t x2621 = x2620;
bool x2622 = true;
for (;;) {
bool x2623 = x2622;
bool x2627;
if (x2623) {
int32_t x2624 = x2621;
bool x2625 = x2624 != -1;
x2627 = x2625;
} else {
x2627 = false;
}
if (!x2627) break;
int32_t x2629 = x2621;
bool x2630 = true;
int32_t* x2631 = x250;
int32_t x2632 = x2631[x2629];
bool x2633 = x2591 == x2632;
if (x2633) {
} else {
x2630 = false;
}
int32_t* x2637 = x254;
int32_t x2638 = x2637[x2629];
bool x2639 = x2592 == x2638;
if (x2639) {
} else {
x2630 = false;
}
int32_t* x2643 = x258;
int32_t x2644 = x2643[x2629];
bool x2645 = x2594 == x2644;
if (x2645) {
} else {
x2630 = false;
}
int32_t* x2649 = x262;
int32_t x2650 = x2649[x2629];
bool x2651 = x2595 == x2650;
if (x2651) {
} else {
x2630 = false;
}
int32_t* x2655 = x266;
int32_t x2656 = x2655[x2629];
bool x2657 = x2597 == x2656;
if (x2657) {
} else {
x2630 = false;
}
bool x2661 = x2630;
if (x2661) {
x2598 = true;
x2622 = false;
} else {
}
int32_t* x2666 = x271;
int32_t x2667 = x2666[x2629];
x2621 = x2667;
}
bool x2671 = x2598;
bool x2760;
if (x2671) {
x2760 = false;
} else {
int32_t* x2679 = x266;
bool x2684 = false;
int32_t x2685 = 0;
int32_t x2673 = x2583[x2482];
int32_t x2686 = x2673 + 233;
x2685 = x2686;
int32_t x2674 = x2577[x2462];
int32_t x2688 = x2686 * 1009;
int32_t x2689 = x2688 + x2674;
int32_t x2690 = x2689 + 233;
x2685 = x2690;
int32_t x2675 = x2583[x2462];
int32_t x2692 = x2690 * 1009;
int32_t x2693 = x2692 + x2675;
int32_t x2694 = x2693 + 233;
x2685 = x2694;
int32_t x2696 = x2694 * 1009;
int32_t x2697 = x2696 + x2595;
int32_t x2698 = x2697 + 233;
x2685 = x2698;
int32_t x2676 = x2596[x2462];
int32_t x2677 = x2596[x2482];
int32_t x2678 = x2676 + x2677;
int32_t x2680 = x2679[x2525];
int32_t x2681 = x2678 + x2680;
int32_t x2682 = x2681 + x2597;
int32_t x2683 = x2682 + 1;
int32_t x2700 = x2698 * 1009;
int32_t x2701 = x2700 + x2683;
int32_t x2702 = x2701 + 233;
x2685 = x2702;
int32_t* x2705 = x93;
int32_t x2704 = x2702 & 4194303;
int32_t x2706 = x2705[x2704];
int32_t x2707 = x2706;
bool x2708 = true;
for (;;) {
bool x2709 = x2708;
bool x2713;
if (x2709) {
int32_t x2710 = x2707;
bool x2711 = x2710 != -1;
x2713 = x2711;
} else {
x2713 = false;
}
if (!x2713) break;
int32_t x2715 = x2707;
bool x2716 = true;
int32_t* x2717 = x57;
int32_t x2718 = x2717[x2715];
bool x2719 = x2673 == x2718;
if (x2719) {
} else {
x2716 = false;
}
int32_t* x2723 = x61;
int32_t x2724 = x2723[x2715];
bool x2725 = x2674 == x2724;
if (x2725) {
} else {
x2716 = false;
}
int32_t* x2729 = x65;
int32_t x2730 = x2729[x2715];
bool x2731 = x2675 == x2730;
if (x2731) {
} else {
x2716 = false;
}
int32_t* x2735 = x69;
int32_t x2736 = x2735[x2715];
bool x2737 = x2595 == x2736;
if (x2737) {
} else {
x2716 = false;
}
int32_t* x2741 = x73;
int32_t x2742 = x2741[x2715];
bool x2743 = x2683 == x2742;
if (x2743) {
} else {
x2716 = false;
}
bool x2747 = x2716;
if (x2747) {
x2684 = true;
x2708 = false;
} else {
}
int32_t* x2752 = x78;
int32_t x2753 = x2752[x2715];
x2707 = x2753;
}
bool x2757 = x2684;
bool x2758 = !x2757;
x2760 = x2758;
}
if (x2760) {
int32_t* x2761 = x266;
bool x2766 = true;
int32_t x2767 = 0;
int32_t x2673 = x2583[x2482];
int32_t x2686 = x2673 + 233;
x2767 = x2686;
int32_t x2674 = x2577[x2462];
int32_t x2688 = x2686 * 1009;
int32_t x2689 = x2688 + x2674;
int32_t x2690 = x2689 + 233;
x2767 = x2690;
int32_t x2675 = x2583[x2462];
int32_t x2692 = x2690 * 1009;
int32_t x2693 = x2692 + x2675;
int32_t x2694 = x2693 + 233;
x2767 = x2694;
int32_t x2696 = x2694 * 1009;
int32_t x2697 = x2696 + x2595;
int32_t x2698 = x2697 + 233;
x2767 = x2698;
int32_t x2700 = x2698 * 1009;
int32_t x2676 = x2596[x2462];
int32_t x2677 = x2596[x2482];
int32_t x2678 = x2676 + x2677;
int32_t x2762 = x2761[x2525];
int32_t x2763 = x2678 + x2762;
int32_t x2764 = x2763 + x2597;
int32_t x2765 = x2764 + 1;
int32_t x2772 = x2700 + x2765;
int32_t x2773 = x2772 + 233;
x2767 = x2773;
int32_t* x2776 = x176;
int32_t x2775 = x2773 & 16383;
int32_t x2777 = x2776[x2775];
int32_t x2778 = x2777;
bool x2779 = true;
for (;;) {
bool x2780 = x2779;
bool x2784;
if (x2780) {
int32_t x2781 = x2778;
bool x2782 = x2781 != -1;
x2784 = x2782;
} else {
x2784 = false;
}
if (!x2784) break;
int32_t x2786 = x2778;
bool x2787 = true;
int32_t* x2788 = x144;
int32_t x2789 = x2788[x2786];
bool x2790 = x2673 == x2789;
if (x2790) {
} else {
x2787 = false;
}
int32_t* x2794 = x148;
int32_t x2795 = x2794[x2786];
bool x2796 = x2674 == x2795;
if (x2796) {
} else {
x2787 = false;
}
int32_t* x2800 = x152;
int32_t x2801 = x2800[x2786];
bool x2802 = x2675 == x2801;
if (x2802) {
} else {
x2787 = false;
}
int32_t* x2806 = x156;
int32_t x2807 = x2806[x2786];
bool x2808 = x2595 == x2807;
if (x2808) {
} else {
x2787 = false;
}
int32_t* x2812 = x160;
int32_t x2813 = x2812[x2786];
bool x2814 = x2765 == x2813;
if (x2814) {
} else {
x2787 = false;
}
bool x2818 = x2787;
if (x2818) {
bool x2819 = true;
if (x2790) {
} else {
x2819 = false;
}
if (x2796) {
} else {
x2819 = false;
}
if (x2802) {
} else {
x2819 = false;
}
if (x2808) {
} else {
x2819 = false;
}
if (x2814) {
} else {
x2819 = false;
}
bool x2835 = x2819;
if (x2835) {
x2766 = false;
} else {
}
bool x2839 = x2766;
x2779 = x2839;
} else {
}
int32_t* x2843 = x165;
int32_t x2844 = x2843[x2786];
x2778 = x2844;
}
bool x2848 = x2766;
if (x2848) {
int32_t x2851 = x162;
int32_t x2852 = x141;
bool x2853 = x2851 == x2852;
if (x2853) {
x141 *= 4;
int32_t x2855 = x141;
printf("buffer.resize %d\n",x2855);
} else {
}
int32_t* x2859 = x144;
x2859[x2851] = x2673;
int32_t* x2861 = x148;
x2861[x2851] = x2674;
int32_t* x2863 = x152;
x2863[x2851] = x2675;
int32_t* x2865 = x156;
x2865[x2851] = x2595;
int32_t* x2867 = x160;
x2867[x2851] = x2765;
x162 += 1;
int32_t x2870 = x2851;
int32_t x2871 = 0;
x2871 = x2686;
x2871 = x2690;
x2871 = x2694;
x2871 = x2698;
x2871 = x2773;
int32_t x2877 = x2777;
x2776[x2775] = x2851;
int32_t* x2879 = x165;
x2879[x2851] = x2777;
int32_t x2881 = 0;
x2881 = x2686;
x2881 = x2690;
int32_t* x2885 = x178;
int32_t x2884 = x2690 & 16383;
int32_t x2886 = x2885[x2884];
int32_t x2887 = x2886;
x2885[x2884] = x2851;
int32_t* x2889 = x169;
x2889[x2851] = x2886;
int32_t x2891 = 0;
x2891 = x2686;
x2891 = x2690;
x2891 = x2694;
int32_t* x2896 = x180;
int32_t x2895 = x2694 & 16383;
int32_t x2897 = x2896[x2895];
int32_t x2898 = x2897;
x2896[x2895] = x2851;
int32_t* x2900 = x173;
x2900[x2851] = x2897;
} else {
}
} else {
}
} else {
}
int32_t* x2908 = x86;
int32_t x2909 = x2908[x2569];
x2565 = x2909;
}
} else {
}
int32_t* x2915 = x279;
int32_t x2916 = x2915[x2525];
x2521 = x2916;
}
} else {
}
} else {
}
int32_t* x2924 = x82;
int32_t x2925 = x2924[x2482];
x2478 = x2925;
}

}
} else {
}
int32_t x2933 = x268;
bool x2934 = x2933 == 0;
bool x2936;
if (x2934) {
x2936 = false;
} else {
bool x1213 = !x1212;
x2936 = x1213;
}
if (x2936) {
for(int x2937=0; x2937 < x1211; x2937++) {
int32_t* x2938 = x61;
int32_t* x2941 = x65;
int32_t x2943 = 0;
int32_t x2939 = x2938[x2937];
int32_t x2940 = x2939 - 1;
int32_t x2944 = x2940 + 233;
x2943 = x2944;
int32_t x2942 = x2941[x2937];
int32_t x2946 = x2944 * 1009;
int32_t x2947 = x2946 + x2942;
int32_t x2948 = x2947 + 233;
x2943 = x2948;
int32_t* x2951 = x95;
int32_t x2950 = x2948 & 4194303;
int32_t x2952 = x2951[x2950];
int32_t x2953 = x2952;
for (;;) {
int32_t x2954 = x2953;
bool x2955 = x2954 != -1;
if (!x2955) break;
int32_t x2957 = x2953;
bool x2958 = true;
int32_t* x2959 = x57;
int32_t x2960 = x2959[x2957];
bool x2961 = x2940 == x2960;
if (x2961) {
} else {
x2958 = false;
}
int32_t* x2965 = x61;
int32_t x2966 = x2965[x2957];
bool x2967 = x2942 == x2966;
if (x2967) {
} else {
x2958 = false;
}
bool x2971 = x2958;
if (x2971) {
int32_t* x2973 = x65;
int32_t x2972 = x2965[x2937];
int32_t x2974 = x2973[x2957];
bool x2975 = x2972 < x2974;
bool x2979;
if (x2975) {
int32_t x2976 = x2959[x2937];
int32_t x2977 = x2974 - 1;
bool x2978 = x2976 == x2977;
x2979 = x2978;
} else {
x2979 = false;
}
if (x2979) {
int32_t x2982 = 0;
int32_t x2980 = x2973[x2937];
int32_t x2981 = x2980 - 1;
int32_t x2983 = x2981 + 233;
x2982 = x2983;
int32_t x2985 = x2983 * 1009;
int32_t x2986 = x2985 + x2974;
int32_t x2987 = x2986 + 233;
x2982 = x2987;
int32_t x2989 = x2987 * 1009;
int32_t x2990 = x2989 + x2972;
int32_t x2991 = x2990 + 233;
x2982 = x2991;
int32_t* x2994 = x97;
int32_t x2993 = x2991 & 4194303;
int32_t x2995 = x2994[x2993];
int32_t x2996 = x2995;
for (;;) {
int32_t x2997 = x2996;
bool x2998 = x2997 != -1;
if (!x2998) break;
int32_t x3000 = x2996;
bool x3001 = true;
int32_t* x3002 = x57;
int32_t x3003 = x3002[x3000];
bool x3004 = x2981 == x3003;
if (x3004) {
} else {
x3001 = false;
}
int32_t* x3008 = x61;
int32_t x3009 = x3008[x3000];
bool x3010 = x2974 == x3009;
if (x3010) {
} else {
x3001 = false;
}
int32_t* x3014 = x65;
int32_t x3015 = x3014[x3000];
bool x3016 = x2972 == x3015;
if (x3016) {
} else {
x3001 = false;
}
bool x3020 = x3001;
if (x3020) {
int32_t* x3021 = x69;
int32_t x3025 = 0;
int32_t x3022 = x3021[x2937];
int32_t x3026 = x3022 + 233;
x3025 = x3026;
int32_t x3023 = x3021[x2957];
int32_t x3028 = x3026 * 1009;
int32_t x3029 = x3028 + x3023;
int32_t x3030 = x3029 + 233;
x3025 = x3030;
int32_t x3024 = x3021[x3000];
int32_t x3032 = x3030 * 1009;
int32_t x3033 = x3032 + x3024;
int32_t x3034 = x3033 + 233;
x3025 = x3034;
int32_t* x3037 = x286;
int32_t x3036 = x3034 & 16383;
int32_t x3038 = x3037[x3036];
int32_t x3039 = x3038;
for (;;) {
int32_t x3040 = x3039;
bool x3041 = x3040 != -1;
if (!x3041) break;
int32_t x3043 = x3039;
bool x3044 = true;
int32_t* x3045 = x250;
int32_t x3046 = x3045[x3043];
bool x3047 = x3022 == x3046;
if (x3047) {
} else {
x3044 = false;
}
int32_t* x3051 = x254;
int32_t x3052 = x3051[x3043];
bool x3053 = x3023 == x3052;
if (x3053) {
} else {
x3044 = false;
}
int32_t* x3057 = x258;
int32_t x3058 = x3057[x3043];
bool x3059 = x3024 == x3058;
if (x3059) {
} else {
x3044 = false;
}
bool x3063 = x3044;
if (x3063) {
int32_t* x3064 = x65;
int32_t* x3066 = x61;
int32_t* x3069 = x262;
int32_t* x3071 = x73;
int32_t* x3077 = x266;
bool x3081 = false;
int32_t x3082 = 0;
int32_t x3065 = x3064[x2957];
int32_t x3083 = x3065 + 233;
x3082 = x3083;
int32_t x3067 = x3066[x2937];
int32_t x3085 = x3083 * 1009;
int32_t x3086 = x3085 + x3067;
int32_t x3087 = x3086 + 233;
x3082 = x3087;
int32_t x3068 = x3064[x2937];
int32_t x3089 = x3087 * 1009;
int32_t x3090 = x3089 + x3068;
int32_t x3091 = x3090 + 233;
x3082 = x3091;
int32_t x3070 = x3069[x3043];
int32_t x3093 = x3091 * 1009;
int32_t x3094 = x3093 + x3070;
int32_t x3095 = x3094 + 233;
x3082 = x3095;
int32_t x3072 = x3071[x2937];
int32_t x3073 = x3071[x2957];
int32_t x3074 = x3072 + x3073;
int32_t x3075 = x3071[x3000];
int32_t x3076 = x3074 + x3075;
int32_t x3078 = x3077[x3043];
int32_t x3079 = x3076 + x3078;
int32_t x3080 = x3079 + 1;
int32_t x3097 = x3095 * 1009;
int32_t x3098 = x3097 + x3080;
int32_t x3099 = x3098 + 233;
x3082 = x3099;
int32_t* x3102 = x93;
int32_t x3101 = x3099 & 4194303;
int32_t x3103 = x3102[x3101];
int32_t x3104 = x3103;
bool x3105 = true;
for (;;) {
bool x3106 = x3105;
bool x3110;
if (x3106) {
int32_t x3107 = x3104;
bool x3108 = x3107 != -1;
x3110 = x3108;
} else {
x3110 = false;
}
if (!x3110) break;
int32_t x3112 = x3104;
bool x3113 = true;
int32_t* x3114 = x57;
int32_t x3115 = x3114[x3112];
bool x3116 = x3065 == x3115;
if (x3116) {
} else {
x3113 = false;
}
int32_t* x3120 = x61;
int32_t x3121 = x3120[x3112];
bool x3122 = x3067 == x3121;
if (x3122) {
} else {
x3113 = false;
}
int32_t* x3126 = x65;
int32_t x3127 = x3126[x3112];
bool x3128 = x3068 == x3127;
if (x3128) {
} else {
x3113 = false;
}
int32_t* x3132 = x69;
int32_t x3133 = x3132[x3112];
bool x3134 = x3070 == x3133;
if (x3134) {
} else {
x3113 = false;
}
int32_t* x3138 = x73;
int32_t x3139 = x3138[x3112];
bool x3140 = x3080 == x3139;
if (x3140) {
} else {
x3113 = false;
}
bool x3144 = x3113;
if (x3144) {
x3081 = true;
x3105 = false;
} else {
}
int32_t* x3149 = x78;
int32_t x3150 = x3149[x3112];
x3104 = x3150;
}
bool x3154 = x3081;
if (x3154) {
} else {
bool x3156 = true;
int32_t x3157 = 0;
x3157 = x3083;
x3157 = x3087;
x3157 = x3091;
x3157 = x3095;
x3157 = x3099;
int32_t* x3164 = x176;
int32_t x3163 = x3099 & 16383;
int32_t x3165 = x3164[x3163];
int32_t x3166 = x3165;
bool x3167 = true;
for (;;) {
bool x3168 = x3167;
bool x3172;
if (x3168) {
int32_t x3169 = x3166;
bool x3170 = x3169 != -1;
x3172 = x3170;
} else {
x3172 = false;
}
if (!x3172) break;
int32_t x3174 = x3166;
bool x3175 = true;
int32_t* x3176 = x144;
int32_t x3177 = x3176[x3174];
bool x3178 = x3065 == x3177;
if (x3178) {
} else {
x3175 = false;
}
int32_t* x3182 = x148;
int32_t x3183 = x3182[x3174];
bool x3184 = x3067 == x3183;
if (x3184) {
} else {
x3175 = false;
}
int32_t* x3188 = x152;
int32_t x3189 = x3188[x3174];
bool x3190 = x3068 == x3189;
if (x3190) {
} else {
x3175 = false;
}
int32_t* x3194 = x156;
int32_t x3195 = x3194[x3174];
bool x3196 = x3070 == x3195;
if (x3196) {
} else {
x3175 = false;
}
int32_t* x3200 = x160;
int32_t x3201 = x3200[x3174];
bool x3202 = x3080 == x3201;
if (x3202) {
} else {
x3175 = false;
}
bool x3206 = x3175;
if (x3206) {
bool x3207 = true;
if (x3178) {
} else {
x3207 = false;
}
if (x3184) {
} else {
x3207 = false;
}
if (x3190) {
} else {
x3207 = false;
}
if (x3196) {
} else {
x3207 = false;
}
if (x3202) {
} else {
x3207 = false;
}
bool x3223 = x3207;
if (x3223) {
x3156 = false;
} else {
}
bool x3227 = x3156;
x3167 = x3227;
} else {
}
int32_t* x3231 = x165;
int32_t x3232 = x3231[x3174];
x3166 = x3232;
}
bool x3236 = x3156;
if (x3236) {
int32_t x3239 = x162;
int32_t x3240 = x141;
bool x3241 = x3239 == x3240;
if (x3241) {
x141 *= 4;
int32_t x3243 = x141;
printf("buffer.resize %d\n",x3243);
} else {
}
int32_t* x3247 = x144;
x3247[x3239] = x3065;
int32_t* x3249 = x148;
x3249[x3239] = x3067;
int32_t* x3251 = x152;
x3251[x3239] = x3068;
int32_t* x3253 = x156;
x3253[x3239] = x3070;
int32_t* x3255 = x160;
x3255[x3239] = x3080;
x162 += 1;
int32_t x3258 = x3239;
int32_t x3259 = 0;
x3259 = x3083;
x3259 = x3087;
x3259 = x3091;
x3259 = x3095;
x3259 = x3099;
int32_t x3265 = x3165;
x3164[x3163] = x3239;
int32_t* x3267 = x165;
x3267[x3239] = x3165;
int32_t x3269 = 0;
x3269 = x3083;
x3269 = x3087;
int32_t* x3273 = x178;
int32_t x3272 = x3087 & 16383;
int32_t x3274 = x3273[x3272];
int32_t x3275 = x3274;
x3273[x3272] = x3239;
int32_t* x3277 = x169;
x3277[x3239] = x3274;
int32_t x3279 = 0;
x3279 = x3083;
x3279 = x3087;
x3279 = x3091;
int32_t* x3284 = x180;
int32_t x3283 = x3091 & 16383;
int32_t x3285 = x3284[x3283];
int32_t x3286 = x3285;
x3284[x3283] = x3239;
int32_t* x3288 = x173;
x3288[x3239] = x3285;
} else {
}
}
} else {
}
int32_t* x3296 = x279;
int32_t x3297 = x3296[x3043];
x3039 = x3297;
}
} else {
}
int32_t* x3303 = x86;
int32_t x3304 = x3303[x3000];
x2996 = x3304;
}
} else {
}
} else {
}
int32_t* x3312 = x82;
int32_t x3313 = x3312[x2957];
x2953 = x3313;
}

}
} else {
}
int32_t x3321 = x162;
bool x3322 = x3321 == 0;
if (x3322) {
x1208 = false;
} else {
for(int x3326=0; x3326 < x3321; x3326++) {
int32_t* x3327 = x144;
int32_t* x3329 = x148;
int32_t* x3331 = x152;
int32_t* x3333 = x156;
int32_t* x3335 = x160;
bool x3337 = true;
int32_t x3338 = 0;
int32_t x3328 = x3327[x3326];
int32_t x3339 = x3328 + 233;
x3338 = x3339;
int32_t x3330 = x3329[x3326];
int32_t x3341 = x3339 * 1009;
int32_t x3342 = x3341 + x3330;
int32_t x3343 = x3342 + 233;
x3338 = x3343;
int32_t x3332 = x3331[x3326];
int32_t x3345 = x3343 * 1009;
int32_t x3346 = x3345 + x3332;
int32_t x3347 = x3346 + 233;
x3338 = x3347;
int32_t x3334 = x3333[x3326];
int32_t x3349 = x3347 * 1009;
int32_t x3350 = x3349 + x3334;
int32_t x3351 = x3350 + 233;
x3338 = x3351;
int32_t x3336 = x3335[x3326];
int32_t x3353 = x3351 * 1009;
int32_t x3354 = x3353 + x3336;
int32_t x3355 = x3354 + 233;
x3338 = x3355;
int32_t* x3358 = x93;
int32_t x3357 = x3355 & 4194303;
int32_t x3359 = x3358[x3357];
int32_t x3360 = x3359;
bool x3361 = true;
for (;;) {
bool x3362 = x3361;
bool x3366;
if (x3362) {
int32_t x3363 = x3360;
bool x3364 = x3363 != -1;
x3366 = x3364;
} else {
x3366 = false;
}
if (!x3366) break;
int32_t x3368 = x3360;
bool x3369 = true;
int32_t* x3370 = x57;
int32_t x3371 = x3370[x3368];
bool x3372 = x3328 == x3371;
if (x3372) {
} else {
x3369 = false;
}
int32_t* x3376 = x61;
int32_t x3377 = x3376[x3368];
bool x3378 = x3330 == x3377;
if (x3378) {
} else {
x3369 = false;
}
int32_t* x3382 = x65;
int32_t x3383 = x3382[x3368];
bool x3384 = x3332 == x3383;
if (x3384) {
} else {
x3369 = false;
}
int32_t* x3388 = x69;
int32_t x3389 = x3388[x3368];
bool x3390 = x3334 == x3389;
if (x3390) {
} else {
x3369 = false;
}
int32_t* x3394 = x73;
int32_t x3395 = x3394[x3368];
bool x3396 = x3336 == x3395;
if (x3396) {
} else {
x3369 = false;
}
bool x3400 = x3369;
if (x3400) {
bool x3401 = true;
if (x3372) {
} else {
x3401 = false;
}
if (x3378) {
} else {
x3401 = false;
}
if (x3384) {
} else {
x3401 = false;
}
if (x3390) {
} else {
x3401 = false;
}
if (x3396) {
} else {
x3401 = false;
}
bool x3417 = x3401;
if (x3417) {
x3337 = false;
} else {
}
bool x3421 = x3337;
x3361 = x3421;
} else {
}
int32_t* x3425 = x78;
int32_t x3426 = x3425[x3368];
x3360 = x3426;
}
bool x3430 = x3337;
if (x3430) {
int32_t x3433 = x75;
int32_t x3434 = x54;
bool x3435 = x3433 == x3434;
if (x3435) {
x54 *= 4;
int32_t x3437 = x54;
printf("buffer.resize %d\n",x3437);
} else {
}
int32_t* x3441 = x57;
x3441[x3433] = x3328;
int32_t* x3443 = x61;
x3443[x3433] = x3330;
int32_t* x3445 = x65;
x3445[x3433] = x3332;
int32_t* x3447 = x69;
x3447[x3433] = x3334;
int32_t* x3449 = x73;
x3449[x3433] = x3336;
x75 += 1;
int32_t x3452 = x3433;
int32_t x3453 = 0;
x3453 = x3339;
x3453 = x3343;
x3453 = x3347;
x3453 = x3351;
x3453 = x3355;
int32_t x3459 = x3359;
x3358[x3357] = x3433;
int32_t* x3461 = x78;
x3461[x3433] = x3359;
int32_t x3463 = 0;
x3463 = x3339;
x3463 = x3343;
int32_t* x3467 = x95;
int32_t x3466 = x3343 & 4194303;
int32_t x3468 = x3467[x3466];
int32_t x3469 = x3468;
x3467[x3466] = x3433;
int32_t* x3471 = x82;
x3471[x3433] = x3468;
int32_t x3473 = 0;
x3473 = x3339;
x3473 = x3343;
x3473 = x3347;
int32_t* x3478 = x97;
int32_t x3477 = x3347 & 4194303;
int32_t x3479 = x3478[x3477];
int32_t x3480 = x3479;
x3478[x3477] = x3433;
int32_t* x3482 = x86;
x3482[x3433] = x3479;
int32_t x3484 = 0;
int32_t x3485 = x3330 + 233;
x3484 = x3485;
int32_t* x3488 = x99;
int32_t x3487 = x3485 & 4194303;
int32_t x3489 = x3488[x3487];
int32_t x3490 = x3489;
x3488[x3487] = x3433;
int32_t* x3492 = x90;
x3492[x3433] = x3489;
} else {
}

}
SWAP(x268,x162);
SWAP(x247,x141);
SWAP(x251,x145);
SWAP(x248,x142);
SWAP(x250,x144);
SWAP(x255,x149);
SWAP(x252,x146);
SWAP(x254,x148);
SWAP(x259,x153);
SWAP(x256,x150);
SWAP(x258,x152);
SWAP(x263,x157);
SWAP(x260,x154);
SWAP(x262,x156);
SWAP(x267,x161);
SWAP(x264,x158);
SWAP(x266,x160);
SWAP(x272,x166);
SWAP(x269,x163);
SWAP(x271,x165);
SWAP(x276,x170);
SWAP(x273,x167);
SWAP(x275,x169);
SWAP(x280,x174);
SWAP(x277,x171);
SWAP(x279,x173);
SWAP(x282,x176);
SWAP(x284,x178);
SWAP(x286,x180);
x162 = 0;
x166 = 0;
x170 = 0;
x174 = 0;
for(int x3531=0; x3531 < 16384; x3531++) {
int32_t* x3532 = x176;
x3532[x3531] = -1;

}
for(int x3536=0; x3536 < 16384; x3536++) {
int32_t* x3537 = x178;
x3537[x3536] = -1;

}
for(int x3541=0; x3541 < 16384; x3541++) {
int32_t* x3542 = x180;
x3542[x3541] = -1;

}
}
}
for(int x3550=0; x3550 < 16384; x3550++) {
int32_t* x3551 = x282;
x3551[x3550] = -1;

}
for(int x3555=0; x3555 < 16384; x3555++) {
int32_t* x3556 = x284;
x3556[x3555] = -1;

}
for(int x3560=0; x3560 < 16384; x3560++) {
int32_t* x3561 = x286;
x3561[x3560] = -1;

}
for(int x3565=0; x3565 < 16384; x3565++) {
int32_t* x3566 = x176;
x3566[x3565] = -1;

}
for(int x3570=0; x3570 < 16384; x3570++) {
int32_t* x3571 = x178;
x3571[x3570] = -1;

}
for(int x3575=0; x3575 < 16384; x3575++) {
int32_t* x3576 = x180;
x3576[x3575] = -1;

}
for(int x3580=0; x3580 < 4194304; x3580++) {
int32_t* x3581 = x241;
x3581[x3580] = -1;

}
int32_t x3586 = x75;
FILE *x3585 = fopen("tak.out","w");
for(int x3588=0; x3588 < x3586; x3588++) {
int32_t* x3589 = x57;
int32_t x3590 = x3589[x3588];
int32_t x3591 = fprintf(x3585,"%d",x3590);
int32_t x3592 = fprintf(x3585,"\t");
int32_t* x3593 = x61;
int32_t x3594 = x3593[x3588];
int32_t x3595 = fprintf(x3585,"%d",x3594);
int32_t x3596 = fprintf(x3585,"\t");
int32_t* x3597 = x65;
int32_t x3598 = x3597[x3588];
int32_t x3599 = fprintf(x3585,"%d",x3598);
int32_t x3600 = fprintf(x3585,"\t");
int32_t* x3601 = x69;
int32_t x3602 = x3601[x3588];
int32_t x3603 = fprintf(x3585,"%d",x3602);
int32_t x3604 = fprintf(x3585,"\t");
int32_t* x3605 = x73;
int32_t x3606 = x3605[x3588];
int32_t x3607 = fprintf(x3585,"%d",x3606);
int32_t x3608 = fprintf(x3585,"\n");

}
fclose(x3585);
int32_t x3615 = 0;
int32_t x3612 = open("low2.facts",0);
int32_t x3613 = fsize(x3612);
char* x3614 = mmap(0, x3613, PROT_READ, MAP_FILE | MAP_SHARED, x3612, 0);
for (;;) {
int32_t x3616 = x3615;
bool x3617 = x3616 < x3613;
if (!x3617) break;
int32_t x3619 = x3615;
for (;;) {
int32_t x3620 = x3615;
char x3621 = x3614[x3620];
bool x3622 = x3621 != '\n';
if (!x3622) break;
x3615 += 1;
}
int32_t x3627 = x3615;
x3615 += 1;
char* x3630 = x3614+x3619;
int32_t x3631 = atoi(x3630);
int32_t x3632 = x24;
int32_t x3633 = x19;
bool x3634 = x3632 == x3633;
if (x3634) {
x19 *= 4;
int32_t x3636 = x19;
printf("buffer.resize %d\n",x3636);
} else {
}
int32_t* x3640 = x22;
x3640[x3632] = x3631;
x24 += 1;
int32_t x3643 = x3632;
int32_t x3644 = 0;
int32_t x3645 = x3631 + 233;
x3644 = x3645;
int32_t* x3648 = x30;
int32_t x3647 = x3645 & 4194303;
int32_t x3649 = x3648[x3647];
int32_t x3650 = x3649;
x3648[x3647] = x3632;
int32_t* x3652 = x27;
x3652[x3632] = x3649;
}
bool x3656 = x3586 == 0;
bool x3662;
if (x3656) {
x3662 = false;
} else {
int32_t x3658 = x24;
bool x3659 = x3658 == 0;
bool x3660 = !x3659;
x3662 = x3660;
}
bool x3667;
if (x3662) {
int32_t x3663 = x307;
bool x3664 = x3663 == 0;
bool x3665 = !x3664;
x3667 = x3665;
} else {
x3667 = false;
}
if (x3667) {
int32_t x3668 = 0;
x3668 = 233;
int32_t x3670 = 233 & 4194303;
int32_t x3671 = x98[x3670];
int32_t x3672 = x3671;
for (;;) {
int32_t x3673 = x3672;
bool x3674 = x3673 != -1;
if (!x3674) break;
int32_t x3676 = x3672;
bool x3677 = true;
int32_t* x3678 = x61;
int32_t x3679 = x3678[x3676];
bool x3680 = 0 == x3679;
if (x3680) {
} else {
x3677 = false;
}
bool x3684 = x3677;
if (x3684) {
int32_t* x3685 = x65;
int32_t* x3687 = x57;
int32_t x3686 = x3685[x3676];
int32_t x3688 = x3687[x3676];
int32_t x3689 = x3688 + 1;
bool x3690 = x3686 == x3689;
if (x3690) {
int32_t x3691 = 0;
bool x3692 = true;
for (;;) {
bool x3693 = x3692;
bool x3698;
if (x3693) {
int32_t x3694 = x3691;
int32_t x3695 = x24;
bool x3696 = x3694 < x3695;
x3698 = x3696;
} else {
x3698 = false;
}
if (!x3698) break;
int32_t x3700 = x3691;
int32_t* x3701 = x57;
int32_t* x3703 = x22;
int32_t x3702 = x3701[x3676];
int32_t x3704 = x3703[x3700];
bool x3705 = x3702 >= x3704;
if (x3705) {
if (x3705) {
int32_t x3706 = 0;
bool x3707 = true;
for (;;) {
bool x3708 = x3707;
bool x3713;
if (x3708) {
int32_t x3709 = x3706;
int32_t x3710 = x307;
bool x3711 = x3709 < x3710;
x3713 = x3711;
} else {
x3713 = false;
}
if (!x3713) break;
int32_t x3715 = x3706;
int32_t* x3716 = x57;
int32_t* x3718 = x305;
int32_t x3717 = x3716[x3676];
int32_t x3719 = x3718[x3715];
bool x3720 = x3717 < x3719;
if (x3720) {
if (x3720) {
int32_t* x3721 = x73;
bool x3723 = true;
int32_t x3724 = 0;
int32_t x3725 = x3717 + 233;
x3724 = x3725;
int32_t x3722 = x3721[x3676];
int32_t x3727 = x3725 * 1009;
int32_t x3728 = x3727 + x3722;
int32_t x3729 = x3728 + 233;
x3724 = x3729;
int32_t* x3732 = x135;
int32_t x3731 = x3729 & 4194303;
int32_t x3733 = x3732[x3731];
int32_t x3734 = x3733;
bool x3735 = true;
for (;;) {
bool x3736 = x3735;
bool x3740;
if (x3736) {
int32_t x3737 = x3734;
bool x3738 = x3737 != -1;
x3740 = x3738;
} else {
x3740 = false;
}
if (!x3740) break;
int32_t x3742 = x3734;
bool x3743 = true;
int32_t* x3744 = x123;
int32_t x3745 = x3744[x3742];
bool x3746 = x3717 == x3745;
if (x3746) {
} else {
x3743 = false;
}
int32_t* x3750 = x127;
int32_t x3751 = x3750[x3742];
bool x3752 = x3722 == x3751;
if (x3752) {
} else {
x3743 = false;
}
bool x3756 = x3743;
if (x3756) {
bool x3757 = true;
if (x3746) {
} else {
x3757 = false;
}
if (x3752) {
} else {
x3757 = false;
}
bool x3764 = x3757;
if (x3764) {
x3723 = false;
} else {
}
bool x3768 = x3723;
x3735 = x3768;
} else {
}
int32_t* x3772 = x132;
int32_t x3773 = x3772[x3742];
x3734 = x3773;
}
bool x3777 = x3723;
if (x3777) {
int32_t x3780 = x129;
int32_t x3781 = x120;
bool x3782 = x3780 == x3781;
if (x3782) {
x120 *= 4;
int32_t x3784 = x120;
printf("buffer.resize %d\n",x3784);
} else {
}
int32_t* x3788 = x123;
x3788[x3780] = x3717;
int32_t* x3790 = x127;
x3790[x3780] = x3722;
x129 += 1;
int32_t x3793 = x3780;
int32_t x3794 = 0;
x3794 = x3725;
x3794 = x3729;
int32_t x3797 = x3733;
x3732[x3731] = x3780;
int32_t* x3799 = x132;
x3799[x3780] = x3733;
} else {
}
} else {
}
} else {
}
bool x3807 = !x3720;
x3707 = x3807;
x3706 += 1;
}
} else {
}
} else {
}
bool x3816 = !x3705;
x3692 = x3816;
x3691 += 1;
}
} else {
}
} else {
}
int32_t* x3825 = x90;
int32_t x3826 = x3825[x3676];
x3672 = x3826;
}
} else {
}
int32_t x3833 = x129;
FILE *x3832 = fopen("query.out","w");
for(int x3835=0; x3835 < x3833; x3835++) {
int32_t* x3836 = x123;
int32_t x3837 = x3836[x3835];
int32_t x3838 = fprintf(x3832,"%d",x3837);
int32_t x3839 = fprintf(x3832,"\t");
int32_t* x3840 = x127;
int32_t x3841 = x3840[x3835];
int32_t x3842 = fprintf(x3832,"%d",x3841);
int32_t x3843 = fprintf(x3832,"\n");

}
fclose(x3832);
for(int x3847=0; x3847 < 4194304; x3847++) {
int32_t* x3848 = x93;
x3848[x3847] = -1;

}
for(int x3852=0; x3852 < 4194304; x3852++) {
int32_t* x3853 = x95;
x3853[x3852] = -1;

}
for(int x3857=0; x3857 < 4194304; x3857++) {
int32_t* x3858 = x97;
x3858[x3857] = -1;

}
for(int x3862=0; x3862 < 4194304; x3862++) {
int32_t* x3863 = x99;
x3863[x3862] = -1;

}
for(int x3867=0; x3867 < 4194304; x3867++) {
int32_t* x3868 = x30;
x3868[x3867] = -1;

}
for(int x3872=0; x3872 < 4194304; x3872++) {
int32_t* x3873 = x313;
x3873[x3872] = -1;

}
}
/*****************************************
  End of C Generated Code                  
*******************************************/

