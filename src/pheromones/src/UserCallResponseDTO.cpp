#include "UserCallResponseDTO.h"

UserCallResponseDTO::UserCallResponseDTO(UserCallTargetDTO source,
                                         UserCallTargetDTO destination,
                                         const GenericResponseDTO& response) :
    m_source(source), m_destination(destination), m_response(response) {}

UserCallResponseDTO::UserCallResponseDTO(UserCallTargetDTO source,
                                         UserCallTargetDTO destination,
                                         const FunctionCallResponseDTO& response) :
    m_source(source), m_destination(destination), m_response(response) {}

UserCallResponseDTO::UserCallResponseDTO(UserCallTargetDTO source,
                                         UserCallTargetDTO destination,
                                         const FunctionListLengthResponseDTO& response) :

    m_source(source), m_destination(destination), m_response(response) {}

UserCallResponseDTO::UserCallResponseDTO(UserCallTargetDTO source,
                                         UserCallTargetDTO destination,
                                         const FunctionDescriptionResponseDTO& response) :
    m_source(source), m_destination(destination), m_response(response) {}

UserCallResponseDTO::UserCallResponseDTO(const UserCallResponse& response) :
    m_source(targetToDTO(response.source)), m_destination(targetToDTO(response.destination)) {

    switch (response.which_response) {

    case UserCallResponse_generic_tag:
        m_response = GenericResponseDTO(response.response.generic);
        break;

    case UserCallResponse_function_call_tag:
        m_response = FunctionCallResponse(response.response.function_call);
        break;

    case UserCallResponse_function_list_length_tag:
        m_response = FunctionListLengthResponseDTO(response.response.function_list_length);
        break;

    case UserCallResponse_function_description_tag:
        m_response = FunctionDescriptionResponseDTO(response.response.function_description);
        break;

    default:
        m_response = std::monostate();
    }
}

UserCallTargetDTO UserCallResponseDTO::getSource() const { return m_source; }

UserCallTargetDTO UserCallResponseDTO::getDestination() const { return m_destination; }

const std::variant<std::monostate,
                   GenericResponseDTO,
                   FunctionCallResponseDTO,
                   FunctionListLengthResponseDTO,
                   FunctionDescriptionResponseDTO>&
UserCallResponseDTO::getResponse() const {
    return m_response;
}

void UserCallResponseDTO::setSource(UserCallTargetDTO source) { m_source = source; }

void UserCallResponseDTO::setDestination(UserCallTargetDTO destination) {
    m_destination = destination;
}

void UserCallResponseDTO::setResponse(
    const std::variant<std::monostate,
                       GenericResponseDTO,
                       FunctionCallResponseDTO,
                       FunctionListLengthResponseDTO,
                       FunctionDescriptionResponseDTO>& response) {
    m_response = response;
}

bool UserCallResponseDTO::serialize(UserCallResponse& response) const {
    response.source = dtoToTarget(m_source);
    response.destination = dtoToTarget(m_destination);

    if (const auto* responseDTO = std::get_if<GenericResponseDTO>(&m_response)) {
        response.which_response = UserCallResponse_generic_tag;
        return responseDTO->serialize(response.response.generic);
    }
    if (const auto* responseDTO = std::get_if<FunctionCallResponseDTO>(&m_response)) {
        response.which_response = UserCallResponse_function_call_tag;
        return responseDTO->serialize(response.response.function_call);
    }
    if (const auto* responseDTO = std::get_if<FunctionListLengthResponseDTO>(&m_response)) {
        response.which_response = UserCallResponse_function_list_length_tag;
        return responseDTO->serialize(response.response.function_list_length);
    }
    if (const auto* responseDTO = std::get_if<FunctionDescriptionResponseDTO>(&m_response)) {
        response.which_response = UserCallResponse_function_description_tag;
        return responseDTO->serialize(response.response.function_description);
    }

    return false;
}
