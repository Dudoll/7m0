//16软件2班任思颖 201600800502  叶珂（201600800529） 杨倩（201600800526）
//叶珂                                                                       
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#define DVD_len sizeof(DI)
#define MEMBER_len sizeof(MI)


//DVD 信息结构体
typedef struct DVDInfo
{
	char No[10]; //DVD 编号
	char name[20]; //DVD 名字
	int state; //DVD 状态：0 表示已借出，1 表示可出借
	struct DVDInfo* next;
}DI;

//会员信息结构体
typedef struct MemberInfo
{
	char No[10]; //会员编号
	char name[20]; //会员姓名
	char password[20]; //会员密码
	float balance; //账户余额
	DI borrowDVD[3]; //所借 DVD 信息
	int state; //表示租用 DVD 的数目，取值为 0-3
	struct MemberInfo* next;
}MI;


int DVDs, Members;//全局变量 创建链表时DVD和会员的节点数目
DI*head_DVD;
MI*head_mem;


void cover();//软件封面
void Member_cover(char[]);//会员登录界面
void Admin_cover();
void choose();//注册、会员登录or管理员登陆
void log_in_Mem();//用户登陆
void log_in_Admin();//管理员登陆
void Register_Mem();//会员注册
void Register_Admin();//管理员注册
void DVD_hire(char[]);//会员租用DVD
void DVD_return(char[]);//会员归还DVD
void Payment_fee(char[]);//会员缴费
void Account_info(char[]);//会员浏览会员信息
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

//程序封面
void cover()
{
	printf("\n\n\n\t\t");
	printf("*******************************************");
	printf("\n\n\n\t\t \" 青 青 草 原 \" 电 影 俱 乐 部 管 理 系 统");
	printf("\n\n\n\t\t");
	printf("*******************************************");
	printf("\n\n\n");
	printf("\n\t\t\t\t\t16软件: 任  思  颖   201600800502\n");
	printf("\n\t\t\t\t\t16软件: 杨      倩   201600800526\n");
	printf("\n\t\t\t\t\t16软件: 叶      珂   201600800529\n");
	printf("\n\n \020 ");
	system("pause");
	system("cls");
	choose();
}

//注册、会员登录or管理员登陆
void choose()
{
	char i[10], example[] = "E";
	printf("\n\n\n\n**********【 \6 DVD租借管理系统 \6】**********\n\n\n");
	printf(".............【E】立即登录\n\n");
	printf(".............【N】新用户注册\n\n");
	printf(".............【0】退出系统\n\n");
	printf("\n**********【请输入】**********\n\n");
	scanf("%s", i);


	//注册
	if (i[0] == 'N'&&i[1] == '\0')
	{
		//会员注册或管理员注册
		char a;
		system("cls");
		printf("\n\n\n\n**********【 DVD租借系统 -- \16 注册 \16】**********\n\n\n");
		printf(".............【A】管理员注册\n\n");
		printf(".............【M】会员注册\n\n");
		printf(".............【0】返回上一层\n\n");
		printf("\n**********【请输入】**********\n\n");
		getchar();//保存换行符
		scanf("%c", &a);
		if (a == 'A')
		{
			system("cls");
			Register_Admin();//会员注册
		}
		else if (a == 'M')
		{
			system("cls");
			Register_Mem();//管理员注册
		}
		else if (a == '0')
		{
			printf("\n\t. . . 即将返回上一层，");
			system("pause");
			system("cls");
			choose();
		}
		//错误输入
		else
		{
			printf("\n**********【 \020 输入有误 \021 】**********\n\n");
			printf("\n\t. . . 请重新输入，");
			system("pause");
			system("cls");
			choose();
		}
	}
	//登陆
	else if (!strcmp(i, example))
	{
		//选择会员登录或管理员登陆
		char a;
		system("cls");
		printf("\n\n\n\n**********【DVD租借系统-- \4 登陆 \4】**********\n\n\n");
		printf(".............【A】管理员登陆\n\n");
		printf(".............【M】会员登陆\n\n");
		printf(".............【0】返回上一层\n\n");
		printf("\n**********【请输入】**********\n\n");
		getchar();//保存换行符
		scanf("%c", &a);
		if (a == 'A')
		{
			system("cls");
			log_in_Admin();//管理员登陆
		}
		else if (a == 'M')
		{
			system("cls");
			log_in_Mem();//会员登录
		}
		else if (a == '0')
		{
			printf("\n\t. . . 即将返回上一层，");
			system("pause");
			system("cls");
			choose();
		}
		//错误输入
		else
		{
			printf("\n**********【 \020 输入有误 \021 】**********\n\n");
			printf("\n\t. . . 请重新输入，");
			system("pause");
			system("cls");
			choose();
		}
	}
	//退出
	else if (i[0] == '0'&&i[1] == '\0')
		log_out();
	//错误输入
	else
	{
		printf("\n**********【 \020 输入有误 \021 】**********\n\n");
		printf("\n\t. . . 请重新输入，");
		system("pause");
		system("cls");
		choose();
	}
}

