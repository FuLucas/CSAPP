/*
 3.61��
 ����xpΪ��ָ�룬�Կ�ָ�� NULL �����ݵĲ�������
 */
long cread_alt(long *xp) {
    long temp = 0;
    long *p = xp ? xp : &temp;
    return *p;
}