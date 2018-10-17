#include "sumtree.h"


SumTree::SumTree(long maxsize) {
    _maxsize = maxsize;
    _write_pointer = 0;
    _depth = 0;
    _data_offset = 0;

    _rebuild(_maxsize);
}

void SumTree::append(long item, long size) {
    long prev_size = _tree[_data_offset + _write_pointer];

    _data[_write_pointer] = item;
    _update_size(_write_pointer, size - prev_size);

    _write_pointer = (_write_pointer + 1)% _maxsize;
}

long SumTree::__len__() {
    return _tree[0];
}

std::pair<long,long> SumTree::__getitem__(long value) {
    std::size_t search_idx = 0; long search_depth = 1;

    while (search_depth++ <= _depth) {
        long left_value = _tree[_left_child_of(search_idx)];

        if (value >= left_value) {
            search_idx = _right_child_of(search_idx);
            value -= left_value;
        } else { search_idx = _left_child_of(search_idx); }
    }

    return {_data[search_idx - _data_offset], value };
}

void SumTree::_update_size(std::size_t data_idx, long size) {
    std::size_t idx = _data_offset + data_idx;

    while (true) {
        _tree[idx] += size;
        if (idx == 0) break;
        idx = _parent_of(idx);
    }
}

void SumTree::_rebuild(long new_size) {
    std::vector<int> sizes(_tree.begin() + _data_offset, _tree.end());
    _tree.clear(); _data_offset = 0; _depth = 0;

    while (_max_elem(_depth) < new_size) {
        _data_offset += _max_elem(_depth++);
    }

    _tree.resize(_data_offset + _max_elem(_depth));
    _tree.clear();
    for (std::size_t i = 0; i < sizes.size(); ++i) {
        _update_size(i, sizes[i]);
    }

    _data.resize(new_size);
}

std::size_t SumTree::_max_elem(long depth) { return (std::size_t) pow(2, depth); }
std::size_t SumTree::_parent_of(std::size_t idx) { return (std::size_t) floor((idx - 1) / 2); }
std::size_t SumTree::_left_child_of(std::size_t idx) { return 2 * idx + 1; }
std::size_t SumTree::_right_child_of(std::size_t idx) { return 2 * idx + 2; }
