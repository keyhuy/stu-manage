#include "StuManage.h"
  
//修改学生信息
void ModifyManage(SLinkList &SL, int num){
	
	// 参数不合理，直接返回 
	if(!SL||num <= 0||num <= 20170000||num >= 20200199){//学号默认大于0且为大于20170000的8位数字 
		
		printf("\n参数不合理，修改失败！（@.@）\n");
		return ;
	}
		
	int flag;
	SLNode *p,*q;
	
	q = NumFindNode(SL,num);//调用函数找到该学生的前一个学生 
	
	//找到该结点
	if(q&&q->next){
		
		p = q->next;//p指向目标学生节点 
		
		printf("\n您要修改的学生信息为：\n");
		printf("学号\t\t姓名\t性别  平均成绩\t班级\t专业\n");
		Output(p);//输出修改前该学生信息 
		
		Stu s1;
		InitStu(s1);//先初始化一个新的学生信息结构体变量，再替换原来学生链表中的学生信息
				
		printf("\n请您按照如下格式依次重新输入该学生信息：\n");
		printf("学号（8位学号） 姓名 性别（M/W） 平均成绩 班级 专业\n");
		scanf("%d %s %c %d %d %s",&s1.num,s1.name,&s1.gender,&s1.avscore,&s1.clas,s1.major);
		
		printf("\n请问您是否确认修改信息？是（1）/否（0）：");
		scanf("%d",&flag);
	
		//如果用户不确认，则重新输入 
		if(!flag){
		
			Stu s2;
			InitStu(s2);
			printf("\n请重新输入：\n");
			printf("学号（8位学号） 姓名 性别（M/W） 平均成绩 班级 专业\n");
		    scanf("%d %s %c %d %d %s",&s2.num,s2.name,&s2.gender,&s2.avscore,&s2.clas,s2.major);
		    
		    if(!CheckManage(s2)){
		    	
		    	printf("\n输入参数不合理，修改失败！（@.@）\n");
				return ;
			}
			
			//如果信息由冲突，则修改失败
			if(!CheckMaConflict(s2,SL)){
				
				printf("\n输入信息有冲突，修改失败！（@.@）\n");
				return ;
			} 
			
			//如果学号没有被修改，则直接替换原来信息 
			if(s2.num == p->data.num)
		    	p->data = s2;//用外部输入的新信息替换原来的学生信息
				
			else{//如果学号被修改，则需重新排序插入 
				
				p->data = s2;
				
				q->next = p->next;
				p->next = NULL;
				
				//重新插入
				EnterNode(SL,p); 
			} 
		}else{
		 
			if(!CheckManage(s1)){
				
				printf("\n输入参数不合理，修改失败！（@.@）\n");
				return ;
			}
			
			//检查输入信息有无冲突
			if(!CheckMaConflict(s1,SL)){
				
				printf("\n输入信息有冲突或与原信息相同，修改失败！（@.@）\n");
				return ;
			} 
				
			//如果学号没有被修改，则直接替换原来信息 
			if(s1.num == p->data.num)
		    	p->data = s1;//用外部输入的新信息替换原来的学生信息
				
			else{//如果学号被修改，则需重新排序插入 
				
				p->data = s1;
				
				q->next = p->next;
				p->next = NULL;
				
				//重新插入
				EnterNode(SL,p); 
			} 
		}
		
		printf("\n修改成功！（^0^）\n当前全部学生信息为：\n"); 
		OutputAll(SL);//输出当前全部学生信息
		
	}else printf("\n修改失败！未找到该学生信息（@.@）\n");
}

//删除学生信息 
void DeleteNode(SLinkList &SL, int num){
	
	//参数不合理，直接返回 
	if(!SL||num <= 20170000||num >= 20200199){//学号默认大于0且为大于20170000的8位数字 
		
		printf("\n参数不合理，删除失败！（@.@）\n");
		return ;
	}
	
	int flag;
	SLNode *p,*q;

	q = NumFindNode(SL,num);//q指向目标学生的前一个

	//找到就删除 
	if(q&&q->next){
		
		p = q->next;//p指向目标学生
		
		printf("您要删除的学生的信息为：\n");
		printf("\n学号\t\t姓名\t性别  平均成绩\t班级\t专业\n");
		Output(p);
		
		printf("\n请问您是否确认删除该学生信息？是（1）/否（0）：");
		scanf("%d",&flag);
		
		//用户不确认，删除失败，直接返回 
		if(!flag){
			
			printf("\n删除失败！（@.@）\n");
			return ;
		} 
		   
		q->next = p->next;
		free(p);//销毁目标学生节点 
		
		printf("\n删除成功！（^0^）\n当前学生信息为：\n");
		OutputAll(SL);//输出当前学生信息 
	}else printf("\n删除失败！未找到该学生信息（@.@）\n");//找不到返回失败 
}

