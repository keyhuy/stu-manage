#include "StuManage.h"
  
//�޸�ѧ����Ϣ
void ModifyManage(SLinkList &SL, int num){
	
	// ������������ֱ�ӷ��� 
	if(!SL||num <= 0||num <= 20170000||num >= 20200199){//ѧ��Ĭ�ϴ���0��Ϊ����20170000��8λ���� 
		
		printf("\n�������������޸�ʧ�ܣ���@.@��\n");
		return ;
	}
		
	int flag;
	SLNode *p,*q;
	
	q = NumFindNode(SL,num);//���ú����ҵ���ѧ����ǰһ��ѧ�� 
	
	//�ҵ��ý��
	if(q&&q->next){
		
		p = q->next;//pָ��Ŀ��ѧ���ڵ� 
		
		printf("\n��Ҫ�޸ĵ�ѧ����ϢΪ��\n");
		printf("ѧ��\t\t����\t�Ա�  ƽ���ɼ�\t�༶\tרҵ\n");
		Output(p);//����޸�ǰ��ѧ����Ϣ 
		
		Stu s1;
		InitStu(s1);//�ȳ�ʼ��һ���µ�ѧ����Ϣ�ṹ����������滻ԭ��ѧ�������е�ѧ����Ϣ
				
		printf("\n�����������¸�ʽ�������������ѧ����Ϣ��\n");
		printf("ѧ�ţ�8λѧ�ţ� ���� �Ա�M/W�� ƽ���ɼ� �༶ רҵ\n");
		scanf("%d %s %c %d %d %s",&s1.num,s1.name,&s1.gender,&s1.avscore,&s1.clas,s1.major);
		
		printf("\n�������Ƿ�ȷ���޸���Ϣ���ǣ�1��/��0����");
		scanf("%d",&flag);
	
		//����û���ȷ�ϣ����������� 
		if(!flag){
		
			Stu s2;
			InitStu(s2);
			printf("\n���������룺\n");
			printf("ѧ�ţ�8λѧ�ţ� ���� �Ա�M/W�� ƽ���ɼ� �༶ רҵ\n");
		    scanf("%d %s %c %d %d %s",&s2.num,s2.name,&s2.gender,&s2.avscore,&s2.clas,s2.major);
		    
		    if(!CheckManage(s2)){
		    	
		    	printf("\n����������������޸�ʧ�ܣ���@.@��\n");
				return ;
			}
			
			//�����Ϣ�ɳ�ͻ�����޸�ʧ��
			if(!CheckMaConflict(s2,SL)){
				
				printf("\n������Ϣ�г�ͻ���޸�ʧ�ܣ���@.@��\n");
				return ;
			} 
			
			//���ѧ��û�б��޸ģ���ֱ���滻ԭ����Ϣ 
			if(s2.num == p->data.num)
		    	p->data = s2;//���ⲿ���������Ϣ�滻ԭ����ѧ����Ϣ
				
			else{//���ѧ�ű��޸ģ���������������� 
				
				p->data = s2;
				
				q->next = p->next;
				p->next = NULL;
				
				//���²���
				EnterNode(SL,p); 
			} 
		}else{
		 
			if(!CheckManage(s1)){
				
				printf("\n����������������޸�ʧ�ܣ���@.@��\n");
				return ;
			}
			
			//���������Ϣ���޳�ͻ
			if(!CheckMaConflict(s1,SL)){
				
				printf("\n������Ϣ�г�ͻ����ԭ��Ϣ��ͬ���޸�ʧ�ܣ���@.@��\n");
				return ;
			} 
				
			//���ѧ��û�б��޸ģ���ֱ���滻ԭ����Ϣ 
			if(s1.num == p->data.num)
		    	p->data = s1;//���ⲿ���������Ϣ�滻ԭ����ѧ����Ϣ
				
			else{//���ѧ�ű��޸ģ���������������� 
				
				p->data = s1;
				
				q->next = p->next;
				p->next = NULL;
				
				//���²���
				EnterNode(SL,p); 
			} 
		}
		
		printf("\n�޸ĳɹ�����^0^��\n��ǰȫ��ѧ����ϢΪ��\n"); 
		OutputAll(SL);//�����ǰȫ��ѧ����Ϣ
		
	}else printf("\n�޸�ʧ�ܣ�δ�ҵ���ѧ����Ϣ��@.@��\n");
}

