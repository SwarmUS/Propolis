#ifndef __IPROTOBUFSTREAM_H_
#define __IPROTOBUFSTREAM_H_

#include "IProtobufInputStream.h"
#include "IProtobufOutputStream.h"
#include <cstdint>

/**
 *@brief An interface to manage the stream of data used to encode/decode.
 * Used in the other pheromones libraries. It is a composite interface of the IProtobufOutputStream
 * and IProtobufOutputStream. It is the user's job to implement this interface, thus implementing
 * the receive and send functions from the inherited interfaces.
 * The child classes uses this interface to get the data to
 * deserialize and send the data to deserialize as one instance.
 **/
class IProtobufStream : public IProtobufInputStream, public IProtobufOutputStream {

  public:
    ~IProtobufStream() override = default;
};

#endif // __IPROTOBUFSTREAM_H_