//退出系统
void log_out()
{
	system("cls");
	printf("\n*************【即将退出系统，请按任意键继续】**************\n\n\n");
	system("pause");
	system("cls");
	printf("\n\t\t*************【Goodbye! \2 】**************\n\n\n");
	exit(0);
}

//会员注册
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
	printf("\n\n\t\t\t\t\16 会员注册 \16\n\n");
	printf("\t\t");
	printf("****************************************");
	printf("\n\n\n\n\t\t请输入您的用户编号（由1-10个字符或数字组成）：");
	scanf("%s", No);
	printf("\n\n");
	printf("\t\t请输入您的姓名（由1-10字符组成）：");
	scanf("%s", name);
	printf("\n\n");
	printf("\t\t 请输入您的密码（由1-20位数字或字符组成）：");
	scanf("%s", password);
	printf("\n\n");
	printf("\t\t\t 请确认您的密码：");
	scanf("%s", repass);
	printf("\n\n");

	if (strcmp(password, repass))
	{
		printf("\n**********【 \023 注册失败 \023 】**********\n\n");
		printf("\n\t. . . 两次密码输入不一致，请重新注册，");
		system("pause");
		system("cls");
		Register_Mem(); //重新注册
	}
	//以上为输入会员信息到数组
	fp = fopen("Member", "rb");//打开文件
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
	}//如果文件中会员信息为空
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
		memcpy(p1, &MM, MEMBER_len);//读取文件中第一个数据
		head = p1;
		while (!feof(fp)) {//循环读取
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
	//文件中会员信息不为空
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
	printf("\n**********【 \16 会员信息注册成功 \16 】**********\n\n");
	printf("\n\t. . . 请重新登陆，");
	system("pause");
	system("cls");
	log_in_Mem();

}

//管理员注册
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
	printf("\n\n\t\t\t\t\16 管理员注册 \16\n\n");
	printf("\t\t");
	printf("****************************************");
	printf("\n\n\n\n\t\t请输入您的管理员编号（由1-10个字符或数字组成）：");
	scanf("%s", No);
	printf("\n\n");
	printf("\t\t请输入您的姓名（由1-10字符组成）：");
	scanf("%s", name);
	printf("\n\n");
	printf("\t\t 请输入您的密码（由1-20位数字或字符组成）：");
	scanf("%s", password);
	printf("\n\n");
	printf("\t\t\t 请确认您的密码：");
	scanf("%s", repass);
	printf("\n\n");

	if (strcmp(password, repass))
	{
		printf("\n**********【 \023 注册失败 \023 】**********\n\n");
		printf("\n\t. . . 两次密码输入不一致，请重新注册，");
		system("pause");
		getchar();
		system("cls");
		Register_Admin(); //重新注册
	}
	//以上为输入会员信息到数组
	fp = fopen("Admin", "rb");//打开文件
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
	}//如果文件中会员信息为空
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
		memcpy(p1, &MM, MEMBER_len);//读取文件中第一个数据
		head = p1;
		while (!feof(fp)) {//循环读取
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
	//文件中管理员信息不为空
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
	printf("\n**********【 \16 管理员信息注册成功 \16 】**********\n\n");
	printf("\n\t. . . 请重新登陆，");
	system("pause");
	system("cls");
	log_in_Admin();
}

