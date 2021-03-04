#include "IdRequestDTO.h"

IdRequestDTO::IdRequestDTO(const IdRequest& req) { (void)req; }

bool IdRequestDTO::serialize(IdRequest& req) const {
    (void)req;
    (void)this;
    return true;
}
