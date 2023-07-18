# neon使用说明

## 1. 寄存器说明
ARMV7架构包含：
* 16个32位通用寄存器，R0-R15
* 16个128位NEON寄存器，Q0-Q15（同时也可以被视为32个64bit的寄存器，D0-D31）
* 16个32位VFP寄存器，S0-S15

ARMV8架构包含：
* 31个64位通用寄存器，X0-X30
* 32个128位NEON寄存器，V0-V31

<br>

## 2. 指令类型说明

NEON指令按照操作数类型可以分为正常指令、宽指令、窄指令、饱和指令、长指令。
* 正常指令：生成大小相同且类型通常与操作数向量相同的结果向量。
* 长指令：对双字向量操作数执行运算，生成四字向量的结果。生成的元素一般是操作数元素宽度的两倍，并属于同一类型。L标记，如VMOVL。
* 宽指令：一个双字向量操作数和一个四字向量操作数执行运算，生成四字向量结果。W标记，如VADDW。
* 窄指令：四字向量操作数执行运算，并生成双字向量结果，所生成的元素一般是操作数元素宽度的一半。N标记，如VMOVN。
* 饱和指令：当超过数据类型指定到范围则自动限制在该范围内。Q标记，如VQSHRUN

<br>

## 3. 指令命名规则

### 数据类型规则

**命名规则：<基本数据类型>x<lane个数>x<向量个数>_t**

* 基本数据类型： int8，int16，int32，int64，uint8，uint16，uint32，uint64，float16，float32
* lane个数：表示并行处理的基本类型数据的个数。
* 向量个数如果省略表示只有一个。

举例：int8x8_t、int8x8x3_t

<br>

### 指令函数规则

__命名规则：v<指令名><后缀>_<基本数据类型简写>__

* 指令名：描述进行的操作
* 后缀：代表指令的类型。如果没有，表示64位并行；如果后缀是q，表示128位并行；如果后缀是l，表示长指令；如果后缀是n，表示窄指令。
* 基本数据类型简写：s8，s16，s32，s64，u8，u16，u32，u64，f16，f32。

    |基本数据类型|类型简写|
    |:--|:--|
    |int8|s8|
    |uint8|u8|
    |int16|s16|
    |uint16|u16|
    |int32|s32|
    |uint32|u32|
    |int64|s64|
    |uint64|u64|
    |float16|f16|
    |float32|f32|

举例：

* vadd_u8：两个uint8x8相加为一个uint8x8
* vaddq_u8：两个uint8x16相加为一个uint8x16
* vaddl_u8：两个uint8x8相加为一个uint16x8

<br>

## 4. 指令使用方式和介绍

### 初始化寄存器

### 加载内存数据进寄存器

### 存储寄存器数据到内存

### 读取/修改寄存器数据

### 寄存器数据重排

### 类型转换指令

### 算数运算指令

#### 加法运算

**1. vadd_<类型简写>  /  vaddq_<类型简写>**

**说明：** 64位/128位整型或浮点型数据相加。

**函数原型：**

```cpp
int8x8_t vadd_s8(int8x8_t a, int8x8_t b);
int16x4_t vadd_s16(int16x4_t a, int16x4_t b);
int32x2_t vadd_s32(int32x2_t a, int32x2_t b);
int64x1_t vadd_s64(int64x1_t a, int64x1_t b);
uint8x8_t vadd_u8(uint8x8_t a, uint8x8_t b);
uint16x4_t vadd_u16(uint16x4_t a, uint16x4_t b);
uint32x2_t vadd_u32(uint32x2_t a, uint32x2_t b);
uint64x1_t vadd_u64(uint64x1_t a, uint64x1_t b);
float32x2_t vadd_f32(float32x2_t a, float32x2_t b);
float64x1_t vadd_f64(float64x1_t a, float64x1_t b);

int8x16_t vaddq_s8(int8x16_t a, int8x16_t b);
int16x8_t vaddq_s16(int16x8_t a, int16x8_t b);
int32x4_t vaddq_s32(int32x4_t a, int32x4_t b);
int64x2_t vaddq_s64(int64x2_t a, int64x2_t b);
uint8x16_t vaddq_u8(uint8x16_t a, uint8x16_t b);
uint16x8_t vaddq_u16(uint16x8_t a, uint16x8_t b);
uint32x4_t vaddq_u32(uint32x4_t a, uint32x4_t b);
uint64x2_t vaddq_u64(uint64x2_t a, uint64x2_t b);
float32x4_t vaddq_f32(float32x4_t a, float32x4_t b);
float64x2_t vaddq_f64(float64x2_t a, float64x2_t b);
```

