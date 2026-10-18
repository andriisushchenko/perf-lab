#include <stdio.h>
#define N 1000
static float A[N][N], B[N][N], C[N][N];

void init(void) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            A[i][j] = (i + j) % 100 / 10.0f;
            B[i][j] = (i - j + N) % 100 / 10.0f;
        }
}
void matmul(void) {
    for (int i = 0; i < N; i++)
        for (int k = 0; k < N; k++) {
            float a = A[i][k];
            for (int j = 0; j < N; j++)
                C[i][j] += a * B[k][j];
        }
}
float checksum(void) {
    float s = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) s += C[i][j];
    return s;
}
int main(void) {
    init(); matmul();
    printf("%f\n", checksum());
    return 0;
}
