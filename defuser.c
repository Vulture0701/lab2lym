#include "defuser.h"

#include <inttypes.h>
#include <stdio.h>

#define MAX_FIELDS 8

/*
 * 把 values 中的 count 个整数写成一行“空格分隔的无符号十进制整数”，存入 out。
 * 成功返回 0；count 为 0（还没有实现）、snprintf 出错或结果被截断时返回非零。
 */
static int write_answer(char *out, size_t cap, const uint32_t *values, size_t count) {
    size_t used = 0;
    for (size_t i = 0; i < count; ++i) {
        int size = snprintf(out + used, cap - used, "%s%" PRIu32, i ? " " : "", values[i]);
        if (size < 0 || (size_t)size >= cap - used) return 1;
        used += (size_t)size;
    }
    return count == 0;
}

int solve_phase_1(uint64_t challenge, char *out, size_t cap) {
    uint32_t values[1];
    size_t count = 0;

    uint32_t L = (uint32_t)challenge;
    uint32_t H = (uint32_t)(challenge >> 32);
    uint64_t S = challenge >> 16;

    uint32_t t2 = ((H + 2 * L) ^ 0x2c61u);
    uint32_t t0 = ((3 * L + (uint32_t)S) ^ 0x1f10u);
    uint32_t ans = ((3 * t0) ^ (t2 + 0x4cabu));

    values[count++] = ans;
    return write_answer(out, cap, values, count);

}

int solve_phase_2(uint64_t challenge, char *out, size_t cap) {
    uint32_t values[6];
    size_t count = 0;

    values[0] = (((uint32_t)(challenge >> 31) * 2) & 0xFF) + 0x18u;

    for (uint32_t i = 1; i <= 5; i++) {
        uint32_t shifted = (uint32_t)(challenge >> (13 + 2*(i-1)));
        uint32_t expected = ((shifted & 0xFu) + i) ^ (3u * values[i-1]);
        values[i] = expected;
    }

    count = 6;
    return write_answer(out, cap, values, count);
}

int solve_phase_3(uint64_t challenge, char *out, size_t cap) {
    uint32_t values[2];
    size_t count = 0;

    uint32_t idx = (uint32_t)challenge & 7u;
    uint32_t x   = (uint32_t)(challenge >> 32) ^ (uint32_t)(challenge >> 3);

    uint32_t ans;
    switch (idx) {
    case 0: ans = 3u * x + 0xdbdu;                 break;  
    case 1: ans = (2u * x) ^ 0x5c6bu;              break;  
    case 2: ans = 5u * x + 0xa25du;                break;  
    case 3: ans = 5u * x + 0x30e9eu;               break;  
    case 4: ans = 5u * x + 0x3ca7du;               break;  
    case 5: ans = (x ^ 0xf61eu) + (x >> 1);        break;  
    case 6: ans = (2u * x) ^ 0xd7dbu;              break;  
    case 7: ans = (x ^ 0xd368u) + (x >> 2);        break;  
    default: ans = 0; break;
}
    values[0] = idx;
    values[1] = ans;
    count = 2;
    return write_answer(out, cap, values, count);
}

int solve_phase_4(uint64_t challenge, char *out, size_t cap) {
    uint32_t values[MAX_FIELDS] = {0};
    size_t count = 0;
    (void)challenge;
    // TODO: 根据 phase_04 的汇编，用 challenge 算出口令中的各个整数，依次存入 values，并把 count 改为整数个数。
    return write_answer(out, cap, values, count);
}

int solve_phase_5(uint64_t challenge, char *out, size_t cap) {
    uint32_t values[MAX_FIELDS] = {0};
    size_t count = 0;
    (void)challenge;
    // TODO: 根据 phase_05 的汇编，用 challenge 算出口令中的各个整数，依次存入 values，并把 count 改为整数个数。
    return write_answer(out, cap, values, count);
}

int solve_phase_6(uint64_t challenge, char *out, size_t cap) {
    uint32_t values[MAX_FIELDS] = {0};
    size_t count = 0;
    (void)challenge;
    // TODO: 根据 phase_06 的汇编，用 challenge 算出口令中的各个整数，依次存入 values，并把 count 改为整数个数。
    return write_answer(out, cap, values, count);
}

int solve_secret(uint64_t challenge, uint64_t context, char *out, size_t cap) {
    (void)challenge;
    (void)context;
    (void)out;
    (void)cap;
    // TODO（选做）: 根据 secret_gate、secret_copy 和 secret_phase 的汇编构造完整的第七行，写入 out 后返回 0。
    // 第七行不一定只有整数，可以直接用 snprintf 写入；还没完成时保持返回 1，测试会显示 not attempted。
    return 1;
}
