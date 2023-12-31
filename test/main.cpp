#include "gtest/gtest.h"

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// void test_vaddq_s8() {
//     std::shared_ptr<int8_t> data = create_data<int8_t>(16, 60);
//     int8x16_t a = vld1q_s8(data.get());
//     int8x16_t b = vld1q_s8(data.get());
//     int8x16_t res = vaddq_s8(a, b);
//     print_op2(16, &a, 16, &b, 16, &res);
// }

// void test_vaddl_s8() {
//     std::shared_ptr<int8_t> data = create_data<int8_t>(8, 60);
//     int8x8_t a = vld1_s8(data.get());
//     int8x8_t b = vld1_s8(data.get());
//     int16x8_t res = vaddl_s8(a, b);
//     print_op2(8, &a, 8, &b, 8, &res);
// }

// void test_vaddl_high_s8() {
//     std::shared_ptr<int8_t> data = create_data<int8_t>(16);
//     int8x16_t a = vld1q_s8(data.get());
//     int8x16_t b = vld1q_s8(data.get());
//     int16x8_t res = vaddl_high_s8(a, b);
//     print_op2(16, &a, 16, &b, 8, &res);
// }

// void test_vaddw_s8() {
//     std::shared_ptr<int8_t> d_int8 = create_data<int8_t>(8, 120);
//     std::shared_ptr<int16_t> d_int16 = create_data<int16_t>(8, 256);
//     int16x8_t a = vld1q_s16(d_int16.get());
//     int8x8_t b = vld1_s8(d_int8.get());
//     int16x8_t res = vaddw_s8(a, b);
//     print_op2(8, &a, 8, &b, 8, &res);
// }

// void test_vaddw_high_s8() {
//     std::shared_ptr<int8_t> d_int8 = create_data<int8_t>(16);
//     std::shared_ptr<int16_t> d_int16 = create_data<int16_t>(8);
//     int16x8_t a = vld1q_s16(d_int16.get());
//     int8x16_t b = vld1q_s8(d_int8.get());
//     int16x8_t res = vaddw_high_s8(a, b);
//     print_op2(8, &a, 16, &b, 8, &res);
// }

// void test_vhaddq_s8() {
//     std::shared_ptr<int8_t> d_int8_1 = create_data<int8_t>(16, 60);
//     std::shared_ptr<int8_t> d_int8_2 = create_data<int8_t>(16, 73);
//     int8x16_t a = vld1q_s8(d_int8_1.get());
//     int8x16_t b = vld1q_s8(d_int8_2.get());
//     int8x16_t res = vhaddq_s8(a, b);
//     print_op2(16, &a, 16, &b, 16, &res);
// }

// void test_vrhaddq_s8() {
//     std::shared_ptr<int8_t> d_int8_1 = create_data<int8_t>(16, 60);
//     std::shared_ptr<int8_t> d_int8_2 = create_data<int8_t>(16, 73);
//     int8x16_t a = vld1q_s8(d_int8_1.get());
//     int8x16_t b = vld1q_s8(d_int8_2.get());
//     int8x16_t res = vrhaddq_s8(a, b);
//     print_op2(16, &a, 16, &b, 16, &res);
// }

// void test_vqaddq_s8() {
//     std::shared_ptr<int8_t> d_int8_1 = create_data<int8_t>(16, 50);
//     std::shared_ptr<int8_t> d_int8_2 = create_data<int8_t>(16, 73);
//     int8x16_t a = vld1q_s8(d_int8_1.get());
//     int8x16_t b = vld1q_s8(d_int8_2.get());
//     int8x16_t res = vqaddq_s8(a, b);
//     print_op2(16, &a, 16, &b, 16, &res);
// }

// void test_vuqaddq_s8() {
//     std::shared_ptr<int8_t> d_int8_1 = create_data<int8_t>(16, 50);
//     std::shared_ptr<uint8_t> d_uint8_2 = create_data<uint8_t>(16, 129);
//     int8x16_t a = vld1q_s8(d_int8_1.get());
//     uint8x16_t b = vld1q_u8(d_uint8_2.get());
//     int8x16_t res = vuqaddq_s8(a, b);
//     print_op2(16, &a, 16, &b, 16, &res);
// }

