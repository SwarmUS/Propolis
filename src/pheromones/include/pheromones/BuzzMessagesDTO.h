#ifndef BUZZMESSAGESDTO_H_
#define BUZZMESSAGESDTO_H_

#include "pheromones/PheromonesSettings.h"
#include <array>
#include <message.pb.h>
#include <pheromones/BuzzMessageDTO.h>

class BuzzMessagesDTO {
  public:
    static constexpr uint16_t MESSAGES_MAX_SIZE = BUZZ_MESSAGES_LIST_SIZE;

    BuzzMessagesDTO(const BuzzMessages& messages);
    BuzzMessagesDTO(BuzzMessageDTO* messages, uint16_t messagesLength);

    /**
     *@brief get the messages
     *@return a ref to the messages array*/
    const std::array<BuzzMessageDTO, MESSAGES_MAX_SIZE>& getMessages() const;

    /**@brief get the raw messages, not const. Can be used to write on it. Call
     * setRawMessagesLength
     *@return the raw value of the messages */
    std::array<BuzzMessageDTO, MESSAGES_MAX_SIZE>& getRawMessages();

    /**
     *@brief get the messages array length
     *@return the length of the array */
    uint16_t getMessagesLength() const;

    /**
     *@brief set the messages length after a write with the raw messages
     *@return true if the length is smaller than the max length, false otherwise*/
    bool setRawMessagesLength(uint16_t messagesLength);

    /**
     *@brief set the messages
     *@param [in] messages a pointer to the messages to set
     *@param [in] length the length of the provided array*/
    void setMessages(const BuzzMessageDTO* messages, uint16_t length);
    void setMessages(const BuzzMessage* messages, uint16_t length);

    /**
     *@brief append a message to the list
     *@param [in] message the message to append
     *@return true if successful (i.e. enough space), false if not*/
    bool appendMessage(const BuzzMessageDTO& message);

    /**
     *@brief serialize a BuzzMessages for nanopb, sets the fields properly before using
     *pb_encode
     *@param [out] msg the message to serialize
     *@return a boolean, true if successfull (fields were recognized) false if not */
    bool serialize(BuzzMessages& msg) const;

  private:
    std::array<BuzzMessageDTO, MESSAGES_MAX_SIZE> m_messages;
    uint16_t m_messagesLength;
};

#endif // BUZZMESSAGESDTO_H_
