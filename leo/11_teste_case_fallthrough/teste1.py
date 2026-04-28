def exemplo_match(valor):
    match valor:
        case 1:
            resultado = "um"
        case 2:
            resultado = "dois"
        case _:
            resultado = "outro"
    return resultado


def exemplo_loop(lista):
    total = 0
    for item in lista:
        if item < 0:
            continue
        if item == 99:
            break
        total += item
    return total
