#include "HiveMindDeserializer.h"
#include <message.pb.h>
#include <pb_decode.h>
#include <pb_encode.h>

HiveMindDeserializer::HiveMindDeserializer(IProtobufStream& stream) : m_stream(stream) {}

std::variant<std::monostate, Request2> HiveMindDeserializer::deserialize() {
    // stream definition

    /*-------- SENDER -------*/
    // Packet definition
    // FunctionArgument arg = {};
    // arg.which_argument = FunctionArgument_int_arg_tag;
    // arg.argument.int_arg = 10;

    // FunctionCallRequest2 f_req = FunctionCallRequest_init_default;
    // f_req.arguments_count = 1;
    // f_req.arguments[0] = arg;
    // strcpy(f_req.functionName, "hello_world");

    // Request2 req = Request_init_default;
    // req.id = 1;
    // req.which_message = Request_function_call_tag;
    // req.message.function_call = f_req;

    // Message msg = Message_init_default;
    // msg.which_message = Message_request_tag;
    // msg.message.request = req
    return std::monostate();
}
