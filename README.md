# Card	会员卡交易系统

## Time类	时间

### 成员

int year	年

int month	月

int day	日

int hour	时

int minute	分

## Log类	交易记录

### 成员

Time time	交易时间

float money	交易金额

Log* next	指向下一节点的指针

### 成员函数

#### logCreate()	创建Log动态链表

返回值：

Log* 链表头指针

#### logDelete()	按时间删除Log链表中某一节点

参数：

Log* head	链表头指针

Time t	时间

返回值：

Log* 新链表头指针

#### logExtend()	在Log链表后接入一个Log类数据

参数：

Log* head	链表头指针

返回值：

Log* 新链表头指针

#### logSearch()	在Log链表中按时间查找某个数据

参数：

Log* head	链表头指针

返回值：

Log* 指向符合条件的元素的指针

#### logFix()	修复Log链表中某个数据

参数：

Log* head	链表头指针

## Card类	会员卡

### 成员

char *name	用户姓名

char *number	会员卡卡号

char *password	会员卡密码

short level	会员卡等级（与折扣有关）

float remaining_sum	卡内余额

float comsumption	总消费金额（与等级有关）

Time createTime	创建时间

Time validTime	有效时间（距离过期的剩余时间）

bool isLost	是否丢失

Log* rechargeLog	充值记录

Log* comsumeLog	消费记录

Card *next	指向下一节点的指针

### 成员函数

#### cardCreate()	创建Card动态链表

#### cardDelete()	删除Card链表中某一节点

#### cardExtend()	在Card链表后接入一个Card类数据

#### cardSort()	给Card链表排序

#### cardSearch()	在Card链表中查找某个数据

#### cardFix()		修复Card链表中某个数据

#### cardLost()	会员卡挂失

#### cardLogIn()	登录会员卡

#### cardRecharge()	会员卡充值与升级

#### cardComsume()	会员卡消费及其折扣

#### cardFind()	找回会员卡密码

## 系统

#### logIn()	系统登录

#### backUp()	系统数据备份

#### restore()	系统数据恢复

#### read()	文件读取

#### write()	文件写入
