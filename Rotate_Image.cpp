void RotateInnerSquare(vector<vector<int>>& matrix, int lowestIndex, int highestIndex);

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int highestIndex = matrix.size() - 1;
        int lowestIndex = 0;
        RotateInnerSquare(matrix, lowestIndex, highestIndex);
    }
};

// Recursive function starts by rotating outermost square, then moving inward
void RotateInnerSquare(vector<vector<int>>& matrix, int lowestIndex, int highestIndex){
    if(highestIndex < 1)
        return;
    
    int store;  // store value to it isn't overwritten
    int replace;    // value to replace
    //  [row][col]
    //  rotates 4 values each iteration 
    for(int i = 0; i < highestIndex - lowestIndex; i++){
        store = matrix[lowestIndex + i][highestIndex];
        replace = matrix[highestIndex][highestIndex - i];   
        
        matrix[lowestIndex + i][highestIndex] = matrix[lowestIndex][lowestIndex + i];
        matrix[highestIndex][highestIndex - i] = store;
        
        store = replace;
        replace = matrix[highestIndex - i][lowestIndex];
        
        matrix[highestIndex - i][lowestIndex] = store;
        matrix[lowestIndex][lowestIndex + i] = replace;
    }
    
    RotateInnerSquare(matrix, lowestIndex + 1, highestIndex - 1);
}
