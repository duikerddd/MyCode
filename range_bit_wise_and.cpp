//给定范围 [m, n]，其中 0 <= m <= n <= 2147483647，返回此范围内所有数字的按位与（包含 m, n 两端点）。

class Solution {
public:
    //解题思路: 暴力求解,使用循环,直接按位与  x 超时
    /*int ret = 0xffffffff;
        for(int i=m;i<=n;i++)
        {
            ret=ret & i;
        }
    */

    //解题思路: 因为数字连续,可能含有规律. --> m&n 公共前缀补0
    //       1   2   3   4   5    6    7
    //      001 010 011 100 101  110  111
    //  &   000 000 000 000 000  000  = 0
    //  已找到的规律: 有0的地方,一定是0.  
    //               因为连续,所以每个位置都会出来0,可能留下1的结果.
    //               通过数学证明,发现结果即为: m&n 的公共前缀补0
    
    
    //  问题 --> 如何找到公共前缀
    //  解决 --> 1.右移 2.消1法
    //右移 两数同时消,直到相等,则只剩下公共前缀
    /*
    int rangeBitwiseAnd(int m, int n) {
        int shift = 0;
        //m<n就很灵性,m<n是已知条件, 因为当m==n的时候,说明前缀一模一样.
        while(m<n)
        {
            m>>=1;
            n>>=1;
            shift++;
        }

        return m<<shift;
    }
    */
    //消1法 : 大数消到只剩前缀
    int rangeBitwiseAnd(int m, int n) {
        
        //m<n更灵性,当m>=n的时候,说明n只剩下了公共前缀
        while(m<n)
        {
            n=n&(n-1);
        }

        return n;
    
    }
};
