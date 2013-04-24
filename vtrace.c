/**
 * @file vtrace.h
 * @author yangxu[ulyx.yang@gmail.com]
 * @date 2013/04/19 15:04
 * @brief function address tracer
 */


#include <stdio.h>
#include <stdlib.h>
#include "vtrace.h"

static FILE* fp = NULL;

const char* tracefile = "trace.txt";

void __cyg_profile_func_enter(void *func_address, void* calls_site) {
    fprintf(fp, "Enter: func = %p, call = %p\n", func_address, calls_site);
}

void __cyg_profile_func_exit(void *func_address, void* calls_site) {
    fprintf(fp, " Exit: func = %p, call = %p\n", func_address, calls_site);
}

void main_constructor(void) {
    fp = fopen(tracefile, "w");
    if (fp == NULL) exit -1;
}

void main_destructor(void) {
    fclose(fp);
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