//ɾ��ѧ����Ϣ 
void DeleteNode(SLinkList &SL, int num){
	
	//������������ֱ�ӷ��� 
	if(!SL||num <= 20170000||num >= 20200199){//ѧ��Ĭ�ϴ���0��Ϊ����20170000��8λ���� 
		
		printf("\n������������ɾ��ʧ�ܣ���@.@��\n");
		return ;
	}
	
	int flag;
	SLNode *p,*q;

	q = NumFindNode(SL,num);//qָ��Ŀ��ѧ����ǰһ��

	//�ҵ���ɾ�� 
	if(q&&q->next){
		
		p = q->next;//pָ��Ŀ��ѧ��
		
		printf("��Ҫɾ����ѧ������ϢΪ��\n");
		printf("\nѧ��\t\t����\t�Ա�  ƽ���ɼ�\t�༶\tרҵ\n");
		Output(p);
		
		printf("\n�������Ƿ�ȷ��ɾ����ѧ����Ϣ���ǣ�1��/��0����");
		scanf("%d",&flag);
		
		//�û���ȷ�ϣ�ɾ��ʧ�ܣ�ֱ�ӷ��� 
		if(!flag){
			
			printf("\nɾ��ʧ�ܣ���@.@��\n");
			return ;
		} 
		   
		q->next = p->next;
		free(p);//����Ŀ��ѧ���ڵ� 
		
		printf("\nɾ���ɹ�����^0^��\n��ǰѧ����ϢΪ��\n");
		OutputAll(SL);//�����ǰѧ����Ϣ 
	}else printf("\nɾ��ʧ�ܣ�δ�ҵ���ѧ����Ϣ��@.@��\n");//�Ҳ�������ʧ�� 
}

//�����µ�ѧ�����
void InsertNode(SLinkList &SL){
	
	if(!SL){
		
		printf("����ʧ�ܣ�����������\n");
		return ;
	} 
	
	Stu s1;
	InitStu(s1);
		
	printf("\n�����������¸�ʽ���������µ�ѧ������Ϣ��\n");
	printf("ѧ�ţ�8λѧ�ţ� ���� �Ա�M/W�� ƽ���ɼ� �༶ רҵ\n");
	scanf("%d %s %c %d %d %s",&s1.num,s1.name,&s1.gender,&s1.avscore,&s1.clas,s1.major);
				
	//�����������������Լ���Ϣ���޳�ͻ  
	if(!CheckManage(s1)) printf("\n����������������ʧ�ܣ���@.@��\n");
	else if(!CheckMaConflict(s1,SL)) printf("\n������Ϣ�г�ͻ���޸�ʧ�ܣ���@.@��\n");
	else if(!MakeNode(s1)) printf("\n����������������ʧ�ܣ���@.@��\n");
	else if(EnterNode(SL,MakeNode(s1))){//����EnterNode�������½ڵ���� 
		
			printf("\n����ɹ�����^0^��\n��ǰȫ��ѧ����ϢΪ��\n");
			OutputAll(SL);//�����ǰȫ��ѧ����Ϣ 
		}else printf("\n����ʧ�ܣ���@.@��\n"); 
}
 
//����ѧ�ż���ѧ����Ϣ
void NumSearchNode(SLinkList SL, int num){
	
	//������������ֱ�ӷ��� 
	if(!SL||num <= 20170000||num >= 20200199){
		
		printf("\n����������������ʧ�ܣ���@.@��\n");
		return ;
	} 
	
	SLNode *p;
	
	//�ҵ�Ŀ��ѧ���ڵ��ǰһ��
	p = NumFindNode(SL,num);
	
	if(p&&p->next){
		
		//���Ŀ��ѧ������Ϣ
		printf("\n�����ɹ�����^0^��\n��ѧ����ϢΪ��\n");
		printf("ѧ��\t\t����\t�Ա�  ƽ���ɼ�\t�༶\tרҵ\n");
		Output(p->next);
	}else printf("\n����ʧ�ܣ���@.@��δ�ҵ������Ϣ\n"); 
} 
  
