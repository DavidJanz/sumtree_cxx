#include "sumtree.h"


SumTree::SumTree() {
    _depth = 0;
    _data_offset = 0;
    _tree.resize((std::size_t) _max_elem(_depth));
}

long SumTree::__len__() {
    return _tree[0];
}

void SumTree::append(long item, long size) {
    if (_data.size() + 1 > _max_elem(_depth)) { _rebuild(); }

    _append(item, size);
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

void SumTree::_append(long item, long size) {
    _data.push_back(item);
    _update_size(_data.size() - 1, size);
}

std::pair<long,long> SumTree::pop_front() {
    auto front_size = _tree[_data_offset];
    auto front_item = _data[0];
    _data.erase(_data.begin());
    _tree.erase(_tree.begin());
    _rebuild();

    return {front_item, front_size};
}

void SumTree::_rebuild() {
    std::vector<int> sizes(_tree.begin() + _data_offset, _tree.end());
    _tree.clear(); _data_offset = 0; _depth = 0;

    while (_max_elem(_depth) < _data.size() + 1) { _data_offset += _max_elem(_depth++); }

    _tree.resize(_data_offset + _max_elem(_depth));
    for (std::size_t i = 0; i < _data.size(); ++i) { _update_size(i, sizes[i]); }
}

std::size_t SumTree::_max_elem(long depth) { return (std::size_t) pow(2, depth); }
std::size_t SumTree::_parent_of(std::size_t idx) { return (std::size_t) floor((idx - 1) / 2); }
std::size_t SumTree::_left_child_of(std::size_t idx) { return 2 * idx + 1; }
std::size_t SumTree::_right_child_of(std::size_t idx) { return 2 * idx + 2; }
