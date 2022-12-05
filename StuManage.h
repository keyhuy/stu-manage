#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define INFINITY INT_MAX //计算机允许的整数最大值，即无穷大 
#define MAXSIZE 11 //默认存入的学生个数 

typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等

//学生信息结构体
typedef struct{
	
	int num;//学号，默认为8位数字，前4位表示年级，第5和6位表示性别，01表示男，00表示女 
	char *name;//姓名
	char gender;//性别 ,M表示男，W表示女 
	int avscore;//平均成绩
	int clas;//班级,与类class区分开 
	char *major;//专业，都是计算机学院的专业 
}Stu;

//学生链表
typedef struct SLNode{
	
	Stu data;//学生信息
	struct SLNode *next; 
}SLNode,*SLinkList;

/*创建学生信息链表*/

//学生链表初始化
Status InitList(SLinkList &SL){
	
	SL = (SLinkList)malloc(sizeof(SLinkList));//创建一个头节点分配空间
	
	//为专业和姓名两个数组分配空间 
	SL->data.major = (char *)malloc(sizeof(char));
	SL->data.name = (char *)malloc(sizeof(char));
	
	if(!SL||!SL->data.major||!SL->data.name) return ERROR;//分配失败，返回失败
	
	SL->next = NULL;//分配成功，创建头节点，返回OK 
	
	return OK; 
} 

//构建一个学生节点
SLNode *MakeNode(Stu s){
	
	SLNode *p;
	p = (SLNode *)malloc(sizeof(SLNode));
	
	if(!p) return NULL;//构建失败，返回空指针
	
	//分配空间成功，构建新节点p，并返回 
	p->data = s;
	p->next = NULL;
	
	return p; 
}

//录入学生信息(插入)，按学号大小升序插入
Status EnterNode(SLinkList &SL, SLNode *p){
	
	if(!SL||!p) return ERROR;//头节点或要插入的节点为空，参数不合理，返回ERROR
	
	SLNode *q;
	q = SL->next;//q指向第一个学生节点
	
	if(!q){	//若第一个学生节点为空，直接插入新学生节点作为第一位学生
		
		SL->next = p;
		p->next = NULL;
		
		return OK; //插入完成，返回OK；
	}else{//第一个学生节点不为空，按照学号大小升序插入 
		
		//若p学号比第一位学生的学号还小，则在最前面插入 
		if(p->data.num < q->data.num){
			
			p->next = q;
			SL->next = p;
	
			return OK; 
		}else{
		
			while(q->next){
			
			//若原来学生中已有p学生的信息，插入失败 
			if(p->data.num == q->data.num) return ERROR; 
			
			//若p学号大小大于当前节点且小于当前节点下一个节点，则插入 
				if(q->data.num < p->data.num&&(q->next)->data.num > p->data.num){
				
					p->next = q->next;
					q->next = p;
				 
					return OK; 
				}
			
				q = q->next;//未找到继续遍历下一个节点 
			}
			
			//若p学号大小比最后一个学生节点还大，直接插到最后 
			q->next = p;
			p->next = NULL;
			 
		    return OK;
	    }
	}
	
	return ERROR; 
}

//构建长度为n的学生有序单链表，数组S[]提供n个元素值（学生） 
Status CreateList(SLinkList &SL, int n, Stu *S){
	
	SLNode *sp;
	
	//初始化失败或参数不合理，返回ERROR 
	if(!InitList(SL)||n <= 0||!S) return ERROR;
	
	//依次插入n个节点 
	for(int i = 0;i < n;i++){
		
		sp = MakeNode(S[i]);//以S[i]提供的信息创建新的节点 
		
		if(!EnterNode(SL,sp)) return ERROR;//有序插入，如果插入失败，返回ERROR； 
	}
	
	return OK;
}

/*对学生信息进行操作*/ 

//输出全部学生信息
void OutputAll(SLinkList SL){
	
	SLNode *p;
	
	p = SL->next;
	
	printf("学号\t\t姓名\t性别  平均成绩\t班级\t专业\n");
	
	while(p){
		
		printf("%d\t%s\t%c\t%d\t%d\t%s\n",
			p->data.num,p->data.name,p->data.gender,p->data.avscore,p->data.clas,p->data.major);
			
		p = p->next;
	}
}

