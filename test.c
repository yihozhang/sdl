
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
int32_t x1 = 262144;
int32_t x2 = 262144;
char** x3 = (char**)malloc(262144 * sizeof(char*));
int32_t x4 = 0;
int32_t x5 = 262144;
char** x6 = (char**)malloc(262144 * sizeof(char*));
int32_t x7 = 0;
int32_t x8 = 0;
int32_t x9 = 262144;
int32_t* x10 = (int32_t*)malloc(262144 * sizeof(int32_t));
int32_t x11 = 0;
int32_t* x12 = (int32_t*)malloc(65536 * sizeof(int32_t));
for(int x14=0; x14 < 65536; x14++) {
x12[x14] = -1;

}
int32_t x18 = 262144;
int32_t x19 = 262144;
char** x20 = (char**)malloc(262144 * sizeof(char*));
int32_t x21 = 0;
int32_t x22 = 262144;
char** x23 = (char**)malloc(262144 * sizeof(char*));
int32_t x24 = 0;
int32_t x25 = 0;
int32_t x26 = 262144;
int32_t* x27 = (int32_t*)malloc(262144 * sizeof(int32_t));
int32_t x28 = 0;
int32_t* x29 = (int32_t*)malloc(65536 * sizeof(int32_t));
for(int x30=0; x30 < 65536; x30++) {
x29[x30] = -1;

}
int32_t x34 = 262144;
int32_t x35 = 262144;
char** x36 = (char**)malloc(262144 * sizeof(char*));
int32_t x37 = 0;
int32_t x38 = 0;
int32_t x39 = 262144;
int32_t* x40 = (int32_t*)malloc(262144 * sizeof(int32_t));
int32_t x41 = 0;
int32_t* x42 = (int32_t*)malloc(65536 * sizeof(int32_t));
for(int x43=0; x43 < 65536; x43++) {
x42[x43] = -1;

}
int32_t x47 = 262144;
int32_t x48 = 262144;
char** x49 = (char**)malloc(262144 * sizeof(char*));
int32_t x50 = 0;
int32_t x51 = 0;
int32_t x52 = 262144;
int32_t* x53 = (int32_t*)malloc(262144 * sizeof(int32_t));
int32_t x54 = 0;
int32_t* x55 = (int32_t*)malloc(65536 * sizeof(int32_t));
for(int x56=0; x56 < 65536; x56++) {
x55[x56] = -1;

}
int32_t x60 = 262144;
int32_t x61 = 262144;
char** x62 = (char**)malloc(262144 * sizeof(char*));
int32_t x63 = 0;
int32_t x64 = 0;
int32_t x65 = 262144;
int32_t* x66 = (int32_t*)malloc(262144 * sizeof(int32_t));
int32_t x67 = 0;
int32_t* x68 = (int32_t*)malloc(65536 * sizeof(int32_t));
for(int x69=0; x69 < 65536; x69++) {
x68[x69] = -1;

}
int32_t x73 = 262144;
int32_t x74 = 262144;
char** x75 = (char**)malloc(262144 * sizeof(char*));
int32_t x76 = 0;
int32_t x77 = 262144;
char** x78 = (char**)malloc(262144 * sizeof(char*));
int32_t x79 = 0;
int32_t x80 = 0;
int32_t x81 = 262144;
int32_t* x82 = (int32_t*)malloc(262144 * sizeof(int32_t));
int32_t x83 = 0;
int32_t x84 = 262144;
int32_t* x85 = (int32_t*)malloc(262144 * sizeof(int32_t));
int32_t x86 = 0;
int32_t* x87 = (int32_t*)malloc(65536 * sizeof(int32_t));
int32_t* x88 = (int32_t*)malloc(65536 * sizeof(int32_t));
for(int x89=0; x89 < 65536; x89++) {
x87[x89] = -1;

}
for(int x93=0; x93 < 65536; x93++) {
x88[x93] = -1;

}
int32_t x97 = 262144;
int32_t x98 = 262144;
char** x99 = (char**)malloc(262144 * sizeof(char*));
int32_t x100 = 0;
int32_t x101 = 262144;
char** x102 = (char**)malloc(262144 * sizeof(char*));
int32_t x103 = 0;
int32_t x104 = 0;
int32_t x105 = 262144;
int32_t* x106 = (int32_t*)malloc(262144 * sizeof(int32_t));
int32_t x107 = 0;
int32_t x108 = 262144;
int32_t* x109 = (int32_t*)malloc(262144 * sizeof(int32_t));
int32_t x110 = 0;
int32_t* x111 = (int32_t*)malloc(65536 * sizeof(int32_t));
int32_t* x112 = (int32_t*)malloc(65536 * sizeof(int32_t));
for(int x113=0; x113 < 65536; x113++) {
x111[x113] = -1;

}
for(int x117=0; x117 < 65536; x117++) {
x112[x117] = -1;

}
int32_t x121 = 262144;
int32_t x122 = 262144;
char** x123 = (char**)malloc(262144 * sizeof(char*));
int32_t x124 = 0;
int32_t x125 = 262144;
char** x126 = (char**)malloc(262144 * sizeof(char*));
int32_t x127 = 0;
int32_t x128 = 0;
int32_t x129 = 262144;
int32_t* x130 = (int32_t*)malloc(262144 * sizeof(int32_t));
int32_t x131 = 0;
int32_t x132 = 262144;
int32_t* x133 = (int32_t*)malloc(262144 * sizeof(int32_t));
int32_t x134 = 0;
int32_t* x135 = (int32_t*)malloc(65536 * sizeof(int32_t));
int32_t* x136 = (int32_t*)malloc(65536 * sizeof(int32_t));
for(int x137=0; x137 < 65536; x137++) {
x135[x137] = -1;

}
for(int x141=0; x141 < 65536; x141++) {
x136[x141] = -1;

}
int32_t x145 = 262144;
int32_t x146 = 262144;
char** x147 = (char**)malloc(262144 * sizeof(char*));
int32_t x148 = 0;
int32_t x149 = 262144;
char** x150 = (char**)malloc(262144 * sizeof(char*));
int32_t x151 = 0;
int32_t x152 = 0;
int32_t x153 = 262144;
int32_t* x154 = (int32_t*)malloc(262144 * sizeof(int32_t));
int32_t x155 = 0;
int32_t x156 = 262144;
int32_t* x157 = (int32_t*)malloc(262144 * sizeof(int32_t));
int32_t x158 = 0;
int32_t* x159 = (int32_t*)malloc(65536 * sizeof(int32_t));
int32_t* x160 = (int32_t*)malloc(65536 * sizeof(int32_t));
for(int x161=0; x161 < 65536; x161++) {
x159[x161] = -1;

}
for(int x165=0; x165 < 65536; x165++) {
x160[x165] = -1;

}
int32_t x169 = 262144;
int32_t x170 = 262144;
char** x171 = (char**)malloc(262144 * sizeof(char*));
int32_t x172 = 0;
int32_t x173 = 262144;
char** x174 = (char**)malloc(262144 * sizeof(char*));
int32_t x175 = 0;
int32_t x176 = 0;
int32_t x177 = 262144;
int32_t* x178 = (int32_t*)malloc(262144 * sizeof(int32_t));
int32_t x179 = 0;
int32_t x180 = 262144;
int32_t* x181 = (int32_t*)malloc(262144 * sizeof(int32_t));
int32_t x182 = 0;
int32_t x183 = 262144;
int32_t* x184 = (int32_t*)malloc(262144 * sizeof(int32_t));
int32_t x185 = 0;
int32_t* x186 = (int32_t*)malloc(65536 * sizeof(int32_t));
int32_t* x187 = (int32_t*)malloc(65536 * sizeof(int32_t));
int32_t* x188 = (int32_t*)malloc(65536 * sizeof(int32_t));
for(int x189=0; x189 < 65536; x189++) {
x186[x189] = -1;

}
for(int x193=0; x193 < 65536; x193++) {
x187[x193] = -1;

}
for(int x197=0; x197 < 65536; x197++) {
x188[x197] = -1;

}
int32_t x201 = 262144;
int32_t x202 = 262144;
char** x203 = (char**)malloc(262144 * sizeof(char*));
int32_t x204 = 0;
int32_t x205 = 262144;
char** x206 = (char**)malloc(262144 * sizeof(char*));
int32_t x207 = 0;
int32_t x208 = 0;
int32_t x209 = 262144;
int32_t* x210 = (int32_t*)malloc(262144 * sizeof(int32_t));
int32_t x211 = 0;
int32_t* x212 = (int32_t*)malloc(65536 * sizeof(int32_t));
for(int x213=0; x213 < 65536; x213++) {
x212[x213] = -1;

}
int32_t x217 = 262144;
int32_t x218 = 262144;
char** x219 = (char**)malloc(262144 * sizeof(char*));
int32_t x220 = 0;
int32_t x221 = 262144;
char** x222 = (char**)malloc(262144 * sizeof(char*));
int32_t x223 = 0;
int32_t x224 = 0;
int32_t x225 = 262144;
int32_t* x226 = (int32_t*)malloc(262144 * sizeof(int32_t));
int32_t x227 = 0;
int32_t x228 = 262144;
int32_t* x229 = (int32_t*)malloc(262144 * sizeof(int32_t));
int32_t x230 = 0;
int32_t* x231 = (int32_t*)malloc(65536 * sizeof(int32_t));
int32_t* x232 = (int32_t*)malloc(65536 * sizeof(int32_t));
for(int x233=0; x233 < 65536; x233++) {
x231[x233] = -1;

}
for(int x237=0; x237 < 65536; x237++) {
x232[x237] = -1;

}
int32_t x241 = 262144;
int32_t x242 = 262144;
char** x243 = (char**)malloc(262144 * sizeof(char*));
int32_t x244 = 0;
int32_t x245 = 0;
int32_t x246 = 262144;
int32_t* x247 = (int32_t*)malloc(262144 * sizeof(int32_t));
int32_t x248 = 0;
int32_t* x249 = (int32_t*)malloc(65536 * sizeof(int32_t));
for(int x250=0; x250 < 65536; x250++) {
x249[x250] = -1;

}
int32_t x254 = 262144;
int32_t x255 = 262144;
char** x256 = (char**)malloc(262144 * sizeof(char*));
int32_t x257 = 0;
int32_t x258 = 0;
int32_t x259 = 262144;
int32_t* x260 = (int32_t*)malloc(262144 * sizeof(int32_t));
int32_t x261 = 0;
int32_t* x262 = (int32_t*)malloc(65536 * sizeof(int32_t));
for(int x263=0; x263 < 65536; x263++) {
x262[x263] = -1;

}
int32_t x267 = 262144;
int32_t x268 = 262144;
char** x269 = (char**)malloc(262144 * sizeof(char*));
int32_t x270 = 0;
int32_t x271 = 262144;
char** x272 = (char**)malloc(262144 * sizeof(char*));
int32_t x273 = 0;
int32_t x274 = 0;
int32_t x275 = 262144;
int32_t* x276 = (int32_t*)malloc(262144 * sizeof(int32_t));
int32_t x277 = 0;
int32_t* x278 = (int32_t*)malloc(65536 * sizeof(int32_t));
for(int x279=0; x279 < 65536; x279++) {
x278[x279] = -1;

}
int32_t x283 = 262144;
int32_t x284 = 262144;
char** x285 = (char**)malloc(262144 * sizeof(char*));
int32_t x286 = 0;
int32_t x287 = 0;
int32_t x288 = 262144;
int32_t* x289 = (int32_t*)malloc(262144 * sizeof(int32_t));
int32_t x290 = 0;
int32_t* x291 = (int32_t*)malloc(65536 * sizeof(int32_t));
for(int x292=0; x292 < 65536; x292++) {
x291[x292] = -1;

}
int32_t x296 = 262144;
int32_t x297 = 262144;
char** x298 = (char**)malloc(262144 * sizeof(char*));
int32_t x299 = 0;
int32_t x300 = 262144;
char** x301 = (char**)malloc(262144 * sizeof(char*));
int32_t x302 = 0;
int32_t x303 = 0;
int32_t x304 = 262144;
int32_t* x305 = (int32_t*)malloc(262144 * sizeof(int32_t));
int32_t x306 = 0;
int32_t* x307 = (int32_t*)malloc(65536 * sizeof(int32_t));
for(int x308=0; x308 < 65536; x308++) {
x307[x308] = -1;

}
int32_t x312 = 262144;
int32_t x313 = 262144;
char** x314 = (char**)malloc(262144 * sizeof(char*));
int32_t x315 = 0;
int32_t x316 = 262144;
char** x317 = (char**)malloc(262144 * sizeof(char*));
int32_t x318 = 0;
int32_t x319 = 0;
int32_t x320 = 262144;
int32_t* x321 = (int32_t*)malloc(262144 * sizeof(int32_t));
int32_t x322 = 0;
int32_t* x323 = (int32_t*)malloc(65536 * sizeof(int32_t));
for(int x324=0; x324 < 65536; x324++) {
x323[x324] = -1;

}
int32_t x331 = 0;
int32_t x328 = open("DATA/female.facts",0);
int32_t x329 = fsize(x328);
char* x330 = mmap(0, x329, PROT_READ, MAP_FILE | MAP_SHARED, x328, 0);
for (;;) {
int32_t x332 = x331;
bool x333 = x332 < x329;
if (!x333) break;
int32_t x335 = x331;
for (;;) {
int32_t x336 = x331;
char x337 = x330[x336];
bool x338 = x337 != '\n';
if (!x338) break;
x331 += 1;
}
int32_t x343 = x331;
x331 += 1;
int32_t x347 = x38;
int32_t x348 = x34;
bool x349 = x347 == x348;
if (x349) {
x34 *= 4;
int32_t x351 = x34;
printf("buffer.resize %d\n",x351);
} else {
}
char* x346 = x330+x335;
x36[x347] = x346;
x38 += 1;
int32_t x357 = 1;
int64_t x358 = hash(x346, 10L);
x357 *= x358;
int32_t x360 = x357;
int32_t x361 = x360 & 65535;
int32_t x362 = x42[x361];
int32_t x363 = x362;
x42[x361] = x347;
x40[x347] = x362;
}
int32_t x371 = 0;
int32_t x368 = open("DATA/parent_child.facts",0);
int32_t x369 = fsize(x368);
char* x370 = mmap(0, x369, PROT_READ, MAP_FILE | MAP_SHARED, x368, 0);
for (;;) {
int32_t x372 = x371;
bool x373 = x372 < x369;
if (!x373) break;
int32_t x375 = x371;
for (;;) {
int32_t x376 = x371;
char x377 = x370[x376];
bool x378 = x377 != '\t';
if (!x378) break;
x371 += 1;
}
int32_t x383 = x371;
x371 += 1;
int32_t x387 = x371;
for (;;) {
int32_t x388 = x371;
char x389 = x370[x388];
bool x390 = x389 != '\n';
if (!x390) break;
x371 += 1;
}
int32_t x395 = x371;
x371 += 1;
int32_t x399 = x176;
int32_t x400 = x169;
bool x401 = x399 == x400;
if (x401) {
x169 *= 4;
int32_t x403 = x169;
printf("buffer.resize %d\n",x403);
} else {
}
char* x386 = x370+x375;
x171[x399] = x386;
char* x398 = x370+x387;
x174[x399] = x398;
x176 += 1;
int32_t x410 = 1;
int64_t x411 = hash(x386, 10L);
x410 *= x411;
int64_t x413 = hash(x398, 10L);
x410 *= x413;
int32_t x415 = x410;
int32_t x416 = x415 & 65535;
int32_t x417 = x186[x416];
int32_t x418 = x417;
x186[x416] = x399;
x178[x399] = x417;
int32_t x421 = 1;
int64_t x422 = hash(x398, 10L);
x421 *= x422;
int32_t x424 = x421;
int32_t x425 = x424 & 65535;
int32_t x426 = x187[x425];
int32_t x427 = x426;
x187[x425] = x399;
x181[x399] = x426;
int32_t x430 = 1;
int64_t x431 = hash(x386, 10L);
x430 *= x431;
int32_t x433 = x430;
int32_t x434 = x433 & 65535;
int32_t x435 = x188[x434];
int32_t x436 = x435;
x188[x434] = x399;
x184[x399] = x435;
}
int32_t x441 = x176;
bool x442 = x441 == 0;
if (x442) {
} else {
for(int x445=0; x445 < x441; x445++) {
bool x448 = true;
int32_t x449 = 1;
char* x446 = x171[x445];
int64_t x450 = hash(x446, 10L);
x449 *= x450;
char* x447 = x174[x445];
int64_t x452 = hash(x447, 10L);
x449 *= x452;
int32_t x454 = x449;
int32_t x455 = x454 & 65535;
int32_t x456 = x307[x455];
int32_t x457 = x456;
bool x458 = true;
for (;;) {
bool x459 = x458;
bool x463;
if (x459) {
int32_t x460 = x457;
bool x461 = x460 != -1;
x463 = x461;
} else {
x463 = false;
}
if (!x463) break;
int32_t x465 = x457;
int32_t x466 = x305[x465];
x457 = x466;
bool x468 = true;
char* x469 = x298[x465];
bool x470 = tpch_streq(x446,x469);
if (x470) {
} else {
x468 = false;
}
char* x474 = x301[x465];
bool x475 = tpch_streq(x447,x474);
if (x475) {
} else {
x468 = false;
}
bool x479 = x468;
if (x479) {
bool x480 = true;
if (x470) {
} else {
x480 = false;
}
if (x475) {
} else {
x480 = false;
}
bool x487 = x480;
if (x487) {
x448 = false;
} else {
}
bool x491 = x448;
x458 = x491;
} else {
}
}
bool x497 = x448;
if (x497) {
int32_t x500 = x303;
int32_t x501 = x296;
bool x502 = x500 == x501;
if (x502) {
x296 *= 4;
int32_t x504 = x296;
printf("buffer.resize %d\n",x504);
} else {
}
x298[x500] = x446;
x301[x500] = x447;
x303 += 1;
int32_t x511 = 1;
int64_t x512 = hash(x446, 10L);
x511 *= x512;
int64_t x514 = hash(x447, 10L);
x511 *= x514;
int32_t x516 = x511;
int32_t x517 = x516 & 65535;
int32_t x518 = x307[x517];
int32_t x519 = x518;
x307[x517] = x500;
x305[x500] = x518;
} else {
}

}
}
int32_t x528 = x303;
for(int x530=0; x530 < x528; x530++) {
bool x533 = true;
int32_t x534 = 1;
char* x531 = x298[x530];
int64_t x535 = hash(x531, 10L);
x534 *= x535;
char* x532 = x301[x530];
int64_t x537 = hash(x532, 10L);
x534 *= x537;
int32_t x539 = x534;
int32_t x540 = x539 & 65535;
int32_t x541 = x159[x540];
int32_t x542 = x541;
bool x543 = true;
for (;;) {
bool x544 = x543;
bool x548;
if (x544) {
int32_t x545 = x542;
bool x546 = x545 != -1;
x548 = x546;
} else {
x548 = false;
}
if (!x548) break;
int32_t x550 = x542;
int32_t x551 = x154[x550];
x542 = x551;
bool x553 = true;
char* x554 = x147[x550];
bool x555 = tpch_streq(x531,x554);
if (x555) {
} else {
x553 = false;
}
char* x559 = x150[x550];
bool x560 = tpch_streq(x532,x559);
if (x560) {
} else {
x553 = false;
}
bool x564 = x553;
if (x564) {
bool x565 = true;
if (x555) {
} else {
x565 = false;
}
if (x560) {
} else {
x565 = false;
}
bool x572 = x565;
if (x572) {
x533 = false;
} else {
}
bool x576 = x533;
x543 = x576;
} else {
}
}
bool x582 = x533;
if (x582) {
int32_t x585 = x152;
int32_t x586 = x145;
bool x587 = x585 == x586;
if (x587) {
x145 *= 4;
int32_t x589 = x145;
printf("buffer.resize %d\n",x589);
} else {
}
x147[x585] = x531;
x150[x585] = x532;
x152 += 1;
int32_t x596 = 1;
int64_t x597 = hash(x531, 10L);
x596 *= x597;
int64_t x599 = hash(x532, 10L);
x596 *= x599;
int32_t x601 = x596;
int32_t x602 = x601 & 65535;
int32_t x603 = x159[x602];
int32_t x604 = x603;
x159[x602] = x585;
x154[x585] = x603;
int32_t x607 = 1;
int64_t x608 = hash(x531, 10L);
x607 *= x608;
int32_t x610 = x607;
int32_t x611 = x610 & 65535;
int32_t x612 = x160[x611];
int32_t x613 = x612;
x160[x611] = x585;
x157[x585] = x612;
} else {
}

}
bool x620 = true;
for (;;) {
bool x621 = x620;
if (!x621) break;
int32_t x623 = x176;
bool x624 = x623 == 0;
bool x630;
if (x624) {
x630 = false;
} else {
int32_t x626 = x152;
bool x627 = x626 == 0;
bool x628 = !x627;
x630 = x628;
}
if (x630) {
for(int x632=0; x632 < x623; x632++) {
int32_t x634 = 1;
char* x633 = x174[x632];
int64_t x635 = hash(x633, 10L);
x634 *= x635;
int32_t x637 = x634;
int32_t x638 = x637 & 65535;
int32_t x639 = x160[x638];
int32_t x640 = x639;
char* x654 = x171[x632];
for (;;) {
int32_t x641 = x640;
bool x642 = x641 != -1;
if (!x642) break;
int32_t x644 = x640;
int32_t x645 = x157[x644];
x640 = x645;
bool x647 = true;
char* x648 = x147[x644];
bool x649 = tpch_streq(x633,x648);
if (x649) {
} else {
x647 = false;
}
bool x653 = x647;
if (x653) {
bool x656 = true;
int32_t x657 = 1;
int64_t x658 = hash(x654, 10L);
x657 *= x658;
char* x655 = x150[x644];
int64_t x660 = hash(x655, 10L);
x657 *= x660;
int32_t x662 = x657;
int32_t x663 = x662 & 65535;
int32_t x664 = x307[x663];
int32_t x665 = x664;
bool x666 = true;
for (;;) {
bool x667 = x666;
bool x671;
if (x667) {
int32_t x668 = x665;
bool x669 = x668 != -1;
x671 = x669;
} else {
x671 = false;
}
if (!x671) break;
int32_t x673 = x665;
int32_t x674 = x305[x673];
x665 = x674;
bool x676 = true;
char* x677 = x298[x673];
bool x678 = tpch_streq(x654,x677);
if (x678) {
} else {
x676 = false;
}
char* x682 = x301[x673];
bool x683 = tpch_streq(x655,x682);
if (x683) {
} else {
x676 = false;
}
bool x687 = x676;
if (x687) {
bool x688 = true;
if (x678) {
} else {
x688 = false;
}
if (x683) {
} else {
x688 = false;
}
bool x695 = x688;
if (x695) {
x656 = false;
} else {
}
bool x699 = x656;
x666 = x699;
} else {
}
}
bool x705 = x656;
if (x705) {
bool x708 = true;
int32_t x709 = 1;
int64_t x710 = hash(x654, 10L);
x709 *= x710;
int64_t x712 = hash(x655, 10L);
x709 *= x712;
int32_t x714 = x709;
int32_t x715 = x714 & 65535;
int32_t x716 = x231[x715];
int32_t x717 = x716;
bool x718 = true;
for (;;) {
bool x719 = x718;
bool x723;
if (x719) {
int32_t x720 = x717;
bool x721 = x720 != -1;
x723 = x721;
} else {
x723 = false;
}
if (!x723) break;
int32_t x725 = x717;
int32_t x726 = x226[x725];
x717 = x726;
bool x728 = true;
char* x729 = x219[x725];
bool x730 = tpch_streq(x654,x729);
if (x730) {
} else {
x728 = false;
}
char* x734 = x222[x725];
bool x735 = tpch_streq(x655,x734);
if (x735) {
} else {
x728 = false;
}
bool x739 = x728;
if (x739) {
bool x740 = true;
if (x730) {
} else {
x740 = false;
}
if (x735) {
} else {
x740 = false;
}
bool x747 = x740;
if (x747) {
x708 = false;
} else {
}
bool x751 = x708;
x718 = x751;
} else {
}
}
bool x757 = x708;
if (x757) {
int32_t x760 = x224;
int32_t x761 = x217;
bool x762 = x760 == x761;
if (x762) {
x217 *= 4;
int32_t x764 = x217;
printf("buffer.resize %d\n",x764);
} else {
}
x219[x760] = x654;
x222[x760] = x655;
x224 += 1;
int32_t x771 = 1;
int64_t x772 = hash(x654, 10L);
x771 *= x772;
int64_t x774 = hash(x655, 10L);
x771 *= x774;
int32_t x776 = x771;
int32_t x777 = x776 & 65535;
int32_t x778 = x231[x777];
int32_t x779 = x778;
x231[x777] = x760;
x226[x760] = x778;
int32_t x782 = 1;
int64_t x783 = hash(x654, 10L);
x782 *= x783;
int32_t x785 = x782;
int32_t x786 = x785 & 65535;
int32_t x787 = x232[x786];
int32_t x788 = x787;
x232[x786] = x760;
x229[x760] = x787;
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
int32_t x803 = x224;
bool x804 = x803 == 0;
if (x804) {
x620 = false;
} else {
for(int x808=0; x808 < x803; x808++) {
bool x811 = true;
int32_t x812 = 1;
char* x809 = x219[x808];
int64_t x813 = hash(x809, 10L);
x812 *= x813;
char* x810 = x222[x808];
int64_t x815 = hash(x810, 10L);
x812 *= x815;
int32_t x817 = x812;
int32_t x818 = x817 & 65535;
int32_t x819 = x307[x818];
int32_t x820 = x819;
bool x821 = true;
for (;;) {
bool x822 = x821;
bool x826;
if (x822) {
int32_t x823 = x820;
bool x824 = x823 != -1;
x826 = x824;
} else {
x826 = false;
}
if (!x826) break;
int32_t x828 = x820;
int32_t x829 = x305[x828];
x820 = x829;
bool x831 = true;
char* x832 = x298[x828];
bool x833 = tpch_streq(x809,x832);
if (x833) {
} else {
x831 = false;
}
char* x837 = x301[x828];
bool x838 = tpch_streq(x810,x837);
if (x838) {
} else {
x831 = false;
}
bool x842 = x831;
if (x842) {
bool x843 = true;
if (x833) {
} else {
x843 = false;
}
if (x838) {
} else {
x843 = false;
}
bool x850 = x843;
if (x850) {
x811 = false;
} else {
}
bool x854 = x811;
x821 = x854;
} else {
}
}
bool x860 = x811;
if (x860) {
int32_t x863 = x303;
int32_t x864 = x296;
bool x865 = x863 == x864;
if (x865) {
x296 *= 4;
int32_t x867 = x296;
printf("buffer.resize %d\n",x867);
} else {
}
x298[x863] = x809;
x301[x863] = x810;
x303 += 1;
int32_t x874 = 1;
int64_t x875 = hash(x809, 10L);
x874 *= x875;
int64_t x877 = hash(x810, 10L);
x874 *= x877;
int32_t x879 = x874;
int32_t x880 = x879 & 65535;
int32_t x881 = x307[x880];
int32_t x882 = x881;
x307[x880] = x863;
x305[x863] = x881;
} else {
}

}
SWAP(x152,x224);
SWAP(x145,x217);
SWAP(x148,x220);
SWAP(x146,x218);
SWAP(x147,x219);
SWAP(x151,x223);
SWAP(x149,x221);
SWAP(x150,x222);
SWAP(x155,x227);
SWAP(x153,x225);
SWAP(x154,x226);
SWAP(x158,x230);
SWAP(x156,x228);
SWAP(x157,x229);
SWAP(x159,x231);
SWAP(x160,x232);
x224 = 0;
x227 = 0;
x230 = 0;
for(int x908=0; x908 < 65536; x908++) {
x231[x908] = -1;

}
for(int x912=0; x912 < 65536; x912++) {
x232[x912] = -1;

}
}
}
for(int x920=0; x920 < 65536; x920++) {
x159[x920] = -1;

}
for(int x924=0; x924 < 65536; x924++) {
x160[x924] = -1;

}
for(int x928=0; x928 < 65536; x928++) {
x231[x928] = -1;

}
for(int x932=0; x932 < 65536; x932++) {
x232[x932] = -1;

}
int32_t x939 = 0;
int32_t x936 = open("./DATA/person_living.facts",0);
int32_t x937 = fsize(x936);
char* x938 = mmap(0, x937, PROT_READ, MAP_FILE | MAP_SHARED, x936, 0);
for (;;) {
int32_t x940 = x939;
bool x941 = x940 < x937;
if (!x941) break;
int32_t x943 = x939;
for (;;) {
int32_t x944 = x939;
char x945 = x938[x944];
bool x946 = x945 != '\n';
if (!x946) break;
x939 += 1;
}
int32_t x951 = x939;
x939 += 1;
int32_t x955 = x287;
int32_t x956 = x283;
bool x957 = x955 == x956;
if (x957) {
x283 *= 4;
int32_t x959 = x283;
printf("buffer.resize %d\n",x959);
} else {
}
char* x954 = x938+x943;
x285[x955] = x954;
x287 += 1;
int32_t x965 = 1;
int64_t x966 = hash(x954, 10L);
x965 *= x966;
int32_t x968 = x965;
int32_t x969 = x968 & 65535;
int32_t x970 = x291[x969];
int32_t x971 = x970;
x291[x969] = x955;
x289[x955] = x970;
}
int32_t x976 = x287;
bool x977 = x976 == 0;
bool x979;
if (x977) {
x979 = false;
} else {
bool x443 = !x442;
x979 = x443;
}
bool x984;
if (x979) {
int32_t x980 = x38;
bool x981 = x980 == 0;
bool x982 = !x981;
x984 = x982;
} else {
x984 = false;
}
if (x984) {
for(int x986=0; x986 < x976; x986++) {
int32_t x988 = 1;
char* x987 = x285[x986];
int64_t x989 = hash(x987, 10L);
x988 *= x989;
int32_t x991 = x988;
int32_t x992 = x991 & 65535;
int32_t x993 = x187[x992];
int32_t x994 = x993;
for (;;) {
int32_t x995 = x994;
bool x996 = x995 != -1;
if (!x996) break;
int32_t x998 = x994;
int32_t x999 = x181[x998];
x994 = x999;
bool x1001 = true;
char* x1002 = x174[x998];
bool x1003 = tpch_streq(x987,x1002);
if (x1003) {
} else {
x1001 = false;
}
bool x1007 = x1001;
if (x1007) {
bool x1009 = true;
int32_t x1010 = 1;
char* x1008 = x171[x998];
int64_t x1011 = hash(x1008, 10L);
x1010 *= x1011;
int32_t x1013 = x1010;
int32_t x1014 = x1013 & 65535;
int32_t x1015 = x42[x1014];
int32_t x1016 = x1015;
bool x1017 = true;
for (;;) {
bool x1018 = x1017;
bool x1022;
if (x1018) {
int32_t x1019 = x1016;
bool x1020 = x1019 != -1;
x1022 = x1020;
} else {
x1022 = false;
}
if (!x1022) break;
int32_t x1024 = x1016;
int32_t x1025 = x40[x1024];
x1016 = x1025;
bool x1027 = true;
char* x1028 = x36[x1024];
bool x1029 = tpch_streq(x1008,x1028);
if (x1029) {
} else {
x1027 = false;
}
bool x1033 = x1027;
if (x1033) {
bool x1034 = true;
if (x1029) {
} else {
x1034 = false;
}
bool x1038 = x1034;
if (x1038) {
x1009 = false;
} else {
}
bool x1042 = x1009;
x1017 = x1042;
} else {
}
}
bool x1048 = x1009;
if (x1048) {
} else {
bool x1050 = true;
int32_t x1051 = 1;
int64_t x1052 = hash(x987, 10L);
x1051 *= x1052;
int64_t x1054 = hash(x1008, 10L);
x1051 *= x1054;
int32_t x1056 = x1051;
int32_t x1057 = x1056 & 65535;
int32_t x1058 = x12[x1057];
int32_t x1059 = x1058;
bool x1060 = true;
for (;;) {
bool x1061 = x1060;
bool x1065;
if (x1061) {
int32_t x1062 = x1059;
bool x1063 = x1062 != -1;
x1065 = x1063;
} else {
x1065 = false;
}
if (!x1065) break;
int32_t x1067 = x1059;
int32_t x1068 = x10[x1067];
x1059 = x1068;
bool x1070 = true;
char* x1071 = x3[x1067];
bool x1072 = tpch_streq(x987,x1071);
if (x1072) {
} else {
x1070 = false;
}
char* x1076 = x6[x1067];
bool x1077 = tpch_streq(x1008,x1076);
if (x1077) {
} else {
x1070 = false;
}
bool x1081 = x1070;
if (x1081) {
bool x1082 = true;
if (x1072) {
} else {
x1082 = false;
}
if (x1077) {
} else {
x1082 = false;
}
bool x1089 = x1082;
if (x1089) {
x1050 = false;
} else {
}
bool x1093 = x1050;
x1060 = x1093;
} else {
}
}
bool x1099 = x1050;
if (x1099) {
int32_t x1102 = x8;
int32_t x1103 = x1;
bool x1104 = x1102 == x1103;
if (x1104) {
x1 *= 4;
int32_t x1106 = x1;
printf("buffer.resize %d\n",x1106);
} else {
}
x3[x1102] = x987;
x6[x1102] = x1008;
x8 += 1;
int32_t x1113 = 1;
int64_t x1114 = hash(x987, 10L);
x1113 *= x1114;
int64_t x1116 = hash(x1008, 10L);
x1113 *= x1116;
int32_t x1118 = x1113;
int32_t x1119 = x1118 & 65535;
int32_t x1120 = x12[x1119];
int32_t x1121 = x1120;
x12[x1119] = x1102;
x10[x1102] = x1120;
} else {
}
}
} else {
}
}

}
} else {
}
int32_t x1136 = x8;
for(int x1138=0; x1138 < x1136; x1138++) {
bool x1141 = true;
int32_t x1142 = 1;
char* x1139 = x3[x1138];
int64_t x1143 = hash(x1139, 10L);
x1142 *= x1143;
char* x1140 = x6[x1138];
int64_t x1145 = hash(x1140, 10L);
x1142 *= x1145;
int32_t x1147 = x1142;
int32_t x1148 = x1147 & 65535;
int32_t x1149 = x111[x1148];
int32_t x1150 = x1149;
bool x1151 = true;
for (;;) {
bool x1152 = x1151;
bool x1156;
if (x1152) {
int32_t x1153 = x1150;
bool x1154 = x1153 != -1;
x1156 = x1154;
} else {
x1156 = false;
}
if (!x1156) break;
int32_t x1158 = x1150;
int32_t x1159 = x106[x1158];
x1150 = x1159;
bool x1161 = true;
char* x1162 = x99[x1158];
bool x1163 = tpch_streq(x1139,x1162);
if (x1163) {
} else {
x1161 = false;
}
char* x1167 = x102[x1158];
bool x1168 = tpch_streq(x1140,x1167);
if (x1168) {
} else {
x1161 = false;
}
bool x1172 = x1161;
if (x1172) {
bool x1173 = true;
if (x1163) {
} else {
x1173 = false;
}
if (x1168) {
} else {
x1173 = false;
}
bool x1180 = x1173;
if (x1180) {
x1141 = false;
} else {
}
bool x1184 = x1141;
x1151 = x1184;
} else {
}
}
bool x1190 = x1141;
if (x1190) {
int32_t x1193 = x104;
int32_t x1194 = x97;
bool x1195 = x1193 == x1194;
if (x1195) {
x97 *= 4;
int32_t x1197 = x97;
printf("buffer.resize %d\n",x1197);
} else {
}
x99[x1193] = x1139;
x102[x1193] = x1140;
x104 += 1;
int32_t x1204 = 1;
int64_t x1205 = hash(x1139, 10L);
x1204 *= x1205;
int64_t x1207 = hash(x1140, 10L);
x1204 *= x1207;
int32_t x1209 = x1204;
int32_t x1210 = x1209 & 65535;
int32_t x1211 = x111[x1210];
int32_t x1212 = x1211;
x111[x1210] = x1193;
x106[x1193] = x1211;
int32_t x1215 = 1;
int64_t x1216 = hash(x1140, 10L);
x1215 *= x1216;
int32_t x1218 = x1215;
int32_t x1219 = x1218 & 65535;
int32_t x1220 = x112[x1219];
int32_t x1221 = x1220;
x112[x1219] = x1193;
x109[x1193] = x1220;
} else {
}

}
bool x1228 = true;
for (;;) {
bool x1229 = x1228;
if (!x1229) break;
int32_t x1231 = x176;
bool x1232 = x1231 == 0;
bool x1238;
if (x1232) {
x1238 = false;
} else {
int32_t x1234 = x38;
bool x1235 = x1234 == 0;
bool x1236 = !x1235;
x1238 = x1236;
}
bool x1243;
if (x1238) {
int32_t x1239 = x104;
bool x1240 = x1239 == 0;
bool x1241 = !x1240;
x1243 = x1241;
} else {
x1243 = false;
}
if (x1243) {
for(int x1245=0; x1245 < x1231; x1245++) {
bool x1247 = true;
int32_t x1248 = 1;
char* x1246 = x171[x1245];
int64_t x1249 = hash(x1246, 10L);
x1248 *= x1249;
int32_t x1251 = x1248;
int32_t x1252 = x1251 & 65535;
int32_t x1253 = x42[x1252];
int32_t x1254 = x1253;
bool x1255 = true;
for (;;) {
bool x1256 = x1255;
bool x1260;
if (x1256) {
int32_t x1257 = x1254;
bool x1258 = x1257 != -1;
x1260 = x1258;
} else {
x1260 = false;
}
if (!x1260) break;
int32_t x1262 = x1254;
int32_t x1263 = x40[x1262];
x1254 = x1263;
bool x1265 = true;
char* x1266 = x36[x1262];
bool x1267 = tpch_streq(x1246,x1266);
if (x1267) {
} else {
x1265 = false;
}
bool x1271 = x1265;
if (x1271) {
bool x1272 = true;
if (x1267) {
} else {
x1272 = false;
}
bool x1276 = x1272;
if (x1276) {
x1247 = false;
} else {
}
bool x1280 = x1247;
x1255 = x1280;
} else {
}
}
bool x1286 = x1247;
if (x1286) {
} else {
int32_t x1289 = 1;
char* x1288 = x174[x1245];
int64_t x1290 = hash(x1288, 10L);
x1289 *= x1290;
int32_t x1292 = x1289;
int32_t x1293 = x1292 & 65535;
int32_t x1294 = x112[x1293];
int32_t x1295 = x1294;
for (;;) {
int32_t x1296 = x1295;
bool x1297 = x1296 != -1;
if (!x1297) break;
int32_t x1299 = x1295;
int32_t x1300 = x109[x1299];
x1295 = x1300;
bool x1302 = true;
char* x1303 = x102[x1299];
bool x1304 = tpch_streq(x1288,x1303);
if (x1304) {
} else {
x1302 = false;
}
bool x1308 = x1302;
if (x1308) {
bool x1310 = true;
int32_t x1311 = 1;
char* x1309 = x99[x1299];
int64_t x1312 = hash(x1309, 10L);
x1311 *= x1312;
int64_t x1314 = hash(x1246, 10L);
x1311 *= x1314;
int32_t x1316 = x1311;
int32_t x1317 = x1316 & 65535;
int32_t x1318 = x12[x1317];
int32_t x1319 = x1318;
bool x1320 = true;
for (;;) {
bool x1321 = x1320;
bool x1325;
if (x1321) {
int32_t x1322 = x1319;
bool x1323 = x1322 != -1;
x1325 = x1323;
} else {
x1325 = false;
}
if (!x1325) break;
int32_t x1327 = x1319;
int32_t x1328 = x10[x1327];
x1319 = x1328;
bool x1330 = true;
char* x1331 = x3[x1327];
bool x1332 = tpch_streq(x1309,x1331);
if (x1332) {
} else {
x1330 = false;
}
char* x1336 = x6[x1327];
bool x1337 = tpch_streq(x1246,x1336);
if (x1337) {
} else {
x1330 = false;
}
bool x1341 = x1330;
if (x1341) {
bool x1342 = true;
if (x1332) {
} else {
x1342 = false;
}
if (x1337) {
} else {
x1342 = false;
}
bool x1349 = x1342;
if (x1349) {
x1310 = false;
} else {
}
bool x1353 = x1310;
x1320 = x1353;
} else {
}
}
bool x1359 = x1310;
if (x1359) {
bool x1362 = true;
int32_t x1363 = 1;
int64_t x1364 = hash(x1309, 10L);
x1363 *= x1364;
int64_t x1366 = hash(x1246, 10L);
x1363 *= x1366;
int32_t x1368 = x1363;
int32_t x1369 = x1368 & 65535;
int32_t x1370 = x87[x1369];
int32_t x1371 = x1370;
bool x1372 = true;
for (;;) {
bool x1373 = x1372;
bool x1377;
if (x1373) {
int32_t x1374 = x1371;
bool x1375 = x1374 != -1;
x1377 = x1375;
} else {
x1377 = false;
}
if (!x1377) break;
int32_t x1379 = x1371;
int32_t x1380 = x82[x1379];
x1371 = x1380;
bool x1382 = true;
char* x1383 = x75[x1379];
bool x1384 = tpch_streq(x1309,x1383);
if (x1384) {
} else {
x1382 = false;
}
char* x1388 = x78[x1379];
bool x1389 = tpch_streq(x1246,x1388);
if (x1389) {
} else {
x1382 = false;
}
bool x1393 = x1382;
if (x1393) {
bool x1394 = true;
if (x1384) {
} else {
x1394 = false;
}
if (x1389) {
} else {
x1394 = false;
}
bool x1401 = x1394;
if (x1401) {
x1362 = false;
} else {
}
bool x1405 = x1362;
x1372 = x1405;
} else {
}
}
bool x1411 = x1362;
if (x1411) {
int32_t x1414 = x80;
int32_t x1415 = x73;
bool x1416 = x1414 == x1415;
if (x1416) {
x73 *= 4;
int32_t x1418 = x73;
printf("buffer.resize %d\n",x1418);
} else {
}
x75[x1414] = x1309;
x78[x1414] = x1246;
x80 += 1;
int32_t x1425 = 1;
int64_t x1426 = hash(x1309, 10L);
x1425 *= x1426;
int64_t x1428 = hash(x1246, 10L);
x1425 *= x1428;
int32_t x1430 = x1425;
int32_t x1431 = x1430 & 65535;
int32_t x1432 = x87[x1431];
int32_t x1433 = x1432;
x87[x1431] = x1414;
x82[x1414] = x1432;
int32_t x1436 = 1;
int64_t x1437 = hash(x1246, 10L);
x1436 *= x1437;
int32_t x1439 = x1436;
int32_t x1440 = x1439 & 65535;
int32_t x1441 = x88[x1440];
int32_t x1442 = x1441;
x88[x1440] = x1414;
x85[x1414] = x1441;
} else {
}
} else {
}
} else {
}
}
}

}
} else {
}
int32_t x1459 = x80;
bool x1460 = x1459 == 0;
if (x1460) {
x1228 = false;
} else {
for(int x1464=0; x1464 < x1459; x1464++) {
bool x1467 = true;
int32_t x1468 = 1;
char* x1465 = x75[x1464];
int64_t x1469 = hash(x1465, 10L);
x1468 *= x1469;
char* x1466 = x78[x1464];
int64_t x1471 = hash(x1466, 10L);
x1468 *= x1471;
int32_t x1473 = x1468;
int32_t x1474 = x1473 & 65535;
int32_t x1475 = x12[x1474];
int32_t x1476 = x1475;
bool x1477 = true;
for (;;) {
bool x1478 = x1477;
bool x1482;
if (x1478) {
int32_t x1479 = x1476;
bool x1480 = x1479 != -1;
x1482 = x1480;
} else {
x1482 = false;
}
if (!x1482) break;
int32_t x1484 = x1476;
int32_t x1485 = x10[x1484];
x1476 = x1485;
bool x1487 = true;
char* x1488 = x3[x1484];
bool x1489 = tpch_streq(x1465,x1488);
if (x1489) {
} else {
x1487 = false;
}
char* x1493 = x6[x1484];
bool x1494 = tpch_streq(x1466,x1493);
if (x1494) {
} else {
x1487 = false;
}
bool x1498 = x1487;
if (x1498) {
bool x1499 = true;
if (x1489) {
} else {
x1499 = false;
}
if (x1494) {
} else {
x1499 = false;
}
bool x1506 = x1499;
if (x1506) {
x1467 = false;
} else {
}
bool x1510 = x1467;
x1477 = x1510;
} else {
}
}
bool x1516 = x1467;
if (x1516) {
int32_t x1519 = x8;
int32_t x1520 = x1;
bool x1521 = x1519 == x1520;
if (x1521) {
x1 *= 4;
int32_t x1523 = x1;
printf("buffer.resize %d\n",x1523);
} else {
}
x3[x1519] = x1465;
x6[x1519] = x1466;
x8 += 1;
int32_t x1530 = 1;
int64_t x1531 = hash(x1465, 10L);
x1530 *= x1531;
int64_t x1533 = hash(x1466, 10L);
x1530 *= x1533;
int32_t x1535 = x1530;
int32_t x1536 = x1535 & 65535;
int32_t x1537 = x12[x1536];
int32_t x1538 = x1537;
x12[x1536] = x1519;
x10[x1519] = x1537;
} else {
}

}
SWAP(x104,x80);
SWAP(x97,x73);
SWAP(x100,x76);
SWAP(x98,x74);
SWAP(x99,x75);
SWAP(x103,x79);
SWAP(x101,x77);
SWAP(x102,x78);
SWAP(x107,x83);
SWAP(x105,x81);
SWAP(x106,x82);
SWAP(x110,x86);
SWAP(x108,x84);
SWAP(x109,x85);
SWAP(x111,x87);
SWAP(x112,x88);
x80 = 0;
x83 = 0;
x86 = 0;
for(int x1564=0; x1564 < 65536; x1564++) {
x87[x1564] = -1;

}
for(int x1568=0; x1568 < 65536; x1568++) {
x88[x1568] = -1;

}
}
}
for(int x1576=0; x1576 < 65536; x1576++) {
x111[x1576] = -1;

}
for(int x1580=0; x1580 < 65536; x1580++) {
x112[x1580] = -1;

}
for(int x1584=0; x1584 < 65536; x1584++) {
x87[x1584] = -1;

}
for(int x1588=0; x1588 < 65536; x1588++) {
x88[x1588] = -1;

}
for(int x1592=0; x1592 < 65536; x1592++) {
x42[x1592] = -1;

}
int32_t x1599 = 0;
int32_t x1596 = open("./DATA/person.facts",0);
int32_t x1597 = fsize(x1596);
char* x1598 = mmap(0, x1597, PROT_READ, MAP_FILE | MAP_SHARED, x1596, 0);
for (;;) {
int32_t x1600 = x1599;
bool x1601 = x1600 < x1597;
if (!x1601) break;
int32_t x1603 = x1599;
for (;;) {
int32_t x1604 = x1599;
char x1605 = x1598[x1604];
bool x1606 = x1605 != '\t';
if (!x1606) break;
x1599 += 1;
}
int32_t x1611 = x1599;
x1599 += 1;
int32_t x1615 = x1599;
for (;;) {
int32_t x1616 = x1599;
char x1617 = x1598[x1616];
bool x1618 = x1617 != '\n';
if (!x1618) break;
x1599 += 1;
}
int32_t x1623 = x1599;
x1599 += 1;
int32_t x1627 = x128;
int32_t x1628 = x121;
bool x1629 = x1627 == x1628;
if (x1629) {
x121 *= 4;
int32_t x1631 = x121;
printf("buffer.resize %d\n",x1631);
} else {
}
char* x1614 = x1598+x1603;
x123[x1627] = x1614;
char* x1626 = x1598+x1615;
x126[x1627] = x1626;
x128 += 1;
int32_t x1638 = 1;
int64_t x1639 = hash(x1614, 10L);
x1638 *= x1639;
int64_t x1641 = hash(x1626, 10L);
x1638 *= x1641;
int32_t x1643 = x1638;
int32_t x1644 = x1643 & 65535;
int32_t x1645 = x135[x1644];
int32_t x1646 = x1645;
x135[x1644] = x1627;
x130[x1627] = x1645;
int32_t x1649 = 1;
int64_t x1650 = hash(x1614, 10L);
x1649 *= x1650;
int32_t x1652 = x1649;
int32_t x1653 = x1652 & 65535;
int32_t x1654 = x136[x1653];
int32_t x1655 = x1654;
x136[x1653] = x1627;
x133[x1627] = x1654;
}
int32_t x1660 = x128;
bool x1661 = x1660 == 0;
bool x1663;
if (x1661) {
x1663 = false;
} else {
bool x978 = !x977;
x1663 = x978;
}
if (x1663) {
for(int x1665=0; x1665 < x1660; x1665++) {
int32_t x1666 = 0;
bool x1667 = true;
char* x1677 = x123[x1665];
for (;;) {
bool x1668 = x1667;
bool x1673;
if (x1668) {
int32_t x1669 = x1666;
int32_t x1670 = x287;
bool x1671 = x1669 < x1670;
x1673 = x1671;
} else {
x1673 = false;
}
if (!x1673) break;
int32_t x1675 = x1666;
bool x1678 = true;
int32_t x1679 = 1;
char* x1676 = x285[x1675];
int64_t x1680 = hash(x1676, 10L);
x1679 *= x1680;
int64_t x1682 = hash(x1677, 10L);
x1679 *= x1682;
int32_t x1684 = x1679;
int32_t x1685 = x1684 & 65535;
int32_t x1686 = x12[x1685];
int32_t x1687 = x1686;
bool x1688 = true;
for (;;) {
bool x1689 = x1688;
bool x1693;
if (x1689) {
int32_t x1690 = x1687;
bool x1691 = x1690 != -1;
x1693 = x1691;
} else {
x1693 = false;
}
if (!x1693) break;
int32_t x1695 = x1687;
int32_t x1696 = x10[x1695];
x1687 = x1696;
bool x1698 = true;
char* x1699 = x3[x1695];
bool x1700 = tpch_streq(x1676,x1699);
if (x1700) {
} else {
x1698 = false;
}
char* x1704 = x6[x1695];
bool x1705 = tpch_streq(x1677,x1704);
if (x1705) {
} else {
x1698 = false;
}
bool x1709 = x1698;
if (x1709) {
bool x1710 = true;
if (x1700) {
} else {
x1710 = false;
}
if (x1705) {
} else {
x1710 = false;
}
bool x1717 = x1710;
if (x1717) {
x1678 = false;
} else {
}
bool x1721 = x1678;
x1688 = x1721;
} else {
}
}
bool x1727 = x1678;
if (x1727) {
bool x1730 = true;
int32_t x1731 = 1;
int64_t x1732 = hash(x1676, 10L);
x1731 *= x1732;
int64_t x1734 = hash(x1677, 10L);
x1731 *= x1734;
int32_t x1736 = x1731;
int32_t x1737 = x1736 & 65535;
int32_t x1738 = x12[x1737];
int32_t x1739 = x1738;
bool x1740 = true;
for (;;) {
bool x1741 = x1740;
bool x1745;
if (x1741) {
int32_t x1742 = x1739;
bool x1743 = x1742 != -1;
x1745 = x1743;
} else {
x1745 = false;
}
if (!x1745) break;
int32_t x1747 = x1739;
int32_t x1748 = x10[x1747];
x1739 = x1748;
bool x1750 = true;
char* x1751 = x3[x1747];
bool x1752 = tpch_streq(x1676,x1751);
if (x1752) {
} else {
x1750 = false;
}
char* x1756 = x6[x1747];
bool x1757 = tpch_streq(x1677,x1756);
if (x1757) {
} else {
x1750 = false;
}
bool x1761 = x1750;
if (x1761) {
bool x1762 = true;
if (x1752) {
} else {
x1762 = false;
}
if (x1757) {
} else {
x1762 = false;
}
bool x1769 = x1762;
if (x1769) {
x1730 = false;
} else {
}
bool x1773 = x1730;
x1740 = x1773;
} else {
}
}
bool x1779 = x1730;
if (x1779) {
bool x1782 = true;
int32_t x1783 = 1;
int64_t x1784 = hash(x1677, 10L);
x1783 *= x1784;
int32_t x1786 = x1783;
int32_t x1787 = x1786 & 65535;
int32_t x1788 = x249[x1787];
int32_t x1789 = x1788;
bool x1790 = true;
for (;;) {
bool x1791 = x1790;
bool x1795;
if (x1791) {
int32_t x1792 = x1789;
bool x1793 = x1792 != -1;
x1795 = x1793;
} else {
x1795 = false;
}
if (!x1795) break;
int32_t x1797 = x1789;
int32_t x1798 = x247[x1797];
x1789 = x1798;
bool x1800 = true;
char* x1801 = x243[x1797];
bool x1802 = tpch_streq(x1677,x1801);
if (x1802) {
} else {
x1800 = false;
}
bool x1806 = x1800;
if (x1806) {
bool x1807 = true;
if (x1802) {
} else {
x1807 = false;
}
bool x1811 = x1807;
if (x1811) {
x1782 = false;
} else {
}
bool x1815 = x1782;
x1790 = x1815;
} else {
}
}
bool x1821 = x1782;
if (x1821) {
int32_t x1824 = x245;
int32_t x1825 = x241;
bool x1826 = x1824 == x1825;
if (x1826) {
x241 *= 4;
int32_t x1828 = x241;
printf("buffer.resize %d\n",x1828);
} else {
}
x243[x1824] = x1677;
x245 += 1;
int32_t x1834 = 1;
int64_t x1835 = hash(x1677, 10L);
x1834 *= x1835;
int32_t x1837 = x1834;
int32_t x1838 = x1837 & 65535;
int32_t x1839 = x249[x1838];
int32_t x1840 = x1839;
x249[x1838] = x1824;
x247[x1824] = x1839;
} else {
}
} else {
}
} else {
}
bool x1728 = !x1727;
bool x1729 = !x1728;
bool x1849 = !x1729;
x1667 = x1849;
x1666 += 1;
}

}
} else {
}
for(int x1858=0; x1858 < 65536; x1858++) {
x291[x1858] = -1;

}
for(int x1862=0; x1862 < 65536; x1862++) {
x12[x1862] = -1;

}
if (x1661) {
} else {
for(int x1866=0; x1866 < x1660; x1866++) {
bool x1868 = true;
int32_t x1869 = 1;
char* x1867 = x123[x1866];
int64_t x1870 = hash(x1867, 10L);
x1869 *= x1870;
int32_t x1872 = x1869;
int32_t x1873 = x1872 & 65535;
int32_t x1874 = x249[x1873];
int32_t x1875 = x1874;
bool x1876 = true;
for (;;) {
bool x1877 = x1876;
bool x1881;
if (x1877) {
int32_t x1878 = x1875;
bool x1879 = x1878 != -1;
x1881 = x1879;
} else {
x1881 = false;
}
if (!x1881) break;
int32_t x1883 = x1875;
int32_t x1884 = x247[x1883];
x1875 = x1884;
bool x1886 = true;
char* x1887 = x243[x1883];
bool x1888 = tpch_streq(x1867,x1887);
if (x1888) {
} else {
x1886 = false;
}
bool x1892 = x1886;
if (x1892) {
bool x1893 = true;
if (x1888) {
} else {
x1893 = false;
}
bool x1897 = x1893;
if (x1897) {
x1868 = false;
} else {
}
bool x1901 = x1868;
x1876 = x1901;
} else {
}
}
bool x1907 = x1868;
if (x1907) {
bool x1910 = true;
int32_t x1911 = 1;
int64_t x1912 = hash(x1867, 10L);
x1911 *= x1912;
int32_t x1914 = x1911;
int32_t x1915 = x1914 & 65535;
int32_t x1916 = x55[x1915];
int32_t x1917 = x1916;
bool x1918 = true;
for (;;) {
bool x1919 = x1918;
bool x1923;
if (x1919) {
int32_t x1920 = x1917;
bool x1921 = x1920 != -1;
x1923 = x1921;
} else {
x1923 = false;
}
if (!x1923) break;
int32_t x1925 = x1917;
int32_t x1926 = x53[x1925];
x1917 = x1926;
bool x1928 = true;
char* x1929 = x49[x1925];
bool x1930 = tpch_streq(x1867,x1929);
if (x1930) {
} else {
x1928 = false;
}
bool x1934 = x1928;
if (x1934) {
bool x1935 = true;
if (x1930) {
} else {
x1935 = false;
}
bool x1939 = x1935;
if (x1939) {
x1910 = false;
} else {
}
bool x1943 = x1910;
x1918 = x1943;
} else {
}
}
bool x1949 = x1910;
if (x1949) {
int32_t x1952 = x51;
int32_t x1953 = x47;
bool x1954 = x1952 == x1953;
if (x1954) {
x47 *= 4;
int32_t x1956 = x47;
printf("buffer.resize %d\n",x1956);
} else {
}
x49[x1952] = x1867;
x51 += 1;
int32_t x1962 = 1;
int64_t x1963 = hash(x1867, 10L);
x1962 *= x1963;
int32_t x1965 = x1962;
int32_t x1966 = x1965 & 65535;
int32_t x1967 = x55[x1966];
int32_t x1968 = x1967;
x55[x1966] = x1952;
x53[x1952] = x1967;
} else {
}
} else {
}

}
}
int32_t x1980 = x51;
FILE *x1979 = fopen("./hw4-4.ans","w");
for(int x1982=0; x1982 < x1980; x1982++) {
char* x1983 = x49[x1982];
int32_t x1984 = printll(x1979,x1983);
int32_t x1985 = fprintf(x1979,"\n");

}
fclose(x1979);
for(int x1989=0; x1989 < 65536; x1989++) {
x249[x1989] = -1;

}
int32_t x1993 = x303;
bool x1994 = x1993 == 0;
bool x1996 = x1980 == 0;
bool x1998;
if (x1994) {
x1998 = false;
} else {
bool x1997 = !x1996;
x1998 = x1997;
}
if (x1998) {
for(int x1999=0; x1999 < x1980; x1999++) {
int32_t x2000 = 0;
bool x2001 = true;
char* x2010 = x49[x1999];
for (;;) {
bool x2002 = x2001;
bool x2007;
if (x2002) {
int32_t x2003 = x2000;
int32_t x2004 = x51;
bool x2005 = x2003 < x2004;
x2007 = x2005;
} else {
x2007 = false;
}
if (!x2007) break;
int32_t x2009 = x2000;
bool x2012 = true;
int32_t x2013 = 1;
int64_t x2014 = hash(x2010, 10L);
x2013 *= x2014;
char* x2011 = x49[x2009];
int64_t x2016 = hash(x2011, 10L);
x2013 *= x2016;
int32_t x2018 = x2013;
int32_t x2019 = x2018 & 65535;
int32_t x2020 = x307[x2019];
int32_t x2021 = x2020;
bool x2022 = true;
for (;;) {
bool x2023 = x2022;
bool x2027;
if (x2023) {
int32_t x2024 = x2021;
bool x2025 = x2024 != -1;
x2027 = x2025;
} else {
x2027 = false;
}
if (!x2027) break;
int32_t x2029 = x2021;
int32_t x2030 = x305[x2029];
x2021 = x2030;
bool x2032 = true;
char* x2033 = x298[x2029];
bool x2034 = tpch_streq(x2010,x2033);
if (x2034) {
} else {
x2032 = false;
}
char* x2038 = x301[x2029];
bool x2039 = tpch_streq(x2011,x2038);
if (x2039) {
} else {
x2032 = false;
}
bool x2043 = x2032;
if (x2043) {
bool x2044 = true;
if (x2034) {
} else {
x2044 = false;
}
if (x2039) {
} else {
x2044 = false;
}
bool x2051 = x2044;
if (x2051) {
x2012 = false;
} else {
}
bool x2055 = x2012;
x2022 = x2055;
} else {
}
}
bool x2061 = x2012;
if (x2061) {
} else {
bool x2063 = true;
int32_t x2064 = 1;
int64_t x2065 = hash(x2010, 10L);
x2064 *= x2065;
int64_t x2067 = hash(x2011, 10L);
x2064 *= x2067;
int32_t x2069 = x2064;
int32_t x2070 = x2069 & 65535;
int32_t x2071 = x307[x2070];
int32_t x2072 = x2071;
bool x2073 = true;
for (;;) {
bool x2074 = x2073;
bool x2078;
if (x2074) {
int32_t x2075 = x2072;
bool x2076 = x2075 != -1;
x2078 = x2076;
} else {
x2078 = false;
}
if (!x2078) break;
int32_t x2080 = x2072;
int32_t x2081 = x305[x2080];
x2072 = x2081;
bool x2083 = true;
char* x2084 = x298[x2080];
bool x2085 = tpch_streq(x2010,x2084);
if (x2085) {
} else {
x2083 = false;
}
char* x2089 = x301[x2080];
bool x2090 = tpch_streq(x2011,x2089);
if (x2090) {
} else {
x2083 = false;
}
bool x2094 = x2083;
if (x2094) {
bool x2095 = true;
if (x2085) {
} else {
x2095 = false;
}
if (x2090) {
} else {
x2095 = false;
}
bool x2102 = x2095;
if (x2102) {
x2063 = false;
} else {
}
bool x2106 = x2063;
x2073 = x2106;
} else {
}
}
bool x2112 = x2063;
if (x2112) {
} else {
bool x2114 = true;
int32_t x2115 = 1;
int64_t x2116 = hash(x2010, 10L);
x2115 *= x2116;
int32_t x2118 = x2115;
int32_t x2119 = x2118 & 65535;
int32_t x2120 = x262[x2119];
int32_t x2121 = x2120;
bool x2122 = true;
for (;;) {
bool x2123 = x2122;
bool x2127;
if (x2123) {
int32_t x2124 = x2121;
bool x2125 = x2124 != -1;
x2127 = x2125;
} else {
x2127 = false;
}
if (!x2127) break;
int32_t x2129 = x2121;
int32_t x2130 = x260[x2129];
x2121 = x2130;
bool x2132 = true;
char* x2133 = x256[x2129];
bool x2134 = tpch_streq(x2010,x2133);
if (x2134) {
} else {
x2132 = false;
}
bool x2138 = x2132;
if (x2138) {
bool x2139 = true;
if (x2134) {
} else {
x2139 = false;
}
bool x2143 = x2139;
if (x2143) {
x2114 = false;
} else {
}
bool x2147 = x2114;
x2122 = x2147;
} else {
}
}
bool x2153 = x2114;
if (x2153) {
int32_t x2156 = x258;
int32_t x2157 = x254;
bool x2158 = x2156 == x2157;
if (x2158) {
x254 *= 4;
int32_t x2160 = x254;
printf("buffer.resize %d\n",x2160);
} else {
}
x256[x2156] = x2010;
x258 += 1;
int32_t x2166 = 1;
int64_t x2167 = hash(x2010, 10L);
x2166 *= x2167;
int32_t x2169 = x2166;
int32_t x2170 = x2169 & 65535;
int32_t x2171 = x262[x2170];
int32_t x2172 = x2171;
x262[x2170] = x2156;
x260[x2156] = x2171;
} else {
}
}
}
bool x2062 = !x2061;
bool x2181 = !x2062;
x2001 = x2181;
x2000 += 1;
}

}
} else {
}
for(int x2190=0; x2190 < 65536; x2190++) {
x307[x2190] = -1;

}
if (x1996) {
} else {
for(int x2194=0; x2194 < x1980; x2194++) {
bool x2196 = true;
int32_t x2197 = 1;
char* x2195 = x49[x2194];
int64_t x2198 = hash(x2195, 10L);
x2197 *= x2198;
int32_t x2200 = x2197;
int32_t x2201 = x2200 & 65535;
int32_t x2202 = x262[x2201];
int32_t x2203 = x2202;
bool x2204 = true;
for (;;) {
bool x2205 = x2204;
bool x2209;
if (x2205) {
int32_t x2206 = x2203;
bool x2207 = x2206 != -1;
x2209 = x2207;
} else {
x2209 = false;
}
if (!x2209) break;
int32_t x2211 = x2203;
int32_t x2212 = x260[x2211];
x2203 = x2212;
bool x2214 = true;
char* x2215 = x256[x2211];
bool x2216 = tpch_streq(x2195,x2215);
if (x2216) {
} else {
x2214 = false;
}
bool x2220 = x2214;
if (x2220) {
bool x2221 = true;
if (x2216) {
} else {
x2221 = false;
}
bool x2225 = x2221;
if (x2225) {
x2196 = false;
} else {
}
bool x2229 = x2196;
x2204 = x2229;
} else {
}
}
bool x2235 = x2196;
if (x2235) {
bool x2238 = true;
int32_t x2239 = 1;
int64_t x2240 = hash(x2195, 10L);
x2239 *= x2240;
int32_t x2242 = x2239;
int32_t x2243 = x2242 & 65535;
int32_t x2244 = x68[x2243];
int32_t x2245 = x2244;
bool x2246 = true;
for (;;) {
bool x2247 = x2246;
bool x2251;
if (x2247) {
int32_t x2248 = x2245;
bool x2249 = x2248 != -1;
x2251 = x2249;
} else {
x2251 = false;
}
if (!x2251) break;
int32_t x2253 = x2245;
int32_t x2254 = x66[x2253];
x2245 = x2254;
bool x2256 = true;
char* x2257 = x62[x2253];
bool x2258 = tpch_streq(x2195,x2257);
if (x2258) {
} else {
x2256 = false;
}
bool x2262 = x2256;
if (x2262) {
bool x2263 = true;
if (x2258) {
} else {
x2263 = false;
}
bool x2267 = x2263;
if (x2267) {
x2238 = false;
} else {
}
bool x2271 = x2238;
x2246 = x2271;
} else {
}
}
bool x2277 = x2238;
if (x2277) {
int32_t x2280 = x64;
int32_t x2281 = x60;
bool x2282 = x2280 == x2281;
if (x2282) {
x60 *= 4;
int32_t x2284 = x60;
printf("buffer.resize %d\n",x2284);
} else {
}
x62[x2280] = x2195;
x64 += 1;
int32_t x2290 = 1;
int64_t x2291 = hash(x2195, 10L);
x2290 *= x2291;
int32_t x2293 = x2290;
int32_t x2294 = x2293 & 65535;
int32_t x2295 = x68[x2294];
int32_t x2296 = x2295;
x68[x2294] = x2280;
x66[x2280] = x2295;
} else {
}
} else {
}

}
}
int32_t x2308 = x64;
FILE *x2307 = fopen("./hw4-5.ans","w");
for(int x2310=0; x2310 < x2308; x2310++) {
char* x2311 = x62[x2310];
int32_t x2312 = printll(x2307,x2311);
int32_t x2313 = fprintf(x2307,"\n");

}
fclose(x2307);
for(int x2317=0; x2317 < 65536; x2317++) {
x55[x2317] = -1;

}
for(int x2321=0; x2321 < 65536; x2321++) {
x262[x2321] = -1;

}
bool x2325;
if (x442) {
x2325 = false;
} else {
bool x1662 = !x1661;
x2325 = x1662;
}
if (x2325) {
int32_t x2326 = 1;
int64_t x2327 = hash("Priscilla", 10L);
x2326 *= x2327;
int32_t x2329 = x2326;
int32_t x2330 = x2329 & 65535;
int32_t x2331 = x188[x2330];
int32_t x2332 = x2331;
for (;;) {
int32_t x2333 = x2332;
bool x2334 = x2333 != -1;
if (!x2334) break;
int32_t x2336 = x2332;
int32_t x2337 = x184[x2336];
x2332 = x2337;
bool x2339 = true;
char* x2340 = x171[x2336];
bool x2341 = tpch_streq("Priscilla",x2340);
if (x2341) {
} else {
x2339 = false;
}
bool x2345 = x2339;
if (x2345) {
int32_t x2347 = 1;
char* x2346 = x174[x2336];
int64_t x2348 = hash(x2346, 10L);
x2347 *= x2348;
int32_t x2350 = x2347;
int32_t x2351 = x2350 & 65535;
int32_t x2352 = x136[x2351];
int32_t x2353 = x2352;
for (;;) {
int32_t x2354 = x2353;
bool x2355 = x2354 != -1;
if (!x2355) break;
int32_t x2357 = x2353;
int32_t x2358 = x133[x2357];
x2353 = x2358;
bool x2360 = true;
char* x2361 = x123[x2357];
bool x2362 = tpch_streq(x2346,x2361);
if (x2362) {
} else {
x2360 = false;
}
bool x2366 = x2360;
if (x2366) {
bool x2368 = true;
int32_t x2369 = 1;
int64_t x2370 = hash(x2346, 10L);
x2369 *= x2370;
char* x2367 = x126[x2357];
int64_t x2372 = hash(x2367, 10L);
x2369 *= x2372;
int32_t x2374 = x2369;
int32_t x2375 = x2374 & 65535;
int32_t x2376 = x212[x2375];
int32_t x2377 = x2376;
bool x2378 = true;
for (;;) {
bool x2379 = x2378;
bool x2383;
if (x2379) {
int32_t x2380 = x2377;
bool x2381 = x2380 != -1;
x2383 = x2381;
} else {
x2383 = false;
}
if (!x2383) break;
int32_t x2385 = x2377;
int32_t x2386 = x210[x2385];
x2377 = x2386;
bool x2388 = true;
char* x2389 = x203[x2385];
bool x2390 = tpch_streq(x2346,x2389);
if (x2390) {
} else {
x2388 = false;
}
char* x2394 = x206[x2385];
bool x2395 = tpch_streq(x2367,x2394);
if (x2395) {
} else {
x2388 = false;
}
bool x2399 = x2388;
if (x2399) {
bool x2400 = true;
if (x2390) {
} else {
x2400 = false;
}
if (x2395) {
} else {
x2400 = false;
}
bool x2407 = x2400;
if (x2407) {
x2368 = false;
} else {
}
bool x2411 = x2368;
x2378 = x2411;
} else {
}
}
bool x2417 = x2368;
if (x2417) {
int32_t x2420 = x208;
int32_t x2421 = x201;
bool x2422 = x2420 == x2421;
if (x2422) {
x201 *= 4;
int32_t x2424 = x201;
printf("buffer.resize %d\n",x2424);
} else {
}
x203[x2420] = x2346;
x206[x2420] = x2367;
x208 += 1;
int32_t x2431 = 1;
int64_t x2432 = hash(x2346, 10L);
x2431 *= x2432;
int64_t x2434 = hash(x2367, 10L);
x2431 *= x2434;
int32_t x2436 = x2431;
int32_t x2437 = x2436 & 65535;
int32_t x2438 = x212[x2437];
int32_t x2439 = x2438;
x212[x2437] = x2420;
x210[x2420] = x2438;
} else {
}
} else {
}
}
} else {
}
}
} else {
}
int32_t x2455 = x208;
FILE *x2454 = fopen("./hw4-0.ans","w");
for(int x2457=0; x2457 < x2455; x2457++) {
char* x2458 = x203[x2457];
int32_t x2459 = printll(x2454,x2458);
int32_t x2460 = fprintf(x2454,"\t");
char* x2461 = x206[x2457];
int32_t x2462 = printll(x2454,x2461);
int32_t x2463 = fprintf(x2454,"\n");

}
fclose(x2454);
bool x2467 = x2455 == 0;
if (x2467) {
} else {
for(int x2469=0; x2469 < x2455; x2469++) {
bool x2472 = true;
int32_t x2473 = 1;
char* x2470 = x203[x2469];
int64_t x2474 = hash(x2470, 10L);
x2473 *= x2474;
char* x2471 = x206[x2469];
int64_t x2476 = hash(x2471, 10L);
x2473 *= x2476;
int32_t x2478 = x2473;
int32_t x2479 = x2478 & 65535;
int32_t x2480 = x278[x2479];
int32_t x2481 = x2480;
bool x2482 = true;
for (;;) {
bool x2483 = x2482;
bool x2487;
if (x2483) {
int32_t x2484 = x2481;
bool x2485 = x2484 != -1;
x2487 = x2485;
} else {
x2487 = false;
}
if (!x2487) break;
int32_t x2489 = x2481;
int32_t x2490 = x276[x2489];
x2481 = x2490;
bool x2492 = true;
char* x2493 = x269[x2489];
bool x2494 = tpch_streq(x2470,x2493);
if (x2494) {
} else {
x2492 = false;
}
char* x2498 = x272[x2489];
bool x2499 = tpch_streq(x2471,x2498);
if (x2499) {
} else {
x2492 = false;
}
bool x2503 = x2492;
if (x2503) {
bool x2504 = true;
if (x2494) {
} else {
x2504 = false;
}
if (x2499) {
} else {
x2504 = false;
}
bool x2511 = x2504;
if (x2511) {
x2472 = false;
} else {
}
bool x2515 = x2472;
x2482 = x2515;
} else {
}
}
bool x2521 = x2472;
if (x2521) {
int32_t x2524 = x274;
int32_t x2525 = x267;
bool x2526 = x2524 == x2525;
if (x2526) {
x267 *= 4;
int32_t x2528 = x267;
printf("buffer.resize %d\n",x2528);
} else {
}
x269[x2524] = x2470;
x272[x2524] = x2471;
x274 += 1;
int32_t x2535 = 1;
int64_t x2536 = hash(x2470, 10L);
x2535 *= x2536;
int64_t x2538 = hash(x2471, 10L);
x2535 *= x2538;
int32_t x2540 = x2535;
int32_t x2541 = x2540 & 65535;
int32_t x2542 = x278[x2541];
int32_t x2543 = x2542;
x278[x2541] = x2524;
x276[x2524] = x2542;
} else {
}

}
}
int32_t x2552 = x274;
for(int x2554=0; x2554 < x2552; x2554++) {
bool x2557 = true;
int32_t x2558 = 1;
char* x2555 = x269[x2554];
int64_t x2559 = hash(x2555, 10L);
x2558 *= x2559;
char* x2556 = x272[x2554];
int64_t x2561 = hash(x2556, 10L);
x2558 *= x2561;
int32_t x2563 = x2558;
int32_t x2564 = x2563 & 65535;
int32_t x2565 = x29[x2564];
int32_t x2566 = x2565;
bool x2567 = true;
for (;;) {
bool x2568 = x2567;
bool x2572;
if (x2568) {
int32_t x2569 = x2566;
bool x2570 = x2569 != -1;
x2572 = x2570;
} else {
x2572 = false;
}
if (!x2572) break;
int32_t x2574 = x2566;
int32_t x2575 = x27[x2574];
x2566 = x2575;
bool x2577 = true;
char* x2578 = x20[x2574];
bool x2579 = tpch_streq(x2555,x2578);
if (x2579) {
} else {
x2577 = false;
}
char* x2583 = x23[x2574];
bool x2584 = tpch_streq(x2556,x2583);
if (x2584) {
} else {
x2577 = false;
}
bool x2588 = x2577;
if (x2588) {
bool x2589 = true;
if (x2579) {
} else {
x2589 = false;
}
if (x2584) {
} else {
x2589 = false;
}
bool x2596 = x2589;
if (x2596) {
x2557 = false;
} else {
}
bool x2600 = x2557;
x2567 = x2600;
} else {
}
}
bool x2606 = x2557;
if (x2606) {
int32_t x2609 = x25;
int32_t x2610 = x18;
bool x2611 = x2609 == x2610;
if (x2611) {
x18 *= 4;
int32_t x2613 = x18;
printf("buffer.resize %d\n",x2613);
} else {
}
x20[x2609] = x2555;
x23[x2609] = x2556;
x25 += 1;
int32_t x2620 = 1;
int64_t x2621 = hash(x2555, 10L);
x2620 *= x2621;
int64_t x2623 = hash(x2556, 10L);
x2620 *= x2623;
int32_t x2625 = x2620;
int32_t x2626 = x2625 & 65535;
int32_t x2627 = x29[x2626];
int32_t x2628 = x2627;
x29[x2626] = x2609;
x27[x2609] = x2627;
} else {
}

}
bool x2635 = true;
for (;;) {
bool x2636 = x2635;
if (!x2636) break;
int32_t x2638 = x25;
bool x2639 = x2638 == 0;
bool x2645;
if (x2639) {
x2645 = false;
} else {
int32_t x2641 = x176;
bool x2642 = x2641 == 0;
bool x2643 = !x2642;
x2645 = x2643;
}
bool x2650;
if (x2645) {
int32_t x2646 = x128;
bool x2647 = x2646 == 0;
bool x2648 = !x2647;
x2650 = x2648;
} else {
x2650 = false;
}
if (x2650) {
for(int x2652=0; x2652 < x2638; x2652++) {
int32_t x2654 = 1;
char* x2653 = x20[x2652];
int64_t x2655 = hash(x2653, 10L);
x2654 *= x2655;
int32_t x2657 = x2654;
int32_t x2658 = x2657 & 65535;
int32_t x2659 = x188[x2658];
int32_t x2660 = x2659;
for (;;) {
int32_t x2661 = x2660;
bool x2662 = x2661 != -1;
if (!x2662) break;
int32_t x2664 = x2660;
int32_t x2665 = x184[x2664];
x2660 = x2665;
bool x2667 = true;
char* x2668 = x171[x2664];
bool x2669 = tpch_streq(x2653,x2668);
if (x2669) {
} else {
x2667 = false;
}
bool x2673 = x2667;
if (x2673) {
int32_t x2675 = 1;
char* x2674 = x174[x2664];
int64_t x2676 = hash(x2674, 10L);
x2675 *= x2676;
int32_t x2678 = x2675;
int32_t x2679 = x2678 & 65535;
int32_t x2680 = x136[x2679];
int32_t x2681 = x2680;
for (;;) {
int32_t x2682 = x2681;
bool x2683 = x2682 != -1;
if (!x2683) break;
int32_t x2685 = x2681;
int32_t x2686 = x133[x2685];
x2681 = x2686;
bool x2688 = true;
char* x2689 = x123[x2685];
bool x2690 = tpch_streq(x2674,x2689);
if (x2690) {
} else {
x2688 = false;
}
bool x2694 = x2688;
if (x2694) {
bool x2696 = true;
int32_t x2697 = 1;
int64_t x2698 = hash(x2674, 10L);
x2697 *= x2698;
char* x2695 = x126[x2685];
int64_t x2700 = hash(x2695, 10L);
x2697 *= x2700;
int32_t x2702 = x2697;
int32_t x2703 = x2702 & 65535;
int32_t x2704 = x278[x2703];
int32_t x2705 = x2704;
bool x2706 = true;
for (;;) {
bool x2707 = x2706;
bool x2711;
if (x2707) {
int32_t x2708 = x2705;
bool x2709 = x2708 != -1;
x2711 = x2709;
} else {
x2711 = false;
}
if (!x2711) break;
int32_t x2713 = x2705;
int32_t x2714 = x276[x2713];
x2705 = x2714;
bool x2716 = true;
char* x2717 = x269[x2713];
bool x2718 = tpch_streq(x2674,x2717);
if (x2718) {
} else {
x2716 = false;
}
char* x2722 = x272[x2713];
bool x2723 = tpch_streq(x2695,x2722);
if (x2723) {
} else {
x2716 = false;
}
bool x2727 = x2716;
if (x2727) {
bool x2728 = true;
if (x2718) {
} else {
x2728 = false;
}
if (x2723) {
} else {
x2728 = false;
}
bool x2735 = x2728;
if (x2735) {
x2696 = false;
} else {
}
bool x2739 = x2696;
x2706 = x2739;
} else {
}
}
bool x2745 = x2696;
if (x2745) {
bool x2748 = true;
int32_t x2749 = 1;
int64_t x2750 = hash(x2674, 10L);
x2749 *= x2750;
int64_t x2752 = hash(x2695, 10L);
x2749 *= x2752;
int32_t x2754 = x2749;
int32_t x2755 = x2754 & 65535;
int32_t x2756 = x323[x2755];
int32_t x2757 = x2756;
bool x2758 = true;
for (;;) {
bool x2759 = x2758;
bool x2763;
if (x2759) {
int32_t x2760 = x2757;
bool x2761 = x2760 != -1;
x2763 = x2761;
} else {
x2763 = false;
}
if (!x2763) break;
int32_t x2765 = x2757;
int32_t x2766 = x321[x2765];
x2757 = x2766;
bool x2768 = true;
char* x2769 = x314[x2765];
bool x2770 = tpch_streq(x2674,x2769);
if (x2770) {
} else {
x2768 = false;
}
char* x2774 = x317[x2765];
bool x2775 = tpch_streq(x2695,x2774);
if (x2775) {
} else {
x2768 = false;
}
bool x2779 = x2768;
if (x2779) {
bool x2780 = true;
if (x2770) {
} else {
x2780 = false;
}
if (x2775) {
} else {
x2780 = false;
}
bool x2787 = x2780;
if (x2787) {
x2748 = false;
} else {
}
bool x2791 = x2748;
x2758 = x2791;
} else {
}
}
bool x2797 = x2748;
if (x2797) {
int32_t x2800 = x319;
int32_t x2801 = x312;
bool x2802 = x2800 == x2801;
if (x2802) {
x312 *= 4;
int32_t x2804 = x312;
printf("buffer.resize %d\n",x2804);
} else {
}
x314[x2800] = x2674;
x317[x2800] = x2695;
x319 += 1;
int32_t x2811 = 1;
int64_t x2812 = hash(x2674, 10L);
x2811 *= x2812;
int64_t x2814 = hash(x2695, 10L);
x2811 *= x2814;
int32_t x2816 = x2811;
int32_t x2817 = x2816 & 65535;
int32_t x2818 = x323[x2817];
int32_t x2819 = x2818;
x323[x2817] = x2800;
x321[x2800] = x2818;
} else {
}
} else {
}
} else {
}
}
} else {
}
}

}
} else {
}
int32_t x2838 = x319;
bool x2839 = x2838 == 0;
if (x2839) {
x2635 = false;
} else {
for(int x2843=0; x2843 < x2838; x2843++) {
bool x2846 = true;
int32_t x2847 = 1;
char* x2844 = x314[x2843];
int64_t x2848 = hash(x2844, 10L);
x2847 *= x2848;
char* x2845 = x317[x2843];
int64_t x2850 = hash(x2845, 10L);
x2847 *= x2850;
int32_t x2852 = x2847;
int32_t x2853 = x2852 & 65535;
int32_t x2854 = x278[x2853];
int32_t x2855 = x2854;
bool x2856 = true;
for (;;) {
bool x2857 = x2856;
bool x2861;
if (x2857) {
int32_t x2858 = x2855;
bool x2859 = x2858 != -1;
x2861 = x2859;
} else {
x2861 = false;
}
if (!x2861) break;
int32_t x2863 = x2855;
int32_t x2864 = x276[x2863];
x2855 = x2864;
bool x2866 = true;
char* x2867 = x269[x2863];
bool x2868 = tpch_streq(x2844,x2867);
if (x2868) {
} else {
x2866 = false;
}
char* x2872 = x272[x2863];
bool x2873 = tpch_streq(x2845,x2872);
if (x2873) {
} else {
x2866 = false;
}
bool x2877 = x2866;
if (x2877) {
bool x2878 = true;
if (x2868) {
} else {
x2878 = false;
}
if (x2873) {
} else {
x2878 = false;
}
bool x2885 = x2878;
if (x2885) {
x2846 = false;
} else {
}
bool x2889 = x2846;
x2856 = x2889;
} else {
}
}
bool x2895 = x2846;
if (x2895) {
int32_t x2898 = x274;
int32_t x2899 = x267;
bool x2900 = x2898 == x2899;
if (x2900) {
x267 *= 4;
int32_t x2902 = x267;
printf("buffer.resize %d\n",x2902);
} else {
}
x269[x2898] = x2844;
x272[x2898] = x2845;
x274 += 1;
int32_t x2909 = 1;
int64_t x2910 = hash(x2844, 10L);
x2909 *= x2910;
int64_t x2912 = hash(x2845, 10L);
x2909 *= x2912;
int32_t x2914 = x2909;
int32_t x2915 = x2914 & 65535;
int32_t x2916 = x278[x2915];
int32_t x2917 = x2916;
x278[x2915] = x2898;
x276[x2898] = x2916;
} else {
}

}
SWAP(x25,x319);
SWAP(x18,x312);
SWAP(x21,x315);
SWAP(x19,x313);
SWAP(x20,x314);
SWAP(x24,x318);
SWAP(x22,x316);
SWAP(x23,x317);
SWAP(x28,x322);
SWAP(x26,x320);
SWAP(x27,x321);
SWAP(x29,x323);
x319 = 0;
x322 = 0;
for(int x2938=0; x2938 < 65536; x2938++) {
x323[x2938] = -1;

}
}
}
for(int x2946=0; x2946 < 65536; x2946++) {
x29[x2946] = -1;

}
for(int x2950=0; x2950 < 65536; x2950++) {
x323[x2950] = -1;

}
int32_t x2955 = x274;
FILE *x2954 = fopen("./hw4-1.ans","w");
for(int x2957=0; x2957 < x2955; x2957++) {
char* x2958 = x269[x2957];
int32_t x2959 = printll(x2954,x2958);
int32_t x2960 = fprintf(x2954,"\t");
char* x2961 = x272[x2957];
int32_t x2962 = printll(x2954,x2961);
int32_t x2963 = fprintf(x2954,"\n");

}
fclose(x2954);
for(int x2967=0; x2967 < 65536; x2967++) {
x212[x2967] = -1;

}
for(int x2971=0; x2971 < 65536; x2971++) {
x186[x2971] = -1;

}
for(int x2975=0; x2975 < 65536; x2975++) {
x187[x2975] = -1;

}
for(int x2979=0; x2979 < 65536; x2979++) {
x188[x2979] = -1;

}
for(int x2983=0; x2983 < 65536; x2983++) {
x135[x2983] = -1;

}
for(int x2987=0; x2987 < 65536; x2987++) {
x136[x2987] = -1;

}
for(int x2991=0; x2991 < 65536; x2991++) {
x278[x2991] = -1;

}
}
/*****************************************
  End of C Generated Code                  
*******************************************/

