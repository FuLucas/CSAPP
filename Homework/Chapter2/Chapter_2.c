//Chapter 2: 2.59, 2.63, 2.67, 2.71, 2.75, 2.79, 2.83, 2.87 , 2.91, 2.95, 2.96

#include <stdio.h>

/*
2.59�⣺
(0x89ABCDEF & 0xFF) | (0x76543210 & 0xFFFFFF00)
*/


/*
2.63�⣺
*/
unsigned srl(unsigned x, int k) {
    /* Perform shift logically */
    unsigned xsra = (int) x >> k;
    int w = sizeof(int) * 8;
    unsigned z = 2 << (w - k - 1) - 1;
    return xsra & z;
}
int sra(int x, int k) {
    /* Perform shift arithmetically */
    int xsra = (unsigned) x >> k;
    int w = sizeof(int) * 8;
    int z = 1 << (w - k - 1);
    int right = xsra & (z - 1); 
    int left = z + (~(z - 1) & ~(xsra & z));
    return left | right;
}


/*
2.67�⣺
A. �羯����˵���������ڡ�1 << 32�������Ʒ�Χ��1~31
   ����λ������int_32�Ϳ�ȣ���C������ʵ�����ƶ�λ���ǶԿ�����࣬���˴��൱��û����λ��
B. ��int����Ϊ32λ�Ļ�������������
C. ��int����Ϊ16λ�Ļ�������������
*/
int int_size_is_32 (){
    int set_msb = 1 << 31;
    int beyond_msb = set_msb << 1;
    return (set_msb && !beyond_msb);
}
int int_size_is_32_in_16 (){
    int set_msb = 1 << 15 << 15 << 1;
    int beyond_msb = set_msb << 1;
    return set_msb && !beyond_msb;
}


/*
2.71�⣺
A. �������������λ������߼����ƣ���λ�����ʵ�ʽ�����ܲ����������˸������
B. ֻʹ��������λ��һ���������������£�
*/
typedef unsigned packed_t;
int xbyte(packed_t word, int bytenum) {
    int z = (int)word << ((3 - bytenum) << 3);
    int w = (sizeof(int) - 1) << 3;
    return z >> w;
}


/*
2.75�⣺
*/
int signed_high_prod(int x, int y) {
    long long s = (long long) x * y;
    return s >> 32;
}
unsigned unsigned_high_prod(unsigned x, unsigned y) {
  int s_x = x >> 31;
  int s_y = y >> 31;
  int m = signed_high_prod(x, y);
  return m + x * s_y + y * s_x;
}


/*
2.79�⣺
*/
int mul3div4 (int x) {
    int m =  (x >> 2) + (x >> 1);
    int low = ((x & 0x3) == 0x3);
    return m + low;
}


/*
2.83�⣺
A.  ��0.yyyyy������С��������kλ�õ�y.yyyyy����
    ����0.yyyyy���� = x, Y+x=x*2^k
    x=Y/(2^k-1)
B.  (1) y=101     Y=5   k=3  x=5/7
    (2) y=0110    Y=6   k=4  x=6/15=2/5
    (3) y=010011  Y=19  k=6  x=19/63
*/


/*
2.87�⣺
    ����                Hex         M           E           V               D
-0                     8000         0          -14         -0             -0.0
��С��>2��ֵ            4001      1025/1024      1       1025*2(-9)     2.001953125
512                    6000         1           9           512           512.0
���ķǹ����        03FF       1023/1024     -14     1023*2(-24)   0.000060975516
-��                     FC00        ---         ---          -��              -��
ʮ�����Ʊ�ʾΪ3BB0����   3BB0       123/64       -1       123*2^(-7)      0.9609375
*/


/*
2.91�⣺
    A. 11.0010010000111111011011
    B. 22/7=3+1/7=11+1/(2^3-1)
           =11.001001001����
    C. ���ڶ�����С������ÿһλ�����Ǵ�ͷ��ÿ��С�� *2���������λ�Ƿ���ȣ���������С�������ƶ�һλ
       �ɴ�223/71*2^8������������804��С�����ֵ�ʮ����Ϊ4/71
       ͬ��22/7*2^8������������804��С�����ֵ�ʮ����Ϊ4/7
       ��ô��С�������ٴ� *2���õ�����������ǰһ��Ϊ0����һ��Ϊ1
       ���Դӵ�9λ��ʼ��ͬ
*/


/*
2.95�⣺
*/
typedef unsigned float_bits;
/* Compute 0.5*f. If f is NaN, then return f. */
float_bits float_half (float_bits f) {
    float_bits s = f >> 31;             //sign
    float_bits exp = (f >> 23) & 0xFF;  //exponent
    float_bits frac = f & 0x7FFFFF;     //fraction
    if (exp == 0xFF)// frac==0 or frac!=0 return �� or NaN 
        return f;
    else {
        float_bits temp = (frac & 0x3 == 3);//Round to even
        if (exp == 0)
            frac = (frac >> 1) + temp;
        else if (exp == 1) {
            frac = ((frac + 0x800000) >> 1) + temp;//���ܴ���111111+1�����
            exp -= 1;
            if (frac == 0x800000) {
                frac = 0;
                exp = 1;
            }
        }
        else exp -=1;
        return (s << 31) + (exp << 23) + (frac);
    }
}


//2.96�⣺
/*
 * Compute (int) f.
 * If conversion causes overflow or f is NaN, return 0x80000000.
 */
int float_f2i(float_bits f) {
    float_bits s = f >> 31;                     //sign
    float_bits exp = ((f >> 23) & 0xFF) - 127;  //exponent
    float_bits frac = f & 0x7FFFFF;             //fraction
    if (exp < 0) //int��ʾ����С������С����ż��0ȡ��
        return 0;
    else if (exp >= 31) //Tmax = 2^31-1, Tmin = -2^31
        return 0x80000000; //�߽�����Ƿ���ǣ���Ҫ��Tmin��
    if (exp >= 23)
        frac = frac << (exp - 23);
    else
        frac = frac >> (23 - exp);  //��ż��ȡ��������Ƿ����
    return s ? -(int)frac : (int)frac;
    // if (s) return -(int)frac;
    // else return (int)frac;
}
