#include "GetNeighborsListRequestDTO.h"

GetNeighborsListRequestDTO::GetNeighborsListRequestDTO(const GetNeighborsListRequest& req) {
    (void)req;
}

bool GetNeighborsListRequestDTO::serialize(GetNeighborsListRequest& req) const {
    (void)req;
    (void)this;
    return true;
}
