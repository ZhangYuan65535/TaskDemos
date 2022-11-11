#include <QDebug>
#include <QVector>

#include "kmp.h"

/**
 * @brief maxEqual 计算一个字符串的最大首尾呼应长度
 * @param str 目标字符串
 * @param size 字符串大小
 * @return 返回最大长度
 */
int maxEqual(const char* str, size_t size)
{
    int max = 0;
    for (int len = size - 1; len > 0; len--) {
        const char* str1 = str;
        const char* str2 = str + size - len;
        if (strncmp(str1, str2, len) == 0) {
            max = len;
            break;
        }
    }
    return max;
}

/**
 * @brief getNextArray 获取 kmp next 数组
 * @param child 目标子串
 * @return 返回 next 数组
 */
QVector<int> getNextArray(const char *child)
{
    QVector<int> nextArray{};
    int len = strlen(child);
    for (int i = 0; i < len; i++) {
        nextArray << maxEqual(child, i + 1);
    }
    nextArray.push_front(0);
    nextArray.pop_back();
    return nextArray;
}


/**
 * @brief searchChildByKmp 模式匹配
 * 在母串中查找子串首次出现的位置
 * @param parent 母串
 * @param child 子串
 * @return 子串首次出现的下标
 */
int searchChildByKmp(const char *parent, const char *child)
{
    QVector<int> nextArray = getNextArray(child);

    int i = 0;
    int j = 0;
    int plen = strlen(parent);
    int clen = strlen(child);

    while (i < plen && j < clen) {
        if (parent[i] == child[j]) {
            i++;
            j++;
        } else {
            if (j == nextArray[j]) {
                i++;
            } else {
                j = nextArray[j];
            }
        }
    }

    if (j == clen) {
        return i - j;
    }
    return -1;
}















