#include "FunctionListLengthRequestDTO.h"

FunctionListLengthRequestDTO::FunctionListLengthRequestDTO(const FunctionListLengthRequest& req) {
    (void)req;
}

bool FunctionListLengthRequestDTO::serialize(FunctionListLengthRequest& req) const {
    (void)req;
    (void)this;
    return true;
}
