class Solution {
	public:
		bool isPowerOfTwo(int n) {
			if( n <= 0){
				return false;
			}
			else if(n == 1){
				return true;
			}
			else{
				while(n > 1){
					if( n%2 == 0){
						n = n/2;
					}
					else{
						return false;
					}
				}
				if(n == 1)
					return true;
			}
		}
};
