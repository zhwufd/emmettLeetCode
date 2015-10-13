uint32_t reverseBits(uint32_t n){
    for(int i = 0; i < 16; i++){
        int j = 31 - i;
        uint32_t si = (n>>i) & 1;
        uint32_t sj = (n>>j) & 1;
        if( si ^ sj){
            n ^= ((1U<<i) | (1U<<j));
        }
    }
    return n;
}
