#ifndef __IPROTOBUFOUTPUTSTREAM_H_
#define __IPROTOBUFOUTPUTSTREAM_H_

#include <cstdint>

/**
 *@brief An interface to manage the stream of data used to encode.
 * Used in the other pheromones libraries. It is the user's job to implement this interface. The
 * other classes uses this interface to send the data to deserialize
 **/
class IProtobufOutputStream {

  public:
    virtual ~IProtobufOutputStream() = default;

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

#endif // __IPROTOBUFOUTPUTSTREAM_H_
