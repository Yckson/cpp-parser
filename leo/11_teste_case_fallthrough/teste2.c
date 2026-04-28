int exemplo_switch_c(int x) {
    switch (x) {
        case 1:
            x = x + 10;  // case com conteudo e sem break: deve separar do proximo
        case 2:
            x = x + 20;
            break;
        case 3:          // case vazio: deve unir com o proximo
        case 4:
            x = x + 40;
            break;
        default:
            x = 0;
            break;
    }
    return x;
}