//ģ������ѧ����Ϣ
/*
���ܽ��ܣ�
1��ͨ��ѧ��ǰ4λ��Ҳ�����꼶��ģ�����������ѧ��ǰ4λ��һ����ѧ����Ϣ
2��ͨ����������ģ������������������и��ֵ�ѧ����Ϣ
3��ͨ�����ģ��������������һ����ѧ����Ϣ
4��ͨ��רҵģ�����������רҵһ����ѧ����Ϣ 
*/ 
void SearchNode(SLinkList SL){
	
	//flag��������Ƿ��ҵ������Ϣ ��k�����ж��Ƿ���Ҫ���ѧ����Ϣ��ʽ���Ҳ�����Ϣ�Ͳ������
	int k = 0,choose,i,flag1,flag = 0; 
	char *c,*s;
	SLNode *p = SL->next;
	
	printf("��ѡ������ķ�ʽ��\nѧ��ǰ4λ--2/��������---3/���----4/רҵ----5\n");
	scanf("%d",&choose);
	
	//��switch�����ʵ��ѡ�� 
	switch(choose){
		
		case 2:
			//ѧ��ǰ4λ����
			printf("\n��������Ҫ������ѧ��ǰ4λ��");
			scanf("%d",&i); 
			
			if(i > 2020||i < 2017){//�꼶��ΧΪ2017��2020 
				
				printf("\n����������\n");
				break;
			}
			
			printf("\nѧ��\t\t����\t�Ա�  ƽ���ɼ�\t�༶\tרҵ\n");
			
			while(p){
			 	
			 	if(p->data.num/10000 == i){
			 	
			 		flag = 1;
			 		Output(p);//���������ľ����;
				 }
			 	
			 	p = p->next;
			 }
			 	
			 break;	
			 
		case 3:
			//�����к��ּ���
			//��Ϊһ������ռ�����ֽڣ��൱�������ַ��������ַ���ָ���������ⲿ����ĺ���
			c = (char *)malloc(sizeof(char));
			
			printf("\n��������Ҫ�����ĺ��֣�");
			scanf("%s",c); 
		
			//�ж���������Ƿ�Ϊ���֣����ֵĵ�һ���ֽ���λΪ1�������з����ַ�����˵�Ǹ����� 
			if(*c > 0){
				
				printf("\n����������\n");
				
				free(c);//���������������ֱ������c 
				break;
			} 
			
			while(p){
				
				//���ú����ȽϺ��� 
				if(CompareChinese(c,p)){
					
					k++;
					if(k == 1) printf("\nѧ��\t\t����\t�Ա�  ƽ���ɼ�\t�༶\tרҵ\n");
					flag = 1;
					Output(p);
					
				}
				p = p->next;
			}
			
			free(c);//����c�����٣��ͷ��ڴ� 
			
			break;
			 
		case 4:
			//�༶����
			printf("\n��������Ҫ�����İ༶��");
			scanf("%d",&i);
			
			if(i <= 0||i > 5){//�༶�ŷ�ΧΪ1��5 
				
				printf("\n������������@.@��\n");
				break;
			}
			
			printf("\nѧ��\t\t����\t�Ա�  ƽ���ɼ�\t�༶\tרҵ\n");
			
			while(p){
				
				if(p->data.clas == i){
					
					flag = 1;
					Output(p);
				}
				
				p = p->next;
			}
			
			break;
			 
		case 5:
			//רҵ����
			flag1 = 0;//�����жϲ����Ƿ���� 
			
			s = (char *)malloc(sizeof(char));
			
			printf("\n��������Ҫ������רҵ��");
			scanf("%s",s);
			
			//�ж���������Ƿ�Ϊ���� 
			for(int j = 0;j < strlen(s);j += 2){
				
				if(*(s+j) > 0){

					printf("\n����������\n");
					flag1 = 1; 
					
					free(s);//������������ֱ������s 
				} 
			}
			
			if(flag1) break;
			
			while(p){
				
				if(!strcmp(p->data.major,s)){//��strcmp�����Ƚ������ַ�������ͬ�ͷ���0 
					
					k++;
					if(k == 1) printf("\nѧ��\t\t����\t�Ա�  ƽ���ɼ�\t�༶\tרҵ\n");
					flag = 1;
					Output(p);
				}
				
				p = p->next;
			}
			
			free(s);//����s�����٣��ͷ��ڴ�
			 
			break;
			 
		default:
			printf("\n����������");
			break;	
	}
	
	//ͨ��flag��ֵ�ж��Ƿ��ҵ�Ŀ����Ϣ
	if(!flag) printf("\nδ�ҵ������Ϣ������ʧ�ܣ���@.@��\n");
	else printf("\n�����ɹ�����^0^��\n");	
}