**调用示例：**

```cpp
int8x16_t result = vaddq_s8(a, b);

a:      60  61  62  63  64   65   66   67   68   69   70   71   72   73   74   75
b:      60  61  62  63  64   65   66   67   68   69   70   71   72   73   74   75
result: 120 122 124 126 -128 -126 -124 -122 -120 -118 -116 -114 -112 -110 -108 -106
```

<br>

**2. vaddl_<类型简写>**

**说明：** 长指令；64位整型数据相加，结果数据是操作数位数的两倍。

**函数原型：**

```cpp
int16x8_t vaddl_s8(int8x8_t a, int8x8_t b);
int32x4_t vaddl_s16(int16x4_t a, int16x4_t b);
int64x2_t vaddl_s32(int32x2_t a, int32x2_t b);
uint16x8_t vaddl_u8(uint8x8_t a, uint8x8_t b);
uint32x4_t vaddl_u16(uint16x4_t a, uint16x4_t b);
uint64x2_t vaddl_u32(uint32x2_t a, uint32x2_t b);
```

**调用示例：**

```cpp
int16x8_t result = vaddl_s8(a, b);

a:      60  61  62  63  64  65  66  67
b:      60  61  62  63  64  65  66  67
result: 120 122 124 126 128 130 132 134
```

<br>

**3. vaddl_high_<类型简写>**

**说明：** 长指令；a和b的后半元素（高位数据）相加，结果位数扩大两倍存储。

**函数原型：**

```cpp
int16x8_t vaddl_high_s8(int8x16_t a, int8x16_t b);
int32x4_t vaddl_high_s16(int16x8_t a, int16x8_t b);
int64x2_t vaddl_high_s32(int32x4_t a, int32x4_t b);
uint16x8_t vaddl_high_u8(uint8x16_t a, uint8x16_t b);
uint32x4_t vaddl_high_u16(uint16x8_t a, uint16x8_t b);
uint64x2_t vaddl_high_u32(uint32x4_t a, uint32x4_t b);
```

**调用示例：**

```cpp
int16x8_t result = vaddl_high_s8(a, b);

a:      0  1  2  3  4  5  6  7  8  9  10  11  12  13  14  15
b:      0  1  2  3  4  5  6  7  8  9  10  11  12  13  14  15
result: 16 18 20 22 24 26 28 30
```

<br>

**4. vaddw_<类型简写>**

**说明：** 宽指令；a和b相加（a的数据位数是b的两倍，通道数相同，结果位数与a相同）。

**函数原型：**

```cpp
int16x8_t vaddw_s8(int16x8_t a, int8x8_t b);
int32x4_t vaddw_s16(int32x4_t a, int16x4_t b);
int64x2_t vaddw_s32(int64x2_t a, int32x2_t b);
uint16x8_t vaddw_u8(uint16x8_t a, uint8x8_t b);
uint32x4_t vaddw_u16(uint32x4_t a, uint16x4_t b);
uint64x2_t vaddw_u32(uint64x2_t a, uint32x2_t b);
```

**调用示例：**

```cpp
int16x8_t result = vaddw_s8(a, b);

a:      256 257 258 259 260 261 262 263
b:      120 121 122 123 124 125 126 127
result: 376 378 380 382 384 386 388 390
```

<br>

**6. vaddw_high_<数据类型简写>**

**说明：** 宽指令；a的元素加上b的后半部分（高位）对应位置元素。

调用示例：

```cpp
int16x8_t vaddw_high_s8(int16x8_t a, int8x16_t b)
a:      0  1  2  3  4  5  6  7
b:      0  1  2  3  4  5  6  7  8  9  10  11  12  13  14  15
result: 8  10 12 14 16 18 20 22
```

<br>

**7. vhadd_<数据类型简写> （64bit）/ vhaddq_<数据类型简写> （128bit）**

**说明：** a和b对应通道元素相加，并将所加结果右移一位存储，向下取整。

调用示例：

```cpp
int8x8_t vhadd_s8(int8x8_t a, int8x8_t b)
a:      5  6  7  8  9  10 11 12
b:      10 11 12 13 14 15 16 17
result: 7  8  9  10 11 12 13 14

int8x16_t vhaddq_s8(int8x16_t a, int8x16_t b)
a:      60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75
b:      73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88
result: 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81
```

<br>

**8. vrhadd_<数据类型简写> （64bit）/ vrhaddq_<数据类型简写> （128bit）**

