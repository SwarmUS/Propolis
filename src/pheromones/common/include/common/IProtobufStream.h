#ifndef __IPROTOBUFSTREAM_H_
#define __IPROTOBUFSTREAM_H_

#include <cstdint>

/**
 *@brief An interface to manage the stream of data used to encode/decode.
 *Used in the other pheromones libraries. It is the user's job to implement this interface. The
 *other classes uses this interface to get the data to deserialize and send the data to deserialize
 **/
class IProtobufStream {

  public:
    virtual ~IProtobufStream() = default;

    /**
     *@brief Used to receive the data to serialize
     *
     *@param [out] data buffer where the received data will be stored
     *
     *@param [in] length maxmimum length of the data to store in the buffer
     *
     *@return true if the operation was successful, false if not
     **/
    virtual bool receive(uint8_t* data, uint16_t length) = 0;

    /**
     *@brief Used to send the serialized data
     *
     *@param [in] data buffer the data to send is stored
     *
     *@param [in] length size of the data in the buffer
     *
     *@return true if the operation was successful, false if not
     **/
    virtual bool send(const uint8_t* data, uint16_t length) = 0;
};

#endif // __IPROTOBUFSTREAM_H_
