#include"card.h"
char* getstr(){
    char *str,*_str;
    int i = 1;
    str = (char*)malloc(sizeof(char)*(i+1));
    while((str[i-1]=getchar())!='\n'){
        i++;
        _str = (char*)malloc(strlen(str)+1);
        str[i-1]='\0';
        strcpy(_str, str);
        free(str);
        str = (char*)malloc(sizeof(char)*(i+1));
        if(!str){
            free(_str);
            printf("No enough memory!");
            return NULL;
        }
        strcpy(str, _str);
        free(_str);
    }
    str[i-1]='\0';  
    return str;
}
bool isTime(int y,int mo,int d,int h,int mi){
    if(y>=1970&&1<=mo&&mo<=12){
        int b=y%4?0:(y%25||y%400==0);
        int ds[]={31,28+b,31,30,31,30,31,31,30,31,30,31};
        return 0<d&&d<=ds[mo]&&0<=h&&h<24&&0<=mi&&mi<60;
    }
    return 0;
}
void read(){
    //todo
}
void initialize(){
    printf("ϵͳ��ʼ���У���ȴ�����\n");
    admins=adminCreate();
    cards=cardCreate();
    read();
    printf("��ʼ����ɣ�\n");
    Sleep(1500);
    system("cls");
}
void adminLogIn(){
    printf("�������˺ţ�����NULL�˳�ϵͳ����\n");
    char* u;
    u=getstr();
    if(!strcmp(u,"NULL"))
        exit(0);
    Admin *a=adminSearch(admins,u);
    if(a==NULL)
        printf("����Ա�ʻ������ڣ�\n");
    else{
        printf("���������룺\n");
        char *p;
        p=getstr();
        if(!strcmp(p,(*a).password)){
            authority=(*a).isSuper+1;
            printf("��¼�ɹ���\n");
            isLoggedIn=1;
        }else
            printf("�������\n"); 
    }
    system("pause");
}
void System(){
    printf("*****************************\n");
    printf("*****��Ա������ϵͳ v1.0*****\n");
    printf("*****************************\n");
    printf("��ѡ�������\n");
    printf("��0.�˳�ϵͳ  1.ע�ᳬ������Ա�˻�  2.��¼������������Ա�˻���\n");
    int f;
    scanf("%d",&f);
    if(f)
        f==1?(admins=SASignUp(admins)):adminLogIn();
    else
        exit(0);
    system("cls");
    if(!isLoggedIn)
        System();
}
bool authorize(){
    if(authority!=2){
        printf("���󣺾ܾ����ʣ�\n�ò�����Ҫ��������ԱȨ�ޡ�\n");
        return 0;
    }
    return 1;
}