//插入新的学生结点
void InsertNode(SLinkList &SL){
	
	if(!SL){
		
		printf("插入失败！参数不合理\n");
		return ;
	} 
	
	Stu s1;
	InitStu(s1);
		
	printf("\n请您按照如下格式依次输入新的学生的信息：\n");
	printf("学号（8位学号） 姓名 性别（M/W） 平均成绩 班级 专业\n");
	scanf("%d %s %c %d %d %s",&s1.num,s1.name,&s1.gender,&s1.avscore,&s1.clas,s1.major);
				
	//检查输入参数合理性以及信息有无冲突  
	if(!CheckManage(s1)) printf("\n参数不合理，插入失败！（@.@）\n");
	else if(!CheckMaConflict(s1,SL)) printf("\n输入信息有冲突，修改失败！（@.@）\n");
	else if(!MakeNode(s1)) printf("\n参数不合理，插入失败！（@.@）\n");
	else if(EnterNode(SL,MakeNode(s1))){//调用EnterNode函数将新节点插入 
		
			printf("\n插入成功！（^0^）\n当前全部学生信息为：\n");
			OutputAll(SL);//输出当前全部学生信息 
		}else printf("\n插入失败！（@.@）\n"); 
}
 
//按照学号检索学生信息
void NumSearchNode(SLinkList SL, int num){
	
	//参数不合理，直接返回 
	if(!SL||num <= 20170000||num >= 20200199){
		
		printf("\n参数不合理，检索失败！（@.@）\n");
		return ;
	} 
	
	SLNode *p;
	
	//找到目标学生节点的前一个
	p = NumFindNode(SL,num);
	
	if(p&&p->next){
		
		//输出目标学生的信息
		printf("\n检索成功！（^0^）\n该学生信息为：\n");
		printf("学号\t\t姓名\t性别  平均成绩\t班级\t专业\n");
		Output(p->next);
	}else printf("\n检索失败！（@.@）未找到相关信息\n"); 
} 
  
