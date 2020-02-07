//
// Created by 陈海斌 on 2020-01-25.
//

#include <string>
#include <iostream>
using namespace std;

//divide two integers without using multiplication, division and mod operator.

//思路1 减法 超时
/*
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend < INT32_MIN or divisor < INT32_MIN or dividend > INT32_MAX or divisor > INT32_MAX)
            return INT32_MAX;
        long dividend_tmp = dividend;
        long divisor_tmp = divisor;
        long res = 0;
        int negative = 1;
        if ((dividend < 0 and divisor > 0) or (dividend > 0 and divisor < 0))
            negative = -1;
        if (dividend_tmp < 0)
            dividend_tmp = -dividend_tmp;
        if (divisor_tmp < 0)
            divisor_tmp = -divisor_tmp;
        while (dividend_tmp >= divisor_tmp)
        {
            dividend_tmp -= divisor_tmp;
            res += 1;
        }
        return res * negative;
    }
};
*/
//思路2 位运算

// 迭代写法
int add(int num1, int num2){
    int sum = num1 ^ num2;
    int carry = (num1 & num2) << 1;
    while(carry != 0){
        int a = sum;
        int b = carry;
        sum = a ^ b;
        carry = (a & b) << 1;
    }
    return sum;
}

int substract(int num1, int num2){
    int subtractor = add(~num2, 1);// 先求减数的补码（取反加一）
    int result = add(num1, subtractor); // add()即上述加法运算　　
    return result ;
}

//乘法 按上面的方式做会超时的
int multiply(int a, int b) {
    //将乘数和被乘数都取绝对值　
    int multiplicand = a < 0 ? add(~a, 1) : a;
    int multiplier = b < 0 ? add(~b , 1) : b;
    //计算绝对值的乘积　　
    int product = 0;
    while(multiplier > 0) {
        if((multiplier & 0x1) > 0) {// 每次考察乘数的最后一位　　　　
            product = add(product, multiplicand);
        }
        multiplicand = multiplicand << 1;// 每运算一次，被乘数要左移一位　　　　
        multiplier = multiplier >> 1;// 每运算一次，乘数要右移一位（可对照上图理解）　　
    }
    //计算乘积的符号　　
    if((a ^ b) < 0) {
        product = add(~product, 1);
    }
    return product;
}

//用减法
int divide_v1(int a, int b)
{
    if (a == INT32_MIN && b == -1)
        return INT32_MAX;
    long dividend = labs(a);
    long divisor = labs(b);
    long res = 0;
    int sign = a > 0 ^ b > 0 ? -1 : 1;
    while (dividend >= divisor)
    {
        long tmp = divisor, m = 1;
        while (tmp << 1 <= dividend)
        {
            tmp = tmp << 1;
            m = m << 1;
        }
        dividend -= tmp;
        res += m;
    }
    return res * sign;
}

// 本质上是有序数组的查找 可以用排序数组加速
// https://github.com/azl397985856/leetcode/blob/master/problems/29.divide-two-integers.md
int divide_v2(int a,int b)
{
    if (a == INT32_MIN && b == -1)
        return INT32_MAX;
    // 先取被除数和除数的绝对值
    long dividend = labs(a);
    long divisor = labs(b);
    long quotient = 0;// 商
    long remainder = 0;// 余数
    for(int i = 31; i >= 0; i--) {
        //比较dividend是否大于divisor的(1<<i)次方，不要将dividend与(divisor<<i)比较，而是用(dividend>>i)与divisor比较，
        //效果一样，但是可以避免因(divisor<<i)操作可能导致的溢出，如果溢出则会可能dividend本身小于divisor，但是溢出导致dividend大于divisor
        if (dividend >= (divisor<<i)) {
            quotient = quotient + (1 << i);
            dividend = dividend - (divisor << i);
        }
    }
    // 确定商的符号
    if((a ^ b) < 0){
        // 如果除数和被除数异号，则商为负数
        quotient = -quotient;
    }
    return quotient;// 返回商
}
/*
int main()
{
    // cout << (-2147483648 << 1) << endl;
    //Solution s;
    //cout << s.divide(-2147483648,1);
    cout << divide_v2(-2147483648,-1);
}
*/