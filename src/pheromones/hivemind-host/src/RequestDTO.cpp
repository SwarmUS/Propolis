#include "RequestDTO.h"
RequestDTO RequestDTO::encode(const Request& request) {
    RequestDTO requestDTO;

    // TODO: change to uint32 in pheromones
    requestDTO.id = (uint32_t)request.id;

    switch (request.which_message) {

    case Request_message_function_call_MSGTYPE:
        requestDTO.m_request = FunctionCallRequestDTO::encode(request.message.function_call);
    }
}

RequestDTO::RequestDTO(const Request& request) {

    m_id = (uint32_t)request.id;

    switch (request.which_message) {

    case Request_message_function_call_MSGTYPE:
        m_request = FunctionCallRequestDTO::encode(request.message.function_call);
    }
}