//会员登陆
void log_in_Mem()
{
	int a;
	FILE* fp;
	char No[10], password[20];
	static int flag1 = 3;//登录次数
	int n = 0;

	if ((fp = fopen("Member", "r")) == NULL)
	{
		printf("\n**********【 \020 会员信息为空 \021 】**********\n\n");
		printf("\n\t. . . 请注册后登陆，即将返回主页面，");
		system("pause");
		system("cls");
		choose();
	}

	//会员登录界面
	while (flag1 > 0 && n == 0) //flag=3
	{
		printf("\n\t\t");
		printf("****************************************");
		printf("\n\n\t\t\t\t\4 会员登陆 \4\n\n");
		printf("\t\t");
		printf("****************************************");
		printf("\n\n\n\n\t\t\t\t会员编号：");
		scanf("%s", No);
		printf("\n\n");
		printf("\t\t\t\t 密码：");
		scanf("%s", password);
		printf("\n\n");


		//读取文件 验证用户密码是否正确
		MI* p;
		p = (MI*)malloc(MEMBER_len);
		while (!feof(fp)) //检测是否读取到末尾
		{
			n = 1;
			a = fread(p, MEMBER_len, 1, fp);
			if (!strcmp(p->No, No))
			{
				n = 0;
				if (!strcmp(p->password, password))
				{
					//密码正确
					fclose(fp);
					printf("\n**********【登陆成功】**********\n\n");
					printf("\n\t. . . \3 尊敬的 %s \3 ，欢迎登陆，", No);
					system("pause");
					system("cls");
					getchar();
					//进入普通会员相关函数
					Member_cover(No);
				}
				else if (flag1 > 1)
				{
					fclose(fp);
					flag1--;
					printf("\n**********【 \023 密码错误 】**********\n\n");
					printf("\n\t. . . 用户名正确，您还有%d次机会，重新登陆", flag1);
					system("pause");
					system("cls");
					log_in_Mem();
				}
				else
				{
					fclose(fp);
					flag1--;
					printf("\n**********【 \023 密码错误 】**********\n\n");
					printf("\n\t. . . 错误次数过多，即将退出系统，");
					system("pause");
					log_out();
				}
			}
		}
	}
	if (flag1 <= 1)
	{
		fclose(fp);
		printf("\n**********【 \023 用户名不存在】**********\n\n");
		printf("\n\t. . . 错误次数过多，即将退出系统，");
		system("pause");
		log_out();
	}
	fclose(fp);
	flag1--;
	printf("\n**********【 \023 用户名不存在】**********\n\n");
	printf("\n\t. . . 您还有%d次机会，重新输入", flag1);
	system("pause");
	system("cls");
	log_in_Mem();
}

//管理员登陆
void log_in_Admin()
{
	int a;
	FILE* fp;
	char No[10], password[20];
	static int flag = 3;//登录次数
	int n = 0;

	if ((fp = fopen("Admin", "r")) == NULL)
	{
		printf("\n**********【 \020 管理员信息为空 \021 】**********\n\n");
		printf("\n\t. . . 请注册后登陆，即将返回主页面，");
		system("pause");
		system("cls");
		choose();
	}

	//管理员登录界面
	while (flag > 0 && n == 0) //flag=3
	{
		printf("\n\t\t");
		printf("****************************************");
		printf("\n\n\t\t\t\t\4 管理员登陆 \4\n\n");
		printf("\t\t");
		printf("****************************************");
		printf("\n\n\n\n\t\t\t\t管理员编号：");
		scanf("%s", No);
		printf("\n\n");
		printf("\t\t\t\t 密码：");
		scanf("%s", password);
		printf("\n\n");


		//读取文件 验证用户密码是否正确
		MI* p;
		p = (MI*)malloc(MEMBER_len);
		while (!feof(fp)) //检测是否读取到末尾
		{
			n = 1;
			a = fread(p, MEMBER_len, 1, fp);
			if (!strcmp(p->No, No))
			{
				n = 0;
				if (!strcmp(p->password, password))
				{
					//密码正确
					fclose(fp);
					printf("\n**********【登陆成功】**********\n\n");
					printf("\n\t. . . \3 尊敬的 %s \3 ，欢迎登陆，", No);
					system("pause");
					system("cls");
					getchar();
					//进入管理员相关函数
					Admin_cover();
				}
				else if (flag > 1)
				{
					fclose(fp);
					flag--;
					printf("\n**********【 \023 密码错误 】**********\n\n");
					printf("\n\t. . . 用户名正确，您还有%d次机会，重新登陆", flag);
					system("pause");
					system("cls");
					log_in_Admin();
				}
				else
				{
					fclose(fp);
					flag--;
					printf("\n**********【 \023 密码错误 】**********\n\n");
					printf("\n\t. . . 错误次数过多，即将退出系统，");
					system("pause");
					log_out();
				}
			}
		}
		if (flag <= 1)
		{
			fclose(fp);
			printf("\n**********【 \023 用户名不存在】**********\n\n");
			printf("\n\t. . . 错误次数过多，即将退出系统，");
			system("pause");
			log_out();
		}
		fclose(fp);
		flag--;
		printf("\n**********【 \023 用户名不存在】**********\n\n");
		printf("\n\t. . . 您还有%d次机会，重新输入", flag);
		system("pause");
		system("cls");
		log_in_Admin();
	}

}


