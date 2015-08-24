class Solution {
	public:
		bool isUgly(int num) {
			if(num <= 0){
				return false;
			}
			else{
				num = divby(num,2);
				num = divby(num,3);
				num = divby(num,5);
				if(num == 1){
					return true;
				}
				else{
					return false;
				}
			}
		}
		int divby(int num, int d) {
			while(num%d == 0){
				num = num/d;
			}
			return num;
		}
};