//main����ʵ�� 
int main(){
	
	int num1,choose,m = 1;
	SLinkList SL;
	
	//N=11��Ĭ��¼��11��ѧ����Ϣ 
	Stu stu[MAXSIZE] = {{20200091,"����",'W',60,3,"��������"},
				{20190100,"�",'M',90,4,"�������ѧ�뼼��"},
				{20190102,"��С��",'M',100,3,"��������"},
				{20180080,"��˿Ƽ",'W',81,1,"��Ϣ��ȫ"},
				{20190111,"��С��",'M',98,5,"���繤��"},
				{20170075,"������",'W',76,2,"�������ѧ�뼼��"},
				{20180129,"����С",'M',76,1,"���繤��"},
				{20170156,"�����",'M',59,2,"��Ϣ��ȫ"},
				{20200043,"���»�",'W',75,3,"��������"},
				{20190118,"��ѧ��",'M',66,5,"�������ѧ�뼼��"},
				{20180138,"��ɽ",'M',78,4,"��Ϣ��ȫ"}
				};
				
	//¼��ѧ����Ϣ������ѧ������ 
	CreateList(SL,MAXSIZE,stu);			
	
	//����ѡ��
	/*����ѡ�����
	�����ǰȫ��ѧ����Ϣ����1 
	�����µ�ѧ������2
	ɾ��ĳ��ѧ������3
	�޸�ĳ��ѧ����Ϣ����4
	��ѧ�ż���ĳ��ѧ����Ϣ����5 
	����ѧ����Ϣ����6
	�������̣���0*/
	//printf("\n\t     ***************��������3��3119005100�ͽ���****************\n");
	printf("\n\t*********************************************************************\n");
	printf("\t*                                                                   * \n");
	printf("\t*                  ��ӭ����ѧ����Ϣ����ϵͳ(^0^)                    *\n");
	printf("\t*                                                                   *\n");
	printf("\t*                                                                   *\n");
	printf("\t*********************************************************************\n"); 

	//��һ��forѭ��ʵ�ֶ��ѡ�����������ѡ�������� 
	for(int i = 0;i < INFINITY;i++){
		
		if(i != 0) printf("\n\t\t\t**********ѧ����Ϣ����ϵͳ**********\n");
		printf("\n\t\t\t*************************************\n");
		printf("\n\t\t\t*      �����ǰȫ��ѧ����Ϣ--1      *\n");
		printf("\t\t\t*      ����ѧ����Ϣ----------2      *\n");
		printf("\t\t\t*      ɾ��ѧ����Ϣ----------3      *\n");
		printf("\t\t\t*      �޸�ѧ����Ϣ----------4      *\n");
		printf("\t\t\t*      ��ѧ�ż���ѧ����Ϣ----5      *\n");
		printf("\t\t\t*      ģ������ѧ����Ϣ------6      *\n");
		printf("\t\t\t*      �˳�ϵͳ--------------0      *\n");
		printf("\n\t\t\t*************************************\n");
		printf("\n*��ѡ������Ҫ���еĲ���:");

		scanf("%d",&choose);
		
		switch(choose){
		
			case 1:
				//�����ǰȫ��ѧ����Ϣ
				system("cls");
				printf("\n\t*********************************************************************\n");
				printf("\t     *                                                         * \n");
				printf("\t     *             ��ӭ����ѧ����Ϣ����ϵͳ(^0^)               *\n");
				printf("\t     *                                                         *\n");
				printf("\t     *            ��ǰ����Ϊ �����ǰȫ��ѧ����Ϣ              *\n");
				printf("\t     *                                                         *\n");
				printf("\t*********************************************************************\n"); 
				
				printf("\n��ǰȫ��ѧ����ϢΪ��\n\n");
				OutputAll(SL);
				
				break; 
			
			case 2:
				//����
				system("cls");
				printf("\n\t*********************************************************************\n");
				printf("\t     *                                                         * \n");
				printf("\t     *             ��ӭ����ѧ����Ϣ����ϵͳ(^0^)               *\n");
				printf("\t     *                                                         *\n");
				printf("\t     *                ��ǰ����Ϊ ����ѧ����Ϣ                  *\n");
				printf("\t     *                                                         *\n");
				printf("\t*********************************************************************\n"); 
				
				InsertNode(SL);//���ò��뺯�� 
				
				break;
			
			case 3:
				//ɾ��
				system("cls"); 
				printf("\n\t*********************************************************************\n");
				printf("\t     *                                                         * \n");
				printf("\t     *             ��ӭ����ѧ����Ϣ����ϵͳ(^0^)               *\n");
				printf("\t     *                                                         *\n");
				printf("\t     *                ��ǰ����Ϊ ɾ��ѧ����Ϣ                  *\n");
				printf("\t     *                                                         *\n");
				printf("\t*********************************************************************\n"); 
				
				printf("\n��ǰȫ��ѧ����ϢΪ��\n\n");
				OutputAll(SL);
				
				printf("\n��������Ҫɾ����ѧ����ѧ�ţ�");
				scanf("%d",&num1);
		        DeleteNode(SL,num1); 
		        
		        break;
		        
		    case 4:
				//�޸�
				system("cls");
				printf("\n\t*********************************************************************\n");
				printf("\t     *                                                         * \n");
				printf("\t     *             ��ӭ����ѧ����Ϣ����ϵͳ(^0^)               *\n");
				printf("\t     *                                                         *\n");
				printf("\t     *                ��ǰ����Ϊ �޸�ѧ����Ϣ                  *\n");
				printf("\t     *                                                         *\n");
				printf("\t*********************************************************************\n"); 
				
				printf("\n��ǰȫ��ѧ����ϢΪ��\n\n");
		        OutputAll(SL); 
		        
				printf("\n��������Ҫ�޸ĵ�ѧ����ѧ�ţ�");
				scanf("%d",&num1); 
				ModifyManage(SL,num1);
				
				break;
				
			case 5:
				//��ѧ�ż��� 
				system("cls");
				printf("\n\t*********************************************************************\n");
				printf("\t     *                                                         * \n");
				printf("\t     *             ��ӭ����ѧ����Ϣ����ϵͳ(^0^)               *\n");
				printf("\t     *                                                         *\n");
				printf("\t     *                 ��ǰ����Ϊ ��ѧ�ż���                   *\n");
				printf("\t     *                                                         *\n");
				printf("\t*********************************************************************\n"); 
				
				printf("\n��������Ҫ������ѧ����ѧ�ţ�");
				scanf("%d",&num1);
				NumSearchNode(SL,num1);
				
				break;
				
			case 6:
				//ģ������
				system("cls");
				printf("\n\t*********************************************************************\n");
				printf("\t     *                                                         * \n");
				printf("\t     *             ��ӭ����ѧ����Ϣ����ϵͳ(^0^)               *\n");
				printf("\t     *                                                         *\n");
				printf("\t     *                  ��ǰ����Ϊ ģ������                    *\n");
				printf("\t     *                                                         *\n");
				printf("\t*********************************************************************\n\n"); 
				
				SearchNode(SL);
				
				break; 
			
			case 0:
				//�˳�ϵͳ 
				m = 0;
				printf("\n���ѳɹ��˳�ϵͳ����л����ʹ�ã��ټ���");
				break; 
				
			default:
				printf("\n������������ϵͳ���Զ��رգ�@.@��\n");
				m = 0;
				break;
		}
		
		if(!m) break;
		
		system("pause");
		system("cls");//��մ��ڵ�����  
	} 
	
	return 0;
} 