// void test_vsqaddq_u8() {
//     std::shared_ptr<uint8_t> d_uint8_1 = create_data<uint8_t>(16, 210);
//     std::shared_ptr<int8_t> d_int8_2 = create_data<int8_t>(16, -3);
//     uint8x16_t a = vld1q_u8(d_uint8_1.get());
//     int8x16_t b = vld1q_s8(d_int8_2.get());
//     uint8x16_t res = vsqaddq_u8(a, b);
//     print_op2(16, &a, 16, &b, 16, &res);
// }

// void test_vaddhn_s16() {
//     std::shared_ptr<int16_t> d_int16_1 = create_data<int16_t>(8, 254);
//     std::shared_ptr<int16_t> d_int16_2 = create_data<int16_t>(8, 253);
//     int16x8_t a = vld1q_s16(d_int16_1.get());
//     int16x8_t b = vld1q_s16(d_int16_2.get());
//     int8x8_t res = vaddhn_s16(a, b);
//     print_op2(8, &a, 8, &b, 8, &res);
// }
    
// void test_vaddhn_high_s16() {
//     std::shared_ptr<int16_t> d_int16_1 = create_data<int16_t>(8, 254);
//     std::shared_ptr<int16_t> d_int16_2 = create_data<int16_t>(8, 253);
//     std::shared_ptr<int8_t> d_int8_3 = create_data<int8_t>(8, 120);
//     int16x8_t a = vld1q_s16(d_int16_1.get());
//     int16x8_t b = vld1q_s16(d_int16_2.get());
//     int8x8_t r = vld1_s8(d_int8_3.get());
//     int8x16_t res = vaddhn_high_s16(r, a, b);
//     print_op2(8, &a, 8, &b, 16, &res);
// }

// void test_vraddhn_s16() {
//     std::shared_ptr<int16_t> d_int16_1 = create_data<int16_t>(8, 254);
//     std::shared_ptr<int16_t> d_int16_2 = create_data<int16_t>(8, 253);
//     int16x8_t a = vld1q_s16(d_int16_1.get());
//     int16x8_t b = vld1q_s16(d_int16_2.get());
//     int8x8_t res = vraddhn_s16(a, b);
//     print_op2(8, &a, 8, &b, 8, &res);
// }

// void test_vraddhn_high_s16() {
//     std::shared_ptr<int16_t> d_int16_1 = create_data<int16_t>(8, 623);
//     std::shared_ptr<int16_t> d_int16_2 = create_data<int16_t>(8, 50);
//     std::shared_ptr<int8_t> d_int8_3 = create_data<int8_t>(8, 120);
//     int16x8_t a = vld1q_s16(d_int16_1.get());
//     int16x8_t b = vld1q_s16(d_int16_2.get());
//     int8x8_t r = vld1_s8(d_int8_3.get());
//     int8x16_t res = vraddhn_high_s16(r, a, b);
//     print_op2(8, &a, 8, &b, 16, &res);
// }

// void test_vmulq_u8() {
//     std::shared_ptr<int8_t> d_int8_1 = create_data<int8_t>(16, 4);
//     std::shared_ptr<int8_t> d_int8_2 = create_data<int8_t>(16, 5);
//     int8x16_t a = vld1q_s8(d_int8_1.get());
//     int8x16_t b = vld1q_s8(d_int8_2.get());
//     int8x16_t res = vmulq_s8(a, b);
//     print_op2(8, &a, 8, &b, 8, &res);
// }

// void test_vmulxq_f32() {
//     std::shared_ptr<float> d_float_1 = create_data<float>(4, 10.0);
//     std::shared_ptr<float> d_float_2 = create_data<float>(4, 11.0);
//     float32x4_t a = vld1q_f32(d_float_1.get());
//     float32x4_t b = vld1q_f32(d_float_2.get());
//     float32x4_t res = vmulxq_f32(a, b);
//     print_op2(4, &a, 4, &b, 4, &res);
// }

// void test_vmulxq_lane_f32() {
//     std::shared_ptr<float> d_float_1 = create_data<float>(4, 10.0);
//     std::shared_ptr<float> d_float_2 = create_data<float>(2, 11.0);
//     float32x4_t a = vld1q_f32(d_float_1.get());
//     float32x2_t b = vld1_f32(d_float_2.get());
//     float32x4_t res = vmulxq_lane_f32(a, b, 1);
//     print_op2(4, &a, 2, &b, 4, &res);
// }

