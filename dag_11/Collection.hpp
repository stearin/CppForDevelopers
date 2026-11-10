#ifndef COURSE_COLLECTION_HPP
#define COURSE_COLLECTION_HPP

#include <vector>

template <typename T>
class Collection {
public:
    void add(const T& value) {
        values_.push_back(value);
    }

    std::size_t size() const {
        return values_.size();
    }

    const T& at(std::size_t index) const {
        return values_.at(index);
    }

    const std::vector<T>& values() const {
        return values_;
    }

private:
    std::vector<T> values_;
};

#endif
