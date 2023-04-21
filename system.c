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
            printf("\u9519\u8bef\uff1a\u5185\u5b58\u6ea2\u51fa\uff01\n");
            return NULL;
        }
        strcpy(str, _str);
        free(_str);
    }
    str[i-1]='\0';  
    return str;
}
char* getPassword(){
    char *str,*_str;
    int i = 1;
    str = (char*)malloc(sizeof(char)*(i+1));
    while(1){
        char c=getch();
        if(c=='\r'){
            printf("\n");
            break;
        }else if(c=='\b')
            printf("\b \b");
        else{
            str[i-1]=c;
            printf("*"); 
            i++;
            _str = (char*)malloc(strlen(str)+1);
            str[i-1]='\0';
            strcpy(_str, str);
            free(str);
            str = (char*)malloc(sizeof(char)*(i+1));
            if(!str){
                free(_str);
                printf("\u9519\u8bef\uff1a\u5185\u5b58\u6ea2\u51fa\uff01\n");
                return NULL;
            }
            strcpy(str, _str);
            free(_str);
            str[i-1]='\0'; 
        } 
    }
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
void initialize(){
    printf("\u7cfb\u7edf\u521d\u59cb\u5316\u4e2d\uff0c\u8bf7\u7b49\u5f85\u2026\u2026\n");
    admins=(Admin*)calloc(1,LENAdmin);
    cards=(Card*)calloc(1,LENCard);
    Time t={0,0,0,0,0};
    Card c={""};
    t0=t;
    c0=c;
    read_file();
    printf("\u521d\u59cb\u5316\u5b8c\u6210\uff01\n");
    Sleep(1500);
    system("cls");
}
void adminLogIn(){
    printf("\u8bf7\u8f93\u5165\u8d26\u53f7\uff08\u8f93\u5165NULL\u8fd4\u56de\u7cfb\u7edf\uff09\uff1a\n");
    char* u;
    getchar();
    u=getstr();
    if(!strcmp(u,"NULL")){
        system("cls");
        System();
    }
    Admin *a=adminSearch(u);
    if(!a)
        printf("\u7ba1\u7406\u5458\u5e10\u6237\u4e0d\u5b58\u5728\uff01\n");
    else{
        printf("\u8bf7\u8f93\u5165\u5bc6\u7801\uff1a\n");
        char *p;
        p=getPassword();
        if(!strcmp(p,a->password)){
            authority=a->isSuper+1;
            isLoggedIn=1;
            printf("\u767b\u5f55\u6210\u529f\uff01\n");
        }else
            printf("\u5bc6\u7801\u9519\u8bef\uff01\n"); 
    }
    system("pause");
}
void SASignUp(){
    printf("\u8bf7\u8f93\u5165\u5bc6\u94a5\uff1a\n");
    char *s;
    getchar();
    s=getstr();
    if(!strcmp(md5C(s),"79e70d8cf6d56c831544a24ee970d5ed")){
        printf("\u9a8c\u8bc1\u6210\u529f\uff01\n");
        char *u,*p;
        printf("\u8bf7\u8f93\u5165\u8d26\u6237\u540d\uff1a\n");
        u=getstr();
        if(!adminSearch(u)){
            printf("\u8bf7\u8f93\u5165\u5bc6\u7801\uff1a\n");
            p=getPassword();
            Admin t={u,p,1,NULL};
            if(!admins)
                memcpy(admins,&t,sizeof(t));
            else{
                Admin *a=adminExtend();
                memcpy(a,&t,sizeof(t));
            }
            printf("\u6ce8\u518c\u6210\u529f\uff01\n");
            isLoggedIn=1;
        }else
            printf("\u9519\u8bef\uff1a\u8be5\u8d26\u6237\u540d\u5df2\u5b58\u5728\uff01\n");
    }else
        printf("\u5bc6\u94a5\u9519\u8bef\uff01\n");
    system("pause");
}
void System(){
    printf("*****************************\n");
    printf("*****\u4f1a\u5458\u5361\u4ea4\u6613\u7cfb\u7edf v1.0*****\n");
    printf("*****************************\n");
    printf("\u8bf7\u9009\u62e9\u64cd\u4f5c\uff1a\n");
    printf("(0.\u9000\u51fa\u7cfb\u7edf  1.\u6ce8\u518c\u8d85\u7ea7\u7ba1\u7406\u5458\u8d26\u6237  2.\u767b\u5f55\uff08\u8d85\u7ea7\uff09\u7ba1\u7406\u5458\u8d26\u6237)\n");
    int f;
    scanf("%d",&f);
    if(f)
        f==1?SASignUp():adminLogIn();
    else
        logOut();
    system("cls");
      if(!isLoggedIn)
        System();
    else
        menu();
}
void adminLogOut(){
    isLoggedIn=0;isCardLoggedIn=0;
    printf("\u9000\u51fa\u6210\u529f\uff01\n");
    system("pause");
    system("cls");
    System();
}
bool authorize(){
    if(authority!=2){
        printf("\u9519\u8bef\uff1a\u62d2\u7edd\u8bbf\u95ee\uff01\n\u8be5\u64cd\u4f5c\u9700\u8981\u8d85\u7ea7\u7ba1\u7406\u5458\u6743\u9650\u3002\n");
        return 0;
    }
    return 1;
}