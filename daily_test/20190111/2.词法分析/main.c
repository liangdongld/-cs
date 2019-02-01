#include<stdio.h>
#include<string.h>

//����ؼ��ֱ�
char keyword[10][10] = { "int","char","float","if","else","while","break","continue","main","return" };
int len_key = 10;

//��������
char del[] = { '+','-','*','/','=','(',')','[',']','{','}',';','>','<' };
int len_del = sizeof(del) / sizeof(del[0]);

//���峣����
#define len_con 10
float con[len_con];
int pos_con = 0;

//�����ʶ����
#define len_id 20
char id[len_id][10];
int pos_id = 0;

//���屣��token������
typedef struct _token {
	char name[6];//��ʾʶ�𵥴ʵķ���
	int pos;//��ʾʶ�𵥴ʵ�λ��
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
	//����ָ��token��ͷָ��
	token = (_token *)malloc(sizeof(_token));
	head = token;
	//char Data[]="int a = 12.3+e2 ; float b = 20 ; if(a) { a = b;}";
	//int Len_Data=sizeof(Data)/sizeof(Data[0])-1;
	FILE *_fp;
	int count = 0;
	_fp = fopen("in.txt", "rb"); //��ָ���ļ�
	char buff[1];
	char Data[1000] = { 'a' };
	while (fread(buff, 1, 1, _fp) != NULL)//ÿ�ζ�ȡһ�ֽڴ���Data������
	{
		Data[count] = buff[0];
		count++;
	}
	fclose(_fp);
	int Len_Data = strlen(Data);//��ȡData���鳤��
	int i = 0;
	for (i; i < Len_Data; i++)
		printf("%c", Data[i]);//��ӡ��Data��������
	printf("\n�ַ�����ȡ���\n");
	int pos_check = 0;
	int _start = 0;

	while (pos_check < Len_Data) {//����ȡ����ʱ����

		_start = pos_check;//_start���浱ǰλ��
		//�����ʶ��
		if (Data[_start] == '_' || (Data[_start] <= 'z'&&Data[_start] >= 'a') || (Data[_start] <= 'Z'&&Data[_start] >= 'A')) {
			printf("�����ʶ���Զ���\n");
			pos_check = deal_id(pos_check, Data);

		}
		//�������ֳ���
		else if (Data[_start] <= '9'&&Data[_start] >= '0') {
			printf("�������ֳ����Զ���\n");
			pos_check = deal_Num(pos_check, Data);
		}
		//������
		else if (IsDel(Data[_start]) != -1) {
			printf("�������Զ���\n");
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

//�ж�ʶ����ı�ʶ���Ƿ�Ϊ�ؼ���
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

//�Ա�ʶ�����д���
int  deal_id(int p, char data[]) {//p��ʾλ��
	int start = p;
	int end = start;//��ʼʱstart��end���
	char word[10], c[2];
	p++;
	while ((data[p] >= 'a'&&data[p] <= 'z') || (data[p] >= '0'&&data[p] <= '9')) {//������ַ���������ʱ 
		p++;
	}
	end = p - 1;
	for (start; start <= end; start++) {
		c[0] = data[start];
		strcat(word, c);
	}//��һ��������ƴ�ӳ����ĵ���
	printf("\n");
	printf("%s\n", word);
	strcpy(id[pos_id], word);                     /*#define len_id 20        char id[len_id][10];         int pos_id = 0;*/
	strcpy(token->name, "id");
	token->pos = pos_id;
	pos_id++;
	if (IsKeyword(word) != -1)//���word�ǹؼ���
	{
		printf("%s �ǹؼ���\n", word);
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

//����10��n����
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

//�����ֳ������д���
int deal_Num(int p, char data[]) {
	int a = 0, b = 0, c = 0, e = 0;//c��ʾС������λ��  e��ʾ+-��
	float sum = 0;
	a = data[p] - 0x30;//���ַ�תΪ����
	p++;
	while (1) {
		while (data[p] <= '9'&&data[p] >= '0') {//�����������С
			a = a * 10 + data[p] - 0x30;
			p++;
		}
		if (data[p] == '.') {//�����С����
			p++;
			while (data[p] <= '9'&&data[p] >= '0') {
				a = a * 10 + data[p] - 0x30;
				c++;//c��ʾС������λ��
				p++;
			}
		}
		if (data[p] == '+' || data[p] == '-') {
			if (data[p] == '+') { e = 1; }
			else { e = -1; }
			p = p + 2;
			b = data[p] - 0x30;
			p++;
			while (data[p] <= '9'&&data[p] >= '0') {//b��ʾ�Ҳ�����
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

//�Խ�����д���
//�жϽ������ĵ����Ƿ��ǽ��
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