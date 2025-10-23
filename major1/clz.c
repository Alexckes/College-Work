//author: James Heath

unsigned int clz(unsigned int a) {
    unsigned int nlz = 0;
    for(int i = 31; i >=0; i--) {
        if(a & (1<<i)) {
            break;
        }
        nlz++;
    }
    return nlz;
}