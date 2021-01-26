#include "FunctionCallArgument.h"

FunctionCallArgument ::FunctionCallArgument(int32_t intArg) : m_argument(intArg) {}

std::variant<int32_t> FunctionCallArgument::getArgument() { return m_argument; }
