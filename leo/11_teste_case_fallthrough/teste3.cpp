int exemplo_switch_cpp(int x) {
    switch (x) {
        case 1:
            x = x + 100;  // case com conteudo e sem break: deve separar do proximo
        case 2:
            x = x + 200;
            break;
        case 3:           // case vazio: deve unir com o proximo
        case 4:
            x = x + 400;
            break;
        default:
            x = -1;
            break;
    }
    return x;
}
