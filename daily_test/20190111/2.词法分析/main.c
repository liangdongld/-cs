#include<stdio.h>
#include<string.h>

//定义关键字表
char keyword[10][10] = { "int","char","float","if","else","while","break","continue","main","return" };
int len_key = 10;

//定义界符表
char del[] = { '+','-','*','/','=','(',')','[',']','{','}',';','>','<' };
int len_del = sizeof(del) / sizeof(del[0]);

//定义常数表
#define len_con 10
float con[len_con];
int pos_con = 0;

//定义标识符表
#define len_id 20
char id[len_id][10];
int pos_id = 0;

//定义保存token的链表
typedef struct _token {
	char name[6];//表示识别单词的分类
	int pos;//表示识别单词的位置
	struct _token *next;
} _token;
_token *token = NULL;
_token *head = NULL;
int IsKeyword(char word[]);
int deal_id(int p, char data[]);
int deal_Num(int p, char data[]);
int IsDel(char check);
int deal_Del(int p, char data[]);

int main()
{
	//定义指向token的头指针
	token = (_token *)malloc(sizeof(_token));
	head = token;
	//char Data[]="int a = 12.3+e2 ; float b = 20 ; if(a) { a = b;}";
	//int Len_Data=sizeof(Data)/sizeof(Data[0])-1;
	FILE *_fp;
	int count = 0;
	_fp = fopen("in.txt", "rb"); //打开指定文件
	char buff[1];
	char Data[1000] = { 'a' };
	while (fread(buff, 1, 1, _fp) != NULL)//每次读取一字节存入Data数组中
	{
		Data[count] = buff[0];
		count++;
	}
	fclose(_fp);
	int Len_Data = strlen(Data);//获取Data数组长度
	int i = 0;
	for (i; i < Len_Data; i++)
		printf("%c", Data[i]);//打印出Data数组内容
	printf("\n字符串读取完毕\n");
	int pos_check = 0;
	int _start = 0;

	while (pos_check < Len_Data) {//当读取结束时跳出

		_start = pos_check;//_start保存当前位置
		//处理标识符
		if (Data[_start] == '_' || (Data[_start] <= 'z'&&Data[_start] >= 'a') || (Data[_start] <= 'Z'&&Data[_start] >= 'A')) {
			printf("进入标识符自动机\n");
			pos_check = deal_id(pos_check, Data);

		}
		//处理数字常量
		else if (Data[_start] <= '9'&&Data[_start] >= '0') {
			printf("进入数字常量自动机\n");
			pos_check = deal_Num(pos_check, Data);
		}
		//处理界符
		else if (IsDel(Data[_start]) != -1) {
			printf("进入界符自动机\n");
			pos_check = deal_Del(pos_check, Data);
		}
		else {
			printf("error\n");
			pos_check++;
		}
	}
	_token *fp = head;
	while (fp->next != NULL) {
		printf("<%s,%d>", fp->name, fp->pos);
		fp = fp->next;
	}
	return 0;
}

//判断识别出的标识符是否为关键字
int IsKeyword(char word[])
{
	int i = 0, ans = -1;
	for (i; i < len_key; i++)
		if (strcmp(word, keyword[i]) == 0)
		{
			ans = i;
			break;
		}
	return ans;
}

//对标识符进行处理
int  deal_id(int p, char data[]) {//p表示位置
	int start = p;
	int end = start;//初始时start与end相等
	char word[10], c[2];
	p++;
	while ((data[p] >= 'a'&&data[p] <= 'z') || (data[p] >= '0'&&data[p] <= '9')) {//如果是字符或者数字时 
		p++;
	}
	end = p - 1;
	for (start; start <= end; start++) {
		c[0] = data[start];
		strcat(word, c);
	}//这一部分生成拼接出来的单词
	printf("\n");
	printf("%s\n", word);
	strcpy(id[pos_id], word);                     /*#define len_id 20        char id[len_id][10];         int pos_id = 0;*/
	strcpy(token->name, "id");
	token->pos = pos_id;
	pos_id++;
	if (IsKeyword(word) != -1)//如果word是关键字
	{
		printf("%s 是关键字\n", word);
		strcpy(token->name, "keyword");
		token->pos = IsKeyword(word);
		pos_id--;
	}
	printf("<%s,%d>\n", token->name, token->pos);
	token->next = malloc(sizeof(_token));
	token = token->next;
	token->next = NULL;
	return p;
}

//计算10的n次幂
float f(int n)
{
	float sum = 1;
	int i = 0;
	if (n >= 0)
		for (i; i < n; i++)
			sum *= 10;
	else
		for (i; i < n; i++)
			sum *= 0.1;
	return sum;
}

//对数字常量进行处理
int deal_Num(int p, char data[]) {
	int a = 0, b = 0, c = 0, e = 0;//c表示小数点后的位数  e表示+-号
	float sum = 0;
	a = data[p] - 0x30;//将字符转为数字
	p++;
	while (1) {
		while (data[p] <= '9'&&data[p] >= '0') {//计算这个数大小
			a = a * 10 + data[p] - 0x30;
			p++;
		}
		if (data[p] == '.') {//如果有小数点
			p++;
			while (data[p] <= '9'&&data[p] >= '0') {
				a = a * 10 + data[p] - 0x30;
				c++;//c表示小数点后的位数
				p++;
			}
		}
		if (data[p] == '+' || data[p] == '-') {
			if (data[p] == '+') { e = 1; }
			else { e = -1; }
			p = p + 2;
			b = data[p] - 0x30;
			p++;
			while (data[p] <= '9'&&data[p] >= '0') {//b表示右操作数
				b = b * 10 + data[p] - 0x30;
				p++;
			}

		}
		break;
	}
	sum = a*f(e*b - c);
	strcpy(token->name, "con");
	token->pos = pos_con;
	con[pos_con] = sum;
	pos_con++;
	token->next = (_token *)malloc(sizeof(_token));
	token = token->next;
	token->next = NULL;
	printf("the num is %f\n", sum);
	return p;
}

//对界符进行处理
//判断接下来的单词是否是界符
int IsDel(char check) {
	int i = 0, ans = -1;
	for (i; i < len_del; i++)
	{
		if (check == del[i]) {
			ans = i;
			break;
		}
	}
	return ans;
}

int deal_Del(int p, char data[])
{
	strcpy(token->name, "del");
	token->pos = IsDel(data[p]);
	token->next = (_token *)malloc(sizeof(_token));
	token = token->next;
	token->next = NULL;
	printf("%c\n", data[p]);
	p++;
	return p;
}