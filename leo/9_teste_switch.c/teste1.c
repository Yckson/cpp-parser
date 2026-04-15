
//Lembrar ao professor que, pela definição de bloco básico
//o switch não pode ter seus cases unidos, pois mesmo
//que o código siga o fluxo completo depois de entrar
//em um caso, o ponto de início não é definido

//Isso permite colocar lixo em um bloco no primeiro case
//Que nunca será executado

int f(int x) { 
    switch (x) { 
        case 1: 
            x += 1; 
        case 2: 
            x += 2;  
        default: 
            x = 0; 
    } 
    
    return x; 
} 