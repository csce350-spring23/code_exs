#ifndef ROD_CUTTING_H
#define ROD_CUTTING_H

#include <vector>

struct cut_value{
    int cut;
    int value;

    cut_value(int c, int v):
        cut(c),
        value(v)
        {}
};

std::vector<int> get_cuts(int length, std::vector<cut_value> cvs);

#endif //ROD_CUTTING_H