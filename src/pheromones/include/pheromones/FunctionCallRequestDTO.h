#ifndef __FUNCTIONCALLREQUESTDTO_H_
#define __FUNCTIONCALLREQUESTDTO_H_

#include "FunctionCallArgumentDTO.h"
#include "pheromones/PheromonesSettings.h"
#include <array>
#include <message.pb.h>
#include <optional>

class FunctionCallRequestDTO {

  public:
    static constexpr uint8_t FUNCTION_CALL_ARGUMENTS_MAX_LENGTH = FUNCTION_ARGUMENT_COUNT;

    static constexpr uint8_t FUNCTION_CALL_NAME_MAX_LENGTH = FUNCTION_NAME_SIZE;

    FunctionCallRequestDTO(const FunctionCallRequest& request);

    FunctionCallRequestDTO(const char* functionName,
                           const FunctionCallArgumentDTO* arguments,
                           uint16_t argumentsLength);

    /**
     *@brief gets the arguments array current length
     *
     *@return the size of the current length of the array
     */
    uint16_t getArgumentsLength() const;

    /**
     *@brief gets the function name c string
     *
     *@return a pointer to the c string
     */
    const char* getFunctionName() const;

    /**
     *@brief gets the arguments array
     *
     *@return a reference to an std::array with the arguments
     */
    const std::array<FunctionCallArgumentDTO, FUNCTION_CALL_ARGUMENTS_MAX_LENGTH>& getArguments()
        const;

    /**
     *@brief set the name of the function call
     *
     *@param [in] functionName a c_string to the desired function name
     */
    void setFunctionName(const char* functionName);

    /**
     *@brief set the stored arguments
     *
     *@param [in] arguments a pointer to an array of arguments
     *
     *@param [in] argumentsLength the length of the provided array
     */
    uint16_t setArguments(const FunctionCallArgumentDTO* arguments, uint16_t argumentsLength);

    /**
     *@brief serialize a FunctionCallRequest for nanopb, sets the fields properly before using
     *pb_encode
     *
     *@param [out] request the request to serialize
     *
     *@return a boolean, true if successfull (fields were recognized) false if not
     */
    bool serialize(FunctionCallRequest& request) const;

  private:
    std::array<FunctionCallArgumentDTO, FUNCTION_CALL_ARGUMENTS_MAX_LENGTH> m_arguments;

    uint16_t m_argumentsLength = 0;

    char m_functionName[FUNCTION_CALL_NAME_MAX_LENGTH];
};

#endif // __FUNCTIONCALLREQUESTDTO_H_
