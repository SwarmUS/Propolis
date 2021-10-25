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

TEST_F(ConfigureAngleParametersFixture, ConfigureInterlocDumps_deserialize_tdoaNormalization) {
    ConfigureAngleParameters msg;
    memset(&msg, 0, sizeof(msg));

    msg.tdoaNormalizationFactor = 1;

    auto dto = ConfigureAngleParametersDTO(msg);

    EXPECT_EQ(dto.getTdoaNormalizationFactor(), msg.tdoaNormalizationFactor);
}

TEST_F(ConfigureAngleParametersFixture, ConfigureInterlocDumps_deserialize_tdoaSlopes) {
    ConfigureAngleParameters msg;
    memset(&msg, 0, sizeof(msg));

    msg.tdoaSlopes[0] = 1;
    msg.tdoaSlopes[1] = 2;
    msg.tdoaSlopes_count = 2;

    auto dto = ConfigureAngleParametersDTO(msg);

    EXPECT_EQ(dto.getTdoaSlopes()[0], msg.tdoaSlopes[0]);
    EXPECT_EQ(dto.getTdoaSlopes()[1], msg.tdoaSlopes[1]);
    EXPECT_EQ(dto.getTdoaSlopesLength(), msg.tdoaSlopes_count);
}

TEST_F(ConfigureAngleParametersFixture, ConfigureInterlocDumps_deserialize_tdoaIntercepts) {
    ConfigureAngleParameters msg;
    memset(&msg, 0, sizeof(msg));

    msg.tdoaIntercepts[0] = 1;
    msg.tdoaIntercepts[1] = 2;
    msg.tdoaIntercepts_count = 2;

    auto dto = ConfigureAngleParametersDTO(msg);

    EXPECT_EQ(dto.getTdoaIntercepts()[0], msg.tdoaIntercepts[0]);
    EXPECT_EQ(dto.getTdoaIntercepts()[1], msg.tdoaIntercepts[1]);
    EXPECT_EQ(dto.getTdoaInterceptsLength(), msg.tdoaIntercepts_count);
}

TEST_F(ConfigureAngleParametersFixture, ConfigureInterlocDumps_deserialize_pdoaNormalization) {
    ConfigureAngleParameters msg;
    memset(&msg, 0, sizeof(msg));

    msg.pdoaNormalizationFactor = 1;

    auto dto = ConfigureAngleParametersDTO(msg);

    EXPECT_EQ(dto.getPdoaNormalizationFactor(), msg.pdoaNormalizationFactor);
}

TEST_F(ConfigureAngleParametersFixture, ConfigureInterlocDumps_deserialize_pdoaSlope) {
    ConfigureAngleParameters msg;
    memset(&msg, 0, sizeof(msg));

    msg.pdoaSlope = 1;

    auto dto = ConfigureAngleParametersDTO(msg);

    EXPECT_EQ(dto.getPdoaSlope(), msg.pdoaSlope);
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

TEST_F(ConfigureAngleParametersFixture, ConfigureInterlocDumps_deserialize_pdoaOrigins) {
    ConfigureAngleParameters msg;
    memset(&msg, 0, sizeof(msg));

    msg.pdoaOrigins[0] = 1;
    msg.pdoaOrigins[1] = 2;
    msg.pdoaOrigins_count = 2;

    auto dto = ConfigureAngleParametersDTO(msg);

    EXPECT_EQ(dto.getPdoaOrigins()[0], msg.pdoaOrigins[0]);
    EXPECT_EQ(dto.getPdoaOrigins()[1], msg.pdoaOrigins[1]);
    EXPECT_EQ(dto.getPdoaOriginsLength(), msg.pdoaOrigins_count);
}