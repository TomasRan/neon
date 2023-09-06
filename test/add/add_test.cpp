#include "gtest/gtest.h"
#include "utils/utils.h"

TEST(AddTest, vaddq_s8)
{
    std::shared_ptr<int8_t> data = mock_data<int8_t>(16, 60);
    int8x16_t a = vld1q_s8(data.get());
    int8x16_t b = vld1q_s8(data.get());
    int8x16_t res = vaddq_s8(a, b);
    print3(16, 16, 16, &a, &b, &res);

    std::vector<int> gt = {120, 122, 124, 126, -128, -126, -124,
            -122, -120, -118, -116, -114, -112, -110, -108, -106};

    compare_eq(16, gt, res);
}