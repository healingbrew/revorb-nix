#ifndef REVORB_H

#include <stdint.h>

typedef struct REVORB_FILE_ {
  intptr_t* start;
  intptr_t* cursor;
  int size;
} REVORB_FILE;

typedef int REVORB_RESULT;

#define REVORB_ERR_SUCCESS 0
#define REVORB_ERR_NOT_OGG 1
#define REVORB_ERR_FIRST_PAGE 2
#define REVORB_ERR_FIRST_PACKET 3
#define REVORB_ERR_HEADER 4
#define REVORB_ERR_TRUNCATED 5
#define REVORB_ERR_SECONDARY_HEADER 6
#define REVORB_ERR_HEADER_WRITE 7
#define REVORB_ERR_CORRUPT 8
#define REVORB_ERR_BITSTREAM_CORRUPT 9
#define REVORB_ERR_WRITE_FAIL 10
#define REVORB_ERR_WRITE_FAIL2 11

REVORB_RESULT revorb(REVORB_FILE* fi, REVORB_FILE* fo);

#endif