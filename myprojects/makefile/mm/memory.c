//
// Created by ldd on 2021/7/3.
//
#include <stdio.h>
#include <tool.h>

extern int page();

int rmalloc(){
    int ret = rmax( 5, 6);
    int pageno = page();
    printf("max:%d", ret);
    printf("page:%d", pageno);
    return 0;
}

