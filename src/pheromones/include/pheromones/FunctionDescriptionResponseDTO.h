#ifndef __FUNCTIONDESCRIPTIONRESPONSEDTO_H_
#define __FUNCTIONDESCRIPTIONRESPONSEDTO_H_

#include "FunctionDescriptionDTO.h"
#include "GenericResponseDTO.h"
#include <message.pb.h>
#include <variant>

class FunctionDescriptionResponseDTO {
  public:
    FunctionDescriptionResponseDTO(const FunctionDescriptionResponse& response);

    FunctionDescriptionResponseDTO(const GenericResponseDTO& response);

    FunctionDescriptionResponseDTO(const FunctionDescriptionDTO& response);

    /**
     *@brief get the stored response
     *@return the stored response */
    const std::variant<std::monostate, GenericResponseDTO, FunctionDescriptionDTO>& getResponse()
        const;

    /**
     *@brief set the response
     *@param [in] response to set */
    void setResponse(
        const std::variant<std::monostate, GenericResponseDTO, FunctionDescriptionDTO>& response);

    /**
     *@brief serialize a FunctionDescriptionResponse for nanopb, sets the fields properly before
     *using pb_encode
     *@param [out] response the response to serialize
     *@return a boolean, true if successfull (fields were recognized) false if not */
    bool serialize(FunctionDescriptionResponse& response) const;

  private:
    std::variant<std::monostate, GenericResponseDTO, FunctionDescriptionDTO> m_response;
};

#endif // __FUNCTIONDESCRIPTIONRESPONSEDTO_H_