//会员界面 17
void Member_cover(char No[])
{
	system("cls");
	static int flag = 0;
	char c;
	printf("\n\n**********【DVD租借管理系统  \017 会员菜单 \017 】**********\n\n\n");
	printf(".............【D】账户信息浏览\n\n");
	printf(".............【H】DVD租借\n\n");
	printf(".............【R】DVD归还\n\n");
	printf(".............【P】缴纳费用\n\n");
	printf(".............【Q】切换账户\n\n");
	printf(".............【0】退出系统\n\n");
	printf("\n**********【请输入】**********\n\n");
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
		printf("\n**********【 \020 输入错误 \021 】**********\n\n");
		printf("\n\t. . . 您的输入有误，重新输入，");
		system("pause");
		getchar();
		Member_cover(No);
		break;
	}
}

//信息浏览 - D
void Account_info(char No[])
{
	system("cls");
	printf("\n\n\t\t****************************************");
	printf("\n\n\t\t\t    \017 会员信息浏览 \017\n\n");
	printf("\t\t****************************************\n\n");

	FILE* fp;
	if ((fp = fopen("Member", "rb")) == NULL)
	{
		printf("\n**********【 \020 文件错误 \021 】**********\n\n");
		printf("\n\t. . . 文件打开出错，\021\021 返回");
		system("pause");
		Member_cover(No);
	}
	MI* p;
	p = (MI*)malloc(MEMBER_len);
	while (!feof(fp)) //检测是否读取到末尾
	{
		fread(p, MEMBER_len, 1, fp);
		if (strcmp(No, p->No) == 0)
		{
			printf("\t\t.............\4 编  号：\t\t%s \n\n", p->No);
			printf("\t\t.............\4 姓  名：\t\t%s \n\n", p->name);
			printf("\t\t.............\4 余  额：\t\t%.2f元 \n\n", p->balance);
			printf("\t\t.............\4 租借DVD数目：\t%d \n\n", p->state);
			if (p->state != 0)
			{
				printf("\t\t.............\4 租借DVD编号&名字：");
				for (int i = 0; i < p->state; i++)
				{
					if (i == 0)
						printf("%-3s  <%s>\n", p->borrowDVD[i].No, p->borrowDVD[i].name);
					else
						printf("\t\t\t\t\t\t %-3s  <%s>\n", p->borrowDVD[i].No, p->borrowDVD[i].name);

				}
			}
			printf("\n\n\t\t. . . 返回主页面");
			system("pause");
			getchar();
			system("cls");
			Member_cover(No);
		}
		//输出会员自身信息少
	}
	fclose(fp);
}

