#pragma once

#include <variant>
#include <string>

struct Type {
    enum Name {
        INT,
        STRING,
        BOOL,
        VOID
    };

    Type(Name other_name): name(other_name) {}

    Name name;
};

typedef std::variant<int, std::string, bool> MultiType;

void SetToDefault(const Type& type_name, MultiType& value);

bool HoldsType(const Type& type_name, const MultiType& value);

/*
class MultiType {

    MultiType(const value_type& new_value) {
        value_ = new_value;
    }

    MultiType& operator= (value_type new_value) {
        Swap(new_value, *this);
        return *this;
    }

    friend void Swap(MultiType& first, MultiType& second) {
        MultiType tmp();
        first.PutValue(tmp);
        second.PutValue(first.value_);
        second.value_ = tmp;
    }

    void PutValue(value_type& target) {
        if (std::holds_alternative<int>(value_)) {
            target = std::get<int>(value_);
        } else if (std::holds_alternative<std::string>(value_)) {
            target = std::get<std::string>(value_);
        }
    }

    value_type value_;
};
*/