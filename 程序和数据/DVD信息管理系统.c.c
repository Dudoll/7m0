//16���2����˼ӱ 201600800502  Ҷ�棨201600800529�� ��ٻ��201600800526��
//Ҷ��                                                                       
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#define DVD_len sizeof(DI)
#define MEMBER_len sizeof(MI)


//DVD ��Ϣ�ṹ��
typedef struct DVDInfo
{
	char No[10]; //DVD ���
	char name[20]; //DVD ����
	int state; //DVD ״̬��0 ��ʾ�ѽ����1 ��ʾ�ɳ���
	struct DVDInfo* next;
}DI;

//��Ա��Ϣ�ṹ��
typedef struct MemberInfo
{
	char No[10]; //��Ա���
	char name[20]; //��Ա����
	char password[20]; //��Ա����
	float balance; //�˻����
	DI borrowDVD[3]; //���� DVD ��Ϣ
	int state; //��ʾ���� DVD ����Ŀ��ȡֵΪ 0-3
	struct MemberInfo* next;
}MI;


int DVDs, Members;//ȫ�ֱ��� ��������ʱDVD�ͻ�Ա�Ľڵ���Ŀ
DI*head_DVD;
MI*head_mem;


void cover();//�������
void Member_cover(char[]);//��Ա��¼����
void Admin_cover();
void choose();//ע�ᡢ��Ա��¼or����Ա��½
void log_in_Mem();//�û���½
void log_in_Admin();//����Ա��½
void Register_Mem();//��Աע��
void Register_Admin();//����Աע��
void DVD_hire(char[]);//��Ա����DVD
void DVD_return(char[]);//��Ա�黹DVD
void Payment_fee(char[]);//��Ա�ɷ�
void Account_info(char[]);//��Ա�����Ա��Ϣ
void fun();
DI* creat_DVD();
MI* creat_member();
DI* Delete_DVD(DI*head);
MI* Delete_member(MI* head);
int print_DVD(DI* head);
int print_member(MI*head);
DI*Info_DVD();
MI*Info_member();
void Info_trade(MI*head_mem);
int save_DVD(DI*head);
int save_member(MI*head);
int start_administrator(int a);
MI*load_mem();
DI*load_DVD();
void Member_logout(char No[]);
void log_out();
DI*Insert_DVD(DI*head);
MI*Insert_member(MI*head);



int main()
{
	system("color 8F");
	//system("color F0");
	system("title  Film club management system");
	cover();
	return 0;
}

//�������
void cover()
{
	printf("\n\n\n\t\t");
	printf("*******************************************");
	printf("\n\n\n\t\t \" �� �� �� ԭ \" �� Ӱ �� �� �� �� �� ϵ ͳ");
	printf("\n\n\n\t\t");
	printf("*******************************************");
	printf("\n\n\n");
	printf("\n\t\t\t\t\t16���: ��  ˼  ӱ   201600800502\n");
	printf("\n\t\t\t\t\t16���: ��      ٻ   201600800526\n");
	printf("\n\t\t\t\t\t16���: Ҷ      ��   201600800529\n");
	printf("\n\n \020 ");
	system("pause");
	system("cls");
	choose();
}

//ע�ᡢ��Ա��¼or����Ա��½
void choose()
{
	char i[10], example[] = "E";
	printf("\n\n\n\n**********�� \6 DVD������ϵͳ \6��**********\n\n\n");
	printf(".............��E��������¼\n\n");
	printf(".............��N�����û�ע��\n\n");
	printf(".............��0���˳�ϵͳ\n\n");
	printf("\n**********�������롿**********\n\n");
	scanf("%s", i);


	//ע��
	if (i[0] == 'N'&&i[1] == '\0')
	{
		//��Աע������Աע��
		char a;
		system("cls");
		printf("\n\n\n\n**********�� DVD���ϵͳ -- \16 ע�� \16��**********\n\n\n");
		printf(".............��A������Աע��\n\n");
		printf(".............��M����Աע��\n\n");
		printf(".............��0��������һ��\n\n");
		printf("\n**********�������롿**********\n\n");
		getchar();//���滻�з�
		scanf("%c", &a);
		if (a == 'A')
		{
			system("cls");
			Register_Admin();//��Աע��
		}
		else if (a == 'M')
		{
			system("cls");
			Register_Mem();//����Աע��
		}
		else if (a == '0')
		{
			printf("\n\t. . . ����������һ�㣬");
			system("pause");
			system("cls");
			choose();
		}
		//��������
		else
		{
			printf("\n**********�� \020 �������� \021 ��**********\n\n");
			printf("\n\t. . . ���������룬");
			system("pause");
			system("cls");
			choose();
		}
	}
	//��½
	else if (!strcmp(i, example))
	{
		//ѡ���Ա��¼�����Ա��½
		char a;
		system("cls");
		printf("\n\n\n\n**********��DVD���ϵͳ-- \4 ��½ \4��**********\n\n\n");
		printf(".............��A������Ա��½\n\n");
		printf(".............��M����Ա��½\n\n");
		printf(".............��0��������һ��\n\n");
		printf("\n**********�������롿**********\n\n");
		getchar();//���滻�з�
		scanf("%c", &a);
		if (a == 'A')
		{
			system("cls");
			log_in_Admin();//����Ա��½
		}
		else if (a == 'M')
		{
			system("cls");
			log_in_Mem();//��Ա��¼
		}
		else if (a == '0')
		{
			printf("\n\t. . . ����������һ�㣬");
			system("pause");
			system("cls");
			choose();
		}
		//��������
		else
		{
			printf("\n**********�� \020 �������� \021 ��**********\n\n");
			printf("\n\t. . . ���������룬");
			system("pause");
			system("cls");
			choose();
		}
	}
	//�˳�
	else if (i[0] == '0'&&i[1] == '\0')
		log_out();
	//��������
	else
	{
		printf("\n**********�� \020 �������� \021 ��**********\n\n");
		printf("\n\t. . . ���������룬");
		system("pause");
		system("cls");
		choose();
	}
}

//�˳�ϵͳ
void log_out()
{
	system("cls");
	printf("\n*************�������˳�ϵͳ���밴�����������**************\n\n\n");
	system("pause");
	system("cls");
	printf("\n\t\t*************��Goodbye! \2 ��**************\n\n\n");
	exit(0);
}

