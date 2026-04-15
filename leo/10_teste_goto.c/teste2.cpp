//Foi solicitado por bruno para simplificar o funcionamento
//do goto. Então, se for goto condicional, finaliza bloco
//Senão, continua no mesmo bloco

int f(int x) {
    if (x < 0) goto erro;
    return x;
    x = 5;
    
goto burno;
burno:
erro:
    int y = x;
    return -1;
}