//租用DVD - H
void DVD_hire(char No[])
{
	system("cls");
	printf("\n\n**********【DVD租借管理系统  \017 租用DVD \017 】**********\n\n");
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
		printf("\n**********【 \020 文件错误 \021 】**********\n\n");
		printf("\n\t. . . 文件打开出错，\021\021 返回");
		DVD_hire(No);
	}
	do {
		p = p->next;
	} while (strcmp(p->No, No));
	printf("\n\n");
	printf(".............【S】浏览DVD\n\n");
	printf(".............【Q】返回上一层\n\n");
	printf("\n**********【请输入】**********\n\n");
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
			printf("\n**********【 \020 DVD信息为空 \021 】**********\n\n");
			printf("\n\t. . . \021\021 返回主页面");
			system("pause");
			system("cls");
			Member_cover(No);
		}
		break;
	}
	case'Q':
		fclose(fp);
		printf("\n\t. . . \021\021 返回主页面");
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
		printf("\n**********【 \023 余额不足 \023 】**********\n\n");
		printf("\n\t. . . 余额不足3元，请充值后再租借！返回主菜单");
		system("pause");
		getchar();
		system("cls");
		Member_cover(No);
		return;
	}
	printf("\n   \020 您的账户余额为：%.2f \021\n", p->balance);
	if (p->balance > 0 && p->state < 3)
	{
		printf("\n**********【 \017 请输入 \017 】**********\n\n");
		printf("请输入想租借的DVD编号，每次租借自动扣费3.0元，输入#取消租借：");
		scanf("%s", No_DVD);
		if (!strcmp("#", No_DVD))
		{
			printf("\n\t. . . 返回租借菜单");
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
			printf("\n**********【 \020 租借失败 \021 】**********\n");
			printf("\n\t\t. . . 无此DVD , 继续租借");
			fclose(fp);
			system("pause");
			getchar();
			system("cls");
			DVD_hire(No);
		}
		if (p3->state == 0)
		{
			printf("\n**********【 \020 租借失败 \021 】**********\n");
			printf("\n\t\t. . . 该DVD已借出 , 租借其他DVD");
			fclose(fp);
			system("pause");
			getchar();
			system("cls");
			Member_cover(No);
			return;
		}
		p3->state = 0;
		//修改DVD的状态
		p->state++;
		int m = p->state - 1;
		strcpy(p->borrowDVD[m].No, No_DVD);
		strcpy(p->borrowDVD[m].name, p3->name);
		p->balance -= 3;
		save_DVD(head_DVD);
		save_member(head_mem);
		printf("\n**********【 \020 租借成功 \021 】**********\n\n");
		printf(" \020 您的账户余额为：%.2f \021  返回主菜单", p->balance);
		system("pause");
		getchar();
		system("cls");
		fclose(fp);
		Member_cover(No);
		//修改会员结构体中租借DVD的信息
	}
	//用户
	else
	{
		while (i--)
		{
			if (p->balance < 3 && p->state < 3)
			{
				fclose(fp);
				printf("\n**********【 \020 租借失败 \021 】**********\n");
				printf("\n\t\t. . . 你的账户余额不足3元，请缴费后再租借，返回主菜单");
				system("pause");
				getchar();
				system("cls");
				Member_cover(No);
			}
			else if (p->balance > 0 && p->state == 3)
			{
				fclose(fp);
				printf("\n**********【 \020 租借失败 \021 】**********\n");
				printf("\n\t\t. . .租借DVD数目已达上限，请归还DVD后再租借 ，返回主菜单");
				system("pause");
				getchar();
				system("cls");
				Member_cover(No);
			}
			else
			{
				fclose(fp);
				printf("\n**********【 \020 租借失败 \021 】**********\n");
				printf("\n\t\t. . .租借DVD数目已达上限且余额不足3元，请归还DVD并缴费后再试 ，返回主菜单");
				system("pause");
				getchar();
				system("cls");
				Member_cover(No);
			}
		}
	}
}

//归还DVD - R
void DVD_return(char No[])
{
	int i, j;//用于循环
	int flag = 0;//是否租借这部DVD
	system("cls");
	printf("\n\n**********【DVD租借管理系统  \017 归还DVD \017 】**********\n\n");

	char No_DVD[10];
	head_mem = load_mem();
	head_DVD = load_DVD();

	MI*p1 = head_mem;
	DI*p3 = head_DVD;
	printf("\n**********【请输入】**********\n\n");
	printf("\020 请输入需要归还的DVD编号：");
	scanf("%s", No_DVD);
	printf("\n\n");
	do {
		p3 = p3->next;
	} while (strcmp(p3->No, No_DVD));
	if (strcmp(p3->No, No_DVD) != 0)
	{
		printf("\n**********【 \020 归还失败 \021 】**********\n");
		printf("\n\t. . .好像没有这个DVD╰(￣▽￣)╭  ，返回主菜单");
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
		printf("\n**********【 \020 归还失败 \021 】**********\n");
		printf("\n\t\t. . .您好像没有借这个DVD╰(￣▽￣)╭  ，继续归还");
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
		printf("\n**********【 \017 归还成功 \017 】**********\n");
		printf("\n\t\t. . .继返回主菜单");
		system("pause");
		getchar();
		system("cls");
	}
	Member_cover(No);
}

//会员缴费 - P
void Payment_fee(char No[])
{
	system("cls");
	printf("\n\n**********【DVD租借管理系统  \017 会员缴费 \017 】**********\n\n");


	float fee;
	head_mem = load_mem();
	MI*p1 = head_mem;
	do {
		p1 = p1->next;
	} while (strcmp(p1->No, No));
	printf("\n   \020 您的账户余额为：%.2f元 \021\n", p1->balance);
	printf("\n\n  . . .请输入缴费金额：");
	scanf("%f", &fee);
	p1->balance += fee;
	printf("\n\n**********【 \017 缴费成功 \017 】**********\n");
	printf("\n您当前账户余额为:%.2f元\n\n", p1->balance);
	//保存到文件
	save_member(head_mem);
	printf("\n\t\t. . . 返回主菜单");
	system("pause");
	getchar();
	system("cls");
	Member_cover(No);
}

