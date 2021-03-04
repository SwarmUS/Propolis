#include "UserCallRequestDTO.h"

UserCallRequestDTO::UserCallRequestDTO(const UserCallRequest& request) :
    m_source(targetToDTO(request.source)), m_destination(targetToDTO(request.destination)) {

    switch (request.which_request) {

    case UserCallRequest_function_call_tag:
        m_request = FunctionCallRequestDTO(request.request.function_call);
        break;
    default:
        m_request = std::monostate();
    }
}

UserCallRequestDTO::UserCallRequestDTO(UserCallTargetDTO source,
                                       UserCallTargetDTO destination,
                                       const FunctionCallRequestDTO& request) :
    m_source(source), m_destination(destination), m_request(request) {}

UserCallRequestDTO::UserCallRequestDTO(UserCallTargetDTO source,
                                       UserCallTargetDTO destination,
                                       const FunctionListLengthRequestDTO& request) :
    m_source(source), m_destination(destination), m_request(request) {}

UserCallRequestDTO::UserCallRequestDTO(UserCallTargetDTO source,
                                       UserCallTargetDTO destination,
                                       const FunctionDescriptionRequestDTO& request) :
    m_source(source), m_destination(destination), m_request(request) {}

UserCallTargetDTO UserCallRequestDTO::getSource() const { return m_source; }

UserCallTargetDTO UserCallRequestDTO::getDestination() const { return m_destination; }

const std::variant<std::monostate,
                   FunctionCallRequestDTO,
                   FunctionListLengthRequestDTO,
                   FunctionDescriptionRequestDTO>&
UserCallRequestDTO::getRequest() const {
    return m_request;
}

void UserCallRequestDTO::setSource(UserCallTargetDTO source) { m_source = source; }

void UserCallRequestDTO::setDestination(UserCallTargetDTO destination) {
    m_destination = destination;
}

void UserCallRequestDTO::setRequest(const std::variant<std::monostate,
                                                       FunctionCallRequestDTO,
                                                       FunctionListLengthRequestDTO,
                                                       FunctionDescriptionRequestDTO>& request) {
    m_request = request;
}

bool UserCallRequestDTO::serialize(UserCallRequest& request) const {

    request.source = dtoToTarget(m_source);
    request.destination = dtoToTarget(m_destination);

    if (const auto* functionRequest = std::get_if<FunctionCallRequestDTO>(&m_request)) {
        request.which_request = UserCallRequest_function_call_tag;
        return functionRequest->serialize(request.request.function_call);
    }
    if (const auto* fListRequest = std::get_if<FunctionListLengthRequestDTO>(&m_request)) {
        request.which_request = UserCallRequest_function_list_length_tag;
        return fListRequest->serialize(request.request.function_list_length);
    }
    if (const auto* fDescRequest = std::get_if<FunctionDescriptionRequestDTO>(&m_request)) {
        request.which_request = UserCallRequest_function_description_tag;
        return fDescRequest->serialize(request.request.function_description);
    }

    return false;
}
