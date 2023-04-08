# Card	会员卡交易系统

## Time类	时间

### 成员

int year	年

int month	月

int day	日

int hour	时

int minute	分

### 成员函数

#### setTime()

修改时间

参数：

Time t	待修改的时间

int y	年

int mo	月

int d	日

int h	时

int mi	分

Log类	交易记录

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

#### logSearch()

在Log链表中按时间或金额查找某个数据

参数：

Log* head	链表头指针

int n	参数个数（1或2）

Time t	时间

double	money	交易金额

返回值：

Log* 指向符合条件的元素的指针

#### logFix()

修复Log链表中某个数据（可以删除）

参数：

Log* head	链表头指针

返回值：

Card*	新链表头指针

## Card类	会员卡

### 成员

char *name	用户姓名

char *number	会员卡卡号

char *password	会员卡密码

short level	会员卡等级（与折扣有关）

double remaining_sum	卡内余额

double comsumption	总消费金额（与等级有关）

Time createTime	创建时间

Time validTime	有效时间（距离过期的剩余时间）

bool isLost	是否丢失（已丢失的卡无法使用）

Log* rechargeLog	充值记录

Log* comsumeLog	消费记录

Card *next	指向下一节点的指针

### 成员函数

#### cardCreate()

创建Card动态链表

返回值：

Card*	链表头指针

#### cardDelete()

删除Card链表中某一节点（退卡等操作）

参数：

Card* head	链表头指针

char* name/number	用户姓名或卡号

返回值：

Card*	新链表头指针

#### cardExtend()

在Card链表后接入一个Card类数据

参数：

Card* head	链表头指针

返回值：

Card*	新链表头指针

#### cardSort()

依次按关键词给Card链表排序

参数：

Card* head	链表头指针

返回值：

Card*	新链表头指针

#### cardSearch()

在Card链表中查找某个数据

参数：

Card* head	链表头指针

char* name/number	用户姓名或卡号

返回值：

Card*	指向符合条件的数据的指针

#### cardFix()

修复Card链表中某个数据

参数：

Card* head	链表头指针

返回值：

Card*	新链表头指针

#### cardLost()

会员卡挂失

参数：

Card* head	链表头指针

char* name/number	用户姓名或卡号

返回值：

Card*	新链表头指针

#### cardLogIn()

登录会员卡

参数：

char* name/number	用户名/卡号

char* password	密码

返回值：

bool	是否登录成功

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

#### cardFind()

找回会员卡密码

参数：

Card* head	链表头指针

char* name/number	用户名/卡号

## Admin类	系统账户

### 成员

char* username	账户名

char* password	密码

bool isSuper	是否为超级管理员

Admin* next	指向下一节点的指针

### 成员函数

#### AdminCreate()

创建Admin动态链表

返回值：

Admin*	链表头指针

#### AdminDelete()

删除Admin链表中某一节点

参数

Admin* head	链表头指针

char* username	账户名

返回值：

Admin*	新链表头指针

#### AdminExtend()

在Admin链表后接入一个Admin类数据

参数：

Admin* head	链表头指针

返回值：

Admin*	新链表头指针

#### adminSearch()

在Admin链表中查找某个数据

参数：

Admin* head	链表头指针

char* username	账户名

返回值：

Admin*	指向符合条件的数据的指针

## 系统

int authority	权限等级（1：管理员，2：超级管理员）

#### authorize()

验证权限

#### logIn()

系统登录

#### logOut()

退出登录

#### backUp()

系统数据备份

#### restore()

系统数据恢复

#### read()

文件读取

#### write()

文件写入
