// system_implementation: poly.h
#ifndef POLY_H   // 头文件保护，防止重复包含
#define POLY_H

// 链表节点结构体定义
typedef struct PolyNode {
    double coef;           // 系数 (支持实数)
    int expn;              // 指数
    struct PolyNode* next; // 指针域
} PolyNode, * Polynomial;

// 接口声明：使用 extern 暴露给其他文件
Polynomial createNode(double coef, int expn);
Polynomial subtractPoly(Polynomial A, Polynomial B);
void freePoly(Polynomial p);

#endif