# Card	��Ա������ϵͳ

## Time��	ʱ��

### ��Ա

int year	��

int month	��

int day	��

int hour	ʱ

int minute	��

### ��Ա����

#### setTime()

�޸�ʱ��

������

Time t	���޸ĵ�ʱ��

int y	��

int mo	��

int d	��

int h	ʱ

int mi	��

Log��	���׼�¼

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

#### logSearch()

��Log�����а�ʱ��������ĳ������

������

Log* head	����ͷָ��

int n	����������1��2��

Time t	ʱ��

double	money	���׽��

����ֵ��

Log* ָ�����������Ԫ�ص�ָ��

#### logFix()

�޸�Log������ĳ�����ݣ�����ɾ����

������

Log* head	����ͷָ��

����ֵ��

Card*	������ͷָ��

## Card��	��Ա��

### ��Ա

char *name	�û�����

char *number	��Ա������

char *password	��Ա������

short level	��Ա���ȼ������ۿ��йأ�

double remaining_sum	�������

double comsumption	�����ѽ���ȼ��йأ�

Time createTime	����ʱ��

Time validTime	��Чʱ�䣨������ڵ�ʣ��ʱ�䣩

bool isLost	�Ƿ�ʧ���Ѷ�ʧ�Ŀ��޷�ʹ�ã�

Log* rechargeLog	��ֵ��¼

Log* comsumeLog	���Ѽ�¼

Card *next	ָ����һ�ڵ��ָ��

### ��Ա����

#### cardCreate()

����Card��̬����

����ֵ��

Card*	����ͷָ��

#### cardDelete()

ɾ��Card������ĳһ�ڵ㣨�˿��Ȳ�����

������

Card* head	����ͷָ��

char* name/number	�û������򿨺�

����ֵ��

Card*	������ͷָ��

#### cardExtend()

��Card��������һ��Card������

������

Card* head	����ͷָ��

����ֵ��

Card*	������ͷָ��

#### cardSort()

���ΰ��ؼ��ʸ�Card��������

������

Card* head	����ͷָ��

����ֵ��

Card*	������ͷָ��

#### cardSearch()

��Card�����в���ĳ������

������

Card* head	����ͷָ��

char* name/number	�û������򿨺�

����ֵ��

Card*	ָ��������������ݵ�ָ��

#### cardFix()

�޸�Card������ĳ������

������

Card* head	����ͷָ��

����ֵ��

Card*	������ͷָ��

#### cardLost()

��Ա����ʧ

������

Card* head	����ͷָ��

char* name/number	�û������򿨺�

����ֵ��

Card*	������ͷָ��

#### cardLogIn()

��¼��Ա��

������

char* name/number	�û���/����

char* password	����

����ֵ��

bool	�Ƿ��¼�ɹ�

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

#### cardFind()

�һػ�Ա������

������

Card* head	����ͷָ��

char* name/number	�û���/����

## Admin��	ϵͳ�˻�

### ��Ա

char* username	�˻���

char* password	����

bool isSuper	�Ƿ�Ϊ��������Ա

Admin* next	ָ����һ�ڵ��ָ��

### ��Ա����

#### AdminCreate()

����Admin��̬����

����ֵ��

Admin*	����ͷָ��

#### AdminDelete()

ɾ��Admin������ĳһ�ڵ�

����

Admin* head	����ͷָ��

char* username	�˻���

����ֵ��

Admin*	������ͷָ��

#### AdminExtend()

��Admin��������һ��Admin������

������

Admin* head	����ͷָ��

����ֵ��

Admin*	������ͷָ��

#### adminSearch()

��Admin�����в���ĳ������

������

Admin* head	����ͷָ��

char* username	�˻���

����ֵ��

Admin*	ָ��������������ݵ�ָ��

## ϵͳ

int authority	Ȩ�޵ȼ���1������Ա��2����������Ա��

#### authorize()

��֤Ȩ��

#### logIn()

ϵͳ��¼

#### logOut()

�˳���¼

#### backUp()

ϵͳ���ݱ���

#### restore()

ϵͳ���ݻָ�

#### read()

�ļ���ȡ

#### write()

�ļ�д��
