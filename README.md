# Card	��Ա������ϵͳ

## Time��	ʱ��

### ��Ա

unsigned year	��

unsigned month	��

unsigned day	��

unsigned hour	ʱ

unsigned minute	��

### ��Ա����

#### timeComp()

�Ƚ�ʱ���Ⱥ�

������

Time x	���Ƚϵ�ʱ��1

TIme y	���Ƚϵ�ʱ��2

����ֵ��(int)

| x>y | x=y | x<y |
| --- | --- | --- |
| 1   | 0   | -1  |

## Log��	���׼�¼

### ��Ա

Time time	����ʱ��

double money	���׽��

Log* next	ָ����һ�ڵ��ָ��

### ��Ա����

#### logCreate()

����Log��̬����

����ֵ��

Log* ����ͷָ��

#### logDelete()

��ʱ��ɾ��Log������ĳһ�ڵ�

������

Log* head	����ͷָ��

Time t	ʱ��

����ֵ��

Log* ������ͷָ��

#### logExtend()

��Log��������һ��Log������

������

Log* head	����ͷָ��

����ֵ��

Log* ������ͷָ��

#### logPrint()

���ָ��Log�����ݵ�����

������

Log* l	ָ��ָ��Log�����ݵ�ָ��

#### logPrints()

���Log����������������

������

Log* head	����ͷָ��

#### logSearch()

��Log�����а�ʱ������������ĳ������

������

Log* head	����ͷָ��

Time t1,t2	ʱ������Ķ˵㣨������

double money	���׽��

����ֵ��

Log* ָ����������ĵ�һ��Ԫ�ص�ָ��

#### logSearchs()

��Log�����а�ʱ������������ĳЩ����

������

Log* head	����ͷָ��

Time t1,t2	ʱ������Ķ˵㣨������

double money	���׽��

����ֵ��

Log* ָ�����飬��������ָ�����������Ԫ�ص�ָ��

#### logFix()

�޸�Log������ĳ������

������

Log* head	����ͷָ��

## Card��	��Ա��

### ��Ա

char *name	�û�����

char *number	��Ա������

char* phone	�ֻ���

char *password	��Ա������

short level	��Ա���ȼ������ۿ��йأ�

double remaining_sum	�������

double total_charge	�ܳ�ֵ����ȼ��йأ�

Time createTime	����ʱ��

Time validTime	��Чʱ�䣨������ڵ�ʣ��ʱ�䣩

bool isLost	�Ƿ�ʧ���Ѷ�ʧ�Ŀ��޷�ʹ�ã�

Log* rechargeLog	��ֵ��¼

Log* consumeLog	���Ѽ�¼

Card *next	ָ����һ�ڵ��ָ��

### ��Ա����

#### cardCreate()

����Card��̬����

����ֵ��

Card*	����ͷָ��

#### cardDelete()

ɾ��Card������ĳһ�ڵ㣨�˿��Ȳ�����

������

char* number/phone	����/�ֻ���

����ֵ��

Card*	������ͷָ��

#### cardExtend()

��Card��������һ��Card������

����ֵ��

Card*	������ͷָ��

#### cardPrint()

���ָ��Card�����ݵ�����

������

Card* c	ָ��ָ��Card�����ݵ�ָ��

#### cardPrints()

���Card�������������ݵ�����

#### cardSort()

���ΰ��ؼ��ʸ�Card��������

����ֵ��

Card*	������ͷָ��

#### cardSearch()

��Card�����в���ĳ������

������

Card* head	����ͷָ��

char* name/number/phone	�û���/����/�ֻ���

short level	��Ա�ȼ�

Time t1,t2	ʱ������Ķ˵㣨������

����ֵ��

Card*	ָ����������ĵ�һ�����ݵ�ָ��

#### cardSearchs()

��Card�����в���ĳЩ����

������

int* cnt	�������������ݸ���

char* name/number/phone	�û���/����/�ֻ���

short level	��Ա�ȼ�

Time t1,t2	ʱ������Ķ˵㣨������

����ֵ��

Card* ָ�����飬��������ָ�����������Ԫ�ص�ָ��

#### cardFix()

�޸�Card������ĳ������

������

Card* c	ָ����޸�Card�����ݵ�ָ��

����ֵ��

Card*	������ͷָ��

#### cardSignUp()

ע���Ա�����������ѹ�ʧ���Ĳ�����

#### cardLogIn()

��¼��Ա��

������

char* number/phone	����/�ֻ���

char* password	����

����ֵ��

Card*	ָ���¼�ɹ���Card��ָ��

#### cardLogOut()

�˳���Ա����¼

#### cardIdentify()

��֤��Ա���û����

������

Card* c	ʹ���е�Card

����ֵ��

bool	�Ƿ�Ϊע���û�����

#### cardUpdatePhone()

������Ա���󶨵��ֻ�

������

Card* c	ʹ���е�Card

#### cardUpdatePassword()

������Ա������

������

Card* c	ʹ���е�Card

#### cardLost()

��Ա����ʧ

������

char* number/phone	����/�ֻ���

#### cardFind()

�һػ�Ա��

������

char* number	����

#### cardRecharge()

��Ա����ֵ������

������

Card* c	ָ�����������ָ��

double money	��ֵ���

#### cardConsume()

��Ա�����Ѽ����ۿ�

������

Card* c	ָ�����������ָ��

double money	���ѽ��

## Admin��	ϵͳ�˻�

### ��Ա

char* username	�˻���

char* password	����

bool isSuper	�Ƿ�Ϊ��������Ա

Admin* next	ָ����һ�ڵ��ָ��

### ��Ա����

#### adminCreate()

����Admin��̬����

����ֵ��

Admin*	����ͷָ��

#### adminDelete()

ɾ��Admin������ĳһ�ڵ�

����

char* username	�˻���

����ֵ��

Admin*	������ͷָ��

#### adminExtend()

��Admin��������һ��Admin������

����ֵ��

Admin*	������ͷָ��

#### adminSearch()

��Admin�����в���ĳ������

������

char* username	�˻���

����ֵ��

Admin*	ָ��������������ݵ�ָ��

#### adminFix()

�޸�Admin������ĳ������

������

Admin* a	ָ����޸�Admin���ݵ�ָ��

#### adminLogIn()

����Ա��¼

#### SASignUp()

��������Աע��

#### adminSignUp()

����Աע��

#### adminLogOut()

����Ա�˳�

## ϵͳ

int authority	Ȩ�޵ȼ���1������Ա��2����������Ա��

bool isLoggenIn	����Ա�Ƿ��¼

bool isCardLoggedIn	�Ƿ��л�Ա����¼

#### logOut()

�˳�ϵͳ

#### authorize()

��֤Ȩ��

#### backUp()

ϵͳ���ݱ���

#### restore()

ϵͳ���ݻָ�

#### read()

�ļ���ȡ

#### write()

�ļ�д��

#### initialize()

�����ʼ��

#### System()

ϵͳ�˵�
