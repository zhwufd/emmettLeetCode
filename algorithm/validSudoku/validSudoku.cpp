bool isValidSudoku(vector<vector<char> >& board){
    //check row
    for(int i = 0; i < 9; i++){
        vector<bool> exists(9, false);
        for(int j = 0; j < 9; j++){
            char c = board[i][j];
            if( c >= '1' && c <= '9'){
                if(exists[c - '1'])
                    return false;
                else
                    exists[c-'1'] = true;
            }
        }
    }
    //check col 
    for(int i = 0; i < 9; i++){
        vector<bool> exists(9, false);
        for(int j = 0; j < 9; j++){
            char c = board[j][i];
            if( c >= '1' && c <= '9'){
                if(exists[c - '1'])
                    return false;
                else
                    exists[c-'1'] = true;
            }
        }
    }
    //check 3*3
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            vector<bool> exists(9,false);
            int y = 3*i;
            int x = 3*j;
            for(int m = 0; m < 3; m++){
                for(int n = 0; n < 3; n++){
                    char c = board[y + m][x + n];
                    if( c >= '1' && c <= '9'){
                        if(exists[c - '1'])
                            return false;
                        else
                            exists[c - '1'] = true;
                    }
                }
            }
        }
    }
    return true;
}
