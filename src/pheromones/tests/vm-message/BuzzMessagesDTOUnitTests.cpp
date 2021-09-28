#include <gtest/gtest.h>
#include <pheromones/vm-message/BuzzMessagesDTO.h>

class BuzzMessagesDTOFixture : public testing::Test {
  public:
    static constexpr uint16_t gc_messageLength = 3;
    BuzzMessagesDTO* m_messagesDTO;

    void SetUp() override {
        BuzzMessageDTO messages[gc_messageLength];
        m_messagesDTO = new BuzzMessagesDTO(messages, gc_messageLength);
    }

    void TearDown() override { delete m_messagesDTO; }
};

TEST_F(BuzzMessagesDTOFixture, BuzzMessagesDTO_constructor_noOverflow) {
    // Given
    BuzzMessageDTO messages[255];

    // Then
    BuzzMessagesDTO messagesDTO(messages, 255);

    // Expect
    EXPECT_EQ(messagesDTO.getMessagesLength(), BuzzMessagesDTO::MESSAGES_MAX_SIZE);
}

TEST_F(BuzzMessagesDTOFixture, BuzzMessagesDTO_append_valid) {
    // Given

    // Then
    m_messagesDTO->appendMessage(BuzzMessageDTO());

    // Expect
    EXPECT_EQ(m_messagesDTO->getMessagesLength(), gc_messageLength + 1);
}

TEST_F(BuzzMessagesDTOFixture, BuzzMessagesDTO_append_full) {
    // Given
    BuzzMessageDTO messages[BuzzMessagesDTO::MESSAGES_MAX_SIZE];
    BuzzMessagesDTO messagesDTO(messages, BuzzMessagesDTO::MESSAGES_MAX_SIZE);

    // Then
    messagesDTO.appendMessage(BuzzMessageDTO());

    // Expect
    EXPECT_EQ(messagesDTO.getMessagesLength(), BuzzMessagesDTO::MESSAGES_MAX_SIZE);
}

TEST_F(BuzzMessagesDTOFixture, BuzzMessagesDTO_serialize_valid) {
    // Given
    BuzzMessages msg;

    // Then
    m_messagesDTO->serialize(msg);

    // Expect
    EXPECT_EQ(msg.messages_count, gc_messageLength);
}