//��Աע��
void Register_Mem()
{
	int r = 0, n = 0;
	char a;
	MI*head, *p1, *p2, MM;
	FILE *fp = NULL;
	system("cls");

	char No[10], name[10], password[20], repass[20];
	printf("\n\t\t");
	printf("****************************************");
	printf("\n\n\t\t\t\t\16 ��Աע�� \16\n\n");
	printf("\t\t");
	printf("****************************************");
	printf("\n\n\n\n\t\t�����������û���ţ���1-10���ַ���������ɣ���");
	scanf("%s", No);
	printf("\n\n");
	printf("\t\t������������������1-10�ַ���ɣ���");
	scanf("%s", name);
	printf("\n\n");
	printf("\t\t �������������루��1-20λ���ֻ��ַ���ɣ���");
	scanf("%s", password);
	printf("\n\n");
	printf("\t\t\t ��ȷ���������룺");
	scanf("%s", repass);
	printf("\n\n");

	if (strcmp(password, repass))
	{
		printf("\n**********�� \023 ע��ʧ�� \023 ��**********\n\n");
		printf("\n\t. . . �����������벻һ�£�������ע�ᣬ");
		system("pause");
		system("cls");
		Register_Mem(); //����ע��
	}
	//����Ϊ�����Ա��Ϣ������
	fp = fopen("Member", "rb");//���ļ�
	if (fp == NULL) {
		head = (MI*)malloc(MEMBER_len);
		p1 = (MI*)malloc(MEMBER_len);
		head->next = p1;
		strcpy(p1->No, No);
		strcpy(p1->name, name);
		strcpy(p1->password, password);
		p1->balance = 0;
		p1->state = 0;
		memset(p1->borrowDVD, 0, sizeof(p1->borrowDVD));
		p1->next = NULL;
	}//����ļ��л�Ա��ϢΪ��
	else {
		p1 = p2 = (MI*)malloc(MEMBER_len);
		r = fread(&MM, MEMBER_len, 1, fp);
		int w = MEMBER_len;
		if (r < 1) {
			if (ferror(fp))
				printf("error");
			return;
		}
		memset(p1, 0, MEMBER_len);
		memcpy(p1, &MM, MEMBER_len);//��ȡ�ļ��е�һ������
		head = p1;
		while (!feof(fp)) {//ѭ����ȡ
			n++;
			p2 = p1;
			r = fread(&MM, MEMBER_len, 1, fp);
			if (r < 1) break;
			p1 = (MI*)malloc(MEMBER_len);
			memset(p1, 0, MEMBER_len);
			memcpy(p1, &MM, MEMBER_len);
			p2->next = p1;
		}
		p2->next = p1;
		p1->next = NULL;
		p2 = p1;
		p1 = (MI*)malloc(MEMBER_len);
		p2->next = p1;
		strcpy(p1->No, No);
		strcpy(p1->name, name);
		strcpy(p1->password, password);
		p1->balance = 0;
		p1->state = 0;
		memset(p1->borrowDVD, 0, sizeof(p1->borrowDVD));
		p1->next = NULL;
		fclose(fp);
	}
	//�ļ��л�Ա��Ϣ��Ϊ��
	p1 = head;
	fp = fopen("Member", "wb");
	while (p1 != NULL)
	{
		if (fwrite(p1, MEMBER_len, 1, fp) != 1)
		{
			printf("error\n");
			return;
		}
		p1 = p1->next;
	}
	fclose(fp);
	//fp = fopen("Member", "wb+");
	//for (p1 = head; p1 != NULL; p1 = p1->next)
	printf("\n**********�� \16 ��Ա��Ϣע��ɹ� \16 ��**********\n\n");
	printf("\n\t. . . �����µ�½��");
	system("pause");
	system("cls");
	log_in_Mem();

}

//����Աע��
void Register_Admin()
{
	int r = 0, n = 0;
	char a;
	MI*head, *p1, *p2, MM;
	FILE *fp = NULL;
	system("cls");

	char No[10], name[10], password[20], repass[20];
	printf("\n\t\t");
	printf("****************************************");
	printf("\n\n\t\t\t\t\16 ����Աע�� \16\n\n");
	printf("\t\t");
	printf("****************************************");
	printf("\n\n\n\n\t\t���������Ĺ���Ա��ţ���1-10���ַ���������ɣ���");
	scanf("%s", No);
	printf("\n\n");
	printf("\t\t������������������1-10�ַ���ɣ���");
	scanf("%s", name);
	printf("\n\n");
	printf("\t\t �������������루��1-20λ���ֻ��ַ���ɣ���");
	scanf("%s", password);
	printf("\n\n");
	printf("\t\t\t ��ȷ���������룺");
	scanf("%s", repass);
	printf("\n\n");

	if (strcmp(password, repass))
	{
		printf("\n**********�� \023 ע��ʧ�� \023 ��**********\n\n");
		printf("\n\t. . . �����������벻һ�£�������ע�ᣬ");
		system("pause");
		getchar();
		system("cls");
		Register_Admin(); //����ע��
	}
	//����Ϊ�����Ա��Ϣ������
	fp = fopen("Admin", "rb");//���ļ�
	if (fp == NULL) {
		head = (MI*)malloc(MEMBER_len);
		p1 = (MI*)malloc(MEMBER_len);
		head->next = p1;
		strcpy(p1->No, No);
		strcpy(p1->name, name);
		strcpy(p1->password, password);
		p1->balance = 0;
		p1->state = 0;
		memset(p1->borrowDVD, 0, sizeof(p1->borrowDVD));
		p1->next = NULL;
	}//����ļ��л�Ա��ϢΪ��
	else {
		p1 = p2 = (MI*)malloc(MEMBER_len);
		r = fread(&MM, MEMBER_len, 1, fp);
		int w = MEMBER_len;
		if (r < 1) {
			if (ferror(fp))
				printf("error");
			return;
		}
		memset(p1, 0, MEMBER_len);
		memcpy(p1, &MM, MEMBER_len);//��ȡ�ļ��е�һ������
		head = p1;
		while (!feof(fp)) {//ѭ����ȡ
			n++;
			p2 = p1;
			r = fread(&MM, MEMBER_len, 1, fp);
			if (r < 1) break;
			p1 = (MI*)malloc(MEMBER_len);
			memset(p1, 0, MEMBER_len);
			memcpy(p1, &MM, MEMBER_len);
			p2->next = p1;
		}
		p2->next = p1;
		p1->next = NULL;
		p2 = p1;
		p1 = (MI*)malloc(MEMBER_len);
		p2->next = p1;
		strcpy(p1->No, No);
		strcpy(p1->name, name);
		strcpy(p1->password, password);
		p1->balance = 0;
		p1->state = 0;
		memset(p1->borrowDVD, 0, sizeof(p1->borrowDVD));
		p1->next = NULL;
		fclose(fp);
	}
	//�ļ��й���Ա��Ϣ��Ϊ��
	p1 = head;
	fp = fopen("Admin", "wb");
	while (p1 != NULL)
	{
		if (fwrite(p1, MEMBER_len, 1, fp) != 1)
		{
			printf("error\n");
			return;
		}
		p1 = p1->next;
	}
	fclose(fp);
	printf("\n**********�� \16 ����Ա��Ϣע��ɹ� \16 ��**********\n\n");
	printf("\n\t. . . �����µ�½��");
	system("pause");
	system("cls");
	log_in_Admin();
}

//��Ա��½
void log_in_Mem()
{
	int a;
	FILE* fp;
	char No[10], password[20];
	static int flag1 = 3;//��¼����
	int n = 0;

	if ((fp = fopen("Member", "r")) == NULL)
	{
		printf("\n**********�� \020 ��Ա��ϢΪ�� \021 ��**********\n\n");
		printf("\n\t. . . ��ע����½������������ҳ�棬");
		system("pause");
		system("cls");
		choose();
	}

	//��Ա��¼����
	while (flag1 > 0 && n == 0) //flag=3
	{
		printf("\n\t\t");
		printf("****************************************");
		printf("\n\n\t\t\t\t\4 ��Ա��½ \4\n\n");
		printf("\t\t");
		printf("****************************************");
		printf("\n\n\n\n\t\t\t\t��Ա��ţ�");
		scanf("%s", No);
		printf("\n\n");
		printf("\t\t\t\t ���룺");
		scanf("%s", password);
		printf("\n\n");


		//��ȡ�ļ� ��֤�û������Ƿ���ȷ
		MI* p;
		p = (MI*)malloc(MEMBER_len);
		while (!feof(fp)) //����Ƿ��ȡ��ĩβ
		{
			n = 1;
			a = fread(p, MEMBER_len, 1, fp);
			if (!strcmp(p->No, No))
			{
				n = 0;
				if (!strcmp(p->password, password))
				{
					//������ȷ
					fclose(fp);
					printf("\n**********����½�ɹ���**********\n\n");
					printf("\n\t. . . \3 �𾴵� %s \3 ����ӭ��½��", No);
					system("pause");
					system("cls");
					getchar();
					//������ͨ��Ա��غ���
					Member_cover(No);
				}
				else if (flag1 > 1)
				{
					fclose(fp);
					flag1--;
					printf("\n**********�� \023 ������� ��**********\n\n");
					printf("\n\t. . . �û�����ȷ��������%d�λ��ᣬ���µ�½", flag1);
					system("pause");
					system("cls");
					log_in_Mem();
				}
				else
				{
					fclose(fp);
					flag1--;
					printf("\n**********�� \023 ������� ��**********\n\n");
					printf("\n\t. . . ����������࣬�����˳�ϵͳ��");
					system("pause");
					log_out();
				}
			}
		}
	}
	if (flag1 <= 1)
	{
		fclose(fp);
		printf("\n**********�� \023 �û��������ڡ�**********\n\n");
		printf("\n\t. . . ����������࣬�����˳�ϵͳ��");
		system("pause");
		log_out();
	}
	fclose(fp);
	flag1--;
	printf("\n**********�� \023 �û��������ڡ�**********\n\n");
	printf("\n\t. . . ������%d�λ��ᣬ��������", flag1);
	system("pause");
	system("cls");
	log_in_Mem();
}

//����Ա��½
void log_in_Admin()
{
	int a;
	FILE* fp;
	char No[10], password[20];
	static int flag = 3;//��¼����
	int n = 0;

	if ((fp = fopen("Admin", "r")) == NULL)
	{
		printf("\n**********�� \020 ����Ա��ϢΪ�� \021 ��**********\n\n");
		printf("\n\t. . . ��ע����½������������ҳ�棬");
		system("pause");
		system("cls");
		choose();
	}

	//����Ա��¼����
	while (flag > 0 && n == 0) //flag=3
	{
		printf("\n\t\t");
		printf("****************************************");
		printf("\n\n\t\t\t\t\4 ����Ա��½ \4\n\n");
		printf("\t\t");
		printf("****************************************");
		printf("\n\n\n\n\t\t\t\t����Ա��ţ�");
		scanf("%s", No);
		printf("\n\n");
		printf("\t\t\t\t ���룺");
		scanf("%s", password);
		printf("\n\n");


		//��ȡ�ļ� ��֤�û������Ƿ���ȷ
		MI* p;
		p = (MI*)malloc(MEMBER_len);
		while (!feof(fp)) //����Ƿ��ȡ��ĩβ
		{
			n = 1;
			a = fread(p, MEMBER_len, 1, fp);
			if (!strcmp(p->No, No))
			{
				n = 0;
				if (!strcmp(p->password, password))
				{
					//������ȷ
					fclose(fp);
					printf("\n**********����½�ɹ���**********\n\n");
					printf("\n\t. . . \3 �𾴵� %s \3 ����ӭ��½��", No);
					system("pause");
					system("cls");
					getchar();
					//�������Ա��غ���
					Admin_cover();
				}
				else if (flag > 1)
				{
					fclose(fp);
					flag--;
					printf("\n**********�� \023 ������� ��**********\n\n");
					printf("\n\t. . . �û�����ȷ��������%d�λ��ᣬ���µ�½", flag);
					system("pause");
					system("cls");
					log_in_Admin();
				}
				else
				{
					fclose(fp);
					flag--;
					printf("\n**********�� \023 ������� ��**********\n\n");
					printf("\n\t. . . ����������࣬�����˳�ϵͳ��");
					system("pause");
					log_out();
				}
			}
		}
		if (flag <= 1)
		{
			fclose(fp);
			printf("\n**********�� \023 �û��������ڡ�**********\n\n");
			printf("\n\t. . . ����������࣬�����˳�ϵͳ��");
			system("pause");
			log_out();
		}
		fclose(fp);
		flag--;
		printf("\n**********�� \023 �û��������ڡ�**********\n\n");
		printf("\n\t. . . ������%d�λ��ᣬ��������", flag);
		system("pause");
		system("cls");
		log_in_Admin();
	}

}