//输出单个学生信息
void Output(SLNode *p){
	
	//printf("学号\t\t姓名\t性别  平均成绩\t班级\t专业\n");
	
	printf("%d\t%s\t%c\t%d\t%d\t%s\n",
		p->data.num,p->data.name,p->data.gender,p->data.avscore,p->data.clas,p->data.major);
} 

//通过学号查找目标学生的前一个学生（方便删除操作），找到返回该学生结点，找不到返回空指针 
SLNode *NumFindNode(SLinkList SL, int n){

	SLNode *p;
	
	p = SL->next;
	
	//如果目标节点为第一位学生，则返回头节点 
	if(p->data.num == n) return SL;
	
	//遍历每一个结点，找到目标节点的前一个节点就返回 
	while(p->next){//如果写p会出错 
		
		if(p->next->data.num == n) return p;
		
		p = p->next;
	}

	return NULL;
}

//初始化一个学生信息结构体类型变量
void InitStu(Stu &S){
	
	S.major = (char *)malloc(sizeof(char));
	S.name = (char *)malloc(sizeof(char)); 
}

/*对信息进行检查*/

//汉字比较
Status CompareChinese(char *c, SLNode *p){
	
	char a[3];//定义一个字符数组来存储一个汉字 
	
	for(int j = 0;j < strlen(p->data.name);j += 2){//汉字的存储占两个字节，故j每次加2  
			
		//一个汉字占两个字节，把每个字节当成一个字符赋给数组a，最后赋值一个字符0作为结束。	
		a[0] = *(p->data.name+j);
		a[1] = *(p->data.name+j+1);
		a[2] = '\0';
		
		//用strcmp函数比较两个汉字 
		if(!strcmp(a,c)) return OK;//找到直接返回OK 
	}
	
	//没找到 
	return ERROR;
} 

//检查学生信息的合理性
Status CheckManage(Stu s){
	
	int j = 0;
	char *maj[4] = {"软件工程","计算机科学与技术","信息安全","网络工程"};
	
	//先检查学号、班级、成绩合理性 
	if(s.num <= 20170000||s.num >= 20200199||s.clas <= 0||s.clas > 5||s.avscore < 0||s.avscore > 100)
		return ERROR;
		
	if((s.num%10000)/1000 != 0&&((s.num%1000)/100 != 0||(s.num%1000)/100 != 1))
		return ERROR;
	
	//再检查性别合理性 
	if(((s.num%1000)/100 == 1&&s.gender != 'M')||((s.num%1000)/100 == 0&&s.gender != 'W'))
		return ERROR; 
	
	//再检查姓名合理性 
	for(int i = 0;i < strlen(s.name);i += 2)
			if(*(s.name+i) > 0) return ERROR;
	
	//最后检查专业合理性		
	for(int i = 0;i < strlen(s.major);i += 2)
		if(*(s.major+i) > 0) return ERROR;
	
	//如果专业都是汉字就看是不是计算机专业 
	for(j = 0;j < 4;j++)
		if(!strcmp(maj[j],s.major)) break;//如果输入有符合的专业就结束循环 
		
	if(j == 4) return ERROR;//for循环进行到最后，说明专业不符合 
	
	return OK;
}

//检查有无信息冲突
Status CheckMaConflict(Stu s, SLinkList SL){
	
	if(!SL) return ERROR;
	
	SLNode *p = SL->next;
	
	while(p){
		
		if(s.num == p->data.num) return ERROR;//学号不能一样，直接返回ERROR 
		
		//如果其他信息完全一样，则产生冲突，返回ERROR 
		if(!strcmp(s.name,p->data.name)&&s.gender == p->data.gender&&
			s.avscore == p->data.avscore&&s.clas == p->data.clas&&!strcmp(s.major,p->data.major))
			return ERROR;
			
		p = p->next;
	}
	
	return OK;
} 



