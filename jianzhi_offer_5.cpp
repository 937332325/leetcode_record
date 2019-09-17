//
// Created by 陈海斌 on 2019-09-04.
//

#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    //原来的做法 nowcoder：3ms 内存：472k
    /*
	void replaceSpace(char *str,int length) {
        string t = str;
        int t_len = t.size();
        string re="%20";
        for (int i=0;i<t_len;i++)
        {
            if (t[i]==' ')
            {
                //t=t.replace(t.begin()+i,t.begin()+i+1,re);
                t = t.substr(0,i) + re + t.substr(i+1,t_len);
                //i +=  re.size();
                t_len += re.size();
            }
        }
        //str = (char*)t.c_str();
        auto ret=t.c_str();
        strcpy(str,ret);
        return;
	}
    */
    // 每找到一个空格 逐个往后移位的时间复杂度是n^2
    // 根据书里提示 从后往前遍历赋值 时间复杂度减少为n
    //运行时间：5ms 占用内存：612k
    char* replaceSpace(char *str,int length) {
        int replace_length = length;
        for (int i=0;i<strlen(str);i++)
        {
            if (str[i] == ' ')
                replace_length += 2;
        }
        char str_res[replace_length+1];
        str_res[replace_length] = '\0';
        int fast_pointer = replace_length-1;
        int low_pointer = length-1;
        for (low_pointer; low_pointer>=0; low_pointer--)
        {
            if (fast_pointer < low_pointer)
            {
                break;
            }
            else if (str[low_pointer] == ' ')
            {
                str_res[fast_pointer--] = '0';
                str_res[fast_pointer--] = '2';
                str_res[fast_pointer--] = '%';
            }
            else
            {
                str_res[fast_pointer--] = str[low_pointer];
            }
        }
        //char*指向了固定地址
        strcpy(str,str_res);
        return str_res;
    }
};

/*
int main()
{
    Solution s;
    char test[] = "we are";
    char *a = test;
    s.replaceSpace(a, 6);
    std::cout << a << std::endl;
}
*/