//模糊检索学生信息
/*
功能介绍：
1、通过学号前4位（也就是年级）模糊检索，输出学号前4位都一样的学生信息
2、通过单个汉字模糊检索，输出姓名中有该字的学生信息
3、通过班别模糊检索，输出班别一样的学生信息
4、通过专业模糊检索，输出专业一样的学生信息 
*/ 
void SearchNode(SLinkList SL){
	
	//flag用来标记是否找到相关信息 ；k用来判断是否需要输出学生信息格式，找不到信息就不用输出
	int k = 0,choose,i,flag1,flag = 0; 
	char *c,*s;
	SLNode *p = SL->next;
	
	printf("请选择检索的方式：\n学号前4位--2/单个汉字---3/班别----4/专业----5\n");
	scanf("%d",&choose);
	
	//用switch语句来实现选择 
	switch(choose){
		
		case 2:
			//学号前4位检索
			printf("\n请输入您要检索的学号前4位：");
			scanf("%d",&i); 
			
			if(i > 2020||i < 2017){//年级范围为2017到2020 
				
				printf("\n参数不合理\n");
				break;
			}
			
			printf("\n学号\t\t姓名\t性别  平均成绩\t班级\t专业\n");
			
			while(p){
			 	
			 	if(p->data.num/10000 == i){
			 	
			 		flag = 1;
			 		Output(p);//满足条件的就输出;
				 }
			 	
			 	p = p->next;
			 }
			 	
			 break;	
			 
		case 3:
			//姓名中汉字检索
			//因为一个汉字占两个字节，相当于两个字符，故用字符串指针来存入外部输入的汉字
			c = (char *)malloc(sizeof(char));
			
			printf("\n请输入您要检索的汉字：");
			scanf("%s",c); 
		
			//判断输入参数是否为汉字（汉字的第一个字节首位为1，对于有符号字符型来说是负数） 
			if(*c > 0){
				
				printf("\n参数不合理\n");
				
				free(c);//输入参数不合理，直接销毁c 
				break;
			} 
			
			while(p){
				
				//调用函数比较汉字 
				if(CompareChinese(c,p)){
					
					k++;
					if(k == 1) printf("\n学号\t\t姓名\t性别  平均成绩\t班级\t专业\n");
					flag = 1;
					Output(p);
					
				}
				p = p->next;
			}
			
			free(c);//用完c就销毁，释放内存 
			
			break;
			 
		case 4:
			//班级检索
			printf("\n请输入您要检索的班级：");
			scanf("%d",&i);
			
			if(i <= 0||i > 5){//班级号范围为1到5 
				
				printf("\n参数不合理（@.@）\n");
				break;
			}
			
			printf("\n学号\t\t姓名\t性别  平均成绩\t班级\t专业\n");
			
			while(p){
				
				if(p->data.clas == i){
					
					flag = 1;
					Output(p);
				}
				
				p = p->next;
			}
			
			break;
			 
		case 5:
			//专业检索
			flag1 = 0;//用来判断参数是否合理 
			
			s = (char *)malloc(sizeof(char));
			
			printf("\n请输入您要检索的专业：");
			scanf("%s",s);
			
			//判断输入参数是否都为汉字 
			for(int j = 0;j < strlen(s);j += 2){
				
				if(*(s+j) > 0){

					printf("\n参数不合理\n");
					flag1 = 1; 
					
					free(s);//参数不合理，直接销毁s 
				} 
			}
			
			if(flag1) break;
			
			while(p){
				
				if(!strcmp(p->data.major,s)){//用strcmp函数比较两个字符串，相同就返回0 
					
					k++;
					if(k == 1) printf("\n学号\t\t姓名\t性别  平均成绩\t班级\t专业\n");
					flag = 1;
					Output(p);
				}
				
				p = p->next;
			}
			
			free(s);//用完s就销毁，释放内存
			 
			break;
			 
		default:
			printf("\n参数不合理");
			break;	
	}
	
	//通过flag的值判断是否找到目标信息
	if(!flag) printf("\n未找到相关信息，检索失败！（@.@）\n");
	else printf("\n检索成功！（^0^）\n");	
}

