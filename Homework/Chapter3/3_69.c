/*
 3.69��
        void test(long i, b_struct *bp)
        i in %rdi, bp in %rsi
 1   <test>:
 2   mov    0x120(%rsi), %ecx
     # %ecx = %rsi + 0x120 (288)������ bp �� first, %ecx ���� n
 3   add    (%rsi), %rcx
     # %rcx = %rcx + %rsi������ bp �� last
     # sizeof(int) + CNT * sizeof(a_struct) = 288
 4   lea    (%rdi, %rdi, 4), %rax
 5   lea    (%rsi, %rax, 8), %rax
     # %rax = bp + 40 * i, bp �ǽṹ���ָ�룬ָ�� first
     # sizeof(a_struct) = 40
 6   mov    0x8(%rax), %rdx
     # %rdx = %rax + 0x8 = bp + 40 * i + 8��ָ��ṹ�����˵ idx
     # first ռ 8 ���ֽ�
 7   movslq %ecx, %rcx
     # mov ������չ��n ��˫����չ�����֣�x Ԫ������Ϊ long
 8   mov    %rcx, 0x10(%rax, %rdx, 8)
     # (%rax + 8 * %rdx + 16) = %rcx, long 8�ֽ�, 16 = 8 first �� + 8 idx ��
 9   retq

 A. CNT = (288 - 8) / 40 = 7
 B. typedef struct {
     long idx;
     long x[4];
 }
 */