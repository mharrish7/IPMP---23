int Solution::firstMissingPositive(vector<int> &A) {
    
    for(int i = 0; i < A.size(); i++){
        if(A[i] < 0){
            A[i] = A.size()+2;
        }
    }
    
    for(int i =0; i < A.size(); i++){
        if(A[i] != 0 && abs(A[i] - 1) < A.size()){
            A[abs(A[i]) - 1] = -A[abs(A[i]) -1 ];
        }
    }
    
    for(int i = 0; i < A.size();i++ ){
        if(A[i] > 0){
            return i+1;
        }
    }
    
    return A.size()+1;
    
}