// void test_vdivq_f32() {
//     std::shared_ptr<float> d_float_1 = create_data<float>(4, 320.0);
//     std::shared_ptr<float> d_float_2 = create_data<float>(4, 11.0);
//     float32x4_t op1 = vld1q_f32(d_float_1.get());
//     float32x4_t op2 = vld1q_f32(d_float_2.get());
//     float32x4_t res = vdivq_f32(op1, op2);
//     print_op2(4, &op1, 4, &op2, 4, &res);
// }

// void test_vmlaq_s8() {
//     std::shared_ptr<int8_t> d_int8_1 = create_data<int8_t>(16, 4);
//     std::shared_ptr<int8_t> d_int8_2 = create_data<int8_t>(16, 5);
//     std::shared_ptr<int8_t> d_int8_3 = create_data<int8_t>(16, 6);
//     int8x16_t op1 = vld1q_s8(d_int8_1.get());
//     int8x16_t op2 = vld1q_s8(d_int8_2.get());
//     int8x16_t op3 = vld1q_s8(d_int8_3.get());
//     int8x16_t res = vmlaq_s8(op1, op2, op3);
//     print_op3(16, &op1, 16, &op2, 16, &op3, 16, &res);
// }

// void test_vmlal_s8() {
//     std::shared_ptr<int16_t> d_int16_1 = create_data<int16_t>(8, 4);
//     std::shared_ptr<int8_t> d_int8_2 = create_data<int8_t>(8, 5);
//     std::shared_ptr<int8_t> d_int8_3 = create_data<int8_t>(8, 6);
//     int16x8_t op1 = vld1q_s16(d_int16_1.get());
//     int8x8_t op2 = vld1_s8(d_int8_2.get());
//     int8x8_t op3 = vld1_s8(d_int8_3.get());
//     int16x8_t res = vmlal_s8(op1, op2, op3);
//     print_op3(8, &op1, 8, &op2, 8, &op3, 8, &res);
// }

// void test_vmlal_high_s8() {
//     std::shared_ptr<int16_t> d_int16_1 = create_data<int16_t>(8, 4);
//     std::shared_ptr<int8_t> d_int8_2 = create_data<int8_t>(16, 5);
//     std::shared_ptr<int8_t> d_int8_3 = create_data<int8_t>(16, 6);
//     int16x8_t op1 = vld1q_s16(d_int16_1.get());
//     int8x16_t op2 = vld1q_s8(d_int8_2.get());
//     int8x16_t op3 = vld1q_s8(d_int8_3.get());
//     int16x8_t res = vmlal_high_s8(op1, op2, op3);
//     print_op3(8, &op1, 16, &op2, 16, &op3, 8, &res);
// }

// void test_vmlsq_s8() {
//     std::shared_ptr<int8_t> d_int8_1 = create_data<int8_t>(16, 4);
//     std::shared_ptr<int8_t> d_int8_2 = create_data<int8_t>(16, 5);
//     std::shared_ptr<int8_t> d_int8_3 = create_data<int8_t>(16, 6);
//     int8x16_t op1 = vld1q_s8(d_int8_1.get());
//     int8x16_t op2 = vld1q_s8(d_int8_2.get());
//     int8x16_t op3 = vld1q_s8(d_int8_3.get());
//     int8x16_t res = vmlsq_s8(op1, op2, op3);
//     print_op3(8, &op1, 8, &op2, 8, &op3, 8, &res);
// }

// int main(int argc, char** argv) {
//     //test_vaddq_s8();
//     //test_vaddl_s8();
//     //test_vaddl_high_s8();
//     //test_vaddw_s8();
//     //test_vaddw_high_s8();
//     //test_vhaddq_s8();
//     //test_vrhaddq_s8();
//     //test_vqaddq_s8();
//     //test_vuqaddq_s8();
//     //test_vsqaddq_u8();
//     //test_vaddhn_s16();
//     //test_vaddhn_high_s16();
//     test_vraddhn_s16();
//     //test_vraddhn_high_s16();
//     //test_vmulq_u8();
//     //test_vmulxq_f32();
//     //test_vmulxq_lane_f32();
//     //test_vdivq_f32();
//     //test_vmlaq_s8();
//     //test_vmlal_s8();
//     //test_vmlal_high_s8();
//     //test_vmlsq_s8();

//     return 0;
// }