**说明：** a和b对应通道元素相加，并将所加结果右移一位存储，向上取整。

调用示例：

```cpp
int8x8_t vrhadd_s8(int8x8_t a, int8x8_t b)
a:      5  6  7  8  9  10 11 12
b:      10 11 12 13 14 15 16 17
result: 8  9  10 11 12 13 14 15

int8x16_t vrhaddq_s8(int8x16_t a, int8x16_t b)
a:      60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75
b:      73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88
result: 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82
```

<br>

**9. vqadd_<数据类型简写> （64bit）/ vqaddq_<数据类型简写> （128bit）**

**说明：** 饱和指令；a和b对应通道元素相加，超出范围则自动限制在该数据类型表示范围内。

调用示例：

```cpp
int8x8_t vqadd_s8(int8x8_t a, int8x8_t b)
a:      62  63  64  65  66  67  68  69
b:      63  64  65  66  67  68  69  70
result: 125 127 127 127 127 127 127 127

int8x16_t vqaddq_s8(int8x16_t a, int8x16_t b)
a:      50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65
b:      73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88
result: 123 125 127 127 127 127 127 127 127 127 127 127 127 127 127 127
```

<br>

**10. vuqadd_<数据类型简写> （64bit）/ vuqaddq_<数据类型简写> （128bit）**

**说明：** 饱和指令；有符号数a和无符合数b对应通道元素相加，超出范围的自动限制在有符号数表示范围内。

调用示例：

```cpp
int8x8_t vuqadd_s8(int8x8_t a, uint8x8_t)
a:      50  51  52  53  54  55  56  57
b:      129 130 131 132 133 134 135 136
result: 127 127 127 127 127 127 127 127

int8x16_t vuqaddq_s8(int8x16_t a, uint8x16_t)
a:      50  51  52  53  54  55  56  57  58  59  60  61  62  63  64  65
b:      129 130 131 132 133 134 135 136 137 138 139 140 141 142 143 144
result: 127 127 127 127 127 127 127 127 127 127 127 127 127 127 127 127
```

<br>

**11. vsqadd_<数据类型简写> （64bit）/ vsqaddq_<数据类型简写> （128bit）**

**说明：** 饱和指令；无符号数a和有符号数b对应通道元素相加，超出范围自动限制在无符号数表示范围内。

调用示例：

```cpp
uint8x8_t vsqadd_u8(uint8x8_t a, int8x8_t b)
a:      210 211 212 213 214 215 216 217
b:      40  41  42  43  44  45  46  47
result: 250 252 254 255 255 255 255 255

uint8x16_t vsqaddq_u8(uint8x16_t a, int8x16_t b)
a:      210 211 212 213 214 215 216 217 218 219 220 221 222 223 224 225
b:      -3  -2  -1  0   1   2   3   4   5   6   7   8   9   10  11  12
result: 207 209 211 213 215 217 219 221 223 225 227 229 231 233 235 237
```

<br>

**12. vaddhn_<数据类型简写>**

**说明：** 窄指令；a和b对应通道元素相加，将结果的一半（高位部分）存储到最终结果数据中。

调用示例：

```cpp
int8x8_t vaddhn_s16(int16x8_t a, int16x8_t b)
a:      257 258 259 260 261 262 263 264
b:      50  51  52  53  54  55  56  57
result: 1   1   1   1   1   1   1   1
```

<br>

**13. vaddhn_high_<数据类型简写>**

**说明：** 窄指令；r的值存放到结果数据的低位部分；a和b对应通道元素相加，将求和结果的一半（高位部分）存储到结果数据的另一半（高位部分）。

调用示例：

```cpp
int8x16_t vaddhn_high_s16(int8x8_t r, int16x8_t a, int 16x8_t b)
r:      120 121 122 123 124 125 126 127
a:      250 251 252 253 254 255 256 257
b:      50  51  52  53  54  55  56  57
result: 120 121 122 123 124 125 126 127 1 1 1 1 1 1 1 1
```

<br>

**14. vraddhn_<数据类型简写>**  tocheck

**说明：** 窄指令；a和b对应通道元素相加，将求和的一半（高位部分）存储到结果数据中。

调用示例：

```cpp
int8x8_t vraddhn_s16(int16x8_t a, int16x8_t b)
a:      66 67 68 69 70 71 72 73
b:      60 61 62 63 64 65 66 67
result: 0  1  1  1  1  1  1  1
```

<br>

**15. vraddhn_high_<数据类型简写>**

