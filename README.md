# Card	会员卡交易系统

## Time类	时间

### 成员

unsigned year	年

unsigned month	月

unsigned day	日

unsigned hour	时

unsigned minute	分

### 成员函数

#### timeComp()

比较时间先后

参数：

Time x	待比较的时间1

TIme y	待比较的时间2

返回值：(int)

| x>y | x=y | x<y |
| --- | --- | --- |
| 1   | 0   | -1  |

## Log类	交易记录

### 成员

Time time	交易时间

double money	交易金额

Log* next	指向下一节点的指针

### 成员函数

#### logCreate()

创建Log动态链表

返回值：

Log* 链表头指针

#### logDelete()

按时间删除Log链表中某一节点

参数：

Log* head	链表头指针

Time t	时间

返回值：

Log* 新链表头指针

#### logExtend()

在Log链表后接入一个Log类数据

参数：

Log* head	链表头指针

返回值：

Log* 新链表头指针

#### logPrint()

输出指定Log类数据的内容

参数：

Log* l	指向指定Log类数据的指针

#### logPrints()

输出Log链表所有数据内容

参数：

Log* head	链表头指针

#### logSearch()

在Log链表中按时间区间或金额查找某个数据

参数：

Log* head	链表头指针

Time t1,t2	时间区间的端点（包含）

double money	交易金额

返回值：

Log* 指向符合条件的第一个元素的指针

#### logSearchs()

在Log链表中按时间区间或金额查找某些数据

参数：

Log* head	链表头指针

Time t1,t2	时间区间的端点（包含）

double money	交易金额

返回值：

Log* 指针数组，储存所有指向符合条件的元素的指针

#### logFix()

修改Log链表中某个数据

参数：

Log* head	链表头指针

## Card类	会员卡

### 成员

char *name	用户姓名

char *number	会员卡卡号

char* phone	手机号

char *password	会员卡密码

short level	会员卡等级（与折扣有关）

double remaining_sum	卡内余额

double total_charge	总充值金额（与等级有关）

Time createTime	创建时间

Time validTime	有效时间（距离过期的剩余时间）

bool isLost	是否丢失（已丢失的卡无法使用）

Log* rechargeLog	充值记录

Log* consumeLog	消费记录

Card *next	指向下一节点的指针

### 成员函数

#### cardCreate()

创建Card动态链表

返回值：

Card*	链表头指针

#### cardDelete()

删除Card链表中某一节点（退卡等操作）

参数：

char* number/phone	卡号/手机号

返回值：

Card*	新链表头指针

#### cardExtend()

在Card链表后接入一个Card类数据

返回值：

Card*	新链表头指针

#### cardPrint()

输出指定Card类数据的内容

参数：

Card* c	指向指定Card类数据的指针

#### cardPrints()

输出Card链表内所有数据的内容

#### cardSort()

依次按关键词给Card链表排序

返回值：

Card*	新链表头指针

#### cardSearch()

在Card链表中查找某个数据

参数：

Card* head	链表头指针

char* name/number/phone	用户名/卡号/手机号

short level	会员等级

Time t1,t2	时间区间的端点（包含）

返回值：

Card*	指向符合条件的第一个数据的指针

#### cardSearchs()

在Card链表中查找某些数据

参数：

int* cnt	符合条件的数据个数

char* name/number/phone	用户名/卡号/手机号

short level	会员等级

Time t1,t2	时间区间的端点（包含）

返回值：

Card* 指针数组，储存所有指向符合条件的元素的指针

#### cardFix()

修改Card链表中某个数据

参数：

Card* c	指向待修改Card类数据的指针

返回值：

Card*	新链表头指针

#### cardSignUp()

注册会员卡（包含对已挂失卡的操作）

#### cardLogIn()

登录会员卡

参数：

char* number/phone	卡号/手机号

char* password	密码

返回值：

Card*	指向登录成功的Card的指针

#### cardLogOut()

退出会员卡登录

#### cardIdentify()

验证会员卡用户身份

参数：

Card* c	使用中的Card

返回值：

bool	是否为注册用户本人

#### cardUpdatePhone()

更换会员卡绑定的手机

参数：

Card* c	使用中的Card

#### cardUpdatePassword()

更换会员卡密码

参数：

Card* c	使用中的Card

#### cardLost()

会员卡挂失

参数：

char* number/phone	卡号/手机号

#### cardFind()

找回会员卡

参数：

char* number	卡号

#### cardRecharge()

会员卡充值与升级

参数：

Card* c	指向待操作卡的指针

double money	充值金额

#### cardConsume()

会员卡消费及其折扣

参数：

Card* c	指向待操作卡的指针

double money	消费金额

## Admin类	系统账户

### 成员

char* username	账户名

char* password	密码

bool isSuper	是否为超级管理员

Admin* next	指向下一节点的指针

### 成员函数

#### adminCreate()

创建Admin动态链表

返回值：

Admin*	链表头指针

#### adminDelete()

删除Admin链表中某一节点

参数

char* username	账户名

返回值：

Admin*	新链表头指针

#### adminExtend()

在Admin链表后接入一个Admin类数据

返回值：

Admin*	新链表头指针

#### adminSearch()

在Admin链表中查找某个数据

参数：

char* username	账户名

返回值：

Admin*	指向符合条件的数据的指针

#### adminFix()

修改Admin链表中某个数据

参数：

Admin* a	指向待修改Admin数据的指针

#### adminLogIn()

管理员登录

#### SASignUp()

超级管理员注册

#### adminSignUp()

管理员注册

#### adminLogOut()

管理员退出

## 系统

int authority	权限等级（1：管理员，2：超级管理员）

bool isLoggenIn	管理员是否登录

bool isCardLoggedIn	是否有会员卡登录

#### logOut()

退出系统

#### authorize()

验证权限

#### backUp()

系统数据备份

#### restore()

系统数据恢复

#### read()

文件读取

#### write()

文件写入

#### initialize()

程序初始化

#### System()

系统菜单
