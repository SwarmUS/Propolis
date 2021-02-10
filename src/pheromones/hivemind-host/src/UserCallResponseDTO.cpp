#include "UserCallResponseDTO.h"

UserCallResponseDTO::UserCallResponseDTO(UserCallDestinationDTO destination,
                                         const FunctionCallResponseDTO& response) :
    m_destination(destination), m_response(response) {}

UserCallResponseDTO::UserCallResponseDTO(const UserCallResponse& response) :
    m_destination(destinationToDTO(response.destination)) {

    switch (response.which_response) {

    case UserCallResponse_functionCall_tag:
        m_response = FunctionCallResponse(response.response.functionCall);
        break;

    default:
        m_response = std::monostate();
    }
}

const std::variant<std::monostate, FunctionCallResponseDTO>& UserCallResponseDTO::getResponse()
    const {
    return m_response;
}

void UserCallResponseDTO::setResponse(
    const std::variant<std::monostate, FunctionCallResponseDTO>& response) {
    m_response = response;
}

bool UserCallResponseDTO::serialize(UserCallResponse& response) const {
    response.destination = dtoToDestination(m_destination);

    if (const FunctionCallResponseDTO* responseDTO =
            std::get_if<FunctionCallResponseDTO>(&m_response)) {
        response.which_response = UserCallResponse_functionCall_tag;
        return responseDTO->serialize(response.response.functionCall);
    }

    return false;
}
