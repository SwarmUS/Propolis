#ifndef __INTERLOCRXFRAMEINFODTO_H__
#define __INTERLOCRXFRAMEINFODTO_H__

#include <cstdint>
#include <message.pb.h>

class InterlocRxFrameInfoDTO {
  public:
    InterlocRxFrameInfoDTO(const InterlocRxFrameInfo& message);
    InterlocRxFrameInfoDTO();

    void setBeeboardPort(uint32_t port);
    void setRxTimestamp(uint64_t timestamp);
    void setSfdAngle(float angle);
    void setAccumulatorAngle(float angle);

    uint32_t getBeeboardPort() const;
    uint64_t getRxTimestamp() const;
    float getSfdAngle() const;
    float getAccumulatorAngle() const;

    /**
     *@brief serialize a Message for nanopb, sets the fields properly before using
     *pb_encode
     *@param [out] message the message to serialize
     *@return a boolean, true if successfull (fields were recognized) false if not */
    bool serialize(InterlocRxFrameInfo& message) const;

  private:
    uint32_t m_beeboardPort;
    uint64_t m_rxTimestamp;
    float m_sfdAngle;
    float m_accumulatorAngle;
};

#endif //__INTERLOCRXFRAMEINFODTO_H__
