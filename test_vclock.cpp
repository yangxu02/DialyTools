/**
 * @file test_vclock.cpp
 * @author yangxu[ulyx.yang@gmail.com]
 * @date 2013/04/19 15:04
 * @brief 
 */



#include <stdio.h>
#include "vclock.h"

struct test {
    int x;
    int y;
    int z;

    test() {
        x = 0;
        y = 0;
        z = 0;
    }
};

struct test2 {
    int x;
    int y;
    int z;

    test2():x(0), y(0), z(0) {
    }
};

int main(int argc, char* argv[]) {

    v_clock_t clock;

    clock.init();

    clock.start();
    for(int i = 0; i < 100000000; ++i) {
        test t;
    }
    clock.stop();
    fprintf(stderr, "%30s%fus, %fms, %fs\n", "assignment: total time:",
            clock.interval(), clock.interval("ms"), clock.interval("s"));

    clock.start();
    for(int i = 0; i < 100000000; ++i) {
        test2 t;
    }
    clock.stop();
    fprintf(stderr, "%30s%fus, %fms, %fs\n", "list: total time:",
            clock.interval(), clock.interval("ms"), clock.interval("s"));

    return 0;
}
