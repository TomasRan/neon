# neon使用

## 寄存器
ARMV7架构包含：
* 16个32位通用寄存器，R0-R15
* 16个128位NEON寄存器，Q0-Q15（同时也可以被视为32个64bit的寄存器，D0-D31）
* 16个32位VFP寄存器，S0-S15

ARMV8架构包含：
* 31个64位通用寄存器，X0-X30
* 32个128位NEON寄存器，V0-V31

<br>

## 指令类型

NEON指令按照操作数类型可以分为正常指令、宽指令、窄指令、饱和指令、长指令。
* 正常指令：生成大小相同且类型通常与操作数向量相同的结果向量。
* 长指令：对双字向量操作数执行运算，生成四字向量的结果。生成的元素一般是操作数元素宽度的两倍，并属于同一类型。L标记，如VMOVL。
* 宽指令：一个双字向量操作数和一个四字向量操作数执行运算，生成四字向量结果。W标记，如VADDW。
* 窄指令：四字向量操作数执行运算，并生成双字向量结果，所生成的元素一般是操作数元素宽度的一半。N标记，如VMOVN。
* 饱和指令：当超过数据类型指定到范围则自动限制在该范围内。Q标记，如VQSHRUN

<br>

## 指令命名规则

### 数据类型规则

__命名规则：<基本数据类型>x<lane个数>x<向量个数>_t__

* 基本数据类型： int8，int16，int32，int64，uint8，uint16，uint32，uint64，float16，float32
* lane个数：表示并行处理的基本类型数据的个数。
* 向量个数如果省略表示只有一个。

举例：int8x8_t、int8x8x3_t


### 指令函数规则

__命名规则：v<指令名><后缀>_<基本数据类型简写>__

*
指令名：描述进行的操作
*
后缀：代表指令的类型。如果没有，表示64位并行；如果后缀是q，表示128位并行；如果后缀是l，表示长指令；如果后缀是n，表示窄指令。
*
基本数据类型简写：s8，s16，s32，s64，u8，u16，u32，u64，f16，f32。

基本数据类型
简写
int8
s8
uint8
u8
int16
s16
uint16
u16
int32
s32
uint32
u32
int64
s64
uint64
u64
float16
f16
float32
f32


举例：
*
vadd_u8：两个uint8x8相加为一个uint8x8
*
vaddq_u8：两个uint8x16相加为一个uint8x16
*
vaddl_u8：两个uint8x8相加为一个uint16x8



初始化寄存器

加载内存数据进寄存器

存储寄存器数据到内存

读取/修改寄存器数据

寄存器数据重排

类型转换指令

算数运算指令

运算类型
指令形式
说明
示例
架构
加法运算
vadd_<数据类型简写>
64位数据相加

v7, A32, A64

vaddq_<数据类型简写>
128位数据相加

v7, A32, A64

vaddl_<数据类型简写>
长指令相加，结果数据是操作数位数的两倍
例如：uint16x8_t vaddl_u8(uint8x8_t a, uint8x8_t)

v7, A32, A64

vaddl_high_<数据类型简写>
操作数a的后半部分（高位）元素加上操作数b的后半部分（高位）元素，结果数据位数扩大两倍存储。
int16x8_t vaddl_hight_s8(int8x16_t a, int8x16_t b)
a: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
b: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
result: 16 18 20 22 24 26 28 30
A64

vaddw_<数据类型简写>
宽指令相加，操作数a和b维度相同，操作数a的位数是操作数b的两倍，结果位数同操作数a相同。
int16x8_t vaddw_s8(int16x8_t a, int8x8_t b)
a: 256 257 258 259 260 261 262 263
b: 120 121 122 123 124 125 126 127
result: 376 378 380 382 384 386 388 390
v7, A32, A64

vaddw_high_<数据类型简写>
操作数a的元素加上操作数b的后半部分（高位）对应位置元素。
int16x8_t vaddw_high_s8(int16x8_t a, int8x16_t b)
a: 0 1 2 3 4 5 6 7
b: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
result: 8 10 12 14 16 18 20 22
A64

