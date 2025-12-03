## KMP算法

```python

def build_next(patt):
    """计算next数组
    """
    next = [0]
    prefix_len = 0
    i = 1
    while i < len(patt):
        if patt[prefix_len - 1] == patt[i]:
            prefix_len += 1
            next.append(prefix_len)
        else:
            prefix_len = next[prefix_len - 1]
            if prefix_len == 0:
                next.append(0)
                i += 1

    return next

def kmp_search(string, patt):
    next = build_next(patt)
    i = 0                                                   # 主串中的指针
    j = 0                                                   # 子串中的指针
    while i < len(string):
        if string[i] == patt[j]:                            # 字符匹配，指针后移
            i += 1
            j += 1
        elif j > 0:                                         # 字符不匹配，根据next跳过子串前面的若干字符
            j = next[j - 1]
        else:                                               # 子串第一个字符就不匹配
            i += 1

        if j == len(patt):
            return i - j

    return -1                                               # 未招到

```



