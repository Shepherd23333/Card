#include"card.h"
void logIn(){
    printf("�������˺ţ�\n");
    char* u;
    gets(u);
    Admin *a=adminSearch(admins,u);
    if(a==NULL){
        printf("����Ա�ʻ������ڣ�\n");
    }else{
        printf("���������룺\n");
        char *p;
        gets(p);
        if(!strcmp(p,(*a).password)){
            authority=(*a).isSuper+1;
            printf("��¼�ɹ���\n");
        }else{
            printf("�������\n");
        }
    }
}
bool authorize(){
    if(authority!=2){
        printf("���󣺾ܾ����ʡ�\n�ò�����Ҫ��������ԱȨ�ޡ�\n");
        return 0;
    }
    return 1;
}