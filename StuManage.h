#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define INFINITY INT_MAX //�����������������ֵ��������� 
#define MAXSIZE 11 //Ĭ�ϴ����ѧ������ 

typedef int Status; // Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��

//ѧ����Ϣ�ṹ��
typedef struct{
	
	int num;//ѧ�ţ�Ĭ��Ϊ8λ���֣�ǰ4λ��ʾ�꼶����5��6λ��ʾ�Ա�01��ʾ�У�00��ʾŮ 
	char *name;//����
	char gender;//�Ա� ,M��ʾ�У�W��ʾŮ 
	int avscore;//ƽ���ɼ�
	int clas;//�༶,����class���ֿ� 
	char *major;//רҵ�����Ǽ����ѧԺ��רҵ 
}Stu;

//ѧ������
typedef struct SLNode{
	
	Stu data;//ѧ����Ϣ
	struct SLNode *next; 
}SLNode,*SLinkList;

/*����ѧ����Ϣ����*/

//ѧ�������ʼ��
Status InitList(SLinkList &SL){
	
	SL = (SLinkList)malloc(sizeof(SLinkList));//����һ��ͷ�ڵ����ռ�
	
	//Ϊרҵ�����������������ռ� 
	SL->data.major = (char *)malloc(sizeof(char));
	SL->data.name = (char *)malloc(sizeof(char));
	
	if(!SL||!SL->data.major||!SL->data.name) return ERROR;//����ʧ�ܣ�����ʧ��
	
	SL->next = NULL;//����ɹ�������ͷ�ڵ㣬����OK 
	
	return OK; 
} 

//����һ��ѧ���ڵ�
SLNode *MakeNode(Stu s){
	
	SLNode *p;
	p = (SLNode *)malloc(sizeof(SLNode));
	
	if(!p) return NULL;//����ʧ�ܣ����ؿ�ָ��
	
	//����ռ�ɹ��������½ڵ�p�������� 
	p->data = s;
	p->next = NULL;
	
	return p; 
}

//¼��ѧ����Ϣ(����)����ѧ�Ŵ�С�������
Status EnterNode(SLinkList &SL, SLNode *p){
	
	if(!SL||!p) return ERROR;//ͷ�ڵ��Ҫ����Ľڵ�Ϊ�գ���������������ERROR
	
	SLNode *q;
	q = SL->next;//qָ���һ��ѧ���ڵ�
	
	if(!q){	//����һ��ѧ���ڵ�Ϊ�գ�ֱ�Ӳ�����ѧ���ڵ���Ϊ��һλѧ��
		
		SL->next = p;
		p->next = NULL;
		
		return OK; //������ɣ�����OK��
	}else{//��һ��ѧ���ڵ㲻Ϊ�գ�����ѧ�Ŵ�С������� 
		
		//��pѧ�űȵ�һλѧ����ѧ�Ż�С��������ǰ����� 
		if(p->data.num < q->data.num){
			
			p->next = q;
			SL->next = p;
	
			return OK; 
		}else{
		
			while(q->next){
			
			//��ԭ��ѧ��������pѧ������Ϣ������ʧ�� 
			if(p->data.num == q->data.num) return ERROR; 
			
			//��pѧ�Ŵ�С���ڵ�ǰ�ڵ���С�ڵ�ǰ�ڵ���һ���ڵ㣬����� 
				if(q->data.num < p->data.num&&(q->next)->data.num > p->data.num){
				
					p->next = q->next;
					q->next = p;
				 
					return OK; 
				}
			
				q = q->next;//δ�ҵ�����������һ���ڵ� 
			}
			
			//��pѧ�Ŵ�С�����һ��ѧ���ڵ㻹��ֱ�Ӳ嵽��� 
			q->next = p;
			p->next = NULL;
			 
		    return OK;
	    }
	}
	
	return ERROR; 
}

//��������Ϊn��ѧ��������������S[]�ṩn��Ԫ��ֵ��ѧ���� 
Status CreateList(SLinkList &SL, int n, Stu *S){
	
	SLNode *sp;
	
	//��ʼ��ʧ�ܻ��������������ERROR 
	if(!InitList(SL)||n <= 0||!S) return ERROR;
	
	//���β���n���ڵ� 
	for(int i = 0;i < n;i++){
		
		sp = MakeNode(S[i]);//��S[i]�ṩ����Ϣ�����µĽڵ� 
		
		if(!EnterNode(SL,sp)) return ERROR;//������룬�������ʧ�ܣ�����ERROR�� 
	}
	
	return OK;
}

/*��ѧ����Ϣ���в���*/ 

