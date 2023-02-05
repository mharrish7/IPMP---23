int Solution::repeatedNumber(const vector<int> &A) {
    int c1 = 0;
    int c2 = 0;
    int e1 = -1;
    int e2 = -1;
    
    for(auto x: A){
        
        if(e1 == x){
            c1++;
        }
        else if(e2 == x){
            c2++;
        }
        else if(c1 == 0){
            e1 = x;
            c1++;
        }
        else if(c2 == 0){
            e2 = x;
            c2++;
        }
        else{
            c1--;
            c2--;
        }
    }
    
    
    c1 = 0 ;
    c2 = 0 ;
    for(auto x: A){
        if(x == e1){
            c1++;
        }
        
        if(x == e2){
            c2++;
        }
    }
    
    if(c1 > A.size()/3){
        return e1;
    }
        
    if(c2 > A.size()/3){
        return e2;
    }
    return -1;
}
