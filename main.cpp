#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf
#include <stdlib.h>

uint32_t ntol(uint32_t a){
	uint32_t a1=(a & 0xff000000)>>24;
	uint32_t a2=(a & 0x00ff0000)>>8;
	uint32_t a3=(a & 0x0000ff00)<<8;
	uint32_t a4=(a & 0x000000ff)<<24;
	a=a1|a2|a3|a4;
	return a;
}

uint32_t read_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Unable to open file %s\n", filename);
        exit(1);
    }

    uint32_t num;
    if (fread(&num, sizeof(num), 1, file) != 1) {
        fprintf(stderr, "Unable to read from file %s\n", filename);
        exit(1);
    }

    fclose(file);
    return ntol(num);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file1> <file2>\n", argv[0]);
        exit(1);
    }

    uint32_t num1 = read_file(argv[1]);
    uint32_t num2 = read_file(argv[2]);
    uint32_t sum = num1 + num2;

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", num1, num1, num2, num2, sum, sum);

    return 0;
}