//会员注销 - Q
void Member_logout(char No[])
{
	char a, b;
	system("cls");
	printf("\n**********【 \14 切换账号 \14 】**********\n\n\n");
	printf("当前所在账号编号为：%s ，是否注销？(Y / N)\n\n", No);
	printf("\n**********【请输入】**********\n\n");
	b = getchar();
	scanf("%c", &a);
	switch (a)
	{
	case'Y':
		printf("\n\t. . . 正在注销，\020\020 登陆");
		system("pause");
		system("cls");
		log_in_Mem();
		break;
	case'N':
		printf("\n\t. . . 取消退出，\021\021 返回菜单");
		system("pause");
		getchar();
		system("cls");
		Member_cover(No);
		break;
	default:
		printf("\n**********【 \020 输入有误 \021 】**********\n\n");
		printf("\n\t. . . 重新输入，");
		system("pause");
		Member_logout(No);
		break;
	}
	return;
}


//------------------------------------------------------------------------

//管理员界面
void Admin_cover()
{
	char a;
	printf("\n\n\n\n**********【DVD租借管理系统 \5 管理员菜单 \5 】**********\n\n\n");
	printf(".............【1】:DVD信息\n\n");
	printf(".............【2】:会员信息\n\n");
	printf(".............【3】:交易信息\n\n");
	printf(".............【4】:退出\n\n");
	printf("\n*************【请输入】**************\n\n\n");
	//getchar();
	a = getchar();
	start_administrator(a);
}

//过渡
void fun() {
	system("cls");
	//getchar();
	printf("\n\n\n\n**********【DVD租借管理系统】**********\n\n\n");
	printf(".............【1】:DVD信息\n\n");
	printf(".............【2】:会员信息\n\n");
	printf(".............【3】:交易信息\n\n");
	printf(".............【4】:退出\n\n");
	printf("\n*************【请输入】**************\n\n\n");
	//getchar();
	int m = getchar();
	start_administrator(m);
}

//选择
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
		printf("\n**********【 \020 输入错误 \021 】**********\n\n");
		printf("\n\t. . . 您的输入有误，重新输入，");
		system("pause");
		getchar();
		system("cls");
		fun();
	}
}

//1-DVD信息
DI*Info_DVD() {
	int r = 0, n = 0;
	char a;
	DI*head, *p1, *p2, DV;
	FILE *fp = NULL;
	system("cls");
	//printf("**********【DVD信息加载成功！】**********\n\n");
	fp = fopen("DVD", "rb+");//打开文件
	if (fp == NULL) {
		printf("\n**********【 \020 文件错误 \021 】**********\n\n");
		printf("\n\t. . . 文件为空，\021\021 返回主菜单");
		system("pause");
		fun();
	}
	p1 = p2 = (DI*)malloc(DVD_len);
	r = fread(&DV, DVD_len, 1, fp);
	//int w = Delete_DVD;
	if (r < 1) { return; }
	memset(p1, 0, DVD_len);
	memcpy(p1, &DV, DVD_len);//读取文件中第一个数据
	head = p1;
	while (!feof(fp)) {//循环读取
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
	print_DVD(head);//打印读取到链表中的信息
					//以上为加载DVD信息
	printf("\n**********【请输入】**********\n\n");
	printf("........【A】: 添加DVD信息\n\n");
	printf("........【B】: 删除DVD信息\n\n");
	printf("........【C】: 返回上一级\n");
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
		printf("\n\t. . . 返回主菜单");
		system("pause");
		getchar();
		system("cls");
		fun();
		return head;
	}
	else
	{
		printf("\n**********【 \020 输入错误 \021 】**********\n\n");
		printf("\n\t. . . 您的输入有误，重新输入，");
		system("pause");
		//getchar();
		Info_DVD();
	}
	//以上为修改DVD信息
}

//2-会员信息
MI*Info_member() {
	int r = 0, n = 0;
	char a;
	MI*head, *p1, *p2, MM;
	FILE *fp = NULL;
	system("cls");
	fp = fopen("Member", "rb");//打开文件
	if (fp == NULL) {
		printf("\n**********【 \020 会员文件错误 \021 】**********\n\n");
		printf("\n\t. . . 文件为空，\021\021 返回主菜单");
		system("pause");
		fun();
	}
	p1 = p2 = (MI*)malloc(MEMBER_len);
	r = fread(&MM, MEMBER_len, 1, fp);
	int w = MEMBER_len;
	if (r < 1) {
		if (ferror(fp))
		{
			printf("\n**********【 \020 读取文件错误 \021 】**********\n\n");
			printf("\n\t\t. . . \021\021 返回主菜单");
			system("pause");
			fun();
		}
		return;
	}
	memset(p1, 0, MEMBER_len);
	memcpy(p1, &MM, MEMBER_len);//读取文件中第一个数据
	head = p1;
	while (!feof(fp)) {//循环读取
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
	print_member(head);//打印读取到链表中的信息
					   //printf("**********【会员信息加载成功！】**********\n\n");
					   //以上为加载会员信息
	printf("\n**********【请输入】**********\n\n");
	printf("........【A】: 添加会员信息\n\n");
	printf("........【B】: 删除会员信息\n\n");
	printf("........【C】: 返回上一级\n");
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
		printf("\n\t. . . 返回主菜单");
		system("pause");
		getchar();
		system("cls");
		fun();
		return head;
	}
	else
	{
		printf("\n**********【 \020 输入错误 \021 】**********\n\n");
		printf("\n\t. . . 您的输入有误，重新输入，");
		system("pause");
		getchar();
		Info_member();
	}
	//以上为修改会员信息
}

