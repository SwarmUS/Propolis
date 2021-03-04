#ifndef __IDRESPONSEDTO_H_
#define __IDRESPONSEDTO_H_

#include <message.pb.h>

/**
 *@brief Returns the id of a hivemind, can be used when broadcasting and getting all ids*/
class IdResponseDTO {
  public:
    IdResponseDTO(const IdResponse& resp);

    IdResponseDTO(uint16_t id);

    /**
     *@brief gets the id
     *@return the id */
    uint16_t getId() const;

    /**
     *@brief set the id
     *@param [in] id the id to set */
    void setId(uint16_t id);

    /**
     *@brief serialize a IdResponse for nanopb, sets the fields properly before using
     *pb_encode
     *@param [out] resp the IdResponse to serialize
     *@return a boolean, true if successfull (fields were recognized) false if not */
    bool serialize(IdResponse& resp) const;

  private:
    uint16_t m_id;
};

#endif // __IDRESPONSEDTO_H_
