/*
 9.11�⣺
 A. 00001001111100
 B.
    |  Parameter    |   Value  |
    |---------------|----------|
    |     VPN       |   0x09   |
    |   TLB index   |    0x1   |
    |    TLB tag    |   0x02   |
    |    TLB hit?   |    ��    |
    |  Page fault?  |    ��    |
    |      PPN      |   0x17   |
 C. 010111111100
 D.
    | Parameter     |  Value  |
    |---------------|---------|
    |  �ֽ�ƫ��      |   0x0   |
    |  ��������      |   0xF   |
    |  ������      |   0x17  |
    |  ��������      |    ��   |
    | ���صĻ����ֽ�  |    -    |
 */


/*
 9.13�⣺
 A. 00000001000000
 B. 
    |  Parameter    |   Value  |
    |---------------|----------|
    |     VPN       |   0x01   |
    |   TLB index   |    0x1   |
    |    TLB tag    |   0x00   |
    |    TLB hit?   |    ��    |
    |  Page fault?  |    ��    |
    |      PPN      |     -    |
 C/D. Page Fault
 */


/*
 9.15�⣺
    |  Request   | Block size | Block header |
    |------------|------------|--------------|
    | malloc(3)  |     8      |     0x9      |
    | malloc(11) |     16     |     0x11     |
    | malloc(20) |     24     |     0x19     |
    | malloc(21) |     32     |     0x21     |
 */


/*
 9.19�⣺
 (1) a
 (2) d
 (3) b
 */