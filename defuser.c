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

static uint32_t p4_walk(uint32_t a, uint32_t b, uint32_t c, uint32_t d){
    uint32_t mid = b + ((c - b) >> 1);

    if(mid == a){
        return(a + 0x3au) ^ d;
    }

    uint32_t base = mid + d;

    if(a < mid){
        uint32_t rec = p4_walk(a, b, mid-1, d);
        return ((5u * rec) ^ base) ^ 0xbu;
    }else{
        uint32_t rec = p4_walk(a, mid+1, c, d);
        return ((5u * rec) ^ base) ^ 0x9u;
    }
}

int solve_phase_4(uint64_t challenge, char *out, size_t cap) {
    uint32_t values[1];
    size_t count = 0;
    
    uint32_t a = (uint32_t)challenge & 0x7fu;
    uint32_t d = (uint32_t)(challenge >> 7) ^ (uint32_t)(challenge >> 32);
    values[count++] = p4_walk(a, 0, 0x7f, d);
    // TODO: 根据 phase_04 的汇编，用 challenge 算出口令中的各个整数，依次存入 values，并把 count 改为整数个数。
    return write_answer(out, cap, values, count);
}

static const int p5_heads[8] = {
    0,9,10,6,5,1,8,7
};

struct  p5_node_data{
    int next;
    uint32_t f8;
    uint32_t fc;
};
static const struct p5_node_data p5_nodes[]=
{
    {  9, 2589, 16804 },
    {  8, 2162, 14322 },
    { -1, 1894, 16757 },  // next 待查，c3<=3 用不到
    { -1,    0,     0 },  // 未使用
    { 11,   96, 50637 },
    {  1, 2845, 43625 },
    {  5, 1403, 39192 },
    {  4, 1042, 45188 },
    {  7, 2389, 29045 },
    { 10,  829, 19059 },
    {  6,  281, 56813 },
    {  2, 1612, 23481 },
};

static uint32_t p5_traverse(uint64_t challenge, uint32_t *out) {
    uint32_t idx = (uint32_t)challenge & 7u;
    uint32_t c3  = ((uint32_t)(challenge >> 3)) & 3u;

    int node = p5_heads[idx];
    uint32_t t = (uint32_t)(challenge >> 6) ^ (uint32_t)(challenge >> 32);

    uint32_t eax = ((t ^ 0xebb3u) + p5_nodes[node].fc) * 5u;
    *out = p5_nodes[node].f8;
    eax ^= p5_nodes[node].f8;

    for (uint32_t i = 0; i < c3; i++) {
        node = p5_nodes[node].next;
        eax = (eax + p5_nodes[node].fc) * 5u;
        *out = p5_nodes[node].f8;
        eax ^= p5_nodes[node].f8;
    }

    return eax;
}

int solve_phase_5(uint64_t challenge, char *out, size_t cap) {
    uint32_t values[2];
    size_t count = 0;
    uint32_t slot =0;

    uint32_t ret = p5_traverse(challenge, &slot);

    values[0] = ret;
    values[1] = slot;
    count =2;

    return write_answer(out, cap, values, count);
}

static uint32_t p6_ror32(uint32_t x, unsigned n) {
    n &= 31;
    return (x >> n) | (x << ((32 - n) & 31));
}

static uint32_t p6_rol32(uint32_t x, unsigned n) {
    n &= 31;
    return (x << n) | (x >> ((32 - n) & 31));
}

static uint32_t p6_op0(uint32_t x) {
    return ((x >> 7) ^ x) + 0x1673u;
}

static uint32_t p6_op1(uint32_t x) {
    return p6_ror32(x, 7);
}

static uint32_t p6_op2(uint32_t x) {
    return p6_rol32(x, 3) ^ 0xad4fu;
}

static uint32_t p6_op3(uint32_t x) {
    return (2u * x + 0x5f6cu) ^ (3u * x);
}

static uint32_t p6_op4(uint32_t x) {
    return (x + 0x33fdu) ^ (x >> 5);
}

static uint32_t p6_op5(uint32_t x) {
    return (x ^ 0xb5adu) + (x << 5);
}

static uint32_t p6_apply(uint32_t idx, uint32_t x) {
    switch (idx) {
        case 0: return p6_op3(x);
        case 1: return p6_op2(x);
        case 2: return p6_op1(x);
        case 3: return p6_op3(x);
        case 4: return p6_op5(x);
        case 5: return p6_op0(x);
        case 6: return p6_op4(x);
        case 7: return p6_op0(x);
        default: return 0;
    }
}

static uint32_t p6_dispatch(uint64_t challenge) {
    uint32_t arg  = (uint32_t)(challenge >> 6) ^ (uint32_t)(challenge >> 32);
    uint32_t idx1 = (uint32_t)challenge & 7u;
    uint32_t idx2 = ((uint32_t)challenge >> 3) & 7u;

    uint32_t r1 = p6_apply(idx1, arg);
    r1 ^= 0xd743u;

    uint32_t r2 = p6_apply(idx2, r1);
    return r2 + 0xc139u;
}

int solve_phase_6(uint64_t challenge, char *out, size_t cap) {
    uint32_t values[1];
    size_t count = 0;
    
    values[count++] = p6_dispatch(challenge);
   
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
