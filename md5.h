//copy from github:pod32g/MD5/blob/master/md5.c and have some changes
#ifndef MD5_H
#define MD5_H

#include<stdint.h>
//just formatting

// leftrotate function definition
#define LEFTROTATE(x, c) (((x) << (c)) | ((x) >> (32 - (c))))

//define some functions here for cross-script using

char* md5C(char*);

#endif