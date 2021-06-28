/*
3.59��
�������� 64 λ�з���ֵ x �� y �� 128 λ�˻�
�� x �� y ����128λʱ��
x = 2^64 * xk + xi ������ xi ��ʾ�� 64 λ��xk ��ʾ�� 64 λ
y = 2^64 * yk + yi ������ yi ��ʾ�� 64 λ��yk ��ʾ�� 64 λ
x * y = (2^64 * xk + xi) * (2^64 * yk + yi)
      = xk * yk * 2^128 + (xk * yi + xi * yk) * 2^64 + xi * yi
      = (xk * yi + xi * yk) * 2^64 + xi * yi ������128λ�Ĳ�����ȥ
      = (xk * yi + xi * yk + zk) * 2^64 + zi ������ zi ��û�г���64λ�Ĳ��֣�zk �ǳ����Ĳ���

   y in %rdx, x in %rsi
 store_prod:
    movq    %rdx, %rax           # %rax = %rdx (%rax = yi)
    cqto                         # %rdx ����Ϊ %rax �ķ�����չλ���� %rdx = yk
    movq    %rsi, %rcx           # %rcx = %rsi (%rcx = xi)
    sarq    $63, %rcx            # %rcx ����63λ��Ϊ y �ķ�����չλ���� %rcx = xk
    imulq   %rax, %rcx           # %rcx = %rax * %rcx = yi * xk �з��ų˷�����ȡ��64λ
    imulq   %rsi, %rdx           # %rdx = %rdx * %rsi = yk * xi �з��ų˷�����ȡ��64λ
    addq    %rdx, %rcx           # %rcx = xk * yi + xi * yk
    mulq    %rsi                 # R[%rdx]:R[%rax] <- %rsi*R[%rax] �޷���ȫ�˷�, ��λ %rdx = zk����λ %rax = zi
    addq    %rcx, %rdx           # %rdx = %rdx + %rcx = xk * yi + xi * yk + zk
    movq    %rax, (%rdi)         # ��64λ %rax ���ڵ͵�ַ
    movq    %rdx, 8(%rdi)        # ��64λ %rdx ���ڸߵ�ַ
    ret
 */