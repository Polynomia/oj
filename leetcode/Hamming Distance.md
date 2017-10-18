# Hamming Distance
Given two integers x and y, calculate the Hamming distance.
## example
Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
## 解析
第一步操作很简单，只需要异或起来就可以得到不同的bit。因此本题的关键在于计算异或之后为1的bit的数量。  
         
* 挨个计数

这是最简单最容易想到的一个方法。复杂度是二进制的位数$log_2n$，但是我直接用了32位。这是我的代码：

```c++
class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        int cnt = 0;
        for(int i = 0; i <32; i++){
            if(z&(1<<i)) cnt += 1;
        }
        return cnt;
    }
};
```

* 利用操作n&(n-1) 

n二进制数中的1bits要比n&(n-1)多一个，因此可以写成这样：

```c++
class Solution {
public:
    int hammingDistance(int x, int y) {
         int count=0; 
         n = x ^ y;
         while(n != 0){ 
            n &= n-1; 
            count ++; 
         } 
         return count;
    }
};
```

* 超级炫酷的方法

下面这个版本则彰显位运算的强大能力，若不告诉这个函数的功能，一般一眼看上去是想不到这是做什么的，这也是wikipedia上给出的计算hamming_weight方法。

```c++
class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x ^ y;
        n = (n&0x55555555) + ((n>>1)&0x55555555); 
        n = (n&0x33333333) + ((n>>2)&0x33333333); 
        n = (n&0x0f0f0f0f) + ((n>>4)&0x0f0f0f0f); 
        n = (n&0x00ff00ff) + ((n>>8)&0x00ff00ff); 
        n = (n&0x0000ffff) + ((n>>16)&0x0000ffff); 
        return 0；
    }
};
```

没有循环，5个位运算语句，一次搞定。

比如这个例子，143的二进制表示是10001111，这里只有8位，高位的0怎么进行与的位运算也是0，所以只考虑低位的运算，按照这个算法走一次

+---+---+---+---+---+---+---+---+
| 1 | 0 | 0 | 0 | 1 | 1 | 1 | 1 |   <---143
+---+---+---+---+---+---+---+---+
|  0 1  |  0 0  |  1 0  |  1 0  |   <---第一次运算后
+-------+-------+-------+-------+
|    0 0 0 1    |    0 1 0 0    |   <---第二次运算后
+---------------+---------------+
|        0 0 0 0 0 1 0 1        |   <---第三次运算后，得数为5
+-------------------------------+

这里运用了分治的思想，先计算每对相邻的2位中有几个1，再计算每相邻的4位中有几个1，下来8位，16位，32位，因为2^5 ＝ 32，所以对于32位的机器，5条位运算语句就够了。