//��Ա���� 17
void Member_cover(char No[])
{
	system("cls");
	static int flag = 0;
	char c;
	printf("\n\n**********��DVD������ϵͳ  \017 ��Ա�˵� \017 ��**********\n\n\n");
	printf(".............��D���˻���Ϣ���\n\n");
	printf(".............��H��DVD���\n\n");
	printf(".............��R��DVD�黹\n\n");
	printf(".............��P�����ɷ���\n\n");
	printf(".............��Q���л��˻�\n\n");
	printf(".............��0���˳�ϵͳ\n\n");
	printf("\n**********�������롿**********\n\n");
	//if (flag == 0)
	//{
	//	scanf("%c", &c);
	//	flag++;
	//}
	//else
	//{
	//	//getchar();
	//	//getchar();
	scanf("%c", &c);
	//}
	switch (c)
	{
	case'H':DVD_hire(No); break;
	case'R':DVD_return(No); break;
	case'P':Payment_fee(No); break;
	case'D':Account_info(No); break;
	case'Q': Member_logout(No); break;
	case'0':log_out();
	default:
		printf("\n**********�� \020 ������� \021 ��**********\n\n");
		printf("\n\t. . . �������������������룬");
		system("pause");
		getchar();
		Member_cover(No);
		break;
	}
}

//��Ϣ��� - D
void Account_info(char No[])
{
	system("cls");
	printf("\n\n\t\t****************************************");
	printf("\n\n\t\t\t    \017 ��Ա��Ϣ��� \017\n\n");
	printf("\t\t****************************************\n\n");

	FILE* fp;
	if ((fp = fopen("Member", "rb")) == NULL)
	{
		printf("\n**********�� \020 �ļ����� \021 ��**********\n\n");
		printf("\n\t. . . �ļ��򿪳���\021\021 ����");
		system("pause");
		Member_cover(No);
	}
	MI* p;
	p = (MI*)malloc(MEMBER_len);
	while (!feof(fp)) //����Ƿ��ȡ��ĩβ
	{
		fread(p, MEMBER_len, 1, fp);
		if (strcmp(No, p->No) == 0)
		{
			printf("\t\t.............\4 ��  �ţ�\t\t%s \n\n", p->No);
			printf("\t\t.............\4 ��  ����\t\t%s \n\n", p->name);
			printf("\t\t.............\4 ��  �\t\t%.2fԪ \n\n", p->balance);
			printf("\t\t.............\4 ���DVD��Ŀ��\t%d \n\n", p->state);
			if (p->state != 0)
			{
				printf("\t\t.............\4 ���DVD���&���֣�");
				for (int i = 0; i < p->state; i++)
				{
					if (i == 0)
						printf("%-3s  <%s>\n", p->borrowDVD[i].No, p->borrowDVD[i].name);
					else
						printf("\t\t\t\t\t\t %-3s  <%s>\n", p->borrowDVD[i].No, p->borrowDVD[i].name);

				}
			}
			printf("\n\n\t\t. . . ������ҳ��");
			system("pause");
			getchar();
			system("cls");
			Member_cover(No);
		}
		//�����Ա������Ϣ��
	}
	fclose(fp);
}

//����DVD - H
void DVD_hire(char No[])
{
	system("cls");
	printf("\n\n**********��DVD������ϵͳ  \017 ����DVD \017 ��**********\n\n");
	int i = 1;
	FILE* fp;
	MI* head_mem = load_mem();
	MI* p = head_mem;
	DI*head_DVD = load_DVD();
	DI*p3 = head_DVD;
	char No_DVD[10], c;


	if ((fp = fopen("Member", "rb")) == NULL)
	{
		fclose(fp);
		printf("\n**********�� \020 �ļ����� \021 ��**********\n\n");
		printf("\n\t. . . �ļ��򿪳���\021\021 ����");
		DVD_hire(No);
	}
	do {
		p = p->next;
	} while (strcmp(p->No, No));
	printf("\n\n");
	printf(".............��S�����DVD\n\n");
	printf(".............��Q��������һ��\n\n");
	printf("\n**********�������롿**********\n\n");
	getchar();
	scanf("%c", &c);
	switch (c)
	{
	case'S':
	{
		system("cls");
		if (head_DVD != NULL)
			print_DVD(head_DVD);
		else
		{
			fclose(fp);
			printf("\n**********�� \020 DVD��ϢΪ�� \021 ��**********\n\n");
			printf("\n\t. . . \021\021 ������ҳ��");
			system("pause");
			system("cls");
			Member_cover(No);
		}
		break;
	}
	case'Q':
		fclose(fp);
		printf("\n\t. . . \021\021 ������ҳ��");
		system("pause");
		getchar();
		system("cls");
		Member_cover(No);
		break;
	default:
		fclose(fp);
		printf("1\n");
	}
	if (p->balance < 3)
	{
		fclose(fp);
		printf("\n**********�� \023 ���� \023 ��**********\n\n");
		printf("\n\t. . . ����3Ԫ�����ֵ������裡�������˵�");
		system("pause");
		getchar();
		system("cls");
		Member_cover(No);
		return;
	}
	printf("\n   \020 �����˻����Ϊ��%.2f \021\n", p->balance);
	if (p->balance > 0 && p->state < 3)
	{
		printf("\n**********�� \017 ������ \017 ��**********\n\n");
		printf("������������DVD��ţ�ÿ������Զ��۷�3.0Ԫ������#ȡ����裺");
		scanf("%s", No_DVD);
		if (!strcmp("#", No_DVD))
		{
			printf("\n\t. . . �������˵�");
			system("pause");
			//getchar();
			system("cls");
			fclose(fp);
			DVD_hire(No);
		}
		do {
			p3 = p3->next;
		} while (strcmp(p3->No, No_DVD));
		if (strcmp(p3->No, No_DVD))
		{
			printf("\n**********�� \020 ���ʧ�� \021 ��**********\n");
			printf("\n\t\t. . . �޴�DVD , �������");
			fclose(fp);
			system("pause");
			getchar();
			system("cls");
			DVD_hire(No);
		}
		if (p3->state == 0)
		{
			printf("\n**********�� \020 ���ʧ�� \021 ��**********\n");
			printf("\n\t\t. . . ��DVD�ѽ�� , �������DVD");
			fclose(fp);
			system("pause");
			getchar();
			system("cls");
			Member_cover(No);
			return;
		}
		p3->state = 0;
		//�޸�DVD��״̬
		p->state++;
		int m = p->state - 1;
		strcpy(p->borrowDVD[m].No, No_DVD);
		strcpy(p->borrowDVD[m].name, p3->name);
		p->balance -= 3;
		save_DVD(head_DVD);
		save_member(head_mem);
		printf("\n**********�� \020 ���ɹ� \021 ��**********\n\n");
		printf(" \020 �����˻����Ϊ��%.2f \021  �������˵�", p->balance);
		system("pause");
		getchar();
		system("cls");
		fclose(fp);
		Member_cover(No);
		//�޸Ļ�Ա�ṹ�������DVD����Ϣ
	}
	//�û�
	else
	{
		while (i--)
		{
			if (p->balance < 3 && p->state < 3)
			{
				fclose(fp);
				printf("\n**********�� \020 ���ʧ�� \021 ��**********\n");
				printf("\n\t\t. . . ����˻�����3Ԫ����ɷѺ�����裬�������˵�");
				system("pause");
				getchar();
				system("cls");
				Member_cover(No);
			}
			else if (p->balance > 0 && p->state == 3)
			{
				fclose(fp);
				printf("\n**********�� \020 ���ʧ�� \021 ��**********\n");
				printf("\n\t\t. . .���DVD��Ŀ�Ѵ����ޣ���黹DVD������� ���������˵�");
				system("pause");
				getchar();
				system("cls");
				Member_cover(No);
			}
			else
			{
				fclose(fp);
				printf("\n**********�� \020 ���ʧ�� \021 ��**********\n");
				printf("\n\t\t. . .���DVD��Ŀ�Ѵ�����������3Ԫ����黹DVD���ɷѺ����� ���������˵�");
				system("pause");
				getchar();
				system("cls");
				Member_cover(No);
			}
		}
	}
}

