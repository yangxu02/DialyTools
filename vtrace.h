/**
 * @file vtrace.h
 * @author yangxu[ulyx.yang@gmail.com]
 * @date 2013/04/19 15:04
 * @brief function address tracer
 */


#ifndef __V_TRACE_H
#define __V_TRACE_H

void __cyg_profile_func_enter(void *func_address, void* calls_site)
        __attribute__ ((no_instrument_function));

void __cyg_profile_func_exit(void *func_address, void* calls_site)
        __attribute__ ((no_instrument_function));

void main_constructor(void) 
        __attribute__ ((no_instrument_function, constructor));

void main_destructor(void) 
        __attribute__ ((no_instrument_function, destructor));

#endif

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
