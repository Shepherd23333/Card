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
void logIn(){
    printf("�������˺ţ�����NULL�˳�ϵͳ����\n");
    char* u;
    u=getstr();
    if(!strcmp(u,"NULL"))
        exit(0);
    Admin *a=adminSearch(admins,u);
    if(a==NULL){
        printf("����Ա�ʻ������ڣ�\n");
    }else{
        printf("���������룺\n");
        char *p;
        p=getstr();
        if(!strcmp(p,(*a).password)){
            authority=(*a).isSuper+1;
            printf("��¼�ɹ���\n");
            isLoggedIn=1;
        }else{
            printf("�������\n");
        }
    }
    system("pause");
}
void read(){
    //todo
}
bool authorize(){
    if(authority!=2){
        printf("���󣺾ܾ����ʡ�\n�ò�����Ҫ��������ԱȨ�ޡ�\n");
        return 0;
    }
    return 1;
}