//���ȫ��ѧ����Ϣ
void OutputAll(SLinkList SL){
	
	SLNode *p;
	
	p = SL->next;
	
	printf("ѧ��\t\t����\t�Ա�  ƽ���ɼ�\t�༶\tרҵ\n");
	
	while(p){
		
		printf("%d\t%s\t%c\t%d\t%d\t%s\n",
			p->data.num,p->data.name,p->data.gender,p->data.avscore,p->data.clas,p->data.major);
			
		p = p->next;
	}
}

//�������ѧ����Ϣ
void Output(SLNode *p){
	
	//printf("ѧ��\t\t����\t�Ա�  ƽ���ɼ�\t�༶\tרҵ\n");
	
	printf("%d\t%s\t%c\t%d\t%d\t%s\n",
		p->data.num,p->data.name,p->data.gender,p->data.avscore,p->data.clas,p->data.major);
} 

//ͨ��ѧ�Ų���Ŀ��ѧ����ǰһ��ѧ��������ɾ�����������ҵ����ظ�ѧ����㣬�Ҳ������ؿ�ָ�� 
SLNode *NumFindNode(SLinkList SL, int n){

	SLNode *p;
	
	p = SL->next;
	
	//���Ŀ��ڵ�Ϊ��һλѧ�����򷵻�ͷ�ڵ� 
	if(p->data.num == n) return SL;
	
	//����ÿһ����㣬�ҵ�Ŀ��ڵ��ǰһ���ڵ�ͷ��� 
	while(p->next){//���дp����� 
		
		if(p->next->data.num == n) return p;
		
		p = p->next;
	}

	return NULL;
}

//��ʼ��һ��ѧ����Ϣ�ṹ�����ͱ���
void InitStu(Stu &S){
	
	S.major = (char *)malloc(sizeof(char));
	S.name = (char *)malloc(sizeof(char)); 
}

/*����Ϣ���м��*/

//���ֱȽ�
Status CompareChinese(char *c, SLNode *p){
	
	char a[3];//����һ���ַ��������洢һ������ 
	
	for(int j = 0;j < strlen(p->data.name);j += 2){//���ֵĴ洢ռ�����ֽڣ���jÿ�μ�2  
			
		//һ������ռ�����ֽڣ���ÿ���ֽڵ���һ���ַ���������a�����ֵһ���ַ�0��Ϊ������	
		a[0] = *(p->data.name+j);
		a[1] = *(p->data.name+j+1);
		a[2] = '\0';
		
		//��strcmp�����Ƚ��������� 
		if(!strcmp(a,c)) return OK;//�ҵ�ֱ�ӷ���OK 
	}
	
	//û�ҵ� 
	return ERROR;
} 

//���ѧ����Ϣ�ĺ�����
Status CheckManage(Stu s){
	
	int j = 0;
	char *maj[4] = {"�������","�������ѧ�뼼��","��Ϣ��ȫ","���繤��"};
	
	//�ȼ��ѧ�š��༶���ɼ������� 
	if(s.num <= 20170000||s.num >= 20200199||s.clas <= 0||s.clas > 5||s.avscore < 0||s.avscore > 100)
		return ERROR;
		
	if((s.num%10000)/1000 != 0&&((s.num%1000)/100 != 0||(s.num%1000)/100 != 1))
		return ERROR;
	
	//�ټ���Ա������ 
	if(((s.num%1000)/100 == 1&&s.gender != 'M')||((s.num%1000)/100 == 0&&s.gender != 'W'))
		return ERROR; 
	
	//�ټ������������ 
	for(int i = 0;i < strlen(s.name);i += 2)
			if(*(s.name+i) > 0) return ERROR;
	
	//�����רҵ������		
	for(int i = 0;i < strlen(s.major);i += 2)
		if(*(s.major+i) > 0) return ERROR;
	
	//���רҵ���Ǻ��־Ϳ��ǲ��Ǽ����רҵ 
	for(j = 0;j < 4;j++)
		if(!strcmp(maj[j],s.major)) break;//��������з��ϵ�רҵ�ͽ���ѭ�� 
		
	if(j == 4) return ERROR;//forѭ�����е����˵��רҵ������ 
	
	return OK;
}

//���������Ϣ��ͻ
Status CheckMaConflict(Stu s, SLinkList SL){
	
	if(!SL) return ERROR;
	
	SLNode *p = SL->next;
	
	while(p){
		
		if(s.num == p->data.num) return ERROR;//ѧ�Ų���һ����ֱ�ӷ���ERROR 
		
		//���������Ϣ��ȫһ�����������ͻ������ERROR 
		if(!strcmp(s.name,p->data.name)&&s.gender == p->data.gender&&
			s.avscore == p->data.avscore&&s.clas == p->data.clas&&!strcmp(s.major,p->data.major))
			return ERROR;
			
		p = p->next;
	}
	
	return OK;
} 



