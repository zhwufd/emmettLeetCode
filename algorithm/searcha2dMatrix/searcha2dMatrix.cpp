class Solution {
    public:
        bool bsearch(vector<int>& v, int target){
            int n = v.size();
            if(n == 0)
                return false;
            int i = 0;
            int j = n - 1;
            int mid = (i + j)/2;
            while(j - i >= 0){
                if(target > v[mid])
                    i = mid + 1;
                else if(target < v[mid])
                    j = mid - 1;
                else
                    return true;
                mid = (i + j)/2;
            }
            return false;
        }

        bool searchMatrix(vector<vector<int> >& matrix, int target){
            int n = matrix.size();
            if(n == 0)
                return false;
            else if(n == 1)
                return bsearch(matrix[0], target);
            else{
                int i = 0;
                int j = n - 1;
                int mid = (i + j)/2;
                while(j - i > 1){
                    if(target > matrix[mid][0])
                        i = mid;
                    else if(target == matrix[mid][0])
                        return true;
                    else
                        j = mid - 1;
                    mid = (i +j)/2;
                }
                if((j -1) == i){
                    if(target >= matrix[j][0])
                        return bsearch(matrix[j], target);
                }
                return bsearch(matrix[i], target);
            }
        }
};
