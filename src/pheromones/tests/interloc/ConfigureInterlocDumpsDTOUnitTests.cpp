#include <gtest/gtest.h>
#include <pheromones/interloc/ConfigureInterlocDumpsDTO.h>

class ConfigureInterlocDumpsFixture : public testing::Test {
  public:
    void SetUp() override {}

    void TearDown() override {}
};

TEST_F(ConfigureInterlocDumpsFixture, ConfigureInterlocDumps_deserialize) {
    ConfigureInterlocDumps msg;
    msg.enable = true;

    auto dto = ConfigureInterlocDumpsDTO(msg);

    EXPECT_EQ(dto.getEnabled(), msg.enable);
}

TEST_F(ConfigureInterlocDumpsFixture, ConfigureInterlocDumps_construct) {
    bool enabled = true;

    auto dto = ConfigureInterlocDumpsDTO(enabled);

    EXPECT_EQ(dto.getEnabled(), enabled);
}

TEST_F(ConfigureInterlocDumpsFixture, ConfigureInterlocDumps_setEnable) {
    ConfigureInterlocDumps msg;
    msg.enable = true;

    auto dto = ConfigureInterlocDumpsDTO(msg);
    dto.setEnabled(false);

    EXPECT_EQ(dto.getEnabled(), false);
}

TEST_F(ConfigureInterlocDumpsFixture, ConfigureInterlocDumps_serialize) {
    bool enabled = true;
    ConfigureInterlocDumps msg;

    auto dto = ConfigureInterlocDumpsDTO(enabled);
    bool ret = dto.serialize(msg);

    EXPECT_TRUE(ret);
    EXPECT_EQ(msg.enable, enabled);
}