//3-交易信息
void Info_trade(MI*head_mem) {
	MI*p1, p2;
	head_mem = load_mem();
	p1 = head_mem->next;
	printf("\n\n\n\n**********【DVD租借管理系统 \05 交易信息 \05】**********\n\n\n");
	printf("  【会员姓名】\t  【租用DVD数目】\n\n");
	do {
		//if (p1->state != 0)
		printf("%15s %15d\n", p1->name, p1->state);
		p1 = p1->next;
	} while (p1 != NULL);
	printf("\n\t\t. . . 交易信息如上，\021\021 返回主菜单");
	system("pause");
	getchar();
	system("cls");
	fun();
}

//插入会员信息
MI*Insert_member(MI*head) {
	MI *p1, *p2 = head->next;
	int n;
	p1 = (MI*)malloc(MEMBER_len);
	while (p2->next != NULL)
		p2 = p2->next;
	p2->next = p1;
	system("cls");
	printf("\n\n\n\n**********【 \5 添加会员信息 \5 】**********\n\n\n");
	printf("\n**********【请输入】**********\n\n");
	printf(" \020 请输入要添加的会员个数：");
	scanf("%d", &n);
	printf("\n\n \020 请输入添加的会员信息：");
	printf("（\023 请依照“会员编号”“会员姓名”“会员密码”格式输入：）\n\n");
	scanf("%s%s%s", &p1->No, &p1->name, &p1->password);
	p1->state = 0;
	p1->balance = 0;//账户余额初始化为0
	memset(p1->borrowDVD, 0, sizeof(p1->borrowDVD));//所借 DVD 信息初始化为空
	while (--n)
	{
		p2 = p1;
		p1 = (MI*)malloc(MEMBER_len);
		scanf("%s%s%s", &p1->No, &p1->name, &p1->password);
		p1->balance = 0;//账户余额初始化为0
		p1->state = 0;
		memset(p1->borrowDVD, 0, sizeof(p1->borrowDVD));//所借 DVD 信息初始化为空
		p2->next = p1;
	}
	p1->next = NULL;
	printf("\n**********【 \017 添加成功 \017 】**********\n");
	print_member(head);
	save_member(head);
	printf("\n\n\t\t. . .继返回主菜单");
	system("pause");
	getchar();
	system("cls");
	fun();
	return head;
}

//删除会员信息
MI*Delete_member(MI*head) {
	MI*p1, *p2;
	char key[20];
	if (head != NULL) {
		printf("\n**********【 管理会员信息 \14 删除 \14 】**********\n\n\n");
		printf("\n*************【请输入】**************\n\n\n");
		printf(" \020 请输入要删除的会员编号：");
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
		printf("\n**********【 \014 删除成功 \014 】**********\n");
	}
	save_member(head);
	printf("\n\t. . .您可以通过“查看会员信息”查看，返回主菜单");
	system("pause");
	getchar();
	system("cls");
	fun();
	return head;
}

//插入DVD信息
DI*Insert_DVD(DI*head) {
	DI *p1, *p2 = head->next;
	int n;
	p1 = (DI*)malloc(DVD_len);
	while (p2->next != NULL)
		p2 = p2->next;
	p2->next = p1;
	printf("\n\n\n\n**********【 \5 添加DVD信息 \5 】**********\n\n\n");
	printf("\n**********【请输入】**********\n\n");
	printf(" \020 请输入要添加的DVD个数：");
	scanf("%d", &n);
	printf("\n\n \020 请输入要添加的DVD信息：");
	printf("（\023 请依照“DVD编号”“DVD名称”格式输入）\n\n");
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
	printf("\n*********【DVD信息插入成功！】**********\n\n");
	printf("\n\t\t. . .继返回主菜单");
	system("pause");
	getchar();
	system("cls");
	fun();
	return head;
}

