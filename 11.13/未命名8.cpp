/* ============================================================
 * 实验6-03：删除空字符
 * 1. 用字符指针数组指向 n 行文本，无冗余存储（按需 malloc）
 * 2. 单独函数完成：删前导空格/tab，多个空格合并为一个
 * ============================================================ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 原地处理：删前导空格和 tab，多个空格合并为一个。tab 原样保留 */
void trimAndMerge(char *s)
{
    char *r = s;          /* 读指针 */
    char *w = s;          /* 写指针 */
    int started = 0;      /* 是否已遇到第一个非空白字符 */
    int last_was_space = 0;  /* 上一个写入的是否是空格 */

    while (*r != '\0') {
        if (*r == ' ' || *r == '\t') {
            if (!started) {
                /* 前导空白：跳过 */
                r++;
                continue;
            }
            if (*r == ' ') {
                /* 空格：仅当上一个写入的不是空格时才写一个 */
                if (!last_was_space) {
                    *w++ = *r;
                    last_was_space = 1;
                }
            } else {
                /* tab：原样写入，并重置空格标记（tab 打断空格串） */
                *w++ = *r;
                last_was_space = 0;
            }
        } else {
            *w++ = *r;
            last_was_space = 0;
            started = 1;
        }
        r++;
    }
    *w = '\0';
}

int main(void)
{
    int n;
    scanf("%d", &n);
    getchar();   /* 吃掉 n 后面的换行 */

    char **lines = (char **)malloc(n * sizeof(char *));
    char buf[82];   /* 最多 80 字符 + 换行 + '\0' */

    for (int i = 0; i < n; i++) {
        fgets(buf, sizeof(buf), stdin);
        buf[strcspn(buf, "\n")] = '\0';   /* 去掉末尾换行 */

        trimAndMerge(buf);   /* 原地处理 */

        int len = (int)strlen(buf);
        lines[i] = (char *)malloc((len + 1) * sizeof(char));   /* 无冗余 */
        if (lines[i] == NULL) return 1;
        strcpy(lines[i], buf);
    }

    for (int i = 0; i < n; i++) {
        printf("%s\n", lines[i]);
        free(lines[i]);
    }
    free(lines);
    return 0;
}
