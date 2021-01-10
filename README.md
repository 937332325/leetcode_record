# leetcode_record

## 常用工具库API整理
### string
注意写法s[i] == 'k'

### stack 栈
push(x), pop(), empty(), top()(size>0), size();

### vector
v.insert(v.end(),3);//在向量末尾追加新元素。
v.insert(v.end(),4,1);//在尾部插入4个1
vector<vector<int>> dp(a.size(), vector<int>(a[0].size(), 0));

### map 字典
创建 map<int,string> personnel
遍历 map<int, string>::iterator iter for(iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
插入 .insert(pair<int, string>(1, "student_one"))
删除 iter = mapStudent.find(1) mapStudent.erase(iter)或int n = mapStudent.erase(1)
是否存在 .count
数量 map[a]

### set
插入 insert
查找 find

### 位运算
https://www.jianshu.com/p/7bba031b11e7

### 易错点
1. c++不支持惰性赋值如int i_span, tmp_span = i, tmp;