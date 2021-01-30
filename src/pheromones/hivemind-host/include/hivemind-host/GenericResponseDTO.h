#ifndef __GENERICRESPONSEDTO_H_
#define __GENERICRESPONSEDTO_H_

#include <generic.pb.h>

enum class GenericResponseStatusDTO { Unknown, Ok, BadRequest, Error };

class GenericResponseDTO {
  public:
    static constexpr uint16_t DETAILS_MAX_LENGTH = 32;

    GenericResponseDTO(const GenericResponse& response);

    GenericResponseDTO(GenericResponseStatusDTO status, const char* message);

    GenericResponseStatusDTO getStatus() const;

    const char* getDetails() const;

    void setStatus(GenericResponseStatusDTO status);

    void setDetails(const char* message);

    bool serialize(GenericResponse& response) const;

  private:
    GenericResponseStatusDTO m_status = GenericResponseStatusDTO::Unknown;

    static GenericResponseStatusDTO statusToDTO(GenericResponseStatus status);

    static GenericResponseStatus DTOToStatus(GenericResponseStatusDTO status);

    char m_details[DETAILS_MAX_LENGTH];
};

#endif // __GENERICRESPONSEDTO_H_
