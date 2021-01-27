#include "RequestDTO.h"

RequestDTO::RequestDTO(const Request& request) {

    m_id = (uint32_t)request.id;

    switch (request.which_message) {

    case Request_message_function_call_MSGTYPE:
        m_request = FunctionCallRequestDTO(request.message.function_call);
    default:
        m_request = std::monostate();
    }
}