//main函数实现 
int main(){
	
	int num1,choose,m = 1;
	SLinkList SL;
	
	//N=11，默认录入11个学生信息 
	Stu stu[MAXSIZE] = {{20200091,"张三",'W',60,3,"软件工程"},
				{20190100,"李华",'M',90,4,"计算机科学与技术"},
				{20190102,"陈小涛",'M',100,3,"软件工程"},
				{20180080,"吴丝萍",'W',81,1,"信息安全"},
				{20190111,"麦小楷",'M',98,5,"网络工程"},
				{20170075,"李张柱",'W',76,2,"计算机科学与技术"},
				{20180129,"陈刘小",'M',76,1,"网络工程"},
				{20170156,"李广先",'M',59,2,"信息安全"},
				{20200043,"刘德华",'W',75,3,"软件工程"},
				{20190118,"张学友",'M',66,5,"计算机科学与技术"},
				{20180138,"华山",'M',78,4,"信息安全"}
				};
				
	//录入学生信息，创建学生链表 
	CreateList(SL,MAXSIZE,stu);			
	
	//功能选择
	/*功能选择介绍
	输出当前全部学生信息，扣1 
	插入新的学生，扣2
	删除某个学生，扣3
	修改某个学生信息，扣4
	按学号检索某个学生信息，扣5 
	检索学生信息，扣6
	结束进程，扣0*/
	//printf("\n\t     ***************软件工程3班3119005100劳健辉****************\n");
	printf("\n\t*********************************************************************\n");
	printf("\t*                                                                   * \n");
	printf("\t*                  欢迎进入学生信息管理系统(^0^)                    *\n");
	printf("\t*                                                                   *\n");
	printf("\t*                                                                   *\n");
	printf("\t*********************************************************************\n"); 

	//用一个for循环实现多次选择操作，最多可选择无穷大次 
	for(int i = 0;i < INFINITY;i++){
		
		if(i != 0) printf("\n\t\t\t**********学生信息管理系统**********\n");
		printf("\n\t\t\t*************************************\n");
		printf("\n\t\t\t*      输出当前全部学生信息--1      *\n");
		printf("\t\t\t*      插入学生信息----------2      *\n");
		printf("\t\t\t*      删除学生信息----------3      *\n");
		printf("\t\t\t*      修改学生信息----------4      *\n");
		printf("\t\t\t*      按学号检索学生信息----5      *\n");
		printf("\t\t\t*      模糊检索学生信息------6      *\n");
		printf("\t\t\t*      退出系统--------------0      *\n");
		printf("\n\t\t\t*************************************\n");
		printf("\n*请选择您想要进行的操作:");

		scanf("%d",&choose);
		
		switch(choose){
		
			case 1:
				//输出当前全部学生信息
				system("cls");
				printf("\n\t*********************************************************************\n");
				printf("\t     *                                                         * \n");
				printf("\t     *             欢迎进入学生信息管理系统(^0^)               *\n");
				printf("\t     *                                                         *\n");
				printf("\t     *            当前功能为 输出当前全部学生信息              *\n");
				printf("\t     *                                                         *\n");
				printf("\t*********************************************************************\n"); 
				
				printf("\n当前全部学生信息为：\n\n");
				OutputAll(SL);
				
				break; 
			
			case 2:
				//插入
				system("cls");
				printf("\n\t*********************************************************************\n");
				printf("\t     *                                                         * \n");
				printf("\t     *             欢迎进入学生信息管理系统(^0^)               *\n");
				printf("\t     *                                                         *\n");
				printf("\t     *                当前功能为 插入学生信息                  *\n");
				printf("\t     *                                                         *\n");
				printf("\t*********************************************************************\n"); 
				
				InsertNode(SL);//调用插入函数 
				
				break;
			
			case 3:
				//删除
				system("cls"); 
				printf("\n\t*********************************************************************\n");
				printf("\t     *                                                         * \n");
				printf("\t     *             欢迎进入学生信息管理系统(^0^)               *\n");
				printf("\t     *                                                         *\n");
				printf("\t     *                当前功能为 删除学生信息                  *\n");
				printf("\t     *                                                         *\n");
				printf("\t*********************************************************************\n"); 
				
				printf("\n当前全部学生信息为：\n\n");
				OutputAll(SL);
				
				printf("\n请输入您要删除的学生的学号：");
				scanf("%d",&num1);
		        DeleteNode(SL,num1); 
		        
		        break;
		        
		    case 4:
				//修改
				system("cls");
				printf("\n\t*********************************************************************\n");
				printf("\t     *                                                         * \n");
				printf("\t     *             欢迎进入学生信息管理系统(^0^)               *\n");
				printf("\t     *                                                         *\n");
				printf("\t     *                当前功能为 修改学生信息                  *\n");
				printf("\t     *                                                         *\n");
				printf("\t*********************************************************************\n"); 
				
				printf("\n当前全部学生信息为：\n\n");
		        OutputAll(SL); 
		        
				printf("\n请输入您要修改的学生的学号：");
				scanf("%d",&num1); 
				ModifyManage(SL,num1);
				
				break;
				
			case 5:
				//按学号检索 
				system("cls");
				printf("\n\t*********************************************************************\n");
				printf("\t     *                                                         * \n");
				printf("\t     *             欢迎进入学生信息管理系统(^0^)               *\n");
				printf("\t     *                                                         *\n");
				printf("\t     *                 当前功能为 按学号检索                   *\n");
				printf("\t     *                                                         *\n");
				printf("\t*********************************************************************\n"); 
				
				printf("\n请输入您要检索的学生的学号：");
				scanf("%d",&num1);
				NumSearchNode(SL,num1);
				
				break;
				
			case 6:
				//模糊检索
				system("cls");
				printf("\n\t*********************************************************************\n");
				printf("\t     *                                                         * \n");
				printf("\t     *             欢迎进入学生信息管理系统(^0^)               *\n");
				printf("\t     *                                                         *\n");
				printf("\t     *                  当前功能为 模糊检索                    *\n");
				printf("\t     *                                                         *\n");
				printf("\t*********************************************************************\n\n"); 
				
				SearchNode(SL);
				
				break; 
			
			case 0:
				//退出系统 
				m = 0;
				printf("\n您已成功退出系统，感谢您的使用，再见！");
				break; 
				
			default:
				printf("\n参数不合理，系统已自动关闭（@.@）\n");
				m = 0;
				break;
		}
		
		if(!m) break;
		
		system("pause");
		system("cls");//清空窗口的内容  
	} 
	
	return 0;
} 