//删除DVD信息
DI* Delete_DVD(DI*head) {
	DI*p1, *p2, *temp;
	char key[20];
	if (head != NULL) {
		printf("\n**********【  管理DVD信息 \14 删除 \14 】**********\n\n\n");
		printf("\n*************【请输入】**************\n\n\n");
		printf(" \020 请输入要删除的DVD编号：");
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
		printf("\n**********【 \014 删除成功 \014 】**********\n");
	}
	save_DVD(head);
	printf("\n\t. . .您可以通过“查看DVD信息”查看，返回主菜单");
	system("pause");
	getchar();
	system("cls");
	fun();
	return head;
}

//打印DVD信息
int print_DVD(DI*head) {
	printf("\n\n***********【 \014 DVD信息 \014 】**********\n\n");
	DI*p1 = head->next;
	printf("【编号】\t【名称】\t【状态】\n");
	do {
		printf("\n %s\t\t  %s\t\t", p1->No, p1->name);
		if (p1->state == 0)
			printf(" 不可借\t\n\n");
		else if (p1->state == 1)
			printf(" 可借\t\n\n");
		else
			printf(" 可借性出错\t\n\n");
		p1 = p1->next;
	} while (p1 != NULL);
	printf("\n");

}

//打印会员信息
int print_member(MI*head) {
	printf("\n***********【 \014 会员信息 \014 】**********\n\n\n");
	MI*p1 = head->next;
	int n;
	do {
		n = p1->state;
		printf("-------------- 会员：%s ------------\n\n", p1->name);
		printf("【会员编号】：%s 会员名：%s 密码：%s\n\n", p1->No, p1->name, p1->password);
		printf("【账户余额】：%.2f元\n\n", p1->balance);
		printf("【租借DVD数目】：%d\n\n", p1->state);
		printf("【租借DVD编号&名称】：\n\n");
		for (int i = 0; i < n; i++)
			printf("\t\t\t%-10s<%s>\n\n\n", p1->borrowDVD[i].No, p1->borrowDVD[i].name);
		printf("\n\n");
		p1 = p1->next;
	} while (p1 != NULL);
}

//保存DVD信息
int save_DVD(DI*head) {

	FILE*fp;
	DI*p1;
	fp = fopen("DVD", "wb+");
	for (p1 = head; p1 != NULL; p1 = p1->next)
		fwrite(p1, DVD_len, 1, fp);
	//printf("\n\n***********【DVD信息已保存至DVD目录下】***********\n\n");
	fclose(fp);
}

//保存会员信息
int save_member(MI*head) {

	FILE*fp;
	MI*p1;
	fp = fopen("Member", "wb+");
	for (p1 = head; p1 != NULL; p1 = p1->next)
		fwrite(p1, MEMBER_len, 1, fp);
	//printf("\n\n**********【会员信息已保存至Member目录下】**********\n\n");
	fclose(fp);

}

//创建DVD信息链表，只需输入DVD编号和名字
DI* creat_DVD()
{
	int m = 0;
	DI*head, *p, *p1;
	int DVDs;
	printf("\n\n\n\n**********【 \5 DVD信息 \5 】**********\n\n\n");
	printf("?请输入DVD数目\n");
	scanf("%d", &DVDs);
	p1 = head = (DI*)malloc(DVD_len);
	head->next = NULL;
	p1 = head;
	while (m < DVDs)
	{
		m++;
		p = (DI*)malloc(DVD_len);
		scanf("%s%s", &p->No, &p->name);
		p->state = 1; //状态初始化为未借出
		p1->next = p;
		p1 = p1->next;
	}
	p->next = NULL;
	print_DVD(head);
	save_DVD(head);
	return head;
}

//创建会员信息列表，仅需输入会员、编号、姓名、密码
MI* creat_member()
{
	int m = 0;
	MI*head, *p, *p1;
	int Mems;
	printf("?请输入会员数目\n");
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
		p->state = 0;//租借DVD数目初始化为0
		p->balance = 0;//账户余额初始化为0
		memset(p->borrowDVD, 0, sizeof(p->borrowDVD));//所借 DVD 信息初始化为空
		p1->next = p;
		p1 = p1->next;
	}
	p->next = NULL;
	print_member(head);
	save_member(head);
	return head;
}

//会员信息加载
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
	memcpy(p1, &MM, MEMBER_len);//读取文件中第一个数据
	head = p1;
	while (!feof(fp)) {//循环读取

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

//DVD信息加载
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
	memcpy(p1, &DV, DVD_len);//读取文件中第一个数据
	head = p1;
	while (!feof(fp)) {//循环读取

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