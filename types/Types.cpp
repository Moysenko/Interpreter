#include "Types.h"

void SetToDefault(const Type& type_name, MultiType& value) {
    switch (type_name.name)
    {
    case Type::INT:
        value = 0;
        break;
    case Type::STRING:
        value = "";
        break;
    case Type::BOOL:
        value = false;
        break;
    case Type::VOID:
        value = nullptr;
        break;
    }
}

bool HoldsType(const Type& type_name, const MultiType& value) {
    switch (type_name.name)
    {
    case Type::INT:
        return std::holds_alternative<int>(value);
    case Type::STRING:
        return std::holds_alternative<std::string>(value);
    case Type::BOOL:
        return std::holds_alternative<bool>(value);
    default:
        return false;
        break;
    }
}