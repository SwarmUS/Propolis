#ifndef __GENERICRESPONSEDTO_H_
#define __GENERICRESPONSEDTO_H_

#include <generic.pb.h>

enum class GenericResponseStatusDTO { Unknown, Ok, BadRequest, Error };

class GenericResponseDTO {
  public:
    static constexpr uint16_t DETAILS_MAX_LENGTH = 32;

    GenericResponseDTO(const GenericResponse& response);

    GenericResponseDTO(GenericResponseStatusDTO status, const char* message);

    /**
     *@brief gets the status response
     *
     *@return the response status
     */
    GenericResponseStatusDTO getStatus() const;

    /**
     *@brief gets the details response
     *
     *@return a char pointer to the details
     */
    const char* getDetails() const;

    /**
     *@brief sets the status response
     *
     *@param [in] status the new status to set
     *
     */
    void setStatus(GenericResponseStatusDTO status);

    /**
     *@brief sets the details response
     *
     *@param [in] message the details to set
     *
     */
    void setDetails(const char* message);

    /**
     *@brief serialize a GenericResponse for nanopb, sets the fields properly before using
     *pb_encode
     *
     *@param [out] response the response to serialize
     *
     *@return a boolean, true if successfull (fields were recognized) false if not
     */
    bool serialize(GenericResponse& response) const;

  private:
    GenericResponseStatusDTO m_status = GenericResponseStatusDTO::Unknown;

    static GenericResponseStatusDTO statusToDTO(GenericResponseStatus status);

    static GenericResponseStatus DTOToStatus(GenericResponseStatusDTO status);

    char m_details[DETAILS_MAX_LENGTH];
};

#endif // __GENERICRESPONSEDTO_H_
