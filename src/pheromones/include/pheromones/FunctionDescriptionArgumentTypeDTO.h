#ifndef __FUNCTIONDESCRIPTIONARGUMENTTYPEDTO_H_
#define __FUNCTIONDESCRIPTIONARGUMENTTYPEDTO_H_

#include <message.pb.h>

/**
 *@brief The types of arguments possible to describe a function call */
enum class FunctionDescriptionArgumentTypeDTO { Unknown, Int, Float };

FunctionDescriptionArgumentTypeDTO typeToDTO(FunctionDescriptionArgumentType type);

FunctionDescriptionArgumentType dtoToType(FunctionDescriptionArgumentTypeDTO type);

#endif // __FUNCTIONDESCRIPTIONARGUMENTTYPEDTO_H_