vhadd_<数据类型简写> （64位数据）
vhaddq_<数据类型简写> （128位数据）
操作数a的元素加上对应通道操作数b的元素，并将所加结果右移一位存储，向下取整。
int8x8_t vhadd_s8(int8x8_t a, int8x8_t b)
a: 5 6 7 8 9 10 11 12
b: 10 11 12 13 14 15 16 17
result: 7 8 9 10 11 12 13 14
int8x16_t vhaddq_s8(int8x16_t a, int8x16_t b)
a: 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75
b: 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88
result: 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81
v7, A32, A64

vrhadd_<数据类型简写> （64位数据）
vrhaddq_<数据类型简写> （128位数据）
操作数a的元素加上对应通道操作数b的元素，并将所加结果右移一位存储，向上取整。
int8x8_t vrhadd_s8(int8x8_t a, int8x8_t b)
a: 5 6 7 8 9 10 11 12
b: 10 11 12 13 14 15 16 17
result: 8 9 10 11 12 13 14 15
int8x16_t vrhaddq_s8(int8x16_t a, int8x16_t b)
a: 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75
b: 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88
result: 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82
v7, A32, A64

vqadd_<数据类型简写> （64位数据）
vqaddq_<数据类型简写> （64位数据）
饱和指令。
操作数a和操作数b对应通道元素相加，超出范围的自动限制在该数据类型表示范围内。
int8x8_t vqadd_s8(int8x8_t a, int8x8_t b)
a: 62 63 64 65 66 67 68 69
b: 63 64 65 66 67 68 69 70
result: 125 127 127 127 127 127 127 127
int8x16_t vqaddq_s8(int8x16_t a, int8x16_t b)
a: 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65
b: 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88
result: 123 125 127 127 127 127 127 127 127 127 127 127 127 127 127 127
v7, A32, A64

vuqadd_<数据类型简写> （64位数据）vuqaddq_<数据类型简写> （128位数据）
饱和指令。
有符号操作数a和无符合操作数b对应通道元素相加，超出范围的自动限制在有符号数表示范围内。
int8x8_t vuqadd_s8(int8x8_t a, uint8x8_t)
a: 50 51 52 53 54 55 56 57
b: 129 130 131 132 133 134 135 136
result: 127 127 127 127 127 127 127 127
int8x16_t vuqaddq_s8(int8x16_t a, uint8x16_t)
a: 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65
b: 129 130 131 132 133 134 135 136 137 138 139 140 141 142 143 144
result: 127 127 127 127 127 127 127 127 127 127 127 127 127 127 127 127
A64

vsqadd_<数据类型简写> （64位数据）
vsqaddq_<数据类型简写> （128位数据）
饱和指令。
无符号数a和有符号数b对应通道元素相加，超出范围自动限制在无符号数表示范围内。
uint8x8_t vsqadd_u8(uint8x8_t a, int8x8_t b)
a: 210 211 212 213 214 215 216 217
b: 40 41 42 43 44 45 46 47
result: 250 252 254 255 255 255 255 255
uint8x16_t vsqaddq_u8(uint8x16_t a, int8x16_t b)
a: 210 211 212 213 214 215 216 217 218 219 220 221 222 223 224 225
b: -3 -2 -1 0 1 2 3 4 5 6 7 8 9 10 11 12
result: 207 209 211 213 215 217 219 221 223 225 227 229 231 233 235 237
A64

vaddhn_<数据类型简写>
窄指令。
操作数a和操作数b对应通道相加求和，将求和结果的一半（高位部分）存储到最终结果数据中。
int8x8_t vaddhn_s16(int16x8_t a, int16x8_t b)
a: 257 258 259 260 261 262 263 264
b: 50 51 52 53 54 55 56 57
result: 1 1 1 1 1 1 1 1
v7, A32, A64

vaddhn_high_<数据类型简写>
窄指令。
操作数r的值存放到结果数据的低位部分；操作数a和操作数b对应通道相加求和，将求和结果的一半（高位部分）存储到结果数据的另一半（高位部分）。
int8x16_t vaddhn_high_s16(int8x8_t r, int16x8_t a, int 16x8_t b)
a: 250 251 252 253 254 255 256 257
b: 50 51 52 53 54 55 56 57
result: 120 121 122 123 124 125 126 127 1 1 1 1 1 1 1 1
A64

