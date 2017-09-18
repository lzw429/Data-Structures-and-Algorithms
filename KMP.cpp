// KMP算法是一种快速的模式匹配算法。
#include <iostream>
#include <string.h>

using namespace std;

int kmp(const char *text, const char *find) {
    if (text == '\0' || find == '\0')
        return -1;
    int find_len = strlen(find);
    int text_len = strlen(text);
    if (text_len < find_len)
        return -1;

    int map[find_len] = {0};
    int i = 2;
    int j = 0;

    for (i = 2; i <= find_len; i++) {
        while (true) {
            if (find[i - 1] == find[j]) {
                j++;
                map[i - 1] = j;
                break;
            } else {
                if (j == 0) {
                    map[i] = 0;
                    break;
                }

            }
        }
    }
}