**说明：** 窄指令；r的值存放到结果数据的低位部分；a和b对应通道相加，将求和的一半（高位部分）存储到结果数据中（低位部分超过可表示范围的一半则进1）

调用示例：

```cpp
int8x16_t vraddhn_high_s16(int8x8_t r, int16x8_t a, int 16x8_t b)
r:      120 121 122 123 124 125 126 127
a:      623 624 625 626 627 628 629 630
b:      50  51  52  53  54  55  56  57
result: 120 121 122 123 124 125 126 127 3 3 3 3 3 3 3 3
```

<br>

#### 乘法运算

**1.  vmul_<数据类型简写> （64bit）/  vmulq_<数据类型简写> （128bit）**

**说明：** 对应通道的数据相乘。

调用示例：

```cpp
int8x16_t vmulq_s8(int8x16_t a, int8x16_t b)
a:      4  5  6  7  8  9  10  11
b:      5  6  7  8  9  10 11  12
result: 20 30 42 56 72 90 110 -124
```

<br>

**2. vmulx_<数据类型简写> （64bit）/ vmulxq_<数据类型简写> （128bit）**

**说明：** 对应通道的浮点数相乘。

调用示例：

```cpp
float32x4_t vmulxq_f32(float32x4_t a, float32x4_t b)

a:      10  11  12  13
b:      11  12  13  14
result: 110 132 156 182
```

<br>

**vmulx_lane_<数据类型简写> / vmulxq_lane_<数据类型简写>**

**说明：** a的元素和b指定通道的元素相乘。

调用示例：

```cpp
float32x4_t vmulxq_lane_f32(float32x4_t a, float32x2_t b, const int lane)

a:      10  11  12  13
b:      11  12
result: 120 132 144 156
```

<br>

#### 除法运算

**vdiv_<数据类型简写> （64bit）/ vdivq_<数据类型简写> （128bit）**

**说明：** 浮点数相除。

调用示例：

```cpp
float32x4_t vdivq_f32(float32x4_t a, float32x4_t b)

a:      320       321       322       323
b:      11        12        13        14
result: 29.090910 26.750000 24.769230 23.071428
```

<br>

#### 乘加/减运算

**1. vmla_<数据类型简写> （64bit）/ vmlaq_<数据类型简写> （128bit）**

**说明：** b和c对应通道元素相乘，结果再与a对应通道元素相加。

调用示例：

```cpp
int8x16_t vmlaq_s8(int8x16_t a, int8x16_t b, int8x16_t c)

a:      4  5  6  7  8  9    10   11  12  13  14 15 16 17  18   19
b:      5  6  7  8  9  10   11   12  13  14  15 16 17 18  19   20
c:      6  7  8  9  10 11   12   13  14  15  16 17 18 19  20   21
result: 34 47 62 79 98 119  -114 -89 -62 -33 -2 31 66 103 -114 -73
```

<br>

**2. vmlal_<数据类型简写>**

**说明：** b和c对应通道元素相乘，结果再与a对应通道元素相加（操作数a的位数是操作数b/c的两倍，通道数相同）。

调用示例：

```cpp
int16x8_t vmlal_s8(int16x8_t a, int8x8_t b, int8x8_t c)

a:      4  5  6  7  8  9   10  11
b:      5  6  7  8  9  10  11  12
c:      6  7  8  9  10 11  12  13
result: 34 47 62 79 98 119 142 167
```

<br>

**3. vmlal_high_<数据类型简写>**

**说明：** b和c的后半部分（高位）对应通道元素相乘，结果再与a对应通道元素相加。（a的位数是b和c的两倍，通道数是其一半）

调用示例：

```cpp
int16x8_t vmlal_high_s8(int16x8_t a, int8x16_t b, int8x16_t c)

a:      4   5   6   7   8   9   10  11
b:      5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20
c:      6   7   8   9   10  11  12  13  14  15  16  17  18  19  20  21
result: 186 215 246 279 314 351 390 431
```

<br>

**4. vmls_<数据类型简写> / vmlsq_<数据类型简写>**

**说明：** b和c对应通道元素相乘，再用a减去对应通道数相乘结果。

调用示例：

```cpp
int8x16_t vmls_s8(int8x8_t a, int8x8_t b, int8x8_t c)

a:      4   5   6   7   8   9    10   11
b:      5   6   7   8   9   10   11   12
c:      6   7   8   9   10  11   12   13
result: -26 -37 -50 -65 -82 -101 -122 111
```

<br>

数据处理指令

比较指令

归约指令
