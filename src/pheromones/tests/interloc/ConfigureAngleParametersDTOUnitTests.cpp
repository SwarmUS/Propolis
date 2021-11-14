#include <gtest/gtest.h>
#include <pheromones/interloc/ConfigureAngleParametersDTO.h>

class ConfigureAngleParametersFixture : public testing::Test {
  public:
    void SetUp() override {}

    void TearDown() override {}
};

TEST_F(ConfigureAngleParametersFixture, ConfigureInterlocDumps_deserialize_pairId) {
    ConfigureAngleParameters msg;
    memset(&msg, 0, sizeof(msg));
    msg.anglePairId = 42;

    auto dto = ConfigureAngleParametersDTO(msg);

    EXPECT_EQ(dto.getPairId(), msg.anglePairId);
}

TEST_F(ConfigureAngleParametersFixture, ConfigureInterlocDumps_deserialize_slopeDecision) {
    ConfigureAngleParameters msg;
    memset(&msg, 0, sizeof(msg));

    msg.slopeDecision[0] = 1;
    msg.slopeDecision[1] = 2;
    msg.slopeDecision_count = 2;

    auto dto = ConfigureAngleParametersDTO(msg);

    EXPECT_EQ(dto.getSlopeDecision()[0], msg.slopeDecision[0]);
    EXPECT_EQ(dto.getSlopeDecision()[1], msg.slopeDecision[1]);
    EXPECT_EQ(dto.getSlopeDecisionLength(), msg.slopeDecision_count);
}

TEST_F(ConfigureAngleParametersFixture, ConfigureInterlocDumps_deserialize_pdoaSlopes) {
    ConfigureAngleParameters msg;
    memset(&msg, 0, sizeof(msg));

    msg.pdoaSlopes[0] = 1;
    msg.pdoaSlopes[1] = 2;
    msg.pdoaSlopes_count = 2;

    auto dto = ConfigureAngleParametersDTO(msg);

    EXPECT_EQ(dto.getPdoaSlopes()[0], msg.pdoaSlopes[0]);
    EXPECT_EQ(dto.getPdoaSlopes()[1], msg.pdoaSlopes[1]);
    EXPECT_EQ(dto.getPdoaSlopesLength(), msg.pdoaSlopes_count);
}

TEST_F(ConfigureAngleParametersFixture, ConfigureInterlocDumps_deserialize_pdoaNormalization) {
    ConfigureAngleParameters msg;
    memset(&msg, 0, sizeof(msg));

    msg.pdoaNormalizationFactor = 1;

    auto dto = ConfigureAngleParametersDTO(msg);

    EXPECT_EQ(dto.getPdoaNormalizationFactor(), msg.pdoaNormalizationFactor);
}

TEST_F(ConfigureAngleParametersFixture, ConfigureInterlocDumps_deserialize_boardOffset) {
    ConfigureAngleParameters msg;
    memset(&msg, 0, sizeof(msg));

    msg.boardOrientationOffset = 42.42;

    auto dto = ConfigureAngleParametersDTO(msg);

    EXPECT_EQ(dto.getBoardOrientationOffset(), msg.boardOrientationOffset);
}

TEST_F(ConfigureAngleParametersFixture, ConfigureInterlocDumps_deserialize_pdoaIntercepts) {
    ConfigureAngleParameters msg;
    memset(&msg, 0, sizeof(msg));

    msg.pdoaIntercepts[0] = 1;
    msg.pdoaIntercepts[1] = 2;
    msg.pdoaIntercepts_count = 2;

    auto dto = ConfigureAngleParametersDTO(msg);

    EXPECT_EQ(dto.getPdoaIntercepts()[0], msg.pdoaIntercepts[0]);
    EXPECT_EQ(dto.getPdoaIntercepts()[1], msg.pdoaIntercepts[1]);
    EXPECT_EQ(dto.getPdoaInterceptsLength(), msg.pdoaIntercepts_count);
}