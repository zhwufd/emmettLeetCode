double myPow(double x, int n) {
    if(n < 0){
        x = 1.0/x;
        n = -n;
    }
    int flag = 1.0;
    if(x < 0){
        x = -x;
        if(n%2 != 0)
            flag = -1.0;
    }
    double p = 1.0;
    for(int j = 1; j <= n; j++){
        double q = p * x;
        double diff = p - q;
        if(diff > -1e-15 && diff < 1e-15 ){
            break;
        }
        p = q;
    }
    return p*flag;
}
