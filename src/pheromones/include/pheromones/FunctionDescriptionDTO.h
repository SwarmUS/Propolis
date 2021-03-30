#ifndef __FUNCTIONDESCRIPTIONDTO_H_
#define __FUNCTIONDESCRIPTIONDTO_H_

#include "FunctionDescriptionArgumentDTO.h"
#include "pheromones/PheromonesSettings.h"
#include <array>
#include <message.pb.h>

class FunctionDescriptionDTO {
  public:
    static constexpr uint16_t FUNCTION_NAME_MAX_SIZE = FUNCTION_NAME_SIZE;
    static constexpr uint16_t ARGUMENTS_MAX_SIZE = FUNCTION_ARGUMENT_COUNT;

    FunctionDescriptionDTO(const FunctionDescription& desc);

    FunctionDescriptionDTO(const char* functionName,
                           const FunctionDescriptionArgumentDTO* args,
                           uint16_t argsLength);

    /**
     *@brief gets the arguments array current length
     *@return the size of the current length of the array */
    uint16_t getArgumentsLength() const;

    /**
     *@brief gets the function name c string
     *@return a pointer to the c string */
    const char* getFunctionName() const;

    /**
     *@brief gets the arguments description array
     *@return a reference to an std::array with the arguments description */
    const std::array<FunctionDescriptionArgumentDTO, ARGUMENTS_MAX_SIZE>& getArguments() const;

    /**
     *@brief set the name of the function
     *@param [in] functionName a c_string to the desired function name */
    void setFunctionName(const char* functionName);

    /**
     *@brief set the stored arguments description
     *@param [in] arguments a pointer to an array of argument descriptions
     *@param [in] argumentsLength the length of the provided array
     *@return the new length of the arguments */
    uint16_t setArguments(const FunctionDescriptionArgumentDTO* arguments,
                          uint16_t argumentsLength);

    /**
     *@brief serialize a FunctionDescription for nanopb, sets the fields properly before using
     *pb_encode
     *@param [out] desc the desc to serialize
     *@return a boolean, true if successfull (fields were recognized) false if not */
    bool serialize(FunctionDescription& desc) const;

  private:
    std::array<FunctionDescriptionArgumentDTO, ARGUMENTS_MAX_SIZE> m_arguments;

    uint16_t m_argumentsLength = 0;

    char m_functionName[FUNCTION_NAME_MAX_SIZE];
};

#endif // __FUNCTIONDESCRIPTIONDTO_H_
