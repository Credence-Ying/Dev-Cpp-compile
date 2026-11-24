#include <stdio.h>
#include <string.h>

int main(void)
{
    char bits[200];
    int cnt = 0;
    int c;
    int i, j, b, p, t, k;
    char seg[8][8];
    int isZero[8];

    /* 不管输入分几行，把读到的所有 '0'/'1' 拼起来，凑满 128 位为止 */
    while (cnt < 128 && (c = getchar()) != EOF) {
        if (c == '0' || c == '1') {
            bits[cnt] = (char)c;
            cnt++;
        }
    }
    if (cnt < 128) return 0;

    /* 每 16 位一段，每段 4 位十六进制 */
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 4; j++) {
            int val = 0;
            for (b = 0; b < 4; b++) {
                val = val * 2 + (bits[i * 16 + j * 4 + b] - '0');
            }
            seg[i][j] = "0123456789abcdef"[val];
        }
        seg[i][4] = '\0';
    }

    /* 去前导零 + 标记全零段 */
    for (i = 0; i < 8; i++) {
        k = 0;
        while (seg[i][k] == '0' && seg[i][k + 1] != '\0') k++;
        if (k > 0) {
            t = 0;
            for (p = k; seg[i][p] != '\0'; p++) {
                seg[i][t] = seg[i][p];
                t++;
            }
            seg[i][t] = '\0';
        }
        isZero[i] = (strcmp(seg[i], "0") == 0) ? 1 : 0;
    }

    /* 找最长的连续全零段（>=2，同长取首次） */
    {
        int bestStart = -1, bestLen = 0, len;
        for (i = 0; i < 8; i++) {
            if (isZero[i] == 0) continue;
            j = i;
            while (j < 8 && isZero[j] == 1) j++;
            len = j - i;
            if (len >= 2 && len > bestLen) {
                bestStart = i;
                bestLen = len;
            }
            i = j - 1;
        }

        if (bestStart == -1) {
            for (i = 0; i < 8; i++) {
                if (i > 0) putchar(':');
                printf("%s", seg[i]);
            }
        } else {
            for (i = 0; i < bestStart; i++) {
                if (i > 0) putchar(':');
                printf("%s", seg[i]);
            }
            printf("::");
            for (i = bestStart + bestLen; i < 8; i++) {
                if (i > bestStart + bestLen) putchar(':');
                printf("%s", seg[i]);
            }
        }
        putchar('\n');
    }
    return 0;
}
