/**
 * @file vclock.h
 * @author yangxu[ulyx.yang@gmail.com]
 * @date 2013/04/19 15:04
 * @brief simple virtual timer for collecting process intervals 
 */


#ifndef __V_CLOCK_H
#define __V_CLOCK_H

#include <time.h>

class v_clock_t {
private:
    struct timespec resolution;
    struct timespec from;
    struct timespec to;

    clockid_t id;

public:

    v_clock_t(clockid_t clockid = CLOCK_MONOTONIC): id(clockid) {
    }

    void init() {
        clock_getres(this->id, &this->resolution);
    }

    void start() {
        clock_gettime(this->id, &this->from);
    }

    void stop() {
        clock_gettime(this->id, &this->to);
    }

    /**
     * return interval in given unit, default [us]
     * @param unit: timing unit
     * @return interval 
     */
    float interval(const char* unit = "us") {
        if (*unit == 'm' && *(unit+1) == 's') {
            return ((to.tv_sec - from.tv_sec) * 1000.0
                    + (to.tv_nsec - from.tv_nsec) / 1000000.0); 
        } else if (*unit == 's') {
            return ((to.tv_sec - from.tv_sec)
                    + (to.tv_nsec - from.tv_nsec) / 1000000000.0); 
        } 
        return ((to.tv_sec - from.tv_sec) * 1000000.0
                + (to.tv_nsec - from.tv_nsec) / 1000.0); 
    }
};


#endif

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
