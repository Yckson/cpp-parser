#include <stdio.h>

// Constantes
#define MAXIMO 512
#define MAX_BYTE 3
// Limite maximo que o programa suporta
#define TOTAL_PACOTES 40000

/**
 *  Struct
 */
typedef struct {
    int priority;
    int size;
    char data[MAXIMO][MAX_BYTE];
} Packet;

// Auxiliar
void swap(Packet *a, Packet *b) {
    Packet temp = *a;
    *a = *b;
    *b = temp;
}

void heapificar(Packet arr[], int n, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l].priority < arr[smallest].priority) {
        smallest = l;
    }
    if (r < n && arr[r].priority < arr[smallest].priority) {
        smallest = r;
    }

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        heapificar(arr, n, smallest);
    }
}

void heapsort(Packet arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapificar(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapificar(arr, i, 0);
    }
}


void write_buffer(FILE *fp, Packet buffer[], int contador_buf) {
    if (contador_buf == 0) return;
    heapsort(buffer, contador_buf);

    for (int i = 0; i < contador_buf; i++) {
        fprintf(fp, "|");
        for (int j = 0; j < buffer[i].size; j++) {
            fprintf(fp, "%s", buffer[i].data[j]);
            if (j < buffer[i].size - 1) {
                fprintf(fp, ",");
            }
        }
        fprintf(fp, "|");
    }
    fprintf(fp, "\n");
}

/**
 * Funcao principal
 */
int main(int argc, char *argv[]) {

    char *input_filename = argv[1];
    char *output_filename = argv[2];

    // Abertura dos Arquivos
    FILE *infile = fopen(input_filename, "r");
    if (infile == NULL) {
        perror("Erro na abertura do arquivo de entrada");
        return 1;
    }

    FILE *outfile = fopen(output_filename, "w");
    if (outfile == NULL) {
        perror("Erro na abertura do arquivo de saida");
        fclose(infile);
        return 1;
    }

    int n_packets, bytes_maximos;
    if (fscanf(infile, "%d %d\n", &n_packets, &bytes_maximos) != 2) {
        fprintf(stderr, "Formato de cabecalho invalido no arquivo de entrada.\n");
        fclose(infile);
        fclose(outfile);
        return 1;
    }


    static Packet buffer[TOTAL_PACOTES];

    if (n_packets > TOTAL_PACOTES) {
        fprintf(stderr, "Erro: O numero de pacotes (%d) excede o limite maximo do programa (%d).\n",
                n_packets, TOTAL_PACOTES);
        fclose(infile);
        fclose(outfile);
        return 1;
    }

    int contador_buf = 0;
    int bytes_atuais = 0;

    for (int i = 0; i < n_packets; i++) {
        Packet novo_pac;

        if (fscanf(infile, "%d %d", &novo_pac.priority, &novo_pac.size) != 2) {
            fprintf(stderr, "Erro: Formato invalido para o pacote %d.\n", i + 1);
            break; 
        }

        for (int j = 0; j < novo_pac.size; j++) {
            if (fscanf(infile, "%s", novo_pac.data[j]) != 1) {
                fprintf(stderr, "Erro: Falha ao ler dados do pacote %d.\n", i + 1);
                break;
            }
        }
        
        if (bytes_atuais + novo_pac.size > bytes_maximos) {
            write_buffer(outfile, buffer, contador_buf);
            
            buffer[0] = novo_pac;
            contador_buf = 1;
            bytes_atuais = novo_pac.size;

        } else {
            buffer[contador_buf] = novo_pac;
            contador_buf++;
            bytes_atuais += novo_pac.size;

            if (bytes_atuais == bytes_maximos) {
                write_buffer(outfile, buffer, contador_buf);
                
                contador_buf = 0;
                bytes_atuais = 0;
            }
        }
    } // Fim do loop de pacotes

    // Processamento Final
    if (contador_buf > 0) {
        write_buffer(outfile, buffer, contador_buf);
    }

    // Limpeza
    fclose(infile);
    fclose(outfile);

    return 0;
}