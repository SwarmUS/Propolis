#include "UserCallRequestDTO.h"
#include "UserCallDestinationDTO.h"

UserCallRequestDTO::UserCallRequestDTO(const UserCallRequest& request) :

    m_destination(destinationToDTO(request.destination)) {

    switch (request.which_request) {

    case UserCallRequest_functionCall_tag:
        m_request = FunctionCallRequestDTO(request.request.functionCall);
        break;
    default:
        m_request = std::monostate();
    }
}

UserCallRequestDTO::UserCallRequestDTO(UserCallDestinationDTO destination,
                                       const FunctionCallRequestDTO& request) :
    m_destination(destination), m_request(request) {}

UserCallDestinationDTO UserCallRequestDTO::getDestination() const { return m_destination; }

const std::variant<std::monostate, FunctionCallRequestDTO>& UserCallRequestDTO::getRequest() const {
    return m_request;
}

void UserCallRequestDTO::setDestination(UserCallDestinationDTO destination) {
    m_destination = destination;
}

void UserCallRequestDTO::setRequest(
    const std::variant<std::monostate, FunctionCallRequestDTO>& request) {
    m_request = request;
}

bool UserCallRequestDTO::serialize(UserCallRequest& request) const {

    request.destination = dtoToDestination(m_destination);

    if (const FunctionCallRequestDTO* functionRequest =
            std::get_if<FunctionCallRequestDTO>(&m_request)) {

        request.which_request = UserCallRequest_functionCall_tag;
        return functionRequest->serialize(request.request.functionCall);
    }

    return false;
}
