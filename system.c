#include"card.h"
void logIn(){
    printf("�������˺ţ�");
    char* u;
    gets(u);
    Admin a=*adminSearch(admins,u);
    printf("���������룺");
    char *p;
    gets(p);
    
}
bool authorize(){
    if(authority!=2){
        printf("���󣺾ܾ����ʡ�\n�ò�����Ҫ��������ԱȨ�ޡ�\n");
        return 0;
    }
    return 1;
}