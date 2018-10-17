#ifndef SUMTREE_SUMTREE_H
#define SUMTREE_SUMTREE_H

#include <math.h>
#include <vector>
#include <iostream>
#include <cstdlib>


class SumTree {
private:
    long _depth;
    long _size;
    long _maxsize;
    long _write_pointer;
    std::size_t _data_offset;
    std::vector<long> _tree;
    std::vector<long> _data;

    void _update_size(std::size_t data_idx, long size);
    void _rebuild(long new_size);

    std::size_t _max_elem(long depth);
    std::size_t _parent_of(std::size_t idx);
    std::size_t _left_child_of(std::size_t idx);
    std::size_t _right_child_of(std::size_t idx);

public:
    SumTree(long maxsize);
    long __len__();
    void append(long item, long size);
    std::pair<long,long> __getitem__(long value);
};


#endif //SUMTREE_SUMTREE_H
