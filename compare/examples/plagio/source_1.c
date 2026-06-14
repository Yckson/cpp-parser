#include <stdio.h>

#define TOTAL_PACKAGES 40000
#define MAXIMUM_BYTE 3
#define MAXIMUM 512

typedef struct {
    char storage[MAXIMUM][MAXIMUM_BYTE];
    int length;
    int precedence;
} PACKAGE;

void exchange(PACKAGE *a, PACKAGE *b);
void heapify(PACKAGE arr[], int n, int i);
void heapsort(PACKAGE arr[], int n);

void write_buffer(FILE *file, PACKAGE buffer[], int buffer_index) {
    if(buffer_index != 0) {
        heapsort(buffer, buffer_index);
        for(int i = 0; i < buffer_index; i++) {
            fprintf(file, "|");
            for(int j = 0; j < buffer[i].length; j++) {
                fprintf(file, "%s", buffer[i].storage[j]);
                if(j < buffer[i].length - 1) {
                    fprintf(file, ",");
                }
            }
            fprintf(file, "|");
        }
        fprintf(file, "\n");
    }
}

void heapify(PACKAGE arr[], int n, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if(l < n && arr[l].precedence < arr[smallest].precedence) smallest = l;
    if(r < n && arr[r].precedence < arr[smallest].precedence) smallest = r;
    if(smallest != i) {
        exchange(&arr[i], &arr[smallest]);
        heapify(arr, n, smallest);
    }
}

void heapsort(PACKAGE arr[], int n) {
    for(int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    for(int i = n - 1; i > 0; i--) {
        exchange(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void exchange(PACKAGE *a, PACKAGE *b) {
    PACKAGE auxiliar = *a;
    *a = *b;
    *b = auxiliar;
}

int main(int argc, char *argv[]) {
    char *input_filename = argv[1];
    char *output_filename = argv[2];
    FILE *input = fopen(input_filename, "r");
    if(input == NULL) {
        perror("INPUT OPEN ERROR\n");
        return 1;
    }
    FILE *output = fopen(output_filename, "w");
    if(output == NULL) {
        perror("OUTPUT OPEN ERROR\n");
        fclose(input);
        return 1;
    }
    int number_of_packets, max_number_bytes;
    int buffer_index = 0;
    int current_bytes = 0;
    static PACKAGE buffer[TOTAL_PACKAGES];
    if(fscanf(input, "%d %d\n", &number_of_packets, &max_number_bytes) != 2) {
        fprintf(stderr, "INPUT LOAD ERROR\n");
        fclose(input);
        fclose(output);
        return 1;
    }
    if(number_of_packets > TOTAL_PACKAGES) {
        fprintf(stderr, "#PACKAGES (%d) EXCEEDS LIMIT (%d)\n", number_of_packets, TOTAL_PACKAGES);
        fclose(input);
        fclose(output);
        return 1;
    }
    for(int i = 0; i < number_of_packets; i++) {
        PACKAGE current_package;
        if(fscanf(input, "%d %d", &current_package.precedence, &current_package.length) != 2) {
            fprintf(stderr, "INVALID PACKAGE FORMAT %d\n", i + 1);
            break; 
        }
        for(int j = 0; j < current_package.length; j++) {
            if(fscanf(input, "%s", current_package.storage[j]) != 1) {
                fprintf(stderr, "Erro: Falha ao ler dados do pacote %d.\n", i + 1);
                break;
            }
        }
        if(current_bytes + current_package.length > max_number_bytes) {
            write_buffer(output, buffer, buffer_index);
            buffer[0] = current_package;
            buffer_index = 1;
            current_bytes = current_package.length;

        }
        else {
            buffer[buffer_index] = current_package;
            buffer_index++;
            current_bytes += current_package.length;
            if(current_bytes == max_number_bytes) {
                write_buffer(output, buffer, buffer_index);  
                buffer_index = 0;
                current_bytes = 0;
            }
        }
    }
    if(buffer_index > 0) write_buffer(output, buffer, buffer_index);
    fclose(input);
    fclose(output);
    return 0;
}