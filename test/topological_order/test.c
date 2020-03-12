
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
int32_t* x11 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x12 = x11;
for(int x14=0; x14 < 4194304; x14++) {
int32_t* x15 = x12;
x15[x14] = -1;

}
int32_t x19 = 4194304;
int32_t x20 = 4194304;
int32_t* x21 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x22 = x21;
int32_t x23 = 0;
int32_t x24 = 4194304;
int32_t* x25 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x26 = x25;
int32_t x27 = 0;
int32_t x28 = 0;
int32_t x29 = 4194304;
int32_t* x30 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x31 = x30;
int32_t x32 = 0;
int32_t* x33 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x34 = x33;
for(int x35=0; x35 < 4194304; x35++) {
int32_t* x36 = x34;
x36[x35] = -1;

}
int32_t x40 = 4194304;
int32_t x41 = 4194304;
int32_t* x42 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x43 = x42;
int32_t x44 = 0;
int32_t x45 = 4194304;
int32_t* x46 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x47 = x46;
int32_t x48 = 0;
int32_t x49 = 0;
int32_t x50 = 4194304;
int32_t* x51 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x52 = x51;
int32_t x53 = 0;
int32_t x54 = 4194304;
int32_t* x55 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x56 = x55;
int32_t x57 = 0;
int32_t* x58 = (int32_t*)malloc(16384 * sizeof(int32_t));
int32_t* x59 = x58;
int32_t* x60 = (int32_t*)malloc(16384 * sizeof(int32_t));
int32_t* x61 = x60;
for(int x63=0; x63 < 16384; x63++) {
int32_t* x64 = x59;
x64[x63] = -1;

}
for(int x68=0; x68 < 16384; x68++) {
int32_t* x69 = x61;
x69[x68] = -1;

}
int32_t x73 = 4194304;
int32_t x74 = 4194304;
int32_t* x75 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x76 = x75;
int32_t x77 = 0;
int32_t x78 = 4194304;
int32_t* x79 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x80 = x79;
int32_t x81 = 0;
int32_t x82 = 0;
int32_t x83 = 4194304;
int32_t* x84 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x85 = x84;
int32_t x86 = 0;
int32_t x87 = 4194304;
int32_t* x88 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x89 = x88;
int32_t x90 = 0;
int32_t* x91 = (int32_t*)malloc(16384 * sizeof(int32_t));
int32_t* x92 = x91;
int32_t* x93 = (int32_t*)malloc(16384 * sizeof(int32_t));
int32_t* x94 = x93;
for(int x95=0; x95 < 16384; x95++) {
int32_t* x96 = x92;
x96[x95] = -1;

}
for(int x100=0; x100 < 16384; x100++) {
int32_t* x101 = x94;
x101[x100] = -1;

}
int32_t x105 = 4194304;
int32_t x106 = 4194304;
int32_t* x107 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x108 = x107;
int32_t x109 = 0;
int32_t x110 = 4194304;
int32_t* x111 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x112 = x111;
int32_t x113 = 0;
int32_t x114 = 0;
int32_t x115 = 4194304;
int32_t* x116 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x117 = x116;
int32_t x118 = 0;
int32_t x119 = 4194304;
int32_t* x120 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x121 = x120;
int32_t x122 = 0;
int32_t* x123 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x124 = x123;
int32_t* x125 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x126 = x125;
for(int x127=0; x127 < 4194304; x127++) {
int32_t* x128 = x124;
x128[x127] = -1;

}
for(int x132=0; x132 < 4194304; x132++) {
int32_t* x133 = x126;
x133[x132] = -1;

}
int32_t x137 = 4194304;
int32_t x138 = 4194304;
int32_t* x139 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x140 = x139;
int32_t x141 = 0;
int32_t x142 = 4194304;
int32_t* x143 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x144 = x143;
int32_t x145 = 0;
int32_t x146 = 0;
int32_t x147 = 4194304;
int32_t* x148 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x149 = x148;
int32_t x150 = 0;
int32_t x151 = 4194304;
int32_t* x152 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x153 = x152;
int32_t x154 = 0;
int32_t* x155 = (int32_t*)malloc(16384 * sizeof(int32_t));
int32_t* x156 = x155;
int32_t* x157 = (int32_t*)malloc(16384 * sizeof(int32_t));
int32_t* x158 = x157;
for(int x159=0; x159 < 16384; x159++) {
int32_t* x160 = x156;
x160[x159] = -1;

}
for(int x164=0; x164 < 16384; x164++) {
int32_t* x165 = x158;
x165[x164] = -1;

}
int32_t x169 = 4194304;
int32_t x170 = 4194304;
int32_t* x171 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x172 = x171;
int32_t x173 = 0;
int32_t x174 = 4194304;
int32_t* x175 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x176 = x175;
int32_t x177 = 0;
int32_t x178 = 0;
int32_t x179 = 4194304;
int32_t* x180 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x181 = x180;
int32_t x182 = 0;
int32_t x183 = 4194304;
int32_t* x184 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x185 = x184;
int32_t x186 = 0;
int32_t* x187 = (int32_t*)malloc(16384 * sizeof(int32_t));
int32_t* x188 = x187;
int32_t* x189 = (int32_t*)malloc(16384 * sizeof(int32_t));
int32_t* x190 = x189;
for(int x191=0; x191 < 16384; x191++) {
int32_t* x192 = x188;
x192[x191] = -1;

}
for(int x196=0; x196 < 16384; x196++) {
int32_t* x197 = x190;
x197[x196] = -1;

}
int32_t x201 = 4194304;
int32_t x202 = 4194304;
int32_t* x203 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x204 = x203;
int32_t x205 = 0;
int32_t x206 = 4194304;
int32_t* x207 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x208 = x207;
int32_t x209 = 0;
int32_t x210 = 0;
int32_t x211 = 4194304;
int32_t* x212 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x213 = x212;
int32_t x214 = 0;
int32_t x215 = 4194304;
int32_t* x216 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x217 = x216;
int32_t x218 = 0;
int32_t x219 = 4194304;
int32_t* x220 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x221 = x220;
int32_t x222 = 0;
int32_t* x223 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x224 = x223;
int32_t* x225 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x226 = x225;
int32_t* x227 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x228 = x227;
for(int x229=0; x229 < 4194304; x229++) {
int32_t* x230 = x224;
x230[x229] = -1;

}
for(int x234=0; x234 < 4194304; x234++) {
int32_t* x235 = x226;
x235[x234] = -1;

}
for(int x239=0; x239 < 4194304; x239++) {
int32_t* x240 = x228;
x240[x239] = -1;

}
int32_t x244 = 4194304;
int32_t x245 = 4194304;
int32_t* x246 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x247 = x246;
int32_t x248 = 0;
int32_t x249 = 4194304;
int32_t* x250 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x251 = x250;
int32_t x252 = 0;
int32_t x253 = 0;
int32_t x254 = 4194304;
int32_t* x255 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x256 = x255;
int32_t x257 = 0;
int32_t x258 = 4194304;
int32_t* x259 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x260 = x259;
int32_t x261 = 0;
int32_t* x262 = (int32_t*)malloc(16384 * sizeof(int32_t));
int32_t* x263 = x262;
int32_t* x264 = (int32_t*)malloc(16384 * sizeof(int32_t));
int32_t* x265 = x264;
for(int x266=0; x266 < 16384; x266++) {
int32_t* x267 = x263;
x267[x266] = -1;

}
for(int x271=0; x271 < 16384; x271++) {
int32_t* x272 = x265;
x272[x271] = -1;

}
int32_t x276 = 4194304;
int32_t x277 = 4194304;
int32_t* x278 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x279 = x278;
int32_t x280 = 0;
int32_t x281 = 4194304;
int32_t* x282 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x283 = x282;
int32_t x284 = 0;
int32_t x285 = 0;
int32_t x286 = 4194304;
int32_t* x287 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x288 = x287;
int32_t x289 = 0;
int32_t x290 = 4194304;
int32_t* x291 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x292 = x291;
int32_t x293 = 0;
int32_t* x294 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x295 = x294;
int32_t* x296 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x297 = x296;
for(int x298=0; x298 < 4194304; x298++) {
int32_t* x299 = x295;
x299[x298] = -1;

}
for(int x303=0; x303 < 4194304; x303++) {
int32_t* x304 = x297;
x304[x303] = -1;

}
int32_t x308 = 4194304;
int32_t x309 = 4194304;
int32_t* x310 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x311 = x310;
int32_t x312 = 0;
int32_t x313 = 4194304;
int32_t* x314 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x315 = x314;
int32_t x316 = 0;
int32_t x317 = 0;
int32_t x318 = 4194304;
int32_t* x319 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x320 = x319;
int32_t x321 = 0;
int32_t x322 = 4194304;
int32_t* x323 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x324 = x323;
int32_t x325 = 0;
int32_t* x326 = (int32_t*)malloc(16384 * sizeof(int32_t));
int32_t* x327 = x326;
int32_t* x328 = (int32_t*)malloc(16384 * sizeof(int32_t));
int32_t* x329 = x328;
for(int x330=0; x330 < 16384; x330++) {
int32_t* x331 = x327;
x331[x330] = -1;

}
for(int x335=0; x335 < 16384; x335++) {
int32_t* x336 = x329;
x336[x335] = -1;

}
int32_t x340 = 4194304;
int32_t x341 = 4194304;
int32_t* x342 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x343 = x342;
int32_t x344 = 0;
int32_t x345 = 4194304;
int32_t* x346 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x347 = x346;
int32_t x348 = 0;
int32_t x349 = 0;
int32_t x350 = 4194304;
int32_t* x351 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x352 = x351;
int32_t x353 = 0;
int32_t* x354 = (int32_t*)malloc(4194304 * sizeof(int32_t));
int32_t* x355 = x354;
for(int x356=0; x356 < 4194304; x356++) {
int32_t* x357 = x355;
x357[x356] = -1;

}
int32_t x364 = 0;
int32_t x361 = open("./edge.facts",0);
int32_t x362 = fsize(x361);
char* x363 = mmap(0, x362, PROT_READ, MAP_FILE | MAP_SHARED, x361, 0);
for (;;) {
int32_t x365 = x364;
bool x366 = x365 < x362;
if (!x366) break;
int32_t x368 = x364;
for (;;) {
int32_t x369 = x364;
char x370 = x363[x369];
bool x371 = x370 != '\t';
if (!x371) break;
x364 += 1;
}
int32_t x376 = x364;
x364 += 1;
char* x379 = x363+x368;
int32_t x380 = atoi(x379);
int32_t x381 = x364;
for (;;) {
int32_t x382 = x364;
char x383 = x363[x382];
bool x384 = x383 != '\n';
if (!x384) break;
x364 += 1;
}
int32_t x389 = x364;
x364 += 1;
char* x392 = x363+x381;
int32_t x393 = atoi(x392);
int32_t x394 = x210;
int32_t x395 = x201;
bool x396 = x394 == x395;
if (x396) {
x201 *= 4;
int32_t x398 = x201;
printf("buffer.resize %d\n",x398);
} else {
}
int32_t* x402 = x204;
x402[x394] = x380;
int32_t* x404 = x208;
x404[x394] = x393;
x210 += 1;
int32_t x407 = x394;
int32_t x408 = 0;
int32_t x409 = x380 + 233;
x408 = x409;
int32_t x411 = x409 * 1009;
int32_t x412 = x411 + x393;
int32_t x413 = x412 + 233;
x408 = x413;
int32_t* x416 = x224;
int32_t x415 = x413 & 4194303;
int32_t x417 = x416[x415];
int32_t x418 = x417;
x416[x415] = x394;
int32_t* x420 = x213;
x420[x394] = x417;
int32_t x422 = 0;
int32_t x423 = x393 + 233;
x422 = x423;
int32_t* x426 = x226;
int32_t x425 = x423 & 4194303;
int32_t x427 = x426[x425];
int32_t x428 = x427;
x426[x425] = x394;
int32_t* x430 = x217;
x430[x394] = x427;
int32_t x432 = 0;
x432 = x409;
int32_t* x435 = x228;
int32_t x434 = x409 & 4194303;
int32_t x436 = x435[x434];
int32_t x437 = x436;
x435[x434] = x394;
int32_t* x439 = x221;
x439[x394] = x436;
}
int32_t x443 = x210;
bool x444 = x443 == 0;
if (x444) {
} else {
for(int x447=0; x447 < x443; x447++) {
int32_t* x448 = x208;
int32_t* x450 = x204;
bool x452 = true;
int32_t x453 = 0;
int32_t x449 = x448[x447];
int32_t x454 = x449 + 233;
x453 = x454;
int32_t x451 = x450[x447];
int32_t x456 = x454 * 1009;
int32_t x457 = x456 + x451;
int32_t x458 = x457 + 233;
x453 = x458;
int32_t* x461 = x295;
int32_t x460 = x458 & 4194303;
int32_t x462 = x461[x460];
int32_t x463 = x462;
bool x464 = true;
for (;;) {
bool x465 = x464;
bool x469;
if (x465) {
int32_t x466 = x463;
bool x467 = x466 != -1;
x469 = x467;
} else {
x469 = false;
}
if (!x469) break;
int32_t x471 = x463;
bool x472 = true;
int32_t* x473 = x279;
int32_t x474 = x473[x471];
bool x475 = x449 == x474;
if (x475) {
} else {
x472 = false;
}
int32_t* x479 = x283;
int32_t x480 = x479[x471];
bool x481 = x451 == x480;
if (x481) {
} else {
x472 = false;
}
bool x485 = x472;
if (x485) {
bool x486 = true;
if (x475) {
} else {
x486 = false;
}
if (x481) {
} else {
x486 = false;
}
bool x493 = x486;
if (x493) {
x452 = false;
} else {
}
bool x497 = x452;
x464 = x497;
} else {
}
int32_t* x501 = x288;
int32_t x502 = x501[x471];
x463 = x502;
}
bool x506 = x452;
if (x506) {
int32_t x509 = x285;
int32_t x510 = x276;
bool x511 = x509 == x510;
if (x511) {
x276 *= 4;
int32_t x513 = x276;
printf("buffer.resize %d\n",x513);
} else {
}
int32_t* x517 = x279;
x517[x509] = x449;
int32_t* x519 = x283;
x519[x509] = x451;
x285 += 1;
int32_t x522 = x509;
int32_t x523 = 0;
x523 = x454;
x523 = x458;
int32_t x526 = x462;
x461[x460] = x509;
int32_t* x528 = x288;
x528[x509] = x462;
int32_t x530 = 0;
int32_t x531 = x451 + 233;
x530 = x531;
int32_t* x534 = x297;
int32_t x533 = x531 & 4194303;
int32_t x535 = x534[x533];
int32_t x536 = x535;
x534[x533] = x509;
int32_t* x538 = x292;
x538[x509] = x535;
} else {
}

}
}
int32_t x546 = x285;
for(int x548=0; x548 < x546; x548++) {
int32_t* x549 = x279;
int32_t* x551 = x283;
bool x553 = true;
int32_t x554 = 0;
int32_t x550 = x549[x548];
int32_t x555 = x550 + 233;
x554 = x555;
int32_t x552 = x551[x548];
int32_t x557 = x555 * 1009;
int32_t x558 = x557 + x552;
int32_t x559 = x558 + 233;
x554 = x559;
int32_t* x562 = x327;
int32_t x561 = x559 & 16383;
int32_t x563 = x562[x561];
int32_t x564 = x563;
bool x565 = true;
for (;;) {
bool x566 = x565;
bool x570;
if (x566) {
int32_t x567 = x564;
bool x568 = x567 != -1;
x570 = x568;
} else {
x570 = false;
}
if (!x570) break;
int32_t x572 = x564;
bool x573 = true;
int32_t* x574 = x311;
int32_t x575 = x574[x572];
bool x576 = x550 == x575;
if (x576) {
} else {
x573 = false;
}
int32_t* x580 = x315;
int32_t x581 = x580[x572];
bool x582 = x552 == x581;
if (x582) {
} else {
x573 = false;
}
bool x586 = x573;
if (x586) {
bool x587 = true;
if (x576) {
} else {
x587 = false;
}
if (x582) {
} else {
x587 = false;
}
bool x594 = x587;
if (x594) {
x553 = false;
} else {
}
bool x598 = x553;
x565 = x598;
} else {
}
int32_t* x602 = x320;
int32_t x603 = x602[x572];
x564 = x603;
}
bool x607 = x553;
if (x607) {
int32_t x610 = x317;
int32_t x611 = x308;
bool x612 = x610 == x611;
if (x612) {
x308 *= 4;
int32_t x614 = x308;
printf("buffer.resize %d\n",x614);
} else {
}
int32_t* x618 = x311;
x618[x610] = x550;
int32_t* x620 = x315;
x620[x610] = x552;
x317 += 1;
int32_t x623 = x610;
int32_t x624 = 0;
x624 = x555;
x624 = x559;
int32_t x627 = x563;
x562[x561] = x610;
int32_t* x629 = x320;
x629[x610] = x563;
int32_t x631 = 0;
int32_t x632 = x552 + 233;
x631 = x632;
int32_t* x635 = x329;
int32_t x634 = x632 & 16383;
int32_t x636 = x635[x634];
int32_t x637 = x636;
x635[x634] = x610;
int32_t* x639 = x324;
x639[x610] = x636;
} else {
}

}
bool x645 = true;
for (;;) {
bool x646 = x645;
if (!x646) break;
int32_t x648 = x317;
bool x649 = x648 == 0;
bool x655;
if (x649) {
x655 = false;
} else {
int32_t x651 = x285;
bool x652 = x651 == 0;
bool x653 = !x652;
x655 = x653;
}
if (x655) {
for(int x657=0; x657 < x648; x657++) {
int32_t* x658 = x311;
int32_t x660 = 0;
int32_t x659 = x658[x657];
int32_t x661 = x659 + 233;
x660 = x661;
int32_t* x664 = x297;
int32_t x663 = x661 & 4194303;
int32_t x665 = x664[x663];
int32_t x666 = x665;
for (;;) {
int32_t x667 = x666;
bool x668 = x667 != -1;
if (!x668) break;
int32_t x670 = x666;
bool x671 = true;
int32_t* x672 = x283;
int32_t x673 = x672[x670];
bool x674 = x659 == x673;
if (x674) {
} else {
x671 = false;
}
bool x678 = x671;
if (x678) {
int32_t* x679 = x279;
int32_t* x681 = x311;
bool x683 = false;
int32_t x684 = 0;
int32_t x680 = x679[x670];
int32_t x685 = x680 + 233;
x684 = x685;
int32_t x682 = x681[x657];
int32_t x687 = x685 * 1009;
int32_t x688 = x687 + x682;
int32_t x689 = x688 + 233;
x684 = x689;
int32_t* x692 = x327;
int32_t x691 = x689 & 16383;
int32_t x693 = x692[x691];
int32_t x694 = x693;
bool x695 = true;
for (;;) {
bool x696 = x695;
bool x700;
if (x696) {
int32_t x697 = x694;
bool x698 = x697 != -1;
x700 = x698;
} else {
x700 = false;
}
if (!x700) break;
int32_t x702 = x694;
bool x703 = true;
int32_t* x704 = x311;
int32_t x705 = x704[x702];
bool x706 = x680 == x705;
if (x706) {
} else {
x703 = false;
}
int32_t* x710 = x315;
int32_t x711 = x710[x702];
bool x712 = x682 == x711;
if (x712) {
} else {
x703 = false;
}
bool x716 = x703;
if (x716) {
x683 = true;
x695 = false;
} else {
}
int32_t* x721 = x320;
int32_t x722 = x721[x702];
x694 = x722;
}
bool x726 = x683;
bool x776;
if (x726) {
x776 = false;
} else {
int32_t* x728 = x315;
bool x730 = false;
int32_t x731 = 0;
int32_t x729 = x728[x657];
int32_t x732 = x729 + 233;
x731 = x732;
int32_t x734 = x732 * 1009;
int32_t x735 = x734 + x680;
int32_t x736 = x735 + 233;
x731 = x736;
int32_t* x739 = x295;
int32_t x738 = x736 & 4194303;
int32_t x740 = x739[x738];
int32_t x741 = x740;
bool x742 = true;
for (;;) {
bool x743 = x742;
bool x747;
if (x743) {
int32_t x744 = x741;
bool x745 = x744 != -1;
x747 = x745;
} else {
x747 = false;
}
if (!x747) break;
int32_t x749 = x741;
bool x750 = true;
int32_t* x751 = x279;
int32_t x752 = x751[x749];
bool x753 = x729 == x752;
if (x753) {
} else {
x750 = false;
}
int32_t* x757 = x283;
int32_t x758 = x757[x749];
bool x759 = x680 == x758;
if (x759) {
} else {
x750 = false;
}
bool x763 = x750;
if (x763) {
x730 = true;
x742 = false;
} else {
}
int32_t* x768 = x288;
int32_t x769 = x768[x749];
x741 = x769;
}
bool x773 = x730;
bool x774 = !x773;
x776 = x774;
}
if (x776) {
int32_t* x777 = x315;
bool x779 = true;
int32_t x780 = 0;
int32_t x778 = x777[x657];
int32_t x781 = x778 + 233;
x780 = x781;
int32_t x783 = x781 * 1009;
int32_t x784 = x783 + x680;
int32_t x785 = x784 + 233;
x780 = x785;
int32_t* x788 = x156;
int32_t x787 = x785 & 16383;
int32_t x789 = x788[x787];
int32_t x790 = x789;
bool x791 = true;
for (;;) {
bool x792 = x791;
bool x796;
if (x792) {
int32_t x793 = x790;
bool x794 = x793 != -1;
x796 = x794;
} else {
x796 = false;
}
if (!x796) break;
int32_t x798 = x790;
bool x799 = true;
int32_t* x800 = x140;
int32_t x801 = x800[x798];
bool x802 = x778 == x801;
if (x802) {
} else {
x799 = false;
}
int32_t* x806 = x144;
int32_t x807 = x806[x798];
bool x808 = x680 == x807;
if (x808) {
} else {
x799 = false;
}
bool x812 = x799;
if (x812) {
bool x813 = true;
if (x802) {
} else {
x813 = false;
}
if (x808) {
} else {
x813 = false;
}
bool x820 = x813;
if (x820) {
x779 = false;
} else {
}
bool x824 = x779;
x791 = x824;
} else {
}
int32_t* x828 = x149;
int32_t x829 = x828[x798];
x790 = x829;
}
bool x833 = x779;
if (x833) {
int32_t x836 = x146;
int32_t x837 = x137;
bool x838 = x836 == x837;
if (x838) {
x137 *= 4;
int32_t x840 = x137;
printf("buffer.resize %d\n",x840);
} else {
}
int32_t* x844 = x140;
x844[x836] = x778;
int32_t* x846 = x144;
x846[x836] = x680;
x146 += 1;
int32_t x849 = x836;
int32_t x850 = 0;
x850 = x781;
x850 = x785;
int32_t x853 = x789;
x788[x787] = x836;
int32_t* x855 = x149;
x855[x836] = x789;
int32_t x857 = 0;
x857 = x685;
int32_t* x860 = x158;
int32_t x859 = x685 & 16383;
int32_t x861 = x860[x859];
int32_t x862 = x861;
x860[x859] = x836;
int32_t* x864 = x153;
x864[x836] = x861;
} else {
}
} else {
}
} else {
}
int32_t* x872 = x292;
int32_t x873 = x872[x670];
x666 = x873;
}

}
} else {
}
int32_t x881 = x285;
bool x882 = x881 == 0;
bool x884;
if (x882) {
x884 = false;
} else {
bool x650 = !x649;
x884 = x650;
}
if (x884) {
for(int x886=0; x886 < x881; x886++) {
int32_t* x887 = x279;
int32_t x889 = 0;
int32_t x888 = x887[x886];
int32_t x890 = x888 + 233;
x889 = x890;
int32_t* x893 = x329;
int32_t x892 = x890 & 16383;
int32_t x894 = x893[x892];
int32_t x895 = x894;
for (;;) {
int32_t x896 = x895;
bool x897 = x896 != -1;
if (!x897) break;
int32_t x899 = x895;
bool x900 = true;
int32_t* x901 = x315;
int32_t x902 = x901[x899];
bool x903 = x888 == x902;
if (x903) {
} else {
x900 = false;
}
bool x907 = x900;
if (x907) {
int32_t* x908 = x283;
int32_t* x910 = x311;
bool x912 = false;
int32_t x913 = 0;
int32_t x909 = x908[x886];
int32_t x914 = x909 + 233;
x913 = x914;
int32_t x911 = x910[x899];
int32_t x916 = x914 * 1009;
int32_t x917 = x916 + x911;
int32_t x918 = x917 + 233;
x913 = x918;
int32_t* x921 = x295;
int32_t x920 = x918 & 4194303;
int32_t x922 = x921[x920];
int32_t x923 = x922;
bool x924 = true;
for (;;) {
bool x925 = x924;
bool x929;
if (x925) {
int32_t x926 = x923;
bool x927 = x926 != -1;
x929 = x927;
} else {
x929 = false;
}
if (!x929) break;
int32_t x931 = x923;
bool x932 = true;
int32_t* x933 = x279;
int32_t x934 = x933[x931];
bool x935 = x909 == x934;
if (x935) {
} else {
x932 = false;
}
int32_t* x939 = x283;
int32_t x940 = x939[x931];
bool x941 = x911 == x940;
if (x941) {
} else {
x932 = false;
}
bool x945 = x932;
if (x945) {
x912 = true;
x924 = false;
} else {
}
int32_t* x950 = x288;
int32_t x951 = x950[x931];
x923 = x951;
}
bool x955 = x912;
if (x955) {
} else {
bool x957 = true;
int32_t x958 = 0;
x958 = x914;
x958 = x918;
int32_t* x962 = x156;
int32_t x961 = x918 & 16383;
int32_t x963 = x962[x961];
int32_t x964 = x963;
bool x965 = true;
for (;;) {
bool x966 = x965;
bool x970;
if (x966) {
int32_t x967 = x964;
bool x968 = x967 != -1;
x970 = x968;
} else {
x970 = false;
}
if (!x970) break;
int32_t x972 = x964;
bool x973 = true;
int32_t* x974 = x140;
int32_t x975 = x974[x972];
bool x976 = x909 == x975;
if (x976) {
} else {
x973 = false;
}
int32_t* x980 = x144;
int32_t x981 = x980[x972];
bool x982 = x911 == x981;
if (x982) {
} else {
x973 = false;
}
bool x986 = x973;
if (x986) {
bool x987 = true;
if (x976) {
} else {
x987 = false;
}
if (x982) {
} else {
x987 = false;
}
bool x994 = x987;
if (x994) {
x957 = false;
} else {
}
bool x998 = x957;
x965 = x998;
} else {
}
int32_t* x1002 = x149;
int32_t x1003 = x1002[x972];
x964 = x1003;
}
bool x1007 = x957;
if (x1007) {
int32_t x1010 = x146;
int32_t x1011 = x137;
bool x1012 = x1010 == x1011;
if (x1012) {
x137 *= 4;
int32_t x1014 = x137;
printf("buffer.resize %d\n",x1014);
} else {
}
int32_t* x1018 = x140;
x1018[x1010] = x909;
int32_t* x1020 = x144;
x1020[x1010] = x911;
x146 += 1;
int32_t x1023 = x1010;
int32_t x1024 = 0;
x1024 = x914;
x1024 = x918;
int32_t x1027 = x963;
x962[x961] = x1010;
int32_t* x1029 = x149;
x1029[x1010] = x963;
int32_t x1031 = 0;
int32_t x1032 = x911 + 233;
x1031 = x1032;
int32_t* x1035 = x158;
int32_t x1034 = x1032 & 16383;
int32_t x1036 = x1035[x1034];
int32_t x1037 = x1036;
x1035[x1034] = x1010;
int32_t* x1039 = x153;
x1039[x1010] = x1036;
} else {
}
}
} else {
}
int32_t* x1047 = x324;
int32_t x1048 = x1047[x899];
x895 = x1048;
}

}
} else {
}
int32_t x1056 = x146;
bool x1057 = x1056 == 0;
if (x1057) {
x645 = false;
} else {
for(int x1061=0; x1061 < x1056; x1061++) {
int32_t* x1062 = x140;
int32_t* x1064 = x144;
bool x1066 = true;
int32_t x1067 = 0;
int32_t x1063 = x1062[x1061];
int32_t x1068 = x1063 + 233;
x1067 = x1068;
int32_t x1065 = x1064[x1061];
int32_t x1070 = x1068 * 1009;
int32_t x1071 = x1070 + x1065;
int32_t x1072 = x1071 + 233;
x1067 = x1072;
int32_t* x1075 = x295;
int32_t x1074 = x1072 & 4194303;
int32_t x1076 = x1075[x1074];
int32_t x1077 = x1076;
bool x1078 = true;
for (;;) {
bool x1079 = x1078;
bool x1083;
if (x1079) {
int32_t x1080 = x1077;
bool x1081 = x1080 != -1;
x1083 = x1081;
} else {
x1083 = false;
}
if (!x1083) break;
int32_t x1085 = x1077;
bool x1086 = true;
int32_t* x1087 = x279;
int32_t x1088 = x1087[x1085];
bool x1089 = x1063 == x1088;
if (x1089) {
} else {
x1086 = false;
}
int32_t* x1093 = x283;
int32_t x1094 = x1093[x1085];
bool x1095 = x1065 == x1094;
if (x1095) {
} else {
x1086 = false;
}
bool x1099 = x1086;
if (x1099) {
bool x1100 = true;
if (x1089) {
} else {
x1100 = false;
}
if (x1095) {
} else {
x1100 = false;
}
bool x1107 = x1100;
if (x1107) {
x1066 = false;
} else {
}
bool x1111 = x1066;
x1078 = x1111;
} else {
}
int32_t* x1115 = x288;
int32_t x1116 = x1115[x1085];
x1077 = x1116;
}
bool x1120 = x1066;
if (x1120) {
int32_t x1123 = x285;
int32_t x1124 = x276;
bool x1125 = x1123 == x1124;
if (x1125) {
x276 *= 4;
int32_t x1127 = x276;
printf("buffer.resize %d\n",x1127);
} else {
}
int32_t* x1131 = x279;
x1131[x1123] = x1063;
int32_t* x1133 = x283;
x1133[x1123] = x1065;
x285 += 1;
int32_t x1136 = x1123;
int32_t x1137 = 0;
x1137 = x1068;
x1137 = x1072;
int32_t x1140 = x1076;
x1075[x1074] = x1123;
int32_t* x1142 = x288;
x1142[x1123] = x1076;
int32_t x1144 = 0;
int32_t x1145 = x1065 + 233;
x1144 = x1145;
int32_t* x1148 = x297;
int32_t x1147 = x1145 & 4194303;
int32_t x1149 = x1148[x1147];
int32_t x1150 = x1149;
x1148[x1147] = x1123;
int32_t* x1152 = x292;
x1152[x1123] = x1149;
} else {
}

}
SWAP(x317,x146);
SWAP(x308,x137);
SWAP(x312,x141);
SWAP(x309,x138);
SWAP(x311,x140);
SWAP(x316,x145);
SWAP(x313,x142);
SWAP(x315,x144);
SWAP(x321,x150);
SWAP(x318,x147);
SWAP(x320,x149);
SWAP(x325,x154);
SWAP(x322,x151);
SWAP(x324,x153);
SWAP(x327,x156);
SWAP(x329,x158);
x146 = 0;
x150 = 0;
x154 = 0;
for(int x1177=0; x1177 < 16384; x1177++) {
int32_t* x1178 = x156;
x1178[x1177] = -1;

}
for(int x1182=0; x1182 < 16384; x1182++) {
int32_t* x1183 = x158;
x1183[x1182] = -1;

}
}
}
for(int x1191=0; x1191 < 16384; x1191++) {
int32_t* x1192 = x327;
x1192[x1191] = -1;

}
for(int x1196=0; x1196 < 16384; x1196++) {
int32_t* x1197 = x329;
x1197[x1196] = -1;

}
for(int x1201=0; x1201 < 16384; x1201++) {
int32_t* x1202 = x156;
x1202[x1201] = -1;

}
for(int x1206=0; x1206 < 16384; x1206++) {
int32_t* x1207 = x158;
x1207[x1206] = -1;

}
int32_t x1212 = x285;
FILE *x1211 = fopen("is_after.out","w");
for(int x1214=0; x1214 < x1212; x1214++) {
int32_t* x1215 = x279;
int32_t x1216 = x1215[x1214];
int32_t x1217 = fprintf(x1211,"%d",x1216);
int32_t x1218 = fprintf(x1211,"\t");
int32_t* x1219 = x283;
int32_t x1220 = x1219[x1214];
int32_t x1221 = fprintf(x1211,"%d",x1220);
int32_t x1222 = fprintf(x1211,"\n");

}
fclose(x1211);
if (x444) {
} else {
for(int x1226=0; x1226 < x443; x1226++) {
int32_t* x1227 = x204;
int32_t* x1229 = x208;
bool x1231 = true;
int32_t x1232 = 0;
int32_t x1228 = x1227[x1226];
int32_t x1233 = x1228 + 233;
x1232 = x1233;
int32_t x1230 = x1229[x1226];
int32_t x1235 = x1233 * 1009;
int32_t x1236 = x1235 + x1230;
int32_t x1237 = x1236 + 233;
x1232 = x1237;
int32_t* x1240 = x124;
int32_t x1239 = x1237 & 4194303;
int32_t x1241 = x1240[x1239];
int32_t x1242 = x1241;
bool x1243 = true;
for (;;) {
bool x1244 = x1243;
bool x1248;
if (x1244) {
int32_t x1245 = x1242;
bool x1246 = x1245 != -1;
x1248 = x1246;
} else {
x1248 = false;
}
if (!x1248) break;
int32_t x1250 = x1242;
bool x1251 = true;
int32_t* x1252 = x108;
int32_t x1253 = x1252[x1250];
bool x1254 = x1228 == x1253;
if (x1254) {
} else {
x1251 = false;
}
int32_t* x1258 = x112;
int32_t x1259 = x1258[x1250];
bool x1260 = x1230 == x1259;
if (x1260) {
} else {
x1251 = false;
}
bool x1264 = x1251;
if (x1264) {
bool x1265 = true;
if (x1254) {
} else {
x1265 = false;
}
if (x1260) {
} else {
x1265 = false;
}
bool x1272 = x1265;
if (x1272) {
x1231 = false;
} else {
}
bool x1276 = x1231;
x1243 = x1276;
} else {
}
int32_t* x1280 = x117;
int32_t x1281 = x1280[x1250];
x1242 = x1281;
}
bool x1285 = x1231;
if (x1285) {
int32_t x1288 = x114;
int32_t x1289 = x105;
bool x1290 = x1288 == x1289;
if (x1290) {
x105 *= 4;
int32_t x1292 = x105;
printf("buffer.resize %d\n",x1292);
} else {
}
int32_t* x1296 = x108;
x1296[x1288] = x1228;
int32_t* x1298 = x112;
x1298[x1288] = x1230;
x114 += 1;
int32_t x1301 = x1288;
int32_t x1302 = 0;
x1302 = x1233;
x1302 = x1237;
int32_t x1305 = x1241;
x1240[x1239] = x1288;
int32_t* x1307 = x117;
x1307[x1288] = x1241;
int32_t x1309 = 0;
x1309 = x1233;
int32_t* x1312 = x126;
int32_t x1311 = x1233 & 4194303;
int32_t x1313 = x1312[x1311];
int32_t x1314 = x1313;
x1312[x1311] = x1288;
int32_t* x1316 = x121;
x1316[x1288] = x1313;
} else {
}

}
}
int32_t x1324 = x114;
for(int x1326=0; x1326 < x1324; x1326++) {
int32_t* x1327 = x108;
int32_t* x1329 = x112;
bool x1331 = true;
int32_t x1332 = 0;
int32_t x1328 = x1327[x1326];
int32_t x1333 = x1328 + 233;
x1332 = x1333;
int32_t x1330 = x1329[x1326];
int32_t x1335 = x1333 * 1009;
int32_t x1336 = x1335 + x1330;
int32_t x1337 = x1336 + 233;
x1332 = x1337;
int32_t* x1340 = x188;
int32_t x1339 = x1337 & 16383;
int32_t x1341 = x1340[x1339];
int32_t x1342 = x1341;
bool x1343 = true;
for (;;) {
bool x1344 = x1343;
bool x1348;
if (x1344) {
int32_t x1345 = x1342;
bool x1346 = x1345 != -1;
x1348 = x1346;
} else {
x1348 = false;
}
if (!x1348) break;
int32_t x1350 = x1342;
bool x1351 = true;
int32_t* x1352 = x172;
int32_t x1353 = x1352[x1350];
bool x1354 = x1328 == x1353;
if (x1354) {
} else {
x1351 = false;
}
int32_t* x1358 = x176;
int32_t x1359 = x1358[x1350];
bool x1360 = x1330 == x1359;
if (x1360) {
} else {
x1351 = false;
}
bool x1364 = x1351;
if (x1364) {
bool x1365 = true;
if (x1354) {
} else {
x1365 = false;
}
if (x1360) {
} else {
x1365 = false;
}
bool x1372 = x1365;
if (x1372) {
x1331 = false;
} else {
}
bool x1376 = x1331;
x1343 = x1376;
} else {
}
int32_t* x1380 = x181;
int32_t x1381 = x1380[x1350];
x1342 = x1381;
}
bool x1385 = x1331;
if (x1385) {
int32_t x1388 = x178;
int32_t x1389 = x169;
bool x1390 = x1388 == x1389;
if (x1390) {
x169 *= 4;
int32_t x1392 = x169;
printf("buffer.resize %d\n",x1392);
} else {
}
int32_t* x1396 = x172;
x1396[x1388] = x1328;
int32_t* x1398 = x176;
x1398[x1388] = x1330;
x178 += 1;
int32_t x1401 = x1388;
int32_t x1402 = 0;
x1402 = x1333;
x1402 = x1337;
int32_t x1405 = x1341;
x1340[x1339] = x1388;
int32_t* x1407 = x181;
x1407[x1388] = x1341;
int32_t x1409 = 0;
x1409 = x1333;
int32_t* x1412 = x190;
int32_t x1411 = x1333 & 16383;
int32_t x1413 = x1412[x1411];
int32_t x1414 = x1413;
x1412[x1411] = x1388;
int32_t* x1416 = x185;
x1416[x1388] = x1413;
} else {
}

}
bool x1422 = true;
for (;;) {
bool x1423 = x1422;
if (!x1423) break;
int32_t x1425 = x178;
bool x1426 = x1425 == 0;
bool x1432;
if (x1426) {
x1432 = false;
} else {
int32_t x1428 = x114;
bool x1429 = x1428 == 0;
bool x1430 = !x1429;
x1432 = x1430;
}
if (x1432) {
for(int x1434=0; x1434 < x1425; x1434++) {
int32_t* x1435 = x176;
int32_t x1437 = 0;
int32_t x1436 = x1435[x1434];
int32_t x1438 = x1436 + 233;
x1437 = x1438;
int32_t* x1441 = x126;
int32_t x1440 = x1438 & 4194303;
int32_t x1442 = x1441[x1440];
int32_t x1443 = x1442;
for (;;) {
int32_t x1444 = x1443;
bool x1445 = x1444 != -1;
if (!x1445) break;
int32_t x1447 = x1443;
bool x1448 = true;
int32_t* x1449 = x108;
int32_t x1450 = x1449[x1447];
bool x1451 = x1436 == x1450;
if (x1451) {
} else {
x1448 = false;
}
bool x1455 = x1448;
if (x1455) {
int32_t* x1456 = x176;
int32_t* x1458 = x112;
bool x1460 = false;
int32_t x1461 = 0;
int32_t x1457 = x1456[x1434];
int32_t x1462 = x1457 + 233;
x1461 = x1462;
int32_t x1459 = x1458[x1447];
int32_t x1464 = x1462 * 1009;
int32_t x1465 = x1464 + x1459;
int32_t x1466 = x1465 + 233;
x1461 = x1466;
int32_t* x1469 = x188;
int32_t x1468 = x1466 & 16383;
int32_t x1470 = x1469[x1468];
int32_t x1471 = x1470;
bool x1472 = true;
for (;;) {
bool x1473 = x1472;
bool x1477;
if (x1473) {
int32_t x1474 = x1471;
bool x1475 = x1474 != -1;
x1477 = x1475;
} else {
x1477 = false;
}
if (!x1477) break;
int32_t x1479 = x1471;
bool x1480 = true;
int32_t* x1481 = x172;
int32_t x1482 = x1481[x1479];
bool x1483 = x1457 == x1482;
if (x1483) {
} else {
x1480 = false;
}
int32_t* x1487 = x176;
int32_t x1488 = x1487[x1479];
bool x1489 = x1459 == x1488;
if (x1489) {
} else {
x1480 = false;
}
bool x1493 = x1480;
if (x1493) {
x1460 = true;
x1472 = false;
} else {
}
int32_t* x1498 = x181;
int32_t x1499 = x1498[x1479];
x1471 = x1499;
}
bool x1503 = x1460;
bool x1553;
if (x1503) {
x1553 = false;
} else {
int32_t* x1505 = x172;
bool x1507 = false;
int32_t x1508 = 0;
int32_t x1506 = x1505[x1434];
int32_t x1509 = x1506 + 233;
x1508 = x1509;
int32_t x1511 = x1509 * 1009;
int32_t x1512 = x1511 + x1459;
int32_t x1513 = x1512 + 233;
x1508 = x1513;
int32_t* x1516 = x124;
int32_t x1515 = x1513 & 4194303;
int32_t x1517 = x1516[x1515];
int32_t x1518 = x1517;
bool x1519 = true;
for (;;) {
bool x1520 = x1519;
bool x1524;
if (x1520) {
int32_t x1521 = x1518;
bool x1522 = x1521 != -1;
x1524 = x1522;
} else {
x1524 = false;
}
if (!x1524) break;
int32_t x1526 = x1518;
bool x1527 = true;
int32_t* x1528 = x108;
int32_t x1529 = x1528[x1526];
bool x1530 = x1506 == x1529;
if (x1530) {
} else {
x1527 = false;
}
int32_t* x1534 = x112;
int32_t x1535 = x1534[x1526];
bool x1536 = x1459 == x1535;
if (x1536) {
} else {
x1527 = false;
}
bool x1540 = x1527;
if (x1540) {
x1507 = true;
x1519 = false;
} else {
}
int32_t* x1545 = x117;
int32_t x1546 = x1545[x1526];
x1518 = x1546;
}
bool x1550 = x1507;
bool x1551 = !x1550;
x1553 = x1551;
}
if (x1553) {
int32_t* x1554 = x172;
bool x1556 = true;
int32_t x1557 = 0;
int32_t x1555 = x1554[x1434];
int32_t x1558 = x1555 + 233;
x1557 = x1558;
int32_t x1560 = x1558 * 1009;
int32_t x1561 = x1560 + x1459;
int32_t x1562 = x1561 + 233;
x1557 = x1562;
int32_t* x1565 = x263;
int32_t x1564 = x1562 & 16383;
int32_t x1566 = x1565[x1564];
int32_t x1567 = x1566;
bool x1568 = true;
for (;;) {
bool x1569 = x1568;
bool x1573;
if (x1569) {
int32_t x1570 = x1567;
bool x1571 = x1570 != -1;
x1573 = x1571;
} else {
x1573 = false;
}
if (!x1573) break;
int32_t x1575 = x1567;
bool x1576 = true;
int32_t* x1577 = x247;
int32_t x1578 = x1577[x1575];
bool x1579 = x1555 == x1578;
if (x1579) {
} else {
x1576 = false;
}
int32_t* x1583 = x251;
int32_t x1584 = x1583[x1575];
bool x1585 = x1459 == x1584;
if (x1585) {
} else {
x1576 = false;
}
bool x1589 = x1576;
if (x1589) {
bool x1590 = true;
if (x1579) {
} else {
x1590 = false;
}
if (x1585) {
} else {
x1590 = false;
}
bool x1597 = x1590;
if (x1597) {
x1556 = false;
} else {
}
bool x1601 = x1556;
x1568 = x1601;
} else {
}
int32_t* x1605 = x256;
int32_t x1606 = x1605[x1575];
x1567 = x1606;
}
bool x1610 = x1556;
if (x1610) {
int32_t x1613 = x253;
int32_t x1614 = x244;
bool x1615 = x1613 == x1614;
if (x1615) {
x244 *= 4;
int32_t x1617 = x244;
printf("buffer.resize %d\n",x1617);
} else {
}
int32_t* x1621 = x247;
x1621[x1613] = x1555;
int32_t* x1623 = x251;
x1623[x1613] = x1459;
x253 += 1;
int32_t x1626 = x1613;
int32_t x1627 = 0;
x1627 = x1558;
x1627 = x1562;
int32_t x1630 = x1566;
x1565[x1564] = x1613;
int32_t* x1632 = x256;
x1632[x1613] = x1566;
int32_t x1634 = 0;
x1634 = x1558;
int32_t* x1637 = x265;
int32_t x1636 = x1558 & 16383;
int32_t x1638 = x1637[x1636];
int32_t x1639 = x1638;
x1637[x1636] = x1613;
int32_t* x1641 = x260;
x1641[x1613] = x1638;
} else {
}
} else {
}
} else {
}
int32_t* x1649 = x121;
int32_t x1650 = x1649[x1447];
x1443 = x1650;
}

}
} else {
}
int32_t x1658 = x114;
bool x1659 = x1658 == 0;
bool x1661;
if (x1659) {
x1661 = false;
} else {
bool x1427 = !x1426;
x1661 = x1427;
}
if (x1661) {
for(int x1663=0; x1663 < x1658; x1663++) {
int32_t* x1664 = x112;
int32_t x1666 = 0;
int32_t x1665 = x1664[x1663];
int32_t x1667 = x1665 + 233;
x1666 = x1667;
int32_t* x1670 = x190;
int32_t x1669 = x1667 & 16383;
int32_t x1671 = x1670[x1669];
int32_t x1672 = x1671;
for (;;) {
int32_t x1673 = x1672;
bool x1674 = x1673 != -1;
if (!x1674) break;
int32_t x1676 = x1672;
bool x1677 = true;
int32_t* x1678 = x172;
int32_t x1679 = x1678[x1676];
bool x1680 = x1665 == x1679;
if (x1680) {
} else {
x1677 = false;
}
bool x1684 = x1677;
if (x1684) {
int32_t* x1685 = x108;
int32_t* x1687 = x176;
bool x1689 = false;
int32_t x1690 = 0;
int32_t x1686 = x1685[x1663];
int32_t x1691 = x1686 + 233;
x1690 = x1691;
int32_t x1688 = x1687[x1676];
int32_t x1693 = x1691 * 1009;
int32_t x1694 = x1693 + x1688;
int32_t x1695 = x1694 + 233;
x1690 = x1695;
int32_t* x1698 = x124;
int32_t x1697 = x1695 & 4194303;
int32_t x1699 = x1698[x1697];
int32_t x1700 = x1699;
bool x1701 = true;
for (;;) {
bool x1702 = x1701;
bool x1706;
if (x1702) {
int32_t x1703 = x1700;
bool x1704 = x1703 != -1;
x1706 = x1704;
} else {
x1706 = false;
}
if (!x1706) break;
int32_t x1708 = x1700;
bool x1709 = true;
int32_t* x1710 = x108;
int32_t x1711 = x1710[x1708];
bool x1712 = x1686 == x1711;
if (x1712) {
} else {
x1709 = false;
}
int32_t* x1716 = x112;
int32_t x1717 = x1716[x1708];
bool x1718 = x1688 == x1717;
if (x1718) {
} else {
x1709 = false;
}
bool x1722 = x1709;
if (x1722) {
x1689 = true;
x1701 = false;
} else {
}
int32_t* x1727 = x117;
int32_t x1728 = x1727[x1708];
x1700 = x1728;
}
bool x1732 = x1689;
if (x1732) {
} else {
bool x1734 = true;
int32_t x1735 = 0;
x1735 = x1691;
x1735 = x1695;
int32_t* x1739 = x263;
int32_t x1738 = x1695 & 16383;
int32_t x1740 = x1739[x1738];
int32_t x1741 = x1740;
bool x1742 = true;
for (;;) {
bool x1743 = x1742;
bool x1747;
if (x1743) {
int32_t x1744 = x1741;
bool x1745 = x1744 != -1;
x1747 = x1745;
} else {
x1747 = false;
}
if (!x1747) break;
int32_t x1749 = x1741;
bool x1750 = true;
int32_t* x1751 = x247;
int32_t x1752 = x1751[x1749];
bool x1753 = x1686 == x1752;
if (x1753) {
} else {
x1750 = false;
}
int32_t* x1757 = x251;
int32_t x1758 = x1757[x1749];
bool x1759 = x1688 == x1758;
if (x1759) {
} else {
x1750 = false;
}
bool x1763 = x1750;
if (x1763) {
bool x1764 = true;
if (x1753) {
} else {
x1764 = false;
}
if (x1759) {
} else {
x1764 = false;
}
bool x1771 = x1764;
if (x1771) {
x1734 = false;
} else {
}
bool x1775 = x1734;
x1742 = x1775;
} else {
}
int32_t* x1779 = x256;
int32_t x1780 = x1779[x1749];
x1741 = x1780;
}
bool x1784 = x1734;
if (x1784) {
int32_t x1787 = x253;
int32_t x1788 = x244;
bool x1789 = x1787 == x1788;
if (x1789) {
x244 *= 4;
int32_t x1791 = x244;
printf("buffer.resize %d\n",x1791);
} else {
}
int32_t* x1795 = x247;
x1795[x1787] = x1686;
int32_t* x1797 = x251;
x1797[x1787] = x1688;
x253 += 1;
int32_t x1800 = x1787;
int32_t x1801 = 0;
x1801 = x1691;
x1801 = x1695;
int32_t x1804 = x1740;
x1739[x1738] = x1787;
int32_t* x1806 = x256;
x1806[x1787] = x1740;
int32_t x1808 = 0;
x1808 = x1691;
int32_t* x1811 = x265;
int32_t x1810 = x1691 & 16383;
int32_t x1812 = x1811[x1810];
int32_t x1813 = x1812;
x1811[x1810] = x1787;
int32_t* x1815 = x260;
x1815[x1787] = x1812;
} else {
}
}
} else {
}
int32_t* x1823 = x185;
int32_t x1824 = x1823[x1676];
x1672 = x1824;
}

}
} else {
}
int32_t x1832 = x253;
bool x1833 = x1832 == 0;
if (x1833) {
x1422 = false;
} else {
for(int x1837=0; x1837 < x1832; x1837++) {
int32_t* x1838 = x247;
int32_t* x1840 = x251;
bool x1842 = true;
int32_t x1843 = 0;
int32_t x1839 = x1838[x1837];
int32_t x1844 = x1839 + 233;
x1843 = x1844;
int32_t x1841 = x1840[x1837];
int32_t x1846 = x1844 * 1009;
int32_t x1847 = x1846 + x1841;
int32_t x1848 = x1847 + 233;
x1843 = x1848;
int32_t* x1851 = x124;
int32_t x1850 = x1848 & 4194303;
int32_t x1852 = x1851[x1850];
int32_t x1853 = x1852;
bool x1854 = true;
for (;;) {
bool x1855 = x1854;
bool x1859;
if (x1855) {
int32_t x1856 = x1853;
bool x1857 = x1856 != -1;
x1859 = x1857;
} else {
x1859 = false;
}
if (!x1859) break;
int32_t x1861 = x1853;
bool x1862 = true;
int32_t* x1863 = x108;
int32_t x1864 = x1863[x1861];
bool x1865 = x1839 == x1864;
if (x1865) {
} else {
x1862 = false;
}
int32_t* x1869 = x112;
int32_t x1870 = x1869[x1861];
bool x1871 = x1841 == x1870;
if (x1871) {
} else {
x1862 = false;
}
bool x1875 = x1862;
if (x1875) {
bool x1876 = true;
if (x1865) {
} else {
x1876 = false;
}
if (x1871) {
} else {
x1876 = false;
}
bool x1883 = x1876;
if (x1883) {
x1842 = false;
} else {
}
bool x1887 = x1842;
x1854 = x1887;
} else {
}
int32_t* x1891 = x117;
int32_t x1892 = x1891[x1861];
x1853 = x1892;
}
bool x1896 = x1842;
if (x1896) {
int32_t x1899 = x114;
int32_t x1900 = x105;
bool x1901 = x1899 == x1900;
if (x1901) {
x105 *= 4;
int32_t x1903 = x105;
printf("buffer.resize %d\n",x1903);
} else {
}
int32_t* x1907 = x108;
x1907[x1899] = x1839;
int32_t* x1909 = x112;
x1909[x1899] = x1841;
x114 += 1;
int32_t x1912 = x1899;
int32_t x1913 = 0;
x1913 = x1844;
x1913 = x1848;
int32_t x1916 = x1852;
x1851[x1850] = x1899;
int32_t* x1918 = x117;
x1918[x1899] = x1852;
int32_t x1920 = 0;
x1920 = x1844;
int32_t* x1923 = x126;
int32_t x1922 = x1844 & 4194303;
int32_t x1924 = x1923[x1922];
int32_t x1925 = x1924;
x1923[x1922] = x1899;
int32_t* x1927 = x121;
x1927[x1899] = x1924;
} else {
}

}
SWAP(x178,x253);
SWAP(x169,x244);
SWAP(x173,x248);
SWAP(x170,x245);
SWAP(x172,x247);
SWAP(x177,x252);
SWAP(x174,x249);
SWAP(x176,x251);
SWAP(x182,x257);
SWAP(x179,x254);
SWAP(x181,x256);
SWAP(x186,x261);
SWAP(x183,x258);
SWAP(x185,x260);
SWAP(x188,x263);
SWAP(x190,x265);
x253 = 0;
x257 = 0;
x261 = 0;
for(int x1952=0; x1952 < 16384; x1952++) {
int32_t* x1953 = x263;
x1953[x1952] = -1;

}
for(int x1957=0; x1957 < 16384; x1957++) {
int32_t* x1958 = x265;
x1958[x1957] = -1;

}
}
}
for(int x1966=0; x1966 < 16384; x1966++) {
int32_t* x1967 = x188;
x1967[x1966] = -1;

}
for(int x1971=0; x1971 < 16384; x1971++) {
int32_t* x1972 = x190;
x1972[x1971] = -1;

}
for(int x1976=0; x1976 < 16384; x1976++) {
int32_t* x1977 = x263;
x1977[x1976] = -1;

}
for(int x1981=0; x1981 < 16384; x1981++) {
int32_t* x1982 = x265;
x1982[x1981] = -1;

}
int32_t x1986 = x114;
for(int x1988=0; x1988 < x1986; x1988++) {
int32_t* x1989 = x108;
int32_t x1990 = x1989[x1988];
int32_t x1991 = fprintf(x1211,"%d",x1990);
int32_t x1992 = fprintf(x1211,"\t");
int32_t* x1993 = x112;
int32_t x1994 = x1993[x1988];
int32_t x1995 = fprintf(x1211,"%d",x1994);
int32_t x1996 = fprintf(x1211,"\n");

}
fclose(x1211);
if (x444) {
} else {
for(int x2000=0; x2000 < x443; x2000++) {
int32_t* x2001 = x204;
bool x2003 = true;
int32_t x2004 = 0;
int32_t x2002 = x2001[x2000];
int32_t x2005 = x2002 + 233;
x2004 = x2005;
int32_t* x2008 = x12;
int32_t x2007 = x2005 & 4194303;
int32_t x2009 = x2008[x2007];
int32_t x2010 = x2009;
bool x2011 = true;
for (;;) {
bool x2012 = x2011;
bool x2016;
if (x2012) {
int32_t x2013 = x2010;
bool x2014 = x2013 != -1;
x2016 = x2014;
} else {
x2016 = false;
}
if (!x2016) break;
int32_t x2018 = x2010;
bool x2019 = true;
int32_t* x2020 = x4;
int32_t x2021 = x2020[x2018];
bool x2022 = x2002 == x2021;
if (x2022) {
} else {
x2019 = false;
}
bool x2026 = x2019;
if (x2026) {
bool x2027 = true;
if (x2022) {
} else {
x2027 = false;
}
bool x2031 = x2027;
if (x2031) {
x2003 = false;
} else {
}
bool x2035 = x2003;
x2011 = x2035;
} else {
}
int32_t* x2039 = x9;
int32_t x2040 = x2039[x2018];
x2010 = x2040;
}
bool x2044 = x2003;
if (x2044) {
int32_t x2047 = x6;
int32_t x2048 = x1;
bool x2049 = x2047 == x2048;
if (x2049) {
x1 *= 4;
int32_t x2051 = x1;
printf("buffer.resize %d\n",x2051);
} else {
}
int32_t* x2055 = x4;
x2055[x2047] = x2002;
x6 += 1;
int32_t x2058 = x2047;
int32_t x2059 = 0;
x2059 = x2005;
int32_t x2061 = x2009;
x2008[x2007] = x2047;
int32_t* x2063 = x9;
x2063[x2047] = x2009;
} else {
}

}
}
if (x444) {
} else {
for(int x2071=0; x2071 < x443; x2071++) {
int32_t* x2072 = x208;
bool x2074 = true;
int32_t x2075 = 0;
int32_t x2073 = x2072[x2071];
int32_t x2076 = x2073 + 233;
x2075 = x2076;
int32_t* x2079 = x12;
int32_t x2078 = x2076 & 4194303;
int32_t x2080 = x2079[x2078];
int32_t x2081 = x2080;
bool x2082 = true;
for (;;) {
bool x2083 = x2082;
bool x2087;
if (x2083) {
int32_t x2084 = x2081;
bool x2085 = x2084 != -1;
x2087 = x2085;
} else {
x2087 = false;
}
if (!x2087) break;
int32_t x2089 = x2081;
bool x2090 = true;
int32_t* x2091 = x4;
int32_t x2092 = x2091[x2089];
bool x2093 = x2073 == x2092;
if (x2093) {
} else {
x2090 = false;
}
bool x2097 = x2090;
if (x2097) {
bool x2098 = true;
if (x2093) {
} else {
x2098 = false;
}
bool x2102 = x2098;
if (x2102) {
x2074 = false;
} else {
}
bool x2106 = x2074;
x2082 = x2106;
} else {
}
int32_t* x2110 = x9;
int32_t x2111 = x2110[x2089];
x2081 = x2111;
}
bool x2115 = x2074;
if (x2115) {
int32_t x2118 = x6;
int32_t x2119 = x1;
bool x2120 = x2118 == x2119;
if (x2120) {
x1 *= 4;
int32_t x2122 = x1;
printf("buffer.resize %d\n",x2122);
} else {
}
int32_t* x2126 = x4;
x2126[x2118] = x2073;
x6 += 1;
int32_t x2129 = x2118;
int32_t x2130 = 0;
x2130 = x2076;
int32_t x2132 = x2080;
x2079[x2078] = x2118;
int32_t* x2134 = x9;
x2134[x2118] = x2080;
} else {
}

}
}
int32_t x2142 = x6;
bool x2143 = x2142 == 0;
if (x2143) {
} else {
for(int x2146=0; x2146 < x2142; x2146++) {
int32_t* x2147 = x4;
bool x2149 = false;
int32_t x2150 = 0;
int32_t x2148 = x2147[x2146];
int32_t x2151 = x2148 + 233;
x2150 = x2151;
int32_t* x2154 = x228;
int32_t x2153 = x2151 & 4194303;
int32_t x2155 = x2154[x2153];
int32_t x2156 = x2155;
bool x2157 = true;
for (;;) {
bool x2158 = x2157;
bool x2162;
if (x2158) {
int32_t x2159 = x2156;
bool x2160 = x2159 != -1;
x2162 = x2160;
} else {
x2162 = false;
}
if (!x2162) break;
int32_t x2164 = x2156;
bool x2165 = true;
int32_t* x2166 = x204;
int32_t x2167 = x2166[x2164];
bool x2168 = x2148 == x2167;
if (x2168) {
} else {
x2165 = false;
}
bool x2172 = x2165;
if (x2172) {
x2149 = true;
x2157 = false;
} else {
}
int32_t* x2177 = x221;
int32_t x2178 = x2177[x2164];
x2156 = x2178;
}
bool x2182 = x2149;
bool x2218;
if (x2182) {
x2218 = false;
} else {
bool x2184 = false;
int32_t x2185 = 0;
x2185 = x2151;
int32_t* x2187 = x226;
int32_t x2188 = x2187[x2153];
int32_t x2189 = x2188;
bool x2190 = true;
for (;;) {
bool x2191 = x2190;
bool x2195;
if (x2191) {
int32_t x2192 = x2189;
bool x2193 = x2192 != -1;
x2195 = x2193;
} else {
x2195 = false;
}
if (!x2195) break;
int32_t x2197 = x2189;
bool x2198 = true;
int32_t* x2199 = x208;
int32_t x2200 = x2199[x2197];
bool x2201 = x2148 == x2200;
if (x2201) {
} else {
x2198 = false;
}
bool x2205 = x2198;
if (x2205) {
x2184 = true;
x2190 = false;
} else {
}
int32_t* x2210 = x217;
int32_t x2211 = x2210[x2197];
x2189 = x2211;
}
bool x2215 = x2184;
bool x2216 = !x2215;
x2218 = x2216;
}
if (x2218) {
bool x2219 = true;
int32_t x2220 = 0;
x2220 = x2151;
int32_t x2222 = x2151 * 1009;
int32_t x2223 = x2222 + 233;
x2220 = x2223;
int32_t* x2226 = x34;
int32_t x2225 = x2223 & 4194303;
int32_t x2227 = x2226[x2225];
int32_t x2228 = x2227;
bool x2229 = true;
for (;;) {
bool x2230 = x2229;
bool x2234;
if (x2230) {
int32_t x2231 = x2228;
bool x2232 = x2231 != -1;
x2234 = x2232;
} else {
x2234 = false;
}
if (!x2234) break;
int32_t x2236 = x2228;
bool x2237 = true;
int32_t* x2238 = x22;
int32_t x2239 = x2238[x2236];
bool x2240 = x2148 == x2239;
if (x2240) {
} else {
x2237 = false;
}
int32_t* x2244 = x26;
int32_t x2245 = x2244[x2236];
bool x2246 = 0 == x2245;
if (x2246) {
} else {
x2237 = false;
}
bool x2250 = x2237;
if (x2250) {
bool x2251 = true;
if (x2240) {
} else {
x2251 = false;
}
if (x2246) {
} else {
x2251 = false;
}
bool x2258 = x2251;
if (x2258) {
x2219 = false;
} else {
}
bool x2262 = x2219;
x2229 = x2262;
} else {
}
int32_t* x2266 = x31;
int32_t x2267 = x2266[x2236];
x2228 = x2267;
}
bool x2271 = x2219;
if (x2271) {
int32_t x2274 = x28;
int32_t x2275 = x19;
bool x2276 = x2274 == x2275;
if (x2276) {
x19 *= 4;
int32_t x2278 = x19;
printf("buffer.resize %d\n",x2278);
} else {
}
int32_t* x2282 = x22;
x2282[x2274] = x2148;
int32_t* x2284 = x26;
x2284[x2274] = 0;
x28 += 1;
int32_t x2287 = x2274;
int32_t x2288 = 0;
x2288 = x2151;
x2288 = x2223;
int32_t x2291 = x2227;
x2226[x2225] = x2274;
int32_t* x2293 = x31;
x2293[x2274] = x2227;
} else {
}
} else {
}

}
}
bool x2303;
if (x2143) {
x2303 = false;
} else {
bool x445 = !x444;
x2303 = x445;
}
if (x2303) {
for(int x2304=0; x2304 < x2142; x2304++) {
int32_t* x2305 = x4;
bool x2307 = false;
int32_t x2308 = 0;
int32_t x2306 = x2305[x2304];
int32_t x2309 = x2306 + 233;
x2308 = x2309;
int32_t* x2312 = x228;
int32_t x2311 = x2309 & 4194303;
int32_t x2313 = x2312[x2311];
int32_t x2314 = x2313;
bool x2315 = true;
for (;;) {
bool x2316 = x2315;
bool x2320;
if (x2316) {
int32_t x2317 = x2314;
bool x2318 = x2317 != -1;
x2320 = x2318;
} else {
x2320 = false;
}
if (!x2320) break;
int32_t x2322 = x2314;
bool x2323 = true;
int32_t* x2324 = x204;
int32_t x2325 = x2324[x2322];
bool x2326 = x2306 == x2325;
if (x2326) {
} else {
x2323 = false;
}
bool x2330 = x2323;
if (x2330) {
x2307 = true;
x2315 = false;
} else {
}
int32_t* x2335 = x221;
int32_t x2336 = x2335[x2322];
x2314 = x2336;
}
bool x2340 = x2307;
bool x2375;
if (x2340) {
bool x2341 = false;
int32_t x2342 = 0;
x2342 = x2309;
int32_t* x2344 = x226;
int32_t x2345 = x2344[x2311];
int32_t x2346 = x2345;
bool x2347 = true;
for (;;) {
bool x2348 = x2347;
bool x2352;
if (x2348) {
int32_t x2349 = x2346;
bool x2350 = x2349 != -1;
x2352 = x2350;
} else {
x2352 = false;
}
if (!x2352) break;
int32_t x2354 = x2346;
bool x2355 = true;
int32_t* x2356 = x208;
int32_t x2357 = x2356[x2354];
bool x2358 = x2306 == x2357;
if (x2358) {
} else {
x2355 = false;
}
bool x2362 = x2355;
if (x2362) {
x2341 = true;
x2347 = false;
} else {
}
int32_t* x2367 = x217;
int32_t x2368 = x2367[x2354];
x2346 = x2368;
}
bool x2372 = x2341;
bool x2373 = !x2372;
x2375 = x2373;
} else {
x2375 = false;
}
if (x2375) {
bool x2376 = true;
int32_t x2377 = 0;
x2377 = x2309;
int32_t x2379 = x2309 * 1009;
int32_t x2380 = x2379 + 1;
int32_t x2381 = x2380 + 233;
x2377 = x2381;
int32_t* x2384 = x34;
int32_t x2383 = x2381 & 4194303;
int32_t x2385 = x2384[x2383];
int32_t x2386 = x2385;
bool x2387 = true;
for (;;) {
bool x2388 = x2387;
bool x2392;
if (x2388) {
int32_t x2389 = x2386;
bool x2390 = x2389 != -1;
x2392 = x2390;
} else {
x2392 = false;
}
if (!x2392) break;
int32_t x2394 = x2386;
bool x2395 = true;
int32_t* x2396 = x22;
int32_t x2397 = x2396[x2394];
bool x2398 = x2306 == x2397;
if (x2398) {
} else {
x2395 = false;
}
int32_t* x2402 = x26;
int32_t x2403 = x2402[x2394];
bool x2404 = 1 == x2403;
if (x2404) {
} else {
x2395 = false;
}
bool x2408 = x2395;
if (x2408) {
bool x2409 = true;
if (x2398) {
} else {
x2409 = false;
}
if (x2404) {
} else {
x2409 = false;
}
bool x2416 = x2409;
if (x2416) {
x2376 = false;
} else {
}
bool x2420 = x2376;
x2387 = x2420;
} else {
}
int32_t* x2424 = x31;
int32_t x2425 = x2424[x2394];
x2386 = x2425;
}
bool x2429 = x2376;
if (x2429) {
int32_t x2432 = x28;
int32_t x2433 = x19;
bool x2434 = x2432 == x2433;
if (x2434) {
x19 *= 4;
int32_t x2436 = x19;
printf("buffer.resize %d\n",x2436);
} else {
}
int32_t* x2440 = x22;
x2440[x2432] = x2306;
int32_t* x2442 = x26;
x2442[x2432] = 1;
x28 += 1;
int32_t x2445 = x2432;
int32_t x2446 = 0;
x2446 = x2309;
x2446 = x2381;
int32_t x2449 = x2385;
x2384[x2383] = x2432;
int32_t* x2451 = x31;
x2451[x2432] = x2385;
} else {
}
} else {
}

}
} else {
}
int32_t x2461 = x28;
for(int x2463=0; x2463 < x2461; x2463++) {
int32_t* x2464 = x22;
int32_t* x2466 = x26;
bool x2468 = true;
int32_t x2469 = 0;
int32_t x2465 = x2464[x2463];
int32_t x2470 = x2465 + 233;
x2469 = x2470;
int32_t x2467 = x2466[x2463];
int32_t x2472 = x2470 * 1009;
int32_t x2473 = x2472 + x2467;
int32_t x2474 = x2473 + 233;
x2469 = x2474;
int32_t* x2477 = x59;
int32_t x2476 = x2474 & 16383;
int32_t x2478 = x2477[x2476];
int32_t x2479 = x2478;
bool x2480 = true;
for (;;) {
bool x2481 = x2480;
bool x2485;
if (x2481) {
int32_t x2482 = x2479;
bool x2483 = x2482 != -1;
x2485 = x2483;
} else {
x2485 = false;
}
if (!x2485) break;
int32_t x2487 = x2479;
bool x2488 = true;
int32_t* x2489 = x43;
int32_t x2490 = x2489[x2487];
bool x2491 = x2465 == x2490;
if (x2491) {
} else {
x2488 = false;
}
int32_t* x2495 = x47;
int32_t x2496 = x2495[x2487];
bool x2497 = x2467 == x2496;
if (x2497) {
} else {
x2488 = false;
}
bool x2501 = x2488;
if (x2501) {
bool x2502 = true;
if (x2491) {
} else {
x2502 = false;
}
if (x2497) {
} else {
x2502 = false;
}
bool x2509 = x2502;
if (x2509) {
x2468 = false;
} else {
}
bool x2513 = x2468;
x2480 = x2513;
} else {
}
int32_t* x2517 = x52;
int32_t x2518 = x2517[x2487];
x2479 = x2518;
}
bool x2522 = x2468;
if (x2522) {
int32_t x2525 = x49;
int32_t x2526 = x40;
bool x2527 = x2525 == x2526;
if (x2527) {
x40 *= 4;
int32_t x2529 = x40;
printf("buffer.resize %d\n",x2529);
} else {
}
int32_t* x2533 = x43;
x2533[x2525] = x2465;
int32_t* x2535 = x47;
x2535[x2525] = x2467;
x49 += 1;
int32_t x2538 = x2525;
int32_t x2539 = 0;
x2539 = x2470;
x2539 = x2474;
int32_t x2542 = x2478;
x2477[x2476] = x2525;
int32_t* x2544 = x52;
x2544[x2525] = x2478;
int32_t x2546 = 0;
x2546 = x2470;
int32_t* x2549 = x61;
int32_t x2548 = x2470 & 16383;
int32_t x2550 = x2549[x2548];
int32_t x2551 = x2550;
x2549[x2548] = x2525;
int32_t* x2553 = x56;
x2553[x2525] = x2550;
} else {
}

}
bool x2559 = true;
for (;;) {
bool x2560 = x2559;
if (!x2560) break;
int32_t x2562 = x114;
bool x2563 = x2562 == 0;
bool x2569;
if (x2563) {
x2569 = false;
} else {
int32_t x2565 = x285;
bool x2566 = x2565 == 0;
bool x2567 = !x2566;
x2569 = x2567;
}
bool x2574;
if (x2569) {
int32_t x2570 = x49;
bool x2571 = x2570 == 0;
bool x2572 = !x2571;
x2574 = x2572;
} else {
x2574 = false;
}
if (x2574) {
for(int x2576=0; x2576 < x2562; x2576++) {
int32_t* x2577 = x112;
int32_t* x2579 = x108;
bool x2581 = false;
int32_t x2582 = 0;
int32_t x2578 = x2577[x2576];
int32_t x2583 = x2578 + 233;
x2582 = x2583;
int32_t x2580 = x2579[x2576];
int32_t x2585 = x2583 * 1009;
int32_t x2586 = x2585 + x2580;
int32_t x2587 = x2586 + 233;
x2582 = x2587;
int32_t* x2590 = x295;
int32_t x2589 = x2587 & 4194303;
int32_t x2591 = x2590[x2589];
int32_t x2592 = x2591;
bool x2593 = true;
for (;;) {
bool x2594 = x2593;
bool x2598;
if (x2594) {
int32_t x2595 = x2592;
bool x2596 = x2595 != -1;
x2598 = x2596;
} else {
x2598 = false;
}
if (!x2598) break;
int32_t x2600 = x2592;
bool x2601 = true;
int32_t* x2602 = x279;
int32_t x2603 = x2602[x2600];
bool x2604 = x2578 == x2603;
if (x2604) {
} else {
x2601 = false;
}
int32_t* x2608 = x283;
int32_t x2609 = x2608[x2600];
bool x2610 = x2580 == x2609;
if (x2610) {
} else {
x2601 = false;
}
bool x2614 = x2601;
if (x2614) {
x2581 = true;
x2593 = false;
} else {
}
int32_t* x2619 = x288;
int32_t x2620 = x2619[x2600];
x2592 = x2620;
}
bool x2624 = x2581;
bool x2666;
if (x2624) {
bool x2625 = false;
int32_t x2626 = 0;
x2626 = x2583;
x2626 = x2587;
int32_t* x2629 = x124;
int32_t x2630 = x2629[x2589];
int32_t x2631 = x2630;
bool x2632 = true;
for (;;) {
bool x2633 = x2632;
bool x2637;
if (x2633) {
int32_t x2634 = x2631;
bool x2635 = x2634 != -1;
x2637 = x2635;
} else {
x2637 = false;
}
if (!x2637) break;
int32_t x2639 = x2631;
bool x2640 = true;
int32_t* x2641 = x108;
int32_t x2642 = x2641[x2639];
bool x2643 = x2578 == x2642;
if (x2643) {
} else {
x2640 = false;
}
int32_t* x2647 = x112;
int32_t x2648 = x2647[x2639];
bool x2649 = x2580 == x2648;
if (x2649) {
} else {
x2640 = false;
}
bool x2653 = x2640;
if (x2653) {
x2625 = true;
x2632 = false;
} else {
}
int32_t* x2658 = x117;
int32_t x2659 = x2658[x2639];
x2631 = x2659;
}
bool x2663 = x2625;
bool x2664 = !x2663;
x2666 = x2664;
} else {
x2666 = false;
}
if (x2666) {
int32_t x2667 = 0;
int32_t x2668 = x2580 + 233;
x2667 = x2668;
int32_t* x2671 = x61;
int32_t x2670 = x2668 & 16383;
int32_t x2672 = x2671[x2670];
int32_t x2673 = x2672;
for (;;) {
int32_t x2674 = x2673;
bool x2675 = x2674 != -1;
if (!x2675) break;
int32_t x2677 = x2673;
bool x2678 = true;
int32_t* x2679 = x43;
int32_t x2680 = x2679[x2677];
bool x2681 = x2580 == x2680;
if (x2681) {
} else {
x2678 = false;
}
bool x2685 = x2678;
if (x2685) {
int32_t* x2686 = x112;
int32_t* x2688 = x47;
bool x2691 = false;
int32_t x2692 = 0;
int32_t x2687 = x2686[x2576];
int32_t x2693 = x2687 + 233;
x2692 = x2693;
int32_t x2689 = x2688[x2677];
int32_t x2690 = x2689 + 1;
int32_t x2695 = x2693 * 1009;
int32_t x2696 = x2695 + x2690;
int32_t x2697 = x2696 + 233;
x2692 = x2697;
int32_t* x2700 = x34;
int32_t x2699 = x2697 & 4194303;
int32_t x2701 = x2700[x2699];
int32_t x2702 = x2701;
bool x2703 = true;
for (;;) {
bool x2704 = x2703;
bool x2708;
if (x2704) {
int32_t x2705 = x2702;
bool x2706 = x2705 != -1;
x2708 = x2706;
} else {
x2708 = false;
}
if (!x2708) break;
int32_t x2710 = x2702;
bool x2711 = true;
int32_t* x2712 = x22;
int32_t x2713 = x2712[x2710];
bool x2714 = x2687 == x2713;
if (x2714) {
} else {
x2711 = false;
}
int32_t* x2718 = x26;
int32_t x2719 = x2718[x2710];
bool x2720 = x2690 == x2719;
if (x2720) {
} else {
x2711 = false;
}
bool x2724 = x2711;
if (x2724) {
x2691 = true;
x2703 = false;
} else {
}
int32_t* x2729 = x31;
int32_t x2730 = x2729[x2710];
x2702 = x2730;
}
bool x2734 = x2691;
if (x2734) {
} else {
bool x2736 = true;
int32_t x2737 = 0;
x2737 = x2693;
x2737 = x2697;
int32_t* x2741 = x92;
int32_t x2740 = x2697 & 16383;
int32_t x2742 = x2741[x2740];
int32_t x2743 = x2742;
bool x2744 = true;
for (;;) {
bool x2745 = x2744;
bool x2749;
if (x2745) {
int32_t x2746 = x2743;
bool x2747 = x2746 != -1;
x2749 = x2747;
} else {
x2749 = false;
}
if (!x2749) break;
int32_t x2751 = x2743;
bool x2752 = true;
int32_t* x2753 = x76;
int32_t x2754 = x2753[x2751];
bool x2755 = x2687 == x2754;
if (x2755) {
} else {
x2752 = false;
}
int32_t* x2759 = x80;
int32_t x2760 = x2759[x2751];
bool x2761 = x2690 == x2760;
if (x2761) {
} else {
x2752 = false;
}
bool x2765 = x2752;
if (x2765) {
bool x2766 = true;
if (x2755) {
} else {
x2766 = false;
}
if (x2761) {
} else {
x2766 = false;
}
bool x2773 = x2766;
if (x2773) {
x2736 = false;
} else {
}
bool x2777 = x2736;
x2744 = x2777;
} else {
}
int32_t* x2781 = x85;
int32_t x2782 = x2781[x2751];
x2743 = x2782;
}
bool x2786 = x2736;
if (x2786) {
int32_t x2789 = x82;
int32_t x2790 = x73;
bool x2791 = x2789 == x2790;
if (x2791) {
x73 *= 4;
int32_t x2793 = x73;
printf("buffer.resize %d\n",x2793);
} else {
}
int32_t* x2797 = x76;
x2797[x2789] = x2687;
int32_t* x2799 = x80;
x2799[x2789] = x2690;
x82 += 1;
int32_t x2802 = x2789;
int32_t x2803 = 0;
x2803 = x2693;
x2803 = x2697;
int32_t x2806 = x2742;
x2741[x2740] = x2789;
int32_t* x2808 = x85;
x2808[x2789] = x2742;
int32_t x2810 = 0;
x2810 = x2693;
int32_t* x2813 = x94;
int32_t x2812 = x2693 & 16383;
int32_t x2814 = x2813[x2812];
int32_t x2815 = x2814;
x2813[x2812] = x2789;
int32_t* x2817 = x89;
x2817[x2789] = x2814;
} else {
}
}
} else {
}
int32_t* x2825 = x56;
int32_t x2826 = x2825[x2677];
x2673 = x2826;
}
} else {
}

}
} else {
}
int32_t x2836 = x82;
bool x2837 = x2836 == 0;
if (x2837) {
x2559 = false;
} else {
for(int x2841=0; x2841 < x2836; x2841++) {
int32_t* x2842 = x76;
int32_t* x2844 = x80;
bool x2846 = true;
int32_t x2847 = 0;
int32_t x2843 = x2842[x2841];
int32_t x2848 = x2843 + 233;
x2847 = x2848;
int32_t x2845 = x2844[x2841];
int32_t x2850 = x2848 * 1009;
int32_t x2851 = x2850 + x2845;
int32_t x2852 = x2851 + 233;
x2847 = x2852;
int32_t* x2855 = x34;
int32_t x2854 = x2852 & 4194303;
int32_t x2856 = x2855[x2854];
int32_t x2857 = x2856;
bool x2858 = true;
for (;;) {
bool x2859 = x2858;
bool x2863;
if (x2859) {
int32_t x2860 = x2857;
bool x2861 = x2860 != -1;
x2863 = x2861;
} else {
x2863 = false;
}
if (!x2863) break;
int32_t x2865 = x2857;
bool x2866 = true;
int32_t* x2867 = x22;
int32_t x2868 = x2867[x2865];
bool x2869 = x2843 == x2868;
if (x2869) {
} else {
x2866 = false;
}
int32_t* x2873 = x26;
int32_t x2874 = x2873[x2865];
bool x2875 = x2845 == x2874;
if (x2875) {
} else {
x2866 = false;
}
bool x2879 = x2866;
if (x2879) {
bool x2880 = true;
if (x2869) {
} else {
x2880 = false;
}
if (x2875) {
} else {
x2880 = false;
}
bool x2887 = x2880;
if (x2887) {
x2846 = false;
} else {
}
bool x2891 = x2846;
x2858 = x2891;
} else {
}
int32_t* x2895 = x31;
int32_t x2896 = x2895[x2865];
x2857 = x2896;
}
bool x2900 = x2846;
if (x2900) {
int32_t x2903 = x28;
int32_t x2904 = x19;
bool x2905 = x2903 == x2904;
if (x2905) {
x19 *= 4;
int32_t x2907 = x19;
printf("buffer.resize %d\n",x2907);
} else {
}
int32_t* x2911 = x22;
x2911[x2903] = x2843;
int32_t* x2913 = x26;
x2913[x2903] = x2845;
x28 += 1;
int32_t x2916 = x2903;
int32_t x2917 = 0;
x2917 = x2848;
x2917 = x2852;
int32_t x2920 = x2856;
x2855[x2854] = x2903;
int32_t* x2922 = x31;
x2922[x2903] = x2856;
} else {
}

}
SWAP(x49,x82);
SWAP(x40,x73);
SWAP(x44,x77);
SWAP(x41,x74);
SWAP(x43,x76);
SWAP(x48,x81);
SWAP(x45,x78);
SWAP(x47,x80);
SWAP(x53,x86);
SWAP(x50,x83);
SWAP(x52,x85);
SWAP(x57,x90);
SWAP(x54,x87);
SWAP(x56,x89);
SWAP(x59,x92);
SWAP(x61,x94);
x82 = 0;
x86 = 0;
x90 = 0;
for(int x2947=0; x2947 < 16384; x2947++) {
int32_t* x2948 = x92;
x2948[x2947] = -1;

}
for(int x2952=0; x2952 < 16384; x2952++) {
int32_t* x2953 = x94;
x2953[x2952] = -1;

}
}
}
for(int x2961=0; x2961 < 16384; x2961++) {
int32_t* x2962 = x59;
x2962[x2961] = -1;

}
for(int x2966=0; x2966 < 16384; x2966++) {
int32_t* x2967 = x61;
x2967[x2966] = -1;

}
for(int x2971=0; x2971 < 16384; x2971++) {
int32_t* x2972 = x92;
x2972[x2971] = -1;

}
for(int x2976=0; x2976 < 16384; x2976++) {
int32_t* x2977 = x94;
x2977[x2976] = -1;

}
int32_t x2982 = x28;
FILE *x2981 = fopen("indices.out","w");
for(int x2984=0; x2984 < x2982; x2984++) {
int32_t* x2985 = x22;
int32_t x2986 = x2985[x2984];
int32_t x2987 = fprintf(x2981,"%d",x2986);
int32_t x2988 = fprintf(x2981,"\t");
int32_t* x2989 = x26;
int32_t x2990 = x2989[x2984];
int32_t x2991 = fprintf(x2981,"%d",x2990);
int32_t x2992 = fprintf(x2981,"\n");

}
fclose(x2981);
for(int x2996=0; x2996 < 4194304; x2996++) {
int32_t* x2997 = x224;
x2997[x2996] = -1;

}
for(int x3001=0; x3001 < 4194304; x3001++) {
int32_t* x3002 = x226;
x3002[x3001] = -1;

}
for(int x3006=0; x3006 < 4194304; x3006++) {
int32_t* x3007 = x228;
x3007[x3006] = -1;

}
for(int x3011=0; x3011 < 4194304; x3011++) {
int32_t* x3012 = x295;
x3012[x3011] = -1;

}
for(int x3016=0; x3016 < 4194304; x3016++) {
int32_t* x3017 = x297;
x3017[x3016] = -1;

}
for(int x3021=0; x3021 < 4194304; x3021++) {
int32_t* x3022 = x124;
x3022[x3021] = -1;

}
for(int x3026=0; x3026 < 4194304; x3026++) {
int32_t* x3027 = x126;
x3027[x3026] = -1;

}
for(int x3031=0; x3031 < 4194304; x3031++) {
int32_t* x3032 = x12;
x3032[x3031] = -1;

}
bool x3036 = x2982 == 0;
if (x3036) {
} else {
for(int x3038=0; x3038 < x2982; x3038++) {
int32_t* x3039 = x22;
int32_t* x3041 = x26;
bool x3044 = false;
int32_t x3045 = 0;
int32_t x3040 = x3039[x3038];
int32_t x3046 = x3040 + 233;
x3045 = x3046;
int32_t x3042 = x3041[x3038];
int32_t x3043 = x3042 + 1;
int32_t x3048 = x3046 * 1009;
int32_t x3049 = x3048 + x3043;
int32_t x3050 = x3049 + 233;
x3045 = x3050;
int32_t* x3053 = x34;
int32_t x3052 = x3050 & 4194303;
int32_t x3054 = x3053[x3052];
int32_t x3055 = x3054;
bool x3056 = true;
for (;;) {
bool x3057 = x3056;
bool x3061;
if (x3057) {
int32_t x3058 = x3055;
bool x3059 = x3058 != -1;
x3061 = x3059;
} else {
x3061 = false;
}
if (!x3061) break;
int32_t x3063 = x3055;
bool x3064 = true;
int32_t* x3065 = x22;
int32_t x3066 = x3065[x3063];
bool x3067 = x3040 == x3066;
if (x3067) {
} else {
x3064 = false;
}
int32_t* x3071 = x26;
int32_t x3072 = x3071[x3063];
bool x3073 = x3043 == x3072;
if (x3073) {
} else {
x3064 = false;
}
bool x3077 = x3064;
if (x3077) {
x3044 = true;
x3056 = false;
} else {
}
int32_t* x3082 = x31;
int32_t x3083 = x3082[x3063];
x3055 = x3083;
}
bool x3087 = x3044;
if (x3087) {
} else {
bool x3089 = true;
int32_t x3090 = 0;
x3090 = x3046;
int32_t x3092 = x3048 + x3042;
int32_t x3093 = x3092 + 233;
x3090 = x3093;
int32_t* x3096 = x355;
int32_t x3095 = x3093 & 4194303;
int32_t x3097 = x3096[x3095];
int32_t x3098 = x3097;
bool x3099 = true;
for (;;) {
bool x3100 = x3099;
bool x3104;
if (x3100) {
int32_t x3101 = x3098;
bool x3102 = x3101 != -1;
x3104 = x3102;
} else {
x3104 = false;
}
if (!x3104) break;
int32_t x3106 = x3098;
bool x3107 = true;
int32_t* x3108 = x343;
int32_t x3109 = x3108[x3106];
bool x3110 = x3040 == x3109;
if (x3110) {
} else {
x3107 = false;
}
int32_t* x3114 = x347;
int32_t x3115 = x3114[x3106];
bool x3116 = x3042 == x3115;
if (x3116) {
} else {
x3107 = false;
}
bool x3120 = x3107;
if (x3120) {
bool x3121 = true;
if (x3110) {
} else {
x3121 = false;
}
if (x3116) {
} else {
x3121 = false;
}
bool x3128 = x3121;
if (x3128) {
x3089 = false;
} else {
}
bool x3132 = x3089;
x3099 = x3132;
} else {
}
int32_t* x3136 = x352;
int32_t x3137 = x3136[x3106];
x3098 = x3137;
}
bool x3141 = x3089;
if (x3141) {
int32_t x3144 = x349;
int32_t x3145 = x340;
bool x3146 = x3144 == x3145;
if (x3146) {
x340 *= 4;
int32_t x3148 = x340;
printf("buffer.resize %d\n",x3148);
} else {
}
int32_t* x3152 = x343;
x3152[x3144] = x3040;
int32_t* x3154 = x347;
x3154[x3144] = x3042;
x349 += 1;
int32_t x3157 = x3144;
int32_t x3158 = 0;
x3158 = x3046;
x3158 = x3093;
int32_t x3161 = x3097;
x3096[x3095] = x3144;
int32_t* x3163 = x352;
x3163[x3144] = x3097;
} else {
}
}

}
}
int32_t x3174 = x349;
FILE *x3173 = fopen("index.out","w");
for(int x3176=0; x3176 < x3174; x3176++) {
int32_t* x3177 = x343;
int32_t x3178 = x3177[x3176];
int32_t x3179 = fprintf(x3173,"%d",x3178);
int32_t x3180 = fprintf(x3173,"\t");
int32_t* x3181 = x347;
int32_t x3182 = x3181[x3176];
int32_t x3183 = fprintf(x3173,"%d",x3182);
int32_t x3184 = fprintf(x3173,"\n");

}
fclose(x3173);
for(int x3188=0; x3188 < 4194304; x3188++) {
int32_t* x3189 = x34;
x3189[x3188] = -1;

}
}
/*****************************************
  End of C Generated Code                  
*******************************************/

