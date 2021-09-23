#ifndef __INTERLOCRXFRAMEINFODTO_H__
#define __INTERLOCRXFRAMEINFODTO_H__

#include <cstdint>
#include <message.pb.h>

class InterlocRxFrameInfoDTO {
  public:
    InterlocRxFrameInfoDTO(const InterlocRxFrameInfo& message);
    InterlocRxFrameInfoDTO();

    /**
     * Sets the BeeBoard port
     * @param port BeeBoard port
     */
    void setBeeboardPort(uint32_t port);

    /**
     * Sets the frame's RX timestamp
     * @param timestamp Timestamp
     */
    void setRxTimestamp(uint64_t timestamp);

    /**
     * Sets the frame's SFD angle
     * @param angle Angle
     */
    void setSfdAngle(float angle);

    /**
     * Sets the frame's angle calculated from I and Q components in the accumualtor
     * @param angle Angle
     */
    void setAccumulatorAngle(float angle);

    /**
     * Returns the BeeBoard port
     * @return BeeBoard port
     */
    uint32_t getBeeboardPort() const;

    /**
     * Returns the RX Timestamp
     * @return RX Timestamp
     */
    uint64_t getRxTimestamp() const;

    /**
     * Returns the SFD Angle
     * @return SFD Angle
     */
    float getSfdAngle() const;

    /**
     * Returns the angle calculated from the accumulator data
     * @return Angle
     */
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
