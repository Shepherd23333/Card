# Card	��Ա������ϵͳ

## Time��	ʱ��

### ��Ա

int year	��

int month	��

int day	��

int hour	ʱ

int minute	��

## Log��	���׼�¼

### ��Ա

Time time	����ʱ��

float money	���׽��

Log* next	ָ����һ�ڵ��ָ��

### ��Ա����

#### logCreate()	����Log��̬����

����ֵ��

Log* ����ͷָ��

#### logDelete()	��ʱ��ɾ��Log������ĳһ�ڵ�

������

Log* head	����ͷָ��

Time t	ʱ��

����ֵ��

Log* ������ͷָ��

#### logExtend()	��Log��������һ��Log������

������

Log* head	����ͷָ��

����ֵ��

Log* ������ͷָ��

#### logSearch()	��Log�����а�ʱ�����ĳ������

������

Log* head	����ͷָ��

����ֵ��

Log* ָ�����������Ԫ�ص�ָ��

#### logFix()	�޸�Log������ĳ������

������

Log* head	����ͷָ��

## Card��	��Ա��

### ��Ա

char *name	�û�����

char *number	��Ա������

char *password	��Ա������

short level	��Ա���ȼ������ۿ��йأ�

float remaining_sum	�������

float comsumption	�����ѽ���ȼ��йأ�

Time createTime	����ʱ��

Time validTime	��Чʱ�䣨������ڵ�ʣ��ʱ�䣩

bool isLost	�Ƿ�ʧ

Log* rechargeLog	��ֵ��¼

Log* comsumeLog	���Ѽ�¼

Card *next	ָ����һ�ڵ��ָ��

### ��Ա����

#### cardCreate()	����Card��̬����

#### cardDelete()	ɾ��Card������ĳһ�ڵ�

#### cardExtend()	��Card��������һ��Card������

#### cardSort()	��Card��������

#### cardSearch()	��Card�����в���ĳ������

#### cardFix()		�޸�Card������ĳ������

#### cardLost()	��Ա����ʧ

#### cardLogIn()	��¼��Ա��

#### cardRecharge()	��Ա����ֵ������

#### cardComsume()	��Ա�����Ѽ����ۿ�

#### cardFind()	�һػ�Ա������

## ϵͳ

#### logIn()	ϵͳ��¼

#### backUp()	ϵͳ���ݱ���

#### restore()	ϵͳ���ݻָ�

#### read()	�ļ���ȡ

#### write()	�ļ�д��
