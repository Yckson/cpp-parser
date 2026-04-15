int f(int x) { 
    try { 
        if (x == 0) throw 1; 
        return 10 / x; 
    } catch (...) { 

    return 0; 
    
    } 
}