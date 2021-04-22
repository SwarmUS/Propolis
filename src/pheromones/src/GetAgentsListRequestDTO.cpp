#include "GetAgentsListRequestDTO.h"

GetAgentsListRequestDTO::GetAgentsListRequestDTO(const GetAgentsListRequest& req) { (void)req; }

bool GetAgentsListRequestDTO::serialize(GetAgentsListRequest& req) const {
    (void)req;
    (void)this;
    return true;
}