//�黹DVD - R
void DVD_return(char No[])
{
	int i, j;//����ѭ��
	int flag = 0;//�Ƿ�����ⲿDVD
	system("cls");
	printf("\n\n**********��DVD������ϵͳ  \017 �黹DVD \017 ��**********\n\n");

	char No_DVD[10];
	head_mem = load_mem();
	head_DVD = load_DVD();

	MI*p1 = head_mem;
	DI*p3 = head_DVD;
	printf("\n**********�������롿**********\n\n");
	printf("\020 ��������Ҫ�黹��DVD��ţ�");
	scanf("%s", No_DVD);
	printf("\n\n");
	do {
		p3 = p3->next;
	} while (strcmp(p3->No, No_DVD));
	if (strcmp(p3->No, No_DVD) != 0)
	{
		printf("\n**********�� \020 �黹ʧ�� \021 ��**********\n");
		printf("\n\t. . .����û�����DVD�t(������)�q  ���������˵�");
		system("pause");
		getchar();
		system("cls");
		Member_cover(No);
		return;
	}
	p3->state = 1;
	do {
		p1 = p1->next;
	} while (strcmp(p1->No, No));
	for (i = 0; i<3; i++) {
		if (!strcmp(p1->borrowDVD[i].No, No_DVD))
		{
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		printf("\n**********�� \020 �黹ʧ�� \021 ��**********\n");
		printf("\n\t\t. . .������û�н����DVD�t(������)�q  �������黹");
		system("pause");
		getchar();
		system("cls");
		DVD_return(No);
	}
	else {
		p1->state--;
		for (j = i + 1; j<3; j++)
		{
			p1->borrowDVD[j - 1] = p1->borrowDVD[j];
		}
		save_DVD(head_DVD);
		save_member(head_mem);
		printf("\n**********�� \017 �黹�ɹ� \017 ��**********\n");
		printf("\n\t\t. . .�̷������˵�");
		system("pause");
		getchar();
		system("cls");
	}
	Member_cover(No);
}

//��Ա�ɷ� - P
void Payment_fee(char No[])
{
	system("cls");
	printf("\n\n**********��DVD������ϵͳ  \017 ��Ա�ɷ� \017 ��**********\n\n");


	float fee;
	head_mem = load_mem();
	MI*p1 = head_mem;
	do {
		p1 = p1->next;
	} while (strcmp(p1->No, No));
	printf("\n   \020 �����˻����Ϊ��%.2fԪ \021\n", p1->balance);
	printf("\n\n  . . .������ɷѽ�");
	scanf("%f", &fee);
	p1->balance += fee;
	printf("\n\n**********�� \017 �ɷѳɹ� \017 ��**********\n");
	printf("\n����ǰ�˻����Ϊ:%.2fԪ\n\n", p1->balance);
	//���浽�ļ�
	save_member(head_mem);
	printf("\n\t\t. . . �������˵�");
	system("pause");
	getchar();
	system("cls");
	Member_cover(No);
}

//��Աע�� - Q
void Member_logout(char No[])
{
	char a, b;
	system("cls");
	printf("\n**********�� \14 �л��˺� \14 ��**********\n\n\n");
	printf("��ǰ�����˺ű��Ϊ��%s ���Ƿ�ע����(Y / N)\n\n", No);
	printf("\n**********�������롿**********\n\n");
	b = getchar();
	scanf("%c", &a);
	switch (a)
	{
	case'Y':
		printf("\n\t. . . ����ע����\020\020 ��½");
		system("pause");
		system("cls");
		log_in_Mem();
		break;
	case'N':
		printf("\n\t. . . ȡ���˳���\021\021 ���ز˵�");
		system("pause");
		getchar();
		system("cls");
		Member_cover(No);
		break;
	default:
		printf("\n**********�� \020 �������� \021 ��**********\n\n");
		printf("\n\t. . . �������룬");
		system("pause");
		Member_logout(No);
		break;
	}
	return;
}


//------------------------------------------------------------------------

//����Ա����
void Admin_cover()
{
	char a;
	printf("\n\n\n\n**********��DVD������ϵͳ \5 ����Ա�˵� \5 ��**********\n\n\n");
	printf(".............��1��:DVD��Ϣ\n\n");
	printf(".............��2��:��Ա��Ϣ\n\n");
	printf(".............��3��:������Ϣ\n\n");
	printf(".............��4��:�˳�\n\n");
	printf("\n*************�������롿**************\n\n\n");
	//getchar();
	a = getchar();
	start_administrator(a);
}

//����
void fun() {
	system("cls");
	//getchar();
	printf("\n\n\n\n**********��DVD������ϵͳ��**********\n\n\n");
	printf(".............��1��:DVD��Ϣ\n\n");
	printf(".............��2��:��Ա��Ϣ\n\n");
	printf(".............��3��:������Ϣ\n\n");
	printf(".............��4��:�˳�\n\n");
	printf("\n*************�������롿**************\n\n\n");
	//getchar();
	int m = getchar();
	start_administrator(m);
}

//ѡ��
int start_administrator(int a) {
	switch (a)
	{
	case '1':
		head_DVD = Info_DVD();
		//fun(); 
		break;
	case '2':
		head_mem = Info_member();
		//fun(); 
		break;
	case '3':
		Info_trade(head_mem);
		//fun(); 
		break;
	case '4':
		log_out();
		break;
	default:
		printf("\n**********�� \020 ������� \021 ��**********\n\n");
		printf("\n\t. . . �������������������룬");
		system("pause");
		getchar();
		system("cls");
		fun();
	}
}

//1-DVD��Ϣ
DI*Info_DVD() {
	int r = 0, n = 0;
	char a;
	DI*head, *p1, *p2, DV;
	FILE *fp = NULL;
	system("cls");
	//printf("**********��DVD��Ϣ���سɹ�����**********\n\n");
	fp = fopen("DVD", "rb+");//���ļ�
	if (fp == NULL) {
		printf("\n**********�� \020 �ļ����� \021 ��**********\n\n");
		printf("\n\t. . . �ļ�Ϊ�գ�\021\021 �������˵�");
		system("pause");
		fun();
	}
	p1 = p2 = (DI*)malloc(DVD_len);
	r = fread(&DV, DVD_len, 1, fp);
	//int w = Delete_DVD;
	if (r < 1) { return; }
	memset(p1, 0, DVD_len);
	memcpy(p1, &DV, DVD_len);//��ȡ�ļ��е�һ������
	head = p1;
	while (!feof(fp)) {//ѭ����ȡ
		n++;
		p2 = p1;
		r = fread(&DV, DVD_len, 1, fp);
		if (r < 1) break;
		p1 = (DI*)malloc(DVD_len);
		memset(p1, 0, DVD_len);
		memcpy(p1, &DV, DVD_len);
		p2->next = p1;
	}
	p2->next = p1;
	p1->next = NULL;
	print_DVD(head);//��ӡ��ȡ�������е���Ϣ
					//����Ϊ����DVD��Ϣ
	printf("\n**********�������롿**********\n\n");
	printf("........��A��: ���DVD��Ϣ\n\n");
	printf("........��B��: ɾ��DVD��Ϣ\n\n");
	printf("........��C��: ������һ��\n");
	getchar();
	a = getchar();
	if (a == 'A')
	{
		system("cls");
		head = Insert_DVD(head);
		return head;
	}
	else if (a == 'B')
	{
		system("cls");
		head = Delete_DVD(head);
		return head;
	}
	else if (a == 'C') {
		printf("\n\t. . . �������˵�");
		system("pause");
		getchar();
		system("cls");
		fun();
		return head;
	}
	else
	{
		printf("\n**********�� \020 ������� \021 ��**********\n\n");
		printf("\n\t. . . �������������������룬");
		system("pause");
		//getchar();
		Info_DVD();
	}
	//����Ϊ�޸�DVD��Ϣ
}

//2-��Ա��Ϣ
MI*Info_member() {
	int r = 0, n = 0;
	char a;
	MI*head, *p1, *p2, MM;
	FILE *fp = NULL;
	system("cls");
	fp = fopen("Member", "rb");//���ļ�
	if (fp == NULL) {
		printf("\n**********�� \020 ��Ա�ļ����� \021 ��**********\n\n");
		printf("\n\t. . . �ļ�Ϊ�գ�\021\021 �������˵�");
		system("pause");
		fun();
	}
	p1 = p2 = (MI*)malloc(MEMBER_len);
	r = fread(&MM, MEMBER_len, 1, fp);
	int w = MEMBER_len;
	if (r < 1) {
		if (ferror(fp))
		{
			printf("\n**********�� \020 ��ȡ�ļ����� \021 ��**********\n\n");
			printf("\n\t\t. . . \021\021 �������˵�");
			system("pause");
			fun();
		}
		return;
	}
	memset(p1, 0, MEMBER_len);
	memcpy(p1, &MM, MEMBER_len);//��ȡ�ļ��е�һ������
	head = p1;
	while (!feof(fp)) {//ѭ����ȡ
		n++;
		p2 = p1;
		r = fread(&MM, MEMBER_len, 1, fp);
		if (r < 1) break;
		p1 = (MI*)malloc(MEMBER_len);
		memset(p1, 0, MEMBER_len);
		memcpy(p1, &MM, MEMBER_len);
		p2->next = p1;
	}
	p2->next = p1;
	p1->next = NULL;
	print_member(head);//��ӡ��ȡ�������е���Ϣ
					   //printf("**********����Ա��Ϣ���سɹ�����**********\n\n");
					   //����Ϊ���ػ�Ա��Ϣ
	printf("\n**********�������롿**********\n\n");
	printf("........��A��: ��ӻ�Ա��Ϣ\n\n");
	printf("........��B��: ɾ����Ա��Ϣ\n\n");
	printf("........��C��: ������һ��\n");
	getchar();
	a = getchar();
	system("cls");
	if (a == 'A')
	{
		head = Insert_member(head);
		return head;
	}
	else if (a == 'B')
	{
		head = Delete_member(head);
		return head;
	}
	else if (a == 'C') {
		printf("\n\t. . . �������˵�");
		system("pause");
		getchar();
		system("cls");
		fun();
		return head;
	}
	else
	{
		printf("\n**********�� \020 ������� \021 ��**********\n\n");
		printf("\n\t. . . �������������������룬");
		system("pause");
		getchar();
		Info_member();
	}
	//����Ϊ�޸Ļ�Ա��Ϣ
}

//3-������Ϣ
void Info_trade(MI*head_mem) {
	MI*p1, p2;
	head_mem = load_mem();
	p1 = head_mem->next;
	printf("\n\n\n\n**********��DVD������ϵͳ \05 ������Ϣ \05��**********\n\n\n");
	printf("  ����Ա������\t  ������DVD��Ŀ��\n\n");
	do {
		//if (p1->state != 0)
		printf("%15s %15d\n", p1->name, p1->state);
		p1 = p1->next;
	} while (p1 != NULL);
	printf("\n\t\t. . . ������Ϣ���ϣ�\021\021 �������˵�");
	system("pause");
	getchar();
	system("cls");
	fun();
}

//�����Ա��Ϣ
MI*Insert_member(MI*head) {
	MI *p1, *p2 = head->next;
	int n;
	p1 = (MI*)malloc(MEMBER_len);
	while (p2->next != NULL)
		p2 = p2->next;
	p2->next = p1;
	system("cls");
	printf("\n\n\n\n**********�� \5 ��ӻ�Ա��Ϣ \5 ��**********\n\n\n");
	printf("\n**********�������롿**********\n\n");
	printf(" \020 ������Ҫ��ӵĻ�Ա������");
	scanf("%d", &n);
	printf("\n\n \020 ��������ӵĻ�Ա��Ϣ��");
	printf("��\023 �����ա���Ա��š�����Ա����������Ա���롱��ʽ���룺��\n\n");
	scanf("%s%s%s", &p1->No, &p1->name, &p1->password);
	p1->state = 0;
	p1->balance = 0;//�˻�����ʼ��Ϊ0
	memset(p1->borrowDVD, 0, sizeof(p1->borrowDVD));//���� DVD ��Ϣ��ʼ��Ϊ��
	while (--n)
	{
		p2 = p1;
		p1 = (MI*)malloc(MEMBER_len);
		scanf("%s%s%s", &p1->No, &p1->name, &p1->password);
		p1->balance = 0;//�˻�����ʼ��Ϊ0
		p1->state = 0;
		memset(p1->borrowDVD, 0, sizeof(p1->borrowDVD));//���� DVD ��Ϣ��ʼ��Ϊ��
		p2->next = p1;
	}
	p1->next = NULL;
	printf("\n**********�� \017 ��ӳɹ� \017 ��**********\n");
	print_member(head);
	save_member(head);
	printf("\n\n\t\t. . .�̷������˵�");
	system("pause");
	getchar();
	system("cls");
	fun();
	return head;
}

//ɾ����Ա��Ϣ
MI*Delete_member(MI*head) {
	MI*p1, *p2;
	char key[20];
	if (head != NULL) {
		printf("\n**********�� �����Ա��Ϣ \14 ɾ�� \14 ��**********\n\n\n");
		printf("\n*************�������롿**************\n\n\n");
		printf(" \020 ������Ҫɾ���Ļ�Ա��ţ�");
		scanf("%s", key);
		p1 = head;
		p2 = p1->next;
		while (p2) {
			if (strcmp(p2->No, key) == 0)
			{
				p1->next = p2->next;
				free(p2);
				break;
			}
			else {
				p1 = p2;
				p2 = p1->next;
			}
		}
		printf("\n**********�� \014 ɾ���ɹ� \014 ��**********\n");
	}
	save_member(head);
	printf("\n\t. . .������ͨ�����鿴��Ա��Ϣ���鿴���������˵�");
	system("pause");
	getchar();
	system("cls");
	fun();
	return head;
}

//����DVD��Ϣ
DI*Insert_DVD(DI*head) {
	DI *p1, *p2 = head->next;
	int n;
	p1 = (DI*)malloc(DVD_len);
	while (p2->next != NULL)
		p2 = p2->next;
	p2->next = p1;
	printf("\n\n\n\n**********�� \5 ���DVD��Ϣ \5 ��**********\n\n\n");
	printf("\n**********�������롿**********\n\n");
	printf(" \020 ������Ҫ��ӵ�DVD������");
	scanf("%d", &n);
	printf("\n\n \020 ������Ҫ��ӵ�DVD��Ϣ��");
	printf("��\023 �����ա�DVD��š���DVD���ơ���ʽ���룩\n\n");
	scanf("%s%s", &p1->No, &p1->name);
	p1->state = 1;
	while (--n)
	{
		p2 = p1;
		p1 = (DI*)malloc(DVD_len);
		scanf("%s%s", &p1->No, &p1->name);
		p1->state = 1;
		p2->next = p1;
	}
	p1->next = NULL;
	print_DVD(head);
	save_DVD(head);
	printf("\n*********��DVD��Ϣ����ɹ�����**********\n\n");
	printf("\n\t\t. . .�̷������˵�");
	system("pause");
	getchar();
	system("cls");
	fun();
	return head;
}

//ɾ��DVD��Ϣ
DI* Delete_DVD(DI*head) {
	DI*p1, *p2, *temp;
	char key[20];
	if (head != NULL) {
		printf("\n**********��  ����DVD��Ϣ \14 ɾ�� \14 ��**********\n\n\n");
		printf("\n*************�������롿**************\n\n\n");
		printf(" \020 ������Ҫɾ����DVD��ţ�");
		scanf("%s", key);
		p1 = head;
		p2 = p1->next;
		while (p2) {
			if (strcmp(p2->No, key) == 0)
			{
				p1->next = p2->next;
				free(p2);
				break;
			}
			else {
				p1 = p2;
				p2 = p1->next;
			}
		}
		printf("\n**********�� \014 ɾ���ɹ� \014 ��**********\n");
	}
	save_DVD(head);
	printf("\n\t. . .������ͨ�����鿴DVD��Ϣ���鿴���������˵�");
	system("pause");
	getchar();
	system("cls");
	fun();
	return head;
}

//��ӡDVD��Ϣ
int print_DVD(DI*head) {
	printf("\n\n***********�� \014 DVD��Ϣ \014 ��**********\n\n");
	DI*p1 = head->next;
	printf("����š�\t�����ơ�\t��״̬��\n");
	do {
		printf("\n %s\t\t  %s\t\t", p1->No, p1->name);
		if (p1->state == 0)
			printf(" ���ɽ�\t\n\n");
		else if (p1->state == 1)
			printf(" �ɽ�\t\n\n");
		else
			printf(" �ɽ��Գ���\t\n\n");
		p1 = p1->next;
	} while (p1 != NULL);
	printf("\n");

}

//��ӡ��Ա��Ϣ
int print_member(MI*head) {
	printf("\n***********�� \014 ��Ա��Ϣ \014 ��**********\n\n\n");
	MI*p1 = head->next;
	int n;
	do {
		n = p1->state;
		printf("-------------- ��Ա��%s ------------\n\n", p1->name);
		printf("����Ա��š���%s ��Ա����%s ���룺%s\n\n", p1->No, p1->name, p1->password);
		printf("���˻�����%.2fԪ\n\n", p1->balance);
		printf("�����DVD��Ŀ����%d\n\n", p1->state);
		printf("�����DVD���&���ơ���\n\n");
		for (int i = 0; i < n; i++)
			printf("\t\t\t%-10s<%s>\n\n\n", p1->borrowDVD[i].No, p1->borrowDVD[i].name);
		printf("\n\n");
		p1 = p1->next;
	} while (p1 != NULL);
}

//����DVD��Ϣ
int save_DVD(DI*head) {

	FILE*fp;
	DI*p1;
	fp = fopen("DVD", "wb+");
	for (p1 = head; p1 != NULL; p1 = p1->next)
		fwrite(p1, DVD_len, 1, fp);
	//printf("\n\n***********��DVD��Ϣ�ѱ�����DVDĿ¼�¡�***********\n\n");
	fclose(fp);
}

//�����Ա��Ϣ
int save_member(MI*head) {

	FILE*fp;
	MI*p1;
	fp = fopen("Member", "wb+");
	for (p1 = head; p1 != NULL; p1 = p1->next)
		fwrite(p1, MEMBER_len, 1, fp);
	//printf("\n\n**********����Ա��Ϣ�ѱ�����MemberĿ¼�¡�**********\n\n");
	fclose(fp);

}

//����DVD��Ϣ����ֻ������DVD��ź�����
DI* creat_DVD()
{
	int m = 0;
	DI*head, *p, *p1;
	int DVDs;
	printf("\n\n\n\n**********�� \5 DVD��Ϣ \5 ��**********\n\n\n");
	printf("?������DVD��Ŀ\n");
	scanf("%d", &DVDs);
	p1 = head = (DI*)malloc(DVD_len);
	head->next = NULL;
	p1 = head;
	while (m < DVDs)
	{
		m++;
		p = (DI*)malloc(DVD_len);
		scanf("%s%s", &p->No, &p->name);
		p->state = 1; //״̬��ʼ��Ϊδ���
		p1->next = p;
		p1 = p1->next;
	}
	p->next = NULL;
	print_DVD(head);
	save_DVD(head);
	return head;
}

//������Ա��Ϣ�б����������Ա����š�����������
MI* creat_member()
{
	int m = 0;
	MI*head, *p, *p1;
	int Mems;
	printf("?�������Ա��Ŀ\n");
	scanf("%d", &Mems);
	p1 = head = (MI*)malloc(MEMBER_len);
	head->next = NULL;
	p1 = head;
	strcpy(p1->No, "abc");
	strcpy(p1->name, "abc");
	strcpy(p1->password, "abc");
	p1->balance = 0;
	memset(p1->borrowDVD, 0, sizeof(p1->borrowDVD));
	p1->state = 0;
	p1->next = NULL;
	while (m < Mems)
	{
		m++;
		p = (MI*)malloc(MEMBER_len);
		scanf("%s%s%s", &p->No, &p->name, &p->password);
		p->state = 0;//���DVD��Ŀ��ʼ��Ϊ0
		p->balance = 0;//�˻�����ʼ��Ϊ0
		memset(p->borrowDVD, 0, sizeof(p->borrowDVD));//���� DVD ��Ϣ��ʼ��Ϊ��
		p1->next = p;
		p1 = p1->next;
	}
	p->next = NULL;
	print_member(head);
	save_member(head);
	return head;
}

//��Ա��Ϣ����
MI*load_mem() {
	MI MM, *p1, *p2, *head;
	FILE*fp = fopen("Member", "rb");
	int r;
	if (fp == NULL)
	{
		printf("null\n");
		Admin_cover();
	}
	p1 = p2 = (MI*)malloc(MEMBER_len);
	r = fread(&MM, MEMBER_len, 1, fp);
	int w = MEMBER_len;
	if (r < 1) {
		if (ferror(fp))
			printf("\nerror\n");
		log_out();
	}
	memset(p1, 0, MEMBER_len);
	memcpy(p1, &MM, MEMBER_len);//��ȡ�ļ��е�һ������
	head = p1;
	while (!feof(fp)) {//ѭ����ȡ

		p2 = p1;
		r = fread(&MM, MEMBER_len, 1, fp);
		if (r < 1) break;
		p1 = (MI*)malloc(MEMBER_len);
		memset(p1, 0, MEMBER_len);
		memcpy(p1, &MM, MEMBER_len);
		p2->next = p1;
	}
	p2->next = p1;
	p1->next = NULL;
	return head;
}

//DVD��Ϣ����
DI*load_DVD() {
	DI DV, *p1, *p2, *head;
	FILE*fp = fopen("DVD", "rb");
	int r;
	if (fp == NULL)
	{
		printf("null\n");
		Admin_cover();
	}
	p1 = p2 = (DI*)malloc(DVD_len);
	r = fread(&DV, DVD_len, 1, fp);
	//int w = Delete_DVD;
	if (r < 1) { Admin_cover(); }
	memset(p1, 0, DVD_len);
	memcpy(p1, &DV, DVD_len);//��ȡ�ļ��е�һ������
	head = p1;
	while (!feof(fp)) {//ѭ����ȡ

		p2 = p1;
		r = fread(&DV, DVD_len, 1, fp);
		if (r < 1) break;
		p1 = (DI*)malloc(DVD_len);
		memset(p1, 0, DVD_len);
		memcpy(p1, &DV, DVD_len);
		p2->next = p1;
	}
	p2->next = p1;
	p1->next = NULL;
	return head;
}