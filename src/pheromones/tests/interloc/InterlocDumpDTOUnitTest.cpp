#include <gtest/gtest.h>
#include <pheromones/interloc/InterlocDumpDTO.h>

class InterlocDumpFixture : public testing::Test {
  public:
    void SetUp() override {}

    void TearDown() override {}
};

TEST_F(InterlocDumpFixture, InterlocDump_deserialize) {
    InterlocDump msg;

    constexpr unsigned int numUpdates = 5;

    for (unsigned int i = 0; i < numUpdates; i++) {
        msg.positionUpdates[i].has_position = true;
        msg.positionUpdates[i].neighbor_id = i;
        msg.positionUpdates[i].position.distance = (float)i;
    }
    msg.positionUpdates_count = numUpdates;

    auto dto = InterlocDumpDTO(msg);

    EXPECT_EQ(dto.getUpdatesLength(), numUpdates);
    for (unsigned int i = 0; i < numUpdates; i++) {
        EXPECT_EQ(dto.getUpdates()[i].getNeighborId(), i);
        EXPECT_TRUE(dto.getUpdates()[i].getNeighborPosition());
        EXPECT_EQ(dto.getUpdates()[i].getNeighborPosition()->getDistance(), i);
    }
}

TEST_F(InterlocDumpFixture, InterlocDump_setUpdates) {
    InterlocDump msg;
    msg.positionUpdates_count = 0;

    auto dto = InterlocDumpDTO(msg);

    constexpr unsigned int numUpdates = 5;
    std::array<GetNeighborResponseDTO, numUpdates> inputArray;

    for (unsigned int i = 0; i < numUpdates; i++) {
        inputArray[i].setNeighborId(i);
        inputArray[i].setNeighborPosition(NeighborPositionDTO((float)i, 0, true));
    }

    dto.setUpdates(inputArray.data(), numUpdates);

    EXPECT_EQ(dto.getUpdatesLength(), numUpdates);
    for (unsigned int i = 0; i < numUpdates; i++) {
        EXPECT_EQ(dto.getUpdates()[i].getNeighborId(), i);
        EXPECT_TRUE(dto.getUpdates()[i].getNeighborPosition());
        EXPECT_EQ(dto.getUpdates()[i].getNeighborPosition()->getDistance(), i);
    }
}

TEST_F(InterlocDumpFixture, InterlocDump_serialize) {
    InterlocDump msg;
    InterlocDump outMsg;
    msg.positionUpdates_count = 0;

    auto dto = InterlocDumpDTO(msg);

    constexpr unsigned int numUpdates = 5;
    std::array<GetNeighborResponseDTO, numUpdates> inputArray;

    for (unsigned int i = 0; i < numUpdates; i++) {
        inputArray[i].setNeighborId(i);
        inputArray[i].setNeighborPosition(NeighborPositionDTO((float)i, 0, true));
    }

    dto.setUpdates(inputArray.data(), numUpdates);
    bool ret = dto.serialize(outMsg);

    EXPECT_TRUE(ret);

    EXPECT_EQ(outMsg.positionUpdates_count, numUpdates);
    for (unsigned int i = 0; i < numUpdates; i++) {
        EXPECT_EQ(outMsg.positionUpdates[i].neighbor_id, i);
        EXPECT_TRUE(outMsg.positionUpdates[i].has_position);
        EXPECT_EQ(outMsg.positionUpdates[i].position.distance, i);
    }
}