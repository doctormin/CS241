//
// Created by 18123 on 2019/10/19.
//

#ifndef CS241_MYSORT_H
#define CS241_MYSORT_H

//默认排序函数
template <typename iterator>
void mySort(iterator first, iterator last) {
    for (iterator k = first; k != last; k++)
        for (iterator i = k; i != last; i++)
            if ((*i).val < (*k).val) {
                auto tmp = *i;
                *i = *k;
                *k = tmp;
            }
}

template <typename iterator, typename Compare>
void mySort(iterator first, iterator last, Compare comp) {
    for (iterator k = first; k != last; k++) {
        for (iterator i = k; i != last; i++) {
            if (comp(*i, *k)) {
                auto tmp = *i;
                *i = *k;
                *k = tmp;
            }
        }
    }
}

#endif //CS241_MYSORT_H
