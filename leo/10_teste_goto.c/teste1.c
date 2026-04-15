//Solicitação de Bruno de que labels não criassem
//Novos blocos

int f(int x) { 
    if (x < 0) goto erro; 
    return x;
        
    int y = x;
    erro: 
    return -1; 
} 