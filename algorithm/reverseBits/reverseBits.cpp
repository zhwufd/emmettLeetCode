uint32_t reverseBits(uint32_t n){
    vector<int> tmp(32,0);
    for(int i = 0; i < 32; i++){
        tmp[i] = n%2;
        n /= 2;
    }
    uint32_t c = 1;
    uint32_t out = 0;
    for(int i = 0; i < 32; i++){
        if(tmp[i] == 1)
            out += ( c <<(31 - i));
    }
    return out;
}
