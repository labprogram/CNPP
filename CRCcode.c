// Generate CRC code for Polynomial 8.

#include <stdio.h>
#include <stdint.h>

#define CRC_POLY 0x9

uint8_t calculate_crc8(const uint8_t *data, size_t length) {
    uint8_t crc = 0xFF;
    size_t i, j;

    for (i = 0; i < length; ++i) {
        crc ^= data[i];
        for (j = 0; j < 8; j++) {
            if (crc & 0x80) {
                crc = (crc << 1) ^ CRC_POLY;
            } else {
                crc <<= 1;
            }
        }
    }

    return crc;
}

int main() {
    const char message[] = "Hello, world!";
    size_t length = sizeof(message) - 1;

    uint8_t crc = calculate_crc8((const uint8_t *)message, length);

    printf("Message: '%s'\n", message);
    printf("CRC-8: 0x%02X\n", crc);

    return 0;
}