vraddhn_<数据类型简写>
窄指令。
操作数a和操作数b对应通读相加求和，将求和的一半（高位部分）存储到结果数据中（低位部分超过可表示范围的一半则进1）
int8x8_t vraddhn_s16(int16x8_t a, int16x8_t b)
a: 66 67 68 69 70 71 72 73
b: 60 61 62 63 64 65 66 67
result: 0 1 1 1 1 1 1 1
v7, A32, A64

vraddhn_high_<数据类型简写>
窄指令。
操作数r的值存放到结果数据的低位部分；操作数a和操作数b对应通读相加求和，将求和的一半（高位部分）存储到结果数据中（低位部分超过可表示范围的一半则进1）
int8x16_t vraddhn_high_s16(int8x8_t r, int16x8_t a, int 16x8_t b)
a: 623 624 625 626 627 628 629 630
b: 50 51 52 53 54 55 56 57
result: 120 121 122 123 124 125 126 127 3 3 3 3 3 3 3 3
A64
乘法运算
vmul_<数据类型简写> （64位数据）
vmulq_<数据类型简写> （128位数据）
对应通道的数据相乘
int8x16_t vmulq_s8(int8x16_t a, int8x16_t b)
a: 4 5 6 7 8 9 10 11
b: 5 6 7 8 9 10 11 12
result: 20 30 42 56 72 90 110 -124
v7, A32, A64

vmulx_<数据类型简写>
vmulxq_<数据类型简写>
对应通道的浮点数相乘
float32x4_t vmulxq_f32(float32x4_t a, float32x4_t b)
a: 10.000000 11.000000 12.000000 13.000000
b: 11.000000 12.000000 13.000000 14.000000
result: 110.000000 132.000000 156.000000 182.000000
A64

vmulx_lane_<数据类型简写>
vmulxq_lane_<数据类型简写>
操作数a的元素和操作数b指定通道的元素相乘。
float32x4_t vmulxq_lane_f32(float32x4_t, float32x2_t b, const int lane)
a: 10.000000 11.000000 12.000000 13.000000
b: 11.000000 12.000000
result: 120.000000 132.000000 144.000000 156.000000
A64

vdiv_<数据类型简写> （64位数据）
vdivq_<数据类型简写> （128位数据）
浮点数相除
float32x4_t vdivq_f32(float32x4_t a, float32x4_t b)
a: 320.000000 321.000000 322.000000 323.000000
b: 11.000000 12.000000 13.000000 14.000000
result: 29.090910 26.750000 24.769230 23.071428
A64

vmla_<数据类型简写> （64位数据）
vmlaq_<数据类型简写> （128位数据）
操作数b和操作数c对应通道元素相乘，结果再与操作数a对应通道元素相加。
int8x16_t vmlaq_s8(int8x16_t a, int8x16_t b, int8x16_t c)
a: 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
b: 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
c: 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21
result: 34 47 62 79 98 119 -114 -89 -62 -33 -2 31 66 103 -114 -73
v7, A32, A64

vmlal_<数据类型简写>
操作数b和操作数c对应通道元素相乘，结果再与操作数a对应通道元素相加。（操作数a的位数是操作数b/c的两倍，通道数相同）
int16x8_t vmlal_s8(int16x8_t a, int8x8_t b, int8x8_t c)
a: 4 5 6 7 8 9 10 11
b: 5 6 7 8 9 10 11 12
c: 6 7 8 9 10 11 12 13
result: 34 47 62 79 98 119 142 167
v7, A32, A64

vmlal_high_<数据类型简写>
操作数b和操作数c的后半部分（高位）对应通道元素相乘，结果再与操作数a对应通道元素相加。（操作数a的位数是操作数b/c的两倍，通道数是其一半）
int16x8_t vmlal_high_s8(int16x8_t a, int8x16_t b, int8x16_t c)
a: 4 5 6 7 8 9 10 11
b: 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
c: 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21
result: 186 215 246 279 314 351 390 431
A64

vmls_<数据类型简写>
vmlsq_<数据类型简写>
操作数b和操作数c对应通道元素相乘，再操作数a减去对应通道数相乘结果。
a[i] - b[i] * c[i]
a: 4 5 6 7 8 9 10 11
b: 5 6 7 8 9 10 11 12
c: 6 7 8 9 10 11 12 13
result: -26 -37 -50 -65 -82 -101 -122 111
v7, A32, A64


数据处理指令

比较指令

归约指令
