#ifndef __FUNCTIONDESCRIPTIONARGUMENTDTO_H_
#define __FUNCTIONDESCRIPTIONARGUMENTDTO_H_

#include "FunctionDescriptionArgumentTypeDTO.h"
#include "pheromones/PheromonesSettings.h"
#include <message.pb.h>

class FunctionDescriptionArgumentDTO {
  public:
    static constexpr uint8_t FUNCTION_ARGUMENT_NAME_MAX_SIZE = FUNCTION_ARGUMENT_NAME_SIZE;

    FunctionDescriptionArgumentDTO();

    FunctionDescriptionArgumentDTO(const FunctionDescriptionArgument& arg);

    FunctionDescriptionArgumentDTO(const char* argName, FunctionDescriptionArgumentTypeDTO type);

    /**
     *@brief get the argument name
     *@return the name of the argument*/
    const char* getArgumentName() const;

    /**
     *@brief set the argument name
     *@param [in] argName the new name of the function*/
    void setArgumentName(const char* argName);

    /**
     *@brief get the argument type
     *@return the type of the argument */
    FunctionDescriptionArgumentTypeDTO getArgumentType() const;

    /**
     *@brief set the argument type
     *@param [in] type the type of the argument */
    void setArgumentType(FunctionDescriptionArgumentTypeDTO type);

    /**
     *@brief serialize a FunctionDescriptionArgument for nanopb, sets the fields properly before
     *using pb_encode
     *@param [out] arg the FunctionDescriptionArgument to serialize
     *@return a boolean, true if successfull (fields were recognized) false if not */
    bool serialize(FunctionDescriptionArgument& arg) const;

  private:
    char m_argumentName[FUNCTION_ARGUMENT_NAME_MAX_SIZE];
    FunctionDescriptionArgumentTypeDTO m_argumentType;
};

#endif // __FUNCTIONDESCRIPTIONARGUMENTDTO_H_
