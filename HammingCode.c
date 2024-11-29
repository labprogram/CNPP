// Implement Hamming code Generation for a given binary code

#include <stdio.h>

void generate_hamming_code(int data_bits[], int hamming_code[]) {
    hamming_code[0] = data_bits[2] ^ data_bits[4] ^ data_bits[6];
    hamming_code[1] = data_bits[2] ^ data_bits[5] ^ data_bits[6];
    hamming_code[3] = data_bits[4] ^ data_bits[5] ^ data_bits[6];
    hamming_code[2] = data_bits[0];
    hamming_code[4] = data_bits[1];
    hamming_code[5] = data_bits[3];
    hamming_code[6] = data_bits[7];
}

int main() {
    int data_bits[4];
    int hamming_code[7];

    printf("Enter 4-bit binary data: ");
    scanf("%1d%1d%1d%1d", &data_bits[0], &data_bits[1], &data_bits[2], &data_bits[3]);

    generate_hamming_code(data_bits, hamming_code);

    printf("Hamming code: ");
    for (int i = 0; i < 7; ++i) {
        printf("%d", hamming_code[i]);
    }
    printf("\n");

    return 0;
}
