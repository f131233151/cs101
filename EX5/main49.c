
#include <stdio.h>

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod);
        return;
    }

    // 第 1 步：將 n-1 個圓盤從起始柱移到輔助柱
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);

    // 第 2 步：將最大的圓盤移到目標柱
    printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod);

    // 第 3 步：將 n-1 個圓盤從輔助柱移到目標柱
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int n = 3;
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}
